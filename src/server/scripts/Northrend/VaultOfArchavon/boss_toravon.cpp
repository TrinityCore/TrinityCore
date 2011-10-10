/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "vault_of_archavon.h"

enum Spells
{
    // Toravon
    SPELL_FREEZING_GROUND   = 72090,    // don't know cd... using 20 secs.
    SPELL_FROZEN_ORB        = 72091,
    SPELL_WHITEOUT          = 72034,    // Every 38 sec. cast. (after SPELL_FROZEN_ORB)
    SPELL_FROZEN_MALLET     = 71993,

    // Frost Warder
    SPELL_FROST_BLAST       = 72123,    // don't know cd... using 20 secs.
    SPELL_FROZEN_MALLET_2   = 72122,

    // Frozen Orb
    SPELL_FROZEN_ORB_DMG    = 72081,    // priodic dmg aura
    SPELL_FROZEN_ORB_AURA   = 72067,    // make visible

    // Frozen Orb Stalker
    SPELL_FROZEN_ORB_SUMMON = 72093,    // summon orb
};

// Events boss
enum Events
{
    EVENT_FREEZING_GROUND   = 1,
    EVENT_FROZEN_ORB        = 2,
    EVENT_WHITEOUT          = 3,

    EVENT_FROST_BLAST       = 4,
};

// Mob Frozen Orb
#define MOB_FROZEN_ORB 38456    // 1 in 10 mode and 3 in 25 mode

class boss_toravon : public CreatureScript
{
    public:
        boss_toravon() : CreatureScript("boss_toravon") { }

        struct boss_toravonAI : public BossAI
        {
            boss_toravonAI(Creature* creature) : BossAI(creature, DATA_TORAVON)
            {
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoCast(me, SPELL_FROZEN_MALLET);

                events.ScheduleEvent(EVENT_FROZEN_ORB, 11000);
                events.ScheduleEvent(EVENT_WHITEOUT, 13000);
                events.ScheduleEvent(EVENT_FREEZING_GROUND, 15000);

                _EnterCombat();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROZEN_ORB:
                            me->CastCustomSpell(SPELL_FROZEN_ORB, SPELLVALUE_MAX_TARGETS, 1, me);
                            events.ScheduleEvent(EVENT_FROZEN_ORB, 38000);
                            break;
                        case EVENT_WHITEOUT:
                            DoCast(me, SPELL_WHITEOUT);
                            events.ScheduleEvent(EVENT_WHITEOUT, 38000);
                            break;
                        case EVENT_FREEZING_GROUND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                                DoCast(target, SPELL_FREEZING_GROUND);
                            events.ScheduleEvent(EVENT_FREEZING_GROUND, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_toravonAI(creature);
        }
};

/*######
##  Mob Frost Warder
######*/
class mob_frost_warder : public CreatureScript
{
    public:
        mob_frost_warder() : CreatureScript("mob_frost_warder") { }

        struct mob_frost_warderAI : public ScriptedAI
        {
            mob_frost_warderAI(Creature* c) : ScriptedAI(c) {}

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoZoneInCombat();

                DoCast(me, SPELL_FROZEN_MALLET_2);

                events.ScheduleEvent(EVENT_FROST_BLAST, 5000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                if (events.ExecuteEvent() == EVENT_FROST_BLAST)
                {
                    DoCastVictim(SPELL_FROST_BLAST);
                    events.ScheduleEvent(EVENT_FROST_BLAST, 20000);
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_frost_warderAI(creature);
        }
};

/*######
##  Mob Frozen Orb
######*/
class mob_frozen_orb : public CreatureScript
{
public:
    mob_frozen_orb() : CreatureScript("mob_frozen_orb") { }

    struct mob_frozen_orbAI : public ScriptedAI
    {
        mob_frozen_orbAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset()
        {
            done = false;
            killTimer = 60000; // if after this time there is no victim -> destroy!
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoZoneInCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!done)
            {
                DoCast(me, SPELL_FROZEN_ORB_AURA, true);
                DoCast(me, SPELL_FROZEN_ORB_DMG, true);
                done = true;
            }

            if (killTimer <= diff)
            {
                if (!UpdateVictim())
                    me->DespawnOrUnsummon();
                killTimer = 10000;
            }
            else
                killTimer -= diff;
        }

    private:
        uint32 killTimer;
        bool done;
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_frozen_orbAI(creature);
    }
};

/*######
##  Mob Frozen Orb Stalker
######*/
class mob_frozen_orb_stalker : public CreatureScript
{
    public:
        mob_frozen_orb_stalker() : CreatureScript("mob_frozen_orb_stalker") { }

        struct mob_frozen_orb_stalkerAI : public Scripted_NoMovementAI
        {
            mob_frozen_orb_stalkerAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                creature->SetVisible(false);
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
                creature->SetReactState(REACT_PASSIVE);

                instance = creature->GetInstanceScript();
                spawned = false;
            }

            void UpdateAI(const uint32 /*diff*/)
            {
                if (spawned)
                    return;

                spawned = true;
                Unit* toravon = me->GetCreature(*me, instance ? instance->GetData64(DATA_TORAVON) : 0);
                if (!toravon)
                    return;

                uint8 num_orbs = RAID_MODE(1, 3);
                for (uint8 i = 0; i < num_orbs; ++i)
                {
                    Position pos;
                    me->GetNearPoint(toravon, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.0f, 10.0f, 0.0f);
                    me->SetPosition(pos);
                    DoCast(me, SPELL_FROZEN_ORB_SUMMON);
                }
            }

        private:
            InstanceScript* instance;
            bool spawned;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_frozen_orb_stalkerAI(creature);
        }
};

void AddSC_boss_toravon()
{
    new boss_toravon();
    new mob_frost_warder();
    new mob_frozen_orb();
    new mob_frozen_orb_stalker();
}
