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
SDName: Boss_Omar_The_Unscarred
SD%Complete: 90
SDComment: Normal/Heroic support: both, to be tested. Temporary solution for orbital/shadow whip-ability. Needs more core support before making it more proper.
SDCategory: Hellfire Citadel, Hellfire Ramparts
EndScriptData */

#include "precompiled.h"

#define SPELL_ORBITAL_STRIKE        30637
#define SPELL_SHADOW_WHIP           30638
#define SPELL_TREACHEROUS_AURA      30695
#define H_SPELL_BANE_OF_TREACHERY   37566
#define SPELL_DEMONIC_SHIELD        31901
#define SPELL_SHADOW_BOLT           30686
#define H_SPELL_SHADOW_BOLT         39297
#define SPELL_SUMMON_FIENDISH_HOUND 30707

#define SAY_AGGRO_1                 "You dare stand against me?!"
#define SOUND_AGGRO_1               10280
#define SAY_AGGRO_2                 "I will not be defeated!"
#define SOUND_AGGRO_2               10279
#define SAY_AGGRO_3                 "Your insolence will be your death."
#define SOUND_AGGRO_3               10281

#define SAY_SUMMON                  "Achor-she-ki! Feast my pet! Eat your fill!"
#define SOUND_SUMMON                10277

#define SAY_CURSE                   "A-Kreesh!"
#define SOUND_CURSE                 10278

#define SAY_KILL_1                  "Die, weakling!"
#define SOUND_KILL_1                10282

#define SAY_DIE                     "It is... not over."
#define SOUND_DIE                   10284

#define SAY_WIPE                    "I am victorious!"
#define SOUND_WIPE                  10283

struct TRINITY_DLL_DECL boss_omor_the_unscarredAI : public ScriptedAI
{
    boss_omor_the_unscarredAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 OrbitalStrike_Timer;
    uint32 ShadowWhip_Timer;
    uint32 Aura_Timer;
    uint32 DemonicShield_Timer;
    uint32 Shadowbolt_Timer;
    uint32 Summon_Timer;
    uint32 SummonedCount;
    uint64 playerGUID;
    bool CanPullBack;
    bool HeroicMode;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();

        DoYell(SAY_WIPE,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_WIPE);

        OrbitalStrike_Timer = 25000;
        ShadowWhip_Timer = 2000;
        Aura_Timer = 10000;
        DemonicShield_Timer = 1000;
        Shadowbolt_Timer = 2000;
        Summon_Timer = 10000;
        SummonedCount = 0;
        playerGUID = 0;
        CanPullBack = false;
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO_1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_1);
                break;
            case 1:
                DoYell(SAY_AGGRO_2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_2);
                break;
            case 2:
                DoYell(SAY_AGGRO_3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_3);
                break;
        }
    }

    void AttackStart(Unit* who)
    {
        if (!who)
            return;

        if (who->isTargetableForAttack())
        {
            DoStartAttackNoMovement(who);

            if (!InCombat)
            {
                InCombat = true;
                Aggro(who);
            }
        }
    }

    void MoveInLineOfSight(Unit* who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if(m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                DoStartAttackNoMovement(who);
                who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if (!InCombat)
                {
                    InCombat = true;
                    Aggro(who);
                }
            }
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

        DoYell(SAY_KILL_1,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_KILL_1);
    }

    void JustSummoned(Creature* summoned)
    {
        DoYell(SAY_SUMMON,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_SUMMON);

        if( Unit* random = SelectUnit(SELECT_TARGET_RANDOM,0) )
            summoned->AI()->AttackStart(random);

        ++SummonedCount;
    }

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DIE,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature,SOUND_DIE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        //only two may be wrong, perhaps increase timer and spawn periodically instead.
        if( SummonedCount < 2 )
        {
            if( Summon_Timer < diff )
            {
                m_creature->InterruptNonMeleeSpells(false);
                DoCast(m_creature,SPELL_SUMMON_FIENDISH_HOUND);
                Summon_Timer = 15000+rand()%15000;
            }else Summon_Timer -= diff;
        }

        if( CanPullBack )
        {
            if( ShadowWhip_Timer < diff )
            {
                if( Unit* temp = Unit::GetUnit(*m_creature,playerGUID) )
                {
                    //if unit dosen't have this flag, then no pulling back (script will attempt cast, even if orbital strike was resisted)
                    if( temp->HasUnitMovementFlag(MOVEMENTFLAG_FALLING) )
                    {
                        m_creature->InterruptNonMeleeSpells(false);
                        DoCast(temp,SPELL_SHADOW_WHIP);
                    }
                }
                playerGUID = 0;
                ShadowWhip_Timer = 2000;
                CanPullBack = false;
            }else ShadowWhip_Timer -= diff;
        }
        else if( OrbitalStrike_Timer < diff )
        {
            Unit* temp = NULL;
            if( m_creature->IsWithinDistInMap(m_creature->getVictim(), ATTACK_DISTANCE) )
                temp = m_creature->getVictim();
            else temp = SelectUnit(SELECT_TARGET_RANDOM,0);

            if( temp && temp->GetTypeId() == TYPEID_PLAYER )
            {
                DoCast(temp,SPELL_ORBITAL_STRIKE);
                OrbitalStrike_Timer = 14000+rand()%2000;
                playerGUID = temp->GetGUID();
                if( playerGUID )
                    CanPullBack = true;
            }
        }else OrbitalStrike_Timer -= diff;

        if( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 20 )
        {
            if( DemonicShield_Timer < diff )
            {
                DoCast(m_creature,SPELL_DEMONIC_SHIELD);
                DemonicShield_Timer = 15000;
            }else DemonicShield_Timer -= diff;
        }

        if( Aura_Timer < diff )
        {
            DoYell(SAY_CURSE,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_CURSE);

            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            {
                if( HeroicMode ) DoCast(target,H_SPELL_BANE_OF_TREACHERY);
                else DoCast(target,SPELL_TREACHEROUS_AURA);

                Aura_Timer = 8000+rand()%8000;
            }
        }else Aura_Timer -= diff;

        if( Shadowbolt_Timer < diff )
        {
            if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            {
                if( target )
                    target = m_creature->getVictim();

                if( HeroicMode ) DoCast(target,H_SPELL_SHADOW_BOLT);
                else DoCast(target,SPELL_SHADOW_BOLT);

                Shadowbolt_Timer = 4000+rand()%2500;
            }
        }else Shadowbolt_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_omor_the_unscarredAI(Creature *_Creature)
{
    return new boss_omor_the_unscarredAI (_Creature);
}

void AddSC_boss_omor_the_unscarred()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_omor_the_unscarred";
    newscript->GetAI = GetAI_boss_omor_the_unscarredAI;
    m_scripts[nrscripts++] = newscript;
}
