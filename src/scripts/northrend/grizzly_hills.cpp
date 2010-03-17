/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Grizzly_Hills
SD%Complete: 80
SDComment: Quest support: 12231, 12247
SDCategory: Grizzly Hills
EndScriptData */

/* ContentData
npc_orsonn_and_kodian
EndContentData */

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"

#define GOSSIP_ITEM1 "You're free to go Orsonn, but first tell me what's wrong with the furbolg."
#define GOSSIP_ITEM2 "What happened then?"
#define GOSSIP_ITEM3 "Thank you, Son of Ursoc. I'll see what can be done."
#define GOSSIP_ITEM4 "Who was this stranger?"
#define GOSSIP_ITEM5 "Thank you, Kodian. I'll do what I can."

enum eEnums
{
    GOSSIP_TEXTID_ORSONN1       = 12793,
    GOSSIP_TEXTID_ORSONN2       = 12794,
    GOSSIP_TEXTID_ORSONN3       = 12796,

    GOSSIP_TEXTID_KODIAN1       = 12797,
    GOSSIP_TEXTID_KODIAN2       = 12798,

    NPC_ORSONN                  = 27274,
    NPC_KODIAN                  = 27275,

    //trigger creatures
    NPC_ORSONN_CREDIT           = 27322,
    NPC_KODIAN_CREDIT           = 27321,

    QUEST_CHILDREN_OF_URSOC     = 12247,
    QUEST_THE_BEAR_GODS_OFFSPRING        = 12231
};

bool GossipHello_npc_orsonn_and_kodian(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_CHILDREN_OF_URSOC) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_THE_BEAR_GODS_OFFSPRING) == QUEST_STATUS_INCOMPLETE)
    {
        switch(pCreature->GetEntry())
        {
            case NPC_ORSONN:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_CHILDREN_OF_URSOC, NPC_ORSONN_CREDIT) || !pPlayer->GetReqKillOrCastCurrentCount(QUEST_THE_BEAR_GODS_OFFSPRING, NPC_ORSONN_CREDIT))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN1, pCreature->GetGUID());
                    return true;
                }
                break;
            case NPC_KODIAN:
                if (!pPlayer->GetReqKillOrCastCurrentCount(QUEST_CHILDREN_OF_URSOC, NPC_KODIAN_CREDIT) || !pPlayer->GetReqKillOrCastCurrentCount(QUEST_THE_BEAR_GODS_OFFSPRING, NPC_KODIAN_CREDIT))
                {
                    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_KODIAN1, pCreature->GetGUID());
                    return true;
                }
                break;
        }
    }

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_orsonn_and_kodian(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ORSONN3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->TalkedToCreature(NPC_ORSONN_CREDIT, pCreature->GetGUID());
            break;

        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_KODIAN2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->TalkedToCreature(NPC_KODIAN_CREDIT, pCreature->GetGUID());
            break;
    }

    return true;
}

/*######
## Quest 12027: Mr. Floppy's Perilous Adventure
######*/

enum eFloppy
{
    NPC_MRFLOPPY                = 26589,
    NPC_HUNGRY_WORG             = 26586,
    NPC_RAVENOUS_WORG           = 26590,   //RWORG
    NPC_EMILY                   = 26588,
    
    QUEST_PERILOUS_ADVENTURE    = 12027,
    
    SPELL_MRFLOPPY              = 47184,    //vehicle aura
    
    SAY_WORGHAGGRO1             = -1800001, //Um... I think one of those wolves is back...
    SAY_WORGHAGGRO2             = -1800002, //He's going for Mr. Floppy!
    SAY_WORGRAGGRO3             = -1800003, //Oh, no! Look, it's another wolf, and it's a biiiiiig one!
    SAY_WORGRAGGRO4             = -1800004, //He's gonna eat Mr. Floppy! You gotta help Mr. Floppy! You just gotta!
    SAY_RANDOMAGGRO             = -1800005, //There's a big meanie attacking Mr. Floppy! Help!
    SAY_VICTORY1                = -1800006, //Let's get out of here before more wolves find us!
    SAY_VICTORY2                = -1800007, //Don't go toward the light, Mr. Floppy!
    SAY_VICTORY3                = -1800008, //Mr. Floppy, you're ok! Thank you so much for saving Mr. Floppy!
    SAY_VICTORY4                = -1800009, //I think I see the camp! We're almost home, Mr. Floppy! Let's go!
    TEXT_EMOTE_WP1              = -1800010, //Mr. Floppy revives
    TEXT_EMOTE_AGGRO            = -1800011, //The Ravenous Worg chomps down on Mr. Floppy
    SAY_QUEST_ACCEPT            = -1800012, //Are you ready, Mr. Floppy? Stay close to me and watch out for those wolves!
    SAY_QUEST_COMPLETE          = -1800013  //Thank you for helping me get back to the camp. Go tell Walter that I'm safe now!
};

//emily
struct npc_emilyAI : public npc_escortAI
{
    npc_emilyAI(Creature* pCreature) : npc_escortAI(pCreature) { }
    
    uint32 m_uiChatTimer;
    
    uint64 RWORGGUID;
    uint64 MrfloppyGUID;
    
    Creature* Mrfloppy;
    Creature* RWORG;
    bool Completed;
    
    
    void JustSummoned(Creature* pSummoned)
    {
        if (Creature* Mrfloppy = GetClosestCreatureWithEntry(m_creature, NPC_MRFLOPPY, 50.0f))
            pSummoned->AI()->AttackStart(Mrfloppy);
        else
            pSummoned->AI()->AttackStart(m_creature->getVictim());
    }
    
    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;
        switch (i)
        {
            case 9:
                Mrfloppy = GetClosestCreatureWithEntry(m_creature, NPC_MRFLOPPY, 100.0f);
                break;
            case 10:
                if (Mrfloppy)
                {
                    DoScriptText(SAY_WORGHAGGRO1, m_creature);
                    m_creature->SummonCreature(NPC_HUNGRY_WORG,m_creature->GetPositionX()+5,m_creature->GetPositionY()+2,m_creature->GetPositionZ()+1,3.229f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,120000);
                }
                break;
            case 11:
                Mrfloppy->GetMotionMaster()->MoveFollow(m_creature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                break;
            case 17:
                Mrfloppy->GetMotionMaster()->MovePoint(0, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ());
                DoScriptText(SAY_WORGRAGGRO3, m_creature);
                RWORG = m_creature->SummonCreature(NPC_RAVENOUS_WORG,m_creature->GetPositionX()+10,m_creature->GetPositionY()+8,m_creature->GetPositionZ()+2,3.229f,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,120000);
                RWORG->setFaction(35);
                break;
            case 18:
                if (Mrfloppy)
                {
                    RWORG->GetMotionMaster()->MovePoint(0, Mrfloppy->GetPositionX(), Mrfloppy->GetPositionY(), Mrfloppy->GetPositionZ());
                    DoCast(Mrfloppy,SPELL_MRFLOPPY);
                }
                break;
            case 19:
                if (Mrfloppy->HasAura(SPELL_MRFLOPPY, 0))
                    Mrfloppy->EnterVehicle(RWORG);
                break;
            case 20:
                if (Mrfloppy)
                    RWORG->HandleEmoteCommand(34);
                break;
            case 21:
                if (Mrfloppy)
                {
                    RWORG->Kill(Mrfloppy);
                    Mrfloppy->ExitVehicle();
                    RWORG->setFaction(14);
                    RWORG->GetMotionMaster()->MovePoint(0, RWORG->GetPositionX()+10,RWORG->GetPositionY()+80,RWORG->GetPositionZ());
                    DoScriptText(SAY_VICTORY2, m_creature);
                }
                break;
            case 22:
                if (Mrfloppy && Mrfloppy->isDead())
                {
                    RWORG->DisappearAndDie();
                    m_creature->GetMotionMaster()->MovePoint(0, Mrfloppy->GetPositionX(), Mrfloppy->GetPositionY(), Mrfloppy->GetPositionZ());
                    Mrfloppy->setDeathState(ALIVE);
                    Mrfloppy->GetMotionMaster()->MoveFollow(m_creature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                    DoScriptText(SAY_VICTORY3, m_creature);
                }
                break;
            case 24:
                if (pPlayer)
                {
                    Completed = true;
                    pPlayer->GroupEventHappens(QUEST_PERILOUS_ADVENTURE, m_creature);
                    DoScriptText(SAY_QUEST_COMPLETE, m_creature, pPlayer);
                }
                m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE);
                break;
            case 25:
                DoScriptText(SAY_VICTORY4, m_creature);
                break;
            case 27:
                m_creature->DisappearAndDie();
                if (Mrfloppy)
                    Mrfloppy->DisappearAndDie();
                break;
        }
    }
    
    void EnterCombat(Unit* Who)
    {
        DoScriptText(SAY_RANDOMAGGRO, m_creature);
    }
    
    void Reset()
    {
        m_uiChatTimer = 4000;
        Mrfloppy = NULL;
        RWORG = NULL;
    }
    
    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);
        
        if (HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (m_uiChatTimer <= uiDiff)
            {
                m_uiChatTimer = 12000;
            }
            else
                m_uiChatTimer -= uiDiff;
        }
    }
};


bool QuestAccept_npc_emily(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_PERILOUS_ADVENTURE)
    {
        DoScriptText(SAY_QUEST_ACCEPT, pCreature);
        if (Creature* Mrfloppy = GetClosestCreatureWithEntry(pCreature, NPC_MRFLOPPY, 180.0f))
        {
            Mrfloppy->GetMotionMaster()->MoveFollow(pCreature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
        }
        
        if (npc_escortAI* pEscortAI = CAST_AI(npc_emilyAI, (pCreature->AI())))
            pEscortAI->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_emily(Creature* pCreature)
{
    return new npc_emilyAI(pCreature);
}

//mrfloppy

struct npc_mrfloppyAI : public ScriptedAI
{
    npc_mrfloppyAI(Creature *c) : ScriptedAI(c) {}
    
    uint64 EmilyGUID;
    uint64 RWORGGUID;
    uint64 HWORGGUID;
    
    Creature* HWORG;
    Creature* RWORG;
    
    Creature* Emily;
    
    void Reset()
    {
        HWORG = NULL;
        RWORG = NULL;
        Emily = NULL;
    }
    
    void EnterCombat(Unit* Who)
    {
        if (Creature* Emily = GetClosestCreatureWithEntry(m_creature, NPC_EMILY, 50.0f))
        {
            switch(Who->GetEntry())
            {
                case NPC_HUNGRY_WORG:
                    DoScriptText(SAY_WORGHAGGRO2, Emily);
                    break;
                case NPC_RAVENOUS_WORG:
                    DoScriptText(SAY_WORGRAGGRO4, Emily);
                    break;
                default:
                    DoScriptText(SAY_RANDOMAGGRO, Emily);
            }
        }
    }
    
    void EnterEvadeMode() {}
    
    void MoveInLineOfSight(Unit *who) {}
    
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_mrfloppy(Creature* pCreature)
{
    return new npc_mrfloppyAI(pCreature);
}

// Outhouse Bunny

enum eOuthouseBunny
{
    SPELL_OUTHOUSE_GROANS           = 48382,
    SPELL_CAMERA_SHAKE              = 47533,
    SPELL_DUST_FIELD                = 48329
};

enum eSounds
{    SOUND_FEMALE        = 12671,    SOUND_MALE          = 12670};
struct npc_outhouse_bunnyAI : public ScriptedAI
{
    npc_outhouse_bunnyAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint8 m_counter;
    uint8 m_gender;

    void Reset()
    {
        m_counter = 0;
        m_gender = 0;
    }

    void SetData(uint32 uiType, uint32 uiData)
    {
        if (uiType == 1)
            m_gender = uiData;
    }
	
    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
         if (pSpell->Id == SPELL_OUTHOUSE_GROANS)
        {
            ++m_counter;
            if (m_counter < 5)
                DoCast(pCaster, SPELL_CAMERA_SHAKE, true);
            else
                m_counter = 0;
            DoCast(me, SPELL_DUST_FIELD, true);
            switch (m_gender)
            {
                case GENDER_FEMALE: DoPlaySoundToSet(m_creature, SOUND_FEMALE); break;
                case GENDER_MALE: DoPlaySoundToSet(m_creature, SOUND_MALE); break;
            }
        }
    }
};

CreatureAI* GetAI_npc_outhouse_bunny(Creature* pCreature)
{
    return new npc_outhouse_bunnyAI (pCreature);
}

// Tallhorn Stage

enum etallhornstage
{
    OBJECT_HAUNCH                   = 188665
};

struct npc_tallhorn_stagAI : public ScriptedAI
{
    npc_tallhorn_stagAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void UpdateAI(const uint32 uiDiff)
    {
        if (GameObject* haunch = me->FindNearestGameObject(OBJECT_HAUNCH, 2.0f))
        {
            me->SetStandState(UNIT_STAND_STATE_DEAD);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD);
        }
    }
};

CreatureAI* GetAI_npc_tallhorn_stag(Creature* pCreature)
{
    return new npc_tallhorn_stagAI (pCreature);
}

// Amberpine Woodsman

enum eamberpinewoodsman
{
    TALLHORN_STAG                   = 26363
};

struct npc_amberpine_woodsmanAI : public ScriptedAI
{
    npc_amberpine_woodsmanAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint8 m_uiPhase;
    uint32 m_uiTimer;

    void Reset()
    {
        m_uiTimer = 0;
        m_uiPhase = 1;
    }	
	
	void UpdateAI(const uint32 uiDiff)
    {	
		if (Creature* stag = me->FindNearestCreature(TALLHORN_STAG, 0.2f))
		{
            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USESTANDING);
        }
		else
            if (m_uiPhase)
            {
                if (m_uiTimer <= uiDiff)
                {
                    switch(m_uiPhase)
                    {
                        case 1:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_LOOT);
                            m_uiTimer = 3000;
                            m_uiPhase = 2;
                            break;						
                        case 2:
                            me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_ONESHOT_ATTACK1H);
                            m_uiTimer = 4000;
                            m_uiPhase = 1;
                            break;
                    }
                }
                else
                m_uiTimer -= uiDiff;
            }
            ScriptedAI::UpdateAI(uiDiff);		
        
        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_amberpine_woodsman(Creature* pCreature)
{
    return new npc_amberpine_woodsmanAI (pCreature);
}

void AddSC_grizzly_hills()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_orsonn_and_kodian";
    newscript->pGossipHello = &GossipHello_npc_orsonn_and_kodian;
    newscript->pGossipSelect = &GossipSelect_npc_orsonn_and_kodian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_emily";
    newscript->GetAI = &GetAI_npc_emily;
    newscript->pQuestAccept = &QuestAccept_npc_emily;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "npc_mrfloppy";
    newscript->GetAI = &GetAI_npc_mrfloppy;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_outhouse_bunny";
    newscript->GetAI = &GetAI_npc_outhouse_bunny;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tallhorn_stag";
    newscript->GetAI = &GetAI_npc_tallhorn_stag;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_amberpine_woodsman";
    newscript->GetAI = &GetAI_npc_amberpine_woodsman;
    newscript->RegisterSelf();
}
