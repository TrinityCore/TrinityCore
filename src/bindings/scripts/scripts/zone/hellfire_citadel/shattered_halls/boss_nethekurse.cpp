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
SDName: Boss_Grand_Warlock_Nethekurse
SD%Complete: 75
SDComment: encounter not fully complete. missing part where boss kill minions.
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_grand_warlock_nethekurse
mob_fel_orc_convert
mob_lesser_shadow_fissure
EndContentData */

#include "precompiled.h"
#include "def_shattered_halls.h"

struct Say
{
    const char* text;
    uint32 sound;
};

#define SAY_INTRO       "You wish to fight us all at once? This should be amusing!"
#define SOUND_INTRO     10262

static Say PeonAttacked[]=
{
    {"You can have that one. I no longer need him.", 10263},
    {"Yes, beat him mercilessly. His skull is a thick as an ogres.", 10264},
    {"Don't waste your time on that one. He's weak!", 10265},
    {"You want him? Very well, take him!", 10266},
};
static Say PeonDies[]=
{
    {"One pitiful wretch down. Go on, take another one.", 10267},
    {"Ahh, what a waste... Next!", 10268},
    {"I was going to kill him anyway!", 10269},
    {"Thank you for saving me the trouble! Now it's my turn to have some fun...", 10270},
};

#define SAY_TAUNT_1         "Beg for your pittyfull life!"
#define SOUND_TAUNT_1       10259
#define SAY_TAUNT_2         "Run covad, ruun!"
#define SOUND_TAUNT_2       10260
#define SAY_TAUNT_3         "Your pain amuses me."
#define SOUND_TAUNT_3       10261

#define SAY_AGGRO_1         "I'm already bored."
#define SOUND_AGGRO_1       10271
#define SAY_AGGRO_2         "Come on! ... Show me a real fight."
#define SOUND_AGGRO_2       10272
#define SAY_AGGRO_3         "I had more fun torturing the peons."
#define SOUND_AGGRO_3       10273

#define SAY_SLAY_1          "You Loose."
#define SOUND_SLAY_1        10274
#define SAY_SLAY_2          "Ohh! Just die."
#define SOUND_SLAY_2        10275

#define SAY_DIE             "What a ... a shame."
#define SOUND_DIE           10276

#define SPELL_DEATH_COIL            30500
#define SPELL_DARK_SPIN             30502                   // core bug spell attack caster :D
#define SPELL_SHADOW_FISSURE        30496                   // Summon the ShadowFissure NPC

#define SPELL_SHADOW_CLEAVE         30495
#define H_SPELL_SHADOW_SLAM         35953

#define SPELL_HEMORRHAGE            30478

#define SPELL_CONSUMPTION           30497
#define SPELL_TEMPORARY_VISUAL      39312                   // this is wrong, a temporary solution. spell consumption already has the purple visual, but doesn't display as it should

struct TRINITY_DLL_DECL boss_grand_warlock_nethekurseAI : public ScriptedAI
{
    boss_grand_warlock_nethekurseAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;

    bool HeroicMode;
    bool IntroOnce;
    bool IsIntroEvent;
    bool IsMainEvent;
    bool SpinOnce;
    //bool HasTaunted;
    bool Phase;

    uint32 PeonEngagedCount;
    uint32 PeonKilledCount;

    uint32 IntroEvent_Timer;
    uint32 DeathCoil_Timer;
    uint32 ShadowFissure_Timer;
    uint32 Cleave_Timer;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        HeroicMode = m_creature->GetMap()->IsHeroic();
        IsIntroEvent = false;
        IntroOnce = false;
        IsMainEvent = false;
        //HasTaunted = false;
        SpinOnce = false;
        Phase = false;

        PeonEngagedCount = 0;
        PeonKilledCount = 0;

        IntroEvent_Timer = 90000;                           //how long before getting bored and kills his minions?
        DeathCoil_Timer = 20000;
        ShadowFissure_Timer = 8000;
        Cleave_Timer = 5000;
    }

    void DoYellForPeonAggro()
    {
        if( PeonEngagedCount >= 4 )
            return;

        DoYell(PeonAttacked[PeonEngagedCount].text, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, PeonAttacked[PeonEngagedCount].sound);
        ++PeonEngagedCount;
    }

    void DoYellForPeonDeath()
    {
        if( PeonKilledCount >= 4 )
            return;

        DoYell(PeonDies[PeonKilledCount].text, LANG_UNIVERSAL, NULL);
        DoPlaySoundToSet(m_creature, PeonDies[PeonKilledCount].sound);
        ++PeonKilledCount;

        if( PeonKilledCount == 4 )
        {
            IsIntroEvent = false;
            IsMainEvent = true;
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    }

    void DoTauntPeons()
    {
        switch(rand()%3)
        {
            case 0:
                DoPlaySoundToSet(m_creature,SOUND_TAUNT_1);
                DoYell(SAY_TAUNT_1,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature,SOUND_TAUNT_2);
                DoYell(SAY_TAUNT_2,LANG_UNIVERSAL,NULL);
                break;
            case 2:
                DoPlaySoundToSet(m_creature,SOUND_TAUNT_3);
                DoYell(SAY_TAUNT_3,LANG_UNIVERSAL,NULL);
                break;
        }

        //TODO: kill the peons first
        IsIntroEvent = false;
        PeonEngagedCount = 4;
        PeonKilledCount = 4;
        IsMainEvent = true;
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void AttackStart(Unit* who)
    {
        if ( IsIntroEvent || !IsMainEvent )
            return;

        if( who->isTargetableForAttack() )
        {
            if( Phase ) DoStartAttackNoMovement(who);
            else DoStartAttackAndMovement(who);

            if( !InCombat )
            {
                InCombat = true;
                Aggro(who);
            }
        }
    }

    void MoveInLineOfSight(Unit *who)
    {
        if( !m_creature->getVictim() && who->isTargetableForAttack() && ( m_creature->IsHostileTo( who )) && who->isInAccessablePlaceFor(m_creature) )
        {
            if( !IntroOnce && m_creature->IsWithinDistInMap(who, 75) )
            {
                DoYell(SAY_INTRO, LANG_UNIVERSAL, NULL);
                DoPlaySoundToSet(m_creature, SOUND_INTRO);
                IntroOnce = true;
                IsIntroEvent = true;

                if( pInstance )
                    pInstance->SetData(TYPE_NETHEKURSE,IN_PROGRESS);
            }

            if(!m_creature->canFly() && m_creature->GetDistanceZ(who) > CREATURE_Z_ATTACK_RANGE )
                return;

            if( IsIntroEvent || !IsMainEvent )
                return;

            float attackRadius = m_creature->GetAttackDistance(who);
            if( m_creature->IsWithinDistInMap(who, attackRadius) && m_creature->IsWithinLOSInMap(who) )
            {
                if( Phase ) DoStartAttackNoMovement(who);
                else DoStartAttackAndMovement(who);

                who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);

                if( !InCombat )
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
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_1);
                DoYell(SAY_AGGRO_1,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_2);
                DoYell(SAY_AGGRO_2,LANG_UNIVERSAL,NULL);
                break;
            case 2:
                DoPlaySoundToSet(m_creature,SOUND_AGGRO_3);
                DoYell(SAY_AGGRO_3,LANG_UNIVERSAL,NULL);
                break;
        }
    }

    void JustSummoned(Creature *summoned)
    {
        summoned->setFaction(14);
        summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void KilledUnit(Unit* victim)
    {
        switch(rand()%2)
        {
            case 0:
                DoPlaySoundToSet(m_creature,SOUND_SLAY_1);
                DoYell(SAY_SLAY_1,LANG_UNIVERSAL,NULL);
                break;
            case 1:
                DoPlaySoundToSet(m_creature,SOUND_SLAY_2);
                DoYell(SAY_SLAY_2,LANG_UNIVERSAL,NULL);
                break;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoPlaySoundToSet(m_creature,SOUND_DIE);
        DoYell(SAY_DIE,LANG_UNIVERSAL,NULL);

        if( !pInstance )
            return;

        pInstance->SetData(TYPE_NETHEKURSE,DONE);

        if( pInstance->GetData64(DATA_NETHEKURSE_DOOR) )
        {
            if( GameObject *Door = GameObject::GetGameObject(*m_creature,pInstance->GetData64(DATA_NETHEKURSE_DOOR)) )
                Door->SetGoState(0);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( IsIntroEvent )
        {
            if( !pInstance )
                return;

            if( pInstance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS )
            {
                if( IntroEvent_Timer < diff )
                {
                    DoTauntPeons();
                }else IntroEvent_Timer -= diff;
            }
        }

        if( !m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( !IsMainEvent )
            return;

        if( Phase )
        {
            if( !SpinOnce )
            {
                DoCast(m_creature->getVictim(),SPELL_DARK_SPIN);
                SpinOnce = true;
            }

            if( Cleave_Timer < diff )
            {
                DoCast(m_creature->getVictim(),(HeroicMode ? H_SPELL_SHADOW_SLAM : SPELL_SHADOW_CLEAVE));
                Cleave_Timer = 6000+rand()%2500;
            }else Cleave_Timer -= diff;
        }
        else
        {
            if( ShadowFissure_Timer < diff )
            {
                if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                    DoCast(target,SPELL_SHADOW_FISSURE);
                ShadowFissure_Timer = 7500+rand()%7500;
            }else ShadowFissure_Timer -= diff;

            if( DeathCoil_Timer < diff )
            {
                if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
                    DoCast(target,SPELL_DEATH_COIL);
                DeathCoil_Timer = 15000+rand()%5000;
            }else DeathCoil_Timer -= diff;

            if( (m_creature->GetHealth()*100) / m_creature->GetMaxHealth() <= 20 )
                Phase = true;

            DoMeleeAttackIfReady();
        }
    }
};

struct TRINITY_DLL_DECL mob_fel_orc_convertAI : public ScriptedAI
{
    mob_fel_orc_convertAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        Reset();
    }

    ScriptedInstance* pInstance;
    uint32 Hemorrhage_Timer;

    void Reset()
    {
        m_creature->SetNoCallAssistence(true);              //we don't want any assistance (WE R HEROZ!)
        Hemorrhage_Timer = 3000;
    }

    void MoveInLineOfSight(Unit *who)
    {
        return;
    }

    void Aggro(Unit* who)
    {
        if( pInstance )
        {
            if( pInstance->GetData64(DATA_NETHEKURSE) )
            {
                Creature *pKurse = (Creature*)Unit::GetUnit(*m_creature,pInstance->GetData64(DATA_NETHEKURSE));
                if( pKurse )
                    ((boss_grand_warlock_nethekurseAI*)pKurse->AI())->DoYellForPeonAggro();
            }

            if( pInstance->GetData(TYPE_NETHEKURSE) == IN_PROGRESS )
                return;
            else pInstance->SetData(TYPE_NETHEKURSE,IN_PROGRESS);
        }
    }

    void JustDied(Unit* Killer)
    {
        if( pInstance )
        {
            if( pInstance->GetData64(DATA_NETHEKURSE) )
            {
                Creature *pKurse = (Creature*)Unit::GetUnit(*m_creature,pInstance->GetData64(DATA_NETHEKURSE));
                if( pKurse )
                    ((boss_grand_warlock_nethekurseAI*)pKurse->AI())->DoYellForPeonDeath();
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if( !m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( Hemorrhage_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_HEMORRHAGE);
            Hemorrhage_Timer = 15000;
        }else Hemorrhage_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

//NOTE: this creature are also summoned by other spells, for different creatures
struct TRINITY_DLL_DECL mob_lesser_shadow_fissureAI : public ScriptedAI
{
    mob_lesser_shadow_fissureAI(Creature *c) : ScriptedAI(c) {Reset();}

    bool Start;
    uint32 Stop_Timer;

    void Reset()
    {
        Start = false;
        Stop_Timer = 30000;
    }

    void Aggro(Unit* who) { }

    void MoveInLineOfSight(Unit *who) { return; }

    void AttackStart(Unit* who) { return; }

    void UpdateAI(const uint32 diff)
    {
        if( !Start )
        {
            //triggered spell of consumption does not properly show it's SpellVisual, hack it a bit
            m_creature->CastSpell(m_creature,SPELL_TEMPORARY_VISUAL,true);
            m_creature->CastSpell(m_creature,SPELL_CONSUMPTION,false);
            Start = true;
        }

        if( Stop_Timer < diff)
        {
            m_creature->setDeathState(JUST_DIED);
            m_creature->SetHealth(0);
            m_creature->CombatStop();
            m_creature->DeleteThreatList();
        }else Stop_Timer -= diff;
    }
};

CreatureAI* GetAI_boss_grand_warlock_nethekurse(Creature *_Creature)
{
    return new boss_grand_warlock_nethekurseAI (_Creature);
}

CreatureAI* GetAI_mob_fel_orc_convert(Creature *_Creature)
{
    return new mob_fel_orc_convertAI (_Creature);
}

CreatureAI* GetAI_mob_lesser_shadow_fissure(Creature *_Creature)
{
    return new mob_lesser_shadow_fissureAI (_Creature);
}

void AddSC_boss_grand_warlock_nethekurse()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_grand_warlock_nethekurse";
    newscript->GetAI = GetAI_boss_grand_warlock_nethekurse;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_fel_orc_convert";
    newscript->GetAI = GetAI_mob_fel_orc_convert;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_lesser_shadow_fissure";
    newscript->GetAI = GetAI_mob_lesser_shadow_fissure;
    m_scripts[nrscripts++] = newscript;
}
