#ifndef IO_H_
#define IO_H_

#include "w/d4t4-5tructur35/string_.h"

#define CLI_COLOR_RED     "\x1B[31m"
#define CLI_COLOR_GREEN   "\x1B[32m"
#define CLI_COLOR_YELLOW  "\x1B[33m"
#define CLI_COLOR_BLUE    "\x1B[34m"
#define CLI_COLOR_MAGENTA "\x1B[35m"
#define CLI_COLOR_CYAN    "\x1B[36m"
#define CLI_COLOR_WHITE   "\x1B[37m"
#define CLI_COLOR_RESET   "\x1B[0m"


// original string will be consumed
static inline String
uIO_MakeRed(String string) {
	String result = S_Format("%s%s%s", CLI_COLOR_RED, string.str, CLI_COLOR_RESET);
	S_Free(&string);	
	return result;
}

// original string will be consumed
static inline String
uIO_MakeGreen(String string) {
	String result = S_Format("%s%s%s", CLI_COLOR_GREEN, string.str, CLI_COLOR_RESET);
	S_Free(&string);	
	return result;
}

#endif
