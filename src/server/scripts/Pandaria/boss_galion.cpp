/*
* Copyright 2023 AzgathCore
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

enum eBosses
{
    BOSS_GALION,
};

enum eSpells
{
    SPELL_STOMP                 = 121787,
    SPELL_CANNON_BARRAGE        = 121600,
    SPELL_FIRE_SHOT             = 121673,
    SPELL_EMPALLING_PULL        = 121747,
    SPELL_BERSERK               = 47008,
};

enum eEvents
{
    EVENT_STOMP                 = 1,
    EVENT_CANNON                = 2,
    EVENT_FIRE_SHOT             = 3,
    EVENT_EMPALLING             = 4,
    EVENT_SPAWN                 = 6,
    EVENT_BERSERK               = 7,
};

enum eCreatures
{
    CREATURE_GALION           = 62351,
};


class boss_galion : public CreatureScript
{
public:
    boss_galion() : CreatureScript("boss_galion") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_galion_AI(creature);
    }

    struct boss_galion_AI : public BossAI
    {
        boss_galion_AI(Creature* creature) : BossAI(creature, BOSS_GALION)
        {}
        void Reset() override
        {
            events.Reset();
            _Reset();
        }

        void KilledUnit(Unit* /*u*/) override
        {
        }

        void EnterCombat(Unit* /*unit*/)
        {
            
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STOMP:
                    {
                        
                    }
                    case EVENT_CANNON:
                    {
                        
                    }
             /*       case EVENT_FIRE_SHOT:
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        me->CastSpell(target, SPELL_FIRE_SHOT, false);

                        events.RescheduleEvent(EVENT_FIRE_SHOT, 5000);
                        break;
                    }*/
                    case EVENT_SPAWN:
                    {
                        
                    }

                    case EVENT_BERSERK:
                    {
                        me->CastSpell(me,SPELL_BERSERK,false);
                        break;
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_galion : public CreatureScript
{
    public:
        npc_galion() : CreatureScript("npc_galion") { }

        struct npc_galionAI : public ScriptedAI
        {
            npc_galionAI(Creature* creature) : ScriptedAI(creature)
            {
            }
        EventMap events;
        void Reset() override
        {
            events.Reset();
        }
        void EnterCombat(Unit* /*unit*/)
        {
            
        }
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMPALLING:
                    {
                        
                    }
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_galionAI (creature);
    }
};

void AddSC_boss_galion()
{
    new boss_galion();
    new npc_galion();
}
