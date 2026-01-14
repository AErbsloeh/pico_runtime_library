message(STATUS "hal_adc available at: ${CMAKE_CURRENT_LIST_FILE}")
add_library(hal_adc INTERFACE)

target_sources(hal_adc INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/adc.c
)

target_link_libraries(hal_adc INTERFACE
    pico_stdlib
    hardware_pio
    hardware_adc
)

target_include_directories(hal_adc INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
