# ProoveSignal
An Arduino library that is used for sending radio signals with an 433Mhz transmitter to [Proove](http://proovesmart.com/default/products) power outlets.

## Usage example
Look in the example directory

## About the Proove protocol

### Bitcoding
The data on the physical link is code so that every bit is sent as two bits, 0 = 01 and 1 = 10.

### An example recorded from an existing remote
    S0110011010011001010101011010100101010101010101100110100101010101P
    S01011010000011100000000101100000P <- Above rewritten from recieved bits to "real" bits
    S = Start pulse
    P = Pause pulse

### Signal parts

    0101 1010 0000 1110 0000 0001 0110 0000
    HHHH HHHH HHHH HHHH HHHH HHHH HHGO CCEE

    H = The first 26 bits are transmitter unique codes, and it is this code that the reciever "learns" to recognize.
    G = Group code. Set to 0 for on, 1 for off.
    O = On/Off bit. Set to 0 for on, 1 for off.
    C = Channel bits.
    E = Unit bits. Device to be turned on or off. Unit #1 = 00, #2 = 01, #3 = 10.

More details can be found at [](http://tech.jolowe.se/home-automation-rf-protocols/).

## License
Released under the GPLv3 license.