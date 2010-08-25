/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Comment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make the boss enter in combat!
 */

#include "ScriptPCH.h"
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

class boss_drakkari_colossus : public CreatureScript
{
public:
    boss_drakkari_colossus() : CreatureScript("boss_drakkari_colossus") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_drakkari_colossusAI (pCreature);
    }

    struct boss_drakkari_colossusAI : public ScriptedAI
    {
        boss_drakkari_colossusAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

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
            MightyBlowTimer = 10*IN_MILLISECONDS;
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

            if (!bHealth && HealthBelowPct(50) && !HealthBelowPct(5))
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
                MightyBlowTimer = 10*IN_MILLISECONDS;
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
                pSummon->DealDamage(pSummon, pSummon->GetHealth() * 0.5, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            pSummon->AI()->AttackStart(me->getVictim());
        }
    };

};

class boss_drakkari_elemental : public CreatureScript
{
public:
    boss_drakkari_elemental() : CreatureScript("boss_drakkari_elemental") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_drakkari_elementalAI (pCreature);
    }

    struct boss_drakkari_elementalAI : public ScriptedAI
    {
        boss_drakkari_elementalAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiSurgeTimer;

        bool bGoToColossus;

        void Reset()
        {
            if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                CAST_AI(boss_drakkari_colossus::boss_drakkari_colossusAI, pColossus->AI())->CreatureState(me, true);
            uiSurgeTimer = 7*IN_MILLISECONDS;
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
                CAST_AI(boss_drakkari_colossus::boss_drakkari_colossusAI, pColossus->AI())->CreatureState(pColossus, true);
                CAST_AI(boss_drakkari_colossus::boss_drakkari_colossusAI, pColossus->AI())->bHealth1 = false;
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
                    if (!CAST_AI(boss_drakkari_colossus::boss_drakkari_colossusAI,pColossus->AI())->HealthBelowPct(6))
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
                uiSurgeTimer = 7*IN_MILLISECONDS;
            } else uiSurgeTimer -= diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (Creature *pColossus = Unit::GetCreature(*me, pInstance ? pInstance->GetData64(DATA_DRAKKARI_COLOSSUS) : 0))
                pColossus->Kill(pColossus);
        }
    };

};

class npc_living_mojo : public CreatureScript
{
public:
    npc_living_mojo() : CreatureScript("npc_living_mojo") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_living_mojoAI (pCreature);
    }

    struct npc_living_mojoAI : public ScriptedAI
    {
        npc_living_mojoAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiMojoWaveTimer;
        uint32 uiMojoPuddleTimer;

        void Reset()
        {
            uiMojoWaveTimer = 2*IN_MILLISECONDS;
            uiMojoPuddleTimer = 7*IN_MILLISECONDS;
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
                uiMojoWaveTimer = 15*IN_MILLISECONDS;
            } else uiMojoWaveTimer -= diff;

            if (uiMojoPuddleTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MOJO_PUDDLE);
                uiMojoPuddleTimer = 18*IN_MILLISECONDS;
            } else uiMojoPuddleTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};




void AddSC_boss_drakkari_colossus()
{
    new boss_drakkari_colossus();
    new boss_drakkari_elemental();
    new npc_living_mojo();
}
