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
SDName: Boss_Eredar_Twins
SD%Complete: 100
SDComment:
EndScriptData */

#include "precompiled.h"
#include "def_sunwell_plateau.h"

//Intro
#define YELL_INTRO_SAC_1                "Misery..."
#define YELL_INTRO_ALY_2                "Depravity..."
#define YELL_INTRO_SAC_3                "Confusion..."
#define YELL_INTRO_ALY_4                "Hatred..."
#define YELL_INTRO_SAC_5                "Mistrust..."
#define YELL_INTRO_ALY_6                "Chaos..."
#define YELL_INTRO_SAC_7                "These are the hallmarks..."
#define YELL_INTRO_ALY_8                "These are the pillars..."

// Lady Sacrolash
#define LADY_SACROLASH                  25165

#define SPELL_DARK_TOUCHED              45347
#define SPELL_SHADOW_BLADES             45248//10 secs
#define SPELL_DARK_STRIKE               45271
#define SPELL_SHADOW_NOVA               45329//30-35 secs
#define SPELL_CONFOUNDING_BLOW          45256//25 secs

#define MOB_SHADOW_IMAGE                25214
#define SPELL_SHADOW_FURY               45270
#define SPELL_IMAGE_VISUAL              45263

#define SOUND_INTRO                     12484
#define YELL_SHADOW_NOVA                "Shadow to the aid of fire!" //only if Alythess is not dead
#define SOUND_SHADOW_NOVA               12485
#define YELL_SISTER_ALYTHESS_DEAD       "Alythess! Your fire burns within me!"
#define SOUND_SISTER_ALYTHESS_DEAD      12488
#define YELL_SAC_KILL_1                 "Shadow engulf."
#define SOUND_SAC_KILL_1                12486
#define YELL_SAC_KILL_2                 "Ee-nok Kryul!"
#define SOUND_SAC_KILL_2                12487
#define SAY_SAC_DEAD                    "I... fade."
#define YELL_ENRAGE                     "Time is a luxury you no longer possess!"

//enrage 6 minutes
#define SPELL_ENRAGE                    46587
//empower after sister is death
#define SPELL_EMPOWER                   45366

//debuff prevents touched spell for 3 secounds
#define SPELL_DARK_FLAME                45345

//Grand Warlock Alythess
// Don't move only spamm spells ...
#define GRAND_WARLOCK_ALYTHESS          25166

#define SPELL_PYROGENICS                45230//15secs
#define SPELL_FLAME_TOUCHED             45348
#define SPELL_CONFLAGRATION             45342//30-35 secs
#define SPELL_BLAZE                     45235//on main target every 3 secs
#define SPELL_FLAME_SEAR                46771
#define SPELL_BLAZE_SUMMON              45236 //187366 GO
#define SPELL_BLAZE_BURN                45246

#define YELL_CANFLAGRATION              "Fire to the aid of shadow!" //only if Sacrolash is not dead
#define SOUND_CANFLAGRATION             12489
#define YELL_SISTER_SACROLASH_DEAD      "Sacrolash!"
#define SOUND_SISTER_SACROLASH_DEAD     12492
#define YELL_ALY_KILL_1                 "Fire consume."
#define SOUND_ALY_KILL_1                12490
#define YELL_ALY_KILL_2                 "Ed-ir Halach!"
#define SOUND_ALY_KILL_2                12491
#define YELL_ALY_DEAD                   "De-ek Anur!"
#define SOUND_ALY_DEAD                  12494
#define YELL_BERSERK                    "Your luck has run its curse!"
#define SOUND_BERSERK                   12493


struct TRINITY_DLL_DECL boss_sacrolashAI : public ScriptedAI
{
    boss_sacrolashAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
    }

    ScriptedInstance *pInstance;
    bool InCombat;
    bool sisterdeath;

    uint32 shadowblades_timer;
    uint32 shadownova_timer;
    uint32 confoundingblow_timer;
    uint32 shadowimage_timer;

    uint32 conflagration_timer;


    uint32 enrage_timer;

    void Reset()
    {
        InCombat = false;
        if(pInstance)
        {
            Unit* Temp =  Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_ALYTHESS));
            if (Temp)
                if (Temp->isDead())
                {
                    ((Creature*)Temp)->Respawn();
                }else
                {
                    if(Temp->getVictim())
                    {
                        m_creature->getThreatManager().addThreat(Temp->getVictim(),0.0f);
                        InCombat = true;
                    }
                }
        }

        if(!InCombat)
        {
            shadowblades_timer = 10000;
            shadownova_timer = 30000;
            confoundingblow_timer = 25000;
            shadowimage_timer = 20000;
            conflagration_timer = 30000;
            sisterdeath = false;

            enrage_timer = 360000;
        }

    }
    void Aggro(Unit *who)
    {
        DoZoneInCombat();
        if(pInstance)
        {
            Unit* Temp =  Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_ALYTHESS));
            if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                ((Creature*)Temp)->AI()->AttackStart(who);
        }
    }

    void KilledUnit(Unit *victim)
    {
        if(rand()%4 == 0)
        {
            switch (rand()%2)
            {
            case 0:
                DoPlaySoundToSet(m_creature,SOUND_SAC_KILL_1);
                DoYell(YELL_SAC_KILL_1 ,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature,SOUND_SAC_KILL_2);
                DoYell(YELL_SAC_KILL_2 ,LANG_UNIVERSAL,NULL);
                break;
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        // only if ALY death
        if (sisterdeath)
        {
            DoYell(SAY_SAC_DEAD ,LANG_UNIVERSAL,NULL);
        }
        else
        {
            m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }
    }

    void SpellHitTarget(Unit* target,const SpellEntry* spell)
    {
        switch(spell->Id)
        {
        case SPELL_SHADOW_BLADES:
        case SPELL_SHADOW_NOVA:
        case SPELL_CONFOUNDING_BLOW:
        case SPELL_SHADOW_FURY:
            HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
            break;
        case SPELL_CONFLAGRATION:
            HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
            break;
        }
    }

    void HandleTouchedSpells(Unit* target, uint32 TouchedType)
    {
        switch(TouchedType)
        {
        case SPELL_FLAME_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME))
            {
                if(target->HasAura(SPELL_DARK_TOUCHED))
                {
                    target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                    target->CastSpell(target,SPELL_DARK_FLAME,true);
                }else
                {
                    target->CastSpell(target,SPELL_FLAME_TOUCHED,true);
                }
            }
            break;
        case SPELL_DARK_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME))
            {
                if(target->HasAura(SPELL_FLAME_TOUCHED))
                {
                    target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                    target->CastSpell(target,SPELL_DARK_FLAME,true);
                }else
                {
                    target->CastSpell(target,SPELL_DARK_TOUCHED,true);
                }
            }
            break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!sisterdeath)
        {
            if (pInstance)
            {
                Unit* Temp = NULL;
                Temp = Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_ALYTHESS));
                if (Temp && Temp->isDead())
                {
                    DoYell(YELL_SISTER_ALYTHESS_DEAD ,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature,SOUND_SISTER_ALYTHESS_DEAD);
                    sisterdeath = true;

                    m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                    DoCast(m_creature,SPELL_EMPOWER);
                }
            }
        }

        if (!UpdateVictim())
            return;

        if(sisterdeath)
        {
            if (conflagration_timer < diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    DoCast(target,SPELL_CONFLAGRATION);
                    conflagration_timer = 30000+(rand()%5000);
                }
            }else conflagration_timer -= diff;
        }
        else
        {
            if(shadownova_timer < diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    DoCast(target,SPELL_SHADOW_NOVA);

                    if(!sisterdeath)
                    {
                        m_creature->MonsterTextEmote("directs Shadow Nova at $N",target->GetGUID(),true);
                        DoPlaySoundToSet(m_creature,SOUND_SHADOW_NOVA);
                        DoYell(YELL_SHADOW_NOVA,LANG_UNIVERSAL,NULL);
                    }

                    shadownova_timer= 30000+(rand()%5000);
                }
            }else shadownova_timer -=diff;
        }

        if(confoundingblow_timer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                DoCast(target,SPELL_CONFOUNDING_BLOW);
                confoundingblow_timer = 20000 + (rand()%5000);
            }
        }else confoundingblow_timer -=diff;

        if(shadowimage_timer < diff)
        {
            Unit* target = NULL;
            Creature* temp = NULL;
            for(int i = 0;i<3;i++)
            {
                target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                temp = DoSpawnCreature(MOB_SHADOW_IMAGE,0,0,0,0,TEMPSUMMON_CORPSE_DESPAWN,10000);
                temp->AI()->AttackStart(target);
            }
            shadowimage_timer = 20000;
        }else shadowimage_timer -=diff;

        if(shadowblades_timer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                DoCast(m_creature,SPELL_SHADOW_BLADES);
                shadowblades_timer = 10000;

            }
        }else shadowblades_timer -=diff;

        if (enrage_timer < diff)
        {
            m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
            DoYell(YELL_ENRAGE ,LANG_UNIVERSAL,NULL);
            DoCast(m_creature,SPELL_ENRAGE);
            enrage_timer = 300000;
        }else enrage_timer -= diff;

        if( m_creature->isAttackReady() && !m_creature->IsNonMeleeSpellCasted(false))
        {
            //If we are within range melee the target
            if( m_creature->IsWithinMeleeRange(m_creature->getVictim()))
            {
                HandleTouchedSpells(m_creature->getVictim(), SPELL_DARK_TOUCHED);
                m_creature->AttackerStateUpdate(m_creature->getVictim());
                m_creature->resetAttackTimer();
            }
        }
    }
};

CreatureAI* GetAI_boss_sacrolash(Creature *_Creature)
{
    return new boss_sacrolashAI (_Creature);
};

struct TRINITY_DLL_DECL boss_alythessAI : public Scripted_NoMovementAI
{
    boss_alythessAI(Creature *c) : Scripted_NoMovementAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());        IntroStepCounter = 10;
    }

    ScriptedInstance *pInstance;
    bool InCombat;
    bool sisterdeath;
    uint32 IntroStepCounter;
    uint32 IntroYell_Timer;

    uint32 conflagration_timer;
    uint32 blaze_timer;
    uint32 pyrogenics_timer;

    uint32 shadownova_timer;
    uint32 flamesear_timer;

    uint32 enrage_timer;

    void Reset()
    {
        InCombat = false;
        if(pInstance)
        {
            Unit* Temp =  Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_SACROLASH));
            if (Temp)
                if (Temp->isDead())
                {
                    ((Creature*)Temp)->Respawn();
                }else
                {
                    if(Temp->getVictim())
                    {
                        m_creature->getThreatManager().addThreat(Temp->getVictim(),0.0f);
                        InCombat = true;
                    }
                }
        }

        if(!InCombat)
        {
            conflagration_timer = 45000;
            blaze_timer = 100;
            pyrogenics_timer = 15000;
            shadownova_timer = 40000;
            sisterdeath = false;
            enrage_timer = 360000;
            flamesear_timer = 15000;
            IntroYell_Timer = 10000;
        }
    }
    void Aggro(Unit *who)
    {
        DoZoneInCombat();
        if(pInstance)
        {
            Unit* Temp =  Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_SACROLASH));
            if (Temp && Temp->isAlive() && !(Temp->getVictim()))
                ((Creature*)Temp)->AI()->AttackStart(who);
        }
    }

    void AttackStart(Unit *who)
    {
        if (!InCombat)
        {
            Scripted_NoMovementAI::AttackStart(who);
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || m_creature->getVictim())
            return;

        if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(m_creature) && m_creature->IsHostileTo(who))
        {

            float attackRadius = m_creature->GetAttackDistance(who);
            if (m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->GetDistanceZ(who) <= CREATURE_Z_ATTACK_RANGE && m_creature->IsWithinLOSInMap(who))
            {
                if (!InCombat)
                {
                    DoStartNoMovement(who);
                    Aggro(who);
                    InCombat = true;
                }
            }
        }
        else if (IntroStepCounter == 10 && m_creature->IsWithinLOSInMap(who)&& m_creature->IsWithinDistInMap(who, 30) )
        {
            IntroStepCounter = 0;
        }
    }

    void KilledUnit(Unit *victim)
    {
        if(rand()%4 == 0)
        {
            switch (rand()%2)
            {
            case 0:
                DoPlaySoundToSet(m_creature,SOUND_ALY_KILL_1);
                DoYell(YELL_ALY_KILL_1 ,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature,SOUND_ALY_KILL_2);
                DoYell(YELL_ALY_KILL_2 ,LANG_UNIVERSAL,NULL);
                break;
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        if (sisterdeath)
        {
            DoYell(YELL_ALY_DEAD ,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature,SOUND_ALY_DEAD);
        }
        else
        {
            m_creature->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
        }
    }

    void SpellHitTarget(Unit* target,const SpellEntry* spell)
    {
        switch(spell->Id)
        {

        case SPELL_BLAZE:
            target->CastSpell(target,SPELL_BLAZE_SUMMON,true);
        case SPELL_CONFLAGRATION:
        case SPELL_FLAME_SEAR:
            HandleTouchedSpells(target, SPELL_FLAME_TOUCHED);
            break;
        case SPELL_SHADOW_NOVA:
            HandleTouchedSpells(target, SPELL_DARK_TOUCHED);
            break;
        }
    }

    void HandleTouchedSpells(Unit* target, uint32 TouchedType)
    {
        switch(TouchedType)
        {
        case SPELL_FLAME_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME))
            {
                if(target->HasAura(SPELL_DARK_TOUCHED))
                {
                    target->RemoveAurasDueToSpell(SPELL_DARK_TOUCHED);
                    target->CastSpell(target,SPELL_DARK_FLAME,true);
                }else
                {
                    target->CastSpell(target,SPELL_FLAME_TOUCHED,true);
                }
            }
            break;
        case SPELL_DARK_TOUCHED:
            if(!target->HasAura(SPELL_DARK_FLAME))
            {
                if(target->HasAura(SPELL_FLAME_TOUCHED))
                {
                    target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                    target->CastSpell(target,SPELL_DARK_FLAME,true);
                }else
                {
                    target->CastSpell(target,SPELL_DARK_TOUCHED,true);
                }
            }
            break;
        }
    }

    uint32 IntroStep(uint32 step)
    {
        Creature* Sacrolash = Unit::GetCreature((*m_creature),pInstance->GetData64(DATA_SACROLASH));
        switch (step)
        {
        case 0: DoPlaySoundToSet(m_creature,SOUND_INTRO); return 0;
        case 1:
            if(Sacrolash)
                Sacrolash->MonsterYell(YELL_INTRO_SAC_1, LANG_UNIVERSAL,NULL);
            return 1000;
        case 2:
            m_creature->MonsterYell(YELL_INTRO_ALY_2, LANG_UNIVERSAL,NULL);
            return 1000;
        case 3:
            if(Sacrolash)
                Sacrolash->MonsterYell(YELL_INTRO_SAC_3, LANG_UNIVERSAL,NULL);
            return 2000;
        case 4:
            m_creature->MonsterYell(YELL_INTRO_ALY_4, LANG_UNIVERSAL,NULL);
            return 1000;
        case 5:
            if(Sacrolash)
                Sacrolash->MonsterYell(YELL_INTRO_SAC_5, LANG_UNIVERSAL,NULL);
            return 2000;
        case 6:
            m_creature->MonsterYell(YELL_INTRO_ALY_6, LANG_UNIVERSAL,NULL);
            return 1000;
        case 7:
            if(Sacrolash)
                Sacrolash->MonsterYell(YELL_INTRO_SAC_7, LANG_UNIVERSAL,NULL);
            return 3000;
        case 8:
            m_creature->MonsterYell(YELL_INTRO_ALY_8, LANG_UNIVERSAL,NULL);
            return 900000;
        }
        return 10000;
    }

    void UpdateAI(const uint32 diff)
    {
        if(IntroStepCounter < 9)
        {
            if(IntroYell_Timer < diff)
            {
                IntroYell_Timer = IntroStep(IntroStepCounter++);
            }else IntroYell_Timer -= diff;
        }

        if(!sisterdeath)
        {
            if (pInstance)
            {
                Unit* Temp = NULL;
                Temp = Unit::GetUnit((*m_creature),pInstance->GetData64(DATA_SACROLASH));
                if (Temp && Temp->isDead())
                {
                    DoYell(YELL_SISTER_SACROLASH_DEAD ,LANG_UNIVERSAL,NULL);
                    DoPlaySoundToSet(m_creature,SOUND_SISTER_SACROLASH_DEAD);
                    sisterdeath = true;

                    m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                    DoCast(m_creature,SPELL_EMPOWER);
                }
            }
        }

        if (!UpdateVictim())
            return;

        if(sisterdeath)
        {
            if(shadownova_timer < diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    DoCast(target,SPELL_SHADOW_NOVA);
                    shadownova_timer= 30000+(rand()%5000);
                }
            }else shadownova_timer -=diff;
        }
        else
        {
            if (conflagration_timer < diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                {
                    m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
                    Unit* target = NULL;
                    target = SelectUnit(SELECT_TARGET_RANDOM, 0);
                    DoCast(target,SPELL_CONFLAGRATION);
                    conflagration_timer = 30000+(rand()%5000);

                    if(!sisterdeath)
                    {
                        m_creature->MonsterTextEmote("directs Conflagration at $N",target->GetGUID(),true);
                        DoPlaySoundToSet(m_creature,SOUND_CANFLAGRATION);
                        DoYell(YELL_CANFLAGRATION,LANG_UNIVERSAL,NULL);
                    }

                    blaze_timer = 4000;
                }
            }else conflagration_timer -= diff;
        }

        if (flamesear_timer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                DoCast(m_creature,SPELL_FLAME_SEAR);
                flamesear_timer = 15000;
            }
        }else flamesear_timer -=diff;

        if (pyrogenics_timer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                DoCast(m_creature,SPELL_PYROGENICS,true);
                pyrogenics_timer = 15000;
            }
        }else pyrogenics_timer -= diff;

        if (blaze_timer < diff)
        {
            if (!m_creature->IsNonMeleeSpellCasted(false))
            {
                DoCast(m_creature->getVictim(),SPELL_BLAZE);
                blaze_timer = 3800;
            }
        }else blaze_timer -= diff;

        if (enrage_timer < diff)
        {
            m_creature->InterruptSpell(CURRENT_GENERIC_SPELL);
            DoPlaySoundToSet(m_creature,SOUND_BERSERK);
            DoYell(YELL_BERSERK ,LANG_UNIVERSAL,NULL);
            DoCast(m_creature,SPELL_ENRAGE);
            enrage_timer = 300000;
        }else enrage_timer -= diff;
    }
};

CreatureAI* GetAI_boss_alythess(Creature *_Creature)
{
    return new boss_alythessAI (_Creature);
};

struct TRINITY_DLL_DECL mob_shadow_imageAI : public ScriptedAI
{
    mob_shadow_imageAI(Creature *c) : ScriptedAI(c) {}

    uint32 shadowfury_timer;
    uint32 kill_timer;
    uint32 darkstrike_timer;

    void Reset()
    {
        shadowfury_timer = 5000 + (rand()%15000);
        darkstrike_timer = 3000;
        kill_timer = 15000;

    }

    void Aggro(Unit *who){}

    void SpellHitTarget(Unit* target,const SpellEntry* spell)
    {
        switch(spell->Id)
        {

        case SPELL_SHADOW_FURY:
        case SPELL_DARK_STRIKE:
            if(!target->HasAura(SPELL_DARK_FLAME))
            {
                if(target->HasAura(SPELL_FLAME_TOUCHED))
                {
                    target->RemoveAurasDueToSpell(SPELL_FLAME_TOUCHED);
                    target->CastSpell(target,SPELL_DARK_FLAME,true);
                }else
                {
                    target->CastSpell(target,SPELL_DARK_TOUCHED,true);
                }
            }
            break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->HasAura(SPELL_IMAGE_VISUAL))
            DoCast(m_creature,SPELL_IMAGE_VISUAL);

        if(kill_timer < diff)
        {
            m_creature->DealDamage(m_creature, m_creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            kill_timer = 9999999;
        }else kill_timer -=diff;

        if (!UpdateVictim())
            return;

        if(shadowfury_timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOW_FURY);
            shadowfury_timer = 10000;
        }else shadowfury_timer -=diff;

        if(darkstrike_timer < diff)
        {
            if(!m_creature->IsNonMeleeSpellCasted(false))
            {
                //If we are within range melee the target
                if( m_creature->IsWithinMeleeRange(m_creature->getVictim()))
                {
                    DoCast(m_creature->getVictim(),SPELL_DARK_STRIKE);
                }
            }
            darkstrike_timer = 3000;
        }
        else darkstrike_timer -= diff;
    }
};

CreatureAI* GetAI_mob_shadow_image(Creature *_Creature)
{
    return new mob_shadow_imageAI (_Creature);
};

void AddSC_boss_eredar_twins()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_sacrolash";
    newscript->GetAI = &GetAI_boss_sacrolash;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_alythess";
    newscript->GetAI = &GetAI_boss_alythess;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_shadow_image";
    newscript->GetAI = &GetAI_mob_shadow_image;
    newscript->RegisterSelf();
}

