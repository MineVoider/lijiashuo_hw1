#include <Arduino.h>

String inString = ""; // 存储字符串
boolean flag = false; // 标记输入是否完成
int cnt = 0; // 密码正确次数
char inChar; // 暂时储存字节

void setup() {
  Serial.begin(9600);
  while(Serial.read() >= 0){} // 清空串口缓存区
  inString.reserve(200); // 给inString分配内存
}

void loop() {
  if (flag) // 判断输入是否完成
  {
    // 判断密码是否正确
    if ((cnt == 0 && inString == "AA\r\n") ||
        (cnt == 1 && inString == "BB\r\n") ||
        (cnt == 2 && inString == "CC\r\n") ||
        (cnt == 3 && inString == "DD\r\n") )
    {
      cnt++;
    }
    else
    {
      cnt = 0; // 从头检测
      Serial.println("Code is Wrong!");
    }
    if (cnt == 4)
    {
      cnt = 0; // 从头检测
      Serial.println("Code is right!");
    }
    flag = false;
    inString = "";
  }
}

/**
 * @brief 将字符串存储在inString中
*/
void serialEvent() {
  while (Serial.available()) 
  {
    inChar = (char)Serial.read();  // 读取串行数据
    inString += inChar; // 将字符添加到字符串中
    if (inChar == '\n') // 检查是否是回车字符
    {  
      Serial.println(inString);  // 打印接收到的字符串
      flag = true; // 标记输入完成
    } 
  }
}