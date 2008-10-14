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
SDName: Boss_Warbringer_Omrogg
SD%Complete: 85
SDComment: Heroic enabled. Spell timing may need additional tweaks
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
mob_omrogg_heads
boss_warbringer_omrogg
EndContentData */

#include "precompiled.h"
#include "def_shattered_halls.h"

#define ENTRY_LEFT_HEAD             19523
#define ENTRY_RIGHT_HEAD            19524

struct Yell
{
    const char* text;
    uint32 sound;
    uint32 creature;
};

static Yell GoCombat[]=
{
    {"Smash!", 10306, ENTRY_LEFT_HEAD},
    {"If you nice me let you live.", 10308, ENTRY_LEFT_HEAD},
    {"Me hungry!", 10309, ENTRY_LEFT_HEAD},
};
static Yell GoCombatDelay[]=
{
    {"Why don't you let me do the talking?", 10317, ENTRY_RIGHT_HEAD},
    {"No, we will NOT let you live!", 10318, ENTRY_RIGHT_HEAD},
    {"You always hungry. That why we so fat!", 10319, ENTRY_RIGHT_HEAD},
};

static Yell Threat[]=
{
    {"You stay here. Me go kill someone else!", 10303, ENTRY_LEFT_HEAD},
    {"What are you doing!", 10315, ENTRY_RIGHT_HEAD},
    {"Me kill someone else...", 10302, ENTRY_LEFT_HEAD},
    {"Me not like this one...",10300, ENTRY_LEFT_HEAD},
};
static Yell ThreatDelay1[]=
{
    {"That's not funny!", 10314, ENTRY_RIGHT_HEAD},
    {"Me get bored...", 10305, ENTRY_LEFT_HEAD},
    {"I'm not done yet, idiot!", 10313, ENTRY_RIGHT_HEAD},
    {"Hey you numbskull!", 10312, ENTRY_RIGHT_HEAD},
};
static Yell ThreatDelay2[]=
{
    {"Ha ha ha.", 10304, ENTRY_LEFT_HEAD},
    {"Whhy! He almost dead!", 10316, ENTRY_RIGHT_HEAD},
    {"H'ey...", 10307, ENTRY_LEFT_HEAD},
    {"We kill his friend!", 10301, ENTRY_LEFT_HEAD},
};

static Yell Killing[]=
{
    {"This one die easy!", 10310, ENTRY_LEFT_HEAD},
    {"I'm tired. You kill next one!", 10320, ENTRY_RIGHT_HEAD},
};
static Yell KillingDelay[]=
{
    {"That's because I do all the hard work!", 10321, ENTRY_RIGHT_HEAD},
    {"SD2 script error, should not see this.", 0, ENTRY_LEFT_HEAD},
};

#define EMOTE_ENRAGE                "enrages"

#define YELL_DIE_L                  "This all...your fault!"
#define SOUND_DIE_L                 10311
#define YELL_DIE_R                  "I...hate...you..."
#define SOUND_DIE_R                 10322

#define SPELL_BLAST_WAVE            30600
#define SPELL_FEAR                  30584
#define SPELL_THUNDERCLAP           30633

#define SPELL_BURNING_MAUL          30598
#define H_SPELL_BURNING_MAUL        36056

struct MANGOS_DLL_DECL mob_omrogg_headsAI : public ScriptedAI
{
    mob_omrogg_headsAI(Creature *c) : ScriptedAI(c) { Reset(); }

    bool DeathYell;
    uint32 Death_Timer;

    void Reset() {}
    void Aggro(Unit* who) { }

    void DoDeathYell()
    {
        Death_Timer = 4000;
        DeathYell = true;
    }

    void UpdateAI(const uint32 diff)
    {
        if( !DeathYell )
            return;

        if( Death_Timer < diff )
        {
            DoYell(YELL_DIE_R,LANG_UNIVERSAL,NULL);
            DoPlaySoundToSet(m_creature, SOUND_DIE_R);
            DeathYell = false;
        }else Death_Timer -= diff;
    }
};

struct MANGOS_DLL_DECL boss_warbringer_omroggAI : public ScriptedAI
{
    boss_warbringer_omroggAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        HeroicMode = m_creature->GetMap()->IsHeroic();
        Reset();
    }

    ScriptedInstance* pInstance;

    uint64 LeftHead;
    uint64 RightHead;
    int iaggro;
    int ithreat;
    int ikilling;

    bool HeroicMode;
    bool AggroYell;
    bool ThreatYell;
    bool ThreatYell2;
    bool KillingYell;

    uint32 Delay_Timer;
    uint32 BlastWave_Timer;
    uint32 BlastCount;
    uint32 Fear_Timer;
    uint32 BurningMaul_Timer;
    uint32 ThunderClap_Timer;
    uint32 ResetThreat_Timer;

    void Reset()
    {
        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(0, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);

        LeftHead = 0;
        RightHead = 0;

        AggroYell = false;
        ThreatYell = false;
        ThreatYell2 = false;
        KillingYell = false;

        Delay_Timer = 4000;
        BlastWave_Timer = 0;
        BlastCount = 0;
        Fear_Timer = 8000;
        BurningMaul_Timer = 25000;
        ThunderClap_Timer = 15000;
        ResetThreat_Timer = 30000;

        if( pInstance )
            pInstance->SetData(TYPE_OMROGG, NOT_STARTED);   //End boss can use this later. O'mrogg must be defeated(DONE) or he will come to aid.
    }

    void DoYellForThreat()
    {
        if( LeftHead && RightHead )
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if( !Left && !Right )
                return;

            ithreat = rand()%4;

            Unit *source = (Left->GetEntry() == Threat[ithreat].creature ? Left : Right);

            source->MonsterYell(Threat[ithreat].text, LANG_UNIVERSAL, 0);
            DoPlaySoundToSet(source, Threat[ithreat].sound);

            Delay_Timer = 3500;
            ThreatYell = true;
        }
    }

    void Aggro(Unit *who)
    {
        DoSpawnCreature(ENTRY_LEFT_HEAD,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,1800000);
        DoSpawnCreature(ENTRY_RIGHT_HEAD,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,1800000);

        if( Unit *Left = Unit::GetUnit(*m_creature,LeftHead) )
        {
            iaggro = rand()%3;

            Left->MonsterYell(GoCombat[iaggro].text, LANG_UNIVERSAL, 0);
            DoPlaySoundToSet(Left, GoCombat[iaggro].sound);

            Delay_Timer = 3500;
            AggroYell = true;
        }
        if( pInstance )
            pInstance->SetData(TYPE_OMROGG, IN_PROGRESS);
    }

    void JustSummoned(Creature *summoned)
    {
        if( summoned->GetEntry() == ENTRY_LEFT_HEAD )
            LeftHead = summoned->GetGUID();

        if( summoned->GetEntry() == ENTRY_RIGHT_HEAD )
            RightHead = summoned->GetGUID();

        //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        summoned->SetVisibility(VISIBILITY_OFF);
    }

    void KilledUnit(Unit* victim)
    {
        if( LeftHead && RightHead )
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if( !Left && !Right )
                return;

            ikilling = rand()%2;

            Unit *source = (Left->GetEntry() == Killing[ikilling].creature ? Left : Right);

            switch(ikilling)
            {
                case 0:
                    source->MonsterYell(Killing[ikilling].text, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(source, Killing[ikilling].sound);
                    Delay_Timer = 3500;
                    KillingYell = true;
                    break;
                case 1:
                    source->MonsterYell(Killing[ikilling].text, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(source, Killing[ikilling].sound);
                    KillingYell = false;
                    break;
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        if( LeftHead && RightHead )
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if( !Left && !Right )
                return;

            Left->MonsterYell(YELL_DIE_L, LANG_UNIVERSAL, 0);
            DoPlaySoundToSet(Left,SOUND_DIE_L);

            ((mob_omrogg_headsAI*)((Creature*)Right)->AI())->DoDeathYell();
        }
        if( pInstance )
            pInstance->SetData(TYPE_OMROGG, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if( Delay_Timer < diff )
        {
            Delay_Timer = 3500;

            if( !LeftHead && !RightHead )
                return;

            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if( !Left && !Right )
                return;

            if( AggroYell )
            {
                Right->MonsterYell(GoCombatDelay[iaggro].text, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(Right, GoCombatDelay[iaggro].sound);
                AggroYell = false;
            }

            if( ThreatYell2 )
            {
                Unit *source = (Left->GetEntry() == ThreatDelay2[ithreat].creature ? Left : Right);

                source->MonsterYell(ThreatDelay2[ithreat].text, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(source, ThreatDelay2[ithreat].sound);
                ThreatYell2 = false;
            }

            if( ThreatYell )
            {
                Unit *source = (Left->GetEntry() == ThreatDelay1[ithreat].creature ? Left : Right);

                source->MonsterYell(ThreatDelay1[ithreat].text, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(source, ThreatDelay1[ithreat].sound);
                ThreatYell = false;
                ThreatYell2 = true;
            }

            if( KillingYell )
            {
                Unit *source = (Left->GetEntry() == KillingDelay[ikilling].creature ? Left : Right);

                source->MonsterYell(KillingDelay[ikilling].text, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(source, KillingDelay[ikilling].sound);
                KillingYell = false;
            }
        }else Delay_Timer -= diff;

        if( !m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        if( BlastCount && BlastWave_Timer <= diff )
        {
            DoCast(m_creature,SPELL_BLAST_WAVE);
            BlastWave_Timer = 5000;
            ++BlastCount;
            if( BlastCount == 3 )
                BlastCount = 0;
        }else BlastWave_Timer -= diff;

        if( BurningMaul_Timer < diff )
        {
            DoTextEmote(EMOTE_ENRAGE,NULL);
            DoCast(m_creature,HeroicMode ? H_SPELL_BURNING_MAUL : SPELL_BURNING_MAUL);
            BurningMaul_Timer = 40000;
            BlastWave_Timer = 16000;
            BlastCount = 1;
        }else BurningMaul_Timer -= diff;

        if( ResetThreat_Timer < diff )
        {
            if( Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0) )
            {
                DoYellForThreat();
                DoResetThreat();
                m_creature->AddThreat(target, 0.0f);
            }
            ResetThreat_Timer = 35000+rand()%10000;
        }else ResetThreat_Timer -= diff;

        if( Fear_Timer < diff )
        {
            DoCast(m_creature,SPELL_FEAR);
            Fear_Timer = 15000+rand()%25000;
        }else Fear_Timer -= diff;

        if( ThunderClap_Timer < diff )
        {
            DoCast(m_creature,SPELL_THUNDERCLAP);
            ThunderClap_Timer = 25000+rand()%15000;
        }else ThunderClap_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_warbringer_omrogg(Creature *_Creature)
{
    return new boss_warbringer_omroggAI (_Creature);
}

CreatureAI* GetAI_mob_omrogg_heads(Creature *_Creature)
{
    return new mob_omrogg_headsAI (_Creature);
}

void AddSC_boss_warbringer_omrogg()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_warbringer_omrogg";
    newscript->GetAI = GetAI_boss_warbringer_omrogg;
    m_scripts[nrscripts++] = newscript;

    newscript = new Script;
    newscript->Name="mob_omrogg_heads";
    newscript->GetAI = GetAI_mob_omrogg_heads;
    m_scripts[nrscripts++] = newscript;
}
