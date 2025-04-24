project(ISOLITE_TESTS)

add_executable(TESTS test_isolite.cpp)
target_link_libraries(TESTS PRIVATE LIB CORE DOCTEST)
