cmake_minimum_required(VERSION 3.2)

include(cmake/HunterGate.cmake)
set(CMAKE_CXX_STANDARD 11)

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.58.tar.gz"
    SHA1 "ee80dc91f91f5eb6892f80a0a92c83b4de8e980a"
    LOCAL
)

project(git-github)

hunter_add_package(CLI11)
hunter_add_package(CURL)
hunter_add_package(libgit2)

find_package(CURL CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(libgit2 CONFIG REQUIRED)

set(
    sources
    main.cc
    repository.cc
    repository.hpp
)

foreach(i IN LISTS sources)
    list(APPEND sources_abs "${CMAKE_CURRENT_SOURCE_DIR}/${i}")
endforeach()

add_executable(
	"${CMAKE_PROJECT_NAME}"
    ${sources}
)

include(GNUInstallDirs)

install(TARGETS "${CMAKE_PROJECT_NAME}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

target_link_libraries(git-github CLI11::CLI11 libgit2::git2)

find_program(
    CLANG_FORMAT_COMMAND
    NAMES "clang-format"
    DOC "Path to clang-format"
)

if(CLANG_FORMAT_COMMAND)
    set(DO_CLANG_FORMAT "${CLANG_FORMAT_COMMAND}" "-i -style=google")
    add_custom_target(
        format
        "${CLANG_FORMAT_COMMAND}" -i -style=google ${sources_abs}
    )
endif()
