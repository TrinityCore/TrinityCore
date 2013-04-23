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
SDName: Icecrown
SD%Complete: 100
SDComment: Quest support: 12807
SDCategory: Icecrown
EndScriptData */

/* ContentData
npc_arete
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "Player.h"
#include "Vehicle.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "CombatAI.h"
#define CAST_PLR(a)     (dynamic_cast<Player*>(a))

/*######
## npc_arete
######*/

#define GOSSIP_ARETE_ITEM1 "Lord-Commander, I would hear your tale."
#define GOSSIP_ARETE_ITEM2 "<You nod slightly but do not complete the motion as the Lord-Commander narrows his eyes before he continues.>"
#define GOSSIP_ARETE_ITEM3 "I thought that they now called themselves the Scarlet Onslaught?"
#define GOSSIP_ARETE_ITEM4 "Where did the grand admiral go?"
#define GOSSIP_ARETE_ITEM5 "That's fine. When do I start?"
#define GOSSIP_ARETE_ITEM6 "Let's finish this!"
#define GOSSIP_ARETE_ITEM7 "That's quite a tale, Lord-Commander."

enum eArete
{
    GOSSIP_TEXTID_ARETE1        = 13525,
    GOSSIP_TEXTID_ARETE2        = 13526,
    GOSSIP_TEXTID_ARETE3        = 13527,
    GOSSIP_TEXTID_ARETE4        = 13528,
    GOSSIP_TEXTID_ARETE5        = 13529,
    GOSSIP_TEXTID_ARETE6        = 13530,
    GOSSIP_TEXTID_ARETE7        = 13531,
    FACTION_FRIENDLY            = 35,
    FACTION_HOSTILE             = 14,

    QUEST_THE_STORY_THUS_FAR    = 12807
};

class npc_arete : public CreatureScript
{
public:
    npc_arete() : CreatureScript("npc_arete") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_THE_STORY_THUS_FAR) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE1, creature->GetGUID());
            return true;
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE3, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE4, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE5, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE6, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+6:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE7, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+7:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(QUEST_THE_STORY_THUS_FAR);
                break;
        }

        return true;
    }
};

/*######
## npc_argent_squire
######*/

enum eArgentSquire
{
    QUEST_THE_ASPIRANT_S_CHALLENGE_H                    = 13680,
    QUEST_THE_ASPIRANT_S_CHALLENGE_A                    = 13679,

    QUEST_THE_VALIANT_S_CHALLENGE_SM                    = 13731,
    QUEST_THE_VALIANT_S_CHALLENGE_UC                    = 13729,
    QUEST_THE_VALIANT_S_CHALLENGE_TB                    = 13728,
    QUEST_THE_VALIANT_S_CHALLENGE_SJ                    = 13727,
    QUEST_THE_VALIANT_S_CHALLENGE_OG                    = 13726,
    QUEST_THE_VALIANT_S_CHALLENGE_DA                    = 13725,
    QUEST_THE_VALIANT_S_CHALLENGE_EX                    = 13724,
    QUEST_THE_VALIANT_S_CHALLENGE_GN                    = 13723,
    QUEST_THE_VALIANT_S_CHALLENGE_IF                    = 13713,
    QUEST_THE_VALIANT_S_CHALLENGE_SW                    = 13699,
  
    QUEST_THE_BLACK_KNGIHT_S_FALL                       = 13664,

    NPC_SQUIRE_DAVID                                    = 33447,
    NPC_SQUIRE_DANNY                                    = 33518,
    NPC_SQUIRE_CAVIN                                    = 33522,

    NPC_ARGENT_VALIANT                                  = 33448,
    NPC_ARGENT_CHAMPION                                 = 33707,
    NPC_BLACK_KNIGHT                                    = 33785,
    
    GOSSIP_TEXTID_SQUIRE                                = 14407
};

#define GOSSIP_SQUIRE_ITEM_1 "I am ready to fight!"
#define GOSSIP_SQUIRE_ITEM_2 "How do the Argent Crusader raiders fight?"

class npc_argent_squire : public CreatureScript
{
public:
    npc_argent_squire() : CreatureScript("npc_argent_squire") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        
    // Squire David handles Aspirant Stuff
    if (creature->GetEntry() == NPC_SQUIRE_DAVID)
    {
        if (player->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_H) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_A) == QUEST_STATUS_INCOMPLETE)//We need more info about it.
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        }
    }

    // Squire Danny handles Valiant Stuff
    if (creature->GetEntry() == NPC_SQUIRE_DANNY)
    {
        if (player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_SM) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_UC) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_TB) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_SJ) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_OG) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_DA) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_EX) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_GN) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_IF) == QUEST_STATUS_INCOMPLETE ||
            player->GetQuestStatus(QUEST_THE_VALIANT_S_CHALLENGE_SW) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        }
            
    }
    
    // Squire Cavin handles the Black Knight
    if (creature->GetEntry() == NPC_SQUIRE_CAVIN)
    {
        if (player->GetQuestStatus(QUEST_THE_BLACK_KNGIHT_S_FALL) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        }    
    }
    
    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SQUIRE, creature->GetGUID());
    return true;

    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            if (creature->GetEntry() == NPC_SQUIRE_DAVID)
                creature->SummonCreature(NPC_ARGENT_VALIANT, 8575.451f, 952.472f, 547.554f, 0.38f);
            else if (creature->GetEntry() == NPC_SQUIRE_DANNY)
                creature->SummonCreature(NPC_ARGENT_CHAMPION, 8534.675781f, 1069.993042f, 552.022827f, 1.274804f);
            else if (creature->GetEntry() == NPC_SQUIRE_CAVIN)
                creature->SummonCreature(NPC_BLACK_KNIGHT, 8430.522681f, 968.674318f, 545.674f, 0.001545f);
            
        }
        return true;
    }
};

/*######
## npc_argent_combatant
######*/

enum eArgentCombatant
{
    SPELL_CHARGE_COMBAT         = 63010,
    SPELL_SHIELD_BREAKER_COMBAT = 65147,
    SPELL_DEFEND                = 62719,
    SPELL_THRUST                = 62544,

    NPC_ARGENT_VALIANT_CREDIT   = 63049,
    NPC_ARGENT_CHAMPION_CREDIT  = 33708,
};

class npc_argent_combatant : public CreatureScript
{
public:
    npc_argent_combatant() : CreatureScript("npc_argent_combatant") { }

    struct npc_argent_combatantAI : public ScriptedAI
    {
        npc_argent_combatantAI(Creature* creature) : ScriptedAI(creature)
        {
            if (creature->GetEntry() == NPC_ARGENT_VALIANT)
            {
                creature->GetMotionMaster()->MovePoint(0, 8599.258f, 963.951f, 547.553f);
                creature->SetHomePosition(8599.258f, 963.951f, 547.553f, 0.18f);
            }
            if (creature->GetEntry() == NPC_ARGENT_CHAMPION)
            {
                creature->GetMotionMaster()->MovePoint(0, 8557.131836f, 1109.635742f, 556.787476f);
                creature->SetHomePosition(8557.131836f, 1109.635742f, 556.787476f, 1.27f);
            }
            creature->setFaction(35); //wrong faction in db?
        }

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;
        uint32 uiShieldTimer;
        uint32 uiThrustTimer;
        bool bCharge;

        void Reset()
        {
            uiChargeTimer = 12000;
            uiShieldBreakerTimer = 10000;
            uiShieldTimer = 4000;
            uiThrustTimer = 2000;
            bCharge = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            for (uint8 i = 0; i < 3; ++i)
                DoCast(me, SPELL_DEFEND, true);
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            // charge after moving away from the victim
            if (me->isInCombat() && me->getVictim() && bCharge)
            {
                me->GetMotionMaster()->Clear();
                // but only after rangecheck
                if (me->GetDistance(me->getVictim()) > 5.0f && me->GetDistance(me->getVictim()) <= 30.0f)
                    DoCastVictim(SPELL_CHARGE_COMBAT);
                me->GetMotionMaster()->MoveChase(me->getVictim());
                uiChargeTimer = 7000;
                bCharge = false;
            }
            else
                me->setFaction(14);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
        {
            if (uiDamage >= me->GetHealth() && pDoneBy->GetTypeId() == TYPEID_PLAYER)
            {
                uiDamage = 0;
                if (me->GetEntry() == NPC_ARGENT_VALIANT)
                    pDoneBy->CastSpell(pDoneBy, NPC_ARGENT_VALIANT_CREDIT, true);
                if (me->GetEntry() == NPC_ARGENT_CHAMPION)
                    CAST_PLR(pDoneBy)->KilledMonsterCredit(NPC_ARGENT_CHAMPION_CREDIT, 0);
                me->setFaction(35);
                me->DespawnOrUnsummon(5000);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                EnterEvadeMode();
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiShieldTimer <= uiDiff)
            {
                me->CastSpell(me, SPELL_DEFEND);
                uiShieldTimer = 4000;
            } else uiShieldTimer -= uiDiff;

            if (uiChargeTimer <= uiDiff && !bCharge)
            {
                // directly charge if range is ok
                if (me->GetDistance(me->getVictim()) > 5.0f && me->GetDistance(me->getVictim()) <= 30.0f)
                    DoCastVictim(SPELL_CHARGE_COMBAT);
                else
                {
                    // move away for charge...
                    float angle = me->GetAngle(me->getVictim());
                    float x = me->GetPositionX() + 20.0f * cos(angle);
                    float y = me->GetPositionY() + 20.0f * sin(angle);
                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
                    bCharge = true;
                }
            } else uiChargeTimer -= uiDiff;

            // prevent shieldbreaker while moving away, npc is not facing player at that time
            if (bCharge)
                return;

            if (uiShieldBreakerTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIELD_BREAKER_COMBAT);
                uiShieldBreakerTimer = 10000;
            } else uiShieldBreakerTimer -= uiDiff;

            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                if (uiThrustTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_THRUST);
                    uiThrustTimer = 2000;
                }
                else uiThrustTimer -= uiDiff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_argent_combatantAI(creature);
    }
};

/*#####
## npc_argent_faction_rider
######*/

enum eArgentFactionRiders
{
    NPC_EXODAR_VALIANT          = 33562,
    NPC_DARNASSUS_VALIANT       = 33559,
    NPC_GNOMEREGAN_VALIANT      = 33558,
    NPC_IRONFORGE_VALIANT       = 33564,
    NPC_STORMWIND_VALIANT       = 33561,
    NPC_SILVERMOON_VALIANT      = 33382,
    NPC_THUNDER_BLUFF_VALIANT   = 33383,
    NPC_UNDERCITY_VALIANT       = 33384,
    NPC_ORGRIMMAR_VALIANT       = 33306,
    NPC_SENJIN_VALIANT          = 33285,
    NPC_EXODAR_CHAMPION         = 33739,
    NPC_DARNASSUS_CHAMPION      = 33738,
    NPC_STORMWIND_CHAMPION      = 33747,
    NPC_IRONFORGE_CHAMPION      = 33743,
    NPC_GNOMEREGAN_CHAMPION     = 33740,
    NPC_SILVERMOON_CHAMPION     = 33746,
    NPC_THUNDER_BLUFF_CHAMPION  = 33748,
    NPC_ORGRIMMAR_CHAMPION      = 33744,
    NPC_SENJIN_CHAMPION         = 33745,
    NPC_UNDERCITY_CHAMPION      = 33749,

    QUEST_AMONG_CHAMPIONS_H_DK  = 13814,
    QUEST_AMONG_CHAMPIONS_H     = 13811,
    QUEST_AMONG_CHAMPIONS_A_DK  = 13793,
    QUEST_AMONG_CHAMPIONS_A     = 13790,
    QUEST_GRAND_MELEE_SM        = 13787,
    QUEST_GRAND_MELEE_UC        = 13782,
    QUEST_GRAND_MELEE_TB        = 13777,
    QUEST_GRAND_MELEE_SJ        = 13772,
    QUEST_GRAND_MELEE_OG        = 13767,
    QUEST_GRAND_MELEE_DA        = 13761,
    QUEST_GRAND_MELEE_EX        = 13756,
    QUEST_GRAND_MELEE_GN        = 13750,
    QUEST_GRAND_MELEE_IF        = 13745,
    QUEST_GRAND_MELEE_SW        = 13665,

    SPELL_BESTED_DARNASSUS          = 64805,
    SPELL_BESTED_EXODAR             = 64808,
    SPELL_BESTED_GNOMEREGAN         = 64809,
    SPELL_BESTED_IRONFORGE          = 64810,
    SPELL_BESTED_ORGRIMMAR          = 64811,
    SPELL_BESTED_SENJIN             = 64812,
    SPELL_BESTED_SILVERMOON         = 64813,
    SPELL_BESTED_STORMWIND          = 64814,
    SPELL_BESTED_THUNDER_BLUFF      = 64815,
    SPELL_BESTED_UNDERCITY          = 64816,
    SPELL_MOUNTED_MELEE_VICTORY_C   = 63596,
    SPELL_MOUNTED_MELEE_VICTORY_V   = 62724,
    SPELL_READYJOUST_POSE_EFFECT    = 64723,
    SPELL_JOUST_MUSIC               = 64780,
    SPELL_NO_MUSIC                  = 64794,

    ITEM_MARK_OF_CHAMPION       = 45500,
    ITEM_MARK_OF_VALIANT        = 45127,

    EVENT_START                 = 1,

    TYPE_VALIANT_ALLIANCE       = 1,
    TYPE_VALIANT_HORDE          = 2,
    TYPE_CHAMPION               = 3,
    TYPE_OTHER                  = 4,

    DATA_PLAYER                 = 1,
    DATA_TYPE                   = 2,
    DATA_DEFEATED               = 3,

    GOSSIP_TEXTID_CHAMPION      = 14421,
    GOSSIP_TEXTID_VALIANT       = 14384,
    GOSSIP_TEXTID_BESTED        = 14492,

    // Talk
    SAY_AGGRO                   = 0,
    SAY_DEFEATED                = 1,
    SAY_VICTORY                 = 2,
};

#define GOSSIP_FACTION_RIDER_1 "I am ready to fight!"

class npc_argent_faction_rider : public CreatureScript
{
public:
    npc_argent_faction_rider() : CreatureScript("npc_argent_faction_rider") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        // check for cooldown
        bool playerCooldown;

        switch (creature->GetEntry())
        {
            case NPC_EXODAR_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_EXODAR);
                break;
            case NPC_DARNASSUS_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_DARNASSUS);
                break;
            case NPC_STORMWIND_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_STORMWIND);
                break;
            case NPC_IRONFORGE_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_IRONFORGE);
                break;
            case NPC_GNOMEREGAN_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_GNOMEREGAN);
                break;
            case NPC_SILVERMOON_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_SILVERMOON);
                break;
            case NPC_THUNDER_BLUFF_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_THUNDER_BLUFF);
                break;
            case NPC_ORGRIMMAR_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_ORGRIMMAR);
                break;
            case NPC_SENJIN_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_SENJIN);
                break;
            case NPC_UNDERCITY_CHAMPION:
                playerCooldown = player->HasAura(SPELL_BESTED_UNDERCITY);
                break;
            case NPC_EXODAR_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_EXODAR);
                break;
            case NPC_DARNASSUS_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_DARNASSUS);
                break;
            case NPC_STORMWIND_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_STORMWIND);
                break;
            case NPC_IRONFORGE_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_IRONFORGE);
                break;
            case NPC_GNOMEREGAN_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_GNOMEREGAN);
                break;
            case NPC_SILVERMOON_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_SILVERMOON);
                break;
            case NPC_THUNDER_BLUFF_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_THUNDER_BLUFF);
                break;
            case NPC_ORGRIMMAR_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_ORGRIMMAR);
                break;
            case NPC_SENJIN_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_SENJIN);
                break;
            case NPC_UNDERCITY_VALIANT:
                playerCooldown = player->HasAura(SPELL_BESTED_UNDERCITY);
                break;
            default:
                playerCooldown = false;
                break;
        }

        uint32 type = creature->GetAI()->GetData(DATA_TYPE);

        // valiants can only be challenged by own faction, while champions fight every faction
        switch (type)
        {
            case TYPE_CHAMPION:
            {
                if (playerCooldown)
                {
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_BESTED, creature->GetGUID());
                }

                else
                {
                    if (player->GetQuestStatus(QUEST_AMONG_CHAMPIONS_H_DK) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_AMONG_CHAMPIONS_H) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_AMONG_CHAMPIONS_A_DK) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_AMONG_CHAMPIONS_A) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (player->GetVehicle())
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FACTION_RIDER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    }
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_CHAMPION, creature->GetGUID());
                    break;
                }
            }
            case TYPE_VALIANT_ALLIANCE:
            {
                if (playerCooldown)
                {
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_BESTED, creature->GetGUID());
                }

                else
                {
                    if (player->GetQuestStatus(QUEST_GRAND_MELEE_EX) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_DA) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_GN) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_IF) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_SW) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (player->GetVehicle())
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FACTION_RIDER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    }
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VALIANT, creature->GetGUID());
                }
                break;
            }
            case TYPE_VALIANT_HORDE:
            {
                if (playerCooldown)
                {
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_BESTED, creature->GetGUID());
                }

                else
                {
                    if (player->GetQuestStatus(QUEST_GRAND_MELEE_SM) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_UC) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_TB) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_SJ) == QUEST_STATUS_INCOMPLETE ||
                            player->GetQuestStatus(QUEST_GRAND_MELEE_OG) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (player->GetVehicle())
                            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FACTION_RIDER_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    }
                    player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_VALIANT, creature->GetGUID());
                }
                break;
            }
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();

            if (!player->GetVehicle())
                return false;

            creature->GetAI()->SetData(DATA_PLAYER, player->GetGUID());
            creature->GetAI()->DoAction(EVENT_START);
        }
        return true;
    }

    struct npc_argent_faction_riderAI : public ScriptedAI
    {
        npc_argent_faction_riderAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;
        uint32 uiShieldTimer;
        uint32 uiThrustTimer;
        uint32 uiMusicTimer;
        bool bCharge;
        bool bDefeated;
        Position arenaCenter;

        uint32 challengeeGUID;

        void Reset()
        {
            me->m_CombatDistance = 100.0f; // lawl, copied from zuldrak.cpp
            me->setFaction(35);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            DoCast(me, SPELL_READYJOUST_POSE_EFFECT, true);

            uiChargeTimer = 7000;
            uiShieldBreakerTimer = 10000;
            uiShieldTimer = 4000;
            uiThrustTimer = 2000;
            uiMusicTimer = 60000;
            bCharge = false;
            bDefeated = false;

            challengeeGUID = 0;

            if (GetCustomType() == TYPE_CHAMPION)
                arenaCenter.Relocate(8428.757f, 945.349f, 544.675f);
            else if (GetCustomType() == TYPE_VALIANT_ALLIANCE)
                arenaCenter.Relocate(8656.402f, 722.827f, 547.523f);
            else if (GetCustomType() == TYPE_VALIANT_HORDE)
                arenaCenter.Relocate(8334.375f, 721.165f, 553.702f);

        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
                case DATA_TYPE:
                    return GetCustomType();
                case DATA_DEFEATED:
                    return bDefeated ? 1 : 0;
                default:
                    break;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_PLAYER)
                challengeeGUID = data;
        }

        void DoAction(int32 type)
        {
            if (type == EVENT_START)
            {
                // check valid player
                Player* challengee = ObjectAccessor::GetPlayer(*me, challengeeGUID);
                if (!challengee)
                    return;

                // remove gossip flag
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                // remove pose aura, otherwise no walking animation
                me->RemoveAura(SPELL_READYJOUST_POSE_EFFECT);

                uint8 stackAmount;
                if (GetCustomType() == TYPE_CHAMPION)
                    stackAmount = 3;
                else
                    stackAmount = 2;

                for (uint8 i = 0; i < stackAmount; ++i)
                    DoCast(me, SPELL_DEFEND, true);

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->setFaction(14);
                Talk(SAY_AGGRO);
                uiMusicTimer = 50;

                // move towards arena center
                float angle = me->GetAngle(&arenaCenter);
                float x = me->GetPositionX() + 22.0f * cos(angle);
                float y = me->GetPositionY() + 22.0f * sin(angle);
                me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
            }

        }

        uint32 GetCustomType() const
        {
            switch (me->GetEntry())
            {
                case NPC_EXODAR_CHAMPION:
                case NPC_DARNASSUS_CHAMPION:
                case NPC_STORMWIND_CHAMPION:
                case NPC_IRONFORGE_CHAMPION:
                case NPC_GNOMEREGAN_CHAMPION:
                case NPC_SILVERMOON_CHAMPION:
                case NPC_THUNDER_BLUFF_CHAMPION:
                case NPC_ORGRIMMAR_CHAMPION:
                case NPC_SENJIN_CHAMPION:
                case NPC_UNDERCITY_CHAMPION:
                    return TYPE_CHAMPION;
                case NPC_EXODAR_VALIANT:
                case NPC_DARNASSUS_VALIANT:
                case NPC_GNOMEREGAN_VALIANT:
                case NPC_IRONFORGE_VALIANT:
                case NPC_STORMWIND_VALIANT:
                    return TYPE_VALIANT_ALLIANCE;
                case NPC_SILVERMOON_VALIANT:
                case NPC_THUNDER_BLUFF_VALIANT:
                case NPC_UNDERCITY_VALIANT:
                case NPC_ORGRIMMAR_VALIANT:
                case NPC_SENJIN_VALIANT:
                    return TYPE_VALIANT_HORDE;
                default:
                    return TYPE_OTHER;
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            // charge after moving away from the victim
            if (me->isInCombat() && me->getVictim() && bCharge)
            {
                me->GetMotionMaster()->Clear();
                // but only after rangecheck
                if (me->GetDistance(me->getVictim()) > 5.0f && me->GetDistance(me->getVictim()) <= 30.0f)
                    DoCastVictim(SPELL_CHARGE_COMBAT);
                me->GetMotionMaster()->MoveChase(me->getVictim());
                uiChargeTimer = GetCustomType() == TYPE_CHAMPION ? 6500 : 7500;
                bCharge = false;
            }
            else
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, challengeeGUID))
                {
                   if (Vehicle* vehicle = player->GetVehicle())
                   {
                      if (Unit* vehicleCreature = vehicle->GetBase())
                        {
                            me->SetInCombatWith(vehicleCreature);
                            vehicleCreature->SetInCombatWith(me);
                            me->AddThreat(vehicleCreature, 0.0f);
                            AttackStart(vehicleCreature);
                        }
                    }
                    else
                        AttackStart(player);
                }
            }
        }

        void DamageTaken(Unit* who, uint32& damage)
        {
            if (damage >= me->GetHealth() && who->GetTypeId() == TYPEID_PLAYER && !bDefeated)
            {
                me->DeleteThreatList();
                me->CombatStop(false);
                bDefeated = true;
                me->SetFullHealth();
                damage = 0;
                GrantCredit(who);
                Talk(SAY_DEFEATED);
                me->setFaction(35);
                me->DespawnOrUnsummon(5000);
            }
        }

        void GrantCredit(Unit* who)
        {
            Player* player;
            if (!(player = who->ToPlayer()))
                return;

            switch (GetCustomType())
            {
                case TYPE_CHAMPION:
                {
                    who->CastSpell(who, SPELL_MOUNTED_MELEE_VICTORY_C, true);
                    who->CastSpell(who, SPELL_NO_MUSIC, true);
                    uint32 creditSpell;
                    switch (me->GetEntry())
                    {
                        case NPC_EXODAR_CHAMPION:
                            creditSpell = SPELL_BESTED_EXODAR;
                            break;
                        case NPC_DARNASSUS_CHAMPION:
                            creditSpell = SPELL_BESTED_DARNASSUS;
                            break;
                        case NPC_STORMWIND_CHAMPION:
                            creditSpell = SPELL_BESTED_STORMWIND;
                            break;
                        case NPC_IRONFORGE_CHAMPION:
                            creditSpell = SPELL_BESTED_IRONFORGE;
                            break;
                        case NPC_GNOMEREGAN_CHAMPION:
                            creditSpell = SPELL_BESTED_GNOMEREGAN;
                            break;
                        case NPC_SILVERMOON_CHAMPION:
                            creditSpell = SPELL_BESTED_SILVERMOON;
                            break;
                        case NPC_THUNDER_BLUFF_CHAMPION:
                            creditSpell = SPELL_BESTED_THUNDER_BLUFF;
                            break;
                        case NPC_ORGRIMMAR_CHAMPION:
                            creditSpell = SPELL_BESTED_ORGRIMMAR;
                            break;
                        case NPC_SENJIN_CHAMPION:
                            creditSpell = SPELL_BESTED_SENJIN;
                            break;
                        case NPC_UNDERCITY_CHAMPION:
                            creditSpell = SPELL_BESTED_UNDERCITY;
                            break;
                    }
                    who->CastSpell(who, creditSpell, false);
                    who->CastSpell(who, creditSpell, false); // second cast for criteria check...which is checked before aura is applied...HILARIOUS!
                    break;
                }
                case TYPE_VALIANT_ALLIANCE:
                {
                    who->CastSpell(who, SPELL_MOUNTED_MELEE_VICTORY_V, true);
                    who->CastSpell(who, SPELL_NO_MUSIC, true);
                    uint32 creditSpell;
                    switch (me->GetEntry())
                    {
                        case NPC_EXODAR_VALIANT:
                            creditSpell = SPELL_BESTED_EXODAR;
                            break;
                        case NPC_DARNASSUS_VALIANT:
                            creditSpell = SPELL_BESTED_DARNASSUS;
                            break;
                        case NPC_STORMWIND_VALIANT:
                            creditSpell = SPELL_BESTED_STORMWIND;
                            break;
                        case NPC_IRONFORGE_VALIANT:
                            creditSpell = SPELL_BESTED_IRONFORGE;
                            break;
                        case NPC_GNOMEREGAN_VALIANT:
                            creditSpell = SPELL_BESTED_GNOMEREGAN;
                            break;
                    }
                    who->CastSpell(who, creditSpell, false);
                    who->CastSpell(who, creditSpell, false);
                    break;
                }
                case TYPE_VALIANT_HORDE:
                {
                    who->CastSpell(who, SPELL_MOUNTED_MELEE_VICTORY_V, true);
                    who->CastSpell(who, SPELL_NO_MUSIC, true);
                    uint32 creditSpell;
                    switch (me->GetEntry())
                    {
                        case NPC_SILVERMOON_VALIANT:
                            creditSpell = SPELL_BESTED_SILVERMOON;
                            break;
                        case NPC_THUNDER_BLUFF_VALIANT:
                            creditSpell = SPELL_BESTED_THUNDER_BLUFF;
                            break;
                        case NPC_ORGRIMMAR_VALIANT:
                            creditSpell = SPELL_BESTED_ORGRIMMAR;
                            break;
                        case NPC_SENJIN_VALIANT:
                            creditSpell = SPELL_BESTED_SENJIN;
                            break;
                        case NPC_UNDERCITY_VALIANT:
                            creditSpell = SPELL_BESTED_UNDERCITY;
                            break;
                    }
                    who->CastSpell(who, creditSpell, false);
                    who->CastSpell(who, creditSpell, false);
                    break;
                }
            }

        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (Player* challengee = ObjectAccessor::GetPlayer(*me, challengeeGUID))
            {
                if (!challengee->GetVehicle() && me->isInCombat())
                {
                    me->DeleteThreatList();
                    me->CombatStop(false);
                    challengee->CastSpell(challengee, SPELL_NO_MUSIC, false);
                    Talk(SAY_VICTORY);
                    me->setFaction(35);
                    me->DespawnOrUnsummon(2000);
                }
            }

            if (uiShieldTimer <= uiDiff)
            {
                me->CastSpell(me, SPELL_DEFEND);
                uiShieldTimer = GetCustomType() == TYPE_CHAMPION ? 8000 : 6000;
            } else uiShieldTimer -= uiDiff;

            if (uiMusicTimer <= uiDiff)
            {
                if (Player* challengee = ObjectAccessor::GetPlayer(*me, challengeeGUID))
                    challengee->CastSpell(challengee, SPELL_JOUST_MUSIC, false);

                uiMusicTimer = 60000;
            }

            if (uiChargeTimer <= uiDiff && !bCharge)
            {
                // directly charge if range is ok
                if (me->GetDistance(me->getVictim()) > 10.0f && me->GetDistance(me->getVictim()) <= 25.0f)
                {
                    DoCastVictim(SPELL_CHARGE_COMBAT);
                    uiChargeTimer = GetCustomType() == TYPE_CHAMPION ? 6500 : 7500;
                }
                else
                {
                    // move away for charge...
                    float angle = me->GetAngle(me->getVictim());
                    float x = me->GetPositionX() + 20.0f * cos(angle);
                    float y = me->GetPositionY() + 20.0f * sin(angle);
                    me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
                    bCharge = true;
                }
            } else uiChargeTimer -= uiDiff;

            if (uiShieldBreakerTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIELD_BREAKER_COMBAT);
                uiShieldBreakerTimer = GetCustomType() == TYPE_CHAMPION ? 9000 : 10000;
            } else uiShieldBreakerTimer -= uiDiff;

            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                if (uiThrustTimer <= uiDiff)
                {
                    DoCastVictim(SPELL_THRUST);
                    uiThrustTimer = GetCustomType() == TYPE_CHAMPION ? 1800 : 2000;
                }
                else uiThrustTimer -= uiDiff;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_argent_faction_riderAI(creature);
    }
};


/*######
## npc_argent_valiant
######*/

enum eArgentValiant
{
    SPELL_CHARGE                = 63010,
    SPELL_SHIELD_BREAKER        = 65147,
    SPELL_KILL_CREDIT           = 63049
};

class npc_argent_valiant : public CreatureScript
{
public:
    npc_argent_valiant() : CreatureScript("npc_argent_valiant") { }

    struct npc_argent_valiantAI : public ScriptedAI
    {
        npc_argent_valiantAI(Creature* creature) : ScriptedAI(creature)
        {
            creature->GetMotionMaster()->MovePoint(0, 8599.258f, 963.951f, 547.553f);
            creature->setFaction(35); //wrong faction in db?
        }

        uint32 uiChargeTimer;
        uint32 uiShieldBreakerTimer;

        void Reset()
        {
            uiChargeTimer = 7000;
            uiShieldBreakerTimer = 10000;
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            me->setFaction(14);
        }

        void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
        {
            if (uiDamage > me->GetHealth() && pDoneBy->GetTypeId() == TYPEID_PLAYER)
            {
                uiDamage = 0;
                pDoneBy->CastSpell(pDoneBy, SPELL_KILL_CREDIT, true);
                me->setFaction(35);
                me->DespawnOrUnsummon(5000);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                EnterEvadeMode();
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiChargeTimer <= uiDiff)
            {
                DoCastVictim(SPELL_CHARGE);
                uiChargeTimer = 7000;
            } else uiChargeTimer -= uiDiff;

            if (uiShieldBreakerTimer <= uiDiff)
            {
                DoCastVictim(SPELL_SHIELD_BREAKER);
                uiShieldBreakerTimer = 10000;
            } else uiShieldBreakerTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_argent_valiantAI(creature);
    }
};

/*######
## npc_guardian_pavilion
######*/

enum eGuardianPavilion
{
    SPELL_TRESPASSER_H                            = 63987,
    AREA_SUNREAVER_PAVILION                       = 4676,

    AREA_SILVER_COVENANT_PAVILION                 = 4677,
    SPELL_TRESPASSER_A                            = 63986,
};

class npc_guardian_pavilion : public CreatureScript
{
public:
    npc_guardian_pavilion() : CreatureScript("npc_guardian_pavilion") { }

    struct npc_guardian_pavilionAI : public ScriptedAI
    {
        npc_guardian_pavilionAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (me->GetAreaId() != AREA_SUNREAVER_PAVILION && me->GetAreaId() != AREA_SILVER_COVENANT_PAVILION)
                return;

            if (!who || who->GetTypeId() != TYPEID_PLAYER || !me->IsHostileTo(who) || !me->isInBackInMap(who, 5.0f))
                return;

            if (who->HasAura(SPELL_TRESPASSER_H) || who->HasAura(SPELL_TRESPASSER_A))
                return;

            if (who->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
                who->CastSpell(who, SPELL_TRESPASSER_H, true);
            else
                who->CastSpell(who, SPELL_TRESPASSER_A, true);

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_guardian_pavilionAI(creature);
    }
};

/*######
## npc_vereth_the_cunning
######*/

enum eVerethTheCunning
{
    NPC_GEIST_RETURN_BUNNY_KC   = 31049,
    NPC_LITHE_STALKER           = 30894,
    SPELL_SUBDUED_LITHE_STALKER = 58151,
};

class npc_vereth_the_cunning : public CreatureScript
{
public:
    npc_vereth_the_cunning() : CreatureScript("npc_vereth_the_cunning") { }

    struct npc_vereth_the_cunningAI : public ScriptedAI
    {
        npc_vereth_the_cunningAI(Creature* creature) : ScriptedAI(creature) {}

        void MoveInLineOfSight(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (who->GetEntry() == NPC_LITHE_STALKER && me->IsWithinDistInMap(who, 10.0f))
            {
                if (Unit* owner = who->GetCharmer())
                {
                    if (who->HasAura(SPELL_SUBDUED_LITHE_STALKER))
                        {
                            owner->ToPlayer()->KilledMonsterCredit(NPC_GEIST_RETURN_BUNNY_KC, 0);
                            who->ToCreature()->DisappearAndDie();

                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vereth_the_cunningAI(creature);
    }
};

/*######
* npc_tournament_training_dummy
######*/
enum TournamentDummy
{
    NPC_CHARGE_TARGET         = 33272,
    NPC_MELEE_TARGET          = 33229,
    NPC_RANGED_TARGET         = 33243,

    SPELL_CHARGE_CREDIT       = 62658,
    SPELL_MELEE_CREDIT        = 62672,
    SPELL_RANGED_CREDIT       = 62673,

    SPELL_PLAYER_THRUST       = 62544,
    SPELL_PLAYER_BREAK_SHIELD = 62626,
    SPELL_PLAYER_CHARGE       = 62874,

    SPELL_RANGED_DEFEND       = 62719,
    SPELL_CHARGE_DEFEND       = 64100,
    SPELL_VULNERABLE          = 62665,

    SPELL_COUNTERATTACK       = 62709,

    EVENT_DUMMY_RECAST_DEFEND = 1,
    EVENT_DUMMY_RESET         = 2,
};

class npc_tournament_training_dummy : public CreatureScript
{
    public:
        npc_tournament_training_dummy(): CreatureScript("npc_tournament_training_dummy"){}

        struct npc_tournament_training_dummyAI : ScriptedAI
        {
            npc_tournament_training_dummyAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
            }

            EventMap events;
            bool isVulnerable;

            void Reset()
            {
                me->SetControlled(true, UNIT_STATE_STUNNED);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                isVulnerable = false;

                // Cast Defend spells to max stack size
                switch (me->GetEntry())
                {
                    case NPC_CHARGE_TARGET:
                        DoCast(SPELL_CHARGE_DEFEND);
                        break;
                    case NPC_RANGED_TARGET:
                        me->CastCustomSpell(SPELL_RANGED_DEFEND, SPELLVALUE_AURA_STACK, 3, me);
                        break;
                }

                events.Reset();
                events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5000);
            }

            void EnterEvadeMode()
            {
                if (!_EnterEvadeMode())
                    return;

                Reset();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                damage = 0;
                events.RescheduleEvent(EVENT_DUMMY_RESET, 10000);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                switch (me->GetEntry())
                {
                    case NPC_CHARGE_TARGET:
                        if (spell->Id == SPELL_PLAYER_CHARGE)
                            if (isVulnerable)
                                DoCast(caster, SPELL_CHARGE_CREDIT, true);
                        break;
                    case NPC_MELEE_TARGET:
                        if (spell->Id == SPELL_PLAYER_THRUST)
                        {
                            DoCast(caster, SPELL_MELEE_CREDIT, true);

                            if (Unit* target = caster->GetVehicleBase())
                                DoCast(target, SPELL_COUNTERATTACK, true);
                        }
                        break;
                    case NPC_RANGED_TARGET:
                        if (spell->Id == SPELL_PLAYER_BREAK_SHIELD)
                            if (isVulnerable)
                                DoCast(caster, SPELL_RANGED_CREDIT, true);
                        break;
                }

                if (spell->Id == SPELL_PLAYER_BREAK_SHIELD)
                    if (!me->HasAura(SPELL_CHARGE_DEFEND) && !me->HasAura(SPELL_RANGED_DEFEND))
                        isVulnerable = true;
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_DUMMY_RECAST_DEFEND:
                        switch (me->GetEntry())
                        {
                            case NPC_CHARGE_TARGET:
                            {
                                if (!me->HasAura(SPELL_CHARGE_DEFEND))
                                    DoCast(SPELL_CHARGE_DEFEND);
                                break;
                            }
                            case NPC_RANGED_TARGET:
                            {
                                Aura* defend = me->GetAura(SPELL_RANGED_DEFEND);
                                if (!defend || defend->GetStackAmount() < 3 || defend->GetDuration() <= 8000)
                                    DoCast(SPELL_RANGED_DEFEND);
                                break;
                            }
                        }
                        isVulnerable = false;
                        events.ScheduleEvent(EVENT_DUMMY_RECAST_DEFEND, 5000);
                        break;
                    case EVENT_DUMMY_RESET:
                        if (UpdateVictim())
                        {
                            EnterEvadeMode();
                            events.ScheduleEvent(EVENT_DUMMY_RESET, 10000);
                        }
                        break;
                }

                if (!UpdateVictim())
                    return;

                if (!me->HasUnitState(UNIT_STATE_STUNNED))
                    me->SetControlled(true, UNIT_STATE_STUNNED);
            }

            void MoveInLineOfSight(Unit* /*who*/){}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tournament_training_dummyAI(creature);
        }

};

enum BlackKnightsGrave
{
	NPC_CULT_SABOTEUR			= 35116,
	NPC_CULT_ASSASSIN			= 35127,
	QUEST_THEBLACKKNIGHTSCURSE	= 14016
};

const Position CultistSpawnPos[] =
{
 {8451.91f, 459.163f, 596.072f, 0.80f}, // NPC_CULT_SABOTEUR
 {8456.2f, 458.904f, 596.072f, 1.55f},  // NPC_CULT_ASSASSIN
};

class npc_black_knights_grave : public CreatureScript
{
public:
    npc_black_knights_grave() : CreatureScript("npc_black_knights_grave") { }

    struct npc_black_knights_graveAI : public ScriptedAI
    {
        npc_black_knights_graveAI(Creature* creature) : ScriptedAI(creature){}

		void MoveInLineOfSight(Unit* who)
        {
            ScriptedAI::MoveInLineOfSight(who);

            if (!me->FindNearestCreature(NPC_CULT_ASSASSIN, 50.0f, true) && who->ToPlayer() && me->IsWithinDist(who, 0.8f) && who->ToPlayer()->GetQuestStatus(QUEST_THEBLACKKNIGHTSCURSE) == QUEST_STATUS_INCOMPLETE) 
	        {
			    me->SummonCreature(NPC_CULT_SABOTEUR, CultistSpawnPos[0], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
			    me->SummonCreature(NPC_CULT_ASSASSIN, CultistSpawnPos[1], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
	        }
        }

        void Reset(){}

		void JustDied(Unit* Player /*victim*/){}

		void UpdateAI(uint32 /*diff*/){}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_black_knights_graveAI(creature);
    }
};

// Boneguard Commander and Lieutenant
enum BoneguardMounted
{
    // NPCs
    NPC_BONEGUARD_COMMANDER         = 34127,
    NPC_BONEGUARD_LIEUTENANT        = 33429,

    // Spells
    SPELL_BANNER_BEARER             = 59942,
    
    // Events
    EVENT_BONEGUARD_SHIELD                    = 1,
    EVENT_BONEGUARD_SHIELD_OOC                = 2,
    EVENT_BONEGUARD_CHARGE                    = 3,
    EVENT_BONEGUARD_SHIELD_BREAKER            = 4,

};

class npc_boneguard_mounted : public CreatureScript
{
public:
    npc_boneguard_mounted() : CreatureScript("npc_boneguard_mounted") { }

    struct npc_boneguard_mountedAI : public ScriptedAI
    {
        npc_boneguard_mountedAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;
        bool bCharge;


        void Reset()
        {
            DoCast(me, SPELL_BANNER_BEARER, false);

            bCharge = false;
            
            events.Reset();
            events.ScheduleEvent(EVENT_BONEGUARD_SHIELD_OOC, 50000);
			
            uint8 stackAmount;
            if (me->GetEntry() == NPC_BONEGUARD_COMMANDER)
                stackAmount = 3;
            else
                stackAmount = 1;

            for (uint8 i = 0; i < stackAmount; ++i)
            {
                me->RemoveAurasDueToSpell(SPELL_DEFEND + i);
                DoCast(me, SPELL_DEFEND, true);
            }
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.Reset();
            events.ScheduleEvent(EVENT_BONEGUARD_SHIELD, 7000);
            events.ScheduleEvent(EVENT_BONEGUARD_CHARGE, 10000);
            events.ScheduleEvent(EVENT_BONEGUARD_SHIELD_BREAKER, 10000);
        }
        
        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            // charge after moving away from the victim
            if (me->isInCombat() && me->getVictim() && bCharge)
            {
                me->GetMotionMaster()->Clear();
                // but only after rangecheck
                if (me->GetDistance(me->getVictim()) > 10.0f && me->GetDistance(me->getVictim()) <= 25.0f)
                    DoCastVictim(SPELL_CHARGE_COMBAT);
                me->GetMotionMaster()->MoveChase(me->getVictim());
                events.ScheduleEvent(EVENT_CHARGE, 10000);
                bCharge = false;
            }
        }
        
        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {

                case EVENT_BONEGUARD_SHIELD:
                    me->CastSpell(me, SPELL_DEFEND);
                    events.ScheduleEvent(EVENT_BONEGUARD_SHIELD, 7000);
                    break;
                case EVENT_BONEGUARD_SHIELD_OOC:
                    uint8 stackAmount;
                    if (me->GetEntry() == NPC_BONEGUARD_COMMANDER)
                        stackAmount = 3;
                    else
                        stackAmount = 1;
        
                    for (uint8 i = 0; i < stackAmount; ++i)
                    {
                        me->RemoveAurasDueToSpell(SPELL_DEFEND + i);
                        DoCast(me, SPELL_DEFEND, true);
                    }
                    events.ScheduleEvent(EVENT_BONEGUARD_SHIELD_OOC, 50000);
                    break;
                case EVENT_BONEGUARD_CHARGE:
                    if (UpdateVictim())
                    {
                        if (me->GetDistance(me->getVictim()) > 10.0f && me->GetDistance(me->getVictim()) <= 25.0f)
                        {
                            DoCastVictim(SPELL_CHARGE_COMBAT);
                            events.ScheduleEvent(EVENT_BONEGUARD_CHARGE, 10000);
                        }
                        else
                        {
                            // move away for charge...
                            float angle = me->GetAngle(me->getVictim());
                            float x = me->GetPositionX() + 20.0f * cos(angle);
                            float y = me->GetPositionY() + 20.0f * sin(angle);
                            me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());
                            bCharge = true;
                        }
                    }
                    break;
                case EVENT_BONEGUARD_SHIELD_BREAKER:
                    DoCastVictim(SPELL_SHIELD_BREAKER_COMBAT);
                    events.ScheduleEvent(EVENT_BONEGUARD_SHIELD_BREAKER, 10000);
                    break;
            }
            
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_boneguard_mountedAI(creature);
    }
};

// Battle for Crusaders' Pinnacle
enum BlessedBanner
{
    SPELL_BLESSING_OF_THE_CRUSADE       = 58026,
    SPELL_THREAT_PULSE                  = 58113,
    SPELL_CRUSADERS_SPIRE_VICTORY       = 58084,
    SPELL_TORCH                         = 58121,

    NPC_BLESSED_BANNER                  = 30891,
    NPC_CRUSADER_LORD_DALFORS           = 31003,
    NPC_ARGENT_BATTLE_PRIEST            = 30919,
    NPC_ARGENT_MASON                    = 30900,
    NPC_REANIMATED_CAPTAIN              = 30986,
    NPC_SCOURGE_DRUDGE                  = 30984,
    NPC_HIDEOUS_PLAGEBRINGER            = 30987,
    NPC_HALOF_THE_DEATHBRINGER          = 30989,
    NPC_LK                              = 31013,

    BANNER_SAY                          = 0, // "The Blessed Banner of the Crusade has been planted.\n Defend the banner from all attackers!"
    DALFORS_SAY_PRE_1                   = 0, // "BY THE LIGHT! Those damned monsters! Look at what they've done to our people!"
    DALFORS_SAY_PRE_2                   = 1, // "Burn it down, boys. Burn it all down."
    DALFORS_SAY_START                   = 2, // "Let 'em come. They'll pay for what they've done!"
    DALFORS_YELL_FINISHED               = 3, // "We've done it, lads! We've taken the pinnacle from the Scourge! Report to Father Gustav at once and tell him the good news! We're gonna get to buildin' and settin' up! Go!"
    LK_TALK_1                           = 0, // "Leave no survivors!"
    LK_TALK_2                           = 1, // "Cower before my terrible creations!"
    LK_TALK_3                           = 2, // "Feast my children! Feast upon the flesh of the living!"
    LK_TALK_4                           = 3, // "Lay down your arms and surrender your souls!"

    EVENT_SPAWN                         = 1,
    EVENT_INTRO_1                       = 2,
    EVENT_INTRO_2                       = 3,
    EVENT_INTRO_3                       = 4,
    EVENT_MASON_ACTION                  = 5,
    EVENT_START_FIGHT                   = 6,
    EVENT_WAVE_SPAWN                    = 7,
    EVENT_HALOF                         = 8,
    EVENT_ENDED                         = 9,
};

Position const DalforsPos[3] =
{
    {6458.703f, 403.858f, 490.498f, 3.1205f}, // Dalfors spawn point
    {6422.950f, 423.335f, 510.451f, 0.0f}, // Dalfors intro pos
    {6426.343f, 420.515f, 508.650f, 0.0f}, // Dalfors fight pos
};

Position const Priest1Pos[2] =
{
    {6462.025f, 403.681f, 489.721f, 3.1007f}, // priest1 spawn point
    {6421.480f, 423.576f, 510.781f, 5.7421f}, // priest1 intro pos
};

Position const Priest2Pos[2] =
{
    {6463.969f, 407.198f, 489.240f, 2.2689f}, // priest2 spawn point
    {6419.778f, 421.404f, 510.972f, 5.7421f}, // priest2 intro pos
};

Position const Priest3Pos[2] =
{
    {6464.371f, 400.944f, 489.186f, 6.1610f}, // priest3 spawn point
    {6423.516f, 425.782f, 510.774f, 5.7421f}, // priest3 intro pos
};

Position const Mason1Pos[3] =
{
    {6462.929f, 409.826f, 489.392f, 3.0968f}, // mason1 spawn point
    {6428.163f, 421.960f, 508.297f, 0.0f}, // mason1 intro pos
    {6414.335f, 454.904f, 511.395f, 2.8972f}, // mason1 action pos
};

Position const Mason2Pos[3] =
{
    {6462.650f, 405.670f, 489.576f, 2.9414f}, // mason2 spawn point
    {6426.250f, 419.194f, 508.219f, 0.0f}, // mason2 intro pos
    {6415.014f, 446.849f, 511.395f, 3.1241f}, // mason2 action pos
};

Position const Mason3Pos[3] =
{
    {6462.646f, 401.218f, 489.601f, 2.7864f}, // mason3 spawn point
    {6423.855f, 416.598f, 508.305f, 0.0f}, // mason3 intro pos
    {6417.070f, 438.824f, 511.395f, 3.6651f}, // mason3 action pos
};

class npc_blessed_banner : public CreatureScript
{
public:
    npc_blessed_banner() : CreatureScript("npc_blessed_banner") { }

    struct npc_blessed_bannerAI : public ScriptedAI
    {
        npc_blessed_bannerAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            HalofSpawned = false;
            PhaseCount = 0;
            Summons.DespawnAll();

            SetCombatMovement(false);
        }

        EventMap events;

        bool HalofSpawned;

        uint32 PhaseCount;

        SummonList Summons;

        uint64 guidDalfors;
        uint64 guidPriest[3];
        uint64 guidMason[3];
        uint64 guidHalof;

        void Reset()
        {
            me->setRegeneratingHealth(false);
            DoCast(SPELL_THREAT_PULSE);
            me->AI()->Talk(BANNER_SAY);
            events.ScheduleEvent(EVENT_SPAWN, 3000);
        }

        void EnterCombat(Unit* /*who*/) {}

        void MoveInLineOfSight(Unit* /*who*/) {}

        void JustSummoned(Creature* Summoned)
        {
            Summons.Summon(Summoned);
        }

        void JustDied(Unit* /*killer*/)
        {
            Summons.DespawnAll();
            me->DespawnOrUnsummon();
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);

            switch (events.ExecuteEvent())
            {
                case EVENT_SPAWN:
                    {
                        if (Creature* Dalfors = DoSummon(NPC_CRUSADER_LORD_DALFORS, DalforsPos[0]))
                        {
                            guidDalfors = Dalfors->GetGUID();
                            Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[1]);
                        }
                        if (Creature* Priest1 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest1Pos[0]))
                        {
                            guidPriest[0] = Priest1->GetGUID();
                            Priest1->GetMotionMaster()->MovePoint(0, Priest1Pos[1]);
                        }
                        if (Creature* Priest2 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest2Pos[0]))
                        {
                            guidPriest[1] = Priest2->GetGUID();
                            Priest2->GetMotionMaster()->MovePoint(0, Priest2Pos[1]);
                        }
                        if (Creature* Priest3 = DoSummon(NPC_ARGENT_BATTLE_PRIEST, Priest3Pos[0]))
                        {
                            guidPriest[2] = Priest3->GetGUID();
                            Priest3->GetMotionMaster()->MovePoint(0, Priest3Pos[1]);
                        }
                        if (Creature* Mason1 = DoSummon(NPC_ARGENT_MASON, Mason1Pos[0]))
                        {
                            guidMason[0] = Mason1->GetGUID();
                            Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[1]);
                        }
                        if (Creature* Mason2 = DoSummon(NPC_ARGENT_MASON, Mason2Pos[0]))
                        {
                            guidMason[1] = Mason2->GetGUID();
                            Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[1]);
                        }
                        if (Creature* Mason3 = DoSummon(NPC_ARGENT_MASON, Mason3Pos[0]))
                        {
                            guidMason[2] = Mason3->GetGUID();
                            Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[1]);
                        }
                        events.ScheduleEvent(EVENT_INTRO_1, 15000);
                    }
                    break;
                case EVENT_INTRO_1:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_SAY_PRE_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 5000);
                    }
                    break;
                case EVENT_INTRO_2:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                        {
                            Dalfors->SetFacingTo(6.215f);
                            Dalfors->AI()->Talk(DALFORS_SAY_PRE_2);
                        }
                    events.ScheduleEvent(EVENT_INTRO_3, 5000);
                    }
                    break;
                case EVENT_INTRO_3:
                    {
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                        {
                            Dalfors->GetMotionMaster()->MovePoint(0, DalforsPos[2]);
                            Dalfors->SetHomePosition(DalforsPos[2]);
                        }
                        if (Creature* Priest1 = me->GetCreature(*me, guidPriest[0]))
                        {
                            Priest1->SetFacingTo(5.7421f);
                            Priest1->SetHomePosition(Priest1Pos[1]);
                        }
                        if (Creature* Priest2 = me->GetCreature(*me, guidPriest[1]))
                        {
                            Priest2->SetFacingTo(5.7421f);
                            Priest2->SetHomePosition(Priest2Pos[1]);
                        }
                        if (Creature* Priest3 = me->GetCreature(*me, guidPriest[2]))
                        {
                            Priest3->SetFacingTo(5.7421f);
                            Priest3->SetHomePosition(Priest3Pos[1]);
                        }
                        if (Creature* Mason1 = me->GetCreature(*me, guidMason[0]))
                        {
                            Mason1->GetMotionMaster()->MovePoint(0, Mason1Pos[2]);
                            Mason1->SetHomePosition(Mason1Pos[2]);
                        }
                        if (Creature* Mason2 = me->GetCreature(*me, guidMason[1]))
                        {
                            Mason2->GetMotionMaster()->MovePoint(0, Mason2Pos[2]);
                            Mason2->SetHomePosition(Mason2Pos[2]);
                        }
                        if (Creature* Mason3 = me->GetCreature(*me, guidMason[2]))
                        {
                            Mason3->GetMotionMaster()->MovePoint(0, Mason3Pos[2]);
                            Mason3->SetHomePosition(Mason3Pos[2]);
                        }
                        events.ScheduleEvent(EVENT_START_FIGHT, 5000);
                        events.ScheduleEvent(EVENT_MASON_ACTION, 15000);
                    }
                    break;
                case EVENT_MASON_ACTION:
                    {
                        if (Creature* Mason1 = me->GetCreature(*me, guidMason[0]))
                        {
                            Mason1->SetFacingTo(2.8972f);
                            Mason1->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                        if (Creature* Mason2 = me->GetCreature(*me, guidMason[1]))
                        {
                            Mason2->SetFacingTo(3.1241f);
                            Mason2->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                        if (Creature* Mason3 = me->GetCreature(*me, guidMason[2]))
                        {
                            Mason3->SetFacingTo(3.6651f);
                            Mason3->AI()->SetData(1, 1); // triggers SAI actions on npc
                        }
                    }
                    break;
                case EVENT_START_FIGHT:
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_1);
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_SAY_START);
                        events.ScheduleEvent(EVENT_WAVE_SPAWN, 1000);
                    }
                    break;
                case EVENT_WAVE_SPAWN:
                    {
                        if (PhaseCount == 3)
                        {
                            if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                                LK->AI()->Talk(LK_TALK_2);
                        }
                        else if (PhaseCount == 6)
                        {
                            if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                                LK->AI()->Talk(LK_TALK_3);
                        }
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason3Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        if (urand(0, 1) == 0)
                        {
                            if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason1Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                            if (Creature* tempsum = DoSummon(NPC_HIDEOUS_PLAGEBRINGER, Mason2Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        }
                        else
                        {
                            if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason1Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                            if (Creature* tempsum = DoSummon(NPC_REANIMATED_CAPTAIN, Mason2Pos[0]))
                            {
                                tempsum->SetHomePosition(DalforsPos[2]);
                                tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                            }
                        }

                        PhaseCount++;

                        if (PhaseCount < 8)
                            events.ScheduleEvent(EVENT_WAVE_SPAWN, urand(10000, 20000));
                        else
                            events.ScheduleEvent(EVENT_HALOF, urand(10000, 20000));
                    }
                    break;
                case EVENT_HALOF:
                    {
                        if (Creature* LK = GetClosestCreatureWithEntry(me, NPC_LK, 100))
                            LK->AI()->Talk(LK_TALK_4);
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason1Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_SCOURGE_DRUDGE, Mason2Pos[0]))
                        {
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                        if (Creature* tempsum = DoSummon(NPC_HALOF_THE_DEATHBRINGER, DalforsPos[0]))
                        {
                            HalofSpawned = true;
                            guidHalof = tempsum->GetGUID();
                            tempsum->SetHomePosition(DalforsPos[2]);
                            tempsum->AI()->AttackStart(GetClosestCreatureWithEntry(me, NPC_BLESSED_BANNER, 100));
                        }
                    }
                    break;
                case EVENT_ENDED:
                    {
                        Summons.DespawnAll();
                        me->DespawnOrUnsummon();
                    }
                    break;
            }

            if (PhaseCount == 8)
                if (Creature* Halof = me->GetCreature(*me, guidHalof))
                    if (Halof->isDead())
                    {
                        DoCast(me, SPELL_CRUSADERS_SPIRE_VICTORY, true);
                        Summons.DespawnEntry(NPC_HIDEOUS_PLAGEBRINGER);
                        Summons.DespawnEntry(NPC_REANIMATED_CAPTAIN);
                        Summons.DespawnEntry(NPC_SCOURGE_DRUDGE);
                        Summons.DespawnEntry(NPC_HALOF_THE_DEATHBRINGER);
                        if (Creature* Dalfors = me->GetCreature(*me, guidDalfors))
                            Dalfors->AI()->Talk(DALFORS_YELL_FINISHED);
                        events.ScheduleEvent(EVENT_ENDED, 10000);
                    }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_blessed_bannerAI(creature);
    }
};

enum TrampleScourge
{
    SPELL_TRAMPLE_TRIGGERED = 63001,
    NPC_BONEGUARD_FOOTMAN   = 33438,
};

class spell_gen_trample_scourge : public SpellScriptLoader
{
    public:
        spell_gen_trample_scourge() : SpellScriptLoader("spell_gen_trample_scourge") { }

        class spell_gen_trample_scourge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_gen_trample_scourge_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                std::list<Creature*> footmen;
                GetCaster()->GetCreatureListWithEntryInGrid(footmen, NPC_BONEGUARD_FOOTMAN, 5.0f);
                footmen.sort(Trinity::ObjectDistanceOrderPred(caster));
                for (std::list<Creature*>::iterator itr = footmen.begin(); itr != footmen.end(); ++itr)
                {
                    Player* caster = GetCaster()->ToPlayer();
                    Unit* bfootmen = (*itr);
                    caster->CastSpell(bfootmen, SPELL_TRAMPLE_TRIGGERED, true);
                }
            }


            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_trample_scourge_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_gen_trample_scourge_AuraScript();
        }
};

/*######
## Borrowed Technology - Id: 13291, The Solution Solution (daily) - Id: 13292, Volatility - Id: 13239, Volatiliy - Id: 13261 (daily)
######*/

enum BorrowedTechnologyAndVolatility
{
    // Spells
    SPELL_GRAB             = 59318,
    SPELL_PING_BUNNY       = 59375,
    SPELL_IMMOLATION       = 54690,
    SPELL_EXPLOSION        = 59335,
    SPELL_RIDE             = 56687,

    // Points
    POINT_GRAB_DECOY       = 1,
    POINT_FLY_AWAY         = 2,

    // Events
    EVENT_FLY_AWAY         = 1
};

class npc_frostbrood_skytalon : public CreatureScript
{
    public:
        npc_frostbrood_skytalon() : CreatureScript("npc_frostbrood_skytalon") { }

        struct npc_frostbrood_skytalonAI : public VehicleAI
        {
            npc_frostbrood_skytalonAI(Creature* creature) : VehicleAI(creature) { }

            EventMap events;

            void IsSummonedBy(Unit* summoner)
            {
                me->GetMotionMaster()->MovePoint(POINT_GRAB_DECOY, summoner->GetPositionX(), summoner->GetPositionY(), summoner->GetPositionZ());
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == POINT_GRAB_DECOY)
                    if (TempSummon* summon = me->ToTempSummon())
                        if (Unit* summoner = summon->GetSummoner())
                            DoCast(summoner, SPELL_GRAB); 
            }

            void UpdateAI(uint32 diff)
            {
                VehicleAI::UpdateAI(diff);
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_FLY_AWAY)
                    {
                        Position randomPosOnRadius;
                        randomPosOnRadius.m_positionZ = (me->GetPositionZ() + 40.0f);
                        me->GetNearPoint2D(randomPosOnRadius.m_positionX, randomPosOnRadius.m_positionY, 40.0f, me->GetAngle(me));
                        me->GetMotionMaster()->MovePoint(POINT_FLY_AWAY, randomPosOnRadius);
                    }
                }
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
            {
                switch (spell->Id)
                {
                    case SPELL_EXPLOSION:
                        DoCast(me, SPELL_IMMOLATION);
                        break;
                    case SPELL_RIDE:
                        DoCastAOE(SPELL_PING_BUNNY);
                        events.ScheduleEvent(EVENT_FLY_AWAY, 100);
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_frostbrood_skytalonAI(creature);
        }
};

void AddSC_icecrown()
{
    new npc_arete;
    new npc_argent_squire;
    new npc_argent_combatant;
    new npc_argent_faction_rider;
    new npc_argent_valiant;
    new npc_guardian_pavilion;
    new npc_vereth_the_cunning;
    new npc_tournament_training_dummy;
    new npc_black_knights_grave;
    new npc_boneguard_mounted;
    new spell_gen_trample_scourge;
    new npc_blessed_banner();
    new npc_frostbrood_skytalon();
}
