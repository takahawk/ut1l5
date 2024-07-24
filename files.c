#include "files.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#include "d4t4-5tructur35/buffer.h"

Buffer
FILES_ReadFile(FILE *f) {
	char* buffer;

	if (!f) {
		printf("file is NULL\n");
		return NullBuffer();
	}

	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);

	buffer = malloc(len);

	int fd = fileno(f);

	void *mapping = mmap(0, len, PROT_READ, MAP_PRIVATE, fd, 0);
	memcpy(buffer, mapping, len);
	munmap(mapping, len);

	return AsBuffer(buffer, len);
}
