/**
 * @file shell_task.h
 * @author Bojan Gavrilovic
 * @brief This module contains the shell task
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SHELL_TASK_H
#define SHELL_TASK_H

/****************************************************************************
 * P U B L I C  I N C L U D E S
 * **************************************************************************/
#include "cmsis_os.h"
#include "sys.h"

/****************************************************************************
 * P U B L I C   D E F I N I T I O N S  
 * **************************************************************************/


/****************************************************************************
 * P U B L I C   V A R I A B L E S  
 * **************************************************************************/


/****************************************************************************
 * P U B L I C   F U N C T I O N  P R O T O T Y P E S
 * **************************************************************************/
void    Shell_Task     (void *argument);

#endif // SHELL_TASK_H