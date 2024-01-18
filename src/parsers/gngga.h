#ifndef INC_NMEA_GNGGA_H
#define INC_NMEA_GNGGA_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	struct tm time;
	nmea_position longitude;
	nmea_position latitude;
	int n_satellites;
	double altitude;
	char altitude_unit;
	double undulation;
	char undulation_unit;
	unsigned char position_fix;
} nmea_gngga_s;

/* Value indexes */
#define NMEA_GNGGA_TIME			0
#define NMEA_GNGGA_LATITUDE		1
#define NMEA_GNGGA_LATITUDE_CARDINAL	2
#define NMEA_GNGGA_LONGITUDE		3
#define NMEA_GNGGA_LONGITUDE_CARDINAL	4
#define NMEA_GNGGA_POSITION_FIX		5
#define NMEA_GNGGA_N_SATELLITES		6
#define NMEA_GNGGA_ALTITUDE		8
#define NMEA_GNGGA_ALTITUDE_UNIT	9
#define NMEA_GNGGA_UNDULATION		10
#define NMEA_GNGGA_UNDULATION_UNIT	11

#define INVALID_UNDULATION -9999.999

#endif  /* INC_NMEA_GNGGA_H */
