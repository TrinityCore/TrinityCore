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
 * Comment: Missing AI for Twisted Visages
 */

#include "ScriptMgr.h"
#include "ahnkahet.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum VolazjTexts
{
    SAY_AGGRO                         = 0,
    SAY_INSANITY                      = 1,
    SAY_SLAY_1                        = 2,
    SAY_SLAY_2                        = 3,
    SAY_SLAY_3                        = 4,
    SAY_DEATH_1                       = 5,
    SAY_DEATH_2                       = 6,

    WHISPER_AGGRO                     = 7,
    WHISPER_INSANITY                  = 8,
    WHISPER_SLAY_1                    = 9,
    WHISPER_SLAY_2                    = 10,
    WHISPER_SLAY_3                    = 11,
    WHISPER_DEATH_1                   = 12,
    WHISPER_DEATH_2                   = 13
};

enum VolazjSpells
{
    SPELL_INSANITY                    = 57496, // Dummy
    INSANITY_VISUAL                   = 57561,
    SPELL_INSANITY_TARGET             = 57508,
    SPELL_MIND_FLAY                   = 57941,
    SPELL_SHADOW_BOLT_VOLLEY          = 57942,
    SPELL_SHIVER                      = 57949,
    SPELL_CLONE_PLAYER                = 57507, // cast on player during insanity
    SPELL_INSANITY_PHASING_1          = 57508,
    SPELL_INSANITY_PHASING_2          = 57509,
    SPELL_INSANITY_PHASING_3          = 57510,
    SPELL_INSANITY_PHASING_4          = 57511,
    SPELL_INSANITY_PHASING_5          = 57512,

    SPELL_WHISPER_AGGRO               = 60291,
    SPELL_WHISPER_INSANITY            = 60292,
    SPELL_WHISPER_SLAY_1              = 60293,
    SPELL_WHISPER_SLAY_2              = 60294,
    SPELL_WHISPER_SLAY_3              = 60295,
    SPELL_WHISPER_DEATH_1             = 60296,
    SPELL_WHISPER_DEATH_2             = 60297
};

enum VolazjAchievements
{
    ACHIEV_QUICK_DEMISE_START_EVENT   = 20382,
};

struct boss_volazj : public BossAI
{
    boss_volazj(Creature* creature) : BossAI(creature, DATA_HERALD_VOLAZJ), _insanityHandled(0)
    {
        Initialize();
        _instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        BossAI::Reset();

        Initialize();

        _instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);

        // Visible for all players in insanity
        me->SetPhaseMask((1|16|32|64|128|256), true);

        ResetPlayersPhaseMask();

        // Cleanup
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetControlled(false, UNIT_STATE_STUNNED);
    }

    void Initialize()
    {
        // Used for Insanity handling
        _insanityHandled = 0;
    }

    void ScheduleTasks() override
    {
        scheduler.Schedule(8s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_MIND_FLAY);
                task.Repeat(20s);
            })
            .Schedule(5s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                task.Repeat();
            })
            .Schedule(15s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_SHIVER);
                task.Repeat();
            });
    }

    // returns the percentage of health after taking the given damage.
    uint32 GetHealthPct(uint32 damage)
    {
        if (damage > me->GetHealth())
            return 0;
        return 100*(me->GetHealth()-damage)/me->GetMaxHealth();
    }

    void DamageTaken(Unit* /*pAttacker*/, uint32 &damage) override
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
            damage = 0;

        if ((GetHealthPct(0) >= 66 && GetHealthPct(damage) < 66)||
            (GetHealthPct(0) >= 33 && GetHealthPct(damage) < 33))
        {
            me->InterruptNonMeleeSpells(false);
            DoCast(me, SPELL_INSANITY, false);
        }
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_INSANITY)
        {
            // Not good target or too many players
            if (target->GetTypeId() != TYPEID_PLAYER || _insanityHandled > 4)
                return;
            // First target - start channel visual and set self as unnattackable
            if (!_insanityHandled)
            {
                // Channel visual
                DoCast(me, INSANITY_VISUAL, true);
                Talk(SAY_INSANITY);
                DoCastSelf(SPELL_WHISPER_INSANITY, true);
                // Unattackable
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetControlled(true, UNIT_STATE_STUNNED);
            }
            // phase mask
            target->CastSpell(target, SPELL_INSANITY_TARGET + _insanityHandled, true);
            // summon twisted party members for this target
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            {
                Player* player = i->GetSource();
                if (!player || !player->IsAlive())
                    continue;
                // Summon clone
                if (Unit* summon = me->SummonCreature(NPC_TWISTED_VISAGE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN))
                {
                    // clone
                    player->CastSpell(summon, SPELL_CLONE_PLAYER, true);
                    // set phase
                    summon->SetPhaseMask((1<<(4 + _insanityHandled)), true);
                }
            }
            ++_insanityHandled;
        }
    }

    void ResetPlayersPhaseMask()
    {
        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
        {
            Player* player = i->GetSource();
            player->RemoveAurasDueToSpell(GetSpellForPhaseMask(player->GetPhaseMask()));
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_WHISPER_AGGRO);

        _instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);
    }

    uint32 GetSpellForPhaseMask(uint32 phase)
    {
        uint32 spell = 0;
        switch (phase)
        {
            case 16:
                spell = SPELL_INSANITY_PHASING_1;
                break;
            case 32:
                spell = SPELL_INSANITY_PHASING_2;
                break;
            case 64:
                spell = SPELL_INSANITY_PHASING_3;
                break;
            case 128:
                spell = SPELL_INSANITY_PHASING_4;
                break;
            case 256:
                spell = SPELL_INSANITY_PHASING_5;
                break;
        }
        return spell;
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);

        uint32 phase = summon->GetPhaseMask();
        uint32 nextPhase = 0;

        // Check if all summons in this phase killed
        for (SummonList::const_iterator iter = summons.begin(); iter != summons.end(); ++iter)
        {
            if (Creature* visage = ObjectAccessor::GetCreature(*me, *iter))
            {
                // Not all are dead
                if (phase == visage->GetPhaseMask())
                    return;
                else
                    nextPhase = visage->GetPhaseMask();
            }
        }

        // Roll Insanity
        uint32 spell = GetSpellForPhaseMask(phase);
        uint32 spell2 = GetSpellForPhaseMask(nextPhase);
        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
        if (!PlayerList.isEmpty())
        {
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    if (player->HasAura(spell))
                    {
                        player->RemoveAurasDueToSpell(spell);
                        if (spell2) // if there is still some different mask cast spell for it
                            player->CastSpell(player, spell2, true);
                    }
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (_insanityHandled)
        {
            if (!summons.empty())
                return;

            _insanityHandled = 0;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetControlled(false, UNIT_STATE_STUNNED);
            me->RemoveAurasDueToSpell(INSANITY_VISUAL);
        }

        scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        ResetPlayersPhaseMask();

        switch (urand(0, 1))
        {
            case 0:
                Talk(SAY_DEATH_1);
                DoCastSelf(SPELL_WHISPER_DEATH_1, true);
                break;
            case 1:
                Talk(SAY_DEATH_2);
                DoCastSelf(SPELL_WHISPER_DEATH_2, true);
                break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER)
            return;

        switch (urand(0, 2))
        {
            case 0:
                Talk(SAY_SLAY_1);
                DoCastSelf(SPELL_WHISPER_SLAY_1);
                break;
            case 1:
                Talk(SAY_SLAY_2);
                DoCastSelf(SPELL_WHISPER_SLAY_2);
                break;
            case 2:
                Talk(SAY_SLAY_3);
                DoCastSelf(SPELL_WHISPER_SLAY_3);
                break;
        }
    }

private:
    InstanceScript* _instance;

    uint32 _insanityHandled;
};

/* 60291 - Volazj Whisper: Aggro
   60292 - Volazj Whisper: Insanity
   60293 - Volazj Whisper: Slay 01
   60294 - Volazj Whisper: Slay 02
   60295 - Volazj Whisper: Slay 03
   60296 - Volazj Whisper: Death 01
   60297 - Volazj Whisper: Death 02 */
class spell_volazj_whisper : public SpellScript
{
    PrepareSpellScript(spell_volazj_whisper);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_WHISPER_AGGRO,
            SPELL_WHISPER_INSANITY,
            SPELL_WHISPER_SLAY_1,
            SPELL_WHISPER_SLAY_2,
            SPELL_WHISPER_SLAY_3,
            SPELL_WHISPER_DEATH_1,
            SPELL_WHISPER_DEATH_2
        });
    }

    void HandleScriptEffect(SpellEffIndex /* effIndex */)
    {
        Unit* target = GetHitPlayer();
        Creature* caster = GetCaster()->ToCreature();
        if (!target || !caster)
            return;

        uint32 text = 0;
        switch (GetSpellInfo()->Id)
        {
            case SPELL_WHISPER_AGGRO:    text = WHISPER_AGGRO;    break;
            case SPELL_WHISPER_INSANITY: text = WHISPER_INSANITY; break;
            case SPELL_WHISPER_SLAY_1:   text = WHISPER_SLAY_1;   break;
            case SPELL_WHISPER_SLAY_2:   text = WHISPER_SLAY_2;   break;
            case SPELL_WHISPER_SLAY_3:   text = WHISPER_SLAY_3;   break;
            case SPELL_WHISPER_DEATH_1:  text = WHISPER_DEATH_1;  break;
            case SPELL_WHISPER_DEATH_2:  text = WHISPER_DEATH_2;  break;
            default: return;
        }
        caster->AI()->Talk(text, target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volazj_whisper::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_volazj()
{
    RegisterAhnKahetCreatureAI(boss_volazj);
    RegisterSpellScript(spell_volazj_whisper);
}
