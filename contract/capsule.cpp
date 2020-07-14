#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

class capsule : eosio::contract {
    private:

    struct [[eosio::table]] capsule_info {
        uint64_t    key;
        std::string  content;
        uint64_t    created_at;
        uint64_t    closed_until;

        auto primary_key() const {return key;}
    };

    typedef eosio::multi_index<name("capsules"), capsule_info> capsules_table;

    capsules_table _capsules;

    public:

    capsule( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds),
    _capsules(receiver, receiver.value) {}

    [[eosio::action]]
    void launch(uint64_t key, std::string content, uint64_t created_at, uint64_t closed_until) {
        capsules_table table{get_self(), 0};

        table.emplace(get_self(), [&](auto& capsule){
        capsule.key = key;
        capsule.content = content;
        capsule.created_at = created_at;
        capsule.closed_until = closed_until;
   });

    }


};