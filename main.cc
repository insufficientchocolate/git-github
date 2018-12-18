#include <iostream>
#include <unistd.h>
#include <git2/global.h>
#include "repository.hpp"

int main(int argc,char** args)
{
    git_libgit2_init();
    git_buf repositoryPath;
    const char *cwd = getcwd(nullptr, 0);
    if(git_repository_discover(&repositoryPath, cwd,false,""))
    {
        github::Repository::throwGitError();
    };
    std::cout << "discovered git repo: " << repositoryPath.ptr << std::endl;
    github::Repository repo(repositoryPath.ptr);
    auto oid = repo.getHeadOID();
    
	std::cout << "Current head is " << oid << std::endl;
    git_libgit2_shutdown();
	return 0;
}
