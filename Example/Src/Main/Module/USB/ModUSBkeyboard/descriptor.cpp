//###################################################################"
//
// USB Descriptor File
//
// DON'T EDIT!
//
// This file is auto generated by
//    >php -f USB_Descriptor_Script.php descriptor.txt USBdeviceDescriptor_0
//
//###################################################################

//###################################################################
#include "Hardware/Common/USB/USBdevice/USBdescriptor.h"

//###################################################################
namespace EmbSysLib {
namespace Hw {

//###################################################################
//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
class USBdeviceDescriptor_0 : public USBdeviceDescriptor
{
  private:
    //-----------------------------------------------------------------
    static WORD getId( BYTE typeID,
                       BYTE confID,
                       BYTE interfID,
                       BYTE ID )
    {
      return(   ( ( ID      &0xFF )<< 0 )
               | ( ( interfID&0x0F )<< 4 )
               | ( ( confID  &0x0F )<< 8 )
               | ( ( typeID  &0x0F )<<12 ) );
    }

  public:
    //---------------------------------------------------------------
    virtual DataPointer getDescriptor( BYTE typeID,
                                       BYTE confID,
                                       BYTE interfID,
                                       BYTE ID )
    {
      switch( getId( typeID, confID, interfID, ID ) )
      {
        case 0x0000: return( DataPointer( ( BYTE* )&descriptor[  0], 18 ) ); // Device
        case 0x1100: return( DataPointer( ( BYTE* )&descriptor[ 18], 34 ) ); // Configuration
        case 0x2100: return( DataPointer( ( BYTE* )&descriptor[ 27],  9 ) ); // Interface
        case 0x3100: return( DataPointer( ( BYTE* )&descriptor[ 36],  9 ) ); // HID
        case 0x4100: return( DataPointer( ( BYTE* )&descriptor[ 45],  7 ) ); // Endpoint
        case 0x5100: return( DataPointer( ( BYTE* )&descriptor[ 52], 63 ) ); // Report
        case 0x6000: return( DataPointer( ( BYTE* )&descriptor[115],  4 ) ); // String
        case 0x6001: return( DataPointer( ( BYTE* )&descriptor[119], 14 ) ); // String
        case 0x6002: return( DataPointer( ( BYTE* )&descriptor[133], 20 ) ); // String
        case 0x6003: return( DataPointer( ( BYTE* )&descriptor[153], 14 ) ); // String
        case 0x6004: return( DataPointer( ( BYTE* )&descriptor[167], 10 ) ); // String
        case 0x6005: return( DataPointer( ( BYTE* )&descriptor[177], 18 ) ); // String
      }
      return( DataPointer(  ) );
    }

    //---------------------------------------------------------------
    virtual void registerInterface( BYTE                confId,
                                    BYTE                interfId,
                                    USBdeviceInterface *interface )
    {
      switch( getId( INTERF,confId,interfId,0 ) )
      {
        case 0x2100: interfaces[0] = interface; break;
      }
    }

    //---------------------------------------------------------------
    virtual USBdeviceInterface *getInterface( BYTE confId, BYTE interfId )
    {
      switch( getId( INTERF,confId,interfId,0 ) )
      {
        case 0x2100: return( interfaces[0] );
      }
      return( NULL );
    }

    //---------------------------------------------------------------
    virtual void registerEndpoint( BYTE epId, USBdeviceEndpoint *ep )
    {
      switch( epId )
      {
        case 0x81: epList[0] = ep; break;
        default: break;
      }
    }

    //---------------------------------------------------------------
    virtual USBdeviceEndpoint *getEndpoint( BYTE epId )
    {
      switch( epId )
      {
       case 0x81: return( epList[0] );
        default: break;
      }
      return( NULL );
    }

  private:
    //---------------------------------------------------------------
    static const BYTE          descriptor[196];
    static USBdeviceInterface *interfaces[1];
    static USBdeviceEndpoint  *epList[1];
};


//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
USBdeviceInterface *USBdeviceDescriptor_0::interfaces[1] =
{
  NULL
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
USBdeviceEndpoint *USBdeviceDescriptor_0::epList[1] =
{
  NULL
};

//-------------------------------------------------------------------
//
//-------------------------------------------------------------------
const BYTE USBdeviceDescriptor_0::descriptor[196] =
{

  // DEVICE
    /* bLength            */ 18,
    /* bDescriptorType    */ 0x01,
    /* bcdUSB             */ (0x0200)&0xFF, (0x0200)>>8,
    /* bDeviceClass       */ Device::RESERVED_CLASS,
    /* bDeviceSubClass    */ 0,
    /* bDeviceProtocol    */ 0,
    /* bMaxPacketSize0    */ 64,
    /* idVendor           */ (0x0025)&0xFF, (0x0025)>>8,
    /* idProduct          */ (0x1010)&0xFF, (0x1010)>>8,
    /* bcdDevice          */ (0x0100)&0xFF, (0x0100)>>8,
    /* iManufacturer      */ 0x01,
    /* iProduct           */ 0x02,
    /* iSerialNumber      */ 0x03,
    /* bNumConfigurations */ 1,

  // CONFIGURATION
    /* bLength             */ 9,
    /* bDescriptorType     */ 0x02,
    /* wTotalLength        */ (34)&0xFF, (34)>>8,
    /* bNumInterfaces      */ 1,
    /* bConfigurationValue */ 1,
    /* iConfiguration      */ 0x04,
    /* bmAttributes        */ 0x80| Configuration::SELF_POWERED,
    /* bMaxPower           */ 100,

  // INTERFACE
    /* bLength            */ 9,
    /* bDescriptorType    */ 0x04,
    /* bInterfaceNumber   */ 0,
    /* bAlternateSetting  */ 0,
    /* bNumEndpoints      */ 1,
    /* bInterfaceClass    */ Interface::HUMAN_INTERFACE_DEVICE,
    /* bInterfaceSubClass */ 0,
    /* bInterfaceProtocol */ 0,
    /* iInterface         */ 0x05,

  // HID
    /* bLength           */ 9,
    /* bDescriptorType   */ 0x21,
    /* bcdHID            */ (0x0400)&0xFF, (0x0400)>>8,
    /* bCountryCode      */ HID::Country::INTERNATIONAL,
    /* bNumDescriptors   */ 1,
    /* bDescriptorType   */ 0x22,
    /* wDescriptorLength */ (63)&0xFF, (63)>>8,

  // ENDPOINT */ 
    /* bLength          */ 7,
    /* bDescriptorType  */ 0x05,
    /* bEndpointAddress */ 0x81,
    /* bmAttributes     */ Endpoint::INTERRUPT,
    /* wMaxPacketSize   */ (64)&0xFF, (64)>>8,
    /* bInterval        */ 10,

  // REPORT
    /* UsagePage       */ 0x05, Report::UsagePage::GenericDesktop::PAGE_ID, 
    /* Usage           */ 0x09, Report::UsagePage::GenericDesktop::KEYBOARD, 
    /* Collection      */ 0xA1, Report::Collection::APPLICATION, 
    /* UsagePage       */ 0x05, Report::UsagePage::KeyCodes::PAGE_ID, 
    /* UsageMin        */ 0x19, (BYTE)224, 
    /* UsageMax        */ 0x29, (BYTE)231, 
    /* LogicalMin      */ 0x15, (BYTE)0, 
    /* LogicalMax      */ 0x25, (BYTE)1, 
    /* ReportSize      */ 0x75, 1, 
    /* ReportCount     */ 0x95, 8, 
    /* Input           */ 0x81, Report::DataType::DATA | Report::DataType::VARIABLE | Report::DataType::ABSOLUTE, 
    /* ReportCount     */ 0x95, 1, 
    /* ReportSize      */ 0x75, 8, 
    /* Input           */ 0x81, Report::DataType::CONSTANT, 
    /* ReportCount     */ 0x95, 5, 
    /* ReportSize      */ 0x75, 1, 
    /* UsagePage       */ 0x05, Report::UsagePage::LED::PAGE_ID, 
    /* UsageMin        */ 0x19, (BYTE)1, 
    /* UsageMax        */ 0x29, (BYTE)5, 
    /* Output          */ 0x91, Report::DataType::DATA | Report::DataType:: VARIABLE | Report::DataType:: ABSOLUTE, 
    /* ReportCount     */ 0x95, 1, 
    /* ReportSize      */ 0x75, 3, 
    /* Output          */ 0x91, Report::DataType::CONSTANT, 
    /* ReportCount     */ 0x95, 6, 
    /* ReportSize      */ 0x75, 8, 
    /* LogicalMin      */ 0x15, (BYTE)0, 
    /* LogicalMax      */ 0x25, (BYTE)101, 
    /* UsagePage       */ 0x05, Report::UsagePage::KeyCodes::PAGE_ID, 
    /* UsageMin        */ 0x19, (BYTE)0, 
    /* UsageMax        */ 0x29, (BYTE)101, 
    /* Input           */ 0x81, Report::DataType::DATA | Report::DataType:: ARRAY, 
    /* EndCollection   */ 0xC0, 

  // STRING 0x00
    /* bLength         */ 4,
    /* bDescriptorType */ 0x03,
    (0x0409)&0xFF, (0x0409)>>8,

  // STRING 0x01
    /* bLength         */ 14,
    /* bDescriptorType */ 0x03,
    'H',0,
    '-',0,
    'B',0,
    'R',0,
    'S',0,
    ' ',0,

  // STRING 0x02
    /* bLength         */ 20,
    /* bDescriptorType */ 0x03,
    'E',0,
    'm',0,
    'b',0,
    'S',0,
    'y',0,
    's',0,
    'L',0,
    'i',0,
    'b',0,

  // STRING 0x03
    /* bLength         */ 14,
    /* bDescriptorType */ 0x03,
    'S',0,
    'N',0,
    '0',0,
    '0',0,
    '0',0,
    '0',0,

  // STRING 0x04
    /* bLength         */ 10,
    /* bDescriptorType */ 0x03,
    'D',0,
    'E',0,
    'M',0,
    'O',0,

  // STRING 0x05
    /* bLength         */ 18,
    /* bDescriptorType */ 0x03,
    'D',0,
    'e',0,
    'v',0,
    'i',0,
    'c',0,
    'e',0,
    ' ',0,
    '0',0,

    0 // final byte
};

//*******************************************************************
}  } //namespace
//EOF