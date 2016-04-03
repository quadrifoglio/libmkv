#pragma once

#include <stdint.h>
#include <stdlib.h>

/*
 * Element data type list
 */
#define ELEMENT_TYPE_UNKNOWN  0x0
#define ELEMENT_TYPE_MASTER   0x1
#define ELEMENT_TYPE_UINT     0x2
#define ELEMENT_TYPE_INT      0x3
#define ELEMENT_TYPE_STRING   0x4
#define ELEMENT_TYPE_UNICODE  0x5
#define ELEMENT_TYPE_BINARY   0x6
#define ELEMENT_TYPE_FLOAT    0x7
#define ELEMENT_TYPE_DATE     0x8

/*
 * Element ID list
 */
#define ELEMENT_UNKNOWN                        0x0
#define ELEMENT_EBML                           0x1a45dfa3
#define ELEMENT_EBML_VERSION                   0x4286
#define ELEMENT_EBML_READ_VERSION              0x42f7
#define ELEMENT_EBML_MAX_ID_LENGTH             0x42f2
#define ELEMENT_EBML_MAX_SIZE_LENGTH           0x42f3
#define ELEMENT_DOC_TYPE                       0x4282
#define ELEMENT_DOC_TYPE_VERSION               0x4287
#define ELEMENT_DOC_TYPE_READ_VERSION          0x4285
#define ELEMENT_VOID                           0xec
#define ELEMENT_CRC32                          0xbf
#define ELEMENT_SEGMENT                        0x18538067
#define ELEMENT_SEEK_HEAD                      0x114d9b74
#define ELEMENT_SEEK                           0x4dbb
#define ELEMENT_SEEK_ID                        0x53ab
#define ELEMENT_SEEK_POSITION                  0x53ac
#define ELEMENT_INFO                           0x1549a966
#define ELEMENT_SEGMENT_UID                    0x73a4
#define ELEMENT_SEGMENT_FILENAME               0x7384
#define ELEMENT_PREV_UID                       0x3cb923
#define ELEMENT_PREV_FILENAME                  0x3c83ab
#define ELEMENT_NEXT_UID                       0x3eb923
#define ELEMENT_NEXT_FILENAME                  0x3e83bb
#define ELEMENT_SEGMENT_FAMILY                 0x4444
#define ELEMENT_CHAPTER_TRANSLATE              0x6924
#define ELEMENT_CHAPTER_TRANSLATE_EDITION_UID  0x69fc
#define ELEMENT_CHAPTER_TRANSLATE_CODEC        0x69bf
#define ELEMENT_CHAPTER_TRANSLATE_ID           0x69a5
#define ELEMENT_TIMECODE_SCALE                 0x2ad7b1
#define ELEMENT_DURATION                       0x4489
#define ELEMENT_DATE_UTC                       0x4461
#define ELEMENT_TITLE                          0x7ba9
#define ELEMENT_MUXING_APP                     0x4d80
#define ELEMENT_WRITING_APP                    0x5741
#define ELEMENT_CLUSTER                        0x1f43b675
#define ELEMENT_TIMECODE                       0xe7
#define ELEMENT_SLIENT_TRACKS                  0x5854
#define ELEMENT_SLIENT_TRACK_NUMBER            0x58d7
#define ELEMENT_POSITION                       0xa7
#define ELEMENT_PREV_SIZE                      0xab
#define ELEMENT_SIMPLE_BLOCK                   0xa3
#define ELEMENT_BLOCK_GROUP                    0xa0
#define ELEMENT_BLOCK                          0xa1
#define ELEMENT_BLOCK_ADDITIONS                0x75a1
#define ELEMENT_BLOCK_MORE                     0xa6
#define ELEMENT_BLOCK_ADD_ID                   0xee
#define ELEMENT_BLOCK_ADDITIONAL               0xa5
#define ELEMENT_BLOCK_DURATION                 0x9b
#define ELEMENT_REFERENCE_PRIORITY             0xfa
#define ELEMENT_REFERENCE_BLOCK                0xfb
#define ELEMENT_CODEC_STATE                    0xa4
#define ELEMENT_DISCARD_PADDING                0x75a2
#define ELEMENT_SLICES                         0x8e
#define ELEMENT_TIME_SLICE                     0xe8
#define ELEMENT_LACE_NUMBER                    0xcc
#define ELEMENT_TRACKS                         0x1654ae6b
#define ELEMENT_TRACK_ENTRY                    0xae
#define ELEMENT_TRACK_NUMBER                   0xd7
#define ELEMENT_TRACK_UID                      0x73c5
#define ELEMENT_TRACK_TYPE                     0x83
#define ELEMENT_FLAG_ENABLED                   0xb9
#define ELEMENT_FLAG_DEFAULT                   0x88
#define ELEMENT_FLAG_FORCED                    0x55aa
#define ELEMENT_FLAG_LACING                    0x9c
#define ELEMENT_MIN_CACHE                      0x6de7
#define ELEMENT_MAX_CACHE                      0x6df8
#define ELEMENT_DEFAULT_DURATION               0x23e383
#define ELEMENT_DEFAULT_DECODED_FIELD_DURATION 0x234e7a
#define ELEMENT_MAX_BLOCK_ADDITION_ID          0x55ee
#define ELEMENT_NAME                           0x536e
#define ELEMENT_LANGUAGE                       0x22b59c
#define ELEMENT_CODEC_ID                       0x86
#define ELEMENT_CODEC_PRIVATE                  0x63a2
#define ELEMENT_CODEC_NAME                     0x258688
#define ELEMENT_ATTACHMENT_LINK                0x7446
#define ELEMENT_CODEC_DECODE_ALL               0xaa
#define ELEMENT_TRACK_OVERLAY                  0x6fab
#define ELEMENT_CODEC_DELAY                    0x56aa
#define ELEMENT_SEEK_PRE_ROLL                  0x56bb
#define ELEMENT_TRACK_TRANSLATE                0x6624
#define ELEMENT_TRACK_TRANSLATE_EDITION_UID    0x66fc
#define ELEMENT_TRACK_TRANSLATE_CODEC          0x66bf
#define ELEMENT_TRACK_TRANSLATE_TRACK_ID       0x66a5
#define ELEMENT_VIDEO                          0xe0
#define ELEMENT_FLAG_INTERLACED                0x9a
#define ELEMENT_STEREO_MODE                    0x53b8
#define ELEMENT_ALPHA_MODE                     0x53c0
#define ELEMENT_PIXEL_WIDTH                    0xb0
#define ELEMENT_PIXEL_HEIGHT                   0xba
#define ELEMENT_PIXEL_CROP_BOTTOM              0x54aa
#define ELEMENT_PIXEL_CROP_TOP                 0x54bb
#define ELEMENT_PIXEL_CROP_LEFT                0x54cc
#define ELEMENT_PIXEL_CROP_RIGHT               0x54dd
#define ELEMENT_DISPLAY_WIDTH                  0x54b0
#define ELEMENT_DISPLAY_HEIGHT                 0x54ba
#define ELEMENT_DISPLAY_UINT                   0x54b2
#define ELEMENT_ASPECT_RATIO_TYPE              0x54b3
#define ELEMENT_COLOUR_SPACE                   0x2eb524
#define ELEMENT_GAMMA_VALUE                    0x2fb523
#define ELEMENT_FRAME_RATE                     0x2383e3
#define ELEMENT_AUDIO                          0xe1
#define ELEMENT_SAMPLING_FREQUENCY             0xb5
#define ELEMENT_OUTPUT_SAMPLING_FREQUENCY      0x78b5
#define ELEMENT_CHANNELS                       0x9f
#define ELEMENT_BIT_DEPTH                      0x6264
#define ELEMENT_TRACK_OPERATION                0xe2
#define ELEMENT_TRACK_COMBINE_PLANES           0xe3
#define ELEMENT_TRACK_PLANE                    0xe4
#define ELEMENT_TRACK_PLANE_UID                0xe5
#define ELEMENT_TRACK_PLANE_TYPE               0xe6
#define ELEMENT_TRACK_JOIN_BLOCKS              0xe9
#define ELEMENT_TRACK_JOIN_UID                 0xed
#define ELEMENT_CONTENT_ENCODINGS              0x6d80
#define ELEMENT_CONTENT_ENCODING               0x6240
#define ELEMENT_CONTENT_ENCODING_ORDER         0x5031
#define ELEMENT_CONTENT_ENCODING_SCOPE         0x5032
#define ELEMENT_CONTENT_ENCODING_TYPE          0x5033
#define ELEMENT_CONTENT_COMPRESSION            0x5034
#define ELEMENT_CONTENT_COMP_ALGO              0x4254
#define ELEMENT_CONTENT_COMP_SETTINGS          0x4255
#define ELEMENT_CONTENT_ENCRYPTION             0x5035
#define ELEMENT_CONTENT_ENC_ALGO               0x47e1
#define ELEMENT_CONTENT_ENC_KEY_ID             0x47e2
#define ELEMENT_CONTENT_SIGNATURE              0x47e3
#define ELEMENT_CONTENT_SIG_KEY_ID             0x47e4
#define ELEMENT_CONTENT_SIG_ALGO               0x47e5
#define ELEMENT_CONTENT_SIG_HASH_ALGO          0x47e6
#define ELEMENT_CUES                           0x1c53bb6b
#define ELEMENT_CUE_POINT                      0xbb
#define ELEMENT_CUE_TIME                       0xb3
#define ELEMENT_CUE_TRACK_POSITIONS            0xb7
#define ELEMENT_CUE_TRACK                      0xf7
#define ELEMENT_CUE_CLUSTER_POSITION           0xf1
#define ELEMENT_CUE_RELATIVE_POSITION          0xf0
#define ELEMENT_CUE_DURATION                   0xb2
#define ELEMENT_CUE_BLOCK_NUMBER               0x5378
#define ELEMENT_CUE_CODEC_STATE                0xea
#define ELEMENT_CUE_REFERENCE                  0xdb
#define ELEMENT_CUE_REF_TIME                   0x96
#define ELEMENT_ATTACHMENTS                    0x1941a469
#define ELEMENT_ATTACHED_FILE                  0x61a7
#define ELEMENT_FILE_DESCRIPTION               0x467e
#define ELEMENT_FILE_NAME                      0x466e
#define ELEMENT_FILE_MIME_TYPE                 0x6460
#define ELEMENT_FILE_DATA                      0x465c
#define ELEMENT_FILE_UID                       0x46ae
#define ELEMENT_CHAPTERS                       0x1043a770
#define ELEMENT_EDITION_ENTRY                  0x45b9
#define ELEMENT_EDITION_UID                    0x45bc
#define ELEMENT_EDITION_FLAG_HIDDEN            0x45bd
#define ELEMENT_EDITION_FLAG_DEFAULT           0x45db
#define ELEMENT_EDITION_FLAG_ORDERED           0x45dd
#define ELEMENT_CHAPTER_ATOM                   0xb6
#define ELEMENT_CHAPTER_UID                    0x73c4
#define ELEMENT_CHAPTER_STRING_UID             0x5654
#define ELEMENT_CHAPTER_TIME_START             0x91
#define ELEMENT_CHAPTER_TIME_END               0x92
#define ELEMENT_CHAPTER_FLAG_HIDDEN            0x98
#define ELEMENT_CHAPTER_FLAG_ENABLED           0x4598
#define ELEMENT_CHAPTER_SEGMENT_UID            0x6e67
#define ELEMENT_CHAPTER_SEGMENT_EDITION_UID    0x6ebc
#define ELEMENT_CHAPTER_PHYSICAL_EQUIV         0x63c3
#define ELEMENT_CHAPTER_TRACK                  0x8f
#define ELEMENT_CHAPTER_TRACK_NUMBER           0x89
#define ELEMENT_CHAPTER_DISPLAY                0x80
#define ELEMENT_CHAP_STRING                    0x85
#define ELEMENT_CHAP_LANGUAGE                  0x437c
#define ELEMENT_CHAP_COUNTRY                   0x437e
#define ELEMENT_CHAP_PROCESS                   0x6944
#define ELEMENT_CHAP_PROCESS_CODEC_ID          0x6955
#define ELEMENT_CHAP_PROCESS_PRIVATE           0x450d
#define ELEMENT_CHAP_PROCESS_COMMAND           0x6911
#define ELEMENT_CHAP_PROCESS_TIME              0x6922
#define ELEMENT_CHAP_PROCESS_DATA              0x6933

typedef uint8_t bool;

typedef struct mkv_buffer mkv_buffer_t;
typedef struct mkv_register mkv_register_t;
typedef struct mkv_element mkv_element_t;

/*
 * Generic buffer structure
 */
struct mkv_buffer {
	size_t len;
	uint8_t* data;
};

/*
 * Element type register
 */
struct mkv_register {
	const uint32_t id;
	const uint8_t type;
	const char* name;
};

/*
 * Actual parsed element
 */
struct mkv_element {
	mkv_register_t type;

	mkv_element_t* parent;
	mkv_buffer_t content;
};

/*
 * MVK/WebM element types, called 'register'
 * The element ID can be up to 32 bits
 */
static const mkv_register_t ElementUnknown                     = {ELEMENT_UNKNOWN, ELEMENT_TYPE_UNKNOWN, "Unknown"};
static const mkv_register_t ElementEBML                        = {ELEMENT_EBML, ELEMENT_TYPE_MASTER, "EBML"};
static const mkv_register_t ElementEBMLVersion                 = {ELEMENT_EBML_VERSION, ELEMENT_TYPE_UINT, "EBMLVersion"};
static const mkv_register_t ElementEBMLReadVersion             = {ELEMENT_EBML_READ_VERSION, ELEMENT_TYPE_UINT, "EBMLReadVersion"};
static const mkv_register_t ElementEBMLMaxIDLength             = {ELEMENT_EBML_MAX_ID_LENGTH, ELEMENT_TYPE_UINT, "EBMLMaxIDLength"};
static const mkv_register_t ElementEBMLMaxSizeLength           = {ELEMENT_EBML_MAX_SIZE_LENGTH, ELEMENT_TYPE_UINT, "EBMLMaxSizeLength"};
static const mkv_register_t ElementDocType                     = {ELEMENT_DOC_TYPE, ELEMENT_TYPE_STRING, "DocType"};
static const mkv_register_t ElementDocTypeVersion              = {ELEMENT_DOC_TYPE_VERSION, ELEMENT_TYPE_UINT, "DocTypeVersion"};
static const mkv_register_t ElementDocTypeReadVersion          = {ELEMENT_DOC_TYPE_READ_VERSION, ELEMENT_TYPE_UINT, "DocTypeReadVersion"};
static const mkv_register_t ElementVoid                        = {ELEMENT_VOID, ELEMENT_TYPE_BINARY, "Void"};
static const mkv_register_t ElementCRC32                       = {ELEMENT_CRC32, ELEMENT_TYPE_BINARY, "CRC32"};
static const mkv_register_t ElementSegment                     = {ELEMENT_SEGMENT, ELEMENT_TYPE_MASTER, "Segment"};
static const mkv_register_t ElementSeekHead                    = {ELEMENT_SEEK_HEAD, ELEMENT_TYPE_MASTER, "SeekHead"};
static const mkv_register_t ElementSeek                        = {ELEMENT_SEEK, ELEMENT_TYPE_MASTER, "Seek"};
static const mkv_register_t ElementSeekID                      = {ELEMENT_SEEK_ID, ELEMENT_TYPE_BINARY, "SeekID"};
static const mkv_register_t ElementSeekPosition                = {ELEMENT_SEEK_POSITION, ELEMENT_TYPE_UINT, "SeekPosition"};
static const mkv_register_t ElementInfo                        = {ELEMENT_INFO, ELEMENT_TYPE_MASTER, "Info"};
static const mkv_register_t ElementSegmentUID                  = {ELEMENT_SEGMENT_UID, ELEMENT_TYPE_BINARY, "SegmentUID"};
static const mkv_register_t ElementSegmentFilename             = {ELEMENT_SEGMENT_FILENAME, ELEMENT_TYPE_UNICODE, "SegmentFilename"};
static const mkv_register_t ElementPrevUID                     = {ELEMENT_PREV_UID, ELEMENT_TYPE_BINARY, "PrevUID"};
static const mkv_register_t ElementPrevFilename                = {ELEMENT_PREV_FILENAME, ELEMENT_TYPE_UNICODE, "PrevFilename"};
static const mkv_register_t ElementNextUID                     = {ELEMENT_NEXT_UID, ELEMENT_TYPE_BINARY, "NextUID"};
static const mkv_register_t ElementNextFilename                = {ELEMENT_NEXT_FILENAME, ELEMENT_TYPE_UNICODE, "NextFilename"};
static const mkv_register_t ElementSegmentFamily               = {ELEMENT_SEGMENT_FAMILY, ELEMENT_TYPE_BINARY, "SegmentFamily"};
static const mkv_register_t ElementChapterTranslate            = {ELEMENT_CHAPTER_TRANSLATE, ELEMENT_TYPE_MASTER, "ChapterTranslate"};
static const mkv_register_t ElementChapterTranslateEditionUID  = {ELEMENT_CHAPTER_TRANSLATE_EDITION_UID, ELEMENT_TYPE_UINT, "ChapterTranslateEditionUID"};
static const mkv_register_t ElementChapterTranslateCodec       = {ELEMENT_CHAPTER_TRANSLATE_CODEC, ELEMENT_TYPE_UINT, "ChapterTranslateCodec"};
static const mkv_register_t ElementChapterTranslateID          = {ELEMENT_CHAPTER_TRANSLATE_ID, ELEMENT_TYPE_BINARY, "ChapterTranslateID"};
static const mkv_register_t ElementTimecodeScale               = {ELEMENT_TIMECODE_SCALE, ELEMENT_TYPE_UINT, "TimecodeScale"};
static const mkv_register_t ElementDuration                    = {ELEMENT_DURATION, ELEMENT_TYPE_FLOAT, "Duration"};
static const mkv_register_t ElementDateUTC                     = {ELEMENT_DATE_UTC, ELEMENT_TYPE_DATE, "DateUTC"};
static const mkv_register_t ElementTitle                       = {ELEMENT_TITLE, ELEMENT_TYPE_UNICODE, "Title"};
static const mkv_register_t ElementMuxingApp                   = {ELEMENT_MUXING_APP, ELEMENT_TYPE_UNICODE, "MuxingApp"};
static const mkv_register_t ElementWritingApp                  = {ELEMENT_WRITING_APP, ELEMENT_TYPE_UNICODE, "WritingApp"};
static const mkv_register_t ElementCluster                     = {ELEMENT_CLUSTER, ELEMENT_TYPE_MASTER, "Cluster"};
static const mkv_register_t ElementTimecode                    = {ELEMENT_TIMECODE, ELEMENT_TYPE_UINT, "Timecode"};
static const mkv_register_t ElementSlientTracks                = {ELEMENT_SLIENT_TRACKS, ELEMENT_TYPE_MASTER, "SlientTracks"};
static const mkv_register_t ElementSlientTrackNumber           = {ELEMENT_SLIENT_TRACK_NUMBER, ELEMENT_TYPE_UINT, "SlientTrackNumber"};
static const mkv_register_t ElementPosition                    = {ELEMENT_POSITION, ELEMENT_TYPE_UINT, "Position"};
static const mkv_register_t ElementPrevSize                    = {ELEMENT_PREV_SIZE, ELEMENT_TYPE_UINT, "PrevSize"};
static const mkv_register_t ElementSimpleBlock                 = {ELEMENT_SIMPLE_BLOCK, ELEMENT_TYPE_BINARY, "SimpleBlock"};
static const mkv_register_t ElementBlockGroup                  = {ELEMENT_BLOCK_GROUP, ELEMENT_TYPE_MASTER, "BlockGroup"};
static const mkv_register_t ElementBlock                       = {ELEMENT_BLOCK, ELEMENT_TYPE_BINARY, "Block"};
static const mkv_register_t ElementBlockAdditions              = {ELEMENT_BLOCK_ADDITIONS, ELEMENT_TYPE_MASTER, "BlockAdditions"};
static const mkv_register_t ElementBlockMore                   = {ELEMENT_BLOCK_MORE, ELEMENT_TYPE_MASTER, "BlockMore"};
static const mkv_register_t ElementBlockAddID                  = {ELEMENT_BLOCK_ADD_ID, ELEMENT_TYPE_UINT, "BlockAddID"};
static const mkv_register_t ElementBlockAdditional             = {ELEMENT_BLOCK_ADDITIONAL, ELEMENT_TYPE_BINARY, "BlockAdditional"};
static const mkv_register_t ElementBlockDuration               = {ELEMENT_BLOCK_DURATION, ELEMENT_TYPE_UINT, "BlockDuration"};
static const mkv_register_t ElementReferencePriority           = {ELEMENT_REFERENCE_PRIORITY, ELEMENT_TYPE_UINT, "ReferencePriority"};
static const mkv_register_t ElementReferenceBlock              = {ELEMENT_REFERENCE_BLOCK, ELEMENT_TYPE_INT, "ReferenceBlock"};
static const mkv_register_t ElementCodecState                  = {ELEMENT_CODEC_STATE, ELEMENT_TYPE_BINARY, "CodecState"};
static const mkv_register_t ElementDiscardPadding              = {ELEMENT_DISCARD_PADDING, ELEMENT_TYPE_INT, "DiscardPadding"};
static const mkv_register_t ElementSlices                      = {ELEMENT_SLICES, ELEMENT_TYPE_MASTER, "Slices"};
static const mkv_register_t ElementTimeSlice                   = {ELEMENT_TIME_SLICE, ELEMENT_TYPE_MASTER, "TimeSlice"};
static const mkv_register_t ElementLaceNumber                  = {ELEMENT_LACE_NUMBER, ELEMENT_TYPE_UINT, "LaceNumber"};
static const mkv_register_t ElementTracks                      = {ELEMENT_TRACKS, ELEMENT_TYPE_MASTER, "Tracks"};
static const mkv_register_t ElementTrackEntry                  = {ELEMENT_TRACK_ENTRY, ELEMENT_TYPE_MASTER, "TrackEntry"};
static const mkv_register_t ElementTrackNumber                 = {ELEMENT_TRACK_NUMBER, ELEMENT_TYPE_UINT, "TrackNumber"};
static const mkv_register_t ElementTrackUID                    = {ELEMENT_TRACK_UID, ELEMENT_TYPE_UINT, "TrackUID"};
static const mkv_register_t ElementTrackType                   = {ELEMENT_TRACK_TYPE, ELEMENT_TYPE_UINT, "TrackType"};
static const mkv_register_t ElementFlagEnabled                 = {ELEMENT_FLAG_ENABLED, ELEMENT_TYPE_UINT, "FlagEnabled"};
static const mkv_register_t ElementFlagDefault                 = {ELEMENT_FLAG_DEFAULT, ELEMENT_TYPE_UINT, "FlagDefault"};
static const mkv_register_t ElementFlagForced                  = {ELEMENT_FLAG_FORCED, ELEMENT_TYPE_UINT, "FlagForced"};
static const mkv_register_t ElementFlagLacing                  = {ELEMENT_FLAG_LACING, ELEMENT_TYPE_UINT, "FlagLacing"};
static const mkv_register_t ElementMinCache                    = {ELEMENT_MIN_CACHE, ELEMENT_TYPE_UINT, "MinCache"};
static const mkv_register_t ElementMaxCache                    = {ELEMENT_MAX_CACHE, ELEMENT_TYPE_UINT, "MaxCache"};
static const mkv_register_t ElementDefaultDuration             = {ELEMENT_DEFAULT_DURATION, ELEMENT_TYPE_UINT, "DefaultDuration"};
static const mkv_register_t ElementDefaultDecodedFieldDuration = {ELEMENT_DEFAULT_DECODED_FIELD_DURATION, ELEMENT_TYPE_UINT, "DefaultDecodedFieldDuration"};
static const mkv_register_t ElementMaxBlockAdditionID          = {ELEMENT_MAX_BLOCK_ADDITION_ID, ELEMENT_TYPE_UINT, "MaxBlockAdditionID"};
static const mkv_register_t ElementName                        = {ELEMENT_NAME, ELEMENT_TYPE_UNICODE, "Name"};
static const mkv_register_t ElementLanguage                    = {ELEMENT_LANGUAGE, ELEMENT_TYPE_STRING, "Language"};
static const mkv_register_t ElementCodecID                     = {ELEMENT_CODEC_ID, ELEMENT_TYPE_STRING, "CodecID"};
static const mkv_register_t ElementCodecPrivate                = {ELEMENT_CODEC_PRIVATE, ELEMENT_TYPE_BINARY, "CodecPrivate"};
static const mkv_register_t ElementCodecName                   = {ELEMENT_CODEC_NAME, ELEMENT_TYPE_UNICODE, "CodecName"};
static const mkv_register_t ElementAttachmentLink              = {ELEMENT_ATTACHMENT_LINK, ELEMENT_TYPE_UINT, "AttachmentLink"};
static const mkv_register_t ElementCodecDecodeAll              = {ELEMENT_CODEC_DECODE_ALL, ELEMENT_TYPE_UINT, "CodecDecodeAll"};
static const mkv_register_t ElementTrackOverlay                = {ELEMENT_TRACK_OVERLAY, ELEMENT_TYPE_UINT, "TrackOverlay"};
static const mkv_register_t ElementCodecDelay                  = {ELEMENT_CODEC_DELAY, ELEMENT_TYPE_UINT, "CodecDelay"};
static const mkv_register_t ElementSeekPreRoll                 = {ELEMENT_SEEK_PRE_ROLL, ELEMENT_TYPE_UINT, "SeekPreRoll"};
static const mkv_register_t ElementTrackTranslate              = {ELEMENT_TRACK_TRANSLATE, ELEMENT_TYPE_MASTER, "TrackTranslate"};
static const mkv_register_t ElementTrackTranslateEditionUID    = {ELEMENT_TRACK_TRANSLATE_EDITION_UID, ELEMENT_TYPE_UINT, "TrackTranslateEditionUID"};
static const mkv_register_t ElementTrackTranslateCodec         = {ELEMENT_TRACK_TRANSLATE_CODEC, ELEMENT_TYPE_UINT, "TrackTranslateCodec"};
static const mkv_register_t ElementTrackTranslateTrackID       = {ELEMENT_TRACK_TRANSLATE_TRACK_ID, ELEMENT_TYPE_BINARY, "TrackTranslateTrackID"};
static const mkv_register_t ElementVideo                       = {ELEMENT_VIDEO, ELEMENT_TYPE_MASTER, "Video"};
static const mkv_register_t ElementFlagInterlaced              = {ELEMENT_FLAG_INTERLACED, ELEMENT_TYPE_UINT, "FlagInterlaced"};
static const mkv_register_t ElementStereoMode                  = {ELEMENT_STEREO_MODE, ELEMENT_TYPE_UINT, "StereoMode"};
static const mkv_register_t ElementAlphaMode                   = {ELEMENT_ALPHA_MODE, ELEMENT_TYPE_UINT, "AlphaMode"};
static const mkv_register_t ElementPixelWidth                  = {ELEMENT_PIXEL_WIDTH, ELEMENT_TYPE_UINT, "PixelWidth"};
static const mkv_register_t ElementPixelHeight                 = {ELEMENT_PIXEL_HEIGHT, ELEMENT_TYPE_UINT, "PixelHeight"};
static const mkv_register_t ElementPixelCropBottom             = {ELEMENT_PIXEL_CROP_BOTTOM, ELEMENT_TYPE_UINT, "PixelCropBottom"};
static const mkv_register_t ElementPixelCropTop                = {ELEMENT_PIXEL_CROP_TOP, ELEMENT_TYPE_UINT, "PixelCropTop"};
static const mkv_register_t ElementPixelCropLeft               = {ELEMENT_PIXEL_CROP_LEFT, ELEMENT_TYPE_UINT, "PixelCropLeft"};
static const mkv_register_t ElementPixelCropRight              = {ELEMENT_PIXEL_CROP_RIGHT, ELEMENT_TYPE_UINT, "PixelCropRight"};
static const mkv_register_t ElementDisplayWidth                = {ELEMENT_DISPLAY_WIDTH, ELEMENT_TYPE_UINT, "DisplayWidth"};
static const mkv_register_t ElementDisplayHeight               = {ELEMENT_DISPLAY_HEIGHT, ELEMENT_TYPE_UINT, "DisplayHeight"};
static const mkv_register_t ElementDisplayUint                 = {ELEMENT_DISPLAY_UINT, ELEMENT_TYPE_UINT, "DisplayUint"};
static const mkv_register_t ElementAspectRatioType             = {ELEMENT_ASPECT_RATIO_TYPE, ELEMENT_TYPE_UINT, "AspectRatioType"};
static const mkv_register_t ElementColourSpace                 = {ELEMENT_COLOUR_SPACE, ELEMENT_TYPE_BINARY, "ColourSpace"};
static const mkv_register_t ElementGammaValue                  = {ELEMENT_GAMMA_VALUE, ELEMENT_TYPE_FLOAT, "ColourSpace"};
static const mkv_register_t ElementFramerate                   = {ELEMENT_FRAME_RATE, ELEMENT_TYPE_FLOAT, "ColourSpace"};
static const mkv_register_t ElementAudio                       = {ELEMENT_AUDIO, ELEMENT_TYPE_MASTER, "Audio"};
static const mkv_register_t ElementSamplingFrequency           = {ELEMENT_SAMPLING_FREQUENCY, ELEMENT_TYPE_FLOAT, "SamplingFrequency"};
static const mkv_register_t ElementOutputSamplingFrequency     = {ELEMENT_OUTPUT_SAMPLING_FREQUENCY, ELEMENT_TYPE_FLOAT, "OutputSamplingFrequency"};
static const mkv_register_t ElementChannels                    = {ELEMENT_CHANNELS, ELEMENT_TYPE_UINT, "Channels"};
static const mkv_register_t ElementBitDepth                    = {ELEMENT_BIT_DEPTH, ELEMENT_TYPE_UINT, "BitDepth"};
static const mkv_register_t ElementTrackOperation              = {ELEMENT_TRACK_OPERATION, ELEMENT_TYPE_MASTER, "TrackOperation"};
static const mkv_register_t ElementTrackCombinePlanes          = {ELEMENT_TRACK_COMBINE_PLANES, ELEMENT_TYPE_MASTER, "TrackCombinePlanes"};
static const mkv_register_t ElementTrackPlane                  = {ELEMENT_TRACK_PLANE, ELEMENT_TYPE_MASTER, "TrackPlane"};
static const mkv_register_t ElementTrackPlaneUID               = {ELEMENT_TRACK_PLANE_UID, ELEMENT_TYPE_UINT, "TrackPlaneUID"};
static const mkv_register_t ElementTrackPlaneType              = {ELEMENT_TRACK_PLANE_TYPE, ELEMENT_TYPE_UINT, "TrackPlaneType"};
static const mkv_register_t ElementTrackJoinBlocks             = {ELEMENT_TRACK_JOIN_BLOCKS, ELEMENT_TYPE_MASTER, "TrackJoinBlocks"};
static const mkv_register_t ElementTrackJoinUID                = {ELEMENT_TRACK_JOIN_UID, ELEMENT_TYPE_UINT, "TrackJoinUID"};
static const mkv_register_t ElementContentEncodings            = {ELEMENT_CONTENT_ENCODINGS, ELEMENT_TYPE_MASTER, "ContentEncodings"};
static const mkv_register_t ElementContentEncoding             = {ELEMENT_CONTENT_ENCODING, ELEMENT_TYPE_MASTER, "ContentEncoding"};
static const mkv_register_t ElementContentEncodingOrder        = {ELEMENT_CONTENT_ENCODING_ORDER, ELEMENT_TYPE_UINT, "ContentEncodingOrder"};
static const mkv_register_t ElementContentEncodingScope        = {ELEMENT_CONTENT_ENCODING_SCOPE, ELEMENT_TYPE_UINT, "ContentEncodingScope"};
static const mkv_register_t ElementContentEncodingType         = {ELEMENT_CONTENT_ENCODING_TYPE, ELEMENT_TYPE_UINT, "ContentEncodingType"};
static const mkv_register_t ElementContentCompression          = {ELEMENT_CONTENT_COMPRESSION, ELEMENT_TYPE_MASTER, "ContentCompression"};
static const mkv_register_t ElementContentCompAlgo             = {ELEMENT_CONTENT_COMP_ALGO, ELEMENT_TYPE_UINT, "ContentCompAlgo"};
static const mkv_register_t ElementContentCompSettings         = {ELEMENT_CONTENT_COMP_SETTINGS, ELEMENT_TYPE_BINARY, "ContentCompSettings"};
static const mkv_register_t ElementContentEncryption           = {ELEMENT_CONTENT_ENCRYPTION, ELEMENT_TYPE_MASTER, "ContentEncryption"};
static const mkv_register_t ElementContentEncAlgo              = {ELEMENT_CONTENT_ENC_ALGO, ELEMENT_TYPE_UINT, "ContentEncAlgo"};
static const mkv_register_t ElementContentEncKeyID             = {ELEMENT_CONTENT_ENC_KEY_ID, ELEMENT_TYPE_UINT, "ContentEncKeyID"};
static const mkv_register_t ElementContentSignature            = {ELEMENT_CONTENT_SIGNATURE, ELEMENT_TYPE_BINARY, "ContentSignature"};
static const mkv_register_t ElementContentSigKeyID             = {ELEMENT_CONTENT_SIG_KEY_ID, ELEMENT_TYPE_BINARY, "ContentSigKeyID"};
static const mkv_register_t ElementContentSigAlgo              = {ELEMENT_CONTENT_SIG_ALGO, ELEMENT_TYPE_UINT, "ContentSigAlgo"};
static const mkv_register_t ElementContentSigHashAlgo          = {ELEMENT_CONTENT_SIG_HASH_ALGO, ELEMENT_TYPE_UINT, "ContentSigHashAlgo"};
static const mkv_register_t ElementCues                        = {ELEMENT_CUES, ELEMENT_TYPE_MASTER, "Cues"};
static const mkv_register_t ElementCuePoint                    = {ELEMENT_CUE_POINT, ELEMENT_TYPE_MASTER, "CuePoint"};
static const mkv_register_t ElementCueTime                     = {ELEMENT_CUE_TIME, ELEMENT_TYPE_UINT, "CueTime"};
static const mkv_register_t ElementCueTrackPositions           = {ELEMENT_CUE_TRACK_POSITIONS, ELEMENT_TYPE_MASTER, "CueTrackPositions"};
static const mkv_register_t ElementCueTrack                    = {ELEMENT_CUE_TRACK, ELEMENT_TYPE_UINT, "CueTrack"};
static const mkv_register_t ElementCueClusterPosition          = {ELEMENT_CUE_CLUSTER_POSITION, ELEMENT_TYPE_UINT, "CueClusterPosition"};
static const mkv_register_t ElementCueRelativePosition         = {ELEMENT_CUE_RELATIVE_POSITION, ELEMENT_TYPE_UINT, "CueRelativePosition"};
static const mkv_register_t ElementCueDuration                 = {ELEMENT_CUE_DURATION, ELEMENT_TYPE_UINT, "CueDuration"};
static const mkv_register_t ElementCueBlockNumber              = {ELEMENT_CUE_BLOCK_NUMBER, ELEMENT_TYPE_UINT, "CueBlockNumber"};
static const mkv_register_t ElementCueCodecState               = {ELEMENT_CUE_CODEC_STATE, ELEMENT_TYPE_UINT, "CueCodecState"};
static const mkv_register_t ElementCueReference                = {ELEMENT_CUE_REFERENCE, ELEMENT_TYPE_MASTER, "CueReference"};
static const mkv_register_t ElementCueRefTime                  = {ELEMENT_CUE_REF_TIME, ELEMENT_TYPE_UINT, "CueRefTime"};
static const mkv_register_t ElementAttachments                 = {ELEMENT_ATTACHMENTS, ELEMENT_TYPE_MASTER, "Attachments"};
static const mkv_register_t ElementAttachedFile                = {ELEMENT_ATTACHED_FILE, ELEMENT_TYPE_MASTER, "AttachedFile"};
static const mkv_register_t ElementFileDescription             = {ELEMENT_FILE_DESCRIPTION, ELEMENT_TYPE_UNICODE, "FileDescription"};
static const mkv_register_t ElementFileName                    = {ELEMENT_FILE_NAME, ELEMENT_TYPE_UNICODE, "FileName"};
static const mkv_register_t ElementFileMimeType                = {ELEMENT_FILE_MIME_TYPE, ELEMENT_TYPE_STRING, "FileMimeType"};
static const mkv_register_t ElementFileData                    = {ELEMENT_FILE_DATA, ELEMENT_TYPE_BINARY, "FileData"};
static const mkv_register_t ElementFileUID                     = {ELEMENT_FILE_UID, ELEMENT_TYPE_UINT, "FileUID"};
static const mkv_register_t ElementChapters                    = {ELEMENT_CHAPTERS, ELEMENT_TYPE_MASTER, "Chapters"};
static const mkv_register_t ElementEditionEntry                = {ELEMENT_EDITION_ENTRY, ELEMENT_TYPE_MASTER, "EditionEntry"};
static const mkv_register_t ElementEditionUID                  = {ELEMENT_EDITION_UID, ELEMENT_TYPE_UINT, "EditionUID"};
static const mkv_register_t ElementEditionFlagHidden           = {ELEMENT_EDITION_FLAG_HIDDEN, ELEMENT_TYPE_UINT, "EditionFlagHidden"};
static const mkv_register_t ElementEditionFlagDefault          = {ELEMENT_EDITION_FLAG_DEFAULT, ELEMENT_TYPE_UINT, "EditionFlagDefault"};
static const mkv_register_t ElementEditionFlagOrdered          = {ELEMENT_EDITION_FLAG_ORDERED, ELEMENT_TYPE_UINT, "EditionFlagOrdered"};
static const mkv_register_t ElementChapterAtom                 = {ELEMENT_CHAPTER_ATOM, ELEMENT_TYPE_MASTER, "ChapterAtom"};
static const mkv_register_t ElementChapterUID                  = {ELEMENT_CHAPTER_UID, ELEMENT_TYPE_UINT, "ChapterUID"};
static const mkv_register_t ElementChapterStringUID            = {ELEMENT_CHAPTER_STRING_UID, ELEMENT_TYPE_UNICODE, "ChapterStringUID"};
static const mkv_register_t ElementChapterTimeStart            = {ELEMENT_CHAPTER_TIME_START, ELEMENT_TYPE_UINT, "ChapterTimeStart"};
static const mkv_register_t ElementChapterTimeEnd              = {ELEMENT_CHAPTER_TIME_END, ELEMENT_TYPE_UINT, "ChapterTimeEnd"};
static const mkv_register_t ElementChapterFlagHidden           = {ELEMENT_CHAPTER_FLAG_HIDDEN, ELEMENT_TYPE_UINT, "ChapterFlagHidden"};
static const mkv_register_t ElementChapterFlagEnabled          = {ELEMENT_CHAPTER_FLAG_ENABLED, ELEMENT_TYPE_UINT, "ChapterFlagEnabled"};
static const mkv_register_t ElementChapterSegmentUID           = {ELEMENT_CHAPTER_SEGMENT_UID, ELEMENT_TYPE_BINARY, "ChapterSegmentUID"};
static const mkv_register_t ElementChapterSegmentEditionUID    = {ELEMENT_CHAPTER_SEGMENT_EDITION_UID, ELEMENT_TYPE_UINT, "ChapterSegmentEditionUID"};
static const mkv_register_t ElementChapterPhysicalEquiv        = {ELEMENT_CHAPTER_PHYSICAL_EQUIV, ELEMENT_TYPE_UINT, "ChapterPhysicalEquiv"};
static const mkv_register_t ElementChapterTrack                = {ELEMENT_CHAPTER_TRACK, ELEMENT_TYPE_MASTER, "ChapterTrack"};
static const mkv_register_t ElementChapterTrackNumber          = {ELEMENT_CHAPTER_TRACK_NUMBER, ELEMENT_TYPE_UINT, "ChapterTrackNumber"};
static const mkv_register_t ElementChapterDisplay              = {ELEMENT_CHAPTER_DISPLAY, ELEMENT_TYPE_MASTER, "ChapterDisplay"};
static const mkv_register_t ElementChapString                  = {ELEMENT_CHAP_STRING, ELEMENT_TYPE_UNICODE, "ChapString"};
static const mkv_register_t ElementChapLanguage                = {ELEMENT_CHAP_LANGUAGE, ELEMENT_TYPE_STRING, "ChapLanguage"};
static const mkv_register_t ElementChapCountry                 = {ELEMENT_CHAP_COUNTRY, ELEMENT_TYPE_STRING, "ChapCountry"};
static const mkv_register_t ElementChapProcess                 = {ELEMENT_CHAP_PROCESS, ELEMENT_TYPE_MASTER, "ChapProcess"};
static const mkv_register_t ElementChapProcessCodecID          = {ELEMENT_CHAP_PROCESS_CODEC_ID, ELEMENT_TYPE_UINT, "ChapProcessCodecID"};
static const mkv_register_t ElementChapProcessPrivate          = {ELEMENT_CHAP_PROCESS_PRIVATE, ELEMENT_TYPE_BINARY, "ChapProcessPrivate"};
static const mkv_register_t ElementChapProcessCommand          = {ELEMENT_CHAP_PROCESS_COMMAND, ELEMENT_TYPE_MASTER, "ChapProcessCommand"};
static const mkv_register_t ElementChapProcessTime             = {ELEMENT_CHAP_PROCESS_TIME, ELEMENT_TYPE_UINT, "ChapProcessTime"};
static const mkv_register_t ElementChapProcessData             = {ELEMENT_CHAP_PROCESS_DATA, ELEMENT_TYPE_BINARY, "ChapProcessData"};

/*
 * Main library calls
 * Returns false (0) in case of failure
 */
bool           mkv_element_parse(mkv_buffer_t* buffer, mkv_element_t* element);
void           mkv_element_free(mkv_element_t* element);

/*
 * Element parsing functionality
 * The buffer parameter contains the data to parse
 * These functions return 0 in case of failure
 */
size_t         mkv_element_id(mkv_buffer_t* buffer, uint32_t* id);
size_t         mkv_element_size(mkv_buffer_t* buffer, size_t* size);

/*
 * Get the element register corresponding to the specified ID
 */
mkv_register_t mkv_register_id(uint32_t id);
