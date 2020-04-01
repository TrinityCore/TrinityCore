#ifndef MARKETER_CONFIG_H
#define MARKETER_CONFIG_H


#include "Define.h"
#include <string>
#include <vector>

class TC_COMMON_API MarketerConfig
{
    MarketerConfig() = default;
    MarketerConfig(MarketerConfig const&) = delete;
    MarketerConfig& operator=(MarketerConfig const&) = delete;
    ~MarketerConfig() = default;

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(std::string const& file, std::vector<std::string> args, std::string& error);

    static MarketerConfig* instance();

    bool Reload(std::string& error);

    std::string GetStringDefault(std::string const& name, const std::string& def) const;
    bool GetBoolDefault(std::string const& name, bool def) const;
    int GetIntDefault(std::string const& name, int def) const;
    float GetFloatDefault(std::string const& name, float def) const;

    std::string const& GetFilename();
    std::vector<std::string> const& GetArguments() const;
    std::vector<std::string> GetKeysByString(std::string const& name);

private:
    template<class T>
    T GetValueDefault(std::string const& name, T def) const;

public :

    bool StartMarketerSystem();

    uint32 Enable;
    uint32 Reset;
    uint32 MaxItemLevel;
    uint32 MaxRequireLevel;
};

#define sMarketerConfig MarketerConfig::instance()

#endif
