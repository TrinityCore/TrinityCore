#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "auchindoun.h"

enum eEmotes
{
    EMOTE_HELLO_NYAMI = 3,
};

Position const g_PositionKaatharCrystalPosition = { 1909.75f, 3188.70f, 66.786f, 5.401960f };

enum eventTuulaniIntro
{
    EVENT_TUULANI_INTRO_1 = 3000,
    EVENT_TUULANI_INTRO_2,
    EVENT_TUULANI_INTRO_3,
    EVENT_TUULANI_INTRO_4,
    EVENT_TUULANI_INTRO_5,
    EVENT_TUULANI_INTRO_6,
    EVENT_TUULANI_INTRO_7,
    EVENT_TUULANI_INTRO_8,
    EVENT_TUULANI_INTRO_9,
    EVENT_TUULANI_INTRO_10,
    EVENT_TUULANI_INTRO_11,
    EVENT_TUULANI_INTRO_12,
    EVENT_TUULANI_INTRO_13,
    EVENT_TUULANI_INTRO_14,
    EVENT_TUULANI_INTRO_15,
    EVENT_TUULANI_INTRO_16,
    EVENT_TUULANI_INTRO_17,
    EVENT_TUULANI_INTRO_18,
    EVENT_TUULANI_INTRO_19,
};

/// Tuulani - 79248
struct auchindoun_mob_tuulani : public ScriptedAI
{
    auchindoun_mob_tuulani(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = p_Creature->GetInstanceScript();
        m_First = true;
    }

    EventMap events;
    InstanceScript* m_Instance;
    bool m_First;
    uint32 m_FirstDiff;

    void Reset() override
    {
        events.Reset();
        m_First = false;
        me->SetFaction(FriendlyFaction);
        Talk(eAuchindounTalks::TUULANITALK1);
        me->SetSpeed(UnitMoveType::MOVE_RUN, 12.0f);
        me->SetSpeed(UnitMoveType::MOVE_WALK, 1.2f);
        me->SetWalk(false);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC));

        //  AddTimedDelayedOperatio(4 * TimeConstants::IN_MILLISECONDS, [this]() -> void
        // {  //??????
        me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani01, g_PositionTuulaniMovements[0]);
        //  });  
    }

    void UpdateAI(uint32 p_Diff) override
    {
        events.Update(p_Diff);
        // UpdateOperations(p_Diff);//????
        switch (events.ExecuteEvent())
        {
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_1:
            if (Creature* l_Nyami = me->FindNearestCreature(NPC_NYAMI,1000.0f,true))
            {
                l_Nyami->SetReactState(ReactStates::REACT_PASSIVE);
                l_Nyami->AddAura(eAuchindounSpells::SpellDarkFire, l_Nyami);
                l_Nyami->CastSpell(l_Nyami, eAuchindounSpells::SpellPrisonAura);
                l_Nyami->AddAura(eAuchindounSpells::SpellLevitateNyami, l_Nyami);
                l_Nyami->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                if (Creature* l_Trigger = l_Nyami->FindNearestCreature(eAuchindounCreatures::CreatureLeftCrystalTrigger, 40.0f, true))
                {
                    l_Trigger->AddAura(eAuchindounSpells::SpellVoidFormTriggerBuff, l_Trigger);
                    l_Nyami->CastSpell(l_Trigger, eAuchindounSpells::SpellShadowBeam);
                }
            }
            Talk(eAuchindounTalks::TUULANITALK1);
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani02, g_PositionTuulaniMovements[1]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_2:
            Talk(eAuchindounTalks::TUULANITALK3);
            me->CastSpell(me, eAuchindounSpells::SpellTuulaniUnlock);
            AddTimedDelayedOperation(2500, [this]() -> void
            {
                if (GameObject* door = me->FindNearestGameObject(GameobjectDoorBarrier, 100.0f))
                    door->Delete();
                me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani03, g_PositionTuulaniMovements[2]);
            });           
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_3:
            if (Creature* l_Guard = me->FindNearestCreature(CreatureAucheniDefender, 50.0f, true))
            {
                l_Guard->SetFacingToObject(me);
                l_Guard->RemoveAura(eAuchindounSpells::SpellKneel);
                l_Guard->AI()->Talk(eAuchindounTalks::AUCHENAIDEFENDERTALK1);
            }
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_4, 7 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_4:
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani04, g_PositionTuulaniMovements[4]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_5:
            Talk(eAuchindounTalks::TUULANITALK4);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_6, 4 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_6:
            me->CastSpell(me, eAuchindounSpells::SpellTuulaniUnlock);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_7, 7 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_7:
            if (GameObject* l_NearestHolyWall = me->FindNearestGameObject(eAuchindounObjects::GameobjectHolyWall, 60.0f))
                l_NearestHolyWall->Delete();
            Talk(eAuchindounTalks::TUULANITALK18);
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani05, g_PositionTuulaniMovements[5]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_8:
            Talk(eAuchindounTalks::TUULANITALK5);
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani06, g_PositionTuulaniMovements[6]);               
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_9:
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani07, g_PositionTuulaniMovements[7]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_10:
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani08, g_PositionTuulaniMovements[8]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_11:
            if (instance)
            {
                instance->DoNearTeleportPlayers(me->GetPosition());
                instance->DoPlayScenePackageIdOnPlayers(SpellAuchindounSceneTulaaniReachNyami);
            }
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani09, g_PositionTuulaniMovements[9]);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_12, 5 * TimeConstants::IN_MILLISECONDS);
            //events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_14, 12 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_12:
            me->GetMotionMaster()->MovePoint(eAuchindounMovementInforms::MovementInformTuulani10, g_PositionTuulaniMovements[10]);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_13:
            Talk(eAuchindounTalks::TUULANITALK7);
            me->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            me->AddAura(eAuchindounSpells::SpellTuulaniCapturedVoidPrison, me);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            me->AddUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_15, 7 * TimeConstants::IN_MILLISECONDS);
            //l_Tuulina->m_Events.AddEvent(new EventTuulaniIntroduction(l_Tuulina, 15, m_InstanceScript), l_Tuulina->m_Events.CalculateTime(7 * TimeConstants::IN_MILLISECONDS));14
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_14:
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_15:
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 200.0f, true))
            {
                l_Nyami->SetReactState(ReactStates::REACT_PASSIVE);
                l_Nyami->AddAura(eAuchindounSpells::SpellDarkFire, l_Nyami);
                l_Nyami->CastSpell(l_Nyami, eAuchindounSpells::SpellPrisonAura);
                l_Nyami->AddAura(eAuchindounSpells::SpellLevitateNyami, l_Nyami);
                l_Nyami->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC));
                if (Creature* l_Trigger = l_Nyami->FindNearestCreature(eAuchindounCreatures::CreatureSoulAegis, 40.0f, true))
                {
                    l_Trigger->AddAura(eAuchindounSpells::SpellVoidFormTriggerBuff, l_Trigger);
                    l_Nyami->CastSpell(l_Trigger, eAuchindounSpells::SpellVoidBeam);
                }
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK2);
            }               
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_16, 9 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_16:
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 200.0f, true))
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK3);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_17, 9 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_17:
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 200.0f, true))
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK4);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_18, 9 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_18:
            Talk(eAuchindounTalks::TUULANITALK8);
            events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_19, 9 * TimeConstants::IN_MILLISECONDS);
            break;
        case eventTuulaniIntro::EVENT_TUULANI_INTRO_19:
            if (Creature* l_Nyami = me->FindNearestCreature(CreatureSoulBinderNyami, 200.0f, true))
                l_Nyami->AI()->Talk(eAuchindounTalks::NYAMITALK5);
            break;
        default:
            break;
        }
    }

    void MovementInform(uint32 /*p_Type*/, uint32 p_Id)
    {
        if (instance)
        {
            switch (p_Id)
            {
            case eAuchindounMovementInforms::MovementInformTuulani01:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_1, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani02:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_2, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani03:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_3, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani04:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_5, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani05:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_8, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani06:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_9, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani07:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_10, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani08:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_11, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani09:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_12, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            case eAuchindounMovementInforms::MovementInformTuulani10:
                events.ScheduleEvent(eventTuulaniIntro::EVENT_TUULANI_INTRO_13, 1 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }
    }
};

/// Sargerei Soulbinder - 77812
struct auchindoun_mob_sargerei_soulbinder : public ScriptedAI
{
    auchindoun_mob_sargerei_soulbinder(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiSoulbinderEvents
    {
        EventMindShear = 1,
        EventBendWill
    };

    enum eSargereiSoulbinderSpells
    {
        SpellVoidShell = 160312,
        SpellBendWill = 154527
    };

    EventMap events;
    InstanceScript* m_Instance;

    void Reset()
    {
        events.Reset();
        if (Creature* target = me->FindNearestCreature(CreatureSoulAegis, 50.0f))
            me->CastSpell(target, SpellVoidBeam, true);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSargereiSoulbinderEvents::EventMindShear, 8 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eSargereiSoulbinderEvents::EventBendWill, 18 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance)
        {
            if (Creature* l_Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (l_Kaathar->IsAlive() && l_Kaathar->IsAIEnabled)
                    l_Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiSoulbinderEvents::EventMindShear:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eSargereiSoulbinderSpells::SpellVoidShell);
            events.ScheduleEvent(eSargereiSoulbinderEvents::EventBendWill, 8 * TimeConstants::IN_MILLISECONDS);
            break;
        case eSargereiSoulbinderEvents::EventBendWill:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eSargereiSoulbinderSpells::SpellBendWill);
            events.ScheduleEvent(eSargereiSoulbinderEvents::EventBendWill, 18 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Cleric - 77134
struct auchindoun_mob_sargerei_cleric : public ScriptedAI
{
    auchindoun_mob_sargerei_cleric(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiClericEvents
    {
        EventVoidShell = 1
    };

    enum eSargereiCleircSpells
    {
        SpellVoidShell = 160312
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        if (Creature* target = me->FindNearestCreature(CreatureSoulAegis, 50.0f))
            me->CastSpell(target, SpellVoidBeam, true);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSargereiClericEvents::EventVoidShell, 15 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance)
        {
            if (Creature* l_Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (l_Kaathar->IsAlive() && l_Kaathar->IsAIEnabled)
                    l_Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiClericEvents::EventVoidShell:
            me->CastSpell(me, eSargereiCleircSpells::SpellVoidShell);
            events.ScheduleEvent(eSargereiClericEvents::EventVoidShell, urand(12 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Ritualist - 77130
struct auchindoun_mob_sargerei_ritualist : public ScriptedAI
{
    auchindoun_mob_sargerei_ritualist(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiRitualistEvents
    {
        EventMindSpike = 1
    };

    enum eSargereiRitualistSpells
    {
        SpellShadowBeam = 156862,
        SpellDarkFire = 156955,
        SpellMindSpike = 157043
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();

        if (Creature* l_Trigger = me->SummonCreature(eAuchindounCreatures::CreatureShadowBeam, g_PositionKaatharCrystalPosition, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN))
            me->CastSpell(l_Trigger, eSargereiRitualistSpells::SpellShadowBeam);

        me->AddAura(eSargereiRitualistSpells::SpellDarkFire, me);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        me->CastStop();
        me->RemoveAllAuras();
        events.ScheduleEvent(eSargereiRitualistEvents::EventMindSpike, urand(6 * TimeConstants::IN_MILLISECONDS, 8 * TimeConstants::IN_MILLISECONDS));
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (l_Kaathar->IsAlive() && l_Kaathar->IsAIEnabled)
                    l_Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiRitualistEvents::EventMindSpike:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eSargereiRitualistSpells::SpellMindSpike);
            events.ScheduleEvent(eSargereiRitualistEvents::EventMindSpike, 6 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }
    }
};

/// Sargerei Zealot - 77132
struct auchindoun_mob_sargerei_zealot : public ScriptedAI
{
    auchindoun_mob_sargerei_zealot(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiZealotSpells
    {
        SpellSeverTendonAura = 157165
    };

    enum eSargereiZealotEvents
    {
        EventSeverTendom = 1
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eAuchindounEvents::EventSeverTendom, 5 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (Kaathar->IsAlive() && Kaathar->IsAIEnabled)
                    Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eAuchindounEvents::EventSeverTendom:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Target, eAuchindounSpells::SpellSeverTendonAura);
            events.ScheduleEvent(eAuchindounEvents::EventSeverTendom, urand(9 * TimeConstants::IN_MILLISECONDS, 14 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Spirit Tender - 77131
struct auchindoun_mob_sargerei_spirit_tender : public ScriptedAI
{
    auchindoun_mob_sargerei_spirit_tender(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSpiritTenderSpells
    {
        SpellVoidMendingDummy = 154623,
        SpellVoidShiftDummy = 155524
    };

    enum eSpiritTenderEvents
    {
        EventVoidMending = 1,
        EventVoidShift
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        if (Creature* target = me->FindNearestCreature(CreatureSoulAegis, 50.0f))
            me->CastSpell(target, SpellVoidBeam, true);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSpiritTenderEvents::EventVoidMending, 10 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eSpiritTenderEvents::EventVoidShift, 16 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (l_Kaathar->IsAlive() && l_Kaathar->IsAIEnabled)
                    l_Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSpiritTenderEvents::EventVoidMending:
            if (Unit* l_FriendUnit = DoSelectLowestHpFriendly(85))
                me->CastSpell(l_FriendUnit, eSpiritTenderSpells::SpellVoidMendingDummy);
            events.ScheduleEvent(eSpiritTenderEvents::EventVoidMending, 10 * TimeConstants::IN_MILLISECONDS);
            break;
        case eSpiritTenderEvents::EventVoidShift:
            me->CastSpell(me, eSpiritTenderSpells::SpellVoidShiftDummy);
            events.ScheduleEvent(eSpiritTenderEvents::EventVoidShift, 16 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Hopilite - 77133
struct auchindoun_mob_sargerei_hopilite : public ScriptedAI
{
    auchindoun_mob_sargerei_hopilite(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiHopiliteSpells
    {
        SpellShieldBash = 157159,
        SpellVoidStrikes = 166749
    };

    enum eSargereiHopiliteEvents
    {
        EventShieldBash = 1,
        EventVoidStrikes
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSargereiHopiliteEvents::EventShieldBash, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eSargereiHopiliteEvents::EventVoidStrikes, 18 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Kaathar = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossKathaar)))
            {
                if (l_Kaathar->IsAlive() && l_Kaathar->IsAIEnabled)
                    l_Kaathar->AI()->DoAction(eAuchindounActions::ActionCountPre1StBossKill);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiHopiliteEvents::EventShieldBash:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eSargereiHopiliteSpells::SpellShieldBash);
            events.ScheduleEvent(eSargereiHopiliteEvents::EventShieldBash, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            break;
        case eSargereiHopiliteEvents::EventVoidStrikes:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eSargereiHopiliteSpells::SpellVoidStrikes);
            events.ScheduleEvent(eSargereiHopiliteEvents::EventVoidStrikes, 18 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Defender - 77042
struct auchindoun_mob_sargerei_defender : public ScriptedAI
{
    auchindoun_mob_sargerei_defender(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
        m_False = true;
    }

    enum eSargereiDefenderSpells
    {
        SpellAvengersShield = 165715,
        SpellCrusaderStirke = 176931
    };

    enum eSargereiDefenderEvents
    {
        EventAvengersShield = 1,
        EventCrusaderStirke
    };

    InstanceScript* m_Instance;
    EventMap events;
    bool m_False;

    void Reset()
    {
        events.Reset();

        if (m_False)
            m_False = false;
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSargereiDefenderEvents::EventAvengersShield, urand(10 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eSargereiDefenderEvents::EventCrusaderStirke, urand(5 * TimeConstants::IN_MILLISECONDS, 9 * TimeConstants::IN_MILLISECONDS));
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiDefenderEvents::EventAvengersShield:
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_FARTHEST, 0, 50.0f, true))
                me->CastSpell(l_Random, eSargereiDefenderSpells::SpellAvengersShield);
            events.ScheduleEvent(eSargereiDefenderEvents::EventAvengersShield, urand(10 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
            break;
        case eSargereiDefenderEvents::EventCrusaderStirke:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eSargereiDefenderSpells::SpellCrusaderStirke);
            events.ScheduleEvent(eSargereiDefenderEvents::EventCrusaderStirke, urand(5 * TimeConstants::IN_MILLISECONDS, 9 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Magus - 76263
struct auchindoun_mob_sargerei_magus : public ScriptedAI
{
    auchindoun_mob_sargerei_magus(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_False = true;
        m_Instance = me->GetInstanceScript();
    }

    enum eSargereiMagusSpells
    {
        SpellArcaneChanneling = 161383,
        SpellArcaneBombDummy = 157652,
        SpellArcaneBoltPeriod = 157505,
        SpellArcaneBoltProje = 157931
    };

    enum eSargereiMagusEvents
    {
        EventArcaneBomb = 1,
        EventArcaneBolt
    };

    InstanceScript* m_Instance;
    EventMap events;
    bool m_False;
    std::list<ObjectGuid> l_Prisoners;

    void Reset()
    {
        if (m_False)
            m_False = false;

        events.Reset();
        me->CastSpell(me, eSargereiMagusSpells::SpellArcaneChanneling);
    }

    void MovementInform(uint32 /*p_Type*/, uint32 p_Id)
    {
        switch (p_Id)
        {
        case eAuchindounMovementInforms::MovementInformFallMagusPrisoners:
            if (!l_Prisoners.empty())
            {
                for (ObjectGuid l_Itr : l_Prisoners)
                {
                    if (!l_Itr)
                        continue;

                    if (Creature* l_Mob = ObjectAccessor::GetCreature(*me, l_Itr))
                    {
                        l_Mob->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
                        l_Mob->AddUnitFlag(UnitFlags(UNIT_FLAG2_FEIGN_DEATH));
                        l_Mob->AddUnitFlag(UnitFlags(UNIT_DYNFLAG_DEAD));
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    void EnterCombat(Unit* p_Attacker)
    {
        me->RemoveAura(eSargereiMagusSpells::SpellArcaneChanneling);
        events.ScheduleEvent(eSargereiMagusEvents::EventArcaneBomb, 13 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eSargereiMagusEvents::EventArcaneBolt, 20 * TimeConstants::IN_MILLISECONDS);

        std::list<Creature*> l_mobsPrisoners;
        me->GetCreatureListWithEntryInGrid(l_mobsPrisoners, eAuchindounCreatures::CreatureAucheniSoulPriest, 20.0f);
        if (!l_mobsPrisoners.empty())
        {
            for (Creature* l_Itr : l_mobsPrisoners)
            {
                l_Itr->Kill(l_Itr);
                l_Itr->RemoveAllAuras();
                l_Itr->GetMotionMaster()->MoveFall(eAuchindounMovementInforms::MovementInformFallMagusPrisoners);
                l_Itr->DespawnOrUnsummon(1 * TimeConstants::IN_MILLISECONDS);
            }
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSargereiMagusEvents::EventArcaneBomb:
            me->CastSpell(me, eSargereiMagusSpells::SpellArcaneBombDummy);
            events.ScheduleEvent(eSargereiMagusEvents::EventArcaneBomb, 13 * TimeConstants::IN_MILLISECONDS);
            break;
        case eSargereiMagusEvents::EventArcaneBolt:
            me->CastSpell(me, eSargereiMagusSpells::SpellArcaneBoltPeriod);
            events.ScheduleEvent(eSargereiMagusEvents::EventArcaneBolt, 20 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Soul Priest - 76595
struct auchindoun_mob_soul_priest : public ScriptedAI
{
    auchindoun_mob_soul_priest(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
        m_False = true;
    }

    enum eSoulPriestSpells
    {
        SpellShadowWordPainPriest = 176518,
        SpellPsychicTerrorDummy = 154356
    };

    enum eSoulPriestEvents
    {
        EventShadowWordPainSoulPriest = 1,
        EventPsychicTerrors
    };

    InstanceScript* m_Instance;
    EventMap events;

    bool m_False;

    void Reset()
    {
        events.Reset();

        if (m_False)
        {
            m_False = false;
        }
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eSoulPriestEvents::EventPsychicTerrors, 15 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eSoulPriestEvents::EventShadowWordPainSoulPriest, urand(8 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eSoulPriestEvents::EventShadowWordPainSoulPriest:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true, -eAuchindounSpells::SpellShadowWordPainPriest))
                me->CastSpell(me, eSoulPriestSpells::SpellShadowWordPainPriest);
            events.ScheduleEvent(eSoulPriestEvents::EventShadowWordPainSoulPriest, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            break;
        case eSoulPriestEvents::EventPsychicTerrors:
            if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
                me->CastSpell(l_Target, eSoulPriestSpells::SpellPsychicTerrorDummy);
            events.ScheduleEvent(eSoulPriestEvents::EventPsychicTerrors, 15 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Sargerei Warden - 77935
struct auchindoun_mob_sargeri_warden : public ScriptedAI
{
    auchindoun_mob_sargeri_warden(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
        m_False = true;
    }

    enum eWardenSpells
    {
        SpellWardenThrowHammer = 154730,
        SpellWardenChainDot = 154831
    };

    enum eWardenEvents
    {
        EventWardenHammer = 1,
        EventWardenChain
    };

    InstanceScript* m_Instance;
    EventMap events;
    bool m_False;

    void Reset()
    {
        events.Reset();

        if (m_False)
            m_False = false;
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eWardenEvents::EventWardenChain, 5 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eWardenEvents::EventWardenHammer, urand(12 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eWardenEvents::EventWardenHammer:
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eWardenSpells::SpellWardenThrowHammer);
            events.ScheduleEvent(eWardenEvents::EventWardenHammer, urand(12 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
            break;
        case eWardenEvents::EventWardenChain:
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eWardenSpells::SpellWardenChainDot);
            events.ScheduleEvent(eWardenEvents::EventWardenChain, 20 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Felborne Abyssal - 77905
struct auchindoun_mob_felborne_abyssal : public ScriptedAI
{
    auchindoun_mob_felborne_abyssal(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eFelborneAbyssalSpells
    {
        SpellFixate = 157168
    };

    enum eFelborneAbyssalEvents
    {
        EventFixate = 1
    };

    InstanceScript* m_Instance;
    EventMap events;
    bool m_Fixated;
    ObjectGuid m_FixatedTargetGUID;

    void Reset()
    {
        events.Reset();
        m_Fixated = false;
        m_FixatedTargetGUID = ObjectGuid::Empty;
        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eFelborneAbyssalEvents::EventFixate, urand(16 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eAuchindounActions::ActionDeactivateFixation:
            m_Fixated = false;
            break;
        default:
            break;
        }
    }

    void OnAddThreat(Unit* p_Victim, float& p_fThreat, SpellSchoolMask /*p_SchoolMask*/, SpellInfo const /*p_ThreatSpell*/)
    {
        if (m_Fixated)
            p_fThreat = 0;
        return;
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        if (m_Fixated)
        {
            if (!m_FixatedTargetGUID)//???
            {
                if (Unit* l_Target = ObjectAccessor::GetUnit(*me, m_FixatedTargetGUID))
                    me->AddThreat(l_Target, 500.0f);
            }
        }

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eAuchindounEvents::EventFixate:
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                m_Fixated = true;
                m_FixatedTargetGUID = l_Random->GetGUID();
                me->CastSpell(l_Random, eFelborneAbyssalSpells::SpellFixate);
            }

            events.ScheduleEvent(eFelborneAbyssalEvents::EventFixate, urand(16 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Cackling Pyrmoaniac - 76260
struct auchindoun_mob_cackling_pyromaniac : public ScriptedAI
{
    auchindoun_mob_cackling_pyromaniac(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eCacklingPyromaniacSpells
    {
        SpellFelBlast = 174422,
        SpellAbyssalVisual = 159610
    };

    enum eCacklingPyromaniacEvents
    {
        EventFelBlast = 1
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        me->CastSpell(me, eCacklingPyromaniacSpells::SpellAbyssalVisual);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eCacklingPyromaniacEvents::EventFelBlast, 6 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Azzakel = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossAzzakael)))
                if (l_Azzakel->IsInCombat() && l_Azzakel->IsAlive() && l_Azzakel->IsAIEnabled)
                    l_Azzakel->GetAI()->DoAction(eAuchindounActions::ActionDemonSoulsAchievement);

            if (Creature* l_Trigger = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataTriggerAzzakelController)))
                if (l_Trigger->IsWithinDistInMap(me, 30.0f) && l_Trigger->IsAIEnabled)
                    l_Trigger->AI()->DoAction(eAuchindounActions::ActionCountPre3StBossKill);
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eCacklingPyromaniacEvents::EventFelBlast:
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eCacklingPyromaniacSpells::SpellFelBlast);
            events.ScheduleEvent(eCacklingPyromaniacEvents::EventFelBlast, 6 * TimeConstants::IN_MILLISECONDS);
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Blazing Trickster - 79511, 79510
struct auchindoun_mob_blazing_trickster : public ScriptedAI
{
    auchindoun_mob_blazing_trickster(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eBlazingTricksterSpells
    {
        SpellConfligirate = 154981
    };

    enum eBlazingTricksterEvents
    {
        EventConfligrate = 1
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
        me->SetDefaultMovementType(MovementGeneratorType::RANDOM_MOTION_TYPE);
        events.ScheduleEvent(eBlazingTricksterEvents::EventConfligrate, urand(8 * TimeConstants::IN_MILLISECONDS, 15 * TimeConstants::IN_MILLISECONDS));
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Azzakel = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossAzzakael)))
                if (l_Azzakel->IsInCombat() && l_Azzakel->IsAlive() && l_Azzakel->IsAIEnabled)
                    l_Azzakel->GetAI()->DoAction(eAuchindounActions::ActionDemonSoulsAchievement);
        }
        if (me->GetEntry() == 79510)
            if (Creature* Azzakel_control = me->FindNearestCreature(87218, 50.0f, true))
                Azzakel_control->AI()->DoAction(2);
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eBlazingTricksterEvents::EventConfligrate:
            me->CastSpell(me, eBlazingTricksterSpells::SpellConfligirate);
            events.ScheduleEvent(eBlazingTricksterEvents::EventConfligrate, urand(8 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Felguard - 76259
struct auchindoun_mob_felguard : public ScriptedAI
{
    auchindoun_mob_felguard(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eFelguardSpells
    {
        SpellFelStomp = 157173
    };

    enum eFelguardEvents
    {
        EventFelStomp = 1
    };

    InstanceScript* m_Instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        me->SetReactState(ReactStates::REACT_AGGRESSIVE);
    }

    void EnterCombat(Unit* p_Attacker)
    {
        events.ScheduleEvent(eFelguardEvents::EventFelStomp, 10 * TimeConstants::IN_MILLISECONDS);
    }

    void JustDied(Unit* /*p_Killer*/)
    {
        if (m_Instance != nullptr)
        {
            if (Creature* l_Azzakel = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataBossAzzakael)))
                if (l_Azzakel->IsInCombat() && l_Azzakel->IsAlive() && l_Azzakel->IsAIEnabled)
                    l_Azzakel->GetAI()->DoAction(eAuchindounActions::ActionDemonSoulsAchievement);

            if (Creature* l_Trigger = m_Instance->instance->GetCreature(m_Instance->GetGuidData(eAuchindounDatas::DataTriggerAzzakelController)))
                if (l_Trigger->IsWithinDistInMap(me, 30.0f) && l_Trigger->IsAIEnabled)
                    l_Trigger->AI()->DoAction(eAuchindounActions::ActionCountPre3StBossKill);
        }
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(p_Diff);

        if (me->HasUnitState(UnitState::UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
        case eFelguardEvents::EventFelStomp:
            me->CastSpell(me, eFelguardSpells::SpellFelStomp);
            events.ScheduleEvent(eFelguardEvents::EventFelStomp, urand(12 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
            break;
        default:
            break;
        }

        DoMeleeAttackIfReady();
    }
};

/// Warden Hammer - 76655
struct auchindoun_mob_warden_hammer : public ScriptedAI
{
    auchindoun_mob_warden_hammer(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_Instance = me->GetInstanceScript();
    }

    enum eWardenHammerSpells
    {
        SpellWardenHammerLightningVisual = 154775,
        SpellWardenHammerDamage = 154773
    };

    InstanceScript* m_Instance;
    uint32 m_DiffHammer;

    void Reset()
    {
        me->SetFaction(HostileFaction);
        m_DiffHammer = 1 * TimeConstants::IN_MILLISECONDS;
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
    }

    void UpdateAI(uint32 p_Diff) override
    {
        if (m_DiffHammer <= p_Diff)
        {
            std::list<Player*> l_ListNerbyPlayers;
            me->GetPlayerListInGrid(l_ListNerbyPlayers, 3.0f);
            if (!l_ListNerbyPlayers.empty())
            {
                for (Player* l_Itr : l_ListNerbyPlayers)
                {
                    if (!l_Itr)
                        continue;

                    if (l_Itr && l_Itr->IsInWorld())
                    {
                        me->CastSpell(l_Itr, eWardenHammerSpells::SpellWardenHammerLightningVisual);
                        me->CastSpell(l_Itr, eWardenHammerSpells::SpellWardenHammerDamage);
                    }
                }
            }

            m_DiffHammer = 1 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_DiffHammer -= p_Diff;
    }
};

/// Void Mending - 154623 
class auchindoun_spell_void_mending : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_void_mending);

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (Unit* l_Caster = GetCaster())
        {
            if (Unit* l_Target = GetHitUnit())
                l_Caster->AddAura(eAuchindounSpells::SpellVoidMendingAura, l_Target);
        }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(auchindoun_spell_void_mending::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
    }
};

/// Psychic Terrors - 154356  
class auchindoun_spell_psychic_terror : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_psychic_terror);

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (Unit* l_Caster = GetCaster())
        {
            if (Unit* l_Target = GetHitUnit())
            {
                std::list<Player*> l_ListPlayers;
                l_Caster->GetPlayerListInGrid(l_ListPlayers, 4.0f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        l_Itr->AddAura(eAuchindounSpells::SpellPsychicTerrorFear, l_Itr);
                    }
                }
            }
        }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(auchindoun_spell_psychic_terror::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
    }
};

/// Warden's Chain - 154683 
class auchindoun_spell_warden_chain : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_warden_chain);

    enum eWardenChainSpells
    {
        SpellWardenChainJump = 154639,
        SpellWardenChainDot = 154831
    };

    void HandleDummy(SpellEffIndex /*p_EffIndex*/)
    {
        if (Unit* l_Caster = GetCaster())
        {
            if (Unit* l_Target = GetExplTargetUnit())
            {
                l_Caster->AddAura(eWardenChainSpells::SpellWardenChainJump, l_Target);
                l_Caster->AddAura(eWardenChainSpells::SpellWardenChainDot, l_Target);
            }
        }
    }

    void Register()
    {
        OnEffectHitTarget += SpellEffectFn(auchindoun_spell_warden_chain::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
    }
};

/// Warden Chain Aura - 154831 
class auchindoun_warden_chain_aura : public AuraScript
{
    PrepareAuraScript(auchindoun_warden_chain_aura);

    enum eWardenChainAuras
    {
        SpellWardenChainRoot = 154263
    };

    void HandlePeriodic(AuraEffect const* p_AurEff)
    {
        if (Unit* l_Target = GetTarget())
            l_Target->AddAura(eWardenChainAuras::SpellWardenChainRoot, l_Target);
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_warden_chain_aura::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
    }
};

/// Void Shift - 155524
class auchindoun_spell_void_shift : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_void_shift);

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (!GetCaster())
            return;

        Unit* l_Caster = GetCaster();
        int32 l_CalcDamage = 8000;

        std::list<Creature*> l_ListPlayers;
        l_Caster->GetCreatureListInGrid(l_ListPlayers, 30.0f);
        //l_Caster->GetPlayerListInGrid(l_ListPlayers, 30.0f);
        //l_Caster->VisitNearbyObject(30.0f, searcher);
        if (!l_ListPlayers.empty())
        {
            for (std::list<Creature*>::const_iterator l_It = l_ListPlayers.begin(); l_It != l_ListPlayers.end(); ++l_It)
            {
                if (!(*l_It))
                    continue;

                if ((*l_It)->GetTypeId() == TypeID::TYPEID_PLAYER)
                    GetCaster()->CastCustomSpell((*l_It), eAuchindounSpells::SpellVoidShiftDamage, &l_CalcDamage, NULL, NULL, true, NULL);
                else
                    GetCaster()->CastCustomSpell((*l_It), eAuchindounSpells::SpellVoidShiftHeal, &l_CalcDamage, NULL, NULL, true, NULL);
            }
        }
    }

    void Register()
    {
        OnEffectLaunch += SpellEffectFn(auchindoun_spell_void_shift::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
    }
};

/// Void Shell - 160312
class auchindoun_spell_void_shell_filter : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_void_shell_filter);

    void CorrectTargets(std::list<WorldObject*>& p_Targets)
    {
        p_Targets.clear();

        if (!GetCaster())
            return;

        Unit* l_Caster = GetCaster();

        std::list<Creature*> l_TargetList;
        l_Caster->GetCreatureListInGrid(l_TargetList, 10.0f);
        // l_Caster->VisitNearbyObject(10.0f, searcher);
        if (!l_TargetList.empty())
        {
            for (Creature* l_Itr : l_TargetList)
            {
                if (!l_Itr)
                    continue;

                if (l_Itr->GetTypeId() == TypeID::TYPEID_PLAYER)
                    continue;

                if (l_Itr && l_Itr->IsInWorld())
                    p_Targets.push_back(l_Itr);
            }
        }
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(auchindoun_spell_void_shell_filter::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_SRC_AREA_ALLY);
    }
};

/// Tuulani Unlock Gate - 160415
class auchindoun_spell_tuulani_unlock : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_tuulani_unlock);

    void CorrectTargets(std::list<WorldObject*>& p_Targets)
    {
        /// Clears all targets at start, fetching new ones
        p_Targets.clear();
        std::list<Creature*> l_ListTriggerWall;
        GetCaster()->GetCreatureListWithEntryInGrid(l_ListTriggerWall, eAuchindounCreatures::CreatureLightWallTargets, 15.0f);
        if (!l_ListTriggerWall.empty())
        {
            for (Creature* l_Itr : l_ListTriggerWall)
            {
                if (l_Itr && l_Itr->IsInWorld())
                    p_Targets.push_back(l_Itr->ToUnit());
            }
        }
    }

    void HandleAfterCast()
    {
        if (Unit* l_Caster = GetCaster())
        {
            if (GameObject * l_GameObject = l_Caster->FindNearestGameObject(eAuchindounObjects::GameobjectHolyBarrierEntra, 15.0f))
            {
                l_GameObject->Delete();
            }
        }
    }

    void Register()
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(auchindoun_spell_tuulani_unlock::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

/// Arcane Bolt - 157505 
class auchindoun_spell_arcane_bolt : public AuraScript
{
    PrepareAuraScript(auchindoun_spell_arcane_bolt);

    enum eArcaneBoltSpells
    {
        SpellArcaneBoltPeriod = 157505,
        SpellArcaneBoltProje = 157931
    };

    void HandlePeriodic(AuraEffect const* p_AurEff)
    {
        if (Unit* l_Caster = GetCaster())
        {
            if (l_Caster->IsAIEnabled)
            {
                if (Unit* l_Target = l_Caster->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    l_Caster->CastSpell(l_Target, eArcaneBoltSpells::SpellArcaneBoltProje, true);
            }
        }
    }

    void Register()
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(auchindoun_spell_arcane_bolt::HandlePeriodic, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DUMMY);
    }
};

/// Arcane Bomb - 157793 
class auchindoun_at_arcane_bomb : public AreaTriggerEntityScript
{
public:

    auchindoun_at_arcane_bomb() : AreaTriggerEntityScript("auchindoun_at_arcane_bomb")
    {
    }

    enum eArcaneBombSpells
    {
        SpellArcaneBombDamage = 157792
    };

    bool m_Used = false;
    uint32 m_Diff = 1 * TimeConstants::IN_MILLISECONDS;
    std::list<ObjectGuid> m_Targets;

    void OnUpdate(Player* Player, uint32 p_Time)
    {
        if (m_Diff <= p_Time)
        {
            if (!m_Used)
            {
                // if (Player* l_Nearest = p_AreaTrigger->FindNearestPlayer(1.0f, true))
                //  {
                m_Used = true;
                // Player->Remove();
                Player->CastSpell(Player, eArcaneBombSpells::SpellArcaneBombDamage);
                //}
            }

            m_Diff = 2 * TimeConstants::IN_MILLISECONDS;
        }
        else
            m_Diff -= p_Time;
    }
    /*
    auchindoun_at_arcane_bomb* GetAI()
    {
    return nullptr;
    }*/
};

/// Talador Portal - 236689
class auchindoun_gob_talador_portal : public GameObjectScript
{
public:

    auchindoun_gob_talador_portal() : GameObjectScript("auchindoun_gob_talador_portal") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gameobject) override
    {
        p_Player->TeleportTo(1116, 1488.52f, 3077.65f, 108.920f, 4.653427f);
        return true;
    }
};

/// 156920/void-beam
class auchindoun_spell_void_beam : public SpellScript
{
    PrepareSpellScript(auchindoun_spell_void_beam);
    /*
    void CorrectTargets(std::list<WorldObject*>& p_Targets)
    {
        p_Targets.clear();
        std::list<Creature*> l_ListTriggerWall;
        GetCaster()->GetCreatureListWithEntryInGrid(l_ListTriggerWall, eAuchindounCreatures::CreatureSoulAegis, 50.0f);
        if (!l_ListTriggerWall.empty())
        {
            for (Creature* l_Itr : l_ListTriggerWall)
            {
                if (l_Itr && l_Itr->IsInWorld())
                    p_Targets.push_back(l_Itr->ToUnit());
            }
        }
    }
    */
    void CheckTarget(WorldObject*& target)
    {
        if (target->GetEntry() != CreatureSoulAegis)
            target = target->FindNearestCreature(CreatureSoulAegis, 50.0f);
    }

    void Register() override
    {
        //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(auchindoun_spell_void_beam::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_NEARBY_ENTRY);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(auchindoun_spell_void_beam::CheckTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
    }
};

void AddSC_auchindoun()
{
    RegisterCreatureAI(auchindoun_mob_tuulani);                   ///< 79248
    RegisterCreatureAI(auchindoun_mob_sargerei_soulbinder);       ///< 77812  
    RegisterCreatureAI(auchindoun_mob_sargerei_cleric);           ///< 77134
    RegisterCreatureAI(auchindoun_mob_sargerei_ritualist);        ///< 77130
    RegisterCreatureAI(auchindoun_mob_sargerei_zealot);           ///< 77132
    RegisterCreatureAI(auchindoun_mob_sargerei_spirit_tender);    ///< 77131
    RegisterCreatureAI(auchindoun_mob_sargerei_hopilite);         ///< 77133
    RegisterCreatureAI(auchindoun_mob_sargeri_warden);            ///< 77935
    RegisterCreatureAI(auchindoun_mob_sargerei_magus);            ///< 76263
    RegisterCreatureAI(auchindoun_mob_sargerei_defender);         ///< 77042
    RegisterCreatureAI(auchindoun_mob_felborne_abyssal);          ///< 77905
    RegisterCreatureAI(auchindoun_mob_soul_priest);               ///< 76595
    RegisterCreatureAI(auchindoun_mob_felguard);                  ///< 76259
    RegisterCreatureAI(auchindoun_mob_cackling_pyromaniac);       ///< 76260
    RegisterCreatureAI(auchindoun_mob_blazing_trickster);         ///< 79511
    RegisterCreatureAI(auchindoun_mob_warden_hammer);             ///< 76655
    RegisterSpellScript(auchindoun_spell_void_shift);              ///< 155524
    RegisterSpellScript(auchindoun_spell_void_mending);            ///< 154623
    RegisterSpellScript(auchindoun_spell_void_shell_filter);       ///< 160312
    RegisterSpellScript(auchindoun_spell_psychic_terror);          ///< 154356
    RegisterSpellScript(auchindoun_spell_tuulani_unlock);          ///< 160415
    RegisterAuraScript(auchindoun_spell_arcane_bolt);             ///< 157505
    new auchindoun_at_arcane_bomb();                ///< 157793//???
    new auchindoun_gob_talador_portal();            ///< 236689
    RegisterAuraScript(auchindoun_warden_chain_aura);
    RegisterSpellScript(auchindoun_spell_void_beam);///156920
}
