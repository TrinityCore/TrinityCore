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
    int32 id;
    uint32 creature;
};

static Yell GoCombat[]=
{
    {-1540018, ENTRY_LEFT_HEAD},
    {-1540019, ENTRY_LEFT_HEAD},
    {-1540020, ENTRY_LEFT_HEAD},
};
static Yell GoCombatDelay[]=
{
    {-1540021, ENTRY_RIGHT_HEAD},
    {-1540022, ENTRY_RIGHT_HEAD},
    {-1540023, ENTRY_RIGHT_HEAD},
};

static Yell Threat[]=
{
    {-1540024, ENTRY_LEFT_HEAD},
    {-1540025, ENTRY_RIGHT_HEAD},
    {-1540026, ENTRY_LEFT_HEAD},
    {-1540027, ENTRY_LEFT_HEAD},
};
static Yell ThreatDelay1[]=
{
    {-1540028, ENTRY_RIGHT_HEAD},
    {-1540029, ENTRY_LEFT_HEAD},
    {-1540030, ENTRY_RIGHT_HEAD},
    {-1540031, ENTRY_RIGHT_HEAD},
};
static Yell ThreatDelay2[]=
{
    {-1540032, ENTRY_LEFT_HEAD},
    {-1540033, ENTRY_RIGHT_HEAD},
    {-1540034, ENTRY_LEFT_HEAD},
    {-1540035, ENTRY_LEFT_HEAD},
};

static Yell Killing[]=
{
    {-1540036, ENTRY_LEFT_HEAD},
    {-1540037, ENTRY_RIGHT_HEAD},
};
static Yell KillingDelay[]=
{
    {-1540038, ENTRY_RIGHT_HEAD},
    {-1000000, ENTRY_LEFT_HEAD},
};

#define YELL_DIE_L                  -1540039
#define YELL_DIE_R                  -1540040
#define EMOTE_ENRAGE                -1540041

#define SPELL_BLAST_WAVE            30600
#define SPELL_FEAR                  30584
#define SPELL_THUNDERCLAP           30633

#define SPELL_BURNING_MAUL          30598
#define H_SPELL_BURNING_MAUL        36056

struct TRINITY_DLL_DECL mob_omrogg_headsAI : public ScriptedAI
{
    mob_omrogg_headsAI(Creature *c) : ScriptedAI(c) {}

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
        if (!DeathYell)
            return;

        if (Death_Timer < diff)
        {
            DoScriptText(YELL_DIE_R, m_creature);
            DeathYell = false;
        }else Death_Timer -= diff;
    }
};

struct TRINITY_DLL_DECL boss_warbringer_omroggAI : public ScriptedAI
{
    boss_warbringer_omroggAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = ((ScriptedInstance*)c->GetInstanceData());
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint64 LeftHead;
    uint64 RightHead;
    int iaggro;
    int ithreat;
    int ikilling;

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

        m_creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
        m_creature->ApplySpellImmune(1, IMMUNITY_EFFECT,SPELL_EFFECT_ATTACK_ME, true);

        if (pInstance)
            pInstance->SetData(TYPE_OMROGG, NOT_STARTED);   //End boss can use this later. O'mrogg must be defeated(DONE) or he will come to aid.
    }

    void DoYellForThreat()
    {
        if (LeftHead && RightHead)
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if (!Left || !Right)
                return;

            ithreat = rand()%4;

            Unit *source = (Left->GetEntry() == Threat[ithreat].creature ? Left : Right);

            DoScriptText(Threat[ithreat].id, source);

            Delay_Timer = 3500;
            ThreatYell = true;
        }
    }

    void Aggro(Unit *who)
    {
        DoSpawnCreature(ENTRY_LEFT_HEAD,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN,90000);
        DoSpawnCreature(ENTRY_RIGHT_HEAD,0,0,0,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,90000);

        if (Unit *Left = Unit::GetUnit(*m_creature,LeftHead))
        {
            iaggro = rand()%3;

            DoScriptText(GoCombat[iaggro].id, Left);

            Delay_Timer = 3500;
            AggroYell = true;
        }

        if (pInstance)
            pInstance->SetData(TYPE_OMROGG, IN_PROGRESS);
    }

    void JustSummoned(Creature *summoned)
    {
        if (summoned->GetEntry() == ENTRY_LEFT_HEAD)
            LeftHead = summoned->GetGUID();

        if (summoned->GetEntry() == ENTRY_RIGHT_HEAD)
            RightHead = summoned->GetGUID();

        //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        //summoned->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        summoned->SetVisibility(VISIBILITY_OFF);
    }

    void KilledUnit(Unit* victim)
    {
        if (LeftHead && RightHead)
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if (!Left || !Right)
                return;

            ikilling = rand()%2;

            Unit *source = (Left->GetEntry() == Killing[ikilling].creature ? Left : Right);

            switch(ikilling)
            {
                case 0:
                    DoScriptText(Killing[ikilling].id, source);
                    Delay_Timer = 3500;
                    KillingYell = true;
                    break;
                case 1:
                    DoScriptText(Killing[ikilling].id, source);
                    KillingYell = false;
                    break;
            }
        }
    }

    void JustDied(Unit* Killer)
    {
        if (LeftHead && RightHead)
        {
            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if (!Left || !Right)
                return;

            DoScriptText(YELL_DIE_L, Left);

            ((mob_omrogg_headsAI*)((Creature*)Right)->AI())->DoDeathYell();
        }

        if (pInstance)
            pInstance->SetData(TYPE_OMROGG, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Delay_Timer < diff)
        {
            Delay_Timer = 3500;

            if (!LeftHead || !RightHead)
                return;

            Unit *Left  = Unit::GetUnit(*m_creature,LeftHead);
            Unit *Right = Unit::GetUnit(*m_creature,RightHead);

            if (!Left || !Right)
                return;

            if (AggroYell)
            {
                DoScriptText(GoCombatDelay[iaggro].id, Right);
                AggroYell = false;
            }

            if (ThreatYell2)
            {
                Unit *source = (Left->GetEntry() == ThreatDelay2[ithreat].creature ? Left : Right);

                DoScriptText(ThreatDelay2[ithreat].id, source);
                ThreatYell2 = false;
            }

            if (ThreatYell)
            {
                Unit *source = (Left->GetEntry() == ThreatDelay1[ithreat].creature ? Left : Right);

                DoScriptText(ThreatDelay1[ithreat].id, source);
                ThreatYell = false;
                ThreatYell2 = true;
            }

            if (KillingYell)
            {
                Unit *source = (Left->GetEntry() == KillingDelay[ikilling].creature ? Left : Right);

                DoScriptText(KillingDelay[ikilling].id, source);
                KillingYell = false;
            }
        }else Delay_Timer -= diff;

        if (!UpdateVictim())
            return;

        if (BlastCount && BlastWave_Timer <= diff)
        {
            DoCast(m_creature,SPELL_BLAST_WAVE);
            BlastWave_Timer = 5000;
            ++BlastCount;

            if (BlastCount == 3)
                BlastCount = 0;
        }else BlastWave_Timer -= diff;

        if (BurningMaul_Timer < diff)
        {
            DoScriptText(EMOTE_ENRAGE, m_creature);
            DoCast(m_creature,HeroicMode ? H_SPELL_BURNING_MAUL : SPELL_BURNING_MAUL);
            BurningMaul_Timer = 40000;
            BlastWave_Timer = 16000;
            BlastCount = 1;
        }else BurningMaul_Timer -= diff;

        if (ResetThreat_Timer < diff)
        {
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0))
            {
                DoYellForThreat();
                DoResetThreat();
                m_creature->AddThreat(target, 0.0f);
            }
            ResetThreat_Timer = 25000+rand()%15000;
        }else ResetThreat_Timer -= diff;

        if (Fear_Timer < diff)
        {
            DoCast(m_creature,SPELL_FEAR);
            Fear_Timer = 15000+rand()%20000;
        }else Fear_Timer -= diff;

        if (ThunderClap_Timer < diff)
        {
            DoCast(m_creature,SPELL_THUNDERCLAP);
            ThunderClap_Timer = 15000+rand()%15000;
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
    newscript->GetAI = &GetAI_boss_warbringer_omrogg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="mob_omrogg_heads";
    newscript->GetAI = &GetAI_mob_omrogg_heads;
    newscript->RegisterSelf();
}

