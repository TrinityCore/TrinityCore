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
SDName: Boss_Temporus
SD%Complete: 100
SDComment:
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "precompiled.h"

#define SPELL_TAUNT           355
#define SPELL_HASTE           31458
#define SPELL_MORTAL_WOUND    28467
#define SPELL_REFLECT         23920                         //Not Implemented (Heroic mod)

#define SAY_ENTER             "Why do you persist? Surely you can see the futility of it all. It is not too late! You may still leave with your lives ..."
#define SAY_AGGRO             "So be it ... you have been warned."
#define SAY_BANISH            "Time... sands of time is run out for you."
#define SAY_SLAY1             "You should have left when you had the chance."
#define SAY_SLAY2             "Your days are done."
#define SAY_DEATH             "My death means ... little."

#define SOUND_ENTER           10442
#define SOUND_AGGRO           10444
#define SOUND_BANISH          10443
#define SOUND_SLAY1           10445
#define SOUND_SLAY2           10446
#define SOUND_DEATH           10447

struct TRINITY_DLL_DECL boss_temporusAI : public ScriptedAI
{
    boss_temporusAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Haste_Timer;
    uint32 SpellReflection_Timer;

    void Reset()
    {
        Haste_Timer = 20000;
        SpellReflection_Timer = 40000;
    }

    void Aggro(Unit *who)
    {
        DoYell(SAY_AGGRO,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_AGGRO);
    }

    void KilledUnit(Unit *victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoYell(SAY_SLAY1,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY1);
                break;
            case 1:
                DoYell(SAY_SLAY2,LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_SLAY2);
                break;
        }
    }

    void JustDied(Unit *victim)
    {
        DoYell(SAY_DEATH,LANG_UNIVERSAL,NULL);
        DoPlaySoundToSet(m_creature, SOUND_DEATH);
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        //Despawn Time Keeper
        if (who->GetTypeId() == TYPEID_UNIT)
        {
            if(((Creature*)who)->GetEntry() == 17918 && m_creature->IsWithinDistInMap(who,20))
            {
                //This is the wrong yell & sound for despawning time keepers!
                DoYell(SAY_ENTER, LANG_UNIVERSAL,NULL);
                DoPlaySoundToSet(m_creature, SOUND_ENTER);

                m_creature->DealDamage(who, who->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }
        }

        if (!m_creature->getVictim() && who->isTargetableForAttack() && who->isInAccessablePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {
            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who))
            {
                if(who->HasStealthAura())
                    who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                DoStartAttackAndMovement(who);
                if (!InCombat)
                {
                    DoYell(SAY_AGGRO, LANG_UNIVERSAL, NULL);
                    DoPlaySoundToSet(m_creature, SOUND_AGGRO);
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //Check if we have a current target
        if( m_creature->getVictim() && m_creature->isAlive())
        {

            //Attack Haste
            if (Haste_Timer < diff)
            {
                DoCast(m_creature, SPELL_HASTE);
                Haste_Timer = 20000+rand()%5000;
            }else Haste_Timer -= diff;

            //Spell Reflection
            if (SpellReflection_Timer < diff)
            {
                DoYell(SAY_BANISH, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_BANISH);

                DoCast(m_creature, SPELL_REFLECT);
                SpellReflection_Timer = 40000+rand()%10000;
            }else SpellReflection_Timer -= diff;

            DoMeleeAttackIfReady();

        }
    }
};

CreatureAI* GetAI_boss_temporus(Creature *_Creature)
{
    return new boss_temporusAI (_Creature);
}

void AddSC_boss_temporus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_temporus";
    newscript->GetAI = GetAI_boss_temporus;
    m_scripts[nrscripts++] = newscript;
}
