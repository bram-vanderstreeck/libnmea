#ifndef INC_NMEA_PARSER_H
#define INC_NMEA_PARSER_H

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>
#include "nmea.h"
#include "parser_types.h"

typedef int (*allocate_data_f) (nmea_parser_s *);
typedef int (*set_default_f) (nmea_parser_s *);
typedef int (*free_data_f) (nmea_parser_s *);
typedef int (*parse_f) (nmea_parser_s *, char *, int);

typedef struct {
  nmea_parser_s parser;
	int errors;

  /* Functions */
	allocate_data_f allocate_data;
	set_default_f set_default;
	free_data_f free_data;
	parse_f parse;
} nmea_parser_module_s;

typedef int (*init_f) (nmea_parser_s *);

#define NMEA_NUM_PARSERS  12
nmea_parser_module_s *parsers[NMEA_NUM_PARSERS];

/**
 * Load the parser libs into array.
 *
 * Returns 0 on success, or -1 if an error occurs.
 */
int nmea_load_parsers();

/**
 * Initiate a parser.
 *
 * Returns a sentence parser struct, or (nmea_parser_module_s *) NULL if an error occurs.
 */
nmea_parser_module_s * nmea_init_parser(const char *filename);

/**
 * Get a parser for a sentence type.
 *
 * Returns the sentence parser struct, should be checked for NULL.
 */
nmea_parser_module_s * nmea_get_parser_by_type(nmea_t type);

/**
 * Get a parser for a sentence type by a sentence string.
 *
 * Returns the sentence parser struct, should be checked for NULL.
 */
nmea_parser_module_s * nmea_get_parser_by_sentence(const char *sentence);

#endif  /* INC_NMEA_PARSER_H */
