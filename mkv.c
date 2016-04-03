#include "mkv.h"

#define false 0
#define true 1

#include <string.h>
#include <stdio.h>

uint64_t pack(int n, uint8_t* b) {
	uint64_t v = 0;
	uint64_t k = ((uint64_t)n - 1) * 8;

	for(int i = 0; i < n; ++i) {
		v |= (uint64_t)b[i] << k;
		k -= 8;
	}

	return v;
}

mkv_buffer_t unpack(int n, uint64_t v) {
	mkv_buffer_t b;
	b.len = n;
	b.data = malloc(n * sizeof(uint8_t));

	int index = 0;
	for(int i = n; i > 0; --i) {
		b.data[index++] = (uint8_t)(v >> (8 * i)) & 0xff;
	}

	return b;
}

bool mkv_element_parse(mkv_buffer_t* buffer, mkv_element_t* element) {
	memset(element, 0, sizeof(mkv_element_t));

	uint32_t id;
	size_t n = mkv_element_id(buffer, &id);
	if(!id) {
		return false;
	}

	buffer->data += n;
	buffer->len -= n;

	size_t size;
	n = mkv_element_size(buffer, &size);
	if(!size) {
		return false;
	}

	buffer->data += n;
	buffer->len -= n;

	mkv_register_t reg = mkv_register_id(id);
	if(reg.id == ELEMENT_UNKNOWN) {
		printf("Unknown elemnt ID %x\n", id);
		return false;
	}

	element->type = reg;

	if(element->type.type != ELEMENT_TYPE_MASTER) {
		if(buffer->len < size) {
			return false;
		}

		element->content.len = size;
		element->content.data = malloc(size);

		memcpy(element->content.data, buffer->data, size);

		buffer->data += size;
		buffer->len -= size;
	}

	return true;
}

void mkv_element_free(mkv_element_t* element) {
	free(element->content.data);
}

size_t mkv_element_id(mkv_buffer_t* buffer, uint32_t* id) {
	if(buffer->len == 0) {
		return 0;
	}

	uint8_t b = buffer->data[0];

	if(((b & 0x80) >> 7) == 1) { // ID Class A (8 bits)
		*id = (uint32_t)b;
		return 1;
	}
	if(((b & 0x40) >> 6) == 1) { // ID Class B (16 bits)
		if(buffer->len < 2) {
			return 0;
		}

		*id = (uint32_t)pack(2, buffer->data);
		return 2;
	}
	if(((b & 0x20) >> 5) == 1) { // ID Class C (24 bits)
		if(buffer->len < 3) {
			return 0;
		}

		*id = (uint32_t)pack(3, buffer->data);
		return 3;
	}
	if(((b & 0x10) >> 4) == 1) { // ID Class D (32 bits)
		if(buffer->len < 4) {
			return 0;
		}

		*id = (uint32_t)pack(4, buffer->data);
		return 4;
	}

	return 0;
}

size_t mkv_element_size(mkv_buffer_t* buffer, size_t* size) {
	if(buffer->len == 0) {
		return 0;
	}

	uint8_t b = buffer->data[0];
	uint8_t mask;
	uint64_t length;

	if(b >= 0x80) {
		length = 1;
		mask = 0x7f;
	}
	else if(b >= 0x40) {
		length = 2;
		mask = 0x3f;
	}
	else if(b >= 0x20) {
		length = 3;
		mask = 0x1f;
	}
	else if(b >= 0x10) {
		length = 4;
		mask = 0x0f;
	}
	else if(b >= 0x08) {
		length = 5;
		mask = 0x07;
	}
	else if(b >= 0x04) {
		length = 6;
		mask = 0x03;
	}
	else if(b >= 0x02) {
		length = 7;
		mask = 0x01;
	}
	else if(b >= 0x01) {
		length = 8;
		mask = 0x00;
	}
	else {
		return 0;
	}

	uint8_t* bb = malloc(length * sizeof(uint8_t));
	bb[0] = b;

	if(length > 1) {
		if(buffer->len < length) {
			free(bb);
			return 0;
		}

		memcpy(bb + 1, buffer->data + 1, length - 1);
	}

	bb[0] &= mask;
	*size = pack(length, bb);

	free(bb);
	return length;
}

mkv_register_t mkv_register_id(uint32_t id) {
	switch(id) {
		case ELEMENT_UNKNOWN:
			return ElementUnknown;
		case ELEMENT_EBML:
			return ElementEBML;
		case ELEMENT_EBML_VERSION:
			return ElementEBMLVersion;
		case ELEMENT_EBML_READ_VERSION:
			return ElementEBMLReadVersion;
		case ELEMENT_EBML_MAX_ID_LENGTH:
			return ElementEBMLMaxIDLength;
		case ELEMENT_EBML_MAX_SIZE_LENGTH:
			return ElementEBMLMaxSizeLength;
		case ELEMENT_DOC_TYPE:
			return ElementDocType;
		case ELEMENT_DOC_TYPE_VERSION:
			return ElementDocTypeVersion;
		case ELEMENT_DOC_TYPE_READ_VERSION:
			return ElementDocTypeReadVersion;
		case ELEMENT_VOID:
			return ElementVoid;
		case ELEMENT_CRC32:
			return ElementCRC32;
		case ELEMENT_SEGMENT:
			return ElementSegment;
		case ELEMENT_SEEK_HEAD:
			return ElementSeekHead;
		case ELEMENT_SEEK:
			return ElementSeek;
		case ELEMENT_SEEK_ID:
			return ElementSeekID;
		case ELEMENT_SEEK_POSITION:
			return ElementSeekPosition;
		case ELEMENT_INFO:
			return ElementInfo;
		case ELEMENT_SEGMENT_UID:
			return ElementSegmentUID;
		case ELEMENT_SEGMENT_FILENAME:
			return ElementSegmentFilename;
		case ELEMENT_PREV_UID:
			return ElementPrevUID;
		case ELEMENT_PREV_FILENAME:
			return ElementPrevFilename;
		case ELEMENT_NEXT_UID:
			return ElementNextUID;
		case ELEMENT_NEXT_FILENAME:
			return ElementNextFilename;
		case ELEMENT_SEGMENT_FAMILY:
			return ElementSegmentFamily;
		case ELEMENT_CHAPTER_TRANSLATE:
			return ElementChapterTranslate;
		case ELEMENT_CHAPTER_TRANSLATE_EDITION_UID:
			return ElementChapterTranslateEditionUID;
		case ELEMENT_CHAPTER_TRANSLATE_CODEC:
			return ElementChapterTranslateCodec;
		case ELEMENT_CHAPTER_TRANSLATE_ID:
			return ElementChapterTranslateID;
		case ELEMENT_TIMECODE_SCALE:
			return ElementTimecodeScale;
		case ELEMENT_DURATION:
			return ElementDuration;
		case ELEMENT_DATE_UTC:
			return ElementDateUTC;
		case ELEMENT_TITLE:
			return ElementTitle;
		case ELEMENT_MUXING_APP:
			return ElementMuxingApp;
		case ELEMENT_WRITING_APP:
			return ElementWritingApp;
		case ELEMENT_CLUSTER:
			return ElementCluster;
		case ELEMENT_TIMECODE:
			return ElementTimecode;
		case ELEMENT_SLIENT_TRACKS:
			return ElementSlientTracks;
		case ELEMENT_SLIENT_TRACK_NUMBER:
			return ElementSlientTrackNumber;
		case ELEMENT_POSITION:
			return ElementPosition;
		case ELEMENT_PREV_SIZE:
			return ElementPrevSize;
		case ELEMENT_SIMPLE_BLOCK:
			return ElementSimpleBlock;
		case ELEMENT_BLOCK_GROUP:
			return ElementBlockGroup;
		case ELEMENT_BLOCK:
			return ElementBlock;
		case ELEMENT_BLOCK_ADDITIONS:
			return ElementBlockAdditions;
		case ELEMENT_BLOCK_MORE:
			return ElementBlockMore;
		case ELEMENT_BLOCK_ADD_ID:
			return ElementBlockAddID;
		case ELEMENT_BLOCK_ADDITIONAL:
			return ElementBlockAdditional;
		case ELEMENT_BLOCK_DURATION:
			return ElementBlockDuration;
		case ELEMENT_REFERENCE_PRIORITY:
			return ElementReferencePriority;
		case ELEMENT_REFERENCE_BLOCK:
			return ElementReferenceBlock;
		case ELEMENT_CODEC_STATE:
			return ElementCodecState;
		case ELEMENT_DISCARD_PADDING:
			return ElementDiscardPadding;
		case ELEMENT_SLICES:
			return ElementSlices;
		case ELEMENT_TIME_SLICE:
			return ElementTimeSlice;
		case ELEMENT_LACE_NUMBER:
			return ElementLaceNumber;
		case ELEMENT_TRACKS:
			return ElementTracks;
		case ELEMENT_TRACK_ENTRY:
			return ElementTrackEntry;
		case ELEMENT_TRACK_NUMBER:
			return ElementTrackNumber;
		case ELEMENT_TRACK_UID:
			return ElementTrackUID;
		case ELEMENT_TRACK_TYPE:
			return ElementTrackType;
		case ELEMENT_FLAG_ENABLED:
			return ElementFlagEnabled;
		case ELEMENT_FLAG_DEFAULT:
			return ElementFlagDefault;
		case ELEMENT_FLAG_FORCED:
			return ElementFlagForced;
		case ELEMENT_FLAG_LACING:
			return ElementFlagLacing;
		case ELEMENT_MIN_CACHE:
			return ElementMinCache;
		case ELEMENT_MAX_CACHE:
			return ElementMaxCache;
		case ELEMENT_DEFAULT_DURATION:
			return ElementDefaultDuration;
		case ELEMENT_DEFAULT_DECODED_FIELD_DURATION:
			return ElementDefaultDecodedFieldDuration;
		case ELEMENT_MAX_BLOCK_ADDITION_ID:
			return ElementMaxBlockAdditionID;
		case ELEMENT_NAME:
			return ElementName;
		case ELEMENT_LANGUAGE:
			return ElementLanguage;
		case ELEMENT_CODEC_ID:
			return ElementCodecID;
		case ELEMENT_CODEC_PRIVATE:
			return ElementCodecPrivate;
		case ELEMENT_CODEC_NAME:
			return ElementCodecName;
		case ELEMENT_ATTACHMENT_LINK:
			return ElementAttachmentLink;
		case ELEMENT_CODEC_DECODE_ALL:
			return ElementCodecDecodeAll;
		case ELEMENT_TRACK_OVERLAY:
			return ElementTrackOverlay;
		case ELEMENT_CODEC_DELAY:
			return ElementCodecDelay;
		case ELEMENT_SEEK_PRE_ROLL:
			return ElementSeekPreRoll;
		case ELEMENT_TRACK_TRANSLATE:
			return ElementTrackTranslate;
		case ELEMENT_TRACK_TRANSLATE_EDITION_UID:
			return ElementTrackTranslateEditionUID;
		case ELEMENT_TRACK_TRANSLATE_CODEC:
			return ElementTrackTranslateCodec;
		case ELEMENT_TRACK_TRANSLATE_TRACK_ID:
			return ElementTrackTranslateTrackID;
		case ELEMENT_VIDEO:
			return ElementVideo;
		case ELEMENT_FLAG_INTERLACED:
			return ElementFlagInterlaced;
		case ELEMENT_STEREO_MODE:
			return ElementStereoMode;
		case ELEMENT_ALPHA_MODE:
			return ElementAlphaMode;
		case ELEMENT_PIXEL_WIDTH:
			return ElementPixelWidth;
		case ELEMENT_PIXEL_HEIGHT:
			return ElementPixelHeight;
		case ELEMENT_PIXEL_CROP_BOTTOM:
			return ElementPixelCropBottom;
		case ELEMENT_PIXEL_CROP_TOP:
			return ElementPixelCropTop;
		case ELEMENT_PIXEL_CROP_LEFT:
			return ElementPixelCropLeft;
		case ELEMENT_PIXEL_CROP_RIGHT:
			return ElementPixelCropRight;
		case ELEMENT_DISPLAY_WIDTH:
			return ElementDisplayWidth;
		case ELEMENT_DISPLAY_HEIGHT:
			return ElementDisplayHeight;
		case ELEMENT_DISPLAY_UINT:
			return ElementDisplayUint;
		case ELEMENT_ASPECT_RATIO_TYPE:
			return ElementAspectRatioType;
		case ELEMENT_COLOUR_SPACE:
			return ElementColourSpace;
		case ELEMENT_GAMMA_VALUE:
			return ElementGammaValue;
		case ELEMENT_FRAME_RATE:
			return ElementFramerate;
		case ELEMENT_AUDIO:
			return ElementAudio;
		case ELEMENT_SAMPLING_FREQUENCY:
			return ElementSamplingFrequency;
		case ELEMENT_OUTPUT_SAMPLING_FREQUENCY:
			return ElementOutputSamplingFrequency;
		case ELEMENT_CHANNELS:
			return ElementChannels;
		case ELEMENT_BIT_DEPTH:
			return ElementBitDepth;
		case ELEMENT_TRACK_OPERATION:
			return ElementTrackOperation;
		case ELEMENT_TRACK_COMBINE_PLANES:
			return ElementTrackCombinePlanes;
		case ELEMENT_TRACK_PLANE:
			return ElementTrackPlane;
		case ELEMENT_TRACK_PLANE_UID:
			return ElementTrackPlaneUID;
		case ELEMENT_TRACK_PLANE_TYPE:
			return ElementTrackPlaneType;
		case ELEMENT_TRACK_JOIN_BLOCKS:
			return ElementTrackJoinBlocks;
		case ELEMENT_TRACK_JOIN_UID:
			return ElementTrackJoinUID;
		case ELEMENT_CONTENT_ENCODINGS:
			return ElementContentEncodings;
		case ELEMENT_CONTENT_ENCODING:
			return ElementContentEncoding;
		case ELEMENT_CONTENT_ENCODING_ORDER:
			return ElementContentEncodingOrder;
		case ELEMENT_CONTENT_ENCODING_SCOPE:
			return ElementContentEncodingScope;
		case ELEMENT_CONTENT_ENCODING_TYPE:
			return ElementContentEncodingType;
		case ELEMENT_CONTENT_COMPRESSION:
			return ElementContentCompression;
		case ELEMENT_CONTENT_COMP_ALGO:
			return ElementContentCompAlgo;
		case ELEMENT_CONTENT_COMP_SETTINGS:
			return ElementContentCompSettings;
		case ELEMENT_CONTENT_ENCRYPTION:
			return ElementContentEncryption;
		case ELEMENT_CONTENT_ENC_ALGO:
			return ElementContentEncAlgo;
		case ELEMENT_CONTENT_ENC_KEY_ID:
			return ElementContentEncKeyID;
		case ELEMENT_CONTENT_SIGNATURE:
			return ElementContentSignature;
		case ELEMENT_CONTENT_SIG_KEY_ID:
			return ElementContentSigKeyID;
		case ELEMENT_CONTENT_SIG_ALGO:
			return ElementContentSigAlgo;
		case ELEMENT_CONTENT_SIG_HASH_ALGO:
			return ElementContentSigHashAlgo;
		case ELEMENT_CUES:
			return ElementCues;
		case ELEMENT_CUE_POINT:
			return ElementCuePoint;
		case ELEMENT_CUE_TIME:
			return ElementCueTime;
		case ELEMENT_CUE_TRACK_POSITIONS:
			return ElementCueTrackPositions;
		case ELEMENT_CUE_TRACK:
			return ElementCueTrack;
		case ELEMENT_CUE_CLUSTER_POSITION:
			return ElementCueClusterPosition;
		case ELEMENT_CUE_RELATIVE_POSITION:
			return ElementCueRelativePosition;
		case ELEMENT_CUE_DURATION:
			return ElementCueDuration;
		case ELEMENT_CUE_BLOCK_NUMBER:
			return ElementCueBlockNumber;
		case ELEMENT_CUE_CODEC_STATE:
			return ElementCueCodecState;
		case ELEMENT_CUE_REFERENCE:
			return ElementCueReference;
		case ELEMENT_CUE_REF_TIME:
			return ElementCueRefTime;
		case ELEMENT_ATTACHMENTS:
			return ElementAttachments;
		case ELEMENT_ATTACHED_FILE:
			return ElementAttachedFile;
		case ELEMENT_FILE_DESCRIPTION:
			return ElementFileDescription;
		case ELEMENT_FILE_NAME:
			return ElementFileName;
		case ELEMENT_FILE_MIME_TYPE:
			return ElementFileMimeType;
		case ELEMENT_FILE_DATA:
			return ElementFileData;
		case ELEMENT_FILE_UID:
			return ElementFileUID;
		case ELEMENT_CHAPTERS:
			return ElementChapters;
		case ELEMENT_EDITION_ENTRY:
			return ElementEditionEntry;
		case ELEMENT_EDITION_UID:
			return ElementEditionUID;
		case ELEMENT_EDITION_FLAG_HIDDEN:
			return ElementEditionFlagHidden;
		case ELEMENT_EDITION_FLAG_DEFAULT:
			return ElementEditionFlagDefault;
		case ELEMENT_EDITION_FLAG_ORDERED:
			return ElementEditionFlagOrdered;
		case ELEMENT_CHAPTER_ATOM:
			return ElementChapterAtom;
		case ELEMENT_CHAPTER_UID:
			return ElementChapterUID;
		case ELEMENT_CHAPTER_STRING_UID:
			return ElementChapterStringUID;
		case ELEMENT_CHAPTER_TIME_START:
			return ElementChapterTimeStart;
		case ELEMENT_CHAPTER_TIME_END:
			return ElementChapterTimeEnd;
		case ELEMENT_CHAPTER_FLAG_HIDDEN:
			return ElementChapterFlagHidden;
		case ELEMENT_CHAPTER_FLAG_ENABLED:
			return ElementChapterFlagEnabled;
		case ELEMENT_CHAPTER_SEGMENT_UID:
			return ElementChapterSegmentUID;
		case ELEMENT_CHAPTER_SEGMENT_EDITION_UID:
			return ElementChapterSegmentEditionUID;
		case ELEMENT_CHAPTER_PHYSICAL_EQUIV:
			return ElementChapterPhysicalEquiv;
		case ELEMENT_CHAPTER_TRACK:
			return ElementChapterTrack;
		case ELEMENT_CHAPTER_TRACK_NUMBER:
			return ElementChapterTrackNumber;
		case ELEMENT_CHAPTER_DISPLAY:
			return ElementChapterDisplay;
		case ELEMENT_CHAP_STRING:
			return ElementChapString;
		case ELEMENT_CHAP_LANGUAGE:
			return ElementChapLanguage;
		case ELEMENT_CHAP_COUNTRY:
			return ElementChapCountry;
		case ELEMENT_CHAP_PROCESS:
			return ElementChapProcess;
		case ELEMENT_CHAP_PROCESS_CODEC_ID:
			return ElementChapProcessCodecID;
		case ELEMENT_CHAP_PROCESS_PRIVATE:
			return ElementChapProcessPrivate;
		case ELEMENT_CHAP_PROCESS_COMMAND:
			return ElementChapProcessCommand;
		case ELEMENT_CHAP_PROCESS_TIME:
			return ElementChapProcessTime;
		case ELEMENT_CHAP_PROCESS_DATA:
			return ElementChapProcessData;
		default:
			return ElementUnknown;
	}
}
