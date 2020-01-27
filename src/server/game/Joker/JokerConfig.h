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

    uint32 enable;

    float InstanceEncounterDamageMod_Warrior;
    float InstanceEncounterDamageMod_Paladin;
    float InstanceEncounterDamageMod_Mage;
    float EliteDamageMod_Warrior;
    float EliteDamageMod_Paladin;
    float EliteDamageMod_Mage;
    float RareDamageMod_Warrior;
    float RareDamageMod_Paladin;
    float RareDamageMod_Mage;
    float RareEliteDamageMod_Warrior;
    float RareEliteDamageMod_Paladin;
    float RareEliteDamageMod_Mage;

    float InstanceEncounterAPMod_Warrior;
    float InstanceEncounterAPMod_Paladin;
    float InstanceEncounterAPMod_Mage;
    float EliteAPMod_Warrior;
    float EliteAPMod_Paladin;
    float EliteAPMod_Mage;
    float RareAPMod_Warrior;
    float RareAPMod_Paladin;
    float RareAPMod_Mage;
    float RareEliteAPMod_Warrior;
    float RareEliteAPMod_Paladin;
    float RareEliteAPMod_Mage;

};

#define sJokerConfig JokerConfig::instance()

#endif
