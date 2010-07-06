/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_aeranas
######*/

enum eAeranas
{
    SAY_SUMMON              = -1000138,
    SAY_FREE                = -1000139,

    FACTION_HOSTILE         = 16,
    FACTION_FRIENDLY        = 35,

    SPELL_ENVELOPING_WINDS  = 15535,
    SPELL_SHOCK             = 12553,

    C_AERANAS               = 17085
};

struct npc_aeranasAI : public ScriptedAI
{
    npc_aeranasAI(Creature* c) : ScriptedAI(c) {}

    uint32 Faction_Timer;
    uint32 EnvelopingWinds_Timer;
    uint32 Shock_Timer;

    void Reset()
    {
        Faction_Timer = 8000;
        EnvelopingWinds_Timer = 9000;
        Shock_Timer = 5000;

        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        me->setFaction(FACTION_FRIENDLY);

        DoScriptText(SAY_SUMMON, me);
    }

    void UpdateAI(const uint32 diff)
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

        if ((me->GetHealth()*100) / me->GetMaxHealth() < 30)
        {
            me->setFaction(FACTION_FRIENDLY);
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveAllAuras();
            me->DeleteThreatList();
            me->CombatStop(true);
            DoScriptText(SAY_FREE, me);
            return;
        }

        if (Shock_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SHOCK);
            Shock_Timer = 10000;
        } else Shock_Timer -= diff;

        if (EnvelopingWinds_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_ENVELOPING_WINDS);
            EnvelopingWinds_Timer = 25000;
        } else EnvelopingWinds_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_aeranas(Creature* pCreature)
{
    return new npc_aeranasAI (pCreature);
}

/*######
## npc_ancestral_wolf
######*/

enum eAncestralWolf
{
    EMOTE_WOLF_LIFT_HEAD            = -1000496,
    EMOTE_WOLF_HOWL                 = -1000497,
    SAY_WOLF_WELCOME                = -1000498,

    SPELL_ANCESTRAL_WOLF_BUFF       = 29981,

    NPC_RYGA                        = 17123
};

struct npc_ancestral_wolfAI : public npc_escortAI
{
    npc_ancestral_wolfAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        if (pCreature->GetOwner() && pCreature->GetOwner()->GetTypeId() == TYPEID_PLAYER)
            Start(false, false, pCreature->GetOwner()->GetGUID());
        else
            sLog.outError("TRINITY: npc_ancestral_wolf can not obtain owner or owner is not a player.");

        pCreature->SetSpeed(MOVE_WALK, 1.5f);
        Reset();
    }

    Unit* pRyga;

    void Reset()
    {
        pRyga = NULL;
        DoCast(me, SPELL_ANCESTRAL_WOLF_BUFF, true);
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (!pRyga && pWho->GetTypeId() == TYPEID_UNIT && pWho->GetEntry() == NPC_RYGA && me->IsWithinDistInMap(pWho, 15.0f))
            pRyga = pWho;

        npc_escortAI::MoveInLineOfSight(pWho);
    }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                DoScriptText(EMOTE_WOLF_LIFT_HEAD, me);
                break;
            case 2:
                DoScriptText(EMOTE_WOLF_HOWL, me);
                break;
            case 50:
                if (pRyga && pRyga->isAlive() && !pRyga->isInCombat())
                    DoScriptText(SAY_WOLF_WELCOME, pRyga);
                break;
        }
    }
};

CreatureAI* GetAI_npc_ancestral_wolf(Creature* pCreature)
{
    return new npc_ancestral_wolfAI(pCreature);
}

/*######
## go_haaleshi_altar
######*/

bool GOHello_go_haaleshi_altar(Player* /*pPlayer*/, GameObject* pGo)
{
    pGo->SummonCreature(C_AERANAS,-1321.79, 4043.80, 116.24, 1.25, TEMPSUMMON_TIMED_DESPAWN, 180000);
    return false;
}

/*######
## npc_naladu
######*/

#define GOSSIP_NALADU_ITEM1 "Why don't you escape?"

enum eNaladu
{
    GOSSIP_TEXTID_NALADU1   = 9788
};

bool GossipHello_npc_naladu(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_NALADU_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_naladu(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_NALADU1, pCreature->GetGUID());

    return true;
}

/*######
## npc_tracy_proudwell
######*/

#define GOSSIP_TEXT_REDEEM_MARKS        "I have marks to redeem!"
#define GOSSIP_TRACY_PROUDWELL_ITEM1    "I heard that your dog Fei Fei took Klatu's prayer beads..."
#define GOSSIP_TRACY_PROUDWELL_ITEM2    "<back>"

enum eTracy
{
    GOSSIP_TEXTID_TRACY_PROUDWELL1       = 10689,
    QUEST_DIGGING_FOR_PRAYER_BEADS       = 10916
};

bool GossipHello_npc_tracy_proudwell(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isVendor())
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_REDEEM_MARKS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    if (pPlayer->GetQuestStatus(QUEST_DIGGING_FOR_PRAYER_BEADS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TRACY_PROUDWELL_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tracy_proudwell(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TRACY_PROUDWELL_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TRACY_PROUDWELL1, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_TRADE:
            pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
            break;
    }

    return true;
}

/*######
## npc_trollbane
######*/

#define GOSSIP_TROLLBANE_ITEM1      "Tell me of the Sons of Lothar."
#define GOSSIP_TROLLBANE_ITEM2      "<more>"
#define GOSSIP_TROLLBANE_ITEM3      "Tell me of your homeland."

enum eTrollbane
{
    GOSSIP_TEXTID_TROLLBANE1        = 9932,
    GOSSIP_TEXTID_TROLLBANE2        = 9933,
    GOSSIP_TEXTID_TROLLBANE3        = 8772
};

bool GossipHello_npc_trollbane(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_trollbane(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_TROLLBANE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE1, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_TROLLBANE3, pCreature->GetGUID());
            break;
    }

    return true;
}

/*######
## npc_wounded_blood_elf
######*/

enum eWoundedBloodElf
{
    SAY_ELF_START               = -1000117,
    SAY_ELF_SUMMON1             = -1000118,
    SAY_ELF_RESTING             = -1000119,
    SAY_ELF_SUMMON2             = -1000120,
    SAY_ELF_COMPLETE            = -1000121,
    SAY_ELF_AGGRO               = -1000122,

    QUEST_ROAD_TO_FALCON_WATCH  = 9375
};

struct npc_wounded_blood_elfAI : public npc_escortAI
{
    npc_wounded_blood_elfAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (i)
        {
        case 0:
            DoScriptText(SAY_ELF_START, me, pPlayer);
            break;
        case 9:
            DoScriptText(SAY_ELF_SUMMON1, me, pPlayer);
            // Spawn two Haal'eshi Talonguard
            DoSpawnCreature(16967, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            DoSpawnCreature(16967, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            break;
        case 13:
            DoScriptText(SAY_ELF_RESTING, me, pPlayer);
            break;
        case 14:
            DoScriptText(SAY_ELF_SUMMON2, me, pPlayer);
            // Spawn two Haal'eshi Windwalker
            DoSpawnCreature(16966, -15, -15, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            DoSpawnCreature(16966, -17, -17, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
            break;
        case 27:
            DoScriptText(SAY_ELF_COMPLETE, me, pPlayer);
            // Award quest credit
            pPlayer->GroupEventHappens(QUEST_ROAD_TO_FALCON_WATCH,me);
            break;
        }
    }

    void Reset() { }

    void EnterCombat(Unit* /*who*/)
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
            DoScriptText(SAY_ELF_AGGRO, me);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(me);
    }
};

CreatureAI* GetAI_npc_wounded_blood_elf(Creature* pCreature)
{
    return new npc_wounded_blood_elfAI(pCreature);
}

bool QuestAccept_npc_wounded_blood_elf(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_ROAD_TO_FALCON_WATCH)
    {
        if (npc_escortAI* pEscortAI = CAST_AI(npc_wounded_blood_elfAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());

        // Change faction so mobs attack
        pCreature->setFaction(775);
    }

    return true;
}

/*######
## npc_fel_guard_hound
######*/

enum eFelGuard
{
    SPELL_SUMMON_POO                              = 37688,

    NPC_DERANGED_HELBOAR                          = 16863
};

struct npc_fel_guard_houndAI : public ScriptedAI
{
    npc_fel_guard_houndAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiCheckTimer;
    uint64 uiHelboarGUID;

    void Reset()
    {
        uiCheckTimer = 5000; //check for creature every 5 sec
        uiHelboarGUID = 0;
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE || uiId != 1)
            return;

        if (Creature* pHelboar = me->GetCreature(*me,uiHelboarGUID))
        {
            pHelboar->RemoveCorpse();
            DoCast(SPELL_SUMMON_POO);

            if (Player* pOwner = me->GetCharmerOrOwnerPlayerOrPlayerItself())
                me->GetMotionMaster()->MoveFollow(pOwner,0.0f,0.0f);
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (uiCheckTimer <= uiDiff)
        {
            if (Creature* pHelboar = me->FindNearestCreature(NPC_DERANGED_HELBOAR, 10.0f, false))
            {
                if (pHelboar->GetGUID() != uiHelboarGUID && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && !me->FindCurrentSpellBySpellId(SPELL_SUMMON_POO))
                {
                    uiHelboarGUID = pHelboar->GetGUID();
                    me->GetMotionMaster()->MovePoint(1,pHelboar->GetPositionX(),pHelboar->GetPositionY(),pHelboar->GetPositionZ());
                }
            }
            uiCheckTimer = 5000;
        }else uiCheckTimer -= uiDiff;

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_fel_guard_hound(Creature* pCreature)
{
    return new npc_fel_guard_houndAI(pCreature);
}

void AddSC_hellfire_peninsula()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_aeranas";
    newscript->GetAI = &GetAI_npc_aeranas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ancestral_wolf";
    newscript->GetAI = &GetAI_npc_ancestral_wolf;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_haaleshi_altar";
    newscript->pGOHello = &GOHello_go_haaleshi_altar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_naladu";
    newscript->pGossipHello = &GossipHello_npc_naladu;
    newscript->pGossipSelect = &GossipSelect_npc_naladu;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tracy_proudwell";
    newscript->pGossipHello = &GossipHello_npc_tracy_proudwell;
    newscript->pGossipSelect = &GossipSelect_npc_tracy_proudwell;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_trollbane";
    newscript->pGossipHello = &GossipHello_npc_trollbane;
    newscript->pGossipSelect = &GossipSelect_npc_trollbane;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_wounded_blood_elf";
    newscript->GetAI = &GetAI_npc_wounded_blood_elf;
    newscript->pQuestAccept = &QuestAccept_npc_wounded_blood_elf;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_fel_guard_hound";
    newscript->GetAI = &GetAI_npc_fel_guard_hound;
    newscript->RegisterSelf();
}

