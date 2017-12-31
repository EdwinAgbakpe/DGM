file(GLOB TESTS_INCLUDE	${PROJECT_SOURCE_DIR}/include/gtest/gtest.h)
file(GLOB TESTS_SOURCES	"*.cpp")
file(GLOB TESTS_HEADERS	"*.h")

# Create named folders for the sources within the .vcproj
# Empty name lists them directly under the .vcproj
source_group("Include" FILES ${TESTS_INCLUDE})
source_group("" FILES ${TESTS_SOURCES} ${TESTS_HEADERS}) 
source_group("Source Files" FILES "main.cpp" "gtest-all.cpp")
source_group("Source Files\\Tests" FILES "Tests.h" "Tests.cpp")


# Properties -> C/C++ -> General -> Additional Include Directories
include_directories(${PROJECT_SOURCE_DIR}/include
					${PROJECT_SOURCE_DIR}/modules
					${OpenCV_INCLUDE_DIRS} 
				)
 
# Properties -> Linker -> General -> Additional Library Directories
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
 
add_executable(Tests ${TESTS_INCLUDE} ${TESTS_SOURCES} ${TESTS_HEADERS})
add_dependencies(Tests DGM)

# Properties->Linker->Input->Additional Dependencies
target_link_libraries(Tests ${OpenCV_LIBS} ${DGM_LIB})  

# Creates folder "Modules" and adds target project 
set_target_properties(Tests PROPERTIES PROJECT_LABEL "Tests")						# in Visual Studio
set_target_properties(Tests PROPERTIES OUTPUT_NAME "Tests")
set_target_properties(Tests PROPERTIES FOLDER "Tests")
 
#install
install(TARGETS Tests RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)