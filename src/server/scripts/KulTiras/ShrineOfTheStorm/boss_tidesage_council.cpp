#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellHistory.h"
#include "shrine_of_the_storm.h"

enum Spells
{
    SPELL_COSMETIC_REINFORCING_WARD = 274690,
    SPELL_HINDERING_CLEAVE = 267899,
    SPELL_REINFORCING_WARD = 267905,
    SPELL_REINFORCING_WARD_DMG_DEC = 267904,
    SPELL_REINFORCING_WARD_REMOVE_NEG = 267952,
    SPELL_BLESSING_OF_IRONSIDES = 267901,

    SPELL_BLESSING_OF_THE_TEMPEST = 267830,
    SPELL_SLICING_BLAST = 267818,
    SPELL_SWIFTNESS_WARD = 267891,
    SPELL_SWIFTNESS_WARD_BUFF = 267888,
    SPELL_COSMETIC_SWIFTNESS_WARD = 274689,
    SPELL_BLOWBACK = 267842,
    SPELL_BLOWBACK_VISUAL = 267836,
    SPELL_BLOWBACK_DMG = 267838,

    SPELL_PERMANENT_FEIGN_DEATH = 70628,
};

enum Creatures
{
    BOSS_BROTHER_IRONHULL = 134063,
    BOSS_GALECALLER_FAYE = 134058,

    NPC_BLOWBACK = 136314,
};

enum Events
{
    EVENT_HINDERING_CLEAVE = 1,
    EVENT_REINFORCING_WARD,

    EVENT_SWIFTNESS_WARD,
    EVENT_SLICING_BLAST,

    EVENT_REGEN_MANA,

    EVENT_BLOWBACK_MOVEMENT,

    EVENT_BLESSING_OF_IRONSIDE,
    EVENT_BLESSING_OF_THE_TEMPEST,
};

enum Timers
{
    TIMER_REINFORCING_WARD = 1 * IN_MILLISECONDS,
    TIMER_SWIFTNESS_WARD = 1 * IN_MILLISECONDS,

    TIMER_REGEN_MANA = 2 * IN_MILLISECONDS, // both use this

    TIMER_HINDERING_CLEAVE = 18 * IN_MILLISECONDS,
    TIMER_SLICING_BLAST = 5 * IN_MILLISECONDS,

    TIMER_BLESSING_OF_IRONSIDE = 32 * IN_MILLISECONDS,
    TIMER_BLESSING_OF_THE_TEMPEST = 20 * IN_MILLISECONDS,
};

enum Actions
{
    ACTION_FINISH_OTHER = 1,
};

#define IRONHULL_AGGRO "The tides shall take you!"
#define IRONHULL_WARD "My hull is impenetrable"

#define FAYE_WARD "The breeze is ever at your backs!"
#define FAYE_BLOWBACK "Winds, protect me!"
#define FAYE_DEATH "The clouds... break..."

const Position centerPos = { 3939.35f, -1007.21f, 109.22f }; // cheaters

uint8 CouncilActive(InstanceScript* instance, Creature* me)
{
    uint8 count = 0;
    if (!instance || !me)
        return count;

    Creature* ironhull = instance->GetCreature(BOSS_BROTHER_IRONHULL);
    if (ironhull && ironhull->IsAlive())
        ++count;

    Creature* faye = instance->GetCreature(BOSS_GALECALLER_FAYE);
    if (faye && faye->IsAlive())
        ++count;

    return count;
}

// texts and sounds

class bfa_boss_brother_ironhull : public CreatureScript
{
public:
    bfa_boss_brother_ironhull() : CreatureScript("bfa_boss_brother_ironhull")
    {
    }

    struct bfa_boss_brother_ironhull_AI : public BossAI
    {
        bfa_boss_brother_ironhull_AI(Creature* creature) : BossAI(creature, DATA_TIDESAGE_COUNCIL)
        {
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;

        Creature* Faye()
        {
            return me->FindNearestCreature(BOSS_GALECALLER_FAYE, 500.0f, true);
        }

        void HandleWards()
        {
            if (Creature* fayeBoss = Faye())
                me->CastSpell(fayeBoss, SPELL_REINFORCING_WARD);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            _DespawnAtEvade(15);
            Reset();
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_FINISH_OTHER:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                break;
            }
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ()) >= 30.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        Creature* fayeDead()
        {
            return me->FindNearestCreature(BOSS_GALECALLER_FAYE, 500.0f, false);
        }


        void RespawnCouncilAtWipe()
        {
            if (Creature* faye = fayeDead())
            {
                faye->Respawn();
            }
        }

        void JustDied(Unit*)
        {
            if (instance)
            {
                switch (CouncilActive(instance, me))
                {
                case 1:
                    me->AddLootRecipient(NULL);
                    break;
                case 0:
                    if (Creature* faye = fayeDead())
                        faye->AI()->DoAction(ACTION_FINISH_OTHER);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    break;
                }
            }
        }

        void HandleManaRegen()
        {
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 10000);
            me->SetPower(POWER_MANA, 0);

            events.ScheduleEvent(EVENT_REGEN_MANA, TIMER_REGEN_MANA);
        }

        void Reset()
        {
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);
            if (Creature* faye = Faye())
                faye->SetInCombatWithZone();
            HandleManaRegen();
            events.ScheduleEvent(EVENT_HINDERING_CLEAVE, TIMER_HINDERING_CLEAVE);
            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_BLESSING_OF_IRONSIDE, TIMER_BLESSING_OF_IRONSIDE);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(IRONHULL_AGGRO, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(IRONHULL_WARD, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->IsInCombat())
                CheckCheaters();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_REGEN_MANA:
                    me->SetPower(POWER_MANA, me->GetPower(POWER_MANA) + 1000);
                    if (me->GetPower(POWER_MANA) == 10000)
                    {
                        events.ScheduleEvent(EVENT_REINFORCING_WARD, TIMER_REINFORCING_WARD);
                        me->SetPower(POWER_MANA, 0);
                    }
                    events.ScheduleEvent(EVENT_REGEN_MANA, TIMER_REGEN_MANA);
                    break;
                case EVENT_REINFORCING_WARD:
                {
                    SelectSoundAndText(me, 2);
                    std::ostringstream str;
                    str << "Brother Ironhull create a |cFFF00000|h[Reinforcing Ward]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);
                    HandleWards();
                    break;
                }
                case EVENT_BLESSING_OF_IRONSIDE:
                    me->CastSpell(me, SPELL_BLESSING_OF_IRONSIDES);
                    events.ScheduleEvent(EVENT_BLESSING_OF_IRONSIDE, TIMER_BLESSING_OF_IRONSIDE);
                    break;
                case EVENT_HINDERING_CLEAVE:
                    me->CastSpell(me->GetVictim(), SPELL_HINDERING_CLEAVE);
                    events.ScheduleEvent(EVENT_HINDERING_CLEAVE, TIMER_HINDERING_CLEAVE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_brother_ironhull_AI(creature);
    }
};

class bfa_boss_galecaller_faye : public CreatureScript
{
public:
    bfa_boss_galecaller_faye() : CreatureScript("bfa_boss_galecaller_faye")
    {
    }

    struct bfa_boss_galecaller_faye_AI : public BossAI
    {
        bfa_boss_galecaller_faye_AI(Creature* creature) : BossAI(creature, DATA_TIDESAGE_COUNCIL)
        {
            instance = me->GetInstanceScript();
        }
        EventMap events;
        InstanceScript* instance;

        void JustDied(Unit*)
        {
            if (instance)
            {
                switch (CouncilActive(instance, me))
                {
                case 1:
                    SelectSoundAndText(me, 2);
                    me->AddLootRecipient(NULL);
                    break;
                case 0:
                    if (Creature* ironhull = ironhullDead())
                        ironhull->AI()->DoAction(ACTION_FINISH_OTHER);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    break;
                }
            }
        }

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(FAYE_BLOWBACK, LANG_UNIVERSAL, NULL);
                    break;
                case 2:
                    me->Yell(FAYE_DEATH, LANG_UNIVERSAL, NULL);
                    break;
                }
            }
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_FINISH_OTHER:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                break;
            }
        }

        Creature* Ironhull()
        {
            return me->FindNearestCreature(BOSS_BROTHER_IRONHULL, 500.0f, true);
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ()) >= 30.0f)
                        {
                            me->Kill(player, false);
                            std::ostringstream str;
                            str << "CHEATERS!";
                            me->TextEmote(str.str().c_str(), 0, true);
                            return false;
                        }
                    }

                }

            return true;
        }

        void HandleWards()
        {
            if (Creature* ironhullBoss = Ironhull())
                me->CastSpell(ironhullBoss, SPELL_SWIFTNESS_WARD);
        }

        void Reset()
        {
            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            _DespawnAtEvade(15);
            Reset();
        }

        Creature* ironhullDead()
        {
            return me->FindNearestCreature(BOSS_BROTHER_IRONHULL, 500.0f, false);
        }


        void RespawnCouncilAtWipe()
        {
            if (Creature* ironhull = ironhullDead())
            {
                ironhull->Respawn();
            }
        }

        void HandleManaRegen()
        {
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 10000);
            me->SetPower(POWER_MANA, 0);

            events.ScheduleEvent(EVENT_REGEN_MANA, TIMER_REGEN_MANA);
        }

        void EnterCombat(Unit*)
        {
            if (Creature* iron = Ironhull())
                iron->SetInCombatWithZone();

            HandleManaRegen();
            events.ScheduleEvent(EVENT_SLICING_BLAST, TIMER_SLICING_BLAST);
            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_BLESSING_OF_THE_TEMPEST, TIMER_BLESSING_OF_THE_TEMPEST);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->IsInCombat())
                CheckCheaters();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_REGEN_MANA:
                    me->SetPower(POWER_MANA, me->GetPower(POWER_MANA) + 1000);
                    if (me->GetPower(POWER_MANA) == 10000)
                    {
                        events.ScheduleEvent(EVENT_SWIFTNESS_WARD, TIMER_SWIFTNESS_WARD);
                        me->SetPower(POWER_MANA, 0);
                    }
                    events.ScheduleEvent(EVENT_REGEN_MANA, TIMER_REGEN_MANA);
                    break;
                case EVENT_SWIFTNESS_WARD:
                {
                    std::ostringstream str;
                    str << "Galecaller Faye creates a |cFFF00000|h[Swiftness Ward]|h|r!";
                    me->TextEmote(str.str().c_str(), 0, true);
                    HandleWards();
                    break;
                }
                case EVENT_BLESSING_OF_THE_TEMPEST:
                    me->CastSpell(me, SPELL_BLESSING_OF_THE_TEMPEST);
                    events.ScheduleEvent(EVENT_BLESSING_OF_THE_TEMPEST, TIMER_BLESSING_OF_THE_TEMPEST);
                    break;
                case EVENT_SLICING_BLAST:
                    me->CastSpell(me->GetVictim(), SPELL_SLICING_BLAST);
                    events.ScheduleEvent(EVENT_SLICING_BLAST, TIMER_SLICING_BLAST);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void OnSpellCastInterrupt(SpellInfo const* spell) override
        {
            if (me->HasAura(SPELL_BLESSING_OF_THE_TEMPEST))
            {
                SelectSoundAndText(me, 1);
                me->GetSpellHistory()->LockSpellSchool(SPELL_SCHOOL_MASK_NATURE, 0);
                me->CastSpell(me, SPELL_BLOWBACK, true);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_galecaller_faye_AI(creature);
    }
};

enum BlowbackEvents
{
    EVENT_CHECK_PLAYER_BLOWBACK = 1,
};

class bfa_npc_blowback : public CreatureScript
{
public:
    bfa_npc_blowback() : CreatureScript("bfa_npc_blowback")
    {
    }

    struct bfa_npc_blowback_AI : public ScriptedAI
    {
        bfa_npc_blowback_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            me->CastSpell(me, SPELL_BLOWBACK_VISUAL, true);
            events.ScheduleEvent(EVENT_CHECK_PLAYER_BLOWBACK, 2500);
            me->GetMotionMaster()->MoveRandom(10.0f);
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
        }

        void CheckNearbyPlayers()
        {
            Map::PlayerList const& players = me->GetMap()->GetPlayers();

            if (!players.isEmpty())
            {
                for (auto& it : players)
                {
                    if (Player* player = it.GetSource())
                    {
                        if (me->GetDistance2d(player) <= 2.0f)
                            me->CastSpell(player, SPELL_BLOWBACK_DMG, true);
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER_BLOWBACK:
                    CheckNearbyPlayers();
                    events.ScheduleEvent(EVENT_CHECK_PLAYER_BLOWBACK, 2500);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_blowback_AI(creature);
    }
};

// Spell 267891 Swiftness Ward
// AT 17766
class bfa_swiftness_ward_at : public AreaTriggerEntityScript
{
public:
    bfa_swiftness_ward_at() : AreaTriggerEntityScript("bfa_swiftness_ward_at") { }

    struct bfa_swiftness_ward_at_AI : AreaTriggerAI
    {
        bfa_swiftness_ward_at_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (!unit->HasAura(SPELL_SWIFTNESS_WARD_BUFF))
                unit->CastSpell(unit, SPELL_SWIFTNESS_WARD_BUFF, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(SPELL_SWIFTNESS_WARD_BUFF);
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_swiftness_ward_at_AI(areatrigger);
    }
};

// Spell 267905 Reinforcing Ward
// AT 17771
class bfa_reinforcing_ward_at : public AreaTriggerEntityScript
{
public:
    bfa_reinforcing_ward_at() : AreaTriggerEntityScript("bfa_reinforcing_ward_at") { }

    struct bfa_reinforcing_ward_at_AI : AreaTriggerAI
    {
        bfa_reinforcing_ward_at_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            if (!unit->HasAura(SPELL_REINFORCING_WARD_DMG_DEC))
                unit->CastSpell(unit, SPELL_REINFORCING_WARD_DMG_DEC, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(SPELL_REINFORCING_WARD_DMG_DEC);
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new bfa_reinforcing_ward_at_AI(areatrigger);
    }
};

void AddSC_boss_tidesage_council()
{
    new bfa_boss_brother_ironhull();
    new bfa_boss_galecaller_faye();
    new bfa_npc_blowback();

    new bfa_reinforcing_ward_at();
    new bfa_swiftness_ward_at();
}
