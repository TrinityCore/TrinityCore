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
#include "ulduar.h"

enum Yells
{
    SAY_AGGRO                                   = -1603180,
    SAY_AGGRO_WITH_ELDER                        = -1603181,
    SAY_SLAY_1                                  = -1603182,
    SAY_SLAY_2                                  = -1603183,
    SAY_DEATH                                   = -1603184,
    SAY_BERSERK                                 = -1603185,
    SAY_SUMMON_CONSERVATOR                      = -1603186,
    SAY_SUMMON_TRIO                             = -1603187,
    SAY_SUMMON_LASHERS                          = -1603188,
    SAY_YS_HELP                                 = -1603189,

    // Elder Brightleaf
    SAY_BRIGHTLEAF_AGGRO                        = -1603190,
    SAY_BRIGHTLEAF_SLAY_1                       = -1603191,
    SAY_BRIGHTLEAF_SLAY_2                       = -1603192,
    SAY_BRIGHTLEAF_DEATH                        = -1603193,

    // Elder Ironbranch
    SAY_IRONBRANCH_AGGRO                        = -1603194,
    SAY_IRONBRANCH_SLAY_1                       = -1603195,
    SAY_IRONBRANCH_SLAY_2                       = -1603196,
    SAY_IRONBRANCH_DEATH                        = -1603197,

    // Elder Stonebark
    SAY_STONEBARK_AGGRO                         = -1603198,
    SAY_STONEBARK_SLAY_1                        = -1603199,
    SAY_STONEBARK_SLAY_2                        = -1603200,
    SAY_STONEBARK_DEATH                         = -1603201,
};

enum
{
    // Con-speed-atory timed achievement.
    // TODO Should be started when 1st trash is killed.
    ACHIEV_CON_SPEED_ATORY_START_EVENT            = 21597,
    SPELL_ACHIEVEMENT_CHECK                       = 65074,

    // Lumberjacked timed achievement.
    // TODO should be started when 1st elder is killed.
    // Spell should be casted when 3rd elder is killed.
    ACHIEV_LUMBERJACKED                           = 21686,
    SPELL_LUMBERJACKED_ACHIEVEMENT_CHECK          = 65296,
};

class boss_freya : public CreatureScript
{
public:
    boss_freya() : CreatureScript("boss_freya") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_freyaAI(pCreature);
    }

    struct boss_freyaAI : public BossAI
    {
        boss_freyaAI(Creature* pCreature) : BossAI(pCreature, TYPE_FREYA)
        {
        }

        void Reset()
        {
            _Reset();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();

            // cast is not rewarding the achievement.
            // DoCast(SPELL_ACHIEVEMENT_CHECK);
            instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT_CHECK);
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);
            _EnterCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
    //SPELLS TODO:

    //
            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }
    };

};

enum eSpells
{
    SPELL_ATTUNED_TO_NATURE_2_DOSE_REDUCTION     = 62524,
    SPELL_ATTUNED_TO_NATURE_10_DOSE_REDUCTION    = 62525,
    SPELL_ATTUNED_TO_NATURE_25_DOSE_REDUCTION    = 62521,
};

class spell_attuned_to_nature_dose_reduction : public SpellScriptLoader
{
public:
    spell_attuned_to_nature_dose_reduction() : SpellScriptLoader("spell_attuned_to_nature_dose_reduction") { }

    class spell_attuned_to_nature_dose_reduction_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_attuned_to_nature_dose_reduction_SpellScript)

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit * target = GetHitUnit();
            SpellEntry const * m_spellInfo = GetSpellInfo();
            switch (m_spellInfo->Id)
            {
                case SPELL_ATTUNED_TO_NATURE_2_DOSE_REDUCTION:
                    if (target->HasAura(GetEffectValue()))
                        for (uint8 n = 0; n < 2; n++)
                            target->RemoveAuraFromStack(GetEffectValue(), 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                case SPELL_ATTUNED_TO_NATURE_10_DOSE_REDUCTION:
                    if (target->HasAura(GetEffectValue()))
                        for (uint8 n = 0; n < 10; n++)
                            target->RemoveAuraFromStack(GetEffectValue(), 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                case SPELL_ATTUNED_TO_NATURE_25_DOSE_REDUCTION:
                    if (target->HasAura(GetEffectValue()))
                        for (uint8 n = 0; n < 25; n++)
                            target->RemoveAuraFromStack(GetEffectValue(), 0, AURA_REMOVE_BY_DEFAULT);
                    break;
                default:
                    break;
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_attuned_to_nature_dose_reduction_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript * GetSpellScript() const
    {
        return new spell_attuned_to_nature_dose_reduction_SpellScript();
    }
};

void AddSC_boss_freya()
{
    new boss_freya();
    new spell_attuned_to_nature_dose_reduction();
}
