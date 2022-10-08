#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "auchindoun.h"

DoorData const doorData[] =
{
    { GO_DOOR_1,                    DATA_KAATHAR,   DOOR_TYPE_PASSAGE },
    { GameobjectHolyBarrier,        DATA_KAATHAR,   DOOR_TYPE_ROOM },
    
};

struct instance_auchindoun : public InstanceScript
{
    instance_auchindoun(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);

        /// Creatures
        m_NyamiGuid = ObjectGuid::Empty;
        m_Tuulani02Guid = ObjectGuid::Empty;
        m_UniqueGuardGuid = ObjectGuid::Empty;
        m_TuulaniGuid = ObjectGuid::Empty;
        m_WardenGuid = ObjectGuid::Empty;
        m_GromtashGuid = ObjectGuid::Empty;
        m_ElumGuid = ObjectGuid::Empty;
        m_IruunGuid = ObjectGuid::Empty;
        m_JoraGuid = ObjectGuid::Empty;
        m_AssainatingGuardGuid = ObjectGuid::Empty;
        m_AssainatedGuardGuid = ObjectGuid::Empty;
        /// Bosses
        m_KaatharGuid = ObjectGuid::Empty;
        m_NyamibossGuid = ObjectGuid::Empty;
        m_AzzakelGuid = ObjectGuid::Empty;
        m_TeronogorGuid = ObjectGuid::Empty;
        /// Objects
        m_HolyBarrierKathaarObjectGuid = ObjectGuid::Empty;
        m_CrystalKaatharGuid = ObjectGuid::Empty;
        m_WindowGuid = ObjectGuid::Empty;
        m_SoulTransportStartGuid = ObjectGuid::Empty;
        m_SoulTransport01Guid = ObjectGuid::Empty;
        m_SoulTransport02Guid = ObjectGuid::Empty;
        m_SoulTransport03Guid = ObjectGuid::Empty;
        m_AuchindounCrystal = ObjectGuid::Empty;
        /// Triggers
        m_TriggerBubbleMiddleNyamiGuid = ObjectGuid::Empty;
        m_KaatharDied = false;
        m_TuulaniSummoned = true;
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        if (creature)
        {
            switch (creature->GetEntry())
            {
            case eAuchindounCreatures::CreatureSoulBinderTuulani01:
                m_Tuulani02Guid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureIruun:
                m_IruunGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureJoraa:
                m_JoraGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureDurem:
                m_ElumGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureAuchenaiDefenderUnique:
                m_UniqueGuardGuid = creature->GetGUID();
                break;
            case NPC_KAATHAR:
                m_KaatharGuid = creature->GetGUID();
                break;
            case NPC_NYAMI:
                m_NyamibossGuid = creature->GetGUID();
                creature->SummonCreature(eAuchindounCreatures::CreatureWardenAzzakael, 1661.218f, 2917.974f, 49.063f, 1.604011f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                break;
            case NPC_AZAAKEL:
                m_AzzakelGuid = creature->GetGUID();
                break;
            case NPC_TERONOGOR:
                m_TeronogorGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureSoulBinderTuulani:
                m_TuulaniGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureSoulBinderNyami:
                m_NyamiGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureShieldSpot:
                m_TriggerBubbleMiddleNyamiGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureWardenAzzakael:
                m_WardenGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureDemonsSummoner:
                m_TriggerAzzakelFelPortalGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureGulkosh:
                m_GulkoshGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureGromtashTheDestructor:
                m_GromtashGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureDuragTheDominator:
                m_DuragGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureSargereiAssasinating:
                m_AssainatingGuardGuid = creature->GetGUID();
                break;
            case eAuchindounCreatures::CreatureAuchenaiAssainated:
                m_AssainatedGuardGuid = creature->GetGUID();
                break;
            default:
                break;
            }
        }
    }

    void OnGameObjectCreate(GameObject* go)override
    {
        InstanceScript::OnGameObjectCreate(go);
        if (go)
        {
            switch (go->GetEntry())
            {
            case eAuchindounObjects::GameObjectAuchindounCrystal:
                m_AuchindounCrystal = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectHolyBarrier://???? //????????
                m_HolyBarrierKathaarObjectGuid = go->GetGUID();
                // go->SetLootState(LootState::GO_READY);
                //  go->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false);
                break;
            case eAuchindounObjects::GameobjectAuchindounWindow:
                m_WindowGuid = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectFelBarrier:
                m_FelBarrierAzzakelObjectGuid = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectSoulTransportStart:
                m_SoulTransportStartGuid = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectSoulTransport1:
                if (instance)
                    if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                        m_SoulTransport01Guid = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectSoulTransport2:
                if (instance)
                    if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                        m_SoulTransport02Guid = go->GetGUID();
                break;
            case eAuchindounObjects::GameobjectSoulTransport3:
                if (instance)
                    if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                        m_SoulTransport03Guid = go->GetGUID();

                break;
            default:
                break;
            }
        }
    }

    void OnUnitDeath(Unit* p_Unit) override
    {
        if (!instance)
            return;

        Creature* p_Creature = p_Unit->ToCreature();
        if (!p_Creature)
            return;

        switch (p_Creature->GetEntry())
        {
        case NPC_KAATHAR:
        {
            if (GameObject* l_Holybarrier = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataHolyBarrier)))
            {
                l_Holybarrier->Delete();
                m_KaatharDied = true;
            }
            break;
        }
        case NPC_AZAAKEL:
        {
            if (GameObject* l_Felbarrier = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataFelBarrier)))
                l_Felbarrier->Delete();

            if (GameObject* l_SoulTransport = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataSoulTransportStart)))
            {
                if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                {
                    if (l_Teronogor->IsAIEnabled)
                        l_Teronogor->GetAI()->DoAction(eAuchindounActions::ActionSoulMove1);
                }
            }
            break;
        }
        /// Soul Transport
        case eAuchindounCreatures::CreatureGromtashTheDestructor:
            if (GameObject* l_SoulTransport = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataSoulTransport3)))
            {
                if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                {
                    if (l_Teronogor->IsAIEnabled)
                        l_Teronogor->GetAI()->DoAction(eAuchindounActions::ActionSoulMove4);
                }
            }
            break;
        case eAuchindounCreatures::CreatureGulkosh:
            if (GameObject* l_SoulTransport = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataSoulTransport2)))
            {
                if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                {
                    if (l_Teronogor->IsAIEnabled)
                        l_Teronogor->GetAI()->DoAction(eAuchindounActions::ActionSoulMove3);
                }
            }
            break;
        case eAuchindounCreatures::CreatureDuragTheDominator:
        {
            if (instance != nullptr)
            {
                if (GameObject* l_SoulTransport = instance->GetGameObject(GetGuidData(eAuchindounDatas::DataSoulTransport1)))
                {
                    if (Creature* l_Teronogor = instance->GetCreature(GetGuidData(eAuchindounDatas::DataBossTeronogor)))
                    {
                        if (l_Teronogor->IsAIEnabled)
                            l_Teronogor->GetAI()->DoAction(eAuchindounActions::ActionSoulMove2);
                    }
                }
            }
            break;
        }
        default:
            break;
        }
    }

    ObjectGuid GetGuidData(uint32 p_Data) const override
    {
        switch (p_Data)
        {
        case eAuchindounDatas::DataCrystal:
            return m_AuchindounCrystal;
            break;
        case eAuchindounDatas::DataTuulani02:
            return m_Tuulani02Guid;
            break;
        case eAuchindounDatas::DataGuard:
            return m_UniqueGuardGuid;
            break;
        case eAuchindounDatas::DataElum:
            return m_ElumGuid;
            break;
        case eAuchindounDatas::DataIruun:
            return m_IruunGuid;
            break;
        case eAuchindounDatas::DataJorra:
            return m_JoraGuid;
            break;
        case eAuchindounDatas::DataSoulTransportStart:
            return m_SoulTransportStartGuid;
            break;
        case eAuchindounDatas::DataSoulTransport1:
            return m_SoulTransport01Guid;
            break;
        case eAuchindounDatas::DataSoulTransport2:
            return m_SoulTransport02Guid;
            break;
        case eAuchindounDatas::DataSoulTransport3:
            return m_SoulTransport03Guid;
            break;
        case eAuchindounDatas::DataHolyBarrier:
            return m_HolyBarrierKathaarObjectGuid;
            break;
        case eAuchindounDatas::DataAuchindounWindow:
            return m_WindowGuid;
            break;
        case eAuchindounDatas::DataFelBarrier:
            return m_FelBarrierAzzakelObjectGuid;
            break;
        case eAuchindounDatas::DataFelPortal:
            return m_FelPortalGuid;
            break;
        case eAuchindounDatas::DataBossKathaar:
            return m_KaatharGuid;
            break;
        case eAuchindounDatas::DataBossAzzakael:
            return m_AzzakelGuid;
            break;
        case eAuchindounDatas::DataBossNyami:
            return m_NyamibossGuid;
            break;
        case eAuchindounDatas::DataBossTeronogor:
            return m_TeronogorGuid;
            break;
        case eAuchindounDatas::DataNyami:
            return m_NyamiGuid;
            break;
        case eAuchindounDatas::DataTuulani:
            return m_TuulaniGuid;
            break;
        case eAuchindounDatas::DataWarden:
            return m_WardenGuid;
            break;
        case eAuchindounDatas::DataGulkosh:
            return m_GulkoshGuid;
            break;
        case eAuchindounDatas::DataGromtash:
            return m_GromtashGuid;
            break;
        case eAuchindounDatas::DataDurag:
            return m_DuragGuid;
            break;
        case eAuchindounDatas::DataTriggerMiddleNyamiFightBubble:
            return m_TriggerBubbleMiddleNyamiGuid;
            break;
        case eAuchindounDatas::DataTriggerAzzakelController:
            return m_TriggerAzzakelFelPortalGuid;
            break;
        case eAuchindounDatas::DataAssinatingGuard:
            return m_AssainatingGuardGuid;
            break;
        case eAuchindounDatas::DataAssinatedGuard:
            return m_AssainatedGuardGuid;
            break;
        default:
            break;
        }

        return ObjectGuid::Empty;
    }

    bool SetBossState(uint32 type, EncounterState state) override
    {
        if (!InstanceScript::SetBossState(type, state))
            return false;
        else
            return true;
        
// wtf is this?? xD
/*        switch (type)
        {
        case DATA_KAATHAR:
        {
            if (state == DONE)
            {
            }
            break;
        }
        default:
            break;
        }
*/
    }

    /// Creatures
    ObjectGuid  m_NyamiGuid;
    ObjectGuid  m_Tuulani02Guid;
    ObjectGuid  m_UniqueGuardGuid;
    ObjectGuid  m_TuulaniGuid;
    ObjectGuid  m_WardenGuid;
    ObjectGuid  m_GromtashGuid;
    ObjectGuid  m_DuragGuid;
    ObjectGuid  m_GulkoshGuid;
    ObjectGuid  m_ElumGuid;
    ObjectGuid  m_IruunGuid;
    ObjectGuid  m_JoraGuid;
    ObjectGuid  m_AssainatingGuardGuid;
    ObjectGuid  m_AssainatedGuardGuid;
    /// Bosses
    ObjectGuid  m_KaatharGuid;
    ObjectGuid  m_NyamibossGuid;
    ObjectGuid  m_AzzakelGuid;
    ObjectGuid  m_TeronogorGuid;
    /// Objects
    ObjectGuid  m_HolyBarrierKathaarObjectGuid;
    ObjectGuid  m_CrystalKaatharGuid;
    ObjectGuid  m_WindowGuid;
    ObjectGuid  m_FelBarrierAzzakelObjectGuid;
    ObjectGuid  m_FelPortalGuid;
    ObjectGuid  m_SoulTransportStartGuid;
    ObjectGuid  m_SoulTransport01Guid;
    ObjectGuid  m_SoulTransport02Guid;
    ObjectGuid  m_SoulTransport03Guid;
    ObjectGuid  m_AuchindounCrystal;
    /// Triggers
    ObjectGuid  m_TriggerBubbleMiddleNyamiGuid;
    ObjectGuid  m_TriggerAzzakelFelPortalGuid;
    bool m_KaatharDied;
    bool m_TuulaniSummoned;
};

void AddSC_instance_auchindoun()
{
    RegisterInstanceScript(instance_auchindoun, 1182);
}
