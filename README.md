Command Line Interpreter library for Arduino
==============================================

Description
------------
Basic CLI (Command Line Interpreter) library for Arduino. 

The CLI class first allows the user to register commands (i.e. a combination of a name and a function address) into a linked list. 

Then, on every 'LF' (Line Feed) char received on the Serial Interface, the class checks whether the input command name matches a registered one. In this case, the corresponding function is executed. 

NB1 : Each command name is 8 characters MAX by default.

NB2 : The functions associated to the commands shall be "void function(void)" typed.

Usage
-----
 1. in the setup() Arduino sketch function, register all your  commands by using RegisterCmd() method and open the serial port (see example below)
 2. in the loop() Arduino sketch function, call the Run() method to allow CLI execution
 (see example below)

NB : If you don't use the Arduino serial monitor, make sure your terminal application is configured with a 'LF' char for New Line ('CR' char is ignored).

Code Example
------------
Arduino sketch example :
```
#include <Cli.h>

Cli cli = Cli(&Serial);

void FunctionHello(void) {Serial.println("\"functionHello\" is being executed!");}
void FunctionByebye(void) {Serial.println("\"functionByebye\" is being executed!");}
void FunctionSeeyou(void) {Serial.println("\"functionSeeyou\" is being executed!");}

void setup(){
  cli.RegisterCmd("hello",&FunctionHello);
  cli.RegisterCmd("byebye",&FunctionByebye);
  cli.RegisterCmd("seeyou",&FunctionSeeyou);
  Serial.begin(115200);
}

void loop(){
  cli.Run();
}
```
