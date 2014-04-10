cmake_minimum_required(VERSION 2.8)

project(cpp_project_with_errors)

set(EXTRA_LINKER_FLAGS "")


if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable Coverage Reporting in GCC" FALSE)

  if (ENABLE_COVERAGE)
    add_definitions(--coverage -O0)
    SET(EXTRA_LINKER_FLAGS ${EXTRA_LINKER_FLAGS} "--coverage")
  endif()

endif()


list(APPEND CPACK_SOURCE_IGNORE_FILES "${CMAKE_CURRENT_BINARY_DIR}")
list(APPEND CPACK_SOURCE_IGNORE_FILES "\\\\.svn")
list(APPEND CPACK_SOURCE_IGNORE_FILES "\\\\.git")
list(APPEND CPACK_SOURCE_IGNORE_FILES ".swp")
list(APPEND CPACK_SOURCE_IGNORE_FILES ".*~")

set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/license.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/readme.md")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/description.txt")

set(CPACK_PACKAGE_VERSION_MAJOR 4)
set(CPACK_PACKAGE_VERSION_MINOR 3)
set(CPACK_PACKAGE_VERSION_PATCH 1)
set(CPACK_PACKAGE_EXECUTABLES "cpp_project_with_errors;cpp_project_with_errors Eval")
set(CPACK_PACKAGE_VENDOR "cpp_project_with_errors.com")
set(CPACK_PACKAGE_CONTACT "contact@cpp_project_with_errors.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An embedded scripting language for C++")

set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")

set(CPACK_RPM_PACKAGE_LICENSE "BSD")
set(CPACK_RPM_PACKAGE_GROUP "Programming")

set(CHAI_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

configure_file(Doxyfile.in ${CMAKE_BINARY_DIR}/Doxyfile)

include(CTest)
include(CPack)

find_library(READLINE_LIBRARY NAMES readline PATH /usr/lib /usr/local/lib /opt/local/lib)

enable_testing()

macro(breaking_macro a)
  #  message(SEND_ERROR "An Error")


  message(WARNING "A Warning")
  #  cause
  #configure_file(Doxyfile.in)

  message(FATAL_ERROR "A Fatal Error")

endmacro()

breaking_macro("bob")

message(STATUS "Detecting readline support")
if (READLINE_LIBRARY)
    message(STATUS "Found: ${READLINE_LIBRARY}")
    set (READLINE_LIB readline)
    add_definitions(/DREADLINE_AVAILABLE)
else(READLINE_LIBRARY)
    message(STATUS "Not Found")
    set (READLINE_LIB )
    set (READLINE_FLAG )
endif(READLINE_LIBRARY)

if(MSVC)
  add_definitions(/W4)
  if(CMAKE_CL_64)
    add_definitions(/bigobj)
   endif()
else()
  add_definitions(-Wall -Wextra -Wshadow -pedantic)

  if (APPLE)
    # -Wno-missing-field-initializers is for boost on macos
    add_definitions(-Wno-missing-field-initializers -Wno-sign-compare)
  endif()
endif()

include_directories(include)


add_executable(cpp_project_with_errors src/main.cpp)
target_link_libraries(cpp_project_with_errors ${LIBS} ${EXTRA_LINKER_FLAGS})


add_test(NAME Test COMMAND cpp_project_with_errors)

install(TARGETS cpp_project_with_errors ${MODULES} RUNTIME DESTINATION bin LIBRARY DESTINATION lib/cpp_project_with_errors )

install(DIRECTORY include/cpp_project_with_errors DESTINATION include
   PATTERN "*.hpp"
   PATTERN "*/.svn*" EXCLUDE
   PATTERN "*/.git*" EXCLUDE
   PATTERN "*~" EXCLUDE)


