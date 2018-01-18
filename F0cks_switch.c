#include "F0cks_switch.h"

int8_t F0cks_Switch_Init( Switch_HandleTypeDef *handler, Switch_ConfigurationTypeDef config)
{
  int8_t error = 0;

  /* Store configuration in handler */
  handler->configuration.pin      =  config.pin;
  handler->configuration.port      =  config.port;
  handler->configuration.polarity  =  config.polarity;

  return error;
}

int8_t F0cks_Switch_Set_State(Switch_HandleTypeDef *handler, Switch_StateTypeDef state)
{
  int8_t error = 0;

  handler->state = state;
  if( (uint8_t)state == (uint8_t)handler->configuration.polarity )
  {
    error += F0cks_GPIO_Write(
          handler->configuration.port,
          handler->configuration.pin,
          1
        );
  }
  else
  {
    error += F0cks_GPIO_Write(
          handler->configuration.port,
          handler->configuration.pin,
          0
        );
  }

  return error;
}

int8_t F0cks_Switch_Toggle(Switch_HandleTypeDef *handler)
{
	int8_t error = 0;

	error += F0cks_Switch_Set_State(handler, !handler->state);

	return error;
}
