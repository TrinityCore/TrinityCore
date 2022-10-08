#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "the_underrot.h"

enum Spells
{
    SPELL_BLOOD_BARRIER                     = 269185,
    SPELL_PUTRID_BLOOD_AURA                 = 269303,
    SPELL_PUTRID_BLOOD = 269301,
    SPELL_VILE_EXPULSION                    = 269843,
    SPELL_VILE_EXPULSION_SPORE_DEATH_DAMAGE = 250950,
    SPELL_VILE_EXPULSION_AT_DAMAGE          = 269838,
    SPELL_VILE_EXPULSION_MISSILE_SPAWN      = 269813, // 5 YARDS
    SPELL_VILE_EXPULSION_SPAWN              = 269836,
    SPELL_DISOLVE_CORPSE                    = 265640,
    SPELL_CORPSE_TRANSFORM                  = 265635,
    SPELL_ROTTING_SPORE_SPAWN               = 270104,
    SPELL_ROTTING_SPORE_FIXATE              = 270107,
    SPELL_ROTTING_SPORE_DAMAGE              = 270108,
    // Blood Visage
    SPELL_BLOOD_CLONE_COSMETIC              = 272663,
    SPELL_FATAL_LINK                        = 269692,
    // Titan Keeper Hezrel
    // Pre-boss event
    SPELL_SHADOW_VISUAL                     = 279551,
    SPELL_HOLY_CHANNEL                      = 279250,
    SPELL_OPEN_WEB_DOOR                     = 279271,
    SPELL_UPDATE_INTERACTIONS               = 187114,
    // Boss fight
    SPELL_HOLY_BOLT                         = 269312,
    SPELL_CLEANSING_LIGHT                   = 269310,
    SPELL_PURGE_CORRUPTION                  = 269406,
    SPELL_PERMANENT_FEIGN_DEATH             = 29266,
};

enum Events
{
    EVENT_PUTRID_BLOOD = 1,
    EVENT_VILE_EXPULSION,

    EVENT_CHECK_ENERGY,

    EVENT_CLEANSING_LIGHT,
    EVENT_HOLY_BOLT,
    EVENT_PURGE_CORRUPTION,

    EVENT_FIXATE_FOLLOW,
    EVENT_CHECK_DIST_PLAYER,
    EVENT_FIXATE,
};

enum Timers
{
    TIMER_FIXATE_PLAYER = 1500,
    TIMER_CHECK_ENERGY = 5 * IN_MILLISECONDS,
    TIMER_VILE_EXPULSION = 15 *IN_MILLISECONDS,
    TIMER_PUTRID_BLOOD = 10 * IN_MILLISECONDS,

    TIMER_CLEANSING_LIGHT = 20 * IN_MILLISECONDS,
    TIMER_PURGE_CORRUPTION = 7 * IN_MILLISECONDS,
    TIMER_HOLY_BOLT = 5 * IN_MILLISECONDS,

};

enum Actions
{
    ACTION_COUNT_VISAGE = 1,
};

enum Creatures
{
    BOSS_UNBOUND_ABOMINATION = 133007,
}; 

const Position centerPosition = { 1199.420044f, 1481.939941f, -181.505997f };

enum Sounds
{
    SOUND_AGGRO_TITAN = 104794,
    SOUND_AGGRO_UNBOUND = 102970,
    SOUND_UNBOUND_VILE = 102967,
    SOUND_UNBOUND_DEATH = 102966,
    SOUND_TITAN_CLEANSING = 104788,
    SOUND_TITAN_PURGE_CORRUPTION = 104790,
};

#define TITAN_AGGRO "Virulent specimen Detected. Containment priority one."
#define UNBOUND_AGGRO "Devour! Consume! Spread!"
#define UNBOUND_VILE "Infected!"
#define UNBOUND_DEATH "Must... spread..."
#define TITAN_CLEANSING "Cleansing area."
#define TITAN_PURGE_CORRUPTION "Contagion detected. Sanitize."

class bfa_boss_unbound_abomination : public CreatureScript
{
public:
    bfa_boss_unbound_abomination() : CreatureScript("bfa_boss_unbound_abomination")
    {}

    struct bfa_boss_unbound_abomination_AI : public BossAI
    {
        bfa_boss_unbound_abomination_AI(Creature* creature) : BossAI(creature, DATA_UNBOUND_ABOMINATION), summons(me)
        {
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
            instance = me->GetInstanceScript();
        }

        EventMap events;
        InstanceScript* instance;
        SummonList summons;
        uint8 visage;

        void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
        {
            if (!me)
                return;

            if (me)
            {
                switch (selectedTextSound)
                {
                case 1:
                    me->Yell(UNBOUND_AGGRO, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_AGGRO_UNBOUND);
                    break;
                case 2:
                    me->Yell(UNBOUND_DEATH, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_UNBOUND_DEATH);
                    break;
                case 3:
                    me->Yell(UNBOUND_VILE, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_UNBOUND_VILE);
                    break;
                }
            }
        }

        void HardResetCheck()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (!player->IsAlive())
                        {
                            if (Creature* titan = GetTitan())
                            {
                                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, titan);
                                me->Kill(titan);
                            }
                            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                        }
                    }
                }
        }

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveAllAreaTriggers();
        }
        
        void JustSummoned(Creature* summon)
        {
            summons.Summon(summon);

            switch (summon->GetEntry())
            {
            case NPC_BLOOD_VISAGE:
            case NPC_ROTTING_SPORE:
                summon->SetInCombatWithZone();
                break;
            case NPC_TITAN_KEEPER_HEZREL:
                summon->SetInCombatWithZone();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
                break;
            }
        }

        void JustDied(Unit*)
        {
            SelectSoundAndText(me, 2);
            if (Creature* titan = GetTitan())
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, titan);
                titan->DespawnOrUnsummon();
            }
            summons.DespawnAll();
            me->RemoveAllAreaTriggers();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void EnterEvadeMode(EvadeReason why)
        {
            if (Creature* titan = GetTitan())
                titan->DespawnOrUnsummon();
            _DespawnAtEvade(15);
        }

        void DoAction(int32 action)
        {
            switch (action)
            {
            case ACTION_COUNT_VISAGE:
                ++visage;

                if (visage >= 6)
                {
                    //select player to kill boss
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (!player->IsGameMaster()) //gm check
                            {
                                me->RemoveAura(SPELL_BLOOD_BARRIER);
                                player->Kill(me, false);
                            }
                        }
                }
            }
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (me->HasAura(SPELL_BLOOD_BARRIER))
            {
                damage = 0;
                me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 1);
            }
        }

        Creature* GetTitan()
        {
            return me->FindNearestCreature(NPC_TITAN_KEEPER_HEZREL, 500.0f, true);
        }

        void EnterCombat(Unit*)
        {
            SelectSoundAndText(me, 1);
            visage = 0;

            me->RemoveAllAreaTriggers();
            me->AddAura(SPELL_BLOOD_BARRIER, me);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            if (Creature* titan = me->SummonCreature(NPC_TITAN_KEEPER_HEZREL, centerPosition.GetPositionX(), centerPosition.GetPositionY(), centerPosition.GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
                titan->AI()->AttackStart(me);

            events.ScheduleEvent(EVENT_PUTRID_BLOOD, TIMER_PUTRID_BLOOD);
            events.ScheduleEvent(EVENT_VILE_EXPULSION, TIMER_VILE_EXPULSION);
            events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
        }


        void OnSpellFinished(SpellInfo const* spellInfo) override
        {
            switch (spellInfo->Id)
            {
            case SPELL_VILE_EXPULSION:
            {
                std::list<Unit*> targets;
                SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);

                if (!targets.empty())
                    if (targets.size() >= 1)
                        targets.resize(1);
                for (auto target : targets)
                {
                    for (uint8 i = 0; i < 5; ++i)
                        me->CastSpell(me->GetPositionX() + 2 * i, me->GetPositionY(), me->GetPositionZ(), SPELL_VILE_EXPULSION_MISSILE_SPAWN);
                }
                break;
            }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->IsInCombat())
                HardResetCheck();

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_PUTRID_BLOOD:
                {
                    Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                        if (Player* player = i->GetSource())
                        {
                            if (!player->IsGameMaster()) //gm check
                            {
                                me->CastSpell(player, SPELL_PUTRID_BLOOD, true);
                            }
                        }
                    events.ScheduleEvent(EVENT_PUTRID_BLOOD, TIMER_PUTRID_BLOOD);
                    break;
                }
                case EVENT_VILE_EXPULSION:
                {
                    SelectSoundAndText(me, 3);
                    me->CastSpell(me, SPELL_VILE_EXPULSION);
                    events.RescheduleEvent(EVENT_VILE_EXPULSION, TIMER_VILE_EXPULSION);
                    break;
                }
                case EVENT_CHECK_ENERGY:
                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        if (Creature* visage1 = me->SummonCreature(NPC_BLOOD_VISAGE, 1228.46f, 1459.84f, -181.44f, TEMPSUMMON_CORPSE_DESPAWN))
                            visage1->SetInCombatWithZone();
                        if (Creature* visage2 = me->SummonCreature(NPC_BLOOD_VISAGE, 1168.01f, 1499.57f, -181.48f, TEMPSUMMON_CORPSE_DESPAWN))
                            visage2->SetInCombatWithZone();

                        me->SetPower(POWER_ENERGY, 0);
                    }
                    else
                        me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - urand(5, 10));
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, TIMER_CHECK_ENERGY);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_boss_unbound_abomination_AI(creature);
    }
};

class bfa_npc_titan_keeper_hezrel : public CreatureScript
{
public:
    bfa_npc_titan_keeper_hezrel() : CreatureScript("bfa_npc_titan_keeper_hezrel")
    {}

    struct bfa_npc_titan_keeper_hezrel_AI : public ScriptedAI
    {
        bfa_npc_titan_keeper_hezrel_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->AddUnitState(UNIT_STATE_ROOT);
        }

        EventMap events;
        
        void Reset()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_HOLY_BOLT, TIMER_HOLY_BOLT);
            events.ScheduleEvent(EVENT_CLEANSING_LIGHT, TIMER_CLEANSING_LIGHT);

            SelectSoundAndText(me, 1);
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
                    me->Yell(TITAN_AGGRO, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_AGGRO_TITAN);
                    break;
                case 2:
                    me->Yell(TITAN_CLEANSING, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_TITAN_CLEANSING);
                    break;
                case 3:
                    me->Yell(TITAN_PURGE_CORRUPTION, LANG_UNIVERSAL, NULL);
                    me->PlayDirectSound(SOUND_TITAN_PURGE_CORRUPTION);
                    break;
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_HOLY_BOLT:
                {
                    std::list<Creature*> cList;
                    me->GetCreatureListWithEntryInGrid(cList, BOSS_UNBOUND_ABOMINATION, 100.0f);
                    if (!cList.empty())
                    {
                        if (cList.size() >= 1)
                            cList.resize(1);

                        for (auto visage : cList)
                        {
                            me->CastSpell(visage, SPELL_HOLY_BOLT);
                        }
                    }
                    events.ScheduleEvent(EVENT_PURGE_CORRUPTION, TIMER_PURGE_CORRUPTION);
                    break;
                }
                case EVENT_PURGE_CORRUPTION:
                {
                    std::list<Creature*> cList;
                    me->GetCreatureListWithEntryInGrid(cList, NPC_BLOOD_VISAGE, 100.0f);
                    if (!cList.empty())
                    {
                        if (cList.size() >= 1)
                            cList.resize(1);

                        for (auto visage : cList)
                        {
                            SelectSoundAndText(me, 3);
                            me->CastSpell(visage, SPELL_PURGE_CORRUPTION);
                        }
                    }
                    events.ScheduleEvent(EVENT_HOLY_BOLT, TIMER_HOLY_BOLT);
                    break;
                }
                case EVENT_CLEANSING_LIGHT:
                {
                    SelectSoundAndText(me, 2);
                    std::ostringstream str;
                    str << "Titan Keeper Hazrel begins to cast |cFFF00000|h[Cleansing Light]|h|r !";
                    me->TextEmote(str.str().c_str(), 0, true);

                    std::list<Unit*> targets;
                    SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);

                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);
                    for (auto target : targets)
                    {
                        me->CastSpell(target, SPELL_CLEANSING_LIGHT);
                        std::list<AreaTrigger*> areatriggers = target->SelectNearestAreaTriggers(SPELL_VILE_EXPULSION_SPAWN, 100.f);
                        for (AreaTrigger* at : areatriggers)
                            if (at->GetDistance(target) < 10.f)
                                at->SetDuration(0);

                    }

                    events.ScheduleEvent(EVENT_CLEANSING_LIGHT, TIMER_CLEANSING_LIGHT);
                    break;
                }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_titan_keeper_hezrel_AI(creature);
    }
};

class bfa_npc_blood_visage : public CreatureScript
{
public:
    bfa_npc_blood_visage() : CreatureScript("bfa_npc_blood_visage")
    {}

    struct bfa_npc_blood_visage_AI : public ScriptedAI
    {
        bfa_npc_blood_visage_AI(Creature* creature) : ScriptedAI(creature)
        {
        }

        Creature* GetUnbound()
        {
            return me->FindNearestCreature(BOSS_UNBOUND_ABOMINATION, 500.0f, true);
        }

        void DamageTaken(Unit* at, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                if (Creature* unbound = GetUnbound())
                {
                    unbound->AI()->DoAction(ACTION_COUNT_VISAGE);
                    me->CastSpell(unbound, SPELL_FATAL_LINK, true);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_blood_visage_AI(creature);
    }
};

class bfa_npc_rotting_spore : public CreatureScript
{
public:
    bfa_npc_rotting_spore() : CreatureScript("bfa_npc_rotting_spore")
    {}

    struct bfa_npc_rotting_spore_AI : public ScriptedAI
    {
        bfa_npc_rotting_spore_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetWalk(true);
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit*)
        {
            me->SetReactState(REACT_AGGRESSIVE);

            events.ScheduleEvent(EVENT_FIXATE, TIMER_FIXATE_PLAYER);
            events.ScheduleEvent(EVENT_CHECK_DIST_PLAYER, 3000);
        }

        Creature* GetUnbound()
        {
            return me->FindNearestCreature(BOSS_UNBOUND_ABOMINATION, 500.0f, true);
        }

        void DamageTaken(Unit* a, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                if(Creature* boss = GetUnbound())
                    boss->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), SPELL_VILE_EXPULSION_MISSILE_SPAWN, true);
                me->DespawnOrUnsummon();
            }
        }

        void CheckNearbyPlayers()
        {
            Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
                if (Player* player = i->GetSource())
                {
                    if (!player->IsGameMaster()) //gm check
                    {
                        if (me->GetDistance(player) <= 1.5f)
                        {
                            me->CastSpell(player, SPELL_ROTTING_SPORE_DAMAGE);
                            if (Creature* boss = GetUnbound())
                                boss->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), SPELL_VILE_EXPULSION_MISSILE_SPAWN, true);
                            me->DespawnOrUnsummon();
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
                case EVENT_FIXATE:
                {
                    std::list<Unit*> targets;
                    SelectTargetList(targets, 1, SELECT_TARGET_RANDOM, 500.0f, true);

                    if (!targets.empty())
                        if (targets.size() >= 1)
                            targets.resize(1);

                    for (auto target : targets)
                    {
                        me->AddThreat(target, 9999999999.9f);
                        me->AI()->AttackStart(target);
                    }
                    events.ScheduleEvent(EVENT_FIXATE_FOLLOW, 2000);
                    break;
                }
                case EVENT_FIXATE_FOLLOW:
                    if (Unit* victim = me->GetVictim())
                    {
                        me->GetMotionMaster()->MoveFollow(victim, 0.0f, 0.0f);

                    }
                    events.ScheduleEvent(EVENT_FIXATE_FOLLOW, 1000);
                    break;
                case EVENT_CHECK_DIST_PLAYER:
                {
                    CheckNearbyPlayers();
                    events.ScheduleEvent(EVENT_CHECK_DIST_PLAYER, 2000);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new bfa_npc_rotting_spore_AI(creature);
    }
};

// 17928
class bfa_at_vile_expulsion : public AreaTriggerEntityScript
{
public:
    bfa_at_vile_expulsion() : AreaTriggerEntityScript("bfa_at_vile_expulsion")
    {}

    struct bfa_at_vile_expulsion_AI : public AreaTriggerAI
    {
        bfa_at_vile_expulsion_AI(AreaTrigger* at) : AreaTriggerAI(at)
        {}
        void OnInitialize() override
        {
            at->SetPeriodicProcTimer(30 * IN_MILLISECONDS);
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (Unit* caster = at->GetCaster())
                if (caster->IsValidAttackTarget(unit))
                    unit->CastSpell(unit, SPELL_VILE_EXPULSION_AT_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(SPELL_VILE_EXPULSION_AT_DAMAGE);
        }

        void OnPeriodicProc() override
        {
            at->SetDuration(110 * IN_MILLISECONDS);

            if (Unit* caster = at->GetCaster())
                if (caster->GetMap()->IsHeroic() || caster->GetMap()->IsMythic())
                    caster->SummonCreature(NPC_ROTTING_SPORE, at->GetPosition(), TEMPSUMMON_CORPSE_DESPAWN);
        }

    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new bfa_at_vile_expulsion_AI(at);
    }
};


void AddSC_boss_unbound_abomination()
{
    new bfa_boss_unbound_abomination();
    new bfa_npc_blood_visage();
    new bfa_npc_rotting_spore();
    new bfa_npc_titan_keeper_hezrel();

    new bfa_at_vile_expulsion();
}
