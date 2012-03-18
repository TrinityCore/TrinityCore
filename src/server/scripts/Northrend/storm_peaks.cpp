/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"

/*######
## npc_agnetta_tyrsdottar
######*/

#define SAY_AGGRO                  -1571003
#define GOSSIP_AGNETTA             "Skip the warmup, sister... or are you too scared to face soemeone your own size?"

enum eAgnetta
{
    QUEST_ITS_THAT_YOUR_GOBLIN      = 12969,
    FACTION_HOSTILE_AT1             = 45
};

class npc_agnetta_tyrsdottar : public CreatureScript
{
public:
    npc_agnetta_tyrsdottar() : CreatureScript("npc_agnetta_tyrsdottar") { }

    struct npc_agnetta_tyrsdottarAI : public ScriptedAI
    {
        npc_agnetta_tyrsdottarAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset()
        {
            me->RestoreFaction();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_agnetta_tyrsdottarAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_ITS_THAT_YOUR_GOBLIN) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_AGNETTA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(13691, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            DoScriptText(SAY_AGGRO, creature);
            player->CLOSE_GOSSIP_MENU();
            creature->setFaction(FACTION_HOSTILE_AT1);
            creature->AI()->AttackStart(player);
        }

        return true;
    }
};

/*######
## npc_frostborn_scout
######*/

#define GOSSIP_ITEM1    "Are you okay? I've come to take you back to Frosthold if you can stand."
#define GOSSIP_ITEM2    "I'm sorry that I didn't get here sooner. What happened?"
#define GOSSIP_ITEM3    "I'll go get some help. Hang in there."

enum eFrostbornScout
{
    QUEST_MISSING_SCOUTS  =  12864
};

class npc_frostborn_scout : public CreatureScript
{
public:
    npc_frostborn_scout() : CreatureScript("npc_frostborn_scout") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {

        if (player->GetQuestStatus(QUEST_MISSING_SCOUTS) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->PlayerTalkClass->SendGossipMenu(13611, creature->GetGUID());
        }

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->PlayerTalkClass->SendGossipMenu(13612, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
            player->PlayerTalkClass->SendGossipMenu(13613, creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->PlayerTalkClass->SendGossipMenu(13614, creature->GetGUID());
            player->AreaExploredOrEventHappens(QUEST_MISSING_SCOUTS);
            break;
        }

        return true;
    }
};

/*######
## npc_thorim
######*/

#define GOSSIP_HN "Thorim?"
#define GOSSIP_SN1 "Can you tell me what became of Sif?"
#define GOSSIP_SN2 "He did more than that, Thorim. He controls Ulduar now."
#define GOSSIP_SN3 "It needn't end this way."

enum eThorim
{
    QUEST_SIBLING_RIVALRY = 13064,
    NPC_THORIM = 29445,
    GOSSIP_TEXTID_THORIM1 = 13799,
    GOSSIP_TEXTID_THORIM2 = 13801,
    GOSSIP_TEXTID_THORIM3 = 13802,
    GOSSIP_TEXTID_THORIM4 = 13803
};

class npc_thorim : public CreatureScript
{
public:
    npc_thorim() : CreatureScript("npc_thorim") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_SIBLING_RIVALRY) == QUEST_STATUS_INCOMPLETE) {
            player->ADD_GOSSIP_ITEM(0, GOSSIP_HN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM1, creature->GetGUID());
            return true;
        }
        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(0, GOSSIP_SN1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(0, GOSSIP_SN2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM3, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(0, GOSSIP_SN3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_THORIM4, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->CLOSE_GOSSIP_MENU();
                player->CompleteQuest(QUEST_SIBLING_RIVALRY);
                break;
        }
        return true;
    }
};

/*######
## npc_victorious_challenger
######*/

#define GOSSIP_CHALLENGER            "Let's do this, sister."

enum eVictoriousChallenger
{
    QUEST_TAKING_ALL_CHALLENGERS    = 12971,
    QUEST_DEFENDING_YOUR_TITLE      = 13423,

    SPELL_SUNDER_ARMOR              = 11971,
    SPELL_REND_VC                   = 11977
};

class npc_victorious_challenger : public CreatureScript
{
public:
    npc_victorious_challenger() : CreatureScript("npc_victorious_challenger") { }

    struct npc_victorious_challengerAI : public ScriptedAI
    {
        npc_victorious_challengerAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 SunderArmorTimer;
        uint32 RendTimer;

        void Reset()
        {
            me->RestoreFaction();

            SunderArmorTimer = 10000;
            RendTimer        = 15000;
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (RendTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_REND_VC, true);
                RendTimer = 15000;
            }else RendTimer -= diff;

            if (SunderArmorTimer < diff)
            {
                DoCast(me->getVictim(), SPELL_SUNDER_ARMOR, true);
                SunderArmorTimer = 10000;
            }else SunderArmorTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void KilledUnit(Unit* /*victim*/)
        {
            me->RestoreFaction();
        }

    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_TAKING_ALL_CHALLENGERS) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_DEFENDING_YOUR_TITLE) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CHALLENGER, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->setFaction(14);
            creature->AI()->AttackStart(player);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_victorious_challengerAI(creature);
    }
};

/*######
## npc_loklira_crone
######*/

#define GOSSIP_LOKLIRACRONE     "Tell me about this proposal"
#define GOSSIP_LOKLIRACRONE1    "What happened then?"
#define GOSSIP_LOKLIRACRONE2    "You want me to take part in the Hyldsmeet to end the war?"
#define GOSSIP_LOKLIRACRONE3    "Very well. I'll take part in this competition."

enum eLokliraCrone
{
    QUEST_HYLDSMEET     = 12970,

    GOSSIP_TEXTID_LOK1  = 13778,
    GOSSIP_TEXTID_LOK2  = 13779,
    GOSSIP_TEXTID_LOK3  = 13780
};

class npc_loklira_crone : public CreatureScript
{
public:
    npc_loklira_crone() : CreatureScript("npc_loklira_crone") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_HYLDSMEET) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOKLIRACRONE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }
        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOKLIRACRONE1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LOK1, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOKLIRACRONE2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LOK2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_LOKLIRACRONE3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_LOK3, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->CLOSE_GOSSIP_MENU();
                player->CompleteQuest(QUEST_HYLDSMEET);
                break;
        }
        return true;
    }
};

/////////////////////
///npc_injured_goblin
/////////////////////

enum eInjuredGoblin
{
    QUEST_BITTER_DEPARTURE     = 12832,
    SAY_QUEST_ACCEPT           =  -1800042,
    SAY_END_WP_REACHED         =  -1800043
};

#define GOSSIP_ITEM_1       "I am ready, lets get you out of here"

class npc_injured_goblin : public CreatureScript
{
public:
    npc_injured_goblin() : CreatureScript("npc_injured_goblin") { }

    struct npc_injured_goblinAI : public npc_escortAI
    {
        npc_injured_goblinAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();
            switch (i)
            {
            case 26:
                DoScriptText(SAY_END_WP_REACHED, me, player);
                break;
            case 27:
                if (player)
                    player->GroupEventHappens(QUEST_BITTER_DEPARTURE, me);
                break;
            }
        }

        void EnterCombat(Unit* /*who*/) {}

        void Reset() {}

        void JustDied(Unit* /*killer*/)
        {
            Player* player = GetPlayerForEscort();
            if (HasEscortState(STATE_ESCORT_ESCORTING) && player)
                player->FailQuest(QUEST_BITTER_DEPARTURE);
        }

       void UpdateAI(const uint32 uiDiff)
        {
            npc_escortAI::UpdateAI(uiDiff);
            if (!UpdateVictim())
                return;
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_injured_goblinAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(QUEST_BITTER_DEPARTURE) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->PlayerTalkClass->SendGossipMenu(9999999, creature->GetGUID());
        }
        else
            player->SEND_GOSSIP_MENU(999999, creature->GetGUID());
        return true;
    }

    bool OnQuestAccept(Player* /*player*/, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_BITTER_DEPARTURE)
            DoScriptText(SAY_QUEST_ACCEPT, creature);

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        npc_escortAI* pEscortAI = CAST_AI(npc_injured_goblin::npc_injured_goblinAI, creature->AI());

        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            pEscortAI->Start(true, true, player->GetGUID());
            creature->setFaction(113);
        }
        return true;
    }
};

/*######
## npc_roxi_ramrocket
######*/

#define SPELL_MECHANO_HOG           60866
#define SPELL_MEKGINEERS_CHOPPER    60867

class npc_roxi_ramrocket : public CreatureScript
{
public:
    npc_roxi_ramrocket() : CreatureScript("npc_roxi_ramrocket") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        //Quest Menu
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        //Trainer Menu
        if( creature->isTrainer() )
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, GOSSIP_TEXT_TRAIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRAIN);

        //Vendor Menu
        if( creature->isVendor() )
            if(player->HasSpell(SPELL_MECHANO_HOG) || player->HasSpell(SPELL_MEKGINEERS_CHOPPER))
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch(action)
        {
        case GOSSIP_ACTION_TRAIN:
            player->GetSession()->SendTrainerList(creature->GetGUID());
            break;
        case GOSSIP_ACTION_TRADE:
            player->GetSession()->SendListInventory(creature->GetGUID());
            break;
        }
        return true;
    }
};

/*######
## npc_quest_12851
######*/

enum eQuest_12851
{
    SPELL_ABLAZE = 54683
};

class npc_quest_12851 : public CreatureScript
{
public:
    npc_quest_12851() : CreatureScript("npc_quest_12851") {}

    struct npc_quest_12851AI : public ScriptedAI
    {
        npc_quest_12851AI(Creature* creature) : ScriptedAI(creature) {}

        bool bBurned;
        uint32 uiDespawnTimer;

        void Reset()
        {
            bBurned = false;
            uiDespawnTimer = 5000;
            me->SetCorpseDelay(5);
        }

        void SpellHit(Unit* /*caster*/, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_ABLAZE)
                bBurned = true;
        }

        void UpdateAI(uint32 const diff)
        {
            // keep this until icefang uses waypoint movement
            if (bBurned && me->isAlive())
                if (uiDespawnTimer < diff)
                {
                    me->Kill(me);
                }else uiDespawnTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_quest_12851AI(creature);
    }
};


/*######
## Quest: Cold Hearted (12856)
######*/

enum eColdHearted
{
    SPELL_KILL_CREDIT_PRISONER = 55144,
    SPELL_KILL_CREDIT_DRAKE    = 55143,
    SPELL_SUMMON_LIBERATED     = 55073
};

const Position FreedDrakeWaypoints[6] =
{
    {7250.15f, -2327.22f, 869.03f, 0.0f},
    {7118.79f, -2122.05f, 841.32f, 0.0f},
    {7052.86f, -1905.99f, 888.59f, 0.0f},
    {7038.24f, -1822.77f, 857.94f, 0.0f},
    {7044.09f, -1792.25f, 841.69f, 0.0f},
    {7071.20f, -1780.73f, 822.42f, 0.0f}
};

class npc_freed_protodrake : public CreatureScript
{
public:
    npc_freed_protodrake() : CreatureScript("npc_freed_protodrake") { }

    struct npc_freed_protodrakeAI : public ScriptedAI
    {
        npc_freed_protodrakeAI(Creature* creature) : ScriptedAI(creature) { }

        uint8 count;
        bool wp_reached;
        bool movementStarted;

        void Reset()
        {
            count = 0;
            wp_reached = false;
            movementStarted = false;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != count)
                return;

            if (id < 5)
            {
                ++count;
                wp_reached = true;
            }
            else // reached village, give credits
            {
                Unit* player = me->GetVehicleKit()->GetPassenger(0); // get player
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                {
                    for (uint8 i = 1; i < 4; ++i) // try to get prisoners
                        if (Unit* prisoner = me->GetVehicleKit()->GetPassenger(i))
                        {
                            if (prisoner->GetTypeId() != TYPEID_UNIT)
                                return;

                            player->CastSpell(player, SPELL_KILL_CREDIT_PRISONER, true);
                            //DoCast(player, SPELL_SUMMON_LIBERATED, true);
                            prisoner->ExitVehicle();
                            prisoner->ToCreature()->AI()->DoAction(0);
                        }

                    player->ToPlayer()->KilledMonsterCredit(29709, 0);
                    //DoCast(player, SPELL_KILL_CREDIT_DRAKE, true);
                    player->ExitVehicle();
                }
            }
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            if (!me->isCharmed() && !movementStarted)
            {
                me->SetSpeed(MOVE_FLIGHT, 5.0f);
                movementStarted = true;
                wp_reached = true;
            }

            if (wp_reached)
            {
                wp_reached = false;
                me->GetMotionMaster()->MovePoint(count, FreedDrakeWaypoints[count]);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_freed_protodrakeAI(creature);
    }
};

/*######
## npc_brunnhildar_prisoner
######*/

enum BrunnhildarPrisoner
{
    SPELL_ICE_BLOCK        = 54894,
    SPELL_ICE_SHARD        = 55046,
    SPELL_ICE_SHARD_IMPACT = 55047
};

class npc_brunnhildar_prisoner : public CreatureScript
{
public:
    npc_brunnhildar_prisoner() : CreatureScript("npc_brunnhildar_prisoner") { }

    struct npc_brunnhildar_prisonerAI : public ScriptedAI
    {
        npc_brunnhildar_prisonerAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 uiCheckTimer;

        void Reset()
        {
            uiCheckTimer = 10*IN_MILLISECONDS;
            DoCast(me, SPELL_ICE_BLOCK, true);
        }

        void DoAction(const int32 /*param*/)
        {
            me->Kill(me);
            me->Respawn();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_ICE_SHARD)
            {
                DoCast(me, SPELL_ICE_SHARD_IMPACT, true);

                if (caster->IsVehicle())
                {
                    uint8 seat = caster->GetVehicleKit()->GetNextEmptySeat(0, true);
                    if (seat <= 0)
                        return;

                    me->EnterVehicle(caster);
                    me->RemoveAurasDueToSpell(SPELL_ICE_BLOCK);
                    caster->SetSpeed(MOVE_FLIGHT, 3.0f);
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            if (uiCheckTimer < diff)
            {
                if (!me->HasUnitState(UNIT_STATE_ONVEHICLE))
                {
                    // return home
                    if (me->GetDistance(me->GetHomePosition()) > 30.0f)
                        DoAction(0);
                }
            else
                {
                    if (me->GetPositionY() > -2595.0f)
                    {
                        // remove player control
                        if (Unit* base = me->GetVehicleBase())
                            if (base->isCharmed())
                                base->RemoveCharmedBy(base->GetCharmer());
                    }
                }

                uiCheckTimer = 10*IN_MILLISECONDS;
            }else uiCheckTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_brunnhildar_prisonerAI(creature);
    }
};

/*######
## Quest: The Last of Her Kind (12983)
######*/

enum IcemawMatriarch
{
    QUEST_LAST_OF_HER_KIND = 12983,
    ENTRY_INJURED_ICEMAW   = 29563,
    SPELL_HARNESSED_ICEMAW = 56795
};

const Position HarnessedIcemawWaypoints[17] =
{
    {7332.80f, -2065.69f, 765.29f, 0.0f},
    {7327.32f, -2101.70f, 774.22f, 0.0f},
    {7254.51f, -2117.08f, 778.98f, 0.0f},
    {7224.31f, -2117.58f, 777.44f, 0.0f},
    {7194.28f, -2114.08f, 765.97f, 0.0f},
    {7155.83f, -2134.19f, 762.16f, 0.0f},
    {7117.62f, -2113.06f, 760.57f, 0.0f},
    {7074.25f, -1956.43f, 769.82f, 0.0f},
    {7065.34f, -1917.58f, 781.57f, 0.0f},
    {7094.17f, -1884.47f, 787.00f, 0.0f},
    {7033.13f, -1883.46f, 799.88f, 0.0f},
    {7021.64f, -1844.55f, 818.59f, 0.0f},
    {7015.42f, -1745.49f, 819.72f, 0.0f},
    {7003.12f, -1721.36f, 820.06f, 0.0f},
    {6947.09f, -1724.14f, 820.61f, 0.0f},
    {6877.17f, -1684.31f, 820.03f, 0.0f},
    {6825.53f, -1702.27f, 820.55f, 0.0f}
};

class npc_injured_icemaw : public CreatureScript
{
public:
    npc_injured_icemaw() : CreatureScript("npc_injured_icemaw") { }

    struct npc_injured_icemawAI : public ScriptedAI
    {
        npc_injured_icemawAI(Creature* creature) : ScriptedAI(creature) { }

        void MoveInLineOfSight(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (who->ToPlayer()->GetQuestStatus(QUEST_LAST_OF_HER_KIND) == QUEST_STATUS_INCOMPLETE && !who->HasUnitState(UNIT_STATE_ONVEHICLE) && who->GetDistance(me) < 5.0f)
            {
                who->CastSpell(who, SPELL_HARNESSED_ICEMAW, true);
                // disable player control
                if (Unit* base = who->GetVehicleBase())
                    if (base->isCharmed())
                        base->RemoveCharmedBy(base->GetCharmer());
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_injured_icemawAI(creature);
    }
};

class npc_harnessed_icemaw : public CreatureScript
{
public:
    npc_harnessed_icemaw() : CreatureScript("npc_harnessed_icemaw") { }

    struct npc_harnessed_icemawAI : public ScriptedAI
    {
        npc_harnessed_icemawAI(Creature* creature) : ScriptedAI(creature) { }

        uint8 count;
        bool wp_reached;
        bool movementStarted;

        void Reset()
        {
            count = 0;
            wp_reached = false;
            movementStarted = false;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != count)
                return;

            if (id < 16)
            {
                ++count;
                wp_reached = true;
            }
            else // reached questgiver, give credit
            {
                Unit* player = me->GetVehicleKit()->GetPassenger(0);
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                {
                    player->ToPlayer()->KilledMonsterCredit(ENTRY_INJURED_ICEMAW, 0);
                    player->ExitVehicle();
                }
            }
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            if (!me->isCharmed() && !movementStarted)
            {
                movementStarted = true;
                wp_reached = true;
            }

            if (wp_reached)
            {
                wp_reached = false;
                me->GetMotionMaster()->MovePoint(count, HarnessedIcemawWaypoints[count]);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_harnessed_icemawAI(creature);
    }
};

/*######
## Quest: The Drakkensryd (12886)
######*/

enum HyldsmeetProtodrakeTransport
{
    //QUEST_DRAKKENSRYD = 12886,
    ENTRY_DRAKE_RIDER   = 29800
};

const Position HyldsmeetProtodrakeWaypoints[11] =
{
    {7043.96f, -1742.44f, 838.93f, 0.0f},
    {7034.98f, -1709.58f, 856.51f, 0.0f},
    {7079.37f, -1612.35f, 924.75f, 0.0f},
    {7379.18f, -1134.81f, 1088.66f, 0.0f},
    {7692.76f, -651.09f, 1461.96f, 0.0f},
    {7675.39f, -486.31f, 1672.88f, 0.0f},
    {7593.01f, -442.39f, 1786.34f, 0.0f},
    {7439.90f, -381.42f, 1852.33f, 0.0f},
    {7339.86f, -426.02f, 1852.92f, 0.0f},
    {7324.65f, -553.58f, 1924.50f, 0.0f},
    {7397.71f, -540.00f, 1927.81f, 0.0f}
};

class npc_hyldsmeet_protodrake_transport : public CreatureScript
{
public:
    npc_hyldsmeet_protodrake_transport() : CreatureScript("npc_hyldsmeet_protodrake_transport") { }

    struct npc_hyldsmeet_protodrake_transportAI : public ScriptedAI
    {
        npc_hyldsmeet_protodrake_transportAI(Creature* creature) : ScriptedAI(creature) { }

        uint8 count;
        bool wp_reached;

        void Reset()
        {
            count = 0;
            wp_reached = false;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if (who && apply)
            {
                    wp_reached = true;
                    me->SetCanFly(true);
                    me->SetSpeed(MOVE_FLIGHT, 5.0f);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE || id != count)
                return;

            if (id < 10)
            {
                ++count;
                wp_reached = true;
            }
            else
            {
                Unit* player = me->GetVehicleKit()->GetPassenger(0);
                if (player && player->GetTypeId() == TYPEID_PLAYER)
                {
                    for (uint8 i = 0; i < 10; ++i)
                        player->ToPlayer()->KilledMonsterCredit(ENTRY_DRAKE_RIDER, 0);
                    player->ExitVehicle();
                    me->DespawnOrUnsummon(5000);
                }
            }
        }

        void UpdateAI(uint32 const /*diff*/)
        {
            if (wp_reached)
            {
                wp_reached = false;
                me->GetMotionMaster()->MovePoint(count, HyldsmeetProtodrakeWaypoints[count]);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hyldsmeet_protodrake_transportAI(creature);
    }
};

/*######
## Quest: Forging a Head (12985)
######*/

enum DeadIrongiant
{
    ENTRY_AMBUSHER              = 30208,
    SPELL_SALVAGE_CORPSE        = 56227,
    SPELL_CREATE_EYES           = 56230
};

class npc_dead_irongiant : public CreatureScript
{
public:
    npc_dead_irongiant() : CreatureScript("npc_dead_irongiant") {}

    struct npc_dead_irongiantAI : public ScriptedAI
    {
        npc_dead_irongiantAI(Creature* creature) : ScriptedAI(creature) {}

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_SALVAGE_CORPSE)
            {
                if (!urand(0,2))
                {
                    for (uint8 i = 0; i < 3; ++i)
                        if (Creature *temp = me->SummonCreature(ENTRY_AMBUSHER, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60*IN_MILLISECONDS))
                            temp->AI()->AttackStart(caster);
                }
                else
                    me->CastSpell(caster, SPELL_CREATE_EYES, true);

                me->DespawnOrUnsummon(500);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_dead_irongiantAI(creature);
    }
};

class npc_hyldsmeet_protodrake : public CreatureScript
{
    enum NPCs
    {
        NPC_HYLDSMEET_DRAKERIDER = 29694
    };

    public:
        npc_hyldsmeet_protodrake() : CreatureScript("npc_hyldsmeet_protodrake") { }

        class npc_hyldsmeet_protodrakeAI : public CreatureAI
        {
            public:
                npc_hyldsmeet_protodrakeAI(Creature* creature) : CreatureAI(creature), _accessoryRespawnTimer(0), _vehicleKit(creature->GetVehicleKit()) {}

                void PassengerBoarded(Unit* who, int8 /*seat*/, bool apply)
                {
                    if (apply)
                        return;

                    if (who->GetEntry() == NPC_HYLDSMEET_DRAKERIDER)
                        _accessoryRespawnTimer = 5 * MINUTE * IN_MILLISECONDS;
                }

                void UpdateAI(uint32 const diff)
                {
                    //! We need to manually reinstall accessories because the vehicle itself is friendly to players,
                    //! so EnterEvadeMode is never triggered. The accessory on the other hand is hostile and killable.
                    if (_accessoryRespawnTimer && _accessoryRespawnTimer <= diff && _vehicleKit)
                    {
                        _vehicleKit->InstallAllAccessories(true);
                        _accessoryRespawnTimer = 0;
                    }
                    else
                        _accessoryRespawnTimer -= diff;
                }
            
            private:
                uint32 _accessoryRespawnTimer;
                Vehicle* _vehicleKit;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hyldsmeet_protodrakeAI (creature);
        }
};

/*######
## Snowblind Follower
## Quest: Gormok Wants His Snobolds (14090,14141)
######*/

enum eSnowblindFollower
{
    ENTRY_SNOWBLIND_CREDIT              = 34899,
    SPELL_THROW_NET                     = 66474,
};

#define SAY_SNOWBLINDFOLLOWER_1         "Grrrrr!"
#define SAY_SNOWBLINDFOLLOWER_2         "Me not afraid!"
#define SAY_SNOWBLINDFOLLOWER_3         "Net not stop me! No... net stop me."
#define SAY_SNOWBLINDFOLLOWER_4         "No kill me!"
#define SAY_SNOWBLINDFOLLOWER_5         "No!"
#define SAY_SNOWBLINDFOLLOWER_6         "You no take... me!"
class npc_snowblind_follower : public CreatureScript
{
public:
    npc_snowblind_follower() : CreatureScript("npc_snowblind_follower") {}

    struct npc_snowblind_followerAI : public ScriptedAI
    {
        npc_snowblind_followerAI(Creature* creature) : ScriptedAI(creature) { }

        bool hitbynet;

        void Reset()
        {
            hitbynet = false;
        }

        void MoveInLineOfSight(Unit* attacker) {}
        void AttackStart(Unit* attacker) {}

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_THROW_NET)
            {
                if(!caster || !caster->ToPlayer())
                    return;

                if(hitbynet)
                    return;

                hitbynet = true;

                switch(urand(0,5))
                {
                case 0: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_1,LANG_UNIVERSAL,caster->GetGUID()); break;
                case 1: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_2,LANG_UNIVERSAL,caster->GetGUID()); break;
                case 2: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_3,LANG_UNIVERSAL,caster->GetGUID()); break;
                case 3: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_4,LANG_UNIVERSAL,caster->GetGUID()); break;
                case 4: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_5,LANG_UNIVERSAL,caster->GetGUID()); break;
                case 5: me->MonsterSay(SAY_SNOWBLINDFOLLOWER_6,LANG_UNIVERSAL,caster->GetGUID()); break;
                }
                caster->ToPlayer()->KilledMonsterCredit(ENTRY_SNOWBLIND_CREDIT,0);
                me->DespawnOrUnsummon(3000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_snowblind_followerAI(creature);
    }
};

/*######
## Quest:  Discipline, Maintaining Discipline (12906,13422)
######*/

enum eExhausted
{
    SPELL_DISCIPLINING_ROD  = 56033,
    NPC_EXHAUSTED_VRYKUL    = 29886,
    SAY_RAND_WORK1          = -1000555,
    SAY_RAND_WORK2          = -1000556,
    SAY_RAND_WORK3          = -1000557,
    SAY_RAND_ATTACK1        = -1000558,
    SAY_RAND_ATTACK2        = -1000559,
    SAY_RAND_ATTACK3        = -1000560
};

class npc_exhausted_vrykul : public CreatureScript
{
public:
    npc_exhausted_vrykul() : CreatureScript("npc_exhausted_vrykul") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_exhausted_vrykulAI(creature);
    }

    struct npc_exhausted_vrykulAI : public ScriptedAI
    {
        npc_exhausted_vrykulAI (Creature* creature) : ScriptedAI(creature) 
        { 
            Reset(); 
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;
        }

        void SpellHit(Unit *caster, const SpellEntry *spell)
        { 
            if ((caster->GetTypeId() == TYPEID_PLAYER ) && spell->Id == SPELL_DISCIPLINING_ROD && CAST_PLR(caster)->GetQuestStatus(12906) == QUEST_STATUS_INCOMPLETE)
            {
                if (me->getStandState() == UNIT_STAND_STATE_STAND)
                    return;

                switch(urand(1,2))
                {
                    case 1:
                    {
                        switch(urand(1,3))
                        {
                            case 1: 
                                DoScriptText(SAY_RAND_ATTACK1, me); 
                                break;
                            case 2: 
                                DoScriptText(SAY_RAND_ATTACK2, me); 
                                break;
                            case 3: 
                                DoScriptText(SAY_RAND_ATTACK3, me); 
                                break;
                        }

                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->AI()->AttackStart(caster);
                        break;
                    }
                    case 2:
                    {
                        switch(urand(1,3))
                        {
                            case 1: 
                                DoScriptText(SAY_RAND_WORK1, me);
                                break;
                            case 2: 
                                DoScriptText(SAY_RAND_WORK2, me);
                                break;
                            case 3: 
                                DoScriptText(SAY_RAND_WORK3, me);
                                break;
                        }
                        ((Player *)caster)->KilledMonsterCredit(NPC_EXHAUSTED_VRYKUL,me->GetGUID());
                        me->SetStandState(UNIT_STAND_STATE_STAND);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_WORK);
                        break;
                    }
                }		
            }
        }
    };   
};


void AddSC_storm_peaks()
{
    new npc_agnetta_tyrsdottar();
    new npc_frostborn_scout();
    new npc_thorim();
    new npc_victorious_challenger();
    new npc_loklira_crone();
    new npc_injured_goblin();
    new npc_roxi_ramrocket();
    new npc_quest_12851();
    new npc_freed_protodrake();
    new npc_hyldsmeet_protodrake_transport();
    new npc_brunnhildar_prisoner();
    new npc_injured_icemaw();
    new npc_harnessed_icemaw();
    new npc_hyldsmeet_protodrake();	
    new npc_dead_irongiant();
    new npc_snowblind_follower();
    new npc_exhausted_vrykul;
}
