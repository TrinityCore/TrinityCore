/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_NexusPrince_Shaffar
SD%Complete: 80
SDComment: Need more tuning of spell timers, it should not be as linear fight as current. Also should possibly find a better way to deal with his three initial beacons to make sure all aggro.
SDCategory: Auchindoun, Mana Tombs
EndScriptData */

/* ContentData
boss_nexusprince_shaffar
mob_ethereal_beacon
EndContentData */

#include "precompiled.h"

#define SAY_INTRO                       -1557000

#define SAY_AGGRO_1                     -1557001
#define SAY_AGGRO_2                     -1557002
#define SAY_AGGRO_3                     -1557003

#define SAY_SLAY_1                      -1557004
#define SAY_SLAY_2                      -1557005

#define SAY_SUMMON                      -1557006

#define SAY_DEAD                        -1557007

#define SPELL_BLINK                     34605
#define SPELL_FROSTBOLT                 32370
#define SPELL_FIREBALL                  20420
#define SPELL_FROSTNOVA                 32365

#define SPELL_ETHEREAL_BEACON           32371               // Summon 18431
#define SPELL_ETHEREAL_BEACON_VISUAL    32368

#define ENTRY_BEACON                    18431
#define ENTRY_SHAFFAR                   18344

#define NR_INITIAL_BEACONS              3

struct TRINITY_DLL_DECL boss_nexusprince_shaffarAI : public ScriptedAI
{
    boss_nexusprince_shaffarAI(Creature *c) : ScriptedAI(c) {}

    uint32 Blink_Timer;
    uint32 Beacon_Timer;
    uint32 FireBall_Timer;
    uint32 Frostbolt_Timer;
    uint32 FrostNova_Timer;

    Creature* Beacon[NR_INITIAL_BEACONS];

    bool HasTaunted;
    bool CanBlink;

    void RemoveBeaconFromList(Creature* targetBeacon)
    {
        for(uint8 i = 0; i < NR_INITIAL_BEACONS; i++)
            if(Beacon[i] && Beacon[i]->GetGUID() == targetBeacon->GetGUID())
                Beacon[i] = NULL;
    }

    void Reset()
    {
        Blink_Timer = 1500;
        Beacon_Timer = 10000;
        FireBall_Timer = 8000;
        Frostbolt_Timer = 4000;
        FrostNova_Timer = 15000;

        HasTaunted = false;
        CanBlink = false;

        float dist = 8.0f;
        float posX, posY, posZ, angle;
        m_creature->GetHomePosition(posX, posY, posZ, angle);

        Beacon[0] = m_creature->SummonCreature(ENTRY_BEACON, posX - dist, posY - dist, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);
        Beacon[1] = m_creature->SummonCreature(ENTRY_BEACON, posX - dist, posY + dist, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);
        Beacon[2] = m_creature->SummonCreature(ENTRY_BEACON, posX + dist, posY, posZ, angle, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 7200000);

        for(uint8 i = 0; i < NR_INITIAL_BEACONS; i++)
        {
            if(Beacon[i])
                Beacon[i]->CastSpell(Beacon[i], SPELL_ETHEREAL_BEACON_VISUAL, false);
        }
    }

    void EnterEvadeMode()
    {
        //Despawn still living initial beacons.
        for(uint8 i = 0; i < NR_INITIAL_BEACONS; i++)
        {
            if(Beacon[i] && Beacon[i]->isAlive())
            {
                Beacon[i]->RemoveAllAuras();
                Beacon[i]->CombatStop();
                Beacon[i]->StopMoving();
                Beacon[i]->Kill(Beacon[i]);
            }
        }
        ScriptedAI::EnterEvadeMode();
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessiblePlaceFor(m_creature) )
        {
            if( !HasTaunted && m_creature->IsWithinDistInMap(who, 100.0) )
            {
                DoScriptText(SAY_INTRO, m_creature);
                HasTaunted = true;
            }

            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
            {
                //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
            }
        }
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0: DoScriptText(SAY_AGGRO_1, m_creature); break;
            case 1: DoScriptText(SAY_AGGRO_2, m_creature); break;
            case 2: DoScriptText(SAY_AGGRO_3, m_creature); break;
        }

        // Send initial beacons to join the fight if not already
        for(uint8 i = 0; i < NR_INITIAL_BEACONS; i++)
            if(Beacon[i] && Beacon[i]->isAlive() && !Beacon[i]->isInCombat())
                Beacon[i]->AI()->AttackStart(who);
    }

    void JustSummoned(Creature *summoned)
    {
        if( summoned->GetEntry() == ENTRY_BEACON )
        {
            summoned->CastSpell(summoned,SPELL_ETHEREAL_BEACON_VISUAL,false);

            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                summoned->AI()->AttackStart(target);
        }
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0: DoScriptText(SAY_SLAY_1, m_creature); break;
            case 1: DoScriptText(SAY_SLAY_2, m_creature); break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DEAD, m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if( FrostNova_Timer < diff )
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(true);

            DoCast(m_creature,SPELL_FROSTNOVA);
            FrostNova_Timer  = 17500 + rand()%7500;
            CanBlink = true;
        }else FrostNova_Timer -= diff;

        if( Frostbolt_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FROSTBOLT);
            Frostbolt_Timer = 4500 + rand()%1500;
        }else Frostbolt_Timer -= diff;

        if( FireBall_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_FIREBALL);
            FireBall_Timer = 4500 + rand()%1500;
        }else FireBall_Timer -= diff;

        if( CanBlink )
        {
            if( Blink_Timer < diff )
            {
                if( m_creature->IsNonMeleeSpellCasted(false) )
                    m_creature->InterruptNonMeleeSpells(true);

                DoCast(m_creature,SPELL_BLINK);
                Blink_Timer = 1000 + rand()%1500;
                CanBlink = false;
            }else Blink_Timer -= diff;
        }

        if( Beacon_Timer < diff)
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(true);

            if( !urand(0,3) )
                DoScriptText(SAY_SUMMON, m_creature);

            DoCast(m_creature,SPELL_ETHEREAL_BEACON);

            Beacon_Timer = 10000;
        }else Beacon_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_nexusprince_shaffar(Creature *_Creature)
{
    return new boss_nexusprince_shaffarAI (_Creature);
}

#define SPELL_ARCANE_BOLT               15254
#define SPELL_ETHEREAL_APPRENTICE       32372               // Summon 18430

struct TRINITY_DLL_DECL mob_ethereal_beaconAI : public ScriptedAI
{
    mob_ethereal_beaconAI(Creature *c) : ScriptedAI(c)
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    bool HeroicMode;
    uint32 Apprentice_Timer;
    uint32 ArcaneBolt_Timer;
    uint32 Check_Timer;

    void KillSelf()
    {
        m_creature->Kill(m_creature);
    }

    void Reset()
    {
        Apprentice_Timer = (HeroicMode ? 10000 : 20000);
        ArcaneBolt_Timer = 1000;
        Check_Timer = 1000;
    }

    void Aggro(Unit *who)
    {
        // Send Shaffar to fight
        Unit* Shaffar = FindCreature(ENTRY_SHAFFAR, 100, m_creature);
        if(!Shaffar || Shaffar->isDead())
        {
            KillSelf();
            return;
        }
        if(!Shaffar->isInCombat())
            ((Creature*)Shaffar)->AI()->AttackStart(who);
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->AI()->AttackStart(m_creature->getVictim());
    }

    void JustDied(Unit* Killer)
    {
        Unit *Shaffar = FindCreature(ENTRY_SHAFFAR, 100, m_creature);
        if(Shaffar)
            ((boss_nexusprince_shaffarAI*)(((Creature*)Shaffar)->AI()))->RemoveBeaconFromList(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(Check_Timer < diff)
        {
            Unit *Shaffar = FindCreature(ENTRY_SHAFFAR, 100, m_creature);
            if(!Shaffar || Shaffar->isDead() || !Shaffar->isInCombat())
            {
                KillSelf();
                return;
            }
            Check_Timer = 1000;
        }else Check_Timer -= diff;

        if( ArcaneBolt_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_ARCANE_BOLT);
            ArcaneBolt_Timer = 2000 + rand()%2500;
        }else ArcaneBolt_Timer -= diff;

        if( Apprentice_Timer < diff )
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(true);

            m_creature->CastSpell(m_creature,SPELL_ETHEREAL_APPRENTICE,true);
            if( m_creature->isPet() )
                ((Pet*)m_creature)->SetDuration(0);
            KillSelf();
            return;
        }else Apprentice_Timer -= diff;
    }
};

CreatureAI* GetAI_mob_ethereal_beacon(Creature *_Creature)
{
    return new mob_ethereal_beaconAI (_Creature);
}

#define SPELL_ETHEREAL_APPRENTICE_FIREBOLT          32369
#define SPELL_ETHEREAL_APPRENTICE_FROSTBOLT         32370

struct TRINITY_DLL_DECL mob_ethereal_apprenticeAI : public ScriptedAI
{
    mob_ethereal_apprenticeAI(Creature *c) : ScriptedAI(c) {}

    uint32 Cast_Timer;

    bool isFireboltTurn;

    void Reset()
    {
        Cast_Timer = 3000;
        isFireboltTurn = true;
    }

    void Aggro(Unit* who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!UpdateVictim())
            return;

        if(Cast_Timer < diff)
        {
            if(isFireboltTurn)
            {
                m_creature->CastSpell(m_creature->getVictim(), SPELL_ETHEREAL_APPRENTICE_FIREBOLT, true);
                isFireboltTurn = false;
            }else{
                m_creature->CastSpell(m_creature->getVictim(), SPELL_ETHEREAL_APPRENTICE_FROSTBOLT, true);
                isFireboltTurn = true;
            }
            Cast_Timer = 3000;
        }else Cast_Timer -= diff;
    }
};

CreatureAI* GetAI_mob_ethereal_apprentice(Creature *_Creature)
{
    return new mob_ethereal_apprenticeAI (_Creature);
}

void AddSC_boss_nexusprince_shaffar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_nexusprince_shaffar";
    newscript->GetAI = &GetAI_boss_nexusprince_shaffar;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_ethereal_beacon";
    newscript->GetAI = &GetAI_mob_ethereal_beacon;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="mob_ethereal_apprentice";
    newscript->GetAI = &GetAI_mob_ethereal_apprentice;
    newscript->RegisterSelf();
}

