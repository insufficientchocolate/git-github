#ifndef _GIT_GITHUB_GIT_ACCESS_H_
#define _GIT_GITHUB_GIT_ACCESS_H_
#include "git.hpp"
namespace github {
class GitAccess {
 public:
  GitAccess() : git_(Git::getInstance()) {}

 protected:
  std::shared_ptr<Git> git_;
};
};  // namespace github
#endif