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
SDName: Ruins of Ahn'Qiraj
SD%Complete: 80
SDComment: fix flesh hunter's spell_consume in core and remove hacks, find right explode spell for anubisath guardian
SDCategory: Ruins of Ahn'Qiraj
EndScriptData */

/* ContentData
mob_anubisath_guardian
mob_flesh_hunter
EndContentData */

#include "scriptPCH.h"
#include "CreatureGroups.h"
#include "ruins_of_ahnqiraj.h"

// Anubisath guardian
enum
{
    SPELL_METEOR        =   24340,
    SPELL_PLAGUE        =   22997,
    SPELL_SHADOW_STORM  =   26546,
    SPELL_THUNDER_CLAP  =   26554,
    SPELL_REFLECT_ARFR  =   13022,
    SPELL_REFLECT_FSSH  =   19595,
    SPELL_ENRAGE        =   8269, //8559,
    SPELL_EXPLODE       =   25699,
    SPELL_INIT_EXPLODE  =   25698,

    EMOTE_FRENZY        =   10677,

    NPC_ANU_WARRIOR     =   15537,
    NPC_ANU_SWARM       =   15538,

    OBJ_SMALL_OBSIDIAN_CHUNK = 181068
};

struct mob_anubisath_guardianAI : public ScriptedAI
{
    mob_anubisath_guardianAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSpell1;
    uint32 m_uiSpell2;
    uint32 m_uiSpell3;
    uint32 m_uiSpell4;
    uint32 m_uiNPCSummon;

    uint32 m_uiSpell1_Timer;
    uint32 m_uiSpell2_Timer;
    uint32 m_uiSummon_Timer;
    uint32 m_uiExplode_Timer;

    uint8 m_uiSummonCount;

    bool m_bIsEnraged;
    bool m_bIsExploding;

    void Reset() override
    {
        m_uiSpell1 = urand(0, 1) ? SPELL_METEOR : SPELL_PLAGUE;
        m_uiSpell2 = urand(0, 1) ? SPELL_SHADOW_STORM : SPELL_THUNDER_CLAP;
        m_uiSpell3 = urand(0, 1) ? SPELL_REFLECT_ARFR : SPELL_REFLECT_FSSH;
        m_uiSpell4 = urand(0, 1) ? SPELL_ENRAGE : SPELL_INIT_EXPLODE;
        m_uiNPCSummon = urand(0, 1) ? NPC_ANU_WARRIOR : NPC_ANU_SWARM;

        m_uiSpell1_Timer = 10000;
        m_uiSpell2_Timer = 20000;
        m_uiSummon_Timer = 10000;
        m_bIsEnraged = false;
        m_bIsExploding = false;
        m_uiSummonCount = 0;
        m_uiExplode_Timer = 6000;

        m_creature->RemoveAllAuras();
    }

    void JustDied(Unit* pKiller) override
    {
        if (GameObject *pObsidian = m_creature->SummonGameObject(OBJ_SMALL_OBSIDIAN_CHUNK, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, 0, 0, 0, 0, -1, false))
            pObsidian->SetRespawnTime(345600);
    }

    void Aggro(Unit* pWho) override
    {
        DoCast(m_creature, m_uiSpell3);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        pSummoned->AI()->AttackStart(m_creature->GetVictim());
        ++m_uiSummonCount;
    }

    void SummonedCreatureDespawn(Creature *pDespawned) override
    {
        -- m_uiSummonCount;
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (!m_bIsEnraged && (m_creature->GetHealth() * 100 / m_creature->GetMaxHealth()) < 10)
        {
            if (m_uiSpell4 == SPELL_ENRAGE)
            {
                DoCast(m_creature->GetVictim(), m_uiSpell4);
                DoScriptText(EMOTE_FRENZY, m_creature);
                m_bIsEnraged = true;
            }
            else
            {
                m_creature->CastSpell(m_creature, m_uiSpell4, false);
                m_bIsExploding = true;
                m_uiExplode_Timer = 6000;
            }
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiExplode_Timer < uiDiff && m_bIsExploding)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_EXPLODE) == CAST_OK)
                m_uiExplode_Timer = 15000;
        }
        else
            m_uiExplode_Timer -= uiDiff;




        if (m_uiSpell1_Timer < uiDiff)
        {
            /** Spell1 shall be cast on random target */
            if (Unit* pUnit = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                // Create visual animation of the spell
                m_creature->SendSpellGo(m_creature, m_uiSpell1);


                if (DoCastSpellIfCan(pUnit, m_uiSpell1) == CAST_OK)
                    m_uiSpell1_Timer = 15000;
            }
        }
        else
            m_uiSpell1_Timer -= uiDiff;

        if (m_uiSpell2_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), m_uiSpell2) == CAST_OK)
                m_uiSpell2_Timer = 15000;
        }
        else
            m_uiSpell2_Timer -= uiDiff;

        if (m_uiSummon_Timer < uiDiff)
        {
            if (m_uiSummonCount < 4)
            {
                m_creature->SummonCreature(m_uiNPCSummon,
                                           m_creature->GetPositionX(),
                                           m_creature->GetPositionY(),
                                           m_creature->GetPositionZ(),
                                           0,
                                           TEMPSUMMON_TIMED_DESPAWN,
                                           60000);
                // Create visual animation of the teleportation spell
                m_creature->SendSpellGo(m_creature, 25681);
            }
            m_uiSummon_Timer = 15000;
        }
        else
            m_uiSummon_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

struct OssirianTornadoAI : public ScriptedAI
{
    OssirianTornadoAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        SetCombatMovement(false);
        m_creature->CastSpell(m_creature, 25160, false);
        m_creature->CastSpell(m_creature, 10092, false);
        m_creature->SetDefaultMovementType(RANDOM_MOTION_TYPE);
        m_creature->SetWanderDistance(55.0f);
        m_creature->GetMotionMaster()->Initialize();
        Reset();
    }

    void Reset() override
    {
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};



// Flesh hunter

enum
{
    SPELL_TRASH         =   3391,
    SPELL_CONSUME       =   25371, //26186, //25371,
    SPELL_CONSUME_HEAL  =   25378,
    SPELL_POISON_BOLT   =   25424,
    SPELL_CONSUME_DMG   =   25373,
    SPELL_SPLIT         =   25383,
};

struct mob_flesh_hunterAI : public ScriptedAI
{
    mob_flesh_hunterAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint64 m_uiConsumeVictim;

    uint32 m_uiPoisonBolt_Timer;
    uint32 m_uiTrash_Timer;
    uint32 m_uiConsume_Timer;
    uint32 m_uiConsumeDamage_Timer;

    bool m_bPlayerConsumed;
    bool m_bPlayerConsumedCharged;

    void Reset() override
    {
        m_uiPoisonBolt_Timer = 3000;
        m_uiTrash_Timer = 5000;
        m_uiConsume_Timer = 3000;
        m_uiConsumeDamage_Timer = 1000;

        m_uiConsumeVictim = 0;
        m_bPlayerConsumed = false;
        m_bPlayerConsumedCharged = false;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }
    /*
    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (m_creature->Attack(who, true))
        {
            m_creature->AddThreat(who);
            m_creature->SetInCombatWith(who);
            who->SetInCombatWith(m_creature);

            // Poursuite à 25m
            m_creature->GetMotionMaster()->MoveCaster(who, 25.0f);
        }
    }
    */
    void KilledUnit(Unit* pWho) override
    {
        if (pWho->GetGUID() == m_uiConsumeVictim)
            DoCast(m_creature, SPELL_CONSUME_HEAL);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiPoisonBolt_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_POISON_BOLT) == CAST_OK)
                    m_uiPoisonBolt_Timer = 3000;
            }
        }
        else
            m_uiPoisonBolt_Timer -= uiDiff;

        if (m_uiConsume_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_TOPAGGRO, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_CONSUME) == CAST_OK)
                {
                    m_uiConsumeVictim = pTarget->GetGUID();
                    m_bPlayerConsumed = true;
                    m_uiConsume_Timer = 30000;
                }
            }
        }
        else
            m_uiConsume_Timer -= uiDiff;

        if (Unit* pConsumeTarget = Unit::GetUnit(*m_creature, m_uiConsumeVictim))
        {
            if (pConsumeTarget->HasAura(SPELL_CONSUME))
            {
                if (m_uiConsumeDamage_Timer < uiDiff)
                {
                    if (DoCastSpellIfCan(pConsumeTarget, SPELL_CONSUME_DMG) == CAST_OK)
                    {
//m_creature->GetMotionMaster()->MoveCaster(pConsumeTarget, 320.0f);
                        m_creature->GetMotionMaster()->Initialize();
                        m_creature->StopMoving();
                        m_creature->GetThreatManager().modifyThreatPercent(pConsumeTarget, -100);
                        m_uiConsumeDamage_Timer = 1000;
                        m_bPlayerConsumedCharged = true;
                        pConsumeTarget->SetHealth(pConsumeTarget->GetHealth() - pConsumeTarget->GetMaxHealth() / 10.0f);
                    }
                }
                else
                    m_uiConsumeDamage_Timer -= uiDiff;

                if (!pConsumeTarget->IsAlive())
                {
                    if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                        m_creature->GetMotionMaster()->MoveChase(pTarget);
                    m_creature->SetHealth(m_creature->GetMaxHealth());
                }
            }
            else
            {
                if (pConsumeTarget->IsAlive() && m_bPlayerConsumedCharged)
                {
                    if (DoCastSpellIfCan(pConsumeTarget, SPELL_SPLIT) == CAST_OK)
                    {
                        m_bPlayerConsumedCharged = false;
                        m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());
                    }
                }
            }
        }

        if (m_uiTrash_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRASH) == CAST_OK)
                m_uiTrash_Timer = 5000 + rand() % 2000;
        }
        else
            m_uiTrash_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_PURGE             =  25756,
    SPELL_DRAINMANA         =  25754,
};


struct ObsidianDestroyerAI : public ScriptedAI
{
    ObsidianDestroyerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    bool m_bIsInCombat;
    uint32 m_uiDrainMana_Timer;

    void Reset() override
    {
        m_uiDrainMana_Timer = 7000;
        m_creature->SetPower(POWER_MANA, 0);

        m_bIsInCombat = false;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
        if (!m_bIsInCombat)
        {
            m_creature->SetPower(POWER_MANA, 0);
            m_bIsInCombat = true;
        }
    }

    void JustDied(Unit* pKiller) override
    {
        if (GameObject *pObsidian = m_creature->SummonGameObject(OBJ_SMALL_OBSIDIAN_CHUNK, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, 0, 0, 0, 0, -1, false))
            pObsidian->SetRespawnTime(345600);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetPower(POWER_MANA) >= m_creature->GetMaxPower(POWER_MANA) && m_bIsInCombat)
            DoCast(m_creature, SPELL_PURGE, true);

        //m_uiDrainMana_Timer
        if (m_uiDrainMana_Timer < uiDiff)
        {
            DoCast(m_creature, SPELL_DRAINMANA);
            m_uiDrainMana_Timer = 7000;
        }
        else
            m_uiDrainMana_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_VENOM_SPIT    =   25497,
    SPELL_RETALIATION   =   22857,
};

/******************/
struct HiveZaraSoldierAI : public ScriptedAI
{
    HiveZaraSoldierAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiVenomSpit_Timer;
    bool m_bRetaliation;

    void Reset() override
    {
        m_uiVenomSpit_Timer = 5000;
        m_bRetaliation = false;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiVenomSpit_Timer < uiDiff)
        {
            Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (DoCastSpellIfCan(pTarget, SPELL_VENOM_SPIT) == CAST_OK)
                m_uiVenomSpit_Timer = urand(5000, 10000);
        }
        else
            m_uiVenomSpit_Timer -= uiDiff;

        if (m_creature->GetHealthPercent() < 20.0f && !m_bRetaliation)
        {
            m_creature->CastSpell(m_creature, SPELL_RETALIATION, false);
            m_bRetaliation = true;
        }

        if (m_creature->GetHealthPercent() < 20.0f && !m_bRetaliation)
        {
            m_creature->CastSpell(m_creature, SPELL_RETALIATION, false);
            m_bRetaliation = true;
        }

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_CLOUD_OF_DISEASE    =   17742,
};

/******************/
struct SilicateFeederAI : public ScriptedAI
{

    bool m_bIsAttacked = false;

    SilicateFeederAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    void Reset() override
    {
        m_creature->SetFactionTemplateId(7);
        m_bIsAttacked = false;
    }

    void JustDied(Unit* pKiller) override
    {
        DoCastSpellIfCan(m_creature, SPELL_CLOUD_OF_DISEASE);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!m_bIsAttacked)
        {
            m_creature->SetFactionTemplateId(14);
            m_creature->SetInCombatWithZone();
            m_bIsAttacked = true;
        }

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_SUNDERING_CLEAVE    =   25174,
};

/******************/
struct QirajiSwarmguardAI : public ScriptedAI
{
    QirajiSwarmguardAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiSunder_Timer;

    void Reset() override
    {
        m_uiSunder_Timer = 2000;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_creature->IsWalking())
            m_creature->SetWalk(false);

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiSunder_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SUNDERING_CLEAVE) == CAST_OK)
                m_uiSunder_Timer = urand(8000, 12000);
        }
        else
            m_uiSunder_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};


enum
{
    SPELL_TRAMPLE    =   5568,
    SPELL_UPPERCUT2  =   10966,
    SPELL_VENGEANCE  =   25164,
};

/******************/
struct QirajiGladiatorAI : public ScriptedAI
{
    QirajiGladiatorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiTrample_Timer;
    uint32 m_uiUppercut_Timer;
    bool m_bIsEnraged;

    void Reset() override
    {
        m_uiTrample_Timer = 4000;
        m_uiUppercut_Timer = 9000;
        m_bIsEnraged = false;
        if (m_pInstance)
            m_pInstance->SetData(TYPE_QIRAJI_GLADIATOR, 0);
    }

    void Aggro(Unit* pWho) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_QIRAJI_GLADIATOR, 0);
        m_creature->SetInCombatWithZone();
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_QIRAJI_GLADIATOR, 1);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_pInstance && m_pInstance->GetData(TYPE_QIRAJI_GLADIATOR) > 0 && !m_bIsEnraged)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_VENGEANCE) == CAST_OK)
                m_bIsEnraged = true;
        }

        if (m_uiTrample_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_TRAMPLE) == CAST_OK)
                m_uiTrample_Timer = urand(4000, 6000);
        }
        else
            m_uiTrample_Timer -= uiDiff;

        if (m_uiUppercut_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UPPERCUT2) == CAST_OK)
                m_uiUppercut_Timer = urand(10000, 15000);
        }
        else
            m_uiUppercut_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

/*******************/
enum
{
    SPELL_CHARGE_STINGER          =   25190,
};

struct HiveZaraStingerAI : public ScriptedAI
{
    HiveZaraStingerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCharge_Timer;
    uint32 m_uiChargeCasted_Timer;
    bool m_bChargeCasted;

    void Reset() override
    {
        m_uiCharge_Timer = 3000;
        m_uiChargeCasted_Timer = 0;
        m_bChargeCasted = false;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiCharge_Timer < uiDiff)
        {
            Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (DoCastSpellIfCan(pTarget, SPELL_CHARGE_STINGER) == CAST_OK)
            {
                m_uiCharge_Timer = 5000;
                m_bChargeCasted = true;
                m_uiChargeCasted_Timer = 500;
            }

        }
        else
        {
            m_uiCharge_Timer -= uiDiff;
            if (m_bChargeCasted)
            {
                m_uiChargeCasted_Timer -= uiDiff;
                if (m_uiChargeCasted_Timer < uiDiff)
                {
                    m_bChargeCasted = false;
                    m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());
                }
            }
        }

//        m_creature->GetMotionMaster()->MoveChase(m_creature->GetVictim());
        DoMeleeAttackIfReady();
    }
};

enum
{
    SAY_TUUBID_KILL       =   -1900117,
    SPELL_ATTACK_ORDER    =   25471,
    SPELL_CLEAVE_T        =   26350,
    SPELL_SUNDER_ARMOR    =   24317,
    LINK_GROUP_TUUBID     =   115,
};

struct TuubidAI : public ScriptedAI
{
    TuubidAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiAttackOrder_Timer;
    uint32 m_uiCleave_Timer;
    uint32 m_uiSunderArmor_Timer;
    uint64 m_uiMarkedGUID;

    void Reset() override
    {
        m_uiMarkedGUID = 0;
        m_uiAttackOrder_Timer = 5000;
        m_uiCleave_Timer = 8000;
        m_uiSunderArmor_Timer = 6000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiAttackOrder_Timer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (Unit* pOldMark = m_creature->GetMap()->GetUnit(m_uiMarkedGUID))
                    pOldMark->RemoveAurasDueToSpell(SPELL_ATTACK_ORDER);

                if (Player* pMark = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                    DoCastSpellIfCan(pMark, SPELL_ATTACK_ORDER);
                    m_uiMarkedGUID = pMark->GetGUID();
                    DoScriptText(SAY_TUUBID_KILL, m_creature, pMark);
                }
                else
                {
                    if (m_uiMarkedGUID)
                        m_uiMarkedGUID = 0;

                    sLog.outError("boss_tuubid could not accuire a new target to mark.");
                }
                m_uiAttackOrder_Timer = 9000;
            }
        }
        else
            m_uiAttackOrder_Timer -= uiDiff;

        if (m_uiCleave_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE_T) == CAST_OK)
                m_uiCleave_Timer = 10000;
        }
        else
            m_uiCleave_Timer -= uiDiff;

        if (m_uiSunderArmor_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SUNDER_ARMOR) == CAST_OK)
                m_uiSunderArmor_Timer = 15000;
        }
        else
            m_uiSunderArmor_Timer -= uiDiff;


        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_ENRAGE_QW       =   8599,
    SPELL_THUNDERCLAP     =   15588,
    SPELL_UPPERCUT        =   10966,
    NPC_TUUBID            =   15392,
};

struct QirajiWarriorAI : public ScriptedAI
{
    QirajiWarriorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32     m_uiThunderclap_Timer;
    uint32     m_uiUppercut_Timer;
    uint64     m_uiTuubidGuid;
    uint32     m_uiUpdateTarget_Timer;
    bool       m_bisTuubidAlive;
    bool       m_bHasEnraged;

    TuubidAI* GetTuubidAI()
    {
        if (!m_uiTuubidGuid)
            if (Creature* pTuubid = m_creature->FindNearestCreature(NPC_TUUBID, 100.0f, true))
                m_uiTuubidGuid = pTuubid->GetGUID();

        if (Creature* pTuubid = m_creature->GetMap()->GetCreature(m_uiTuubidGuid))
            if (pTuubid->IsAlive())
                return CAST_AI(TuubidAI, pTuubid->AI());
        return nullptr;
    }

    void Reset() override
    {
        m_uiThunderclap_Timer = urand(6000, 12000);
        m_uiUppercut_Timer = urand(10000, 15000);
        m_uiTuubidGuid = 0;
        m_uiUpdateTarget_Timer = 2000;
        m_bHasEnraged = false;
        m_bisTuubidAlive = true;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage) override
    {
        if (!m_bHasEnraged && ((m_creature->GetHealth() * 100) / m_creature->GetMaxHealth()) <= 20 && !m_creature->IsNonMeleeSpellCasted(false))
        {
            DoCast(m_creature->GetVictim(), SPELL_ENRAGE_QW);
            m_bHasEnraged = true;
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /** Needed for "marking target system" */
        if (!m_creature->GetCreatureGroup()) // Should not happen
            return;
        if (m_creature->GetCreatureGroup()->GetOriginalLeaderGuid().GetEntry() != NPC_CAPTAIN_TUUBID || !m_bisTuubidAlive)
        {
            // Threat calculation
            if (!m_creature->SelectHostileTarget())
                return;
        }
        if (!m_creature->GetVictim())
            return;

        if (m_uiUpdateTarget_Timer < uiDiff)
        {
            if (TuubidAI* pTuubidAI = GetTuubidAI())
            {
                if (Unit* victim = m_creature->GetMap()->GetUnit(pTuubidAI->m_uiMarkedGUID))
                    AttackStart(victim);
            }
            else
            {
                /** Means that Tuubid is down, creature update their target list */
                m_bisTuubidAlive = false;
            }
            m_uiUpdateTarget_Timer = 1400;
        }
        else
            m_uiUpdateTarget_Timer -= uiDiff;


        if (m_uiThunderclap_Timer < uiDiff)
        {
            if (m_creature->GetDistance2d(m_creature) < 5.0f)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THUNDERCLAP) == CAST_OK)
                    m_uiThunderclap_Timer = 6000;
            }
        }
        else
            m_uiThunderclap_Timer -= uiDiff;

        if (m_uiUppercut_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_UPPERCUT) == CAST_OK)
                m_uiUppercut_Timer = 10000;
        }
        else
            m_uiUppercut_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

enum
{
    SPELL_CLEAVE       =   20684,
};

struct SwarmguardNeedlerAI : public ScriptedAI
{
    SwarmguardNeedlerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCleave_Timer;
    uint32 m_uiUpdateTarget_Timer;
    uint64 m_uiTuubidGuid;
    bool   m_bisTuubidAlive;

    TuubidAI* GetTuubidAI()
    {
        if (!m_uiTuubidGuid)
            if (Creature* pTuubid = m_creature->FindNearestCreature(NPC_TUUBID, 100.0f, true))
                m_uiTuubidGuid = pTuubid->GetGUID();

        if (Creature* pTuubid = m_creature->GetMap()->GetCreature(m_uiTuubidGuid))
            if (pTuubid->IsAlive())
                return CAST_AI(TuubidAI, pTuubid->AI());
        return nullptr;
    }

    void Reset() override
    {
        m_uiUpdateTarget_Timer = 2000;
        m_uiTuubidGuid = 0;
        m_uiCleave_Timer = urand(6000, 12000);;
        m_bisTuubidAlive = true;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->SetInCombatWithZone();
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /** Needed for "marking target system" */
        if (!m_creature->GetCreatureGroup()) // Should not happen
            return;
        if (m_creature->GetCreatureGroup()->GetOriginalLeaderGuid().GetEntry() != NPC_CAPTAIN_TUUBID || !m_bisTuubidAlive)
        {
            // Threat calculation
            if (!m_creature->SelectHostileTarget())
                return;
        }
        if (!m_creature->GetVictim())
            return;

        if (m_uiUpdateTarget_Timer < uiDiff)
        {
            if (TuubidAI* pTuubidAI = GetTuubidAI())
            {
                if (Unit* victim = m_creature->GetMap()->GetUnit(pTuubidAI->m_uiMarkedGUID))
                    AttackStart(victim);
            }
            else
            {
                /** Means that Tuubid is down, creature update their target list */
                m_bisTuubidAlive = false;
            }
            m_uiUpdateTarget_Timer = 1400;
        }
        else
            m_uiUpdateTarget_Timer -= uiDiff;

        if (m_uiCleave_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE) == CAST_OK)
                m_uiCleave_Timer = 8000;
        }
        else
            m_uiCleave_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

/*******************/

CreatureAI* GetAI_Tuubid(Creature* pCreature)
{
    return new TuubidAI(pCreature);
}

CreatureAI* GetAI_SwarmguardNeedler(Creature* pCreature)
{
    return new SwarmguardNeedlerAI(pCreature);
}

CreatureAI* GetAI_QirajiWarrior(Creature* pCreature)
{
    return new QirajiWarriorAI(pCreature);
}


CreatureAI* GetAI_HiveZaraStinger(Creature* pCreature)
{
    return new HiveZaraStingerAI(pCreature);
}

CreatureAI* GetAI_mob_anubisath_guardian(Creature* pCreature)
{
    return new mob_anubisath_guardianAI(pCreature);
}

CreatureAI* GetAI_OssirianTornado(Creature* pCreature)
{
    return new OssirianTornadoAI(pCreature);
}

CreatureAI* GetAI_mob_flesh_hunter(Creature* pCreature)
{
    return new mob_flesh_hunterAI(pCreature);
}

CreatureAI* GetAI_HiveZaraSoldier(Creature* pCreature)
{
    return new HiveZaraSoldierAI(pCreature);
}

CreatureAI* GetAI_ObsidianDestroyer(Creature* pCreature)
{
    return new ObsidianDestroyerAI(pCreature);
}

CreatureAI* GetAI_SilicateFeeder(Creature* pCreature)
{
    return new SilicateFeederAI(pCreature);
}

CreatureAI* GetAI_QirajiGladiator(Creature* pCreature)
{
    return new QirajiGladiatorAI(pCreature);
}

CreatureAI* GetAI_QirajiSwarmguard(Creature* pCreature)
{
    return new QirajiSwarmguardAI(pCreature);
}

void AddSC_ruins_of_ahnqiraj()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "mob_anubisath_guardian";
    newscript->GetAI = &GetAI_mob_anubisath_guardian;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_qiraji_swarmguard";
    newscript->GetAI = &GetAI_QirajiSwarmguard;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_flesh_hunter";
    newscript->GetAI = &GetAI_mob_flesh_hunter;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_tornado_ossirian";
    newscript->GetAI = &GetAI_OssirianTornado;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_qiraji_gladiator";
    newscript->GetAI = &GetAI_QirajiGladiator;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_silicate_feeder";
    newscript->GetAI = &GetAI_SilicateFeeder;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_hive_zara_soldier";
    newscript->GetAI = &GetAI_HiveZaraSoldier;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_obsidian_destroyer";
    newscript->GetAI = &GetAI_ObsidianDestroyer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_hive_zara_stinger";
    newscript->GetAI = &GetAI_HiveZaraStinger;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_qiraji_warrior";
    newscript->GetAI = &GetAI_QirajiWarrior;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_swarmguard_needler";
    newscript->GetAI = &GetAI_SwarmguardNeedler;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_tuubid";
    newscript->GetAI = &GetAI_Tuubid;
    newscript->RegisterSelf();
}
