/* Copyright (C) 2006 - 2013 ScriptDev2 <http://www.scriptdev2.com/>
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
SDName: Boss_Mr_Smite
SD%Complete: 100
SDComment:
SDCategory: Deadmines
EndScriptData */

#include "scriptPCH.h"
#include "deadmines.h"

enum
{
    SAY_PHASE_2                     = 1344,
    SAY_PHASE_3                     = 1345,

    EQUIP_ID_SWORD                  = 2179,
    EQUIP_ID_AXE                    = 2183,
    EQUIP_ID_HAMMER                 = 10756,

    SPELL_NIBLE_REFLEXES            = 6433,                 // removed after phase 1
    SPELL_SMITE_SLAM                = 6435,                 // only casted in phase 3
    SPELL_SMITE_STOMP               = 6432,
    SPELL_SMITE_HAMMER              = 6436,                 // unclear, not casted in
    SPELL_THRASH                    = 3391,//12787,                // only casted in phase 2; unclear, 3391 directly casted instead of proc aura

    GO_SMITE_CHEST                  = 144111, //ALITA coffre.

    PHASE_1                         = 1,
    PHASE_2                         = 2,
    PHASE_3                         = 3,
    PHASE_EQUIP_NULL                = 4,
    PHASE_EQUIP_START               = 5,
    PHASE_EQUIP_PROCESS             = 6,
    PHASE_EQUIP_END                 = 7,
};

struct boss_mr_smiteAI : public ScriptedAI
{
    boss_mr_smiteAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiPhase;
    uint32 m_uiEquipTimer;
    uint32 m_uiSlamTimer;
    uint32 m_uiThrashTimer;
    bool equiping; //Alita : Basicaly when he is not chasing the player.
    bool inSpline; //bool true while running to chest.

    void Reset() override
    {
        equiping = false;
        inSpline = false;
        m_uiPhase = PHASE_1;
        m_uiEquipTimer = 0;
        m_uiSlamTimer = 9000;
        m_uiThrashTimer = 4000;
        m_creature->LoadEquipment(m_creature->GetCreatureInfo()->equipment_id, true);
    }

    void AttackedBy(Unit* pAttacker) override
    {
        if (m_creature->GetVictim())
            return;

        if (m_uiPhase > PHASE_3)
            return;

        AttackStart(pAttacker);
    }

    void AttackStart(Unit* pWho) override
    {
        if (m_uiPhase > PHASE_3)
            return;

        if (m_creature->Attack(pWho, true))
        {
            equiping = false;
            m_creature->AddThreat(pWho);
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);

            m_creature->GetMotionMaster()->MoveChase(pWho);
        }
    }

    void MovementInform(uint32 uiMotionType, uint32 uiPointId) override
    {
        if (inSpline)
        {
            SplineFinished();
            inSpline = false;
        }

        if (!equiping)
        {
            if (uiMotionType == POINT_MOTION_TYPE)
            {
                if (Unit* target = m_creature->GetVictim())
                    m_creature->GetMotionMaster()->MoveChase(target);
            }
            return;
        }

        m_creature->SetSheath(SHEATH_STATE_UNARMED);
        m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);

        m_uiEquipTimer = 3000;
        m_uiPhase = PHASE_EQUIP_PROCESS;
    }

    void SplineFinished()
    {
        //m_creature->MonsterSay("splineFinished.");
        if (!equiping)
            return;
        m_creature->LoadEquipment(0, true);
        m_creature->SetSheath(SHEATH_STATE_UNARMED);
        m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);

        m_uiEquipTimer = 3000;
        m_uiPhase = PHASE_EQUIP_PROCESS;
    }

    void PhaseEquipStart()
    {
        GameObject* pChest = m_creature->FindNearestGameObject(GO_SMITE_CHEST, 150.000000);
        if (!pChest)
        {
            m_uiPhase = PHASE_EQUIP_PROCESS;
            return;
        }


        m_uiPhase = PHASE_EQUIP_NULL;

        float fX, fY, fZ;
        pChest->GetContactPoint(m_creature, fX, fY, fZ, CONTACT_DISTANCE);

        m_creature->GetMotionMaster()->Clear();
        m_creature->SetFacingToObject(pChest);

        inSpline = true;
        m_creature->GetMotionMaster()->MovePoint(0, fX, fY, fZ, MOVE_PATHFINDING);
    }

    void PhaseEquipProcess()
    {
        if (m_creature->GetHealthPercent() < 33.0f)
        {
            // It's Hammer, go Hammer!
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, EQUIP_ID_HAMMER);
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_1, 0);
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_2, 0);
            DoCastSpellIfCan(m_creature, SPELL_SMITE_HAMMER);
        }
        else
        {
            // It's double Axe.
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_0, EQUIP_ID_AXE);
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_1, EQUIP_ID_AXE);
            m_creature->SetVirtualItem(VIRTUAL_ITEM_SLOT_2, 0);
        }

        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_uiPhase = PHASE_EQUIP_END;
        m_uiEquipTimer = 1000;
    }

    void PhaseEquipEnd()
    {
        // We don't have getVictim, so select from threat list
        Unit* pVictim = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0);

        if (!pVictim)
        {
            EnterEvadeMode();
            return;
        }

        m_creature->SetSheath(SHEATH_STATE_MELEE);

        m_uiPhase = m_creature->GetHealthPercent() < 33.0f ? PHASE_3 : PHASE_2;

        equiping = false;
        AttackStart(pVictim);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        Unit * target = m_creature->GetVictim();
        if (!m_creature->SelectHostileTarget() || !target)
        {
            if (m_uiEquipTimer)
            {
                // decrease the cooldown in between equipment change phases
                if (m_uiEquipTimer > uiDiff)
                {
                    m_uiEquipTimer -= uiDiff;
                    return;
                }
                else
                    m_uiEquipTimer = 0;
            }

            switch (m_uiPhase)
            {
                case PHASE_EQUIP_START:
                    PhaseEquipStart();
                    break;
                case PHASE_EQUIP_PROCESS:
                    PhaseEquipProcess();
                    break;
                case PHASE_EQUIP_END:
                    PhaseEquipEnd();
                    break;
            }

            return;
        }
        // the normal combat phases
        switch (m_uiPhase)
        {
            case PHASE_1:
            {
                if (m_creature->GetHealthPercent() < 66.0f)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_SMITE_STOMP) == CAST_OK)
                    {
                        DoScriptText(m_creature->GetHealthPercent() < 33.0f ? SAY_PHASE_3 : SAY_PHASE_2, m_creature);
                        m_uiPhase = PHASE_EQUIP_START;
                        m_uiEquipTimer = 2500;

                        // will clear getVictim (m_attacking)
                        m_creature->GetMotionMaster()->Clear();
                        equiping = true;
                        m_creature->AttackStop(true);
                        m_creature->RemoveAurasDueToSpell(SPELL_NIBLE_REFLEXES);
                    }
                    return;
                }
                break;
            }
            case PHASE_2:
            {
                if (m_uiThrashTimer < uiDiff)//instead of the aura, because the aura procs too much
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THRASH) == CAST_OK)
                        m_uiThrashTimer = urand(1500, 4000);
                }
                else
                    m_uiThrashTimer -= uiDiff;

                if (m_creature->GetHealthPercent() < 33.0f)
                {
                    if (DoCastSpellIfCan(m_creature, SPELL_SMITE_STOMP) == CAST_OK)
                    {
                        DoScriptText(SAY_PHASE_3, m_creature);
                        m_uiPhase = PHASE_EQUIP_START;
                        m_uiEquipTimer = 2500;

                        // will clear getVictim (m_attacking)
                        m_creature->GetMotionMaster()->Clear();
                        equiping = true;
                        m_creature->AttackStop(true);
                        //m_creature->RemoveAurasDueToSpell(SPELL_THRASH);
                    }
                    return;
                }
                break;
            }
            case PHASE_3:
            {
                if (m_uiSlamTimer < uiDiff)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SMITE_SLAM) == CAST_OK)
                        m_uiSlamTimer = 11000;
                }
                else
                    m_uiSlamTimer -= uiDiff;


                break;
            }
        }
        if (!equiping && !m_creature->CanReachWithMeleeAutoAttack(target) && m_creature->IsWithinDistInMap(target, m_creature->GetMeleeReach() * 2)) //test Alita GetDistance
        {
            float x, y, z;
            m_creature->GetRandomAttackPoint(target, x, y, z);
            m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
        }
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_mr_smite(Creature* pCreature)
{

    return new boss_mr_smiteAI(pCreature);
}

void AddSC_boss_mr_smite()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_mr_smite";
    pNewScript->GetAI = &GetAI_boss_mr_smite;
    pNewScript->RegisterSelf();

}
