/**
 * @file shell_task.c
 * @author Bojan Gavrilovic
 * @brief This module contains the shell task
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/****************************************************************************
 * P R I V A T E   I N C L U D E S
 * **************************************************************************/
#include "shell_task.h"

/****************************************************************************
 * P R I V A T E   D E F I N I T I O N S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   V A R I A B L E S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   F U N C T I O N  P R O T O T Y P E S
 * **************************************************************************/


/****************************************************************************
 * F U N C T I O N S
 * **************************************************************************/

/**
 * @brief The main shell task loop
 * 
 * @param argument 
 */
void Shell_Task ( void *argument )
{
  for(;;)
  {
    GPIO_TogglePin();
    osDelay(100);
  }
}
