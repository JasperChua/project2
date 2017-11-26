/*
 * ICT1002 Assignment 2, 2017-18 Trimester 1.
 *
 * This file implements all of the functions for creating and manipulating
 * the map.
 */

#include <stdlib.h>
#include <string.h>
#include "campus1002.h"

/* declare your internal variables here */
// pointer to head of feature list
FEATURE *headPtr = NULL;
// pointer to map array for displaying
char **mapPtr = NULL; 
int mapxdim = 0;
int mapydim = 0;

/*
 * Deallocate the current map.
 */
void map_close() {
	
	/* to be implemented */
	
}

/*
 * Create a new empty map, erasing any existing map.
 *
 * Input:
 *   name - the name of the map
 *   xdim - the x dimension of the new map
 *   ydim - the y dimension of the new map
 *
 * Returns:
 *   0, if successful
 *   ERROR_NOMEM, if memory could not be allocated
 * Junaidi
 */
int map_init(const char *name, int xdim, int ydim) {
	// create map and set pointer
	char **map = malloc(sizeof *map * ydim);
	if (map) {
		for (int i = 0; i < ydim; i++) {
			map[i] = malloc(sizeof *map * xdim);
		}
		mapxdim = xdim;
		mapydim = ydim;

		// set map pointer to created map
		mapPtr = map;
	}
	// if malloc fails
	else {
		return ERROR_NOMEM;
	}
	

	// populate map with FEATURE_NONE
	for (int i = 0; i < ydim; i++) {
		for (int j = 0; j < xdim; j++) {
			map[i][j] = FEATURE_NONE;
		}
	}

	// create first node of linked list to store map
	FEATURE *mapNode = (FEATURE *)malloc(sizeof(FEATURE));
	if (mapNode != NULL) {
		mapNode->type = FEATURE_NONE;
		strcpy(mapNode->id, "MAP");
		strcpy(mapNode->name, name);
		mapNode->xloc = 0;
		mapNode->yloc = 0;
		mapNode->xdim = xdim;
		mapNode->ydim = ydim;

		// assign head to map node
		headPtr = mapNode;
	}
	else {
		return ERROR_NOMEM;
	}

	return 0;
}


/*
 * Print the map on the screen.
 * Junaidi
 */
void map_print() {
	// print map using mapPtr
	// how to print
	for (int i = 0; i < mapydim; i++) {
		for (int j = 0; j < mapxdim; j++) {
			printf("%c", mapPtr[i][j]);
		}
		printf("\n");
	}
}


/*
 * Add a feature to the map.
 *
 * This function does not check that the feature is in a valid location. Use
 * map_validate_geometry() and features_validate_geometry() to check that the
 * feaures lies within the map boundaries and does not conflict with any
 * other features, respectively, before invoking this function.
 *
 * Input:
 *   feature - a pointer to the feature structure to be added
 */
void map_put_feature(FEATURE *feature) {
	
	/* to be implemented */
		
}


/*
 * Create a map from a map record in a file.
 *
 * Input:
 *   f - the file
 *
 * Returns:
 *   0, if successful
 *   ERROR_NOMEM, if memory allocation failed
 *   ERROR_FILE, if there was a file error
 */
int map_read(FILE *f) {
	
	/* to be implemented */
	return 0;
	
}


/*
 * Remove a feature from the map.
 *
 * Input:
 *   feature - a pointer to the feature structure to be removed
 */
void map_remove_feature(FEATURE *feature) {
	
	/* to be implemented */
			
}


/*
 * Check that a rectangle lies within the map boundaries.
 *
 * Input:
 *   xloc    - the x location of the rectangle
 *   yloc    - the y location of the rectangle
 *   xdim    - the x dimension of the rectangle
 *   ydim    - the y dimension of the rectangle
 *
 * Returns:
 *   0, if some part of the rectangle lies outside the map boundaries
 *   1, if the entire rectangle lies within the map boundaries
 */
int map_validate_geometry(int xloc, int yloc, int xdim, int ydim) {
	
	/* to be implemented */
	return 0;
}


/*
 * Write the map record to a file.
 *
 * Input:
 *   f - the file
 *
 * Returns:
 *   ERROR_NONE, if writing was successful
 *   ERROR_FILE, otherwise
 */
int map_write(FILE *f) {
	
	/* to be implemented */
	return ERROR_NONE;
	
}