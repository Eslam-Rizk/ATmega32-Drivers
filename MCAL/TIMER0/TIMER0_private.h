/*
 * TIMER0_private.h
 *
 *  Created on: Dec 26, 2023
 *      Author: Eslam Rizk
 */

#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

// Timer/Counter Control Register 0 (TCCR0) bits definitions
#define TCCR0           *((volatile uint8*)0x53)
#define TCCR0_CS00      0   // Prescaler pin 0
#define TCCR0_CS01      1   // Prescaler pin 1
#define TCCR0_CS02      2   // Prescaler pin 2
#define TCCR0_WGM01     3   // Timer0 mode pin 1
#define TCCR0_WGM00     6   // Timer0 mode pin 0
#define TCCR0_COM00     4   // OC0 mode pin 0
#define TCCR0_COM01     5   // OC0 mode pin 1
#define TCCR0_FOC0      7   // Force Output Compare on OC0 pin
#define TCCR0_CSmax     7   // Mask for the CS0 pins (0, 1, 2)

// Registers
#define TCNT0           *((volatile uint8*)0x52)  // Timer/Counter Register
#define OCR0            *((volatile uint8*)0x5C)  // Output Compare Register

// Enables
#define TIMSK           *((volatile uint8*)0x59)  // Timer/Counter Interrupt Mask Register
#define TIMSK_TOIE0     0   // Timer/Counter0 Overflow Interrupt Enable
#define TIMSK_OCIE0     1   // Timer/Counter0 Output Compare Match Interrupt Enable

// Flags
#define TIFR            *((volatile uint8*)0x58)  // Timer/Counter Interrupt Flag Register
#define TIFR_TOV0       0   // Timer/Counter0 Overflow Flag
#define TIFR_OCF0       1   // Timer/Counter0 Output Compare Match Flag

// Timer Modes
#define NORMAL_MODE             0   // Normal Timer/Counter Mode
#define PHASE_CORRECT_MODE      1   // Phase Correct PWM Mode
#define CTC_MODE                2   // Clear Timer on Compare Match Mode
#define FAST_PWM                3   // Fast PWM Mode

// Prescaler CS0 Pins Values
#define T0_PRESCALER_cs_1       1   // Timer/Counter0 Prescaler clk/1
#define T0_PRESCALER_cs_8       2   // Timer/Counter0 Prescaler clk/8
#define T0_PRESCALER_cs_64      3   // Timer/Counter0 Prescaler clk/64
#define T0_PRESCALER_cs_256     4   // Timer/Counter0 Prescaler clk/256
#define T0_PRESCALER_cs_1024    5   // Timer/Counter0 Prescaler clk/1024

// Prescaler Values
#define T0_PRESCALER_1          1   // Prescaler Value 1
#define T0_PRESCALER_8          8   // Prescaler Value 8
#define T0_PRESCALER_64         64  // Prescaler Value 64
#define T0_PRESCALER_256        256 // Prescaler Value 256
#define T0_PRESCALER_1024       1024    // Prescaler Value 1024

// Other constants
#define COUNTER_RESOLUTION      256 // Timer/Counter0 Resolution
#define MS_US_CONVERT           1000    // Milliseconds to Microseconds conversion factor

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
