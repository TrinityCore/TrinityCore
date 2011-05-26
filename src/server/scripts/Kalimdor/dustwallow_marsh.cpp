/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
mobs_risen_husk_spirit
npc_deserter_agitator
npc_lady_jaina_proudmoore
npc_nat_pagle
npc_private_hendel
npc_cassa_crimsonwing - handled by npc_taxi
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## mobs_risen_husk_spirit
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
    EVENT_CONSUME_FLESH                 = 0,
    EVENT_INTANGIBLE_PRESENCE           = 1,
};

class mobs_risen_husk_spirit : public CreatureScript
{
    public:
        mobs_risen_husk_spirit() : CreatureScript("mobs_risen_husk_spirit") { }

        struct mobs_risen_husk_spiritAI : public ScriptedAI
        {
            mobs_risen_husk_spiritAI(Creature* creature) : ScriptedAI(creature) { }

            void Reset()
            {
                events.Reset();
                if (me->GetEntry() == NPC_RISEN_HUSK)
                    events.ScheduleEvent(EVENT_CONSUME_FLESH, 5000);
                else if (me->GetEntry() == NPC_RISEN_SPIRIT)
                    events.ScheduleEvent(EVENT_INTANGIBLE_PRESENCE, 5000);
            }

            void JustDied(Unit* killer)
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

            void UpdateAI(uint32 const diff)
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mobs_risen_husk_spiritAI (creature);
        }
};

/*######
## npc_deserter_agitator
######*/

enum eDeserter
{
    QUEST_TRAITORS_AMONG_US                      = 11126,
    NPC_THERAMORE_DESERTER                       = 23602,
};

const Position DeserterDisappearPos = {-3609.03f, -4332.91f, 9.39354f, 3.73862f};

#define GOSSIP_ITEM_DESERTER "Your propaganda wont`t work on me. Spout your treasonous filth elsewhere traitor!"

class npc_deserter_agitator : public CreatureScript
{
public:
    npc_deserter_agitator() : CreatureScript("npc_deserter_agitator") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_TRAITORS_AMONG_US) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_DESERTER, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_SENDER_INFO)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            switch (urand(0, 1))
            {
                case 0:
                    pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    pCreature->setFaction(14);
                    pCreature->AI()->AttackStart(pPlayer);
                    break;
                case 1:
                    pPlayer->KilledMonsterCredit(NPC_THERAMORE_DESERTER, 0);
                    pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    pCreature->SetSpeed(MOVE_RUN, pCreature->GetSpeedRate(MOVE_RUN), true);
                    pCreature->setFaction(35);
                    pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NON_ATTACKABLE);
                    pCreature->SetReactState(REACT_PASSIVE);
                    pCreature->GetMotionMaster()->MovePoint(1, DeserterDisappearPos);
                    break;
            }
        }

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_deserter_agitatorAI(pCreature);
    }

    struct npc_deserter_agitatorAI : public ScriptedAI
    {
        npc_deserter_agitatorAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void Reset()
        {
            me->RestoreFaction();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_AGGRESSIVE);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        void MovementInform(uint32 uiType, uint32 uiId)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (uiId == 1)
                me->DisappearAndDie();
        }
    };
};

/*######
## npc_deserter_agitator
######*/

enum eTheramoreGuard
{
    SAY_QUEST1                                   = -1000641,
    SAY_QUEST2                                   = -1000642,
    SAY_QUEST3                                   = -1000643,
    SAY_QUEST4                                   = -1000644,
    SAY_QUEST5                                   = -1000645,
    SAY_QUEST6                                   = -1000646,
    SAY_QUEST7                                   = -1000647,
    SAY_QUEST8                                   = -1000648,
    SAY_QUEST9                                   = -1000649,

    QUEST_DISCREDITING_THE_DESERTERS             = 11133,

    NPC_THERAMORE_GUARD                          = 4979,

    SPELL_DOCTORED_LEAFLET                       = 42725,
    SPELL_PROPAGANDIZED                          = 42246,
};

#define GOSSIP_ITEM_THERAMORE_GUARD "You look like an intelligent person. Why don't you read one of these leaflets and give it some thought?"

class npc_theramore_guard : public CreatureScript
{
public:
    npc_theramore_guard() : CreatureScript("npc_theramore_guard") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pPlayer->GetQuestStatus(QUEST_DISCREDITING_THE_DESERTERS) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_THERAMORE_GUARD, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();

        if (uiAction == GOSSIP_SENDER_INFO)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->KilledMonsterCredit(NPC_THERAMORE_GUARD, 0);
            DoScriptText(SAY_QUEST1, pCreature);
            pCreature->CastSpell(pCreature, SPELL_DOCTORED_LEAFLET, false);
            pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            CAST_AI(npc_theramore_guard::npc_theramore_guardAI, pCreature->AI())->uiYellTimer = 4000;
            CAST_AI(npc_theramore_guard::npc_theramore_guardAI, pCreature->AI())->bYellTimer = true;
        }

        return true;
    }

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return new npc_theramore_guardAI(pCreature);
    }

    struct npc_theramore_guardAI : public ScriptedAI
    {
        npc_theramore_guardAI(Creature *pCreature) : ScriptedAI(pCreature) { }

        uint32 uiYellTimer;
        uint32 uiStep;
        bool bYellTimer;

        void Reset()
        {
            bYellTimer = false;
            uiStep = 0;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!me->HasAura(SPELL_PROPAGANDIZED))
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            if (bYellTimer && uiYellTimer <= uiDiff)
            {
                switch(uiStep)
                {
                    case 0:
                        DoScriptText(RAND(SAY_QUEST2, SAY_QUEST3, SAY_QUEST4, SAY_QUEST5, SAY_QUEST6), me);
                        uiYellTimer = 3000;
                        ++uiStep;
                        break;
                    case 1:
                        DoScriptText(RAND(SAY_QUEST7, SAY_QUEST8, SAY_QUEST9), me);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_LAUGH);
                        uiStep = 0;
                        bYellTimer = false;
                        break;
                }
            }
            else
                uiYellTimer -= uiDiff;
        }
    };
};

/*######
## npc_lady_jaina_proudmoore
######*/

enum eLadyJaina
{
    QUEST_JAINAS_AUTOGRAPH = 558,
    SPELL_JAINAS_AUTOGRAPH = 23122
};

#define GOSSIP_ITEM_JAINA "I know this is rather silly but i have a young ward who is a bit shy and would like your autograph."

class npc_lady_jaina_proudmoore : public CreatureScript
{
public:
    npc_lady_jaina_proudmoore() : CreatureScript("npc_lady_jaina_proudmoore") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_SENDER_INFO)
        {
            pPlayer->SEND_GOSSIP_MENU(7012, pCreature->GetGUID());
            pPlayer->CastSpell(pPlayer, SPELL_JAINAS_AUTOGRAPH, false);
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(QUEST_JAINAS_AUTOGRAPH) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_JAINA, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

};

/*######
## npc_nat_pagle
######*/

enum eNatPagle
{
    QUEST_NATS_MEASURING_TAPE = 8227
};

class npc_nat_pagle : public CreatureScript
{
public:
    npc_nat_pagle() : CreatureScript("npc_nat_pagle") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            pPlayer->GetSession()->SendListInventory(pCreature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pCreature->isVendor() && pPlayer->GetQuestRewardStatus(QUEST_NATS_MEASURING_TAPE))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            pPlayer->SEND_GOSSIP_MENU(7640, pCreature->GetGUID());
        }
        else
            pPlayer->SEND_GOSSIP_MENU(7638, pCreature->GetGUID());

        return true;
    }

};

/*######
## npc_private_hendel
######*/

enum eHendel
{
    // looks like all this text ids are wrong.
    SAY_PROGRESS_1_TER          = -1000411, // signed for 3568
    SAY_PROGRESS_2_HEN          = -1000412, // signed for 3568
    SAY_PROGRESS_3_TER          = -1000413,
    SAY_PROGRESS_4_TER          = -1000414,
    EMOTE_SURRENDER             = -1000415,

    QUEST_MISSING_DIPLO_PT16    = 1324,
    FACTION_HOSTILE             = 168,                      //guessed, may be different

    NPC_SENTRY                  = 5184,                     //helps hendel
    NPC_JAINA                   = 4968,                     //appears once hendel gives up
    NPC_TERVOSH                 = 4967
};

//TODO: develop this further, end event not created
class npc_private_hendel : public CreatureScript
{
public:
    npc_private_hendel() : CreatureScript("npc_private_hendel") { }

    bool OnQuestAccept(Player* /*pPlayer*/, Creature* pCreature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT16)
            pCreature->setFaction(FACTION_HOSTILE);

        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_private_hendelAI(pCreature);
    }

    struct npc_private_hendelAI : public ScriptedAI
    {
        npc_private_hendelAI(Creature* pCreature) : ScriptedAI(pCreature) { }

        void Reset()
        {
            me->RestoreFaction();
        }

        void AttackedBy(Unit* pAttacker)
        {
            if (me->getVictim())
                return;

            if (me->IsFriendlyTo(pAttacker))
                return;

            AttackStart(pAttacker);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (uiDamage > me->GetHealth() || me->HealthBelowPctDamaged(20, uiDamage))
            {
                uiDamage = 0;

                if (Player* pPlayer = pDoneBy->GetCharmerOrOwnerPlayerOrPlayerItself())
                    pPlayer->GroupEventHappens(QUEST_MISSING_DIPLO_PT16, me);

                DoScriptText(EMOTE_SURRENDER, me);
                EnterEvadeMode();
            }
        }
    };

};

/*######
## npc_zelfrax
######*/

const Position MovePosition = {-2967.030f, -3872.1799f, 35.620f, 0.0f};

enum eZelfrax
{
    SAY_ZELFRAX     = -1000472,
    SAY_ZELFRAX_2   = -1000473
};

class npc_zelfrax : public CreatureScript
{
public:
    npc_zelfrax() : CreatureScript("npc_zelfrax") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_zelfraxAI(pCreature);
    }

    struct npc_zelfraxAI : public ScriptedAI
    {
        npc_zelfraxAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            MoveToDock();
        }

        void AttackStart(Unit* pWho)
        {
            if (!pWho)
                return;

            if (me->Attack(pWho, true))
            {
                me->SetInCombatWith(pWho);
                pWho->SetInCombatWith(me);

                if (IsCombatMovementAllowed())
                    me->GetMotionMaster()->MoveChase(pWho);
            }
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            SetCombatMovement(true);

            if (me->isInCombat())
                if (Unit* pUnit = me->getVictim())
                    me->GetMotionMaster()->MoveChase(pUnit);
        }

        void MoveToDock()
        {
            SetCombatMovement(false);
            me->GetMotionMaster()->MovePoint(0, MovePosition);
            DoScriptText(SAY_ZELFRAX, me);
            DoScriptText(SAY_ZELFRAX_2, me);
        }

        void UpdateAI(uint32 const /*uiDiff*/)
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

enum eStinky
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_stinkyAI(pCreature);
    }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const *quest)
    {
         if (quest->GetQuestId() == QUEST_STINKYS_ESCAPE_H || QUEST_STINKYS_ESCAPE_A)
         {
             if (npc_stinkyAI* pEscortAI = CAST_AI(npc_stinky::npc_stinkyAI, pCreature->AI()))
             {
                 pCreature->setFaction(FACTION_ESCORT_N_NEUTRAL_ACTIVE);
                 pCreature->SetStandState(UNIT_STAND_STATE_STAND);
                 DoScriptText(SAY_QUEST_ACCEPTED, pCreature);
                 pEscortAI->Start(false, false, pPlayer->GetGUID());
             }
         }
         return true;
    }

    struct npc_stinkyAI : public npc_escortAI
    {
       npc_stinkyAI(Creature* pCreature) : npc_escortAI(pCreature) { }

        void WaypointReached(uint32 i)
        {
            Player* pPlayer = GetPlayerForEscort();
            if (!pPlayer)
                return;

            switch (i)
            {
            case 7:
                DoScriptText(SAY_STAY_1, me, pPlayer);
                break;
            case 11:
                DoScriptText(SAY_STAY_2, me, pPlayer);
                break;
            case 25:
                DoScriptText(SAY_STAY_3, me, pPlayer);
                break;
            case 26:
                DoScriptText(SAY_STAY_4, me, pPlayer);
                break;
            case 27:
                DoScriptText(SAY_STAY_5, me, pPlayer);
                break;
            case 28:
                DoScriptText(SAY_STAY_6, me, pPlayer);
                me->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;
            case 29:
                me->SetStandState(UNIT_STAND_STATE_STAND);
                break;
            case 37:
                DoScriptText(SAY_QUEST_COMPLETE, me, pPlayer);
                me->SetSpeed(MOVE_RUN, 1.2f, true);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                if (pPlayer && pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_H))
                    pPlayer->GroupEventHappens(QUEST_STINKYS_ESCAPE_H, me);
                if (pPlayer && pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_A))
                    pPlayer->GroupEventHappens(QUEST_STINKYS_ESCAPE_A, me);
                break;
            case 39:
                DoScriptText(EMOTE_DISAPPEAR, me);
                break;

            }
        }

        void EnterCombat(Unit* pWho)
        {
            DoScriptText(SAY_ATTACKED_1, me, pWho);
        }

        void Reset() {}

        void JustDied(Unit* /*pKiller*/)
        {
            Player* pPlayer = GetPlayerForEscort();
            if (HasEscortState(STATE_ESCORT_ESCORTING) && pPlayer)
            {
                if (pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_H))
                    pPlayer->FailQuest(QUEST_STINKYS_ESCAPE_H);
                if (pPlayer->GetQuestStatus(QUEST_STINKYS_ESCAPE_A))
                    pPlayer->FailQuest(QUEST_STINKYS_ESCAPE_A);
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

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_OOZE_ZAP))
                    return false;
                return true;
            }

            SpellCastResult CheckRequirement()
            {
                if (!GetCaster()->HasAura(SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_1)))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW; // This is actually correct

                if (!GetTargetUnit())
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
                OnEffect += SpellEffectFn(spell_ooze_zap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_OOZE_ZAP_CHANNEL_END))
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
                OnEffect += SpellEffectFn(spell_ooze_zap_channel_end_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
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

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ENERGIZED))
                    return false;
                return true;
            }

            void FilterTargets(std::list<Unit*>& unitList)
            {
                for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end();)
                {
                    if ((*itr)->GetTypeId() == TYPEID_PLAYER && (*itr)->ToPlayer()->GetQuestStatus(SpellMgr::CalculateSpellEffectAmount(GetSpellInfo(), EFFECT_1)) == QUEST_STATUS_INCOMPLETE)
                        ++itr;
                    else
                        unitList.erase(itr++);
                }
                unitList.push_back(GetCaster());
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_energize_aoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENTRY_SRC);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_energize_aoe_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_AREA_ENTRY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_energize_aoe_SpellScript();
        }
};

void AddSC_dustwallow_marsh()
{
    new mobs_risen_husk_spirit();
    new npc_lady_jaina_proudmoore();
    new npc_nat_pagle();
    new npc_private_hendel();
    new npc_zelfrax();
    new npc_stinky();
    new npc_theramore_guard();
    new npc_deserter_agitator();
    new spell_ooze_zap();
    new spell_ooze_zap_channel_end();
    new spell_energize_aoe();
}
