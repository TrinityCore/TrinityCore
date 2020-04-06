#ifndef JOKER_CONFIG_H
#define JOKER_CONFIG_H


#include "Define.h"
#include <string>
#include <vector>

class TC_COMMON_API JokerConfig
{
    JokerConfig() = default;
    JokerConfig(JokerConfig const&) = delete;
    JokerConfig& operator=(JokerConfig const&) = delete;
    ~JokerConfig() = default;

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(std::string const& file, std::vector<std::string> args, std::string& error);

    static JokerConfig* instance();

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

    bool StartJokerSystem();

    uint32 Enable;

    float InstanceEncounterAPMod;
    float EliteAPMod;
    float UniqueEliteAPMod;
    float RareAPMod;
    float RareEliteAPMod;
    float InstanceEncounterSpellMod;
    float EliteSpellMod;
    float UniqueEliteSpellMod;
    float RareSpellMod;
    float RareEliteSpellMod;

};

#define sJokerConfig JokerConfig::instance()

#endif
