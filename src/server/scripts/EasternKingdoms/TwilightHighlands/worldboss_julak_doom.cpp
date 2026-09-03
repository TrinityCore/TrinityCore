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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Scripts::EasternKingdoms::TwilightHighlands::JulakDoom
{
    namespace Spells
    {
        static constexpr uint32 SpellBlackBreath = 93611;
        static constexpr uint32 SpellMassiveShockwave = 93610;
        static constexpr uint32 SpellDarkWhisper = 93621;
    }
    namespace Events
    {
        static constexpr uint32 EventBlackBreath = 1;
        static constexpr uint32 EventMassiveShockwave = 2;
        static constexpr uint32 EventDarkWhisper = 3;
    }

    // 50089 - Julak-Doom
    struct worldboss_julak_doom : public WorldBossAI
    {
        using WorldBossAI::WorldBossAI;

        void JustEngagedWith(Unit* who) override
        {
            WorldBossAI::JustEngagedWith(who);

            events.ScheduleEvent(Events::EventBlackBreath, 8s);
            events.ScheduleEvent(Events::EventMassiveShockwave, 12s);
            events.ScheduleEvent(Events::EventDarkWhisper, 60s);
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
                case Events::EventBlackBreath:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, true))
                        DoCast(target, Spells::SpellBlackBreath);
                    events.ScheduleEvent(Events::EventBlackBreath, 15s);
                    break;
                }
                case Events::EventMassiveShockwave:
                {
                    DoCast(Spells::SpellMassiveShockwave);
                    events.ScheduleEvent(Events::EventMassiveShockwave, 29s);
                    break;
                }
                case Events::EventDarkWhisper:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 60.0f, true))
                        DoCast(target, Spells::SpellDarkWhisper);
                    events.ScheduleEvent(Events::EventDarkWhisper, 40s);
                    break;
                }
                default:
                    break;
                }
            }
        }
    };

    // 93621 - Dark Whisper
    class spell_julak_doom_dark_whisper : public AuraScript
    {
        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetActionTarget()->HealthBelowPct(90))
                return true;

            DamageInfo* damageInfo = eventInfo.GetDamageInfo();
            if (damageInfo && damageInfo->GetDamage())
                if (GetTarget()->HealthBelowPctDamaged(90, damageInfo->GetDamage()))
                    return true;

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_julak_doom_dark_whisper::CheckProc);
        }
    };
}

void AddSC_worldboss_julak_doom()
{
    using namespace Scripts::EasternKingdoms::TwilightHighlands::JulakDoom;

    // Creature
    RegisterCreatureAI(worldboss_julak_doom);

    // Spells
    RegisterSpellScript(spell_julak_doom_dark_whisper);
}
