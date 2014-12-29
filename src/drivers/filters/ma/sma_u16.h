/**************************************************************************/
/*!
    @file     sma_u16.h
    @author   Nguyen Quang Huy, Nguyen Thien Tin

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
#ifndef __SMA_U16_H__
#define __SMA_U16_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "projectconfig.h"

typedef struct sma_u16_s
{
  uint32_t        k;            /**< Total number of samples processed so far                           */
  uint16_t const  size;         /**< Window size (number of samples to average)                         */
  uint16_t        avg;          /**< Current average                                                    */
  uint16_t        exponent;     /**< Exponential number (size=window)                                   */
  uint16_t       *buffer;       /**< Pointer to the input data buffer (size=window)                     */
  uint32_t        total;        /**< Total value of current window (use uint32 for overflow prevention) */
} sma_u16_t;

err_t sma_u16_init ( sma_u16_t *sma );
void    sma_u16_add  ( sma_u16_t *sma, uint16_t x );

#ifdef __cplusplus
}
#endif

#endif /* __SMA_U16_H__ */
