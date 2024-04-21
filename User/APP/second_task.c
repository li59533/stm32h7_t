/**
 **************************************************************************************************
 * @file        second_task.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "second_task.h"

/**
 * @addtogroup    XXX 
 * @{  
 */
#include "clog.h"
#include "FreeRTOS.h"
#include "task.h"

#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "netif_port.h"

#include "tcp_client.h"


/**
 * @addtogroup    second_task_Modules 
 * @{  
 */

/**
 * @defgroup      second_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      second_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      second_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      second_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      second_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      second_task_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      second_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */
static void netif_config(void);
/**
 * @}
 */

/**
 * @defgroup      second_task_Functions 
 * @brief         
 * @{  
 */

void Second_Task(void * pvParameter)
{
//	DEBUG("Second Task Enter\r\n");
//	while(1)
//	{
//		DEBUG("Second Task Looping\r\n");
//		vTaskDelay(pdMS_TO_TICKS(1000));
//		
//	}
	
	  /* Create tcp_ip stack thread */
  tcpip_init(NULL, NULL);

  /* Initilaize the netif */
  netif_config();

	for(;;)
	{
		
		tcp_client_conn_server_task();
		
		vTaskDelay( 2000 / portTICK_PERIOD_MS );
	}
	
	
	
}
				

struct netif gnetif; /* network interface structure */

static void netif_config(void)
{
  ip_addr_t ipaddr;
  ip_addr_t netmask;
  ip_addr_t gw;

  IP_ADDR4(&ipaddr,192,168,1,11);
  IP_ADDR4(&netmask,255,255,255,0);
  IP_ADDR4(&gw,192,168,1,1);

  /* add the network interface */ 
  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);
  
  /*  Registers the default network interface. */
  netif_set_default(&gnetif);
	
	/* Set the link callback function, this function is called on change of link status*/
  netif_set_link_callback(&gnetif, eth_link_callback);

}

/*
*********************************************************************************************************
*	�� �� ��: vTaskLwip
*	����˵��: ��ʼ�� ETH,MAC,DMA,GPIO,LWIP,�������߳����ڴ�����̫����Ϣ
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
* �� �� ��: 2  
*********************************************************************************************************
*/
static void vTaskLwip(void *pvParameters)
{

  /* Create tcp_ip stack thread */
  tcpip_init(NULL, NULL);

  /* Initilaize the netif */
  netif_config();

	for(;;)
	{
		
		tcp_client_conn_server_task();
		
		vTaskDelay( 2000 / portTICK_PERIOD_MS );
	}
}







/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

