/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Mekgineer_Thermaplugg
SD%Complete: 90 - Timer
SDComment: Timer need improvement, especially for bomb-spawning
SDCategory: Gnomeregan
EndScriptData */

#include "scriptPCH.h"
#include "gnomeregan.h"

enum
{
    SAY_AGGRO                           = -1090024,
    SAY_PHASE                           = -1090025,
    SAY_BOMB                            = -1090026,
    SAY_SLAY                            = -1090027,

    SPELL_ACTIVATE_BOMB_A               = 11511,            // Target Dest = -530.754 670.571 -313.784
    SPELL_ACTIVATE_BOMB_B               = 11795,            // Target Dest = -530.754 670.571 -313.784
    SPELL_KNOCK_AWAY                    = 10101,
    SPELL_KNOCK_AWAY_AOE                = 11130,
    SPELL_WALKING_BOMB_EFFECT           = 11504,

    NPC_WALKING_BOMB                    = 7915,
};

static float const fBombSpawnZ  = -316.2625f;

struct boss_thermapluggAI : public ScriptedAI
{
    boss_thermapluggAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (instance_gnomeregan*)pCreature->GetInstanceData();
        Reset();
    }

    instance_gnomeregan* m_pInstance;
    bool m_bIsPhaseTwo;

    uint32 m_uiKnockAwayTimer;
    uint32 m_uiActivateBombTimer;

    sBombFace* m_asBombFaces;
    float m_afSpawnPos[3];

    std::list<uint64> m_lSummonedBombGUIDs;
    std::list<uint64> m_lLandedBombGUIDs;

    void Reset() override
    {
        m_uiKnockAwayTimer = urand(17000, 20000);
        m_uiActivateBombTimer = urand(10000, 15000);
        m_bIsPhaseTwo = false;
        m_asBombFaces = nullptr;

        memset(&m_afSpawnPos, 0.0f, sizeof(m_afSpawnPos));
        m_lLandedBombGUIDs.clear();
    }

    void KilledUnit(Unit* pVictim) override
    {
        DoScriptText(SAY_SLAY, m_creature);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_THERMAPLUGG, DONE);

        m_lSummonedBombGUIDs.clear();
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);

        if (m_pInstance)
        {
            m_pInstance->SetData(TYPE_THERMAPLUGG, IN_PROGRESS);
            m_asBombFaces = m_pInstance->GetBombFaces();
        }

        m_afSpawnPos[0] = m_creature->GetPositionX();
        m_afSpawnPos[1] = m_creature->GetPositionY();
        m_afSpawnPos[2] = m_creature->GetPositionZ();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_THERMAPLUGG, FAIL);

        // Remove remaining bombs
        for (const auto& guid : m_lSummonedBombGUIDs)
        {
            if (Creature* pBomb = m_creature->GetMap()->GetCreature(guid))
                pBomb->ForcedDespawn();
        }
        m_lSummonedBombGUIDs.clear();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_WALKING_BOMB)
        {
            m_lSummonedBombGUIDs.push_back(pSummoned->GetGUID());
            // calculate point for falling down
            float fX, fY, fZ;
            fX = 0.2 * m_afSpawnPos[0] + 0.8 * pSummoned->GetPositionX();
            fY = 0.2 * m_afSpawnPos[1] + 0.8 * pSummoned->GetPositionY();
            fZ = m_afSpawnPos[2] - 2.0f;
            pSummoned->UpdateGroundPositionZ(fX, fY, fZ);
            pSummoned->GetMotionMaster()->MovePoint(1, fX, fY, fZ, MOVE_FALLING);
        }
    }

    void SummonedMovementInform(Creature* pSummoned, uint32 uiMotionType, uint32 uiPointId) override
    {
        if (pSummoned->GetEntry() == NPC_WALKING_BOMB && uiMotionType == POINT_MOTION_TYPE && uiPointId == 1)
            m_lLandedBombGUIDs.push_back(pSummoned->GetGUID());
    }

    void SummonedCreatureDespawn(Creature* pSummoned) override
    {
        m_lSummonedBombGUIDs.remove(pSummoned->GetGUID());
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Movement of Summoned mobs
        if (!m_lLandedBombGUIDs.empty())
        {
            for (const auto& guid : m_lLandedBombGUIDs)
            {
                if (Creature* pBomb = m_creature->GetMap()->GetCreature(guid))
                    pBomb->GetMotionMaster()->MoveFollow(m_creature, 0.0f, 0.0f);
            }
            m_lLandedBombGUIDs.clear();
        }

        if (!m_bIsPhaseTwo && m_creature->GetHealthPercent() < 50.0f)
        {
            DoScriptText(SAY_PHASE, m_creature);
            m_bIsPhaseTwo = true;
        }

        if (m_uiKnockAwayTimer < uiDiff)
        {
            if (m_bIsPhaseTwo)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_KNOCK_AWAY_AOE) == CAST_OK)
                    m_uiKnockAwayTimer = 12000;
            }
            else
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                    m_uiKnockAwayTimer = urand(17000, 20000);
            }
        }
        else
            m_uiKnockAwayTimer -= uiDiff;

        if (m_uiActivateBombTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, m_bIsPhaseTwo ? SPELL_ACTIVATE_BOMB_B : SPELL_ACTIVATE_BOMB_A) == CAST_OK)
            {
                m_uiActivateBombTimer = (m_bIsPhaseTwo ? urand(6, 12) : urand(12, 17)) * IN_MILLISECONDS;
                if (!urand(0, 5))                           // TODO, chance/ place for this correct?
                    DoScriptText(SAY_BOMB, m_creature);
            }
        }
        else
            m_uiActivateBombTimer -= uiDiff;

        // Spawn bombs
        if (m_asBombFaces)
        {
            for (uint8 i = 0; i < MAX_GNOME_FACES; i++)
            {
                if (m_asBombFaces[i].m_bActivated)
                {
                    if (m_asBombFaces[i].m_uiBombTimer < uiDiff)
                    {
                        std::list<Creature*> m_BombList;
                        GetCreatureListWithEntryInGrid(m_BombList, m_creature, NPC_WALKING_BOMB, 250.0f);
                        if (m_BombList.size() < MAX_GNOME_FACES)
                        {
                            // Calculate the spawning position as 90% between face and thermaplugg spawn-pos, and hight hardcoded
                            float fX = 0.0f, fY = 0.0f;
                            if (GameObject* pFace = m_creature->GetMap()->GetGameObject(m_asBombFaces[i].m_uiGnomeFaceGUID))
                            {
                                fX = 0.35 * m_afSpawnPos[0] + 0.65 * pFace->GetPositionX();
                                fY = 0.35 * m_afSpawnPos[1] + 0.65 * pFace->GetPositionY();
                            }
                            m_creature->SummonCreature(NPC_WALKING_BOMB, fX, fY, fBombSpawnZ, 0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        }
                        m_asBombFaces[i].m_uiBombTimer = urand(10000, 25000);   // TODO
                    }
                    else
                        m_asBombFaces[i].m_uiBombTimer -= uiDiff;
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_thermaplugg(Creature* pCreature)
{
    return new boss_thermapluggAI(pCreature);
}

bool EffectDummyCreature_spell_boss_thermaplugg(WorldObject* /*pCaster*/, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget)
{
    if ((uiSpellId != SPELL_ACTIVATE_BOMB_A && uiSpellId != SPELL_ACTIVATE_BOMB_B) || uiEffIndex != EFFECT_INDEX_0)
        return false;

    // This spell should select a random Bomb-Face and activate it if needed
    if (instance_gnomeregan* pInstance = (instance_gnomeregan*)pCreatureTarget->GetInstanceData())
        pInstance->DoActivateBombFace(urand(0, MAX_GNOME_FACES - 1));

    return true;
}

bool GOHello_go_gnomeface_button(Player* pPlayer, GameObject* pGo)
{
    instance_gnomeregan* pInstance = (instance_gnomeregan*)pPlayer->GetInstanceData();
    if (!pInstance)
        return false;

    // If a button is used, the related face should be deactivated (if already activated)
    switch (pGo->GetEntry())
    {
        case GO_BUTTON_1:
            pInstance->DoDeactivateBombFace(0);
            break;
        case GO_BUTTON_2:
            pInstance->DoDeactivateBombFace(1);
            break;
        case GO_BUTTON_3:
            pInstance->DoDeactivateBombFace(2);
            break;
        case GO_BUTTON_4:
            pInstance->DoDeactivateBombFace(3);
            break;
        case GO_BUTTON_5:
            pInstance->DoDeactivateBombFace(4);
            break;
        case GO_BUTTON_6:
            pInstance->DoDeactivateBombFace(5);
            break;
    }

    return false;
}

void AddSC_boss_thermaplugg()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_thermaplugg";
    pNewScript->GetAI = &GetAI_boss_thermaplugg;
    pNewScript->pEffectDummyCreature = &EffectDummyCreature_spell_boss_thermaplugg;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "go_gnomeface_button";
    pNewScript->pGOHello = &GOHello_go_gnomeface_button;
    pNewScript->RegisterSelf();
}
