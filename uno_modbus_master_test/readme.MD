## Modbus master test

Using Arduino UNO as master and PC as slave.

Note: this project is only my initial step, only write registers.

The next project:

https://github.com/hardwarelayer/arduino_uno_generic_projects/tree/master/uno_modbus_master_rw_pc

Also implement the Read operations.

### Diagram:

![Diagram](tien_diagram1.PNG)


First, I followed this:
https://circuitdigest.com/microcontroller-projects/rs-485-modbus-serial-communication-with-arduino-as-master

but the library in the article is old and cannot build (error)

so I modified everything

to use the ModBusMaster lib from standard Libraries Manager (https://github.com/4-20ma/ModbusMaster)

### Tool on PC:

Free:
	https://www.modbusdriver.com/diagslave.html

	Usage:
		diagslave -b 9600 -p none -m rtu COM5

But this cannot view the register values on realtime.
![Diagram](diagslave.PNG)


Trial:

Modbus slave software for PC:

	https://www.modbustools.com/modbus_slave.html <-- trial

Must configure correctly as in code:

![ConnectSetting](slave_connect_setting.PNG)

![Definition](slave_setting.PNG)

![Values](register_values.PNG)

### Note: 

USB-RS485 should be removed during flashing Uno

Sometime, TX and RX will block flashing, when failed, remove them.

The common GND between USB and diagram is not needed (nice to have)