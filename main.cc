#include <iostream>
#include <git2/errors.h>
#include <git2/annotated_commit.h>
#include <git2/repository.h>

int main(int argc,char** args)
{
	git_repository *repo;
	int errno;
	errno = git_repository_open(&repo, ".");
	if (errno != 0)
	{
		const git_error* e = giterr_last(); 
		std::cout << e->message << std::endl;
		return errno;
	}
	git_reference *ref;
	errno = git_repository_head(&ref, repo);
	if (errno != 0)
	{
		const git_error* e = giterr_last(); 
		std::cout << e->message << std::endl;
		return errno;
	}
	git_annotated_commit *commit;
	errno = git_annotated_commit_from_ref(&commit, repo, ref);
	if (errno != 0)
	{
		const git_error* e = giterr_last();
		std::cout << e->message << std::endl;
		return errno;
	}
	const git_oid *oid = git_annotated_commit_id(commit);
	std::cout << "Current head is " << oid->id << std::endl;
	return 0;
}
