//
// Created by GV9408 on 28.09.2024.
//

#include "tasks.h"

#if TASK_SELECTION == 1
#include "Task1/task1.h"
#elif TASK_SELECTION == 2
#include "Task2/task2.h"
#elif TASK_SELECTION == 3
#include "Task3/task3.h"
#elif TASK_SELECTION == 4
#include "Task4/task4.h"
#elif TASK_SELECTION == 5
#include "Task5/task5.h"
#elif TASK_SELECTION == 6
#include "Task6/task6.h"
#elif TASK_SELECTION == 7
#include "Task7/task7.h"
#elif TASK_SELECTION == 8
#include "Task8/task8.h"
#else
#error "No or invalid task selected! Please select a task by defining TASK_SELECTION to a value of TASK1 to TASK8."
#endif

void TaskSelection(void)
{
#if TASK_SELECTION == 1
    TaskSelection_Task1();
#elif TASK_SELECTION == 2
    TaskSelection_Task2();
#elif TASK_SELECTION == 3
    TaskSelection_Task3();
#elif TASK_SELECTION == 4
    TaskSelection_Task4();
#elif TASK_SELECTION == 5
    TaskSelection_Task5();
#elif TASK_SELECTION == 6
    TaskSelection_Task6();
#elif TASK_SELECTION == 7
    TaskSelection_Task7();
#elif TASK_SELECTION == 8
    TaskSelection_Task8();
#else
#error "No or invalid task selected! Please select a task by defining TASK_SELECTION to a value of TASK1 to TASK8."
#endif
}

void TasksFreeRtosIdleHook(void)
{

}