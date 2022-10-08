/*
 * Copyright (C) 2006-2011 ScriptDev2 <http://www.scriptdev2.com/>
 * Copyright (C) 2010-2011 ScriptDev0 <http://github.com/mangos-zero/scriptdev0>
 *
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
SDName: Sunken_Temple
SD%Complete: 100
SDComment: Quest support: 8733
SDCategory: Sunken Temple
EndScriptData */

/* ContentData
at_shade_of_eranikus
npc_malfurion_stormrage
event_antalarion_statue_activation
event_avatar_of_hakkar
go_eternal_flame
effectDummy_summon_hakkar
EndContentData */

#include "scriptPCH.h"
#include "sunken_temple.h"

enum
{
    QUEST_THE_CHARGE_OF_DRAGONFLIGHTS = 8555,
    QUEST_ERANIKUS_TYRANT_OF_DREAMS   = 8733
};

/*######
## npc_malfurion_stormrage
######*/

enum
{
    EMOTE_MALFURION1              = -1109000,
    SAY_MALFURION1                = -1109001,
    SAY_MALFURION2                = -1109002,
    SAY_MALFURION3                = -1109003,
    SAY_MALFURION4                = -1109004,

    MAX_MALFURION_TEMPLE_SPEECHES = 7
};

struct npc_malfurionAI : public ScriptedAI
{
    npc_malfurionAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_uiSpeech   = 0;
        m_uiSayTimer = 3000;
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);

        // Prevents interference with Waking Legends
        m_inDungeon = m_creature->GetMap()->IsDungeon();

        if (m_inDungeon)
        {
            // If in temple, spawn invisible, emote "Walls Tremble"
            m_creature->SetVisibility(VISIBILITY_OFF);
            DoScriptText(EMOTE_MALFURION1, m_creature);
        }
    }

    uint32 m_uiSayTimer;
    uint32 m_uiSpeech;
    bool m_inDungeon;

    void Reset() override {}

    void UpdateAI(uint32 const uiDiff) override
    {
        // We are in Sunken Temple
        if (m_inDungeon)
        {
            if (m_uiSpeech < MAX_MALFURION_TEMPLE_SPEECHES)
            {
                if (m_uiSayTimer <= uiDiff)
                {
                    switch (m_uiSpeech)
                    {
                        case 0:
                            m_creature->SetVisibility(VISIBILITY_ON);
                            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            // Resurrection visual
                            m_creature->CastSpell(m_creature, 20761, true);
                            m_uiSayTimer = 1500;
                            break;

                        case 1:
                            m_creature->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                            m_uiSayTimer = 2000;
                            break;

                        case 2:
                            DoScriptText(SAY_MALFURION1, m_creature);
                            m_uiSayTimer = 10000;
                            break;

                        case 3:
                            DoScriptText(SAY_MALFURION2, m_creature);
                            m_uiSayTimer = 10000;
                            break;

                        case 4:
                            DoScriptText(SAY_MALFURION3, m_creature);
                            m_uiSayTimer = 8000;
                            break;

                        case 5:
                            DoScriptText(SAY_MALFURION4, m_creature);
                            m_uiSayTimer = 5000;
                            break;
                        
                        case 6:
                            m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
                            break;
                    }

                    ++m_uiSpeech;
                }
                else
                    m_uiSayTimer -= uiDiff;
            }
        }
    }
};

CreatureAI* GetAI_npc_malfurion(Creature* pCreature)
{
    return new npc_malfurionAI(pCreature);
}

// Summon Malfurion trigger (AQ scepter quest)
bool AreaTrigger_at_shade_of_eranikus(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (!pPlayer || !pPlayer->IsAlive() || !pAt)
        return false;

    if (pAt->id != AREATRIGGER_MALFURION)
        return false;

    // Don't spawn if player did not complete Charge of Dragonflights, or already on/done with Malfurion quest
    if (!pPlayer->GetQuestRewardStatus(QUEST_THE_CHARGE_OF_DRAGONFLIGHTS)
        || pPlayer->GetQuestStatus(QUEST_ERANIKUS_TYRANT_OF_DREAMS) != QUEST_STATUS_NONE
        || pPlayer->GetQuestRewardStatus(QUEST_ERANIKUS_TYRANT_OF_DREAMS))
        return false;

    // Check if Malfurion already spawned
    if (Creature* cMalfurion = GetClosestCreatureWithEntry(pPlayer, NPC_MALFURION, 50.0f))
        return true;

    // Summon for real now
    if (Creature* cMalfurion = pPlayer->SummonCreature(NPC_MALFURION, pAt->x, pAt->y - 15, pAt->z, 1.52f, TEMPSUMMON_CORPSE_DESPAWN, 0))
        return true;
    
    return false;
}

/*######
## go_eternal_flame
######*/
struct go_eternal_flameAI: public GameObjectAI
{
    go_eternal_flameAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser) override
    {
        if (me->GetGoState() == GO_STATE_ACTIVE)    // already used - script handler calls twice
            return true;

        ScriptedInstance* pInstance = (ScriptedInstance*)me->GetInstanceData();

        if (!pInstance)
            return false;

        if (pInstance->GetData(TYPE_AVATAR) != IN_PROGRESS)
            return false;

        if (Creature *shade = pInstance->GetCreature(pInstance->GetData64(NPC_SHADE_OF_HAKKAR)))
        {
            if (npc_shade_hakkarAI *ai = dynamic_cast<npc_shade_hakkarAI*>(shade->AI()))
            {
                ai->UpdateBrazierState(me, true);
                return true;
            }
        }

        return false;
    }
};

GameObjectAI* GetAIgo_eternal_flame(GameObject *pGo)
{
    return new go_eternal_flameAI(pGo);
}

/*######
## npc_shade_hakkar
######*/

struct SpawnLocation
{
    float m_fX, m_fY, m_fZ, m_fO;
};

static SpawnLocation const aMobLocs[8] =
{
    { -451.838f, 270.88f, -90.5418f, 2.39622f},
    { -477.712f, 283.707f, -90.5464f, 3.9631f},
    { -476.58f, 261.124f, -90.4991f, 4.94248f},
    { -467.589f, 257.202f, -90.5792f, 3.14941f},
    { -483.749f, 272.907f, -90.6463f, 0.023527f},
    { -469.401f, 290.183f, -90.5949f, 0.475917f},
    { -457.525f, 260.605f, -90.5002f, 0.715479f},
    { -457.922f, 286.686f, -90.5413f, 1.02569f}
};

static SpawnLocation const aMobDest[8] =
{
    { -441.838f, 270.387f, -90.791f, 6.23f},
    { -487.712f, 291.707f, -90.7024f, 2.448f},
    { -484.988f, 254.289f, -90.652f, 3.824f},
    { -466.789f, 248.819f, -90.773f, 4.807f},
    { -494.863f, 273.234f, -90.927f, 3.110f},
    { -472.606f, 300.384f, -90.748f, 1.867f},
    { -451.712f, 253.742f, -90.659f, 5.406f},
    { -451.815f, 296.753f, -90.693f, 0.992f}
};

enum
{
    SPELL_SUPPRESSION   = 12623
};

static uint32 const brazierEntries[] = { GO_ETERNAL_FLAME_1, GO_ETERNAL_FLAME_2, GO_ETERNAL_FLAME_3, GO_ETERNAL_FLAME_4 };

npc_shade_hakkarAI::npc_shade_hakkarAI(Creature* pCreature) : ScriptedAI(pCreature)
{
    m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
    if (m_pInstance)
    {
        m_pInstance->SetData64(NPC_SHADE_OF_HAKKAR, pCreature->GetGUID());
        if (m_pInstance->GetData(TYPE_AVATAR) == DONE || m_pInstance->GetData(TYPE_AVATAR) == FAIL)
        {
            pCreature->SetVisibility(VISIBILITY_OFF);
            pCreature->ForcedDespawn(1000);

            return;
        }
        else
            EngagedOnce = false;
    }
    Reset();
}

void npc_shade_hakkarAI::Reset()
{
    m_uiHakkariTimer        = 6000;
    CheckTimer              = 2000;
    m_uiSuppressorTimer     = 0;
    m_uiSuppressingTimer    = 10000;
    m_uiBraziersUsed        = 0;
    FirstPop                = true;

    while (Creature* Cre = m_creature->FindNearestCreature(NPC_HAKKARI_MINION, 150.0f))
        Cre->DisappearAndDie();

    while (Creature* Cre = m_creature->FindNearestCreature(NPC_BLOODKEEPER, 150.0f))
        Cre->DisappearAndDie();

    while (Creature* Cre = m_creature->FindNearestCreature(NPC_SUPPRESSOR, 150.0f))
        Cre->DisappearAndDie();

    while (Creature* Cre = m_creature->FindNearestCreature(NPC_AVATAR_OF_HAKKAR, 150.0f))
        Cre->DisappearAndDie();

    if (EngagedOnce)
    {
        if (m_pInstance && m_pInstance->GetData(TYPE_AVATAR) != DONE)
            m_pInstance->SetData(TYPE_AVATAR, FAIL);

        EngagedOnce = false;
        m_creature->ForcedDespawn(1000);
    }
    m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    //m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

    for (uint32 & eventSpawn : eventSpawns)
        eventSpawn = 0;

    if (m_pInstance)
    {
        for (uint32 i : brazierEntries)
        {
            if (GameObject *go = m_pInstance->GetGameObject(m_pInstance->GetData64(i)))
                UpdateBrazierState(go, false);
        }
    }
}

void npc_shade_hakkarAI::UpdateBrazierState(GameObject *go, bool used)
{
    if (go)
    {
        if (used)
        {
            ++m_uiBraziersUsed;
            m_uiSuppressorTimer = 1000;

            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            go->SetGoState(GO_STATE_ACTIVE);
        }
        else
        {
            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NO_INTERACT);
            go->SetGoState(GO_STATE_READY);
        }
    }

    switch (m_uiBraziersUsed)
    {
        case 1:
            DoScriptText(SAY_AVATAR_BRAZIER_1, m_creature);
            break;
        case 2:
            DoScriptText(SAY_AVATAR_BRAZIER_2, m_creature);
            break;
        case 3:
            DoScriptText(SAY_AVATAR_BRAZIER_3, m_creature);
            break;
            // Summon the avatar of all flames are used
        case 4:
            DoScriptText(SAY_AVATAR_BRAZIER_4, m_creature);
            SummonTheAvatar();
            break;
    }
}

void npc_shade_hakkarAI::SummonTheAvatar()
{
    m_creature->CastSpell(m_creature, 12639, true); // Summon Hakkar (Visual)
    if (Creature* Avatar = m_creature->SummonCreature(NPC_AVATAR_OF_HAKKAR, -466.8673f, 272.31204f, -90.7441f, 3.5255f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
    {
        if (m_pInstance)
            m_pInstance->SetData64(NPC_AVATAR_OF_HAKKAR, Avatar->GetGUID());

        Avatar->CastSpell(Avatar, 12948, true); // Summon Hakkar (Visual)
        //Avatar->SetInCombatWithZone();
    }

    std::list<GameObject*> circles;
    m_creature->GetGameObjectListWithEntryInGrid(circles, GO_EVIL_CIRCLE, 20);

    for (const auto go : circles)
        go->Use(m_creature);

    m_creature->ForcedDespawn(500);
}

void npc_shade_hakkarAI::Aggro(Unit* pWho)
{
    if (m_pInstance)
        m_pInstance->SetData(TYPE_AVATAR, IN_PROGRESS);
}

void npc_shade_hakkarAI::JustSummoned(Creature* summoned)
{
    switch (summoned->GetEntry())
    {
        case NPC_SUPPRESSOR:
            summoned->CastSpell(summoned, 7741, true);  // Summoned Demon (Visual)
            break;
        case NPC_BLOODKEEPER:
            summoned->CastSpell(summoned, 7741, true);  // Summoned Demon (Visual)
            ++eventSpawns[SHADE_KEEPER_TYPE];
            break;
        case NPC_HAKKARI_MINION:
            ++eventSpawns[SHADE_HAKKARI_TYPE];
            break;
    }
}

void npc_shade_hakkarAI::SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId)
{
    if (uiMotionType != POINT_MOTION_TYPE || !pSummoned->IsAlive())
        return;

    if (pSummoned->GetEntry() == NPC_HAKKARI_MINION)
    {
        switch (uiPointId)
        {
            case 0:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 1:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 2:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 3:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 4:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 5:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 6:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 7:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId + 10, -466.110f, 274.284f, -90.460f, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 10:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[0].m_fX, aMobDest[0].m_fY, aMobDest[0].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 11:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[1].m_fX, aMobDest[1].m_fY, aMobDest[1].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 12:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[2].m_fX, aMobDest[2].m_fY, aMobDest[2].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 13:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[3].m_fX, aMobDest[3].m_fY, aMobDest[3].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 14:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[4].m_fX, aMobDest[4].m_fY, aMobDest[4].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 15:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[5].m_fX, aMobDest[5].m_fY, aMobDest[5].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 16:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[6].m_fX, aMobDest[6].m_fY, aMobDest[6].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
            case 17:
                pSummoned->GetMotionMaster()->MovePoint(uiPointId - 10, aMobDest[7].m_fX, aMobDest[7].m_fY, aMobDest[7].m_fZ, MOVE_PATHFINDING | MOVE_WALK_MODE | MOVE_FORCE_DESTINATION);
                break;
        }
    }
    if (pSummoned->GetEntry() == NPC_SUPPRESSOR)
    {
        switch (uiPointId)
        {
            case 0:
                pSummoned->GetMotionMaster()->MoveIdle();
                if (pSummoned->IsAlive())
                    if (Creature* Shade = pSummoned->FindNearestCreature(8440, 150.0f)) // NPC_SHADE_OF_HAKKAR
                        pSummoned->CastSpell(Shade, SPELL_SUPPRESSION, false);
                break;
        }
    }
}

void npc_shade_hakkarAI::UpdateAI(uint32 const uiDiff)
{
    if (CheckTimer <= uiDiff && !EngagedOnce)
    {
        /*if (Creature* Cre = m_creature->FindNearestCreature(8440, 20.0f))    // NPC_SHADE_OF_HAKKAR
            if (Cre->GetGUID() != m_pInstance->GetData64(8440))
                Cre->DisappearAndDie();*/

        m_creature->SetInCombatWithZone();
        SetCombatMovement(false);
        EngagedOnce = true;
        return;
    }
    else
        CheckTimer -= uiDiff;

    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim() || !m_pInstance)
        return;

    if (m_creature->HasAura(SPELL_SUPPRESSION))
    {
        if (m_uiSuppressingTimer <= uiDiff)
        {
            EnterEvadeMode();
            return;
        }
        else
            m_uiSuppressingTimer -= uiDiff;
    }
    else
        m_uiSuppressingTimer = 10000;

    if (m_uiHakkariTimer <= uiDiff)
    {
        uint32 uiRoll = urand(0, 99);
        int uiMaxSummons = uiRoll < 75 ? 1 : uiRoll < 95 ? 2 : 3;

        // NPC_BLOODKEEPER
        if (FirstPop)
        {
            int RandomLoc = urand(0, 7);
            m_creature->SummonCreature(NPC_BLOODKEEPER, aMobLocs[RandomLoc].m_fX, aMobLocs[RandomLoc].m_fY, aMobLocs[RandomLoc].m_fZ, aMobLocs[RandomLoc].m_fO, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);
        }
        else if (!urand(0, 3) && eventSpawns[SHADE_KEEPER_TYPE] < MAX_BLOODKEEPER)
        {
            int RandomLoc = urand(0, 7);
            m_creature->SummonCreature(NPC_BLOODKEEPER, aMobLocs[RandomLoc].m_fX, aMobLocs[RandomLoc].m_fY, aMobLocs[RandomLoc].m_fZ, aMobLocs[RandomLoc].m_fO, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);
            --uiMaxSummons;
        }

        // NPC_HAKKARI_MINION
        if (FirstPop)
        {
            for (int i = 0; i < 8; i++)
                if (Creature* Minion = m_creature->SummonCreature(NPC_HAKKARI_MINION, aMobLocs[i].m_fX, aMobLocs[i].m_fY, aMobLocs[i].m_fZ, aMobLocs[i].m_fO, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                    Minion->GetMotionMaster()->MovePoint(i, aMobDest[i].m_fX, aMobDest[i].m_fY, aMobDest[i].m_fZ, MOVE_PATHFINDING | MOVE_FORCE_DESTINATION | MOVE_WALK_MODE);
        }
        else if (eventSpawns[SHADE_HAKKARI_TYPE] < MAX_HAKKARI_MINION)
        {
            for (int i = 0; i < uiMaxSummons; i++)
            {
                int rand = urand(0, 7);
                if (Creature* Minion = m_creature->SummonCreature(NPC_HAKKARI_MINION, aMobLocs[rand].m_fX, aMobLocs[rand].m_fY, aMobLocs[rand].m_fZ, aMobLocs[rand].m_fO, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                    Minion->GetMotionMaster()->MovePoint(rand, aMobDest[rand].m_fX, aMobDest[rand].m_fY, aMobDest[rand].m_fZ, MOVE_PATHFINDING | MOVE_FORCE_DESTINATION | MOVE_WALK_MODE);
            }
        }

        if (FirstPop)
            FirstPop = false;

        m_uiHakkariTimer = urand(5000, 15000);
    }
    else
        m_uiHakkariTimer -= uiDiff;

    if (m_uiSuppressorTimer)
    {
        if (m_uiSuppressorTimer <= uiDiff)
        {
            // NPC_SUPPRESSOR
            if (urand(0, 1))
            {
                if (Creature* Suppressor = m_creature->SummonCreature(NPC_SUPPRESSOR, -415.681f, 276.184f, -91.201f, 3.174f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                    Suppressor->GetMotionMaster()->MovePoint(0, -448.663f, 276.239f, -90.615f, MOVE_PATHFINDING | MOVE_FORCE_DESTINATION | MOVE_WALK_MODE);
            }
            else if (Creature* Suppressor = m_creature->SummonCreature(NPC_SUPPRESSOR, -518.494f, 276.067f, -91.201f, 6.280f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                Suppressor->GetMotionMaster()->MovePoint(0, -485.250f, 276.099f, -90.672f, MOVE_PATHFINDING | MOVE_FORCE_DESTINATION | MOVE_WALK_MODE);
            m_uiSuppressorTimer = 0;
        }
        else
            m_uiSuppressorTimer -= uiDiff;
    }
}

void npc_shade_hakkarAI::SummonJustDied(Creature *m_creature)
{
    switch (m_creature->GetEntry())
    {
        case NPC_HAKKARI_MINION:
            if (eventSpawns[SHADE_HAKKARI_TYPE] > 0)
                --eventSpawns[SHADE_HAKKARI_TYPE];
            break;
        case NPC_BLOODKEEPER:
            if (eventSpawns[SHADE_KEEPER_TYPE] > 0)
                --eventSpawns[SHADE_KEEPER_TYPE];
            break;
    }
}

CreatureAI* GetAI_npc_shade_hakkar(Creature* pCreature)
{
    return new npc_shade_hakkarAI(pCreature);
}

/*######
## go_atalai_light
######*/
struct go_atalai_lightAI: public GameObjectAI
{
    go_atalai_lightAI(GameObject* pGo) : GameObjectAI(pGo) {}

    bool OnUse(Unit* pUser) override
    {
        ScriptedInstance* pInstance = (ScriptedInstance*)me->GetInstanceData();

        if (!pInstance || pInstance->GetData(TYPE_ATALARION) == DONE)
            return false;

        pInstance->SetData64(me->GetEntry(), me->GetGUID());
        pInstance->SetData(TYPE_ATALARION, IN_PROGRESS);

        return true;
    }
};

GameObjectAI* GetAIgo_atalai_light(GameObject *pGo)
{
    return new go_atalai_lightAI(pGo);
}

void AddSC_sunken_temple()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_malfurion_stormrage";
    pNewScript->GetAI = &GetAI_npc_malfurion;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "at_shade_of_eranikus";
    pNewScript->pAreaTrigger = &AreaTrigger_at_shade_of_eranikus;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_eternal_flame";
    pNewScript->GOGetAI = &GetAIgo_eternal_flame;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_shade_hakkar";
    pNewScript->GetAI = &GetAI_npc_shade_hakkar;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_atalai_light";
    pNewScript->GOGetAI = &GetAIgo_atalai_light;
    pNewScript->RegisterSelf();
}
