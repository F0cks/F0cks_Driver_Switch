#ifndef F0CKS_SWITCH_H
#define F0CKS_SWITCH_H

#include "stdint.h"

typedef enum
{
  SWITCH_ON_LOW		=  0x00U,   // SWITCH ON with LOW state
	SWITCH_ON_HIGH	=  0x01U    // SWITCH ON with HIGH state

}Switch_PolartityTypeDef;

typedef enum
{
	SWITCH_OFF      =  0x00U,
	SWITCH_ON      =  0x01U
}Switch_StateTypeDef;

typedef struct
{
  uint32_t             		 port;
  uint16_t             		 pin;
  Switch_PolartityTypeDef  polarity;

}Switch_ConfigurationTypeDef;

/**
  * @brief  LED handle Structure definition
  */
typedef struct
{
	Switch_ConfigurationTypeDef  configuration;
  uint8_t                 	   state;

}Switch_HandleTypeDef;

int8_t F0cks_Switch_Init( Switch_HandleTypeDef *handler, Switch_ConfigurationTypeDef config);
int8_t F0cks_Switch_Set_State(Switch_HandleTypeDef *handler, Switch_StateTypeDef state);
int8_t F0cks_Switch_Toggle(Switch_HandleTypeDef *handler);
int8_t F0cks_GPIO_Write(uint32_t port, uint16_t pin, uint16_t state);


#endif //F0CKS_SWITCH_H
