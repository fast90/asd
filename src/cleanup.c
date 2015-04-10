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

#include "loging.h"
#include "options.h"
/*
 * Cleanup
 * Return 0 on success
 * Otherwise return 1
 */
int cleanup()
{
  int status=1;

  bcm2835_gpio_write(switch_pin, LOW);

  status = bcm2835_close();

  if(status > 0)
    loging("Cleaning up",LEVEL_INFORMATION);

  else if (status < 0)
    loging("Failed to clean up", LEVEL_ERROR);

  return status;
}
