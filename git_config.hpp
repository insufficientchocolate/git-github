#ifndef _GIT_GITHUB_GIT_CONFIG_H_
#define _GIT_GITHUB_GIT_CONFIG_H_
#include <memory>

namespace github {
    class GitConfig {
        public:
            static std::shared_ptr<GitConfig> getConfig();
    };
};
#endif