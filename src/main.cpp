#include <Arduino.h>
#include <avr/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define secuencia0 0
#define secuencia1 1
#define secuencia2 2
#define secuencia3 3

void funcion (unsigned char aux){

  PORTD = (aux & 0b11110000) | (PORTD & 0b00001111);
  PORTB = (aux & 0b00001111) | (PORTB & 0b11110000); 
  _delay_ms (150);
}


int main(void){
  
  DDRB |= (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);
  DDRD |= (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);

  DDRC = DDRC & (~(1 << PC0));
  DDRC = DDRC & (~(1 << PC1));
  DDRC = DDRC & (~(1 << PC2));
  DDRC = DDRC & (~(1 << PC3));


  char secuencia;

  secuencia = 0;
  

  for(;;){

    if ((PINC & (1 << PC0)) == 0){

      secuencia = secuencia0;
    }

    if ((PINC & (1 << PC1)) == 0){

      secuencia = secuencia1;
    }

    if ((PINC & (1 << PC2)) == 0){

      secuencia = secuencia2;
    }

    if ((PINC & (1 << PC3)) == 0){

      secuencia = secuencia3;
    }

    switch (secuencia){

      case 0:
        funcion (1 << PD4);
        funcion (1 << PD5);
        funcion (1 << PD6);
        funcion (1 << PD7);
        funcion (1 << PB0);
        funcion (1 << PB1);
        funcion (1 << PB2);
        funcion (1 << PB3);
        funcion (1 << PB3);
        funcion (1 << PB2);
        funcion (1 << PB1);
        funcion (1 << PB0);
        funcion (1 << PD7);
        funcion (1 << PD6);
        funcion (1 << PD5);
        funcion (1 << PD4);
      break;
    
      case 1:
        funcion (0b11001100);
        funcion (0b00110011);
      break;

      case 2:
        funcion (0b01010101);
        funcion (0b10101010);
      break;

      case 3:
        funcion (0b11111111);
      break;

    }

  }
  return (0);
}