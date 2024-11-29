# ===================================================================================
cmake_minimum_required(VERSION 3.9)

project ("logic")
# ===================================================================================
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.8.0\\msvc2022_64")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
# ===================================================================================

SET(DataManger_DIR "${PROJECT_SOURCE_DIR}/DataManger")
SET(QtManger_DIR "${PROJECT_SOURCE_DIR}/QtManger")
SET(SystemModules_DIR "${PROJECT_SOURCE_DIR}/SystemModules")

# set the project sources files as CXX_FILES
file(GLOB CXX_FILES CONFIGURE_DEPENDS
    ${DataManger_DIR}/source/*.cpp
    ${QtManger_DIR}/source/*.cpp
    ${SystemModules_DIR}/source/*.cpp
    )
# set the project header files as H_FILES
file(GLOB H_FILES CONFIGURE_DEPENDS
    ${DataManger_DIR}/header/*.h 
    ${QtManger_DIR}/header/*.h 
    ${SystemModules_DIR}/header/*.h
    )
	
# ===================================================================================
# list the header files
set(HEADER_FILES
)

# list the source files
set(SOURCE_FILES
	MianApp.cpp
)

# link with qt5
find_package(Qt6Core    CONFIG REQUIRED)
find_package(Qt6Widgets CONFIG REQUIRED)
find_package(Qt6Gui     CONFIG REQUIRED)

qt6_wrap_cpp(HEADER_MOC ${HEADER_FILES})

# add library target
add_executable(logic
	${HEADER_FILES}
	${SOURCE_FILES}
	${HEADER_MOC}
	${RCC_SOURCES}
	${H_FILES}
	${CXX_FILES}
)
target_include_directories(logic
	PUBLIC
        ${DataManger_DIR}/header
        ${QtManger_DIR}/header
        ${SystemModules_DIR}/header
	)
# ===================================================================================
set(QT_LIBS
	Qt6::Core
	Qt6::Gui
	Qt6::Widgets
)

target_link_libraries(logic
	PUBLIC
		${QT_LIBS}
)
# ===================================================================================
# Windows specfic flags to enable W variations of winapi
if(WIN32)
	target_compile_definitions(logic
		PRIVATE
			OS_WINDOWS=1
	)
	target_compile_options(logic
		PRIVATE
			/WX
	)
endif()

# enable C++17
# disable any compiler specifc extensions
target_compile_features(logic PUBLIC cxx_std_17)
set_target_properties(logic PROPERTIES
	CXX_EXTENSIONS OFF
)