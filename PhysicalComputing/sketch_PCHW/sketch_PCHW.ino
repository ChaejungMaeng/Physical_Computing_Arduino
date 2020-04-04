const int buttonPin = 4; // 스위치의 핀번호는 digital 4번
int SensorPin = A0; // 압력센서의 핀번호는 analog A0
int buttonState = 0;    // 스위치 버튼의 상태 읽어오는 변수 buttonState

void setup() {
  Serial.begin(9600); // 초기화
  pinMode(buttonPin, INPUT); //스위치 값을 INPUT으로 설정
  pinMode(3,OUTPUT); // digital 3번핀에 연결된 버저를 OUTPUT으로 설정
}

void loop() {
  // read the state of the pushbutton value:
  int buttonState = digitalRead(buttonPin);   // 스위치 버튼의 값 읽어오는 digitalRead
  int SensorReading = analogRead(SensorPin); // 압력센서의 값 읽어오는 analogRead
  int mfsr_r18 = map(SensorReading,0,1024,0,255); //압력센서 값 : analogRead값은 0부터 1024까지, analogWrite는 0부터 255까지 
  Serial.println(mfsr_r18); //압력센서값 확인하기 위함 

  if(mfsr_r18>=30) //사람이 앉아서 압력값이 30보다 클때
  {
  if (buttonState == LOW) // 버튼이 눌러져 있으면
  {
    digitalWrite(3,HIGH); // 버저가 울린다.
    
  } 
  else //버튼이 눌러져 있지 않으면
  {
    digitalWrite(3,LOW); // 버저가 울리지 않는다.
  }
 }

 else if(mfsr_r18==0) // 사람이 앉지 않아 압력이 0 이면
 {
  digitalWrite(3,LOW); // 버저는 울리지 않는다.
 }
}


