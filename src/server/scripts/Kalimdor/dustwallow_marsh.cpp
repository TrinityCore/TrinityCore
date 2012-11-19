/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Dustwallow_Marsh
SD%Complete: 95
SDComment: Quest support: 1270, 1222, 27245
SDCategory: Dustwallow Marsh
EndScriptData */

/* ContentData
npc_stinky
go_blackhoof_cage
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"

/*######
## npc_stinky
######*/

enum Stinky
{
    QUEST_STINKYS_ESCAPE_H                       = 1270,
    QUEST_STINKYS_ESCAPE_A                       = 1222,
    SAY_QUEST_ACCEPTED                           = -1000507,
    SAY_STAY_1                                   = -1000508,
    SAY_STAY_2                                   = -1000509,
    SAY_STAY_3                                   = -1000510,
    SAY_STAY_4                                   = -1000511,
    SAY_STAY_5                                   = -1000512,
    SAY_STAY_6                                   = -1000513,
    SAY_QUEST_COMPLETE                           = -1000514,
    SAY_ATTACKED_1                               = -1000515,
    EMOTE_DISAPPEAR                              = -1000516
};

class npc_stinky : public CreatureScript
{
public:
   npc_stinky() : CreatureScript("npc_stinky") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_stinkyAI(creature);
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
         if (quest->GetQuestId() == QUEST_STINKYS_ESCAPE_H || quest->GetQuestId() == QUEST_STINKYS_ESCAPE_A)
         {
             if (npc_stinkyAI* pEscortAI = CAST_AI(npc_stinky::npc_stinkyAI, creature->AI()))
             {
                 creature->setFaction(FACTION_ESCORT_N_NEUTRAL_ACTIVE);
                 creature->SetStandState(UNIT_STAND_STATE_STAND);
                 DoScriptText(SAY_QUEST_ACCEPTED, creature);
                 pEscortAI->Start(false, false, player->GetGUID());
             }
         }
         return true;
    }

    struct npc_stinkyAI : public npc_escortAI
    {
       npc_stinkyAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 7:
                    DoScriptText(SAY_STAY_1, me, player);
                    break;
                case 11:
                    DoScriptText(SAY_STAY_2, me, player);
                    break;
                case 25:
                    DoScriptText(SAY_STAY_3, me, player);
                    break;
                case 26:
                    DoScriptText(SAY_STAY_4, me, player);
                    break;
                case 27:
                    DoScriptText(SAY_STAY_5, me, player);
                    break;
                case 28:
                    DoScriptText(SAY_STAY_6, me, player);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    break;
                case 29:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 37:
                    DoScriptText(SAY_QUEST_COMPLETE, me, player);
                    me->SetSpeed(MOVE_RUN, 1.2f, true);
                    me->SetWalk(false);
                    if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_H))
                        player->GroupEventHappens(QUEST_STINKYS_ESCAPE_H, me);
                    if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_A))
                        player->GroupEventHappens(QUEST_STINKYS_ESCAPE_A, me);
                    break;
                case 39:
                    DoScriptText(EMOTE_DISAPPEAR, me);
                    break;
            }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(SAY_ATTACKED_1, me, who);
        }

        void Reset() {}

        void JustDied(Unit* /*killer*/)
        {
            Player* player = GetPlayerForEscort();
            if (player && HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_H))
                    player->FailQuest(QUEST_STINKYS_ESCAPE_H);

                if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_A))
                    player->FailQuest(QUEST_STINKYS_ESCAPE_A);
            }
        }

       void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

enum SpellScripts
{
    SPELL_OOZE_ZAP              = 42489,
    SPELL_OOZE_ZAP_CHANNEL_END  = 42485,
    SPELL_OOZE_CHANNEL_CREDIT   = 42486,
    SPELL_ENERGIZED             = 42492,
};

class spell_ooze_zap : public SpellScriptLoader
{
    public:
        spell_ooze_zap() : SpellScriptLoader("spell_ooze_zap") { }

        class spell_ooze_zap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ooze_zap_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_OOZE_ZAP))
                    return false;
                return true;
            }

            SpellCastResult CheckRequirement()
            {
                if (!GetCaster()->HasAura(GetSpellInfo()->Effects[EFFECT_1].CalcValue()))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW; // This is actually correct

                if (!GetExplTargetUnit())
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (GetHitUnit())
                    GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ooze_zap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_ooze_zap_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ooze_zap_SpellScript();
        }
};

class spell_ooze_zap_channel_end : public SpellScriptLoader
{
    public:
        spell_ooze_zap_channel_end() : SpellScriptLoader("spell_ooze_zap_channel_end") { }

        class spell_ooze_zap_channel_end_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_ooze_zap_channel_end_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_OOZE_ZAP_CHANNEL_END))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Player* player = GetCaster()->ToPlayer())
                    player->CastSpell(player, SPELL_OOZE_CHANNEL_CREDIT, true);
                GetHitUnit()->Kill(GetHitUnit());
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_ooze_zap_channel_end_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_ooze_zap_channel_end_SpellScript();
        }
};

class spell_energize_aoe : public SpellScriptLoader
{
    public:
        spell_energize_aoe() : SpellScriptLoader("spell_energize_aoe") { }

        class spell_energize_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_energize_aoe_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_ENERGIZED))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
                {
                    if ((*itr)->GetTypeId() == TYPEID_PLAYER && (*itr)->ToPlayer()->GetQuestStatus(GetSpellInfo()->Effects[EFFECT_1].CalcValue()) == QUEST_STATUS_INCOMPLETE)
                        ++itr;
                    else
                        targets.erase(itr++);
                }
                targets.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_energize_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_energize_aoe_SpellScript();
        }
};

/*######
## go_blackhoof_cage
######*/

enum PrisonersOfTheGrimTotems
{
    NPC_THERAMORE_PRISONER                          = 23720,
    SAY_FREE                                        = 0,
};

class go_blackhoof_cage : public GameObjectScript
{
public:
    go_blackhoof_cage() : GameObjectScript("go_blackhoof_cage") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        if (Creature* prisoner = go->FindNearestCreature(NPC_THERAMORE_PRISONER, 1.0f))
        {
            go->UseDoorOrButton();
            if (player)
                player->KilledMonsterCredit(NPC_THERAMORE_PRISONER, 0);

            prisoner->AI()->Talk(SAY_FREE); // We also emote cry here (handled in creature_text.emote)
            prisoner->DespawnOrUnsummon(6000);
        }
        return true;
    }
};

void AddSC_dustwallow_marsh()
{
    new npc_stinky();
    new spell_ooze_zap();
    new spell_ooze_zap_channel_end();
    new spell_energize_aoe();
    new go_blackhoof_cage();
}
