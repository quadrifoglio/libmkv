#include <stdio.h>
#include "mkv.h"

int main(void) {
	FILE* f = fopen("test.webm", "r");
	if(!f) {
		return 1;
	}

	fseek(f, 0, SEEK_END);
	size_t sz = ftell(f);
	fseek(f, 0, SEEK_SET);

	mkv_buffer_t buf;
	buf.len = sz;
	buf.data = malloc(sz);

	fread(buf.data, 1, buf.len, f);

	while(1) {
		mkv_element_t element;

		if(!mkv_element_parse(&buf, &element)) {
			printf("Exiting");
			break;
		}

		printf("Element %s - Size %zu\n", element.type.name, element.content.len);
		mkv_element_free(&element);
	}

	return 0;
}
