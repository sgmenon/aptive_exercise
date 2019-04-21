file(GLOB CALC_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_definitions(-DBUILDING_CALC)

add_executable(calc 
    ${CALC_SRCS}
)

target_link_libraries(calc 
                      INTERFACE libcalc_interface)
                      
target_link_libraries(calc               
                      LINK_PUBLIC libmultiply 
                      #libdivide
                      )

target_include_directories(calc PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} 
)