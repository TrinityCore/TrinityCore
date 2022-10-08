#include "grimrail_depot.h"
#include "GameObject.h"
/*
static BossScenarios const g_BossScenarios[] =
{
    { GrimrailDepotData::DataRocketsparkEncounter,   eGrimrailDepotScenarios::ScenarioBossRocketsparkAndBorka },
    { GrimrailDepotData::DataNitroggThundertower,    eGrimrailDepotScenarios::ScenarioBossNitroggThundertower },
    { GrimrailDepotData::DataSkyLordTovra,           eGrimrailDepotScenarios:: },
    { 0, 0 }
};
*/

struct instance_grimrail_depot : public InstanceScript
{
    instance_grimrail_depot(InstanceMap* map) : InstanceScript(map) {}

    InstanceScript* m_Instance = this;

    ObjectGuid m_RocketsparkGUID;
    ObjectGuid m_BorkaGUID;
    ObjectGuid m_SkylordTovraGUID;
    ObjectGuid m_SkylordTovraDragonGUID;
    ObjectGuid m_RocketsparkAndBurkaEntrance;
    ObjectGuid m_RocketsparkAndBurkaExit;
    ObjectGuid m_NitrogThunderPowerGUID;
    ObjectGuid m_NitroggTurretGUID;
    ObjectGuid m_NitroggAssaultFlapsGUID;
    ObjectGuid m_NitroggInvisibleDoorGUID;
    ObjectGuid m_SkylordTovraDoorGUID;

    void Initialize() override
    {
        SetBossNumber(3);
        //LoadScenariosInfos(g_BossScenarios, instance->IsChallengeMode() ? eGrimrailDepotScenarios::IronDocksChallengeID : eIronDocksScenario::IronDocksScenarioID);

        m_RocketsparkGUID = ObjectGuid::Empty;
        m_BorkaGUID = ObjectGuid::Empty;
        m_NitrogThunderPowerGUID = ObjectGuid::Empty;
        m_SkylordTovraGUID = ObjectGuid::Empty;
        m_NitroggTurretGUID = ObjectGuid::Empty;
        m_NitroggAssaultFlapsGUID = ObjectGuid::Empty;
        m_NitroggInvisibleDoorGUID = ObjectGuid::Empty;
        m_SkylordTovraDoorGUID = ObjectGuid::Empty;
        m_RocketsparkAndBurkaEntrance = ObjectGuid::Empty;
        m_RocketsparkAndBurkaExit = ObjectGuid::Empty;
    }

    void OnCreatureCreate(Creature* l_Creature) override
    {
        if (l_Creature)
        {
            switch (l_Creature->GetEntry())
            {
            case GrimrailDepotBosses::BossRocketSpark:
                m_RocketsparkGUID = l_Creature->GetGUID();
                break;
            case GrimrailDepotBosses::BossBorkatheBrute:
                m_BorkaGUID = l_Creature->GetGUID();
                break;
            case GrimrailDepotBosses::BossNitroggThundertower:
                m_NitrogThunderPowerGUID = l_Creature->GetGUID();
                break;
            case GrimrailDepotBosses::BossSkylordTovra:
                m_SkylordTovraGUID = l_Creature->GetGUID();
                break;
            case GrimrailDepotCreatures::CreatureIronTurretNitrogg:
                m_NitroggTurretGUID = l_Creature->GetGUID();
                break;
            case GrimrailDepotCreatures::CreatureSkylordTovraDragon:
                m_SkylordTovraDragonGUID = l_Creature->GetGUID();
                break;
            default:
                break;
            }
        }
    }

    void OnUnitDeath(Unit* p_Unit) override
    {
        Creature* l_Creature = p_Unit->ToCreature();
        if (!l_Creature)
            return;

        switch (l_Creature->GetEntry())
        {
        case GrimrailDepotBosses::BossSkylordTovra:
        {
            if (l_Creature->GetMap()->IsHeroic())
                DoCompleteAchievement(GrimrailDepotAchivement::AchievementGrimrailDepotHeroic);
            else
                DoCompleteAchievement(GrimrailDepotAchivement::AchievementGrimrailDepotNormal);
            break;
        }
        default:
            break;
        }
    }

    void OnGameObjectCreate(GameObject* p_Go) override
    {
        switch (p_Go->GetEntry())
        {
        case GrimrailDepotGobjects::GameObjectIronWroughtGate:
            m_RocketsparkAndBurkaExit = p_Go->GetGUID();
            break;
        case GrimrailDepotGobjects::GameObjectSpikedGate:
            m_RocketsparkAndBurkaEntrance = p_Go->GetGUID();
            break;
        case GrimrailDepotGobjects::GameObjectAssaultFlaps:
            m_NitroggAssaultFlapsGUID = p_Go->GetGUID();
            break;
        case GrimrailDepotGobjects::GameObjectInvisibleDoor:
            m_NitroggInvisibleDoorGUID = p_Go->GetGUID();
            break;
        case GrimrailDepotGobjects::GameObjectSpikedGateSkylordTovra:
            m_SkylordTovraDoorGUID = p_Go->GetGUID();
            break;
        default:
            break;
        }
    }

    ObjectGuid GetGuidData(uint32 DataId) const
    {
        switch (DataId)
        {
        case GrimrailDepotData::DataRocketspark:
            return m_RocketsparkGUID;
            break;
        case GrimrailDepotData::DataBorka:
            return m_BorkaGUID;
            break;
        case GrimrailDepotData::DataNitroggThundertower:
            return m_NitrogThunderPowerGUID;
            break;
        case GrimrailDepotData::DataSkyLordTovra:
            return m_SkylordTovraGUID;
            break;
        case GrimrailDepotData::DataNitroggTurret:
            return m_NitroggTurretGUID;
            break;
        case GrimrailDepotData::DataAssaultFlaps:
            return m_NitroggAssaultFlapsGUID;
            break;
        case GrimrailDepotData::DataInvisibleDoor:
            return m_NitroggInvisibleDoorGUID;
            break;
        case GrimrailDepotData::DataSkyLordTovraDragon:
            return m_SkylordTovraDragonGUID;
            break;
        case GrimrailDepotData::DataSpikedGateSkylordTovraDoor:
            return m_SkylordTovraDoorGUID;
            break;
        case GrimrailDepotData::DataSpikedGateBoss1:
            return m_RocketsparkAndBurkaEntrance;
            break;
        case GrimrailDepotData::DataIronWroughtGate:
            return m_RocketsparkAndBurkaExit;
            break;
        default:
            break;
        }
        return ObjectGuid::Empty;
    }
};

void AddSC_instance_grimrail_depot()
{
    RegisterInstanceScript(instance_grimrail_depot, 1208);
}
