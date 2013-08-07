/**
 ******************************************************************************
 * @file    additional_pins.ino
 * @author  JiapengLi
 * @brief   This file provides a demostration on 
 * how to use Taijiuino DUE addtional IO pin.
 ******************************************************************************
 * @note:
 *  Input '0' to flip TaijiPin0, '1' for TaijiPin1, 2 for TaijiPin2 and so on.
 *  This example is only used for TaijiUino DUE
 ******************************************************************************
 * @section  HISTORY
 * 
 * 2013/08/6    Initial version.
 */

/** save pin status */
uint32_t taiji_pin;

void setup() {
  // Serial initialize Native USB serial and USART0
  SerialUSB.begin(115200);
  Serial.begin(115200);

  pinMode(TP0, OUTPUT);
  pinMode(TP1, OUTPUT);
  pinMode(TP2, OUTPUT);
  pinMode(TP3, OUTPUT);
  pinMode(TP4, OUTPUT);
  pinMode(TP5, OUTPUT);
  pinMode(TP6, OUTPUT);

  digitalWrite(TP0, HIGH);
  digitalWrite(TP1, HIGH);
  digitalWrite(TP2, HIGH);
  digitalWrite(TP3, HIGH);
  digitalWrite(TP4, HIGH);
  digitalWrite(TP5, HIGH);
  digitalWrite(TP6, HIGH);

  taiji_pin |= 0x7F;
}

void loop() {
  // Control through USB Serial
  if(SerialUSB.available()){
    switch(SerialUSB.read()){
    case '0':
      if(taiji_pin & (1<<0)){
        taiji_pin &= ~(1<<0);
        digitalWrite(TP0, LOW);
      }
      else{
        taiji_pin |= (1<<0);
        digitalWrite(TP0, HIGH);
      }
      break;
    case '1':
      if(taiji_pin & (1<<1)){
        taiji_pin &= ~(1<<1);
        digitalWrite(TP1, LOW);
      }
      else{
        taiji_pin |= (1<<1);
        digitalWrite(TP1, HIGH);
      }
      break;
    case '2':
      if(taiji_pin & (1<<2)){
        taiji_pin &= ~(1<<2);
        digitalWrite(TP2, LOW);
      }
      else{
        taiji_pin |= (1<<2);
        digitalWrite(TP2, HIGH);
      }
      break;
    case '3':
      if(taiji_pin & (1<<3)){
        taiji_pin &= ~(1<<3);
        digitalWrite(TP3, LOW);
      }
      else{
        taiji_pin |= (1<<3);
        digitalWrite(TP3, HIGH);
      }
      break;
    case '4':
      if(taiji_pin & (1<<4)){
        taiji_pin &= ~(1<<4);
        digitalWrite(TP4, LOW);
      }
      else{
        taiji_pin |= (1<<4);
        digitalWrite(TP4, HIGH);
      }
      break;
    case '5':
      if(taiji_pin & (1<<5)){
        taiji_pin &= ~(1<<5);
        digitalWrite(TP5, LOW);
      }
      else{
        taiji_pin |= (1<<5);
        digitalWrite(TP5, HIGH);
      }
      break;
    case '6':
      if(taiji_pin & (1<<6)){
        taiji_pin &= ~(1<<6);
        digitalWrite(TP6, LOW);
      }
      else{
        taiji_pin |= (1<<6);
        digitalWrite(TP6, HIGH);
      }
      break;
    }
  }

  // Control through USART
  if(Serial.available()){
    switch(Serial.read()){
    case '0':
      if(taiji_pin & (1<<0)){
        taiji_pin &= ~(1<<0);
        digitalWrite(TP0, LOW);
      }
      else{
        taiji_pin |= (1<<0);
        digitalWrite(TP0, HIGH);
      }
      break;
    case '1':
      if(taiji_pin & (1<<1)){
        taiji_pin &= ~(1<<1);
        digitalWrite(TP1, LOW);
      }
      else{
        taiji_pin |= (1<<1);
        digitalWrite(TP1, HIGH);
      }
      break;
    case '2':
      if(taiji_pin & (1<<2)){
        taiji_pin &= ~(1<<2);
        digitalWrite(TP2, LOW);
      }
      else{
        taiji_pin |= (1<<2);
        digitalWrite(TP2, HIGH);
      }
      break;
    case '3':
      if(taiji_pin & (1<<3)){
        taiji_pin &= ~(1<<3);
        digitalWrite(TP3, LOW);
      }
      else{
        taiji_pin |= (1<<3);
        digitalWrite(TP3, HIGH);
      }
      break;
    case '4':
      if(taiji_pin & (1<<4)){
        taiji_pin &= ~(1<<4);
        digitalWrite(TP4, LOW);
      }
      else{
        taiji_pin |= (1<<4);
        digitalWrite(TP4, HIGH);
      }
      break;
    case '5':
      if(taiji_pin & (1<<5)){
        taiji_pin &= ~(1<<5);
        digitalWrite(TP5, LOW);
      }
      else{
        taiji_pin |= (1<<5);
        digitalWrite(TP5, HIGH);
      }
      break;
    case '6':
      if(taiji_pin & (1<<6)){
        taiji_pin &= ~(1<<6);
        digitalWrite(TP6, LOW);
      }
      else{
        taiji_pin |= (1<<6);
        digitalWrite(TP6, HIGH);
      }
      break;
    }
  }
}

