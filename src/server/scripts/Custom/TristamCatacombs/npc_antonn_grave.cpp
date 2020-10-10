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
#define ACOLYTE_SPAWN_POS_SIZE      6

enum Texts
{
    SAY_ANTONN_GRAVE_01             = 4
};

enum Events
{
    EVENT_AG_SKELETON_01            = 1,
    EVENT_AG_SKELETON_02,
    EVENT_AG_SKELETON_03,
    EVENT_AG_SKELETON_04,
};

enum Spells
{
    SPELL_SHADOW_BOLT               = 100028,
    SPELL_CORRUPTION                = 100074,
};

enum class Phases : uint8
{
    None,
    Skeleton,
    Combat
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

const Position acolyteSpawnPos[ACOLYTE_SPAWN_POS_SIZE] =
{
    { 281.48f,  83.11f, 109.97f, 3.13f },
    { 242.66f,  82.45f, 109.97f, 6.25f },
    { 281.06f, 102.17f, 109.97f, 3.14f },
    { 280.80f, 120.62f, 109.97f, 3.08f },
    { 242.03f, 120.16f, 109.97f, 6.27f },
    { 242.14f, 101.67f, 109.97f, 6.27f }
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
            phase(Phases::None)
        {
            Initialize();
        }

        void Initialize()
        {
            phase = Phases::None;
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_AG_SKELETON:
                    DoZoneInCombat();
                    phase = Phases::Skeleton;
                    events.ScheduleEvent(EVENT_AG_SKELETON_01, 1s);
                    break;
                case ACTION_AG_COMBAT:
                    phase = Phases::Combat;
                    summons.DespawnEntry(NPC_SKELETON_MINION);
                    summons.DespawnEntry(NPC_MAGE_SKELETON_MINION);
                    me->SetControlled(false, UNIT_STATE_ROOT);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                    break;
                default:
                    break;
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();

            me->CombatStop();
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);

            for (auto acolyte : acolytes)
            {
                if (acolyte->isDead())
                    acolyte->Respawn(true);
                else
                    acolyte->GetMotionMaster()->MoveTargetedHome();
            }
        }

        void Reset() override
        {
            _Reset();

            Initialize();

            if (!acolytes.empty())
                acolytes.clear();

            for (uint8 i = 0; i < ACOLYTE_SPAWN_POS_SIZE; i++)
            {
                if (Creature* acolyte = me->SummonCreature(NPC_ACOLYTE, acolyteSpawnPos[i]))
                {
                    acolyte->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                    acolyte->SetFacingToObject(me);
                    acolyte->CastSpell(me, SPELL_RITUAL_CANALISATION, true);
                    acolytes.push_back(acolyte);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (phase == Phases::Combat)
                if (!UpdateVictim())
                    return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 event = events.ExecuteEvent())
            {
                switch (event)
                {
                    case EVENT_AG_SKELETON_01:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_PACIFIED);
                        events.ScheduleEvent(EVENT_AG_SKELETON_02, 2s);
                        break;
                    case EVENT_AG_SKELETON_02:
                        me->AI()->Talk(SAY_ANTONN_GRAVE_01);
                        for (auto acolyte : acolytes)
                            acolyte->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                        events.ScheduleEvent(EVENT_AG_SKELETON_03, 4s);
                        events.ScheduleEvent(EVENT_AG_SKELETON_04, 2min);
                        break;
                    case EVENT_AG_SKELETON_03:
                        if (Creature* minion = me->SummonCreature(RAND(NPC_SKELETON_MINION, NPC_MAGE_SKELETON_MINION),
                            skeletonSpawnPos[urand(0, SKELETON_SPAWN_POS_SIZE - 1)], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 30s))
                        {
                            minion->CastSpell(minion, SPELL_VISUAL_TELEPORT_DEMON, true);
                            if (Unit* victim = me->GetThreatManager().GetAnyTarget())
                            {
                                if (minion->Attack(victim, true))
                                    minion->GetMotionMaster()->MoveChase(victim);
                            }
                        }
                        events.RescheduleEvent(EVENT_AG_SKELETON_03, 8s);
                        break;
                    case EVENT_AG_SKELETON_04:
                        DoAction(ACTION_AG_COMBAT);
                        events.CancelEvent(EVENT_AG_SKELETON_03);
                        break;
                    default:
                        break;
                }
            }

            if (phase == Phases::Combat)
                DoMeleeAttackIfReady();
        }

        private:
        Phases phase;
        std::vector<Creature*> acolytes;
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

void AddSC_npc_antonn_grave()
{
    new npc_antonn_grave();
    new npc_acolyte();
}
