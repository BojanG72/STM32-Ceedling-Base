/**
 * @file rtos.c
 * @author Bojan Gavrilovic
 * @brief This module is used as an interface to the RTOS.
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/****************************************************************************
 * P R I V A T E   I N C L U D E S
 * **************************************************************************/
#include "rtos.h"

/****************************************************************************
 * P R I V A T E   D E F I N I T I O N S  
 * **************************************************************************/
#define SHELL_STACK_SIZE    (128*4)

/****************************************************************************
 * P R I V A T E   V A R I A B L E S  
 * **************************************************************************/
/**
 * Task ID number
 * */
typedef enum
{
    SHELL_TASK,
    ////////////
    NUM_OF_TASKS
} RTOS_TaskId;

/**
 * Lookup table holding the task names
 */
const char * const pcTaskNames[] = {
    "SHELL_TASK",
    "END_OF_LIST"
};

///////////////////////////////////
/// SHELL TASK VARIABLES
//////////////////////////////////
static osThreadId_t shellTaskHandle;

static const osThreadAttr_t shellTask_attributes = {
  .name = pcTaskNames[SHELL_TASK],
  .stack_size = SHELL_STACK_SIZE,
  .priority = (osPriority_t) osPriorityNormal,
};


/****************************************************************************
 * P R I V A T E   F U N C T I O N  P R O T O T Y P E S
 * **************************************************************************/
static void     createShellTask         ( void );

/****************************************************************************
 * F U N C T I O N S
 * **************************************************************************/

/**
 * @brief This function is used to initialize and launch the RTOS
 * and all tasks
 * 
 */
void RTOS_Launch ( void )
{
    ///< Init scheduler
    osKernelInitialize();
    ///< Creation of the shell task
    createShellTask();
    ///< Start scheduler
    osKernelStart();
    return;
}

/**
 * @brief This function will create the shell task
 * 
 */
static void createShellTask ( void )
{
    shellTaskHandle = osThreadNew(Shell_Task, NULL, &shellTask_attributes);
    return;
}


