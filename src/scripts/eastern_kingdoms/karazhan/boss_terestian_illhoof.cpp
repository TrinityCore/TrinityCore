/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Boss_Terestian_Illhoof
SD%Complete: 95
SDComment: Complete! Needs adjustments to use spell though.
SDCategory: Karazhan
EndScriptData */

#include "ScriptedPch.h"
#include "karazhan.h"

#define SAY_SLAY1                   -1532065
#define SAY_SLAY2                   -1532066
#define SAY_DEATH                   -1532067
#define SAY_AGGRO                   -1532068
#define SAY_SACRIFICE1              -1532069
#define SAY_SACRIFICE2              -1532070
#define SAY_SUMMON1                 -1532071
#define SAY_SUMMON2                 -1532072

#define SPELL_SUMMON_DEMONCHAINS    30120                   // Summons demonic chains that maintain the ritual of sacrifice.
#define SPELL_DEMON_CHAINS          30206                   // Instant - Visual Effect
#define SPELL_ENRAGE                23537                   // Increases the caster's attack speed by 50% and the Physical damage it deals by 219 to 281 for 10 min.
#define SPELL_SHADOW_BOLT           30055                   // Hurls a bolt of dark magic at an enemy, inflicting Shadow damage.
#define SPELL_SACRIFICE             30115                   // Teleports and adds the debuff
#define SPELL_BERSERK               32965                   // Increases attack speed by 75%. Periodically casts Shadow Bolt Volley.
#define SPELL_SUMMON_FIENDISIMP     30184                   // Summons a Fiendish Imp.
#define SPELL_SUMMON_IMP            30066                   // Summons Kil'rek

#define SPELL_FIENDISH_PORTAL       30171                   // Opens portal and summons Fiendish Portal, 2 sec cast
#define SPELL_FIENDISH_PORTAL_1     30179                   // Opens portal and summons Fiendish Portal, instant cast

#define SPELL_FIREBOLT              30050                   // Blasts a target for 150 Fire damage.
#define SPELL_BROKEN_PACT           30065                   // All damage taken increased by 25%.
#define SPELL_AMPLIFY_FLAMES        30053                   // Increases the Fire damage taken by an enemy by 500 for 25 sec.

#define CREATURE_DEMONCHAINS    17248
#define CREATURE_FIENDISHIMP    17267
#define CREATURE_PORTAL         17265
#define CREATURE_KILREK         17229

struct mob_kilrekAI : public ScriptedAI
{
    mob_kilrekAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint64 TerestianGUID;

    uint32 AmplifyTimer;

    void Reset()
    {
        TerestianGUID = 0;
        AmplifyTimer = 2000;
    }

    void EnterCombat(Unit *who)
    {
        if (!pInstance)
        {
            ERROR_INST_DATA(m_creature);
            return;
        }
    }

    void JustDied(Unit* Killer)
    {
        if (pInstance)
        {
            uint64 TerestianGUID = pInstance->GetData64(DATA_TERESTIAN);
            if (TerestianGUID)
            {
                Unit* Terestian = Unit::GetUnit((*m_creature), TerestianGUID);
                if (Terestian && Terestian->isAlive())
                    DoCast(Terestian, SPELL_BROKEN_PACT, true);
            }
        } else ERROR_INST_DATA(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (AmplifyTimer <= diff)
        {
            m_creature->InterruptNonMeleeSpells(false);
            DoCast(m_creature->getVictim(), SPELL_AMPLIFY_FLAMES);

            AmplifyTimer = urand(10000,20000);
        } else AmplifyTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct mob_demon_chainAI : public ScriptedAI
{
    mob_demon_chainAI(Creature *c) : ScriptedAI(c) {}

    uint64 SacrificeGUID;

    void Reset()
    {
        SacrificeGUID = 0;
    }

    void EnterCombat(Unit* who) {}
    void AttackStart(Unit* who) {}
    void MoveInLineOfSight(Unit* who) {}

    void JustDied(Unit *killer)
    {
        if (SacrificeGUID)
        {
            Unit* Sacrifice = Unit::GetUnit((*m_creature),SacrificeGUID);
            if (Sacrifice)
                Sacrifice->RemoveAurasDueToSpell(SPELL_SACRIFICE);
        }
    }
};

struct mob_fiendish_portalAI : public PassiveAI
{
    mob_fiendish_portalAI(Creature *c) : PassiveAI(c),summons(m_creature){}

    SummonList summons;

    void Reset()
    {
        summons.DespawnAll();
    }

    void JustSummoned(Creature* summon)
    {
        summons.Summon(summon);
        DoZoneInCombat(summon);
    }

    void DespawnAllImp()
    {
        summons.DespawnAll();
    }
};

struct boss_terestianAI : public ScriptedAI
{
    boss_terestianAI(Creature *c) : ScriptedAI(c)
    {
        for (uint8 i = 0; i < 2; ++i)
            PortalGUID[i] = 0;
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;

    uint64 PortalGUID[2];
    uint8 PortalsCount;

    uint32 SacrificeTimer;
    uint32 ShadowboltTimer;
    uint32 SummonTimer;
    uint32 BerserkTimer;

    bool SummonedPortals;
    bool Berserk;

    void Reset()
    {
        for (uint8 i = 0; i < 2; ++i)
        {
            if (PortalGUID[i])
            {
                if (Creature* pPortal = Unit::GetCreature(*m_creature, PortalGUID[i]))
                {
                    CAST_AI(mob_fiendish_portalAI, pPortal->AI())->DespawnAllImp();
                    pPortal->ForcedDespawn();
                }

                PortalGUID[i] = 0;
            }
        }

        PortalsCount        =     0;
        SacrificeTimer      = 30000;
        ShadowboltTimer     =  5000;
        SummonTimer         = 10000;
        BerserkTimer        = 600000;

        SummonedPortals     = false;
        Berserk             = false;

        if (pInstance)
            pInstance->SetData(TYPE_TERESTIAN, NOT_STARTED);

        m_creature->RemoveAurasDueToSpell(SPELL_BROKEN_PACT);

        if(Minion* Kilrek = m_creature->GetFirstMinion())
        {
            if(!Kilrek->isAlive())
            {
                Kilrek->UnSummon();
                DoCast(m_creature, SPELL_SUMMON_IMP, true);
            }
        }
        else DoCast(m_creature, SPELL_SUMMON_IMP, true);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
    }

    void JustSummoned(Creature* pSummoned)
    {
        if (pSummoned->GetEntry() == CREATURE_PORTAL)
        {
            PortalGUID[PortalsCount] = pSummoned->GetGUID();
            ++PortalsCount;

            if (pSummoned->GetUInt32Value(UNIT_CREATED_BY_SPELL) == SPELL_FIENDISH_PORTAL_1)
            {
                DoScriptText(RAND(SAY_SUMMON1,SAY_SUMMON2), m_creature);
                SummonedPortals = true;
            }
        }
    }

    void KilledUnit(Unit *victim)
    {
        DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2), m_creature);
    }

    void JustDied(Unit *killer)
    {
        for (uint8 i = 0; i < 2; ++i)
        {
            if (PortalGUID[i])
            {
                if (Creature* pPortal = Unit::GetCreature((*m_creature), PortalGUID[i]))
                    pPortal->ForcedDespawn();

                PortalGUID[i] = 0;
            }
        }

        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
            pInstance->SetData(TYPE_TERESTIAN, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (SacrificeTimer <= diff)
        {
            Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 100, true);
            if (pTarget && pTarget->isAlive())
            {
                DoCast(pTarget, SPELL_SACRIFICE, true);
                DoCast(pTarget, SPELL_SUMMON_DEMONCHAINS, true);

                if (Creature* Chains = m_creature->FindNearestCreature(CREATURE_DEMONCHAINS, 5000))
                {
                    CAST_AI(mob_demon_chainAI, Chains->AI())->SacrificeGUID = pTarget->GetGUID();
                    Chains->CastSpell(Chains, SPELL_DEMON_CHAINS, true);
                    DoScriptText(RAND(SAY_SACRIFICE1,SAY_SACRIFICE2), m_creature);
                    SacrificeTimer = 30000;
                }
            }
        } else SacrificeTimer -= diff;

        if (ShadowboltTimer <= diff)
        {
            DoCast(SelectUnit(SELECT_TARGET_TOPAGGRO, 0), SPELL_SHADOW_BOLT);
            ShadowboltTimer = 10000;
        } else ShadowboltTimer -= diff;

        if (SummonTimer <= diff)
        {
            if(!PortalGUID[0])
                DoCast(m_creature->getVictim(), SPELL_FIENDISH_PORTAL, false);

            if(!PortalGUID[1])
                DoCast(m_creature->getVictim(), SPELL_FIENDISH_PORTAL_1, false);

            if(PortalGUID[0] && PortalGUID[1])
            {
                if (Creature* pPortal = Unit::GetCreature(*m_creature, PortalGUID[urand(0,1)]))
                    pPortal->CastSpell(m_creature->getVictim(), SPELL_SUMMON_FIENDISIMP, false);
                SummonTimer = 5000;
            }
        } else SummonTimer -= diff;

        if (!Berserk)
        {
            if (BerserkTimer <= diff)
            {
                DoCast(m_creature, SPELL_BERSERK);
                Berserk = true;
            } else BerserkTimer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};

#define SPELL_FIREBOLT  30050   // Blasts a target for 181-209 Fire damage.

struct mob_fiendish_impAI : public ScriptedAI
{
    mob_fiendish_impAI(Creature *c) : ScriptedAI(c) {}

    uint32 FireboltTimer;

    void Reset()
    {
        FireboltTimer = 2000;

        m_creature->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
    }

    void EnterCombat(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (FireboltTimer <= diff)
        {
            DoCast(m_creature->getVictim(), SPELL_FIREBOLT);
            FireboltTimer = 2200;
        } else FireboltTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_kilrek(Creature* pCreature)
{
    return new mob_kilrekAI (pCreature);
}

CreatureAI* GetAI_mob_fiendish_imp(Creature* pCreature)
{
    return new mob_fiendish_impAI (pCreature);
}

CreatureAI* GetAI_mob_fiendish_portal(Creature* pCreature)
{
    return new mob_fiendish_portalAI (pCreature);
}

CreatureAI* GetAI_boss_terestian_illhoof(Creature* pCreature)
{
    return new boss_terestianAI (pCreature);
}

CreatureAI* GetAI_mob_demon_chain(Creature* pCreature)
{
    return new mob_demon_chainAI(pCreature);
}

void AddSC_boss_terestian_illhoof()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_terestian_illhoof";
    newscript->GetAI = &GetAI_boss_terestian_illhoof;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_fiendish_imp";
    newscript->GetAI = &GetAI_mob_fiendish_imp;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name= "mob_fiendish_portal";
    newscript->GetAI = &GetAI_mob_fiendish_portal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_kilrek";
    newscript->GetAI = &GetAI_mob_kilrek;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_demon_chain";
    newscript->GetAI = &GetAI_mob_demon_chain;
    newscript->RegisterSelf();
}

