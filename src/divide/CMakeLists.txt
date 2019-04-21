file(GLOB DIVIDE_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/export/include/DIVIDE/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_definitions(-DBUILDING_DIVIDE)

add_library(libdivide SHARED
    ${DIVIDE_SRCS}
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/export/include" )

target_link_libraries(libdivide 
                      PUBLIC libcalc_interface)

target_include_directories(libdivide PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<INSTALL_INTERFACE:include/DIVIDE>  
)

add_subdirectory(unittest)