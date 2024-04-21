/*
*********************************************************************************************************
*
*	ģ������ : tcp_client 
*	�ļ����� : tcp_client.h
*	��    �� : V1.0
*	˵    �� : 
*
*	�޸ļ�¼ :
*						�汾��    ����        ����       ˵��
*						V1.0  2019��04��04��  suozhang   �״η���
*
*********************************************************************************************************
*/

#ifndef  __TCP_CLIENT_H__
#define  __TCP_CLIENT_H__

#include "lwip/opt.h"
	
void tcp_client_conn_server_task( void );

int send_server_data( uint8_t *data, uint16_t len );
int received_server_data_process( uint8_t *data, uint16_t len );

#endif
