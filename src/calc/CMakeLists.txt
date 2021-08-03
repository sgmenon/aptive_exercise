file(GLOB CALC_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
)

add_executable(calc 
    ${CALC_SRCS}
)
                      
target_link_libraries(calc               
                      PUBLIC 
                      libcalc_interface
                      libmultiply 
                      libdivide
                      )

install(TARGETS calc DESTINATION bin)