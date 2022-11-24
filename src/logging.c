#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void logging(const char *header, const char *msg, ...)
{
	va_list args;
	va_start(args, msg);
	size_t headerlen = strlen(header);
	char *format = calloc(sizeof(char), strlen(msg) + headerlen);
	strcpy(format, header);
	strcpy(format + headerlen, msg);
	vfprintf(stdout, format, args);
	va_end(args);
	printf("\n");
	free(format);
}