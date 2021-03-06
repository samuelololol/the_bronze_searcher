#copy gtest cmakelists template
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
#build gtest
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )

# force build gtest binaries with our build
# -----
# add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# marked for further reference
# -------------------
# # test hello world
# add_executable(test_hello test_hello.cpp)
# #target_link_libraries(test_hello gtest gmock_main)
# target_link_libraries(test_hello gtest)
# add_test(NAME test_hello COMMAND test_hello)


# test cu_common
add_executable(test_cu_common
               ../src/cu_common.h ../src/cu_common.c
               test_cu_common.cpp)
target_link_libraries(test_cu_common gtest)
add_test(NAME test_cu_common COMMAND test_cu_common)

# test cu_file
add_executable(test_cu_file
               ../src/cu_common.h ../src/cu_common.c
               ../src/cu_file.h ../src/cu_file.c
               test_cu_file.cpp)
target_link_libraries(test_cu_file gtest)
add_test(NAME test_cu_file COMMAND test_cu_file)
