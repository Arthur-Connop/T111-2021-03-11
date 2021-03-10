#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

byte btn;
int i_count = 0;
int i_min = -10;
int i_max = 10;
bool increasing = true;

int i_delay = 250;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  MFS.initialize(&Timer1);
  
  //t_main();
}

void update_score(){
  score++;
  i_delay = i_delay - 20;
  if(score == 15) {}
  MFS.beep();
}

void loop() {
  // put your main code here, to run repeatedly:
  btn = MFS.getButton();
  delay(i_delay);
  MFS.write(i_count);
  if(i_count == 0 && btn == BUTTON_1_PRESSED) {update_score();}
  if (increasing) {
    i_count += 1;
    if (i_count == i_max) {
      increasing = false;
    }
  }
  else {
    i_count -= 1;
    if (i_count == i_min) {
      increasing = true;
    }
  }
}
