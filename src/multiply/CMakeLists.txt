file(GLOB MULTIPLY_SRCS
	${CMAKE_CURRENT_SOURCE_DIR}/export/include/multiply/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_definitions(-DBUILDING_MULTIPLY)

add_library(mymultiply SHARED
    ${MULTIPLY_SRCS}
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/export/include" )

target_link_libraries(mymultiply 
                      PUBLIC calc_interface)

target_include_directories(mymultiply PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export/include>
  $<INSTALL_INTERFACE:include/multiply>  
)

install(TARGETS mymultiply DESTINATION lib)

add_subdirectory(unittest)