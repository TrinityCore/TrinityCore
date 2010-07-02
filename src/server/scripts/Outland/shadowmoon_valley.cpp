/* Copyright (C) 2006 - 2010 Trinity <http://www.trinitycore.org/>
 * Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Shadowmoon_Valley
SD%Complete: 100
SDComment: Quest support: 10519, 10583, 10601, 10814, 10804, 10854, 10458, 10481, 10480, 11082, 10781, 10451. Vendor Drake Dealer Hurlunk.
SDCategory: Shadowmoon Valley
EndScriptData */

/* ContentData
mob_mature_netherwing_drake
mob_enslaved_netherwing_drake
npc_drake_dealer_hurlunk
npcs_flanis_swiftwing_and_kagrosh
npc_murkblood_overseer
npc_neltharaku
npc_karynaku
npc_oronok_tornheart
npc_overlord_morghor
npc_earthmender_wilda
mob_torloth_the_magnificent
mob_illidari_spawn
npc_lord_illidan_stormrage
go_crystal_prison
npc_enraged_spirit
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*#####
# mob_mature_netherwing_drake
#####*/

enum eMatureNetherwing
{
    SAY_JUST_EATEN              = -1000222,

    SPELL_PLACE_CARCASS         = 38439,
    SPELL_JUST_EATEN            = 38502,
    SPELL_NETHER_BREATH         = 38467,
    POINT_ID                    = 1,

    GO_CARCASS                  = 185155,

    QUEST_KINDNESS              = 10804,
    NPC_EVENT_PINGER            = 22131
};

struct mob_mature_netherwing_drakeAI : public ScriptedAI
{
    mob_mature_netherwing_drakeAI(Creature* c) : ScriptedAI(c) { }

    uint64 uiPlayerGUID;

    bool bCanEat;
    bool bIsEating;

    uint32 EatTimer;
    uint32 CastTimer;

    void Reset()
    {
        uiPlayerGUID = 0;

        bCanEat = false;
        bIsEating = false;

        EatTimer = 5000;
        CastTimer = 5000;
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell)
    {
        if (bCanEat || bIsEating)
            return;

        if (pCaster->GetTypeId() == TYPEID_PLAYER && pSpell->Id == SPELL_PLACE_CARCASS && !me->HasAura(SPELL_JUST_EATEN))
        {
            uiPlayerGUID = pCaster->GetGUID();
            bCanEat = true;
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_ID)
        {
            bIsEating = true;
            EatTimer = 7000;
            me->HandleEmoteCommand(EMOTE_ONESHOT_ATTACKUNARMED);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (bCanEat || bIsEating)
        {
            if (EatTimer <= diff)
            {
                if (bCanEat && !bIsEating)
                {
                    if (Unit* pUnit = Unit::GetUnit(*me, uiPlayerGUID))
                    {
                        if (GameObject* pGo = pUnit->FindNearestGameObject(GO_CARCASS, 10))
                        {
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == WAYPOINT_MOTION_TYPE)
                                me->GetMotionMaster()->MovementExpired();

                            me->GetMotionMaster()->MoveIdle();
                            me->StopMoving();

                            me->GetMotionMaster()->MovePoint(POINT_ID, pGo->GetPositionX(), pGo->GetPositionY(), pGo->GetPositionZ());
                        }
                    }
                    bCanEat = false;
                }
                else if (bIsEating)
                {
                    DoCast(me, SPELL_JUST_EATEN);
                    DoScriptText(SAY_JUST_EATEN, me);

                    if (Player* pPlr = Unit::GetPlayer(uiPlayerGUID))
                    {
                        pPlr->KilledMonsterCredit(NPC_EVENT_PINGER, me->GetGUID());

                        if (GameObject* pGo = pPlr->FindNearestGameObject(GO_CARCASS, 10))
                            pGo->Delete();
                    }

                    Reset();
                    me->GetMotionMaster()->Clear();
                }
            }
            else
                EatTimer -= diff;

        return;
        }

        if (!UpdateVictim())
            return;

        if (CastTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_NETHER_BREATH);
            CastTimer = 5000;
        } else CastTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_mature_netherwing_drake(Creature* pCreature)
{
    return new mob_mature_netherwing_drakeAI(pCreature);
}

/*###
# mob_enslaved_netherwing_drake
####*/

#define FACTION_DEFAULT     62
#define FACTION_FRIENDLY    1840                            // Not sure if this is correct, it was taken off of Mordenai.

#define SPELL_HIT_FORCE_OF_NELTHARAKU   38762
#define SPELL_FORCE_OF_NELTHARAKU       38775

#define CREATURE_DRAGONMAW_SUBJUGATOR   21718
#define CREATURE_ESCAPE_DUMMY           22317

struct mob_enslaved_netherwing_drakeAI : public ScriptedAI
{
    mob_enslaved_netherwing_drakeAI(Creature* c) : ScriptedAI(c)
    {
        PlayerGUID = 0;
        Tapped = false;
        Reset();
    }

    uint64 PlayerGUID;
    uint32 FlyTimer;
    bool Tapped;

    void Reset()
    {
        if (!Tapped)
            me->setFaction(FACTION_DEFAULT);

        FlyTimer = 10000;
        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        me->SetVisibility(VISIBILITY_ON);
    }

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if (!caster)
            return;

        if (caster->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_HIT_FORCE_OF_NELTHARAKU && !Tapped)
        {
            Tapped = true;
            PlayerGUID = caster->GetGUID();

            me->setFaction(FACTION_FRIENDLY);
            DoCast(caster, SPELL_FORCE_OF_NELTHARAKU, true);

            Unit* Dragonmaw = me->FindNearestCreature(CREATURE_DRAGONMAW_SUBJUGATOR, 50);

            if (Dragonmaw)
            {
                me->AddThreat(Dragonmaw, 100000.0f);
                AttackStart(Dragonmaw);
            }

            HostileReference* ref = me->getThreatManager().getOnlineContainer().getReferenceByTarget(caster);
            if (ref)
                ref->removeReference();
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 1)
        {
            if (PlayerGUID)
            {
                Unit* plr = Unit::GetUnit((*me), PlayerGUID);
                if (plr)
                    DoCast(plr, SPELL_FORCE_OF_NELTHARAKU, true);

                PlayerGUID = 0;
            }
            me->SetVisibility(VISIBILITY_OFF);
            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            me->RemoveCorpse();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
        {
            if (Tapped)
                if (FlyTimer <= diff)
            {
                Tapped = false;
                if (PlayerGUID)
                {
                    Player* plr = Unit::GetPlayer(PlayerGUID);
                    if (plr && plr->GetQuestStatus(10854) == QUEST_STATUS_INCOMPLETE)
                    {
                        DoCast(plr, SPELL_FORCE_OF_NELTHARAKU, true);
                        /*
                        float x,y,z;
                        me->GetPosition(x,y,z);

                        float dx,dy,dz;
                        me->GetRandomPoint(x, y, z, 20, dx, dy, dz);
                        dz += 20; // so it's in the air, not ground*/

                        Position pos;
                        if (Unit* EscapeDummy = me->FindNearestCreature(CREATURE_ESCAPE_DUMMY, 30))
                            EscapeDummy->GetPosition(&pos);
                        else
                        {
                            me->GetRandomNearPosition(pos, 20);
                            pos.m_positionZ += 25;
                        }

                        me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->GetMotionMaster()->MovePoint(1, pos);
                    }
                }
            } else FlyTimer -= diff;
            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_enslaved_netherwing_drake(Creature* pCreature)
{
    return new mob_enslaved_netherwing_drakeAI(pCreature);
}

/*#####
# mob_dragonmaw_peon
#####*/

struct mob_dragonmaw_peonAI : public ScriptedAI
{
    mob_dragonmaw_peonAI(Creature* c) : ScriptedAI(c) {}

    uint64 PlayerGUID;
    bool Tapped;
    uint32 PoisonTimer;

    void Reset()
    {
        PlayerGUID = 0;
        Tapped = false;
        PoisonTimer = 0;
    }

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if (!caster)
            return;

        if (caster->GetTypeId() == TYPEID_PLAYER && spell->Id == 40468 && !Tapped)
        {
            PlayerGUID = caster->GetGUID();

            Tapped = true;
            float x, y, z;
            caster->GetClosePoint(x, y, z, me->GetObjectSize());

            me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            me->GetMotionMaster()->MovePoint(1, x, y, z);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id)
        {
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_EAT);
            PoisonTimer = 15000;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (PoisonTimer)
            if (PoisonTimer <= diff)
        {
            if (PlayerGUID)
            {
                Player* plr = Unit::GetPlayer(PlayerGUID);
                if (plr && plr->GetQuestStatus(11020) == QUEST_STATUS_INCOMPLETE)
                    plr->KilledMonsterCredit(23209, me->GetGUID());
            }
            PoisonTimer = 0;
            me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        } else PoisonTimer -= diff;
    }
};

CreatureAI* GetAI_mob_dragonmaw_peon(Creature* pCreature)
{
    return new mob_dragonmaw_peonAI(pCreature);
}

/*######
## npc_drake_dealer_hurlunk
######*/

bool GossipHello_npc_drake_dealer_hurlunk(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isVendor() && pPlayer->GetReputationRank(1015) == REP_EXALTED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_drake_dealer_hurlunk(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

    return true;
}

/*######
## npc_flanis_swiftwing_and_kagrosh
######*/

#define GOSSIP_HSK1 "Take Flanis's Pack"
#define GOSSIP_HSK2 "Take Kagrosh's Pack"

bool GossipHello_npcs_flanis_swiftwing_and_kagrosh(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(10583) == QUEST_STATUS_INCOMPLETE && !pPlayer->HasItemCount(30658,1,true))
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_HSK1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    if (pPlayer->GetQuestStatus(10601) == QUEST_STATUS_INCOMPLETE && !pPlayer->HasItemCount(30659,1,true))
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_HSK2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npcs_flanis_swiftwing_and_kagrosh(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        ItemPosCountVec dest;
        uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 30658, 1, false);
        if (msg == EQUIP_ERR_OK)
        {
            pPlayer->StoreNewItem(dest, 30658, 1, true);
            pPlayer->PlayerTalkClass->ClearMenus();
        }
    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        ItemPosCountVec dest;
        uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 30659, 1, false);
        if (msg == EQUIP_ERR_OK)
        {
            pPlayer->StoreNewItem(dest, 30659, 1, true);
            pPlayer->PlayerTalkClass->ClearMenus();
        }
    }
    return true;
}

/*######
## npc_murkblood_overseer
######*/

#define QUEST_11082     11082

#define GOSSIP_HMO "I am here for you, overseer."
#define GOSSIP_SMO1 "How dare you question an overseer of the Dragonmaw!"
#define GOSSIP_SMO2 "Who speaks of me? What are you talking about, broken?"
#define GOSSIP_SMO3 "Continue please."
#define GOSSIP_SMO4 "Who are these bidders?"
#define GOSSIP_SMO5 "Well... yes."

bool GossipHello_npc_murkblood_overseer(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_11082) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_HMO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_murkblood_overseer(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SMO1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SMO2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SMO3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SMO4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SMO5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
                                                            //correct id not known
            pPlayer->SEND_GOSSIP_MENU(10940, pCreature->GetGUID());
            pCreature->CastSpell(pPlayer,41121,false);
            pPlayer->AreaExploredOrEventHappens(QUEST_11082);
            break;
    }
    return true;
}

/*######
## npc_neltharaku
######*/

#define GOSSIP_HN "I am listening, dragon"
#define GOSSIP_SN1 "But you are dragons! How could orcs do this to you?"
#define GOSSIP_SN2 "Your mate?"
#define GOSSIP_SN3 "I have battled many beasts, dragon. I will help you."

bool GossipHello_npc_neltharaku(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(10814) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_HN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(10613, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_neltharaku(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(10614, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->SEND_GOSSIP_MENU(10615, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_SN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->SEND_GOSSIP_MENU(10616, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(10814);
            break;
    }
    return true;
}

/*######
## npc_oronok
######*/

#define GOSSIP_ORONOK1 "I am ready to hear your story, Oronok."
#define GOSSIP_ORONOK2 "How do I find the cipher?"
#define GOSSIP_ORONOK3 "How do you know all of this?"
#define GOSSIP_ORONOK4 "Yet what? What is it, Oronok?"
#define GOSSIP_ORONOK5 "Continue, please."
#define GOSSIP_ORONOK6 "So what of the cipher now? And your boys?"
#define GOSSIP_ORONOK7 "I will find your boys and the cipher, Oronok."

bool GossipHello_npc_oronok_tornheart(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());
    if (pCreature->isVendor())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    if (pPlayer->GetQuestStatus(10519) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        pPlayer->SEND_GOSSIP_MENU(10312, pCreature->GetGUID());
    }else
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_oronok_tornheart(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_TRADE:
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(10313, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(10314, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            pPlayer->SEND_GOSSIP_MENU(10315, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            pPlayer->SEND_GOSSIP_MENU(10316, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            pPlayer->SEND_GOSSIP_MENU(10317, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ORONOK7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            pPlayer->SEND_GOSSIP_MENU(10318, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(10519);
            break;
    }
    return true;
}

/*####
# npc_karynaku
####*/

enum eKarynaku
{
    QUEST_ALLY_OF_NETHER    = 10870,

    TAXI_PATH_ID            = 649
};

bool QuestAccept_npc_karynaku(Player* pPlayer, Creature* /*pCreature*/, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_ALLY_OF_NETHER)
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID);        //pPlayer->ActivateTaxiPathTo(649);

    return true;
}

/*####
# npc_overlord_morghor
####*/

#define QUEST_LORD_ILLIDAN_STORMRAGE 11108

#define C_ILLIDAN 22083
#define C_YARZILL 23141

#define SPELL_ONE 39990 // Red Lightning Bolt
#define SPELL_TWO 41528 // Mark of Stormrage
#define SPELL_THREE 40216 // Dragonaw Faction
#define SPELL_FOUR 42016 // Dragonaw Trasform

#define OVERLORD_SAY_1 -1100206
#define OVERLORD_SAY_2 -1100207
#define OVERLORD_SAY_3 -1100208 //signed for 28315
#define OVERLORD_SAY_4 -1100209
#define OVERLORD_SAY_5 -1100210
#define OVERLORD_SAY_6 -1100211

#define OVERLORD_YELL_1 -1000212
#define OVERLORD_YELL_2 -1000213

#define LORD_ILLIDAN_SAY_1 -1100214
#define LORD_ILLIDAN_SAY_2 -1100215
#define LORD_ILLIDAN_SAY_3 -1100216
#define LORD_ILLIDAN_SAY_4 -1100217
#define LORD_ILLIDAN_SAY_5 -1100218
#define LORD_ILLIDAN_SAY_6 -1100219
#define LORD_ILLIDAN_SAY_7 -1100220

#define YARZILL_THE_MERC_SAY -1100221

struct npc_overlord_morghorAI : public ScriptedAI
{
    npc_overlord_morghorAI(Creature *c) : ScriptedAI(c) {}

    uint64 PlayerGUID;
    uint64 IllidanGUID;

    uint32 ConversationTimer;
    uint32 Step;

    bool Event;

    void Reset()
    {
        PlayerGUID = 0;
        IllidanGUID = 0;

        ConversationTimer = 0;
        Step = 0;

        Event = false;
        me->SetUInt32Value(UNIT_NPC_FLAGS, 2);
    }

    void StartEvent()
    {
        me->SetUInt32Value(UNIT_NPC_FLAGS, 0);
        me->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
        Unit* Illidan = me->SummonCreature(C_ILLIDAN, -5107.83, 602.584, 85.2393, 4.92598, TEMPSUMMON_CORPSE_DESPAWN, 0);
        if (Illidan)
        {
            IllidanGUID = Illidan->GetGUID();
            Illidan->SetVisibility(VISIBILITY_OFF);
        }
        if (PlayerGUID)
        {
            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            if (pPlayer)
                DoScriptText(OVERLORD_SAY_1, me, pPlayer);
        }
        ConversationTimer = 4200;
        Step = 0;
        Event = true;
    }

    uint32 NextStep(uint32 Step)
    {
        Unit* plr = Unit::GetUnit((*me), PlayerGUID);

        Unit* Illi = Unit::GetUnit((*me), IllidanGUID);

        if (!plr || !Illi)
        {
            EnterEvadeMode();
            return 0;
        }

        switch(Step)
        {
        case 0: return 0; break;
        case 1: me->GetMotionMaster()->MovePoint(0, -5104.41, 595.297, 85.6838); return 9000; break;
        case 2: DoScriptText(OVERLORD_YELL_1, me, plr); return 4500; break;
        case 3: me->SetInFront(plr); return 3200;  break;
        case 4: DoScriptText(OVERLORD_SAY_2, me, plr); return 2000; break;
        case 5: Illi->SetVisibility(VISIBILITY_ON);
             Illi->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE); return 350; break;
        case 6:
            Illi->CastSpell(Illi, SPELL_ONE, true);
            Illi->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
            me->SetUInt64Value(UNIT_FIELD_TARGET, IllidanGUID);
            return 2000; break;
        case 7: DoScriptText(OVERLORD_YELL_2, me); return 4500; break;
        case 8: me->SetUInt32Value(UNIT_FIELD_BYTES_1, 8); return 2500; break;
        case 9: DoScriptText(OVERLORD_SAY_3, me); return 6500; break;
        case 10: DoScriptText(LORD_ILLIDAN_SAY_1, Illi); return 5000;  break;
        case 11: DoScriptText(OVERLORD_SAY_4, me, plr); return 6000; break;
        case 12: DoScriptText(LORD_ILLIDAN_SAY_2, Illi); return 5500; break;
        case 13: DoScriptText(LORD_ILLIDAN_SAY_3, Illi); return 4000; break;
        case 14: Illi->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID); return 1500; break;
        case 15: DoScriptText(LORD_ILLIDAN_SAY_4, Illi); return 1500; break;
        case 16:
            if (plr)
            {
                Illi->CastSpell(plr, SPELL_TWO, true);
                plr->RemoveAurasDueToSpell(SPELL_THREE);
                plr->RemoveAurasDueToSpell(SPELL_FOUR);
                return 5000;
            }else{
                CAST_PLR(plr)->FailQuest(QUEST_LORD_ILLIDAN_STORMRAGE); Step = 30; return 100;
            }
            break;
        case 17: DoScriptText(LORD_ILLIDAN_SAY_5, Illi); return 5000; break;
        case 18: DoScriptText(LORD_ILLIDAN_SAY_6, Illi); return 5000; break;
        case 19: DoScriptText(LORD_ILLIDAN_SAY_7, Illi); return 5000; break;
        case 20:
            Illi->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            Illi->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            return 500; break;
        case 21: DoScriptText(OVERLORD_SAY_5, me); return 500; break;
        case 22:
            Illi->SetVisibility(VISIBILITY_OFF);
            Illi->setDeathState(JUST_DIED);
            return 1000; break;
        case 23: me->SetUInt32Value(UNIT_FIELD_BYTES_1,0); return 2000; break;
        case 24: me->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID); return 5000; break;
        case 25: DoScriptText(OVERLORD_SAY_6, me); return 2000; break;
        case 26:
            if (plr)
                CAST_PLR(plr)->GroupEventHappens(QUEST_LORD_ILLIDAN_STORMRAGE, me);
            return 6000; break;
        case 27:
            {
            Unit* Yarzill = me->FindNearestCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
            return 500; }
 break;
        case 28:
            plr->RemoveAurasDueToSpell(SPELL_TWO);
            plr->RemoveAurasDueToSpell(41519);
            plr->CastSpell(plr, SPELL_THREE, true);
            plr->CastSpell(plr, SPELL_FOUR, true);
            return 1000; break;
        case 29:
            {
            Unit* Yarzill = me->FindNearestCreature(C_YARZILL, 50);
            if (Yarzill)
                DoScriptText(YARZILL_THE_MERC_SAY, Yarzill, plr);
            return 5000; }
 break;
        case 30:
            {
            Unit* Yarzill = me->FindNearestCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, 0);
            return 5000; }
 break;
        case 31:
            {
            Unit* Yarzill = me->FindNearestCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->CastSpell(plr, 41540, true);
            return 1000;}
break;
        case 32: me->GetMotionMaster()->MovePoint(0, -5085.77, 577.231, 86.6719); return 5000; break;
        case 33: Reset(); return 100; break;

        default : return 0;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!ConversationTimer)
            return;

        if (ConversationTimer <= diff)
        {
            if (Event && IllidanGUID && PlayerGUID)
            {
                ConversationTimer = NextStep(++Step);
            }
        } else ConversationTimer -= diff;
    }
};

CreatureAI* GetAI_npc_overlord_morghor(Creature* pCreature)
{
return new npc_overlord_morghorAI(pCreature);
}

bool QuestAccept_npc_overlord_morghor(Player* pPlayer, Creature* pCreature, const Quest *_Quest)
{
    if (_Quest->GetQuestId() == QUEST_LORD_ILLIDAN_STORMRAGE)
    {
        CAST_AI(npc_overlord_morghorAI, pCreature->AI())->PlayerGUID = pPlayer->GetGUID();
        CAST_AI(npc_overlord_morghorAI, pCreature->AI())->StartEvent();
        return true;
    }
    return false;
}

/*####
# npc_earthmender_wilda
####*/

enum eEarthmender
{
    SAY_WIL_START               = -1000381,
    SAY_WIL_AGGRO1              = -1000382,
    SAY_WIL_AGGRO2              = -1000383,
    SAY_WIL_PROGRESS1           = -1000384,
    SAY_WIL_PROGRESS2           = -1000385,
    SAY_WIL_FIND_EXIT           = -1000386,
    SAY_WIL_PROGRESS4           = -1000387,
    SAY_WIL_PROGRESS5           = -1000388,
    SAY_WIL_JUST_AHEAD          = -1000389,
    SAY_WIL_END                 = -1000390,

    SPELL_CHAIN_LIGHTNING       = 16006,
    SPELL_EARTHBING_TOTEM       = 15786,
    SPELL_FROST_SHOCK           = 12548,
    SPELL_HEALING_WAVE          = 12491,

    QUEST_ESCAPE_COILSCAR       = 10451,
    NPC_COILSKAR_ASSASSIN       = 21044,
    FACTION_EARTHEN             = 1726                      //guessed
};

struct npc_earthmender_wildaAI : public npc_escortAI
{
    npc_earthmender_wildaAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    uint32 m_uiHealingTimer;

    void Reset()
    {
        m_uiHealingTimer = 0;
    }

    void WaypointReached(uint32 uiPointId)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(uiPointId)
        {
            case 13:
                DoScriptText(SAY_WIL_PROGRESS1, me, pPlayer);
                DoSpawnAssassin();
                break;
            case 14:
                DoSpawnAssassin();
                break;
            case 15:
                DoScriptText(SAY_WIL_FIND_EXIT, me, pPlayer);
                break;
            case 19:
                DoRandomSay();
                break;
            case 20:
                DoSpawnAssassin();
                break;
            case 26:
                DoRandomSay();
                break;
            case 27:
                DoSpawnAssassin();
                break;
            case 33:
                DoRandomSay();
                break;
            case 34:
                DoSpawnAssassin();
                break;
            case 37:
                DoRandomSay();
                break;
            case 38:
                DoSpawnAssassin();
                break;
            case 39:
                DoScriptText(SAY_WIL_JUST_AHEAD, me, pPlayer);
                break;
            case 43:
                DoRandomSay();
                break;
            case 44:
                DoSpawnAssassin();
                break;
            case 50:
                DoScriptText(SAY_WIL_END, me, pPlayer);

                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_ESCAPE_COILSCAR, me);
                break;
        }
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == NPC_COILSKAR_ASSASSIN)
            pSummoned->AI()->AttackStart(me);
    }

    //this is very unclear, random say without no real relevance to script/event
    void DoRandomSay()
    {
        DoScriptText(RAND(SAY_WIL_PROGRESS2,SAY_WIL_PROGRESS4,SAY_WIL_PROGRESS5), me);
    }

    void DoSpawnAssassin()
    {
        //unknown where they actually appear
        DoSummon(NPC_COILSKAR_ASSASSIN, me, 15.0f, 5000, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
    }

    void Aggro(Unit* pWho)
    {
        //don't always use
        if (rand()%5)
            return;

        //only aggro text if not player
        if (pWho->GetTypeId() != TYPEID_PLAYER)
        {
            //appears to be random
            if (urand(0,1))
                DoScriptText(RAND(SAY_WIL_AGGRO1, SAY_WIL_AGGRO2), pWho);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;

        //TODO: add more abilities
        if (me->GetHealth()*100 / me->GetMaxHealth() <= 30)
        {
            if (m_uiHealingTimer <= uiDiff)
            {
                DoCast(me, SPELL_HEALING_WAVE);
                m_uiHealingTimer = 15000;
            }
            else
                m_uiHealingTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_earthmender_wilda(Creature* pCreature)
{
    return new npc_earthmender_wildaAI(pCreature);
}

bool QuestAccept_npc_earthmender_wilda(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ESCAPE_COILSCAR)
    {
        DoScriptText(SAY_WIL_START, pCreature, pPlayer);
        pCreature->setFaction(FACTION_EARTHEN);

        if (npc_earthmender_wildaAI* pEscortAI = CAST_AI(npc_earthmender_wildaAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

/*#####
# Quest: Battle of the crimson watch
#####*/

/* ContentData
Battle of the crimson watch - creatures, gameobjects and defines
mob_illidari_spawn : Adds that are summoned in the Crimson Watch battle.
mob_torloth_the_magnificent : Final Creature that players have to face before quest is completed
npc_lord_illidan_stormrage : Creature that controls the event.
go_crystal_prison : GameObject that begins the event and hands out quest
EndContentData */

#define END_TEXT -1000366 //signed for 10646

#define QUEST_BATTLE_OF_THE_CRIMSON_WATCH 10781
#define EVENT_AREA_RADIUS 65 //65yds
#define EVENT_COOLDOWN 30000 //in ms. appear after event completed or failed (should be = Adds despawn time)

struct TorlothCinematic
{
    int32 TextId;
    uint32 pCreature, Timer;
};

// Creature 0 - Torloth, 1 - Illidan
static TorlothCinematic TorlothAnim[]=
{
    {-1000367, 0, 2000},
    {-1000368, 1, 7000},
    {-1000369, 0, 3000},
    {NULL, 0, 2000}, // Torloth stand
    {-1000370, 0, 1000},
    {NULL, 0, 3000},
    {NULL, 0, NULL}
};

struct Location
{
    float x, y, z, o;
};

//Cordinates for Spawns
static Location SpawnLocation[]=
{
    //Cords used for:
    {-4615.8556, 1342.2532, 139.9, 1.612},//Illidari Soldier
    {-4598.9365, 1377.3182, 139.9, 3.917},//Illidari Soldier
    {-4598.4697, 1360.8999, 139.9, 2.427},//Illidari Soldier
    {-4589.3599, 1369.1061, 139.9, 3.165},//Illidari Soldier
    {-4608.3477, 1386.0076, 139.9, 4.108},//Illidari Soldier
    {-4633.1889, 1359.8033, 139.9, 0.949},//Illidari Soldier
    {-4623.5791, 1351.4574, 139.9, 0.971},//Illidari Soldier
    {-4607.2988, 1351.6099, 139.9, 2.416},//Illidari Soldier
    {-4633.7764, 1376.0417, 139.9, 5.608},//Illidari Soldier
    {-4600.2461, 1369.1240, 139.9, 3.056},//Illidari Mind Breaker
    {-4631.7808, 1367.9459, 139.9, 0.020},//Illidari Mind Breaker
    {-4600.2461, 1369.1240, 139.9, 3.056},//Illidari Highlord
    {-4631.7808, 1367.9459, 139.9, 0.020},//Illidari Highlord
    {-4615.5586, 1353.0031, 139.9, 1.540},//Illidari Highlord
    {-4616.4736, 1384.2170, 139.9, 4.971},//Illidari Highlord
    {-4627.1240, 1378.8752, 139.9, 2.544} //Torloth The Magnificent
};

struct WaveData
{
    uint8 SpawnCount, UsedSpawnPoint;
    uint32 CreatureId, SpawnTimer,YellTimer;
    int32 WaveTextId;
};

static WaveData WavesInfo[]=
{
    {9, 0, 22075, 10000, 7000, -1000371},   //Illidari Soldier
    {2, 9, 22074, 10000, 7000, -1000372},   //Illidari Mind Breaker
    {4, 11, 19797, 10000, 7000, -1000373},  //Illidari Highlord
    {1, 15, 22076, 10000, 7000, -1000374}   //Torloth The Magnificent
};

struct SpawnSpells
{
 uint32 Timer1, Timer2, SpellId;
};

static SpawnSpells SpawnCast[]=
{
    {10000, 15000, 35871},  // Illidari Soldier Cast - Spellbreaker
    {10000, 10000, 38985},  // Illidari Mind Breake Cast - Focused Bursts
    {35000, 35000, 22884},  // Illidari Mind Breake Cast - Psychic Scream
    {20000, 20000, 17194},  // Illidari Mind Breake Cast - Mind Blast
    {8000, 15000, 38010},   // Illidari Highlord Cast - Curse of Flames
    {12000, 20000, 16102},  // Illidari Highlord Cast - Flamestrike
    {10000, 15000, 15284},  // Torloth the Magnificent Cast - Cleave
    {18000, 20000, 39082},  // Torloth the Magnificent Cast - Shadowfury
    {25000, 28000, 33961}   // Torloth the Magnificent Cast - Spell Reflection
};

/*######
# mob_illidari_spawn
######*/

struct mob_illidari_spawnAI : public ScriptedAI
{
    mob_illidari_spawnAI(Creature* c) : ScriptedAI(c) {}

    uint64 LordIllidanGUID;
    uint32 SpellTimer1, SpellTimer2, SpellTimer3;
    bool Timers;

    void Reset()
    {
        LordIllidanGUID = 0;
        Timers = false;
    }

    void EnterCombat(Unit* /*who*/) {}
    void JustDied(Unit* slayer);

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (!Timers)
        {
            if (me->GetEntry() == 22075)//Illidari Soldier
            {
                SpellTimer1 = SpawnCast[0].Timer1 + (rand()%4 * 1000);
            }
            if (me->GetEntry() == 22074)//Illidari Mind Breaker
            {
                SpellTimer1 = SpawnCast[1].Timer1 + (rand()%10 * 1000);
                SpellTimer2 = SpawnCast[2].Timer1 + (rand()%4 * 1000);
                SpellTimer3 = SpawnCast[3].Timer1 + (rand()%4 * 1000);
            }
            if (me->GetEntry() == 19797)// Illidari Highlord
            {
                SpellTimer1 = SpawnCast[4].Timer1 + (rand()%4 * 1000);
                SpellTimer2 = SpawnCast[5].Timer1 + (rand()%4 * 1000);
            }
            Timers = true;
        }
        //Illidari Soldier
        if (me->GetEntry() == 22075)
        {
            if (SpellTimer1 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[0].SpellId);//Spellbreaker
                SpellTimer1 = SpawnCast[0].Timer2 + (rand()%5 * 1000);
            } else SpellTimer1 -= diff;
        }
        //Illidari Mind Breaker
        if (me->GetEntry() == 22074)
        {
            if (SpellTimer1 <= diff)
            {
                if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                {
                    if (pTarget->GetTypeId() == TYPEID_PLAYER)
                    {
                        DoCast(pTarget, SpawnCast[1].SpellId); //Focused Bursts
                        SpellTimer1 = SpawnCast[1].Timer2 + (rand()%5 * 1000);
                    } else SpellTimer1 = 2000;
                }
            } else SpellTimer1 -= diff;

            if (SpellTimer2 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[2].SpellId);//Psychic Scream
                SpellTimer2 = SpawnCast[2].Timer2 + (rand()%13 * 1000);
            } else SpellTimer2 -= diff;

            if (SpellTimer3 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[3].SpellId);//Mind Blast
                SpellTimer3 = SpawnCast[3].Timer2 + (rand()%8 * 1000);
            } else SpellTimer3 -= diff;
        }
        //Illidari Highlord
        if (me->GetEntry() == 19797)
        {
            if (SpellTimer1 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[4].SpellId);//Curse Of Flames
                SpellTimer1 = SpawnCast[4].Timer2 + (rand()%10 * 1000);
            } else SpellTimer1 -= diff;

            if (SpellTimer2 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[5].SpellId);//Flamestrike
                SpellTimer2 = SpawnCast[5].Timer2 + (rand()%7 * 13000);
            } else SpellTimer2 -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

/*######
# mob_torloth_the_magnificent
#####*/

struct mob_torloth_the_magnificentAI : public ScriptedAI
{
    mob_torloth_the_magnificentAI(Creature* c) : ScriptedAI(c) {}

    uint32 AnimationTimer, SpellTimer1, SpellTimer2, SpellTimer3;

    uint8 AnimationCount;

    uint64 LordIllidanGUID;
    uint64 AggroTargetGUID;

    bool Timers;

    void Reset()
    {
        AnimationTimer = 4000;
        AnimationCount = 0;
        LordIllidanGUID = 0;
        AggroTargetGUID = 0;
        Timers = false;

        me->addUnitState(UNIT_STAT_ROOT);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetUInt64Value(UNIT_FIELD_TARGET, 0);
    }

    void EnterCombat(Unit* /*who*/){}

    void HandleAnimation()
    {
        Creature* pCreature = me;

        if (TorlothAnim[AnimationCount].pCreature == 1)
        {
            pCreature = (Unit::GetCreature(*me, LordIllidanGUID));

            if (!pCreature)
                return;
        }

        if (TorlothAnim[AnimationCount].TextId)
            DoScriptText(TorlothAnim[AnimationCount].TextId, pCreature);

        AnimationTimer = TorlothAnim[AnimationCount].Timer;

        switch(AnimationCount)
        {
        case 0:
            me->SetUInt32Value(UNIT_FIELD_BYTES_1,8);
            break;
        case 3:
            me->RemoveFlag(UNIT_FIELD_BYTES_1,8);
            break;
        case 5:
            if (Player* AggroTarget = (Unit::GetPlayer(AggroTargetGUID)))
            {
                me->SetUInt64Value(UNIT_FIELD_TARGET, AggroTarget->GetGUID());
                me->AddThreat(AggroTarget, 1);
                me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
            }
            break;
        case 6:
            if (Player* AggroTarget = (Unit::GetPlayer(AggroTargetGUID)))
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->clearUnitState(UNIT_STAT_ROOT);

                float x, y, z;
                AggroTarget->GetPosition(x,y,z);
                me->GetMotionMaster()->MovePoint(0,x,y,z);
            }
            break;
        }
        ++AnimationCount;
    }

    void UpdateAI(const uint32 diff)
    {
        if (AnimationTimer)
        {
            if (AnimationTimer <= diff)
            {
                HandleAnimation();
            } else AnimationTimer -= diff;
        }

        if (AnimationCount < 6)
        {
            me->CombatStop();
        } else if (!Timers)
        {

            SpellTimer1 = SpawnCast[6].Timer1;
            SpellTimer2 = SpawnCast[7].Timer1;
            SpellTimer3 = SpawnCast[8].Timer1;
            Timers = true;
        }

        if (Timers)
        {
            if (SpellTimer1 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[6].SpellId);//Cleave
                SpellTimer1 = SpawnCast[6].Timer2 + (rand()%10 * 1000);
            } else SpellTimer1 -= diff;

            if (SpellTimer2 <= diff)
            {
                DoCast(me->getVictim(), SpawnCast[7].SpellId);//Shadowfury
                SpellTimer2 = SpawnCast[7].Timer2 + (rand()%5 * 1000);
            } else SpellTimer2 -= diff;

            if (SpellTimer3 <= diff)
            {
                DoCast(me, SpawnCast[8].SpellId);
                SpellTimer3 = SpawnCast[8].Timer2 + (rand()%7 * 1000);//Spell Reflection
            } else SpellTimer3 -= diff;
        }

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* slayer)
    {
        if (slayer)
            switch(slayer->GetTypeId())
        {
            case TYPEID_UNIT:
                if (Unit *owner = slayer->GetOwner())
                    if (owner->GetTypeId() == TYPEID_PLAYER)
                        CAST_PLR(owner)->GroupEventHappens(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, me);
                break;

            case TYPEID_PLAYER:
                CAST_PLR(slayer)->GroupEventHappens(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, me);
                break;
        }

        if (Creature* LordIllidan = (Unit::GetCreature(*me, LordIllidanGUID)))
        {
            DoScriptText(END_TEXT, LordIllidan, slayer);
            LordIllidan->AI()->EnterEvadeMode();
        }
    }
};

/*#####
# npc_lord_illidan_stormrage
#####*/

struct npc_lord_illidan_stormrageAI : public ScriptedAI
{
    npc_lord_illidan_stormrageAI(Creature* c) : ScriptedAI(c) {}

    uint64 PlayerGUID;

    uint32 WaveTimer;
    uint32 AnnounceTimer;

    int8 LiveCount;
    uint8 WaveCount;

    bool EventStarted;
    bool Announced;
    bool Failed;

    void Reset()
    {
        PlayerGUID = 0;

        WaveTimer = 10000;
        AnnounceTimer = 7000;
        LiveCount = 0;
        WaveCount = 0;

        EventStarted = false;
        Announced = false;
        Failed = false;

        me->SetVisibility(VISIBILITY_OFF);
    }

    void EnterCombat(Unit* /*who*/) {}
    void MoveInLineOfSight(Unit* /*who*/) {}
    void AttackStart(Unit* /*who*/) {}

    void SummonNextWave()
    {
        uint8 count = WavesInfo[WaveCount].SpawnCount;
        uint8 locIndex = WavesInfo[WaveCount].UsedSpawnPoint;
        srand(time(NULL));//initializing random seed
        uint8 FelguardCount = 0;
        uint8 DreadlordCount = 0;

        for (uint8 i = 0; i < count; ++i)
        {
            Creature* Spawn = NULL;
            float X = SpawnLocation[locIndex + i].x;
            float Y = SpawnLocation[locIndex + i].y;
            float Z = SpawnLocation[locIndex + i].z;
            float O = SpawnLocation[locIndex + i].o;
            Spawn = me->SummonCreature(WavesInfo[WaveCount].CreatureId, X, Y, Z, O, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
            ++LiveCount;

            if (Spawn)
            {
                Spawn->LoadCreaturesAddon();

                if (WaveCount == 0)//1 Wave
                {
                    if (rand()%3 == 1 && FelguardCount<2)
                    {
                        Spawn->SetDisplayId(18654);
                        ++FelguardCount;
                    }
                    else if (DreadlordCount < 3)
                    {
                        Spawn->SetDisplayId(19991);
                        ++DreadlordCount;
                    }
                    else if (FelguardCount<2)
                    {
                        Spawn->SetDisplayId(18654);
                        ++FelguardCount;
                    }
                }

                if (WaveCount < 3)//1-3 Wave
                {
                    if (PlayerGUID)
                    {
                        if (Player* pTarget = Unit::GetPlayer(PlayerGUID))
                        {
                            float x, y, z;
                            pTarget->GetPosition(x,y,z);
                            Spawn->GetMotionMaster()->MovePoint(0,x, y, z);
                        }
                    }
                    CAST_AI(mob_illidari_spawnAI, Spawn->AI())->LordIllidanGUID = me->GetGUID();
                }

                if (WavesInfo[WaveCount].CreatureId == 22076) // Torloth
                {
                    CAST_AI(mob_torloth_the_magnificentAI, Spawn->AI())->LordIllidanGUID = me->GetGUID();
                    if (PlayerGUID)
                        CAST_AI(mob_torloth_the_magnificentAI, Spawn->AI())->AggroTargetGUID = PlayerGUID;
                }
            }
        }
        ++WaveCount;
        WaveTimer = WavesInfo[WaveCount].SpawnTimer;
        AnnounceTimer = WavesInfo[WaveCount].YellTimer;
    }

    void CheckEventFail()
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        if (Group *EventGroup = pPlayer->GetGroup())
        {
            Player* GroupMember;

            uint8 GroupMemberCount = 0;
            uint8 DeadMemberCount = 0;
            uint8 FailedMemberCount = 0;

            const Group::MemberSlotList members = EventGroup->GetMemberSlots();

            for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
            {
                GroupMember = (Unit::GetPlayer(itr->guid));
                if (!GroupMember)
                    continue;
                if (!GroupMember->IsWithinDistInMap(me, EVENT_AREA_RADIUS) && GroupMember->GetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) == QUEST_STATUS_INCOMPLETE)
                {
                    GroupMember->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
                    GroupMember->SetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, QUEST_STATUS_NONE);
                    ++FailedMemberCount;
                }
                ++GroupMemberCount;

                if (GroupMember->isDead())
                {
                    ++DeadMemberCount;
                }
            }

            if (GroupMemberCount == FailedMemberCount)
            {
                Failed = true;
            }

            if (GroupMemberCount == DeadMemberCount)
            {
                for (Group::member_citerator itr = members.begin(); itr!= members.end(); ++itr)
                {
                    GroupMember = Unit::GetPlayer(itr->guid);

                    if (GroupMember && GroupMember->GetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH) == QUEST_STATUS_INCOMPLETE)
                    {
                        GroupMember->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
                        GroupMember->SetQuestStatus(QUEST_BATTLE_OF_THE_CRIMSON_WATCH, QUEST_STATUS_NONE);
                    }
                }
                Failed = true;
            }
        } else if (pPlayer->isDead() || !pPlayer->IsWithinDistInMap(me, EVENT_AREA_RADIUS))
        {
            pPlayer->FailQuest(QUEST_BATTLE_OF_THE_CRIMSON_WATCH);
            Failed = true;
        }
    }

    void LiveCounter()
    {
        --LiveCount;
        if (!LiveCount)
            Announced = false;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!PlayerGUID || !EventStarted)
            return;

        if (!LiveCount && WaveCount < 4)
        {
            if (!Announced && AnnounceTimer <= diff)
            {
                DoScriptText(WavesInfo[WaveCount].WaveTextId, me);
                Announced = true;
            } else AnnounceTimer -= diff;

            if (WaveTimer <= diff)
            {
                SummonNextWave();
            } else WaveTimer -= diff;
        }
        CheckEventFail();

        if (Failed)
            EnterEvadeMode();
    }
};

void mob_illidari_spawnAI::JustDied(Unit * /*slayer*/)
{
    me->RemoveCorpse();
    if (Creature* LordIllidan = (Unit::GetCreature(*me, LordIllidanGUID)))
        if (LordIllidan)
            CAST_AI(npc_lord_illidan_stormrageAI, LordIllidan->AI())->LiveCounter();
}

/*#####
# go_crystal_prison
######*/

bool GOQuestAccept_GO_crystal_prison(Player* plr, GameObject* /*go*/, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_BATTLE_OF_THE_CRIMSON_WATCH)
    {
        Creature* Illidan = plr->FindNearestCreature(22083, 50);

        if (Illidan && !CAST_AI(npc_lord_illidan_stormrageAI, Illidan->AI())->EventStarted)
        {
            CAST_AI(npc_lord_illidan_stormrageAI, Illidan->AI())->PlayerGUID = plr->GetGUID();
            CAST_AI(npc_lord_illidan_stormrageAI, Illidan->AI())->LiveCount = 0;
            CAST_AI(npc_lord_illidan_stormrageAI, Illidan->AI())->EventStarted=true;
        }
    }
 return true;
}

CreatureAI* GetAI_npc_lord_illidan_stormrage(Creature* c)
{
    return new npc_lord_illidan_stormrageAI(c);
}

CreatureAI* GetAI_mob_illidari_spawn(Creature* c)
{
    return new mob_illidari_spawnAI(c);
}

CreatureAI* GetAI_mob_torloth_the_magnificent(Creature* c)
{
    return new mob_torloth_the_magnificentAI(c);
}

/*####
# npc_enraged_spirits
####*/

/* QUESTS */
#define QUEST_ENRAGED_SPIRITS_FIRE_EARTH 10458
#define QUEST_ENRAGED_SPIRITS_AIR 10481
#define QUEST_ENRAGED_SPIRITS_WATER 10480

/* Totem */
#define ENTRY_TOTEM_OF_SPIRITS 21071
#define RADIUS_TOTEM_OF_SPIRITS 15

/* SPIRITS */
#define ENTRY_ENRAGED_EARTH_SPIRIT 21050
#define ENTRY_ENRAGED_FIRE_SPIRIT 21061
#define ENTRY_ENRAGED_AIR_SPIRIT 21060
#define ENTRY_ENRAGED_WATER_SPIRIT 21059

/* SOULS */
#define ENTRY_EARTHEN_SOUL 21073
#define ENTRY_FIERY_SOUL 21097
#define ENTRY_ENRAGED_AIRY_SOUL 21116
#define ENTRY_ENRAGED_WATERY_SOUL 21109  // wrong model

/* SPELL KILLCREDIT - not working!?! - using KilledMonsterCredit */
#define SPELL_EARTHEN_SOUL_CAPTURED_CREDIT 36108
#define SPELL_FIERY_SOUL_CAPTURED_CREDIT 36117
#define SPELL_AIRY_SOUL_CAPTURED_CREDIT 36182
#define SPELL_WATERY_SOUL_CAPTURED_CREDIT 36171

/* KilledMonsterCredit Workaround */
#define CREDIT_FIRE 21094
#define CREDIT_WATER 21095
#define CREDIT_AIR 21096
#define CREDIT_EARTH 21092

/* Captured Spell/Buff */
#define SPELL_SOUL_CAPTURED 36115

/* Factions */
#define ENRAGED_SOUL_FRIENDLY 35
#define ENRAGED_SOUL_HOSTILE 14

struct npc_enraged_spiritAI : public ScriptedAI
{
    npc_enraged_spiritAI(Creature *c) : ScriptedAI(c) {}

    void Reset()   { }

    void EnterCombat(Unit * /*who*/){}

    void JustDied(Unit* /*killer*/)
    {
        // always spawn spirit on death
        // if totem around
        // move spirit to totem and cast kill count
        uint32 entry = 0;
        uint32 credit = 0;

        switch(me->GetEntry()) {
          case ENTRY_ENRAGED_FIRE_SPIRIT:
            entry  = ENTRY_FIERY_SOUL;
            //credit = SPELL_FIERY_SOUL_CAPTURED_CREDIT;
            credit = CREDIT_FIRE;
          break;
          case ENTRY_ENRAGED_EARTH_SPIRIT:
            entry  = ENTRY_EARTHEN_SOUL;
            //credit = SPELL_EARTHEN_SOUL_CAPTURED_CREDIT;
            credit = CREDIT_EARTH;
          break;
          case ENTRY_ENRAGED_AIR_SPIRIT:
            entry  = ENTRY_ENRAGED_AIRY_SOUL;
            //credit = SPELL_AIRY_SOUL_CAPTURED_CREDIT;
            credit = CREDIT_AIR;
          break;
          case ENTRY_ENRAGED_WATER_SPIRIT:
            entry  = ENTRY_ENRAGED_WATERY_SOUL;
            //credit = SPELL_WATERY_SOUL_CAPTURED_CREDIT;
            credit = CREDIT_WATER;
          break;
        }

        // Spawn Soul on Kill ALWAYS!
        Creature* Summoned = NULL;
        Unit* totemOspirits = NULL;

        if (entry != 0)
            Summoned = DoSpawnCreature(entry, 0, 0, 1, 0, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 5000);

        // FIND TOTEM, PROCESS QUEST
        if (Summoned)
        {
             totemOspirits = me->FindNearestCreature(ENTRY_TOTEM_OF_SPIRITS, RADIUS_TOTEM_OF_SPIRITS);
             if (totemOspirits)
             {
                 Summoned->setFaction(ENRAGED_SOUL_FRIENDLY);
                 Summoned->GetMotionMaster()->MovePoint(0,totemOspirits->GetPositionX(), totemOspirits->GetPositionY(), Summoned->GetPositionZ());

                 Unit* Owner = totemOspirits->GetOwner();
                 if (Owner && Owner->GetTypeId() == TYPEID_PLAYER)
                     // DoCast(Owner, credit); -- not working!
                     CAST_PLR(Owner)->KilledMonsterCredit(credit, Summoned->GetGUID());
                 DoCast(totemOspirits, SPELL_SOUL_CAPTURED);
             }
        }
    }
};

CreatureAI* GetAI_npc_enraged_spirit(Creature* pCreature)
{
return new npc_enraged_spiritAI(pCreature);
}

/*#####
#
######*/

void AddSC_shadowmoon_valley()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mob_mature_netherwing_drake";
    newscript->GetAI = &GetAI_mob_mature_netherwing_drake;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_enslaved_netherwing_drake";
    newscript->GetAI = &GetAI_mob_enslaved_netherwing_drake;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_dragonmaw_peon";
    newscript->GetAI = &GetAI_mob_dragonmaw_peon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_drake_dealer_hurlunk";
    newscript->pGossipHello =  &GossipHello_npc_drake_dealer_hurlunk;
    newscript->pGossipSelect = &GossipSelect_npc_drake_dealer_hurlunk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npcs_flanis_swiftwing_and_kagrosh";
    newscript->pGossipHello =  &GossipHello_npcs_flanis_swiftwing_and_kagrosh;
    newscript->pGossipSelect = &GossipSelect_npcs_flanis_swiftwing_and_kagrosh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_murkblood_overseer";
    newscript->pGossipHello =  &GossipHello_npc_murkblood_overseer;
    newscript->pGossipSelect = &GossipSelect_npc_murkblood_overseer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_neltharaku";
    newscript->pGossipHello =  &GossipHello_npc_neltharaku;
    newscript->pGossipSelect = &GossipSelect_npc_neltharaku;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_karynaku";
    newscript->pQuestAccept = &QuestAccept_npc_karynaku;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_oronok_tornheart";
    newscript->pGossipHello =  &GossipHello_npc_oronok_tornheart;
    newscript->pGossipSelect = &GossipSelect_npc_oronok_tornheart;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_overlord_morghor";
    newscript->GetAI = &GetAI_npc_overlord_morghor;
    newscript->pQuestAccept = &QuestAccept_npc_overlord_morghor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_earthmender_wilda";
    newscript->GetAI = &GetAI_npc_earthmender_wilda;
    newscript->pQuestAccept = &QuestAccept_npc_earthmender_wilda;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lord_illidan_stormrage";
    newscript->GetAI = &GetAI_npc_lord_illidan_stormrage;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_crystal_prison";
    newscript->pGOQuestAccept = &GOQuestAccept_GO_crystal_prison;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_illidari_spawn";
    newscript->GetAI = &GetAI_mob_illidari_spawn;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_torloth_the_magnificent";
    newscript->GetAI = &GetAI_mob_torloth_the_magnificent;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_enraged_spirit";
    newscript->GetAI = &GetAI_npc_enraged_spirit;
    newscript->RegisterSelf();
}

