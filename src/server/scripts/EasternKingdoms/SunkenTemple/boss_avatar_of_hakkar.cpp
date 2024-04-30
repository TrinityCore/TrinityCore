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
#include "sunken_temple.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "Player.h"

enum Events
{
    EVENT_CAST_LASH              = 1,
    EVENT_CAST_CAUSE_INSANITY,
    EVENT_CAST_CURSE_OF_TONGUES,
    EVENT_SUPPRESSOR
};

enum Spells
{
    SPELL_LASH             = 6607,
    SPELL_CAUSE_INSANITY   = 12888,
    SPELL_CURSE_OF_TONGUES = 12889,
};

enum Yells
{
    SAY_SPAWN_AVATAR = 0,
    SAY_AGRO_AVATAR  = 1
};

enum DisplayID
{
    DISPLAY_SHADE_OF_HAKKAR  = 7690,
    DISPLAY_AVATAR_OF_HAKKAR = 8053
};


/*#####
# boss_avatar_of_hakkar
#####*/

class boss_avatar_of_hakkar : public CreatureScript
{
public:
    boss_avatar_of_hakkar() : CreatureScript("boss_avatar_of_hakkar") { }

    struct boss_avatar_of_hakkarAI : public BossAI
    {
        boss_avatar_of_hakkarAI(Creature* creature) : BossAI(creature, BOSS_AVATAR_OF_HAKKAR) { }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGRO_AVATAR);
            events.ScheduleEvent(EVENT_CAST_LASH, 4s, 7s);
            events.ScheduleEvent(EVENT_CAST_CAUSE_INSANITY, 6s, 14s);
            events.ScheduleEvent(EVENT_CAST_CURSE_OF_TONGUES, 14s, 21s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_LASH:
                    DoCastVictim(SPELL_LASH);
                    events.ScheduleEvent(EVENT_CAST_LASH, 4s, 7s);
                    break;
                case EVENT_CAST_CAUSE_INSANITY:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_CAUSE_INSANITY);
                    events.ScheduleEvent(EVENT_CAST_CAUSE_INSANITY, 6s, 14s);
                    break;
                case EVENT_CAST_CURSE_OF_TONGUES:
                    DoCastSelf(SPELL_CURSE_OF_TONGUES);
                    events.ScheduleEvent(EVENT_CAST_CURSE_OF_TONGUES, 14s, 21s);
                    break;
                }
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunkenTempleAI<boss_avatar_of_hakkarAI>(creature);
    }
};

/*#####
# npc_shade_of_hakkar
#####*/

class npc_shade_of_hakkar : public CreatureScript
{
public:
    npc_shade_of_hakkar() : CreatureScript("npc_shade_of_hakkar") { }
    struct npc_shade_of_hakkarAI : public ScriptedAI
    {
        npc_shade_of_hakkarAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_SUPPRESSION)
                _events.ScheduleEvent(EVENT_SUPPRESSOR, 1min);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_REMOVE_SUPPRESSOR:
                me->RemoveAurasDueToSpell(SPELL_SUPPRESSION);
                _events.CancelEvent(EVENT_SUPPRESSOR);
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!me->HasAura(SPELL_SUPPRESSION))
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SUPPRESSOR:
                    me->DespawnOrUnsummon();
                    _instance->SetBossState(BOSS_AVATAR_OF_HAKKAR, FAIL);
                    break;
                }
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    private:
        InstanceScript* _instance;
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunkenTempleAI<npc_shade_of_hakkarAI>(creature);
    }
};

void AddSC_boss_avatar_of_hakkar()
{
    new boss_avatar_of_hakkar();
    new npc_shade_of_hakkar();
}
