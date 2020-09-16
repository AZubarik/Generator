/******************************************************************************
*   @file   ad7682.c
*   @brief  Driver for the AD7682 ADC altera avalon IP
*   @author ACostina
*
*******************************************************************************
* Copyright 2013(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, 
* are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR IMPLIED 
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT, MERCHANTABILITY 
* AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
* INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND 
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************
*   SVN Revision: 1905
******************************************************************************/

/*****************************************************************************/
/***************************** Include Files *********************************/
/*****************************************************************************/

#include "system.h"
#include "ad7682.h"
#include "ad7682_regs.h"

/*****************************************************************************/
/************************ Functions Definitions ******************************/
/*****************************************************************************/

/****************************************************************
* @brief This function performes a softare reset on the AD7682
*        core componenet
*
* @return none 
*****************************************************************/
void AD7682_Reset(void)
{
    IOWR_AD7682_CONTROL(AD7682_0_BASE, 0x00000002);
    IOWR_AD7682_CONTROL(AD7682_0_BASE, 0x00000000);
}

/****************************************************************
* @brief Updates the selected register on the Eval Board
*
* parameter reg     Selects the register in which the value should be
*                   written
* parameter value   The new value to be written in the configuration
*                   register
*
* @return There is no return value
*****************************************************************/

void AD7682_WriteEvalBoardRegister(char reg, unsigned short value)
{
  IOWR_AD7682_DUT (AD7682_0_BASE, (reg << 16) + value);
  IOWR_AD7682_CONTROL (AD7682_0_BASE, 0x0008);
  IOWR_AD7682_DUT (AD7682_0_BASE, 0x00);
  IOWR_AD7682_CONTROL (AD7682_0_BASE, 0x0008);
}

/****************************************************************
* @brief Starts the data acquisition process
* parameter size will send the number of samples that need to 
*                be acquired. For CED1Z must be under 512*1024
* parameter destination will point to the memory location starting 
*                       from where data will be written
*    
* @return 0 if acquisition starts successfully
* @return 1 if the number of samples is too large
*****************************************************************/
int AD7682_StartAcquisition(int size, int destination)
{
    if ( size > (MEMORY_LINE_SIZE * MAX_MEMORY_LINES))
    {
        return 1;
    }
    else
    {
        if (size % 2)
        {
            size++;
        }
        IOWR_AD7682_ACQ_COUNT(AD7682_0_BASE, size);     //write number of samples
        IOWR_AD7682_BASE(AD7682_0_BASE, destination);   //write the memory destination
        IOWR_AD7682_CONTROL(AD7682_0_BASE, 0x00000001); //start acquisition
    }
    return 0;
}

/****************************************************************
* @brief Reads the status register
*
* @return The status register
*****************************************************************/
int AD7682_ReadStatus (void)
{
    return IORD_AD7682_STATUS(AD7682_0_BASE);
}

