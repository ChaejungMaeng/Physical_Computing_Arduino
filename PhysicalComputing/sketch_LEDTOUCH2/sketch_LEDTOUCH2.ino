const int LED_PIN = 10; //LED를 digital 10번 핀에 연결
const int TOUCH_PIN = 4; // 터치센서를 digital 4번 핀에 연결 
boolean button_is_activate = true; // 터치센서가 활성화 상태를 ture로
int button_step = 0;  // 터치센서 정지(0)

void setup() {
    pinMode(TOUCH_PIN, INPUT); // 터치센서를 INPUT으로 설정
    pinMode(LED_PIN, OUTPUT); // LED를 OUTPUT으로 설정
}

void button_pressed() { // 터치센서가 눌러지면
    if (button_step == 0) { // 터치센서가 정지상태일 때 
        analogWrite(LED_PIN, 255); //LED 켜진다.
    }
    else if (button_step == 1) { //터치센서가 정지상태가 아닐때 
        analogWrite(LED_PIN, 0); //button_step이 1일때 LED는 꺼진다.
    }
}

void loop() {
    button_pressed(); // button_pressed 함수 호출
    if (digitalRead(TOUCH_PIN) == HIGH) {  // 터치센서가 터치되었을때
        if (button_is_activate) { // 터치센서 활성화 값에 따라 ture일때
            button_step++; //button_step 하나씩 더하기 
            if (button_step == 2) { //만약 button_step이 2가 되었을때
                button_step = 0; //button_step 0으로 초기화
            }
            button_is_activate = false; // 한번만 실행될 수 있게 버튼 비활성화
        }
    }
    else { //터치센서가 터치되지 않았을때
        button_is_activate = true; //터치센서 활성화 
    }
}
