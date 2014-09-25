/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SpellScript.h"

/*######
## npc_whisperwind_lasher
######*/

enum WhisperwindLasher
{
    EVENT_CHECK_OOC        = 1,
    SPELL_INFECTED_WOULD   = 52225,
    SPELL_STAND            = 37752,
    NPC_WHISPERWIND_LASHER = 47747,
    NPC_CORRUPTED_LASHER   = 48387,
    FACTION_HOSTILE        = 14,
    CHANCE_HOSTILE         = 30
};

class npc_whisperwind_lasher : public CreatureScript
{
public:
    npc_whisperwind_lasher() : CreatureScript("npc_whisperwind_lasher") { }

    struct npc_whisperwind_lasherAI : public ScriptedAI
    {
        npc_whisperwind_lasherAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            lasher_clicked = false;
        }

        void OnSpellClick(Unit* clicker, bool& result) override
        {
            if (!result)
                return;

            if (roll_chance_i(CHANCE_HOSTILE))
            {
                me->CastSpell(me, SPELL_INFECTED_WOULD);
                me->SetEntry(NPC_CORRUPTED_LASHER);
                me->setFaction(FACTION_HOSTILE);
            }
            else
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            me->CastSpell(me, SPELL_STAND);
            me->GetMotionMaster()->MoveRandom(8.0f);
            events.ScheduleEvent(EVENT_CHECK_OOC, 20000);
            lasher_clicked = true;

            if (Player* player = clicker->ToPlayer())
                player->KilledMonsterCredit(NPC_WHISPERWIND_LASHER);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!lasher_clicked)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_OOC:
                    if (!me->IsInCombat())
                        me->DespawnOrUnsummon();
                    else
                        events.ScheduleEvent(EVENT_CHECK_OOC, 5000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        bool lasher_clicked;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_whisperwind_lasherAI(creature);
    }
};

/*#####
# Spell 88254 "Swipe Honey" scripted for quest 27989 "Ruumbo Demands Honey"
#####*/

enum SwipeHoney
{
    NPC_HONEY_BUNNY = 47308,
    ITEM_HONEY_GLOB = 62820,
    SPELL_BEES      = 94064
};

class spell_swipe_honey : public SpellScriptLoader
{
public:
    spell_swipe_honey() : SpellScriptLoader("spell_swipe_honey") { }

    class spell_swipe_honey_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_swipe_honey_SpellScript);

        SpellCastResult CheckTarget()
        {
            if (GetCaster()->FindNearestCreature(NPC_HONEY_BUNNY, 5.0f, true))
                return SPELL_CAST_OK;
            return SPELL_FAILED_OUT_OF_RANGE;
        }

        void HandleDummy(SpellEffIndex /* effIndex */)
        {
            if (Creature* honey = GetCaster()->FindNearestCreature(NPC_HONEY_BUNNY, 5.0f, true))
            {
                if (Player* player = GetCaster()->ToPlayer())
                {
                    player->AddItem(ITEM_HONEY_GLOB, 1);

                    if (urand(1, 100) < 30)
                        honey->CastSpell(player, SPELL_BEES);
                    else
                        honey->DespawnOrUnsummon();
                }
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_swipe_honey_SpellScript::CheckTarget);
            OnEffectHitTarget += SpellEffectFn(spell_swipe_honey_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_swipe_honey_SpellScript();
    }
};

/*#####
# Spell 88425 "Bees! BEES!" scripted for quest 27989 "Ruumbo Demands Honey"
#####*/

enum BeesBEES
{
    BOSS_EMOTE_BEES = 0,
    SPELL_BEES_BEES = 88425
};

class spell_beesbees : public SpellScriptLoader
{
public: spell_beesbees() : SpellScriptLoader("spell_beesbees") { }

        class spell_beesbees_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_beesbees_SpellScript);

            void HandleScriptEffect(SpellEffIndex /* effIndex */)
            {
                if (Creature* honey = GetCaster()->ToCreature())
                {
                    if (Player* player = GetHitPlayer())
                    {
                        honey->AI()->Talk(BOSS_EMOTE_BEES, player);
                        honey->CastSpell(player, SPELL_BEES_BEES);
                        honey->DespawnOrUnsummon();
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_beesbees_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_beesbees_SpellScript();
        }
};

/*#####
# Spell 88665 "Ruumbo's Silly Dance" scripted for quest 27995 "Dance for Ruumbo!"
#####*/

enum RuumbosSillyDance
{
    NPC_DRIZZLE  = 47556,
    NPC_FERLI    = 47558,
    MAP_KALIMDOR = 1
};

Position const DrizzleSpawnPos = { 3852.52f, -1321.92f, 213.3353f, 5.72468f };
Position const FerliSpawnPos = { 3850.44f, -1323.34f, 213.2113f, 5.637414f };

class spell_ruumbos_silly_dance : public SpellScriptLoader
{
public: spell_ruumbos_silly_dance() : SpellScriptLoader("spell_ruumbos_silly_dance") { }

        class spell_ruumbos_silly_dance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ruumbos_silly_dance_SpellScript);

            void HandleScriptEffect(SpellEffIndex /* effIndex */)
            {
                if (Player* player = GetHitPlayer())
                {
                    player->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_DANCE);

                    if (player->GetMap()->GetId() == MAP_KALIMDOR)
                    {
                        player->SummonCreature(NPC_DRIZZLE, DrizzleSpawnPos, TEMPSUMMON_TIMED_DESPAWN, 20000);
                        player->SummonCreature(NPC_FERLI, FerliSpawnPos, TEMPSUMMON_TIMED_DESPAWN, 20000);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_ruumbos_silly_dance_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ruumbos_silly_dance_SpellScript();
        }
};

void AddSC_felwood()
{
    new npc_whisperwind_lasher();
    new spell_swipe_honey();
    new spell_beesbees();
    new spell_ruumbos_silly_dance();
}
