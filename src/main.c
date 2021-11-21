/**
 * @file main.c
 * @author Bojan Gavrilovic
 * @brief 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/****************************************************************************
 * P R I V A T E   I N C L U D E S
 * **************************************************************************/
#include "main.h"


/****************************************************************************
 * P R I V A T E   D E F I N I T I O N S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   V A R I A B L E S  
 * **************************************************************************/


/****************************************************************************
 * P R I V A T E   F U N C T I O N S
 * **************************************************************************/

#ifdef STM32
/**
 * @brief The function main is used to call AppMain.
 * It is structured this way so that AppMain can be run as a unit test if needed
 * 
 * @return int 
 */
  int main ( void )              
  {
    return AppMain();
  }
#endif // STM32


/**
 * @brief The main entry point into the firmware. Here is where the system is setup
 *  and the RTOS kernel is launched
 * 
 * @return int 
 */
int AppMain( void )
{
    ///< Initialize the system
    SYS_Init();

    ///< Launch the RTOS and pass control to the scheduler
    RTOS_Launch();

    LOOP
    {

    }
    return 0;
}

