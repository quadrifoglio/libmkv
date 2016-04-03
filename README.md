# libmkv

Simple mvk/webm parser for C.

## Usage

```c
#include "mkv.h"

mkv_buffer_t buf;
buf.len = ...; // File length
buf.data = ...; // File data

while(1) {
	mkv_element_t element;

	if(!mkv_element_parse(&buf, &element)) {
		printf("Exiting");
		break;
	}

	printf("Element %s - Size %zu\n", element.type.name, element.content.len);
	mkv_element_free(&element);
}
```
