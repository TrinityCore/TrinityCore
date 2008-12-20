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
SDComment: Quest support: 10519, 10583, 10601, 10814, 10804, 10854, 11082. Vendor Drake Dealer Hurlunk.
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
EndContentData */

#include "precompiled.h"

/*#####
# mob_mature_netherwing_drake
#####*/

#define SPELL_PLACE_CARCASS             38439
#define SPELL_JUST_EATEN                38502
#define SPELL_NETHER_BREATH             38467

#define SAY_JUST_EATEN                  "Thank you, mortal."

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
            DoSay(SAY_JUST_EATEN, LANG_DRACONIC, NULL);
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
# quest_lord_illidan_stormrage
####*/
#define QUEST_LORD_ILLIDAN_STORMRAGE 11108
#define LORD_ILLIDAN_STORMRAGE 22083

#define SPELL_ONE 39990 // Red Lightning Bolt
#define SPELL_TWO 41528 // Mark of Stormrage
#define SPELL_THREE 40216 // Dragonaw Faction
#define SPELL_FOUR 42016 // Dragonaw Trasform

#define OVERLORD_SAY_1 "Come, $N. Lord Stormrage awaits."
#define OVERLORD_SAY_2 "Lord Illidan will be here shortly."
#define OVERLORD_SAY_3 "Lord Illidan, this is the Dragonmaw that I, and others, have told you about. He will lead us to victory!"
#define OVERLORD_SAY_4 "But... My lord, I do not understand. $N... He is the orc that has..."
#define OVERLORD_SAY_5 "It will be done, my lord."
#define OVERLORD_SAY_6 "So you thought to make a fool of Mor'ghor, eh? Before you are delivered to Lord Illidan, you will feel pain that you could not know to exist. I will take pleasure in exacting my own vengeance."

#define OVERLORD_YELL_1 "Warriors of Dragonmaw, gather 'round! One among you has attained the rank of highlord! Bow your heads in reverence! Show your respect and allegiance to Highlord $N!"
#define OVERLORD_YELL_2 "All hail Lord Illidan!"

#define LORD_ILLIDAN_SAY_1 "What is the meaning of this, Mor'ghor?"
#define LORD_ILLIDAN_SAY_2 "SILENCE!"
#define LORD_ILLIDAN_SAY_3 "Blathering idiot. You incomprehensibly incompetent buffoon..."
#define LORD_ILLIDAN_SAY_4 "THIS is your hero?"
#define LORD_ILLIDAN_SAY_5 "You have been deceived, imbecile."
#define LORD_ILLIDAN_SAY_6 "This... whole... operation... HAS BEEN COMPROMISED!"
#define LORD_ILLIDAN_SAY_7 "I expect to see this insect's carcass in pieces in my lair within the hour. Fail and you will suffer a fate so much worse than death."

#define YARZILL_THE_MERC_SAY "You will not harm the boy, Mor'ghor! Quickly, $N, climb on my back!"

#define GOSSIP_FLY "Lets Do! <MISSING TEXT>"

bool GossipHello_npc_yarzill_fly(Player *player, Creature *_Creature)
{
	if (player->GetQuestStatus(QUEST_LORD_ILLIDAN_STORMRAGE) == QUEST_STATUS_COMPLETE)
	{
		player->ADD_GOSSIP_ITEM(0, GOSSIP_FLY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->SEND_GOSSIP_MENU(3961,_Creature->GetGUID());
		return true;
	}else{
		return false;
	}
}

bool GossipSelect_npc_yarzill_fly(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
	if (action == GOSSIP_ACTION_INFO_DEF + 1)
	{
		std::vector<uint32> nodes;
		nodes.resize(2);
		nodes[0] = 173;
		nodes[1] = 174;
		error_log("SD2: Player %s started quest 11108 which has disabled taxi node, need to be fixed in core", player->GetName());
		//player->ActivateTaxiPathTo(nodes, 23468);
		return true;
	}
	return false;
}

struct TRINITY_DLL_DECL Yarzill_The_MercAI : public ScriptedAI
{
	Yarzill_The_MercAI(Creature *c) : ScriptedAI(c) {Reset();}

void Reset(){}

void Aggro(Unit *who){}

void DoSpeach(Unit *target)
{
DoSay(YARZILL_THE_MERC_SAY,LANG_UNIVERSAL,target);
}
};

struct TRINITY_DLL_DECL Lord_IllidanAI : public ScriptedAI
{
Lord_IllidanAI(Creature *c) : ScriptedAI(c) {Reset();}

void Reset(){}

void Aggro(Unit *who){}

void DoSpeach(int phase)
{
	switch(phase)
	{
	case 1:
		DoSay(LORD_ILLIDAN_SAY_1,LANG_UNIVERSAL,NULL);
		break;
	case 2:
		DoSay(LORD_ILLIDAN_SAY_2,LANG_UNIVERSAL,NULL);
		break;
	case 3:
		DoSay(LORD_ILLIDAN_SAY_3,LANG_UNIVERSAL,NULL);
		break;
	case 4:
		DoSay(LORD_ILLIDAN_SAY_4,LANG_UNIVERSAL,NULL);
		break;
	case 5:
		DoSay(LORD_ILLIDAN_SAY_5,LANG_UNIVERSAL,NULL);
		break;
	case 6:
		DoSay(LORD_ILLIDAN_SAY_6,LANG_UNIVERSAL,NULL);
		break;
	case 7:
		DoSay(LORD_ILLIDAN_SAY_7,LANG_UNIVERSAL,NULL);
		break;
	case 0:
	default:
		break;
	}
}
};

struct TRINITY_DLL_DECL Overlord_MorghorAI : public ScriptedAI
{
    Overlord_MorghorAI(Creature *c) : ScriptedAI(c)
    {
        Lord = NULL;
        Yarzill = NULL;
        Reset();
    }

    Unit* m_player;
    Unit* PlayerCheck;

    uint32 SpeachTimer;
    uint32 SpeachNum;

    uint64 PlayerGUID;
    uint64 YazillGUID;

    bool DoingSpeach;
    bool Failed;

    Creature* Lord;
    Creature* Yarzill;

    void Reset()
    {
        if (Lord)
        {
            Lord->SetUInt64Value(UNIT_FIELD_TARGET, 0);
            Lord->SetVisibility(VISIBILITY_OFF);
            Lord->setDeathState(JUST_DIED);
        }

        if (Yarzill)
        {
            Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, 0);
        }

        m_creature->Relocate(-5085.77, 577.231, 86.6719, 2.32608);
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, 2);
        m_creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
        m_player = NULL;
        PlayerCheck = NULL;
        PlayerGUID = 0;
        YazillGUID = 0;
        Lord = NULL;
        Yarzill = NULL;
        DoingSpeach = false;
        Failed = false;
        SpeachNum = 0;
        SpeachTimer = 0;
    }

    void BeginSpeach(Unit* target)
    {
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, 0);
        m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
        DoSay(OVERLORD_SAY_1,LANG_UNIVERSAL,target);
        m_player = target;
        PlayerCheck = NULL;
        PlayerGUID = target->GetGUID();
        SpeachTimer = 4200;
        SpeachNum = 0;
        DoingSpeach = true;
    }

    void Aggro(Unit *who){}

    void MoveInLineOfSight(Unit *who)
    {
        if (!who)
            return;

        if (DoingSpeach)
        {
            if (who->GetEntry() == 23141 && m_creature->IsWithinDistInMap(who, 15))
            {
                if (!YazillGUID)
                {
                    YazillGUID = who->GetGUID();
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Speach
        if (DoingSpeach)
        {
            if (SpeachTimer < diff)
            {
                if (YazillGUID && !Yarzill)
                    Yarzill = ((Creature*)Unit::GetUnit((*m_creature), YazillGUID));

                if (!m_creature->IsWithinDistInMap(m_player, 50) && ((Player*)m_player)->GetQuestStatus(QUEST_LORD_ILLIDAN_STORMRAGE) == QUEST_STATUS_INCOMPLETE)
                {
                    ((Player*)m_player)->FailQuest(QUEST_LORD_ILLIDAN_STORMRAGE);
                    SpeachNum = 30;
                }

                switch (SpeachNum)
                {
                    // Overlord Movement
                case 0:
                    m_creature->GetMotionMaster()->MovePoint(0, -5104.41, 595.297, 85.6838);
                    SpeachTimer = 9000; SpeachNum++; break;
                    // Overlord Yell 1
                case 1:
                    m_creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_SHOUT);
                    DoYell(OVERLORD_YELL_1,LANG_UNIVERSAL,m_player);
                    SpeachTimer = 4500; SpeachNum++; break;
                    // Overlord Angle
                case 2:
                    m_creature->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
                    SpeachTimer = 3200; SpeachNum++; break;
                    // Overlord Say 2
                case 3:
                    DoSay(OVERLORD_SAY_2,LANG_UNIVERSAL,NULL);
                    SpeachTimer = 2000; SpeachNum++; break;
                    // Summon Illidan
                case 4:
                    Lord = m_creature->SummonCreature(LORD_ILLIDAN_STORMRAGE, -5107.83, 602.584, 85.2393, 4.92598, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    Lord->LoadCreaturesAddon();
                    SpeachTimer = 350; SpeachNum++; break;
                    // Illidan Cast Red Bolt
                case 5:
                    Lord->CastSpell(Lord, SPELL_ONE, true);
                    Lord->SetUInt64Value(UNIT_FIELD_TARGET, m_creature->GetGUID());
                    m_creature->SetUInt64Value(UNIT_FIELD_TARGET, Lord->GetGUID());
                    SpeachTimer = 2000; SpeachNum++; break;
                    // Overlord Yell 2
                case 6:
                    DoYell(OVERLORD_YELL_2,LANG_UNIVERSAL,NULL);
                    SpeachTimer = 4500; SpeachNum++; break;
                    // Overlord Kneel
                case 7:
                    m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,8);
                    SpeachTimer = 2500; SpeachNum++; break;
                    // Overlord Say 3
                case 8:
                    DoSay(OVERLORD_SAY_3,LANG_UNIVERSAL,NULL);
                    SpeachTimer = 6500; SpeachNum++; break;
                    // Illidan Say 1
                case 9:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(1);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Overlord Say 4
                case 10:
                    DoSay(OVERLORD_SAY_4,LANG_UNIVERSAL,m_player);
                    SpeachTimer = 6000; SpeachNum++; break;
                    // Illidan Say 2
                case 11:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(2);
                    SpeachTimer = 5500; SpeachNum++; break;
                    // Illidan Say 3
                case 12:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(3);
                    SpeachTimer = 4000; SpeachNum++; break;
                    // Illidan Angle
                case 13:
                    Lord->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
                    SpeachTimer = 1500; SpeachNum++; break;
                    // Illidan Say 4
                case 14:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(4);
                    SpeachTimer = 1500; SpeachNum++; break;
                    // Illidan Cast
                case 15:
                    PlayerCheck = Unit::GetUnit(*Lord, PlayerGUID);
                    if (PlayerCheck)
                    {
                        Lord->CastSpell(m_player, SPELL_TWO, true);
                        m_player->RemoveAurasDueToSpell(SPELL_THREE);
                        m_player->RemoveAurasDueToSpell(SPELL_FOUR);
                        SpeachTimer = 5000; SpeachNum++;
                    }
                    else
                    {
                        ((Player*)m_player)->FailQuest(QUEST_LORD_ILLIDAN_STORMRAGE);
                        SpeachTimer = 100; SpeachNum = 30;
                    }
                    break;
                    // Illidan Say 5
                case 16:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(5);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Illidan Say 6
                case 17:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(6);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Illidan Say 7
                case 18:
                    ((Lord_IllidanAI*)Lord->AI())->DoSpeach(7);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Illidan Fly
                case 19:
                    Lord->HandleEmoteCommand(EMOTE_ONESHOT_LIFTOFF);
                    Lord->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT + MOVEMENTFLAG_LEVITATING);
                    SpeachTimer = 500; SpeachNum++; break;
                    // Overlord Say 5
                case 20:
                    DoSay(OVERLORD_SAY_5,LANG_UNIVERSAL,NULL);
                    SpeachTimer = 500; SpeachNum++; break;
                    // Illidan Despawn
                case 21:
                    Lord->SetVisibility(VISIBILITY_OFF);
                    Lord->setDeathState(JUST_DIED);
                    Lord = NULL;
                    SpeachTimer = 1000; SpeachNum++; break;
                    // Overlord Stand Up
                case 22:
                    m_creature->SetUInt32Value(UNIT_FIELD_BYTES_1,0);
                    SpeachTimer = 2000; SpeachNum++; break;
                    // Overlord Angle
                case 23:
                    m_creature->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Overlord Say 6
                case 24:
                    DoSay(OVERLORD_SAY_6,LANG_UNIVERSAL,NULL);
                    SpeachTimer = 2000; SpeachNum++; break;
                    // Complete Quest
                case 25:
                    ((Player*)m_player)->CompleteQuest(QUEST_LORD_ILLIDAN_STORMRAGE);
                    SpeachTimer = 6000; SpeachNum++; break;
                    // Goblin Angle
                case 26:
                    if (Yarzill)
                        Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, PlayerGUID);
                    SpeachTimer = 500; SpeachNum++; break;
                    // Cast Again Dragonaw Illusion
                case 27:
                    m_player->RemoveAurasDueToSpell(SPELL_TWO);
                    m_player->RemoveAurasDueToSpell(41519);
                    m_player->CastSpell(m_player, SPELL_THREE, true);
                    m_player->CastSpell(m_player, SPELL_FOUR, true);
                    SpeachTimer = 1000; SpeachNum++; break;
                    // Goblin
                case 28:
                    if (Yarzill)
                        ((Yarzill_The_MercAI*)Yarzill->AI())->DoSpeach(m_player);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Goblin Off
                case 29:
                    if (Yarzill)
                        Yarzill->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Overlord Go Back
                case 30:
                    m_creature->GetMotionMaster()->MovePoint(0, -5085.77, 577.231, 86.6719);
                    SpeachTimer = 5000; SpeachNum++; break;
                    // Reset
                case 31:
                    Reset();
                    break;
                default: break;
                }
            }else SpeachTimer -= diff;
        }
    }
};

CreatureAI* GetAI_Overlord_Morghor(Creature *_Creature)
{
return new Overlord_MorghorAI(_Creature);
}

CreatureAI* GetAI_Lord_Illidan(Creature *_Creature)
{
return new Lord_IllidanAI(_Creature);
}

CreatureAI* GetAI_Yarzill_The_Merc(Creature *_Creature)
{
return new Yarzill_The_MercAI(_Creature);
}
bool QuestAccept_Overlord_Morghor(Player *player, Creature *_Creature, const Quest *_Quest )
{
	if(_Quest->GetQuestId() == QUEST_LORD_ILLIDAN_STORMRAGE)
	{
		((Overlord_MorghorAI*)_Creature->AI())->BeginSpeach((Unit*)player);
		return true;
	}
	return false;
}

void AddSC_shadowmoon_valley()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mob_mature_netherwing_drake";
    newscript->GetAI = GetAI_mob_mature_netherwing_drake;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_enslaved_netherwing_drake";
    newscript->GetAI = GetAI_mob_enslaved_netherwing_drake;
    newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "mob_dragonmaw_peon";
	newscript->GetAI = GetAI_mob_dragonmaw_peon;
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
	newscript->GetAI = GetAI_Overlord_Morghor;
	newscript->pQuestAccept = &QuestAccept_Overlord_Morghor;
	newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "npc_lord_illidan_stormrage";
	newscript->GetAI = GetAI_Lord_Illidan;
	newscript->RegisterSelf();

	newscript = new Script;
	newscript->Name = "npc_yarzill_the_merc";
	newscript->GetAI = GetAI_Yarzill_The_Merc;
	newscript->pGossipHello = &GossipHello_npc_yarzill_fly;
	newscript->pGossipSelect = &GossipSelect_npc_yarzill_fly;
	newscript->RegisterSelf();
}
