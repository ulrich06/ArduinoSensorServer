void DEEP_SLEEP(){
  ADCSRA &= ~(1 << 7);
  SMCR |= (1 << 2);
  SMCR |= 1;
  MCUCR |= (3 << 5);
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6);
  __asm__ __volatile__("sleep");
}
int SLEEP_8(int time){
  WDTCSR = (24);
  WDTCSR = (33);
  WDTCSR |= (1 << 6);
  for (int i = 0; i < time % 8; i++)
    DEEP_SLEEP();
  return RETURN_OK;
}

int SLEEP_4(int time){
  WDTCSR = (24);
  WDTCSR = (32);
  WDTCSR |= (1 << 6);
  for (int i = 0; i < time % 4; i++)
    DEEP_SLEEP();
  return RETURN_OK;
}

int SLEEP_2(int time){
  WDTCSR = (24);
  WDTCSR = (7);
  WDTCSR |= (1 << 6);
  for (int i = 0; i < time % 2; i++)
    DEEP_SLEEP();
  return RETURN_OK;
}

int SLEEP_1(int time){
  WDTCSR = (24);
  WDTCSR = (6);
  WDTCSR |= (1 << 6);
  for (int i = 0; i < time % 1; i++)
    DEEP_SLEEP();
  return RETURN_OK;
}
