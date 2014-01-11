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

#include "ProoveSignal.h"

#define PROOVE_SIGNAL_CHECK_BIT(variable, position) ((variable) & (1 << (position)))

void prooveSignalSendPulse(char pin, unsigned int high, unsigned int low)
{
  digitalWrite(pin, HIGH);
  delayMicroseconds(high);
  digitalWrite(pin, LOW);
  delayMicroseconds(low);
}

void prooveSignalSendData(char pin, unsigned long data)
{
  char index = 0;
  char index2 = 0;

  for (index = 0; index < PROOVE_SIGNAL_REPEATS; index++) {
    prooveSignalSendPulse(
      pin,
      PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
      PROOVE_SIGNAL_PULSE_LENGTH_LOW_SYNC
    );

    for (index2 = 31; index2 >= 0; index2--) {
      if (PROOVE_SIGNAL_CHECK_BIT(data, index2)) {
        prooveSignalSendPulse(
          pin,
          PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
          PROOVE_SIGNAL_PULSE_LENGTH_LOW_ONE
        );
        prooveSignalSendPulse(
          pin,
          PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
          PROOVE_SIGNAL_PULSE_LENGTH_LOW_ZERO
        );
      } else {
        prooveSignalSendPulse(
          pin,
          PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
          PROOVE_SIGNAL_PULSE_LENGTH_LOW_ZERO
        );
        prooveSignalSendPulse(
          pin,
          PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
          PROOVE_SIGNAL_PULSE_LENGTH_LOW_ONE
        );
      }
    }

    prooveSignalSendPulse(
      pin,
      PROOVE_SIGNAL_PULSE_LENGTH_HIGH,
      PROOVE_SIGNAL_PULSE_LENGTH_LOW_PAUSE
    );
  }
}
