/* -*- mode: c; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*-
 *
 * Conky, a system monitor, based on torsmo
 *
 * Any original torsmo code is licensed under the BSD license
 *
 * All code written since the fork of torsmo is licensed under the GPL
 *
 * Please see COPYING for details
 *
 * Copyright (c) 2004, Hannu Saransaari and Lauri Hakkarainen
 * Copyright (c) 2005-2009 Brenden Matthews, Philip Kovacs, et. al.
 *	(see AUTHORS)
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef WEATHER_H_
#define WEATHER_H_

#include "config.h"

/* WEATHER data */
typedef struct PWEATHER_ {
	char lastupd[32];
#ifdef XOAP
	char xoap_t[32];
	char icon[3];
#endif /* XOAP */
	int temp;
	int dew;
	int cc;
	int bar;
	int wind_s;
	int wind_d;
	int hmid;
	int wc;
} PWEATHER;

#ifdef XOAP
typedef struct PWEATHER_FORECAST_ {
	int hi[5];
	int low[5];
	char icon[5][3];
	char xoap_t[5][32];
	int wind_s[5];
	int wind_d[5];
	int hmid[5];
	int ppcp[5];
} PWEATHER_FORECAST;
#endif /* XOAP */

/* Prototypes */
void weather_free_info(void);
void weather_process_info(char *p, int p_max_size, char *uri, char *data_type, int interval);
#ifdef XOAP
void weather_forecast_process_info(char *p, int p_max_size, char *uri, unsigned int day, char *data_type, int interval);
#endif /* XOAP */
int process_weather_uri(char *uri, char *locID, int dayf);

#ifdef XOAP
void load_xoap_keys(void);
#endif /* XOAP */


#endif /*WEATHER_H_*/
