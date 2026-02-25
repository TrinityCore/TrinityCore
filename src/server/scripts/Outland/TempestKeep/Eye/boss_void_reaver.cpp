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
#include "Containers.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "the_eye.h"

enum ReaverTexts
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    SAY_POUNDING                = 3
};

enum ReaverSpells
{
    SPELL_POUNDING              = 34162,
    SPELL_ARCANE_ORB            = 34172,
    SPELL_KNOCK_AWAY            = 25778,
    SPELL_BERSERK               = 26662
};

enum ReaverEvents
{
    EVENT_POUNDING              = 1,
    EVENT_ARCANE_ORB,
    EVENT_KNOCK_AWAY,
    EVENT_BERSERK
};

// 19516 - Void Reaver
struct boss_void_reaver : public BossAI
{
    boss_void_reaver(Creature* creature) : BossAI(creature, DATA_VOID_REAVER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        me->CallForHelp(120.0f);

        events.ScheduleEvent(EVENT_POUNDING, 8s, 15s);
        events.ScheduleEvent(EVENT_ARCANE_ORB, 3s);
        events.ScheduleEvent(EVENT_KNOCK_AWAY, 12s, 16s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_POUNDING)
            Talk(SAY_POUNDING);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_POUNDING:
                    DoCastSelf(SPELL_POUNDING);
                    events.Repeat(12s, 14s);
                    break;
                case EVENT_ARCANE_ORB:
                {
                    std::vector<Unit*> target_list;
                    for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
                    {
                        Unit* target = ref->GetVictim();
                        if (target->GetTypeId() == TYPEID_PLAYER && target->IsAlive() && !target->IsWithinDist(me, 18, false))
                            target_list.push_back(target);
                    }

                    Unit* target;
                    if (!target_list.empty())
                        target = Trinity::Containers::SelectRandomContainerElement(target_list);
                    else
                        target = me->GetVictim();

                    if (target)
                        DoCast(target, SPELL_ARCANE_ORB);

                    events.Repeat(3s);
                    break;
                }
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    events.Repeat(20s, 22s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_void_reaver()
{
    RegisterTheEyeCreatureAI(boss_void_reaver);
}
