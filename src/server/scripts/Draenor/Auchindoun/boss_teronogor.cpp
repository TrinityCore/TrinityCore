#include "ScriptMgr.h"
#include "GameObject.h"
#include "AreaTrigger.h"
#include "auchindoun.h"


enum eTerongorSpells
{
    SpellAgony = 156925,
    SpellChaosBolt = 156975,
    SpellChaosWaveDummy = 157001,
    SpellChaosWaveDmg = 157002,
    SpellConflagrate = 154083,
    SpellCorruptionDmg = 156842,
    SpellCurseOfExhaustionDebuff = 164841,
    SpellDemonicLeapDummy = 157039,
    SpellDemonicLeapAreatriger = 157040,
    SpellDoomBuff = 156965,
    SpellDrainLife = 156854,
    SpellImmolate = 156964,
    SpellIncinrate = 156963,
    SpellRainOfFire = 156974,
    SpellSeedOfMalevolenceApplyAura = 156921,
    SpellSeedOfMalevolenceBuff = 166451,
    SpellSeedOfMalevolenceDmg = 156924,
    SpellSeedOfMalevolenceVisualTriger = 166462,
    SpellShadowBolt = 156829,
    SpellTouchOfChaosDummy = 169028,
    SpellTouchOfChaosDmg = 156968,
    SpellUnstableAffliction = 156954,
    SpellWrathCleave = 159035,
    SpellWrathStorm = 159033,
    SpellTranscend = 164009,
    SpellAfflictionTransform = 156863,
    SpellDestructionTransform = 156866,
    SpellDemonologyTransform = 156919,
    SpellSummonAbyssalMeteor = 164508,
    SpellSummonAbyssalGroundEffect = 159681,
    SpellSummonAbyssalDummy = 157214,
    SpellSummonAbyssalSummonSpell = 157216,
    SpellDemonicCircleVisual = 149133,
    SpellTeronogorShield = 157017,
    SpellBrokenSouls = 72398,
    SpellSoulBarrage = 72305,
    SpellGuldenSoulVisual = 166453
};

enum eTerongorEvents
{
    EventAgony = 1,
    EventChaosBolt,
    EventChaosWave,
    EventConflagrate,
    EventCorruption,
    EventCurseOfExhaustion,
    EventDemonicLeap,
    EventDoom,
    EventDrainLife,
    EventImmolate,
    EventIncinrate,
    EventRainOfFire,
    EventSeedOfMalevolence,
    EventTouchOfChaos,
    EventUnstableAffliction,
    EventShadowBolt,
    EventWrathcleave,
    EventWrathstorm,
    EventBloomOfMalevolence,
    EventDepassive,
    EventTransform,
    EventTransformRemovePassive,
    TransformationPreChannel1,
    TransformationPreChannel2,
    TransformationPreChannel3,
    TransformationPreChannel4,
    TransformationPreChannel5,
    TransformationPreChannel6,
};

enum eTerongorTalks
{
    TERONGOR_INTRO_01 = 83255, ///< p_Who know the draenei held such...delicious treasure in their temple?  (44423)
    TERONGOR_INTRO_02 = 43, ///< Do you dare challenge me,defenders of Auchindoun?!(44424)
    TERONGOR_INTRO_03 = 44, ///< Such decadence...it will all burn. (44425)
    TERONGOR_INTRO_05 = 45, ///< Gul'dan, such foolshness. This gift...so much more you could ever know...(44427)
    TERONGOR_INTRO_06 = 46, ///< Long have i waited...(44428)
    TERONGOR_INTRO_07 = 47, ///< ...hungered... to be more... (44429)
    TERONGOR_INTRO_08 = 48, ///<  And now, all shall bow before me!(44430)
    TERONGOR_KILL_01 = 49, ///< All will fall before me!(44431)
    TERONGOR_AGGRO_01 = 0, ///< This power. you will be the first to know it.(44418)
    TERONGOR_SPELL_01 = 52, ///< Destruction!(44433)
    TERONGOR_SPELL_02 = 2, ///< Wither.. away! (44434)
    TERONGOR_SPELL_03 = 53, ///< I become something greater!(44435)
    TERONGOR_SPELL_04 = 54, ///< Die! (44436)
    TERONGOR_SPELL_05 = 55, ///< Your demise awaits! (44437)
    TERONGOR_SPELL_06 = 3, ///< Quickly now. (44438)
    TERONGOR_SPELL_07 = 57, ///< More! I...need...more!(44439)
    TERONGOR_EVENT_01 = 60, ///< Jorrun.. p_Who battle demons in life, in death.. your power will feed them! (44420)
    TERONGOR_EVENT_02 = 61, ///< Joraa, paragon of order - i shall twist your soul to power Destruction!(44421)
    TERONGOR_EVENT_03 = 1, ///< Elum, life time of healing... now, you shall fuel Deziz and Decay!(44422)
    TERONGOR_DEATH = 4 ///< (44419)
};

enum eTeronogorActions
{
    ActionTransport = 1,
    ActionChoosePower
};

enum eTeronogorCreatures
{
    TriggerSummonAbyssal = 213593
};

enum eTeronogorTransformations
{
    TransformationAffliction = 0,
    TransformationDestruction = 1,
    TransformationDemonology = 2,
    TransformationPreChannel = 3,
    TransformationOccur = 4,
    TransformationOccured = 5
};

enum eTeronogorMovements
{
    MovementBossDeathSceneStart = 1,
    MovementBossDeathSceneStage01,
    MovementBossDeathSceneEnd
};

Position const g_EndBossCinematicTeleport = { 1904.59f, 2982.96f, 16.844f };
Position const g_EndBossCinematicTeleportPreDespawn = { 1930.304f, 3056.913f, 33.249f };
Position const g_EndBossCinematicTeleportDespawn = { 1925.326f, 3043.384f, -53.435f };

struct boss_teronogor : public BossAI
{
    boss_teronogor(Creature* creature) : BossAI(creature, DATA_TERONOGOR) { Initialize(); }

    void Initialize()
    {
        m_Intro = false;
        m_First = false;
        m_Death = false;
    }

    bool m_Intro;
    bool m_First;
    bool m_SecondPhase;
    bool m_SoulTransport01;
    bool m_SoulTransport02;
    bool m_SoulTransport03;
    bool m_SoulTransport04;
    bool m_SoulTransport05;
    bool m_Death;

    void Reset() override
    {
        _Reset();

        events.Reset();
        m_SecondPhase = false;
        me->SetReactState(ReactStates::REACT_DEFENSIVE);

        if (!m_Death)
        {
            if (instance)
                if (Creature* l_Jorra = instance->GetCreature(eAuchindounDatas::DataIruun))
                    me->CastSpell(l_Jorra, eAuchindounSpells::SpellDrainSoulVisual);

            if (m_First)
            {
                m_First = false;

                m_SoulTransport01 = false;
                m_SoulTransport02 = false;
                m_SoulTransport03 = false;
                m_SoulTransport04 = false;
                m_SoulTransport05 = false;

                SetData(DataSoulTransport1, 0);
                SetData(DataSoulTransport2, 0);
                SetData(DataSoulTransport3, 0);
                SetData(DataSoulTransport4, 0);
         

                me->AddAura(eTerongorSpells::SpellTeronogorShield, me);
                me->CastSpell(me, eTerongorSpells::SpellDemonicCircleVisual);

                // me->GetMap()->SetObjectVisibility(1000.0f);
            }
        }
    }

    void JustReachedHome() override
    {
        summons.DespawnAll();
        DespawnCreaturesInArea(eAuchindounCreatures::CreatureFelborneAbyssal, me);

        if (instance)
            instance->SetBossState(eAuchindounDatas::DataBossTeronogor, EncounterState::FAIL);
    }

    void DamageTaken(Unit* p_Attacker, uint32 &p_Damage) override
    {
        if(me->HealthWillBeBelowPctDamaged(75, p_Damage) && !m_SecondPhase)
        {
            events.Reset();
            me->AttackStop();
            m_SecondPhase = true;
            me->SetReactState(ReactStates::REACT_PASSIVE);
            DoAction(eTeronogorActions::ActionChoosePower);
            me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_NON_ATTACKABLE));
        }
    }

    void DoAction(int32 p_Action)
    {
        switch (p_Action)
        {
        case eAuchindounActions::ActionSoulMove1:
            m_SoulTransport01 = true;
            SetData(DataSoulTransport1, 1);
            break;
        case eAuchindounActions::ActionSoulMove2:
            m_SoulTransport02 = true;
            SetData(DataSoulTransport2, 1);
            break;
        case eAuchindounActions::ActionSoulMove3:
            m_SoulTransport03 = true;
            SetData(DataSoulTransport3, 1);
            break;
        case eAuchindounActions::ActionSoulMove4:
            m_SoulTransport04 = true;
            SetData(DataSoulTransport4, 1);
            break;
        case eTeronogorActions::ActionChoosePower:
        {
            events.Reset();

            switch (urand(eTeronogorTransformations::TransformationAffliction, eTeronogorTransformations::TransformationDemonology))
            {
            case eTeronogorTransformations::TransformationAffliction: // Mender Elum - Affliction
                events.Reset();
                Talk(eTerongorTalks::TERONGOR_EVENT_03);
                events.ScheduleEvent(eTerongorEvents::EventShadowBolt, urand(8 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventCurseOfExhaustion, 13 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventSeedOfMalevolence, urand(22 * TimeConstants::IN_MILLISECONDS, 25 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventAgony, 16 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventDrainLife, urand(13 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventUnstableAffliction, 20 * TimeConstants::IN_MILLISECONDS);             
                break;
            case eTeronogorTransformations::TransformationDestruction: // Arcanist Jorra's - destruction
                events.Reset();
                Talk(eTerongorTalks::TERONGOR_EVENT_01);
                events.ScheduleEvent(eTerongorEvents::EventChaosBolt, 20 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventImmolate, urand(10 * TimeConstants::IN_MILLISECONDS, 14 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventConflagrate, urand(8 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventRainOfFire, 24 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventIncinrate, 16 * TimeConstants::IN_MILLISECONDS);
                break;
            case eTeronogorTransformations::TransformationDemonology: // Vindication Iruun's - demonology
                events.Reset();
                Talk(eTerongorTalks::TERONGOR_EVENT_02);
                events.ScheduleEvent(eTerongorEvents::EventDoom, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventDemonicLeap, urand(10 * TimeConstants::IN_MILLISECONDS, 14 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventCurseOfExhaustion, 18 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventCorruption, urand(10 * TimeConstants::IN_MILLISECONDS, 14 * TimeConstants::IN_MILLISECONDS));
                events.ScheduleEvent(eTerongorEvents::EventChaosBolt, 25 * TimeConstants::IN_MILLISECONDS);
                events.ScheduleEvent(eTerongorEvents::EventTouchOfChaos, 16 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }
        default:
            break;
        }
    }

    void ScheduleTasks() override
    {
        me->CastStop();
        me->RemoveAllAuras();
        Talk(eTerongorTalks::TERONGOR_AGGRO_01);
        me->RemoveAura(eTerongorSpells::SpellTeronogorShield);
        events.ScheduleEvent(eTerongorEvents::EventShadowBolt, urand(8 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eTerongorEvents::EventCorruption, urand(10 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
        events.ScheduleEvent(eTerongorEvents::EventRainOfFire, 21 * TimeConstants::IN_MILLISECONDS);
        events.ScheduleEvent(eTerongorEvents::EventDrainLife, 16 * TimeConstants::IN_MILLISECONDS);

        if (instance)
        {
            instance->SendEncounterUnit(EncounterFrameType::ENCOUNTER_FRAME_ENGAGE, me);

            if (IsHeroic())
            {
                Position l_Position;
                me->GetRandomNearPosition(10.0f);
                me->SummonCreature(eTeronogorCreatures::TriggerSummonAbyssal, l_Position, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            }
        }
    }

    void KilledUnit(Unit* p_Who)
    {
        if (p_Who && p_Who->GetTypeId() == TypeID::TYPEID_PLAYER)
            Talk(eTerongorTalks::TERONGOR_KILL_01);
    }

    void MovementInform(uint32 p_Type, uint32 p_Id)
    {
        Position pos;
        switch (p_Id)
        {
        case eTeronogorMovements::MovementBossDeathSceneStart:
            if (Player* l_Nearest = me->SelectNearestPlayer(100.0f))
                me->SetFacingToObject(l_Nearest);

            /*
            l_Teronogor->AddAura(eTerongorSpells::SpellSoulBarrage, l_Teronogor);
            l_Teronogor->AddAura(eTerongorSpells::SpellBrokenSouls, l_Teronogor);
            */

            Talk(eTerongorTalks::TERONGOR_DEATH);

            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 0.7f);
            me->CastSpell(me, eTerongorSpells::SpellGuldenSoulVisual);

            pos.Relocate(me);
            pos.m_positionZ += 4.f;//?????
            me->GetMotionMaster()->MoveTakeoff(eTeronogorMovements::MovementBossDeathSceneStage01, pos);
            break;
        case eTeronogorMovements::MovementBossDeathSceneStage01:
            me->CastSpell(me, eTerongorSpells::SpellGuldenSoulVisual);

            me->SetSpeed(UnitMoveType::MOVE_FLIGHT_BACK, 15.0f);
            me->RemoveAura(eTerongorSpells::SpellGuldenSoulVisual);
            // me->GetMotionMaster()->MoveBackward(eTeronogorMovements::MovementBossDeathSceneEnd, g_EndBossCinematicTeleportPreDespawn.GetPositionX(), g_EndBossCinematicTeleportPreDespawn.GetPositionY(), g_EndBossCinematicTeleportPreDespawn.GetPositionZ(), 15.0F);
            break;
        case eTeronogorMovements::MovementBossDeathSceneEnd:
            me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 15.0f);
            me->DespawnOrUnsummon(10 * TimeConstants::IN_MILLISECONDS);
            // me->GetMotionMaster()->MoveBackward(1000, g_EndBossCinematicTeleportDespawn.GetPositionX(), g_EndBossCinematicTeleportDespawn.GetPositionY(), g_EndBossCinematicTeleportDespawn.GetPositionZ(), 15.0F);
            break;
        default:
            break;
        }
    }

    void JustDied(Unit* /*p_Killer*/) override
    {
        _JustDied();

        m_Death = true;

        DespawnCreaturesInArea(eAuchindounCreatures::CreatureFelborneAbyssal, me);
        if (instance)
            instance->SetBossState(eAuchindounDatas::DataBossTeronogor, EncounterState::DONE);

        me->SetFaction(FriendlyFaction);
        me->SetReactState(ReactStates::REACT_PASSIVE);
        me->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC));

        if (Player* l_Nearest = me->SelectNearestPlayer(100.0f))
            me->SetFacingToObject(l_Nearest);

        Talk(eTerongorTalks::TERONGOR_DEATH);

        me->SetSpeed(UnitMoveType::MOVE_FLIGHT, 0.7f);
        Position pos;
        pos.Relocate(me);
        pos.m_positionZ += 4.0f;//?????
        me->GetMotionMaster()->MoveTakeoff(eTeronogorMovements::MovementBossDeathSceneStage01, pos);

        me->SummonGameObject(eAuchindounObjects::GameobjectChestAucheni, 1891.84f, 2973.80f, 16.844f, 5.664811f, QuaternionData(0, 0, 0, 0), 0);
        me->SummonCreature(eAuchindounCreatures::CreatureSoulBinderTuulani01, 1911.65f, 2757.72f, 30.799f, 1.566535f, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case eTerongorEvents::EventShadowBolt:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellShadowBolt);

            events.ScheduleEvent(eTerongorEvents::EventShadowBolt, 6 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventCorruption:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true, -eTerongorSpells::SpellCorruptionDmg))
                me->CastSpell(l_Random, eTerongorSpells::SpellCorruptionDmg);

            events.ScheduleEvent(eTerongorEvents::EventCorruption, 9 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventDrainLife:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellDrainLife);

            events.ScheduleEvent(eTerongorEvents::EventDrainLife, 16 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventCurseOfExhaustion:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true, -eTerongorSpells::SpellCurseOfExhaustionDebuff))
                me->CastSpell(l_Random, eTerongorSpells::SpellCurseOfExhaustionDebuff);

            events.ScheduleEvent(eTerongorEvents::EventCurseOfExhaustion, 13 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventAgony:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellAgony);

            events.ScheduleEvent(eTerongorEvents::EventAgony, 16 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventUnstableAffliction:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true, -eTerongorSpells::SpellUnstableAffliction))
                me->CastSpell(l_Random, eTerongorSpells::SpellUnstableAffliction);

            events.ScheduleEvent(eTerongorEvents::EventUnstableAffliction, 20 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventSeedOfMalevolence:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellSeedOfMalevolenceApplyAura);

            events.ScheduleEvent(eTerongorEvents::EventSeedOfMalevolence, urand(22 * TimeConstants::IN_MILLISECONDS, 25 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        case eTerongorEvents::EventChaosBolt:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(me->GetVictim(), eTerongorSpells::SpellChaosBolt);

            events.ScheduleEvent(eTerongorEvents::EventChaosBolt, 20 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventImmolate:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellImmolate);

            events.ScheduleEvent(eTerongorEvents::EventImmolate, 12 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventConflagrate:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellConflagrate);

            events.ScheduleEvent(eTerongorEvents::EventConflagrate, urand(15 * TimeConstants::IN_MILLISECONDS, 20 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        case eTerongorEvents::EventIncinrate:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellIncinrate);

            events.ScheduleEvent(eTerongorEvents::EventIncinrate, 6 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::EventRainOfFire:
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellRainOfFire, true);

            events.ScheduleEvent(eTerongorEvents::EventRainOfFire, 10 * TimeConstants::IN_MILLISECONDS);
            break;
        case eTerongorEvents::EventDoom:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellDoomBuff);

            events.ScheduleEvent(eTerongorEvents::EventDoom, urand(8 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        case eTerongorEvents::EventDemonicLeap:
        {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                me->CastSpell(l_Random, eTerongorSpells::SpellDemonicLeapDummy);

            events.ScheduleEvent(eTerongorEvents::EventDemonicLeap, urand(18 * TimeConstants::IN_MILLISECONDS, 30 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        case eTerongorEvents::EventChaosWave:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellChaosWaveDummy);

            events.ScheduleEvent(eTerongorEvents::EventChaosWave, urand(8 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
            break;
        }
        case eTerongorEvents::EventTouchOfChaos:
        {
            if (Unit* l_Target = me->GetVictim())
                me->CastSpell(l_Target, eTerongorSpells::SpellTouchOfChaosDummy);

            events.ScheduleEvent(eTerongorEvents::EventTouchOfChaos, 16 * TimeConstants::IN_MILLISECONDS);
            break;
        }
        case eTerongorEvents::TransformationPreChannel1:
            if (Creature* l_Elum = instance->GetCreature(eAuchindounDatas::DataElum))
                me->CastSpell(l_Elum, eAuchindounSpells::SpellDrainSoulVisual);
            break;
        case eTerongorEvents::TransformationPreChannel2:
            if (Creature* l_Jorra = instance->GetCreature(eAuchindounDatas::DataJorra))
                me->CastSpell(l_Jorra, eAuchindounSpells::SpellDrainSoulVisual);
            break;
        case eTerongorEvents::TransformationPreChannel3:
            if (Creature* l_Iruun = instance->GetCreature(eAuchindounDatas::DataIruun))
                me->CastSpell(l_Iruun, eAuchindounSpells::SpellDrainSoulVisual);
            break;
        case eTerongorEvents::TransformationPreChannel4:
            DoCastTransformation(SpellAfflictionTransform);
            break;
        case eTerongorEvents::TransformationPreChannel5:
            DoCastTransformation(SpellDestructionTransform);
            break;
        case eTerongorEvents::TransformationPreChannel6:
            DoCastTransformation(SpellDemonologyTransform);
            break;
        default:
            break;
        }
    }

    void DoCastTransformation(uint32 spell)
    {
        me->RemoveAllAuras();
        me->CastStop();
        me->CastSpell(me, spell);
        if (me->IsAIEnabled)
        {
            if (Unit* l_Victim = me->GetAI()->SelectTarget(SelectAggroTarget::SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
                me->Attack(l_Victim, true);
        }
        me->UpdatePosition(*me);
        me->SetReactState(ReactStates::REACT_DEFENSIVE);
        me->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_NON_ATTACKABLE));
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who && who->IsPlayer() && me->IsWithinDist(who, 18.0f, false) && !m_Intro)
        {
            m_Intro = true;
            me->Yell(eTerongorTalks::TERONGOR_INTRO_01);
            who->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
        }
    }
};


/// Durag The Dominator <Shadow Council> - 77890
class auchindoun_teronogor_mob_durag : public CreatureScript
{
public:

    auchindoun_teronogor_mob_durag() : CreatureScript("auchindoun_teronogor_mob_durag") { }

    struct auchindoun_teronogor_mob_duragAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_duragAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = me->GetInstanceScript();
            m_First = true;
        }

        enum eTeronogorDuragSpells
        {
            GrimoireofServitude = 159021,
            SpellShadowBolt = 156829,
            SpellCorruptionDmg = 156842,
            SpellChaosWaveDummy = 157001
        };

        enum eTeronogorDuragEvents
        {
            EventShadowBolt = 1,
            EventCorruption,
            EventChaosWave
        };

        InstanceScript* m_Instance;
        EventMap events;
        bool m_First;

        void Reset()
        {
            events.Reset();
            //if (me->GetMap())//???
            //  me->GetMap()->SetObjectVisibility(1000.0f);

            /// Cosmetic channel - 
            if (Creature* l_Teronogor = me->FindNearestCreature(NPC_TERONOGOR, 1000.0f, true))
            {
                me->CastStop();
                me->CastSpell(l_Teronogor, eAuchindounSpells::SpellDrainSoulVisual);
            }

            me->SetReactState(ReactStates::REACT_DEFENSIVE);
        }

        void EnterCombat(Unit* p_Attacker)
        {
            me->CastStop();
            me->RemoveAllAuras();
            me->CastSpell(me, eTeronogorDuragSpells::GrimoireofServitude);
            events.ScheduleEvent(eTeronogorDuragEvents::EventShadowBolt, 6 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTeronogorDuragEvents::EventCorruption, 9 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTeronogorDuragEvents::EventChaosWave, 12 * TimeConstants::IN_MILLISECONDS);
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
            case eTeronogorDuragEvents::EventShadowBolt:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eTeronogorDuragSpells::SpellShadowBolt);
                events.ScheduleEvent(eTeronogorDuragEvents::EventShadowBolt, 6 * TimeConstants::IN_MILLISECONDS);
                break;
            case eTeronogorDuragEvents::EventCorruption:
                if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true, -eTerongorSpells::SpellCorruptionDmg))
                    me->CastSpell(l_Random, eTeronogorDuragSpells::SpellCorruptionDmg);
                events.ScheduleEvent(eTeronogorDuragEvents::EventCorruption, 9 * TimeConstants::IN_MILLISECONDS);
                break;
            case eTeronogorDuragEvents::EventChaosWave:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eTeronogorDuragSpells::SpellChaosWaveDummy);
                events.ScheduleEvent(eTeronogorDuragEvents::EventChaosWave, 20 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_duragAI(p_Creature);
    }
};

/// Gulkosh <Shadow Council> - 78437
class auchindoun_teronogor_mob_gulkosh : public CreatureScript
{
public:

    auchindoun_teronogor_mob_gulkosh() : CreatureScript("auchindoun_teronogor_mob_gulkosh") { }

    struct auchindoun_teronogor_mob_gulkoshAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_gulkoshAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = me->GetInstanceScript();
            m_First = true;
        }

        enum eTeronogorGulkoshSpells
        {
            SpellShadowBolt = 156829,
            SpellUnstableAffliction = 156954,
            SpellDrainLife = 156854
        };

        enum eTeronogorGulkoshEvents
        {
            EventShadowBolt = 1,
            EventUnstableAffliction,
            EventDrainLife
        };

        InstanceScript* m_Instance;
        EventMap events;
        bool m_First;

        void Reset()
        {
            events.Reset();

            //if (me->GetMap())//???
            // me->GetMap()->SetObjectVisibility(1000.0f);
            if (Creature* l_Teronogor = me->FindNearestCreature(NPC_TERONOGOR, 1000.0f, true))
            {
                me->CastStop();
                me->CastSpell(l_Teronogor, eAuchindounSpells::SpellDrainSoulVisual);
            }

            me->SetReactState(ReactStates::REACT_DEFENSIVE);
        }

        void EnterCombat(Unit* p_Attacker)
        {
            me->CastStop();
            me->RemoveAllAuras();
            events.ScheduleEvent(eTeronogorGulkoshEvents::EventShadowBolt, 6 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTeronogorGulkoshEvents::EventUnstableAffliction, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTeronogorGulkoshEvents::EventDrainLife, 10 * TimeConstants::IN_MILLISECONDS);
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
            case eTeronogorGulkoshEvents::EventShadowBolt:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eTeronogorGulkoshSpells::SpellShadowBolt);
                events.ScheduleEvent(eTeronogorGulkoshEvents::EventShadowBolt, 6 * TimeConstants::IN_MILLISECONDS);
                break;
            case eTeronogorGulkoshEvents::EventUnstableAffliction:
                if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(l_Random, eTeronogorGulkoshSpells::SpellUnstableAffliction);
                events.ScheduleEvent(eTeronogorGulkoshEvents::EventUnstableAffliction, 8 * TimeConstants::IN_MILLISECONDS);
                break;
            case eTeronogorGulkoshEvents::EventDrainLife:
                if (Unit* l_Target = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(l_Target, eTeronogorGulkoshSpells::SpellDrainLife);
                events.ScheduleEvent(eTeronogorGulkoshEvents::EventDrainLife, 10 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who && who->IsPlayer() && me->IsWithinDist(who, 18.0f, false) && !IsLock)
            {
                IsLock = true;
                who->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_gulkoshAI(p_Creature);
    }
};

/// Shaduum - 78728
class auchindoun_teronogor_mob_shaadum : public CreatureScript
{
public:

    auchindoun_teronogor_mob_shaadum() : CreatureScript("auchindoun_teronogor_mob_shaadum") { }

    struct auchindoun_teronogor_mob_shaadumAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_shaadumAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_First = true;
        }

        enum eShaddumSpells
        {
            SpellWrathStorm = 159033,
            SpellWrathCleave = 159035
        };

        enum eShaddumEvents
        {
            EventWrathcleave = 1,
            EventWrathstorm
        };

        bool m_First;
        EventMap events;

        void Reset()
        {
            events.Reset();
            me->SetReactState(ReactStates::REACT_AGGRESSIVE);
        }

        void EnterCombat(Unit* p_Attacker)
        {
            events.ScheduleEvent(eTerongorEvents::EventWrathcleave, 10 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTerongorEvents::EventWrathstorm, urand(14 * TimeConstants::IN_MILLISECONDS, 16 * TimeConstants::IN_MILLISECONDS));
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
            case eShaddumEvents::EventWrathstorm:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eShaddumSpells::SpellWrathStorm);
                events.ScheduleEvent(eShaddumEvents::EventWrathstorm, urand(8 * TimeConstants::IN_MILLISECONDS, 10 * TimeConstants::IN_MILLISECONDS));
                break;
            case eShaddumEvents::EventWrathcleave:
                if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(l_Random, eShaddumSpells::SpellWrathCleave);
                events.ScheduleEvent(eShaddumEvents::EventWrathcleave, urand(10 * TimeConstants::IN_MILLISECONDS, 14 * TimeConstants::IN_MILLISECONDS));
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who && who->IsPlayer() && me->IsWithinDist(who, 18.0f, false) && !IsLock)
            {
                IsLock = true;
                who->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_shaadumAI(p_Creature);
    }
};

/// Grom'tash The Destructor <Shadow Council> - 77889
class auchindoun_teronogor_mob_gromkash : public CreatureScript
{
public:

    auchindoun_teronogor_mob_gromkash() : CreatureScript("auchindoun_teronogor_mob_gromkash") { }

    struct auchindoun_teronogor_mob_gromkashAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_gromkashAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_First = true;
            m_Instance = me->GetInstanceScript();
        }

        enum eGromkashSpells
        {
            SpellGrimoireOfSacrifice = 159024,
            SpellImmolate = 156964,
            SpellIncinrate = 146963,
            SpellRainOfFire = 65757
        };

        enum eGromkashEvents
        {
            EventImmolate = 1,
            EventIncinrate,
            EventRainOfFire
        };

        InstanceScript* m_Instance;
        EventMap events;
        bool m_First;

        void Reset()
        {
            events.Reset();

            //if (me->GetMap())//???
            //  me->GetMap()->SetObjectVisibility(1000.0f);
            if (Creature* l_Teronogor = me->FindNearestCreature(NPC_TERONOGOR, 1000.0f, true))
                me->CastSpell(l_Teronogor, eAuchindounSpells::SpellDrainSoulVisual);
        }

        void EnterCombat(Unit* p_Attacker)
        {
            me->CastStop();
            me->RemoveAllAuras();
            events.ScheduleEvent(eTerongorEvents::EventImmolate, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(eTerongorEvents::EventIncinrate, urand(10 * TimeConstants::IN_MILLISECONDS, 12 * TimeConstants::IN_MILLISECONDS));
            events.ScheduleEvent(eTerongorEvents::EventRainOfFire, 18 * TimeConstants::IN_MILLISECONDS);
            if (Creature* l_Zashoo = me->FindNearestCreature(eAuchindounCreatures::CreatureZashoo, 20.0f, true))
                me->CastSpell(l_Zashoo, eGromkashSpells::SpellGrimoireOfSacrifice);
        }

        void JustDied(Unit* p_Killer)
        {
            if (Creature* l_Teronogor = me->FindNearestCreature(NPC_TERONOGOR, 1000.0f, true))
                l_Teronogor->RemoveAura(eTerongorSpells::SpellTeronogorShield);
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
            case eGromkashEvents::EventImmolate:
                if (Unit* l_Target = me->GetVictim())
                    me->CastSpell(l_Target, eGromkashSpells::SpellImmolate);
                events.ScheduleEvent(eGromkashEvents::EventImmolate, 10 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGromkashEvents::EventIncinrate:
                if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(l_Random, eGromkashSpells::SpellIncinrate);
                events.ScheduleEvent(eGromkashEvents::EventIncinrate, 6 * TimeConstants::IN_MILLISECONDS);
                break;
            case eGromkashEvents::EventRainOfFire:
                if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(l_Random, eGromkashSpells::SpellRainOfFire);
                events.ScheduleEvent(eGromkashEvents::EventRainOfFire, 15 * TimeConstants::IN_MILLISECONDS);
                break;
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who && who->IsPlayer() && me->IsWithinDist(who, 18.0f, false) && !IsLock)
            {
                IsLock = true;
                who->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_gromkashAI(p_Creature);
    }
};

/// Abyssal - 77905
class auchindoun_teronogor_mob_abyssal : public CreatureScript
{
public:

    auchindoun_teronogor_mob_abyssal() : CreatureScript("auchindoun_teronogor_mob_abyssal") { }

    struct auchindoun_teronogor_mob_abyssalAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_abyssalAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = me->GetInstanceScript();
            m_First = true;
        }

        enum eTeronogorAbyssalSpells
        {
            SpellFixate = 173080,
        };

        enum eTeronogorAbyssalEvents
        {
            EventFixate = 1,
        };

        InstanceScript* m_Instance;
        EventMap events;
        ObjectGuid m_Target;
        bool m_First;

        void Reset()
        {
            // m_Target = 0;
            events.Reset();
            //  ClearDelayedOperations();

            if (m_First)
            {
                /*  AddTimedDelayedOperation(2 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                {
                me->SetInCombatWithZone();
                me->SetDisplayId(InvisibleDisplay);
                me->SetReactState(ReactStates::REACT_AGGRESSIVE);
                me->RemoveFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_DISABLE_MOVE | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);
                });*/

                m_First = false;
                me->SetDisplayId(InvisibleDisplay);
                me->SetReactState(ReactStates::REACT_PASSIVE);
                me->CastSpell(me, eTerongorSpells::SpellSummonAbyssalMeteor);
                me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_PC | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC));
            }
        }

        void BeginFixation()
        {
            // if (m_Target == ObjectGuid::Empty)
            // {
            if (Unit* l_Random = SelectTarget(SelectAggroTarget::SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                m_Target = l_Random->GetGUID();
                me->GetMotionMaster()->MoveChase(l_Random);
                me->AddAura(eTeronogorAbyssalSpells::SpellFixate, l_Random);
            }
            //  }
        }

        void OnAddThreat(Unit* p_Victim, float& p_FThreat, SpellSchoolMask /*p_SchoolMask*/, SpellInfo const* /*p_ThreatSpell*/)
        {
            //if (m_Target)
            //{
            if (p_Victim->GetGUID() != m_Target)
                p_FThreat = 0;
            return;
            // }
        }

        void UpdateAI(uint32 p_Diff) override
        {
            me->SetSpeed(UnitMoveType::MOVE_RUN, 0.3f);

            if (!UpdateVictim())
                return;

            //  UpdateOperations(p_Diff);

            if (me->HasUnitState(UnitState::UNIT_STATE_CASTING) || me->HasUnitState(UnitState::UNIT_STATE_STUNNED))
                return;

            // if (m_Target)
            //{
            ///< Burst hardcoded
            if (Player* l_Player = ObjectAccessor::GetPlayer(*me, m_Target))
            {
                if (!l_Player->HasAura(eTeronogorAbyssalSpells::SpellFixate)) /// Fixated aura
                    me->AddAura(eTeronogorAbyssalSpells::SpellFixate, l_Player);

                if (!me->isMoving())
                    me->GetMotionMaster()->MoveFollow(l_Player, 0, 0, MovementSlot::MOTION_SLOT_ACTIVE);
            }
            // }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_abyssalAI(p_Creature);
    }
};

class auchindoun_teronogor_mob_spirit : public CreatureScript
{
public:

    auchindoun_teronogor_mob_spirit() : CreatureScript("auchindoun_teronogor_mob_spirit") { }

    struct auchindoun_teronogor_mob_spiritAI : public ScriptedAI
    {
        auchindoun_teronogor_mob_spiritAI(Creature* p_Creature) : ScriptedAI(p_Creature)
        {
            m_Instance = me->GetInstanceScript();
        }

        InstanceScript* m_Instance;

        void Reset()
        {
            me->SetReactState(ReactStates::REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const
    {
        return new auchindoun_teronogor_mob_spiritAI(p_Creature);
    }
};

/// Chaos Wave - 157001
class auchindoun_teronogor_spell_chaos_wave : public SpellScriptLoader
{
public:

    auchindoun_teronogor_spell_chaos_wave() : SpellScriptLoader("auchindoun_teronogor_spell_chaos_wave") { }

    class auchindoun_teronogor_spell_chaos_wave_SpellScript : public SpellScript
    {
        PrepareSpellScript(auchindoun_teronogor_spell_chaos_wave_SpellScript);

        enum eChaosWaveSpells
        {
            SpellChaosWaveDmg = 157002
        };

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (!GetCaster() && !GetExplTargetUnit())
                return;

            GetCaster()->CastSpell(GetExplTargetUnit(), eChaosWaveSpells::SpellChaosWaveDmg);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(auchindoun_teronogor_spell_chaos_wave_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new auchindoun_teronogor_spell_chaos_wave_SpellScript();
    }
};

/// Seed of Malevolence - 156921 
class auchindoun_teronogor_spell_seed_of_malevolence : public SpellScriptLoader
{
public:

    auchindoun_teronogor_spell_seed_of_malevolence() : SpellScriptLoader("auchindoun_teronogor_spell_seed_of_malevolence") { }

    class auchindoun_teronogor_spell_seed_of_malevolence_AuraScript : public AuraScript
    {
        PrepareAuraScript(auchindoun_teronogor_spell_seed_of_malevolence_AuraScript);

        enum eSeedOfMalevolanceSpells
        {
            SpellSeedOfMalevolenceDmg = 156924
        };

        void OnRemove(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*p_Mode*/)
        {
            if (!GetTarget())
                return;

            GetTarget()->CastSpell(GetTarget(), eSeedOfMalevolanceSpells::SpellSeedOfMalevolenceDmg);
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(auchindoun_teronogor_spell_seed_of_malevolence_AuraScript::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_PERIODIC_DAMAGE, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new auchindoun_teronogor_spell_seed_of_malevolence_AuraScript();
    }
};

/// Spell Demon Jump - 157039
class auchindoun_teronogor_spell_demonic_leap_jump : public SpellScriptLoader
{
public:

    auchindoun_teronogor_spell_demonic_leap_jump() : SpellScriptLoader("auchindoun_teronogor_spell_demonic_leap_jump") { }

    class auchindoun_teronogor_spell_demonic_leap_jump_SpellScript : public SpellScript
    {
        PrepareSpellScript(auchindoun_teronogor_spell_demonic_leap_jump_SpellScript);

        void Land(SpellEffIndex /*p_EffIndex*/)
        {
            if (Unit* l_Caster = GetCaster())
                l_Caster->CastSpell(l_Caster, eTerongorSpells::SpellDemonicLeapAreatriger);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(auchindoun_teronogor_spell_demonic_leap_jump_SpellScript::Land, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new auchindoun_teronogor_spell_demonic_leap_jump_SpellScript();
    }
};

/// Demonic Leap - 148969 
class auchindoun_teronogor_spell_demonic_leap : public SpellScriptLoader
{
public:

    auchindoun_teronogor_spell_demonic_leap() : SpellScriptLoader("auchindoun_teronogor_spell_demonic_leap") { }

    class auchindoun_teronogor_spell_demonic_leap_SpellScript : public SpellScript
    {
        PrepareSpellScript(auchindoun_teronogor_spell_demonic_leap_SpellScript);

        enum eDemonicLeapSpells
        {
            SpellDemonicLeapJump = 157039
        };

        void HandleDummy(SpellEffIndex p_EffIndex)
        {
            if (!GetCaster() && !GetExplTargetUnit())
                return;

            GetCaster()->CastSpell(GetExplTargetUnit(), eDemonicLeapSpells::SpellDemonicLeapJump);
        }

        void Register()
        {
            OnEffectLaunch += SpellEffectFn(auchindoun_teronogor_spell_demonic_leap_SpellScript::HandleDummy, SpellEffIndex::EFFECT_0, SpellEffectName::SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new auchindoun_teronogor_spell_demonic_leap_SpellScript();
    }
};

/// Soul Transport Object 01 - 231736
class auchindoun_teronogor_gameobject_soul_transporter_01 : public GameObjectScript
{
public:

    auchindoun_teronogor_gameobject_soul_transporter_01() : GameObjectScript("auchindoun_teronogor_gameobject_soul_transporter_01") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gobject)
    {
        p_Player->AddAura(eTerongorSpells::SpellTranscend, p_Player);
        //p_Player->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLE_TURN);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);

        p_Player->GetMotionMaster()->MoveCharge(g_PositionFirstPlatformFirstMove.GetPositionX(), g_PositionFirstPlatformFirstMove.GetPositionY(), g_PositionFirstPlatformFirstMove.GetPositionZ(), 60.0f);
        p_Player->GetScheduler().Schedule(Milliseconds(3000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionFirstPlatormSecondMove.GetPositionX(), g_PositionFirstPlatormSecondMove.GetPositionY(), g_PositionFirstPlatormSecondMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(6000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionFirstPlatformThirdMove.GetPositionX(), g_PositionFirstPlatformThirdMove.GetPositionY(), g_PositionFirstPlatformThirdMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(11000), [p_Player](TaskContext context)
        {
            p_Player->RemoveAura(eTerongorSpells::SpellTranscend);
            p_Player->RemoveUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            p_Player->RemoveUnitFlag(UnitFlags(UNIT_FLAG2_DISABLE_TURN));
        });
        return true;
    }
};

/// Soul Transport Object 02 - 231739 345366
class auchindoun_teronogor_gameobject_soul_transporter_02 : public GameObjectScript
{
public:

    auchindoun_teronogor_gameobject_soul_transporter_02() : GameObjectScript("auchindoun_teronogor_gameobject_soul_transporter_02") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gobject)
    {
        p_Player->AddAura(eTerongorSpells::SpellTranscend, p_Player);
        //p_Player->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLE_TURN);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);
        p_Player->GetScheduler().Schedule(Milliseconds(1000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionSecondPlatformFirstMove.GetPositionX(), g_PositionSecondPlatformFirstMove.GetPositionY(), g_PositionSecondPlatformFirstMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(4000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionSecondPlatformSecondMove.GetPositionX(), g_PositionSecondPlatformSecondMove.GetPositionY(), g_PositionSecondPlatformSecondMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(7000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionSecondPlatformThirdMove.GetPositionX(), g_PositionSecondPlatformThirdMove.GetPositionY(), g_PositionSecondPlatformThirdMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(12000), [p_Player](TaskContext context)
        {
            p_Player->RemoveAura(eTerongorSpells::SpellTranscend);
            p_Player->RemoveUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
        });
        return true;
    }
};

/// Soul Transport Object 03 - 231740, 345367
class auchindoun_teronogor_gameobject_soul_transporter_03 : public GameObjectScript
{
public:

    auchindoun_teronogor_gameobject_soul_transporter_03() : GameObjectScript("auchindoun_teronogor_gameobject_soul_transporter_03") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gobject)
    {
        p_Player->AddAura(eTerongorSpells::SpellTranscend, p_Player);
        //p_Player->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLE_TURN);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);
        p_Player->GetScheduler().Schedule(Milliseconds(1000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionThirdPlatformFirstMove.GetPositionX(), g_PositionThirdPlatformFirstMove.GetPositionY(), g_PositionThirdPlatformFirstMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(4000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionThirdPlatformsSecondMove.GetPositionX(), g_PositionThirdPlatformsSecondMove.GetPositionY(), g_PositionThirdPlatformsSecondMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(7000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionThirdPlatformThirdMove.GetPositionX(), g_PositionThirdPlatformThirdMove.GetPositionY(), g_PositionThirdPlatformThirdMove.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(12000), [p_Player](TaskContext context)
        {
            p_Player->RemoveAura(eTerongorSpells::SpellTranscend);
            p_Player->RemoveUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
        });
        return true;
    }
};

/// Soul Transport Object 04 - 231741,345368
class auchindoun_teronogor_gameobject_soul_transporter_04 : public GameObjectScript
{
public:

    auchindoun_teronogor_gameobject_soul_transporter_04() : GameObjectScript("auchindoun_teronogor_gameobject_soul_transporter_04") { }

    bool OnGossipHello(Player* p_Player, GameObject* p_Gobject)
    {
        p_Player->AddAura(eTerongorSpells::SpellTranscend, p_Player);
        //p_Player->AddUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS_2, UnitFlags2::UNIT_FLAG2_DISABLE_TURN);
        //p_Player->SetFlag(UnitFields::UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL | UnitFlags::UNIT_FLAG_IMMUNE_TO_NPC);
        p_Player->GetScheduler().Schedule(Milliseconds(1000), [p_Player](TaskContext context)
        {
            p_Player->GetMotionMaster()->MoveCharge(g_PositionFourthMovement.GetPositionX(), g_PositionFourthMovement.GetPositionY(), g_PositionFourthMovement.GetPositionZ(), 60.0f);
        }).Schedule(Milliseconds(6000), [p_Player](TaskContext context)
        {
            p_Player->RemoveAura(eTerongorSpells::SpellTranscend);
            p_Player->RemoveUnitMovementFlag(MovementFlags::MOVEMENTFLAG_ROOT);
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags::UNIT_FLAG_REMOVE_CLIENT_CONTROL));
            p_Player->RemoveUnitFlag(UnitFlags(UnitFlags2::UNIT_FLAG2_DISABLE_TURN));
        });
        return true;
    }
};

/// Chaos Wave - 157001 
class auchindoun_teronogor_areatrigger_chaos_wave : public AreaTriggerEntityScript
{
public:

    auchindoun_teronogor_areatrigger_chaos_wave() : AreaTriggerEntityScript("auchindoun_teronogor_areatrigger_chaos_wave") { }

    uint32 l_DiffDot = 1 * TimeConstants::IN_MILLISECONDS;

    void OnUpdate(AreaTrigger* p_AreaTrigger, uint32 p_Time)
    {
        if (p_AreaTrigger)
        {
            if (p_Time <= l_DiffDot)
            {
                std::list<Player*> l_ListPlayers;
                p_AreaTrigger->GetPlayerListInGrid(l_ListPlayers, 2.0f);
                if (!l_ListPlayers.empty())
                {
                    for (Player* l_Itr : l_ListPlayers)
                    {
                        if (!l_Itr)
                            continue;

                        l_Itr->CastSpell(l_Itr, eTerongorSpells::SpellChaosWaveDmg);
                    }
                }

                l_DiffDot = 1 * TimeConstants::IN_MILLISECONDS;
            }
            else
                l_DiffDot -= p_Time;
        }
    }
    /*
    auchindoun_teronogor_areatrigger_chaos_wave* GetAI()const
    {
    return nullptr;
    }*/
};

void AddSC_boss_teronogor()
{
    RegisterCreatureAI(boss_teronogor);
    new auchindoun_teronogor_mob_gromkash();                        ///< 77889
    new auchindoun_teronogor_mob_abyssal();                         ///< 77905
    new auchindoun_teronogor_mob_durag();                           ///< 77890
    new auchindoun_teronogor_mob_gulkosh();                         ///< 78437
    new auchindoun_teronogor_mob_shaadum();                         ///< 78728
    new auchindoun_teronogor_mob_spirit();
    new auchindoun_teronogor_spell_chaos_wave();                    ///< 157001
    new auchindoun_teronogor_spell_demonic_leap();                  ///< 148969
    new auchindoun_teronogor_spell_seed_of_malevolence();           ///< 156921
    new auchindoun_teronogor_spell_demonic_leap_jump();             ///< 157039
    new auchindoun_teronogor_areatrigger_chaos_wave();              ///< 157001
    new auchindoun_teronogor_gameobject_soul_transporter_01();      ///< 231736
    new auchindoun_teronogor_gameobject_soul_transporter_02();      ///< 231739 
    new auchindoun_teronogor_gameobject_soul_transporter_03();      ///< 231740
    new auchindoun_teronogor_gameobject_soul_transporter_04();      ///< 231741
}
