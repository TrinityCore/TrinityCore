/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "halls_of_reflection.h"

enum Yells
{
    SAY_AGGRO                                     = -1668050,
    SAY_SLAY_1                                    = -1668051,
    SAY_SLAY_2                                    = -1668052,
    SAY_DEATH                                     = -1668053,
    SAY_IMPENDING_DESPAIR                         = -1668054,
    SAY_DEFILING_HORROR                           = -1668055,
};

enum Spells
{
    SPELL_QUIVERING_STRIKE                        = 72422,
    H_SPELL_QUIVERING_STRIKE                      = 72453,
    SPELL_IMPENDING_DESPAIR                       = 72426,
    SPELL_DEFILING_HORROR                         = 72435,
    H_SPELL_DEFILING_HORROR                       = 72452,
    SPELL_HOPELESSNESS                            = 72395,
    H_SPELL_HOPELESSNESS                          = 72390, // TODO: not in dbc. Add in DB.
};

enum Events
{
    EVENT_NONE,
    EVENT_QUIVERING_STRIKE,
    EVENT_IMPENDING_DESPAIR,
    EVENT_DEFILING_HORROR,
};

const uint32 HoplessnessSpellId[6] =
{
    72395,
    72396,
    72397,
    72390,
    72391,
    72393
};

class boss_falric : public CreatureScript
{
public:
    boss_falric() : CreatureScript("boss_falric") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_falricAI(creature);
    }

    struct boss_falricAI : public boss_horAI
    {
        boss_falricAI(Creature* creature) : boss_horAI(creature) {}

        uint8 uiHopelessnessCount;

        void Reset()
        {
            boss_horAI::Reset();

            uiHopelessnessCount = 0;

            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_QUIVERING_STRIKE, DUNGEON_MODE(10000, 6000));
            events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 9000);
            events.ScheduleEvent(EVENT_DEFILING_HORROR, 20000);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);

            // Cleanup all Hopelessness auras
            RemoveAllAurasOfHopelessness();

            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void DoDefilingHorror()
        {
            std::list<Unit*> targetList;
            SelectTargetList(targetList, 5, SELECT_TARGET_RANDOM, 100.0f, true);

            if (targetList.empty())
                return;

            for (std::list<Unit*>::const_iterator i = targetList.begin(); i != targetList.end(); ++i)
            {
                if ((*i))
                   if (me->IsValidAttackTarget((*i)))
                       me->AddAura(DUNGEON_MODE(SPELL_DEFILING_HORROR, H_SPELL_DEFILING_HORROR), (*i));
            }
        }

        void DoHopelessness(uint8 count)
        {
            // Cleanup all Hopelessness auras
            RemoveAllAurasOfHopelessness();

            // Needed for array calling later
            count -= 1;

            // If Heroic add 3 to count
            if (IsHeroic())
                count += 3;

            DoCast(me, HoplessnessSpellId[count], true);
        }

        void RemoveAllAurasOfHopelessness()
        {
            if (!instance || !me->GetMap())
                return;

            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator itr = PlayerList.begin(); itr != PlayerList.end(); ++itr)
                {
                    if (Player* player = itr->getSource())
                    {
                        for (uint8 i = 0; i < 6; i++)
                        {
                            if (Aura* plrAur = player->GetAura(HoplessnessSpellId[i]))
                                plrAur->Remove();

                            if (Pet* pet = player->GetPet())
                                if (Aura* petAur = pet->GetAura(HoplessnessSpellId[i]))
                                    petAur->Remove();
                        }
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            // Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_QUIVERING_STRIKE:
                    DoCast(me->getVictim(), DUNGEON_MODE(SPELL_QUIVERING_STRIKE, H_SPELL_QUIVERING_STRIKE));
                    events.ScheduleEvent(EVENT_QUIVERING_STRIKE, DUNGEON_MODE(10000, 6000));
                    break;
                case EVENT_IMPENDING_DESPAIR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        DoScriptText(SAY_IMPENDING_DESPAIR, me);
                        DoCast(target, SPELL_IMPENDING_DESPAIR);
                    }
                    events.ScheduleEvent(EVENT_IMPENDING_DESPAIR, 13000);
                    break;
                case EVENT_DEFILING_HORROR:
                    DoDefilingHorror();
                    events.ScheduleEvent(EVENT_DEFILING_HORROR, 20000);
                    break;
            }

            if ((uiHopelessnessCount < 1 && HealthBelowPct(66))
                || (uiHopelessnessCount < 2 && HealthBelowPct(33))
                || (uiHopelessnessCount < 3 && HealthBelowPct(10)))
            {
                uiHopelessnessCount++;
                DoHopelessness(uiHopelessnessCount);
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_falric()
{
    new boss_falric();
}
