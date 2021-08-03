add_library(libcalc_interface INTERFACE)

target_include_directories(libcalc_interface INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/export/include
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/calc_interface>
)

install(TARGETS libcalc_interface)