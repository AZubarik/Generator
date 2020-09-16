/**************************************************************************//**
*   @file   ad7682.h
*   @brief  Header file for the ad7682 ADC altera avalon IP
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
#ifndef __ad7682_H__
#define __ad7682_H__

/*****************************************************************************/
/***************************** Include Files *********************************/
/*****************************************************************************/

#include "alt_types.h"

/*****************************************************************************/
/******************* Macros and Constants Definitions ************************/
/*****************************************************************************/

#define MEMORY_LINE_SIZE    512
#define MAX_MEMORY_LINES    1024
#define MEMORY_SIZE         (MEMORY_LINE_SIZE * MAX_MEMORY_LINES)

#define RB              1
#define SEQ             (1 << 1)
#define REF             (1 << 3)
#define BW              (1 << 6)
#define INX             (1 << 7)
#define INCC            (1 << 10)
#define CFG             (1 << 13)

#define APCONFIG        0x2
#define COMMCFGR        0x3
#define ADCCFG          0x4
#define IDSTRING        0x5
#define PSUDATA         0x6
#define TRIMDATA        0x7
#define TEST            0x8
#define AUXCFG          0x9
#define SAMPDIV         0xA
#define SOCTIME         0xB
#define SEQPROG         0xC

/*****************************************************************************/
/************************ Functions Declarations *****************************/
/*****************************************************************************/

void AD7682_Reset(void);
void AD7682_WriteEvalBoardRegister(char reg, unsigned short value);
int  AD7682_StartAcquisition(int size, int destination);
int  AD7682_ReadStatus(void);

#endif /*__ad7682_H__ */
