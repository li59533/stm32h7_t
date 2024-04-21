/**
 **************************************************************************************************
 * @file        first_task.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "first_task.h"

/**
 * @addtogroup    XXX 
 * @{  
 */
#include "clog.h"
#include "FreeRTOS.h"
#include "task.h"

#include "bsp.h"

/**
 * @addtogroup    first_task_Modules 
 * @{  
 */

/**
 * @defgroup      first_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      first_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      first_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      first_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      first_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      first_task_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      first_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      first_task_Functions 
 * @brief         
 * @{  
 */

void First_Task(void * pvParameter)
{
//	DEBUG("First Task Enter\r\n");
//	UBaseType_t firsttask_ramainheap = 0;
//	while(1)
//	{
//		DEBUG("First Task Looping\r\n");

//        										xPortGetFreeHeapSize
//		firsttask_ramainheap = uxTaskGetStackHighWaterMark(NULL);
//        
//		DEBUG("First Task ramain heap:%d %%\r\n",firsttask_ramainheap);
//        vTaskDelay(pdMS_TO_TICKS(1000));
//		
//	}
	
	
  uint32_t ulNotifiedValue     = 0;
	uint32_t ledToggleIntervalMs = 1000;

	for(;;)
	{
		
		/*
			* 参数 0x00      表示使用通知前不清除任务的通知值位，
			* 参数 ULONG_MAX 表示函数xTaskNotifyWait()退出前将任务通知值设置为0
			*/
	 if( pdPASS == xTaskNotifyWait( 0x00, 0xffffffffUL, &ulNotifiedValue, ledToggleIntervalMs ) )
	 {
		 if( ulNotifiedValue < 2000 )
			ledToggleIntervalMs  = ulNotifiedValue;
		 else
			 ledToggleIntervalMs = 1000 / portTICK_PERIOD_MS;
	 }

		LED_TOGGLE ;

//		log_i( "SystemCoreClock:%u,system heap:%u.", SystemCoreClock,xPortGetFreeHeapSize() );

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

