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

enum Phases
{
    PHASE_INTRO  = 1,
    PHASE_COMBAT = 2
};

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

class boss_avatar_of_hakkar : public CreatureScript
{
public:
    boss_avatar_of_hakkar() : CreatureScript("boss_avatar_of_hakkar") { }

    struct boss_avatar_of_hakkarAI : public BossAI
    {
        boss_avatar_of_hakkarAI(Creature* creature) : BossAI(creature, BOSS_AVATAR_OF_HAKKAR) { }

        void Reset() override
        {
            _Reset();
        }

        void JustAppeared() override
        {
            SetShadeParameters(true);
        }

        void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_SUPPRESSION)
                events.ScheduleEvent(EVENT_SUPPRESSOR, 1min);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_FIGHT_STATE_AVATAR:
                SetShadeParameters(false);
                break;
            case ACTION_REMOVE_SUPPRESSOR_AVATAR:
                me->RemoveAurasDueToSpell(SPELL_SUPPRESSION);
                events.CancelEvent(EVENT_SUPPRESSOR);
                break;
            default:
                break;
            }
        }

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Talk(SAY_AGRO_AVATAR);
            events.ScheduleEvent(EVENT_CAST_LASH, 4s, 7s);
            events.ScheduleEvent(EVENT_CAST_CAUSE_INSANITY, 6s, 14s);
            events.ScheduleEvent(EVENT_CAST_CURSE_OF_TONGUES, 14s, 21s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
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
                    if (CheckNearbyPlayers())
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                            DoCast(target, SPELL_CAUSE_INSANITY);
                    events.ScheduleEvent(EVENT_CAST_CAUSE_INSANITY, 6s, 14s);
                    break;
                case EVENT_CAST_CURSE_OF_TONGUES:
                    DoCastSelf(SPELL_CURSE_OF_TONGUES);
                    events.ScheduleEvent(EVENT_CAST_CURSE_OF_TONGUES, 14s, 21s);
                    break;
                case EVENT_SUPPRESSOR:
                    if (events.IsInPhase(PHASE_INTRO))
                    {
                        me->DespawnOrUnsummon();
                        instance->SetBossState(BOSS_AVATAR_OF_HAKKAR, FAIL);
                    }
                    break;
                }
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

        void SetShadeParameters(bool on)
        {
            if (on)
            {
                me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetFaction(FACTION_FRIENDLY);
                me->SetDisplayId(DISPLAY_SHADE_OF_HAKKAR);
                events.SetPhase(PHASE_INTRO);
            }
            else
            {
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetFaction(FACTION_MONSTER_2);
                me->SetDisplayId(DISPLAY_AVATAR_OF_HAKKAR);
                events.SetPhase(PHASE_COMBAT);
                Talk(SAY_SPAWN_AVATAR);
            }
        }

        bool CheckNearbyPlayers()
        {
            std::vector<Player*> temp;
            me->GetPlayerListInGrid(temp, 20.0f);
            if (temp.size() > 1)
                return true;
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunkenTempleAI<boss_avatar_of_hakkarAI>(creature);
    }
};

void AddSC_boss_avatar_of_hakkar()
{
    new boss_avatar_of_hakkar();
}
