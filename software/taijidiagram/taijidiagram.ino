uint32_t taiji[76]={
  /** circle */
  0, 14, 15, 16, 17, 18, 19, 20, 21, 22,
  23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
  43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 
  53, 69, 68, 67, 71, 70,  70, 13, 12, 11, 
  10,  9,  8,  7,  6,  5,  4,  3,  2,  1,
  /** arc */
  54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 
  64, 65, 66, 74,
  /** eye */
  76,  //SCLK
  75,  //MOSI
};
unsigned char taiji_pos[76]={
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, 1, 1, 1, 
};

unsigned long time_cur;
unsigned long time_last;
unsigned char time_cnt=0;

unsigned int i;
static unsigned char taiji_off_cnt;
static unsigned char taiji_cnt;
unsigned char taiji_contrast;
#define TAIJI_CONTRAST        7

unsigned sys_contrast;
unsigned sys_pattern_num;

int led_tx = 72;
int led_rx = 73;
void taiji_init(unsigned char contrast)
{
  unsigned char i;
  for(i=0; i<76; i++){
    pinMode(taiji[i], OUTPUT);
    digitalWrite(taiji[i], HIGH);
  }
  taiji_contrast = contrast;
  taiji_cnt = 0;
  taiji_off_cnt = 76 - taiji_contrast;
}

void taiji_scan(void)
{
  for(i=0;i<taiji_contrast;i++){
    taiji_off_cnt++;
    if(taiji_off_cnt==76){
      taiji_off_cnt = 0;
    }
    digitalWrite(taiji[taiji_off_cnt], HIGH);
  }
  for(i=0;i<taiji_contrast;i++){
    taiji_cnt++;
    if(taiji_cnt == 76){
      taiji_cnt = 0;
    }
    if(taiji_pos[taiji_cnt]){
      digitalWrite(taiji[taiji_cnt], LOW);
    }
  }
  //  delay(100);
}

void taiji_pattern_init(unsigned char num)
{
  unsigned char i;
  switch(num){
  case 0:
    for(i=0; i<60; i++){
      taiji_pos[i] = 1;
    }
    for(i=60; i<76; i++){
      taiji_pos[i] = 1;
    }
    break;
  case 1:
    for(i=0; i<60; i++){
      taiji_pos[i] = 1;
    }
    for(i=60; i<76; i++){
      taiji_pos[i] = 0;
    }
    break;
  case 2:
    for(i=0; i<60; i++){
      taiji_pos[i] = 0;
    }
    for(i=60; i<76; i++){
      taiji_pos[i] = 1;
    }
    break;
   case 3:
    for(i=0; i<60; i++){
      if(i%2){
        taiji_pos[i] = 0;
      }else{
        taiji_pos[i] = 1;
      }
    }
    for(i=60; i<76; i++){
      taiji_pos[i] = 1;
    }
    break;
    case 4:
    for(i=0; i<60; i++){
      if(i%2){
        taiji_pos[i] = 1;
      }else{
        taiji_pos[i] = 0;
      }
    }
    for(i=60; i<76; i++){
      taiji_pos[i] = 1;
    }
    break;
  }
}

void setup(void)
{
  SerialUSB.begin(9600);
  sys_contrast = TAIJI_CONTRAST;
  taiji_init(TAIJI_CONTRAST);
  sys_pattern_num = 0;
  
  time_last = millis();
  
  // initialize the digital pin as an output.
  pinMode(led_tx, OUTPUT);     
  pinMode(led_rx, OUTPUT);
  digitalWrite(led_tx, HIGH);   // turn the TX_LED on (HIGH is the voltage level)
  digitalWrite(led_rx, LOW);    // turn the RX_LED on (LOW is the voltage level)
}

void loop(void)
{
  taiji_scan();
  time_cur = millis();
  if(time_cur - time_last>500){
    time_last = time_cur;
    if(!time_cnt){
      time_cnt = 1;
      digitalWrite(led_tx, LOW);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(led_rx, HIGH );
    }else{
      time_cnt = 0;
      digitalWrite(led_tx, HIGH);   // turn the LED on (HIGH is the voltage level)
      digitalWrite(led_rx, LOW);
    }
    
  }
  if(SerialUSB.available()){
    switch(SerialUSB.read()){
    case '1':
      if(sys_contrast == 30){
        break;
      }
      sys_contrast++;
      taiji_init(sys_contrast);
      SerialUSB.write("Level:");
      SerialUSB.println(sys_contrast,DEC);
      break;
    case '2':
      if(sys_contrast == 1){
        break;
      }
      sys_contrast--;
      taiji_init(sys_contrast);
      SerialUSB.write("Level:");
      SerialUSB.println(sys_contrast,DEC);
      break;
    case '3':
      if(sys_contrast == 30){
        break;
      }
      sys_pattern_num++;
      taiji_pattern_init(sys_pattern_num);
      SerialUSB.write("Pattern:");
      SerialUSB.println(sys_pattern_num,DEC);
      break;
    case '4':
      if(sys_pattern_num == 0){
        break;
      }
      sys_pattern_num--;
      taiji_pattern_init(sys_pattern_num);
      SerialUSB.write("Pattern:");
      SerialUSB.println(sys_pattern_num,DEC);
      break;
    }
  }
}





