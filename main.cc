#include <git2/buffer.h>
#include <git2/global.h>
#include <unistd.h>
#include <CLI/CLI.hpp>
#include <iostream>
#include "repository.hpp"

int main(int argc, char **argv) {
  CLI::App app("git extension for github", "git-github");
  CLI::App *repositoryCommand = app.add_subcommand("repository");
  repositoryCommand->add_subcommand("status")->callback([] {
    // get username
  });

  CLI11_PARSE(app, argc, argv);

  return 0;
}
