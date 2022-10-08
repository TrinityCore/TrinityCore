#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "operation_mechagon.h"

enum Spells
{
    SPELL_CHARGED_SMASH = 297254,
    SPELL_ELECTRICAL_CHARGE = 297257,
    SPELL_RUMBLE = 297261,
    SPELL_PERIODIC_ENERGY_GAIN = 295065,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SMASH,
    SAY_RUMBLE,
    SAY_GETEM,
    SAY_KILL,
    SAY_DEATH
};

enum Events
{
    EVENT_CHARGED_SMASH = 1,
    EVENT_ELECTRICAL_CHARGE,
    EVENT_RUMBLE,
    EVENT_GETEM
};

const Position cave_pos = { 1188.0f, -75.0f, 21.84f, 3.59f };

//150159
struct boss_king_gobbamak : public BossAI
{
    boss_king_gobbamak(Creature* creature) : BossAI(creature, DATA_KING_GOBBAMAK) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_OCEAN);
        me->SetPower(POWER_ENERGY, 0);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        this->pack_counter = 0;
        _EnterCombat();
        Talk(SAY_AGGRO);
        me->SetPower(POWER_ENERGY, 33);
        DoCastSelf(SPELL_PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_ELECTRICAL_CHARGE, 3s);
        events.ScheduleEvent(EVENT_RUMBLE, 8s);
        events.ScheduleEvent(EVENT_CHARGED_SMASH, 12s);
        events.ScheduleEvent(EVENT_GETEM, 17s);
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        me->DespawnCreaturesInArea(NPC_STOLEN_SCRAPBOT, 125.0f);
        me->DespawnCreaturesInArea(NPC_STOLEN_SHOCK_COIL, 125.0f);
        me->DespawnCreaturesInArea(NPC_SCRAPBONE_GRUNTER, 125.0f);
        instance->DoModifyPlayerCurrencies(1553, 35);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();

        me->DespawnCreaturesInArea(NPC_SCRAPBONE_GRUNTER);
        if (Creature* stolen_scrapbot = me->FindNearestCreature(NPC_STOLEN_SCRAPBOT, 100.0f, true))
        {            
            stolen_scrapbot->ForcedDespawn(0, 1s);            
        }

        std::list<Creature*> _shock;
        _shock.clear();
        me->GetCreatureListWithEntryInGrid(_shock, NPC_STOLEN_SHOCK_COIL, 100.0f);
        for (auto& stolen_shock_coil : _shock)
        {            
            stolen_shock_coil->ForcedDespawn(0, 1s);
        }
    }

    void KilledUnit(Unit* unit) override
    {
        uint32 randomChance = urand(0, 1);

        if (unit->IsPlayer())
        {
            switch (randomChance)
            {
            case 0:
                return;
                break;

            case 1:
                Talk(SAY_KILL);
                break;
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
        case NPC_SCRAPBONE_GRUNTER:
            summon->AI()->DoZoneInCombat(nullptr);
            break;
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        if (me->GetPower(POWER_ENERGY) == 100)
        {
            me->SetPower(POWER_ENERGY, 0);
            Talk(SAY_SMASH);            
            DoCastVictim(SPELL_CHARGED_SMASH, false);
        }

        switch (eventid)
        {
        case EVENT_ELECTRICAL_CHARGE:
            DoCastRandom(SPELL_ELECTRICAL_CHARGE, 100.0f, true);
            events.Repeat(15s);
            break;

        case EVENT_RUMBLE:
            Talk(SAY_RUMBLE);
            me->StopMoving();
            DoCastSelf(SPELL_RUMBLE);
            events.Repeat(45s);
            break;

        case EVENT_GETEM:
            Talk(SAY_GETEM);
            me->GetScheduler().Schedule(3s, [this] (TaskContext context)
            {
                for (uint8 i = 0; i < 4; i++)
                {
                    pack_counter++;
                    me->SummonCreature(NPC_SCRAPBONE_GRUNTER, cave_pos, TEMPSUMMON_MANUAL_DESPAWN);
                }                

                if (this->pack_counter < 4)
                    context.Repeat(3s);

                else this->pack_counter = 0;
            });
            events.Repeat(25s);
            break;
        }
    }

private:
    uint8 pack_counter;
};

enum Misc
{
    PHASE_ON = 1,
    PHASE_OFF,
    SPELL_THRASH = 297382,
    SPELL_ZAP = 297543,
    EVENT_THRASH = 1,
    EVENT_ZAP = 2,
    EVENT_CHECK_CHARGE,
};

//153172
struct npc_stolen_scrapbot : public ScriptedAI
{
    npc_stolen_scrapbot(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (Creature* gobbamak = me->FindNearestCreature(NPC_SCRAPBONE_GRUNTER, 30.0f, true))
        {
            if (gobbamak->IsInCombat())
            {
                std::list<Player*> p_li;
                p_li.clear();
                me->GetPlayerListInGrid(p_li, 30.0f);
                for (auto& players : p_li)
                {
                    if (players->HasAura(SPELL_ELECTRICAL_CHARGE))
                    {
                        Thrash();
                    }
                }
            }
        }
    }

    void Thrash()
    {
        std::list<Creature*>_troggs;
        _troggs.clear();
        me->GetCreatureListWithEntryInGrid(_troggs, NPC_SCRAPBONE_GRUNTER, 15.0f);
        if (!_troggs.empty())
        {
            for (auto& trogs : _troggs)
            {
                trogs->CastSpell(nullptr, SPELL_THRASH, true);
                me->Kill(trogs, false);
            }
        }
    }
};

//153172
struct npc_scrapbone_grunter : public ScriptedAI
{
    npc_scrapbone_grunter(Creature* creature) : ScriptedAI(creature) { }
};

//153245
struct npc_stolen_shock_coil : public ScriptedAI
{
    npc_stolen_shock_coil(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (Creature* gobbamak = me->FindNearestCreature(NPC_SCRAPBONE_GRUNTER, 30.0f, true))
        {
            if (gobbamak->IsInCombat())
            {
                std::list<Player*> p_li;
                p_li.clear();
                me->GetPlayerListInGrid(p_li, 30.0f);
                for (auto& players : p_li)
                {
                    if (players->HasAura(SPELL_ELECTRICAL_CHARGE))
                    {
                        Zap();
                    }
                }
            }
        }
    }

    void Zap()
    {
        std::list<Creature*>_troggs;
        _troggs.clear();
        me->GetCreatureListWithEntryInGrid(_troggs, NPC_SCRAPBONE_GRUNTER, 15.0f);
        if (!_troggs.empty())
        {
            for (auto& trogs : _troggs)
            {
                trogs->CastSpell(nullptr, SPELL_ZAP, true);
                me->Kill(trogs, false);
            }
        }
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_king_gobbamak()
{
    RegisterCreatureAI(boss_king_gobbamak);
    RegisterCreatureAI(npc_stolen_scrapbot);
    RegisterCreatureAI(npc_scrapbone_grunter);
    RegisterCreatureAI(npc_stolen_shock_coil);
}