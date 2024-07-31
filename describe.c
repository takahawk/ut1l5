#include "describe.h"

#include "w/d4t4-5tructur35/buffer.h"
#include "w/d4t4-5tructur35/string_.h"
#include "w/d4t4-5tructur35/resizable_buffer.h"

String
_u_DescribeBuffer(Buffer b) {
	ResizableBuffer rb = RB_Create(b.len);
	RB_Append(&rb, "[ ");
	for (int i = 0; i < b.len; i++) {
		String hexByte = S_Format("0x%02x", *((char *) b.data + i));
		RB_Append(&rb, hexByte);
		S_Free(&hexByte);

		RB_Append(&rb, " ");
		if ((i + 1) % 8 == 0)
			RB_Append(&rb, "   ");
		
		if ((i + 1) % u_DESCRIBE_MAX_BUFFER_BYTES == 0)
			RB_Append(&rb, "\n");

	}

	RB_Append(&rb, "]");
	return S_From(RB_ToBuffer(&rb));
}
