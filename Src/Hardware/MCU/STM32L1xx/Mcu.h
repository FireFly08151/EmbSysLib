//*******************************************************************
/*!
\file   Mcu.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

License: See file "LICENSE"

\brief Include controller specific header files

All controller specific header files are included here.
*/

//*******************************************************************
#ifndef _HW_MCU_H
#define _HW_MCU_H

//*******************************************************************
#include <stdlib.h>
#include <stdint.h>

//*******************************************************************
#include "Sys/stm32l1xx.h"

//*******************************************************************
#include "Std/Report.h"
#include "Hardware/ReportID_Hw.h"
#include "PinConfig.h"

//*******************************************************************
#include "Src/Adc_Mcu.h"
#include "Src/Dac_Mcu.h"
#include "Src/I2Cmaster_Mcu.h"
#include "Src/Memory_BKRAM.h"
#include "Src/Memory_EEPROM.h"
#include "Src/Memory_Flash.h"
#include "Src/Port_Mcu.h"
#include "Src/Rtc_Mcu.h"
#include "Src/Timer_Mcu.h"
#include "Src/Uart_Mcu.h"
#include "Src/USBdevice_Mcu.h"

#endif //_HW_MCU_H
