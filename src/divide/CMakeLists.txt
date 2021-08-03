file(GLOB DIVIDE_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/export/include/DIVIDE/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_definitions(-DBUILDING_DIVIDE)

add_library(mydivide SHARED
    ${DIVIDE_SRCS}
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/export/include" )

target_link_libraries(mydivide 
                      PUBLIC calc_interface)

target_include_directories(mydivide PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<INSTALL_INTERFACE:include/DIVIDE>  
)

install(TARGETS mydivide DESTINATION lib)

add_subdirectory(unittest)