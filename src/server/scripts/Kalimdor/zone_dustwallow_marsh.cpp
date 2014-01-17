/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
SDComment: Quest support: 11180, 558, 11126, 11142, 11174, Vendor Nat Pagle
SDCategory: Dustwallow Marsh
EndScriptData */

/* ContentData
npc_risen_husk_spirit
npc_lady_jaina_proudmoore
npc_nat_pagle
npc_private_hendel
npc_cassa_crimsonwing - handled by npc_taxi
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## npc_risen_husk_spirit
######*/

enum HauntingWitchHill
{
    // Quest
    QUEST_WHATS_HAUNTING_WITCH_HILL     = 11180,

    // General spells
    SPELL_SUMMON_RESTLESS_APPARITION    = 42511,
    SPELL_WITCH_HILL_INFORMATION_CREDIT = 42512,

    // Risen Husk specific
    SPELL_CONSUME_FLESH                 = 37933,
    NPC_RISEN_HUSK                      = 23555,

    // Risen Spirit specific
    SPELL_INTANGIBLE_PRESENCE           = 43127,
    NPC_RISEN_SPIRIT                    = 23554,

    // Events
    EVENT_CONSUME_FLESH                 = 1,
    EVENT_INTANGIBLE_PRESENCE           = 2,
};

class npc_risen_husk_spirit : public CreatureScript
{
    public:
        npc_risen_husk_spirit() : CreatureScript("npc_risen_husk_spirit") { }

        struct npc_risen_husk_spiritAI : public ScriptedAI
        {
            npc_risen_husk_spiritAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset() OVERRIDE
            {
                events.Reset();
                if (me->GetEntry() == NPC_RISEN_HUSK)
                    events.ScheduleEvent(EVENT_CONSUME_FLESH, 5000);
                else if (me->GetEntry() == NPC_RISEN_SPIRIT)
                    events.ScheduleEvent(EVENT_INTANGIBLE_PRESENCE, 5000);
            }

            void JustDied(Unit* killer) OVERRIDE
            {
                if (killer->GetTypeId() == TYPEID_PLAYER)
                {
                    if (killer->ToPlayer()->GetQuestStatus(QUEST_WHATS_HAUNTING_WITCH_HILL) == QUEST_STATUS_INCOMPLETE)
                    {
                        DoCast(me, SPELL_SUMMON_RESTLESS_APPARITION, true);
                        DoCast(killer, SPELL_WITCH_HILL_INFORMATION_CREDIT, true);
                    }
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CONSUME_FLESH:
                            DoCastVictim(SPELL_CONSUME_FLESH);
                            events.ScheduleEvent(EVENT_CONSUME_FLESH, 15000);
                            break;
                        case EVENT_INTANGIBLE_PRESENCE:
                            DoCastVictim(SPELL_INTANGIBLE_PRESENCE);
                            events.ScheduleEvent(EVENT_INTANGIBLE_PRESENCE, 15000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_risen_husk_spiritAI(creature);
        }
};

/*######
## npc_theramor_guard
######*/

enum TheramoreGuard
{
    QUEST_DISCREDITING_THE_DESERTERS            = 11133,

    NPC_THERAMORE_GUARD                         = 4979,

    SPELL_DOCTORED_LEAFLET                      = 42725,
    SPELL_PROPAGANDIZED                         = 42246,

    SAY_QUEST1                                  = 0,
    SAY_QUEST2                                  = 1,
    SAY_QUEST3                                  = 2
};

#define GOSSIP_ITEM_THERAMORE_GUARD "You look like an intelligent person. Why don't you read one of these leaflets and give it some thought?"

class npc_theramore_guard : public CreatureScript
{
public:
    npc_theramore_guard() : CreatureScript("npc_theramore_guard") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_DISCREDITING_THE_DESERTERS) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THERAMORE_GUARD, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();

        if (action == GOSSIP_SENDER_INFO)
        {
            player->CLOSE_GOSSIP_MENU();
            player->KilledMonsterCredit(NPC_THERAMORE_GUARD, 0);
            creature->AI()->Talk(SAY_QUEST1);
            creature->CastSpell(creature, SPELL_DOCTORED_LEAFLET, false);
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            CAST_AI(npc_theramore_guard::npc_theramore_guardAI, creature->AI())->YellTimer = 4000;
            CAST_AI(npc_theramore_guard::npc_theramore_guardAI, creature->AI())->bYellTimer = true;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_theramore_guardAI(creature);
    }

    struct npc_theramore_guardAI : public ScriptedAI
    {
        npc_theramore_guardAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 YellTimer;
        uint32 Step;
        bool bYellTimer;

        void Reset() OVERRIDE
        {
            bYellTimer = false;
            Step = 0;
        }

        void UpdateAI(uint32 Diff) OVERRIDE
        {
            if (!me->HasAura(SPELL_PROPAGANDIZED))
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (bYellTimer && YellTimer <= Diff)
            {
                switch (Step)
                {
                    case 0:
                        Talk(SAY_QUEST2);
                        YellTimer = 3000;
                        ++Step;
                        break;
                    case 1:
                        Talk(SAY_QUEST3);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        Step = 0;
                        bYellTimer = false;
                        break;
                }
            }
            else
                YellTimer -= Diff;
        }
    };
};

/*######
## npc_lady_jaina_proudmoore
######*/

enum LadyJaina
{
    QUEST_JAINAS_AUTOGRAPH = 558,
    SPELL_JAINAS_AUTOGRAPH = 23122
};

#define GOSSIP_ITEM_JAINA "I know this is rather silly but i have a young ward who is a bit shy and would like your autograph."

class npc_lady_jaina_proudmoore : public CreatureScript
{
public:
    npc_lady_jaina_proudmoore() : CreatureScript("npc_lady_jaina_proudmoore") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_SENDER_INFO)
        {
            player->SEND_GOSSIP_MENU(7012, creature->GetGUID());
            player->CastSpell(player, SPELL_JAINAS_AUTOGRAPH, false);
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_JAINAS_AUTOGRAPH) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_JAINA, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

/*######
## npc_nat_pagle
######*/

enum NatPagle
{
    QUEST_NATS_MEASURING_TAPE = 8227
};

class npc_nat_pagle : public CreatureScript
{
public:
    npc_nat_pagle() : CreatureScript("npc_nat_pagle") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor() && player->GetQuestRewardStatus(QUEST_NATS_MEASURING_TAPE))
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(7640, creature->GetGUID());
        }
        else
            player->SEND_GOSSIP_MENU(7638, creature->GetGUID());

        return true;
    }

};

/*######
## npc_private_hendel
######*/

enum Hendel
{
    SAY_PROGRESS_1_TER          = 0,
    SAY_PROGRESS_2_HEN          = 1,
    SAY_PROGRESS_3_TER          = 2,
    SAY_PROGRESS_4_TER          = 3,
    EMOTE_SURRENDER             = 4,

    QUEST_MISSING_DIPLO_PT16    = 1324,
    FACTION_HOSTILE             = 168,                      //guessed, may be different

    NPC_SENTRY                  = 5184,                     //helps hendel
    NPC_JAINA                   = 4968,                     //appears once hendel gives up
    NPC_TERVOSH                 = 4967
};

/// @todo develop this further, end event not created
class npc_private_hendel : public CreatureScript
{
public:
    npc_private_hendel() : CreatureScript("npc_private_hendel") { }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, const Quest* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_MISSING_DIPLO_PT16)
            creature->setFaction(FACTION_HOSTILE);

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_private_hendelAI(creature);
    }

    struct npc_private_hendelAI : public ScriptedAI
    {
        npc_private_hendelAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() OVERRIDE
        {
            me->RestoreFaction();
        }

        void AttackedBy(Unit* pAttacker) OVERRIDE
        {
            if (me->GetVictim())
                return;

            if (me->IsFriendlyTo(pAttacker))
                return;

            AttackStart(pAttacker);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &Damage) OVERRIDE
        {
            if (Damage > me->GetHealth() || me->HealthBelowPctDamaged(20, Damage))
            {
                Damage = 0;

                if (Player* player = pDoneBy->GetCharmerOrOwnerPlayerOrPlayerItself())
                    player->GroupEventHappens(QUEST_MISSING_DIPLO_PT16, me);

                Talk(EMOTE_SURRENDER);
                EnterEvadeMode();
            }
        }
    };

};

/*######
## npc_zelfrax
######*/

Position const MovePosition = {-2967.030f, -3872.1799f, 35.620f, 0.0f};

enum Zelfrax
{
    SAY_ZELFRAX1     = 0,
    SAY_ZELFRAX2     = 1
};

class npc_zelfrax : public CreatureScript
{
public:
    npc_zelfrax() : CreatureScript("npc_zelfrax") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_zelfraxAI(creature);
    }

    struct npc_zelfraxAI : public ScriptedAI
    {
        npc_zelfraxAI(Creature* creature) : ScriptedAI(creature)
        {
            MoveToDock();
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (me->Attack(who, true))
            {
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                if (IsCombatMovementAllowed())
                    me->GetMotionMaster()->MoveChase(who);
            }
        }

        void MovementInform(uint32 Type, uint32 /*Id*/) OVERRIDE
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            SetCombatMovement(true);

            if (me->IsInCombat())
                if (Unit* unit = me->GetVictim())
                    me->GetMotionMaster()->MoveChase(unit);
        }

        void MoveToDock()
        {
            SetCombatMovement(false);
            me->GetMotionMaster()->MovePoint(0, MovePosition);
            Talk(SAY_ZELFRAX1);
            Talk(SAY_ZELFRAX2);
        }

        void UpdateAI(uint32 /*Diff*/) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_stinky
######*/

enum Stinky
{
    QUEST_STINKYS_ESCAPE_H                       = 1270,
    QUEST_STINKYS_ESCAPE_A                       = 1222,
    SAY_QUEST_ACCEPTED                           = 0,
    SAY_STAY_1                                   = 1,
    SAY_STAY_2                                   = 2,
    SAY_STAY_3                                   = 3,
    SAY_STAY_4                                   = 4,
    SAY_STAY_5                                   = 5,
    SAY_STAY_6                                   = 6,
    SAY_QUEST_COMPLETE                           = 7,
    SAY_ATTACKED_1                               = 8,
    EMOTE_DISAPPEAR                              = 9
};

class npc_stinky : public CreatureScript
{
public:
   npc_stinky() : CreatureScript("npc_stinky") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_stinkyAI(creature);
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
         if (quest->GetQuestId() == QUEST_STINKYS_ESCAPE_H || quest->GetQuestId() == QUEST_STINKYS_ESCAPE_A)
         {
             if (npc_stinkyAI* pEscortAI = CAST_AI(npc_stinky::npc_stinkyAI, creature->AI()))
             {
                 creature->setFaction(FACTION_ESCORT_N_NEUTRAL_ACTIVE);
                 creature->SetStandState(UNIT_STAND_STATE_STAND);
                 creature->AI()->Talk(SAY_QUEST_ACCEPTED);
                 pEscortAI->Start(false, false, player->GetGUID());
             }
         }
         return true;
    }

    struct npc_stinkyAI : public npc_escortAI
    {
       npc_stinkyAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 7:
                    Talk(SAY_STAY_1, player);
                    break;
                case 11:
                    Talk(SAY_STAY_2, player);
                    break;
                case 25:
                    Talk(SAY_STAY_3, player);
                    break;
                case 26:
                    Talk(SAY_STAY_4, player);
                    break;
                case 27:
                    Talk(SAY_STAY_5, player);
                    break;
                case 28:
                    Talk(SAY_STAY_6, player);
                    me->SetStandState(UNIT_STAND_STATE_KNEEL);
                    break;
                case 29:
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    break;
                case 37:
                    Talk(SAY_QUEST_COMPLETE, player);
                    me->SetSpeed(MOVE_RUN, 1.2f, true);
                    me->SetWalk(false);
                    if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_H))
                        player->GroupEventHappens(QUEST_STINKYS_ESCAPE_H, me);
                    if (player->GetQuestStatus(QUEST_STINKYS_ESCAPE_A))
                        player->GroupEventHappens(QUEST_STINKYS_ESCAPE_A, me);
                    break;
                case 39:
                    Talk(EMOTE_DISAPPEAR);
                    break;
            }
        }

        void EnterCombat(Unit* who) OVERRIDE
        {
            Talk(SAY_ATTACKED_1, who);
        }

        void Reset() OVERRIDE { }

        void JustDied(Unit* /*killer*/) OVERRIDE
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

       void UpdateAI(uint32 uiDiff) OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_ooze_zap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_ooze_zap_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_ooze_zap_channel_end_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
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

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_energize_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
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

    bool OnGossipHello(Player* player, GameObject* go) OVERRIDE
    {
        go->UseDoorOrButton();
        if (Creature* prisoner = go->FindNearestCreature(NPC_THERAMORE_PRISONER, 1.0f))
        {
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
    new npc_risen_husk_spirit();
    new npc_lady_jaina_proudmoore();
    new npc_nat_pagle();
    new npc_private_hendel();
    new npc_zelfrax();
    new npc_stinky();
    new npc_theramore_guard();
    new spell_ooze_zap();
    new spell_ooze_zap_channel_end();
    new spell_energize_aoe();
    new go_blackhoof_cage();
}
