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
SDName: Desolace
SD%Complete: 100
SDComment: Quest support: 5561, 5381
SDCategory: Desolace
EndScriptData */

/* ContentData
go_hand_of_iruxos_crystal

EndContentData */

#include "scriptPCH.h"
#include "MoveMapSharedDefines.h"
#include "CreatureGroups.h"

/*######
## go_hand_of_iruxos_crystal
######*/

enum
{
    DEMON_SPIRIT  = 11876
};

bool GOHello_go_hand_of_iruxos_crystal(Player* pPlayer, GameObject* pGO)
{
    if (pGO->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
    {
        if (Creature* pCreature = pPlayer->SummonCreature(DEMON_SPIRIT, -346.84f, 1765.13f, 138.39f, 5.91f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000))
            pCreature->AI()->AttackStart(pPlayer);
    }

    return true;
}
/*######
## npc_melizza_brimbuzzle
######*/

enum
{
    QUEST_GET_ME_OUT_OF_HERE    = 6132,

    GO_MELIZZAS_CAGE            = 177706,

    SAY_MELIZZA_START           = -1000784,
    SAY_MELIZZA_FINISH          = -1000785,
    SAY_MELIZZA_1               = -1000786,
    SAY_MELIZZA_2               = -1000787,
    SAY_MELIZZA_3               = -1000788,

    NPC_MARAUDINE_MARAUDER      = 4659,
    NPC_MARAUDINE_BONEPAW       = 4660,
    NPC_MARAUDINE_WRANGLER      = 4655,
    NPC_HORNIZ_BRIMBUZZLE       = 6019,

    NPC_MELIZZA                 = 12277,

    POINT_ID_QUEST_COMPLETE     = 1,
    POINT_ID_EVENT_COMPLETE     = 2,

    MAX_MARAUDERS               = 2,
    MAX_WRANGLERS               = 3,
};

struct SummonLocation
{
    float m_fX, m_fY, m_fZ;
};

static const SummonLocation aMarauderSpawn[] =
{
    { -1291.492f, 2644.650f, 111.556f},
    { -1306.730f, 2675.163f, 111.561f},
};

static const SummonLocation wranglerSpawn = { -1393.194f, 2429.465f, 88.689f };

struct npc_melizza_brimbuzzleAI : public npc_escortAI
{
    npc_melizza_brimbuzzleAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        Reset();
    }

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_dialogueStep = 20;
            m_dialogueTimer = 0;
        }
    }

    void JustStartedEscort() override
    {
        m_dialogueStep = 20;
        if (GameObject* pCage = GetClosestGameObjectWithEntry(m_creature, GO_MELIZZAS_CAGE, INTERACTION_DISTANCE))
            pCage->UseDoorOrButton();
    }
    uint16 m_dialogueStep;
    uint32 m_dialogueTimer;

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 1:
                if (Player* pPlayer = GetPlayerForEscort())
                    DoScriptText(SAY_MELIZZA_START, m_creature, pPlayer);

                m_creature->SetFactionTemporary(FACTION_ESCORT_N_NEUTRAL_PASSIVE, TEMPFACTION_RESTORE_RESPAWN);
                break;
            case 4:
                for (const auto& i : aMarauderSpawn)
                {
                    for (uint8 j = 0; j < MAX_MARAUDERS; ++j)
                    {
                        // Summon 2 Marauders on each point
                        float fX, fY, fZ;
                        m_creature->GetRandomPoint(i.m_fX, i.m_fY, i.m_fZ, 7.0f, fX, fY, fZ);
                        m_creature->SummonCreature(NPC_MARAUDINE_MARAUDER, fX, fY, fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
                    }
                }
                break;
            case 9:
                for (uint8 i = 0; i < MAX_WRANGLERS; ++i)
                {
                    float fX, fY, fZ;
                    m_creature->GetRandomPoint(wranglerSpawn.m_fX, wranglerSpawn.m_fY, wranglerSpawn.m_fZ, 10.0f, fX, fY, fZ);
                    m_creature->SummonCreature(NPC_MARAUDINE_BONEPAW, fX, fY, fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);

                    m_creature->GetRandomPoint(wranglerSpawn.m_fX, wranglerSpawn.m_fY, wranglerSpawn.m_fZ, 10.0f, fX, fY, fZ);
                    m_creature->SummonCreature(NPC_MARAUDINE_WRANGLER, fX, fY, fZ, 0.0f, TEMPSUMMON_DEAD_DESPAWN, 0);
                }
                break;
            case 12:
                m_dialogueStep = 6;
                SetEscortPaused(true);
                SetMaxPlayerDistance(100); //Let's not have her despawn so easily.
                if (Player* player = GetPlayerForEscort())
                    m_creature->SetFacingToObject(player);
                m_dialogueTimer = 200;
                break;
            case 19:
                m_dialogueStep = 0;
                SetEscortPaused(true);
                break;
        }
    }
    void Dialogue(uint32 const uiDiff)
    {
        if (m_dialogueStep > 6)
            return;
        if (m_dialogueTimer < uiDiff)
        {
            //sLog.nostalrius("Melizza: DialogueStep n°%u",m_dialogueStep);
            switch (m_dialogueStep)
            {
                case 0:
                    if (Creature* pHorniz = m_creature->FindNearestCreature(NPC_HORNIZ_BRIMBUZZLE, 30.0f))
                        m_creature->SetFacingToObject(pHorniz);
                    DoScriptText(SAY_MELIZZA_1, m_creature);
                    m_dialogueTimer = 4000;
                    m_dialogueStep++;
                    break;
                case 1:
                    DoScriptText(SAY_MELIZZA_2, m_creature);
                    m_dialogueTimer = 5000;
                    m_dialogueStep++;
                    break;
                case 2:
                    DoScriptText(SAY_MELIZZA_3, m_creature);
                    m_dialogueTimer = 4000;
                    m_dialogueStep++;
                    break;
                case 3:
                    SetEscortPaused(false);
                    m_dialogueTimer = 0;
                    m_dialogueStep++;
                    break;
                case 6:
                    if (Player* pPlayer = GetPlayerForEscort())
                    {
                        DoScriptText(SAY_MELIZZA_FINISH, m_creature, pPlayer);
                        pPlayer->GroupEventHappens(QUEST_GET_ME_OUT_OF_HERE, m_creature);
                    }
                    m_dialogueTimer = 2000;
                    m_dialogueStep++;
                    m_creature->ClearTemporaryFaction();
                    SetRun(true);
                    SetEscortPaused(false);
                    break;
            }
        }
        else
            m_dialogueTimer  -= uiDiff;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        Dialogue(uiDiff);
        npc_escortAI::UpdateAI(uiDiff);
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_melizza_brimbuzzle(Creature* pCreature)
{
    return new npc_melizza_brimbuzzleAI(pCreature);
}

bool QuestAccept_npc_melizza_brimbuzzle(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_GET_ME_OUT_OF_HERE)
    {
        if (npc_melizza_brimbuzzleAI* pEscortAI = dynamic_cast<npc_melizza_brimbuzzleAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
    }

    return true;
}

/*######
## npc_dalinda_malem
######*/

enum
{
    QUEST_RETURN_TO_VAHLARRIEL  = 1440,
};

struct npc_dalinda_malemAI : public npc_escortAI
{
    npc_dalinda_malemAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        Reset();
    }

    void Reset() override {}

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        npc_escortAI::JustRespawned();
    }

    void JustStartedEscort() override
    {
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        if (uiPointId == 18)
        {
            if (Player* pPlayer = GetPlayerForEscort())
                pPlayer->GroupEventHappens(QUEST_RETURN_TO_VAHLARRIEL, m_creature);
        }
    }
};

CreatureAI* GetAI_npc_dalinda_malem(Creature* pCreature)
{
    return new npc_dalinda_malemAI(pCreature);
}

bool QuestAccept_npc_dalinda_malem(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_RETURN_TO_VAHLARRIEL)
    {
        if (npc_dalinda_malemAI* pEscortAI = dynamic_cast<npc_dalinda_malemAI*>(pCreature->AI()))
        {
            pCreature->SetFactionTemporary(FACTION_ESCORT_A_NEUTRAL_PASSIVE, TEMPFACTION_RESTORE_RESPAWN);
            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
        }
    }
    return true;
}
enum
{
//guid 12609 entry 177673 Serpant statue
    NPC_LORD_KRAGARU            = 12369,
    QUEST_BOOK_OF_THE_ANCIENTS  = 6027

};
struct go_serpent_statueAI: public GameObjectAI
{
    go_serpent_statueAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        timer = 0;
        state = 0;
        guid_kragaru = 0;
    }
    uint64 guid_kragaru;
    uint32 timer;
    bool state;//0 = usual, can launch. //1 = in use, cannot launch

    void UpdateAI(uint32 const uiDiff) override
    {
        if (state)
        {
            if (timer < uiDiff)
            {
                state = 0;
                me->SetGoState(GO_STATE_READY);
                me->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            }
            else
                timer -= uiDiff;
        }
    }
    bool CheckCanStartEvent()
    {
        return !state && !me->GetMap()->GetCreature(guid_kragaru);
    }

    void SetInUse(Creature* kragaru)
    {
        guid_kragaru = kragaru->GetGUID();
        me->SetGoState(GO_STATE_ACTIVE);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        state = 1;
        timer = 120000;
    }
};
GameObjectAI* GetAIgo_serpent_statue(GameObject *pGo)
{
    return new go_serpent_statueAI(pGo);
}
bool GOHello_go_serpent_statue(Player* pPlayer, GameObject* pGo)
{
    if (go_serpent_statueAI* pMarkAI = dynamic_cast<go_serpent_statueAI*>(pGo->AI()))
    {
        if (pMarkAI->CheckCanStartEvent())
        {
            if (pGo->GetGoType() == GAMEOBJECT_TYPE_BUTTON)
            {
                if (pPlayer->GetQuestStatus(QUEST_BOOK_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE)
                {
                    if (Creature* kragaru = pGo->SummonCreature(NPC_LORD_KRAGARU, 0, 0, 0, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        kragaru->SetRespawnDelay(350000);
                        pMarkAI->SetInUse(kragaru);
                    }
                }
            }
        }
    }
    return true;
}
enum
{
    NPC_MAGRAMI_SPECTRE                 = 11560,
    GO_GHOST_MAGNET                     = 177746,
    GO_GHOST_MAGNET_AURA                = 177749,
    SPELL_CURSE_OF_THE_FALLEN_MAGRAM    = 18159,
    SPELL_PLACE_GHOST_MAGNET            = 19588,
    SPELL_DESTROY_MAGNET                = 19571,//not used maybe.
    SPELL_BLUE_AURA                     = 17327,//neutral, walk to target
    SPELL_GREEN_AURA                    = 18951, //aura becomes green once they get to magnet. and aggressive
    FACTION_NEUTRAL                     = 634, //or 58
    FACTION_ENNEMY                      = 16
};

void DefineMagramiMagnet(Creature * crea, uint64 gobjGUID);

struct go_ghost_magnetAI: public GameObjectAI
{
    go_ghost_magnetAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        bigTimer = 120000;
        timer = 5000;
        nbToSpawn = 8;

        state = 1;
        std::list<GameObject*> lGobj;
        me->GetGameObjectListWithEntryInGrid(lGobj, GO_GHOST_MAGNET_AURA, 30.0f);
        for (const auto& it : lGobj)
        {
            if (it->isSpawned())
            {
                state = 0;
                break;
            }
        }
        if (state)
        {
            float mx, my, mz;
            me->GetPosition(mx, my, mz);
            me->SummonGameObject(GO_GHOST_MAGNET_AURA, mx, my, mz, 0, 0, 0, 0, 0, 120);//120sec to go with the 12000 spectre spawn
        }
    }
    uint32 timer;
    uint32 bigTimer;
    uint16 nbToSpawn;
    bool state;//0 = already are functioning magnets, do not spawn spectre. //1 = spawning.

    void UpdateAI(uint32 const uiDiff) override
    {
        if (state)
        {
            if (bigTimer < uiDiff)
            {
                state=0;
            }
            else
                bigTimer -= uiDiff;
            if(nbToSpawn>0)
            {
                if (timer < uiDiff)
                {
                    spawnSpetre();
                    timer = urand(3000, 8000);
                    --nbToSpawn;
                }
                else
                    timer -= uiDiff;
            }
        }
    }

    void spawnSpetre()
    {
        float x, y, z;
        float mx, my, mz;
        me->GetPosition(mx, my, mz);
        me->GetRandomPoint(mx,my,mz, 40, x, y, z);
        if(Creature* spectre=me->SummonCreature(NPC_MAGRAMI_SPECTRE, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
        {
            spectre->SetRespawnDelay(425000);
            DefineMagramiMagnet(spectre, me->GetGUID());
        }
    }
    void MagramiSpectreDied(uint64 guid)
    {
        if (state)
            spawnSpetre();
    }
};
GameObjectAI* GetAIgo_ghost_magnet(GameObject *pGo)
{
    return new go_ghost_magnetAI(pGo);
}
struct npc_magrami_spetreAI : public ScriptedAI
{
    npc_magrami_spetreAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        isGreen = false;
        guidMagnet = 0;
        corpseTimer = 20000;
        Reset();
    }
    void Reset() override
    {
        timer=0;
        curseTimer = urand(5000, 9000);
        if(isGreen)
             m_creature->AddAura(SPELL_GREEN_AURA);
        else
             m_creature->AddAura(SPELL_BLUE_AURA);
    }
    uint32 corpseTimer;
    uint32 timer;
    uint32 curseTimer;
    uint64 guidMagnet;
    bool isGreen;

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if(isGreen)
            return;
        if (uiType != POINT_MOTION_TYPE || uiPointId!=2)
            return;
        turnGreen();
    }
    void JustReachedHome() override
    {
        if(!isGreen)
            turnGreen();
    }
    void turnGreen()
    {
        m_creature->RemoveAurasDueToSpell(SPELL_BLUE_AURA);
        m_creature->AddAura(SPELL_GREEN_AURA);
        m_creature->SetFactionTemplateId(FACTION_ENNEMY);
        isGreen=true;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if ( curseTimer < uiDiff)
        {
            if(m_creature->GetVictim()->HasAura(SPELL_CURSE_OF_THE_FALLEN_MAGRAM))
                curseTimer = 5000;
            else
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CURSE_OF_THE_FALLEN_MAGRAM) == CAST_OK)
                    curseTimer = urand(15000, 21000);
            }
        }
        else
            curseTimer -= uiDiff;
        DoMeleeAttackIfReady();
    }
    void UpdateAI_corpse(uint32 const uiDiff) override
    {
        if ( corpseTimer < uiDiff)//purpose is to delay the new spawn.
        {
            if(GameObject* gobj=m_creature->GetMap()->GetGameObject(guidMagnet))
            {
                if (go_ghost_magnetAI* pMoundAI = dynamic_cast<go_ghost_magnetAI*>(gobj->AI()))
                {
                    pMoundAI->MagramiSpectreDied(m_creature->GetGUID());
                }
            }
            corpseTimer=150000;//after despawn.
        }
        else
            corpseTimer -= uiDiff;
    }
    void SetMagnetGuid(uint64 ghostMagnetGuid)
    {
        if (GameObject* gobj = m_creature->GetMap()->GetGameObject(ghostMagnetGuid))
        {
            float x,y,z;

            gobj->GetContactPoint(m_creature, x, y, z, 1);
            m_creature->SetHomePosition(x, y, z, 0);
            m_creature->GetMotionMaster()->MovePoint(2, x, y, z, MOVE_PATHFINDING);
            guidMagnet=ghostMagnetGuid;
        }
    }
};

CreatureAI* GetAI_npc_magrami_spetre(Creature* pCreature)
{
    return new npc_magrami_spetreAI(pCreature);
}
void DefineMagramiMagnet(Creature * crea, uint64 gobjGUID)
{
    if (npc_magrami_spetreAI* spectreAI = dynamic_cast<npc_magrami_spetreAI*>(crea->AI()))
    {
        spectreAI->SetMagnetGuid(gobjGUID);
    }
}

/*
 * Gizelton Caravan, Bodyguard For Hire support
 */

struct GizeltonStruct
{
    int32 onLeave, onAnnounce, onAmbush0, onAmbush1, onAmbush2, onComplete;
};

const GizeltonStruct CaravanTalk[] = 
{
    { 7506, 7475, 7330, 7331, 7332, 7333 },
    { 7505, 7474, 7310, 7311, 7312, 7334 }
};

enum
{
    NPC_RIGGER_GIZELTON     = 11626,
    NPC_CORK_GIZELTON       = 11625,
    NPC_SUPER_SELLER_680    = 12246,
    NPC_VENDOR_TRON_1000    = 12245,
    NPC_CARAVAN_KODO        = 11564,
    NPC_DOOMWARDER          = 4677,
    NPC_NETHER_SORCERESS    = 4684,
    NPC_LESSER_INFERNAL     = 4676,
    NPC_KOLKAR_AMBUSHER     = 12977,
    NPC_KOLKAR_WAYLAYER     = 12976,

    POINT_BOT_CAMP          = 279,
    POINT_BOT_ANNOUNCE      = 14,
    POINT_BOT_AMBUSH_0      = 28,
    POINT_BOT_AMBUSH_1      = 34,
    POINT_BOT_AMBUSH_2      = 40,
    POINT_BOT_COMPLETE      = 42,

    POINT_TOP_CAMP          = 141,
    POINT_TOP_ANNOUNCE      = 164,
    POINT_TOP_AMBUSH_0      = 173,
    POINT_TOP_AMBUSH_1      = 181,
    POINT_TOP_AMBUSH_2      = 188,
    POINT_TOP_COMPLETE      = 195,
    POINT_END               = 281,

    QUEST_BOTTOM            = 5943,
    QUEST_TOP               = 5821,
};

struct Coords
{
    uint32 entry;
    float x, y, z, o;
};

struct Formation
{
    float distance, angle;
};

struct CaravanMember
{
    Coords coords;
    Formation form;
};

const Coords Ambusher[] = 
{
    { NPC_DOOMWARDER,       -1814.41f, 1983.18f, 58.9549f, 0.0f },
    { NPC_NETHER_SORCERESS, -1814.41f, 1983.18f, 58.9549f, 0.0f },
    { NPC_LESSER_INFERNAL,  -1814.41f, 1983.18f, 58.9549f, 0.0f },

    { NPC_DOOMWARDER,       -1751.9f, 1917.2f, 59.0003f, 0.0f },
    { NPC_NETHER_SORCERESS, -1751.9f, 1917.2f, 59.0003f, 0.0f },
    { NPC_LESSER_INFERNAL,  -1751.9f, 1917.2f, 59.0003f, 0.0f },

    { NPC_DOOMWARDER,       -1684.12f, 1872.66f, 59.0354f, 0.0f },
    { NPC_NETHER_SORCERESS, -1684.12f, 1872.66f, 59.0354f, 0.0f },
    { NPC_LESSER_INFERNAL,  -1684.12f, 1872.66f, 59.0354f, 0.0f },

    { NPC_KOLKAR_AMBUSHER,  -792.515f, 1177.07f, 98.8327f, 0.0f },
    { NPC_KOLKAR_WAYLAYER,  -792.515f, 1177.07f, 98.8327f, 0.0f },

    { NPC_KOLKAR_AMBUSHER,  -931.15f, 1182.17f, 91.8346f, 0.0f },
    { NPC_KOLKAR_WAYLAYER,  -931.15f, 1182.17f, 91.8346f, 0.0f },

    { NPC_KOLKAR_AMBUSHER,  -1073.62f, 1186.33f, 89.7398f, 0.0f },
    { NPC_KOLKAR_WAYLAYER,  -1073.62f, 1186.33f, 89.7398f, 0.0f }
};

const CaravanMember Caravan[] =
{
    { {NPC_CARAVAN_KODO,     -1887.26f, 2465.12f, 59.8224f, 4.48f}, { 26.0f, 3.14f } },
    { {NPC_RIGGER_GIZELTON,  -1883.63f, 2471.68f, 59.8224f, 4.48f}, { 18.0f, 3.14f } },
    { {NPC_CARAVAN_KODO,     -1882.11f, 2476.80f, 59.8224f, 4.48f}, { 8.0f,  3.14f } }
};

struct npc_cork_gizeltonAI : npc_escortAI
{
    const Formation FORMATION_CORK = { 32.0f, 6.28f };

    explicit npc_cork_gizeltonAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        ResetCreature();
    }

    std::vector<ObjectGuid> m_lCaravanGuid;
    ObjectGuid m_RiggerGuid;
    ObjectGuid m_playerGuid;
    uint8 m_uiEnemiesCount;
    uint8 m_uiAnnounceCount;
    uint32 m_uiInitDelayTimer;
    uint32 m_uiCampTimer;
    uint32 m_uiAnnounceTimer;
    uint32 m_uiDepartTimer;
    bool m_bInit;
    bool m_bCamp;
    bool m_bWaitingForPlayer;
    bool m_bWaitingForDepart;
    bool m_bRigger;

    void Reset() override
    {

    }

    void ResetCreature() override
    {
        m_lCaravanGuid.clear();
        m_RiggerGuid.Clear();
        m_playerGuid.Clear();
        m_uiEnemiesCount = 0;
        m_uiAnnounceCount = 0;
        m_uiInitDelayTimer = 2000;
        m_uiCampTimer = 10 * MINUTE * IN_MILLISECONDS;
        m_uiDepartTimer = MINUTE * IN_MILLISECONDS;
        m_uiAnnounceTimer = 0;
        m_bInit = false;
        m_bCamp = false;
        m_bWaitingForPlayer = false;
        m_bWaitingForDepart = false;
        m_bRigger = true;
    }

    void SummonCaravan()
    {
        m_lCaravanGuid.push_back(m_creature->GetObjectGuid());
        AddToFormation(m_creature, FORMATION_CORK);

        for (const auto& member : Caravan)
        {
            if (const auto pCreature = m_creature->SummonCreature(member.coords.entry,
                member.coords.x,
                member.coords.y,
                member.coords.z,
                member.coords.o, TEMPSUMMON_DEAD_DESPAWN, 30000, true))
            {
                AddToFormation(pCreature, member.form);
            }
            else
            {
                sLog.outError("[Desolace.GizeltonCaravan] Failed to summon caravan. Self-despawn.");
                DespawnCaravan();
            }
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        FailEscort();
    }

    void FailEscort()
    {
        DespawnCaravan();

        if (!m_playerGuid)
            return;

        if (auto pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
            pPlayer->GroupEventFailHappens(m_bRigger ? QUEST_BOTTOM : QUEST_TOP);
    }

    void DespawnCaravan()
    {
        for (const auto& guid : m_lCaravanGuid)
        {
            if (guid != m_creature->GetObjectGuid())
            {
                if (auto pKillMe = m_creature->GetMap()->GetCreature(guid))
                    pKillMe->DespawnOrUnsummon();
            }
        }

        m_creature->ForcedDespawn();
    }

    void CaravanFaction(bool apply)
    {
        for (const auto& guid : m_lCaravanGuid)
        {
            if (guid != m_creature->GetObjectGuid())
            {
                if (Creature* pCreature = m_creature->GetMap()->GetCreature(guid))
                {
                    if (apply)
                    {
                        pCreature->SetFactionTemporary(FACTION_ESCORT_N_FRIEND_ACTIVE, TEMPFACTION_NONE);
                        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    }
                    else
                    {
                        pCreature->ClearTemporaryFaction();
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
                    }
                }
            }
        }

        if (apply)
        {
            m_creature->SetFactionTemporary(FACTION_ESCORT_N_FRIEND_ACTIVE, TEMPFACTION_NONE);
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        }
        else
        {
            m_creature->ClearTemporaryFaction();
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        }
    }

    void SummonAmbusher(uint8 index) const
    {
        float x = Ambusher[index].x;
        float y = Ambusher[index].y;
        float z = Ambusher[index].z;

        for (uint8 i = 0; i < 5; ++i)
        {
            if (m_creature->GetMap()->GetWalkRandomPosition(nullptr, x, y, z, 20.0f, NAV_GROUND))
                break;
        }

        m_creature->SummonCreature(Ambusher[index].entry, x, y, z, 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 30000);
    }

    void Ambush(uint8 index) const
    {
        switch (index)
        {
        case POINT_BOT_AMBUSH_0:
            SummonAmbusher(0);
            SummonAmbusher(1);
            SummonAmbusher(2);
            DoTalk(CaravanTalk[0].onAmbush0);
            break;
        case POINT_BOT_AMBUSH_1:
            SummonAmbusher(3);
            SummonAmbusher(4);
            SummonAmbusher(5);
            DoTalk(CaravanTalk[0].onAmbush1);
            break;
        case POINT_BOT_AMBUSH_2:
            SummonAmbusher(6);
            SummonAmbusher(7);
            SummonAmbusher(8);
            DoTalk(CaravanTalk[0].onAmbush2);
            break;
        case POINT_TOP_AMBUSH_0:
            SummonAmbusher(9);
            SummonAmbusher(10);
            SummonAmbusher(9);
            SummonAmbusher(10);
            DoTalk(CaravanTalk[1].onAmbush0);
            break;
        case POINT_TOP_AMBUSH_1:
            SummonAmbusher(11);
            SummonAmbusher(12);
            SummonAmbusher(11);
            SummonAmbusher(12);
            DoTalk(CaravanTalk[1].onAmbush1);
            break;
        case POINT_TOP_AMBUSH_2:
            SummonAmbusher(13);
            SummonAmbusher(14);
            SummonAmbusher(13);
            SummonAmbusher(14);
            DoTalk(CaravanTalk[1].onAmbush2);
            break;
        }
    }

    void AddToFormation(Creature* const pWho, Formation const& form) const
    {
        pWho->JoinCreatureGroup(m_creature, form.distance, form.angle,
            OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_RIGGER_GIZELTON:
                m_RiggerGuid = pSummoned->GetObjectGuid();
                pSummoned->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            case NPC_CARAVAN_KODO:
                m_lCaravanGuid.push_back(pSummoned->GetObjectGuid());
                break;
            default:
                ++m_uiEnemiesCount;

                // pick random caravan target
                uint8 targetIndex = urand(0, m_lCaravanGuid.size() - 1);

                auto targetGuid = m_lCaravanGuid[targetIndex];

                if (auto pCreature = m_creature->GetMap()->GetCreature(targetGuid))
                    pSummoned->AI()->AttackStart(pCreature);
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_RIGGER_GIZELTON:
            case NPC_CARAVAN_KODO:
                FailEscort();
                break;
            default:
                --m_uiEnemiesCount;

                if (!m_uiEnemiesCount)
                    SetEscortPaused(false);
        }
    }

    void ResumePath(Player* pPlayer)
    {
        m_bWaitingForPlayer = false;
        m_bWaitingForDepart = true;
        m_uiAnnounceCount = 0;
        if (pPlayer)
            m_playerGuid = pPlayer->GetObjectGuid();
        GiveQuest(false);
    }

    void DoTalk(int32 textId, bool yell = false) const
    {
        auto pTalker = m_bRigger ? m_creature->GetMap()->GetCreature(m_RiggerGuid) : m_creature;

        if (pTalker)
        {
            if (yell)
                pTalker->MonsterYellToZone(textId);
            else
                pTalker->MonsterSay(textId);
        }
    }

    void GiveQuest(bool give) const
    {
        auto pGiver = m_bRigger ? m_creature->GetMap()->GetCreature(m_RiggerGuid) : m_creature;

        if (pGiver)
        {
            if (give)
                pGiver->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            else
                pGiver->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        }
    }

    void CaravanWalk(bool walk) const
    {
        m_creature->SetWalk(walk);
    }

    void DoVendor(bool visible) const
    {
        if (Creature* pVendor = m_creature->FindNearestCreature(m_bRigger ? NPC_SUPER_SELLER_680 : NPC_VENDOR_TRON_1000, 100.0f))
            pVendor->SetVisibility(visible ? VISIBILITY_ON : VISIBILITY_OFF);
    }

    void WaypointReached(uint32 uiPoint) override
    {
        switch (uiPoint)
        {
            case POINT_BOT_CAMP:
            case POINT_TOP_CAMP:
            {
                SetEscortPaused(true);
                CaravanWalk(true);
                m_uiCampTimer = 10 * MINUTE * IN_MILLISECONDS;
                m_bCamp = true;
                DoVendor(true);
                break;
            }
            case POINT_BOT_ANNOUNCE:
            case POINT_TOP_ANNOUNCE:
            {
                SetEscortPaused(true);
                GiveQuest(true);
                m_uiAnnounceTimer = 0;
                m_uiDepartTimer = 10 * IN_MILLISECONDS;
                m_bWaitingForPlayer = true;
                break;
            }
            case POINT_BOT_AMBUSH_0:
            case POINT_BOT_AMBUSH_1:
            case POINT_BOT_AMBUSH_2:
            case POINT_TOP_AMBUSH_0:
            case POINT_TOP_AMBUSH_1:
            case POINT_TOP_AMBUSH_2:
            {
                if (m_playerGuid)
                {
                    SetEscortPaused(true);
                    Ambush(uiPoint);
                }
                break;
            }
            case POINT_BOT_COMPLETE:
            case POINT_TOP_COMPLETE:
            {
                if (auto pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
                {
                    DoTalk(CaravanTalk[m_bRigger ? 0 : 1].onComplete);

                    if (pPlayer->IsInRange(m_creature, 0.0f, 100.0f))
                        pPlayer->GroupEventHappens(m_bRigger ? QUEST_BOTTOM : QUEST_TOP, m_creature);
                }

                m_playerGuid.Clear();
                CaravanFaction(false);
                CaravanWalk(false);
                m_bRigger = !m_bRigger;
                break;
            }
            case POINT_END:
            {
                DespawnCaravan();
                break;
            }
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        // just summoned, do init
        if (!m_bInit)
        {
            if (m_uiInitDelayTimer < uiDiff)
            {
                SummonCaravan();
                m_bInit = true;
                Start();
            }
            else
                m_uiInitDelayTimer -= uiDiff;

            return;
        }

        // caravan is at camp point, vendor is available
        if (m_bCamp)
        {
            if (m_uiCampTimer < uiDiff)
            {
                m_bCamp = false;
                DoTalk(CaravanTalk[m_bRigger ? 0 : 1].onLeave);
                DoVendor(false);
                SetEscortPaused(false);
            }
            else
                m_uiCampTimer -= uiDiff;

            return;
        }

        // caravan is at waiting point, announcing every 3 minutes
        if (m_bWaitingForPlayer)
        {
            if (m_uiAnnounceTimer < uiDiff)
            {
                ++m_uiAnnounceCount;

                // caravan stays for 15+ minutes waiting for help
                if (m_uiAnnounceCount > 5)
                {
                    ResumePath(nullptr);
                    return;
                }

                DoTalk(CaravanTalk[m_bRigger ? 0 : 1].onAnnounce, true);
                m_uiAnnounceTimer = 3 * MINUTE * IN_MILLISECONDS;
            }
            else
                m_uiAnnounceTimer -= uiDiff;

            return;
        }

        // player is here, 10 seconds more and caravan goes
        if (m_bWaitingForDepart)
        {
            if (m_uiDepartTimer < uiDiff)
            {
                m_bWaitingForDepart = false;
                CaravanFaction(true);
                SetEscortPaused(false);
            }
            else
                m_uiDepartTimer -= uiDiff;

            return;
        }

        npc_escortAI::UpdateEscortAI(uiDiff);
    }
};

CreatureAI* GetAI_npc_cork_gizelton(Creature* pCreature)
{
    return new npc_cork_gizeltonAI(pCreature);
}

bool QuestAccept_npc_cork_gizelton(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_TOP)
    {
        if (auto pCorkAI = dynamic_cast<npc_cork_gizeltonAI*>(pCreature->AI()))
            pCorkAI->ResumePath(pPlayer);
    }

    return true;
}

bool QuestAccept_npc_rigger_gizelton(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_BOTTOM)
    {
        if (auto pCork = pCreature->FindNearestCreature(NPC_CORK_GIZELTON, 100.0f))
        {
            if (auto pCorkAI = dynamic_cast<npc_cork_gizeltonAI*>(pCork->AI()))
                pCorkAI->ResumePath(pPlayer);
        }
    }

    return true;
}

void AddSC_desolace()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_hand_of_iruxos_crystal";
    newscript->pGOHello = &GOHello_go_hand_of_iruxos_crystal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_melizza_brimbuzzle";
    newscript->GetAI = &GetAI_npc_melizza_brimbuzzle;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_melizza_brimbuzzle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dalinda_malem";
    newscript->GetAI = &GetAI_npc_dalinda_malem;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_dalinda_malem;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_serpent_statue";
    newscript->GOGetAI = &GetAIgo_serpent_statue;
    newscript->pGOHello = &GOHello_go_serpent_statue;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_ghost_magnet";
    newscript->GOGetAI = &GetAIgo_ghost_magnet;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_magrami_spetre";
    newscript->GetAI = &GetAI_npc_magrami_spetre;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_cork_gizelton";
    newscript->GetAI = &GetAI_npc_cork_gizelton;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_cork_gizelton;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rigger_gizelton";
    newscript->pQuestAcceptNPC = &QuestAccept_npc_rigger_gizelton;
    newscript->RegisterSelf();
}
