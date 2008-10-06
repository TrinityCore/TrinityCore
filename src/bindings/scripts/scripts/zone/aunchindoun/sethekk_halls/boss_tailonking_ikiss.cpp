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
SDName: Boss_Talon_King_Ikiss
SD%Complete: 80
SDComment: Heroic supported. Some details missing, but most are spell related.
SDCategory: Auchindoun, Sethekk Halls
EndScriptData */

#include "precompiled.h"
#include "def_sethekk_halls.h"

#define SAY_INTRO                   "<squawk>..Trinkets yes pretty Trinkets..<squawk>..power, great power.<squawk>..power in Trinkets..<squawk>"
#define SOUND_INTRO                 10557

#define SAY_AGGRO_1                 "You make war on Ikiss?..<squawk>"
#define SOUND_AGGRO_1               10554
#define SAY_AGGRO_2                 "Ikiss cut you pretty..<squawk>..slice you. Yes!"
#define SOUND_AGGRO_2               10555
#define SAY_AGGRO_3                 "No escape for..<squawk>..for you"
#define SOUND_AGGRO_3               10556

#define SAY_SLAY_1                  "You die..<squawk>..stay away from Trinkets"
#define SOUND_SLAY_1                10558
#define SAY_SLAY_2                  "<squawk>"
#define SOUND_SLAY_2                10559

#define SAY_DEATH                   "Ikiss will not..<squawk>..die"
#define SOUND_DEATH                 10560

#define EMOTE_ARCANE_EXP            "begins to channel arcane energy..."

#define SPELL_BLINK                 38194
#define SPELL_BLINK_TELEPORT        38203
#define SPELL_MANA_SHIELD           38151
#define SPELL_ARCANE_BUBBLE         9438
#define H_SPELL_SLOW                35032

#define SPELL_POLYMORPH             38245
#define H_SPELL_POLYMORPH           43309

#define SPELL_ARCANE_VOLLEY         35059
#define H_SPELL_ARCANE_VOLLEY       40424

#define SPELL_ARCANE_EXPLOSION      38197
#define H_SPELL_ARCANE_EXPLOSION    40425

struct MANGOS_DLL_DECL boss_talon_king_ikissAI : public ScriptedAI
{
    boss_talon_king_ikissAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    bool HeroicMode;

    uint32 ArcaneVolley_Timer;
    uint32 Sheep_Timer;
    uint32 Blink_Timer;
    uint32 Slow_Timer;

    bool ManaShield;
    bool Blink;
    bool Intro;

    void Reset()
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();

        ArcaneVolley_Timer = 5000;
        Sheep_Timer = 8000;
        Blink_Timer = 35000;
        Slow_Timer = 15000+rand()%15000;
        Blink = false;
        Intro = false;
        ManaShield = false;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
        {
            if(!Intro && m_creature->IsWithinDistInMap(who, 100))
            {
                Intro = true;
                DoYell(SAY_INTRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_INTRO);
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
                    InCombat = true;
                    Aggro(who);
                }
            }
        }
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

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);

        if( pInstance )
            pInstance->SetData(DATA_IKISSDOOREVENT, DONE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY_1, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY_1);
                break;

            case 1:
                DoYell(SAY_SLAY_2, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_SLAY_2);
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( Blink )
        {
            DoCast(m_creature,HeroicMode ? H_SPELL_ARCANE_EXPLOSION : SPELL_ARCANE_EXPLOSION);
            m_creature->CastSpell(m_creature,SPELL_ARCANE_BUBBLE,true);
            Blink = false;
        }

        if( ArcaneVolley_Timer < diff )
        {
            DoCast(m_creature,HeroicMode ? H_SPELL_ARCANE_VOLLEY : SPELL_ARCANE_VOLLEY);
            ArcaneVolley_Timer = 10000+rand()%5000;
        }else ArcaneVolley_Timer -= diff;

        if( Sheep_Timer < diff )
        {
            //second top aggro target in normal, random target in heroic correct?
            Unit *target = NULL;
            if( HeroicMode ? target = SelectUnit(SELECT_TARGET_RANDOM,0) : target = SelectUnit(SELECT_TARGET_TOPAGGRO,1) )
                DoCast(target,HeroicMode ? H_SPELL_POLYMORPH : SPELL_POLYMORPH);
            Sheep_Timer = 15000+rand()%2500;
        }else Sheep_Timer -= diff;

        //may not be correct time to cast
        if( !ManaShield && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 20) )
        {
            DoCast(m_creature,SPELL_MANA_SHIELD);
            ManaShield = true;
        }

        if( HeroicMode )
        {
            if( Slow_Timer < diff )
            {
                DoCast(m_creature,H_SPELL_SLOW);
                Slow_Timer = 15000+rand()%25000;
            }else Slow_Timer -= diff;
        }

        if( Blink_Timer < diff )
        {
            DoTextEmote(EMOTE_ARCANE_EXP,NULL,true);

            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            {
                if( m_creature->IsNonMeleeSpellCasted(false) )
                    m_creature->InterruptNonMeleeSpells(false);

                //Spell doesn't work, but we use for visual effect at least
                DoCast(target,SPELL_BLINK);

                float X = target->GetPositionX();
                float Y = target->GetPositionY();
                float Z = target->GetPositionZ();

                m_creature->Relocate(X,Y,Z);
                m_creature->SendMonsterMove(X, Y, Z, 0, 0, 0);

                DoCast(target,SPELL_BLINK_TELEPORT);
                Blink = true;
            }
            Blink_Timer = 35000+rand()%5000;
        }else Blink_Timer -= diff;

        if( !Blink )
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_talon_king_ikiss(Creature *_Creature)
{
    return new boss_talon_king_ikissAI (_Creature);
}

void AddSC_boss_talon_king_ikiss()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_talon_king_ikiss";
    newscript->GetAI = GetAI_boss_talon_king_ikiss;
    m_scripts[nrscripts++] = newscript;
}
