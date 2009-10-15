/* Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
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
SDName: Boss_Muru
SD%Complete: 80
SDComment: all sounds, black hole effect triggers to often (46228)
*/

#include "precompiled.h"
#include "def_sunwell_plateau.h"

// Muru & Entropius's spells
enum Spells
{
    SPELL_ENRAGE                = 26662,

    // Muru's spells
    SPELL_NEGATIVE_ENERGY        = 46009, //(this trigger 46008)
    SPELL_DARKNESS                = 45999,
    SPELL_OPEN_ALL_PORTALS        = 46177,
    SPELL_OPEN_PORTAL            = 45977,
    SPELL_OPEN_PORTAL_2            = 45976,
    SPELL_SUMMON_BERSERKER        = 46037,
    SPELL_SUMNON_FURY_MAGE        = 46038,
    SPELL_SUMMON_VOID_SENTINEL    = 45988,
    SPELL_SUMMON_ENTROPIUS        = 46217,

    // Entropius's spells
    SPELL_DARKNESS_E            = 46269,
    SPELL_BLACKHOLE             = 46282,
    SPELL_NEGATIVE_ENERGY_E     = 46284,
    SPELL_ENTROPIUS_SPAWN        = 46223,

    // Shadowsword Berserker's spells
    SPELL_FLURRY                = 46160,
    SPELL_DUAL_WIELD            = 29651,

    // Shadowsword Fury Mage's spells
    SPELL_FEL_FIREBALL          = 46101,
    SPELL_SPELL_FURY            = 46102,

    // Void Sentinel's spells
    SPELL_SHADOW_PULSE          = 46087,
    SPELL_VOID_BLAST            = 46161,

    // Void Spawn's spells
    SPELL_SHADOW_BOLT_VOLLEY    = 46082,

    //Dark Fiend Spells
    SPELL_DARKFIEND_AOE            = 45944,
    SPELL_DARKFIEND_VISUAL        = 45936,
    SPELL_DARKFIEND_SKIN        = 45934,

    //Black Hole Spells
    SPELL_BLACKHOLE_SPAWN        = 46242,
    SPELL_BLACKHOLE_GROW        = 46228
};

enum Creatures
{
    CREATURE_DARKNESS            = 25879,
    CREATURE_DARK_FIENDS        = 25744,
    CREATURE_BERSERKER            = 25798,
    CREATURE_FURY_MAGE            = 25799,
    CREATURE_VOID_SENTINEL        = 25772,
    CREATURE_VOID_SPAWN            = 25824,
    CREATURE_BLACK_HOLE            = 25855,
    BOSS_MURU                    = 25741,
    BOSS_ENTROPIUS                = 25840
};

enum BossTimers{
    TIMER_DARKNESS                = 0,
    TIMER_HUMANOIDES            = 1,
    TIMER_PHASE                    = 2,
    TIMER_SENTINEL                = 3
};

float DarkFiends[8][4] =
{
    {1819.9,    609.80,    69.74,    1.94},
    {1829.39,   617.89,    69.73,    2.61},
    {1801.98,   633.62,    69.74,    5.71},
    {1830.88,   629.99,    69.73,    3.52},
    {1800.38,   621.41,    69.74,    0.22},
    {1808.3 ,   612.45,    69.73,    1.02},
    {1823.9 ,   639.69,    69.74,    4.12},
    {1811.85,   640.46,    69.73,    4.97}
};

float Humanoides[6][5] =
{
    {CREATURE_FURY_MAGE, 1780.16,    666.83,    71.19,    5.21},
    {CREATURE_FURY_MAGE, 1847.93,    600.30,    71.30,    2.57},
    {CREATURE_BERSERKER, 1779.97,    660.64,    71.19,    5.28},
    {CREATURE_BERSERKER, 1786.2 ,    661.01,    71.19,    4.51},
    {CREATURE_BERSERKER, 1845.17,    602.63,    71.28,    2.43},
    {CREATURE_BERSERKER, 1842.91,    599.93,    71.23,    2.44}
};

uint32 EnrageTimer = 600000;
struct TRINITY_DLL_DECL boss_entropiusAI : public ScriptedAI
{
    boss_entropiusAI(Creature *c) : ScriptedAI(c), Summons(m_creature)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    SummonList Summons;

    uint32 BlackHoleSummonTimer;

    void Reset()
    {
        BlackHoleSummonTimer = 15000;
        DoCastAOE(SPELL_NEGATIVE_ENERGY_E, false);

        Summons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_MURU_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoCastAOE(SPELL_NEGATIVE_ENERGY_E, true);
        DoCast(m_creature, SPELL_ENTROPIUS_SPAWN, false);

        if (pInstance)
            pInstance->SetData(DATA_MURU_EVENT, IN_PROGRESS);
    }

    void JustSummoned(Creature* summoned)
    {
        switch(summoned->GetEntry())
        {
            case CREATURE_DARK_FIENDS:
                summoned->CastSpell(summoned,SPELL_DARKFIEND_VISUAL,false);
                break;
            case CREATURE_DARKNESS:
                summoned->addUnitState(UNIT_STAT_STUNNED);
                float x,y,z,o;
                summoned->GetHomePosition(x,y,z,o);
                m_creature->SummonCreature(CREATURE_DARK_FIENDS, x,y,z,o, TEMPSUMMON_CORPSE_DESPAWN, 0);
                break;
        }
        summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM,0, 50, true));
        Summons.Summon(summoned);
    }

    void JustDied(Unit* killer)
    {
        Summons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_MURU_EVENT, DONE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (EnrageTimer < diff && !m_creature->HasAura(SPELL_ENRAGE, 0))
        {
            DoCast(m_creature,SPELL_ENRAGE, false);
        }else EnrageTimer -= diff;

        if (BlackHoleSummonTimer < diff)
        {
            Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
            if (!random)
                return;

            DoCast(random, SPELL_DARKNESS_E, false);

            random = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
            if (!random)
                return;

            random->CastSpell(random, SPELL_BLACKHOLE, false);
            BlackHoleSummonTimer = 15000;
        }else BlackHoleSummonTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_entropius(Creature* pCreature)
{
    return new boss_entropiusAI (pCreature);
}

struct TRINITY_DLL_DECL boss_muruAI : public Scripted_NoMovementAI
{
    boss_muruAI(Creature *c) : Scripted_NoMovementAI(c), Summons(m_creature)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;
    SummonList Summons;

    uint8 Phase;
    uint32 Timer[4];

    bool DarkFiend;

    void Reset()
    {
        DarkFiend = false;
        Phase = 1;

        EnrageTimer = 600000;
        Timer[TIMER_DARKNESS] = 45000;
        Timer[TIMER_HUMANOIDES] = 10000;
        Timer[TIMER_PHASE] = 2000;
        Timer[TIMER_SENTINEL] = 31500;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        m_creature->SetVisibility(VISIBILITY_ON);

        Summons.DespawnAll();

        if (pInstance)
            pInstance->SetData(DATA_MURU_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoCastAOE(SPELL_NEGATIVE_ENERGY,false);

        if (pInstance)
            pInstance->SetData(DATA_MURU_EVENT, IN_PROGRESS);
    }

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if (damage > m_creature->GetHealth() && Phase == 1)
        {
            damage = 0;
            Phase = 2;
            m_creature->RemoveAllAuras();
            DoCast(m_creature, SPELL_OPEN_ALL_PORTALS, false);
            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
        if (Phase > 1 && Phase < 4)
            damage = 0;
    }

    void JustSummoned(Creature* summoned)
    {
        switch(summoned->GetEntry())
        {
            case BOSS_ENTROPIUS:
                m_creature->SetVisibility(VISIBILITY_OFF);
                break;
            case CREATURE_DARK_FIENDS:
                summoned->CastSpell(summoned,SPELL_DARKFIEND_VISUAL,false);
                break;
        }
        summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM,0, 50, true));
        Summons.Summon(summoned);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (Phase == 3)
        {
            if (Timer[TIMER_PHASE] <diff)
            {
                if(!pInstance)
                    return;
                switch(pInstance->GetData(DATA_MURU_EVENT))
                {
                    case NOT_STARTED:
                        Reset();
                        break;
                    case DONE:
                        Phase = 4;
                        m_creature->DisappearAndDie();
                        break;
                }
                Timer[TIMER_PHASE] = 3000;
            }else Timer[TIMER_PHASE] -= diff;
            return;
        }

        if (EnrageTimer < diff && !m_creature->HasAura(SPELL_ENRAGE, 0))
        {
            DoCast(m_creature, SPELL_ENRAGE, false);
        }else EnrageTimer -= diff;

        for (uint8 i = 0; i < 4; ++i)
        {
            if (Timer[i] < diff)
            {
                switch(i)
                {
                    case TIMER_DARKNESS:
                        if (!DarkFiend)
                        {
                            DoCastAOE(SPELL_DARKNESS, false);
                            Timer[TIMER_DARKNESS] = 3000;
                            DarkFiend = true;
                        }
                        else
                        {
                            DarkFiend = false;
                            for(uint8 i = 0; i < 8; ++i)
                                m_creature->SummonCreature(CREATURE_DARK_FIENDS,DarkFiends[i][0],DarkFiends[i][1],DarkFiends[i][2], DarkFiends[i][3], TEMPSUMMON_CORPSE_DESPAWN, 0);
                            Timer[TIMER_DARKNESS] = 42000;
                        }
                        break;
                    case TIMER_HUMANOIDES:
                        for(uint8 i = 0; i < 6; ++i)
                            m_creature->SummonCreature(Humanoides[i][0],Humanoides[i][1],Humanoides[i][2],Humanoides[i][3], Humanoides[i][4], TEMPSUMMON_CORPSE_DESPAWN, 0);
                        Timer[TIMER_HUMANOIDES] = 60000;
                        break;
                    case TIMER_PHASE:
                        m_creature->RemoveAllAuras();
                        DoCast(m_creature, SPELL_SUMMON_ENTROPIUS, false);
                        Timer[TIMER_PHASE] = 3000;
                        Phase = 3;
                        return;
                    case TIMER_SENTINEL:
                        DoCastAOE(SPELL_OPEN_PORTAL_2, false);
                        Timer[TIMER_SENTINEL] = 30000;
                        break;
                }
                break;
            }
        }

        //Timer
        for(uint8 i = 0; i < 4; ++i)
        {
            if (i != TIMER_PHASE)Timer[i] -= diff;
            else if (Phase == 2) Timer[i] -= diff;
        }
    }
};

CreatureAI* GetAI_boss_muru(Creature* pCreature)
{
    return new boss_muruAI (pCreature);
}

struct TRINITY_DLL_DECL npc_muru_portalAI : public Scripted_NoMovementAI
{
    npc_muru_portalAI(Creature *c) : Scripted_NoMovementAI(c), Summons(m_creature)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    SummonList Summons;
    Creature* Muru;

    bool SummonSentinel;
    bool InAction;

    uint32 SummonTimer;

    void Reset()
    {
        SummonTimer = 5000;

        InAction = false;
        SummonSentinel = false;

        m_creature->addUnitState(UNIT_STAT_STUNNED);

        Summons.DespawnAll();
    }

    void JustSummoned(Creature* summoned)
    {
        if (pInstance)
            if (Player* Target = Unit::GetPlayer(pInstance->GetData64(DATA_PLAYER_GUID)))
                summoned->AI()->AttackStart(Target);

        Summons.Summon(summoned);
    }

    void SpellHit(Unit* caster, const SpellEntry* Spell)
    {
        float x,y,z,o;
        m_creature->GetHomePosition(x,y,z,o);
        DoTeleportTo(x,y,z);
        InAction = true;
        switch(Spell->Id)
        {
            case SPELL_OPEN_ALL_PORTALS:
                DoCastAOE(SPELL_OPEN_PORTAL, false);
                break;
            case SPELL_OPEN_PORTAL_2:
                DoCastAOE(SPELL_OPEN_PORTAL, false);
                SummonSentinel = true;
                break;
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!SummonSentinel)
        {
            if (InAction && pInstance && pInstance->GetData(DATA_MURU_EVENT) == NOT_STARTED)
                Reset();
            return;
        }
        if (SummonTimer < diff)
        {
            DoCastAOE(SPELL_SUMMON_VOID_SENTINEL, false);
            SummonTimer = 5000;
            SummonSentinel = false;
        }else SummonTimer -= diff;
    }
};

CreatureAI* GetAI_npc_muru_portal(Creature* pCreature)
{
    return new npc_muru_portalAI (pCreature);
}

struct TRINITY_DLL_DECL npc_dark_fiendAI : public ScriptedAI
{
    npc_dark_fiendAI(Creature *c) : ScriptedAI(c) {}

    uint32 WaitTimer;
    bool InAction;

    void Reset()
    {
        WaitTimer = 2000;
        InAction = false;

        m_creature->addUnitState(UNIT_STAT_STUNNED);
    }

    void SpellHit(Unit* caster, const SpellEntry* Spell)
    {
        for(uint8 i = 0; i < 3; ++i)
            if (Spell->Effect[i] == 38)
                m_creature->DisappearAndDie();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (WaitTimer < diff)
        {
            if (!InAction)
            {
                m_creature->clearUnitState(UNIT_STAT_STUNNED);
                DoCastAOE(SPELL_DARKFIEND_SKIN, false);
                AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true));
                InAction = true;
                WaitTimer = 500;
            }
            else
            {

                if (m_creature->IsWithinDist(m_creature->getVictim(), 5))
                {
                    DoCastAOE(SPELL_DARKFIEND_AOE, false);
                    m_creature->DisappearAndDie();
                }
                WaitTimer = 500;
            }
        } else WaitTimer -= diff;
    }
};

CreatureAI* GetAI_npc_dark_fiend(Creature* pCreature)
{
    return new npc_dark_fiendAI (pCreature);
}

struct TRINITY_DLL_DECL npc_void_sentinelAI : public ScriptedAI
{
    npc_void_sentinelAI(Creature *c) : ScriptedAI(c){}

    uint32 PulseTimer;
    uint32 VoidBlastTimer;

    void Reset()
    {
        PulseTimer = 3000;
        VoidBlastTimer = 45000; //is this a correct timer?

        float x,y,z,o;
        m_creature->GetHomePosition(x,y,z,o);
        DoTeleportTo(x,y,71);
    }

    void JustDied(Unit* killer)
    {
        for (uint8 i = 0; i < 8; ++i)
            m_creature->SummonCreature(CREATURE_VOID_SPAWN, m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(), rand()%6, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 180000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (PulseTimer < diff)
        {
            DoCastAOE(SPELL_SHADOW_PULSE, true);
            PulseTimer = 3000;
        } else PulseTimer -= diff;

        if (VoidBlastTimer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_VOID_BLAST, false);
            VoidBlastTimer = 45000;
        } else VoidBlastTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_void_sentinel(Creature* pCreature)
{
    return new npc_void_sentinelAI (pCreature);
}

struct TRINITY_DLL_DECL npc_blackholeAI : public ScriptedAI
{
    npc_blackholeAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 DespawnTimer;
    uint32 SpellTimer;
    uint8 Phase;
    uint8 NeedForAHack;

    void Reset()
    {
        DespawnTimer = 15000;
        SpellTimer = 5000;
        Phase = 0;

        m_creature->addUnitState(UNIT_STAT_STUNNED);
        DoCastAOE(SPELL_BLACKHOLE_SPAWN, true);
    }

    void UpdateAI(const uint32 diff)
    {
        if (SpellTimer < diff)
        {
            Unit* Victim = Unit::GetUnit(*m_creature, pInstance ? pInstance->GetData64(DATA_PLAYER_GUID) : 0);
            switch (NeedForAHack)
            {
                case 0:
                    m_creature->clearUnitState(UNIT_STAT_STUNNED);
                    DoCastAOE(SPELL_BLACKHOLE_GROW, false);
                    if (Victim)
                        AttackStart(Victim);
                    SpellTimer = 700;
                    NeedForAHack = 2;
                    break;
                case 1:
                    m_creature->AddAura(SPELL_BLACKHOLE_GROW, m_creature);
                    NeedForAHack = 2;
                    SpellTimer = 600;
                    break;
                case 2:
                    SpellTimer = 400;
                    NeedForAHack = 3;
                    m_creature->RemoveAura(SPELL_BLACKHOLE_GROW, 1);
                    break;
                case 3:
                    SpellTimer = urand(400,900);
                    NeedForAHack = 1;
                    if (Unit* Temp = m_creature->getVictim())
                    {
                        if (Temp->GetPositionZ() > 73 && Victim)
                            AttackStart(Victim);
                    } else
                        return;
            }
        } else SpellTimer -= diff;

        if (DespawnTimer < diff)
            m_creature->DisappearAndDie();
        else DespawnTimer -= diff;
    }
};

CreatureAI* GetAI_npc_blackhole(Creature* pCreature)
{
    return new npc_blackholeAI (pCreature);
}

void AddSC_boss_muru()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_muru";
    newscript->GetAI = &GetAI_boss_muru;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_entropius";
    newscript->GetAI = &GetAI_boss_entropius;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_muru_portal";
    newscript->GetAI = &GetAI_npc_muru_portal;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dark_fiend";
    newscript->GetAI = &GetAI_npc_dark_fiend;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_void_sentinel";
    newscript->GetAI = &GetAI_npc_void_sentinel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_blackhole";
    newscript->GetAI = &GetAI_npc_blackhole;
    newscript->RegisterSelf();
}
