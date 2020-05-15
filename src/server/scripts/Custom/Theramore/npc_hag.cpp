#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Custom/AI/CustomAI.h"

enum Spells
{
	SPELL_FIREBALL          = 100003,
	SPELL_ICE_LANCE         = 100007,
	SPELL_ICE_BLOCK         = 100008,
	SPELL_BLINK             = 57869,
	SPELL_ARCANE_BLAST      = 100010,
    SPELL_PRISMATIC_BARRIER = 100069,
    SPELL_IMMOLATE          = 100079
};

class npc_hag : public CreatureScript
{
    public:
    npc_hag() : CreatureScript("npc_hag") {}

    struct npc_hagAI : public CustomAI
    {
        npc_hagAI(Creature* creature) : CustomAI(creature), hasUsedIceBlock(false)
        {
            SetCombatMovement(false);
        }

        void Reset() override
        {
            CustomAI::Reset();

            hasUsedIceBlock = false;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
        {
            if (spellInfo->GetSchoolMask() == SPELL_SCHOOL_MASK_FIRE && roll_chance_i(70))
                me->AddAura(SPELL_IMMOLATE, target);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(SPELL_PRISMATIC_BARRIER);

            scheduler
                .Schedule(1s, [this](TaskContext fireball)
                {
                    DoCastVictim(SPELL_FIREBALL);
                    fireball.Repeat(1800ms);
                })
                .Schedule(5s, [this](TaskContext ice_lance)
                {
                    me->InterruptNonMeleeSpells(true);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ICE_LANCE);
                    ice_lance.Repeat(8s, 15s);
                })
                .Schedule(10s, [this](TaskContext blink)
                {
                    me->InterruptNonMeleeSpells(true);
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE))
                        DoCast(target, SPELL_BLINK);
                    blink.Repeat(20s, 30s);
                })
                .Schedule(3s, [this](TaskContext arcane_blast)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ARCANE_BLAST);
                    arcane_blast.Repeat(8s, 14s);
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!hasUsedIceBlock && HealthBelowPct(30))
            {
                DoCastSelf(SPELL_ICE_BLOCK);

                hasUsedIceBlock = true;

                scheduler.Schedule(1min, [this](TaskContext /*context*/)
                {
                    hasUsedIceBlock = false;
                });
            }
        }

        private:
        bool hasUsedIceBlock;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hagAI(creature);
    }
};

void AddSC_npc_hag()
{
    new npc_hag();
}
