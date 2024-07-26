#include "files.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#include "d4t4-5tructur35/buffer.h"

Buffer
uF_ReadFile(FILE *f) {
	char* buffer;

	if (!f) {
		printf("file is NULL\n");
		return B_Null();
	}

	fseek(f, 0, SEEK_END);
	int len = ftell(f);
	fseek(f, 0, SEEK_SET);

	buffer = malloc(len);

	int fd = fileno(f);

	void *mapping = mmap(0, len, PROT_READ, MAP_PRIVATE, fd, 0);
	memcpy(buffer, mapping, len);
	munmap(mapping, len);

	return B_As(buffer, len);
}

Buffer
uF_ReadFileByName(char* filename) {
	FILE *f = fopen(filename, "rb");

	if (f == NULL) {
		printf("Failed to open file: %s\n", filename);
		return B_Null();
	}

	Buffer buf = uF_ReadFile(f);
	fclose(f);

	return buf;
}
