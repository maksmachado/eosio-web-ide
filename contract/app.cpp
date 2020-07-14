#include "cryptocapsule.hpp"

void cryptocapsule::launch(uint key, char content, uint64_t created_at, uint64_t closed_until) {
    auto capsule_iterator = _capsules.emplace(key, content, created_at, closed_until, [&](auto& new_capsule) {
        new_capsule.key = key;
        new_capsule.content = content;
        new_capsule.created_at = created_at;
        new_capsule.closed_until = closed_until;
    }); 

}