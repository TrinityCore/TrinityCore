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

/* ScriptData
SDName: Boss_Murmur
SD%Complete: 90
SDComment: Timers may be incorrect
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shadow_labyrinth.h"
#include "SpellInfo.h"

enum Murmur
{
    // Spell
    SPELL_RESONANCE             = 33657,
    SPELL_MAGNETIC_PULL         = 33689,
    SPELL_SONIC_SHOCK           = 38797,
    SPELL_THUNDERING_STORM      = 39365,
    SPELL_SONIC_BOOM_CAST       = 33923,
    SPELL_SONIC_BOOM_EFFECT     = 33666,
    SPELL_MURMURS_TOUCH         = 33711,
    // Text
    EMOTE_SONIC_BOOM            = 0
};

enum Events
{
    EVENT_SONIC_BOOM            = 1,
    EVENT_MURMURS_TOUCH         = 2,
    EVENT_RESONANCE             = 3,
    EVENT_MAGNETIC_PULL         = 4,
    EVENT_THUNDERING_STORM      = 5,
    EVENT_SONIC_SHOCK           = 6
};

class boss_murmur : public CreatureScript
{
public:
    boss_murmur() : CreatureScript("boss_murmur") { }

    struct boss_murmurAI : public BossAI
    {
        boss_murmurAI(Creature* creature) : BossAI(creature, DATA_MURMUREVENT)
        {
            SetCombatMovement(false);
        }

        void Reset() OVERRIDE
        {
            events.ScheduleEvent(EVENT_SONIC_BOOM, 30000);
            events.ScheduleEvent(EVENT_MURMURS_TOUCH, urand(8000, 20000));
            events.ScheduleEvent(EVENT_RESONANCE, 5000);
            events.ScheduleEvent(EVENT_MAGNETIC_PULL, urand(15000, 30000));
            if (IsHeroic())
            {
                events.ScheduleEvent(EVENT_THUNDERING_STORM, 15000);
                events.ScheduleEvent(EVENT_SONIC_SHOCK, 10000);
            }

            //database should have `RegenHealth`=0 to prevent regen
            uint32 hp = me->CountPctFromMaxHealth(40);
            if (hp) me->SetHealth(hp);
            me->ResetPlayerDamageReq();
        }

        void SonicBoomEffect()
        {
            ThreatContainer::StorageType const &t_list = me->getThreatManager().getThreatList();
            for (ThreatContainer::StorageType::const_iterator itr = t_list.begin(); itr!= t_list.end(); ++itr)
            {
               Unit* target = Unit::GetUnit(*me, (*itr)->getUnitGuid());
               if (target && target->GetTypeId() == TYPEID_PLAYER)
               {
                   //Not do anything without aura, spell can be resisted!
                   if (target->HasAura(SPELL_SONIC_BOOM_CAST) && me->IsWithinDistInMap(target, 34.0f))
                   {
                       //This will be wrong calculation. Also, comments suggest it must deal damage
                       target->SetHealth(target->CountPctFromMaxHealth(20));
                   }
               }
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE {}

        // Sonic Boom instant damage (needs core fix instead of this)
        void SpellHitTarget(Unit* target, const SpellInfo* spell) OVERRIDE
        {
            if (target && target->IsAlive() && spell && spell->Id == uint32(SPELL_SONIC_BOOM_EFFECT))
                me->DealDamage(target, (target->GetHealth()*90)/100, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NATURE, spell);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target or casting
            if (!UpdateVictim() || me->IsNonMeleeSpellCasted(false))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SONIC_BOOM:
                        Talk(EMOTE_SONIC_BOOM);
                        DoCast(me, SPELL_SONIC_BOOM_CAST);
                        DoCast(me, SPELL_SONIC_BOOM_EFFECT, true);
                        SonicBoomEffect();
                        events.ScheduleEvent(EVENT_SONIC_BOOM, 30000);
                        events.ScheduleEvent(EVENT_RESONANCE, 1500);
                        break;
                    case EVENT_MURMURS_TOUCH:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 80, true))
                            DoCast(target, SPELL_MURMURS_TOUCH);
                        events.ScheduleEvent(EVENT_MURMURS_TOUCH, urand(25000, 35000));
                        break;
                    case EVENT_RESONANCE:
                        if (!(me->IsWithinMeleeRange(me->GetVictim())))
                        {
                            DoCast(me, SPELL_RESONANCE);
                            events.ScheduleEvent(EVENT_RESONANCE, 5000);
                        }
                        break;
                    case EVENT_MAGNETIC_PULL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            if (target->GetTypeId() == TYPEID_PLAYER && target->IsAlive())
                            {
                                DoCast(target, SPELL_MAGNETIC_PULL);
                                events.ScheduleEvent(EVENT_MAGNETIC_PULL, 15000+rand()%15000);
                                break;
                            }
                        events.ScheduleEvent(EVENT_MAGNETIC_PULL, 500);
                        break;
                    case EVENT_THUNDERING_STORM:
                    {
                        ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
                        for (ThreatContainer::StorageType::const_iterator i = threatlist.begin(); i != threatlist.end(); ++i)
                            if (Unit* target = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                                if (target->IsAlive() && !me->IsWithinDist(target, 35, false))
                                    DoCast(target, SPELL_THUNDERING_STORM, true);
                        events.ScheduleEvent(EVENT_THUNDERING_STORM, 15000);
                        break;
                    }
                    case EVENT_SONIC_SHOCK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20, false))
                            if (target->IsAlive())
                                DoCast(target, SPELL_SONIC_SHOCK);
                        events.ScheduleEvent(EVENT_SONIC_SHOCK, 10000+rand()%10000);
                        break;
                }
            }

            // Select nearest most aggro target if top aggro too far
            if (!me->isAttackReady())
                return;

            if (!me->IsWithinMeleeRange(me->GetVictim()))
            {
                ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
                for (ThreatContainer::StorageType::const_iterator i = threatlist.begin(); i != threatlist.end(); ++i)
                    if (Unit* target = Unit::GetUnit(*me, (*i)->getUnitGuid()))
                        if (target->IsAlive() && me->IsWithinMeleeRange(target))
                        {
                            me->TauntApply(target);
                            break;
                        }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_murmurAI(creature);
    }
};

void AddSC_boss_murmur()
{
    new boss_murmur();
}
