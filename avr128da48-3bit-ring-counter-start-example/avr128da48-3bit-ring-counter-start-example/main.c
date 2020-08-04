#include <atmel_start.h>
#include "util/delay.h"
#include <atomic.h>
#include "stdio.h"
/**
 * **********************************************************
 *  Macros definitions
 * **********************************************************
 **/
#define ONE_SEC (1000)

// string to display on terminal window as soon as MCU is loaded with firmware
const uint8_t applicationStartedText[] = " .............3-bit Ring Counter............\n";

// strings to display on terminal window, when MCU enters ring counter states by switch press
const uint8_t pressSwitchText[] = "Press Switch-";
const uint8_t toDisplayText[]   = "To display";
const uint8_t firstStateText[]  = "First state";
const uint8_t secondStateText[] = "Second state";
const uint8_t thirdStateText[]  = "Third state";
const uint8_t ringCounterText[] = "of the Ring Counter\n";

volatile buttonState_t buttonState = KEY_NO_ACTION;

typedef enum {
	FIRST_STATE_INS_TEXT = 1,
	SECOND_STATE_INS_TEXT,
	THIRD_STATE_INS_TEXT,
} pressSwitchInstruction_t;

typedef enum {
	WAIT_FOR_SWITCH_PRESS0,
	FIRST_STATE_OF_RNG_COUNTER,
	WAIT_FOR_SWITCH_PRESS1,
	SECOND_STATE_OF_RNG_COUNTER,
	WAIT_FOR_SWITCH_PRESS2,
	THIRD_STATE_OF_RNG_COUNTER,
	LAST_STATE,
} rng_counter_state_t;

static rng_counter_state_t ringCounterState;

const uint8_t *displayStrings[] = {
    firstStateText,
    secondStateText,
    thirdStateText,
};

/**
 * **********************************************************
 *  static function's declaration
 * **********************************************************
 **/
static void SendHighSignal(void);
static void RingCounterInit(void);
static void SwitchSignal(void);
static void SendLowSignal(void);
static void FlipflopOutputRead(void);
static void RingCounterState(void);
static void DisableSwitchPress(void);
static void EnableSwitchPress(void);
static void SendButtonPressInstruction(pressSwitchInstruction_t displayStringsIndex, const uint8_t *ringcounterstate);

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	// Ring Counter intialization function
	RingCounterInit();
	/* Replace with your application code */

	while (1) {
		// application task
		RingCounterState();
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  RingCounterState()
  @brief
  *SendButtonPressInstruction()-To print next instruction to the user on terminal window.
  *FlipflopOutputRead()- Reads all three flipflops output and displayed on terminal window.
  *DisableSwitchPress()-Disables the Global interrupt, Pin change interrupt and Timer B peripheral to generate a single
 pulse which is used as a clock to the flipflops. *EnableSwitchPress()-Enables the Global interrupt, Pin change
 interrupt and Timer B peripheral to generate a single pulse which is used as a clock to the flipflops.
  *
 **/
void RingCounterState(void)
{
	switch (ringCounterState) {
	case WAIT_FOR_SWITCH_PRESS0:
	case WAIT_FOR_SWITCH_PRESS1:
	case WAIT_FOR_SWITCH_PRESS2:
		if (buttonState == KEY_PRESSED) {
			ringCounterState = ringCounterState + 1;
			buttonState      = KEY_RELEASED;
		}
		break;
	case FIRST_STATE_OF_RNG_COUNTER:
		DisableSwitchPress();
		printf("\t\t%s=", firstStateText);
		FlipflopOutputRead();
		SendButtonPressInstruction(SECOND_STATE_INS_TEXT, secondStateText);
		EnableSwitchPress();
		ringCounterState = WAIT_FOR_SWITCH_PRESS1;
		break;
	case SECOND_STATE_OF_RNG_COUNTER:
		DisableSwitchPress();
		printf("\t\t%s=", secondStateText);
		FlipflopOutputRead();
		SendButtonPressInstruction(THIRD_STATE_INS_TEXT, thirdStateText);
		EnableSwitchPress();
		ringCounterState = WAIT_FOR_SWITCH_PRESS2;
		break;
	case THIRD_STATE_OF_RNG_COUNTER:
		DisableSwitchPress();
		printf("\t\t%s=", thirdStateText);
		FlipflopOutputRead();
		SendButtonPressInstruction(FIRST_STATE_INS_TEXT, firstStateText);
		EnableSwitchPress();
		ringCounterState = WAIT_FOR_SWITCH_PRESS0;
		break;
	default:
		break;
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  This function reads three flipflops output and displayed on terminal window.
  **/
void FlipflopOutputRead(void)
{
	uint8_t ff1Output;
	uint8_t ff2Output;
	uint8_t ff3Output;
	// Read First FlipFlop output
	ff1Output = PORTA_get_pin_level(3);
	// Read Second FlipFlop output
	ff2Output = PORTD_get_pin_level(3);
	// Read Third FlipFlop output
	ff3Output = PORTB_get_pin_level(3);
	// Print all three FlipFlop's output on terminal window
	printf("%d %d %d\n", ff1Output, ff2Output, ff3Output);
	// delay is given to avoid the text display on terminal window back-to-back continously
	_delay_ms(ONE_SEC);
}

/**
  @Param
  none
  @Returns
   none
  @Description
  In 3-bit Ring Counter example, high signal must be given only to the first flipflop using GPIO PA1 only at start of
 the application. GPIO PA1 pin is made as output and set that pin to high , which feeds logic one signal to flipflop1.
 **/
void SendHighSignal(void)
{
	// Set pin direction to output
	InputSignal_set_dir(PORT_DIR_OUT);

	InputSignal_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    true);
}

/**
  @Param
  none
  @Returns
   none
  @Description
    After reading the first flipflop output and if the output is equal to one, then send Low signal to the first
flipflop. GPIO PA1 pin , which is made as output, sets that pin to low , which feeds logic zero signal to flipflop1.
  This function sends Low signal to the flipflop.
 **/
void SendLowSignal(void)
{
	if (PORTA_get_pin_level(3) == 1) {
		InputSignal_set_level(
		    // <y> Initial level
		    // <id> pad_initial_level
		    // <false"> Low
		    // <true"> High
		    false);
	} else {
		printf("Error\n");
	}
}

/**
  @Param
  none
  @Returns
   none
  @Description
  function to send an instruction to the user to press switch,in order to display the three states of the ring counter
  **/
void SendButtonPressInstruction(pressSwitchInstruction_t displayStringsIndex, const uint8_t *ringcounterstate)
{
	printf("\n%d. %s %s %s %s", displayStringsIndex, pressSwitchText, toDisplayText, ringcounterstate, ringCounterText);
}

/**
  @Param
  none
  @Returns
   none
  @Description
  function to enable the Global interrupt, Pin change interrupt and Timer B peripheral to generate a single pulse which
  is used as a clock to the flipflops.
  **/
void EnableSwitchPress(void)
{
	// Enables the global interrupt
	ENABLE_INTERRUPTS();
	// Enables the Falling edge interrupt on pin PC7 (switch)
	Switch_set_isc(
	    // <y> Pin Input/Sense Configuration
	    // <id> pad_isc
	    // <PORT_ISC_INTDISABLE_gc"> Interrupt disabled but input buffer enabled
	    // <PORT_ISC_BOTHEDGES_gc"> Sense Both Edges
	    // <PORT_ISC_RISING_gc"> Sense Rising Edge
	    // <PORT_ISC_FALLING_gc"> Sense Falling Edge
	    // <PORT_ISC_INPUT_DISABLE_gc"> Digital Input Buffer disabled
	    // <PORT_ISC_LEVEL_gc"> Sense low Level
	    PORT_ISC_RISING_gc);
}

/**
  @Param
  none
  @Returns
   none
  @Description
  function to disable the Global interrupt, Pin change interrupt and Timer B peripheral to generate a single pulse which
  is used as a clock to the flipflops.
  **/
void DisableSwitchPress(void)
{
	// Disables the global interrupt
	DISABLE_INTERRUPTS();
	// Disables the Falling edge interrupt on pin PC7 (switch)
	Switch_set_isc(
	    // <y> Pin Input/Sense Configuration
	    // <id> pad_isc
	    // <PORT_ISC_INTDISABLE_gc"> Interrupt disabled but input buffer enabled
	    // <PORT_ISC_BOTHEDGES_gc"> Sense Both Edges
	    // <PORT_ISC_RISING_gc"> Sense Rising Edge
	    // <PORT_ISC_FALLING_gc"> Sense Falling Edge
	    // <PORT_ISC_INPUT_DISABLE_gc"> Digital Input Buffer disabled
	    // <PORT_ISC_LEVEL_gc"> Sense low Level
	    PORT_ISC_INTDISABLE_gc);
}

/**
  @Param
  none
  @Returns
   none
  @Description
  function which toggles the switch pin PC7, to trigger the
  Timer peripheral to generate a single pulse.With this function, output of the First flipflop
  is changed without a switch press event.
  **/
void SwitchSignal(void)
{
	Switch_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    true);
	_delay_ms(ONE_SEC);
}

/**
  @Param
  none
  @Returns
   none
  @Description
  Ring Counter intialization function. In this function flipflop outputs are changed without
  a switch press event, only at the start of the functionality.
  **/
void RingCounterInit(void)
{
	// setting the GPIO pin PA1 as output and making it high, which feeds logic high signal as input to  first flipflop.
	SendHighSignal();
	_delay_ms(ONE_SEC);
	// making the switch pin PC7 to toggle
	SwitchSignal();
	_delay_ms(ONE_SEC);
	// setting the GPIO pin PA1 to low, after reading first flipflop output.
	SendLowSignal();
	_delay_ms(ONE_SEC);
	// first string to display on terminal window, when MCU is loaded with firmware
	printf("%s", applicationStartedText);
	// Sends press switch instruction to the user on terminal window.
	SendButtonPressInstruction(FIRST_STATE_INS_TEXT, firstStateText);

	// makes the on-board switch connected to pin PC7 as an input pin
	Switch_set_dir(
	    // <y> Pin direction
	    // <id> pad_dir
	    // <PORT_DIR_OFF"> Off
	    // <PORT_DIR_IN"> In
	    // <PORT_DIR_OUT"> Out
	    PORT_DIR_IN);
}
