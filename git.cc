#include "git.hpp"
#include <git2/errors.h>
#include <git2/global.h>

namespace github {
std::weak_ptr<Git> Git::instance = std::weak_ptr<Git>();
std::shared_ptr<Git> Git::getInstance() {
  std::shared_ptr<Git> git = Git::instance.lock();
  if (!git) {
    git = std::make_shared<Git>();
    Git::instance = git;
  }
  return git;
}
Git::Git() {
  if (git_libgit2_init() != 0) {
    throwError();
  }
}

Git::~Git() noexcept { git_libgit2_shutdown(); }
void Git::throwError(std::string prefix) {
  const git_error* err = giterr_last();
  if (!err) {
    return;
  }
  prefix.append(err->message);
  throw std::runtime_error(prefix);
}
void Git::throwError() {
  const git_error* err = giterr_last();
  if (!err) {
    return;
  }
  throw std::runtime_error(err->message);
}
};  // namespace github
