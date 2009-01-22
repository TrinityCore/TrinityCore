/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDComment: Quest support: 10519, 10583, 10601, 10814, 10804, 10854, 11082, 10451. Vendor Drake Dealer Hurlunk.
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
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*#####
# mob_mature_netherwing_drake
#####*/

#define SPELL_PLACE_CARCASS             38439
#define SPELL_JUST_EATEN                38502
#define SPELL_NETHER_BREATH             38467

#define SAY_JUST_EATEN                  -1000222

struct TRINITY_DLL_DECL mob_mature_netherwing_drakeAI : public ScriptedAI
{
    mob_mature_netherwing_drakeAI(Creature* c) : ScriptedAI(c)
    {
        Reset();
        PlayerGUID = 0;
    }

    uint64 PlayerGUID;

    bool IsEating;
    bool Evade;

    uint32 ResetTimer;
    uint32 CastTimer;
    uint32 EatTimer;

    void Reset()
    {
        IsEating = false;
        Evade = false;

        ResetTimer = 120000;
        EatTimer = 5000;
        CastTimer = 5000;
    }

    void Aggro(Unit* who) { }

    void MoveInLineOfSight(Unit* who)
    {
        if(m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if(!caster)
            return;

        if(caster->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_PLACE_CARCASS && !m_creature->HasAura(SPELL_JUST_EATEN, 0) && !PlayerGUID)
        {
            float PlayerX, PlayerY, PlayerZ;
            caster->GetClosePoint(PlayerX, PlayerY, PlayerZ, m_creature->GetObjectSize());
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->GetMotionMaster()->MovePoint(1, PlayerX, PlayerY, PlayerZ);
            PlayerGUID = caster->GetGUID();
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if(id == 1)
        {
            IsEating = true;
            EatTimer = 5000;
            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_ATTACKUNARMED);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(IsEating)
            if(EatTimer < diff)
        {
            IsEating = false;
            DoCast(m_creature, SPELL_JUST_EATEN);
            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_NONE);
            DoScriptText(SAY_JUST_EATEN, m_creature);
            if(PlayerGUID)
            {
                Player* plr = ((Player*)Unit::GetUnit((*m_creature), PlayerGUID));
                if(plr && plr->GetQuestStatus(10804) == QUEST_STATUS_INCOMPLETE)
                {
                    plr->KilledMonster(22131, m_creature->GetGUID());
                    Evade = true;
                    PlayerGUID = 0;
                }
            }
        }else EatTimer -= diff;

        if(Evade)
            if(ResetTimer < diff)
                EnterEvadeMode();
        else ResetTimer -= diff;

        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(CastTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_NETHER_BREATH);
            CastTimer = 5000;
        }else CastTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_mature_netherwing_drake(Creature *_creature)
{
    return new mob_mature_netherwing_drakeAI(_creature);
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

struct TRINITY_DLL_DECL mob_enslaved_netherwing_drakeAI : public ScriptedAI
{
    mob_enslaved_netherwing_drakeAI(Creature* c) : ScriptedAI(c)
    {
        Reset();
        PlayerGUID = 0;
        Tapped = false;
    }

    uint64 PlayerGUID;
    uint32 FlyTimer;
    bool Tapped;

    void Reset()
    {
        if(!Tapped)
            m_creature->setFaction(FACTION_DEFAULT);

        FlyTimer = 10000;
        m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
        m_creature->SetVisibility(VISIBILITY_ON);
    }

    void Aggro(Unit* who) { }

    Creature* SelectCreatureInGrid(uint32 entry, float range)
    {
        Creature* pCreature = NULL;

        // Time for some omg mind blowing code to search for creature
        CellPair pair(Trinity::ComputeCellPair(m_creature->GetPositionX(), m_creature->GetPositionY()));
        Cell cell(pair);
        cell.data.Part.reserved = ALL_DISTRICT;
        cell.SetNoCreate();

        Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck creature_check(*m_creature, entry, true, range);
        Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck> searcher(pCreature, creature_check);

        TypeContainerVisitor<Trinity::CreatureLastSearcher<Trinity::NearestCreatureEntryWithLiveStateInObjectRangeCheck>, GridTypeMapContainer> creature_searcher(searcher);

        CellLock<GridReadGuard> cell_lock(cell, pair);
        cell_lock->Visit(cell_lock, creature_searcher,*(m_creature->GetMap()));

        return pCreature;
    }

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if(!caster)
            return;

        if(caster->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_HIT_FORCE_OF_NELTHARAKU && !Tapped)
        {
            Tapped = true;
            PlayerGUID = caster->GetGUID();

            m_creature->setFaction(FACTION_FRIENDLY);
            DoCast(caster, SPELL_FORCE_OF_NELTHARAKU, true);

            Creature* Dragonmaw = SelectCreatureInGrid(CREATURE_DRAGONMAW_SUBJUGATOR, 50);

            if(Dragonmaw)
            {
                m_creature->AddThreat(Dragonmaw, 100000.0f);
                AttackStart(Dragonmaw);
            }

            HostilReference* ref = m_creature->getThreatManager().getOnlineContainer().getReferenceByTarget(caster);
            if(ref)
                ref->removeReference();
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if(id == 1)
        {
            if(PlayerGUID)
            {
                Unit* plr = Unit::GetUnit((*m_creature), PlayerGUID);
                if(plr)
                    DoCast(plr, SPELL_FORCE_OF_NELTHARAKU, true);

                PlayerGUID = 0;
            }
            m_creature->SetVisibility(VISIBILITY_OFF);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
        {
            if(Tapped)
                if(FlyTimer < diff)
            {
                Tapped = false;
                if(PlayerGUID)
                {
                    Player* plr = ((Player*)Unit::GetUnit((*m_creature), PlayerGUID));
                    if(plr && plr->GetQuestStatus(10854) == QUEST_STATUS_INCOMPLETE)
                    {
                        plr->KilledMonster(22316, m_creature->GetGUID());
                        /*
                        float x,y,z;
                        m_creature->GetPosition(x,y,z);

                        float dx,dy,dz;
                        m_creature->GetRandomPoint(x, y, z, 20, dx, dy, dz);
                        dz += 20; // so it's in the air, not ground*/

                        float dx, dy, dz;

                        Creature* EscapeDummy = SelectCreatureInGrid(CREATURE_ESCAPE_DUMMY, 30);
                        if(EscapeDummy)
                            EscapeDummy->GetPosition(dx, dy, dz);
                        else
                        {
                            m_creature->GetRandomPoint(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 20, dx, dy, dz);
                            dz += 25;
                        }

                        m_creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                        m_creature->GetMotionMaster()->MovePoint(1, dx, dy, dz);
                    }
                }
            }else FlyTimer -= diff;
            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_enslaved_netherwing_drake(Creature* _Creature)
{
    return new mob_enslaved_netherwing_drakeAI(_Creature);
}

/*#####
# mob_dragonmaw_peon
#####*/

struct TRINITY_DLL_DECL mob_dragonmaw_peonAI : public ScriptedAI
{
    mob_dragonmaw_peonAI(Creature* c) : ScriptedAI(c)
    {
        Reset();
    }

    uint64 PlayerGUID;
    bool Tapped;
    uint32 PoisonTimer;

    void Reset()
    {
        PlayerGUID = 0;
        Tapped = false;
        PoisonTimer = 0;
    }

    void Aggro(Unit* who) { }

    void SpellHit(Unit* caster, const SpellEntry* spell)
    {
        if(!caster)
            return;

        if(caster->GetTypeId() == TYPEID_PLAYER && spell->Id == 40468 && !Tapped)
        {
            PlayerGUID = caster->GetGUID();

            Tapped = true;
            float x, y, z;
            caster->GetClosePoint(x, y, z, m_creature->GetObjectSize());

            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
            m_creature->GetMotionMaster()->MovePoint(1, x, y, z);
        }
    }

    void MovementInform(uint32 type, uint32 id)
    {
        if(type != POINT_MOTION_TYPE)
            return;

        if(id)
        {
            m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_EAT);
            PoisonTimer = 15000;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(PoisonTimer)
            if(PoisonTimer <= diff)
        {
            if(PlayerGUID)
            {
                Player* plr = ((Player*)Unit::GetUnit((*m_creature), PlayerGUID));
                if(plr && plr->GetQuestStatus(11020) == QUEST_STATUS_INCOMPLETE)
                    plr->KilledMonster(23209, m_creature->GetGUID());
            }
            PoisonTimer = 0;
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        }else PoisonTimer -= diff;
    }
};

CreatureAI* GetAI_mob_dragonmaw_peon(Creature* _Creature)
{
    return new mob_dragonmaw_peonAI(_Creature);
}

/*######
## npc_drake_dealer_hurlunk
######*/

bool GossipHello_npc_drake_dealer_hurlunk(Player *player, Creature *_Creature)
{
    if (_Creature->isVendor() && player->GetReputationRank(1015) == REP_EXALTED)
        player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_drake_dealer_hurlunk(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_TRADE)
        player->SEND_VENDORLIST( _Creature->GetGUID() );

    return true;
}

/*######
## npc_flanis_swiftwing_and_kagrosh
######*/

bool GossipHello_npcs_flanis_swiftwing_and_kagrosh(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(10583) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(30658,1,true))
        player->ADD_GOSSIP_ITEM( 0, "Take Flanis's Pack", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    if (player->GetQuestStatus(10601) == QUEST_STATUS_INCOMPLETE && !player->HasItemCount(30659,1,true))
        player->ADD_GOSSIP_ITEM( 0, "Take Kagrosh's Pack", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npcs_flanis_swiftwing_and_kagrosh(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, 30658, 1, false);
        if( msg == EQUIP_ERR_OK )
        {
            player->StoreNewItem( dest, 30658, 1, true);
            player->PlayerTalkClass->ClearMenus();
        }
    }
    if (action == GOSSIP_ACTION_INFO_DEF+2)
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem( NULL_BAG, NULL_SLOT, dest, 30659, 1, false);
        if( msg == EQUIP_ERR_OK )
        {
            player->StoreNewItem( dest, 30659, 1, true);
            player->PlayerTalkClass->ClearMenus();
        }
    }
    return true;
}

/*######
## npc_murkblood_overseer
######*/

#define QUEST_11082     11082

bool GossipHello_npc_murkblood_overseer(Player *player, Creature *_Creature)
{
    if (player->GetQuestStatus(QUEST_11082) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "I am here for you, overseer.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_murkblood_overseer(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(0, "How dare you question an overseer of the Dragonmaw!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(0, "Who speaks of me? What are you talking about, broken?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM(0, "Continue please.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM(0, "Who are these bidders?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM(0, "Well... yes.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
                                                            //correct id not known
            player->SEND_GOSSIP_MENU(10940, _Creature->GetGUID());
            _Creature->CastSpell(player,41121,false);
            player->AreaExploredOrEventHappens(QUEST_11082);
            break;
    }
    return true;
}

/*######
## npc_neltharaku
######*/

bool GossipHello_npc_neltharaku(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );

    if (player->GetQuestStatus(10814) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM( 0, "I am listening, dragon", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(10613, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_neltharaku(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "But you are dragons! How could orcs do this to you?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(10614, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, "Your mate?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(10615, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM( 0, "I have battled many beasts, dragon. I will help you.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(10616, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(10814);
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

bool GossipHello_npc_oronok_tornheart(Player *player, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        player->PrepareQuestMenu( _Creature->GetGUID() );
    if (_Creature->isVendor())
        player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    if (player->GetQuestStatus(10519) == QUEST_STATUS_INCOMPLETE)
    {
        player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
        player->SEND_GOSSIP_MENU(10312, _Creature->GetGUID());
    }else
    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_oronok_tornheart(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch (action)
    {
        case GOSSIP_ACTION_TRADE:
            player->SEND_VENDORLIST( _Creature->GetGUID() );
            break;
        case GOSSIP_ACTION_INFO_DEF:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(10313, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->SEND_GOSSIP_MENU(10314, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->SEND_GOSSIP_MENU(10315, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
            player->SEND_GOSSIP_MENU(10316, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
            player->SEND_GOSSIP_MENU(10317, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            player->ADD_GOSSIP_ITEM( 0, GOSSIP_ORONOK7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
            player->SEND_GOSSIP_MENU(10318, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            player->CLOSE_GOSSIP_MENU();
            player->AreaExploredOrEventHappens(10519);
            break;
    }
    return true;
}

/*####
# npc_karynaku
####*/

bool QuestAccept_npc_karynaku(Player* player, Creature* creature, Quest const* quest)
{
    if(quest->GetQuestId() == 10870)                        // Ally of the Netherwing
    {
        std::vector<uint32> nodes;

        nodes.resize(2);
        nodes[0] = 161;                                     // From Karynaku
        nodes[1] = 162;                                     // To Mordenai
        error_log("SD2: Player %s started quest 10870 which has disabled taxi node, need to be fixed in core", player->GetName());
        //player->ActivateTaxiPathTo(nodes, 20811);
    }

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

#define OVERLORD_SAY_1 -1000206
#define OVERLORD_SAY_2 -1000207
#define OVERLORD_SAY_3 -1000208
#define OVERLORD_SAY_4 -1000209
#define OVERLORD_SAY_5 -1000210
#define OVERLORD_SAY_6 -1000211

#define OVERLORD_YELL_1 -1000212
#define OVERLORD_YELL_2 -1000213

#define LORD_ILLIDAN_SAY_1 -1000214
#define LORD_ILLIDAN_SAY_2 -1000215
#define LORD_ILLIDAN_SAY_3 -1000216
#define LORD_ILLIDAN_SAY_4 -1000217
#define LORD_ILLIDAN_SAY_5 -1000218
#define LORD_ILLIDAN_SAY_6 -1000219
#define LORD_ILLIDAN_SAY_7 -1000220

#define YARZILL_THE_MERC_SAY -1000221

struct TRINITY_DLL_DECL npc_overlord_morghorAI : public ScriptedAI
{
    npc_overlord_morghorAI(Creature *c) : ScriptedAI(c) {Reset();}

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
    }

    void Aggro(Unit* who){}

    void StartEvent()
    {
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, 0);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);                
        Unit* Illidan = m_creature->SummonCreature(C_ILLIDAN, -5107.83, 602.584, 85.2393, 4.92598, TEMPSUMMON_CORPSE_DESPAWN, 0);
        IllidanGUID = Illidan->GetGUID();
        Illidan->SetVisibility(VISIBILITY_OFF);
        if(PlayerGUID)
        {
            Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);
            DoScriptText(OVERLORD_SAY_1, m_creature, player);         
        }
        ConversationTimer = 4200;
        Step = 0;
        Event = true;
    }

    uint32 NextStep(uint32 Step)
    {
        Unit* plr = Unit::GetUnit((*m_creature), PlayerGUID);        

        Unit* Illi = Unit::GetUnit((*m_creature), IllidanGUID);

        switch(Step)
        {
        case 0: return 0; break;
        case 1: m_creature->GetMotionMaster()->MovePoint(0, -5104.41, 595.297, 85.6838); return 9000; break;    
        case 2: DoScriptText(OVERLORD_YELL_1, m_creature, plr); return 4500; break;                    
        case 3: m_creature->SetInFront(plr); return 3200;  break;
        case 4: DoScriptText(OVERLORD_SAY_2, m_creature, plr); return 2000; break;
        case 5: Illi->SetVisibility(VISIBILITY_ON); return 350; break;
        case 6:
            Illi->CastSpell(Illi, SPELL_ONE, true);
            Illi->SetUInt64Value(UNIT_FIELD_TARGET, m_creature->GetGUID());
            m_creature->SetUInt64Value(UNIT_FIELD_TARGET, IllidanGUID);
            return 2000; break;                    
        case 7: DoScriptText(OVERLORD_YELL_2, m_creature); return 4500; break;                    
        case 8: m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 8); return 2500; break;                    
        case 9: DoScriptText(OVERLORD_SAY_3, m_creature); return 6500; break;                    
        case 10: DoScriptText(LORD_ILLIDAN_SAY_1, Illi); return 5000;  break;                    
        case 11: DoScriptText(OVERLORD_SAY_4, m_creature, plr); return 6000; break;
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
                ((Player*)plr)->FailQuest(QUEST_LORD_ILLIDAN_STORMRAGE); Step = 30; return 100;
            }break;                    
        case 17: DoScriptText(LORD_ILLIDAN_SAY_5, Illi); return 5000; break;                    
        case 18: DoScriptText(LORD_ILLIDAN_SAY_6, Illi); return 5000; break;                    
        case 19: DoScriptText(LORD_ILLIDAN_SAY_7, Illi); return 5000; break;                    
        case 20: 
            Illi->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
            Illi->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
            return 500; break;                  
        case 21: DoScriptText(OVERLORD_SAY_5, m_creature); return 500; break;                    
        case 22: 
            Illi->SetVisibility(VISIBILITY_OFF);
            Illi->setDeathState(JUST_DIED);                    
            return 1000; break;            
        case 23: m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0); return 2000; break;                    
        case 24: m_creature->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID); return 5000; break;
        case 25: DoScriptText(OVERLORD_SAY_6, m_creature); return 2000; break;                    
        case 26: ((Player*)plr)->CompleteQuest(QUEST_LORD_ILLIDAN_STORMRAGE); return 6000; break;                    
        case 27:
            {
            Unit* Yarzill = FindCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
            return 500; }break;            
        case 28:
            plr->RemoveAurasDueToSpell(SPELL_TWO);
            plr->RemoveAurasDueToSpell(41519);
            plr->CastSpell(plr, SPELL_THREE, true);
            plr->CastSpell(plr, SPELL_FOUR, true);
            return 1000; break;           
        case 29:
            {
            Unit* Yarzill = FindCreature(C_YARZILL, 50);
            if(Yarzill)
                DoScriptText(YARZILL_THE_MERC_SAY, Yarzill, plr);
            return 5000; }break;
        case 30:
            {
            Unit* Yarzill = FindCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, 0);
            return 5000; }break;
        case 31:
            {
            Unit* Yarzill = FindCreature(C_YARZILL, 50);
            if (Yarzill)
                Yarzill->CastSpell(plr, 41540, true);             
            return 1000;}break;
        case 32: m_creature->GetMotionMaster()->MovePoint(0, -5085.77, 577.231, 86.6719); return 5000; break;                    
        case 33: Reset(); return 100; break;

        default : return 9999999;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(ConversationTimer < diff)
        {
            if(Event && IllidanGUID && PlayerGUID)
            {
                ConversationTimer = NextStep(++Step);
            }
        }else ConversationTimer -= diff;
    }
};

CreatureAI* GetAI_npc_overlord_morghorAI(Creature *_Creature)
{
return new npc_overlord_morghorAI(_Creature);
}

bool QuestAccept_npc_overlord_morghor(Player *player, Creature *_Creature, const Quest *_Quest )
{
	if(_Quest->GetQuestId() == QUEST_LORD_ILLIDAN_STORMRAGE)
	{
        ((npc_overlord_morghorAI*)_Creature->AI())->PlayerGUID = player->GetGUID();
        ((npc_overlord_morghorAI*)_Creature->AI())->StartEvent();        
		return true;
	}
	return false;
}

/*####
# npc_earthmender_wilda
####*/

#define SAY_START -1000223
#define SAY_AGGRO1 -1000224
#define SAY_AGGRO2 -1000225
#define ASSASSIN_SAY_AGGRO1 -1000226
#define ASSASSIN_SAY_AGGRO2 -1000227
#define SAY_PROGRESS1 -1000228
#define SAY_PROGRESS2 -1000229
#define SAY_PROGRESS3 -1000230
#define SAY_PROGRESS4 -1000231
#define SAY_PROGRESS5 -1000232
#define SAY_PROGRESS6 -1000233
#define SAY_END -1000234

#define QUEST_ESCAPE_FROM_COILSKAR_CISTERN 10451
#define NPC_COILSKAR_ASSASSIN 21044

struct TRINITY_DLL_DECL npc_earthmender_wildaAI : public npc_escortAI
{
    npc_earthmender_wildaAI(Creature *c) : npc_escortAI(c) {Reset();}

    bool Completed;

    void Aggro(Unit *who)
    {
        Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

        if(who->GetTypeId() == TYPEID_UNIT && who->GetEntry() == NPC_COILSKAR_ASSASSIN)
            DoScriptText(SAY_AGGRO2, m_creature, player);
        else DoScriptText(SAY_AGGRO1, m_creature, player);
    }

    void Reset()
    {
        m_creature->setFaction(1726);
        Completed = false;
    }

    void WaypointReached(uint32 i)
    {
        Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

        if (!player)
            return;

        switch(i)
        {
               case 0: DoScriptText(SAY_START, m_creature, player); break;
               case 13: DoScriptText(SAY_PROGRESS1, m_creature, player);
                   SummonAssassin();
                   break;
               case 14: SummonAssassin(); break;
               case 15: DoScriptText(SAY_PROGRESS3, m_creature, player); break;
               case 19: 
                   switch(rand()%3)
                   {
                   case 0: DoScriptText(SAY_PROGRESS2, m_creature, player); break;
                   case 1: DoScriptText(SAY_PROGRESS4, m_creature, player); break;
                   case 2: DoScriptText(SAY_PROGRESS5, m_creature, player); break;
                   }
                   break;
               case 20: SummonAssassin(); break;
               case 26:
                   switch(rand()%3)
                   {
                   case 0: DoScriptText(SAY_PROGRESS2, m_creature, player); break;
                   case 1: DoScriptText(SAY_PROGRESS4, m_creature, player); break;
                   case 2: DoScriptText(SAY_PROGRESS5, m_creature, player); break;
                   }
                   break;
               case 27: SummonAssassin(); break;
               case 33:
                   switch(rand()%3)
                   {
                   case 0: DoScriptText(SAY_PROGRESS2, m_creature, player); break;
                   case 1: DoScriptText(SAY_PROGRESS4, m_creature, player); break;
                   case 2: DoScriptText(SAY_PROGRESS5, m_creature, player); break;
                   }
                   break;
               case 34: SummonAssassin(); break;
               case 37:
                   switch(rand()%3)
                   {
                   case 0: DoScriptText(SAY_PROGRESS2, m_creature, player); break;
                   case 1: DoScriptText(SAY_PROGRESS4, m_creature, player); break;
                   case 2: DoScriptText(SAY_PROGRESS5, m_creature, player); break;
                   }
                   break;
               case 38: SummonAssassin(); break;
               case 39: DoScriptText(SAY_PROGRESS6, m_creature, player); break;
               case 43:
                   switch(rand()%3)
                   {
                   case 0: DoScriptText(SAY_PROGRESS2, m_creature, player); break;
                   case 1: DoScriptText(SAY_PROGRESS4, m_creature, player); break;
                   case 2: DoScriptText(SAY_PROGRESS5, m_creature, player); break;
                   }
                   break;
               case 44: SummonAssassin(); break;
               case 50: 
                   DoScriptText(SAY_END, m_creature, player);
                   ((Player*)player)->GroupEventHappens(QUEST_ESCAPE_FROM_COILSKAR_CISTERN, m_creature);
                   Completed = true;
                   break;
               }
       }

       void SummonAssassin()
       {
           Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);

           Unit* CoilskarAssassin = m_creature->SummonCreature(NPC_COILSKAR_ASSASSIN, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation(), TEMPSUMMON_DEAD_DESPAWN, 0);
           if( CoilskarAssassin )
           {
               switch(rand()%2)
               {
               case 0: DoScriptText(ASSASSIN_SAY_AGGRO1, CoilskarAssassin, player); break;
               case 1: DoScriptText(ASSASSIN_SAY_AGGRO2, CoilskarAssassin, player); break;
               }
               ((Creature*)CoilskarAssassin)->AI()->AttackStart(m_creature);
           }
           else error_log("SD2 ERROR: Coilskar Assassin couldn't be summmoned");
       }

       void JustDied(Unit* killer)
       {
           if (PlayerGUID && !Completed)
           {
               Unit* player = Unit::GetUnit((*m_creature), PlayerGUID);
               if (player)
                   ((Player*)player)->FailQuest(QUEST_ESCAPE_FROM_COILSKAR_CISTERN);
           }
       }

       void UpdateAI(const uint32 diff) 
       {
               npc_escortAI::UpdateAI(diff);
       }
};

CreatureAI* GetAI_npc_earthmender_wildaAI(Creature *_Creature)
{
    npc_earthmender_wildaAI* earthmender_wildaAI = new npc_earthmender_wildaAI(_Creature);

       earthmender_wildaAI->AddWaypoint(0, -2637.466064, 1359.977905, 35.889114, 2000); // SAY_START
       earthmender_wildaAI->AddWaypoint(1, -2666.364990, 1348.222656, 34.445557);
       earthmender_wildaAI->AddWaypoint(2, -2693.789307, 1336.964966, 34.445557);
       earthmender_wildaAI->AddWaypoint(3, -2715.495361, 1328.054443, 34.106014);
       earthmender_wildaAI->AddWaypoint(4, -2742.530762, 1314.138550, 33.606144);
       earthmender_wildaAI->AddWaypoint(5, -2745.077148, 1311.108765, 33.630898);
       earthmender_wildaAI->AddWaypoint(6, -2749.855225, 1302.737915, 33.475632);
       earthmender_wildaAI->AddWaypoint(7, -2753.639648, 1294.059448, 33.314930);
       earthmender_wildaAI->AddWaypoint(8, -2756.796387, 1285.122192, 33.391262);
       earthmender_wildaAI->AddWaypoint(9, -2750.042969, 1273.661987, 33.188259);
       earthmender_wildaAI->AddWaypoint(10, -2740.378418, 1258.846680, 33.212521);
       earthmender_wildaAI->AddWaypoint(11, -2733.629395, 1248.259766, 33.640598);
       earthmender_wildaAI->AddWaypoint(12, -2727.212646, 1238.606445, 33.520847);
       earthmender_wildaAI->AddWaypoint(13, -2726.377197, 1237.264526, 33.461823, 4000); // SAY_PROGRESS1
       earthmender_wildaAI->AddWaypoint(14, -2746.383301, 1266.390625, 33.191952, 2000);
       earthmender_wildaAI->AddWaypoint(15, -2746.383301, 1266.390625, 33.191952, 4000); // SAY_PROGRESS3
       earthmender_wildaAI->AddWaypoint(16, -2758.927734, 1285.134155, 33.341728);
       earthmender_wildaAI->AddWaypoint(17, -2761.845703, 1292.313599, 33.209042);
       earthmender_wildaAI->AddWaypoint(18, -2758.871826, 1300.677612, 33.285332);
       earthmender_wildaAI->AddWaypoint(19, -2758.871826, 1300.677612, 33.285332);
       earthmender_wildaAI->AddWaypoint(20, -2753.928955, 1307.755859, 33.452457);
       earthmender_wildaAI->AddWaypoint(20, -2738.612061, 1316.191284, 33.482975);
       earthmender_wildaAI->AddWaypoint(21, -2727.897461, 1320.013916, 33.381111);
       earthmender_wildaAI->AddWaypoint(22, -2709.458740, 1315.739990, 33.301838);
       earthmender_wildaAI->AddWaypoint(23, -2704.658936, 1301.620361, 32.463303);
       earthmender_wildaAI->AddWaypoint(24, -2704.120117, 1298.922607, 32.768162);
       earthmender_wildaAI->AddWaypoint(25, -2691.798340, 1292.846436, 33.852642);
       earthmender_wildaAI->AddWaypoint(26, -2682.879639, 1288.853882, 32.995399);
       earthmender_wildaAI->AddWaypoint(27, -2661.869141, 1279.682495, 26.686783);
       earthmender_wildaAI->AddWaypoint(28, -2648.943604, 1270.272827, 24.147522);
       earthmender_wildaAI->AddWaypoint(29, -2642.506836, 1262.938721, 23.512444);
       earthmender_wildaAI->AddWaypoint(20, -2636.984863, 1252.429077, 20.418257);
       earthmender_wildaAI->AddWaypoint(31, -2648.113037, 1224.984863, 8.691818);
       earthmender_wildaAI->AddWaypoint(32, -2658.393311, 1200.136719, 5.492243);
       earthmender_wildaAI->AddWaypoint(33, -2668.504395, 1190.450562, 3.127407);
       earthmender_wildaAI->AddWaypoint(34, -2685.930420, 1174.360840, 5.163924);
       earthmender_wildaAI->AddWaypoint(35, -2701.613770, 1160.026367, 5.611311);
       earthmender_wildaAI->AddWaypoint(36, -2714.659668, 1149.980347, 4.342373);
       earthmender_wildaAI->AddWaypoint(37, -2721.443359, 1145.002808, 1.913474);
       earthmender_wildaAI->AddWaypoint(38, -2733.962158, 1143.436279, 2.620415);
       earthmender_wildaAI->AddWaypoint(39, -2757.876709, 1146.937500, 6.184002, 2000); // SAY_PROGRESS6
       earthmender_wildaAI->AddWaypoint(40, -2772.300537, 1166.052734, 6.331811);
       earthmender_wildaAI->AddWaypoint(41, -2790.265381, 1189.941650, 5.207958);
       earthmender_wildaAI->AddWaypoint(42, -2805.448975, 1208.663940, 5.557623);
       earthmender_wildaAI->AddWaypoint(43, -2820.617676, 1225.870239, 6.266103);
       earthmender_wildaAI->AddWaypoint(44, -2831.926758, 1237.725830, 5.808506);
       earthmender_wildaAI->AddWaypoint(45, -2842.578369, 1252.869629, 6.807481);
       earthmender_wildaAI->AddWaypoint(46, -2846.344971, 1258.727295, 7.386168);
       earthmender_wildaAI->AddWaypoint(47, -2847.556396, 1266.771729, 8.208790);
       earthmender_wildaAI->AddWaypoint(48, -2841.654541, 1285.809204, 7.933223);
       earthmender_wildaAI->AddWaypoint(49, -2841.754883, 1289.832520, 6.990304);
       earthmender_wildaAI->AddWaypoint(50, -2871.398438, 1302.348145, 6.807335, 8000); // SAY_END

       return (CreatureAI*)earthmender_wildaAI;
}

bool QuestAccept_npc_earthmender_wilda(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_ESCAPE_FROM_COILSKAR_CISTERN)
    {
        creature->setFaction(113);
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
    }
    return true;
}

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
    newscript->Name="npc_drake_dealer_hurlunk";
    newscript->pGossipHello =  &GossipHello_npc_drake_dealer_hurlunk;
    newscript->pGossipSelect = &GossipSelect_npc_drake_dealer_hurlunk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npcs_flanis_swiftwing_and_kagrosh";
    newscript->pGossipHello =  &GossipHello_npcs_flanis_swiftwing_and_kagrosh;
    newscript->pGossipSelect = &GossipSelect_npcs_flanis_swiftwing_and_kagrosh;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_murkblood_overseer";
    newscript->pGossipHello =  &GossipHello_npc_murkblood_overseer;
    newscript->pGossipSelect = &GossipSelect_npc_murkblood_overseer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_neltharaku";
    newscript->pGossipHello =  &GossipHello_npc_neltharaku;
    newscript->pGossipSelect = &GossipSelect_npc_neltharaku;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_karynaku";
    newscript->pQuestAccept = &QuestAccept_npc_karynaku;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_oronok_tornheart";
    newscript->pGossipHello =  &GossipHello_npc_oronok_tornheart;
    newscript->pGossipSelect = &GossipSelect_npc_oronok_tornheart;
    newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "npc_overlord_morghor";
	newscript->GetAI = &GetAI_npc_overlord_morghorAI;
	newscript->pQuestAccept = &QuestAccept_npc_overlord_morghor;
	newscript->RegisterSelf();

	newscript = new Script;
    newscript->Name = "npc_earthmender_wilda";
    newscript->GetAI = &GetAI_npc_earthmender_wildaAI;
    newscript->pQuestAccept = &QuestAccept_npc_earthmender_wilda;
    newscript->RegisterSelf();
}
