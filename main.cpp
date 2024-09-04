
// Hiện tại. comment nào t muốn diễn tả cho m hiểu t sẽ viết bằng tiếng Việt
// Comment chuẩn t muốn m học theo để viết comment cho đúng thì sẽ tiếng Anh

// thường thì t sẽ define như t đã nói
// và những biến t viết trong define (và cả const (biến hằng)) t sẽ viết IN
// style code cá nhân và đó là thói quen tốt nên t nghĩ nên làm

#include <Arduino.h>

/* Defines */
#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_DP 9

// tên biến t sẽ viết theo Snake case nghĩa là sd "_"
// tên hàm t sẽ viết theo Camel Case nghĩa là viết hoa từ đầu sau mỗi từ.
// Snake case là đặt tên hàm theo dấu gạch vd: void init_system();
// việc đặt tên này không có đúng sai. phụ thuộc vào thói quen
// nhưng có 2 chuẩn phổ biến là Camel Case và Snake case.

/* variables */
uint8_t counter = 0;

/* Functions */
void initSystem(void);
void initLed7Seg(void);
void led7SegSetColon(uint8_t status);
void led7SegDisplay(const int number);

void setup()
{
  initSystem();
  led7SegSetColon(0);
}

void loop()
{
  if (counter > 9)
  {
    counter = 0;
  }
  led7SegDisplay(counter);
  ++counter;

  delay(1000);
}

/* Functions Implentation */
void initSystem()
{
  initUart();
  initLed7Seg();
}

// chắc m thắc mắc tại sao chúng ta cần Serial.begin(9600); (nếu không có ctring vẫn chạy)
// dòng này chỉ đang muốn thiết lập tốc độ giao tiếp của uart (cổng nối với máy tính)
// tạm thời sẽ hiểu như vận trước. Có cơ hội sẽ nói thêm sau
/**
 * @brief  	Init Uart
 */
void initUart()
{
  Serial.begin(9600);
}

/**
 * @brief  	Init led 7 segment
 */
void initLed7Seg()
{
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_DP, OUTPUT);
}

/**
 * @brief  	Display a digit
 * @param  	num	Number displayed
 */
void led7SegDisplay(const int num)
{
  switch (num)
  {
  case 0:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, LOW);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, HIGH);
    break;
  }
  case 1:
  {
    digitalWrite(SEG_A, HIGH);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, HIGH);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, HIGH);
    digitalWrite(SEG_G, HIGH);
    break;
  }
  case 2:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, HIGH);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, LOW);
    digitalWrite(SEG_F, HIGH);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 3:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, HIGH);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 4:
  {
    digitalWrite(SEG_A, HIGH);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, HIGH);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 5:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, HIGH);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 6:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, HIGH);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, LOW);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 7:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, HIGH);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, HIGH);
    digitalWrite(SEG_G, HIGH);
    break;
  }
  case 8:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, LOW);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    break;
  }
  case 9:
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, HIGH);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    break;
  }
  default: // nếu number < 0 || > 9 thì hàm sẽ bật tất cả các đèn. lúc này m hiểu là sai để debug
  {
    digitalWrite(SEG_A, LOW);
    digitalWrite(SEG_B, LOW);
    digitalWrite(SEG_C, LOW);
    digitalWrite(SEG_D, LOW);
    digitalWrite(SEG_E, LOW);
    digitalWrite(SEG_F, LOW);
    digitalWrite(SEG_G, LOW);
    led7SegSetColon(1);
  }
  }
}

/**
 * @brief	Control the colon led
 * @param	status Status applied to the colon (1: turn on, 0: turn off)
 *          This parameter can be one of the following values:
 *				@arg 0: Turn off
 *				@arg != 0: Turn on
 */
void led7SegSetColon(uint8_t status)
{
  switch (status)
  {
  case 0:
  {
    digitalWrite(SEG_DP, HIGH);
    break;
  }
  default:
  {
    digitalWrite(SEG_DP, LOW);
    break;
  }
  }
}