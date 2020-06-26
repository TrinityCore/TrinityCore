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

    float AttackMod_Max_Normal;
    float AttackMod_Min_Normal;
    float AttackMod_Level_Normal;

    float AttackMod_Max_Elite;
    float AttackMod_Min_Elite;
    float AttackMod_Level_Elite;

    float AttackMod_Max_UniqueElite;
    float AttackMod_Min_UniqueElite;
    float AttackMod_Level_UniqueElite;

    float AttackMod_Max_RaidElite;
    float AttackMod_Min_RaidElite;
    float AttackMod_Level_RaidElite;

    float AttackMod_Max_InstanceEncounter;
    float AttackMod_Min_InstanceEncounter;
    float AttackMod_Level_InstanceEncounter;

    float AttackMod_Max_Rare;
    float AttackMod_Min_Rare;
    float AttackMod_Level_Rare;

    float AttackMod_Max_RareElite;
    float AttackMod_Min_RareElite;
    float AttackMod_Level_RareElite;

    float AttackMod_Max_WorldBoss;
    float AttackMod_Min_WorldBoss;
    float AttackMod_Level_WorldBoss;


    float SpellMod_Max_Normal;
    float SpellMod_Min_Normal;
    float SpellMod_Level_Normal;

    float SpellMod_Max_Elite;
    float SpellMod_Min_Elite;
    float SpellMod_Level_Elite;

    float SpellMod_Max_UniqueElite;
    float SpellMod_Min_UniqueElite;
    float SpellMod_Level_UniqueElite;

    float SpellMod_Max_RaidElite;
    float SpellMod_Min_RaidElite;
    float SpellMod_Level_RaidElite;

    float SpellMod_Max_InstanceEncounter;
    float SpellMod_Min_InstanceEncounter;
    float SpellMod_Level_InstanceEncounter;

    float SpellMod_Max_Rare;
    float SpellMod_Min_Rare;
    float SpellMod_Level_Rare;

    float SpellMod_Max_RareElite;
    float SpellMod_Min_RareElite;
    float SpellMod_Level_RareElite;

    float SpellMod_Max_WorldBoss;
    float SpellMod_Min_WorldBoss;
    float SpellMod_Level_WorldBoss;


    float HPMod_Max_Normal;
    float HPMod_Min_Normal;
    float HPMod_Level_Normal;

    float HPMod_Max_Elite;
    float HPMod_Min_Elite;
    float HPMod_Level_Elite;

    float HPMod_Max_UniqueElite;
    float HPMod_Min_UniqueElite;
    float HPMod_Level_UniqueElite;

    float HPMod_Max_RaidElite;
    float HPMod_Min_RaidElite;
    float HPMod_Level_RaidElite;

    float HPMod_Max_InstanceEncounter;
    float HPMod_Min_InstanceEncounter;
    float HPMod_Level_InstanceEncounter;

    float HPMod_Max_Rare;
    float HPMod_Min_Rare;
    float HPMod_Level_Rare;

    float HPMod_Max_RareElite;
    float HPMod_Min_RareElite;
    float HPMod_Level_RareElite;

    float HPMod_Max_WorldBoss;
    float HPMod_Min_WorldBoss;
    float HPMod_Level_WorldBoss;


    float MPMod_Max_Normal;
    float MPMod_Min_Normal;
    float MPMod_Level_Normal;

    float MPMod_Max_Elite;
    float MPMod_Min_Elite;
    float MPMod_Level_Elite;

    float MPMod_Max_UniqueElite;
    float MPMod_Min_UniqueElite;
    float MPMod_Level_UniqueElite;

    float MPMod_Max_RaidElite;
    float MPMod_Min_RaidElite;
    float MPMod_Level_RaidElite;

    float MPMod_Max_InstanceEncounter;
    float MPMod_Min_InstanceEncounter;
    float MPMod_Level_InstanceEncounter;

    float MPMod_Max_Rare;
    float MPMod_Min_Rare;
    float MPMod_Level_Rare;

    float MPMod_Max_RareElite;
    float MPMod_Min_RareElite;
    float MPMod_Level_RareElite;

    float MPMod_Max_WorldBoss;
    float MPMod_Min_WorldBoss;
    float MPMod_Level_WorldBoss;

    std::string CreatureModException;
    uint32 MaxModLevel;
    uint32 MaxTrainerSpellLevel;

    uint32 PlayerMod;

    uint32 LootCountEachGroup_Normal;
    uint32 LootCountEachGroup_InstanceEncounter;
    uint32 LootCountEachGroup_UniqueElite;
    uint32 LootCountEachGroup_Elite;
    uint32 LootCountEachGroup_RareElite;
    uint32 LootCountEachGroup_WorldBoss;
    uint32 LootCountEachGroup_Rare;

    std::unordered_set<uint32> CreatureModExceptionSet;

    uint32 ServerExpansion;

    std::vector<std::string> SplitString(std::string srcStr, std::string delimStr, bool repeatedCharIgnored);
    std::string TrimString(std::string srcStr);
};

#define sJokerConfig JokerConfig::instance()

#endif
