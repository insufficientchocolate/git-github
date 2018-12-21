#include <git2/global.h>
#include <unistd.h>
#include <iostream>
#include "repository.hpp"

int main(int argc, char** args) {
  github::Repository repo(".git");
  std::cout << "Current head is " << repo.getHeadSHA() << std::endl;
  return 0;
}
