idf_component_register(SRCS "led/led.c" "key/key.c"
                       INCLUDE_DIRS "led" "key"
                       REQUIRES esp_driver_gpio)


# # 自动收集所有子目录的源文件和头文件目录
# file(GLOB_RECURSE BSP_SRCS "*/*.c")
# file(GLOB BSP_INCLUDE_DIRS LIST_DIRECTORIES true RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*")
# list(FILTER BSP_INCLUDE_DIRS INCLUDE REGEX "^[^.]+$")  # 过滤掉隐藏目录

# idf_component_register(SRCS ${BSP_SRCS}
#                        INCLUDE_DIRS ${BSP_INCLUDE_DIRS}
#                        REQUIRES esp_driver_gpio)
                       