/*
 * Controll Raspberry Pi GPIO based on MPD Status
 * Copyright (C) 2015  Fabian Stahl <fabian.m.stahl@posteo.de>
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
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "gpio.h"
#include "daemonize.h"
#include "status.h"
#include "options.h"
#include "arguments.h"
#include "switch.h"



int main(int argc, char *argv[])
{
  /*Parse arguments*/
  parse_arguments(argc, argv);

  /*Daemonize*/
  if(daemon_flag > 0)
    daemonize();

  /*Setup GPIOs*/
  if(gpio_setup() < 0)
    {
      exit(EXIT_FAILURE);
    }

  /*Set initial state*/
  state = STATE_NORMAL;

  while(1)
    {
      sleep(1);
      switch_output();
    }

  return 0;
}
