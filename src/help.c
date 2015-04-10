/*
 * This file is part of Audio switch daemon.
 * Audio switch daemon is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * Audio switch daemon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Audio switch daemon.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#include "version.h"


/*
 * Print short help
 */
void print_help()
{
  printf("Audio switch daemon\n");
  printf("Usage:\n");
  printf("\t asd [OPTIONS]\n");
  printf("\n");
  printf("Help options:\n");
  printf("\t --help \t show help page\n");
  printf("\n");
  printf("Config options:\n");
  printf("\t --pin \t\t change GPIO pin (default is GPIO 17)\n");
  printf("\t --socket \t path to mpd socket file\n");
  printf("\t --no-daemon \t don't detach from console\n");
  printf("\n");
  printf("Report bugs to: fabian.m.stahl@posteo.de\n");
  printf("asd home page: <http://www.github.com/fast90/audioswitch/>\n");
}

/*
 * Print version
 */

void print_version()
{
  printf("asd, version %s\n",VERSION);
}
