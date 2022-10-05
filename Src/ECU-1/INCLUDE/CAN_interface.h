#ifndef __CAN_INTERFACE_H__
#define __CAN_INTERFACE_H__

/**
 *  Service name    : Can_Init                                             
 *  Service ID[hex] : 0x00                                                 
 *  Sync/Async      : Synchronous                                          
 *  Reentrancy      : Non Reentrant                                        
 *  Parameters (in) : Config Pointer to driver configuration.  Parameters  
 *  (inout)         : None                                                 
 *  Parameters (out): None                                                 
 *  Return value    : None                                                 
 *  Description     : This function initializes the module.                
 */
void Can_Init( const Can_ConfigType* Config);

/**
 *  Service name      : Can_DeInit                                
 *  Service ID[hex]   : 0x10                                      
 *  Sync/Async        : Synchronous                               
 *  Reentrancy        : Non Reentrant                             
 *  Parameters (in)   : None                                      
 *  Parameters (inout): None                                      
 *  Parameters (out)  : None                                      
 *  Return value      : None                                      
 *  Description       : This function de-initializes the module.  
 */
void Can_DeInit( void);


/**
 *  Service name      : Can_SetBaudrate                                                                     
 *  Service ID[hex]   : 0x0f                                                                                
 *  Sync/Async        : Synchronous                                                                         
 *  Reentrancy        : Reentrant for different Controllers. Non reentrant for the same Controller.         
 *  Parameters (in)   : Controller CAN controller, whose baud rate shall be set BaudRateConfigID            
 *                    : references a baud rate configuration by ID (see CanControllerBaudRateConfigID)      
 *  Parameters (inout): None                                                                                
 *  Parameters (out)  : None                                                                                
 *  Return value      : Std_ReturnType E_OK/ Service request accepted, setting of (new) baud rate started   
 *                    :                E_NOT_OK/ Service request not accepted                               
 *  Description       : This service shall set the baud rate configuration of the CAN controller.           
 *                    : Depending on necessary baud rate modifications the controller might have to reset.  
 */
Std_ReturnType Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID);

/**
 *  Service name      : Can_SetControllerMode                                                                                                            
 *  Service ID[hex]   : 0x03                                                                                                                             
 *  Sync/Async        : Asynchronous                                                                                                                     
 *  Reentrancy        : Non Reentrant                                                                                                                    
 *  Parameters (in)   : Controller CAN controller for which the status shall be changed Transition Transition value to request new CAN controller state  
 *  Parameters (inout): None                                                                                                                             
 *  Parameters (out)  : None                                                                                                                             
 *  Return value      : Std_ReturnType E_OK/ request accepted                                                                                            
 *                    :                E_NOT_OK/ request not accepted, a development error occurred                                                      
 *  Description       : This function performs software triggered state transitions of the CAN controller State machine.                                 
 */
Std_ReturnType Can_SetControllerMode( uint8 Controller, Can_ControllerStateType Transition);

/**
 *  Service name      : Can_DisableControllerInterrupts                                    
 *  Service ID[hex]   : 0x04                                                               
 *  Sync/Async        : Synchronous                                                        
 *  Reentrancy        : Reentrant                                                          
 *  Parameters (in)   : Controller CAN controller for which interrupts shall be disabled.  
 *  Parameters (inout): None                                                               
 *  Parameters (out)  : None                                                               
 *  Return value      : None                                                               
 *  Description       : This function disables all interrupts for this CAN controller.     
 */
void Can_DisableControllerInterrupts( uint8 Controller);


/**
 *  Service name      : Can_EnableControllerInterrupts                                      
 *  Service ID[hex]   : 0x05                                                                
 *  Sync/Async        : Synchronous                                                         
 *  Reentrancy        : Reentrant                                                           
 *  Parameters (in)   : Controller CAN controller for which interrupts shall be re-enabled  
 *  Parameters (inout): None                                                                
 *  Parameters (out)  : None                                                                
 *  Return value      : None                                                                
 *  Description       : This function enables all allowed interrupts.                       
 */
void Can_EnableControllerInterrupts( uint8 Controller);

/**
 *  Service name      : Can_CheckWakeup                                                          
 *  Service ID[hex]   : 0x0b                                                                     
 *  Sync/Async        : Synchronous                                                              
 *  Reentrancy        : Non Reentrant                                                            
 *  Parameters (in)   : Controller Controller to be checked for a wakeup.                        
 *  Parameters (inout): None                                                                     
 *  Parameters (out)  : None                                                                     
 *  Return value      : Std_ReturnType E_OK/ API call has been accepted                          
 *                    :                E_NOT_OK/ API call has not been accepted                  
 *  Description       : This function checks if a wakeup has occurred for the given controller.  
 */
Std_ReturnType Can_CheckWakeup( uint8 Controller);


/**
 *  Service name      : Can_GetControllerErrorState                                                                                           
 *  Service ID[hex]   : 0x11                                                                                                                  
 *  Sync/Async        : Synchronous                                                                                                           
 *  Reentrancy        : Non Reentrant for the same ControllerId                                                                               
 *  Parameters (in)   : ControllerId Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for ErrorState.  
 *  Parameters (inout): None                                                                                                                  
 *  Parameters (out)  : ErrorStatePtr Pointer to a memory location, where the error state of the CAN controller will be stored.               
 *  Return value      : Std_ReturnType E_OK/ Error state request has been accepted.                                                           
 *                    :                E_NOT_OK/ Error state request has not been accepted.                                                   
 *  Description       : This service obtains the error state of the CAN controller.                                                           
 */
Std_ReturnType Can_GetControllerErrorState( uint8 ControllerId, Can_ErrorStateType* ErrorStatePtr);


/**
 *  Service name      : Can_GetControllerMode                                                                                         
 *  Service ID[hex]   : 0x12                                                                                                          
 *  Sync/Async        : Synchronous                                                                                                   
 *  Reentrancy        : Non Reentrant                                                                                                 
 *  Parameters (in)   : Controller CAN controller for which the status shall be requested.                                            
 *  Parameters (inout): None                                                                                                          
 *  Parameters (out)  : ControllerModePtr Pointer to a memory location, where the current mode of the CAN controller will be stored.  
 *  Return value      : Std_ReturnType E_OK/ Controller mode request has been accepted.                                               
 *                    :                E_NOT_OK/ Controller mode request has not been accepted.                                       
 *  Description       : This service reports about the current status of the requested CAN controller.                                
 */
Std_ReturnType Can_GetControllerMode( uint8 Controller, Can_ControllerStateType* ControllerModePtr);

/**
 *  Service name      : Can_GetControllerRxErrorCounter                                                                                           
 *  Service ID[hex]   : 0x30                                                                                                                      
 *  Sync/Async        : Synchronous                                                                                                               
 *  Reentrancy        : Non Reentrant for the same ControllerId                                                                                   
 *  Parameters (in)   : ControllerId CAN controller, whose current Rx error counter shall be acquired.                                            
 *  Parameters (inout): None                                                                                                                      
 *  Parameters (out)  : RxErrorCounterPtr Pointer to a memory location, where the current Rx error counter of the CAN controller will be stored.  
 *  Return value      : Std_ReturnType E_OK/ Rx error counter available.                                                                          
 *                    :                E_NOT_OK/ Wrong ControllerId, or Rx error counter not available.                                           
 *  Description       : Returns the Rx error counter for a CAN controller. This value might not be                                                
 *                    : available for all CAN controllers, in which case E_NOT_OK would be returned.                                              
 *                    : Please note that the value of the counter might not be correct at the moment the                                          
 *                    : API returns it, because the Rx counter is handled asynchronously in hardware.                                             
 *                    : Applications should not trust this value for any assumption about the current bus                                         
 *                    : state.                                                                                                                    
 */
Std_ReturnType Can_GetControllerRxErrorCounter( uint8 ControllerId, uint8* RxErrorCounterPtr);

/**
 *  Service name      : Can_GetControllerTxErrorCounter                                                                                           
 *  Service ID[hex]   : 0x31                                                                                                                      
 *  Sync/Async        : Synchronous                                                                                                               
 *  Reentrancy        : Non Reentrant for the same ControllerId                                                                                   
 *  Parameters (in)   : ControllerId CAN controller, whose current Tx error counter shall be acquired.                                            
 *  Parameters (inout): None                                                                                                                      
 *  Parameters (out)  : TxErrorCounterPtr Pointer to a memory location, where the current Tx error counter of the CAN controller will be stored.  
 *  Return value      : Std_ReturnType E_OK/ Tx error counter available.                                                                          
 *                    :                E_NOT_OK/ Wrong ControllerId, or Tx error counter not available.                                           
 *  Description       : Returns the Tx error counter for a CAN controller. This value might not be                                                
 *                    : available for all CAN controllers, in which case E_NOT_OK would be returned.                                              
 *                    : Please note that the value of the counter might not be correct at the moment the                                          
 *                    : API returns it, because the Tx counter is handled asynchronously in hardware.                                             
 *                    : Applications should not trust this value for any assumption about the current bus                                         
 *                    : state.                                                                                                                    
 */
Std_ReturnType Can_GetControllerTxErrorCounter( uint8 ControllerId, uint8* TxErrorCounterPtr);




#endif /* __CAN_INTERFACE_H__ */

