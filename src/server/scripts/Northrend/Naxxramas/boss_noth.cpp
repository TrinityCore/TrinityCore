/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "naxxramas.h"

enum Noth
{
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_SLAY                        = 2,
    SAY_DEATH                       = 3,

    SOUND_DEATH                     = 8848,

    SPELL_CURSE_PLAGUEBRINGER       = 29213, // 25-man: 54835
    SPELL_CRIPPLE                   = 29212, // 25-man: 54814
    SPELL_TELEPORT                  = 29216,

    NPC_WARRIOR                     = 16984,
    NPC_CHAMPION                    = 16983,
    NPC_GUARDIAN                    = 16981
};

#define SPELL_BLINK                     RAND(29208, 29209, 29210, 29211)

// Teleport position of Noth on his balcony
#define TELE_X 2631.370f
#define TELE_Y -3529.680f
#define TELE_Z 274.040f
#define TELE_O 6.277f

#define MAX_SUMMON_POS 5

const float SummonPos[MAX_SUMMON_POS][4] =
{
    {2728.12f, -3544.43f, 261.91f, 6.04f},
    {2729.05f, -3544.47f, 261.91f, 5.58f},
    {2728.24f, -3465.08f, 264.20f, 3.56f},
    {2704.11f, -3456.81f, 265.53f, 4.51f},
    {2663.56f, -3464.43f, 262.66f, 5.20f},
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_CURSE,
    EVENT_BLINK,
    EVENT_WARRIOR,
    EVENT_BALCONY,
    EVENT_WAVE,
    EVENT_GROUND,
};

class boss_noth : public CreatureScript
{
public:
    boss_noth() : CreatureScript("boss_noth") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_nothAI(creature);
    }

    struct boss_nothAI : public BossAI
    {
        boss_nothAI(Creature* creature) : BossAI(creature, BOSS_NOTH) { }

        uint32 waveCount, balconyCount;

        void Reset() OVERRIDE
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            balconyCount = 0;
            EnterPhaseGround();
        }

        void EnterPhaseGround()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoZoneInCombat();
            if (me->getThreatManager().isThreatListEmpty())
                EnterEvadeMode();
            else
            {
                events.ScheduleEvent(EVENT_BALCONY, 110000);
                events.ScheduleEvent(EVENT_CURSE, 10000+rand()%15000);
                events.ScheduleEvent(EVENT_WARRIOR, 30000);
                if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                    events.ScheduleEvent(EVENT_BLINK, urand(20000, 40000));
            }
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            if (!(rand()%5))
                Talk(SAY_SLAY);
        }

        void JustSummoned(Creature* summon) OVERRIDE
        {
            summons.Summon(summon);
            summon->setActive(true);
            summon->AI()->DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void SummonUndead(uint32 entry, uint32 num)
        {
            for (uint32 i = 0; i < num; ++i)
            {
                uint32 pos = rand()%MAX_SUMMON_POS;
                me->SummonCreature(entry, SummonPos[pos][0], SummonPos[pos][1], SummonPos[pos][2],
                    SummonPos[pos][3], TEMPSUMMON_CORPSE_DESPAWN, 60000);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CURSE:
                        DoCastAOE(SPELL_CURSE_PLAGUEBRINGER);
                        events.ScheduleEvent(EVENT_CURSE, urand(50000, 60000));
                        return;
                    case EVENT_WARRIOR:
                        Talk(SAY_SUMMON);
                        SummonUndead(NPC_WARRIOR, RAID_MODE(2, 3));
                        events.ScheduleEvent(EVENT_WARRIOR, 30000);
                        return;
                    case EVENT_BLINK:
                        DoCastAOE(SPELL_CRIPPLE, true);
                        DoCastAOE(SPELL_BLINK);
                        DoResetThreat();
                        events.ScheduleEvent(EVENT_BLINK, 40000);
                        return;
                    case EVENT_BALCONY:
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->AttackStop();
                        me->RemoveAllAuras();
                        me->NearTeleportTo(TELE_X, TELE_Y, TELE_Z, TELE_O);
                        events.Reset();
                        events.ScheduleEvent(EVENT_WAVE, urand(2000, 5000));
                        waveCount = 0;
                        return;
                    case EVENT_WAVE:
                        Talk(SAY_SUMMON);
                        switch (balconyCount)
                        {
                            case 0: SummonUndead(NPC_CHAMPION, RAID_MODE(2, 4)); break;
                            case 1: SummonUndead(NPC_CHAMPION, RAID_MODE(1, 2));
                                    SummonUndead(NPC_GUARDIAN, RAID_MODE(1, 2)); break;
                            case 2: SummonUndead(NPC_GUARDIAN, RAID_MODE(2, 4)); break;
                            default:SummonUndead(NPC_CHAMPION, RAID_MODE(5, 10));
                                    SummonUndead(NPC_GUARDIAN, RAID_MODE(5, 10));break;
                        }
                        ++waveCount;
                        events.ScheduleEvent(waveCount < 2 ? EVENT_WAVE : EVENT_GROUND, urand(30000, 45000));
                        return;
                    case EVENT_GROUND:
                    {
                        ++balconyCount;
                        float x, y, z, o;
                        me->GetHomePosition(x, y, z, o);
                        me->NearTeleportTo(x, y, z, o);
                        events.ScheduleEvent(EVENT_BALCONY, 110000);
                        EnterPhaseGround();
                        return;
                    }
                }
            }

            if (me->HasReactState(REACT_AGGRESSIVE))
                DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_noth()
{
    new boss_noth();
}
