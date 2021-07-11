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
SDName: Boss_Baroness_Anastari
SD%Complete: 90
SDComment: MC disabled
SDCategory: Stratholme
EndScriptData */

#include "scriptPCH.h"
#include "stratholme.h"

#define SPELL_BANSHEEWAIL   16565
#define SPELL_BANSHEECURSE  16867
#define SPELL_SILENCE       18327
#define SPELL_POSSESS       17244

#define SPELL_INVISIBLE     24699

struct SpawnLocations
{
    float x, y, z;
};

struct boss_baroness_anastariAI : public ScriptedAI
{
    boss_baroness_anastariAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 BansheeWail_Timer;
    uint32 BansheeCurse_Timer;
    uint32 Silence_Timer;
    uint32 Possess_Timer;
    uint32 CheckPossess_Timer;

    uint64 PossessedPlayerGuid;
    bool Possessed;
    bool Position_memorized;

    uint64 PlayerGuids[10];
    float PlayerAggro[10];
    SpawnLocations old_Position;
    float PlayerHealth;

    void Reset() override
    {
        BansheeWail_Timer       = 1000;
        BansheeCurse_Timer      = 11000;
        Silence_Timer           = 13000;
        Possess_Timer           = 20000;
        CheckPossess_Timer      = 1000;
        PlayerHealth            = 0;

        PossessedPlayerGuid     = 0;
        Possessed = false;
        Position_memorized = false;

        for (int i = 0; i < 5; i++)
        {
            PlayerGuids[i] = 0;
            PlayerAggro[i] = 0;
        }

        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ALL, false);

        /** Memorize old position of the Banshee */
        old_Position.x = m_creature->GetPositionX();
        old_Position.y = m_creature->GetPositionY();
        old_Position.z = m_creature->GetPositionZ();
    }

    void JustDied(Unit* Killer) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_BARONESS, DONE);

        m_creature->SetVisibility(VISIBILITY_ON);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        for (int i = 0; i < 5; i++)
            if (Unit* pTarget = m_creature->GetMap()->GetUnit(PlayerGuids[i]))
                pTarget->RestoreFaction();
    }
    void DamageTaken(Unit *done_by, uint32 &damage) override
    {
        if (Possessed)
            damage = 0;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (Possessed)
        {
            if (CheckPossess_Timer < diff)
            {
                if (Unit* pTarget = m_creature->GetMap()->GetUnit(PossessedPlayerGuid))
                {
                    if (pTarget->GetHealthPercent() < 25.0f || !pTarget->HasAura(SPELL_POSSESS))
                    {
                        pTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                        pTarget->RestoreFaction();

                        /** Teleport the banshee to his old position */
                        m_creature->NearTeleportTo(old_Position.x, old_Position.y, old_Position.z, 0.0f);

                        /** Set the player health back to its old state unless their party members killed them, whoops! */
                        if (pTarget->IsAlive())
                            pTarget->SetHealthPercent(PlayerHealth);

                        m_creature->SetVisibility(VISIBILITY_ON);
                        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ALL, false);

                        for (int i = 0; i < 5; i++)
                        {
                            if (Unit* pTarg = m_creature->GetMap()->GetUnit(PlayerGuids[i]))
                            {
                                m_creature->GetThreatManager().addThreatDirectly(pTarg, PlayerAggro[i]);
                                if (pTarg->IsAlive())
                                    m_creature->SetInCombatWith(pTarg);
                            }
                        }
                        m_creature->Attack(pTarget, false);

                        if (DoCastSpellIfCan(m_creature, SPELL_SILENCE) == CAST_OK)
                            Silence_Timer = 13000;

                        Possess_Timer = urand(13000, 18000);
                        Possessed = false;
                    }
                }
                CheckPossess_Timer = 1000;
            }
            else
                CheckPossess_Timer -= diff;

            return;
        }

        if (m_creature->GetVisibility() != VISIBILITY_ON)
            m_creature->SetVisibility(VISIBILITY_ON);

        //Possess
        if (Possess_Timer < diff)
        {
            if (m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 1)) // au moins 2 joueurs présents
            {
                if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    if (target->IsPlayer() && target->GetHealthPercent() > 30.0f)
                    {
                        PossessedPlayerGuid = target->GetGUID();
                        /*PossessedPlayerAggro = m_creature->GetThreatManager().getThreat(target);*/

                        for (int i = 0; i < 5; i++)
                        {
                            PlayerGuids[i] = 0;
                            PlayerAggro[i] = 0;
                        }
                        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                        for (const auto i : tList)
                        {
                            Unit* pUnit = m_creature->GetMap()->GetUnit(i->getUnitGuid());
                            if (pUnit && pUnit->IsPlayer())
                            {
                                for (int i = 0; i < 5; i++)
                                {
                                    if (PlayerGuids[i] == 0)
                                    {
                                        PlayerGuids[i] = pUnit->GetGUID();
                                        PlayerAggro[i] = m_creature->GetThreatManager().getThreat(pUnit);
                                    }
                                }
                            }
                        }

                        if (!Position_memorized)
                        {
                            /** Memorize old position of the Banshee */
                            old_Position.x = m_creature->GetPositionX();
                            old_Position.y = m_creature->GetPositionY();
                            old_Position.z = m_creature->GetPositionZ();

                            /** Memorize current health of the possessed player */
                            PlayerHealth = target->GetHealthPercent();

                            Position_memorized =  true;
                        }

                        m_creature->NearTeleportTo(target->GetPosition());
                        if (DoCastSpellIfCan(target, SPELL_POSSESS) == CAST_OK)
                        {
                            m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ALL, true);
                            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            m_creature->SetVisibility(VISIBILITY_OFF);

                            for (int i = 0; i < 5; i++)
                            {
                                if (PlayerGuids[i] != PossessedPlayerGuid)
                                    m_creature->GetThreatManager().addThreatDirectly(m_creature->GetMap()->GetUnit(PlayerGuids[i]), PlayerAggro[i]);
                            }

                            Possessed = true;
                            CheckPossess_Timer = 2000;
                            return;
                        }
                    }
                }
            }
        }
        else
            Possess_Timer -= diff;

        //BansheeWail
        if (BansheeWail_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BANSHEEWAIL) == CAST_OK)
                BansheeWail_Timer = 4000;
        }
        else BansheeWail_Timer -= diff;

        //BansheeCurse
        if (BansheeCurse_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BANSHEECURSE, CF_AURA_NOT_PRESENT) == CAST_OK)
                BansheeCurse_Timer = 18000;
        }
        else BansheeCurse_Timer -= diff;

        //Silence
        if (Silence_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SILENCE) == CAST_OK)
                Silence_Timer = urand(13000, 18000);
        }
        else Silence_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_baroness_anastari(Creature* pCreature)
{
    return new boss_baroness_anastariAI(pCreature);
}

void AddSC_boss_baroness_anastari()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_baroness_anastari";
    newscript->GetAI = &GetAI_boss_baroness_anastari;
    newscript->RegisterSelf();
}
