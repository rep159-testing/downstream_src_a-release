cmake_minimum_required(VERSION 3.22)
project(downstream_src_a VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

find_package(upstream_c 0.1 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML REQUIRED IMPORTED_TARGET yaml-0.1)

add_library(downstream_src_a SHARED src/downstream_src_a.cpp)
target_include_directories(downstream_src_a PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(downstream_src_a PRIVATE upstream_c::upstream_c PkgConfig::YAML)

install(TARGETS downstream_src_a
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CTest)
if(BUILD_TESTING)
  find_package(GTest REQUIRED)
  add_executable(test_downstream_src_a test/test_downstream_src_a.cpp)
  target_link_libraries(test_downstream_src_a PRIVATE downstream_src_a GTest::gtest_main)
  add_test(NAME test_downstream_src_a COMMAND test_downstream_src_a)
endif()
