/*
 * ICT1002 Assignment 2, 2017-18 Trimester 1.
 *
 * This file contains the definitions and function prototypes for all of
 * features of the campus designer.
 */
 
#ifndef _CAMPUS1002_H
#define _CAMPUS1002_H
 
#include <stdint.h>
#include <stdio.h>
 
 
/* the maximum number of characters we expect in a line of input */
#define MAX_INPUT   256

/* the maximum length of a feature identifier (including the terminating null) */
#define MAX_ID      12

/* the maximum length of a feature name (including the terminating null) */
#define MAX_NAME    256

/* error codes for functions that might fail */
#define ERROR_NONE   0
#define ERROR_NOMEM  -1
#define ERROR_FILE   -2

/* the character code for each feature */
#define FEATURE_NONE        ' '
#define FEATURE_BUILDING    '#'
#define FEATURE_GREENSPACE  '.'
#define FEATURE_ROAD        '_'
#define FEATURE_WALKWAY     '*'

/* a structure for representing features */
typedef struct feature_struct {
	char        type;            /* feature type */
	char        id[MAX_ID];      /* unique identifier */
	char        name[MAX_NAME];  /* name */
	int32_t     xloc;            /* x location */
	int32_t     yloc;            /* y location */
	int32_t     xdim;            /* x dimension */
	int32_t     ydim;            /* y dimension */
} FEATURE;
 
 
/* functions defined in main.c */
void main_design();
int compare_token(const char *token1, const char *token2);
int lscanf(const char *format, ...);


/* functions defined in commands.c */
int do_file_command(const char *command, const char *arg);
void do_file_help(const char *arg);
void do_file_new(const char *arg);
void do_file_open(const char *arg);
int do_design_command(const char *command, const char *arg);
void do_design_help(const char *arg);
void do_design_add(const char *arg);
void do_design_delete(const char *arg);
void do_design_display(const char *arg);
void do_design_list(const char *arg);
void do_design_move(const char *arg);
void do_design_rename(const char *arg);
void do_design_resize(const char *arg);
void do_design_save(const char *arg);
 
 
/* functions defined in features.c */
FEATURE * features_add(char type, const char *id, const char *name, int xloc, int yloc, int xdim, int ydim);
void features_close();
void features_delete(FEATURE *feature);
FEATURE * features_get();
void features_init();
void features_list();
void features_print(FEATURE *feature);
int features_read(FILE *f);
FEATURE * features_validate_geometry(const char *id, int xloc, int yloc, int xdim, int ydim);
int features_write(FILE *f);

/* functions defined in map.c */
void map_close();
int map_init(const char *name, int xdim, int ydim);
void map_print();
void map_put_feature(FEATURE *feature);
int map_read(FILE *f);
void map_remove_feature(FEATURE *feature);
int map_validate_geometry(int xloc, int yloc, int xdim, int ydim);
int map_write(FILE *f);

#endif