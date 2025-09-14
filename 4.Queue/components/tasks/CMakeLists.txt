idf_component_register(SRCS "task1/task1.c" "task2/task2.c" "task3/task3.c" "taskInit/user_task.c"
                       INCLUDE_DIRS "task1" "task2" "task3" "taskInit"
                       REQUIRES freertos BSP queue esp_timer)
