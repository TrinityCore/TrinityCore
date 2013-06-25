/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "ScriptedCreature.h"
#include "blackrock_spire.h"

enum Spells
{
    SPELL_WHIRLWIND                 = 13736, // sniffed
    SPELL_CLEAVE                    = 15284,
    SPELL_MORTAL_STRIKE             = 16856,
    SPELL_FRENZY                    = 8269,
    SPELL_KNOCKDOWN                 = 13360 // On spawn during Gyth fight
};

enum Says
{
    // Rend Blackhand
    SAY_BLACKHAND_1                 = 0,
    SAY_BLACKHAND_2                 = 1,
    EMOTE_BLACKHAND_DISMOUNT        = 2,
    // Victor Nefarius
    SAY_NEFARIUS_1                  = 0,
    SAY_NEFARIUS_2                  = 1,
    SAY_NEFARIUS_3                  = 2,
    SAY_NEFARIUS_4                  = 3,
    SAY_NEFARIUS_5                  = 4,
    SAY_NEFARIUS_6                  = 5,
    SAY_NEFARIUS_7                  = 6,
    SAY_NEFARIUS_8                  = 7,
    SAY_NEFARIUS_9                  = 8,
    SAY_NEFARIUS_10                 = 9,
};

enum Adds
{
    NPC_CHROMATIC_WHELP             = 10442,
    NPC_CHROMATIC_DRAGONSPAWN       = 10447,
    NPC_BLACKHAND_DRAGON_HANDLER    = 10742
};

struct Wave
{
    uint32 entry;
    float  x_pos;
    float  y_pos;
    float  z_pos;
    float  o_pos;
};

static Wave Wave2[]= // 22 sec
{
    { 10447, 209.8637f, -428.2729f, 110.9877f, 0.6632251f },
    { 10442, 209.3122f, -430.8724f, 110.9814f, 2.9147f    },
    { 10442, 211.3309f, -425.9111f, 111.0006f, 1.727876f  }
};

static Wave Wave3[]= // 60 sec
{
    { 10742, 208.6493f, -424.5787f, 110.9872f, 5.8294f    },
    { 10447, 203.9482f, -428.9446f, 110.982f,  4.677482f  },
    { 10442, 203.3441f, -426.8668f, 110.9772f, 4.712389f  },
    { 10442, 206.3079f, -424.7509f, 110.9943f, 4.08407f   }
};

static Wave Wave4[]= // 49 sec
{
    { 10742, 212.3541f, -412.6826f, 111.0352f, 5.88176f   },
    { 10447, 212.5754f, -410.2841f, 111.0296f, 2.740167f  },
    { 10442, 212.3449f, -414.8659f, 111.0348f, 2.356194f  },
    { 10442, 210.6568f, -412.1552f, 111.0124f, 0.9773844f }
};

static Wave Wave5[]= // 60 sec
{
    { 10742, 210.2188f, -410.6686f, 111.0211f, 5.8294f    },
    { 10447, 209.4078f, -414.13f,   111.0264f, 4.677482f  },
    { 10442, 208.0858f, -409.3145f, 111.0118f, 4.642576f  },
    { 10442, 207.9811f, -413.0728f, 111.0098f, 5.288348f  },
    { 10442, 208.0854f, -412.1505f, 111.0057f, 4.08407f   }
};

static Wave Wave6[]= // 27 sec
{
    { 10742, 213.9138f, -426.512f,  111.0013f, 3.316126f  },
    { 10447, 213.7121f, -429.8102f, 110.9888f, 1.413717f  },
    { 10447, 213.7157f, -424.4268f, 111.009f,  3.001966f  },
    { 10442, 210.8935f, -423.913f,  111.0125f, 5.969026f  },
    { 10442, 212.2642f, -430.7648f, 110.9807f, 5.934119f  }
};

enum Events
{
    EVENT_WHIRLWIND                 = 1,
    EVENT_CLEAVE                    = 2,
    EVENT_MORTAL_STRIKE             = 3,

    EVENT_GYTH_1                    = 5,
    EVENT_GYTH_2                    = 6,
    EVENT_GYTH_3                    = 7,
    EVENT_GYTH_4                    = 8,
    EVENT_GYTH_5                    = 9,
    EVENT_GYTH_6                   = 10,
    EVENT_PORTCULLIS               = 11,
};

class boss_rend_blackhand : public CreatureScript
{
public:
    boss_rend_blackhand() : CreatureScript("boss_rend_blackhand") { }

    struct boss_rend_blackhandAI : public BossAI
    {
        boss_rend_blackhandAI(Creature* creature) : BossAI(creature, DATA_WARCHIEF_REND_BLACKHAND) { }

        void Reset()
        {
            _Reset();
            _gythEvent = false;
            _victorGUID = 0;
            _portcullisGUID = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WHIRLWIND,     13000);
            events.ScheduleEvent(EVENT_CLEAVE,        15000);
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, 17000);
        }

        void JustDied(Unit* /*killer*/)
        {
            _JustDied();
            // Do data set on victor
        }

        void SetData(uint32 type, uint32 data)
        {
            if (instance && type == AREATRIGGER && data == AREATRIGGER_BLACKROCK_STADIUM)
            {
                if (!_gythEvent)
                {
                    _gythEvent = true;

                    if (Creature* victor = me->FindNearestCreature(NPC_LORD_VICTOR_NEFARIUS, 5.0f, true))
                        _victorGUID = victor->GetGUID();

                    if (GameObject* portcullis = me->FindNearestGameObject(GO_DR_PORTCULLIS, 50.0f))
                        _portcullisGUID = portcullis->GetGUID();

                    if (Creature* victor = me->GetCreature(*me, _victorGUID))
                    {
                        if (Unit* player = victor->SelectNearestPlayer(40.0f))
                        {
                            victor->SetInFront(player);
                            victor->SendMovementFlagUpdate();
                        }
                    }
                }

                events.ScheduleEvent(EVENT_GYTH_1, 1000);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (_gythEvent)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GYTH_1:
                            if (Creature* victor = me->GetCreature(*me, _victorGUID))
                                victor->AI()->Talk(SAY_NEFARIUS_1);
                            events.ScheduleEvent(EVENT_GYTH_2, 4000);
                            break;
                        case EVENT_GYTH_2:
                            if (Creature* victor = me->GetCreature(*me, _victorGUID))
                                victor->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                            events.ScheduleEvent(EVENT_GYTH_3, 4000);
                            break;
                        case EVENT_GYTH_3:
                            if (Creature* victor = me->GetCreature(*me, _victorGUID))
                                victor->AI()->Talk(SAY_NEFARIUS_2);
                            events.ScheduleEvent(EVENT_PORTCULLIS, 2000);
                            events.ScheduleEvent(EVENT_GYTH_4, 4000);
                            break;
                        case EVENT_GYTH_4:
                            if (Creature* victor = me->GetCreature(*me, _victorGUID))
                            {
                                victor->SetInFront(me);
                                victor->SendMovementFlagUpdate();
                            }
                            break;
                        case EVENT_PORTCULLIS:
                            if (GameObject* portcullis = me->FindNearestGameObject(GO_DR_PORTCULLIS, 50.0f))
                                portcullis->UseDoorOrButton();
                            // move wave
                            break;
                        default:
                            break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WHIRLWIND:
                        DoCast(SPELL_WHIRLWIND);
                        events.ScheduleEvent(EVENT_WHIRLWIND, urand(13000, 18000));
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 10000);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE, 16000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
        private:
            bool   _gythEvent;
            uint64 _victorGUID;
            uint64 _portcullisGUID;

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_rend_blackhandAI(creature);
    }
};

void AddSC_boss_rend_blackhand()
{
    new boss_rend_blackhand();
}
