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

cmake_minimum_required(VERSION 3.25)

project(ee205_animal_farm
      VERSION 1.0
      DESCRIPTION "All animals are equal, but some animals are more equal than others"
      LANGUAGES CXX)

message(STATUS "CMAKE_SOURCE_DIR = [${CMAKE_SOURCE_DIR}]")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set(CMAKE_CXX_CLANG_TIDY
      clang-tidy --extra-arg-before=-std=c++17;
      )

set(DOC_BUILD_DIR "${PROJECT_BINARY_DIR}/generated_docs")
set_directory_properties(PROPERTIES ADDITIONAL_CLEAN_FILES ${DOC_BUILD_DIR})
get_filename_component(PROJECT_PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)

find_package(Doxygen REQUIRED dot)

if (DOXYGEN_FOUND)
   message(STATUS "Generating documentation using Doxygen")

   # Project
   set(DOXYGEN_PROJECT_NUMBER ${CMAKE_PROJECT_VERSION})
   set(DOXYGEN_PROJECT_BRIEF ${PROJECT_DESCRIPTION})
   set(DOXYGEN_PROJECT_LOGO "images/animal_farm_logo.jpg")
   set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/generated_docs)
   set(DOXYGEN_STRIP_FROM_PATH ${PROJECT_PARENT_DIR})
   set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
   set(DOXYGEN_TAB_SIZE 3)
   set(DOXYGEN_ALIASES "pattern=@par Design Pattern: ")  # Create a custom @pattern tag
   set(DOXYGEN_OPTIMIZE_OUTPUT_FOR_C YES)
   set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

   # Build
   set(DOXYGEN_EXTRACT_PRIVATE YES)
   set(DOXYGEN_EXTRACT_PRIV_VIRTUAL YES)
   set(DOXYGEN_EXTRACT_PACKAGE YES)
   set(DOXYGEN_EXTRACT_STATIC YES)
   set(DOXYGEN_EXTRACT_LOCAL_METHODS YES)
   set(DOXYGEN_INTERNAL_DOCS YES)
   set(DOXYGEN_CASE_SENSE_NAMES YES)
   set(DOXYGEN_SORT_MEMBERS_CTORS_1ST YES)   # Put constructors first

   # Messages
   set(DOXYGEN_QUIET YES)
   set(DOXYGEN_WARN_AS_ERROR FAIL_ON_WARNINGS)

   # Input
   set(DOXYGEN_IMAGE_PATH images/)
   set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "README.md")

   # Source Browser
   set(DOXYGEN_SOURCE_BROWSER YES)
   set(DOXYGEN_STRIP_CODE_COMMENTS NO)
   set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
   set(DOXYGEN_CLANG_OPTIONS "-std=c++17 -I /usr/include/llvm -I /usr/lib/clang/14.0.6/include" )

   # Index

   # HTML
   set(DOXYGEN_GENERATE_HTML YES)
   set(DOXYGEN_HTML_EXTRA_STYLESHEET "html/extraStyleSheet.css")
   set(DOXYGEN_HTML_COLORSTYLE LIGHT)
   set(DOXYGEN_HTML_TIMESTAMP YES)
   set(DOXYGEN_GENERATE_TREEVIEW YES)

   # LaTeX

   # RTF

   # Man

   # XML

   # Docbook

   # Autogen

   # Pearlmod

   # Preprocessor
   set(DOXYGEN_MACRO_EXPANSION YES)
   set(DOXYGEN_EXPAND_ONLY_PREDEF YES)

   # External

   # Dot
   set(DOXYGEN_HAVE_DOT YES)
   set(DOXYGEN_DOT_NUM_THREADS 1)
   set(DOXYGEN_UML_LOOK YES)
   set(DOXYGEN_UML_LIMIT_NUM_FIELDS 100)
   set(DOXYGEN_DOT_UML_DETAILS YES)
   set(DOXYGEN_DOT_WRAP_THRESHOLD 80)
   set(DOXYGEN_TEMPLATE_RELATIONS YES)
   set(DOXYGEN_CALL_GRAPH YES)
   set(DOXYGEN_CALLER_GRAPH YES)
   set(DOXYGEN_DOT_IMAGE_FORMAT svg)
   set(DOXYGEN_INTERACTIVE_SVG YES)
   set(DOXYGEN_DOT_GRAPH_MAX_NODES 100)
   set(DOXYGEN_DOT_MULTI_TARGETS YES)

   message(STATUS "DOXYGEN_OUTPUT_DIRECTORY = [${DOXYGEN_OUTPUT_DIRECTORY}]")

   doxygen_add_docs(Doxygen
         ${CMAKE_SOURCE_DIR}/src
#        ${CMAKE_SOURCE_DIR}/README.md
         ${CMAKE_SOURCE_DIR}/WEEKLY_PROGRESS.md
         ${CMAKE_SOURCE_DIR}/STATISTICS.md
         ${CMAKE_SOURCE_DIR}/About.md
         ${CMAKE_SOURCE_DIR}/CONTRIBUTE.md
         ${CMAKE_SOURCE_DIR}/README.md
         ALL
         COMMENT "Generating doxygen documentation for ${PROJECT_NAME} to ${DOXYGEN_OUTPUT_DIRECTORY}"
         )

#   add_custom_command(TARGET Doxygen
#         PRE_BUILD
#         COMMAND rsync --recursive --mkpath --checksum --delete ${CMAKE_SOURCE_DIR}/images ${DOXYGEN_OUTPUT_DIRECTORY}/html
#         COMMENT "Updating images directory"
#         )

   add_custom_command(TARGET Doxygen
         PRE_BUILD
         WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
         COMMAND ./bin/stats.py
         COMMENT "Updating statistics"
         )

   #add_custom_command(TARGET Doxygen
   #       POST_BUILD
   #       COMMAND rsync --recursive --checksum --delete --compress --stats ${DOXYGEN_OUTPUT_DIRECTORY}/html/ marknels@uhunix.hawaii.edu:~/public_html/ee205/${CMAKE_PROJECT_NAME}
   #       COMMENT "Pushing files to UHUnix"
   #       )

else (DOXYGEN_FOUND)
   message("Doxygen needs to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

message(STATUS "PROJECT_BINARY_DIR = [${PROJECT_BINARY_DIR}]")

add_executable(ee205_animal_farm src/main.cpp src/Utility/Trim.cpp src/Utility/Trim.h src/config.h src/Container/Container.h)
add_executable(epicCats src/Legacy/epicCats.cpp src/Legacy/Cat.cpp src/Legacy/Cat.h src/Legacy/ArrayDB.cpp src/Legacy/ArrayDB.h src/config.h)

add_executable(catEmpire src/main_catEmpire.cpp
        src/Utility/Name.cpp               src/Utility/Name.h
        src/Utility/Trim.cpp               src/Utility/Trim.h
        src/Mammal/Cat/Cat.cpp             src/Mammal/Cat/Cat.h
        src/Mammal/Mammal.cpp              src/Mammal/Mammal.h
        src/Animal/Animal.cpp              src/Animal/Animal.h
        src/Container/Container.h          src/Container/Node.h
        src/Container/SingleLinkedList.cpp src/Container/SingleLinkedList.h
        src/Utility/Gender.cpp             src/Utility/Gender.h)

add_subdirectory(tests)
