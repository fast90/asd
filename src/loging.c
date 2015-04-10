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

#include <syslog.h>

#include "loging.h"
#include "options.h"

/*
 * Write to syslog
 * type = 0 -> Information
 * type = 1 -> Error
 */
void loging(const char *msg,int type)
{

  openlog("audioswitch", LOG_PID|LOG_CONS, LOG_DAEMON);

  if(type == LEVEL_INFORMATION)
    syslog(LOG_INFO,msg);

  if(type == LEVEL_ERROR)
    syslog(LOG_ERR,msg);

  closelog();
}
