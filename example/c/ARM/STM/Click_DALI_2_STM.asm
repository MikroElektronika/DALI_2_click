Click_DALI_2_STM_dali2_configTimer:
;click_dali_2_timer.h,15 :: 		static void dali2_configTimer()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_dali_2_timer.h,17 :: 		RCC_APB1ENR.TIM2EN = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(RCC_APB1ENR+0)
MOVT	R0, #hi_addr(RCC_APB1ENR+0)
_SX	[R0, ByteOffset(RCC_APB1ENR+0)]
;click_dali_2_timer.h,18 :: 		TIM2_CR1.CEN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_dali_2_timer.h,19 :: 		TIM2_PSC = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(TIM2_PSC+0)
MOVT	R0, #hi_addr(TIM2_PSC+0)
STR	R1, [R0, #0]
;click_dali_2_timer.h,20 :: 		TIM2_ARR = 7487;
MOVW	R1, #7487
MOVW	R0, #lo_addr(TIM2_ARR+0)
MOVT	R0, #hi_addr(TIM2_ARR+0)
STR	R1, [R0, #0]
;click_dali_2_timer.h,21 :: 		NVIC_IntEnable(IVT_INT_TIM2);
MOVW	R0, #44
BL	_NVIC_IntEnable+0
;click_dali_2_timer.h,22 :: 		TIM2_DIER.UIE = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_DIER+0)
MOVT	R0, #hi_addr(TIM2_DIER+0)
_SX	[R0, ByteOffset(TIM2_DIER+0)]
;click_dali_2_timer.h,23 :: 		TIM2_CR1.CEN = 1;
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;click_dali_2_timer.h,24 :: 		EnableInterrupts();
BL	_EnableInterrupts+0
;click_dali_2_timer.h,25 :: 		}
L_end_dali2_configTimer:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of Click_DALI_2_STM_dali2_configTimer
_Timer_interrupt:
;click_dali_2_timer.h,27 :: 		void Timer_interrupt() iv IVT_INT_TIM2
SUB	SP, SP, #4
STR	LR, [SP, #0]
;click_dali_2_timer.h,29 :: 		dali2_isr();
BL	_dali2_isr+0
;click_dali_2_timer.h,30 :: 		TIM2_SR.UIF = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_SR+0)
MOVT	R0, #hi_addr(TIM2_SR+0)
_SX	[R0, ByteOffset(TIM2_SR+0)]
;click_dali_2_timer.h,31 :: 		}
L_end_Timer_interrupt:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _Timer_interrupt
_systemInit:
;Click_DALI_2_STM.c,35 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_DALI_2_STM.c,37 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_DALI_2_STM.c,38 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_DALI_2_STM.c,39 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_DALI_2_STM.c,41 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_DALI_2_STM.c,43 :: 		dali2_gpioDriverInit( (T_DALI2_P)&_MIKROBUS1_GPIO );
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_dali2_gpioDriverInit+0
;Click_DALI_2_STM.c,44 :: 		dali2_masterInit();
BL	_dali2_masterInit+0
;Click_DALI_2_STM.c,45 :: 		dali2_configTimer();
BL	Click_DALI_2_STM_dali2_configTimer+0
;Click_DALI_2_STM.c,46 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_DALI_2_STM.c,48 :: 		void applicationTask()
SUB	SP, SP, #8
STR	LR, [SP, #0]
;Click_DALI_2_STM.c,53 :: 		for (counter = 0; counter < 2; counter++)
; counter start address is: 4 (R1)
MOVS	R1, #0
; counter end address is: 4 (R1)
L_applicationTask0:
; counter start address is: 4 (R1)
CMP	R1, #2
IT	CS
BCS	L_applicationTask1
;Click_DALI_2_STM.c,55 :: 		dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_OFF, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
STRB	R1, [SP, #4]
MOVS	R3, __DALI2_FOLLOWING_COMMAND
MOVS	R2, __DALI2_BROADCAST_CMD
MOVS	R1, __DALI2_OFF
MOVS	R0, __DALI2_ADDRESS01
BL	_dali2_sendCmd+0
;Click_DALI_2_STM.c,56 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask3:
SUBS	R7, R7, #1
BNE	L_applicationTask3
NOP
NOP
NOP
;Click_DALI_2_STM.c,57 :: 		dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_RECALL_MAX_LEVEL, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
MOVS	R3, __DALI2_FOLLOWING_COMMAND
MOVS	R2, __DALI2_BROADCAST_CMD
MOVS	R1, __DALI2_RECALL_MAX_LEVEL
MOVS	R0, __DALI2_ADDRESS01
BL	_dali2_sendCmd+0
LDRB	R1, [SP, #4]
;Click_DALI_2_STM.c,58 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask5:
SUBS	R7, R7, #1
BNE	L_applicationTask5
NOP
NOP
NOP
;Click_DALI_2_STM.c,53 :: 		for (counter = 0; counter < 2; counter++)
ADDS	R1, R1, #1
UXTB	R1, R1
;Click_DALI_2_STM.c,59 :: 		}
; counter end address is: 4 (R1)
IT	AL
BAL	L_applicationTask0
L_applicationTask1:
;Click_DALI_2_STM.c,61 :: 		for (counter = 0; counter < 8; counter++)
; counter start address is: 4 (R1)
MOVS	R1, #0
; counter end address is: 4 (R1)
L_applicationTask7:
; counter start address is: 4 (R1)
CMP	R1, #8
IT	CS
BCS	L_applicationTask8
;Click_DALI_2_STM.c,63 :: 		dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_DOWN, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
STRB	R1, [SP, #4]
MOVS	R3, __DALI2_FOLLOWING_COMMAND
MOVS	R2, __DALI2_BROADCAST_CMD
MOVS	R1, __DALI2_DOWN
MOVS	R0, __DALI2_ADDRESS01
BL	_dali2_sendCmd+0
LDRB	R1, [SP, #4]
;Click_DALI_2_STM.c,64 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask10:
SUBS	R7, R7, #1
BNE	L_applicationTask10
NOP
NOP
NOP
;Click_DALI_2_STM.c,61 :: 		for (counter = 0; counter < 8; counter++)
ADDS	R1, R1, #1
UXTB	R1, R1
;Click_DALI_2_STM.c,65 :: 		}
; counter end address is: 4 (R1)
IT	AL
BAL	L_applicationTask7
L_applicationTask8:
;Click_DALI_2_STM.c,67 :: 		for (counter = 0; counter < 8; counter++)
; counter start address is: 4 (R1)
MOVS	R1, #0
; counter end address is: 4 (R1)
L_applicationTask12:
; counter start address is: 4 (R1)
CMP	R1, #8
IT	CS
BCS	L_applicationTask13
;Click_DALI_2_STM.c,69 :: 		dali2_sendCmd(_DALI2_ADDRESS01, _DALI2_UP, _DALI2_BROADCAST_CMD, _DALI2_FOLLOWING_COMMAND);
STRB	R1, [SP, #4]
MOVS	R3, __DALI2_FOLLOWING_COMMAND
MOVS	R2, __DALI2_BROADCAST_CMD
MOVS	R1, __DALI2_UP
MOVS	R0, __DALI2_ADDRESS01
BL	_dali2_sendCmd+0
LDRB	R1, [SP, #4]
;Click_DALI_2_STM.c,70 :: 		Delay_ms( 500 );
MOVW	R7, #36223
MOVT	R7, #91
NOP
NOP
L_applicationTask15:
SUBS	R7, R7, #1
BNE	L_applicationTask15
NOP
NOP
NOP
;Click_DALI_2_STM.c,67 :: 		for (counter = 0; counter < 8; counter++)
ADDS	R1, R1, #1
UXTB	R1, R1
;Click_DALI_2_STM.c,71 :: 		}
; counter end address is: 4 (R1)
IT	AL
BAL	L_applicationTask12
L_applicationTask13:
;Click_DALI_2_STM.c,73 :: 		current_state = dali2_masterStatus();
BL	_dali2_masterStatus+0
;Click_DALI_2_STM.c,74 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _applicationTask
_main:
;Click_DALI_2_STM.c,76 :: 		void main()
;Click_DALI_2_STM.c,78 :: 		systemInit();
BL	_systemInit+0
;Click_DALI_2_STM.c,79 :: 		applicationInit();
BL	_applicationInit+0
;Click_DALI_2_STM.c,81 :: 		while (1)
L_main17:
;Click_DALI_2_STM.c,83 :: 		applicationTask();
BL	_applicationTask+0
;Click_DALI_2_STM.c,84 :: 		}
IT	AL
BAL	L_main17
;Click_DALI_2_STM.c,85 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
