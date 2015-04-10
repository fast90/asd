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

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

#include "status.h"
#include "loging.h"
#include "options.h"

/*
 * Connect to mpd socket, read and parse status.
 * Return 1 if status is 'playing'.
 * Return 0 if status is 'pause'.
 * Otherwise return -1.
 */
int get_mpd_status()
{

  int sock, t, len;
  struct sockaddr_un remote;
  char str[300];

  const char *msg = "status\n";

  if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) == -1)
    {
      loging("Can not connect to socket",LEVEL_ERROR);
      return -1;
    }

  remote.sun_family = AF_UNIX;
  strcpy(remote.sun_path, sock_path);
  len = strlen(remote.sun_path) + sizeof(remote.sun_family);

  if (connect(sock, (struct sockaddr *)&remote, len) == -1)
    {
      loging("Can not connect to socket",LEVEL_ERROR);
      return -1;
    }

  if((t=recv(sock,str,400,0)) > 0)
    {
      str[t] = '\0';
    }

  else
    {
      if (t < 0)
      {
        loging("Receive failed",LEVEL_ERROR);
        return -1;
      }

      else
      {
        loging("Connection was closed",LEVEL_ERROR);
        return -1;
      }

    }

  if(send(sock,msg,strlen(msg), 0) == -1)
  {
    loging("Failed to send command",LEVEL_ERROR);
    return -1;
  }

  if((t=recv(sock,str,400,0)) > 0)
    {
      str[t] = '\0';
    }

  else
    {
      if (t < 0)
      {
        loging("Receive failed",LEVEL_ERROR);
        return -1;
      }
      else
      {
        loging("Connection was closed",LEVEL_ERROR);
        return -1;
      }

    }

  close(sock);

  if(strstr(str, "state: play") != NULL)
    return 1;
  else
    return 0;
}
