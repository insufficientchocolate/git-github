#include "repository.hpp"

namespace github
{
    Repository::Repository(const char* path): repository_(nullptr, git_repository_free)
    {
        git_repository *repo;
        if(git_repository_init(&repo, path, false)) {
            const git_error *err = giterr_last();
            std::string message("failed to init repository: ");
            message.append(err->message);
            throw std::runtime_error(message);
        }
        repository_ = std::unique_ptr<git_repository, decltype(&git_repository_free)>(repo, git_repository_free);
    }
    
    std::string Repository::getHeadOID()
    {
        git_annotated_commit *commit;
        if(git_annotated_commit_from_ref(&commit, repository_.get(), getHead().get()))
        {
            throw std::runtime_error("failed to get annotated commit");
        }
        const git_oid *oid = git_annotated_commit_id(commit);
        git_annotated_commit_free(commit);
        
        return std::string(reinterpret_cast<const char*>(oid->id));
    }
    
    std::shared_ptr<git_reference> Repository::getHead()
    {
        git_reference *out;
        if(git_repository_head(&out, repository_.get())) {
            const git_error *err = giterr_last();
            std::string message("failed to read repository head: ");
            message.append(err->message);
            throw std::runtime_error(message);
        }
        return std::shared_ptr<git_reference>(out, git_reference_free);
    }
    
    void Repository::throwGitError(std::string prefix)
    {
        const git_error *err = giterr_last();
        if (!err)
        {
            return;
        }
        prefix.append(err->message);
        throw std::runtime_error(prefix);
    }
};
