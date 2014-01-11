/**
 * ProoveSignal - An Arduino library that is used for sending radio
 * signals with an 433Mhz transmitter to Proove power outlets.
 * Copyright (C) 2014  Fredrik Söderström <tirithen@gmail.com>
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

#ifndef PROOVE_SIGNAL_H
#define PROOVE_SIGNAL_H

#include "Arduino.h"

#define PROOVE_SIGNAL_PULSE_LENGTH_HIGH 250
#define PROOVE_SIGNAL_PULSE_LENGTH_LOW_ONE 250
#define PROOVE_SIGNAL_PULSE_LENGTH_LOW_ZERO 1250
#define PROOVE_SIGNAL_PULSE_LENGTH_LOW_SYNC 2500
#define PROOVE_SIGNAL_PULSE_LENGTH_LOW_PAUSE 10000

#define PROOVE_SIGNAL_ON 0
#define PROOVE_SIGNAL_OFF 1

#ifndef PROOVE_SIGNAL_REPEATS
#define PROOVE_SIGNAL_REPEATS 6
#endif

union ProoveSignal
{
  struct
  {
    unsigned unit        :2;
    unsigned channel     :2;
    unsigned status      :1;
    unsigned group       :1;
    unsigned long remote :26;
  } parts;
  unsigned long data;
};

void prooveSignalSendData(char pin, unsigned long data);

#endif
