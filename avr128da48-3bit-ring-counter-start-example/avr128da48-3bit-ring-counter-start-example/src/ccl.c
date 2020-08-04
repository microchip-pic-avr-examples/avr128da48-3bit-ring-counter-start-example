/**
 * \file
 *
 * \brief CCL related functionality implementation.
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
 * \addtogroup doc_driver_ccl
 *
 * \section doc_driver_ccl_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <ccl.h>

/**
 * \brief Initialize CCL peripheral
 * \return Return value 0 if success
 */
int8_t DIGITAL_GLUE_LOGIC_0_init()
{

	CCL.SEQCTRL0 = CCL_SEQSEL0_DFF_gc; /* D FlipFlop */

	CCL.SEQCTRL1 = CCL_SEQSEL1_DFF_gc; /* D FlipFlop */

	CCL.SEQCTRL2 = CCL_SEQSEL2_DFF_gc; /* D FlipFlop */

	CCL.TRUTH0 = 238; /* Truth 0: 238 */

	CCL.LUT0CTRLC = CCL_INSEL2_EVENTA_gc; /* Event input source A */

	CCL.LUT0CTRLB = CCL_INSEL0_EVENTB_gc /* Event input source B */
	                | CCL_INSEL1_IN1_gc; /* IO pin LUTn-IN1 input source */

	CCL.LUT0CTRLA = CCL_CLKSRC_IN2_gc        /* Selection by INSEL2 */
	                | CCL_EDGEDET_DIS_gc     /* Edge detector is disabled */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 1 << CCL_OUTEN_bp;     /* Output Enable: enabled */

	CCL.TRUTH1 = 16; /* Truth 1: 16 */

	CCL.LUT1CTRLC = CCL_INSEL2_IN2_gc; /* IO pin LUTn-IN2 input source */

	// CCL.LUT1CTRLB = CCL_INSEL0_MASK_gc /* Masked input */
	//		 | CCL_INSEL1_MASK_gc; /* Masked input */

	CCL.LUT1CTRLA = CCL_CLKSRC_CLKPER_gc     /* Peripheral Clock */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 0 << CCL_OUTEN_bp;     /* Output Enable: disabled */

	CCL.TRUTH2 = 204; /* Truth 2: 204 */

	CCL.LUT2CTRLC = CCL_INSEL2_EVENTA_gc; /* Event input source A */

	CCL.LUT2CTRLB = CCL_INSEL0_MASK_gc      /* Masked input */
	                | CCL_INSEL1_EVENTB_gc; /* Event input source B */

	CCL.LUT2CTRLA = CCL_CLKSRC_IN2_gc        /* Selection by INSEL2 */
	                | CCL_EDGEDET_DIS_gc     /* Edge detector is disabled */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 1 << CCL_OUTEN_bp;     /* Output Enable: enabled */

	CCL.TRUTH3 = 16; /* Truth 3: 16 */

	CCL.LUT3CTRLC = CCL_INSEL2_IN2_gc; /* IO pin LUTn-IN2 input source */

	// CCL.LUT3CTRLB = CCL_INSEL0_MASK_gc /* Masked input */
	//		 | CCL_INSEL1_MASK_gc; /* Masked input */

	CCL.LUT3CTRLA = CCL_CLKSRC_CLKPER_gc     /* Peripheral Clock */
	                | CCL_EDGEDET_DIS_gc     /* Edge detector is disabled */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 0 << CCL_OUTEN_bp;     /* Output Enable: disabled */

	CCL.TRUTH4 = 204; /* Truth 4: 204 */

	CCL.LUT4CTRLC = CCL_INSEL2_EVENTA_gc; /* Event input source A */

	CCL.LUT4CTRLB = CCL_INSEL0_MASK_gc      /* Masked input */
	                | CCL_INSEL1_EVENTB_gc; /* Event input source B */

	CCL.LUT4CTRLA = CCL_CLKSRC_IN2_gc        /* Selection by INSEL2 */
	                | CCL_EDGEDET_DIS_gc     /* Edge detector is disabled */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 1 << CCL_OUTEN_bp;     /* Output Enable: enabled */

	CCL.TRUTH5 = 16; /* Truth 5: 16 */

	CCL.LUT5CTRLC = CCL_INSEL2_EVENTA_gc; /* Event input source A */

	// CCL.LUT5CTRLB = CCL_INSEL0_MASK_gc /* Masked input */
	//		 | CCL_INSEL1_MASK_gc; /* Masked input */

	CCL.LUT5CTRLA = CCL_CLKSRC_CLKPER_gc     /* Peripheral Clock */
	                | CCL_EDGEDET_DIS_gc     /* Edge detector is disabled */
	                | CCL_FILTSEL_DISABLE_gc /* Filter disabled */
	                | 1 << CCL_ENABLE_bp     /* LUT Enable: enabled */
	                | 0 << CCL_OUTEN_bp;     /* Output Enable: disabled */

	CCL.CTRLA = 1 << CCL_ENABLE_bp      /* Enable: enabled */
	            | 0 << CCL_RUNSTDBY_bp; /* Run in Standby: disabled */

	// CCL.INTCTRL0 = CCL_INTMODE0_BOTH_gc /* Sense both edges */
	//		 | CCL_INTMODE1_BOTH_gc /* Sense both edges */
	//		 | CCL_INTMODE2_BOTH_gc /* Sense both edges */
	//		 | CCL_INTMODE3_BOTH_gc; /* Sense both edges */

	// CCL.INTCTRL1 = CCL_INTMODE4_BOTH_gc /* Sense both edges */
	//		 | CCL_INTMODE5_BOTH_gc; /* Sense both edges */

	return 0;
}
