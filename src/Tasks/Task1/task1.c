
#include "task1.h"

static volatile TickType_t delayTimeTask1 = pdMS_TO_TICKS(100);
static volatile uint32_t forLoopCounterTask1 = 100000;

void LoopDoingNothing(uint32_t forLoopCounter)
{
    for (uint32_t i = 0; i < forLoopCounter; i++)
    {
        __NOP();
    }
}

_Noreturn static void Task1(void *pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        HAL_GPIO_TogglePin(LD5_Green_GPIO_Port, LD5_Green_Pin);

        LoopDoingNothing(forLoopCounterTask1);

        /* Please implement your task here */
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(delayTimeTask1));
    }
}
static volatile TickType_t delayTimeTask2 = pdMS_TO_TICKS(200);
static volatile uint32_t forLoopCounterTask2 = 100000;
_Noreturn static void Task2(void *pvParameters)
{
    while (1)
    {
        HAL_GPIO_TogglePin(LD6_Red_GPIO_Port, LD6_Red_Pin);

        LoopDoingNothing(forLoopCounterTask2);

        /* Please implement your task here */
        vTaskDelay(delayTimeTask2);
    }
}

static TaskHandle_t Task1Handle;
static TaskHandle_t Task2Handle;

void TaskSelection_Task1()
{
    /* Please implement your task here */
    xTaskCreate(Task1, "Task1", configMINIMAL_STACK_SIZE, NULL, osPriorityNormal, &Task1Handle);
    xTaskCreate(Task2, "Task2", configMINIMAL_STACK_SIZE, NULL, osPriorityNormal, &Task2Handle);
}
