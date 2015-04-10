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
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

#include "loging.h"
#include "sighandler.h"
#include "options.h"


void daemonize()
{

  pid_t process_id = 0;

  process_id = fork();

  /*An error occured*/
  if(process_id < 0)
    {
      loging("Fork failed!",LEVEL_ERROR);
      exit(EXIT_FAILURE);
    }

  /*Success: Let the parent terminate*/
  if(process_id > 0)
    {
      exit(EXIT_SUCCESS);
    }

  /*An error occured*/
  if(setsid() < 0)
    {
      loging("Failed to set session id",LEVEL_ERROR);
      exit(EXIT_FAILURE);
    }

  /*Catch signals*/
  signal(SIGINT, handle_signal);
  signal(SIGHUP, handle_signal);
  signal(SIGTERM, handle_signal);


  process_id = fork();

  /* An error occurred */
  if (process_id < 0)
    {
      loging("Failed to fork",LEVEL_ERROR);
      exit(EXIT_FAILURE);
    }


  /* Success: Let the parent terminate */
  if (process_id > 0)
    {
      fprintf(stdout,"Pid of asd is: %d \n", process_id);
      exit(EXIT_SUCCESS);
    }

  /*Set file permission */
  umask(0);

  /*Change current working directory to root.*/
  if(chdir("/") != 0)
    loging("Failed to change working directory to root",LEVEL_ERROR);

  /*Close open file descriptors*/
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
}
