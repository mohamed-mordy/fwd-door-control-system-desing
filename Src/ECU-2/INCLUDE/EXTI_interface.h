#ifndef __EXTI_INTERFACE_H__
#define __EXTI_INTERFACE_H__


#define LOW_LEVEL         0b00
#define BOTH_EDGES        0b01
#define FALLING_EDGE      0b10
#define RISING_EDGE       0b11


#define EXTI_0     0
#define EXTI_1     1
#define EXTI_2     2

void EXTI_vInit(void);
void EXTI_vSetSenseCtrl(u8 extiPin, u8 sensoCtrl);
void EXTI_vEnableInterrupt(u8 extiPin, u8 senseCtrl);
void EXTI_vDisableInterrupt(u8 extiPin);
void EXTI_vRegisterCallback(u8 extiPin, void (*fptr)(void));



#endif /* __EXTI_INTERFACE_H__ */

