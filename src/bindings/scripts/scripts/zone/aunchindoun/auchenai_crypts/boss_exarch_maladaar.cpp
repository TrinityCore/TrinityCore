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
SDName: Boss_Exarch_Maladaar
SD%Complete: 95
SDComment: Most of event implemented, some adjustments to timers remain and possibly make some better code for switching his dark side in to better "images" of player.
SDCategory: Auchindoun, Auchenai Crypts
EndScriptData */

/* ContentData
mob_stolen_soul
boss_exarch_maladaar
mob_avatar_of_martyred
EndContentData */

#include "precompiled.h"

#define SPELL_MOONFIRE          37328
#define SPELL_FIREBALL          37329
#define SPELL_MIND_FLAY         37330
#define SPELL_HEMORRHAGE        37331
#define SPELL_FROSTSHOCK        37332
#define SPELL_CURSE_OF_AGONY    37334
#define SPELL_MORTAL_STRIKE     37335
#define SPELL_FREEZING_TRAP     37368
#define SPELL_HAMMER_OF_JUSTICE 37369

struct TRINITY_DLL_DECL mob_stolen_soulAI : public ScriptedAI
{
    mob_stolen_soulAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint8 myClass;
    uint32 Class_Timer;

    void Reset()
    {
        Class_Timer = 1000;
    }

    void Aggro(Unit *who)
        { }

    void SetMyClass(uint8 myclass)
    {
        myClass = myclass;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( Class_Timer < diff )
        {
            switch( myClass )
            {
                case CLASS_WARRIOR:
                    DoCast(m_creature->getVictim(), SPELL_MORTAL_STRIKE);
                    Class_Timer = 6000;
                    break;
                case CLASS_PALADIN:
                    DoCast(m_creature->getVictim(), SPELL_HAMMER_OF_JUSTICE);
                    Class_Timer = 6000;
                    break;
                case CLASS_HUNTER:
                    DoCast(m_creature->getVictim(), SPELL_FREEZING_TRAP);
                    Class_Timer = 20000;
                    break;
                case CLASS_ROGUE:
                    DoCast(m_creature->getVictim(), SPELL_HEMORRHAGE);
                    Class_Timer = 10000;
                    break;
                case CLASS_PRIEST:
                    DoCast(m_creature->getVictim(), SPELL_MIND_FLAY);
                    Class_Timer = 5000;
                    break;
                case CLASS_SHAMAN:
                    DoCast(m_creature->getVictim(), SPELL_FROSTSHOCK);
                    Class_Timer = 8000;
                    break;
                case CLASS_MAGE:
                    DoCast(m_creature->getVictim(), SPELL_FIREBALL);
                    Class_Timer = 5000;
                    break;
                case CLASS_WARLOCK:
                    DoCast(m_creature->getVictim(), SPELL_CURSE_OF_AGONY);
                    Class_Timer = 20000;
                    break;
                case CLASS_DRUID:
                    DoCast(m_creature->getVictim(), SPELL_MOONFIRE);
                    Class_Timer = 10000;
                    break;
            }
        }else Class_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_stolen_soul(Creature *_Creature)
{
    return new mob_stolen_soulAI (_Creature);
}

#define SAY_INTRO                   "You have defiled the resting place of our ancestors. For this offense, there can be but one punishment. It is fitting that you have come to a place of the dead... for you will soon be joining them."
#define SOUND_INTRO                 10509
#define SAY_SUMMON                  "Rise my fallen brothers. Take form and fight!"
#define SOUND_SUMMON                10512

#define SAY_AGGRO_1                 "You will pay with your life!"
#define SOUND_AGGRO_1               10513
#define SAY_AGGRO_2                 "There's no turning back now!"
#define SOUND_AGGRO_2               10514
#define SAY_AGGRO_3                 "Serve your penitence!"
#define SOUND_AGGRO_3               10515

#define SAY_ROAR                    "Let your mind be clouded."
#define SOUND_ROAR                  10510
#define SAY_SOUL_CLEAVE             "Stare into the darkness of your soul."
#define SOUND_SOUL_CLEAVE           10511

#define SAY_SLAY_1                  "These walls will be your doom."
#define SOUND_SLAY_1                10516
#define SAY_SLAY_2                  "<laugh> Now, you'll stay for eternity!"
#define SOUND_SLAY_2                10517

#define SAY_DEATH                   "This is... where.. I belong..."
#define SOUND_DEATH                 10518

#define SPELL_RIBBON_OF_SOULS       32422
#define SPELL_SOUL_SCREAM           32421

#define SPELL_STOLEN_SOUL           32346
#define SPELL_STOLEN_SOUL_VISUAL    32395

#define SPELL_SUMMON_AVATAR         32424

#define ENTRY_STOLEN_SOUL           18441

struct TRINITY_DLL_DECL boss_exarch_maladaarAI : public ScriptedAI
{
    boss_exarch_maladaarAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 soulmodel;
    uint64 soulholder;
    uint8 soulclass;

    uint32 Fear_timer;
    uint32 Ribbon_of_Souls_timer;
    uint32 StolenSoul_Timer;

    bool HasTaunted;
    bool Avatar_summoned;

    void Reset()
    {
        soulmodel = 0;
        soulholder = 0;
        soulclass = 0;

        Fear_timer = 20000;
        Ribbon_of_Souls_timer = 5000;
        StolenSoul_Timer = 30000;

        HasTaunted = false;
        Avatar_summoned = false;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
        {
            if( !HasTaunted && m_creature->IsWithinDistInMap(who, 150.0) )
            {
                DoYell(SAY_INTRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature,SOUND_INTRO);
                HasTaunted = true;
            }

            if (!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE)
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
            {
                who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
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

    void JustSummoned(Creature *summoned)
    {
        if( summoned->GetEntry() == ENTRY_STOLEN_SOUL )
        {
            //SPELL_STOLEN_SOUL_VISUAL has shapeshift effect, but not implemented feature in Trinity for this spell.
            summoned->SetDisplayId(soulmodel);
            summoned->CastSpell(summoned,SPELL_STOLEN_SOUL_VISUAL,false);

            if( Unit *target = Unit::GetUnit(*m_creature,soulholder) )
                summoned->AI()->AttackStart(target);

            ((mob_stolen_soulAI*)summoned->AI())->SetMyClass(soulclass);
        }
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

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

    void JustDied(Unit* Killer)
    {
        DoYell(SAY_DEATH, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature,SOUND_DEATH);

        //When Exarch Maladar is defeated D'ore appear.
        DoSpawnCreature(19412,0,0,0,0, TEMPSUMMON_TIMED_DESPAWN, 600000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( !Avatar_summoned && ((m_creature->GetHealth()*100) / m_creature->GetMaxHealth() < 25) )
        {
            if( m_creature->IsNonMeleeSpellCasted(false) )
                m_creature->InterruptNonMeleeSpells(true);

            DoYell(SAY_SUMMON, LANG_UNIVERSAL, NULL);
            DoPlaySoundToSet(m_creature,SOUND_SUMMON);

            DoCast(m_creature, SPELL_SUMMON_AVATAR);
            Avatar_summoned = true;
            StolenSoul_Timer = 45000;
        }

        if( StolenSoul_Timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            {
                if( target->GetTypeId() == TYPEID_PLAYER )
                {
                    if( m_creature->IsNonMeleeSpellCasted(false) )
                        m_creature->InterruptNonMeleeSpells(true);

                    uint32 i = urand(1,2);
                    if( i == 1 )
                    {
                        DoYell(SAY_ROAR, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature,SOUND_ROAR);
                    }
                    else
                    {
                        DoYell(SAY_SOUL_CLEAVE, LANG_UNIVERSAL, NULL);
                        DoPlaySoundToSet(m_creature,SOUND_SOUL_CLEAVE);
                    }

                    soulmodel = target->GetDisplayId();
                    soulholder = target->GetGUID();
                    soulclass = target->getClass();

                    DoCast(target,SPELL_STOLEN_SOUL);
                    DoSpawnCreature(ENTRY_STOLEN_SOUL,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);

                    StolenSoul_Timer = 45000;
                } else StolenSoul_Timer = 1000;
            }
        }else StolenSoul_Timer -= diff;

        if( Ribbon_of_Souls_timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                DoCast(target,SPELL_RIBBON_OF_SOULS);

            Ribbon_of_Souls_timer = 5000 + (rand()%20 * 1000);
        }else Ribbon_of_Souls_timer -= diff;

        if( Fear_timer < diff )
        {
            DoCast(m_creature,SPELL_SOUL_SCREAM);
            Fear_timer = 25000 + rand()% 10000;
        }else Fear_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_exarch_maladaar(Creature *_Creature)
{
    return new boss_exarch_maladaarAI (_Creature);
}

#define SPELL_MORTAL_STRIKE         16856
#define SPELL_SUNDER_ARMOR          16145

struct TRINITY_DLL_DECL mob_avatar_of_martyredAI : public ScriptedAI
{
    mob_avatar_of_martyredAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 Mortal_Strike_timer;

    void Reset()
    {
        Mortal_Strike_timer = 10000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if(Mortal_Strike_timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_MORTAL_STRIKE);
            Mortal_Strike_timer = 10000 + rand()%20 * 1000;
        }else Mortal_Strike_timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_avatar_of_martyred(Creature *_Creature)
{
    return new mob_avatar_of_martyredAI (_Creature);
}

void AddSC_boss_exarch_maladaar()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_exarch_maladaar";
    newscript->GetAI = GetAI_boss_exarch_maladaar;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_avatar_of_martyred";
    newscript->GetAI = GetAI_mob_avatar_of_martyred;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_stolen_soul";
    newscript->GetAI = GetAI_mob_stolen_soul;
    m_scripts[nrscripts++] = newscript;
}
