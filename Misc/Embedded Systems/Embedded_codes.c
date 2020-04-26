//-------------------------------------------------------------------------------------------------------------------------------
// Analog_input.c
#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
//time sharing

int main(){
    int flag = 0, pot, ldr;
	//Setup the UART
	uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
	//Setup the ADC
	ADCSRA = ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)); //16Mhz/128 = 125Khz the ADC reference clock
	ADCSRA |= (1 << ADEN); //Turn on ADC
	ADMUX |= (1 << REFS0); //Voltage reference from Avcc (5v)
	while(1){
		
		ADMUX &= 0xF0; //Clear the older channel that was read
		if(flag == 0)
		{
			ADMUX |= 1; //ADC channel to be read
			flag = 1;
		}
		else
		{
			ADMUX |= 2;
			flag = 0;
		}
		// 		
		ADCSRA |= (1 << ADSC); //Starts a new conversion
		// x1xx xxxx
		while (ADCSRA & (1 << ADSC)); //Wait until the conversion is done
		// xaxx xxxx  || _BV(ADSC)
		// 0100 0000
		// 0000 0000
		if ( flag == 0)
		{
			ldr = ADCW;
		}
		else
		{
			pot = ADCW;
		}
		printf("pot: %d ldr:%d\n",pot, ldr );
		_delay_ms(250);
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
// Analog_input_interrupt

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

ISR(ADC_vect)
{
	ADCSRA |= (1 << ADSC); //Starts a new conversion
	printf("%d\n", ADCW);
}

int main(){
	//Setup the UART
	uart_init();
    
    stdout = &uart_outpustdoutt;
    stdin  = &uart_input;

	//Setup the ADC
	
	ADCSRA = ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)); //16Mhz/128 = 125Khz the ADC reference clock
	ADCSRA |= (1 << ADEN); //Turn on ADC
	ADCSRA |= (1 << ADIE);
	
	ADMUX &= 0xF0; //Clear the older channel that was read
	ADMUX |= 1; //ADC channel to be read
	ADMUX |= (1 << REFS0); //Voltage reference from Avcc (5v)
	ADCSRA |= (1 << ADSC); //Starts a new conversion
	
	sei();
	
	while(1);
	return 0;
}

// -------------------------------------------------------------------------------------------------------------------------------------
//Analog.c
#include <avr/io.h>
int adc_value;        //Variable used to store the value read from the ADC converter
 
int main(void){
 
	DDRB |= (1<<PB5);    ///PB5/digital 13 is an output
	 
	ADCSRA |= ((1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0));    //Prescaler at 128 so we have an 125Khz clock source
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);                //Avcc(+5v) as voltage reference
	ADCSRB &= ~((1<<ADTS2)|(1<<ADTS1)|(1<<ADTS0));    //ADC in free-running mode
	ADCSRA |= (1<<ADATE);                //Signal source, in this case is the free-running
	ADCSRA |= (1<<ADEN);                //Power up the ADC
	ADCSRA |= (1<<ADSC);                //Start converting
	 
	for(;;){            //The infinite loop
	 adc_value = ADCW;    //Read the ADC value, really that's just it
	 if(adc_value > 512){
	 PORTB |= (1<<PB5);    //If ADC value is above 512 turn led on
	 }
	 else {
	 PORTB &= ~(1<<PB5);    //Else turn led off
	 }
	}
	 
	return 0;
}
//-------------------------------------------------------------------------------------------------------------------------------------
// ctc1.c
#include <avr/io.h>
void ctc_init(){
    // set up timer with prescaler = 64 and CTC mode
    TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	TCNT1 = 0;
    OCR1A = 10000;
}

void delay_func(){
	while (!(TIFR1 & (1 << OCF1A)));
	TIFR1 |= (1 << OCF1A);
}

int main(){

	DDRD = 0xFC;
	ctc_init();
	while(1){
		PORTD = 0b00001000;
		delay_func();
		PORTD = 0b00000000;
		delay_func();
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------
// External.c

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
 
#define DataPort	PORTB	// Using PortB as our Dataport
#define DataDDR		DDRB
 
//Interrupt Service Routine for INT0
ISR(INT0_vect)
{
	unsigned char i, temp;
 
	_delay_ms(500); // Software debouncing control
 
	temp = DataPort;	// Save current value on DataPort
 
	/* This for loop blink LEDs on Dataport 5 times*/
	for(i = 0; i<5; i++)
	{
		DataPort = 0x00;
		_delay_ms(500);	// Wait 5 seconds
		DataPort = 0xFF;
		_delay_ms(500);	// Wait 5 seconds
	}
 
	DataPort = temp;	//Restore old value to DataPort	
}	
 
int main(void)
{
	DDRD = 1<<PD2;		// Set PD2 as input (Using for interupt INT0)
	PORTD = 1<<PD2;		// Enable PD2 pull-up resistor
 
	DataDDR = 0xFF;		// Configure Dataport as output
	DataPort = 0x01;	// Initialise Dataport to 1
 
    EICRA |= (1 << ISC00);    // set INT0 to trigger on ANY logic change
    EIMSK |= (1 << INT0);     // Turns on INT0
 
	sei();				//Enable Global Interrupt
 
    while(1)
    {
		if(DataPort >= 0x35)
			DataPort = 1;
		else
			DataPort = DataPort << 1;	// Shift to the left
 
		_delay_ms(500);	// Wait 5 seconds
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------
// normal.c
#include <avr/io.h>
void normal_init(){
	TCNT1H = 0x0B;
	TCNT1L = 0xDC;
	TCCR1A = 0x00;
	TCCR1B = 0x03;
}

void delay_func(){
	while (!(TIFR1 & 0x01));
	TIFR1 = 0x01;
	TCNT1H = 0x0B;
	TCNT1L = 0xDC;
}

int main(){

	DDRD = 0xFC;
	normal_init();
	while(1){
		PORTD = 0b00001000;
		delay_func();
		PORTD = 0b00000000;
		delay_func();
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------
//pcint_source.c

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <util/delay.h>
#include <stdbool.h>

/*
 * A global flag used to communicate between the Interrupt Service Routine
 * and the main program.  It has to be declared volatile or the compiler
 *  might optimize it out.
 */
volatile bool update = false;

/**
 * set update on a high edge
 */
ISR(PCINT0_vect) {
	if (PINB & _BV(PB0)) update = true;
	_delay_ms(500); // Giant friggin' debounce delay
}

int main(void) {

	/**
	 * Using PB1 as LED output
	 */
	DDRB = 0x02;
	PORTB = 0x00;

	/**
	 * Pin Change Interrupt enable on PCINT0 (PB0)
	 */
	PCICR |= _BV(PCIE0);
	PCMSK0 |= _BV(PCINT0);

	// Turn interrupts on.
	sei();

	for(;;) {

		// This turns interrupts off for the code inside it.  Probably
		// not needed here but it's good to know about.
		ATOMIC_BLOCK(ATOMIC_FORCEON) {

			// If the ISR has indicated we need to update the state
			// then run this block.
			if (update) {

				// Toggle the pins on PORTB on/off.
				PORTB ^= 0x02;
				
			   /*We reset the update flag to false to indicate that
				 * we are done.  This ensures that this block will not
				 * be executed until update is set to true again, which
				 * is only done by the interrupt service routine.*/
				 
				update = false;
			}
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------------------------
//pwm1.c
// this code sets up counter0 for an 8kHz Fast PWM wave @ 16Mhz Clock
#include <avr/io.h>

int main(void)
{
    DDRD |= (1 << DDD6);
    // PD6 is now an output

    OCR0A = 128;
    // set PWM for 50% duty cycle

    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

    TCCR0B |= (1 << CS02) | (1 << CS00);
    // set prescaler to 8 and starts PWM

    while (1);
    {
        // we have a working Fast PWM
    }
}
//-------------------------------------------------------------------------------------------------------------------
//pwm2.c

// this code sets up counter1 A output at 25% and B output at 75% 
// using ICR1 as top (16bit), Fast PWM.
#include <avr/io.h>
int main(void)
{
    DDRB |= (1 << DDB1)|(1 << DDB2);
    // PB1 and PB2 is now an output

    ICR1 = 0xFFFF;
    // set TOP to 16bit

    OCR1A = 0x3FFF;
    // set PWM for 25% duty cycle @ 16bit

    OCR1B = 0xBFFF;
    // set PWM for 75% duty cycle @ 16bit

    TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
    // set none-inverting mode

    TCCR1A |= (1 << WGM11);
    TCCR1B |= (1 << WGM12)|(1 << WGM13);
    // set Fast PWM mode using ICR1 as TOP
    
    TCCR1B |= (1 << CS10);
    // START the timer with no prescaler
 
    while (1);
    {
        // we have a working Fast PWM
    }
}
//---------------------------------------------------------------------------------------------------
//pwm3.c
// this code sets up counter2 for an 8kHz Fast PWM wave @ 16Mhz Clock
#include <avr/io.h>
int main(void)
{
    DDRD |= (1 << DDD6);
    // PD6 is now an output

    OCR2A = 128;
    // set PWM for 50% duty cycle

    TCCR2A |= (1 << COM2A1);
    // set none-inverting mode

    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode

    TCCR2B |= (1 << CS21);
    // set prescaler to 8 and starts PWM

    while (1);
    {
        // we have a working Fast PWM
    }
}
//-------------------------------------------------------------------------------------------------------------------
//watchdog.c

#include <stdio.h>
#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include "uart.h"
#include <avr/interrupt.h>

void watchdogSetup(){
 	cli();
	// clear all interrupts
  	wdt_reset();
	// reset the WDT timer
	/*
	WDTCSR configuration:
	WDIE = 1: Interrupt Enable
	WDE = 1 :Reset Enable
	WDP3 = 0 :For 2000ms Time-out
	WDP2 = 1 :For 2000ms Time-out
	WDP1 = 1 :For 2000ms Time-out
	WDP0 = 1 :For 2000ms Time-out
	*/
	// Enter Watchdog Configuration mode:
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	// Set Watchdog settings:
	WDTCSR = (1<<WDIE) | (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0);	
	// set up interrupts	
	sei();

}

int main() {
	DDRD = 0xFC;
	uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
	int loop_count = 0;
	printf("Starting up...\n");	
	watchdogSetup();

	while(1){
		for (int i = 0; i <= loop_count;i++){
    		PORTD = 0xFF;
    		_delay_ms(100);
    		PORTD = 0x00;;
    		_delay_ms(100);
  		}
  		loop_count++;
  		wdt_reset();
  		printf("%d. Watchdog fed in approx. %d milliseconds. \n", loop_count, loop_count*200);
  	}
}
//-------------------------------------------------------------------------------------------------------------------
//ctc_example1.c
#include <avr/io.h>
int main(void)
{
    while (1)
    {

        // Set the Timer Mode to CTC
        TCCR0A |= (1 << WGM01);

        // Set the value that you want to count to
        OCR0A = 0xF9;

        // start the timer
        TCCR0B |= (1 << CS01) | (1 << CS00);
        // set prescaler to 64 and start the timer

        while ( (TIFR0 & (1 << TOV0) ) > 0)        // wait for the overflow event
        {
        }
        
        TIFR0 |= (1 << TOV0);
        // reset the overflow flag

    }
}
//-------------------------------------------------------------------------------------------------------------------
//ctc_example2.c

// this code sets up a timer0 for 4ms @ 16Mhz clock cycle
// an interrupt is triggered each time the interval occurs.
#include <avr/io.h> 
#include <avr/interrupt.h>
int main(void)
{
    // Set the Timer Mode to CTC
    TCCR0A |= (1 << WGM01);

    // Set the value that you want to count to
    OCR0A = 0xF9;

    TIMSK0 |= (1 << OCIE0A);    //Set the ISR COMPA vect

    sei();         //enable interrupts

    TCCR0B |= (1 << CS02);
    // set prescaler to 256 and start the timer

    while (1)
    {
        //main loop
    }
}

ISR (TIMER0_COMPA_vect)  // timer0 overflow interrupt
{
    //event to be exicuted every 4ms here
}
//-------------------------------------------------------------------------------------------------------------------
//ctc_example3.c
// this code sets up timer1 for a 1s  @ 16Mhz Clock (mode 4)
#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
    OCR1A = 0x3D08;

    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << OCIE1A);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12) | (1 << CS10);
    // set prescaler to 1024 and start the timer

    sei();
    // enable interrupts

    while (1)
    {
        // we have a working Timer
    }
}

ISR (TIMER1_COMPA_vect)
{
    // action to be done every 1 sec
}
//-------------------------------------------------------------------------------------------------------------------
//ctc_example4.c
// this code sets up timer1 for a 200ms  @ 16Mhz Clock (Mode 12)
#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
    ICR1 = 0x30D3;

    TCCR1B |= (1 << WGM12);
    // Mode 4, CTC on OCR1A

    TIMSK1 |= (1 << ICIE1);
    //Set interrupt on compare match

    TCCR1B |= (1 << CS12);
    // set prescaler to 256 and starts the timer

    sei();
    // enable interrupts

    while (1)
    {
        // we have a working Timer
    }
}

ISR (TIMER1_COMPA_vect)
{
    // action to be done every 200ms
}
//-------------------------------------------------------------------------------------------------------------------
//ctc_example5.c
// this code sets up timer2 for a 250us  @ 16Mhz Clock
#include <avr/io.h>
#include <avr/interrupt.h>
int main(void)
{
    OCR2A = 62;

    TCCR2A |= (1 << WGM21);
    // Set to CTC Mode

    TIMSK2 |= (1 << OCIE2A);
    //Set interrupt on compare match

    TCCR2B |= (1 << CS21);
    // set prescaler to 64 and starts PWM

    sei();
    // enable interrupts

    while (1)
    {
        // Main loop
    }
}

ISR (TIMER2_COMPA_vect)
{
    // action to be done every 250 usec
}
//-------------------------------------------------------------------------------------------------------------------