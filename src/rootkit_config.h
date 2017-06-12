#ifndef ROOTKIT_CONFIG_H
#define ROOTKIT_CONFIG_H

// Rootkit configuration
#define ROOTKIT_NAME "rootkit"
#define ROOTKIT_VERSION "0.0.1"
#define ROOTKIT_DEBUG 1
#define ROOTKIT_INTERCEPT_OUTPUT "/tmp/php-module-rootkit.txt"

// Custom printf macro to strip all debug messages on compile-time
// Removes debugging strings from appearing during runtime & in the binary
#if ROOTKIT_DEBUG == 1
#define ROOTKIT_PRINTF(...) php_printf(__VA_ARGS__)
#else
#define ROOTKIT_PRINTF(...) ((void) 0)
#endif

// Prevents my IDE from screaming that certain macro's are not defined
#ifndef SUCCESS
#define SUCCESS 1
#endif

#endif
