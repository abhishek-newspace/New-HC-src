# scout-td0-HC
Repository for single hand controller (HC) to be used in Mode A operation 

## Prerequisites

Before installing and running this project, ensure you have the following tools installed on your system:

* **Arduino IDE**: Required for compiling the project sketches. [Download here](https://www.arduino.cc/en/software).
* **avrdude**: Command-line program for updating the flash/EEPROM/fuse contents of AVR microcontrollers.

## Installation

Follow these steps to set up the project locally:

1. **Create a new directory**: mkdir my_project && cd my_project
2. **Clone the Repo**: git clone https://github.com/newspaceresearch-ugv/scout-td0-HC.git
   Navigate to Build directory: cd Build/
3.**Launch**: avrdude -v -p m2560 -c wiring -x delay=10 -P /dev/ttyACM0 -b 115200 -D -U flash:w:"single_hand_controller.ino.hex":i
