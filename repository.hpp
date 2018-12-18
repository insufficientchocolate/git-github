#ifndef _GIT_GITHUB_REPOSITORY_H_
#define _GIT_GITHUB_REPOSITORY_H_
#include <git2/repository.h>
#include <git2/annotated_commit.h>
#include <git2/refs.h>
#include <git2/global.h>
#include <git2/errors.h>
#include <memory>
#include <array>
#include <string>
namespace github
{
    class Repository
    {
    public:
        Repository(const char* path);
        std::shared_ptr<git_reference> getHead();
        std::string getHeadOID();
        static void throwGitError(std::string prefixMessage = "");
    private:
       std::unique_ptr<git_repository, decltype(&git_repository_free)> repository_;
    };
};

#endif
