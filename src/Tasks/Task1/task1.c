
#include "task1.h"

static volatile TickType_t delayTimeTask1 = pdMS_TO_TICKS(10);
static volatile uint32_t forLoopCounterTask1 = 100000;

#define TABLE_SIZE 256
#define PI 3.14159265358979323846

// Lookup table for sine values
uint16_t sineTable[TABLE_SIZE];

// Function to initialize the sine table
void initSineTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        sineTable[i] = (uint16_t)((sin(2 * PI * i / TABLE_SIZE) + 1) * 32767.5); // Scale to 0-65535 range
    }
}

// Function to get sine value from the table
uint16_t getSineValue(uint16_t angle) {
    return sineTable[angle % TABLE_SIZE];
}

void LoopDoingNothing(uint32_t forLoopCounter)
{
    for (uint32_t i = 0; i < forLoopCounter; i++)
    {
        __NOP();
    }
}

void LoopDoingNothing2(uint32_t forLoopCounter)
{
    for (uint32_t i = 0; i < forLoopCounter; i++)
    {
        __NOP();
    }
}
static uint32_t myTestVariable = 0;
static uint32_t mySineValue = 0;
static uint16_t sineValue;
_Noreturn static void Task1(void *pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();
    uint32_t counter = 0;
    initSineTable();
    while (1)
    {
        //HAL_GPIO_TogglePin(LD5_Green_GPIO_Port, LD5_Green_Pin);

        // Example usage
        counter++;
        sineValue = getSineValue(counter);

        LoopDoingNothing(forLoopCounterTask1);

        if(myTestVariable <= 10)
        {
            myTestVariable ++;
        }
        else
        {
            myTestVariable = 0;
        }

        /* Please implement your task here */
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(delayTimeTask1));
    }
}
static volatile TickType_t delayTimeTask2 = pdMS_TO_TICKS(500);
static volatile uint32_t forLoopCounterTask2 = 0;
_Noreturn static void Task2(void *pvParameters)
{
    while (1)
    {
//        HAL_GPIO_TogglePin(LD6_Red_GPIO_Port, LD6_Red_Pin);

        LoopDoingNothing2(forLoopCounterTask2);

        /* Please implement your task here */
        //vTaskDelay(delayTimeTask2);
    }
}
static volatile TickType_t delayTimeTask3 = pdMS_TO_TICKS(10);
static volatile uint32_t forLoopCounterTask3 = 0;
void Task3(void *pvParameters)
{
    while (1)
    {
        LoopDoingNothing(forLoopCounterTask3);

        /* Please implement your task here */
        vTaskDelay(delayTimeTask3);
    }
}
static TaskHandle_t Task1Handle;
static TaskHandle_t Task2Handle;
static TaskHandle_t Task3Handle;

void TaskSelection_Task1()
{
    /* Please implement your task here */
    xTaskCreate(Task1, "Task1", configMINIMAL_STACK_SIZE, NULL, osPriorityNormal, &Task1Handle);
    xTaskCreate(Task2, "Task2", configMINIMAL_STACK_SIZE, NULL, osPriorityNormal, &Task2Handle);
    //xTaskCreate(Task3, "Task3", configMINIMAL_STACK_SIZE, NULL, osPriorityAboveNormal, &Task3Handle);
}
