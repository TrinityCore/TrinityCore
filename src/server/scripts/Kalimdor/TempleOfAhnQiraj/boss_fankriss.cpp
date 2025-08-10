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

/*
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "temple_of_ahnqiraj.h"

enum FankrissSpells
{
    SPELL_MORTAL_WOUND      = 25646,

    SPELL_SUMMON_WORM_1     = 518,
    SPELL_SUMMON_WORM_2     = 25831,
    SPELL_SUMMON_WORM_3     = 25832,

    SPELL_ENTANGLE_1        = 720,
    SPELL_ENTANGLE_2        = 731,
    SPELL_ENTANGLE_3        = 1121,

    SPELL_SPAWN_HATCHLING_1 = 26630,
    SPELL_SPAWN_HATCHLING_2 = 26631,
    SPELL_SPAWN_HATCHLING_3 = 26632
};

enum FankrissEvents
{
    EVENT_MORTAL_WOUND      = 1,
    EVENT_SUMMON_WORM,
    EVENT_ENTANGLE
};

// 15510 - Fankriss the Unyielding
struct boss_fankriss : public BossAI
{
    boss_fankriss(Creature* creature) : BossAI(creature, DATA_FRANKRIS), _wormsSpawnPerWave(0), _entanglePerWave(0) { }

    std::vector<uint32> SummonWormSpells = { SPELL_SUMMON_WORM_1, SPELL_SUMMON_WORM_2, SPELL_SUMMON_WORM_3 };
    std::vector<uint32> EntangleSpells = { SPELL_ENTANGLE_1, SPELL_ENTANGLE_2, SPELL_ENTANGLE_3 };

    void Reset() override
    {
        _Reset();
        _wormsSpawnPerWave = urand(1, 3);
        Trinity::Containers::RandomShuffle(SummonWormSpells);
        _entanglePerWave = urand(1, 3);
        Trinity::Containers::RandomShuffle(EntangleSpells);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_MORTAL_WOUND, 2s, 6s);
        events.ScheduleEvent(EVENT_SUMMON_WORM, 30s, 50s);
        events.ScheduleEvent(EVENT_ENTANGLE, 15s, 20s);
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
                case EVENT_MORTAL_WOUND:
                    DoCastVictim(SPELL_MORTAL_WOUND);
                    events.Repeat(4s, 12s);
                    break;
                case EVENT_SUMMON_WORM:
                {
                    DoCastSelf(SummonWormSpells[_wormsSpawnPerWave - 1]);

                    --_wormsSpawnPerWave;

                    if (!_wormsSpawnPerWave)
                    {
                        _wormsSpawnPerWave = urand(1, 3);
                        Trinity::Containers::RandomShuffle(SummonWormSpells);
                        events.Repeat(20s, 70s);
                    }
                    else
                        events.Repeat(5s, 20s);
                    break;
                }
                case EVENT_ENTANGLE:
                {
                    Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 100.0f, true);

                    if (!target)
                        target = me->GetVictim();

                    if (target)
                        DoCast(target, EntangleSpells[_entanglePerWave - 1]);

                    --_entanglePerWave;

                    if (!_entanglePerWave)
                    {
                        _entanglePerWave = urand(1, 3);
                        Trinity::Containers::RandomShuffle(EntangleSpells);
                        events.Repeat(25s, 55s);
                    }
                    else
                        events.Repeat(5s, 10s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    uint8 _wormsSpawnPerWave;
    uint8 _entanglePerWave;
};

// 720, 731, 1121 - Entangle
class spell_fankriss_entangle : public SpellScript
{
    PrepareSpellScript(spell_fankriss_entangle);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPAWN_HATCHLING_1, SPELL_SPAWN_HATCHLING_2, SPELL_SPAWN_HATCHLING_3 });
    }

    void HandleAfterCast()
    {
        switch (GetSpellInfo()->Id)
        {
            case SPELL_ENTANGLE_1:
                GetCaster()->CastSpell(GetCaster(), SPELL_SPAWN_HATCHLING_1, true);
                break;
            case SPELL_ENTANGLE_2:
                GetCaster()->CastSpell(GetCaster(), SPELL_SPAWN_HATCHLING_2, true);
                break;
            case SPELL_ENTANGLE_3:
                GetCaster()->CastSpell(GetCaster(), SPELL_SPAWN_HATCHLING_3, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_fankriss_entangle::HandleAfterCast);
    }
};

void AddSC_boss_fankriss()
{
    RegisterAQ40CreatureAI(boss_fankriss);
    RegisterSpellScript(spell_fankriss_entangle);
}
