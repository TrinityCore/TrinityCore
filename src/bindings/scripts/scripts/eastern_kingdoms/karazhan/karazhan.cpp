 /* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Karazhan
SD%Complete: 100
SDComment: Support for Barnes (Opera controller) and Berthold (Doorman), Support for Quest 9645.
SDCategory: Karazhan
EndScriptData */

/* ContentData
npc_barnes
npc_berthold
npc_image_of_medivh
EndContentData */

#include "precompiled.h"
#include "def_karazhan.h"
#include "escort_ai.h"

/*######
# npc_barnesAI
######*/

#define GOSSIP_READY        "I'm not an actor."

#define SAY_READY           "Splendid, I'm going to get the audience ready. Break a leg!"
#define SAY_OZ_INTRO1       "Finally, everything is in place. Are you ready for your big stage debut?"
#define OZ_GOSSIP1          "I'm not an actor."
#define SAY_OZ_INTRO2       "Don't worry, you'll be fine. You look like a natural!"
#define OZ_GOSSIP2          "Ok, I'll give it a try, then."

#define SAY_RAJ_INTRO1      "The romantic plays are really tough, but you'll do better this time. You have TALENT. Ready?"
#define RAJ_GOSSIP1         "I've never been more ready."

#define OZ_GM_GOSSIP1       "[GM] Change event to EVENT_OZ"
#define OZ_GM_GOSSIP2       "[GM] Change event to EVENT_HOOD"
#define OZ_GM_GOSSIP3       "[GM] Change event to EVENT_RAJ"

struct Dialogue
{
    int32 textid;
    uint32 timer;
};

static Dialogue OzDialogue[]=
{
    {-1532103, 6000},
    {-1532104, 18000},
    {-1532105, 9000},
    {-1532106, 15000}
};

static Dialogue HoodDialogue[]=
{
    {-1532107, 6000},
    {-1532108, 10000},
    {-1532109, 14000},
    {-1532110, 15000}
};

static Dialogue RAJDialogue[]=
{
    {-1532111, 5000},
    {-1532112, 7000},
    {-1532113, 14000},
    {-1532114, 14000}
};

// Entries and spawn locations for creatures in Oz event
float Spawns[6][2]=
{
    {17535, -10896},                                        // Dorothee
    {17546, -10891},                                        // Roar
    {17547, -10884},                                        // Tinhead
    {17543, -10902},                                        // Strawman
    {17603, -10892},                                        // Grandmother
    {17534, -10900},                                        // Julianne
};

#define CREATURE_SPOTLIGHT  19525

#define SPELL_SPOTLIGHT     25824
#define SPELL_TUXEDO        32616

#define SPAWN_Z             90.5
#define SPAWN_Y             -1758
#define SPAWN_O             4.738

struct TRINITY_DLL_DECL npc_barnesAI : public npc_escortAI
{
    npc_barnesAI(Creature* c) : npc_escortAI(c)
    {
        RaidWiped = false;
        m_uiEventId = 0;
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint64 m_uiSpotlightGUID;

    uint32 TalkCount;
    uint32 TalkTimer;
    uint32 WipeTimer;
    uint32 m_uiEventId;

    bool PerformanceReady;
    bool RaidWiped;

    void Reset()
    {
        m_uiSpotlightGUID = 0;

        TalkCount = 0;
        TalkTimer = 2000;
        WipeTimer = 5000;

        PerformanceReady = false;

        if (pInstance)
            m_uiEventId = pInstance->GetData(DATA_OPERA_PERFORMANCE);
    }

    void StartEvent()
    {
        if (!pInstance)
            return;

        pInstance->SetData(TYPE_OPERA, IN_PROGRESS);

        //resets count for this event, in case earlier failed
        if (m_uiEventId == EVENT_OZ)
            pInstance->SetData(DATA_OPERA_OZ_DEATHCOUNT, IN_PROGRESS);

        Start(false, false);
    }

    void EnterCombat(Unit* who) {}

    void WaypointReached(uint32 i)
    {
        if (!pInstance)
            return;

        switch(i)
        {
            case 0:
                m_creature->CastSpell(m_creature, SPELL_TUXEDO, false);
                pInstance->DoUseDoorOrButton(pInstance->GetData64(DATA_GO_STAGEDOORLEFT));
                break;
            case 4:
                TalkCount = 0;
                SetEscortPaused(true);

                if (Creature* pSpotlight = m_creature->SummonCreature(CREATURE_SPOTLIGHT,
                    m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0.0f,
                    TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000))
                {
                    pSpotlight->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    pSpotlight->CastSpell(pSpotlight, SPELL_SPOTLIGHT, false);
                    m_uiSpotlightGUID = pSpotlight->GetGUID();
                }
                break;
            case 8:
                pInstance->DoUseDoorOrButton(pInstance->GetData64(DATA_GO_STAGEDOORLEFT));
                PerformanceReady = true;
                break;
            case 9:
                PrepareEncounter();
                pInstance->DoUseDoorOrButton(pInstance->GetData64(DATA_GO_CURTAINS));
                break;
        }
    }

    void Talk(uint32 count)
    {
        int32 text = 0;

        switch(m_uiEventId)
        {
            case EVENT_OZ:
                if (OzDialogue[count].textid)
                     text = OzDialogue[count].textid;
                if (OzDialogue[count].timer)
                    TalkTimer = OzDialogue[count].timer;
                break;

            case EVENT_HOOD:
                if (HoodDialogue[count].textid)
                    text = HoodDialogue[count].textid;
                if (HoodDialogue[count].timer)
                    TalkTimer = HoodDialogue[count].timer;
                break;

            case EVENT_RAJ:
                 if (RAJDialogue[count].textid)
                     text = RAJDialogue[count].textid;
                if (RAJDialogue[count].timer)
                    TalkTimer = RAJDialogue[count].timer;
                break;
        }

        if (text)
             DoScriptText(text, m_creature);
    }

    void PrepareEncounter()
    {
        debug_log("TSCR: Barnes Opera Event - Introduction complete - preparing encounter %d", m_uiEventId);
        uint8 index = 0;
        uint8 count = 0;

        switch(m_uiEventId)
        {
            case EVENT_OZ:
                index = 0;
                count = 4;
                break;
            case EVENT_HOOD:
                index = 4;
                count = index+1;
                break;
            case EVENT_RAJ:
                index = 5;
                count = index+1;
                break;
        }

        for(; index < count; ++index)
        {
            uint32 entry = ((uint32)Spawns[index][0]);
            float PosX = Spawns[index][1];

            if (Creature* pCreature = m_creature->SummonCreature(entry, PosX, SPAWN_Y, SPAWN_Z, SPAWN_O, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, HOUR*2*IN_MILISECONDS))
            {
                // In case database has bad flags
                pCreature->SetUInt32Value(UNIT_FIELD_FLAGS, 0);
                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        RaidWiped = false;
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);

        if (HasEscortState(STATE_ESCORT_PAUSED))
        {
            if (TalkTimer < diff)
            {
                if (TalkCount > 3)
                {
                    if (Creature* pSpotlight = Unit::GetCreature(*m_creature, m_uiSpotlightGUID))
                        pSpotlight->ForcedDespawn();

                    SetEscortPaused(false);
                    return;
                }

                Talk(TalkCount);
                ++TalkCount;
            }
            else
                TalkTimer -= diff;
        }

        if (PerformanceReady)
        {
            if (!RaidWiped)
            {
                if (WipeTimer < diff)
                {
                    Map* pMap = m_creature->GetMap();
                    if (!pMap->IsDungeon()) return;

                    Map::PlayerList const &PlayerList = pMap->GetPlayers();
                    if (PlayerList.isEmpty())
                        return;

                    RaidWiped = true;
                    for(Map::PlayerList::const_iterator i = PlayerList.begin();i != PlayerList.end(); ++i)
                    {
                        if (i->getSource()->isAlive() && !i->getSource()->isGameMaster())
                        {
                            RaidWiped = false;
                            break;
                        }
                    }

                    if (RaidWiped)
                    {
                        RaidWiped = true;
                        EnterEvadeMode();
                        return;
                    }

                    WipeTimer = 15000;
                }else WipeTimer -= diff;
            }

        }
    }
};

CreatureAI* GetAI_npc_barnesAI(Creature* pCreature)
{
    return new npc_barnesAI(pCreature);
}

bool GossipHello_npc_barnes(Player* pPlayer, Creature* pCreature)
{
    if (ScriptedInstance* pInstance = pCreature->GetInstanceData())
    {
        // Check for death of Moroes and if opera event is not done already
        if (pInstance->GetData(TYPE_MOROES) == DONE && pInstance->GetData(TYPE_OPERA) != DONE)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, OZ_GOSSIP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            if (pPlayer->isGameMaster())
            {
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, OZ_GM_GOSSIP1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, OZ_GM_GOSSIP2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, OZ_GM_GOSSIP3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }

            if (npc_barnesAI* pBarnesAI = CAST_AI(npc_barnesAI,pCreature->AI()))
            {
                if (!pBarnesAI->RaidWiped)
                    pPlayer->SEND_GOSSIP_MENU(8970, pCreature->GetGUID());
                else
                    pPlayer->SEND_GOSSIP_MENU(8975, pCreature->GetGUID());

                return true;
            }
        }
    }

    pPlayer->SEND_GOSSIP_MENU(8978, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_barnes(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    npc_barnesAI* pBarnesAI = CAST_AI(npc_barnesAI, pCreature->AI());

    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, OZ_GOSSIP2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            pPlayer->SEND_GOSSIP_MENU(8971, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            pBarnesAI->StartEvent();
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            pBarnesAI->m_uiEventId = EVENT_OZ;
            outstring_log("TSCR: player (GUID %i) manually set Opera event to EVENT_OZ",pPlayer->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->CLOSE_GOSSIP_MENU();
            pBarnesAI->m_uiEventId = EVENT_HOOD;
            outstring_log("TSCR: player (GUID %i) manually set Opera event to EVENT_HOOD",pPlayer->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->CLOSE_GOSSIP_MENU();
            pBarnesAI->m_uiEventId = EVENT_RAJ;
            outstring_log("TSCR: player (GUID %i) manually set Opera event to EVENT_RAJ",pPlayer->GetGUID());
            break;
    }

    return true;
}

/*###
# npc_berthold
####*/

enum eBerthold
{
    SPELL_TELEPORT           = 39567
};

#define GOSSIP_ITEM_TELEPORT    "Teleport me to the Guardian's Library"

bool GossipHello_npc_berthold(Player* pPlayer, Creature* pCreature)
{
    if (ScriptedInstance* pInstance = pCreature->GetInstanceData())
    {
        // Check if Shade of Aran event is done
        if (pInstance->GetData(TYPE_ARAN) == DONE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TELEPORT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    }

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_berthold(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
        pPlayer->CastSpell(pPlayer, SPELL_TELEPORT, true);

    pPlayer->CLOSE_GOSSIP_MENU();
    return true;
}

/*###
# npc_image_of_medivh
####*/

#define SAY_DIALOG_MEDIVH_1         "You've got my attention, dragon. You'll find I'm not as easily scared as the villagers below."
#define SAY_DIALOG_ARCANAGOS_2      "Your dabbling in the arcane has gone too far, Medivh. You've attracted the attention of powers beyond your understanding. You must leave Karazhan at once!"
#define SAY_DIALOG_MEDIVH_3         "You dare challenge me at my own dwelling? Your arrogance is astounding, even for a dragon!"
#define SAY_DIALOG_ARCANAGOS_4      "A dark power seeks to use you, Medivh! If you stay, dire days will follow. You must hurry, we don't have much time!"
#define SAY_DIALOG_MEDIVH_5         "I do not know what you speak of, dragon... but I will not be bullied by this display of insolence. I'll leave Karazhan when it suits me!"
#define SAY_DIALOG_ARCANAGOS_6      "You leave me no alternative. I will stop you by force if you won't listen to reason!"
#define EMOTE_DIALOG_MEDIVH_7       "begins to cast a spell of great power, weaving his own essence into the magic."
#define SAY_DIALOG_ARCANAGOS_8      "What have you done, wizard? This cannot be! I'm burning from... within!"
#define SAY_DIALOG_MEDIVH_9         "He should not have angered me. I must go... recover my strength now..."

#define MOB_ARCANAGOS               17652
#define SPELL_FIRE_BALL             30967
#define SPELL_UBER_FIREBALL         30971
#define SPELL_CONFLAGRATION_BLAST   30977
#define SPELL_MANA_SHIELD           31635

static float MedivPos[4] = {-11161.49,-1902.24,91.48,1.94};
static float ArcanagosPos[4] = {-11169.75,-1881.48,95.39,4.83};

struct TRINITY_DLL_DECL npc_image_of_medivhAI : public ScriptedAI
{
    npc_image_of_medivhAI(Creature* c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    uint64 ArcanagosGUID;

    uint32 YellTimer;
    uint32 Step;
    uint32 FireMedivhTimer;
    uint32 FireArcanagosTimer;

    bool EventStarted;

    void Reset()
    {
        ArcanagosGUID = 0;

        if (pInstance && pInstance->GetData64(DATA_IMAGE_OF_MEDIVH) == 0)
        {
            pInstance->SetData64(DATA_IMAGE_OF_MEDIVH, m_creature->GetGUID());
            (*m_creature).GetMotionMaster()->MovePoint(1,MedivPos[0],MedivPos[1],MedivPos[2]);
            Step = 0;
        }else
        {
            m_creature->DealDamage(m_creature,m_creature->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            m_creature->RemoveCorpse();
        }
    }
    void EnterCombat(Unit* who){}

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;
        if (id == 1)
        {
            StartEvent();
            m_creature->SetOrientation(MedivPos[3]);
            m_creature->SetOrientation(MedivPos[3]);
        }
    }

    void StartEvent()
    {
        Step = 1;
        EventStarted = true;
        Creature* Arcanagos = m_creature->SummonCreature(MOB_ARCANAGOS,ArcanagosPos[0],ArcanagosPos[1],ArcanagosPos[2],0,TEMPSUMMON_CORPSE_TIMED_DESPAWN,20000);
        if (!Arcanagos)
            return;
        ArcanagosGUID = Arcanagos->GetGUID();
        Arcanagos->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
        (*Arcanagos).GetMotionMaster()->MovePoint(0,ArcanagosPos[0],ArcanagosPos[1],ArcanagosPos[2]);
        Arcanagos->SetOrientation(ArcanagosPos[3]);
        m_creature->SetOrientation(MedivPos[3]);
        YellTimer = 10000;
    }


    uint32 NextStep(uint32 Step)
    {
        Unit* arca = Unit::GetUnit((*m_creature),ArcanagosGUID);
        Map* pMap = m_creature->GetMap();
        switch(Step)
        {
        case 0: return 9999999;
        case 1:
            m_creature->MonsterYell(SAY_DIALOG_MEDIVH_1,LANG_UNIVERSAL,NULL);
            return 10000;
        case 2:
            if (arca)
                CAST_CRE(arca)->MonsterYell(SAY_DIALOG_ARCANAGOS_2,LANG_UNIVERSAL,NULL);
            return 20000;
        case 3:
            m_creature->MonsterYell(SAY_DIALOG_MEDIVH_3,LANG_UNIVERSAL,NULL);
            return 10000;
        case 4:
            if (arca)
                CAST_CRE(arca)->MonsterYell(SAY_DIALOG_ARCANAGOS_4, LANG_UNIVERSAL, NULL);
            return 20000;
        case 5:
            m_creature->MonsterYell(SAY_DIALOG_MEDIVH_5, LANG_UNIVERSAL, NULL);
            return 20000;
        case 6:
            if (arca)
                CAST_CRE(arca)->MonsterYell(SAY_DIALOG_ARCANAGOS_6, LANG_UNIVERSAL, NULL);
            return 10000;
        case 7:
            FireArcanagosTimer = 500;
            return 5000;
        case 8:
            FireMedivhTimer = 500;
            DoCast(m_creature, SPELL_MANA_SHIELD);
            return 10000;
        case 9:
            m_creature->MonsterTextEmote(EMOTE_DIALOG_MEDIVH_7, 0, false);
            return 10000;
        case 10:
            if (arca)
                m_creature->CastSpell(arca, SPELL_CONFLAGRATION_BLAST, false);
            return 1000;
        case 11:
            if (arca)
                CAST_CRE(arca)->MonsterYell(SAY_DIALOG_ARCANAGOS_8, LANG_UNIVERSAL, NULL);
            return 5000;
        case 12:
            arca->GetMotionMaster()->MovePoint(0, -11010.82,-1761.18, 156.47);
            arca->setActive(true);
            arca->InterruptNonMeleeSpells(true);
            arca->SetSpeed(MOVE_FLIGHT, 2.0f);
            return 10000;
        case 13:
            m_creature->MonsterYell(SAY_DIALOG_MEDIVH_9, LANG_UNIVERSAL, NULL);
            return 10000;
        case 14:
            m_creature->SetVisibility(VISIBILITY_OFF);
            m_creature->ClearInCombat();

            if (pMap->IsDungeon())
            {
                InstanceMap::PlayerList const &PlayerList = pMap->GetPlayers();
                for (InstanceMap::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    if (i->getSource()->isAlive())
                    {
                        if (i->getSource()->GetQuestStatus(9645) == QUEST_STATUS_INCOMPLETE)
                            i->getSource()->CompleteQuest(9645);
                    }
                }
            }
            return 50000;
        case 15:
            arca->DealDamage(arca,arca->GetHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            return 5000;
        default : return 9999999;
        }

    }

    void UpdateAI(const uint32 diff)
    {

        if (YellTimer < diff)
        {
            if (EventStarted)
            {
                YellTimer = NextStep(Step++);
            }
        }else YellTimer -= diff;

        if (Step >= 7 && Step <= 12)
        {
            Unit* arca = Unit::GetUnit((*m_creature),ArcanagosGUID);

            if (FireArcanagosTimer < diff)
            {
                if (arca)
                    arca->CastSpell(m_creature, SPELL_FIRE_BALL, false);
                FireArcanagosTimer = 6000;
            }else FireArcanagosTimer -= diff;

            if (FireMedivhTimer < diff)
            {
                if (arca)
                    DoCast(arca, SPELL_FIRE_BALL);
                FireMedivhTimer = 5000;
            }else FireMedivhTimer -= diff;

        }
    }
};

CreatureAI* GetAI_npc_image_of_medivh(Creature* pCreature)
{
    return new npc_image_of_medivhAI(pCreature);
}

void AddSC_karazhan()
{
    Script* newscript;

    newscript = new Script;
    newscript->GetAI = &GetAI_npc_barnesAI;
    newscript->Name = "npc_barnes";
    newscript->pGossipHello = &GossipHello_npc_barnes;
    newscript->pGossipSelect = &GossipSelect_npc_barnes;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_berthold";
    newscript->pGossipHello = &GossipHello_npc_berthold;
    newscript->pGossipSelect = &GossipSelect_npc_berthold;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_image_of_medivh";
    newscript->GetAI = &GetAI_npc_image_of_medivh;
    newscript->RegisterSelf();
}

