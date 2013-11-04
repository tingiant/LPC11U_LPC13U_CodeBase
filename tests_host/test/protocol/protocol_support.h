/**************************************************************************/
/*!
    @file     protocol_support.h
    @author   K. Townsend (microBuilder.eu)

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, K. Townsend (microBuilder.eu)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef _PROTOCOL_SUPPORT_H_
#define _PROTOCOL_SUPPORT_H_

#include "protocol.h"

extern fifo_t ff_prot_cmd; // command fifo in protocol.c

#if defined(CFG_PROTOCOL_VIA_HID)
  #define command_received_isr usb_hid_generic_recv_isr
  #define command_send         usb_hid_generic_send
#elif defined(CFG_PROTOCOL_VIA_BULK)
  #define command_received_isr usb_custom_received_isr
  #define command_send         usb_custom_send
#elif defined(CFG_PROTOCOL_VIA_SSP0)
  #define command_received_isr  ssp0_received_isr
  #define command_send          ssp0_slave_send
#elif defined(CFG_PROTOCOL_VIA_SSP1)
  #define command_received_isr  ssp1_received_isr
  #define command_send          ssp1_slave_send
#endif

#define MOCK_PROT(func, behavior)   XSTRING_CONCAT(func, behavior)

#endif
