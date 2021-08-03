add_library(calc_interface INTERFACE)

target_include_directories(calc_interface INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/export/include
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/calc_interface>
)

install(TARGETS calc_interface)