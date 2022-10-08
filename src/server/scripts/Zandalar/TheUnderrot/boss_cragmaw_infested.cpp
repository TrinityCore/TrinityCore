#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "the_underrot.h"

enum Spells
{
    SPELL_CRAWG_EATING                  = 279156,

    SPELL_INFESTED                      = 260477,
    SPELL_CHARGE                        = 260292, // spawn 12 random pos lava, change spellinfo effect target
    SPELL_CHARGE_DAMAGE                 = 260312,
    SPELL_INDIGESTION                   = 260793,

    SPELL_TANTRUM_ENERGY_VISUAL         = 271771,
    SPELL_TANTRUM_ENERGY_PERIODIC       = 271775,
    SPELL_TANTRUM                       = 260333,

    SPELL_BLOOD_TICK_SPELL_DEST = 260391,
    SPELL_LARVA_SUMMON_VISUAL           = 260411, // visual on npc larves
    SPELL_LARVA_SUMMON_BLOOD_TICK       = 260353,
    SPELL_LARVA_METAMORPHOSIS           = 260416,
    SPELL_LARVA_METAMORPHOSIS_2         = 260766,
    SPELL_LARVA_DESTROY                 = 260418, // visual on blood is created

    SPELL_BLOOD_TICK_SPAWN              = 260768, // on blood ticks at spawn, size increase
    SPELL_BLOOD_TICK_SERRATED_FANGS     = 260455,
    SPELL_BLOOD_TICK_BLOOD_BURST        = 278641,
    SPELL_BLOOD_TICK_BLOOD_BURST_DAMAGE = 278637,
};

enum Events
{
    EVENT_ENERGY_REGEN = 1,
    EVENT_CHARGE_TARGET,
    EVENT_INDIGESTION,
    EVENT_TANTRUM,

    EVENT_METAMORPHOSIS,
    EVENT_SERRATED_FANGS,
};

enum Timers
{
    TIMER_ENERGY_REGEN = 2 * IN_MILLISECONDS,
    TIMER_CHARGE = 20 * IN_MILLISECONDS,
    TIMER_INDIGESTION = 8 * IN_MILLISECONDS,
    TIMER_SERRATED_FANGS = 3 * IN_MILLISECONDS,
    TIMER_SERRATED_FANGS_AFTER = 10 * IN_MILLISECONDS,
    TIMER_METAMORPHOSIS = 10 * IN_MILLISECONDS,
};

enum Creatures
{
    BOSS_CRAGMAW_THE_INFESTED = 131817,

    NPC_BLOOD_TICK = 132051,
    NPC_LARVES = 132080,
};

enum Points
{
    POINT_ONE = 1,
    POINT_TWO = 2,
    POINT_THREE = 3,
};

const Position centerZone = { 856.38f, 981.99f, 39.14f  }; // cheaters

class bfa_boss_cragmaw_the_infested : public CreatureScript
{
public:
    bfa_boss_cragmaw_the_infested() : CreatureScript("bfa_boss_cragmaw_the_infested")
    {}

    struct bfa_boss_cragmaw_the_infested_AI : public BossAI
    {
        bfa_boss_cragmaw_the_infested_AI(Creature* creature) : BossAI(creature, DATA_CRAGMAW_THE_INFESTED)
        {
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;

        void Reset()
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            events.Reset();
            DespawnCreature(NPC_BLOOD_TICK);
            DespawnCreature(NPC_LARVES);

        }

        void DespawnCreature(uint32 entry)
        {
            std::list<Creature*> cList;
            me->GetCreatureListWithEntryInGrid(cList, entry, 500.0f);
            if (!cList.empty())
                for (std::list<Creature*>::const_iterator itr = cList.begin(); itr != cList.end(); ++itr)
                    (*itr)->DespawnOrUnsummon();
        }

        bool CheckCheaters()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(centerZone.GetPositionX(), centerZone.GetPositionY(), centerZone.GetPositionZ()) >= 80.0f)
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

        void JustDied(Unit*)
        {
            DespawnCreature(NPC_BLOOD_TICK);
            DespawnCreature(NPC_LARVES);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            DespawnCreature(NPC_BLOOD_TICK);
            DespawnCreature(NPC_LARVES);
            _DespawnAtEvade(15);
        }

        void MovementInform(uint32 uiType, uint32 id)
        {
            switch (id)
            {
            case POINT_ONE:
                if(me->HasAura(SPELL_TANTRUM))
                    me->GetMotionMaster()->MovePoint(2, 839.35f, 968.41f, 40.61f, false);
                else
                {
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(MOVE_WALK, 1.5f);
                    me->SetSpeed(MOVE_RUN, 1.5f);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetSpeed(MOVE_FLIGHT, 1.5f);
                }
                break;
            case POINT_TWO:
                if(me->HasAura(SPELL_TANTRUM))
                    me->GetMotionMaster()->MovePoint(3, 863.21f, 1015.53f, 39.90f, false);
                else
                {
                    me->GetMotionMaster()->Clear();
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetSpeed(MOVE_WALK, 1.5f);
                    me->SetSpeed(MOVE_RUN, 1.5f);
                    me->SetSpeed(MOVE_FLIGHT, 1.5f);
                }
                break;
            case POINT_THREE:
                me->SetReactState(REACT_AGGRESSIVE);
                me->GetMotionMaster()->Clear();
                me->SetSpeed(MOVE_WALK, 1.5f);
                me->SetSpeed(MOVE_RUN, 1.5f);
                me->SetSpeed(MOVE_FLIGHT, 1.5f);
                break;
            }
        }
        // too many effecttargets to corret, handle this way
        void HandleLarveSpawnBySpell(bool bigWave)
        {
            if (!me->GetVictim())
                return;

            if (bigWave)
            {
                // 12 larves, CHARGE SPELL
                // select random position based on our current position
                float Myx;
                float Myy;

                Myx = me->GetPositionX();

                Myy = me->GetPositionY();

                // main spell has 12 missiles
                for (uint8 i = 0; i < 12; ++i)
                    me->CastSpell(Myx + urand(2, 10) , Myy - urand(2, 10), me->GetPositionZ(), SPELL_BLOOD_TICK_SPELL_DEST, true);

            }
            else
            {
                // 4 larves INDIGESTION
                // target random in front of caster
                float x;
                float y;

                // we take tank as main point and play with values
                x = me->GetVictim()->GetPositionX();
                y = me->GetVictim()->GetPositionY();

                for (uint8 i = 0; i < 4; ++i)
                    me->CastSpell(x + urand(3, 5), y - urand(3,7), me->GetPositionZ(), SPELL_BLOOD_TICK_SPELL_DEST, true);

            }
        }

        void EnterCombat(Unit*)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);

            events.ScheduleEvent(EVENT_INDIGESTION, TIMER_INDIGESTION);
            events.ScheduleEvent(EVENT_CHARGE_TARGET, TIMER_CHARGE);

            if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
                events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
        }

        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_CHARGE:
                HandleLarveSpawnBySpell(true);
                break;
            case SPELL_INDIGESTION:
                HandleLarveSpawnBySpell(false);
                break;
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
                case EVENT_ENERGY_REGEN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 2);
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        events.ScheduleEvent(EVENT_TANTRUM, 1000);
                        me->SetPower(POWER_ENERGY, 0);
                    }
                    events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
                    break;
                case EVENT_TANTRUM:
                    me->SetSpeed(MOVE_WALK, 4.5f);
                    me->SetSpeed(MOVE_RUN, 4.5f);
                    me->SetSpeed(MOVE_FLIGHT, 4.5f);
                    me->GetMotionMaster()->MovePoint(POINT_ONE, 888.63f, 967.30f, 41.06f, false);
                    me->SetReactState(REACT_PASSIVE);
                    me->CastSpell(me, SPELL_TANTRUM, true);
                    break;
                case EVENT_INDIGESTION:
                    me->CastSpell(me->GetVictim(), SPELL_INDIGESTION);
                    events.ScheduleEvent(EVENT_INDIGESTION, TIMER_INDIGESTION);
                    break;
                case EVENT_CHARGE_TARGET:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    {
                        me->CastSpell(target, SPELL_CHARGE);
                    }
                    events.ScheduleEvent(EVENT_CHARGE_TARGET, TIMER_CHARGE);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_cragmaw_the_infested_AI(creature);
    }
};

class bfa_npc_blood_larves : public CreatureScript
{
public:
    bfa_npc_blood_larves() : CreatureScript("bfa_npc_blood_larves")
    {}

    struct bfa_npc_blood_larves_AI : public ScriptedAI
    {
        bfa_npc_blood_larves_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetDisplayId(88361);
            me->AddAura(167209, me); // hack fix because aura tend to disappear sometimes and we set an arrow and displayid
        }

        EventMap events;

        void Reset()
        {
            me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 2.0f, me->GetOrientation()); //safety
            events.ScheduleEvent(EVENT_METAMORPHOSIS, TIMER_METAMORPHOSIS);
            me->CastSpell(me, SPELL_LARVA_SUMMON_VISUAL, true);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (player->GetDistance(me) <= 0.5f)
                        {
                            me->CastSpell(player, SPELL_LARVA_DESTROY, true);
                            me->ForcedDespawn();
                        }
                    }
                }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_METAMORPHOSIS:
                    if (Creature* tick = me->SummonCreature(NPC_BLOOD_TICK, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN))
                        tick->SetInCombatWithZone();
                    me->ForcedDespawn();
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_blood_larves_AI(creature);
    }
};

class bfa_npc_blood_tick : public CreatureScript
{
public:
    bfa_npc_blood_tick() : CreatureScript("bfa_npc_blood_tick")
    {}

    struct bfa_npc_blood_tick_AI : public ScriptedAI
    {
        bfa_npc_blood_tick_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddAura(SPELL_BLOOD_TICK_SPAWN, me);
            me->AddAura(SPELL_LARVA_METAMORPHOSIS_2, me);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            events.ScheduleEvent(EVENT_SERRATED_FANGS, TIMER_SERRATED_FANGS);
        }

        void DamageTaken(Unit* killer, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                me->CastSpell(killer, SPELL_BLOOD_TICK_BLOOD_BURST_DAMAGE, true);
                me->DespawnOrUnsummon(1000);
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SERRATED_FANGS:
                    me->CastSpell(me->GetVictim(), SPELL_BLOOD_TICK_SERRATED_FANGS);
                    events.ScheduleEvent(EVENT_SERRATED_FANGS, TIMER_SERRATED_FANGS_AFTER);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_blood_tick_AI(creature);
    }
};


// at 17014
class bfa_at_cragmaw_charge : public AreaTriggerEntityScript
{
public:
    bfa_at_cragmaw_charge() : AreaTriggerEntityScript("bfa_at_cragmaw_charge")
    {}

    struct bfa_at_cragmaw_charge_AI : public AreaTriggerAI
    {
        bfa_at_cragmaw_charge_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
                caster->CastSpell(unit, SPELL_CHARGE_DAMAGE, true);
    }

    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new bfa_at_cragmaw_charge_AI(at);
    }
};


void AddSC_boss_cragmaw_infested()
{
    new bfa_boss_cragmaw_the_infested();
    new bfa_npc_blood_larves();
    new bfa_npc_blood_tick();

    new bfa_at_cragmaw_charge();
}
