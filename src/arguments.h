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

#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <stdint.h>

void parse_arguments(int argc, char * argv[]);
uint8_t eval_pin(int pin);
#endif
