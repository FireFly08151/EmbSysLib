//*******************************************************************
/*!
\file   Mcu_Types.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   16.10.2022

License: See file "LICENSE"

\brief Include controller specific header files

All controller specific header files are included here.
*/

//*******************************************************************
#ifndef _MCU_TYPES_H
#define _MCU_TYPES_H

//*******************************************************************
#if defined MCU_STM32L432xC

#else
  #error "device type mismatch"
#endif

//*******************************************************************
#include <stdlib.h>
#include <stdint.h>

//-------------------------------------------------------------------
#include "Sys/stm32l4xx.h"

//*******************************************************************
//
// Summary of clock configuration in system_STM32L1xx.cpp"
//
// These constants doesn't affect the PLCK settings.
// If other clock settings are used, all constants and their usage in
// "Hardware/Src" must be checked.
//
#define system_PCLK          (80000000)
#define system_PCLK_SYSTIC   (system_PCLK)
#define system_PCLK_TIM      (system_PCLK)
#define system_PCLK_I2C      (system_PCLK)
#define system_PCLK_SPI      (system_PCLK)
#define system_PCLK_UART     (system_PCLK)

//*******************************************************************
typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef uint64_t   LWORD;
typedef uint32_t   MTYPE;

//*******************************************************************
#define PROGMEM // nothing to do
#define GET_BYTE_PROGMEM(varName)       (varName)
#define GET_BYTE_PROGMEM_PTR(ptrName)   (*(ptrName))

#endif //_MCU_TYPES_H
