cmake_minimum_required(VERSION 3.2)

include(cmake/HunterGate.cmake)

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
find_package(LIBGIT2 CONFIG REQUIRED)


add_executable(
	git-github
	main.cc
)

target_link_libraries(git-github CLI11::CLI11 LIBGIT2::libgit2)
