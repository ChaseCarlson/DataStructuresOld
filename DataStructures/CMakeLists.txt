# CMakeList.txt : CMake project for DataStructures, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DataStructures "DataStructures.c"  "structure/linked_list/linked_list.h" "structure/linked_list/linked_list_test.c" "structure/linked_list/linked_list_test.h" "structure/linked_list/linked_list.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DataStructures PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
