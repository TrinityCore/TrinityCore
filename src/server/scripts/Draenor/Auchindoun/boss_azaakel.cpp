#include "ScriptMgr.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "auchindoun.h"


enum eAzzakelSpells
{
    SpellClawsOfArgusBuff = 153762,
    SpellClawsOfArgusVisual = 153764,
    SpellClawsOfArgusDmg = 153772,
    SpellCurtainOfFlameAura = 153392,
    SpellCurtainOfFlameForceCast = 153396,
    SpellCurtainOfFlameVisual = 153400,
    SpellFelLashVisual = 153234,
    SpellFelLashDummy = 174872,
    SpellFelLashDebuff = 177120,
    SpellFelLashDebuffTwo = 177121,
    SpellMalevilentCrush = 153499,
    SpellFelPoolAreatriger = 153500,
    SpellFelPoolDebuffDmg = 153616,
    SpellVisualFelBurst = 169682,
    SpellFelSparkAreaTrigger = 153725,
    SpellFelSparkDamage = 153726,
    SpellFelSparkPerioidicCreation = 153727,
    SpellSummonImp = 153775,
    SpellFelGuard = 164080,
    SpellSummonPyromaniac = 164127,
    SpellFly = 161778
};

enum eAzzakelEvents
{
    EventClawsOfArgus = 1,
    EventCurtainOfFlame,
    EventFelLash,
    EventFelPool,
    EventFelSpark = 78,
    EventMalevolentCrush01,
    EventMalevolentCrush02,
    EventSummonAzzakel01,
    EventSummonAzzakel02
};

enum eAzzakelTalks
{
    AzzakelIntro = 0,  ///< Who Dares Meddlie In The Works Of The Legion?! (46776) 
    AzzakelAggro = 1,  ///< This World...All World...Shell Burn!(46774)
    AzzakelSpell03 = 2,  ///< Die, Insect!(46781)
    AzzakelSpell02 = 3,  ///< Burn In The Master'S Fire!(46780)
    AzzakelSpell01 = 4,  ///< Come Forth, Servants!(46779)
    AzzakelKill01 = 90297,  ///< The Masters Blase Your Soul! (46777)
    AzzakelKill02 = 90298,  ///< Burn! (46778)
    AzzakelDeath = 44   ///< (46775)
};

enum eAzzakelCreatures
{
    TriggerFelPool = 326526,
    TriggerFelSpark = 326527,
    TriggerDemonSummoning = 432636,
    CreatureFelguard = 76259,
    CreatureCacklingPyromaniac = 76260,
    CreatureBlazingTrickster = 79511,
    CreatureBlazingTrickster02 = 76220
};

enum eAzzakelActions
{
    ActionFelSpark = 1,
    ActionSummonDemons,
    ActionRenewEvents,
    ActionBoolActivate,
    ActionBoolDeactivate,
    ActionMalevolentCrash
};

enum eAzzakelMovements
{
    MovementAzzakelMalevolentCrash = 2
};

Position const g_PositionAzzakel_Blackgate = { 1929.65f, 2699.27f, 30.799f, 4.428220f };

Position const g_PositionSpawningFlyCoords[2] =
{
    { 1912.13f, 2720.44f, 49.818f, 1.600908f },
{ 1911.65f, 2757.73f, 30.799f, 4.748000f }
};

Position const g_PositionAzzakelBlackgateLittle[4] =
{
    { 1911.90f, 2680.62f, 31.418f, 1.450705f },
{ 1911.79f, 2764.35f, 31.418f, 4.721891f },
{ 1953.55f, 2722.47f, 31.418f, 3.139304f },
{ 1869.70f, 2722.45f, 31.418f, 0.001632f }
};

static void HandleDoors(Unit* p_Me)
{
    std::list<GameObject*> l_ListGameObjects;
    p_Me->GetGameObjectListWithEntryInGrid(l_ListGameObjects, eAuchindounObjects::GameobjectFelBarrier, 100.0f);
    if (l_ListGameObjects.empty())
        return;

    for (GameObject* l_Itr : l_ListGameObjects)
        l_Itr->Delete();
}

struct boss_azaakel : public BossAI
{
    boss_azaakel(Creature* creature) : BossAI(creature, DATA_AZAAKEL)
    {
        m_Intro = false;
        m_First = true;
    }

    uint32 m_Interval;
    bool m_Intro;
    bool m_Argus;
    bool m_First;
    bool m_Achievement;

    void Reset() override
    {
        _Reset();
        events.Reset();
        m_Argus = false;
        m_Interval = 3 * TimeConstants::IN_MILLISECONDS;

        instance->DoRemoveAurasDueToSpellOnPlayers(eAzzakelSpells::SpellFelPoolDebuffDmg);
        instance->DoRemoveAurasDueToSpellOnPlayers(eAzzakelSpells::SpellFelSparkPerioidicCreation);
        me->SetHomePosition(g_PositionSpawningFlyCoords[1].GetPositionX(), g_PositionSpawningFlyCoords[1].GetPositionY(), g_PositionSpawningFlyCoords[1].GetPositionZ(), me->GetOrientation());
        me->GetMotionMaster()->MoveTargetedHome();

        uint32 l_Entries[5] = { eAzzakelCreatures::TriggerDemonSummoning, eAzzakelCreatures::CreatureCacklingPyromaniac, eAzzakelCreatures::CreatureBlazingTrickster, eAzzakelCreatures::CreatureFelguard, eAzzakelCreatures::CreatureBlazingTrickster02 };
        for (uint32 l_Entry : l_Entries)
            DespawnCreaturesInArea(l_Entry, me);
    }

    void MoveInLineOfSight(Unit* p_Who)
    {
        if (p_Who && p_Who->IsInWorld() && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER && me->IsWithinDistInMap(p_Who, 18.0f) && !m_Intro)
        {
            m_Intro = true;
            Talk(eAzzakelTalks::AzzakelIntro);
        }
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eAuchindounActions::ActionDemonSoulsAchievement:
            m_Achievement = false;
            break;
        case eAzzakelActions::ActionBoolDeactivate:
            m_Argus = false;
            me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), true);
            break;
        case eAzzakelActions::ActionBoolActivate:
            m_Argus = true;
            break;
        case eAzzakelActions::ActionFelSpark:
            events.ScheduleEvent(eAzzakelEvents::EventFelSpark, 1 * TimeConstants::IN_MILLISECONDS);
            break;
        case eAzzakelActions::ActionRenewEvents:
        {
            events.Reset();
            me->GetMotionMaster()->Clear();
            me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), false);
            events.ScheduleEvent(eAzzakelEvents::EventFelLash, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eAzzakelEvents::EventClawsOfArgus, 45 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eAzzakelEvents::EventCurtainOfFlame, 14 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eAzzakelEvents::EventMalevolentCrush01, 20 * TimeConstants::IN_MILLISECONDS);
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                AttackStart(l_Target);
            break;
        }
        case eAzzakelActions::ActionMalevolentCrash:
            events.ScheduleEvent(eAzzakelEvents::EventMalevolentCrush01, 1 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }
    }

    void JustReachedHome()
    {
        _JustReachedHome();
        HandleDoors(me);
        summons.DespawnAll();

        uint32 l_Entries[4] = { CreatureCacklingPyromaniac, CreatureBlazingTrickster, CreatureFelguard, CreatureBlazingTrickster02 };
        for (uint32 l_Entry : l_Entries)
            DespawnCreaturesInArea(l_Entry, me);
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon)
        {
            switch (summon->GetEntry())
            {
            case eAzzakelCreatures::CreatureBlazingTrickster:
            case eAzzakelCreatures::CreatureCacklingPyromaniac:
            case eAzzakelCreatures::CreatureFelguard:
                summon->SetReactState(ReactStates::REACT_AGGRESSIVE);
                summon->SetInCombatWithZone();
                break;
            default:
                break;
            }
        }
    }

    void ScheduleTasks() override
    {
        m_Achievement = true;
        Talk(eAzzakelTalks::AzzakelAggro);

        me->SummonGameObject(eAuchindounObjects::GameobjectFelBarrier, 1911.01f, 2722.89f, 30.799f, g_PositionAzzakel_Blackgate.GetOrientation(), QuaternionData(0, 0, 0, 0), 0);
        events.ScheduleEvent(eAzzakelEvents::EventFelLash, 8 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eAzzakelEvents::EventClawsOfArgus, 45 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eAzzakelEvents::EventCurtainOfFlame, 14 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eAzzakelEvents::EventMalevolentCrush01, 20 * TimeConstants::IN_MILLISECONDS);

        if (instance)
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);
    }

    void MovementInform(uint32 p_Type, uint32 p_ID)
    {
        if (p_ID == eAzzakelMovements::MovementAzzakelMalevolentCrash)
        {
            me->SummonCreature(eAzzakelCreatures::TriggerFelPool, *me, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            me->CastSpell(me, eAzzakelSpells::SpellFelPoolAreatriger);

            me->SetCanFly(false);
            me->SetDisableGravity(false);
            Talk(eAzzakelTalks::AzzakelSpell02);
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);

            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->GetMotionMaster()->MoveChase(l_Target, 0.0f, 0.0f);
                me->Attack(l_Target, true);
            }
        }
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        _JustDied();
        Talk(eAzzakelTalks::AzzakelDeath);
        uint32 l_Entries[4] = { eAzzakelCreatures::CreatureCacklingPyromaniac, eAzzakelCreatures::CreatureBlazingTrickster, eAzzakelCreatures::CreatureFelguard, eAzzakelCreatures::CreatureBlazingTrickster02 };
        for (uint32 l_Entry : l_Entries)
            DespawnCreaturesInArea(l_Entry, me);

        if (instance)
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(eAzzakelSpells::SpellFelPoolDebuffDmg);
            instance->DoRemoveAurasDueToSpellOnPlayers(eAzzakelSpells::SpellFelSparkPerioidicCreation);
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_DISENGAGE, me);;

            if (GameObject* l_Transport = instance->GetGameObject(eAuchindounDatas::DataSoulTransport1))
            {
                l_Transport->SetLootState(LootState::GO_READY);
                l_Transport->UseDoorOrButton(10 * TimeConstants::IN_MILLISECONDS, false, me);
            }
            //成就
            /*  if (m_Achievement)
            {
            if (me->GetMap() && me->GetMap()->IsHeroic())
            m_Instance->DoCompleteAchievement(eAuchindounAchievements::AchievementDemonSouls);
            }*/
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        if (m_Argus)
        {
            if (m_Interval <= p_Diff)
            {
                if (Creature* l_AzzakelController = me->FindNearestCreature(87218,100.0f,true)) 
                {
                    switch (urand(0, 3))
                    {
                    case 0:
                        l_AzzakelController->CastSpell(l_AzzakelController, eAzzakelSpells::SpellSummonImp);
                        break;
                    case 1:
                        l_AzzakelController->CastSpell(l_AzzakelController, eAzzakelSpells::SpellFelGuard);
                        break;
                    case 2:
                        l_AzzakelController->CastSpell(l_AzzakelController, eAzzakelSpells::SpellSummonPyromaniac);
                        break;
                    default:
                        break;
                    }
                }

                m_Interval = 3 * TimeConstants::IN_MILLISECONDS;
            }
            else
                m_Interval -= p_Diff;
        }

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eAzzakelEvents::EventFelLash:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eAzzakelSpells::SpellFelLashVisual);
            events.Repeat(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS);
            break;
        case eAzzakelEvents::EventClawsOfArgus:
        {
            events.Reset();
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 2.5f);
            Talk(eAzzakelTalks::AzzakelSpell01);
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_FLYING);
            me->CastSpell(me, eAzzakelSpells::SpellClawsOfArgusVisual);
            // me->MonsterTextEmote("Azzakel casts |cffff0000[Azzakael casts [Claws of Agrus]|cfffaeb00!", me->GetGUID(), true);
            events.Repeat(45 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eAzzakelEvents::EventCurtainOfFlame:
        {
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
            {
                Talk(eAzzakelTalks::AzzakelSpell03);
                me->AddAura(eAzzakelSpells::SpellCurtainOfFlameAura, l_Target);
            }

            events.Repeat(8 * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eAzzakelEvents::EventMalevolentCrush01:
        {
            me->StopMoving();
            me->AttackStop();
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            Talk(eAzzakelTalks::AzzakelSpell02);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 2.5f);

            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->GetMotionMaster()->MoveJump(l_Target->GetPositionX(), l_Target->GetPositionY(), l_Target->GetPositionZ(), 15.0f, 20.0f, 10.0f, eAzzakelMovements::MovementAzzakelMalevolentCrash);

            events.Repeat(20 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        default:
            break;
        }

        DoMeleeAttackIfReady();
    } 

};

/// Azzakael Controller - 76216
struct auchindoun_azzakel_mob_controller : public ScriptedAI
{
    auchindoun_azzakel_mob_controller(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
        m_First = true;
    }

    InstanceScript* m_Instance;
    EventMap events;
    ObjectGuid m_Azzakel;
    int32 m_Counting;
    bool m_Summoned;
    bool m_First;

    void Reset()
    {
        if (m_First)
        {
            HandleDoors(me);
            m_Azzakel = ObjectGuid::Empty;
            m_Counting = 0;
            m_First = false;
            m_Summoned = false;
            me->SetFaction(FriendlyFaction);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
        }
    }

    void JustSummoned(Creature* p_Summon)
    {
        if (p_Summon)
        {
            switch (p_Summon->GetEntry())
            {
            case eAzzakelCreatures::CreatureBlazingTrickster:
            case eAzzakelCreatures::CreatureCacklingPyromaniac:
            case eAzzakelCreatures::CreatureFelguard:
                p_Summon->SetReactState(ReactStates::REACT_AGGRESSIVE);
                p_Summon->SetInCombatWithZone();
                break;
            default:
                break;
            }
        }
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eAuchindounActions::ActionCountPre3StBossKill:
        {
            m_Counting = m_Counting + 1;

            if (m_Counting >= 6 && !m_Summoned)
            {
                m_Summoned = true;
                me->CastSpell(me, eAzzakelSpells::SpellVisualFelBurst);
                me->NearTeleportTo(1911.50f, 2722.52f, 30.799f, g_PositionAzzakel_Blackgate.GetOrientation());
                events.ScheduleEvent(EventSummonAzzakel01, 2 * TimeConstants::IN_MILLISECONDS);
            }
            break;
        }
        default:
            break;
        }
    }

    void UpdateAI(uint32 p_p_Diff) override
    {
        events.Update(p_p_Diff);

        switch (events.ExecuteEvent())
        {
        case eAzzakelEvents::EventSummonAzzakel01:
        {
            if (Creature* TempAzzakael = me->SummonCreature(NPC_AZAAKEL, *me, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN))
            {
                if (GameObject* l_Portal = me->SummonGameObject(eAuchindounObjects::GameobjectDemonicPortal, *me, QuaternionData(0, 0, 0, 0), 0))
                {
                    m_Azzakel = TempAzzakael->GetGUID();
                    l_Portal->AddFlag(GameObjectFlags(GO_FLAG_NOT_SELECTABLE | GameObjectFlags::GO_FLAG_NODESPAWN | GO_FLAG_INTERACT_COND));
                    Position const pos = { g_PositionSpawningFlyCoords[1].GetPositionX(), g_PositionSpawningFlyCoords[1].GetPositionY(), g_PositionSpawningFlyCoords[1].GetPositionZ() };
                    TempAzzakael->GetMotionMaster()->MoveJump(pos, 30.0f, 25.0f);
                }
            }
            events.ScheduleEvent(eAzzakelEvents::EventSummonAzzakel02, 1 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eAzzakelEvents::EventSummonAzzakel02:
        {
            if (!m_Azzakel)
            {
                if (Creature* l_Azzakael = ObjectAccessor::GetCreature(*me, m_Azzakel))
                {
                    l_Azzakael->SetFaction(HostileFaction);
                    l_Azzakael->GetMotionMaster()->MoveCharge(1911.93f, 2754.40f, 30.973f, 42.0f);
                }
                break;
            }
        }
        default:
            break;
        }
    }

};

/// Fel Spark Trigger - 326527
class auchindoun_azzakel_mob_fel_spark_trigger : public CreatureScript
{
public:

    auchindoun_azzakel_mob_fel_spark_trigger() : CreatureScript("auchindoun_azzakel_mob_fel_spark_trigger") {}

    struct auchindoun_azzakel_mob_fel_spark_triggerAI : public ScriptedAI
    {
        auchindoun_azzakel_mob_fel_spark_triggerAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_First = true;
        }

        enum eFelSparkSpells
        {
            SpellFelSparkAreaTrigger = 153725
        };

        enum eFelSparkCreatures
        {
            CreatureFelSparkNullAI = 326527,
            CreatureFelSparkNullAITrigger = 326528
        };

        bool m_First;

        void Reset()
        {
            m_First = false;
            me->SetFaction(HostileFaction);
            me->SetDisplayId(InvisibleDisplay);
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));

            for (uint8 l_I = 0; l_I < 20; ++l_I)
            {
                float l_X = me->m_positionX + (l_I + 1) /** cos(me->m_orientation)*/;
                float l_Y = me->m_positionY + (l_I + 1)/* * sin(me->m_orientation)*/;

                /// 326528
                if (Creature* l_FelSparkNullAITrigger = me->SummonCreature(eFelSparkCreatures::CreatureFelSparkNullAITrigger, l_X, l_Y, me->GetPositionZ(), me->GetOrientation(), TempSummonType::TEMPSUMMON_TIMED_DESPAWN, 7 * TimeConstants::IN_MILLISECONDS))
                {
                    l_FelSparkNullAITrigger->SetFaction(HostileFaction);
                    l_FelSparkNullAITrigger->SetDisplayId(InvisibleDisplay);
                    l_FelSparkNullAITrigger->SetReactState(ReactStates::REACT_PASSIVE);
                    l_FelSparkNullAITrigger->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));

                    l_FelSparkNullAITrigger->CastSpell(l_FelSparkNullAITrigger, eFelSparkSpells::SpellFelSparkAreaTrigger, true);
                }
            }

            me->DespawnOrUnsummon(7 * TimeConstants::IN_MILLISECONDS);
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_azzakel_mob_fel_spark_triggerAI(p_Creature);
    }
};

/// Fel Pool - 326526
class auchindoun_azzakel_mob_fel_pool : public CreatureScript
{
public:

    auchindoun_azzakel_mob_fel_pool() : CreatureScript("auchindoun_azzakel_mob_fel_pool") {}

    struct auchindoun_azzakel_mob_fel_poolAI : public ScriptedAI
    {
        auchindoun_azzakel_mob_fel_poolAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_First = true;
            m_Instance = me->GetInstanceScript();
        }

        enum eFelPoolSpells
        {
            SpellFelPoolDebuffDmg = 153616
        };

        bool m_First;
        InstanceScript* m_Instance;

        void Reset()
        {
            if (m_First)
            {
                m_First = false;
                me->SetFaction(HostileFaction);
                me->SetDisplayId(InvisibleDisplay);
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
            }

            if (m_Instance != nullptr)
            {
                if (m_Instance->instance->IsHeroic())
                {
                    me->SummonCreature(eAzzakelCreatures::TriggerFelSpark, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 4.756f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(eAzzakelCreatures::TriggerFelSpark, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.028f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(eAzzakelCreatures::TriggerFelSpark, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 1.583f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(eAzzakelCreatures::TriggerFelSpark, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 3.111f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
        }

        void UpdateAI(uint32 p_Diff) override
        {
            std::list<Player*> l_ListPlayers;
            me->GetPlayerListInGrid(l_ListPlayers, 15.0f);
            // me->VisitNearbyObject(15.0f, searcher);
            if (!l_ListPlayers.empty())
            {
                for (std::list<Player*>::const_iterator l_Itr = l_ListPlayers.begin(); l_Itr != l_ListPlayers.end(); ++l_Itr)
                {
                    if (!(*l_Itr))
                        continue;

                    if ((*l_Itr)->IsWithinDistInMap(me, 5.0f))
                    {
                        if (!(*l_Itr)->HasAura(eFelPoolSpells::SpellFelPoolDebuffDmg))
                            me->AddAura(eFelPoolSpells::SpellFelPoolDebuffDmg, (*l_Itr));
                    }
                    else
                    {
                        if ((*l_Itr)->HasAura(eFelPoolSpells::SpellFelPoolDebuffDmg, me->GetGUID()))
                            (*l_Itr)->RemoveAura(eFelPoolSpells::SpellFelPoolDebuffDmg);
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_azzakel_mob_fel_poolAI(p_Creature);
    }
};

/// Curtain of Flames - 153392
class auchindoun_azzakel_spell_curtain_flames : public SpellScriptLoader
{
public:

    auchindoun_azzakel_spell_curtain_flames() : SpellScriptLoader("auchindoun_azzakel_spell_curtain_flames") { }

    class auchindoun_azzakel_spell_curtain_flames_AuraScript : public AuraScript
    {
        PrepareAuraScript(auchindoun_azzakel_spell_curtain_flames_AuraScript);

        enum eCurtainFlamesSpells
        {
            SpellCurtainOfFlameAura = 153392,
            SpellCurtainOfFlameVisual = 153400
        };
        void OnPeriodic(AuraEffect const* p_AurEff)
        {
            if (Unit* l_Target = GetTarget())
            {
                if (l_Target->GetTypeId() != TypeID::TYPEID_PLAYER)
                    return;

                std::list<Player*> l_ListPlayers;
                l_Target->GetPlayerListInGrid(l_ListPlayers, 3.0f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        if (!l_Itr)
                            continue;

                        if (GetTarget()->GetGUID() != l_Itr->GetGUID())
                        {
                            l_Target->AddAura(eCurtainFlamesSpells::SpellCurtainOfFlameAura, l_Itr);
                            l_Target->CastSpell(l_Target, eCurtainFlamesSpells::SpellCurtainOfFlameVisual);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_azzakel_spell_curtain_flames_AuraScript::OnPeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new auchindoun_azzakel_spell_curtain_flames_AuraScript();
    }
};

/// Claw of Flames Loader - 153764
class auchindoun_azzakel_spell_claws_of_argus : public SpellScriptLoader
{
public:

    auchindoun_azzakel_spell_claws_of_argus() : SpellScriptLoader("auchindoun_azzakel_spell_claws_of_argus") { }

    class auchindoun_azzakel_spell_claws_of_argus_AuraScript : public AuraScript
    {
        PrepareAuraScript(auchindoun_azzakel_spell_claws_of_argus_AuraScript);

        enum eAzzakelEvents
        {
            EventMalevolentCrush01 = 78
        };

        void OnApply(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
        {
            if (!GetCaster())
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature* l_Azzakel = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eAuchindounDatas::DataBossAzzakael)))
                {
                    if (l_Azzakel->IsAIEnabled)
                    {
                        l_Azzakel->SetCanFly(true);
                        l_Azzakel->SetDisableGravity(true);
                        l_Azzakel->GetAI()->DoAction(eAzzakelActions::ActionBoolActivate);
                        l_Azzakel->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE));
                        Position pos;
                        pos.Relocate(l_Azzakel);
                        pos.m_positionZ += 45.0f;
                        l_Azzakel->GetMotionMaster()->MoveTakeoff(1000, pos);  //修改过定位位置。。
                    }
                }
            }
        }

        void OnRemove(AuraEffect const* p_AurEff, AuraEffectHandleModes /*p_Mode*/)
        {
            if (!GetCaster())
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature* l_Azzakel = l_Instance->instance->GetCreature(l_Instance->GetGuidData(eAuchindounDatas::DataBossAzzakael)))
                {
                    if (l_Azzakel->IsAIEnabled)
                    {
                        l_Azzakel->RemoveAllAuras();
                        l_Azzakel->SetReactState(ReactStates::REACT_DEFENSIVE);
                        l_Azzakel->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_NOT_SELECTABLE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));
                        l_Azzakel->GetAI()->DoAction(eAzzakelActions::ActionBoolDeactivate);
                        l_Azzakel->GetAI()->DoAction(eAzzakelActions::ActionRenewEvents);

                        l_Azzakel->SetCanFly(false);
                        l_Azzakel->SetDisableGravity(false);
                        l_Azzakel->RemoveAura(eAzzakelSpells::SpellFly);
                        l_Azzakel->SetReactState(ReactStates::REACT_AGGRESSIVE);
                        l_Azzakel->SetSpeed(UnitMoveType::MOVE_FLIGHT, 0.3f);

                        if (l_Azzakel->GetMap() && l_Azzakel->GetMap()->IsHeroic())
                            l_Azzakel->GetAI()->DoAction(eAzzakelActions::ActionMalevolentCrash);
                        else
                        {
                            if (Unit* l_Target = GetCaster()->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                            {
                                GetCaster()->GetMotionMaster()->MoveChase(l_Target, 0.0f, 0.0f);
                                GetCaster()->Attack(l_Target, true);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(auchindoun_azzakel_spell_claws_of_argus_AuraScript::OnApply, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(auchindoun_azzakel_spell_claws_of_argus_AuraScript::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new auchindoun_azzakel_spell_claws_of_argus_AuraScript();
    }
};

/// Fel Spark - 153725
class auchindoun_azzakel_at_fel_spark : public AreaTriggerEntityScript
{
public:

    auchindoun_azzakel_at_fel_spark() : AreaTriggerEntityScript("auchindoun_azzakel_at_fel_spark") {}

    enum eFelSparkSpells
    {
        SpellFelSparkDebuffDmg = 153726
    };

    uint32 m_Diff = 1 * TimeConstants::IN_MILLISECONDS;

    void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
    {
        if (m_Diff <= p_Time)
        {
            std::list<Player*> l_ListPlayers;
            p_AreaTrigger->GetPlayerListInGrid(l_ListPlayers, 2.0f);
            // p_AreaTrigger->VisitNearbyObject(2.0f, searcher);
            if (!l_ListPlayers.empty())
            {
                for (std::list<Player*>::const_iterator l_Itr = l_ListPlayers.begin(); l_Itr != l_ListPlayers.end(); ++l_Itr)
                {
                    if (!(*l_Itr))
                        continue;

                    if (!(*l_Itr)->HasAura(eFelSparkSpells::SpellFelSparkDebuffDmg))
                        (*l_Itr)->AddAura(eFelSparkSpells::SpellFelSparkDebuffDmg, (*l_Itr));
                }
            }

            m_Diff = 1 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_Diff -= p_Time;
    }
    /*
    auchindoun_azzakel_at_fel_spark* GetAI()
    {
    return nullptr;
    }*/
};

void AddSC_boss_azaakel()
{
    RegisterCreatureAI(boss_azaakel);
    RegisterCreatureAI(auchindoun_azzakel_mob_controller);   //76216
    new auchindoun_azzakel_mob_fel_spark_trigger(); //326527
    new auchindoun_azzakel_mob_fel_pool();          //326526
    new auchindoun_azzakel_spell_curtain_flames();  //153392
    new auchindoun_azzakel_spell_claws_of_argus();  //153764
    new auchindoun_azzakel_at_fel_spark();          //153725
}
