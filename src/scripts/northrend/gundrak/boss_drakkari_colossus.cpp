/*
 * Copyright (C) 2009 - 2010 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Comment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make the boss enter in combat!
 */

#include "ScriptedPch.h"
#include "gundrak.h"

enum Spells
{
    SPELL_EMERGE                                  = 54850,
    SPELL_MIGHTY_BLOW                             = 54719,
    SPELL_MERGE                                   = 54878,
    SPELL_SURGE                                   = 54801,
    SPELL_FREEZE_ANIM                             = 16245,
    SPELL_MOJO_PUDDLE                             = 55627,
    H_SPELL_MOJO_PUDDLE                           = 58994,
    SPELL_MOJO_WAVE                               = 55626,
    H_SPELL_MOJO_WAVE                             = 58993
};

struct boss_drakkari_colossusAI : public ScriptedAI
{
    boss_drakkari_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    bool bHealth;
    bool bHealth1;

    uint32 MightyBlowTimer;

    void Reset()
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, NOT_STARTED);
        if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE))
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->clearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
        me->SetReactState(REACT_PASSIVE);
        MightyBlowTimer = 10*IN_MILISECONDS;
        bHealth = false;
        bHealth1 = false;
    }

    void EnterCombat(Unit* /*who*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, IN_PROGRESS);
    }

    void CreatureState(Creature* pWho, bool bRestore = false)
    {
        if (!pWho)
            return;

        if (bRestore)
        {
            pWho->clearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
            pWho->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            if (pWho == me)
                me->RemoveAura(SPELL_FREEZE_ANIM);
        }else
        {
            pWho->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            pWho->addUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
            if (pWho == me)
                DoCast(me,SPELL_FREEZE_ANIM);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!bHealth && HealthBelowPct(50) &&  !HealthBelowPct(5))
        {
            CreatureState(me, false);
            DoCast(me,SPELL_FREEZE_ANIM);
            DoCast(me,SPELL_EMERGE);
            bHealth = true;
        }

        if (!bHealth1 && HealthBelowPct(5))
        {
            DoCast(me,SPELL_EMERGE);
            CreatureState(me, false);
            bHealth1 = true;
            me->RemoveAllAuras();
        }

        if (MightyBlowTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_MIGHTY_BLOW, true);
            MightyBlowTimer = 10*IN_MILISECONDS;
        } else MightyBlowTimer -= diff;

        if (!me->hasUnitState(UNIT_STAT_STUNNED))
            DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRAKKARI_COLOSSUS_EVENT, DONE);
    }

    void JustSummoned(Creature* pSummon)
    {
        if (HealthBelowPct(5))
            pSummon->DealDamage(pSummon, pSummon->GetHealth() * 0.5 , NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
        pSummon->AI()->AttackStart(me->getVictim());
    }
};

struct boss_drakkari_elementalAI : public ScriptedAI
{
    boss_drakkari_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiSurgeTimer;

    bool bGoToColossus;

    void Reset()
    {
        if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
            CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->CreatureState(me, true);
        uiSurgeTimer = 7*IN_MILISECONDS;
        bGoToColossus = false;
    }

    void EnterEvadeMode()
    {
        me->RemoveFromWorld();
    }

    void MovementInform(uint32 uiType, uint32 /*uiId*/)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;
        if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
        {
            CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->CreatureState(pColossus, true);
            CAST_AI(boss_drakkari_colossusAI, pColossus->AI())->bHealth1 = false;
        }
        me->RemoveFromWorld();
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (!bGoToColossus && HealthBelowPct(50))
        {
            if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
            {
                if (!CAST_AI(boss_drakkari_colossusAI,pColossus->AI())->HealthBelowPct(6))
                {
                    me->InterruptNonMeleeSpells(true);
                    DoCast(pColossus, SPELL_MERGE);
                    bGoToColossus = true;
                }
            }
        }

        if (uiSurgeTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_SURGE);
            uiSurgeTimer = 7*IN_MILISECONDS;
        } else uiSurgeTimer -= diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* /*killer*/)
    {
        if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
            pColossus->Kill(pColossus);
    }
};

struct npc_living_mojoAI : public ScriptedAI
{
    npc_living_mojoAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pInstance = pCreature->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 uiMojoWaveTimer;
    uint32 uiMojoPuddleTimer;

    void Reset()
    {
        uiMojoWaveTimer = 2*IN_MILISECONDS;
        uiMojoPuddleTimer = 7*IN_MILISECONDS;
    }

    void EnterCombat(Unit* /*who*/)
    {

        //Check if the npc is near of Drakkari Colossus.
        if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
        {
            if (pColossus->isAlive() && me->IsInRange3d(pColossus->GetHomePosition().GetPositionX(),pColossus->GetHomePosition().GetPositionY(),pColossus->GetHomePosition().GetPositionZ(),0.0f,17.0f))
                me->SetReactState(REACT_PASSIVE);
            else
                me->SetReactState(REACT_AGGRESSIVE);
        }
    }

    void DamageTaken(Unit* pDone_by, uint32& /*uiDamage*/)
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
            {
                if (pColossus->isAlive() && !pColossus->isInCombat())
                {
                    pColossus->RemoveAura(SPELL_FREEZE_ANIM);
                    pColossus->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                    pColossus->SetReactState(REACT_AGGRESSIVE);
                    if (pDone_by && pDone_by->isAlive())
                        pColossus->AI()->AttackStart(pDone_by);
                    EnterEvadeMode();
                }
            }
        }
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (uiMojoWaveTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_MOJO_WAVE);
            uiMojoWaveTimer = 15*IN_MILISECONDS;
        } else uiMojoWaveTimer -= diff;

        if (uiMojoPuddleTimer <= diff)
        {
            DoCast(me->getVictim(), SPELL_MOJO_PUDDLE);
            uiMojoPuddleTimer = 18*IN_MILISECONDS;
        } else uiMojoPuddleTimer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_drakkari_colossus(Creature* pCreature)
{
    return new boss_drakkari_colossusAI (pCreature);
}

CreatureAI* GetAI_boss_drakkari_elemental(Creature* pCreature)
{
    return new boss_drakkari_elementalAI (pCreature);
}

CreatureAI* GetAI_npc_living_mojo(Creature* pCreature)
{
    return new npc_living_mojoAI (pCreature);
}

void AddSC_boss_drakkari_colossus()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "boss_drakkari_colossus";
    newscript->GetAI = &GetAI_boss_drakkari_colossus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_drakkari_elemental";
    newscript->GetAI = &GetAI_boss_drakkari_elemental;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_living_mojo";
    newscript->GetAI = &GetAI_npc_living_mojo;
    newscript->RegisterSelf();
}
