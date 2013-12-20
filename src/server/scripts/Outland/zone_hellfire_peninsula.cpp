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
SDName: Hellfire_Peninsula
SD%Complete: 100
SDComment: Quest support: 9375, 9410, 9418, 10129, 10146, 10162, 10163, 10340, 10346, 10347, 10382 (Special flight paths)
SDCategory: Hellfire Peninsula
EndScriptData */

/* ContentData
npc_aeranas
npc_ancestral_wolf
go_haaleshi_altar
npc_naladu
npc_tracy_proudwell
npc_trollbane
npc_wounded_blood_elf
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Player.h"
#include "WorldSession.h"

/*######
## npc_aeranas
######*/

enum Aeranas
{
    SAY_SUMMON              = 0,
    SAY_FREE                = 1,

    FACTION_HOSTILE         = 16,
    FACTION_FRIENDLY        = 35,

    SPELL_ENVELOPING_WINDS  = 15535,
    SPELL_SHOCK             = 12553
};

class npc_aeranas : public CreatureScript
{
public:
    npc_aeranas() : CreatureScript("npc_aeranas") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_aeranasAI(creature);
    }

    struct npc_aeranasAI : public ScriptedAI
    {
        npc_aeranasAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Faction_Timer;
        uint32 EnvelopingWinds_Timer;
        uint32 Shock_Timer;

        void Reset() OVERRIDE
        {
            Faction_Timer = 8000;
            EnvelopingWinds_Timer = 9000;
            Shock_Timer = 5000;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->setFaction(FACTION_FRIENDLY);

            Talk(SAY_SUMMON);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (Faction_Timer)
            {
                if (Faction_Timer <= diff)
                {
                    me->setFaction(FACTION_HOSTILE);
                    Faction_Timer = 0;
                } else Faction_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (HealthBelowPct(30))
            {
                me->setFaction(FACTION_FRIENDLY);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->RemoveAllAuras();
                me->DeleteThreatList();
                me->CombatStop(true);
                Talk(SAY_FREE);
                return;
            }

            if (Shock_Timer <= diff)
            {
                DoCastVictim(SPELL_SHOCK);
                Shock_Timer = 10000;
            } else Shock_Timer -= diff;

            if (EnvelopingWinds_Timer <= diff)
            {
                DoCastVictim(SPELL_ENVELOPING_WINDS);
                EnvelopingWinds_Timer = 25000;
            } else EnvelopingWinds_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

/*######
## npc_ancestral_wolf
######*/

enum AncestralWolf
{
    EMOTE_WOLF_LIFT_HEAD            = 0,
    EMOTE_WOLF_HOWL                 = 1,
    SAY_WOLF_WELCOME                = 2,

    SPELL_ANCESTRAL_WOLF_BUFF       = 29981,

    NPC_RYGA                        = 17123
};

class npc_ancestral_wolf : public CreatureScript
{
public:
    npc_ancestral_wolf() : CreatureScript("npc_ancestral_wolf") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ancestral_wolfAI(creature);
    }

    struct npc_ancestral_wolfAI : public npc_escortAI
    {
        npc_ancestral_wolfAI(Creature* creature) : npc_escortAI(creature)
        {
            if (creature->GetOwner() && creature->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                Start(false, false, creature->GetOwner()->GetGUID());
            else
                TC_LOG_ERROR("scripts", "TRINITY: npc_ancestral_wolf can not obtain owner or owner is not a player.");

            creature->SetSpeed(MOVE_WALK, 1.5f);
            Reset();
        }

        Creature* pRyga;

        void Reset() OVERRIDE
        {
            pRyga = NULL;
            DoCast(me, SPELL_ANCESTRAL_WOLF_BUFF, true);
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!pRyga && who->GetEntry() == NPC_RYGA && me->IsWithinDistInMap(who, 15.0f))
                if (Creature* temp = who->ToCreature())
                    pRyga = temp;

            npc_escortAI::MoveInLineOfSight(who);
        }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            switch (waypointId)
            {
                case 0:
                    Talk(EMOTE_WOLF_LIFT_HEAD);
                    break;
                case 2:
                    Talk(EMOTE_WOLF_HOWL);
                    break;
                case 50:
                    if (pRyga && pRyga->IsAlive() && !pRyga->IsInCombat())
                        pRyga->AI()->Talk(SAY_WOLF_WELCOME);
                    break;
            }
        }
    };
};

/*######
## npc_naladu
######*/

#define GOSSIP_NALADU_ITEM1 "Why don't you escape?"

enum Naladu
{
    GOSSIP_TEXTID_NALADU1   = 9788
};

class npc_naladu : public CreatureScript
{
public:
    npc_naladu() : CreatureScript("npc_naladu") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
            player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_NALADU1, creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_NALADU_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }
};

/*######
## npc_tracy_proudwell
######*/

#define GOSSIP_TEXT_REDEEM_MARKS        "I have marks to redeem!"
#define GOSSIP_TRACY_PROUDWELL_ITEM1    "I heard that your dog Fei Fei took Klatu's prayer beads..."
#define GOSSIP_TRACY_PROUDWELL_ITEM2    "<back>"

enum Tracy
{
    GOSSIP_TEXTID_TRACY_PROUDWELL1       = 10689,
    QUEST_DIGGING_FOR_PRAYER_BEADS       = 10916
};

class npc_tracy_proudwell : public CreatureScript
{
public:
    npc_tracy_proudwell() : CreatureScript("npc_tracy_proudwell") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TRACY_PROUDWELL_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TRACY_PROUDWELL1, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                break;
            case GOSSIP_ACTION_TRADE:
                player->GetSession()->SendListInventory(creature->GetGUID());
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->IsVendor())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_REDEEM_MARKS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        if (player->GetQuestStatus(QUEST_DIGGING_FOR_PRAYER_BEADS) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TRACY_PROUDWELL_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }
};

/*######
## npc_trollbane
######*/

#define GOSSIP_TROLLBANE_ITEM1      "Tell me of the Sons of Lothar."
#define GOSSIP_TROLLBANE_ITEM2      "<more>"
#define GOSSIP_TROLLBANE_ITEM3      "Tell me of your homeland."

enum Trollbane
{
    GOSSIP_TEXTID_TROLLBANE1        = 9932,
    GOSSIP_TEXTID_TROLLBANE2        = 9933,
    GOSSIP_TEXTID_TROLLBANE3        = 8772
};

class npc_trollbane : public CreatureScript
{
public:
    npc_trollbane() : CreatureScript("npc_trollbane") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE1, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE2, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE3, creature->GetGUID());
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }
};

/*######
## npc_wounded_blood_elf
######*/

enum WoundedBloodElf
{
    SAY_ELF_START               = 0,
    SAY_ELF_SUMMON1             = 1,
    SAY_ELF_RESTING             = 2,
    SAY_ELF_SUMMON2             = 3,
    SAY_ELF_COMPLETE            = 4,
    SAY_ELF_AGGRO               = 5,

    QUEST_ROAD_TO_FALCON_WATCH  = 9375
};

class npc_wounded_blood_elf : public CreatureScript
{
public:
    npc_wounded_blood_elf() : CreatureScript("npc_wounded_blood_elf") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_ROAD_TO_FALCON_WATCH)
        {
            if (npc_escortAI* pEscortAI = CAST_AI(npc_wounded_blood_elf::npc_wounded_blood_elfAI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());

            // Change faction so mobs attack
            creature->setFaction(775);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_wounded_blood_elfAI(creature);
    }

    struct npc_wounded_blood_elfAI : public npc_escortAI
    {
        npc_wounded_blood_elfAI(Creature* creature) : npc_escortAI(creature) { }

        void WaypointReached(uint32 waypointId) OVERRIDE
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (waypointId)
            {
                case 0:
                    Talk(SAY_ELF_START, player->GetGUID());
                    break;
                case 9:
                    Talk(SAY_ELF_SUMMON1, player->GetGUID());
                    // Spawn two Haal'eshi Talonguard
                    DoSpawnCreature(16967, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    DoSpawnCreature(16967, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 13:
                    Talk(SAY_ELF_RESTING, player->GetGUID());
                    break;
                case 14:
                    Talk(SAY_ELF_SUMMON2, player->GetGUID());
                    // Spawn two Haal'eshi Windwalker
                    DoSpawnCreature(16966, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    DoSpawnCreature(16966, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
                    break;
                case 27:
                    Talk(SAY_ELF_COMPLETE, player->GetGUID());
                    // Award quest credit
                    player->GroupEventHappens(QUEST_ROAD_TO_FALCON_WATCH, me);
                    break;
            }
        }

        void Reset() OVERRIDE { }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                Talk(SAY_ELF_AGGRO);
        }

        void JustSummoned(Creature* summoned) OVERRIDE
        {
            summoned->AI()->AttackStart(me);
        }
    };
};

/*######
## npc_fel_guard_hound
######*/

enum FelGuard
{
    SPELL_SUMMON_POO                              = 37688,

    NPC_DERANGED_HELBOAR                          = 16863
};

class npc_fel_guard_hound : public CreatureScript
{
public:
    npc_fel_guard_hound() : CreatureScript("npc_fel_guard_hound") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_fel_guard_houndAI(creature);
    }

    struct npc_fel_guard_houndAI : public ScriptedAI
    {
        npc_fel_guard_houndAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 uiCheckTimer;
        uint64 uiHelboarGUID;

        void Reset() OVERRIDE
        {
            uiCheckTimer = 5000; //check for creature every 5 sec
            uiHelboarGUID = 0;
        }

        void MovementInform(uint32 uiType, uint32 uiId) OVERRIDE
        {
            if (uiType != POINT_MOTION_TYPE || uiId != 1)
                return;

            if (Creature* pHelboar = me->GetCreature(*me, uiHelboarGUID))
            {
                pHelboar->RemoveCorpse();
                DoCast(SPELL_SUMMON_POO);

                if (Player* owner = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                    me->GetMotionMaster()->MoveFollow(owner, 0.0f, 0.0f);
            }
        }

        void UpdateAI(uint32 uiDiff) OVERRIDE
        {
            if (uiCheckTimer <= uiDiff)
            {
                if (Creature* pHelboar = me->FindNearestCreature(NPC_DERANGED_HELBOAR, 10.0f, false))
                {
                    if (pHelboar->GetGUID() != uiHelboarGUID && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && !me->FindCurrentSpellBySpellId(SPELL_SUMMON_POO))
                    {
                        uiHelboarGUID = pHelboar->GetGUID();
                        me->GetMotionMaster()->MovePoint(1, pHelboar->GetPositionX(), pHelboar->GetPositionY(), pHelboar->GetPositionZ());
                    }
                }
                uiCheckTimer = 5000;
            }else uiCheckTimer -= uiDiff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_hellfire_peninsula()
{
    new npc_aeranas();
    new npc_ancestral_wolf();
    new npc_naladu();
    new npc_tracy_proudwell();
    new npc_trollbane();
    new npc_wounded_blood_elf();
    new npc_fel_guard_hound();
}
