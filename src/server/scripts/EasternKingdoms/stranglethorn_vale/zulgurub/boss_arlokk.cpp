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
SDName: Boss_Arlokk
SD%Complete: 95
SDComment: Wrong cleave and red aura is missing.
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

#define DISABLE_TIMER 1000000
bool GOHello_go_gong_of_bethekk(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        if (pInstance->GetData(TYPE_ARLOKK) == DONE || pInstance->GetData(TYPE_ARLOKK) == IN_PROGRESS)
            return true;

        pInstance->SetData(TYPE_ARLOKK, IN_PROGRESS);
    }

    return false;
}

enum
{
    SAY_AGGRO                   = -1309011,
    SAY_FEAST_PANTHER           = -1309012,
    SAY_DEATH                   = -1309013,

    SPELL_SHADOWWORDPAIN        = 24212, // Mot de l'ombre : douleur
    SPELL_GOUGE                 = 12540, // Suriner
    SPELL_MARK                  = 24210,
    SPELL_CLEAVE                = 26350,                    //Perhaps not right. Not a red aura...
    SPELL_PANTHER_TRANSFORM     = 24190,
    SPELL_BACKSTAB              = 15582, // Attaque sournoise
    SPELL_TOURBILLON            = 15589,
    SPELL_ATTAQUE_MENTALE       = 15587,
    SPELL_ROSSER                = 3391,
    SPELL_RAVAGE                = 24213,

    MODEL_ID_NORMAL             = 15218,
    MODEL_ID_PANTHER            = 15215,
    MODEL_ID_BLANK              = 11686,

    NPC_ZULIAN_PROWLER          = 15101,
//    NPC_ARLOKK                  = 14515, // zulgurub.h
    MAX_PANTHER_COUNT           = 30,

    GO_ARLOKK_FORCE_FIELD       = 180497,
    GO_ARLOKK_GONG              = 180526
};

/*
[SQL]
INSERT INTO creature_template SET entry=14968, modelid_1=15013, modelid_2=15013, name="High Priestess Arlokk Transform Visual", faction=35
*/

struct boss_arlokkAI : public ScriptedAI
{
    boss_arlokkAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiShadowWordPain_Timer;
    uint32 m_uiGouge_Timer;
    uint32 m_uiMark_Timer;
    uint32 m_uiThrash_Timer;
    uint32 m_uiVanish_Timer;
    uint32 m_uiVisible_Timer;
    uint32 m_uiBackstab_Timer;
    uint32 m_uiTourbillon_Timer;
    uint32 m_uiRosser_Timer;
    uint32 m_uiRavage_Timer;
    uint32 m_uiSwitchToTroll_Timer;

    uint32 m_uiSummon_Timer;
    uint32 m_uiSummonCount;

    uint64 m_uiMarkedGUID;

    bool m_bIsPhaseTwo;
    bool m_bIsVanished;
    ObjectGuid m_doorGuid;

    void Reset() override
    {
        m_uiShadowWordPain_Timer = 8000;
        m_uiGouge_Timer = 14000;
        m_uiMark_Timer = 35000;
        m_uiThrash_Timer = urand(5000, 9000);
        m_uiVanish_Timer = 35000;
        m_uiSwitchToTroll_Timer = DISABLE_TIMER; // Modifie apres
        m_uiVisible_Timer = 6000;
        m_uiBackstab_Timer = 6000;
        m_uiRosser_Timer = urand(5000, 9000);
        m_uiTourbillon_Timer = 4000; // Timer incertain
        m_uiRavage_Timer = 15000;

        m_uiSummon_Timer = 5000;
        m_uiSummonCount = 0;

        m_bIsPhaseTwo = false;
        m_bIsVanished = false;

        m_uiMarkedGUID = 0;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->ResetStats();
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
    }

    void Aggro(Unit* pWho) override
    {
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->SetInCombatWithZone();
        if (GameObject* door = m_creature->FindNearestGameObject(GO_ARLOKK_FORCE_FIELD, 100.0f))
            door->UseDoorOrButton();
    }

    void JustReachedHome() override
    {
        if (m_pInstance)
            if (m_pInstance->GetData(TYPE_ARLOKK) != DONE)
                m_pInstance->SetData(TYPE_ARLOKK, NOT_STARTED);

        if (GameObject* door = m_creature->FindNearestGameObject(GO_ARLOKK_FORCE_FIELD, 100.0f))
            door->ResetDoorOrButton();
        if (GameObject* gong = m_creature->FindNearestGameObject(GO_ARLOKK_GONG, 100.0f))
            gong->Respawn();
        //we should be summoned, so despawn
        m_creature->ForcedDespawn();
    }

    void JustDied(Unit* pKiller) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        m_creature->RemoveAurasDueToSpell(SPELL_PANTHER_TRANSFORM);
        LeaveVanish();
        m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_ARLOKK, DONE);
        if (GameObject* door = m_creature->FindNearestGameObject(GO_ARLOKK_FORCE_FIELD, 100.0f))
            door->ResetDoorOrButton();

        // Remove a Hakkar Power stack.
        m_creature->CastSpell(m_creature, SPELL_HAKKAR_POWER_DOWN, true);
    }

    void DoSummonSinglePhanter(float x, float y, float z, Unit* pTarget)
    {
        if (Creature* pInvoc = m_creature->SummonCreature(NPC_ZULIAN_PROWLER, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000))
            if (pTarget && pInvoc->AI())
                pInvoc->AI()->AttackStart(pTarget);
    }
    void DoSummonPhanters()
    {
        Unit* pUnit = m_creature->GetMap()->GetUnit(m_uiMarkedGUID);
        DoSummonSinglePhanter(-11532.7998f, -1649.6734f, 41.4800f, pUnit);
        DoSummonSinglePhanter(-11532.9970f, -1606.4840f, 41.2979f, pUnit);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (Unit* pUnit = m_creature->GetMap()->GetUnit(m_uiMarkedGUID))
        {
            if (pUnit->IsAlive())
            {
                pSummoned->AI()->AttackStart(pUnit);
                ++m_uiSummonCount;
                return;
            }
        }
        if (Unit *pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
        {
            pSummoned->AI()->AttackStart(pTarget);
            ++m_uiSummonCount;
            return;
        }
        // Y'a plus personne ?
        pSummoned->AddObjectToRemoveList();
        EnterEvadeMode();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_bIsPhaseTwo && !m_bIsVanished) //P1
        {
            if (m_uiShadowWordPain_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWWORDPAIN) == CAST_OK)
                    m_uiShadowWordPain_Timer = 15000;
            }
            else
                m_uiShadowWordPain_Timer -= uiDiff;

            if (m_uiBackstab_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BACKSTAB) == CAST_OK)
                    m_uiBackstab_Timer = urand(6000, 12000);
            }
            else
                m_uiBackstab_Timer -= uiDiff;

            if (m_uiMark_Timer < uiDiff)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    // On retire la marque a l'ancien joueur qui l'avait
                    if (Unit* pOldMark = m_creature->GetMap()->GetUnit(m_uiMarkedGUID))
                        pOldMark->RemoveAurasDueToSpell(SPELL_MARK);

                    if (Player* pMark = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself())
                    {
                        if (DoCastSpellIfCan(pMark, SPELL_MARK) == CAST_OK)
                        {
                            m_uiMarkedGUID = pMark->GetGUID();
                            DoScriptText(SAY_FEAST_PANTHER, m_creature, pMark);
                            m_uiMark_Timer = 15000;
                        }
                    }
                    else
                    {
                        if (m_uiMarkedGUID)
                            m_uiMarkedGUID = 0;

                        sLog.outError("boss_arlokk could not accuire a new target to mark.");
                    }
                }
            }
            else
                m_uiMark_Timer -= uiDiff;
        }
        else if (!m_bIsVanished) // P2 : Panthere
        {
            if (m_uiThrash_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_ROSSER) == CAST_OK)
                    m_uiThrash_Timer = urand(5000, 9000);
            }
            else
                m_uiThrash_Timer -= uiDiff;

            // Ravage Timer
            if (m_uiRavage_Timer <= uiDiff)
            {
                if (DoCastSpellIfCan(me->GetVictim(), SPELL_RAVAGE) == CAST_OK)
                    m_uiRavage_Timer = 16000;
            }
            else
                m_uiRavage_Timer -= uiDiff;

            //Gouge_Timer
            if (m_uiGouge_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_GOUGE) == CAST_OK)
                {
                    if (m_creature->GetThreatManager().getThreat(m_creature->GetVictim()))
                        m_creature->GetThreatManager().modifyThreatPercent(m_creature->GetVictim(), -80);

                    m_uiGouge_Timer = urand(17000, 27000);
                }
            }
            else
                m_uiGouge_Timer -= uiDiff;

            if (m_uiTourbillon_Timer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TOURBILLON) == CAST_OK)
                    m_uiTourbillon_Timer = 16000;
            }
            else
                m_uiTourbillon_Timer -= uiDiff;
        }

        if (m_uiSummonCount <= (MAX_PANTHER_COUNT - 1))
        {
            if (m_uiSummon_Timer < uiDiff)
            {
                DoSummonPhanters();
                m_uiSummon_Timer = 5000;
            }
            else
                m_uiSummon_Timer -= uiDiff;
        }

        //
        // GESTION DES PHASES
        //
        // Troll -> Vanish
        if (m_uiVanish_Timer < uiDiff)
        {
            //Invisble Model
            m_creature->RemoveAurasDueToSpell(SPELL_PANTHER_TRANSFORM);
            EnterVanish();

            m_bIsVanished = true;

            // Disparait entre 35 sec et 50 sec
            m_uiVisible_Timer = urand(35000, 50000);
            m_uiVanish_Timer  = DISABLE_TIMER;
        }
        else
            m_uiVanish_Timer -= uiDiff;

        // Vanish -> Panthere
        if (m_bIsVanished)
        {
            if (m_uiVisible_Timer < uiDiff)
            {
                // Transformation en panthere
                m_creature->CastSpell(m_creature, SPELL_PANTHER_TRANSFORM, false);
                m_creature->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.7f);
                CreatureInfo const *cinfo = m_creature->GetCreatureInfo();
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->dmg_min + ((cinfo->dmg_min / 100) * 35)));
                m_creature->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->dmg_max + ((cinfo->dmg_max / 100) * 35)));
                m_creature->UpdateDamagePhysical(BASE_ATTACK);

                // Et embush
                Unit* pVanishTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
                LeaveVanish();
                Ambush(pVanishTarget, SPELL_BACKSTAB);

                m_bIsPhaseTwo = true;
                m_bIsVanished = false;
                // 45 sec en forme PANTHERE + 1 min en forme TROLL
                m_uiSwitchToTroll_Timer = 45000;
                m_uiVanish_Timer = m_uiSwitchToTroll_Timer + 30000;
            }
            else
                m_uiVisible_Timer -= uiDiff;
        }
        else
            DoMeleeAttackIfReady();

        // Panthere -> Troll
        // Repassage en TROLL si en panthere depuis plus de 45 sec.
        if (m_bIsPhaseTwo)
        {
            if (m_uiSwitchToTroll_Timer < uiDiff)
            {
                m_creature->RemoveAurasDueToSpell(SPELL_PANTHER_TRANSFORM);
                m_bIsPhaseTwo = false;
                m_uiSwitchToTroll_Timer = DISABLE_TIMER; // Modifie apres
            }
            else
                m_uiSwitchToTroll_Timer -= uiDiff;
        }
    }
};

// Pantheres invoquees
struct mob_prowlerAI : public ScriptedAI
{
    uint64 m_uiArlokkGuid;
    uint32 m_uiThrash_Timer;
    uint32 m_uiUpdateTarget_Timer;

    mob_prowlerAI(Creature* pCreature) : ScriptedAI(pCreature), m_uiArlokkGuid(0), m_uiThrash_Timer(0), m_uiUpdateTarget_Timer(0)
    {
    }


    boss_arlokkAI* GetArlokkAI()
    {
        if (!m_uiArlokkGuid)
            if (Creature* pArlokk = m_creature->FindNearestCreature(NPC_ARLOKK, 100.0f, true))
                m_uiArlokkGuid = pArlokk->GetGUID();

        if (Creature* pArlokk = m_creature->GetMap()->GetCreature(m_uiArlokkGuid))
            if (pArlokk->IsAlive())
                return CAST_AI(boss_arlokkAI, pArlokk->AI());
        return nullptr;
    }
    void Reset() override
    {
        DoCast(m_creature, 22766);
        m_uiThrash_Timer = urand(5000, 9000);
        m_uiUpdateTarget_Timer = 2000;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (boss_arlokkAI* pArlokkAI = GetArlokkAI())
            pArlokkAI->m_uiSummonCount--;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiUpdateTarget_Timer <= uiDiff)
        {
            Unit *pMarkedTarget = nullptr;
            if (boss_arlokkAI* pArlokkAI = GetArlokkAI())
                pMarkedTarget = m_creature->GetMap()->GetUnit(pArlokkAI->m_uiMarkedGUID);
            else
            {
                m_creature->AddObjectToRemoveList();
                return;
            }
            if (DoGetThreat(m_creature->GetVictim()))
                DoModifyThreatPercent(m_creature->GetVictim(), -100);
            if (pMarkedTarget)
            {
                
                m_creature->AI()->AttackStart(pMarkedTarget);
DoCast(m_creature, 22766);
            }
            m_uiUpdateTarget_Timer = 2000;
        }
        else
            m_uiUpdateTarget_Timer -= uiDiff;


        if (m_uiThrash_Timer <= uiDiff)
        {
            DoCast(m_creature, SPELL_ROSSER);
            m_uiThrash_Timer = urand(5000, 9000);
        }
        else
            m_uiThrash_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_arlokk(Creature* pCreature)
{
    return new boss_arlokkAI(pCreature);
}
CreatureAI* GetAI_mob_prowler(Creature* pCreature)
{
    return new mob_prowlerAI(pCreature);
}

void AddSC_boss_arlokk()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_gong_of_bethekk";
    newscript->pGOHello = &GOHello_go_gong_of_bethekk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_arlokk";
    newscript->GetAI = &GetAI_boss_arlokk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_prowler";
    newscript->GetAI = &GetAI_mob_prowler;
    newscript->RegisterSelf();
}
