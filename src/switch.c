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

#include "switch.h"
#include "status.h"
#include "options.h"
#include "gpio.h"
#include "loging.h"
#include "cleanup.h"

/*
 * Check MPD-status and switch GPIO.
 */

int switch_output()
{

  switch (state)
    {

    case STATE_NORMAL:
      if(get_mpd_status() == 0)
        {
          break;
        }

      else if(get_mpd_status() == 1)
        {
          gpio_switch_high();
          state = STATE_SWITCHED;
          break;
        }

      else
        {
          loging("MPD not running. Exiting!\n",LEVEL_INFORMATION);
          cleanup();
          exit(EXIT_FAILURE);
        }

    case STATE_SWITCHED:
      if(get_mpd_status() == 1)
        {
          break;
        }
      else if(get_mpd_status()==0)
        {
          gpio_switch_low();
          state = STATE_NORMAL;
          break;
        }

      else
        {
          loging("MPD not running. Exiting!\n",LEVEL_INFORMATION);
          cleanup();
          exit(EXIT_FAILURE);
        }

    default:
      break;
    }


  return state;
}
