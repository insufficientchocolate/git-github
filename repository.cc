#include "repository.hpp"

namespace github
{
    Repository::Repository(const char* path)
    {
        git_repository *repo;
        if(!git_repository_init(&repo, path, false)) {
            throw std::runtime_error("failed to init git repository");
        }
        repository_ = std::unique_ptr<git_repository, decltype(&git_repository_free)>(repo, git_repository_free);
    }
};
