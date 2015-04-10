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

#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

#include "help.h"
#include "version.h"
#include "options.h"
#include "arguments.h"

/*
 * Parse Arguments, set Flags
 */

void parse_arguments(int argc, char *argv[])
{

  int c;
  int option_index = 0;

  /*Set defaults*/
  daemon_flag = 1;
  sock_path = "/home/pi/.mpd/socket";
  switch_pin = 17;

  while(1)
    {
      static struct option long_options[] =
      {
        {"no-daemon",   no_argument, &daemon_flag, 0},
        /* These options don’t set a flag.*/
        {"help",    no_argument,       0, 'h'},
        {"version", no_argument,       0, 'v'},
        {"pin",     required_argument, 0, 'p'},
        {"socket",	required_argument, 0, 's'},
        {0, 0, 0, 0}
      };

      c = getopt_long (argc, argv, "hvkP:s:p:c:",long_options,
                       &option_index);

      if(c==-1)
        break;

      switch(c)
        {
        case 0:
          /* If this option set a flag, do nothing else now. */
          if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'h':
          print_help();
          exit(EXIT_SUCCESS);
          break;

        case 'v':
          print_version();
          exit(EXIT_SUCCESS);
          break;

        case 'p':
          switch_pin=eval_pin(atoi(optarg));
          break;

        case 's':
          sock_path = optarg;

        case '?':
          printf ("Unknown arguments. See asd --help for arguments.\n");
          exit(EXIT_FAILURE);
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }
}

/*
 * Check if pin is in usable GPIO range.
 * Return default (GPIO 17) if pin is out of range.
 * Otherwise return pin
 */

uint8_t eval_pin(int pin)
{

  if ( pin < 0 || pin == 5 || pin ==6 || pin == 12 || pin == 13 || pin == 16 || pin == 19 || pin == 20 || pin == 26 || pin > 31)
    {
      fprintf(stdout,"Invalid pin, using default pin %d\n",DEFAULT_PIN);
      return DEFAULT_PIN;
    }

  else
    {
      return pin;
    }

}

