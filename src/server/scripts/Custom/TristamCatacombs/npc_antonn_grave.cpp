#include "tristam_catacombs.h"
#include "Custom/AI/CustomAI.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "World.h"

#define SKELETON_SPAWN_POS_SIZE     6

enum Texts
{
    SAY_ANTONN_GRAVE_01             = 4
};

enum Events
{
    EVENT_SKELETON_01               = 1,
    EVENT_SKELETON_02,
    EVENT_SKELETON_03,
    EVENT_SKELETON_END,

    EVENT_DRAINING,
    EVENT_DRAINING_END,

    EVENT_SHADOWBOLT,
    EVENT_CORRUPTION,
    EVENT_HAUNT,
    EVENT_FEL_FIREBALL,
    EVENT_CURSE_OF_AGONY,
};

enum Spells
{
    SPELL_SHADOW_CANALISATION       = 43897,

    SPELL_SHADOW_BOLT               = 100028,
    SPELL_CORRUPTION                = 100074,
    SPELL_HAUNT                     = 100075,
    SPELL_FEL_FIREBALL              = 100027,
    SPELL_DRAIN_OF_LIFE             = 100097,
    SPELL_CURSE_OF_AGONY            = 100077,
    SPELL_ASMODAN_PROTECTION        = 100098
};

enum Misc
{
    // Summon group
    SUMMON_GROUP_ACOLYTES           = 0,
    SUMMON_GROUP_SACRIFIED_SOULS    = 1,

    // Actions
    ACTION_AG_SWITCH_PHASE          = -668000
};

enum Phases : uint8
{
    PHASE_NONE,
    PHASE_SKELETON,
    PHASE_COMBAT,
    PHASE_DRAINING
};

const Position skeletonSpawnPos[SKELETON_SPAWN_POS_SIZE] =
{
    { 247.27f,  82.09f, 110.20f, 6.25f },
    { 246.90f, 102.05f, 110.22f, 0.00f },
    { 245.97f, 119.86f, 110.20f, 5.43f },
    { 276.61f, 120.70f, 110.21f, 4.31f },
    { 277.21f, 103.29f, 110.21f, 3.97f },
    { 277.44f,  82.74f, 110.20f, 3.85f }
};

class npc_antonn_grave : public CreatureScript
{
    public:
    npc_antonn_grave() : CreatureScript("npc_antonn_grave")
    {
    }

    struct npc_antonn_graveAI : public BossAI
    {
        npc_antonn_graveAI(Creature* creature) : BossAI(creature, DATA_ANTONN_GRAVE),
            scheduledEvents(false)
        {
            curseOfAgonyInfo = sSpellMgr->AssertSpellInfo(SPELL_CURSE_OF_AGONY);
            corruptionInfo = sSpellMgr->AssertSpellInfo(SPELL_CORRUPTION);

            Initialize();
        }

        void Initialize()
        {
            events.SetPhase(PHASE_NONE);
            scheduledEvents = false;
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_AG_SKELETON:
                    DoZoneInCombat();
                    events.SetPhase(PHASE_SKELETON);
                    events.ScheduleEvent(EVENT_SKELETON_01, 1s, 0, PHASE_SKELETON);
                    break;
                case ACTION_AG_COMBAT:
                    me->AI()->Talk(SAY_ANTONN_GRAVE_01);
                    if (GameObject* door = instance->GetGameObject(DATA_ANTONN_GRAVE_ENTRANCE))
                        instance->HandleGameObject(ObjectGuid::Empty, false, door);
                    me->SummonCreatureGroup(SUMMON_GROUP_SACRIFIED_SOULS, &souls);
                    for (auto soul : souls)
                    {
                        soul->CombatStop();
                        soul->SetControlled(true, UNIT_STATE_ROOT);
                    }
                    for (auto acolyte : acolytes)
                        acolyte->KillSelf();
                    events.SetPhase(PHASE_COMBAT);
                    ScheduleCombatSpells();
                    summons.DespawnEntry(NPC_SKELETON_MINION);
                    summons.DespawnEntry(NPC_MAGE_SKELETON_MINION);
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                    me->RemoveAurasDueToSpell(SPELL_ASMODAN_PROTECTION);
                    break;
                case ACTION_AG_SWITCH_PHASE:
                    events.SetPhase(PHASE_COMBAT);
                    ScheduleCombatSpells();
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                    AttackStart(me->GetVictim());
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
                    break;
                default:
                    break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                Unit* soul = ObjectAccessor::GetUnit(*me, soulGUID);
                if (soul && soul->IsAlive())
                {
                    me->SetFacingToObject(soul);
                    soul->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    soul->CastSpell(me, SPELL_DRAIN_OF_LIFE, true);
                    events.ScheduleEvent(EVENT_DRAINING_END, 10s, 0, PHASE_DRAINING);
                }
            }
        }

        void Reset() override
        {
            _Reset();

            Initialize();

            soulGUID.Clear();

            if (!acolytes.empty())
                acolytes.clear();

            me->SummonCreatureGroup(SUMMON_GROUP_ACOLYTES, &acolytes);

            uint8 index = 0;
            for (auto acolyte : acolytes)
            {
                acolytesOrientation[index] = acolyte->GetOrientation();

                acolyte->SetImmuneToAll(true);
                acolyte->SetFacingToObject(me);
                acolyte->CastSpell(me, SPELL_RITUAL_CANALISATION, true);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.IsInPhase(PHASE_COMBAT))
                if (!UpdateVictim())
                    return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 event = events.ExecuteEvent())
            {
                switch (event)
                {
                    #pragma region Skeletons minions event
                    case EVENT_SKELETON_01:
                        me->SetImmuneToAll(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                        DoCastSelf(SPELL_ASMODAN_PROTECTION);
                        events.ScheduleEvent(EVENT_SKELETON_02, 2s, 0, PHASE_SKELETON);
                        break;
                    case EVENT_SKELETON_02:
                    {
                        uint8 index = 0;
                        for (auto acolyte : acolytes)
                        {
                            acolyte->SetFacingTo(acolytesOrientation[index]);
                            acolyte->CastSpell(acolyte, SPELL_SHADOW_CANALISATION, true);
                            index++;
                        }
                        events.ScheduleEvent(EVENT_SKELETON_03, 4s, 0, PHASE_SKELETON);
                        events.ScheduleEvent(EVENT_SKELETON_END, 2min, 0, PHASE_SKELETON);
                        break;
                    }
                    case EVENT_SKELETON_03:
                    {
                        const Position spawnPos = GetRandomPositionOffset(3.f);
                        if (Creature* minion = me->SummonCreature(RAND(NPC_SKELETON_MINION, NPC_MAGE_SKELETON_MINION),
                            spawnPos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s))
                        {
                            minion->CastSpell(minion, SPELL_VISUAL_TELEPORT_DEMON, true);
                            if (Unit* victim = me->GetThreatManager().GetAnyTarget())
                            {
                                if (Creature* netristrasza = instance->GetCreature(DATA_NETRISTRASZA))
                                {
                                    if (!netristrasza->IsEngaged())
                                    {
                                        netristrasza->Attack(minion, true);
                                        netristrasza->GetMotionMaster()->MoveChase(minion);
                                    }
                                }

                                switch (minion->GetEntry())
                                {
                                    case NPC_MAGE_SKELETON_MINION:
                                        minion->Attack(victim, false);
                                        break;
                                    default:
                                        if (minion->Attack(victim, true))
                                            minion->GetMotionMaster()->MoveChase(victim);
                                        break;
                                }
                            }
                        }
                        events.RescheduleEvent(EVENT_SKELETON_03, 10s, 0, PHASE_SKELETON);
                        break;
                    }
                    case EVENT_SKELETON_END:
                        events.CancelEvent(EVENT_SKELETON_03);
                        DoAction(ACTION_AG_COMBAT);
                        break;
                    #pragma endregion

                    #pragma region Combat events
                    case EVENT_DRAINING:
                        SelectNearestSoul();
                        scheduledEvents = false;
                        break;
                    case EVENT_DRAINING_END:
                    {
                        Creature* soul = ObjectAccessor::GetCreature(*me, soulGUID);
                        if (soul && soul->IsAlive())
                            soul->KillSelf();

                        soulGUID.Clear();

                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                        break;
                    }
                    case EVENT_SHADOWBOLT:
                        DoCastVictim(SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(EVENT_SHADOWBOLT, 8s, 0, PHASE_COMBAT);
                        break;
                    case EVENT_HAUNT:
                        if (Unit* target = DoSelectLowestHpEnemy(45.f))
                            DoCast(target, SPELL_HAUNT);
                        events.RescheduleEvent(EVENT_HAUNT, 30s, 0, PHASE_COMBAT);
                        break;
                    case EVENT_FEL_FIREBALL:
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            DoCast(target, SPELL_FEL_FIREBALL);
                        events.RescheduleEvent(EVENT_FEL_FIREBALL, 15s, 24s, 0, PHASE_COMBAT);
                        break;
                    case EVENT_CURSE_OF_AGONY:
                        if (Unit* target = DoFindEnemyMissingDot(50.0f, curseOfAgonyInfo))
                            DoCast(target, SPELL_CURSE_OF_AGONY);
                        events.RescheduleEvent(EVENT_CURSE_OF_AGONY, 1s, 0, PHASE_COMBAT);
                        break;
                    case EVENT_CORRUPTION:
                        if (Unit* target = DoFindEnemyMissingDot(50.0f, corruptionInfo))
                            DoCast(target, SPELL_CORRUPTION);
                        events.RescheduleEvent(EVENT_CORRUPTION, 1s, 0, PHASE_COMBAT);
                        break;
                    #pragma endregion

                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            if (HealthBelowPct(50))
            {
                if (events.IsInPhase(PHASE_COMBAT) && !scheduledEvents)
                {
                    scheduledEvents = true;
                    Milliseconds timer = randtime(2s, 4s);
                    events.ScheduleEvent(EVENT_DRAINING, timer, 0, PHASE_COMBAT);
                }
            }

            if (events.IsInPhase(PHASE_COMBAT))
                DoMeleeAttackIfReady();
        }

        private:
        ObjectGuid soulGUID;
        bool scheduledEvents;
        float acolytesOrientation[6];
        std::list<TempSummon*> acolytes;
        std::list<TempSummon*> souls;
        const SpellInfo* curseOfAgonyInfo;
        const SpellInfo* corruptionInfo;

        void SelectNearestSoul()
        {
            if (Creature* soul = me->FindNearestCreature(NPC_SACRIFIED_SOUL, 250.0f))
            {
                soulGUID = soul->GetGUID();

                events.SetPhase(PHASE_DRAINING);
                me->SetWalk(false);
                me->GetMotionMaster()->MoveCloserAndStop(1, soul, 10.f);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
            }
        }

        void ScheduleCombatSpells()
        {
            events.ScheduleEvent(EVENT_SHADOWBOLT, 2s, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_HAUNT, 24s, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_FEL_FIREBALL, 8s, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_CURSE_OF_AGONY, 1s, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_CORRUPTION, 1s, 0, PHASE_COMBAT);
        }

        Position GetRandomPositionOffset(float offset) const
        {
            uint8 random = urand(0, SKELETON_SPAWN_POS_SIZE - 1);
            float alpha = 2 * float(M_PI) * float(rand_norm());
            float r = offset * sqrtf(float(rand_norm()));
            float x = r * cosf(alpha) + skeletonSpawnPos[random].GetPositionX();
            float y = r * sinf(alpha) + skeletonSpawnPos[random].GetPositionY();
            float z = skeletonSpawnPos[random].GetPositionZ();
            float o = skeletonSpawnPos[random].GetOrientation();
            return { x, y, z, o };
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTristamCatacombsAI<npc_antonn_graveAI>(creature);
    }
};

class npc_acolyte : public CreatureScript
{
    public:
    npc_acolyte() : CreatureScript("npc_acolyte") {}

    struct npc_acolyteAI : public CustomAI
    {
        npc_acolyteAI(Creature* creature) : CustomAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            corruptionInfo = sSpellMgr->AssertSpellInfo(SPELL_CORRUPTION);

            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(1s, 5s, [this](TaskContext shadow_bolt)
                {
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    shadow_bolt.Repeat(3s);
                })
                .Schedule(5ms, [this](TaskContext corruption)
                {
                    if (Unit* target = DoFindEnemyMissingDot(50.0f, corruptionInfo))
                        DoCast(target, SPELL_CORRUPTION);
                    corruption.Repeat(1s);
                });
        }

        private:
        const SpellInfo* corruptionInfo;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTristamCatacombsAI<npc_acolyteAI>(creature);
    }
};

class npc_sacrified_soul : public CreatureScript
{
    public:
    npc_sacrified_soul() : CreatureScript("npc_sacrified_soul")
    {
    }

    struct npc_sacrified_soulAI : public ScriptedAI
    {
        npc_sacrified_soulAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                Creature* antonn = instance->GetCreature(DATA_ANTONN_GRAVE);
                if (antonn && antonn->IsAlive())
                    antonn->AI()->DoAction(ACTION_AG_SWITCH_PHASE);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTristamCatacombsAI<npc_sacrified_soulAI>(creature);
    };
};

void AddSC_npc_antonn_grave()
{
    new npc_antonn_grave();
    new npc_acolyte();
    new npc_sacrified_soul();
}
