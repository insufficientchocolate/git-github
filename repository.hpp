#ifndef _GIT_GITHUB_REPOSITORY_H_
#define _GIT_GITHUB_REPOSITORY_H_
#include <git2/repository.h>
#include <memory>
namespace github
{
    class Repository
    {
    public:
        Repository(const char* path);
    private:
       std::unique_ptr<git_repository, decltype(&git_repository_free)> repository_;
    };
};

#endif
