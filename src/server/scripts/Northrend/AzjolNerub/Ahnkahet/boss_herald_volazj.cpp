/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "SpellMgr.h"
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

class boss_volazj : public CreatureScript
{
public:
    boss_volazj() : CreatureScript("boss_volazj") { }

    struct boss_volazjAI : public ScriptedAI
    {
        boss_volazjAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            uiMindFlayTimer = 8 * IN_MILLISECONDS;
            uiShadowBoltVolleyTimer = 5 * IN_MILLISECONDS;
            uiShiverTimer = 15 * IN_MILLISECONDS;
            // Used for Insanity handling
            insanityHandled = 0;
        }

        InstanceScript* instance;

        uint32 uiMindFlayTimer;
        uint32 uiShadowBoltVolleyTimer;
        uint32 uiShiverTimer;
        uint32 insanityHandled;
        SummonList Summons;

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

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_INSANITY)
            {
                // Not good target or too many players
                if (target->GetTypeId() != TYPEID_PLAYER || insanityHandled > 4)
                    return;
                // First target - start channel visual and set self as unnattackable
                if (!insanityHandled)
                {
                    // Channel visual
                    DoCast(me, INSANITY_VISUAL, true);
                    // Unattackable
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetControlled(true, UNIT_STATE_STUNNED);
                }

                // phase the player
                target->CastSpell(target, SPELL_INSANITY_TARGET + insanityHandled, true);

                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_INSANITY_TARGET + insanityHandled);
                if (!spellInfo)
                    return;

                // summon twisted party members for this target
                Map::PlayerList const &players = me->GetMap()->GetPlayers();
                for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                {
                    Player* player = i->GetSource();
                    if (!player || !player->IsAlive())
                        continue;
                    // Summon clone
                    if (Unit* summon = me->SummonCreature(NPC_TWISTED_VISAGE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 0))
                    {
                        // clone
                        player->CastSpell(summon, SPELL_CLONE_PLAYER, true);
                        // phase the summon
                        PhasingHandler::AddPhase(summon, spellInfo->GetEffect(EFFECT_0)->MiscValueB, true);
                    }
                }
                ++insanityHandled;
            }
        }

        void ResetPlayersPhase()
        {
            Map::PlayerList const &players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            {
                Player* player = i->GetSource();
                for (uint32 index = 0; index <= 4; ++index)
                    player->RemoveAurasDueToSpell(SPELL_INSANITY_TARGET + index);
            }
        }

        void Reset() override
        {
            Initialize();

            instance->SetBossState(DATA_HERALD_VOLAZJ, NOT_STARTED);
            instance->DoStopCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);

            // Visible for all players in insanity
            for (uint32 i = 173; i <= 177; ++i)
                PhasingHandler::AddPhase(me, i, false);
            PhasingHandler::AddPhase(me, 169, true);

            ResetPlayersPhase();

            // Cleanup
            Summons.DespawnAll();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetControlled(false, UNIT_STATE_STUNNED);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            instance->SetBossState(DATA_HERALD_VOLAZJ, IN_PROGRESS);
            instance->DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_QUICK_DEMISE_START_EVENT);
        }

        void JustSummoned(Creature* summon) override
        {
            Summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            uint32 nextPhase = 0;
            Summons.Despawn(summon);

            // Check if all summons in this phase killed
            for (SummonList::const_iterator iter = Summons.begin(); iter != Summons.end(); ++iter)
            {
                if (Creature* visage = ObjectAccessor::GetCreature(*me, *iter))
                {
                    // Not all are dead
                    if (visage->IsInPhase(summon))
                        return;
                    else
                    {
                        nextPhase = visage->GetPhaseShift().GetPhases().begin()->Id;
                        break;
                    }
                }
            }

            // Roll Insanity
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            {
                if (Player* player = i->GetSource())
                {
                    for (uint32 index = 0; index <= 4; ++index)
                        player->RemoveAurasDueToSpell(SPELL_INSANITY_TARGET + index);
                    player->CastSpell(player, SPELL_INSANITY_TARGET + nextPhase - 173, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (insanityHandled)
            {
                if (!Summons.empty())
                    return;

                insanityHandled = 0;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetControlled(false, UNIT_STATE_STUNNED);
                me->RemoveAurasDueToSpell(INSANITY_VISUAL);
            }

            if (uiMindFlayTimer <= diff)
            {
                DoCastVictim(SPELL_MIND_FLAY);
                uiMindFlayTimer = 20*IN_MILLISECONDS;
            } else uiMindFlayTimer -= diff;

            if (uiShadowBoltVolleyTimer <= diff)
            {
                DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                uiShadowBoltVolleyTimer = 5*IN_MILLISECONDS;
            } else uiShadowBoltVolleyTimer -= diff;

            if (uiShiverTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SHIVER);
                uiShiverTimer = 15*IN_MILLISECONDS;
            } else uiShiverTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetBossState(DATA_HERALD_VOLAZJ, DONE);

            Summons.DespawnAll();
            ResetPlayersPhase();
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAhnKahetAI<boss_volazjAI>(creature);
    }
};

void AddSC_boss_volazj()
{
    new boss_volazj();
}
