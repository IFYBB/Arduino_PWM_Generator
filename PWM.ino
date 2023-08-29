// 1.5 kHz, 2.5 us 

void pwm6configure()
{
  // TCCR4B configuration
  TCCR4B = 8; /* 4 sets 23437Hz */ // 6 = OK!
  /* 2 sets 157898Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 8 sets 2467Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 10 sets 616Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 11 sets 308Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 12 sets 154Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 14 sets 38Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;
  /* 15 sets 19Hz */ // PLLFRQ = (PLLFRQ & 0xCF) | 0x30; OCR4C = 151;

  // TCCR4C configuration
  TCCR4C = 0;

  // TCCR4D configuration
  TCCR4D = 0;

  // PLL Configuration
  PLLFRQ = (PLLFRQ & 0xCF) | 0x30;

  // Terminal count for Timer 4 PWM
  OCR4C = 255; // OCR4C = 255; // 
}

// Set PWM to D6 (Timer4 D)
// Argument is PWM between 0 and 255
void pwmSet6(int value)
{
  OCR4D = value;  // Set PWM value
  DDRD |= 1 << 7; // Set Output Mode D7
  TCCR4C |= 0x09; // Activate channel D
}

void setup() {
  pwm6configure();
  pwmSet6(254);
}

void loop() {


}

