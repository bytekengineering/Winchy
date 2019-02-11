#include <Winchy.h>

boolean leftState=0, rightState=0;
Winchy w;

void setup() {
  // put your setup code here, to run once:
  pinMode(D4, INPUT);
  pinMode(D5, INPUT);
  delay(3000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  leftState = digitalRead(D4);
  rightState = digitalRead(D5);
  
  if(leftState)
    if(rightState)  w.forward();
    else            w.right();
  else
    if(rightState)  w.left();
    else            w.myStop();
    
}
