#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

#include <mysql.h>

/**********************************
  hello
  
  hello(name);
  
  RETURN string
*/

my_bool
hello_init(UDF_INIT *initid,
           UDF_ARGS *args,
           char     *message)
{
	if (args->arg_count != 1) {
		strcpy(message, "requires one arguments.");
		return EXIT_FAILURE;
	}
	if (args->args[0] == NULL) {
		initid->ptr = NULL;
	} else {
		if (args->arg_type[0] != STRING_RESULT) {
			strcpy(message, "invalid arguments.");
			return EXIT_FAILURE;
		}
	}
	
	initid->maybe_null = 1;
	return EXIT_SUCCESS;
}


void
hello_deinit(UDF_INIT *initid)
{
	if (initid->ptr != NULL) {
		free(initid->ptr);
	}
}


char*
hello(UDF_INIT      *initid,
      UDF_ARGS      *args,
      char          *result,
      unsigned long *length,
      char          *is_null,
      char          *error)
{
	// check arguments
	if (args->args[0] == NULL) {
		*is_null = 1;
		return NULL;
	} else {
		if (args->arg_type[0] != STRING_RESULT) {
			// invalid arguments
			*error   = 1;
			return NULL;
		}
	}

	result = malloc(strlen(args->args[0]) + 8 + 1); 
    sprintf(result, "Hello, %s!", args->args[0]);

final:
	if (result != NULL) {
		*length = strlen(result);
		initid->max_length = *length;
		initid->ptr = result;
	} else {
		*is_null = 1;
	}
	return result;
}