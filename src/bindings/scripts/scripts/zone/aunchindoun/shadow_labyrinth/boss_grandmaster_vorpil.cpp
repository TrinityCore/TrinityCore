/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Grandmaster_Vorpil
SD%Complete: 75
SDComment: Despawn all summoned on death not implemented. Void Traveler effects not implemented.
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "def_shadow_labyrinth.h"

#define SPELL_DRAW_SHADOWS              33563
#define SPELL_VOID_PORTAL_A             33566               //spell only summon one unit, but we use it for the visual effect and summon the 4 other portals manual way(only one spell exist)
#define SPELL_VOID_PORTAL_VISUAL        33569
#define SPELL_SHADOW_BOLT_VOLLEY        32963
#define SPELL_SUMMON_VOIDWALKER_A       33582
#define SPELL_SUMMON_VOIDWALKER_B       33583
#define SPELL_SUMMON_VOIDWALKER_C       33584
#define SPELL_SUMMON_VOIDWALKER_D       33585
#define SPELL_SUMMON_VOIDWALKER_E       33586
#define SPELL_RAIN_OF_FIRE              33617
#define H_SPELL_RAIN_OF_FIRE            39363
#define H_SPELL_BANISH                  38791

#define SAY_INTRO               "Keep your minds focused for the days of reckoning are close at hand. Soon, the destroyer of worlds will return to make good on his promise. Soon the destruction of all that is will begin!"
#define SAY_AGGRO1              "I'll make an offering of your blood!"
#define SAY_AGGRO2              "You'll be a fine example, for the others."
#define SAY_AGGRO3              "Good, a worthy sacrifice."
#define SAY_HELP                "Come to my aid, heed your master now!"
#define SAY_SLAY1               "I serve with pride."
#define SAY_SLAY2               "Your death is for the greater cause!"
#define SAY_DEATH               "I give my life... Gladly."

#define SOUND_INTRO             10522
#define SOUND_AGGRO1            10524
#define SOUND_AGGRO2            10525
#define SOUND_AGGRO3            10526
#define SOUND_HELP              10523
#define SOUND_SLAY1             10527
#define SOUND_SLAY2             10528
#define SOUND_DEATH             10529

#define ENTRY_VOID_PORTAL       19224
#define ENTRY_VOID_TRAVELER     19226

#define LOCX                    -253.06f
#define LOCY                    -264.02f
#define LOCZ                    17.08

struct MANGOS_DLL_DECL boss_grandmaster_vorpilAI : public ScriptedAI
{
    boss_grandmaster_vorpilAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 ShadowBoltVolley_Timer;
    uint32 DrawShadows_Timer;
    uint32 Teleport_Timer;
    uint32 VoidTraveler_Timer;
    uint32 Banish_Timer;
    bool Intro;
    bool Teleport;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();

        ShadowBoltVolley_Timer = 15000;
        DrawShadows_Timer = 40000;
        Teleport_Timer = 1000;
        VoidTraveler_Timer = 20000;
        Banish_Timer = 25000;
        Intro = false;
        Teleport = false;

        if( pInstance )
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, NOT_STARTED);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
        {
            //not sure about right radius
            if(!Intro && m_creature->IsWithinDistInMap(who, 50))
            {
                DoYell(SAY_INTRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_INTRO);
                DoCast(m_creature, SPELL_VOID_PORTAL_A,true);
                m_creature->SummonCreature(ENTRY_VOID_PORTAL,-262.40,-229.57,17.08,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                m_creature->SummonCreature(ENTRY_VOID_PORTAL,-260.35,-297.56,17.08,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                m_creature->SummonCreature(ENTRY_VOID_PORTAL,-292.05,-270.37,12.68,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                m_creature->SummonCreature(ENTRY_VOID_PORTAL,-301.64,-255.97,12.68,0,TEMPSUMMON_CORPSE_DESPAWN,0);
                Intro = true;
            }

            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
            {
                DoStartAttackAndMovement(who);
                who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if (!InCombat)
                {
                    Aggro(who);
                    InCombat = true;
                }
            }
        }
    }

    void Aggro(Unit *who)
    {
        switch(rand()%3)
        {
            case 0:
                DoYell(SAY_AGGRO1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO1);
                break;
            case 1:
                DoYell(SAY_AGGRO2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO2);
                break;
            case 2:
                DoYell(SAY_AGGRO3, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_AGGRO3);
                break;
        }

        if( pInstance )
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
        }
    }

    void JustSummoned(Creature *summoned)
    {
        if( summoned->GetEntry() == ENTRY_VOID_TRAVELER )
        {
            summoned->GetMotionMaster()->MoveChase(m_creature);
            summoned->SetSpeed(MOVE_WALK,0.8,true);
        }

        if( summoned->GetEntry() == ENTRY_VOID_PORTAL )
            summoned->CastSpell(summoned,SPELL_VOID_PORTAL_VISUAL,true);
    }

    void JustDied(Unit *victim)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);

        if( pInstance )
            pInstance->SetData(DATA_GRANDMASTERVORPILEVENT, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( Teleport )
        {
            if( Teleport_Timer <= diff )
            {
                m_creature->Relocate(LOCX,LOCY,LOCZ);
                m_creature->SendMonsterMove(LOCX,LOCY,LOCZ,0,true,0);

                float ranX = LOCX;
                float ranY = LOCY;
                float ranZ = LOCZ;

                std::list<HostilReference *> t_list = m_creature->getThreatManager().getThreatList();
                for( std::list<HostilReference *>::iterator itr = t_list.begin(); itr!= t_list.end(); ++itr )
                {
                    Unit* target = Unit::GetUnit(*m_creature, (*itr)->getUnitGuid());
                    if( target && target->GetTypeId() == TYPEID_PLAYER )
                    {
                        target->GetRandomPoint(LOCX,LOCY,LOCZ,3.0,ranX,ranY,ranZ);
                        DoTeleportPlayer(target,ranX,ranY,ranZ,m_creature->GetAngle(m_creature->GetPositionX(),m_creature->GetPositionY()));
                    }
                }
                Teleport = false;

                if( HeroicMode ) DoCast(m_creature->getVictim(), H_SPELL_RAIN_OF_FIRE);
                else DoCast(m_creature->getVictim(), SPELL_RAIN_OF_FIRE);

                Teleport_Timer = 1000;
            }else Teleport_Timer -= diff;
        }

        if( ShadowBoltVolley_Timer < diff )
        {
            DoCast(m_creature->getVictim(), SPELL_SHADOW_BOLT_VOLLEY);
            ShadowBoltVolley_Timer = 30000;
        }else ShadowBoltVolley_Timer -= diff;

        if( DrawShadows_Timer < diff )
        {
            DoCast(m_creature,SPELL_DRAW_SHADOWS);
            DrawShadows_Timer = 35000;
            Teleport = true;
        }else DrawShadows_Timer -= diff;

        if( VoidTraveler_Timer < diff )
        {
            DoYell(SAY_HELP, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature, SOUND_HELP);

            switch(rand()%5)
            {
                case 0:
                    DoCast(m_creature,SPELL_SUMMON_VOIDWALKER_A,true);
                    break;
                case 1:
                    DoCast(m_creature,SPELL_SUMMON_VOIDWALKER_B,true);
                    break;
                case 2:
                    DoCast(m_creature,SPELL_SUMMON_VOIDWALKER_C,true);
                    break;
                case 3:
                    DoCast(m_creature,SPELL_SUMMON_VOIDWALKER_D,true);
                    break;
                case 4:
                    DoCast(m_creature,SPELL_SUMMON_VOIDWALKER_E,true);
                    break;
            }
            //faster rate when below (X) health?
            VoidTraveler_Timer = 35000;
        }else VoidTraveler_Timer -= diff;

        if( HeroicMode )
        {
            if( Banish_Timer < diff )
            {
                if( Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 1) )
                    DoCast(target,H_SPELL_BANISH);
                Banish_Timer = 35000;
            }else Banish_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_grandmaster_vorpil(Creature *_Creature)
{
    return new boss_grandmaster_vorpilAI (_Creature);
}

void AddSC_boss_grandmaster_vorpil()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_grandmaster_vorpil";
    newscript->GetAI = GetAI_boss_grandmaster_vorpil;
    m_scripts[nrscripts++] = newscript;
}
