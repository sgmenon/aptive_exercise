set(MY_HDRS
	export/include/calc_interface/*.hpp
)

add_library(libcalc_interface INTERFACE)

target_include_directories(libcalc_interface INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}/export/include
)