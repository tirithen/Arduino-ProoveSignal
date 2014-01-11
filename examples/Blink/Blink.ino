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
