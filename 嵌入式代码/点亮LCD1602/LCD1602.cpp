#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 3, en = 4, d4 = 5, d5 = 6, d6 = 7, d7 = 8;  // 定义引脚
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   // 根据引脚，创建一个 lcd 实例

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  lcd.begin(16, 2); // 初始化lcd ，并定义LCD1602的规格
  lcd.setCursor(0, 0); // 设置光标位置为(0,0)
  lcd.print("Hello World!"); // lcd 打印字符串
}
  void loop() {
  lcd.setCursor(0, 1); // 设置光标位置为(0,1)
  lcd.print(millis() / 1000); // 把系统运行的时间打到屏幕上
}