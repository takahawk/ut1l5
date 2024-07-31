#ifndef DESCRIBE_H_
#define DESCRIBE_H_

#include "w/d4t4-5tructur35/buffer.h"
#include "w/d4t4-5tructur35/string_.h"

#define u_DESCRIBE_MAX_BUFFER_BYTES 40

#define u_Describe(X) _Generic(X, \
	Buffer: _u_DescribeBuffer \
	) (X)

String
_u_DescribeBuffer(Buffer);

#endif
