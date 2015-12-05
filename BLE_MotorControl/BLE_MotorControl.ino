#include "arduino.h"
#include <DRV8835MotorShield.h>

DRV8835MotorShield motors;

const int LED=13;
int rsvData = 0;
//int sensorVal = 0;

int wheelSpeed = 100;
int wheelSpeedMinus = -100;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
   
  // 受信処理
  if(Serial.available() > 0){
    rsvData = Serial.read();
    if(rsvData == 1){
      digitalWrite(LED, HIGH);
    } else if(rsvData == 0){
      digitalWrite(LED, LOW);
      motors.setSpeeds(0,0);
    }
    // モーター制御
    else if(rsvData == 2){ // 前進
      motors.setSpeeds(wheelSpeed,wheelSpeed);
    }
    else if(rsvData == 3){// 後退
      motors.setSpeeds(wheelSpeedMinus,wheelSpeedMinus);
    }
    else if(rsvData == 4){// 右旋回
      motors.setSpeeds(wheelSpeed,wheelSpeedMinus);
      digitalWrite(LED, HIGH);
    }
    else if(rsvData == 5){// 左旋回
      motors.setSpeeds(wheelSpeedMinus,wheelSpeed);
      digitalWrite(LED, HIGH);
    }
  }
  //センサー読み取り～送信
//  sensorVal = analogRead(0);
//  sensorVal = sensorVal>>2; //10bit->8bit値
//  Serial.write(sensorVal);
}
