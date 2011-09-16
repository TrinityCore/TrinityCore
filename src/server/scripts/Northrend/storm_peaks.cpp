/*
 * Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

// ------------------------------------------------------------------------------------------
// Skripte für Gefangene Brunnhildar + Befreiter Protodrache und die Quest 12856 (Kaltherzig)
// ------------------------------------------------------------------------------------------
const Position KoordsBefreiterProtodrache[8] =
{
    { 7332.145f, -2438.706f, 843.39642f, 0.0f },
    { 7227.096f, -2312.145f, 828.94330f, 0.0f },
    { 7143.731f, -2196.052f, 821.44989f, 0.0f },
    { 7105.639f, -2086.571f, 833.62183f, 0.0f },
    { 7076.477f, -1965.428f, 844.88654f, 0.0f },
    { 7053.544f, -1829.283f, 850.52417f, 0.0f },
    { 7050.993f, -1769.351f, 847.84186f, 0.0f },
    { 7048.844727f, -1701.853271f, 830.052246f, 1.787752f }
};

enum KoordsBefreiterProtodracheIdx
{
    WP1 = 0,    // Wegpunkt 1
    WP2,        // Wegpunkt 2
    WP3,        // Wegpunkt 3
    WP4,        // Wegpunkt 4
    WP5,        // Wegpunkt 5
    WP6,        // Wegpunkt 6
    WP7,        // Wegpunkt 7
    Ziel        // Ziel / Abwurfpunkt
};

enum KaltherzigDivers
{
    Quest_Kaltherzig                    = 12856,    // Quest ID
    Befreiter_Protodrache               = 29709,    // NPC ID
    Liberated_Brunnhildar_PH_Texture    = 29734,    // NPC ID
    Befreiter_Protodrache_Vehicle_ID    = 194,      // Vehicle ID
    Dun_Niffelem                        = 4438      // Dun Niffelem Area
};

enum KaltherzigSpells
{
    Spell_Protodrachen_Kettenkanal              = 55244,    // Visuelle Kette für den Gefangener Protodrache

    Spell_Befreiter_Protodrache_beschwoeren     = 55028,    // Spell klick für den Gefangener Protodrache auf den Spieler casten
    Spell_Befreiter_Protodrache_reiten          = 55029,    // Wenn der Befreiter Protodrache gespawnt wird auf den Spieler casten!

    Spell_Eisgefaengnis                         = 54894,    // Gefängnis der Brunnhildar
    Spell_Eissplitter                           = 55046,    // Spell des Befreiter Protodrache um die Brunnhildar zu befreien
    Spell_Gefangenen_von_Brunnhildar_befreien   = 55048,    // Effekt für das Befreien einer Gefangener von Brunnhildar

    Spell_Befreite_von_Brunnhildar_beschwoeren  = 55073,    // Spawnt Liberated Brunnhildar <PH Texture> (29734)
    Spell_Protodrachen_reiten                   = 55074,    // Reiten für Liberated Brunnhildar <PH Texture>
    Spell_Ping_Protodrachen                     = 55075,    // ??? Dummy - Server-side script

    Spell_Brunnhildar_Vorauswurf                = 55141,    // Absetzen von Liberated Brunnhildar <PH Texture> !?
    Spell_ProtoDrakeKill_Credit                 = 55143,    // Kill Credit für den Drachen
    Spell_Liberated_Vrykul_Kill_Credit          = 55144     // Kill Credit für Liberated Brunnhildar <PH Texture>
};

class npc_brunnhildar_prisoner : public CreatureScript
{
    public:
        npc_brunnhildar_prisoner() : CreatureScript("npc_brunnhildar_prisoner") { }

        struct npc_brunnhildar_prisonerAI : public ScriptedAI
        {
            npc_brunnhildar_prisonerAI(Creature * creature) : ScriptedAI(creature), summons(me)
            {
            }

            void Reset()
            {
                me->SetVisible(true);
                me->CastSpell(me, Spell_Eisgefaengnis, true);

                drake = NULL;

                enter_timer = 0;
                visible_timer = 0;

                hasEmptySeats = false;
            }

            void DamageTaken(Unit * attacker, uint32 & damage)
            {
                if (attacker && attacker->GetTypeId() == TYPEID_UNIT) // Darf nicht von NPCs getötet werden können!
                    damage = 0;
            }

            void JustSummoned(Creature * summon)
            {
                summons.Summon(summon);

                if (drake && summon->GetEntry() == Liberated_Brunnhildar_PH_Texture)
                {
                    summon->setFaction(35);
                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    summon->JumpTo(drake, 35.0f);

                    uint8 seat = drake->GetVehicleKit()->GetNextEmptySeat(0, true);
                    if (seat <= 0)
                    {
                        summon->DespawnOrUnsummon();
                        return;
                    }
                    summon->EnterVehicle(drake, seat);
                    summon->SendMovementFlagUpdate();

                    hasEmptySeats = false;
                }
            }

            void SummonedCreatureDespawn(Creature * summon)
            {
                summons.Despawn(summon);
            }

            void SpellHit(Unit * hitter, const SpellInfo * spell)
            {
                if (!hitter || !spell)
                    return;

                if (spell->Id == Spell_Eissplitter)
                {
                    me->CastSpell(me, Spell_Gefangenen_von_Brunnhildar_befreien, true);
                    me->RemoveAura(Spell_Eisgefaengnis);

                    if (hitter->IsVehicle())
                    {
                        drake = hitter;

                        if (drake->GetVehicleKit()->GetNextEmptySeat(0, true))
                            hasEmptySeats = true;
                    }
                    enter_timer = 1 * IN_MILLISECONDS;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (enter_timer && enter_timer <= diff)
                {
                    if (hasEmptySeats)
                    {
                        me->SetVisible(false);
                        me->CastSpell(me, Spell_Befreite_von_Brunnhildar_beschwoeren, true);
                        visible_timer = SEKUNDEN_20;
                    }
                    else
                        Reset();

                    enter_timer = 0;
                }
                else
                    enter_timer -= diff;

                if (visible_timer && visible_timer <= diff)
                {
                    me->SetVisible(true);
                    Reset();
                    visible_timer = 0;
                }
                else
                    visible_timer -= diff;
            }
        private:
            Unit * drake;
            uint16 enter_timer;
            bool hasEmptySeats;
            uint32 visible_timer;
            SummonList summons;
        };

        CreatureAI * GetAI(Creature * creature) const
        {
            return new npc_brunnhildar_prisonerAI(creature);
        }
};

class npc_befreiter_protodrache : public CreatureScript
{
public:
    npc_befreiter_protodrache() : CreatureScript("npc_befreiter_protodrache") { }

    struct npc_befreiter_protodracheAI : public VehicleAI
    {
        npc_befreiter_protodracheAI(Creature * creature) : VehicleAI(creature)
        {
            me->SetFlying(true);
            me->SetSpeed(MOVE_FLIGHT, 3.0f, true);
            kontrolle = false;
            exit_timer = 0;
            rider = NULL;
        }

        void Reset()
        {
        }

        void AttackStart(Unit * /*target*/, float /*dist*/ = 0)
        {
        }

        void MoveInLineOfSight(Unit * /*who*/)
        {
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case WP1: me->GetMotionMaster()->MovePoint(WP2, KoordsBefreiterProtodrache[WP2]); break;
                case WP2: me->GetMotionMaster()->MovePoint(WP3, KoordsBefreiterProtodrache[WP3]); break;
                case WP3: me->GetMotionMaster()->MovePoint(WP4, KoordsBefreiterProtodrache[WP4]); break;
                case WP4: me->GetMotionMaster()->MovePoint(WP5, KoordsBefreiterProtodrache[WP5]); break;
                case WP5: me->GetMotionMaster()->MovePoint(WP6, KoordsBefreiterProtodrache[WP6]); break;
                case WP6: me->GetMotionMaster()->MovePoint(WP7, KoordsBefreiterProtodrache[WP7]); break;
                case WP7: me->GetMotionMaster()->MovePoint(Ziel, KoordsBefreiterProtodrache[Ziel]); break;
                case Ziel:
                {
                    for (uint8 i=0; i<4; ++i)
                        if (Unit * passenger = me->GetVehicleKit()->GetPassenger(i))
                            if (!passenger->ToPlayer()) // Den Spieler erst später auswerfen!
                            {
                                passenger->ExitVehicle();
                                passenger->CastSpell(passenger, Spell_Brunnhildar_Vorauswurf, true);
                                passenger->SetTimeUntilDisappear(5 * IN_MILLISECONDS);
                                rider->CastSpell(rider, Spell_Liberated_Vrykul_Kill_Credit, true);
                            }

                    exit_timer = 3 * IN_MILLISECONDS;
                }
                break;
            }
        }

        bool CheckRider()
        {
            if (me->GetVehicleKit()->GetAvailableSeatCount() == 0)
                return true;

            for (uint8 i=0; i<4; ++i)
                if (Unit * passenger = me->GetVehicleKit()->GetPassenger(i))
                    if (passenger->ToPlayer() && passenger->ToPlayer()->isValid())
                        return true;

            return false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!rider || !rider->isValid())
            {
                for (uint8 i=0; i<4; ++i)
                    if (Unit * passenger = me->GetVehicleKit()->GetPassenger(i))
                        if (passenger->ToPlayer() && passenger->ToPlayer()->isValid())
                        {
                            rider = passenger->ToPlayer();
                            rider->CastSpell(rider, Spell_Befreiter_Protodrache_reiten, true);
                            check_timer = SEKUNDEN_10;
                        }

                if (!rider || !rider->isValid())
                    rider = NULL;
            }

            if (rider)
            {
                if (exit_timer && exit_timer <= diff)
                {
                    rider->ExitVehicle();
                    rider->CastSpell(rider, Spell_ProtoDrakeKill_Credit, true);
                    rider->SetMover(rider);
                    rider->SendMovementFlagUpdate();
                    rider->KilledMonsterCredit(29709, me->GetGUID());
                    me->SetTimeUntilDisappear(5 * IN_MILLISECONDS);
                    exit_timer = 0;
                }
                else
                    exit_timer -= diff;

                if (!kontrolle && rider->GetAreaId() != Dun_Niffelem)
                {
                    rider->SetMover(me);
                    rider->SendMovementFlagUpdate();
                    me->GetMotionMaster()->MovePoint(WP1, KoordsBefreiterProtodrache[WP1]);
                    kontrolle = true;
                }

                if (check_timer && check_timer <= diff)
                {
                    if (!CheckRider())
                    {
                        for (uint8 i=0; i<4; ++i)
                            if (Unit * passenger = me->GetVehicleKit()->GetPassenger(i))
                            {
                                passenger->ExitVehicle();
                                passenger->SetTimeUntilDisappear(5 * IN_MILLISECONDS);
                            }

                        me->GetVehicleKit()->Dismiss();

                        check_timer = 0;
                    }
                    else
                        check_timer = SEKUNDEN_10;
                }
                else
                    check_timer -= diff;
            }
        }
    private:
        bool kontrolle;
        uint32 exit_timer;
        uint32 check_timer;
        Player * rider;
    };

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_befreiter_protodracheAI(creature);
    }
};

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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
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
## npc_goblin_prisoner
######*/

enum eGoblinPrisoner
{
    GO_RUSTY_CAGE = 191544
};

class npc_goblin_prisoner : public CreatureScript
{
public:
    npc_goblin_prisoner() : CreatureScript("npc_goblin_prisoner") { }

    struct npc_goblin_prisonerAI : public ScriptedAI
    {
        npc_goblin_prisonerAI(Creature* creature) : ScriptedAI (creature){}

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);

            if (GameObject* pGO = me->FindNearestGameObject(GO_RUSTY_CAGE, 5.0f))
            {
                if (pGO->GetGoState() == GO_STATE_ACTIVE)
                    pGO->SetGoState(GO_STATE_READY);
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_goblin_prisonerAI(creature);
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
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

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        npc_escortAI* pEscortAI = CAST_AI(npc_injured_goblin::npc_injured_goblinAI, creature->AI());

        if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
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

class npc_icefang : public CreatureScript
{
public:
    npc_icefang() : CreatureScript("npc_icefang") { }

    struct npc_icefangAI : public npc_escortAI
    {
        npc_icefangAI(Creature* creature) : npc_escortAI(creature) {}

        void AttackStart(Unit * /*who*/, float /*dist*/ = 0) {}
        void EnterCombat(Unit* /*who*/) {}
        void EnterEvadeMode() {}

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (apply)
                    Start(false, true, who->GetGUID());
            }
        }

        void WaypointReached(uint32 /*wp*/)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
        }

        void OnCharmed(bool /*apply*/)
        {
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_icefangAI (creature);
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
                npc_hyldsmeet_protodrakeAI(Creature* c) : CreatureAI(c), _accessoryRespawnTimer(0), _vehicleKit(c->GetVehicleKit()) {}

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

void AddSC_storm_peaks()
{
    new npc_agnetta_tyrsdottar;
    new npc_frostborn_scout;
    new npc_thorim;
    new npc_goblin_prisoner;
    new npc_victorious_challenger;
    new npc_loklira_crone;
    new npc_injured_goblin;
    new npc_roxi_ramrocket;
    new npc_brunnhildar_prisoner;
    new npc_befreiter_protodrache;
    new npc_icefang;
    new npc_hyldsmeet_protodrake;
}
