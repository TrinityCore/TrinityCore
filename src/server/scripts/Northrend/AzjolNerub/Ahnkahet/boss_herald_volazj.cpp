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
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_INSANITY                                = 57496, //Dummy
    INSANITY_VISUAL                               = 57561,
    SPELL_INSANITY_TARGET                         = 57508,
    SPELL_MIND_FLAY                               = 57941,
    SPELL_SHADOW_BOLT_VOLLEY                      = 57942,
    SPELL_SHIVER                                  = 57949,
    SPELL_CLONE_PLAYER                            = 57507, //cast on player during insanity
    SPELL_INSANITY_PHASING_1                      = 57508,
    SPELL_INSANITY_PHASING_2                      = 57509,
    SPELL_INSANITY_PHASING_3                      = 57510,
    SPELL_INSANITY_PHASING_4                      = 57511,
    SPELL_INSANITY_PHASING_5                      = 57512
};

enum Yells
{
    SAY_AGGRO   = 0,
    SAY_SLAY    = 1,
    SAY_DEATH   = 2,
    SAY_PHASE   = 3
};

enum Achievements
{
    ACHIEV_QUICK_DEMISE_START_EVENT               = 20382,
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

        _instance->DoStopCriteriaTimer(CriteriaStartEvent::SendEvent, ACHIEV_QUICK_DEMISE_START_EVENT);

        // Visible for all players in insanity
        for (uint32 i = 173; i <= 177; ++i)
            PhasingHandler::AddPhase(me, i, false);
        PhasingHandler::AddPhase(me, 169, true);

        ResetPlayersPhaseMask();

        // Cleanup
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
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
        if (me->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
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
                // Unattackable
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
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
                    PhasingHandler::AddPhase(summon, 173 + _insanityHandled, true);
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
            for (uint32 index = 0; index <= 4; ++index)
                player->RemoveAurasDueToSpell(SPELL_INSANITY_TARGET + index);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        _instance->DoStartCriteriaTimer(CriteriaStartEvent::SendEvent, ACHIEV_QUICK_DEMISE_START_EVENT);
    }

    uint32 GetSpellForPhaseMask(uint32 phase)
    {
        uint32 spell = 0;
        switch (phase)
        {
            case 173:
                spell = SPELL_INSANITY_PHASING_1;
                break;
            case 174:
                spell = SPELL_INSANITY_PHASING_2;
                break;
            case 175:
                spell = SPELL_INSANITY_PHASING_3;
                break;
            case 176:
                spell = SPELL_INSANITY_PHASING_4;
                break;
            case 177:
                spell = SPELL_INSANITY_PHASING_5;
                break;
        }
        return spell;
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        BossAI::SummonedCreatureDespawn(summon);

        uint32 phase = !summon->GetPhaseShift().GetPhases().empty() ? summon->GetPhaseShift().GetPhases().begin()->Id : 0;
        uint32 nextPhase = 0;

        // Check if all summons in this phase killed
        for (SummonList::const_iterator iter = summons.begin(); iter != summons.end(); ++iter)
        {
            if (Creature* visage = ObjectAccessor::GetCreature(*me, *iter))
            {
                // Not all are dead
                if (visage->IsInPhase(summon))
                    return;
                else if (!visage->GetPhaseShift().GetPhases().empty())
                {
                    nextPhase = visage->GetPhaseShift().GetPhases().begin()->Id;
                    break;
                }
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
            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
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

        Talk(SAY_DEATH);
        ResetPlayersPhaseMask();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

private:
    InstanceScript* _instance;

    uint32 _insanityHandled;
};

void AddSC_boss_volazj()
{
    RegisterAhnKahetCreatureAI(boss_volazj);
}
