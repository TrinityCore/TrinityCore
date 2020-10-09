#include "tristam_catacombs.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "World.h"

enum Texts
{

};

class npc_antonn_grave : public CreatureScript
{
    public:
    npc_antonn_grave() : CreatureScript("npc_antonn_grave")
    {
    }

    struct npc_antonn_graveAI : public ScriptedAI
    {
        npc_antonn_graveAI(Creature* creature) : ScriptedAI(creature),
            instance(creature->GetInstanceScript())
        {
            Initialize();
        }

        void Initialize()
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                DoStartMovement(who, 20.0f);
                SetCombatMovement(true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {

        }

        void JustDied(Unit* /*killer*/) override
        {
            scheduler.CancelAll();
        }

        void Reset() override
        {
            Initialize();

            scheduler.CancelAll();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update(diff, [this]
            {
                DoMeleeAttackIfReady();
            });
        }

        private:
        TaskScheduler scheduler;
        InstanceScript* instance;
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

    struct npc_acolyteAI : public ScriptedAI
    {
        npc_acolyteAI(Creature* creature) : ScriptedAI(creature),
            instance(creature->GetInstanceScript())
        {
            Initialize();
        }

        void Initialize()
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                DoStartMovement(who, 20.0f);
                SetCombatMovement(true);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {

        }

        void JustDied(Unit* /*killer*/) override
        {
            scheduler.CancelAll();
        }

        void Reset() override
        {
            Initialize();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);

            scheduler.CancelAll();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            scheduler.Update();
        }

        private:
        TaskScheduler scheduler;
        InstanceScript* instance;
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
