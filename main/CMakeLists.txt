message(STATUS "Settings main")

set(COMPONENT_SRCDIRS "." "epdgui" "frame")

set(COMPONENT_ADD_INCLUDEDIRS "resources")

list(APPEND COMPONENT_REQUIRES "spi_flash")
list(APPEND COMPONENT_REQUIRES "m5epd")
list(APPEND COMPONENT_REQUIRES "appjs")

register_component()

component_compile_options(
                -Wno-unused-const-variable
	            -Wno-missing-field-initializers)
