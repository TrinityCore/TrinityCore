#pragma once

// Starts with 1, because MySQL enum starts with 1
enum class SharedNameType
{
    PlayerName  = 1,
    Guild       = 2
};

class SharedNamesMgr
{
public:
    static SharedNamesMgr& instance() {
        static SharedNamesMgr instance;
        return instance;
    }

    void AddSharedName(SharedNameType type, std::string const& name, uint32 guid) const;
    void DeleteSharedName(SharedNameType type, uint32 guid) const;
    void UpdateSharedName(SharedNameType type, std::string const& newName, uint32 guid) const;

    QueryCallback GetSharedNameCheckQueryCallback(SharedNameType type, std::string const& name) const;

private:
    SharedNamesMgr(){}
    SharedNamesMgr(const SharedNamesMgr&) = delete;
    SharedNamesMgr& operator=(const SharedNamesMgr&) = delete;
    SharedNamesMgr(SharedNamesMgr&&) = delete;
    SharedNamesMgr& operator=(SharedNamesMgr&&) = delete;
};

#define sSharedNamesMgr SharedNamesMgr::instance()
