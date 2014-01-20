/**
 * Blink - A simple light toggle example
 *
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

extern "C" {
  #include <ProoveSignal.h>
}

ProoveSignal signal;

char transmissionPin = 13;

void setup()
{
  // Set pin to output
  pinMode(transmissionPin, OUTPUT);

  // Set the remote id
  signal.parts.remote = 0x1683805;

  // Turn off the group
  signal.parts.group = PROOVE_SIGNAL_OFF;

  // Turn the power outlet off
  signal.parts.status = PROOVE_SIGNAL_OFF;
  prooveSignalSendData(transmissionPin, signal.data);
}

void loop()
{
  // Turn the power outlet on and wait 5 seconds
  signal.parts.status = PROOVE_SIGNAL_ON;
  prooveSignalSendData(transmissionPin, signal.data);
  delay(5000);

  // Turn the power outlet off and wait 5 seconds
  signal.parts.status = PROOVE_SIGNAL_OFF;
  prooveSignalSendData(transmissionPin, signal.data);
  delay(5000);
}
