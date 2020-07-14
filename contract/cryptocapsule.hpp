#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

class cryptocapsule : eosio::contract {
    private:

    struct [[eosio::table]] capsule_info {
        uint    key;
        std::string  content;
        uint64_t    created_at;
        uint64_t    closed_until;

        auto primary_key() const {return key.value;}
    };

    typedef eosio::multi_index<name("capsules"), capsule_info> capsules_table;

    capsules_table _capsules;

    public:

    cryptocapsule( name receiver, name code, datastream<const char*> ds ):contract(receiver, code, ds),
    _capsules(receiver, receiver.value) {}

    [[eosio::action]]
    void launch(uint key, char content, uint64_t created_at, uint64_t closed_until);


};