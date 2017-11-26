/*
 * ICT1002 Assignment 2, 2017-18 Trimester 1.
 *
 * This file implements the main program, including parsing of commands in
 * file mode and design mode.
 *
 * DO NOT MODIFY THIS FILE. You may invoke its functions if you like, however.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campus1002.h"
 
 
 /*
  * Main method.
  */
int main(char *argv[], int argc) {

	int num_tokens;				/* the number of tokens in the input */
	char command[MAX_INPUT];	/* buffer for holding the command */
	char arg[MAX_INPUT];		/* buffer for holding the argument */
	int done = 0;				/* set to 1 to end the main loop */
	
	/* print a welcome message */
	printf("Welcome to the ICT1002 Campus Designer.\n");
	do_file_help(NULL);
	
	/* main command loop */
	while (!done) {
	
		/* read a line of input */
		printf("? ");
		num_tokens = lscanf("%s%s", command, arg);
		
		if (num_tokens == 1) {
			/* command with no argument */
			done = do_file_command(command, NULL);
		} else if (num_tokens == 2) {
			/* command with an argument */
			done = do_file_command(command, arg);
		}
		
	}
	
	/* print a goodbye message */
	printf("Goodbye!\n");
	
	return 0;
}

	
/*
 * Design mode command processor.
 */
void main_design() {

	int num_tokens;				/* the number of tokens in the input */
	char command[MAX_INPUT];	/* buffer for holding the command */
	char arg[MAX_INPUT];		/* buffer for holding the argument */
	int done = 0;				/* set to 1 to end the main loop */
	
	/* print some help text */
	do_design_help(NULL);
	
	/* main command loop */
	while (!done) {
	
		/* read a line of input */
		printf("? ");
		num_tokens = lscanf("%s%s", command, arg);
		
		if (num_tokens == 1) {
			/* command with no argument */
			done = do_design_command(command, NULL);
		} else if (num_tokens == 2) {
			/* process the command */
			done = do_design_command(command, arg);
		}
		
	}
	
	/* give feedback to the user that we're exiting design mode */
	printf("Leaving design mode.\n");
	
}


/*
 * Utility function for comparing commands, arguments, etc. case-insensitively.
 *
 * Input:
 *   token1 - the first token
 *   token2 - the second token
 *
 * Returns:
 *   as strcmp()
 */
int compare_token(const char *token1, const char *token2) {
	
	int i = 0;
	while (token1[i] != '\0' && token2[i] != '\0') {
		if (toupper(token1[i]) < toupper(token2[i]))
			return -1;
		else if (toupper(token1[i]) > toupper(token2[i]))
			return 1;
		i++;
	}
	
	if (token1[i] == '\0' && token2[i] == '\0')
		return 0;
	else if (token1[i] == '\0')
		return -1;
	else
		return 1;
	
}


/*
 * Utility function for parsing a line of input, ensuring that everything is
 * read to the end of the line.
 *
 * The format string for this function also accepts a special format string
 * "%z", which will read the whole line into the first non-format argument.
 * This argument should have space for at least MAX_INPUT characters.
 *
 * Input:
 *   as scanf()
 *
 * Returns:
 *   the number of tokens successfully parse
 */
int lscanf(const char *format, ...) {
	
	char line[MAX_INPUT];	/* buffer for holding the line of input */
	
	/* initialise variable argument list */
	va_list args;
	va_start(args, format);
	
	/* read the line */
	fgets(line, MAX_INPUT, stdin);
	
	int num_tokens = 0;
	if (format[0] == '%' && format[strlen(format) - 1] == 'z') {
		
		/* get the maximum number of characters to read, if any */
		int n = atoi(format + 1);
		if (n <= 0)
			n = MAX_INPUT;
		
		/* copy the whole line, up to n characters */
		char *output = va_arg(args, char *);
		strncpy(output, line, n);
		num_tokens = 1;
		
		/* remove the trailing '\n' */
		char *p = strchr(output, '\n');
		if (p != NULL)
			*p = '\0';
		
	} else {
	
		/* pass to scanf */
		num_tokens = vsscanf(line, format, args);
		
	}
	
	/* clean up variable argument list */
	va_end(args);
	
	return num_tokens;
}