
#include "task4.h"

#if TASK_SELECTION == 4

static volatile uint32_t myTestVariableFalling = 0;
static volatile uint32_t myTestVariableRising = 0;

/**
 * @brief  EXTI line detection callback.
 * @param  GPIO_Pin: Specifies the pins connected EXTI line.
 * @retval None
 */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)
{
    /*  check if the interrupt is from the correct pin */
    if (GPIO_Pin == USER_BUTTON_Pin)
    {
        /* Please implement your task here */
        myTestVariableRising++;
    }
}

/**
 * @brief  EXTI line detection callback.
 * @param  GPIO_Pin: Specifies the pins connected EXTI line.
 * @retval None
 */
void HAL_GPIO_EXTI_Falling_Callback(uint16_t GPIO_Pin)
{
    /*  check if the interrupt is from the correct pin */
    if (GPIO_Pin == USER_BUTTON_Pin)
    {
        /* Please implement your task here */
        myTestVariableFalling++;
    }
}


void TaskSelection_Task4()
{

}

#endif //TASK_SELECTION == 4
