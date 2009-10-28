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
SDName: Boss_Omar_The_Unscarred
SD%Complete: 90
SDComment: Temporary solution for orbital/shadow whip-ability. Needs more core support before making it more proper.
SDCategory: Hellfire Citadel, Hellfire Ramparts
EndScriptData */

#include "precompiled.h"

#define SAY_AGGRO_1                 -1543009
#define SAY_AGGRO_2                 -1543010
#define SAY_AGGRO_3                 -1543011
#define SAY_SUMMON                  -1543012
#define SAY_CURSE                   -1543013
#define SAY_KILL_1                  -1543014
#define SAY_DIE                     -1543015
#define SAY_WIPE                    -1543016

#define SPELL_ORBITAL_STRIKE        30637
#define SPELL_SHADOW_WHIP           30638
#define SPELL_TREACHEROUS_AURA      30695
#define H_SPELL_BANE_OF_TREACHERY   37566
#define SPELL_DEMONIC_SHIELD        31901
#define SPELL_SHADOW_BOLT           30686
#define H_SPELL_SHADOW_BOLT         39297
#define SPELL_SUMMON_FIENDISH_HOUND 30707

struct TRINITY_DLL_DECL boss_omor_the_unscarredAI : public ScriptedAI
{
    boss_omor_the_unscarredAI(Creature *c) : ScriptedAI(c)
    {
        SetCombatMovement(false);
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    bool HeroicMode;

    uint32 OrbitalStrike_Timer;
    uint32 ShadowWhip_Timer;
    uint32 Aura_Timer;
    uint32 DemonicShield_Timer;
    uint32 Shadowbolt_Timer;
    uint32 Summon_Timer;
    uint32 SummonedCount;
    uint64 PlayerGUID;
    bool CanPullBack;

    void Reset()
    {
        DoScriptText(SAY_WIPE, m_creature);

        OrbitalStrike_Timer = 25000;
        ShadowWhip_Timer = 2000;
        Aura_Timer = 10000;
        DemonicShield_Timer = 1000;
        Shadowbolt_Timer = 2000;
        Summon_Timer = 10000;
        SummonedCount = 0;
        PlayerGUID = 0;
        CanPullBack = false;
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2,SAY_AGGRO_3), m_creature);
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

        DoScriptText(SAY_KILL_1, m_creature);
    }

    void JustSummoned(Creature* summoned)
    {
        DoScriptText(SAY_SUMMON, m_creature);

        if (Unit* random = SelectUnit(SELECT_TARGET_RANDOM,0))
            summoned->AI()->AttackStart(random);

        ++SummonedCount;
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DIE, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //only two may be wrong, perhaps increase timer and spawn periodically instead.
        if (SummonedCount < 2)
        {
            if (Summon_Timer <= diff)
            {
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(m_creature,SPELL_SUMMON_FIENDISH_HOUND);
                Summon_Timer = 15000+rand()%15000;
            } else Summon_Timer -= diff;
        }

        if (CanPullBack)
        {
            if (ShadowWhip_Timer <= diff)
            {
                if (Player* temp = Unit::GetPlayer(PlayerGUID))
                {
                    //if unit dosen't have this flag, then no pulling back (script will attempt cast, even if orbital strike was resisted)
                    if (temp->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
                    {
                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(temp,SPELL_SHADOW_WHIP);
                    }
                }
                PlayerGUID = 0;
                ShadowWhip_Timer = 2000;
                CanPullBack = false;
            } else ShadowWhip_Timer -= diff;
        }
        else if (OrbitalStrike_Timer <= diff)
        {
            Unit* temp = NULL;
            if (m_creature->IsWithinMeleeRange(m_creature->getVictim()))
                temp = m_creature->getVictim();
            else temp = SelectUnit(SELECT_TARGET_RANDOM,0);

            if (temp && temp->GetTypeId() == TYPEID_PLAYER)
            {
                DoCast(temp,SPELL_ORBITAL_STRIKE);
                OrbitalStrike_Timer = 14000+rand()%2000;
                PlayerGUID = temp->GetGUID();

                if (PlayerGUID)
                    CanPullBack = true;
            }
        } else OrbitalStrike_Timer -= diff;

        if ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 20)
        {
            if (DemonicShield_Timer <= diff)
            {
                DoCast(m_creature,SPELL_DEMONIC_SHIELD);
                DemonicShield_Timer = 15000;
            } else DemonicShield_Timer -= diff;
        }

        if (Aura_Timer <= diff)
        {
            DoScriptText(SAY_CURSE, m_creature);

            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
            {
                DoCast(pTarget,HEROIC(SPELL_TREACHEROUS_AURA, H_SPELL_BANE_OF_TREACHERY));
                Aura_Timer = 8000+rand()%8000;
            }
        } else Aura_Timer -= diff;

        if (Shadowbolt_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
            {
                if (pTarget)
                    pTarget = m_creature->getVictim();

                DoCast(pTarget,HEROIC(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
                Shadowbolt_Timer = 4000+rand()%2500;
            }
        } else Shadowbolt_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_omor_the_unscarredAI(Creature* pCreature)
{
    return new boss_omor_the_unscarredAI (pCreature);
}

void AddSC_boss_omor_the_unscarred()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_omor_the_unscarred";
    newscript->GetAI = &GetAI_boss_omor_the_unscarredAI;
    newscript->RegisterSelf();
}

