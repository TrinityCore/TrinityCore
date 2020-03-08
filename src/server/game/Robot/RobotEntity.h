#ifndef ROBOT_AI_H
#define ROBOT_AI_H

class Script_Base;
class Strategy_Solo_Normal;
class Strategy_Group_Normal;

class RobotEntity
{
public:
    RobotEntity(uint32 pmTargetLevel, uint32 pmTargetClass, uint32 pmTargetRace);
    ~RobotEntity();
    void Update();    
    void SetStrategy(std::string pmStrategyName, bool pmEnable);
    
    uint32 FindSpellID(std::string pmSpellName);
    bool SpellValid(uint32 pmSpellID);
    bool CancelAura(std::string pmSpellName);
    void CancelAura(uint32 pmSpellID);
    void ClearShapeshift();
    void WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget);    
    void Logout();

public:
    uint8 characterTalentTab;
    // 0 dps, 1 tank, 2 healer
    uint32 characterType;
    std::string accountName;
    uint32 accountID;
    ObjectGuid characterGUID;
    ObjectGuid masterGUID;
    uint32 targetLevel;
    uint32 targetRace;
    uint32 targetClass;
    int32 allDelay;
    int32 checkDelay;
    int32 onlineDelay;
    int32 offlineDelay;
    uint32 robotState;

    uint32 realPrevTime;

    std::unordered_map<std::string, uint32> spellIDMap;
    std::unordered_map<std::string, uint8> spellLevelMap;
    std::unordered_map<uint64, bool> interestMap;


    Strategy_Solo_Normal* st_Solo_Normal;
    Strategy_Group_Normal* st_Group_Normal;

    Script_Base* s_base;

    bool staying;
    bool holding;
    bool cure;
};
#endif
