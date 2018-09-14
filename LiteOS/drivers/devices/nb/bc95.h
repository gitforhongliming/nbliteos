/*----------------------------------------------------------------------------
 * Copyright (c) <2016-2018>, <Huawei Technologies Co., Ltd>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *---------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Notice of Export Control Law
 * ===============================================
 * Huawei LiteOS may be subject to applicable export control laws and regulations, which might
 * include those applicable to Huawei LiteOS of U.S. and the country in which you are located.
 * Import, export and usage of Huawei LiteOS in any manner by you shall be in compliance with such
 * applicable export control laws and regulations.
 *---------------------------------------------------------------------------*/

#ifndef __NB_NEUL_BC95_H__
#define __NB_NEUL_BC95_H__

#include "atadapter.h"

//#define CLOUD_IP  "218.4.33.71,5683"
#define AT_NB_LINE_END 			"\r\n"

#define AT_NB_reboot    		"AT+NRB\r"
#define AT_NB_hw_detect    		"AT+CFUN?\r"
#define AT_NB_get_auto_connect    		"AT+NCONFIG?\r"
#define AT_CMD_PREFIX      "+NNMI:"

#define AT_MODU_NAME        "nb_neul95"
#define AT_USART_PORT       3
#define AT_BUARDRATE        9600
#define AT_CMD_TIMEOUT      10000    //ms
#define AT_MAX_LINK_NUM     4
#define MAX_AT_USERDATA_LEN (1024*5)
#define AT_MAX_PAYLOADLEN     512

#define NB_STAT_LOCALPORT 56
#define AT_LINE_END 		"\r\n"
#define AT_CMD_BEGIN		"\r\n"
#define AT_DATAF_PREFIX      "+NSONMI"
#define MAX_SOCK_NUM 5
typedef struct _remote_info_t
{
    int socket;
    unsigned short port;
    char ip[16];
}remote_info;//struct to save socket info

int str_to_hex(const char *bufin, int len, char *bufout);
int32_t nb_set_cdpserver(char* host, char* port);
int32_t nb_hw_detect(void);
int32_t nb_get_netstat(void);
int nb_query_ip(void);
int32_t nb_send_payload(const char* buf, int len);
int32_t nb_check_csq(void);
int32_t nb_send_psk(char* pskid, char* psk);
int32_t nb_set_no_encrypt(void);
int32_t nb_reboot(void);
int32_t nb_recv_timeout(int32_t id , uint8_t  *buf, uint32_t len, int32_t timeout);
#endif