#include <Cli.h>

Cli cli = Cli(Serial);

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



