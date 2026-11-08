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
 * He should call trash(from the room with Embalming Slime up to frogger(not sure
  if trash before Embalming Slime too or not)) after aggro
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "naxxramas.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum PatchwerkTexts
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    EMOTE_BERSERK               = 3,
    EMOTE_FRENZY                = 4
};

enum PatchwerkSpells
{
    SPELL_HATEFUL_STRIKE_PRIMER = 28307,
    SPELL_HATEFUL_STRIKE        = 28308,
    SPELL_HATEFUL_STRIKE_HEROIC = 59192,
    SPELL_FRENZY                = 28131,
    SPELL_BERSERK               = 26662,
    SPELL_SLIME_BOLT            = 32309
};

enum PatchwerkEvents
{
    EVENT_BERSERK = 1,
    EVENT_HATEFUL,
    EVENT_SLIME
};

enum Misc
{
    ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT  = 10286
};

enum HatefulThreatAmounts
{
    HATEFUL_THREAT_AMT  = 1000,
};

struct boss_patchwerk : public BossAI
{
    boss_patchwerk(Creature* creature) : BossAI(creature, BOSS_PATCHWERK), _enraged(false) { }

    void Reset() override
    {
        _Reset();
        _enraged = false;

        instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
    }

    void KilledUnit(Unit* /*Victim*/) override
    {
        // 20s cd, not random
        if (!(rand32() % 5))
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_HATEFUL, 3600ms);
        events.ScheduleEvent(EVENT_BERSERK, 6min);

        instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HATEFUL:
                    DoCastSelf(SPELL_HATEFUL_STRIKE_PRIMER, true);
                    events.Repeat(1200ms);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK, true);
                    Talk(EMOTE_BERSERK);
                    events.ScheduleEvent(EVENT_SLIME, 2s);
                    break;
                case EVENT_SLIME:
                    DoCastAOE(SPELL_SLIME_BOLT, true);
                    events.Repeat(Seconds(2));
                    break;
            }
        }

        if (!_enraged && !HealthAbovePct(5))
        {
            DoCastSelf(SPELL_FRENZY, true);
            Talk(EMOTE_FRENZY);
            _enraged = true;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _enraged;
};

// 28307 - Hateful Strike Primer
class spell_patchwerk_hateful_strike_primer : public SpellScript
{
    PrepareSpellScript(spell_patchwerk_hateful_strike_primer);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HATEFUL_STRIKE, SPELL_HATEFUL_STRIKE_HEROIC });
    }

    void SelectTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();

        uint32 targetLimit = caster->GetMap()->Is25ManRaid() ? 3 : 2;
        std::array<Unit*, 3> newTargets = { };
        auto newTargetsItr = newTargets.begin();
        auto newTargetsEnd = newTargetsItr + targetLimit;

        for (ThreatReference const* threatRef : caster->GetThreatManager().GetSortedThreatList())
        {
            if (!threatRef->IsOnline() || !threatRef->GetVictim()->IsPlayer() || !caster->IsWithinMeleeRange(threatRef->GetVictim()))
                continue;

            *newTargetsItr = threatRef->GetVictim();
            if (++newTargetsItr == newTargetsEnd)
                break;
        }

        // Hateful Strike damages the higher HP target out of the two highest non-MT threats in melee range on 25man
        if (newTargets[1] && newTargets[2] && newTargets[1]->GetHealth() < newTargets[2]->GetHealth())
            std::swap(newTargets[1], newTargets[2]);

        targets.assign(newTargets.begin(), newTargetsItr);
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();

        // all targets get threat increase
        caster->GetThreatManager().AddThreat(GetHitUnit(), HATEFUL_THREAT_AMT, GetSpellInfo());

        // Hateful Strike damages the second unit on target list (not the MT)
        // or MT if it is the only target
        if (GetUnitTargetIndexForEffect(GetHitUnit()->GetGUID(), effIndex) == 1
            || GetUnitTargetCountForEffect(effIndex) == 1)
            caster->CastSpell(GetHitUnit(), caster->GetMap()->Is25ManRaid() ? SPELL_HATEFUL_STRIKE_HEROIC : SPELL_HATEFUL_STRIKE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_patchwerk_hateful_strike_primer::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_patchwerk_hateful_strike_primer::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_patchwerk()
{
    RegisterNaxxramasCreatureAI(boss_patchwerk);
    RegisterSpellScript(spell_patchwerk_hateful_strike_primer);
}
