message(STATUS "peri_w5500 available at: ${CMAKE_CURRENT_LIST_FILE}")
add_library(peri_w5500 INTERFACE)

# --- Fetch external libs from GitHub ---
if(PICO_W5500_ENABLED)
    include(FetchContent)
    FetchContent_Declare(
        wiznet_pico_c
        GIT_REPOSITORY https://github.com/WIZnet-ioNIC/WIZnet-PICO-C.git
        GIT_TAG main  
    )
    FetchContent_MakeAvailable(wiznet_pico_c)
    add_subdirectory(${CMAKE_BINARY_DIR}/_deps/wiznet_pico_c-src/src build)
    message(STATUS "download code for W5500 Ethernet support")

    target_sources(peri_w5500 INTERFACE
    )
    target_link_libraries(peri_w5500 INTERFACE
        pico_stdlib
        hardware_gpio
    )
endif()

# --- Link to project ---
target_include_directories(peri_w5500 INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/../..
)
