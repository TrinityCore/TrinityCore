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
SDName: Boss_Kelidan_The_Breaker
SD%Complete: 100
SDComment:
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

/* ContentData
boss_kelidan_the_breaker
mob_shadowmoon_channeler
EndContentData */

#include "precompiled.h"
#include "blood_furnace.h"

enum eKelidan
{
    SAY_WAKE                    = -1542000,
    SAY_ADD_AGGRO_1             = -1542001,
    SAY_ADD_AGGRO_2             = -1542002,
    SAY_ADD_AGGRO_3             = -1542003,
    SAY_KILL_1                  = -1542004,
    SAY_KILL_2                  = -1542005,
    SAY_NOVA                    = -1542006,
    SAY_DIE                     = -1542007,

    SPELL_CORRUPTION            = 30938,
    SPELL_EVOCATION             = 30935,

    SPELL_FIRE_NOVA             = 33132,
    H_SPELL_FIRE_NOVA           = 37371,

    SPELL_SHADOW_BOLT_VOLLEY    = 28599,
    H_SPELL_SHADOW_BOLT_VOLLEY  = 40070,

    SPELL_BURNING_NOVA          = 30940,
    SPELL_VORTEX                = 37370,

    ENTRY_KELIDAN               = 17377,
    ENTRY_CHANNELER             = 17653
};

const float ShadowmoonChannelers[5][4]=
{
    {302,-87,-24.4,0.157},
    {321,-63.5,-24.6,4.887},
    {346,-74.5,-24.6,3.595},
    {344,-103.5,-24.5,2.356},
    {316,-109,-24.6,1.257}
};

struct TRINITY_DLL_DECL boss_kelidan_the_breakerAI : public ScriptedAI
{
    boss_kelidan_the_breakerAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
        for (uint8 i=0; i<5; ++i)
            Channelers[i] = 0;
    }

    ScriptedInstance* pInstance;

    uint32 ShadowVolley_Timer;
    uint32 BurningNova_Timer;
    uint32 Firenova_Timer;
    uint32 Corruption_Timer;
    uint32 check_Timer;
    bool Firenova;
    bool addYell;
    uint64 Channelers[5];

    void Reset()
    {
        ShadowVolley_Timer = 1000;
        BurningNova_Timer = 15000;
        Corruption_Timer = 5000;
        check_Timer = 0;
        Firenova = false;
        addYell = false;
        SummonChannelers();
        if (pInstance)
            pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, NOT_STARTED);
    }

    void EnterCombat(Unit *who)
    {
        DoScriptText(SAY_WAKE, m_creature);
        if (m_creature->IsNonMeleeSpellCasted(false))
            m_creature->InterruptNonMeleeSpells(true);
        DoStartMovement(who);
        if (pInstance)
            pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, IN_PROGRESS);
    }

    void KilledUnit(Unit* victim)
    {
        if (rand()%2)
            return;

        DoScriptText(RAND(SAY_KILL_1,SAY_KILL_2), m_creature);
    }

    void ChannelerEngaged(Unit* who)
    {
        if (who && !addYell)
        {
            addYell = true;
            DoScriptText(RAND(SAY_ADD_AGGRO_1,SAY_ADD_AGGRO_2,SAY_ADD_AGGRO_3), m_creature);
        }
        for (uint8 i=0; i<5; ++i)
        {
            Creature *channeler = Unit::GetCreature(*m_creature, Channelers[i]);
            if (who && channeler && !channeler->isInCombat())
                channeler->AI()->AttackStart(who);
        }
    }

    void ChannelerDied(Unit* killer)
    {
        for (uint8 i=0; i<5; ++i)
        {
            Creature *channeler = Unit::GetCreature(*m_creature, Channelers[i]);
            if (channeler && channeler->isAlive())
                return;
        }

        if (killer)
            m_creature->AI()->AttackStart(killer);
    }

    uint64 GetChanneled(Creature *channeler1)
    {
        SummonChannelers();
        if (!channeler1) return NULL;
        uint8 i;
        for (i=0; i<5; ++i)
        {
            Creature *channeler = Unit::GetCreature(*m_creature, Channelers[i]);
            if (channeler && channeler->GetGUID() == channeler1->GetGUID())
                break;
        }
        return Channelers[(i+2)%5];
    }

    void SummonChannelers()
    {
        for (uint8 i=0; i<5; ++i)
        {
            Creature *channeler = Unit::GetCreature(*m_creature, Channelers[i]);
            if (!channeler || channeler->isDead())
                channeler = m_creature->SummonCreature(ENTRY_CHANNELER,ShadowmoonChannelers[i][0],ShadowmoonChannelers[i][1],ShadowmoonChannelers[i][2],ShadowmoonChannelers[i][3],TEMPSUMMON_CORPSE_TIMED_DESPAWN,300000);
            if (channeler)
                Channelers[i] = channeler->GetGUID();
            else
                Channelers[i] = 0;
        }
    }

    void JustDied(Unit* Killer)
    {
        DoScriptText(SAY_DIE, m_creature);

        if (!pInstance)
            return;

        pInstance->SetData(TYPE_KELIDAN_THE_BREAKER_EVENT, DONE);
        pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR1), true);
        pInstance->HandleGameObject(pInstance->GetData64(DATA_DOOR6), true);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
        {
            if (check_Timer <= diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                    DoCast(m_creature, SPELL_EVOCATION);
                check_Timer = 5000;
            } else check_Timer -= diff;
            return;
        }

        if (Firenova)
        {
            if (Firenova_Timer <= diff)
            {
                DoCast(m_creature, DUNGEON_MODE(SPELL_FIRE_NOVA, H_SPELL_FIRE_NOVA), true);
                Firenova = false;
                ShadowVolley_Timer = 2000;
            } else Firenova_Timer -=diff;

            return;
        }

        if (ShadowVolley_Timer <= diff)
        {
            DoCast(m_creature, DUNGEON_MODE(SPELL_SHADOW_BOLT_VOLLEY, H_SPELL_SHADOW_BOLT_VOLLEY));
            ShadowVolley_Timer = 5000+rand()%8000;
        } else ShadowVolley_Timer -=diff;

        if (Corruption_Timer <= diff)
        {
            DoCast(m_creature, SPELL_CORRUPTION);
            Corruption_Timer = 30000+rand()%20000;
        } else Corruption_Timer -=diff;

        if (BurningNova_Timer <= diff)
        {
            if (m_creature->IsNonMeleeSpellCasted(false))
                m_creature->InterruptNonMeleeSpells(true);

            DoScriptText(SAY_NOVA, m_creature);

            if (SpellEntry *nova = GET_SPELL(SPELL_BURNING_NOVA))
            {
                if (Aura * aura = Aura::TryCreate(nova, me, me))
                    aura->ApplyForTargets();
            }

            if (IsHeroic())
                DoTeleportAll(m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(),m_creature->GetOrientation());

            BurningNova_Timer = 20000+rand()%8000;
            Firenova_Timer= 5000;
            Firenova = true;
        } else BurningNova_Timer -=diff;

        DoMeleeAttackIfReady();
    }

};

CreatureAI* GetAI_boss_kelidan_the_breaker(Creature* pCreature)
{
    return new boss_kelidan_the_breakerAI (pCreature);
}

/*######
## mob_shadowmoon_channeler
######*/

enum eShadowmoon
{
    SPELL_SHADOW_BOLT       = 12739,
    H_SPELL_SHADOW_BOLT     = 15472,

    SPELL_MARK_OF_SHADOW    = 30937,
    SPELL_CHANNELING        = 39123
};

struct TRINITY_DLL_DECL mob_shadowmoon_channelerAI : public ScriptedAI
{
    mob_shadowmoon_channelerAI(Creature *c) : ScriptedAI(c)
    {
    }

    uint32 ShadowBolt_Timer;
    uint32 MarkOfShadow_Timer;
    uint32 check_Timer;

    void Reset()
    {
        ShadowBolt_Timer = 1000+rand()%1000;
        MarkOfShadow_Timer = 5000+rand()%2000;
        check_Timer = 0;
        if (m_creature->IsNonMeleeSpellCasted(false))
            m_creature->InterruptNonMeleeSpells(true);
    }

    void EnterCombat(Unit* who)
    {
        if (Creature *Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
            CAST_AI(boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerEngaged(who);
        if (m_creature->IsNonMeleeSpellCasted(false))
            m_creature->InterruptNonMeleeSpells(true);
        DoStartMovement(who);
    }

    void JustDied(Unit* Killer)
    {
       if (Creature *Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
           CAST_AI(boss_kelidan_the_breakerAI, Kelidan->AI())->ChannelerDied(Killer);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
        {
            if (check_Timer <= diff)
            {
                if (!m_creature->IsNonMeleeSpellCasted(false))
                    if (Creature *Kelidan = me->FindNearestCreature(ENTRY_KELIDAN, 100))
                    {
                        uint64 channeler = CAST_AI(boss_kelidan_the_breakerAI, Kelidan->AI())->GetChanneled(m_creature);
                        if (Unit *channeled = Unit::GetUnit(*m_creature, channeler))
                            DoCast(channeled, SPELL_CHANNELING);
                    }
                check_Timer = 5000;
            } else check_Timer -= diff;
            return;
        }

        if (MarkOfShadow_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                DoCast(pTarget, SPELL_MARK_OF_SHADOW);
            MarkOfShadow_Timer = 15000+rand()%5000;
        } else MarkOfShadow_Timer -=diff;

        if (ShadowBolt_Timer <= diff)
        {
            DoCast(m_creature->getVictim(), DUNGEON_MODE(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
            ShadowBolt_Timer = 5000+rand()%1000;
        } else ShadowBolt_Timer -=diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_shadowmoon_channeler(Creature* pCreature)
{
    return new mob_shadowmoon_channelerAI (pCreature);
}

void AddSC_boss_kelidan_the_breaker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_kelidan_the_breaker";
    newscript->GetAI = &GetAI_boss_kelidan_the_breaker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_shadowmoon_channeler";
    newscript->GetAI = &GetAI_mob_shadowmoon_channeler;
    newscript->RegisterSelf();
}

