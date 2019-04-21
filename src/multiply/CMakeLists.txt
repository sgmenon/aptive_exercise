file(GLOB MULTIPLY_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/export/include/multiply/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_definitions(-DBUILDING_MULTIPLY)

add_library(libmultiply SHARED
    ${MULTIPLY_SRCS}
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/export/include" )

target_link_libraries(libmultiply 
                      PUBLIC libcalc_interface)

target_include_directories(libmultiply PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<INSTALL_INTERFACE:include/multiply>  
)

add_subdirectory(unittest)