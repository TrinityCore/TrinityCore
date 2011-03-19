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
#include "naxxramas.h"

#define SAY_AGGRO               RAND(-1533075,-1533076,-1533077)
#define SAY_SUMMON              -1533078
#define SAY_SLAY                RAND(-1533079,-1533080)
#define SAY_DEATH               -1533081

#define SOUND_DEATH      8848

#define SPELL_CURSE_PLAGUEBRINGER       RAID_MODE(29213,54835)
#define SPELL_BLINK                     RAND(29208,29209,29210,29211)
#define SPELL_CRIPPLE                   RAID_MODE(29212,54814)
#define SPELL_TELEPORT                  29216

#define MOB_WARRIOR         16984
#define MOB_CHAMPION        16983
#define MOB_GUARDIAN        16981

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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_nothAI (pCreature);
    }

    struct boss_nothAI : public BossAI
    {
        boss_nothAI(Creature *c) : BossAI(c, BOSS_NOTH) {}

        uint32 waveCount, balconyCount;

        void Reset()
        {
            me->SetReactState(REACT_AGGRESSIVE);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            _Reset();
        }

        void EnterCombat(Unit * /*who*/)
        {
            _EnterCombat();
            DoScriptText(SAY_AGGRO, me);
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
                    events.ScheduleEvent(EVENT_BLINK, 20000 + rand()%20000);
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                DoScriptText(SAY_SLAY, me);
        }

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
            summon->setActive(true);
            summon->AI()->DoZoneInCombat();
        }

        void JustDied(Unit* /*Killer*/)
        {
            _JustDied();
            DoScriptText(SAY_DEATH, me);
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

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_CURSE:
                        DoCastAOE(SPELL_CURSE_PLAGUEBRINGER);
                        events.ScheduleEvent(EVENT_CURSE, 50000 + rand()%10000);
                        return;
                    case EVENT_WARRIOR:
                        DoScriptText(SAY_SUMMON, me);
                        SummonUndead(MOB_WARRIOR, RAID_MODE(2,3));
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
                        events.ScheduleEvent(EVENT_WAVE, 2000 + rand()%3000);
                        waveCount = 0;
                        return;
                    case EVENT_WAVE:
                        DoScriptText(SAY_SUMMON, me);
                        switch(balconyCount)
                        {
                            case 0: SummonUndead(MOB_CHAMPION, RAID_MODE(2,4)); break;
                            case 1: SummonUndead(MOB_CHAMPION, RAID_MODE(1,2));
                                    SummonUndead(MOB_GUARDIAN, RAID_MODE(1,2)); break;
                            case 2: SummonUndead(MOB_GUARDIAN, RAID_MODE(2,4)); break;
                            default:SummonUndead(MOB_CHAMPION, RAID_MODE(5,10));
                                    SummonUndead(MOB_GUARDIAN, RAID_MODE(5,10));break;
                        }
                        ++waveCount;
                        events.ScheduleEvent(waveCount < 2 ? EVENT_WAVE : EVENT_GROUND, 30000 + rand()%15000);
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
