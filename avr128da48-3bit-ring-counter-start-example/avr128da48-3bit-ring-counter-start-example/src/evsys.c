/**
 * \file
 *
 * \brief EVSYS related functionality implementation.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \addtogroup doc_driver_evsys
 *
 * \section doc_driver_evsys_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <evsys.h>

/**
 * \brief Initialize EVSYS interface
 *
 * \return Initialization status.
 */
int8_t EVENT_SYSTEM_0_init()
{

	EVSYS.CHANNEL0 = EVSYS_CHANNEL0_PORTA_PIN2_gc; /* Port A Pin 2 */

	// EVSYS.CHANNEL1 = EVSYS_CHANNEL1_OFF_gc; /* Off */

	EVSYS.CHANNEL2 = EVSYS_CHANNEL2_PORTC_PIN7_gc; /* Port C Pin 7 */

	EVSYS.CHANNEL3 = EVSYS_CHANNEL3_TCB2_CAPT_gc; /* Timer/Counter B2 capture */

	EVSYS.CHANNEL4 = EVSYS_CHANNEL4_CCL_LUT0_gc; /* Configurable Custom Logic LUT0 */

	EVSYS.CHANNEL5 = EVSYS_CHANNEL5_CCL_LUT2_gc; /* Configurable Custom Logic LUT2 */

	EVSYS.CHANNEL6 = EVSYS_CHANNEL6_CCL_LUT4_gc; /* Configurable Custom Logic LUT4 */

	// EVSYS.CHANNEL7 = EVSYS_CHANNEL7_OFF_gc; /* Off */

	// EVSYS.CHANNEL8 = EVSYS_CHANNEL8_OFF_gc; /* Off */

	// EVSYS.CHANNEL9 = EVSYS_CHANNEL9_OFF_gc; /* Off */

	EVSYS.USERCCLLUT0A = EVSYS_USER_CHANNEL3_gc; /* Connect user to event channel 3 */

	// EVSYS.USERCCLLUT1A = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERCCLLUT2A = EVSYS_USER_CHANNEL3_gc; /* Connect user to event channel 3 */

	// EVSYS.USERCCLLUT3A = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERCCLLUT4A = EVSYS_USER_CHANNEL3_gc; /* Connect user to event channel 3 */

	EVSYS.USERCCLLUT5A = EVSYS_USER_CHANNEL0_gc; /* Connect user to event channel 0 */

	EVSYS.USERCCLLUT0B = EVSYS_USER_CHANNEL6_gc; /* Connect user to event channel 6 */

	// EVSYS.USERCCLLUT1B = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERCCLLUT2B = EVSYS_USER_CHANNEL4_gc; /* Connect user to event channel 4 */

	// EVSYS.USERCCLLUT3B = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERCCLLUT4B = EVSYS_USER_CHANNEL5_gc; /* Connect user to event channel 5 */

	// EVSYS.USERCCLLUT5B = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERADC0START = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERPTCSTART = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTB = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTC = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTD = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTE = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTF = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USEREVSYSEVOUTG = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART0IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART1IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART2IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART3IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART4IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERUSART5IRDA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB0CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB0COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB1CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB1COUNT = EVSYS_USER_OFF_gc; /* Off */

	EVSYS.USERTCB2CAPT = EVSYS_USER_CHANNEL2_gc; /* Connect user to event channel 2 */

	// EVSYS.USERTCB2COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB3CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB3COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB4CAPT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCB4COUNT = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCD0INPUTA = EVSYS_USER_OFF_gc; /* Off */

	// EVSYS.USERTCD0INPUTB = EVSYS_USER_OFF_gc; /* Off */

	return 0;
}
