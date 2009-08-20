/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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
SDName: Assembly of Iron encounter
SD%Complete: 60%
SDComment: Runes need DB support, chain lightning won't cast, supercharge won't cast (target error?) - it worked before during debugging.
SDCategory: Ulduar - Ulduar
EndScriptData */

#include "precompiled.h"
#include "def_ulduar.h"

// Any boss
#define SPELL_SUPERCHARGE   61920
#define SPELL_BERSERK       47008   // Hard enrage, don't know the correct ID.

// Steelbreaker
#define SPELL_HIGH_VOLTAGE           61890
#define SPELL_HIGH_VOLTAGE_H         63498
#define SPELL_FUSION_PUNCH           61903
#define SPELL_FUSION_PUNCH_H         63493
#define SPELL_STATIC_DISRUPTION      44008
#define SPELL_STATIC_DISRUPTION_H    63494
#define SPELL_OVERWHELMING_POWER_H   61888
#define SPELL_OVERWHELMING_POWER     64637
#define SPELL_ELECTRICAL_CHARGE      61902

// Runemaster Molgeim
#define SPELL_SHIELD_OF_RUNES        62274
#define SPELL_SHIELD_OF_RUNES_H      63489
#define SPELL_RUNE_OF_POWER          64320
#define SPELL_RUNE_OF_DEATH          62269
#define SPELL_RUNE_OF_SUMMONING      62273
#define SPELL_LIGHTNING_BLAST        62054
#define SPELL_LIGHTNING_BLAST_H      63491
#define CREATURE_RUNE_OF_SUMMONING   33051

// Stormcaller Brundir
#define SPELL_CHAIN_LIGHTNING_N      61879
#define SPELL_CHAIN_LIGHTNING_H      63479
#define SPELL_OVERLOAD               61869
#define SPELL_OVERLOAD_H             63481
#define SPELL_LIGHTNING_WHIRL        61915
#define SPELL_LIGHTNING_WHIRL_H      63483
#define SPELL_LIGHTNING_TENDRILS     61887
#define SPELL_LIGHTNING_TENDRILS_H   63486
#define SPELL_STORMSHIELD            64187
      


enum
{
    EVENT_ENRAGE,
    // Steelbreaker
    EVENT_FUSION_PUNCH,
    EVENT_STATIC_DISRUPTION,
    EVENT_OVERWHELMING_POWER,
    // Molgeim
    EVENT_RUNE_OF_POWER,
    EVENT_SHIELD_OF_RUNES,
    EVENT_RUNE_OF_DEATH,
    EVENT_RUNE_OF_SUMMONING,
    EVENT_LIGHTNING_BLAST,
    // Brundir
    EVENT_CHAIN_LIGHTNING,
    EVENT_OVERLOAD,
    EVENT_LIGHTNING_WHIRL,
    EVENT_LIGHTNING_TENDRILS,
    EVENT_STORMSHIELD,
    MAX_EVENT
   
};



bool IsEncounterComplete(ScriptedInstance* pInstance, Creature* m_creature)
{
   if (!pInstance || !m_creature)
        return false;
    
    for(uint8 i = 0; i < 3; ++i)
    {
        uint64 guid = pInstance->GetData64(DATA_STEELBREAKER+i);
        if(!guid)
            return false;
            
        if(Creature *boss = (Unit::GetCreature((*m_creature), guid)))
        {
            if(boss->isAlive())
                return false;
                
            continue;
        }
        else
            return false;
    }
    return true;
}

struct TRINITY_DLL_DECL boss_steelbreakerAI : public ScriptedAI
{
    boss_steelbreakerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        if(!pInstance)
            return;
        Reset();
    }
    
    void Reset()
    {
        events.Reset();
        phase = 0;
        m_creature->RemoveAllAuras();
        pInstance->SetData(DATA_ASSEMBLY, NOT_STARTED);
    }
    
    EventMap events;
    ScriptedInstance* pInstance;
    uint32 phase;

    void EnterCombat(Unit *who)
    {
        DoZoneInCombat();
        DoCast(m_creature, (HeroicMode) ? SPELL_HIGH_VOLTAGE_H : SPELL_HIGH_VOLTAGE);
        events.ScheduleEvent(EVENT_ENRAGE, 900000);
        UpdatePhase();
    }
    
    void UpdatePhase()
    {
        ++phase;
        events.SetPhase(phase);
        events.RescheduleEvent(EVENT_FUSION_PUNCH, 15000);
        if(phase >= 2)
            events.RescheduleEvent(EVENT_STATIC_DISRUPTION, 30000);
        if(phase >= 3)
            events.RescheduleEvent(EVENT_OVERWHELMING_POWER, rand()%5000);
    }
    
    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth())
        {
            if(Creature* Brundir = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_STORMCALLER_BRUNDIR)))
                if(Brundir->isAlive())
                {
                    Brundir->SetHealth(Brundir->GetMaxHealth());
                }
            
            if(Creature* Molgeim = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_RUNEMASTER_MOLGEIM)))
                if(Molgeim->isAlive())
                {
                    Molgeim->SetHealth(Molgeim->GetMaxHealth());
                }
             DoCast(SPELL_SUPERCHARGE);
        }
    }
    
    void JustDied(Unit* Killer)
    {
        if(IsEncounterComplete(pInstance, m_creature))
            pInstance->SetData(DATA_ASSEMBLY, DONE);
    }
    
    void KilledUnit(Unit *who)
    {
        if(phase == 3)
            DoCast(m_creature, SPELL_ELECTRICAL_CHARGE);
    }
    
    void SpellHit(Unit *from, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_SUPERCHARGE)
            UpdatePhase();
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                break;
                case EVENT_FUSION_PUNCH:
                    DoCast(me->getVictim(), (HeroicMode) ? SPELL_FUSION_PUNCH : SPELL_FUSION_PUNCH_H);
                    events.ScheduleEvent(EVENT_FUSION_PUNCH, 13000 + (rand()%9)*1000);
                break;
                case EVENT_STATIC_DISRUPTION:
                {
                    Unit *target = SelectTarget(SELECT_TARGET_RANDOM);
                    DoCast(target, (HeroicMode) ? SPELL_STATIC_DISRUPTION : SPELL_STATIC_DISRUPTION_H);
                    events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 20000 + (rand()%20)*1000);
                }
                break;
                case EVENT_OVERWHELMING_POWER:
                    DoCast(me->getVictim(), (HeroicMode) ? SPELL_OVERWHELMING_POWER_H : SPELL_OVERWHELMING_POWER);
                    events.ScheduleEvent(EVENT_OVERWHELMING_POWER, (HeroicMode) ? 35000 : 60000);
                break;
            }
        }
        
        DoMeleeAttackIfReady();    
    }
};

struct TRINITY_DLL_DECL boss_runemaster_molgeimAI : public ScriptedAI
{
    boss_runemaster_molgeimAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        if(!pInstance)
            return;
            
        Reset();
       
    }
    
    void Reset()
    {
        pInstance->SetData(DATA_ASSEMBLY, NOT_STARTED);
        events.Reset();
        m_creature->RemoveAllAuras();
        phase = 0;
    }
    
    ScriptedInstance* pInstance;
    EventMap events;
    uint32 phase;
    
    void EnterCombat(Unit* who)
    {
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_ENRAGE, 900000);
        UpdatePhase();
    }
    
    void UpdatePhase()
    {
        ++phase;
        events.SetPhase(phase);
        events.RescheduleEvent(EVENT_SHIELD_OF_RUNES, 27000);
        events.RescheduleEvent(EVENT_RUNE_OF_POWER, 60000);
        if(phase >= 2)
            events.RescheduleEvent(EVENT_RUNE_OF_DEATH, 30000);
        if(phase >= 3)
            events.RescheduleEvent(EVENT_RUNE_OF_SUMMONING, 20000+(rand()%10)*1000);
    }
    
    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth())
        {   
        if(Creature* Steelbreaker = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_STEELBREAKER)))
                if(Steelbreaker->isAlive())
                {
                    Steelbreaker->SetHealth(Steelbreaker->GetMaxHealth());
                }
            
            if(Creature* Brundir = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_STORMCALLER_BRUNDIR)))
                if(Brundir->isAlive())
                {
                    Brundir->SetHealth(Brundir->GetMaxHealth());
                }
            DoCast(m_creature, SPELL_SUPERCHARGE);
        }
    }
    
    void JustDied(Unit* Killer)
    {
        if(IsEncounterComplete(pInstance, m_creature))
            pInstance->SetData(DATA_ASSEMBLY, DONE);
    }
    
    void SpellHit(Unit *from, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_SUPERCHARGE)
            UpdatePhase();
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                break;
                case EVENT_RUNE_OF_POWER: // Improve target selection; random alive friendly
                {
                    Unit *Target = DoSelectLowestHpFriendly(60);
                    if(!Target || (Target && !Target->isAlive()))
                        Target = m_creature;
                    DoCast(Target, SPELL_RUNE_OF_POWER);
                    events.ScheduleEvent(EVENT_RUNE_OF_POWER, 60000);
                }
                break;
                case EVENT_SHIELD_OF_RUNES:
                    DoCast( m_creature, (HeroicMode) ? SPELL_SHIELD_OF_RUNES_H : SPELL_SHIELD_OF_RUNES);
                    events.ScheduleEvent(EVENT_SHIELD_OF_RUNES, 27000+ (rand()%7)*1000);
                break;
                case EVENT_RUNE_OF_DEATH:
                {
                    Unit *target = SelectTarget(SELECT_TARGET_RANDOM);
                    DoCast(target, SPELL_RUNE_OF_DEATH);
                    events.ScheduleEvent(EVENT_RUNE_OF_DEATH, 30000+ (rand()%10)*1000);    
                }
                break;
                case EVENT_RUNE_OF_SUMMONING:
                {
                    Unit *target = SelectTarget(SELECT_TARGET_RANDOM);
                    DoCast(target, SPELL_RUNE_OF_SUMMONING);
                    events.ScheduleEvent(EVENT_RUNE_OF_SUMMONING, 20000+(rand()%10)*1000);
                }
                break;
            }
        }
        
        DoMeleeAttackIfReady();    
    }
};

struct TRINITY_DLL_DECL mob_lightning_elementalAI : public ScriptedAI
{
    mob_lightning_elementalAI(Creature *c) : ScriptedAI(c)
    {
        Charge();
    }

    Unit* Target;
    
    void Charge()
    {
        Target = m_creature->SelectNearestTarget();
        m_creature->AddThreat(Target, 5000000.0f);
        AttackStart(Target);
    }
    
    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->isInCombat())
            return;
            
        if(m_creature->IsWithinMeleeRange(Target))
        {
            DoCast(Target, (HeroicMode) ? SPELL_LIGHTNING_BLAST_H : SPELL_LIGHTNING_BLAST);
            m_creature->DealDamage(m_creature, m_creature->GetMaxHealth()); // hack untill spell works
        }
        
        m_creature->GetMotionMaster()->MoveChase(Target); // needed at every update?
    }
    
};

struct TRINITY_DLL_DECL mob_rune_of_summoningAI : public ScriptedAI
{
    mob_rune_of_summoningAI(Creature *c) : ScriptedAI(c)
    {
        SummonLightningElemental();
    }

    void SummonLightningElemental()
    {
        m_creature->SummonCreature(CREATURE_RUNE_OF_SUMMONING, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN );
        m_creature->DealDamage(m_creature, m_creature->GetHealth());
    }
};

struct TRINITY_DLL_DECL boss_stormcaller_brundirAI : public ScriptedAI
{
    boss_stormcaller_brundirAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        if(!pInstance)
            return;

        Reset();   
    }
    
    void Reset()
    {
        pInstance->SetData(DATA_ASSEMBLY, NOT_STARTED);
        m_creature->RemoveAllAuras();
        events.Reset();
        phase = 0;
    }
    
    EventMap events;
    ScriptedInstance* pInstance;
    uint32 phase;
    
    void EnterCombat(Unit* who)
    {
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_ENRAGE, 900000);
        UpdatePhase();
    }
    
    void UpdatePhase()
    {
        ++phase;
        events.SetPhase(phase);
        events.RescheduleEvent(EVENT_CHAIN_LIGHTNING, 9000+ (rand()%8)*1000);
        events.RescheduleEvent(EVENT_OVERLOAD, 60000+ (rand()%65)*1000);
        if(phase >= 2)
            events.RescheduleEvent(EVENT_LIGHTNING_WHIRL, 20000+ (rand()%20)*1000);
        if(phase >= 3)
        {
            DoCast(m_creature, SPELL_STORMSHIELD);
            events.RescheduleEvent(EVENT_LIGHTNING_TENDRILS, 40000+ (rand()%40)*1000);
        }
    
    }
    
    void DamageTaken(Unit* pKiller, uint32 &damage)
    {
        if(damage >= m_creature->GetHealth())
        {
            if(Creature* Steelbreaker = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_STEELBREAKER)))
                if(Steelbreaker->isAlive())
                {
                    Steelbreaker->SetHealth(Steelbreaker->GetMaxHealth());
                }
            
            if(Creature* Molgeim = Unit::GetCreature((*m_creature), pInstance->GetData64(DATA_RUNEMASTER_MOLGEIM)))
                if(Molgeim->isAlive())
                {
                    Molgeim->SetHealth(Molgeim->GetMaxHealth());
                }
                
            DoCast(SPELL_SUPERCHARGE);
        }
    }
    
    void JustDied(Unit* Killer)
    {
        if(IsEncounterComplete(pInstance, m_creature))
            pInstance->SetData(DATA_ASSEMBLY, DONE);
    }
    
    void SpellHit(Unit *from, const SpellEntry *spell)
    {
        if(spell->Id == SPELL_SUPERCHARGE)
        {
            UpdatePhase();
        }
    }
    
    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_ENRAGE:
                    DoCast(SPELL_BERSERK);
                break;
                case EVENT_CHAIN_LIGHTNING:
                {
                    Unit* Target = SelectUnit(SELECT_TARGET_RANDOM,0);
                    DoCast(Target, (HeroicMode) ? SPELL_CHAIN_LIGHTNING_H : SPELL_CHAIN_LIGHTNING_N );
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 9000+ (rand()%8)*1000);
                }
                break;
                case EVENT_OVERLOAD:
                    DoCast( (HeroicMode) ? SPELL_OVERLOAD_H : SPELL_OVERLOAD );
                    events.ScheduleEvent(EVENT_OVERLOAD, 60000+ (rand()%65)*1000);
                break;
                case EVENT_LIGHTNING_WHIRL:
                    DoCast( (HeroicMode) ? SPELL_LIGHTNING_WHIRL_H : SPELL_LIGHTNING_WHIRL );
                    events.ScheduleEvent(EVENT_LIGHTNING_WHIRL, 20000+ (rand()%20)*1000);
                break;
                case EVENT_LIGHTNING_TENDRILS:
                    DoCast( (HeroicMode) ? SPELL_LIGHTNING_TENDRILS_H : SPELL_LIGHTNING_TENDRILS );
                    events.DelayEvents(15000, 5000);
                    DoResetThreat();
                break;
            }
        }
        
        DoMeleeAttackIfReady();    
    }
};

CreatureAI* GetAI_boss_steelbreaker(Creature* pCreature)
{
    return new boss_steelbreakerAI (pCreature);
}

CreatureAI* GetAI_boss_runemaster_molgeim(Creature* pCreature)
{
    return new boss_runemaster_molgeimAI (pCreature);
}

CreatureAI* GetAI_boss_stormcaller_brundir(Creature* pCreature)
{
    return new boss_stormcaller_brundirAI (pCreature);
}

CreatureAI* GetAI_mob_lightning_elemental(Creature* pCreature)
{
    return new mob_lightning_elementalAI (pCreature);
}

CreatureAI* GetAI_mob_rune_of_summoning(Creature* pCreature)
{
    return new mob_rune_of_summoningAI (pCreature);
}

void AddSC_boss_assembly_of_iron()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_steelbreaker";
    newscript->GetAI = &GetAI_boss_steelbreaker;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="boss_runemaster_molgeim";
    newscript->GetAI = &GetAI_boss_runemaster_molgeim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="boss_stormcaller_brundir";
    newscript->GetAI = &GetAI_boss_stormcaller_brundir;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="mob_lightning_elemental";
    newscript->GetAI = &GetAI_mob_lightning_elemental;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name="mob_rune_of_summoning";
    newscript->GetAI = &GetAI_mob_rune_of_summoning;
    newscript->RegisterSelf();
    
}