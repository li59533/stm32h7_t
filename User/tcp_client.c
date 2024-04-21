/*
*********************************************************************************************************
*
*	ģ������ : tcp_client
*	�ļ����� : tcp_client.c
*	��    �� : V1.0
*	˵    �� : TCP �ͻ��� �������Ӻ�̨������
*
*	�޸ļ�¼ :
*						�汾��    ����        ����       ˵��
*						V1.0  2019��04��04��  suozhang   �״η���
*
*********************************************************************************************************
*/


#include "tcp_client.h"


/**
 * Log default configuration for EasyLogger.
 * NOTE: Must defined before including the <elog.h>
 */
#if !defined(LOG_TAG)
#define LOG_TAG                    "tcp_client_tag:"
#endif
#undef LOG_LVL
#if defined(XX_LOG_LVL)
    #define LOG_LVL                    XX_LOG_LVL
#endif

#include "elog.h"

#if LWIP_NETCONN

#include "lwip/sys.h"
#include "lwip/api.h"

#include "lwip/tcp.h"
#include "lwip/ip.h"

extern TaskHandle_t xHandleTaskLED;

#define TCP_SERVER_IP   "192.168.1.59"
#define TCP_SERVER_PORT 60000

/* ������ͨ��ʹ��Ȩ�ź��� */
SemaphoreHandle_t xServerCommunicationLockSemaphore = NULL;

static struct netconn *tcp_client_server_conn;

void tcp_client_conn_server_task( void )
{
  struct netbuf *buf;
  void *data;
  u16_t len;
  err_t err;
	
	ip_addr_t server_ip;
	

	
	u16_t server_port = TCP_SERVER_PORT;				     // �������˿ںų�ʼ��

	ip4addr_aton( TCP_SERVER_IP, &server_ip ); 			 // ������IP��ַ��ʼ��

	xServerCommunicationLockSemaphore = xSemaphoreCreateBinary();

	if( NULL == xServerCommunicationLockSemaphore )
	{
			log_e("err:xServerCommunicationLockSemaphore == NULL,while(1).");
			while(1);
	}
	
	for( ;; )
	{
				
		log_i("tcp server connecting %s:%d......", ipaddr_ntoa(&server_ip), server_port );
		
		
		xTaskNotify( xHandleTaskLED, 200, eSetValueWithOverwrite );/* �������Ͽ�����״̬��LED��˸Ϊ200mSһ��. */
		
		/* Create a new connection identifier. */
		tcp_client_server_conn = netconn_new( NETCONN_TCP );
				
		if( tcp_client_server_conn != NULL )
		{		
			//��TCP �ı���� ���ͻ��˲�Ĭ�ϴ򿪣���2018��12��6��10:00:41��SuoZhang
			tcp_client_server_conn->pcb.tcp->so_options |= SOF_KEEPALIVE;

			err = netconn_connect( tcp_client_server_conn, &server_ip, server_port );
					
			if(err == ERR_OK)
			{
				log_i("TCP Server %s:%d connected sucess.", ipaddr_ntoa(&server_ip), server_port );
						
				xSemaphoreGive( xServerCommunicationLockSemaphore ); /* �ͷŷ�����ͨ��ʹ��Ȩ */

				xTaskNotify( xHandleTaskLED, 1000, eSetValueWithOverwrite );/* ����������״̬��LED��˸Ϊ1000mSһ��. */
				
				for( ;; )
				{
					/* receive data until the other host closes the connection */
					if((err = netconn_recv(tcp_client_server_conn, &buf)) == ERR_OK) 
					{
								 //��ȡһ��ָ��netbuf �ṹ�е����ݵ�ָ��
								 if((err = netbuf_data(buf, &data, &len)) == ERR_OK)
								 {
									  received_server_data_process( data, len );
										netbuf_delete(buf);
								 }
								 else
								 {
									 log_e("err:netbuf_data(buf, &data, &len):%d.",err);
								 }
								
					}
					else//if((err = netconn_recv(conn, &buf)) == ERR_OK)
					{
						log_e("err:netconn_recv(conn, &buf):%d.",err);
						netbuf_delete(buf);	
						break; //���ӷ��������˳��������ݵ�ѭ�������½�������
					}
				 }
			 }
			
			 log_e("err:TCP Server %s:%d connect fail,err:%d.", ipaddr_ntoa(&server_ip), server_port, err );
			 netconn_close  ( tcp_client_server_conn );
			 netconn_delete ( tcp_client_server_conn );		
		   vTaskDelay(1000);
		}
		else//(conn!=NULL)
		{
			log_e("err:Can not create tcp_client_server_conn.");
			vTaskDelay(1000);
		}
	}
}

int received_server_data_process( uint8_t *data, uint16_t len )
{
	 return send_server_data( data, len );
}

int send_server_data( uint8_t *data, uint16_t len )
{
												 
	if( tcp_client_server_conn )
	{
		return netconn_write( tcp_client_server_conn, data, len, NETCONN_COPY);
	}
	else
		return ERR_CONN; 

}

#endif /* LWIP_NETCONN */
















