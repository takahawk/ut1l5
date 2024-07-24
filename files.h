#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>

#include "d4t4-5tructur35/buffer.h"

// reads file to buffer. user is responsible for freeing buffer afterwards
Buffer
FILES_ReadFile(FILE *file);

#endif
