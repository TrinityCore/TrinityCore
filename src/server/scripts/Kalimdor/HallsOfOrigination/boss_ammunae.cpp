#include "ScriptMgr.h"
#include "halls_of_origination.h"
#include "Vehicle.h"
#include "SpellAuras.h"

enum Spells
{
    SPELL_WITHER                    = 76043,
    SPELL_CONSUME_LIFE_ENERGY       = 75665,
    SPELL_CONSUME_ENERGY            = 79766,
    SPELL_CONSUME_RAGE              = 79767,
    SPELL_CONSUME_RUNIC_POWER       = 79768,
    SPELL_CONSUME_MANA              = 75718,
    SPELL_CONSUME_FOCUS             = 80968,
    SPELL_SUMMON_SPORE              = 75866,
    SPELL_RAMPANT_GROWTH            = 75790,

    SPELL_SPORE_BLAST               = 75153,
    SPELL_SPORE_CLOUD               = 75701,
};

enum Events
{
    EVENT_WITHER                    = 1,
    EVENT_CONSUME_LIFE,
    EVENT_SUMMON_POD,
    EVENT_SUMMON_SPORE,

    EVENT_SPORE_BLAST,
    EVENT_SPORE_CLOUD,
};

enum Misc
{
    NPC_SEEDLING_POD                = 51329,
    DATA_RAMPANT_GROWTH             = 1
};

enum Quotes
{
    SAY_AGGRO,
    SAY_DEATH,
    SAY_SLAY,
    SAY_RAMPANT_GROWTH
};

class boss_ammunae : public CreatureScript
{
    struct boss_ammunaeAI : public BossAI
    {
        boss_ammunaeAI(Creature * creature) : BossAI(creature, DATA_AMMUNAE)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 89889, true); // Noxious Spores
        }

        void Reset() override
        {
            _Reset();
            me->SetPower(POWER_ENERGY, 0);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _EnterCombat();
            events.ScheduleEvent(EVENT_WITHER, urand(5000, 7000));
            events.ScheduleEvent(EVENT_CONSUME_LIFE, urand(10000, 12000));
            events.ScheduleEvent(EVENT_SUMMON_POD, urand(10000, 12000));
            events.ScheduleEvent(EVENT_SUMMON_SPORE, urand(15000, 20000));
        }

        void KilledUnit(Unit* victim) override
        {
            if(victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(me->GetPower(POWER_ENERGY) == 100)
            {
                DoCast(SPELL_RAMPANT_GROWTH);
                std::list<Creature*> cList;
                me->GetCreatureListWithEntryInGrid(cList, NPC_SEEDLING_POD, 100.0f);
                if(!cList.empty())
                    for(std::list<Creature *>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                        (*itr)->AI()->SetData(DATA_RAMPANT_GROWTH, 1);
                return;
            }

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_WITHER:
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_WITHER);
                    events.ScheduleEvent(EVENT_WITHER, urand(10000, 15000));
                    break;
                case EVENT_CONSUME_LIFE:
                    if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        uint32 spellId = 0;
                        switch(target->GetPowerType())
                        {
                        case POWER_MANA:
                            spellId = SPELL_CONSUME_MANA;
                            break;
                        case POWER_RAGE:
                            spellId = SPELL_CONSUME_RAGE;
                            break;
                        case POWER_ENERGY:
                            spellId = SPELL_CONSUME_ENERGY;
                            break;
                        case POWER_FOCUS:
                            spellId = SPELL_CONSUME_FOCUS;
                            break;
                        case POWER_RUNIC_POWER:
                            spellId = SPELL_CONSUME_RUNIC_POWER;
                            break;
                        default:
                            break;
                        }

                        if(spellId)
                        {
                            DoCast(me, SPELL_CONSUME_LIFE_ENERGY, true);
                            DoCast(target, spellId, false);
                        }
                    }
                    events.ScheduleEvent(EVENT_CONSUME_LIFE, urand(18000, 20000));
                    break;
                case EVENT_SUMMON_POD:
                    {
                        Position pos;
                        pos = me->GetRandomNearPosition(20.0f);
                        me->SummonCreature(NPC_BLOODPETAL_BLOSSOM, pos);
                    }
                    events.ScheduleEvent(EVENT_SUMMON_POD, urand(10000, 12000));
                    break;
                case EVENT_SUMMON_SPORE:
                    DoCast(SPELL_SUMMON_SPORE);
                    events.ScheduleEvent(EVENT_SUMMON_SPORE, urand(20000, 25000));
                    break;
                }
            }

            DoMeleeAttackIfReady();

            //EnterEvadeIfOutOfCombatArea(diff);
        }
    };
public:
    boss_ammunae() : CreatureScript("boss_ammunae") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ammunaeAI(creature);
    }
};

class npc_bloodpetal_blossom : public CreatureScript
{
    enum
    {
        SPELL_SEEDLING_VISUAL           = 96278,
        SPELL_SPAWN_VISUAL              = 75687,
        SPELL_THORN_SLASH               = 76044,
        SPELL_BLOSSOM_VISUAL            = 75768,
        SPELL_ENERGIZE                  = 75657,
        SPELL_ENERGIZE_HC               = 89123,
    };

    struct npc_bloodpetal_blossomAI : public ScriptedAI
    {
        npc_bloodpetal_blossomAI(Creature * creature) : ScriptedAI(creature)
        {
            done = false;
            me->UpdateEntry(NPC_SEEDLING_POD);
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override
        {
            DoCast(SPELL_SPAWN_VISUAL);
            if(IsHeroic())
                DoCast(SPELL_ENERGIZE_HC);
            actionTimer = urand(15000, 18000);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if(Aura* aur = summoner->GetAura(SPELL_ENERGIZE))
                aur->ModStackAmount(1);
            else
                summoner->AddAura(SPELL_ENERGIZE, summoner);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (TempSummon* summon = me->ToTempSummon())
                if (Unit* summoner = summon->GetSummoner())
                    summoner->RemoveAuraFromStack(SPELL_ENERGIZE);
        }

        void SetData(uint32 type, uint32) override
        {
            if(!done && type == DATA_RAMPANT_GROWTH)
                actionTimer = 100;
        }

        void UpdateAI(uint32 diff) override
        {
            if(!done)
            {
                if(actionTimer <= diff)
                {
                    done = true;
                    me->RemoveAurasDueToSpell(SPELL_SEEDLING_VISUAL);
                    me->RemoveAurasDueToSpell(SPELL_ENERGIZE);
                    me->RemoveAurasDueToSpell(SPELL_ENERGIZE_HC);
                    me->UpdateEntry(NPC_BLOODPETAL_BLOSSOM);
                    DoCast(SPELL_BLOSSOM_VISUAL);
                    me->SetHealth(me->GetMaxHealth());
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    actionTimer = urand(5000, 8000);
                }else actionTimer -= diff;
            }
            else
            {
                if(!UpdateVictim())
                    return;

                if(actionTimer <= diff)
                {
                    DoCastVictim(SPELL_THORN_SLASH);
                    actionTimer = urand(5000, 7500);
                }else actionTimer -= diff;
            }
        }
    private:
        bool done;
        uint32 actionTimer;
    };

public:
    npc_bloodpetal_blossom() : CreatureScript("npc_bloodpetal_blossom") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_bloodpetal_blossomAI(creature);
    }
};


class npc_ammunae_spore : public CreatureScript
{
    enum
    {
        SPELL_SPORE_CLOUD               = 75701
    };

    struct npc_ammunae_sporeAI : public ScriptedAI
    {
        npc_ammunae_sporeAI(Creature * creature) : ScriptedAI(creature) {}

        void DamageTaken(Unit* /*done_by*/, uint32& damage) override
        {
            if(damage >= me->GetHealth())
            {
                damage = 0;
                me->RemoveAllAuras();
                me->StopMoving();
                me->SetReactState(REACT_PASSIVE);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                DoCast(SPELL_SPORE_CLOUD);
                me->SetHealth(0);
            }
        }
    };

public:
    npc_ammunae_spore() : CreatureScript("npc_ammunae_spore") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ammunae_sporeAI(creature);
    }
};

class npc_living_vine : public CreatureScript
{
public:
    npc_living_vine() : CreatureScript("npc_living_vine") { }

    struct npc_living_vineAI : public ScriptedAI
    {
        npc_living_vineAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
            me->ApplySpellImmune(0, IMMUNITY_ID, 75701, true); // Noxious Spores
        }

        void Reset() override
        {
            events.Reset();

            if(Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
               passenger->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SPORE_BLAST, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if(Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
               passenger->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            me->DespawnOrUnsummon(100);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SPORE_BLAST:
                    DoCastRandom(SPELL_SPORE_BLAST, 40.0f);
                    events.ScheduleEvent(EVENT_SPORE_BLAST, 5000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_living_vineAI (creature);
    }
};

class mob_spore : public CreatureScript
{
public:
    mob_spore() : CreatureScript("mob_spore") { }

    struct mob_sporeAI : public ScriptedAI
    {
        mob_sporeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, 75701, true); // Noxious Spores
        }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SPORE_CLOUD, 2000);
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                case EVENT_SPORE_CLOUD:
                    DoCastAOE(SPELL_SPORE_CLOUD);
                    events.ScheduleEvent(EVENT_SPORE_CLOUD, 10000);
                    break;
                }
            }
        }
    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_sporeAI (creature);
    }
};

void AddSC_boss_ammunae()
{
    new boss_ammunae();
    new npc_bloodpetal_blossom();
    new npc_ammunae_spore();
    new npc_living_vine();
    new mob_spore();
};
