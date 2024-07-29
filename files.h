#ifndef FILES_H_
#define FILES_H_

#include <stdio.h>

#include "w/d4t4-5tructur35/buffer.h"

// reads file to buffer. user is responsible for freeing buffer afterwards
// returns null buffer on error
Buffer
uF_ReadFile(FILE *file);

// same as uF_ReadFile, but opens file for you
Buffer
uF_ReadFileByName(char* filename);

#endif
