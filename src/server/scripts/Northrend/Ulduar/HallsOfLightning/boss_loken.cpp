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
SDName: Boss Loken
SD%Complete: 60%
SDComment: Missing intro.
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "halls_of_lightning.h"

enum Yells
{
    SAY_INTRO_1                                   = 0,
    SAY_INTRO_2                                   = 1,
    SAY_AGGRO                                     = 2,
    SAY_NOVA                                      = 3,
    SAY_SLAY                                      = 4,
    SAY_75HEALTH                                  = 5,
    SAY_50HEALTH                                  = 6,
    SAY_25HEALTH                                  = 7,
    SAY_DEATH                                     = 8,
    EMOTE_NOVA                                    = 9
};

enum Spells
{
    SPELL_ARC_LIGHTNING                           = 52921,
    SPELL_LIGHTNING_NOVA_N                        = 52960,
    SPELL_LIGHTNING_NOVA_H                        = 59835,

    SPELL_PULSING_SHOCKWAVE_N                     = 52961,
    SPELL_PULSING_SHOCKWAVE_H                     = 59836,
    SPELL_PULSING_SHOCKWAVE_AURA                  = 59414
};

enum Misc
{
    ACHIEV_TIMELY_DEATH_START_EVENT               = 20384
};

/*######
## Boss Loken
######*/

class boss_loken : public CreatureScript
{
public:
    boss_loken() : CreatureScript("boss_loken") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_lokenAI(creature);
    }

    struct boss_lokenAI : public ScriptedAI
    {
        boss_lokenAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 m_uiArcLightning_Timer;
        uint32 m_uiLightningNova_Timer;
        uint32 m_uiResumePulsingShockwave_Timer;

        uint32 m_uiHealthAmountModifier;

        void Reset() OVERRIDE
        {
            m_uiArcLightning_Timer = 15000;
            m_uiLightningNova_Timer = 20000;
            m_uiResumePulsingShockwave_Timer = 1000;

            m_uiHealthAmountModifier = 1;

            if (instance)
            {
                instance->SetBossState(DATA_LOKEN, NOT_STARTED);
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMELY_DEATH_START_EVENT);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);

            if (instance)
            {
                instance->SetBossState(DATA_LOKEN, IN_PROGRESS);
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMELY_DEATH_START_EVENT);
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (instance)
            {
                instance->SetBossState(DATA_LOKEN, DONE);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_PULSING_SHOCKWAVE_AURA);
            }
        }

        void KilledUnit(Unit* who) OVERRIDE
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (m_uiResumePulsingShockwave_Timer)
            {
                if (m_uiResumePulsingShockwave_Timer <= uiDiff)
                {
                    DoCast(me, SPELL_PULSING_SHOCKWAVE_AURA, true);
                    me->ClearUnitState(UNIT_STATE_CASTING); // this flag breaks movement

                    DoCast(me, SPELL_PULSING_SHOCKWAVE_N, true);
                    m_uiResumePulsingShockwave_Timer = 0;
                }
                else
                    m_uiResumePulsingShockwave_Timer -= uiDiff;
            }

            if (m_uiArcLightning_Timer <= uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_ARC_LIGHTNING);

                m_uiArcLightning_Timer = urand(15000, 16000);
            }
            else
                m_uiArcLightning_Timer -= uiDiff;

            if (m_uiLightningNova_Timer <= uiDiff)
            {
                Talk(SAY_NOVA);
                Talk(EMOTE_NOVA);
                DoCast(me, SPELL_LIGHTNING_NOVA_N);

                me->RemoveAurasDueToSpell(DUNGEON_MODE<uint32>(SPELL_PULSING_SHOCKWAVE_N, SPELL_PULSING_SHOCKWAVE_H));
                m_uiResumePulsingShockwave_Timer = DUNGEON_MODE(5000, 4000); // Pause Pulsing Shockwave aura
                m_uiLightningNova_Timer = urand(20000, 21000);
            }
            else
                m_uiLightningNova_Timer -= uiDiff;

            // Health check
            if (HealthBelowPct(100 - 25 * m_uiHealthAmountModifier))
            {
                switch (m_uiHealthAmountModifier)
                {
                    case 1: Talk(SAY_75HEALTH); break;
                    case 2: Talk(SAY_50HEALTH); break;
                    case 3: Talk(SAY_25HEALTH); break;
                }

                ++m_uiHealthAmountModifier;
            }

            DoMeleeAttackIfReady();
        }
    };

};

class spell_loken_pulsing_shockwave : public SpellScriptLoader
{
    public:
        spell_loken_pulsing_shockwave() : SpellScriptLoader("spell_loken_pulsing_shockwave") { }

        class spell_loken_pulsing_shockwave_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_loken_pulsing_shockwave_SpellScript);

            void CalculateDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetHitUnit())
                    return;

                float distance = GetCaster()->GetDistance2d(GetHitUnit());
                if (distance > 1.0f)
                    SetHitDamage(int32(GetHitDamage() * distance));
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_loken_pulsing_shockwave_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_loken_pulsing_shockwave_SpellScript();
        }
};

void AddSC_boss_loken()
{
    new boss_loken();
    new spell_loken_pulsing_shockwave();
}
