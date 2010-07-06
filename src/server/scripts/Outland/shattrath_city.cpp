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
SDName: Shattrath_City
SD%Complete: 100
SDComment: Quest support: 10004, 10009, 10211, 10231. Flask vendors, Teleport to Caverns of Time
SDCategory: Shattrath City
EndScriptData */

/* ContentData
npc_raliq_the_drunk
npc_salsalabim
npc_shattrathflaskvendors
npc_zephyr
npc_kservant
npc_dirty_larry
npc_ishanah
npc_khadgar
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_raliq_the_drunk
######*/

#define GOSSIP_RALIQ            "You owe Sim'salabim money. Hand them over or die!"

enum eRaliq
{
    SPELL_UPPERCUT          = 10966,
    QUEST_CRACK_SKULLS      = 10009,
    FACTION_HOSTILE_RD      = 45
};

struct npc_raliq_the_drunkAI : public ScriptedAI
{
    npc_raliq_the_drunkAI(Creature* c) : ScriptedAI(c)
    {
        m_uiNormFaction = c->getFaction();
    }

    uint32 m_uiNormFaction;
    uint32 Uppercut_Timer;

    void Reset()
    {
        Uppercut_Timer = 5000;
        me->RestoreFaction();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (Uppercut_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_UPPERCUT);
            Uppercut_Timer = 15000;
        } else Uppercut_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_raliq_the_drunk(Creature* pCreature)
{
    return new npc_raliq_the_drunkAI (pCreature);
}

bool GossipHello_npc_raliq_the_drunk(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_CRACK_SKULLS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_RALIQ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(9440, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_raliq_the_drunk(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->setFaction(FACTION_HOSTILE_RD);
        pCreature->AI()->AttackStart(pPlayer);
    }
    return true;
}

/*######
# npc_salsalabim
######*/

#define FACTION_HOSTILE_SA              90
#define FACTION_FRIENDLY_SA             35
#define QUEST_10004                     10004

#define SPELL_MAGNETIC_PULL             31705

struct npc_salsalabimAI : public ScriptedAI
{
    npc_salsalabimAI(Creature* c) : ScriptedAI(c) {}

    uint32 MagneticPull_Timer;

    void Reset()
    {
        MagneticPull_Timer = 15000;
        me->RestoreFaction();
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (done_by->GetTypeId() == TYPEID_PLAYER)
            if ((me->GetHealth()-damage)*100 / me->GetMaxHealth() < 20)
        {
            CAST_PLR(done_by)->GroupEventHappens(QUEST_10004,me);
            damage = 0;
            EnterEvadeMode();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (MagneticPull_Timer <= diff)
        {
            DoCast(me->getVictim(), SPELL_MAGNETIC_PULL);
            MagneticPull_Timer = 15000;
        } else MagneticPull_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_salsalabim(Creature* pCreature)
{
    return new npc_salsalabimAI (pCreature);
}

bool GossipHello_npc_salsalabim(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_10004) == QUEST_STATUS_INCOMPLETE)
    {
        pCreature->setFaction(FACTION_HOSTILE_SA);
        pCreature->AI()->AttackStart(pPlayer);
    }
    else
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    }
    return true;
}

/*
##################################################
Shattrath City Flask Vendors provides flasks to people exalted with 3 factions:
Haldor the Compulsive
Arcanist Xorith
Both sell special flasks for use in Outlands 25man raids only,
purchasable for one Mark of Illidari each
Purchase requires exalted reputation with Scryers/Aldor, Cenarion Expedition and The Sha'tar
##################################################
*/

bool GossipHello_npc_shattrathflaskvendors(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->GetEntry() == 23484)
    {
        // Aldor vendor
        if (pCreature->isVendor() && (pPlayer->GetReputationRank(932) == REP_EXALTED) && (pPlayer->GetReputationRank(935) == REP_EXALTED) && (pPlayer->GetReputationRank(942) == REP_EXALTED))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            pPlayer->SEND_GOSSIP_MENU(11085, pCreature->GetGUID());
        }
        else
        {
            pPlayer->SEND_GOSSIP_MENU(11083, pCreature->GetGUID());
        }
    }

    if (pCreature->GetEntry() == 23483)
    {
        // Scryers vendor
        if (pCreature->isVendor() && (pPlayer->GetReputationRank(934) == REP_EXALTED) && (pPlayer->GetReputationRank(935) == REP_EXALTED) && (pPlayer->GetReputationRank(942) == REP_EXALTED))
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            pPlayer->SEND_GOSSIP_MENU(11085, pCreature->GetGUID());
        }
        else
        {
            pPlayer->SEND_GOSSIP_MENU(11084, pCreature->GetGUID());
        }
    }

    return true;
}

bool GossipSelect_npc_shattrathflaskvendors(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

    return true;
}

/*######
# npc_zephyr
######*/

#define GOSSIP_HZ "Take me to the Caverns of Time."

bool GossipHello_npc_zephyr(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetReputationRank(989) >= REP_REVERED)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HZ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_zephyr(Player* pPlayer, Creature* /*pCreature*/, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        pPlayer->CastSpell(pPlayer,37778,false);

    return true;
}

/*######
# npc_kservant
######*/

#define SAY1       -1000234
#define WHISP1     -1000235
#define WHISP2     -1000236
#define WHISP3     -1000237
#define WHISP4     -1000238
#define WHISP5     -1000239
#define WHISP6     -1000240
#define WHISP7     -1000241
#define WHISP8     -1000242
#define WHISP9     -1000243
#define WHISP10    -1000244
#define WHISP11    -1000245
#define WHISP12    -1000246
#define WHISP13    -1000247
#define WHISP14    -1000248
#define WHISP15    -1000249
#define WHISP16    -1000250
#define WHISP17    -1000251
#define WHISP18    -1000252
#define WHISP19    -1000253
#define WHISP20    -1000254
#define WHISP21    -1000255

struct npc_kservantAI : public npc_escortAI
{
public:
    npc_kservantAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch(i)
        {
            case 0: DoScriptText(SAY1, me, pPlayer); break;
            case 4: DoScriptText(WHISP1, me, pPlayer); break;
            case 6: DoScriptText(WHISP2, me, pPlayer); break;
            case 7: DoScriptText(WHISP3, me, pPlayer); break;
            case 8: DoScriptText(WHISP4, me, pPlayer); break;
            case 17: DoScriptText(WHISP5, me, pPlayer); break;
            case 18: DoScriptText(WHISP6, me, pPlayer); break;
            case 19: DoScriptText(WHISP7, me, pPlayer); break;
            case 33: DoScriptText(WHISP8, me, pPlayer); break;
            case 34: DoScriptText(WHISP9, me, pPlayer); break;
            case 35: DoScriptText(WHISP10, me, pPlayer); break;
            case 36: DoScriptText(WHISP11, me, pPlayer); break;
            case 43: DoScriptText(WHISP12, me, pPlayer); break;
            case 44: DoScriptText(WHISP13, me, pPlayer); break;
            case 49: DoScriptText(WHISP14, me, pPlayer); break;
            case 50: DoScriptText(WHISP15, me, pPlayer); break;
            case 51: DoScriptText(WHISP16, me, pPlayer); break;
            case 52: DoScriptText(WHISP17, me, pPlayer); break;
            case 53: DoScriptText(WHISP18, me, pPlayer); break;
            case 54: DoScriptText(WHISP19, me, pPlayer); break;
            case 55: DoScriptText(WHISP20, me, pPlayer); break;
            case 56: DoScriptText(WHISP21, me, pPlayer);
                if (pPlayer)
                    pPlayer->GroupEventHappens(10211,me);
                break;
        }
    }

    void MoveInLineOfSight(Unit* pWho)
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        if (pWho->GetTypeId() == TYPEID_PLAYER)
        {
            if (CAST_PLR(pWho)->GetQuestStatus(10211) == QUEST_STATUS_INCOMPLETE)
            {
                float Radius = 10.0;
                if (me->IsWithinDistInMap(pWho, Radius))
                {
                    Start(false, false, pWho->GetGUID());
                }
            }
        }
    }

    void Reset() {}
};
CreatureAI* GetAI_npc_kservantAI(Creature* pCreature)
{
    return new npc_kservantAI(pCreature);
}

/*######
# npc_dirty_larry
######*/

#define GOSSIP_BOOK "Ezekiel said that you might have a certain book..."

#define SAY_1       -1000274
#define SAY_2       -1000275
#define SAY_3       -1000276
#define SAY_4       -1000277
#define SAY_5       -1000278
#define SAY_GIVEUP  -1000279

#define QUEST_WBI       10231
#define NPC_CREEPJACK   19726
#define NPC_MALONE      19725

struct npc_dirty_larryAI : public ScriptedAI
{
    npc_dirty_larryAI(Creature* c) : ScriptedAI(c) {}

    bool Event;
    bool Attack;
    bool Done;

    uint64 PlayerGUID;

    uint32 SayTimer;
    uint32 Step;

    void Reset()
    {
        Event = false;
        Attack = false;
        Done = false;

        PlayerGUID = 0;
        SayTimer = 0;
        Step = 0;

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->setFaction(1194);
        Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
        if (Creepjack)
        {
            CAST_CRE(Creepjack)->AI()->EnterEvadeMode();
            Creepjack->setFaction(1194);
            Creepjack->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
        Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
        if (Malone)
        {
            CAST_CRE(Malone)->AI()->EnterEvadeMode();
            Malone->setFaction(1194);
            Malone->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    uint32 NextStep(uint32 Step)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        switch(Step)
        {
        case 0:{ me->SetInFront(pPlayer);
            Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
            if (Creepjack)
                Creepjack->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
            if (Malone)
                Malone->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP); }return 2000;
        case 1: DoScriptText(SAY_1, me, pPlayer); return 3000;
        case 2: DoScriptText(SAY_2, me, pPlayer); return 5000;
        case 3: DoScriptText(SAY_3, me, pPlayer); return 2000;
        case 4: DoScriptText(SAY_4, me, pPlayer); return 2000;
        case 5: DoScriptText(SAY_5, me, pPlayer); return 2000;
        case 6: Attack = true; return 2000;
        default: return 0;
        }
    }

    void EnterCombat(Unit* /*who*/){}

    void UpdateAI(const uint32 diff)
    {
        if (SayTimer <= diff)
        {
            if (Event)
                SayTimer = NextStep(++Step);
        } else SayTimer -= diff;

        if (Attack)
        {
            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            me->setFaction(14);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (pPlayer)
            {
            Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
            if (Creepjack)
            {
                Creepjack->Attack(pPlayer, true);
                Creepjack->setFaction(14);
                Creepjack->GetMotionMaster()->MoveChase(pPlayer);
                Creepjack->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
            if (Malone)
            {
                Malone->Attack(pPlayer, true);
                Malone->setFaction(14);
                Malone->GetMotionMaster()->MoveChase(pPlayer);
                Malone->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
                DoStartMovement(pPlayer);
                AttackStart(pPlayer);
            }
            Attack = false;
        }

        if ((me->GetHealth()*100)/me->GetMaxHealth() < 5 && !Done)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->RemoveAllAuras();

            Unit* Creepjack = me->FindNearestCreature(NPC_CREEPJACK, 20);
            if (Creepjack)
            {
                CAST_CRE(Creepjack)->AI()->EnterEvadeMode();
                Creepjack->setFaction(1194);
                Creepjack->GetMotionMaster()->MoveTargetedHome();
                Creepjack->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            Unit* Malone = me->FindNearestCreature(NPC_MALONE, 20);
            if (Malone)
            {
                CAST_CRE(Malone)->AI()->EnterEvadeMode();
                Malone->setFaction(1194);
                Malone->GetMotionMaster()->MoveTargetedHome();
                Malone->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
            me->setFaction(1194);
            Done = true;
            DoScriptText(SAY_GIVEUP, me, NULL);
            me->DeleteThreatList();
            me->CombatStop();
            me->GetMotionMaster()->MoveTargetedHome();
            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            if (pPlayer)
                CAST_PLR(pPlayer)->GroupEventHappens(QUEST_WBI, me);
        }
        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_dirty_larry(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_WBI) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_BOOK, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_dirty_larry(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        CAST_AI(npc_dirty_larryAI, pCreature->AI())->Event = true;
        CAST_AI(npc_dirty_larryAI, pCreature->AI())->PlayerGUID = pPlayer->GetGUID();
        pPlayer->CLOSE_GOSSIP_MENU();
    }

    return true;
}

CreatureAI* GetAI_npc_dirty_larryAI(Creature* pCreature)
{
    return new npc_dirty_larryAI (pCreature);
}

/*######
# npc_ishanah
######*/

#define ISANAH_GOSSIP_1 "Who are the Sha'tar?"
#define ISANAH_GOSSIP_2 "Isn't Shattrath a draenei city? Why do you allow others here?"

bool GossipHello_npc_ishanah(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ISANAH_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ISANAH_GOSSIP_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_ishanah(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
        pPlayer->SEND_GOSSIP_MENU(9458, pCreature->GetGUID());
    else if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
        pPlayer->SEND_GOSSIP_MENU(9459, pCreature->GetGUID());

    return true;
}

/*######
# npc_khadgar
######*/

#define KHADGAR_GOSSIP_1    "I've heard your name spoken only in whispers, mage. Who are you?"
#define KHADGAR_GOSSIP_2    "Go on, please."
#define KHADGAR_GOSSIP_3    "I see." //6th too this
#define KHADGAR_GOSSIP_4    "What did you do then?"
#define KHADGAR_GOSSIP_5    "What happened next?"
#define KHADGAR_GOSSIP_7    "There was something else I wanted to ask you."

bool GossipHello_npc_khadgar(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (!pPlayer->hasQuest(10211))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        pPlayer->SEND_GOSSIP_MENU(9243, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_khadgar(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
    case GOSSIP_ACTION_INFO_DEF+1:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->SEND_GOSSIP_MENU(9876, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+2:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
        pPlayer->SEND_GOSSIP_MENU(9877, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+3:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
        pPlayer->SEND_GOSSIP_MENU(9878, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+4:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
        pPlayer->SEND_GOSSIP_MENU(9879, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+5:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+6);
        pPlayer->SEND_GOSSIP_MENU(9880, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+6:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+7);
        pPlayer->SEND_GOSSIP_MENU(9881, pCreature->GetGUID());
        break;
    case GOSSIP_ACTION_INFO_DEF+7:
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, KHADGAR_GOSSIP_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(9243, pCreature->GetGUID());
        break;
    }
    return true;
}

void AddSC_shattrath_city()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_raliq_the_drunk";
    newscript->GetAI = &GetAI_npc_raliq_the_drunk;
    newscript->pGossipHello =  &GossipHello_npc_raliq_the_drunk;
    newscript->pGossipSelect = &GossipSelect_npc_raliq_the_drunk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_salsalabim";
    newscript->GetAI = &GetAI_npc_salsalabim;
    newscript->pGossipHello =  &GossipHello_npc_salsalabim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_shattrathflaskvendors";
    newscript->pGossipHello =  &GossipHello_npc_shattrathflaskvendors;
    newscript->pGossipSelect = &GossipSelect_npc_shattrathflaskvendors;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_zephyr";
    newscript->pGossipHello =  &GossipHello_npc_zephyr;
    newscript->pGossipSelect = &GossipSelect_npc_zephyr;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_kservant";
    newscript->GetAI = &GetAI_npc_kservantAI;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dirty_larry";
    newscript->GetAI = &GetAI_npc_dirty_larryAI;
    newscript->pGossipHello =   &GossipHello_npc_dirty_larry;
    newscript->pGossipSelect = &GossipSelect_npc_dirty_larry;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ishanah";
    newscript->pGossipHello =  &GossipHello_npc_ishanah;
    newscript->pGossipSelect = &GossipSelect_npc_ishanah;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_khadgar";
    newscript->pGossipHello =  &GossipHello_npc_khadgar;
    newscript->pGossipSelect = &GossipSelect_npc_khadgar;
    newscript->RegisterSelf();
}

