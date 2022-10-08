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
SDName: boss_cannon_master_willey
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"

//front, left
//previously
//3536.851807f -17
//-2958.885986f +13
#define ADD_1X  3537.2725f
#define ADD_1Y  -2958.18f
#define ADD_1Z 125.001015f
#define ADD_1O 0.592007f
//front, right
#define ADD_2X 3542.206299f
#define ADD_2Y -2965.929932f
#define ADD_2Z 125.001015f
#define ADD_2O 0.592007f
//mid, left
#define ADD_3X 3539.417480f
#define ADD_3Y -2959.667236f
#define ADD_3Z 125.001015f
#define ADD_3O 0.592007f
//mid, right
#define ADD_4X 3540.651855f
#define ADD_4Y -2964.519043f
#define ADD_4Z 125.001015f
#define ADD_4O 0.592007f
//back, left
#define ADD_5X 3531.927246f
#define ADD_5Y -2962.977295f
#define ADD_5Z 125.001015f
#define ADD_5O 0.592007f
//back, mid
#define ADD_6X 3538.094697f
#define ADD_6Y -2963.123291f
#define ADD_6Z 125.001015f
#define ADD_6O 0.592007f
//back, right
#define ADD_7X 3535.727539f
#define ADD_7Y -2969.776123f
#define ADD_7Z 125.001015f
#define ADD_7O 0.592007f
//behind, left
#define ADD_8X 3532.156250f
#define ADD_8Y -2966.162354f
#define ADD_8Z 125.001015f
#define ADD_8O 0.592007f
//behind, right
#define ADD_9X 3533.202148f
#define ADD_9Y -2969.437744f
#define ADD_9Z 125.001015f
#define ADD_9O 0.592007f


/*######
## boss_cannon_master_willey
######*/

enum
{
    SPELL_KNOCK_AWAY        = 10101,
    SPELL_PUMMEL            = 15615,
    SPELL_SHOOT             = 20463,
  //SPELL_SUMMON_CRIMSON    = 17279,            // Summons three Crimson Rifleman

    NPC_CRIMSON_RIFLEMAN    = 11054,

    GO_WILLEY_GATE          = 175969,

    CLOSED    = 0,
    OPEN      = 1
};

struct boss_cannon_master_willeyAI : public ScriptedAI
{
    boss_cannon_master_willeyAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }
    ScriptedInstance* pInstance;

    bool m_bInMelee;
    uint32 m_uiKnockAwayTimer;
    uint32 m_uiPummelTimer;
    uint32 m_uiShootTimer;
    uint32 m_uiSummonRiflemanTimer;

    void Reset() override
    {
        ToggleGate(OPEN);

        SetCombatMovement(true);
        m_bInMelee                  = true;

        m_uiKnockAwayTimer          = urand(15000, 20000);
        m_uiPummelTimer             = urand(5000, 10000);
        m_uiShootTimer              = 1000;
        m_uiSummonRiflemanTimer     = 5000;
    }

    void Aggro(Unit* pWho) override
    {
        ToggleGate(CLOSED);
    }

    void JustDied(Unit* Victim) override
    {
        ToggleGate(OPEN);
    }

    void ToggleGate(bool bOpen)
    {
        if (GameObject* pGo = m_creature->FindNearestGameObject(GO_WILLEY_GATE, 200.0f))
        {
            if (bOpen && pGo->GetGoState() == GO_STATE_READY)
                pInstance->DoUseDoorOrButton(pGo->GetObjectGuid());
            if (!bOpen && pGo->GetGoState() == GO_STATE_ACTIVE)
                pInstance->DoUseDoorOrButton(pGo->GetObjectGuid());
        }
    }

    void JustSummoned(Creature* pWho) override
    {
        pWho->SetInCombatWithZone();
    }

    void EnterEvadeMode() override
    {
        std::list<Creature*> RiflemanList;
        GetCreatureListWithEntryInGrid(RiflemanList, m_creature, NPC_CRIMSON_RIFLEMAN, 200.0f);
        for (const auto& itr : RiflemanList)
            itr->ForcedDespawn();
        
        ScriptedAI::EnterEvadeMode();
    }

    void UpdateAI(uint32 const diff) override
    {
        //Return since we have no target
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        // Pummel
        if (m_uiPummelTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PUMMEL) == CAST_OK)
                m_uiPummelTimer = 12000;
        }
        else 
            m_uiPummelTimer -= diff;

        // Knock Away
        if (m_uiKnockAwayTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_KNOCK_AWAY) == CAST_OK)
                m_uiKnockAwayTimer = urand(15000, 20000);
        }
        else 
            m_uiKnockAwayTimer -= diff;

        // Summon Rifleman
        if (m_uiSummonRiflemanTimer < diff)
        {
            //Cast
            switch (urand(0, 8))
            {
                case 0:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_1X,ADD_1Y,ADD_1Z,ADD_1O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_2X,ADD_2Y,ADD_2Z,ADD_2O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_4X,ADD_4Y,ADD_4Z,ADD_4O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 1:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_2X,ADD_2Y,ADD_2Z,ADD_2O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_3X,ADD_3Y,ADD_3Z,ADD_3O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_5X,ADD_5Y,ADD_5Z,ADD_5O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 2:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_3X,ADD_3Y,ADD_3Z,ADD_3O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_4X,ADD_4Y,ADD_4Z,ADD_4O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_6X,ADD_6Y,ADD_6Z,ADD_6O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 3:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_4X,ADD_4Y,ADD_4Z,ADD_4O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_5X,ADD_5Y,ADD_5Z,ADD_5O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_7X,ADD_7Y,ADD_7Z,ADD_7O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 4:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_5X,ADD_5Y,ADD_5Z,ADD_5O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_6X,ADD_6Y,ADD_6Z,ADD_6O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_8X,ADD_8Y,ADD_8Z,ADD_8O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 5:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_6X,ADD_6Y,ADD_6Z,ADD_6O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_7X,ADD_7Y,ADD_7Z,ADD_7O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_9X,ADD_9Y,ADD_9Z,ADD_9O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 6:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_7X,ADD_7Y,ADD_7Z,ADD_7O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_8X,ADD_8Y,ADD_8Z,ADD_8O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_1X,ADD_1Y,ADD_1Z,ADD_1O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 7:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_8X,ADD_8Y,ADD_8Z,ADD_8O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_9X,ADD_9Y,ADD_9Z,ADD_9O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_2X,ADD_2Y,ADD_2Z,ADD_2O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
                case 8:
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_9X,ADD_9Y,ADD_9Z,ADD_9O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_1X,ADD_1Y,ADD_1Z,ADD_1O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    m_creature->SummonCreature(NPC_CRIMSON_RIFLEMAN, ADD_3X,ADD_3Y,ADD_3Z,ADD_3O, TEMPSUMMON_TIMED_DESPAWN, 240000);
                    break;
            }            
            m_uiSummonRiflemanTimer = 10000;
        }
        else 
            m_uiSummonRiflemanTimer -= diff;

        // Shoot
        if (m_uiShootTimer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHOOT) == CAST_OK)
                m_uiShootTimer = urand(2500, 3500);
        }
        else 
            m_uiShootTimer -= diff;

        if (!IsCombatMovementEnabled())
        { //Melee
            if (!m_bInMelee && (m_creature->GetDistance2d(m_creature->GetVictim()) < 8.0f || m_creature->GetDistance2d(m_creature->GetVictim()) > 27.0f || !m_creature->IsWithinLOSInMap(m_creature->GetVictim())))
            {
                SetCombatMovement(true);
                DoStartMovement(m_creature->GetVictim());
                m_bInMelee = true;
                return;
            }
        }
        else
        { //Range
            if (m_bInMelee && m_creature->GetDistance2d(m_creature->GetVictim()) >= 8.0f && m_creature->GetDistance2d(m_creature->GetVictim()) <= 27.0f && m_creature->IsWithinLOSInMap(m_creature->GetVictim()))
            {
                SetCombatMovement(false);
                m_bInMelee = false;
                DoStartNoMovement(m_creature->GetVictim());
                return;
            }
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_cannon_master_willey(Creature* pCreature)
{
    return new boss_cannon_master_willeyAI(pCreature);
}

/*######
## GO_scarlet_cannon
######*/

enum
{
    NPC_CANNONBALL    = 160018,
    SPELL_CANNON_FIRE = 17278
};

bool GO_scarlet_cannon(Player* pPlayer, GameObject* pGo)
{
    if (Creature* pCannonBall = pPlayer->SummonCreature(NPC_CANNONBALL, 3534.661f, -2966.512f, 125.001f, 0.592f, TEMPSUMMON_TIMED_DESPAWN, 5000)) // Trigger Cannonball
    {
        pCannonBall->CastSpell(pCannonBall, SPELL_CANNON_FIRE, false);
        pCannonBall->ForcedDespawn(200);
    }
    return false;
};

void AddSC_boss_cannon_master_willey()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_cannon_master_willey";
    newscript->GetAI = &GetAI_boss_cannon_master_willey;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_scarlet_cannon";
    newscript->pGOHello = &GO_scarlet_cannon;
    newscript->RegisterSelf();
}
