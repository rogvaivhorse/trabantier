/**
 * \file
 *
 * \brief SAM4L Xplained Pro board configuration
 *
 * Copyright (C) 2013 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 * 
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

//#define CONF_BOARD_KEEP_WATCHDOG_AT_INIT

#define CONF_BOARD_COM_PORT

#define CONF_BOARD_SPI
#define CONF_BOARD_SPI_NPCS0
//#define CONF_BOARD_SPI_NPCS1
//#define CONF_BOARD_SPI_NPCS2

//#define SPI_ID          ID_SPI

//Optical Encoder Count
#define OPT_Enc_Count 8

//External Interrupt Pinout
#define EIC_0 EXT4_PIN_9
#define EIC_1 EXT3_PIN_15
#define EIC_2 EXT3_PIN_18	//dont forget to modify from EXT3_PIN_13
#define EIC_3 EXT3_PIN_17	//dont forget to modify from EXT3_PIN_14
#define EIC_4 EXT3_PIN_16
#define EIC_5 EXT2_PIN_7
#define EIC_6 EXT2_PIN_8
#define EIC_7 EXT2_PIN_9

//IO Encoder Pinout
#define IO_ENC_0 EXT2_PIN_6
#define IO_ENC_1 EXT4_PIN_5 //dont forget to modify from EXT3_PIN_11 
#define IO_ENC_2 EXT3_PIN_3
#define IO_ENC_3 EXT3_PIN_4
#define IO_ENC_4 EXT4_PIN_6 //dont forget to modify from EXT3_PIN_12
#define IO_ENC_5 EXT2_PIN_3
#define IO_ENC_6 EXT2_PIN_4
#define IO_ENC_7 EXT2_PIN_5

#endif /* CONF_BOARD_H_INCLUDED */
