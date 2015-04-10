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

#include <bcm2835.h>
#include <stdint.h>
#include <stdio.h>

#include "loging.h"
#include "options.h"


/*
 * Setup GPIOs
 * Return 0 on success
 * Otherwise return -1
 */
int gpio_setup()
{

  if (!bcm2835_init())
    {
      loging("Failed to initialize GPIOs",LEVEL_ERROR);
      return -1;
    }

  else
    {
      bcm2835_gpio_fsel(switch_pin, BCM2835_GPIO_FSEL_OUTP);
      return 0;
    }
  return 0;
}

void gpio_switch_high()
{
  bcm2835_gpio_write(switch_pin, HIGH);
}

void gpio_switch_low()
{
  bcm2835_gpio_write(switch_pin, LOW);
}

