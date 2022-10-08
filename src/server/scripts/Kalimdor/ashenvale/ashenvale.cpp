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
SDName: Ashenvale
SD%Complete: 70
SDComment: Quest support: 976, 6482, 6544, 6641
SDCategory: Ashenvale Forest
EndScriptData */

/* ContentData
npc_ruul_snowhoof
npc_torek
npc_feero_ironhand
EndContentData */

#include "scriptPCH.h"

/*####
# npc_ruul_snowhoof
####*/

enum RuulSnowhoofData
{
    QUEST_FREEDOM_TO_RUUL = 6482,
    NPC_T_URSA            = 3921,
    NPC_T_TOTEMIC         = 3922,
    NPC_T_PATHFINDER      = 3926,
    SAY_RUUL_END          = 8265,
    BEAR_AURA             = 20514,
    FACTION_ESCORTEE      = 33,
};

struct npc_ruul_snowhoofAI : public npc_escortAI
{
    npc_ruul_snowhoofAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    void Reset() override
    {
        m_creature->AddAura(BEAR_AURA);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        //m_creature->MonsterYell("DEBUG : WayPoint reached", 0); //The hell, still skipping waypoints 13/02/2015
        //sLog.outString("DEBUG : Ruul : WayPoint n° %u", uiPointId);
        switch (uiPointId)
        {
            case 13:
                m_creature->SummonCreature(NPC_T_TOTEMIC, 3449.218018f, -587.825073f, 174.978867f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(NPC_T_URSA, 3446.384521f, -587.830872f, 175.186279f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(NPC_T_PATHFINDER, 3444.218994f, -587.835327f, 175.380600f, 4.714445f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                break;
            case 19:
                m_creature->SummonCreature(NPC_T_TOTEMIC, 3508.344482f, -492.024261f, 186.929031f, 4.145029f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(NPC_T_URSA, 3506.265625f, -490.531006f, 186.740128f, 4.239277f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                m_creature->SummonCreature(NPC_T_PATHFINDER, 3503.682373f, -489.393799f, 186.629684f, 4.349232f, TEMPSUMMON_DEAD_DESPAWN, 60000);
                break;
            case 25:
                m_creature->RemoveAurasDueToSpell(BEAR_AURA);
                DoScriptText(SAY_RUUL_END, m_creature);
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_FREEDOM_TO_RUUL, m_creature);
                break;
        }
    }

    void JustSummoned(Creature* summoned) override
    {
        summoned->AI()->AttackStart(m_creature);
    }
};

bool QuestAccept_npc_ruul_snowhoof(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_FREEDOM_TO_RUUL)
    {
        pCreature->SetFactionTemplateId(FACTION_ESCORTEE);
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);

        if (npc_ruul_snowhoofAI* pEscortAI = dynamic_cast<npc_ruul_snowhoofAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

CreatureAI* GetAI_npc_ruul_snowhoofAI(Creature* pCreature)
{
    return new npc_ruul_snowhoofAI(pCreature);
}

/*####
# npc_torek
####*/

enum TorekData
{
    SAY_READY   = 8284,
    SAY_MOVE    = 8278,
    SAY_PREPARE = 8282,
    SAY_WIN     = 8280,
    SAY_END     = 8281,

    SPELL_REND        = 11977,
    SPELL_THUNDERCLAP = 8078,

    FACTION_ORGRIMMAR = 1174,

    QUEST_TOREK_ASSULT = 6544,

    NPC_SPLINTERTREE_RAIDER = 12859,
    NPC_DURIEL              = 12860,
    NPC_SILVERWING_SENTINEL = 12896,
    NPC_SILVERWING_WARRIOR  = 12897
};

struct npc_torekAI : public npc_escortAI
{
    npc_torekAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiRend_Timer;
    uint32 m_uiThunderclap_Timer;

    void Reset() override
    {
        m_uiRend_Timer = 5000;
        m_uiThunderclap_Timer = 8000;
    }

    void JustDied(Unit* pKiller) override
    {
        std::list<Creature*> lCrea;
        m_creature->GetCreatureListWithEntryInGrid(lCrea, NPC_SPLINTERTREE_RAIDER, 40.0f);
        for (const auto& it : lCrea)
            it->DisappearAndDie();
        npc_escortAI::JustDied(pKiller);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (uiPointId)
        {
            case 1:
                DoScriptText(SAY_MOVE, m_creature, pPlayer);
                break;
            case 8:
                DoScriptText(SAY_PREPARE, m_creature, pPlayer);
                break;
            case 19:
                //TODO: verify location and creatures amount.
                m_creature->SummonCreature(NPC_DURIEL, 1776.73f, -2049.06f, 109.83f, 1.54f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                m_creature->SummonCreature(NPC_SILVERWING_SENTINEL, 1774.64f, -2049.41f, 109.83f, 1.40f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                m_creature->SummonCreature(NPC_SILVERWING_WARRIOR, 1778.73f, -2049.50f, 109.83f, 1.67f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                break;
            case 20:
                DoScriptText(SAY_WIN, m_creature, pPlayer);
                pPlayer->GroupEventHappens(QUEST_TOREK_ASSULT, m_creature);
                break;
            case 21:
                DoScriptText(SAY_END, m_creature, pPlayer);
                break;
            case 22:
                std::list<Creature*> lCrea;
                m_creature->GetCreatureListWithEntryInGrid(lCrea, NPC_SPLINTERTREE_RAIDER, 40.0f);
                for (const auto& it : lCrea)
                    it->DisappearAndDie();
                break;
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->AI()->AttackStart(m_creature);
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiRend_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_REND);
            m_uiRend_Timer = 20000;
        }
        else
            m_uiRend_Timer -= uiDiff;

        if (m_uiThunderclap_Timer < uiDiff)
        {
            DoCastSpellIfCan(m_creature, SPELL_THUNDERCLAP);
            m_uiThunderclap_Timer = 30000;
        }
        else
            m_uiThunderclap_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

bool QuestAccept_npc_torek(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_TOREK_ASSULT)
    {
        //TODO: find companions, make them follow Torek, at any time (possibly done by mangos/database in future?)
        DoScriptText(SAY_READY, pCreature, pPlayer);

        // Faction changes during escort.
        pCreature->SetFactionTemporary(FACTION_ORGRIMMAR, TEMPFACTION_RESTORE_RESPAWN);
        std::list<Creature*> lCrea;
        pCreature->GetCreatureListWithEntryInGrid(lCrea, NPC_SPLINTERTREE_RAIDER, 40.0f);
        for (const auto& it : lCrea)
            it->SetFactionTemporary(FACTION_ORGRIMMAR, TEMPFACTION_RESTORE_RESPAWN);

        if (npc_torekAI* pEscortAI = dynamic_cast<npc_torekAI*>(pCreature->AI()))
            pEscortAI->Start(true, pPlayer->GetGUID(), pQuest);
    }

    return true;
}

CreatureAI* GetAI_npc_torek(Creature* pCreature)
{
    return new npc_torekAI(pCreature);
}

/*####
 # npc_feero_ironhand
 ####*/

enum FeeroIronhandData
{
    SAY_QUEST_START          = 1292,
    SAY_FIRST_AMBUSH_START   = 1372,
    SAY_FIRST_AMBUSH_END     = 1294,
    SAY_SECOND_AMBUSH_START  = 1373,
    SAY_SCOUT_SECOND_AMBUSH  = 1309,
    SAY_SECOND_AMBUSH_END    = 1310,
    SAY_FINAL_AMBUSH_START   = 1374,
    SAY_BALIZAR_FINAL_AMBUSH = 1313,
    SAY_FINAL_AMBUSH_ATTACK  = 1499,
    SAY_QUEST_END            = 1315,

    QUEST_SUPPLIES_TO_AUBERDINE = 976,

    NPC_DARK_STRAND_ASSASSIN = 3879,
    NPC_FORSAKEN_SCOUT       = 3893,
    NPC_ALIGAR_THE_TORMENTOR = 3898,
    NPC_BALIZAR_THE_UMBRAGE  = 3899,
    NPC_CAEDAKAR_THE_VICIOUS = 3900
};

/*
 * Notes about the event:
 * The summon coords and event sequence are guesswork based on the comments from wowhead and wowwiki
 */

// Distance, Angle or Offset
static float const aSummonPositions[2][2] =
{
    {30.0f, 1.25f},
    {15.0f, 0.95f}//30.0f is in the tree and gets stuck with fathfinding
};

// Hardcoded positions for the last 3 mobs
static float const aEliteSummonPositions[3][4] =
{
    {4243.12f, 108.22f, 38.12f, 3.62f},
    {4240.95f, 114.04f, 38.35f, 3.56f},
    {4235.78f, 118.09f, 38.08f, 4.12f}
};

struct npc_feero_ironhandAI : public npc_escortAI
{
    npc_feero_ironhandAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    uint8 m_uiCreaturesCount;
    bool m_bIsAttacked;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiCreaturesCount = 0;
            m_bIsAttacked = false;
        }
    }

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        npc_escortAI::JustRespawned();
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 14:
                // Prepare the first ambush
                DoScriptText(SAY_FIRST_AMBUSH_START, m_creature);
                for (uint8 i = 0; i < 4; ++i)
                    DoSpawnMob(NPC_DARK_STRAND_ASSASSIN, aSummonPositions[0][0], aSummonPositions[0][1] - M_PI_F / 4 * i);
                break;
            case 20:
                // Prepare the second ambush
                DoScriptText(SAY_SECOND_AMBUSH_START, m_creature);
                for (uint8 i = 0; i < 3; ++i)
                    DoSpawnMob(NPC_FORSAKEN_SCOUT, aSummonPositions[1][0], aSummonPositions[1][1] - M_PI_F / 3 * i);
                break;
            case 29:
                // Final ambush
                DoScriptText(SAY_FINAL_AMBUSH_START, m_creature);
                m_creature->SummonCreature(NPC_BALIZAR_THE_UMBRAGE, aEliteSummonPositions[0][0], aEliteSummonPositions[0][1], aEliteSummonPositions[0][2], aEliteSummonPositions[0][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                m_creature->SummonCreature(NPC_ALIGAR_THE_TORMENTOR, aEliteSummonPositions[1][0], aEliteSummonPositions[1][1], aEliteSummonPositions[1][2], aEliteSummonPositions[1][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                m_creature->SummonCreature(NPC_CAEDAKAR_THE_VICIOUS, aEliteSummonPositions[2][0], aEliteSummonPositions[2][1], aEliteSummonPositions[2][2], aEliteSummonPositions[2][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
                break;
            case 30:
                // Complete the quest
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_SUPPLIES_TO_AUBERDINE, m_creature);
                break;
        }
    }

    void AttackedBy(Unit* pWho) override
    {
        // Yell only at the first attack
        if (!m_bIsAttacked)
        {
            if (pWho->ToCreature() && pWho->ToCreature()->GetEntry() == NPC_BALIZAR_THE_UMBRAGE)
            {
                DoScriptText(SAY_FINAL_AMBUSH_ATTACK, m_creature);
                m_bIsAttacked = true;
            }
        }
    }

    // Summon mobs at calculated points
    void DoSpawnMob(uint32 uiEntry, float fDistance, float fAngle)
    {
        float fX, fY, fZ;
        m_creature->GetNearPoint(m_creature, fX, fY, fZ, 0, fDistance, fAngle);

        m_creature->SummonCreature(uiEntry, fX, fY, fZ, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 20000);
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        --m_uiCreaturesCount;

        if (!m_uiCreaturesCount)
        {
            switch (pSummoned->GetEntry())
            {
                case NPC_DARK_STRAND_ASSASSIN:
                    DoScriptText(SAY_FIRST_AMBUSH_END, m_creature);
                    break;
                case NPC_FORSAKEN_SCOUT:
                    DoScriptText(SAY_SECOND_AMBUSH_END, m_creature);
                    break;
                case NPC_ALIGAR_THE_TORMENTOR:
                case NPC_BALIZAR_THE_UMBRAGE:
                case NPC_CAEDAKAR_THE_VICIOUS:
                    DoScriptText(SAY_QUEST_END, m_creature);
                    break;
            }
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_FORSAKEN_SCOUT)
        {
            // Only one of the scouts yells
            if (m_uiCreaturesCount == 1)
                DoScriptText(SAY_SCOUT_SECOND_AMBUSH, pSummoned, m_creature);
        }
        else if (pSummoned->GetEntry() == NPC_BALIZAR_THE_UMBRAGE)
            DoScriptText(SAY_BALIZAR_FINAL_AMBUSH, pSummoned);

        ++m_uiCreaturesCount;
        if (Player* pPlayer = GetPlayerForEscort())
            pSummoned->AI()->AttackStart(pPlayer);
    }
};

CreatureAI* GetAI_npc_feero_ironhand(Creature* pCreature)
{
    return new npc_feero_ironhandAI(pCreature);
}

bool QuestAccept_npc_feero_ironhand(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_SUPPLIES_TO_AUBERDINE)
    {
        DoScriptText(SAY_QUEST_START, pCreature, pPlayer);
        pCreature->SetFactionTemplateId(FACTION_ESCORT_A_NEUTRAL_PASSIVE);
        pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);

        if (npc_feero_ironhandAI* pEscortAI = dynamic_cast<npc_feero_ironhandAI*>(pCreature->AI()))
            pEscortAI->Start(true, pPlayer->GetGUID(), pQuest);
    }

    return true;
}

//Alita King Of The Foulweed
enum FoulwealdTotemMoundData
{
    NPC_ENRAGED_FOULWEALD = 12921,
    NPC_CHIEF_MURGUT      = 12918,

    GO_KARANG_S_BANNER = 178205,
    GO_KARANG_LIGHT    = 178207,
    GO_MOUND           = 300131,

    SPELL_CORRUPTED_STRENGTH        = 6821,
    SPELL_DESTROY_KARANG_S_BANNER_1 = 20786,
    SPELL_DESTROY_KARANG_S_BANNER_2 = 20783,

    SAY_ATTACK_BANNER = 8398
};

static float foulwealdSpawnCoords[4][3] =
{
    {2237.48f, -1524.45f, 89.7827f},
    {2202.16f, -1544.48f,  87.796f},
    {2235.44f, -1578.43f, 86.4944f},
    {2260.9f, -1547.91f, 89.1733f}
};

void DefineFoulwealdMound(Creature * crea, uint64 gobjGUID);

struct go_foulweald_totem_moundAI: public GameObjectAI
{
    go_foulweald_totem_moundAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        reset();
    }

    void reset()
    {
        eventPhase = 0;
        phaseTimer = 170000;
    }

    uint64 guidCurrentEnragedFoulweald[2];
    uint8 eventPhase; //0 nothing, 1 repoping enraged foulwealds, 2 wait, 3 chief_murgut, 4 done
    uint32 phaseTimer;

    bool EventStart(uint64 playerGuid)
    {
        if (eventPhase != 0)
            return false;

        eventPhase = 1;
        Creature* foulweald = nullptr;
        for (int i = 0; i < 2; i++)
        {
            if (foulweald = me->SummonCreature(NPC_ENRAGED_FOULWEALD, foulwealdSpawnCoords[i][0], foulwealdSpawnCoords[i][1], foulwealdSpawnCoords[i][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 420000))
            {
                guidCurrentEnragedFoulweald[i] = foulweald->GetGUID();
                float x, y, z;
                me->GetPosition(x, y, z);
                foulweald->GetMotionMaster()->MovePoint(1, x, y, z, true);
                foulweald->SetHomePosition(x, y, z, 0);
                foulweald->SetRespawnDelay(425000);
                DefineFoulwealdMound(foulweald, me->GetGUID());
            }
            foulweald = nullptr;
        }
        return true;
    }

    void EventEnded()
    {
        if (GameObject* pGo = me->FindNearestGameObject(GO_KARANG_S_BANNER, 10))
            pGo->AddObjectToRemoveList();
        reset();
    }

    void EnragedFoulwealdJustDied(uint64 creatureGUID)
    {
        if (eventPhase != 1)
            return;

        Creature* foulweald;
        int pos = 0;
        for (uint64 & guid : guidCurrentEnragedFoulweald)
        {
            if (creatureGUID == guid)
            {
                pos = urand(0, 3);
                if (foulweald = me->SummonCreature(NPC_ENRAGED_FOULWEALD, foulwealdSpawnCoords[pos][0], foulwealdSpawnCoords[pos][1], foulwealdSpawnCoords[pos][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 420000))
                {
                    guid = foulweald->GetGUID();
                    float x, y, z;
                    me->GetPosition(x, y, z);
                    foulweald->GetMotionMaster()->MovePoint(1, x, y, z, true);
                    foulweald->SetHomePosition(x, y, z, 0);
                    foulweald->SetRespawnDelay(425000);
                    DefineFoulwealdMound(foulweald, me->GetGUID());
                }
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (eventPhase == 0 || eventPhase > 4)
            return;

        if (phaseTimer < uiDiff)
        {
            eventPhase++;
            switch (eventPhase)
            {
                case 2:
                    phaseTimer = 10000;
                    break;
                case 3:
                    if (Creature* murgut = me->SummonCreature(NPC_CHIEF_MURGUT, foulwealdSpawnCoords[3][0], foulwealdSpawnCoords[3][1], foulwealdSpawnCoords[3][2], 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
                    {
                        float x, y, z;
                        me->GetPosition(x, y, z);
                        murgut->GetMotionMaster()->MovePoint(1, x, y, z, true);
                        murgut->SetHomePosition(x, y, z, 0);
                        murgut->SetRespawnDelay(125000);
                        if (GameObject* pGo = me->FindNearestGameObject(GO_KARANG_S_BANNER, 10))
                        {
                            pGo->GetPosition(x, y, z);
                            me->SummonGameObject(178207, x, y, z, 0, 0, 0, 0, 0, 120);
                        }
                    }
                    phaseTimer = 120000;
                    break;
                case 4:
                    EventEnded();
                    break;
            }
        }
        else
            phaseTimer -= uiDiff;
    }
};

GameObjectAI* GetAIgo_foulweald_totem_mound(GameObject *pGo)
{
    return new go_foulweald_totem_moundAI(pGo);
}

struct npc_enraged_foulwealdAI : public ScriptedAI
{
    npc_enraged_foulwealdAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override
    {
        m_creature->AddAura(SPELL_CORRUPTED_STRENGTH);
        timer = 0;
    }

    uint32 timer;
    uint64 guidMound;

    void JustDied(Unit* pKiller) override
    {
        if (GameObject* gobj = m_creature->GetMap()->GetGameObject(guidMound))
        {
            if (go_foulweald_totem_moundAI* pMoundAI = dynamic_cast<go_foulweald_totem_moundAI*>(gobj->AI()))
                pMoundAI->EnragedFoulwealdJustDied(m_creature->GetGUID());
        }
    }

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE || uiPointId != 2)
            return;
        HitBanner();
    }

    void AttackStart(Unit * unit) override
    {
        if (m_creature->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            return;
        ScriptedAI::AttackStart(unit);
    }

    bool HitBanner()
    {
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_KARANG_S_BANNER, CONTACT_DISTANCE + 1))
        {
            float x, y, z;
            pGo->GetPosition(x, y, z);
            m_creature->CastSpell(x, y, z, SPELL_DESTROY_KARANG_S_BANNER_1, false);
            DoScriptText(SAY_ATTACK_BANNER, m_creature);
            timer = 10000;
            return true;
        }
        return false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_creature->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            return;

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            if (timer < uiDiff)
            {
                if (!HitBanner())
                {
                    if (GameObject* pGo = m_creature->FindNearestGameObject(GO_KARANG_S_BANNER, 30))
                    {
                        float fX, fY, fZ;
                        pGo->GetContactPoint(m_creature, fX, fY, fZ, CONTACT_DISTANCE);
                        m_creature->GetMotionMaster()->MovePoint(2, fX, fY, fZ, MOVE_PATHFINDING);
                        timer = 10000;
                    }
                }
            }
            else
                timer -= uiDiff;
            return;
        }
        DoMeleeAttackIfReady();
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pSpell->Id == SPELL_DESTROY_KARANG_S_BANNER_2)
        {
            if (GameObject* pGo = m_creature->FindNearestGameObject(GO_MOUND, 3))
            {
                if (go_foulweald_totem_moundAI* pMoundAI = dynamic_cast<go_foulweald_totem_moundAI*>(pGo->AI()))
                    pMoundAI->EventEnded();
            }
        }
    }

    void SetMoundGuid(uint64 moundGuid)
    {
        guidMound = moundGuid;
    }
};

CreatureAI* GetAI_npc_enraged_foulweald(Creature* pCreature)
{
    return new npc_enraged_foulwealdAI(pCreature);
}

bool ProcessEventId_event_king_of_the_foulweald(uint32 eventId, Object* source, Object* target, bool isStart)
{
    if (!target || !source)
        return true;

    if (go_foulweald_totem_moundAI* pMoundAI = dynamic_cast<go_foulweald_totem_moundAI*>(((GameObject*) target)->AI()))
        pMoundAI->EventStart(source->GetGUID());
    return true;//return the result of EventStart or true? true because otherwise it'll get the event in the DB.
}

void DefineFoulwealdMound(Creature * crea, uint64 gobjGUID)
{
    if (npc_enraged_foulwealdAI* foulwealdAI = dynamic_cast<npc_enraged_foulwealdAI*>(crea->AI()))
        foulwealdAI->SetMoundGuid(gobjGUID);
}

void AddSC_ashenvale()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_ruul_snowhoof";
    newscript->GetAI = &GetAI_npc_ruul_snowhoofAI;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_ruul_snowhoof;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_torek";
    newscript->GetAI = &GetAI_npc_torek;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_torek;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_feero_ironhand";
    newscript->GetAI = &GetAI_npc_feero_ironhand;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_feero_ironhand;
    newscript->RegisterSelf();

    //Alita
    newscript = new Script;
    newscript->Name = "event_king_of_the_foulweald";
    newscript->pProcessEventId = &ProcessEventId_event_king_of_the_foulweald;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_enraged_foulweald";
    newscript->GetAI = &GetAI_npc_enraged_foulweald;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_foulweald_totem_mound";
    newscript->GOGetAI = &GetAIgo_foulweald_totem_mound;
    newscript->RegisterSelf();
}
