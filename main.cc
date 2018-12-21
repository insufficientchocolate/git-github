#include <git2/buffer.h>
#include <git2/global.h>
#include <unistd.h>
#include <CLI/CLI.hpp>
#include <iostream>
#include "repository.hpp"

const std::string findRepository() {
  git_buf out = {0};
  git_repository *repo;

  char *wd = getwd(NULL);

  if (git_repository_discover(&out, wd, true, nullptr)) {
    github::Repository::throwGitError();
  }
  free(wd);
  const std::string path(out.ptr);
  return path;
}

int main(int argc, char **argv) {
  if (git_libgit2_init()) {
    github::Repository::throwGitError();
  }
  const std::string repositoryPath = findRepository();
  CLI::App app("git extension for github", "git-github");
  app.add_subcommand("download")->callback([repositoryPath] {
    github::Repository repo(repositoryPath.c_str());
    std::string head = repo.getHeadSHA();
    std::cout << "Current head is " << head << std::endl;
    std::cout << "Donwloading " << head << std::endl;
  });

  CLI11_PARSE(app, argc, argv);

  return 0;
}
