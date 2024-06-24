###############################################################################
###               University of Hawaii, College of Engineering
###               Animal Farm - EE 205 - Spring 2023
###
### Tells cmake about the project's source files and targets
###
### @see https://cmake.org/cmake/help/latest/manual/cmake-language.7.html
###
### @file   CMakeLists.txt
### @author Mark Nelson <marknels@hawaii.edu>
###############################################################################

set (Boost_USE_STATIC_LIBS OFF)

# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

if (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message(STATUS "Generating unit tests using BOOST Unit Test Framework")

   add_executable ( All_Boost_Tests test_Trim.cpp ../src/Utility/Trim.cpp ../src/Utility/Trim.h ../src/Legacy/Cat.cpp ../src/Legacy/Cat.h ../src/Legacy/ArrayDB.cpp ../src/Legacy/ArrayDB.h test_Legacy_ArrayDB.cpp test_Legacy_Cat.cpp ../src/config.h ../src/Utility/Gender.cpp ../src/Utility/Gender.h test_Gender.cpp ../src/Animal/Animal.cpp ../src/Animal/Animal.h test_Animal.cpp ../src/Container/Node.h ../src/Container/SingleLinkedList.cpp ../src/Container/SingleLinkedList.h ../src/Mammal/Mammal.cpp ../src/Mammal/Mammal.h test_SingleLinkedList.cpp test_Mammal.cpp test_Name.cpp ../src/Mammal/Cat/Cat.cpp ../src/Mammal/Cat/Cat.h test_Cat.cpp)
   target_link_libraries (All_Boost_Tests ${Boost_LIBRARIES})

else (Boost_UNIT_TEST_FRAMEWORK_FOUND)
   message("BOOST Test needs to be installed to do unit testing")
endif (Boost_UNIT_TEST_FRAMEWORK_FOUND)
