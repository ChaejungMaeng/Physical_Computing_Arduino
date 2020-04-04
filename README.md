# Physical_Computing_Arduino

# 프로젝트 설명

 영하의 기온으로 날씨가 점점 추워지고 있는 요즘, 추위를 피해 잠시 쉬다 가려고 의자에 앉은 사람에게 어떤 경험을 선물로 줄 수 있을까 고민하였습니다. 저는 잠시 쉴 때 음악 듣는 것을 좋아하는데 저처럼 음악 듣기를 좋아하는 사람에게 시각적으로도 즐거운 경험을 줄 수 있을까 생각하였습니다. 만약 음악에 따라 LED 색이 변하는 조명이 있으면 음악을 들으면서 예쁜 조명도 감상할 수 있어 지루하지 않은 쉼이 될 것이라 생각하였고 ‘리듬타는 LED Bottle’을 제작하게 되었습니다.  ‘리듬타는 LED Bottle’의 작동원리는 다음과 같습니다. 사용자가 의자에 앉으면 의자에 부착된 압력센서로 압력값이 변하고 이를 확인한 숨어있던 사람이 스위치를 눌러 버저가 울리도록 합니다. 버저가 울린 곳을 바라본 사용자는 안내에 따라 터치센서를 터치합니다. 그 순간 LED 8x8이 켜지고 그 위에 있던 병이 빛납니다. 병의 문구에 따라 사용자가 좋아하는 음악을 켠 스마트폰을 나무 스피커에 꽂으면 소리센서가 음악을 감지하고 측정값에 따라 LED 전구들의 색이 변합니다. 사용자는 좋아하는 음악을 들으며 리듬에 따라 예쁘게 변하는 LED병을 감상하고 즐거운 휴식을 취합니다.

## 사용한 재료 목록 : 아두이노 UNO 2개, 아두이노 나노, 압력센서, 스위치 1개, 터치센서, LED 전구 11개, 버저, 소리센서, 브레드보드 2개, 네오픽셀 호환 RGB LED 모듈, USB 케이블 2개, 기판 2개, 나무상자, 유리병 3개, 5V power supply Jack

# < 작동 순서 >

 압력센서가 부착되어 있는 의자에 사용자(1)가 다가와 앉습니다.
 뒤에 숨어 있던 사람(2)은 압력센서의 측정값이 변한 것을 보고 사용자(1)가 온 것을 인지합니다.
 숨어있던 사람(2)은 스위치를 눌러 사용자(1)가 앉았을 때(압력센서가 무게를 감지했을 때) 작동하도록 만든 버저가 울리도록 합니다.
 버저가 울린 곳을 사용자(1)가 바라보면 그곳에 “빨간색 센서를 터치하세요”라고 쓰여 있는 작은 상자가 하나 있습니다.
 사용자(1)가 손으로 작은 상자의 터치센서를 손으로 터치하면 연결되어 있던 LED 8x8이 켜집니다.
 켜진 LED 8x8 위에 놓여있던 병에는 “환영합니다~ 스마트폰에 음악을 켜고 왼쪽 스피커에 꽂아주세요”라고 문구가 쓰여있습니다.
 문구에 따라 사용자(1)가 나무 스피커에 좋아하는 음악을 켠 스마트폰을 넣습니다.
 스마트폰에서 나오는 소리를 감지한 사운드 센서가 소리의 크기에 따라 R, Y, B, R_1, G_1, G_2 각각의 LED 전구 밝기 값이 변합니다.
 사용자(1)는 선택한 음악의 비트에 맞추어 시시각각 변하는 예쁜 조명을 감상하며 음악을 즐깁니다.





