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
SDName: Boss_Jeklik
SD%Complete: 99
SDComment:
SDCategory: Zul'Gurub
EndScriptData */

#include "scriptPCH.h"
#include "zulgurub.h"

enum
{
    SAY_AGGRO               = -1309002,
    SAY_RAIN_FIRE           = -1309003,
    SAY_DEATH               = -1309004,
    TEXT_GREAT_HEAL         = -1309025,
    TEXT_SUMMON_BATS        = -1309026,

    SPELL_GREENCHANNELING   = 13540, // Green Spell. [ChanneledInstant]
    SPELL_BAT_FORM          = 23966, // Transform to bat. [Instant]
    SPELL_BOMB              = 19629, // Summon Flames gobject 177764. [Instant]
    SPELL_THROW_LIQUID_FIRE = 23970, // [Instant] [50000 yd range]
    SPELL_TRANSFORMVISUAL   = 24085, // [Instant]
    SPELL_BLOODLEECH        = 22644, // Drains 30 health from nearby enemies, healing the caster for up to three times the amount stolen. [Instant] [Melee Range]

    // P1
    SPELL_SWOOP             = 23919, // Inflicts normal damage plus 500 to enemies in a cone in front of the caster, stunning them for 2 sec. [Instant] [Melee Range]
    SPELL_CHARGE            = 24408, // Charges an enemy, inflicting normal damage plus 0 and stuns the opponent for 2 sec. [Instant] [40 yd range]
    SPELL_SONICBURST        = 23918, // Inflicts normal damage plus 1750 to 2251 on nearby enemies, preventing them from spellcasting for 10 sec. [Instant]
    SPELL_PIERCEARMOR       = 12097, // Reduces an enemy's armor by 75% for 20 sec. [Instant]

    // P2
    SPELL_SHADOW_WORD_PAIN  = 23952, // Utters a word of darkness, inflicting Shadow damage to an enemy every 3 sec. for 18 sec. [Instant] [60 yd range]
    SPELL_MIND_FLAY         = 23953, // Inflicts Shadow damage to an enemy and reduces its movement speed for 10 sec. [ChanneledInstant] [100 yd range]
    SPELL_GREAT_HEAL        = 23954, // Calls upon Holy magic to heal an ally. [4 sec cast] [40 yd range]
    SPELL_CURSE_OF_BLOOD    = 16098, // Increases the Physical damage take by nearby enemies by 2 for 10 min. [2 sec cast] [20 yd range]
    SPELL_SCREECH           = 6605   // Causes nearby enemies to flee in fear for 4 sec. [Instant]
};

struct boss_jeklikAI : public ScriptedAI
{
    boss_jeklikAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
        m_creature->CastSpell(m_creature, SPELL_GREENCHANNELING, false);
    }

    ScriptedInstance* m_pInstance;

    uint32 Charge_Timer;
    uint32 SonicBurst_Timer;
    uint32 Swoop_Timer;
    uint32 PierceArmor_Timer;
    uint32 SpawnBats_Timer;
    uint32 ShadowWordPain_Timer;
    uint32 CurseOfBlood_Timer;
    uint32 MindFlay_Timer;
    uint32 GreatHeal_Timer;
    uint32 Screech_Timer;
    uint32 SpawnFlyingBats_Timer;
    uint32 GlobalCooldown;
    uint32 Diff_Add;
    bool skillStarted;

    bool PhaseTwo;

    void Reset() override
    {
        SpawnBats_Timer = 40000;

        Charge_Timer      = 10000;
        SonicBurst_Timer  = 12000;
        Swoop_Timer       = 8000;
        PierceArmor_Timer = 9000;

        Screech_Timer = 12000;

        ShadowWordPain_Timer  = 9000;
        CurseOfBlood_Timer    = 26000;
        MindFlay_Timer        = 2000;
        GreatHeal_Timer       = 20000;
        SpawnFlyingBats_Timer = 10000;

        GlobalCooldown = 0;
        PhaseTwo       = false;
        skillStarted   = false;

        if (m_pInstance && m_creature->IsAlive())
            m_pInstance->SetData(TYPE_JEKLIK, FAIL);

        m_creature->SetObjectScale(1.5f);
    }

    void JustReachedHome() override
    {
        m_creature->CastSpell(m_creature, SPELL_GREENCHANNELING, false);
        m_creature->SetObjectScale(1.0f);
    }

    void Aggro(Unit *who) override
    {
        m_creature->AddUnitState(UNIT_STAT_IGNORE_PATHFINDING);
        DoScriptText(SAY_AGGRO, m_creature);
        m_creature->AddAura(SPELL_BAT_FORM);
        m_creature->SetFly(true);
        m_creature->SetObjectScale(2.0f);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_JEKLIK, IN_PROGRESS);
        ScriptedAI::Aggro(who);
    }

    void JustDied(Unit* Killer) override
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_JEKLIK, DONE);

        // Remove a Hakkar Power stack.
        m_creature->CastSpell(m_creature, SPELL_HAKKAR_POWER_DOWN, true);
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();
        m_creature->Respawn();
        m_creature->NearTeleportTo(m_creature->GetHomePosition());
    }

    void UpdateAI(uint32 const lastDiff) override
    {
        if (!m_pInstance || !m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!PhaseTwo && m_creature->GetHealthPercent() < 50.0f)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_BAT_FORM);
            m_creature->SetFly(false);
            m_creature->SetObjectScale(1.5f);
            DoResetThreat();
            PhaseTwo = true;
        }

        // SUMMON_BATS
        if (m_creature->GetHealthPercent() > 50.0f)
        {
            if (SpawnBats_Timer < lastDiff)
            {
                DoScriptText(TEXT_SUMMON_BATS, m_creature);
                for (uint8 i = 0; i < 6; ++i)
                {
                    Creature* Bat = m_creature->SummonCreature(11368, -12294.0f + frand(0.0f, 5.0f), -1382.0f + frand(0.0f, 5.0f), 144.8304f, 5.483f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 15000);
                    if (Bat && Bat->AI())
                    {
                        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                            Bat->AI()->AttackStart(pTarget);
                    }
                }
                SpawnBats_Timer = 65000;
            }
            else
                SpawnBats_Timer -= lastDiff;
        }

        // SPAWN_FLYING_BAT
        if (PhaseTwo)
        {
            if (SpawnFlyingBats_Timer < lastDiff)
            {
                if (Unit *target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                {
                    Creature* FlyingBat = m_creature->SummonCreature(14965, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ() + 15, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30 * 60 * 1000);
                    if (FlyingBat && FlyingBat->AI())
                    {
                        FlyingBat->AI()->AttackStart(target);
                        DoScriptText(SAY_RAIN_FIRE, m_creature);
                    }
                }
                SpawnFlyingBats_Timer = 10000;
            }
            else
                SpawnFlyingBats_Timer -= lastDiff;
        }

        if (m_creature->IsNonMeleeSpellCasted(false))
        {
            Diff_Add += lastDiff;
            return;
        }

        DoMeleeAttackIfReady();

        if (GlobalCooldown > lastDiff)
        {
            Diff_Add += lastDiff;
            GlobalCooldown -= lastDiff;
            return;
        }

        uint32 diff = Diff_Add + lastDiff;
        Diff_Add = 0;

        skillStarted = false;
        // BAT FORM COMBAT (PHASE 1)
        if (!PhaseTwo)
        {
            // CHARGE
            if (Charge_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (m_creature->CastSpellOnNearestVictim(SPELL_CHARGE, 10.0f, 40.0f, false))
                    {
                        skillStarted   = true;
                        Charge_Timer   = urand(15000, 30000);
                        GlobalCooldown = 1000;
                    }
                    else
                        Charge_Timer = 2000;
                }
            }
            else
                Charge_Timer -= diff;

            // SCREECH
            if (Screech_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SCREECH) == CAST_OK)
                    {
                        skillStarted   = true;
                        Screech_Timer  = 30000;
                        GlobalCooldown = 1000;
                    }
                    else
                        Charge_Timer = 1000;
                }
            }
            else
                Screech_Timer -= diff;

            // SONICBURST
            if (SonicBurst_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SONICBURST) == CAST_OK)
                    {
                        skillStarted     = true;
                        SonicBurst_Timer = urand(20000, 24000);
                        GlobalCooldown   = 1000;
                    }
                }
            }
            else
                SonicBurst_Timer -= diff;

            // SWOOP
            if (Swoop_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SWOOP) == CAST_OK)
                    {
                        skillStarted   = true;
                        Swoop_Timer    = urand(12000, 15000);
                        GlobalCooldown = 1000;
                    }
                }
            }
            else
                Swoop_Timer -= diff;

            // PIERCEARMOR
            if (PierceArmor_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_PIERCEARMOR) == CAST_OK)
                    {
                        skillStarted      = true;
                        PierceArmor_Timer = urand(16000, 18000);
                        GlobalCooldown    = 1000;
                    }
                }
            }
            else
                PierceArmor_Timer -= diff;

        }
        // P2
        else
        {
            // SHADOW_WORD_PAIN
            if (ShadowWordPain_Timer < diff)
            {
                if (!skillStarted)
                {
                    if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        if (DoCastSpellIfCan(target, SPELL_SHADOW_WORD_PAIN) == CAST_OK)
                        {
                            ShadowWordPain_Timer = urand(8000, 12000);
                            GlobalCooldown       = 1000;
                            skillStarted         = true;
                        }
                    }
                }
            }
            else
                ShadowWordPain_Timer -= diff;

            // GREAT_HEAL
            if (GreatHeal_Timer < diff)
            {
                if (!skillStarted)
                {
                    m_creature->InterruptNonMeleeSpells(false);
                    if (DoCastSpellIfCan(m_creature, SPELL_GREAT_HEAL) == CAST_OK)
                    {
                        DoScriptText(TEXT_GREAT_HEAL, m_creature);
                        skillStarted = true;
                        GreatHeal_Timer = urand(20000, 25000);
                    }
                }
            }
            else
                GreatHeal_Timer -= diff;

            // MIND_FLAY
            if (MindFlay_Timer < diff)
            {
                if (!skillStarted)
                {
                    m_creature->InterruptNonMeleeSpells(false);
                    if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        if (DoCastSpellIfCan(target, SPELL_MIND_FLAY) == CAST_OK)
                        {
                            MindFlay_Timer = urand(25000, 30000);
                            skillStarted   = true;
                        }
                    }
                }
            }
            else
                MindFlay_Timer -= diff;

            // CURSE_OF_BLOOD
            if (CurseOfBlood_Timer < diff)
            {
                if (!skillStarted)
                {
                    m_creature->InterruptNonMeleeSpells(false);
                    if (Unit* target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                    {
                        if (DoCastSpellIfCan(target, SPELL_CURSE_OF_BLOOD) == CAST_OK)
                        {
                            CurseOfBlood_Timer = urand(25000, 30000);
                            skillStarted = true;
                        }
                    }
                }
            }
            else
                CurseOfBlood_Timer -= diff;
        }
    }
};

// Flying Bat
struct mob_batriderAI : public ScriptedAI
{
    mob_batriderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 Bomb_Timer;

    void Reset() override
    {
        Bomb_Timer = 2000;
    }

    void AttackStart(Unit *pWho) override
    {
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
    }

    void DoAttack()
    {
        if (Bomb_Timer)
            return;

        Bomb_Timer = urand(5000, 10000);

        if (Creature* pJeklik = m_creature->FindNearestCreature(NPC_JEKLIK, 150.0f))
        {
            if (Unit* pTarget = pJeklik->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
                m_creature->CastSpell(pTarget, SPELL_THROW_LIQUID_FIRE, false);
            else
                sLog.outString("mob_batriderAI: Unable to find a target");
        }
        else
            sLog.outString("mob_batriderAI: Jeklik not found.");
    }

    // Called when spell hits creature's target
    void SpellHitTarget(Unit* target, SpellEntry const* spell) override
    {
        // Trigger bomb AoE on the ground
        if (target && spell && spell->Id == SPELL_THROW_LIQUID_FIRE)
            m_creature->CastSpell(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), SPELL_BOMB, false);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        if (Bomb_Timer < diff)
            Bomb_Timer = 0;
        else
            Bomb_Timer -= diff;

        switch (m_pInstance->GetData(TYPE_JEKLIK))
        {
            case IN_PROGRESS:
                DoAttack();
                break;
            default:
                m_creature->AddObjectToRemoveList();
                break;
        }
    }
};

CreatureAI* GetAI_boss_jeklik(Creature* pCreature)
{
    return new boss_jeklikAI(pCreature);
}

CreatureAI* GetAI_mob_batrider(Creature* pCreature)
{
    return new mob_batriderAI(pCreature);
}

// TRASH
enum
{
    SPELL_EXPLOSION          = 24024, // [3 sec cast]
    SPELL_DEMORALIZING_SHOUT = 23511, // Reduces the melee attack power of nearby enemies by 40 for 30 sec. [Instant]
    SPELL_BATTLE_COMBAT      = 5115,  // Increases the attack speed of nearby allies by 50% for 6 sec.
    SPELL_INFECTED_BITE      = 16128, // Inflicts Nature damage to an enemy every 10 sec. and increases the Physical damage it takes for 3 sec. [Instant] [Melee Range]
    SPELL_THRASH             = 3391,  // Gives the caster 2 extra attacks. [Instant]
};

struct npc_guru_bat_riderAI : public ScriptedAI
{
    npc_guru_bat_riderAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    bool GoingToExplose;
    uint32 Despawn_Timer;
    uint32 Combat_Timer;
    uint32 InfectedBite_Timer;
    uint32 Thrash_Timer;

    void Reset() override
    {
        GoingToExplose     = false;
        Despawn_Timer      = 0;
        Combat_Timer       = 8000;
        InfectedBite_Timer = 6500;
        Thrash_Timer       = 6000;
    }

    void Aggro(Unit* pWho) override
    {
        m_creature->CastSpell(m_creature, SPELL_DEMORALIZING_SHOUT, false);
        ScriptedAI::Aggro(pWho);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!GoingToExplose && m_creature->GetHealthPercent() < 40.0f)
        {
            GoingToExplose = true;
            if (urand(0, 1))
                m_creature->MonsterTextEmote("Gurubashi Bat Rider becomes fully engulfed in flames.", nullptr, false);
            else
                m_creature->MonsterTextEmote("Gurubashi Bat Rider gets a crazed look in his eye.", nullptr, false);
            m_creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true); // fear immunity
            m_creature->CastSpell(m_creature, SPELL_EXPLOSION, false);
        }

        if (Combat_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_BATTLE_COMBAT) == CAST_OK)
                Combat_Timer = 25000;
        }
        else
            Combat_Timer -= diff;

        if (InfectedBite_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_INFECTED_BITE) == CAST_OK)
                InfectedBite_Timer = 15000;
        }
        else
            InfectedBite_Timer -= diff;

        if (Thrash_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THRASH) == CAST_OK)
                Thrash_Timer = 6000;
        }
        else
            Thrash_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_guru_bat_rider(Creature* pCreature)
{
    return new npc_guru_bat_riderAI(pCreature);
}

void AddSC_boss_jeklik()
{
    Script* newscript;
    newscript = new Script;
    newscript->Name = "boss_jeklik";
    newscript->GetAI = &GetAI_boss_jeklik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_batrider";
    newscript->GetAI = &GetAI_mob_batrider;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_guru_bat_rider";
    newscript->GetAI = &GetAI_guru_bat_rider;
    newscript->RegisterSelf();
}
