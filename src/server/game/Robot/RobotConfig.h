#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H


#include "Define.h"
#include <string>
#include <vector>

class TC_COMMON_API RobotConfig
{
    RobotConfig() = default;
    RobotConfig(RobotConfig const&) = delete;
    RobotConfig& operator=(RobotConfig const&) = delete;
    ~RobotConfig() = default;

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(std::string const& file, std::vector<std::string> args, std::string& error);

    static RobotConfig* instance();

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

    bool StartRobotSystem();
    uint32 Enable;
    uint32 ResetRobots;
    uint32 ResetEquipments;
    uint32 OnlineLevel;
    uint32 CountEachLevel;    
    uint32 OnlineMinDelay;
    uint32 OnlineMaxDelay;
    std::string AccountNamePrefix;
    uint32 GroupInterest;
    float TeleportMinRange;
    float TeleportMaxRange;
    uint32 DeathMinDelay;
    uint32 DeathMaxDelay;
    uint32 SoloMinDelay;
    uint32 SoloMaxDelay;
    float AssembleTeleportMinRange;
    uint32 DPSDelay;
    uint32 AOEDelay;

    uint32 RaidRobotCount_60;
    uint32 RaidRobotCount_70;
    uint32 RaidRobotCount_80;
};

#define sRobotConfig RobotConfig::instance()	

#endif
