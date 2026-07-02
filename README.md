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
3. **Navigate to Build directory**: cd Build/
4. **Launch**: `sh flash_code.sh` or `sh flash_code.sh [port]`

***Refer src/error_handling.md for understanding how to handle error codes displayed on screen***

***Refer src/readme.md for more info on compiling in different modes, and editing files/configurations***