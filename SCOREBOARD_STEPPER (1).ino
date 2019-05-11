#include <LiquidCrystal.h>
//variables
int bluePin = 4;
int pinkPin = 5;
int yellowPin=6;
int orangePin=7;
int currentStep=0;
LiquidCrystal lcd (13,12,3,2,1,0);
const int buttonTeam1 = 10;
const int buttonTeam2 = 9;
int buttonState1=0;
int buttonState2=0;
int team1=0;
int firstTime=1;
int team2=0;
int gameStart=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin,OUTPUT);
  pinMode(pinkPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  pinMode(orangePin,OUTPUT);

  digitalWrite(bluePin, LOW);
  digitalWrite(pinkPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(orangePin, LOW);
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("WELCOME 2 ROCKET");
  lcd.setCursor(1,2);
  lcd.print("LEAGUE COZMOS");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonTeam1);
  buttonState2= digitalRead(buttonTeam2);

  if (buttonState1 == HIGH) {
      if(gameStart==0){
        team1=0;
        team2=0;
         gameStart=1;
         firstTime=1;
         lcd.clear();
         lcd.print("GAME STARTS IN 5");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 4");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 3");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 2");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 1");
         delay(1000);
         lcd.clear();
         lcd.print("BEGIN!!");
         delay(2000);
         lcd.clear();
         lcd.print("Player 1: 0");
         lcd.setCursor(0,1);
         lcd.print("Player 2: 0");
         for(int i = 0; i<1030;i++){     
                switch(currentStep){
                    case 0:
                    digitalWrite(bluePin, HIGH);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 1:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, HIGH);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 2:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, HIGH);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 3:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, HIGH);
                    break;
                  
                  }
                  currentStep= (++currentStep < 4) ? currentStep : 0;
                  delay(3);
         }
         
      }else if(gameStart==1){
        //player 1 scored
        firstTime=0;
        team1=team1+1;
        lcd.clear();
        lcd.print("Player 1 Scores!");
        delay(2000);
        if(team1==0){
              if(team2==0){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 0");
              }else if(team2==1){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 1");
              }else if(team2==2){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 2");
              }else if(team2==3){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 3");
                   delay(3500);
                   lcd.clear();
                   gameStart=0;
                   lcd.print("!!!PLAYER 2 WINS!!!");
              }
        }else if(team1 ==1){
            if(team2==0){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 0");
            }else if(team2==1){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 1");
            }else if(team2==2){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 2");
            }else if(team2==3){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 3");
                 delay(3500);
                 lcd.clear();
                 gameStart=0;
                 lcd.print("!!!PLAYER 2 WINS!!!");
            }
        }else if(team1 == 2){
            if(team2==0){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 0");
            }else if(team2==1){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 1");
            }else if(team2==2){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 2");
            }else if(team2==3){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 3");
                 delay(3500);
                 lcd.clear();
                 gameStart=0;
                 lcd.print("PLAYER 2 WINS!!!");
            }
    }else if(team1 ==3){
        if(team2==0){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 0");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==1){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 1");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==2){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 2");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==3){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 3");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("tie(my program doesnt work)!!!");
          }
 
    
    
      }
      if(firstTime!=1){
      delay(10000);
      for(int i = 0; i<1030;i++){     
                switch(currentStep){
                    case 0:
                    digitalWrite(bluePin, HIGH);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 1:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, HIGH);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 2:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, HIGH);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 3:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, HIGH);
                    break;
                  
                  }
                  currentStep= (++currentStep < 4) ? currentStep : 0;
                  delay(3);
         }
      }else if(firstTime==1){
          firstTime=0;
         }
  }
  }
  buttonState2= digitalRead(buttonTeam2);
  if(buttonState2== HIGH) {
      if(gameStart==0){
        team1=0;
        team2=0;
         gameStart=1;
         firstTime=1;
         lcd.clear();
         lcd.print("GAME STARTS IN 5");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 4");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 3");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 2");
         delay(1000);
         lcd.clear();
         lcd.print("GAME STARTS IN 1");
         delay(1000);
         lcd.clear();
         lcd.print("BEGIN!!");
         delay(2000);
         lcd.clear();
         lcd.print("Player 1: 0");
         lcd.setCursor(0,1);
         lcd.print("Player 2: 0");
         for(int i = 0; i<1030;i++){     
                switch(currentStep){
                    case 0:
                    digitalWrite(bluePin, HIGH);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 1:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, HIGH);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 2:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, HIGH);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 3:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, HIGH);
                    break;
                  
                  }
                  currentStep= (++currentStep < 4) ? currentStep : 0;
                  delay(3);
         }
         
      }else if(gameStart==1){
        //player 1 scored
        firstTime=0;
        team2=team2+1;
        lcd.clear();
        lcd.print("Player 2 Scores!");
        delay(2000);
        if(team1==0){
              if(team2==0){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 0");
              }else if(team2==1){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 1");
              }else if(team2==2){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 2");
              }else if(team2==3){
                   lcd.clear();
                   lcd.print("Player 1: 0");
                   lcd.setCursor(0,1);
                   lcd.print("Player 2: 3");
                   delay(3500);
                   lcd.clear();
                   gameStart=0;
                   lcd.print("PLAYER 2 WINS!!!");
              }
        }else if(team1 ==1){
            if(team2==0){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 0");
            }else if(team2==1){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 1");
            }else if(team2==2){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 2");
            }else if(team2==3){
                 lcd.clear();
                 lcd.print("Player 1: 1");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 3");
                 delay(3500);
                 lcd.clear();
                 gameStart=0;
                 lcd.print("PLAYER 2 WINS!!!");
            }
        }else if(team1 == 2){
            if(team2==0){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 0");
            }else if(team2==1){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 1");
            }else if(team2==2){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 2");
            }else if(team2==3){
                 lcd.clear();
                 lcd.print("Player 1: 2");
                 lcd.setCursor(0,1);
                 lcd.print("Player 2: 3");
                 delay(3500);
                 lcd.clear();
                 gameStart=0;
                 lcd.print("PLAYER 2 WINS!!!");
            }
    }else if(team1 ==3){
        if(team2==0){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 0");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==1){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 1");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==2){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 2");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("PLAYER 1 WINS!!!");
        }else if(team2==3){
             lcd.clear();
             lcd.print("Player 1: 3");
             lcd.setCursor(0,1);
             lcd.print("Player 2: 3");
             delay(3500);
             lcd.clear();
             gameStart=0;
             lcd.print("tie(my program doesnt work)!!!");
          }
 
    
    
      }
      if(firstTime!=1){
      delay(10000);
      for(int i = 0; i<1030;i++){     
                switch(currentStep){
                    case 0:
                    digitalWrite(bluePin, HIGH);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 1:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, HIGH);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 2:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, HIGH);
                    digitalWrite(orangePin, LOW);
                    break;
                    case 3:
                    digitalWrite(bluePin, LOW);
                    digitalWrite(pinkPin, LOW);
                    digitalWrite(yellowPin, LOW);
                    digitalWrite(orangePin, HIGH);
                    break;
                  
                  }
                  currentStep= (++currentStep < 4) ? currentStep : 0;
                  delay(3);
         }
      }else if(firstTime==1){
          firstTime=0;
         }
  }
  }
}
