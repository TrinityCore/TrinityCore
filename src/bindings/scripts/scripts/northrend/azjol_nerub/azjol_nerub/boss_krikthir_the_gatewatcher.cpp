/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: boss_krikthir_the_gatewatcher
SD%Complete: 80 %
SDComment: Find in the future best timers and the event is not implemented.
SDCategory: Azjol Nerub
EndScriptData */

/*** SQL START ***
update creature_template set scriptname = 'boss_krik_thir' where entry = '';
*** SQL END ***/

#include "precompiled.h"
#include "def_azjol_nerub.h"

enum Spells
{
    SPELL_MIND_FLAY                        =   52586,
    H_SPELL_MIND_FLAY                      =   59367,
    SPELL_CURSE_OF_FATIGUE                 =   52592,
    H_SPELL_CURSE_OF_FATIGUE               =   59368,
    SPELL_FRENZY                           =   28747, //maybe 53361

    SPELL_SUMMON_SKITTERING_SWARMER        =   52438, //AOE Effect 140, maybe 52439
    SPELL_SUMMON_SKITTERING_SWARMER_1      =   52439, //Summon 3x 28735

    H_SPELL_ACID_SPLASH                    =   59363,
    SPELL_ACID_SPLASH                      =   52446,

    SPELL_CHARGE                           =   16979,//maybe is another spell
    SPELL_BACKSTAB                         =   52540,

    SPELL_SHADOW_BOLT                      =   52534,
    H_SPELL_SHADOW_BOLT                    =   59357,
    SPELL_SHADOW_NOVA                      =   52535,
    H_SPELL_SHADOW_NOVA                    =   59358,

    SPELL_STRIKE                           =   52532,
    SPELL_CLEAVE                           =   49806,

    SPELL_ENRAGE                           =   52470,

    SPELL_INFECTED_BITE                    =   52469,
    H_SPELL_INFECTED_BITE                  =   59364,
    SPELL_WEB_WRAP                         =   52086,//the spell is not working propperly

    SPELL_BLINDING_WEBS                    =   52524,
    H_SPELL_BLINDING_WEBS                  =   59365,

    SPELL_POSION_SPRAY                     =   52493,
    H_SPELL_POSION_SPRAY                   =   59366,
};

enum Mobs
{
    MOB_SKITTERING_SWARMER                 =   28735,
    MOB_SKITTERING_SWARMER_CONTROLLER      =   32593,
    MOB_SKITTERING_INFECTIOR               =   28736,
};

enum Yells
{
    SAY_AGGRO                              =   -1601000,
    SAY_SLAY_1                             =   -1601001,
    SAY_SLAY_2                             =   -1601002,
    SAY_DEATH                              =   -1601003,
    //Not in db
    SAY_SEND_GROUP_1                       =   -1601004,
    SAY_SEND_GROUP_2                       =   -1601005,
    SAY_SEND_GROUP_3                       =   -1601006,
    SAY_SWARM_1                            =   -1601007,
    SAY_SWARM_2                            =   -1601008,
    SAY_PREFIGHT_1                         =   -1601009,
    SAY_PREFIGHT_2                         =   -1601010,
    SAY_PREFIGHT_3                         =   -1601011,
};
enum Misc
{
    ACHIEVEMENT_WATCH_HIM_DIE              =   1296
};
struct TRINITY_DLL_DECL boss_krik_thirAI : public ScriptedAI
{
    boss_krik_thirAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        HeroicMode = c->GetMap()->IsHeroic();
    }

    ScriptedInstance* pInstance;
    bool HeroicMode;

    uint32 MindFlayTimer;
    uint32 CurseFatigueTimer;
    uint32 SummonTimer;

    void Reset()
    {
        MindFlayTimer        = 15000;
        CurseFatigueTimer   = 12000;

        if (pInstance)
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature);
        Summon();
        SummonTimer = 15000;

        if (pInstance)
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, IN_PROGRESS);
    }

    void Summon()
    {
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,566.164,682.087,769.079,2.21657,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,566.164,682.087,769.079,2.21657,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,529.042,706.941,777.298,1.0821,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,529.042,706.941,777.298,1.0821,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,489.975,671.239,772.131,0.261799,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,489.975,671.239,772.131,0.261799,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,488.556,692.95,771.764,4.88692,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,488.556,692.95,771.764,4.88692,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,553.34,640.387,777.419,1.20428,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,553.34,640.387,777.419,1.20428,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,517.486,706.398,777.335,5.35816,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,517.486,706.398,777.335,5.35816,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_INFECTIOR,504.01,637.693,777.479,0.506145,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,504.01,637.693,777.479,0.506145,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,552.625,706.408,777.177,3.4383,TEMPSUMMON_TIMED_DESPAWN,25000);
            m_creature->SummonCreature(MOB_SKITTERING_SWARMER,552.625,706.408,777.177,3.4383,TEMPSUMMON_TIMED_DESPAWN,25000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;


        if(SummonTimer < diff)
        {
            Summon();
            SummonTimer = 15000;
        } else SummonTimer -= diff;

        if (MindFlayTimer < diff)
        {
                DoCast(m_creature->getVictim(), HEROIC(SPELL_MIND_FLAY, H_SPELL_MIND_FLAY));
                MindFlayTimer = 15000;
            } else MindFlayTimer -= diff;

        if (CurseFatigueTimer < diff)
        {
            //WowWiki say "Curse of Fatigue-Kirk'thir will cast Curse of Fatigue on 2-3 targets periodically. "
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM, 0);
            Unit* target_1 = SelectUnit(SELECT_TARGET_RANDOM, 1);

            DoCast(target, HEROIC(SPELL_CURSE_OF_FATIGUE, H_SPELL_CURSE_OF_FATIGUE));
            DoCast(target_1, HEROIC(SPELL_CURSE_OF_FATIGUE, H_SPELL_CURSE_OF_FATIGUE));

            CurseFatigueTimer = 10000;
        } else CurseFatigueTimer -= diff;

        if (!m_creature->HasAura(SPELL_FRENZY) && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 10)
            m_creature->CastSpell(m_creature,SPELL_FRENZY,true);

        DoMeleeAttackIfReady();
    }
    void JustDied(Unit* killer)
    {
        DoScriptText(SAY_DEATH, m_creature);

        if (pInstance)
        {
            pInstance->SetData(DATA_KRIKTHIR_THE_GATEWATCHER_EVENT, DONE);
            //Achievement: Watch him die
            AchievementEntry const *AchievWatchHimDie = GetAchievementStore()->LookupEntry(ACHIEVEMENT_WATCH_HIM_DIE);
            Map* pMap = m_creature->GetMap();
            Creature *pAdd1, *pAdd2, *pAdd3;
            if ((pAdd1 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_WATCHER_GASHRA))) && pAdd1->isAlive() &&
                (pAdd2 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_WATCHER_SILTHIK))) && pAdd2->isAlive() &&
                (pAdd3 = Unit::GetCreature(*m_creature, pInstance->GetData64(DATA_WATCHER_NARJIL))) && pAdd3->isAlive() &&
                HeroicMode && pMap && pMap->IsDungeon() && AchievWatchHimDie)
            {
                Map::PlayerList const &players = pMap->GetPlayers();
                for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    itr->getSource()->CompletedAchievement(AchievWatchHimDie);
            }
        }
    }
    void KilledUnit(Unit *victim)
    {
        if (victim == m_creature)
            return;

        DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), m_creature);
    }

    void JustSummoned(Creature* summoned)
    {
        summoned->GetMotionMaster()->MovePoint(m_creature->GetEntry(),m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ());
    }
};

struct TRINITY_DLL_DECL npc_skittering_infectorAI : public ScriptedAI
{
    npc_skittering_infectorAI(Creature *c) : ScriptedAI(c) {}

    void JustDied(Unit* killer)
    {
        //The spell is not working propperly
        DoCast(m_creature->getVictim(),HEROIC(SPELL_ACID_SPLASH, H_SPELL_ACID_SPLASH), true);
    }

};

struct TRINITY_DLL_DECL npc_anub_ar_skirmisherAI : public ScriptedAI
{
    npc_anub_ar_skirmisherAI(Creature *c) : ScriptedAI(c) {}

    uint32 ChargeTimer;
    uint32 BackstabTimer;

    void Reset()
    {
        ChargeTimer   = 11000;
        BackstabTimer = 7000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(ChargeTimer < diff)
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
            {
                DoResetThreat();
                m_creature->AddThreat(pTarget,1.0f);
                DoCast(pTarget,SPELL_CHARGE,true);
            }

            ChargeTimer = 15000;
        } else ChargeTimer -= diff;

        if(BackstabTimer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_BACKSTAB);
            BackstabTimer = 12000;
        } else BackstabTimer -= diff;

        DoMeleeAttackIfReady();

    }
};

struct TRINITY_DLL_DECL npc_anub_ar_shadowcasterAI : public ScriptedAI
{
    npc_anub_ar_shadowcasterAI(Creature *c) : ScriptedAI(c) {}

    uint32 ShadowBoltTimer;
    uint32 ShadowNovaTimer;

    void Reset()
    {
        ShadowBoltTimer = 6000;
        ShadowNovaTimer = 15000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(ShadowBoltTimer < diff)
        {
             if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                 DoCast(target, HEROIC(SPELL_SHADOW_BOLT : H_SPELL_SHADOW_BOLT), true);
            ShadowBoltTimer = 15000;
        } else ShadowBoltTimer -= diff;

        if(ShadowNovaTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_SHADOW_NOVA, H_SPELL_SHADOW_NOVA), true);
            ShadowNovaTimer = 17000;
        } else ShadowNovaTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL npc_anub_ar_warriorAI : public ScriptedAI
{
    npc_anub_ar_warriorAI(Creature *c) : ScriptedAI(c){}

    uint32 CleaveTimer;
    uint32 StrikeTimer;

    void Reset()
    {
        CleaveTimer = 11000;
        StrikeTimer = 6000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(StrikeTimer < diff)
        {
            m_creature->CastSpell(m_creature->getVictim(),SPELL_STRIKE,true);
            StrikeTimer = 15000;
        } else StrikeTimer -= diff;

        if(CleaveTimer < diff)
        {
            m_creature->CastSpell(m_creature->getVictim(), SPELL_CLEAVE ,true);
            CleaveTimer = 17000;
        } else CleaveTimer -= diff;

        DoMeleeAttackIfReady();

    }

};

struct TRINITY_DLL_DECL npc_watcher_gashraAI : public ScriptedAI
{
    npc_watcher_gashraAI(Creature *c) : ScriptedAI(c) {}

    uint32 WebWrapTimer;
    uint32 InfectedBiteTimer;

    void Reset()
    {
        WebWrapTimer      = 11000;
        InfectedBiteTimer = 4000;
    }


    void EnterCombat(Unit* who)
    {
        m_creature->CastSpell(m_creature,SPELL_ENRAGE,true);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(WebWrapTimer < diff)
        {
            if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                m_creature->CastSpell(target, SPELL_WEB_WRAP,true);
            WebWrapTimer = 17000;
        } else WebWrapTimer -= diff;

        if(InfectedBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_INFECTED_BITE, H_SPELL_INFECTED_BITE), true);
            InfectedBiteTimer = 15000;
        } else InfectedBiteTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL npc_watcher_narjilAI : public ScriptedAI
{
    npc_watcher_narjilAI(Creature *c) : ScriptedAI(c) {}

    uint32 WebWrapTimer;
    uint32 InfectedBiteTimer;
    uint32 BlindingWebsTimer;

    void Reset()
    {
        WebWrapTimer      = 11000;
        InfectedBiteTimer = 4000;
        BlindingWebsTimer = 17000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(WebWrapTimer < diff)
        {
            if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                DoCast(target, SPELL_WEB_WRAP,true);
            WebWrapTimer = 15000;
        } else WebWrapTimer -= diff;

        if(InfectedBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_INFECTED_BITE, H_SPELL_INFECTED_BITE), true);
            InfectedBiteTimer = 11000;
        } else InfectedBiteTimer -= diff;

        if(BlindingWebsTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_BLINDING_WEBS, H_SPELL_BLINDING_WEBS), true);
            BlindingWebsTimer = 17000;
        } else BlindingWebsTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL npc_watcher_silthikAI : public ScriptedAI
{
    npc_watcher_silthikAI(Creature *c) : ScriptedAI(c) {}

    uint32 WebWrapTimer;
    uint32 InfectedBiteTimer;
    uint32 PosionSprayTimer;

    void Reset()
    {
        WebWrapTimer      = 11000;
        InfectedBiteTimer = 4000;
        PosionSprayTimer  = 15000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if(WebWrapTimer < diff)
        {
            if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,100,true))
                DoCast(target, SPELL_WEB_WRAP,true);

            WebWrapTimer = 15000;
        } else WebWrapTimer -= diff;

        if(InfectedBiteTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_INFECTED_BITE, H_SPELL_INFECTED_BITE), true);
            InfectedBiteTimer = 15000;
        } else InfectedBiteTimer -= diff;

        if(PosionSprayTimer < diff)
        {
            DoCast(m_creature->getVictim(), HEROIC(SPELL_POSION_SPRAY , H_SPELL_POSION_SPRAY), true);
            PosionSprayTimer = 17000;
        } else PosionSprayTimer -= diff;

        DoMeleeAttackIfReady();

    }
};

CreatureAI* GetAI_boss_krik_thir(Creature* pCreature)
{
    return new boss_krik_thirAI (pCreature);
}

CreatureAI* GetAI_npc_anub_ar_skirmisher (Creature* pCreature)
{
    return new npc_anub_ar_skirmisherAI (pCreature);
}

CreatureAI* GetAI_npc_skittering_infector (Creature* pCreature)
{
    return new npc_skittering_infectorAI (pCreature);
}

CreatureAI* GetAI_npc_anub_ar_shadowcaster (Creature* pCreature)
{
    return new npc_anub_ar_shadowcasterAI (pCreature);
}

CreatureAI* GetAI_npc_anub_ar_warrior (Creature* pCreature)
{
    return new npc_anub_ar_warriorAI (pCreature);
}

CreatureAI* GetAI_npc_watcher_gashra (Creature* pCreature)
{
    return new npc_watcher_gashraAI (pCreature);
}

CreatureAI* GetAI_npc_watcher_narjil (Creature* pCreature)
{
    return new npc_watcher_narjilAI (pCreature);
}

CreatureAI* GetAI_npc_watcher_silthik (Creature* pCreature)
{
    return new npc_watcher_silthikAI (pCreature);
}


void AddSC_boss_krik_thir()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_krik_thir";
    newscript->GetAI = &GetAI_boss_krik_thir;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_skittering_infector";
    newscript->GetAI = &GetAI_npc_skittering_infector;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_anub_ar_skirmisher";
    newscript->GetAI = &GetAI_npc_anub_ar_skirmisher;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_anub_ar_shadowcaster";
    newscript->GetAI = &GetAI_npc_anub_ar_shadowcaster;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_watcher_gashra";
    newscript->GetAI = &GetAI_npc_watcher_gashra;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_anub_ar_warrior";
    newscript->GetAI = &GetAI_npc_anub_ar_warrior;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_watcher_silthik";
    newscript->GetAI = &GetAI_npc_watcher_silthik;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_watcher_narjil";
    newscript->GetAI = &GetAI_npc_watcher_narjil;
    newscript->RegisterSelf();
}
