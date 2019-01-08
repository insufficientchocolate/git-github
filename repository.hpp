#ifndef _GIT_GITHUB_REPOSITORY_H_
#define _GIT_GITHUB_REPOSITORY_H_
#include <git2/annotated_commit.h>
#include <git2/errors.h>
#include <git2/global.h>
#include <git2/refs.h>
#include <git2/repository.h>
#include <array>
#include <memory>
#include <string>
#include "git_access.hpp"
namespace github {
class Repository : private GitAccess {
 public:
  Repository(const char* path);
  std::shared_ptr<git_reference> getHead();
  std::string getHeadSHA();

 private:
  std::unique_ptr<git_repository, decltype(&git_repository_free)> repository_;
};
};  // namespace github

#endif
