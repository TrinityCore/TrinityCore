/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "CreatureGroups.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "stonecore.h"

// TO-DO:
// Find heroic sniffs and script spawning Crystal Shards on heroic mode.

enum Spells
{
    // Corborus intro
    SPELL_TWILIGHT_DOCUMENTS        = 93167,
    SPELL_RING_WYRM_CHARGE          = 81237,
    SPELL_DOOR_BREAK                = 81232, // cast by World Trigger 22515

    // Corborus boss
    SPELL_DAMPENING_WAVE            = 82415,
    SPELL_CRYSTAL_BARRAGE           = 86881, // 81638 triggers 81637
//  SPELL_CRYSTAL_BARRAGE_SHARD     = 92012, // heroic only, summons Crystal Shard (TO-DO!)
    SPELL_CLEAR_ALL_DEBUFFS         = 34098,
    SPELL_SUBMERGE                  = 81629,
    SPELL_TRASHING_CHARGE_TELEPORT  = 81839, // triggers 81864
//  SPELL_TRASHING_CHARGE_TELEPORT_2= 81838, // dummy, targets all players, threat update packet follows
    SPELL_SUMMON_TRASHING_CHARGE    = 81816,
    SPELL_TRASHING_CHARGE_VISUAL    = 81801, // cast time 3.5 sec
    SPELL_TRASHING_CHARGE_EFFECT    = 81828, // 40 yard radius
    SPELL_EMERGE                    = 81948,

    // Rock Borer npc (43917)
    SPELL_ROCK_BORER_EMERGE         = 82185,
    SPELL_ROCK_BORE                 = 80028,
};

enum NPCs
{
    NPC_TRASHING_CHARGE             = 43743,
//  NPC_CRYSTAL_SHARD               = 49267, // 49473
};

enum Events
{
    EVENT_NONE,

    // Corborus intro
    EVENT_CORBORUS_CHARGE,
    EVENT_CORBORUS_KNOCKBACK,
    EVENT_CORBORUS_FACEPLAYERS,

    // Corborus boss
    EVENT_DAMPENING_WAVE,
    EVENT_CRYSTAL_BARRAGE,
    EVENT_SUBMERGE,
    EVENT_TELEPORT,
    EVENT_TRASHING_CHARGE,
    EVENT_SUMMON_BEETLE,
    EVENT_EMERGE,
    EVENT_ATTACK,

    // Rock Borer
    EVENT_EMERGED,
    EVENT_ROCK_BORE,
};

class boss_corborus : public CreatureScript
{
    public:
        boss_corborus() : CreatureScript("boss_corborus") { }

        struct boss_corborusAI : public BossAI
        {
            boss_corborusAI(Creature* creature) : BossAI(creature, DATA_CORBORUS)
            {
                stateIntro = NOT_STARTED;
            }

            void Reset() override
            {
                _Reset();

                countTrashingCharge = 0;

                events.ScheduleEvent(EVENT_DAMPENING_WAVE, 10000);
                events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, 15000);
                events.ScheduleEvent(EVENT_SUBMERGE, 36000);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CORBORUS_INTRO: // Executes Corborus intro event
                    {
                        if (stateIntro != NOT_STARTED)
                            return;

                        stateIntro = IN_PROGRESS;

                        if (Creature* Millhouse = instance->GetCreature(DATA_MILLHOUSE_MANASTORM))
                        {
                            Millhouse->InterruptNonMeleeSpells(true);
                            Millhouse->RemoveAllAuras();
                            Millhouse->HandleEmoteCommand(EMOTE_ONESHOT_KNOCKDOWN);
                        }

                        events.ScheduleEvent(EVENT_CORBORUS_CHARGE, 1000);
                        break;
                    }
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && stateIntro != IN_PROGRESS)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CORBORUS_CHARGE:
                            // Face Millhouse and other mobs
                            instance->SetData(DATA_MILLHOUSE_EVENT_FACE, 0);

                            // Open rock gate and cast visual from nearby worldtrigger
                            instance->SetData(DATA_HANDLE_CORBORUS_ROCKDOOR, 0);
                            if (Creature* worldtrigger = me->FindNearestCreature(NPC_WORLDTRIGGER, 60.0f))
                                worldtrigger->CastSpell(worldtrigger, SPELL_DOOR_BREAK, true);

                            // Make Corborus charge
                            DoCast(me, SPELL_RING_WYRM_CHARGE, true);

                            events.ScheduleEvent(EVENT_CORBORUS_KNOCKBACK, 1000);
                            break;
                        case EVENT_CORBORUS_KNOCKBACK:
                            // Spawn Twilight Documents (quest gameobject)
                            if (Creature* Millhouse = instance->GetCreature(DATA_MILLHOUSE_MANASTORM))
                                Millhouse->CastSpell(Millhouse, SPELL_TWILIGHT_DOCUMENTS, true);

                            // Knockback Millhouse and other mobs
                            instance->SetData(DATA_MILLHOUSE_EVENT_KNOCKBACK, 0);

                            events.ScheduleEvent(EVENT_CORBORUS_FACEPLAYERS, 2000);
                            break;
                        case EVENT_CORBORUS_FACEPLAYERS:
                            // Face Corborus to players and set new home position
                            me->SetFacingTo(3.176499f);
                            me->SetHomePosition(1154.55f, 878.843f, 284.963f, 3.176499f);
                            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);

                            // Despawn Millhouse and all trash
                            instance->SetData(DATA_MILLHOUSE_EVENT_DESPAWN, 0);

                            stateIntro = DONE;
                            break;
                        case EVENT_DAMPENING_WAVE:
                            DoCastVictim(SPELL_DAMPENING_WAVE);
                            events.ScheduleEvent(EVENT_DAMPENING_WAVE, 15000);
                            break;
                        case EVENT_CRYSTAL_BARRAGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_CRYSTAL_BARRAGE);
                            events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, 10000);
                            break;
                        case EVENT_SUBMERGE:
                            events.RescheduleEvent(EVENT_DAMPENING_WAVE, 35000);
                            events.RescheduleEvent(EVENT_CRYSTAL_BARRAGE, 30000);
                            events.RescheduleEvent(EVENT_SUBMERGE, 100000);

                            me->SetReactState(REACT_PASSIVE);
                            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                            me->AttackStop();

                            DoCast(me, SPELL_SUBMERGE);

                            countTrashingCharge = 0;
                            events.ScheduleEvent(EVENT_TELEPORT, 500);
                            break;
                        case EVENT_TELEPORT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_TRASHING_CHARGE_TELEPORT);
                            countTrashingCharge += 1;
                            if (countTrashingCharge <= 4)
                                events.ScheduleEvent(EVENT_TRASHING_CHARGE, 1000);
                            else
                                events.ScheduleEvent(EVENT_EMERGE, 2500);
                            break;
                        case EVENT_TRASHING_CHARGE:
                            DoCast(me, SPELL_SUMMON_TRASHING_CHARGE);
                            DoCast(me, SPELL_TRASHING_CHARGE_VISUAL);
                            events.ScheduleEvent(EVENT_TELEPORT, 5000);
                            break;
                        case EVENT_EMERGE:
                            me->RemoveAllAuras();
                            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                            DoCast(me, SPELL_EMERGE);
                            events.ScheduleEvent(EVENT_ATTACK, 2500);
                            break;
                        case EVENT_ATTACK:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_TRASHING_CHARGE)
                {
                    summon->SetReactState(REACT_PASSIVE);
                    summon->CastSpell(summon, SPELL_TRASHING_CHARGE_EFFECT);
                    summon->DespawnOrUnsummon(6000);
                }

                BossAI::JustSummoned(summon);
            }

        private:
            EncounterState stateIntro;
            uint32 countTrashingCharge = 0;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<boss_corborusAI>(creature);
        }
};

// 43391 - Rock Borer
class npc_rock_borer : public CreatureScript
{
    public:
        npc_rock_borer() : CreatureScript("npc_rock_borer") { }

        struct npc_rock_borerAI : public ScriptedAI
        {
            npc_rock_borerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_EMERGED, 1200);
                events.ScheduleEvent(EVENT_ROCK_BORE, urand(15000, 20000)); // Need sniffs for this timer
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->SetInCombatState(false, summoner);
                DoCast(me, SPELL_ROCK_BORER_EMERGE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && me->GetReactState() != REACT_PASSIVE)
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_EMERGED:
                            me->RemoveAurasDueToSpell(SPELL_ROCK_BORER_EMERGE);
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_ROCK_BORE:
                            DoCast(me, SPELL_ROCK_BORE);
                            events.ScheduleEvent(EVENT_ROCK_BORE, urand(15000, 20000)); // Need sniffs for this timer
                            break;
                        default:
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
            return GetStonecoreAI<npc_rock_borerAI>(creature);
        }
};

void AddSC_boss_corborus()
{
    new boss_corborus();
    new npc_rock_borer();
}
