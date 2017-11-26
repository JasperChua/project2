/*
 * ICT1002 Assignment 2, 2017-18 Trimester 1.
 *
 * This file implements all of the campus designer commands using the functions
 * provided in other files.
 *
 * All of the functions in this file (except do_file_command and
 * do_design_command) accept a single argument, being a string containing the
 * argument passed to the command. This string may be NULL or empty if the
 * command does not use an argument.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "campus1002.h"


/*
 * Execute a command in file mode.
 *
 * Input:
 *   command - a string containing the command (may be an empty string)
 *   arg - a string containing the argument (may be an empty string)
 *
 * Returns:
 *   0, if the program should continue
 *   1, if the command indicates that the interpreter should exit
 */
int do_file_command(const char *command, const char *arg) {

	int done = 0;	/* return value */

	if (command == NULL || strlen(command) == 0) {
		/* blank line; do nothing and return */
		return 0;
	}
	
	/* determine which command was given and execute the appropriate function */
	if (compare_token(command, "help") == 0)
		do_file_help(arg);
	else if (compare_token(command, "new") == 0)
		do_file_new(arg);
	else if (compare_token(command, "open") == 0)
		do_file_open(arg);
	else if (compare_token(command, "exit") == 0)
		done = 1;
	else
		printf("Unrecognised command: %s.\n", command);
	
	return done;
	
}


/*
 * File mode HELP command.
 */
void do_file_help(const char *arg) {
	
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "new") == 0)
		printf("NEW              Create a new design.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "open") == 0)
		printf("OPEN <filename>  Load a design from <filename>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "exit") == 0)
		printf("EXIT             Leave the program.\n");
	
}


/*
 * File mode NEW command.
	Junaidi
 */
void do_file_new(const char *arg) {
	// get name, x dim, y dim
	char name[MAX_NAME];
	int xdim = 0; 
	int ydim = 0;

	printf("Enter a name for the new design: ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';
	do {
		printf("Enter the X dimension: ");
		scanf("%d", &xdim);
	} while (xdim <= 0);
	do {
		printf("Enter the Y dimension: ");
		scanf("%d", &ydim);
	} while (ydim <= 0);

	// initialise map
	int status = map_init(name, xdim, ydim);

	if (status == 0) {
		// carry on to next part
		main_design();
	}
	else {
		printf("Memory allocation error. Please try again.");
	}
}


/*
 * File mode OPEN command.
 */
void do_file_open(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Execute a command in design mode.
 *
 * Input:
 *   command - a string containing the command (may be an empty string)
 *   arg - a string containing the argument (may be an empty string)
 *
 * Returns:
 *   0, if the program should continue
 *   1, if the command indicates that the interpreter should exit
 */
int do_design_command(const char *command, const char *arg) {

	int done = 0;	/* return value */

	if (command == NULL || strlen(command) == 0) {
		/* blank line; do nothing and return */
		return 0;
	}
	
	/* determine which command was given and execute the appropriate function */
	if (compare_token(command, "help") == 0)
		do_design_help(arg);
	else if (compare_token(command, "add") == 0)
		do_design_add(arg);
	else if (compare_token(command, "delete") == 0)
		do_design_delete(arg);
	else if (compare_token(command, "display") == 0)
		do_design_display(arg);
	else if (compare_token(command, "list") == 0)
		do_design_list(arg);
	else if (compare_token(command, "move") == 0)
		do_design_move(arg);
	else if (compare_token(command, "resize") == 0)
		do_design_resize(arg);
	else if (compare_token(command, "rename") == 0)
		do_design_rename(arg);
	else if (compare_token(command, "save") == 0)
		do_design_save(arg);
	else if (compare_token(command, "exit") == 0)
		done = 1;
	else
		printf("Unrecognised command: %s.\n", command);
	
	return done;
	
}


/*
 * Design mode HELP command.
 */
void do_design_help(const char *arg) {
	
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "display") == 0)
		printf("DISPLAY          Show the current map.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "display") == 0)
		printf("DISPLAY <id>     Show the details of the feature with identifier <id>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "add") == 0)
		printf("ADD <id>         Create a new feature with identifer <id>\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "delete") == 0)
		printf("DELETE <id>      Delete the feature with identifier <id>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "list") == 0)
		printf("LIST             List all of the features on the map.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "move") == 0)
		printf("MOVE <id>        Move the feature with identifier <id>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "rename") == 0)
		printf("RENAME <id>      Rename the feature with identifier <id>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "resize") == 0)
		printf("RESIZE <id>      Resize the feature with identifier <id>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "save") == 0)
		printf("SAVE <filename>  Save the current map in <filename>.\n");
	if (arg == NULL || arg[0] == '\0' || compare_token(arg, "exit") == 0)
		printf("EXIT             Stop editing and return to file mode.\n");
	
}


/*
 * Design mode ADD command.
 */
void do_design_add(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode delete command.
 */
void do_design_delete(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode DISPLAY command.
	Junaidi
 */
void do_design_display(const char *arg) {
	// call map_print() to display current map
	map_print();
	
}


/*
 * Design mode LIST command.
 */
void do_design_list(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode MOVE command.
 */
void do_design_move(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode RENAME command.
 */
void do_design_rename(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode RESIZE command.
 */
void do_design_resize(const char *arg) {
	
	/* to be implemented */
	
}


/*
 * Design mode SAVE command.
 */
void do_design_save(const char *arg) {
	
	/* to be implemented */
	
}