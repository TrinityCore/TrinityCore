#include "grimrail_depot.h"
#include "Vehicle.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum eNitroggThundertowerTalks
{
    TalkAggro = 1,          ///< Ready!!! [46109]
    TalkDeath,              ///< i didn't ... even ... try .. [46110]
    TalkCommanderEvent01,   ///< Let'em have it boys! [46111]
    TalkCommanderEvent02,   ///< Give'em all you got! [46112]
    TalkCommanderEvent03,   ///< I've got my sights on you! [46113]
    TalkCommanderEvent04,   ///< RAPID FIRE!!! [46114]
    TalkCommanderEvent05,   ///< Hah! Let's take this down to your level. [46115]
    TalkIntro01,            ///< Who dares challenge me? [46116]
    TalkIntro02,            ///< They are here... get up! [46117]
    TalkIntro03,            ///< Formation! NOW!! [46118]
    TalkIntro04,            ///< Come on swines! move.. like you've signed up for this. [46118]
    TalkKill01,             ///< Ha ha ha Another contender down! [46120]
    TalkKill02              ///< So weak! [46121]
};

enum eNitroggThundertowerActions
{
    ActionActivateSlagBlast = 1
};

enum eNitroggThundertowerMovments
{
    MovementPointThreeRemoveFlags = 1,
    MovementAboardOnTurret,
};

enum eNitroggThundertowerPhases
{
    PhaseOOC01,
    PhaseOOC02
};

enum eNitroggThundertowerSpellVisuals
{
    SpellFireSuppressionVisualId = 41206
};

#define OOCOrientation 4.753863f

Position const g_PositionNitroggtowerWaypoints[3] =
{
    { 1646.740f, 1719.148f, 106.951f },
    { 1646.630f, 1737.518f, 106.951f },
    { 1646.513f, 1776.855f, 107.634f }
};

Position const g_PositionBlackrockTurretPosition[6]
{
    /// Starts from left and ends at the right one
    {1628.628f, 1779.534f, 107.981f}, /// First
    { 1628.576f, 1814.675f, 107.983f }, /// Second
    { 1628.486f, 1837.735f, 107.989f }, /// Third
    { 1664.699f, 1826.430f, 108.154f }, /// Fourth
    // {1665.088f, 1838.148f, 108.154f},
    { 1664.667f, 1814.876f, 108.291f }, /// Fifth
    { 1664.475f, 1792.299f, 108.261f }, /// Sixth
    // {1664.599f, 1779.760f, 108.220f}
};

Position const g_PositionSlagBlast[3] =
{
    { 1646.737f, 1818.399f, 107.412f },
    { 1646.204f, 1796.842f, 107.471f },
    { 1646.544f, 1840.300f, 107.635f }
};

Position const g_PositionReinforce1 = { 1628.354f, 1851.177f, 114.154f, 4.650741f }; /// Right to the turret
Position const g_PositionReinforce2 = { 1653.266f, 1794.999f, 107.767f, 2.742215f }; /// Near door
Position const g_PositionReinforce3 = { 1659.568f, 1813.276f, 108.144f, 3.194596f }; /// Left to the turret

#define g_NitroggDisplay 55162
#define g_TrainFloorPositionZ 107.479

/// Nitrogg Thunder Tower - 79545
class boss_nitrogg_thundertower : public CreatureScript
{
    public:

    boss_nitrogg_thundertower() : CreatureScript("boss_nitrogg_thundertower") { }

    struct boss_nitrogg_thundertowerAI : public BossAI
    {
        boss_nitrogg_thundertowerAI(Creature* p_Creature) : BossAI(p_Creature, GrimrailDepotData::DataNitroggThundertower)
        {
            m_Instance = me->GetInstanceScript();
            m_First = false;
            m_Phase = 0;
        }

        enum eNitroggThundertowerSpells
        {
            SpellBlackrockGrenadeTriggerMissileA = 163539,
            SpellBlackrockGrenadeTriggerMissileB = 161150,
            SpellBlackrockGrenadeDamage = 161153,
            SpellBlackrockMortarDummy = 163550,
            SpellBlackRockMortarPeriodic = 163550,
            SpellBlackRockTriggerMissile = 163541,
            SpellBlackrockMortarDamage = 163741,
            SpellBlackrockMunitionsDummy = 167709,
            SpellFlametongueDummy = 176031,
            SpellFlametongueTriggerMissile = 176032,
            SpellFlametongueAura = 176033,
            SpellFlametongue = 176039,
            SpellLavaWreath = 176027,
            SpellLavaWreathDummy = 176025,
            SpellShrapnelBlast = 160943,
            SpellBlackrockMortarShellsAura = 160702,
            SpellBlackrockMortarShellsDummy = 160965,
            SpellBlackrockGrenadeAura = 160703,
            SpellBlackrockGrenadeDummy = 160997
        };

        enum eNitroggThundertowerEvents
        {
            EventBlackrockGrenade = 1,
            EventBlackrockMortar,
            EventReinforceBoomers,
            EventReinforceInfantry,
            EventReinforceGunner,
            EventBlackrockMortarBombs,
            EventOpenAssaultFlaps
        };

        InstanceScript* m_Instance;
        uint32 m_Phase;
        uint32 m_PhaseDiff;
        uint32 m_PushbackDiff;
        uint64 m_TargetGUID;
        bool m_First;

        void Reset() override
        {
            events.Reset();
            m_TargetGUID = 0;
            me->SetDisplayId(g_NitroggDisplay);
            m_PhaseDiff = 2 * TimeConstants::IN_MILLISECONDS;
            m_PushbackDiff = 2 * TimeConstants::IN_MILLISECONDS;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));

            if (!m_First)
            {
                m_First = true;
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            }
            else if (m_Phase > 2)
                m_Phase = 3;
        }

        void EnterCombat(Unit* p_Who) override
        {
            if (m_Instance != nullptr)
            {
                m_Instance->DoSendScenarioEvent(41095);
                m_Instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
            }             

            _EnterCombat();
            Talk(eNitroggThundertowerTalks::TalkAggro);
            events.ScheduleEvent(eNitroggThundertowerEvents::EventOpenAssaultFlaps, 50 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNitroggThundertowerEvents::EventBlackrockGrenade, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eNitroggThundertowerEvents::EventBlackrockMortar, 15 * TimeConstants::IN_MILLISECONDS);
        }

        void KilledUnit(Unit* p_Who) override
        {
            if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            {
                if (roll_chance_i(50))
                    Talk(eNitroggThundertowerTalks::TalkKill01);
                else
                    Talk(eNitroggThundertowerTalks::TalkKill02);
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            uint32 l_Entries[4] = { GrimrailDepotCreatures::CreatureGromkarBoomer, GrimrailDepotCreatures::CreatureGromkarGunner, GrimrailDepotCreatures::CreatureGromkarGrenadier, GrimrailDepotCreatures::CreatureIronInfantry };

            for (uint32 l_I = 0; l_I < 4; l_I++)
            {
                DespawnCreaturesInArea(l_Entries[l_I], me);
            }

            if (m_Instance != nullptr)
            {
                if (GameObject* l_AssaultFlaps = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataAssaultFlaps)))
                {
                    if (l_AssaultFlaps->isActiveObject())
                    {
                        // Activate
                        l_AssaultFlaps->SetLootState(LootState::GO_READY);
                        l_AssaultFlaps->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                    }
                }

                if (GameObject* l_InvisibleDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataInvisibleDoor)))
                {
                    if (l_InvisibleDoor->isActiveObject())
                        l_InvisibleDoor->Respawn();
                }
                  
            }

            /// Begin moving turrets
            std::list<Creature*> l_TurretsList;
            me->GetCreatureListWithEntryInGrid(l_TurretsList, GrimrailDepotCreatures::CreatureIronTurret, 200.0f);
            if (!l_TurretsList.empty())
            {
                for (Creature* l_Itr : l_TurretsList)
                {
                    if (!l_Itr)
                        continue;

                    l_Itr->Respawn(true);
                    l_Itr->NearTeleportTo(l_Itr->GetHomePosition().m_positionX, l_Itr->GetHomePosition().m_positionY, l_Itr->GetHomePosition().m_positionZ, l_Itr->GetHomePosition().GetOrientation());
                }
            }
        }

        void OpenAssaultFlaps()
        {
            if (m_Instance != nullptr)
            {
                if (GameObject* l_AssaultFlaps = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataAssaultFlaps)))
                {
                    // Activate
                    l_AssaultFlaps->SetLootState(LootState::GO_READY);
                    l_AssaultFlaps->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
                }

                if (GameObject* l_InvisibleDoor = m_Instance->instance->GetGameObject(m_Instance->GetGuidData(GrimrailDepotData::DataInvisibleDoor)))
                    l_InvisibleDoor->Delete();

                /// Begin moving turrets
                std::list<Creature*> l_TurretsList;
                me->GetCreatureListWithEntryInGrid(l_TurretsList, GrimrailDepotCreatures::CreatureIronTurret, 200.0f);
                if (!l_TurretsList.empty())
                {
                    uint32 m_WaypointCount = 0;

                    for (Creature* l_Itr : l_TurretsList)
                    {
                        if (!l_Itr)
                            continue;

                        if (Unit* l_Target = l_Itr->FindNearestCreature(GrimrailDepotCreatures::CreatureTurretMovement, 10.0f, true))
                            l_Itr->GetMotionMaster()->MovePoint(0, l_Target->GetPositionX(), l_Target->GetPositionY(), l_Target->GetPositionZ());
                    }
                }
            }
        }

        void MovementInform(uint32 /*p_Type*/, uint32 p_Id) override
        {
            switch (p_Id)
            {
            case 0:
                me->SetFacingTo(OOCOrientation);
                break;
            case eNitroggThundertowerMovments::MovementPointThreeRemoveFlags:
                me->SetFacingTo(OOCOrientation);
                me->SetHomePosition(1646.960f, 1775.986f, 107.635f, 4.763840f);
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (Player* l_Player = me->SelectNearestPlayer(18.0f))
            {
                if (m_PhaseDiff <= p_Diff)
                {
                    switch (m_Phase)
                    {
                    case 0:
                        m_Phase = 1;
                        Talk(eNitroggThundertowerTalks::TalkIntro01);
                        me->GetMotionMaster()->MovePoint(0, g_PositionNitroggtowerWaypoints[0]);
                        break;
                    case 1:
                        m_Phase = 2;
                        Talk(eNitroggThundertowerTalks::TalkIntro02);
                        me->GetMotionMaster()->MovePoint(0, g_PositionNitroggtowerWaypoints[1]);
                        break;
                    case 2:
                        m_Phase = 3;
                        Talk(eNitroggThundertowerTalks::TalkIntro03);
                        me->GetMotionMaster()->MovePoint(eNitroggThundertowerMovments::MovementPointThreeRemoveFlags, g_PositionNitroggtowerWaypoints[2]);
                        break;
                    default:
                        break;
                    }

                    m_PhaseDiff = 4 * TimeConstants::IN_MILLISECONDS;
                }
                else
                    m_PhaseDiff -= p_Diff;
            }

            if (!UpdateVictim())
                return;

            if (m_Phase == 3 && me->GetHealthPct() < 80 && events.ExecuteEvent() == eNitroggThundertowerEvents::EventOpenAssaultFlaps)
            {
                m_Phase = 4;
                events.Reset();
                me->AttackStop();

                if (m_Instance != nullptr)
                {
                    if (Creature* l_NitroggTurret = m_Instance->instance->GetCreature(m_Instance->GetGuidData(GrimrailDepotData::DataNitroggTurret)))
                    {
                        events.Reset();
                        OpenAssaultFlaps();

                        //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

                        if (Player* l_NearestPlayer = l_NitroggTurret->SelectNearestPlayer(100.0f))
                        {
                            l_NitroggTurret->SetFaction(HostileFaction);
                            l_NitroggTurret->SetInCombatWithZone();
                        }

                        events.Reset();
                        events.ScheduleEvent(eNitroggThundertowerEvents::EventReinforceBoomers, 30 * TimeConstants::IN_MILLISECONDS);
                        events.ScheduleEvent(eNitroggThundertowerEvents::EventReinforceInfantry, 20 * TimeConstants::IN_MILLISECONDS);
                    }
                }

                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                me->GetMotionMaster()->MoveJump(1646.839f, 1841.400f, 107.383f, 15.0f, 15.0f, eNitroggThundertowerMovments::MovementAboardOnTurret);
            }
            else
            {
                events.ScheduleEvent(eNitroggThundertowerEvents::EventOpenAssaultFlaps, 10 * TimeConstants::IN_MILLISECONDS);
            }
            if (m_PushbackDiff <= p_Diff)
            {
                std::list<Player*> l_ListPlayers;
                me->GetPlayerListInGrid(l_ListPlayers, 100.0f);
                if (!l_ListPlayers.empty())
                {
                    Position l_Position;
                    l_Position = me->GetPosition();
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        if (!l_Itr)
                            continue;

                        if (Creature* l_NearestPushBackTrigger = l_Itr->FindNearestCreature(GrimrailDepotCreatures::CreatureNitroggPushBackTrigger, 10.0f))
                        {
                            if (!l_Itr->IsWithinLOSInMap(l_NearestPushBackTrigger))
                            {
                                if (l_Itr->IsWithinDist(me, 100.0f, true))
                                {
                                    if (l_Itr->IsAlive() && !l_Itr->HasMovementForce(me->GetGUID()))
                                      //  l_Itr->ApplyMovementForce(me->GetGUID(), -3.0f, l_Position);
                                  //  else if (!l_Itr->IsAlive() && l_Itr->HasMovementForce(me->GetGUID()))
                                        l_Itr->RemoveMovementForce(me->GetGUID());
                                }
                                else if (l_Itr->HasMovementForce(me->GetGUID()))
                                    l_Itr->RemoveMovementForce(me->GetGUID());
                            }
                            else if (l_Itr->HasMovementForce(me->GetGUID()))
                                l_Itr->RemoveMovementForce(me->GetGUID());
                        }
                        else if (l_Itr->HasMovementForce(me->GetGUID()))
                            l_Itr->RemoveMovementForce(me->GetGUID());
                    }
                }

                m_PushbackDiff = 2 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_PushbackDiff -= p_Diff;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eNitroggThundertowerEvents::EventBlackrockGrenade:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 20.0f, true))
                    me->CastSpell(l_Target, eNitroggThundertowerSpells::SpellBlackrockGrenadeTriggerMissileA);

                events.ScheduleEvent(eNitroggThundertowerEvents::EventBlackrockGrenade, 10 * TimeConstants::IN_MILLISECONDS);
                break;
            case eNitroggThundertowerEvents::EventBlackrockMortar:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 20.0f, true))
                    me->CastSpell(l_Target, eNitroggThundertowerSpells::SpellBlackRockMortarPeriodic);

                events.ScheduleEvent(eNitroggThundertowerEvents::EventBlackrockMortar, 25 * TimeConstants::IN_MILLISECONDS);
                break;
            case eNitroggThundertowerEvents::EventReinforceBoomers:
                for (uint8 l_I = 0; l_I < 3; l_I++)
                {
                    uint32 l_Entries[3] = { GrimrailDepotCreatures::CreatureGromkarBoomer, GrimrailDepotCreatures::CreatureGromkarGrenadier, GrimrailDepotCreatures::CreatureGromkarGunner };

                    if (Creature* l_Creature = me->SummonCreature(l_Entries[l_I], g_PositionReinforce1, TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                    {
                        float l_X = (l_Creature->m_positionX + 15) * cos(l_Creature->GetOrientation());
                        float l_Y = (l_Creature->m_positionY + 15) * sin(l_Creature->GetOrientation());

                        l_Creature->GetMotionMaster()->MoveJump(l_X, l_Y, float(g_TrainFloorPositionZ));
                    }
                }

                events.ScheduleEvent(eNitroggThundertowerEvents::EventReinforceBoomers, 25 * TimeConstants::IN_MILLISECONDS);
                break;
            case eNitroggThundertowerEvents::EventReinforceInfantry:
                if (roll_chance_i(50)) /// 2ND
                {
                    for (uint8 l_I = 0; l_I < 2; l_I++)
                    {
                        if (Creature* l_Infantry = me->SummonCreature(GrimrailDepotCreatures::CreatureIronInfantry, g_PositionReinforce2, TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                            l_Infantry->SetInCombatWithZone();
                    }
                }
                else                 /// 3RD
                {
                    for (uint8 l_I = 0; l_I < 2; l_I++)
                    {
                        if (Creature* l_Infantry = me->SummonCreature(GrimrailDepotCreatures::CreatureIronInfantry, g_PositionReinforce3, TempSummonType::TEMPSUMMON_DEAD_DESPAWN))
                            l_Infantry->SetInCombatWithZone();
                    }
                }

                events.ScheduleEvent(eNitroggThundertowerEvents::EventReinforceInfantry, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
            }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new boss_nitrogg_thundertowerAI(p_Creature);
    }
};

/// Iron Turret - 
class grimrail_depot_nitrogg_thundertower_mob_iron_turret : public CreatureScript
{
    public:

    grimrail_depot_nitrogg_thundertower_mob_iron_turret() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_iron_turret") {}

    struct grimrail_depot_nitrogg_thundertower_mob_iron_turretAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_iron_turretAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eIronTowerSpells
        {
            SpellSuppressiveFirePeriodicDummy = 160681,
            SpellSuppressiveFireTriggerMissile = 160683,
            SpelllSuppresiveFireDamage = 161220,
            SpellSlagBlastTriggerMissile = 166565,
            SpellSlagBlastDot = 166570,
            SpellSlagBlastAreatrigger = 166571,
            SpellSlagBlastAreatrigger02 = 167370
        };

        enum eIronTowerEvents
        {
            EventSuppressiveFire = 1,
            EventSuppressiveFireCancel,
            EventSlagBlast
        };

        InstanceScript* m_Instance;
        bool m_SuppressiveFire;
        bool m_First;

        void Reset() override
        {
            events.Reset();
            SetCombatMovement(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }

        void EnterCombat(Unit* p_Who) override
        {    
            events.ScheduleEvent(eIronTowerEvents::EventSuppressiveFire, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eIronTowerEvents::EventSlagBlast, 20 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eIronTowerEvents::EventSuppressiveFire:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    me->CastSpell(l_Target, eIronTowerSpells::SpellSuppressiveFirePeriodicDummy);

                me->Say("suppressive fire", LANG_UNIVERSAL, me);

                events.ScheduleEvent(eIronTowerEvents::EventSuppressiveFire, 15 * TimeConstants::IN_MILLISECONDS);
                break;
            case eIronTowerEvents::EventSlagBlast:
                switch (urand(0, 2))
                {
                case 0:
                    me->CastSpell(g_PositionSlagBlast[0].GetPositionX(), g_PositionSlagBlast[0].GetPositionY(), g_PositionSlagBlast[0].GetPositionZ(), eIronTowerSpells::SpellSlagBlastTriggerMissile, true);
                    break;
                case 1:
                    me->CastSpell(g_PositionSlagBlast[1].GetPositionX(), g_PositionSlagBlast[1].GetPositionY(), g_PositionSlagBlast[1].GetPositionZ(), eIronTowerSpells::SpellSlagBlastTriggerMissile, true);
                    break;
                case 2:
                    me->CastSpell(g_PositionSlagBlast[2].GetPositionX(), g_PositionSlagBlast[2].GetPositionY(), g_PositionSlagBlast[2].GetPositionZ(), eIronTowerSpells::SpellSlagBlastTriggerMissile, true);
                    break;
                default:
                    break;
                }

                me->Say("slag blast", LANG_UNIVERSAL, me);

                events.ScheduleEvent(eIronTowerEvents::EventSlagBlast, 30 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_iron_turretAI(p_Creature);
    }
};

/// Grom'kar Boomer - 79720
class grimrail_depot_nitrogg_thundertower_mob_gromkar_boomer : public CreatureScript
{
    public:

    grimrail_depot_nitrogg_thundertower_mob_gromkar_boomer() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_gromkar_boomer") { }

    struct grimrail_depot_nitrogg_thundertower_mob_gromkar_boomerAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_gromkar_boomerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGromkarboomerEvents
        {
            EventBlackrockMortar = 1,
            EventBlackrockMortarBombs
        };

        enum eGromkarboomerSpells
        {
            SpellBlackRockTriggerMissile    = 163541,
            SpellBlackRockMortarPeriodic    = 163550,
            SpellBlackrockMortarDamage      = 160963,
            SpellBlackrockMortarShellsAura  = 160702,
            SpellBlackrockMortarShellsDummy = 160965,
        };

        InstanceScript* m_Instance;
        ObjectGuid m_TargetGUID;
        uint32 m_Modifier;
        bool m_Activated;

        void Reset() override
        {
            events.Reset();
            m_Modifier = 0;
            m_TargetGUID = ObjectGuid::Empty;
            m_Activated = false;
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarboomerEvents::EventBlackrockMortar, 8 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* p_Killer) override
        {
            /// Adds Blackrock Mortar to the player.
            if (p_Killer)
            {
                p_Killer->AddAura(eGromkarboomerSpells::SpellBlackrockMortarShellsAura, p_Killer);
                me->DespawnOrUnsummon(2 * TimeConstants::IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || m_Activated)
                return;

            switch (events.ExecuteEvent())
            {
            case eGromkarboomerEvents::EventBlackrockMortar:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 20.0f, true))
                {
                    me->CastSpell(l_Target, eGromkarboomerSpells::SpellBlackRockMortarPeriodic);
                    m_TargetGUID = l_Target->GetGUID();
                }

                m_Activated = true;
                m_Modifier = 0;

                events.ScheduleEvent(eGromkarboomerEvents::EventBlackrockMortarBombs, 2 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eGromkarboomerEvents::EventBlackrockMortar, 25 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGromkarboomerEvents::EventBlackrockMortarBombs:
            {
                if (m_Modifier == 10)
                {
                    m_Activated = false;
                    events.CancelEvent(eGromkarboomerEvents::EventBlackrockMortarBombs);
                }

                if (Vehicle* l_Vehicle = me->GetVehicleKit())
                {
                    if (Unit* l_Passenger = l_Vehicle->GetPassenger(0))
                    {
                        if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_TargetGUID))
                        {
                            m_Modifier += 2;
                            float l_X = (me->m_positionX + 2 + m_Modifier) * cos(me->GetOrientation());
                            float l_Y = (me->m_positionY + 2 + m_Modifier) * sin(me->GetOrientation());

                            l_Passenger->CastSpell(l_X, l_Y, l_Target->GetPositionZ(), eGromkarboomerSpells::SpellBlackRockTriggerMissile, true);
                        }
                    }
                }
                events.ScheduleEvent(eGromkarboomerEvents::EventBlackrockMortarBombs, 2 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_gromkar_boomerAI(p_Creature);
    }
};

/// Assault Turret - 82721
class grimrail_depot_nitrogg_thundertower_mob_assault_turret : public CreatureScript
{
    public:

    grimrail_depot_nitrogg_thundertower_mob_assault_turret() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_assault_turret") { }

    struct grimrail_depot_nitrogg_thundertower_mob_assault_turretAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_assault_turretAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = p_Creature->GetInstanceScript();
        }

        enum eGromkarboomerEvents
        {
            EventBlackrockMortar = 1,
            EventBlackrockMortarBombs
        };

        enum eGromkarboomerSpells
        {
            SpellBlackRockTriggerMissile = 163541,
            SpellBlackRockMortarPeriodic = 163550,
            SpellBlackrockMortarDamage = 160963,
            SpellBlackrockMortarShellsAura = 160702,
            SpellBlackrockMortarShellsDummy = 160965
        };

        InstanceScript* m_Instance;

        void Reset() override
        {
            events.Reset();
            me->SetReactState(ReactStates::REACT_PASSIVE);
            SetCombatMovement(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC));
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            // wtf is this...
/*            switch (events.ExecuteEvent())
            {
                default:
                    break;
            }
*/
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_assault_turretAI(p_Creature);
    }
};

/// Iron Infantry - 79888
class grimrail_depot_nitrogg_thundertower_mob_iron_infantry : public CreatureScript
{
    public:

    grimrail_depot_nitrogg_thundertower_mob_iron_infantry() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_iron_infantry") { }

    struct grimrail_depot_nitrogg_thundertower_mob_iron_infantryAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_iron_infantryAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            // wtf is this...
/*            switch (events.ExecuteEvent())
            {
            default:
                break;
            }
*/
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_iron_infantryAI(p_Creature);
    }
};
/*
/// Slag Blast Creature Trigger - 79888
class grimrail_depot_nitrogg_thundertower_mob_slag_blast : public CreatureScript
{
    public:

    grimrail_depot_nitrogg_thundertower_mob_slag_blast() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_slag_blast") { }

    struct grimrail_depot_nitrogg_thundertower_mob_slag_blastAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_slag_blastAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eNitroggSlagBlastSpells
        {
            SpellSlagBlastAreatrigger = 166571
        };

        void DoAction(int32 const p_Action) override
        {
            switch (p_Action)
            {
            case eNitroggThundertowerActions::ActionActivateSlagBlast:
                me->CastSpell(me, eNitroggSlagBlastSpells::SpellSlagBlastAreatrigger);
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_slag_blastAI(p_Creature);
    }
};
*/

/// Grom'kar Grenadier - 79739
class grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadier : public CreatureScript
{
public:

    grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadier() : CreatureScript("grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadier") { }

    struct grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadierAI : public ScriptedAI
    {
        grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadierAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        enum eGromkarGrenadierEvents
        {
            EventBlackrockGrenade = 1
        };

        enum eGromkarGrenadierSpells
        {
            SpellBlackRockGrenade       = 161150,
            SpellBlackrockGrenadeAura   = 160703,
            SpellBlackrockGrenadeDummy  = 160997
        };

        void Reset() override
        {
            events.Reset();
        }

        void JustDied(Unit* p_Killer) override
        {
            /// Adds Blackrock Mortar to the player.
            if (p_Killer)
            {
                p_Killer->AddAura(eGromkarGrenadierSpells::SpellBlackrockGrenadeAura, p_Killer);
                me->DespawnOrUnsummon(2 * TimeConstants::IN_MILLISECONDS);
            }
        }

        void EnterCombat(Unit* p_Attacker) override
        {
            events.ScheduleEvent(eGromkarGrenadierEvents::EventBlackrockGrenade, 4 * TimeConstants::IN_MILLISECONDS);
        }

        void UpdateAI(uint32 const p_Diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case eGromkarGrenadierEvents::EventBlackrockGrenade:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 10.0f, true))
                    me->CastSpell(l_Target, eGromkarGrenadierSpells::SpellBlackRockGrenade);
                events.ScheduleEvent(eGromkarGrenadierEvents::EventBlackrockGrenade, 10 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadierAI(p_Creature);
    }
};

/// Suppressive Fire - 160681  
class grimrail_depot_nitrogg_thundertower_spell_suppressive_fire : public SpellScriptLoader
{
    public:

    grimrail_depot_nitrogg_thundertower_spell_suppressive_fire() : SpellScriptLoader("grimrail_depot_nitrogg_thundertower_spell_suppressive_fire") { }

    class grimrail_depot_nitrogg_thundertower_spell_suppressive_fire_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_nitrogg_thundertower_spell_suppressive_fire_AuraScript);

        enum eSuppressiveFireSpells
        {
            SpellSuppressiveFireTriggerMissile = 160683
        };

        enum eSuppressiveFireCreatures
        {
            CreatureIronTurretNitroggSuppressiveFire = 324265
        };

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            PreventDefaultAction();

            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetTarget())
                {
                    if (l_Target->IsWithinLOSInMap(l_Caster))
                    {
                        Position l_Position;

                        Position l_Pos = *l_Target;
                        float l_Angle = l_Caster->GetRelativeAngle(l_Pos.GetPositionX(), l_Pos.GetPositionY());
                        float l_Dist = l_Caster->GetDistance(l_Pos);

                        l_Pos = l_Caster->GetFirstCollisionPosition(l_Dist, l_Angle);

                        if (Creature* l_NearestTrigger = l_Caster->SummonCreature(eSuppressiveFireCreatures::CreatureIronTurretNitroggSuppressiveFire, l_Position, TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 1 * TimeConstants::IN_MILLISECONDS))
                        {
                            l_NearestTrigger->SetReactState(ReactStates::REACT_PASSIVE);
                            l_NearestTrigger->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
                            l_Caster->SendPlaySpellVisual(l_NearestTrigger->GetGUID(), eNitroggThundertowerSpellVisuals::SpellFireSuppressionVisualId, 0, 0, 50.0f, false);
                            l_Caster->CastSpell(l_NearestTrigger, eSuppressiveFireSpells::SpellSuppressiveFireTriggerMissile, true);
                        }
                    }
                    else
                    {
                        l_Caster->SendPlaySpellVisual(l_Target->GetGUID(), eNitroggThundertowerSpellVisuals::SpellFireSuppressionVisualId, 0, 0, 50.0f, false);
                        l_Caster->CastSpell(l_Target, eSuppressiveFireSpells::SpellSuppressiveFireTriggerMissile, true);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(grimrail_depot_nitrogg_thundertower_spell_suppressive_fire_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_nitrogg_thundertower_spell_suppressive_fire_AuraScript();
    }
};

/// Suppressive Fire - 160681  
class grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb : public SpellScriptLoader
{
    public:

    grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb() : SpellScriptLoader("grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb") { }

    class grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb_AuraScript : public AuraScript
    {
        PrepareAuraScript(grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb_AuraScript);

        enum eBlackrockSpells
        {
            SpellBlackRockTriggerMissile = 163541
        };

        void HandlePeriodic(AuraEffect const* p_AurEff)
        {
            PreventDefaultAction();

            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetTarget())
                    l_Caster->CastSpell(l_Target, eBlackrockSpells::SpellBlackRockTriggerMissile, true);
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb_AuraScript::HandlePeriodic, SpellEffIndex::EFFECT_1, AuraType::SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb_AuraScript();
    }
};

/// Slag Blast - 166565 
class grimrail_depot_nitrogg_thundertower_slag_blast : public SpellScriptLoader
{
    public:

    grimrail_depot_nitrogg_thundertower_slag_blast() : SpellScriptLoader("grimrail_depot_nitrogg_thundertower_slag_blast") { }

    class grimrail_depot_nitrogg_thundertower_slag_blast_SpellScript : public SpellScript
    {
        PrepareSpellScript(grimrail_depot_nitrogg_thundertower_slag_blast_SpellScript);

        enum eSlagBlastSpells
        {
            SpellSlagBlastAreatrigger = 166571
        };

        void OnSpellHit(SpellEffIndex)
        {
            Unit* l_Caster = GetCaster();
            WorldLocation const* l_Dest = GetExplTargetDest();

            if (!l_Caster || !l_Dest)
                return;

            l_Caster->CastSpell(l_Dest->GetPosition(), eSlagBlastSpells::SpellSlagBlastAreatrigger, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(grimrail_depot_nitrogg_thundertower_slag_blast_SpellScript::OnSpellHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new grimrail_depot_nitrogg_thundertower_slag_blast_SpellScript();
    }
};

/// Slagblast - 166571   AT 2760
class grimrail_depot_nitrogg_thundertower_at_slagblast : public AreaTriggerEntityScript
{
    public:

    grimrail_depot_nitrogg_thundertower_at_slagblast() : AreaTriggerEntityScript("grimrail_depot_nitrogg_thundertower_at_slagblast") { }

    enum eSlagblastSpells
    {
        SpellSlagBlastDot = 166570,
        SpellSlagBlastAreatrigger = 166571
    };

    enum eSlagblastCreatures
    {
        CreatureSlagblast = 543533
    };

    struct grimrail_depot_nitrogg_thundertower_at_slagblast_AI : public AreaTriggerAI
    {
        explicit grimrail_depot_nitrogg_thundertower_at_slagblast_AI(AreaTrigger* at) : AreaTriggerAI(at)    { m_Targets.clear(); }

        std::list<ObjectGuid> m_Targets;
        uint32 m_Timer = 2 * TimeConstants::IN_MILLISECONDS;

        void OnUpdate(uint32 diff) override
        {
            if (m_Timer <= diff)
            {
                std::list<Player*> l_PlayerList;

                l_PlayerList = at->SelectNearestPlayers(2.0f, true);

                if (l_PlayerList.empty())
                    return;

                for (auto l_Itr : l_PlayerList)
                {
                    if (!l_Itr->HasAura(eSlagblastSpells::SpellSlagBlastDot))
                    {
                        l_Itr->CastSpell(l_Itr, eSlagblastSpells::SpellSlagBlastDot, true);
                        m_Targets.push_back(l_Itr->GetGUID());
                    }
                }

                m_Timer = 1 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_Timer -= diff;
        }

        void OnCreate() override
        {
            std::list<Creature*> l_ListCreatures;
            at->GetCreatureListWithEntryInGrid(l_ListCreatures, eSlagblastCreatures::CreatureSlagblast, 200.0f);
            if (!l_ListCreatures.empty())
            {
                /// Sort so fire spreads from the hit point.
                l_ListCreatures.sort();
                //l_ListCreatures.sort(Trinity::WorldObjectDistanceCompareOrderPred(at));
                l_ListCreatures.resize(l_ListCreatures.max_size());

                for (std::list<Creature*>::iterator l_Itr = l_ListCreatures.begin(); l_Itr != l_ListCreatures.end(); l_Itr++)
                {
                    if (!(*l_Itr))
                        continue;

                    (*l_Itr)->CastSpell((*l_Itr), eSlagblastSpells::SpellSlagBlastAreatrigger);
                }
            }
        }

        void OnRemove() override
        {
            if (m_Targets.empty())
                return;

            for (ObjectGuid l_Guid : m_Targets)
            {
                Unit* l_Target = ObjectAccessor::GetUnit(*at, l_Guid);
                if (l_Target && l_Target->HasAura(eSlagblastSpells::SpellSlagBlastDot))
                    l_Target->RemoveAura(eSlagblastSpells::SpellSlagBlastDot);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new grimrail_depot_nitrogg_thundertower_at_slagblast_AI(at);
    }
};

void AddSC_boss_nitrogg_thundertower()
{
    new boss_nitrogg_thundertower();                                    ///< 79545
    new grimrail_depot_nitrogg_thundertower_mob_iron_turret();          ///< 85216
    new grimrail_depot_nitrogg_thundertower_mob_gromkar_boomer();       ///< 79720
    new grimrail_depot_nitrogg_thundertower_mob_assault_turret();       ///< 55169
    new grimrail_depot_nitrogg_thundertower_mob_iron_infantry();        ///< 79888
    new grimrail_depot_nitrogg_thundertower_mob_gromkar_grenadier();    ///  79739
    new grimrail_depot_nitrogg_thundertower_spell_blackrock_bomb();     ///< 163550 
    new grimrail_depot_nitrogg_thundertower_spell_suppressive_fire();   ///< 160681
    new grimrail_depot_nitrogg_thundertower_slag_blast();               ///< 166565
    new grimrail_depot_nitrogg_thundertower_at_slagblast();             ///< 166571
}
