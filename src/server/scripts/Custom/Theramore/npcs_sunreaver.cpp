#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "World.h"
#include "Custom/AI/CustomAI.h"

#include <iostream>

enum Misc
{
    // Quests
    QUEST_SEWER_CLEANING        = 80017,
    NPC_INVISIBLE_STALKER       = 32780,
    SUNREAVER_KILL_CREDIT       = 100062,
    SAY_BRASAEL_AGGRO           = 0,
};

enum Spells
{
    // Assassin
    SPELL_SINISTER_STRIKE       = 59409,
    SPELL_KIDNEY_SHOT           = 72335,

    // Duelist
    SPELL_MIGHTY_KICK           = 69021,

    // Pyromancer
    SPELL_FIRE_ARMOR            = 43046,
    SPELL_FIREBALL              = 100003,
    SPELL_FIREBLAST             = 100004,
    SPELL_PYROBLAST             = 100005,

    // Forsthand
    SPELL_FROST_ARMOR           = 43008,
    SPELL_FROSTBOLT             = 100006,
    SPELL_ICE_LANCE             = 100007,
    SPELL_FROST_CONE            = 65023,

    // Brasael
    SPELL_SCORCH                = 100055,
    SPELL_METEOR                = 100054,
    SPELL_DRAGON_BREATH         = 37289,
    SPELL_POSTCOMBUSTION        = 100082,
    SPELL_DUMMY_METEOR          = 100056 
};

enum Phases
{
    PHASE_NORMAL = 1,
    PHASE_POSTCOMBUSTION
};

void KillCredit(Unit* killer)
{
    if (killer->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = killer->ToPlayer();
    if (player && player->GetQuestStatus(QUEST_SEWER_CLEANING) == QUEST_STATUS_INCOMPLETE)
        player->KilledMonsterCredit(SUNREAVER_KILL_CREDIT);
}

class npc_sunreaver_assassin : public CreatureScript
{
    public:
    npc_sunreaver_assassin() : CreatureScript("npc_sunreaver_assassin") {}

    struct npc_sunreaver_assassinAI : public CustomAI
    {
        npc_sunreaver_assassinAI(Creature* creature) : CustomAI(creature, MELEE) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(5s, [this](TaskContext sinisterStrike)
                {
                    DoCast(SPELL_SINISTER_STRIKE);
                    sinisterStrike.Repeat(14s, 28s);
                })
                .Schedule(10s, [this](TaskContext kidneyShot)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_KIDNEY_SHOT, 35.f))
                    {
                        DoCast(target, SPELL_KIDNEY_SHOT);
                        kidneyShot.Repeat(25s, 40s);
                    }
                    else
                    {
                        kidneyShot.Repeat(1s);
                    }
                });
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_assassinAI(creature);
    }
};

class npc_sunreaver_duelist : public CreatureScript
{
    public:
    npc_sunreaver_duelist() : CreatureScript("npc_sunreaver_duelist") {}

    struct npc_sunreaver_duelistAI : public CustomAI
    {
        npc_sunreaver_duelistAI(Creature* creature) : CustomAI(creature, MELEE) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler.Schedule(5s, [this](TaskContext mightyKick)
            {
                DoCast(SPELL_MIGHTY_KICK);
                mightyKick.Repeat(14s, 28s);
            });
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_duelistAI(creature);
    }
};

class npc_sunreaver_pyromancer : public CreatureScript
{
    public:
    npc_sunreaver_pyromancer() : CreatureScript("npc_sunreaver_pyromancer") {}

    struct npc_sunreaver_pyromancerAI : public CustomAI
    {
        npc_sunreaver_pyromancerAI(Creature* creature) : CustomAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(5s, [this](TaskContext fireball)
                {
                    DoCast(SPELL_FIREBALL);
                    fireball.Repeat(5s, 8s);
                })
                .Schedule(14s, [this](TaskContext fireblast)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FIREBLAST);
                    fireblast.Repeat(14s, 28s);
                })
                .Schedule(20s, [this](TaskContext pyroblast)
                {
                    DoCast(SPELL_PYROBLAST);
                    pyroblast.Repeat(18s, 30s);
                });
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void UpdateAI(uint32 diff) override
        {
            // aura refresh
            if (!UpdateVictim())
            {
                if (!me->HasAura(SPELL_FIRE_ARMOR))
                    DoCastSelf(SPELL_FIRE_ARMOR);
                return;
            }

            CustomAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_pyromancerAI(creature);
    }
};

class npc_sunreaver_frosthand : public CreatureScript
{
    public:
    npc_sunreaver_frosthand() : CreatureScript("npc_sunreaver_frosthand") {}

    struct npc_sunreaver_frosthandAI : public CustomAI
    {
        npc_sunreaver_frosthandAI(Creature* creature) : CustomAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            scheduler
                .Schedule(5s, [this](TaskContext frostbotl)
                {
                    DoCast(SPELL_FROSTBOLT);
                    frostbotl.Repeat(5s, 8s);
                })
                .Schedule(14s, [this](TaskContext iceLance)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_ICE_LANCE);
                    iceLance.Repeat(14s, 28s);
                })
                .Schedule(20s, [this](TaskContext frostCone)
                {
                    DoCast(SPELL_FROST_CONE);
                    frostCone.Repeat(18s, 30s);
                });
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
            {
                if (!me->HasAura(SPELL_FROST_ARMOR))
                    DoCastSelf(SPELL_FROST_ARMOR);
                return;
            }

            CustomAI::UpdateAI(diff);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sunreaver_frosthandAI(creature);
    }
};

class npc_magister_brasael : public CreatureScript
{
    public:
    npc_magister_brasael() : CreatureScript("npc_magister_brasael") {}

    struct npc_magister_brasaelAI : public CustomAI
    {
        npc_magister_brasaelAI(Creature* creature) : CustomAI(creature),
            phase(PHASE_NORMAL), meteors(0), combustionUsed(false)
        {

        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_BRASAEL_AGGRO);
            SetCombatToNormal();
        }

        void DamageTaken(Unit* attacker, uint32& /*damage*/) override
        {
            if (attacker->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!combustionUsed && HealthBelowPct(80))
            {
                phase = PHASE_POSTCOMBUSTION;

                scheduler.Schedule(1s, PHASE_POSTCOMBUSTION, [this](TaskContext postcombustion)
                {
                    if (me->GetVictim()->GetTypeId() == TYPEID_PLAYER)
                    {
                        scheduler.CancelGroup(PHASE_NORMAL);

                        combustionUsed = true;

                        DoCastSelf(SPELL_POSTCOMBUSTION);

                        me->SetControlled(true, UNIT_STATE_ROOT);
                        me->NearTeleportTo(5966.76f, 613.82f, 650.62f, 2.77f);
                        me->PlayDistanceSound(3226, me->GetVictim()->ToPlayer());
                    }
                    else
                    {
                        phase = PHASE_NORMAL;
                        scheduler.CancelGroup(PHASE_POSTCOMBUSTION);
                    }
                });
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            me->SetControlled(false, UNIT_STATE_ROOT);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_POSTCOMBUSTION)
            {
                scheduler.Schedule(1s, PHASE_POSTCOMBUSTION, [this](TaskContext meteor)
                {
                    if (meteors > 2)
                    {
                        me->SetControlled(false, UNIT_STATE_ROOT);
                        SetCombatToNormal();
                        return;
                    }

                    meteors++;

                    const Position spellDestination = SelectTarget(SELECT_TARGET_RANDOM, 0)->GetPosition();
                    if (Creature* fx = DoSummon(NPC_INVISIBLE_STALKER, spellDestination, 7000, TEMPSUMMON_TIMED_DESPAWN))
                        fx->CastSpell(fx, SPELL_DUMMY_METEOR);

                    me->CastSpell(spellDestination, SPELL_METEOR);

                    meteor.Repeat(2830ms);
                });
            }
        }

        void JustDied(Unit* killer) override
        {
            KillCredit(killer);
        }

        void Reset() override
        {
            phase = PHASE_NORMAL;
            combustionUsed = false;
            meteors = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
            {
                if (!me->HasAura(SPELL_FIRE_ARMOR))
                    DoCastSelf(SPELL_FIRE_ARMOR);
                return;
            }

            CustomAI::UpdateAI(diff);
        }

        private:
        Phases phase;
        uint8 meteors;
        bool combustionUsed;

        void SetCombatToNormal()
        {
            phase = PHASE_NORMAL;

            scheduler
                .Schedule(5ms, PHASE_NORMAL, [this](TaskContext scorch)
                {
                    DoCast(SPELL_SCORCH);
                    scorch.Repeat(5s, 8s);
                })
                .Schedule(14s, PHASE_NORMAL, [this](TaskContext dragonBreath)
                {
                    DoCast(SPELL_DRAGON_BREATH);
                    dragonBreath.Repeat(14s, 28s);
                });
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_magister_brasaelAI(creature);
    }
};

void AddSC_npcs_sunreaver()
{
    new npc_sunreaver_assassin();
    new npc_sunreaver_duelist();
    new npc_sunreaver_pyromancer();
    new npc_sunreaver_frosthand();
    new npc_magister_brasael();
}
