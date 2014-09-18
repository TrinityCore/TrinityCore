/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
    SPELL_MORTAL_WOUND      = 25646,
    SPELL_ENRAGE            = 28371,
    SPELL_DECIMATE          = 28374,
    SPELL_BERSERK           = 26662,
    SPELL_INFECTED_WOUND    = 29306
};

enum Creatures
{
    NPC_ZOMBIE              = 16360
};

Position const PosSummon[3] =
{
    {3267.9f, -3172.1f, 297.42f, 0.94f},
    {3253.2f, -3132.3f, 297.42f, 0},
    {3308.3f, -3185.8f, 297.42f, 1.58f},
};

enum Events
{
    EVENT_WOUND     = 1,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
};

enum Emotes
{
    EMOTE_ZOMBIE,
    EMOTE_ENRAGE,
    EMOTE_DECIMATE
};

class boss_gluth : public CreatureScript
{
public:
    boss_gluth() : CreatureScript("boss_gluth") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_gluthAI(creature);
    }

    struct boss_gluthAI : public BossAI
    {
        boss_gluthAI(Creature* creature) : BossAI(creature, BOSS_GLUTH)
        {
            // Do not let Gluth be affected by zombies' debuff
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetEntry() == NPC_ZOMBIE && me->IsWithinDistInMap(who, 7))
            {
                SetGazeOn(who);
                /// @todo use a script text
                me->TextEmote(EMOTE_NEARBY, nullptr, true);
                me->Kill(who);
                me->ModifyHealth(me->CountPctFromMaxHealth(5));
            }
            else
                BossAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_WOUND, 10000);
            events.ScheduleEvent(EVENT_ENRAGE, 15000);
            events.ScheduleEvent(EVENT_DECIMATE, 105000);
            events.ScheduleEvent(EVENT_BERSERK, 8*60000);
            events.ScheduleEvent(EVENT_SUMMON, 15000);
        }
        
        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (target->GetTypeId() == TYPEID_UNIT && target->GetEntry() == NPC_ZOMBIE && spell->Id == SPELL_DECIMATE)
            {
                target->ToCreature()->AI()->AttackStart(me);
                target->ToCreature()->SetReactState(REACT_PASSIVE);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictimWithGaze() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_WOUND:
                        DoCastVictim(SPELL_MORTAL_WOUND);
                        events.ScheduleEvent(EVENT_WOUND, 10000);
                        break;
                    case EVENT_ENRAGE:
                        Talk(EMOTE_ENRAGE);
                        DoCast(me, SPELL_ENRAGE);
                        events.ScheduleEvent(EVENT_ENRAGE, 15000);
                        break;
                    case EVENT_DECIMATE:
                        Talk(EMOTE_DECIMATE);
                        DoCastAOE(SPELL_DECIMATE);
                        events.ScheduleEvent(EVENT_DECIMATE, 105000);
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK);
                        events.ScheduleEvent(EVENT_BERSERK, 5*60000);
                        break;
                    case EVENT_SUMMON:
                        for (int32 i = 0; i < RAID_MODE(1, 2); ++i)
                            DoSummon(NPC_ZOMBIE, PosSummon[rand32() % RAID_MODE(1, 3)]);
                        // There's probably a better way to handle this
                        for (SummonList::iterator itr = summons.begin(); itr != summons.end(); ++itr)
                            if(Unit* unit = ObjectAccessor::GetUnit(*me, *itr))
                                if (unit->GetEntry() == NPC_ZOMBIE)
                                    unit->ToCreature()->AI()->AttackStart(me);
                        events.ScheduleEvent(EVENT_SUMMON, 10000);
                        break;
                }
            }
                DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_gluth()
{
    new boss_gluth();
}
