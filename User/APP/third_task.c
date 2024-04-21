/**
 **************************************************************************************************
 * @file        third_task.c
 * @author
 * @version   v0.1.0
 * @date        
 * @brief
 **************************************************************************************************
 * @attention
 *
 **************************************************************************************************
 */
#include "third_task.h"

/**
 * @addtogroup    XXX 
 * @{  
 */
#include "clog.h"
#include "FreeRTOS.h"
#include "task.h"
 
 
#include "tcp_client.h"

/**
 * @addtogroup    third_task_Modules 
 * @{  
 */

/**
 * @defgroup      third_task_IO_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      third_task_Macros_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      third_task_Constants_Defines 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      third_task_Private_Types
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      third_task_Private_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */
 
/**
 * @defgroup      third_task_Public_Variables 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      third_task_Private_FunctionPrototypes 
 * @brief         
 * @{  
 */

/**
 * @}
 */

/**
 * @defgroup      third_task_Functions 
 * @brief         
 * @{  
 */

void Third_Task(void * pvParameter)
{
	DEBUG("Third Task Enter\r\n");
	UBaseType_t thirdtask_ramainheap = 0;
	char send_buf[] = "nihao ??\r\n" ;
	while(1)
	{
		DEBUG("Third Task Looping\r\n");
 
		//thirdtask_ramainheap = uxTaskGetStackHighWaterMark(NULL);
        
		//DEBUG("Third Task ramain heap:%d %%\r\n",thirdtask_ramainheap);
		
		
		send_server_data((uint8_t *)send_buf , sizeof(send_buf));
    vTaskDelay(pdMS_TO_TICKS(2000));
		
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

