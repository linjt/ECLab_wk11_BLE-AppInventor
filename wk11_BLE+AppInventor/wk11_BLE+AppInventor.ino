#include <BluetoothSerial.h>
BluetoothSerial BT;

int i=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("TestEsp324");//請改名
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    //顯示在序列視窗
    Serial.println(BTdata);
    if(BTdata == "A"){
      i++;
      if(i>1){
      i=0;
    }
    }
    if(i == 0){
      digitalWrite(13,HIGH);
    }
    if(i == 1){
      digitalWrite(13,LOW);
    }
  }
  delay(1);
}
