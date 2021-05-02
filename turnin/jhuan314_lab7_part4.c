/*	Author: Jack Huang
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *      https://drive.google.com/drive/folders/1JBIqqJb-m900203LVLXI8yLaMciH493w?usp=sharing
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1<<ADEN) | (1<<ADSC) | (1<<ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA=0x00; PORTA=0xFF;
    DDRB=0xFF; PORTB=0x00;
    DDRD=0xFF; PORTD=0x00;
    ADC_init();
    unsigned short x = ADC;
    unsigned char temp;
    /* Insert your solution below */
    while (1) {
	//min is 35
	//max is 828
	x = ADC;
	if(x<0x67){
		temp = 0x01;
	}
	else if(x<0xCE){
		temp = 0x03;
	}
	else if(x<0x135){
		temp = 0x07;
	}
	else if(x<0x19C){
		temp = 0x0F;
	}
	else if(x<0x203){
		temp = 0x1F;
	}
	else if(x<0x26A){
		temp = 0x3F;
	}
	else if(x<0x2D1){
		temp = 0x7F;
	}
	else if(x<0x338){
		temp = 0xFF;
	}
	PORTB = temp;
    }
    return 1;
}
