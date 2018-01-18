# retrowhackamole
whack a mole game with arcade button

#schema
```
                            5V
                            +-----------------------+
                            GND                     |
+-----------------------------+                     |
|                                                   |
|                          +--------------------+   |
|                          |                    |   |
|                    +-----+Q1            Vcc 5V+---+
|                    |     |                    |   |
|                 +--------+Q2                Q0+---------+
|                 |  |     |      74HC595       |   |     |  Serial data
|              +-----------+Q3                DS+--------------------------------+
|              |  |  |     |                    |   |     |
|           +--------------+Q4               |OE+------+  |
|           |  |  |  |     |                    |   |  |  |  Storage register
|        +-----------------+Q5             ST_CP+--------------------------------+
|        |  |  |  |  |     |                    |   |  |  |  Shift register
|     +--------------------+Q5             SH_CP+--------------------------------+
|     |  |  |  |  |  |     |                    |   |  |  |
|  +-----------------------+Q7               |MR+---+  |  |
|  |  |  |  |  |  |  |     |                    |      |  |  to next 74HC pin DS
+-----------------------+--+GND              Q7'+--------------------------------+
|  |  |  |  |  |  |  |  |  |                    |      |  |
|  |  |  |  |  |  |  |  |  +--------------------+      |  |
|  |  |  |  |  |  |  |  |                              |  |
|  |  |  |  |  |  |  |  +------------------------------+  |
|  |  |  |  |  |  |  |                                    |
|  |  |  |  |  |  |  |  +---------------------------------+
|  |  |  |  |  |  |  |  |
|  |  |  |  |  |  |  |  |  +--------------------+
|  |  |  |  |  |  |  |  |  |                    |
|  |  |  |  |  |  |  |  +--+in 1           out 1+-------+ LED 1 +----+
|  |  |  |  |  |  |  |     |                    |                    |
|  |  |  |  |  |  |  +-----+in 2           out 2+-------+ LED 2 +----+
|  |  |  |  |  |  |        |                    |                    |
|  |  |  |  |  |  +--------+in 3           out 3+-------+ LED 3 +----+
|  |  |  |  |  |           |      ULN2803A      |                    |
|  |  |  |  |  +-----------+in 4           out 4+-------+ LED 4 +----+
|  |  |  |  |              |                    |                    |
|  |  |  |  +--------------+in 5           out 5+-------+ LED 5 +----+
|  |  |  |                 |                    |                    |
|  |  |  +-----------------+in 6           out 6+-------+ LED 6 +----+
|  |  |                    |                    |                    |
|  |  +--------------------+in 7           out 7+-------+ LED 7 +----+
|  |                       |                    |                    |
|  +-----------------------+in 8           out 8+-------+ LED 8 +----+
|                          |                    |                    |    12V
+--------------------------+0v               COM+--------------------+-------+
                           |                    |
                           +--------------------+
```

# description

 - Arcade buttons work in 12v ; 
 - on top, ASCII schematic for 1x8 buttons ; 
 - if you have some flicker when the latch pin pulses you can use a 0.1uF capacitor [tutorial here](https://www.arduino.cc/en/Tutorial/ShiftOut) ; 
 - In my case, I have a grid with 4x4,
 - To control this buttons, I use arduino nano.
 
 # materials
 - 1 arduino nano [ebay sample](https://www.ebay.com/itm/USB-Nano-V3-0-ATmega328-16M-5V-Micro-controller-CH340G-board-For-Arduino/201601613488) ; 
 - a Power Supply Adapter Transformer about 12v 3A ;
 - 60mm arcade button x16 (different color is better ^^) ; 
 - 4x4 Matrix 16 Keypad [ebay sample](https://www.ebay.com/itm/4x4-4-4-Matrix-16-Button-16-Keypad-Keyboard-Module-16-Key-Mcu-for-Arduino-NEW/331565848686) ; 
 - some wire ( different color is better ^^, something like 18awg for led and 22awg for push button command) ;
 
 
 
