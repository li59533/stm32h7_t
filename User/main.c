/*
*********************************************************************************************************
*
*	ģ������ : ������ģ��
*	�ļ����� : main.c
*	��    �� : V1.1
*	˵    �� : 
*
*	�޸ļ�¼ :
*		�汾��   ����         ����        ˵��
*		V1.0    2018-12-12   Eric2013     1. CMSIS����汾 V5.4.0
*                                     2. HAL��汾 V1.3.0
*
*   V1.1    2019-04-01   suozhang     1. add FreeRTOS V10.20
*
*	Copyright (C), 2018-2030, ���������� www.armfly.com
*
*********************************************************************************************************
*/	
#include "bsp.h"			/* �ײ�Ӳ������ */

#include "FreeRTOS.h"
#include "task_list.h"


#include "task.h"
#include "queue.h"
#include "croutine.h"
#include "semphr.h"
#include "event_groups.h"

/**
 * Log default configuration for EasyLogger.
 * NOTE: Must defined before including the <elog.h>
 */
#if !defined(LOG_TAG)
#define LOG_TAG                    "main_test_tag:"
#endif
#undef LOG_LVL
#if defined(XX_LOG_LVL)
    #define LOG_LVL                    XX_LOG_LVL
#endif

#include "elog.h"



static void vTaskLED (void *pvParameters);
static void vTaskLwip(void *pvParameters);



/*
*********************************************************************************************************
*	�� �� ��: main
*	����˵��: c�������
*	��    ��: ��
*	�� �� ֵ: �������(���账��)
*********************************************************************************************************
*/
int main(void)
{

	bsp_Init();		/* Ӳ����ʼ�� */
	
	/* initialize EasyLogger */
//	if (elog_init() == ELOG_NO_ERR)
//	{
//			/* set enabled format */
//			elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL & ~ELOG_FMT_P_INFO);
//			elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_ALL );
//			elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
//			elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_TAG | ELOG_FMT_TIME);
//			elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~(ELOG_FMT_FUNC | ELOG_FMT_P_INFO));
//			elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~(ELOG_FMT_FUNC | ELOG_FMT_P_INFO));
//		
//			elog_set_text_color_enabled( true );
//		
//			elog_buf_enabled( false );
//		
//			/* start EasyLogger */
//			elog_start();
//	}
	
	//xTaskCreate( vTaskLED, "vTaskLED", 512, NULL, 3, &xHandleTaskLED );
	//xTaskCreate( vTaskLwip,"Lwip"     ,512, NULL, 2, &xHandleTaskLwip );
	
	RTOS_Init();
	
	/* �������ȣ���ʼִ������ */
	//vTaskStartScheduler();
}




/*
*********************************************************************************************************
*	�� �� ��: vTaskLED
*	����˵��: KED��˸	
*	��    ��: pvParameters ���ڴ���������ʱ���ݵ��β�
*	�� �� ֵ: ��
* �� �� ��: 2  
*********************************************************************************************************
*/
static void vTaskLED(void *pvParameters)
{
	
	uint32_t ulNotifiedValue     = 0;
	uint32_t ledToggleIntervalMs = 1000;

	for(;;)
	{
		
		/*
			* ���� 0x00      ��ʾʹ��֪ͨǰ����������ֵ֪ͨλ��
			* ���� ULONG_MAX ��ʾ����xTaskNotifyWait()�˳�ǰ������ֵ֪ͨ����Ϊ0
			*/
	 if( pdPASS == xTaskNotifyWait( 0x00, 0xffffffffUL, &ulNotifiedValue, ledToggleIntervalMs ) )
	 {
		 if( ulNotifiedValue < 2000 )
			ledToggleIntervalMs  = ulNotifiedValue;
		 else
			 ledToggleIntervalMs = 1000 / portTICK_PERIOD_MS;
	 }

		//LED_TOGGLE ;

//		log_i( "SystemCoreClock:%u,system heap:%u.", SystemCoreClock,xPortGetFreeHeapSize() );

	}
}

/***************************** ���������� www.armfly.com (END OF FILE) *********************************/
