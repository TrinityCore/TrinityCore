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

public:

    bool StartJokerSystem();

    uint32 Enable;
    float ThreatMod;

    float NormalAttackMod_Total;
    float InstanceEncounterAttackMod_Total;
    float UniqueEliteAttackMod_Total;
    float EliteAttackMod_Total;
    float RareEliteAttackMod_Total;
    float WorldBossAttackMod_Total;
    float RareAttackMod_Total;

    float NormalSpellMod_Total;
    float InstanceEncounterSpellMod_Total;
    float UniqueEliteSpellMod_Total;
    float EliteSpellMod_Total;
    float RareEliteSpellMod_Total;
    float WorldBossSpellMod_Total;
    float RareSpellMod_Total;

    float NormalHPMod_Total;
    float InstanceEncounterHPMod_Total;
    float UniqueEliteHPMod_Total;
    float EliteHPMod_Total;
    float RareEliteHPMod_Total;
    float WorldBossHPMod_Total;
    float RareHPMod_Total;

    float NormalMPMod_Total;
    float InstanceEncounterMPMod_Total;
    float UniqueEliteMPMod_Total;
    float EliteMPMod_Total;
    float RareEliteMPMod_Total;
    float WorldBossMPMod_Total;
    float RareMPMod_Total;

    float PlayerHPMod_Total;
    float PlayerMPMod_Total;

    float NormalAttackMod_Level;
    float InstanceEncounterAttackMod_Level;
    float UniqueEliteAttackMod_Level;
    float EliteAttackMod_Level;
    float RareEliteAttackMod_Level;
    float WorldBossAttackMod_Level;
    float RareAttackMod_Level;

    float NormalSpellMod_Level;
    float InstanceEncounterSpellMod_Level;
    float UniqueEliteSpellMod_Level;
    float EliteSpellMod_Level;
    float RareEliteSpellMod_Level;
    float WorldBossSpellMod_Level;
    float RareSpellMod_Level;

    float NormalHPMod_Level;
    float InstanceEncounterHPMod_Level;
    float UniqueEliteHPMod_Level;
    float EliteHPMod_Level;
    float RareEliteHPMod_Level;
    float WorldBossHPMod_Level;
    float RareHPMod_Level;


    float NormalMPMod_Level;
    float InstanceEncounterMPMod_Level;
    float UniqueEliteMPMod_Level;
    float EliteMPMod_Level;
    float RareEliteMPMod_Level;
    float WorldBossMPMod_Level;
    float RareMPMod_Level;

    float PlayerHPMod_Level;
    float PlayerMPMod_Level;

    uint32 MaxModLevel;

    uint32 MaxTrainerSpellLevel;

    uint32 LootCountEachGroup_Normal;
    uint32 LootCountEachGroup_InstanceEncounter;    
    uint32 LootCountEachGroup_UniqueElite;
    uint32 LootCountEachGroup_Elite;
    uint32 LootCountEachGroup_RareElite;
    uint32 LootCountEachGroup_WorldBoss;
    uint32 LootCountEachGroup_Rare;
};

#define sJokerConfig JokerConfig::instance()

#endif
