#ifndef _GIT_GITHUB_GIT_H_
#define _GIT_GITHUB_GIT_H_
#include <memory>
#include <string>
namespace github {
class Git : public std::enable_shared_from_this<Git> {
 public:
  Git();
  ~Git() noexcept;
  static std::shared_ptr<Git> getInstance();
  static void throwError(std::string prefix);
  static void throwError();

 private:
  static std::weak_ptr<Git> instance;
};
};  // namespace github
#endif