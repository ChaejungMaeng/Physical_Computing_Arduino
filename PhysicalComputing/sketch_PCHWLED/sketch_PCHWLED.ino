const int Soundsensor = A0; //사운드 센서 핀번호
const int sensitivity = 684; //사운드 센서 감도(초기값)

int preSound = 0;  // 이전의 음악 소리 크기 측정값 변수
int nowSound = 0; // 현재 음악 소리 크기 측정값 변수
int val = 0;

int G_1 = 3; // LED Green을 digital 3번 핀으로 설정
int G_2 = 6; // LED Green2을 digital 3번 핀으로 설정
int R_1 = 5; // LED Red을 digital 5번 핀으로 설정

int R = 9; // LED Red을 digital 9번 핀으로 설정
int Y = 10; // LED Yellow를 digital 10번 핀으로 설정
int B = 11; // LED Blue를 digital 11번 핀으로 설정

void setup() {
  pinMode(Soundsensor, INPUT); //소리센서에서 읽은 값을 INPUT으로 설정 
  // i가 9, 10, 11로 증가하면서 G_1, G_2, R_1 LED의 OUTPUT 제어
  for(int i=9;i<12;i++) pinMode(i,OUTPUT);
  pinMode(G_2,OUTPUT); pinMode(G_1,OUTPUT); pinMode(R_1,OUTPUT);
  Serial.begin(9600);   //시리얼통신 초기화
}

void loop() {
  for(int i = 0; i < 255; i++) { //255번 for루프 실행
    //사운드센서의 읽어온 값에서 사운드센서 감도값을 빼어 sensorstate에 저장
    nowSound = analogRead(Soundsensor)-sensitivity; 
    //음악 소리 크기 측정값을 preVal에 저장
    measureSoundValue(nowSound, preSound);
    //val 값 확인
    Serial.println(val); 

    analogWrite(Y,255-i); // LED Y 값이 i에 따라 변화
    analogWrite(R,i); // LED R 값이 i에 따라 변화
    blinkLED(B,val); //LED B 깜박임

    analogWrite(G_1,i); //LED G_1값이 변화
    analogWrite(G_2,255-i); //LED G_2값이 변화
    blinkLED(R_1,val); //LED R_1값이 깜박임
    
    val = 0; //val 초기화
    preSound = nowSound; //소리크기 변수를 초기화 
    delay(50); //루프 돌때마다 delay
  }
  
  for(int i = 0; i < 255; i++) {//255번 for루프 실행
    //사운드센서의 읽어온 값에서 사운드센서 감도값을 빼어 sensorstate에 저장
    nowSound = analogRead(Soundsensor)-sensitivity;
    //음악 소리 크기 측정값을 preVal에 저장
    measureSoundValue(nowSound, preSound);
    //val 값 확인
    Serial.println(val);

    analogWrite(R,255-i); //LED R 값이 i에 따라 변화
    analogWrite(Y,i); //LED Y 값이 i에 따라 변화
    blinkLED(B,val); //LED B 깜박임
        
    analogWrite(G_1,255-i); //LED G_1값이 변화
    analogWrite(R_1,i); //LED R_1값이 변화
    blinkLED(G_2,val);  //LED G_2값이 변화
    
    preSound = nowSound; //소리크기 변수를 초기화 
    val = 0; //val 초기화
    delay(50); //루프 돌때마다 delay
  }

  for(int i = 0; i < 255; i++) { //255번 for루프 실행
    nowSound = analogRead(Soundsensor)-sensitivity;
    //사운드센서의 읽어온 값에서 사운드센서 감도값을 빼어 sensorstate에 저장
    measureSoundValue(nowSound, preSound);   
    //음악 소리 크기 측정값을 preVal에 저장
    //val 값 확인
    Serial.println(val);

    analogWrite(R,i); //LED R 값이 i에 따라 변화
    analogWrite(Y,255-i); //LED Y 값이 i에 따라 변화
    blinkLED(B,val); //LED B 깜박임

    blinkLED(G_2,val); //LED B_1 깜박임
    analogWrite(R_1,255-i); //LED R_1값이 변화
    analogWrite(G_1,i); //LED G_1값이 변화
    
    preSound = nowSound; //소리크기 변수를 초기화 
    val = 0; //val 초기화
    delay(50); //루프 돌때마다 delay 50
  }
  delay(10); //루프 돌때마다 delay 10
}

//사운드센서의 측정값에 따라 특정 LED를 깜빡거리게 하는 blinkLED 함수
void blinkLED(int pinNum ,int brightness) { 
  analogWrite(pinNum, brightness);
  analogWrite(pinNum, 0);
  analogWrite(pinNum, brightness);
}

//사운드센서가 측정하는 값에 크기에 따라 LED의 수치를 임의적으로 조절하는 measureSoundValue 함수
//sensorsate는 현재 음악 소리 크기
//prevVal은 이전의 음악 소리 크기 
void measureSoundValue(int nowSound, int preSound) {
  //(현재 음악 소리 크기- 이전의 음악 소리 크기)값이 클수록 val값을 크게 하여 LED의 밝기가 더 밝아지도록 한다.
  if(abs(nowSound - preSound) > 31 ) 
    val = 240;
  else if(abs(nowSound - preSound) > 28 )    
    val = 210;
  else if(abs(nowSound - preSound) > 25 )    
    val = 180;
  else if(abs(nowSound - preSound) > 22 )    
    val = 150;
  else if(abs(nowSound - preSound) > 19 )    
    val = 120;
  else if(abs(nowSound - preSound) > 16 )    
    val = 90;
  else if(abs(nowSound - preSound) > 13 )    
    val = 60;
  else if(abs(nowSound - preSound) > 10 )    
    val = 30;
  else if(abs(nowSound - preSound) > 7 )
    val = 0;
}
