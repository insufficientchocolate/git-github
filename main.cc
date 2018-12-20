#include <git2/global.h>
#include <unistd.h>
#include <iostream>
#include "repository.hpp"

int main(int argc, char** args) {
  git_libgit2_init();
  {
    github::Repository repo(".git");
    auto oid = repo.getHeadOID();

    std::cout << "Current head is " << oid << std::endl;
  }
  git_libgit2_shutdown();
  return 0;
}
