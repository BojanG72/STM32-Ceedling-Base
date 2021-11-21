/**
 * @file sys.h
 * @author Bojan Gavrilovic
 * 
 * @brief This module is used to setup and initialize the system. It should be cointained
 * within the BSP layer for the given MCU
 * 
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SYS_H
#define SYS_H

/****************************************************************************
 * P U B L I C  I N C L U D E S
 * **************************************************************************/


/****************************************************************************
 * P U B L I C   D E F I N I T I O N S  
 * **************************************************************************/


/****************************************************************************
 * P U B L I C   V A R I A B L E S  
 * **************************************************************************/


/****************************************************************************
 * P U B L I C   F U N C T I O N  P R O T O T Y P E S
 * **************************************************************************/
void    SYS_Init                    ( void );
void    SYS_ErrorHandler            ( void );
void    GPIO_TogglePin              ( void );

#endif // SYS_H
