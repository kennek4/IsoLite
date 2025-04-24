project(ISOLITE_TESTS)

add_executable(TESTS test_isolite.cpp)
target_link_libraries(TESTS PRIVATE ISOLITE_LIB doctest)
