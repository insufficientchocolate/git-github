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

add_executable(
	"${CMAKE_PROJECT_NAME}"
	main.cc
    repository.cc
    repository.hpp
)

include(GNUInstallDirs)
#set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
#set(config_install_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${CMAKE_PROJECT_NAME}")
#set(project_config "${generated_dir}/${CMAKE_PROJECT_NAME}Config.cmake")

install(TARGETS "${CMAKE_PROJECT_NAME}"
	RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)


target_link_libraries(git-github CLI11::CLI11 libgit2::git2)
