message(STATUS "hal_btspp available at: ${CMAKE_CURRENT_LIST_FILE}")
add_library(hal_btspp INTERFACE)

if(PICO_BTSTACK_ENABLED)
    message(STATUS "Copy btstack_config.h file")
    file(COPY 
        ${CMAKE_CURRENT_SOURCE_DIR}/btstack_config.h 
        DESTINATION ${CMAKE_BINARY_DIR}/..
    )
    target_sources(hal_btspp INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/bl_spp.c
    )
    target_link_libraries(hal_btspp INTERFACE
        pico_stdlib
        pico_btstack_classic
		pico_btstack_cyw43
		pico_cyw43_arch_none
    )
endif()

target_include_directories(hal_btspp INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
