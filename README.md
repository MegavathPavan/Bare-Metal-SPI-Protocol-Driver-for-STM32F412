# SPI Communication on STM32F412

## **Aim:**
Implement the SPI protocol in bare-metal programming on the STM32F412 microcontroller without using external libraries.

## **Overview:**
This project demonstrates how to implement the Serial Peripheral Interface (SPI) protocol on the STM32F412 microcontroller using bare-metal programming in C. The SPI protocol is implemented strictly according to its specifications, and the project includes header and source files for both UART and SPI communication. The entire implementation does not rely on any external libraries.

## **Equipment Required:**
- STM32F412 Nucleo board
- Keil μVision IDE
- Arduino Board (Master)
- Serial Monitor (e.g., Putty/Arduino)
- Connecting wires
- USB cable

## **SPI Implementation:**

### **Key Files:**
1. **`spi_driver.h`**: Contains definitions, macros, and function prototypes.
2. **`spi_driver.c`**: Initializes and configures SPI for data transmission and reception.
3. **`spi_main.c`**: Main source file that demonstrates the use of SPI functions for transmitting and receiving data.

### **SPI Protocol Basics:**
- SPI is a full-duplex communication protocol with a master-slave architecture.
- Four key signals:
  1. **SCK (Serial Clock)**
  2. **MOSI (Master Out Slave In)**
  3. **MISO (Master In Slave Out)**
  4. **SS (Slave Select)**

### **Function Details:**
1. **`SPI_config()`**:
   - Configures SPI with the chosen peripheral (SPI4).
   - Sets the operating mode (master/slave), direction (full-duplex), data size(8bit/16bit), clock polarity, phase, and baud rate.
   
2. **`GPIO_config()`**:
   - Enables clock for GPIOE and SPI4.
   - Configures pins (PE2, PE4, PE5, PE6) for SPI communication.

3. **`transfer_nbit_SPI()`**:
   - Sends and receives data by checking the SPI buffer and transferring data until the buffer is empty.

## **SPI Initialization:**
1. Enable the SPI4 clock.
2. Configure SPI in master mode, with specified settings (e.g., polarity, phase, baud rate).
3. Enable SPI4 after configuration.

### **Main Functionality in `spi_main.c`:**
- Calls `GPIO_config()` to configure GPIO pins.
- Calls `SPI_config()` to configure SPI settings.
- Uses `transfer_nbit_SPI()` to manage data transfer between the master and slave devices.

## **Testing and Debugging:**
- For verification, an Arduino board is used as the master device, sending data to the STM32F412 Nucleo board, which acts as the slave.
- Data received by the STM32F412 is displayed on a serial monitor (Putty or Arduino IDE).

### SPI Communication Setup
![SPI Communication Setup](https://github.com/MegavathPavan/SPI-Protocol/blob/main/SPI_Demo_Board.png)

### SPI Working Demo(left-master, right-slave)
Transmitter: Arduino Board(master)
Receiver: ArduSTM32F412 Nucleo Board(master)
![SPI Working Demo](https://github.com/MegavathPavan/SPI-Protocol/blob/main/stmspi-output%20demonstration.gif?raw=true)

## **Comparison of SPI with Other Communication Protocols:**

1. **SPI vs UART**:
   - SPI is Synchronous with a shared clock between master and slave, whereas
UART is Asynchronous with start and stop bits for synchronization.
   - Both the protocols are full-duplex communication protocols but the no. of
data lines in the SPI are more.
   - SPI is used for high-speed communication with peripherals, while UART is used for serial communication.

2. **SPI vs I2C**:
   - SPI uses more lines (4 vs 2) and provides full-duplex communication, whereas I2C is half-duplex and can support multiple devices on the same bus.

3. **SPI vs CAN**:
   - SPI is for short-distance, high-speed communication, while CAN is used for long-distance communication with noise tolerance.

## **Advantages of SPI:**
1. Full-duplex communication.
2. High-speed data transmission.
3. Simple master-slave architecture.
4. Low overhead with no need for address bits.
5. Versatility with support for multiple devices.

## **Drawbacks of SPI:**
1. Requires more signal lines.
2. Complex for multi-device setups.

## **Frame Format and Data Transfer:**
- The SPI frame format depends on the clock polarity, phase, and data size.
- Data is transmitted when the slave select line is low.
- Supported modes:
  - **Mode 0 (CPOL=0, CPHA=0)**
  - **Mode 1 (CPOL=0, CPHA=1)**
  - **Mode 2 (CPOL=1, CPHA=0)**
  - **Mode 3 (CPOL=1, CPHA=1)**

## **Conclusion:**
The SPI communication protocol was successfully implemented on the STM32F412 Nucleo board. The implementation was verified using an Arduino master device, and data was transmitted via SPI. Minor errors in received data (e.g., missing characters) were identified, which can be resolved using CRC for error checking.

## **References:**
1. [Texas Instruments: SPI Protocol](https://www.ti.com/lit/ug/sprugp2a/sprugp2a.pdf)
