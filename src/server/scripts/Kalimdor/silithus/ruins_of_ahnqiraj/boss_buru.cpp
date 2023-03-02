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
SDName: Boss_Buru
SD%Complete: 100%
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

#include "scriptPCH.h"
#include "ruins_of_ahnqiraj.h"

enum
{
    EMOTE_TARGET                = 11074,

    SPELL_CREEPING_PLAGUE       = 20512,
    SPELL_DISMEMBER             = 96,
    SPELL_GAIN_SPEED            = 1834,
    SPELL_FULL_SPEED            = 1557,
    SPELL_THORNS                = 25640,
    SPELL_BURU_TRANSFORM        = 24721,
    SPELL_SELF_FREEZE           = 29826,

    NPC_BURU_EGG                = 15514,
    SPELL_SUMMON_HATCHLING      = 1881,
    SPELL_EXPLODE               = 19593,
    NPC_BURU_EGG_TRIGGER        = 15964,

    NPC_HIVEZARA_HATCHLING      = 15521,

    MODEL_INVISIBLE             = 11686
};

float const THREAT_LOCK = FLT_MAX;

static SpawnLocations AddPop[] =
{
    { -9312.0f, 1281.0f, -62.0f },
    { -9268.0f, 1249.0f, -62.0f },
    { -9263.0f, 1292.0f, -63.0f }
};

static SpawnLocations Eggs[] =
{
    { -9312.73f, 1281.51f, -63.56f },
    { -9300.03f, 1304.52f, -63.25f },
    { -9263.38f, 1293.48f, -63.84f },
    { -9245.11f, 1280.30f, -63.33f },
    { -9234.96f, 1244.95f, -63.05f },
    { -9267.78f, 1249.26f, -63.58f }
};

struct boss_buruAI : public ScriptedAI
{
    boss_buruAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    bool m_bIsEnraged;
    bool m_HatchPop;

    uint32 m_uiDismember_Timer;
    uint32 m_uiSpeed_Timer;
    uint32 m_uiCreepingPlague_Timer;
    uint32 m_uiTransformTimer;
    uint32 m_uiRespawnEgg_Timer[6];
    uint8 m_transitionStep;

    uint64 m_eggsGUID[6];

    void Reset() override
    {
        m_creature->SetDisplayId(15654);
        m_creature->RemoveAllAuras();
        m_creature->UpdateSpeed(MOVE_RUN, true, 0.5f);
        m_bIsEnraged = false;
        m_HatchPop = false;
        m_uiDismember_Timer = 1000;
        m_uiSpeed_Timer = 30000;
        m_uiCreepingPlague_Timer = 6000;
        m_uiTransformTimer = 0;
        m_transitionStep = 0;

        for (uint32 & i : m_uiRespawnEgg_Timer)
            i = 120000;

        Creature* egg;
        for (int i = 0; i < 6; i++)
        {
            egg = m_pInstance->GetCreature(m_eggsGUID[i]);
            if (egg != nullptr)
                egg->AddObjectToRemoveList();
            if (Creature* egg = m_creature->SummonCreature(NPC_BURU_EGG, Eggs[i].x, Eggs[i].y, Eggs[i].z, 0))
                m_eggsGUID[i] = egg->GetGUID();
        }

        if (m_pInstance)
            m_pInstance->SetData(TYPE_BURU, NOT_STARTED);
    }

    void EnterCombat(Unit *pWho) override
    {
        m_creature->SetInCombatWithZone();
        m_creature->SetArmor(20000);
        DoCast(m_creature, SPELL_THORNS);
        if (!IsMeleeAttackEnabled())
            SetMeleeAttack(true);
        if (!IsCombatMovementEnabled())
            SetCombatMovement(true);
        if (m_pInstance)
            m_pInstance->SetData(TYPE_BURU, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        // The debuff should fade when dead, otherwise the raid gets decimated 
        Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
        for (const auto& i : liste)
            i.getSource()->RemoveAurasDueToSpell(SPELL_CREEPING_PLAGUE);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_BURU, DONE);
    }

    void AttackStart(Unit* pVictim) override
    {
        if (m_bIsEnraged && m_uiTransformTimer)
            return;

        ScriptedAI::AttackStart(pVictim);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        Creature* egg;
        for (int i = 0; i < 6 && !m_bIsEnraged; i++)
        {
            egg = m_pInstance->GetCreature(m_eggsGUID[i]);
            if (egg == nullptr)
            {
                if (Creature* egg = m_creature->SummonCreature(NPC_BURU_EGG, Eggs[i].x, Eggs[i].y, Eggs[i].z, 0))
                    m_eggsGUID[i] = egg->GetGUID();
            }
            else if (!egg->IsAlive())
            {
                if (m_uiRespawnEgg_Timer[i] < uiDiff)
                {
                    m_uiRespawnEgg_Timer[i] = 120000;
                    egg->Respawn();
                }
                else
                    m_uiRespawnEgg_Timer[i] -= uiDiff;

            }
        }

        // Phase transition. All this to have a nice visual :)
        if (m_bIsEnraged && m_uiTransformTimer)
        {
            if (m_uiTransformTimer <= uiDiff)
            {
                switch (m_transitionStep)
                {
                    case 0:
                    {    
                        m_creature->RemoveAllAuras(); // Delete Thorns ability during Phase 2
                        DoCastSpellIfCan(m_creature, SPELL_BURU_TRANSFORM);
                        m_transitionStep = 1;
                        m_uiTransformTimer = 5000;
                        break;
                    }
                    case 1:
                    {
                        DoCastSpellIfCan(m_creature, SPELL_FULL_SPEED, CF_TRIGGERED);
                        SetMeleeAttack(true);
                        SetCombatMovement(true);
                        m_creature->SetInCombatWithZone();
                        m_transitionStep = 2;
                        m_uiTransformTimer = 0;
                        break;
                    }
                }
            }
            else
                m_uiTransformTimer -= uiDiff;

            return;
        }

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // If he is not enraged and no longer has a threat list, he chooses a person with focus at random 
        if (!m_bIsEnraged)
        {
            if (m_creature->GetHealthPercent() < 20)
            {
                m_bIsEnraged = true;

                // The transformation spell should not be cast right away if you want to have the visual. 
                m_uiTransformTimer = 200;
                m_transitionStep = 0;

                // Removed armor, enrage, reset aggro list and reset speed to normal
                m_creature->SetArmor(0);
                m_creature->DeleteThreatList();
                m_creature->RemoveAurasDueToSpell(SPELL_GAIN_SPEED);
                m_creature->UpdateSpeed(MOVE_RUN, true, 1.0f);

                if (m_creature->GetVictim())
                    m_creature->SetFacingToObject(m_creature->GetVictim());

                SetMeleeAttack(false);
                SetCombatMovement(false);
                m_creature->AttackStop(true);

                // Despawn eggs when enraged
                for (uint64 & guid : m_eggsGUID)
                {
                    if (guid)
                    {
                        if (Creature* egg = m_pInstance->GetCreature(guid))
                            egg->AddObjectToRemoveList();

                        guid = 0;
                    }
                }
            }
            else if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()) < (THREAT_LOCK / 1000))
            {
                std::array<uint64, 40> GUIDs = { };

                int var = 0;
                ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                for (const auto itr : tList)
                {
                    Player* pPlayer = m_creature->GetMap()->GetPlayer(itr->getUnitGuid());
                    if (pPlayer && pPlayer->IsAlive())
                    {
                        GUIDs[var] = itr->getUnitGuid();
                        ++var;
                    }
                }

                if (var)
                {

                    if (Player* pTarget = m_creature->GetMap()->GetPlayer(GUIDs[urand(0, var - 1)]))
                    {
                        DoScriptText(EMOTE_TARGET, m_creature, pTarget);

                        // To lock the target, we apply a very high threat
                        m_creature->GetThreatManager().addThreat(pTarget, THREAT_LOCK);

                        m_creature->RemoveAurasDueToSpell(SPELL_GAIN_SPEED);
                        m_creature->UpdateSpeed(MOVE_RUN, true, 0.5f);
                        m_uiSpeed_Timer = 30000;
                    }
                }
            }
        }

        // Dismember - A stacking bleed effect that does 1248 damage every 2 second. Buru will use this if he catches up to whoever he is targeting.
        if (m_uiDismember_Timer < uiDiff && !m_bIsEnraged)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_DISMEMBER) == CAST_OK)
                m_uiDismember_Timer = 6000;
        }
        else
            m_uiDismember_Timer -= uiDiff;

        // Creeping plague
        if (m_bIsEnraged)
        {
            if (m_uiCreepingPlague_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_CREEPING_PLAGUE) == CAST_OK)
                    m_uiCreepingPlague_Timer = 6000;
            }
            else
                m_uiCreepingPlague_Timer -= uiDiff;

            // Pop additions when enraged (3, but I'm not sure of this number and don't know if they all happen at once) 
            if (!m_HatchPop)
            {
                for (const auto& i : AddPop)
                {
                    if (Creature* summoned = m_creature->SummonCreature(NPC_HIVEZARA_HATCHLING, i.x, i.y, i.z, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
                        summoned->SetInCombatWithZone();
                }
                m_HatchPop = true;
            }
        }

        // Gain speed
        if (m_uiSpeed_Timer < uiDiff)
        {
            m_creature->CastSpell(m_creature, SPELL_GAIN_SPEED, true);
            m_uiSpeed_Timer = 30000;
        }
        else
            m_uiSpeed_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};


struct mob_buru_eggAI : public ScriptedAI
{
    mob_buru_eggAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    Creature* pBuru;

    void Reset() override
    {
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        // Aggro Buru on taking damage
        if (Creature* pBuru = m_pInstance->GetCreature(m_pInstance->GetData64(DATA_BURU)))
        {
            if (!pBuru->IsInCombat())
                pBuru->SetInCombatWithZone();
        }
    }

    void JustDied(Unit* pKiller) override
    {
        if (!m_pInstance)
            return;

        // Explodes and spawns a creature when it dies
        m_creature->CastSpell(m_creature, SPELL_EXPLODE, false);

        if (Creature* add = m_creature->SummonCreature(NPC_HIVEZARA_HATCHLING, m_creature->GetPositionX(), m_creature->GetPositionY(),
            m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000))
        {
            add->SetInCombatWithZone();
        }
    }

    void UpdateAI(uint32 const /*uiDiff*/) override {}
};

CreatureAI* GetAI_boss_buru(Creature* pCreature)
{
    return new boss_buruAI(pCreature);
}

CreatureAI* GetAI_mob_buru_egg(Creature* pCreature)
{
    return new mob_buru_eggAI(pCreature);
}

void AddSC_boss_buru()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_buru";
    newscript->GetAI = &GetAI_boss_buru;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_buru_egg";
    newscript->GetAI = &GetAI_mob_buru_egg;
    newscript->RegisterSelf();
}

