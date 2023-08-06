enable_testing()

set(TEST_NAME ${PROJECT_NAME}_tests)

file(GLOB TEST_FILES CONFIGURE_DEPENDS "*.cpp")

add_executable(${TEST_NAME} ${TEST_FILES} ${INC_FILES})
target_link_libraries(${TEST_NAME} Boost::boost)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

add_custom_target(test
     COMMAND ./${TEST_NAME}
)