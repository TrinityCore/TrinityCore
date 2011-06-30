/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Skarvald_Dalronn
SD%Complete: 95
SDComment: Needs adjustments to blizzlike timers, Yell Text + Sound to DB
SDCategory: Utgarde Keep
EndScriptData */

#include "ScriptPCH.h"
#include "utgarde_keep.h"

enum eEnums
{
    //signed for 24200, but used by 24200, 27390
    YELL_SKARVALD_AGGRO                         = -1574011,
    YELL_SKARVALD_DAL_DIED                      = -1574012,
    YELL_SKARVALD_SKA_DIEDFIRST                 = -1574013,
    YELL_SKARVALD_KILL                          = -1574014,
    YELL_SKARVALD_DAL_DIEDFIRST                 = -1574015,

    //signed for 24201, but used by 24201, 27389
    YELL_DALRONN_AGGRO                          = -1574016,
    YELL_DALRONN_SKA_DIED                       = -1574017,
    YELL_DALRONN_DAL_DIEDFIRST                  = -1574018,
    YELL_DALRONN_KILL                           = -1574019,
    YELL_DALRONN_SKA_DIEDFIRST                  = -1574020,

//Spells of Skarvald and his Ghost
    MOB_SKARVALD_THE_CONSTRUCTOR                = 24200,
    SPELL_CHARGE                                = 43651,
    SPELL_STONE_STRIKE                          = 48583,
    SPELL_SUMMON_SKARVALD_GHOST                 = 48613,
    MOB_SKARVALD_GHOST                          = 27390,
//Spells of Dalronn and his Ghost
    MOB_DALRONN_THE_CONTROLLER                  = 24201,
    SPELL_SHADOW_BOLT                           = 43649,
    H_SPELL_SHADOW_BOLT                         = 59575,
    H_SPELL_SUMMON_SKELETONS                    = 52611,
    SPELL_DEBILITATE                            = 43650,
    SPELL_SUMMON_DALRONN_GHOST                  = 48612,
    MOB_DALRONN_GHOST                           = 27389
};

class boss_skarvald_the_constructor : public CreatureScript
{
public:
    boss_skarvald_the_constructor() : CreatureScript("boss_skarvald_the_constructor") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_skarvald_the_constructorAI (pCreature);
    }

    struct boss_skarvald_the_constructorAI : public ScriptedAI
    {
        boss_skarvald_the_constructorAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        bool ghost;
        uint32 Charge_Timer;
        uint32 StoneStrike_Timer;
        uint32 Response_Timer;
        uint32 Check_Timer;
        bool Dalronn_isDead;

        void Reset()
        {
            Charge_Timer = 5000;
            StoneStrike_Timer = 10000;
            Dalronn_isDead = false;
            Check_Timer = 5000;

            ghost = (me->GetEntry() == MOB_SKARVALD_GHOST);
            if (!ghost && pInstance)
            {
                Unit* dalronn = Unit::GetUnit((*me), pInstance->GetData64(DATA_DALRONN));
                if (dalronn && dalronn->isDead())
                    CAST_CRE(dalronn)->Respawn();

                pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* who)
        {
            if (!ghost && pInstance)
            {
                DoScriptText(YELL_SKARVALD_AGGRO, me);

                Unit* dalronn = Unit::GetUnit((*me), pInstance->GetData64(DATA_DALRONN));
                if (dalronn && dalronn->isAlive() && !dalronn->getVictim())
                    dalronn->getThreatManager().addThreat(who, 0.0f);

                pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* Killer)
        {
            if (!ghost && pInstance)
            {
                Unit* dalronn = Unit::GetUnit((*me), pInstance->GetData64(DATA_DALRONN));
                if (dalronn)
                {
                    if (dalronn->isDead())
                    {
                        DoScriptText(YELL_SKARVALD_DAL_DIED, me);

                        pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, DONE);
                    }
                    else
                    {
                        DoScriptText(YELL_SKARVALD_SKA_DIEDFIRST, me);

                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                        //DoCast(me, SPELL_SUMMON_SKARVALD_GHOST, true);
                        Creature* temp = me->SummonCreature(MOB_SKARVALD_GHOST, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 5000);
                        if (temp)
                        {
                            temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            temp->AI()->AttackStart(Killer);
                        }
                    }
                }
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (!ghost)
            {
                DoScriptText(YELL_SKARVALD_KILL, me);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (ghost)
            {
                if (pInstance && pInstance->GetData(DATA_SKARVALD_DALRONN_EVENT) != IN_PROGRESS)
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }

            if (!UpdateVictim())
                return;

            if (!ghost)
            {
                if (Check_Timer)
                {
                    if (Check_Timer <= diff)
                    {
                        Check_Timer = 5000;
                        Unit* dalronn = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_DALRONN) : 0);
                        if (dalronn && dalronn->isDead())
                        {
                            Dalronn_isDead = true;
                            Response_Timer = 2000;
                            Check_Timer = 0;
                        }
                    } else Check_Timer -= diff;
                }
                if (Response_Timer && Dalronn_isDead)
                {
                    if (Response_Timer <= diff)
                    {
                        DoScriptText(YELL_SKARVALD_DAL_DIEDFIRST, me);

                        Response_Timer = 0;
                    } else Response_Timer -= diff;
                }
            }

            if (Charge_Timer <= diff)
            {
                DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_CHARGE);
                Charge_Timer = 5000+rand()%5000;
            } else Charge_Timer -= diff;

            if (StoneStrike_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_STONE_STRIKE);
                StoneStrike_Timer = 5000+rand()%5000;
            } else StoneStrike_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

class boss_dalronn_the_controller : public CreatureScript
{
public:
    boss_dalronn_the_controller() : CreatureScript("boss_dalronn_the_controller") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_dalronn_the_controllerAI (pCreature);
    }

    struct boss_dalronn_the_controllerAI : public ScriptedAI
    {
        boss_dalronn_the_controllerAI(Creature* c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        bool ghost;
        uint32 ShadowBolt_Timer;
        uint32 Debilitate_Timer;
        uint32 Summon_Timer;

        uint32 Response_Timer;
        uint32 Check_Timer;
        uint32 AggroYell_Timer;
        bool Skarvald_isDead;

        void Reset()
        {
            ShadowBolt_Timer = 1000;
            Debilitate_Timer = 5000;
            Summon_Timer = 10000;
            Check_Timer = 5000;
            Skarvald_isDead = false;
            AggroYell_Timer = 0;

            ghost = me->GetEntry() == MOB_DALRONN_GHOST;
            if (!ghost && pInstance)
            {
                Unit* skarvald = Unit::GetUnit((*me), pInstance->GetData64(DATA_SKARVALD));
                if (skarvald && skarvald->isDead())
                    CAST_CRE(skarvald)->Respawn();

                pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* who)
        {
            if (!ghost && pInstance)
            {
                Unit* skarvald = Unit::GetUnit((*me), pInstance->GetData64(DATA_SKARVALD));
                if (skarvald && skarvald->isAlive() && !skarvald->getVictim())
                    skarvald->getThreatManager().addThreat(who, 0.0f);

                AggroYell_Timer = 5000;

                if (pInstance)
                    pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, IN_PROGRESS);
            }
        }

        void JustDied(Unit* Killer)
        {
            if (!ghost && pInstance)
            {
                Unit* skarvald = Unit::GetUnit((*me), pInstance->GetData64(DATA_SKARVALD));
                if (skarvald)
                {
                    if (skarvald->isDead())
                    {
                        DoScriptText(YELL_DALRONN_SKA_DIED, me);

                        if (pInstance)
                            pInstance->SetData(DATA_SKARVALD_DALRONN_EVENT, DONE);
                    }
                    else
                    {
                        DoScriptText(YELL_DALRONN_DAL_DIEDFIRST, me);

                        me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
                        //DoCast(me, SPELL_SUMMON_DALRONN_GHOST, true);
                        Creature* temp = me->SummonCreature(MOB_DALRONN_GHOST, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 5000);
                        if (temp)
                        {
                            temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            temp->AI()->AttackStart(Killer);
                        }
                    }
                }
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (!ghost)
            {
                DoScriptText(YELL_DALRONN_KILL, me);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (ghost)
            {
                if (pInstance && pInstance->GetData(DATA_SKARVALD_DALRONN_EVENT) != IN_PROGRESS)
                    me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
            }

            if (!UpdateVictim())
                return;

            if (AggroYell_Timer)
            {
                if (AggroYell_Timer <= diff)
                {
                    DoScriptText(YELL_DALRONN_AGGRO, me);

                    AggroYell_Timer = 0;
                } else AggroYell_Timer -= diff;
            }

            if (!ghost)
            {
                if (Check_Timer)
                {
                    if (Check_Timer <= diff)
                    {
                        Check_Timer = 5000;
                        Unit* skarvald = Unit::GetUnit(*me, pInstance ? pInstance->GetData64(DATA_SKARVALD) : 0);
                        if (skarvald && skarvald->isDead())
                        {
                            Skarvald_isDead = true;
                            Response_Timer = 2000;
                            Check_Timer = 0;
                        }
                    } else Check_Timer -= diff;
                }

                if (Response_Timer && Skarvald_isDead)
                {
                    if (Response_Timer <= diff)
                    {
                        DoScriptText(YELL_DALRONN_SKA_DIEDFIRST, me);
                        Response_Timer = 0;
                    } else Response_Timer -= diff;
                }
            }

            if (ShadowBolt_Timer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_SHADOW_BOLT);
                    ShadowBolt_Timer = 2100;//give a 100ms pause to try cast other spells
                }
            } else ShadowBolt_Timer -= diff;

            if (Debilitate_Timer <= diff)
            {
                if (!me->IsNonMeleeSpellCasted(false))
                {
                    DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_DEBILITATE);
                    Debilitate_Timer = 5000+rand()%5000;
                }
            } else Debilitate_Timer -= diff;

            if (IsHeroic())
            {
                if (Summon_Timer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(me, H_SPELL_SUMMON_SKELETONS);
                        Summon_Timer = (rand()%10000) + 20000;
                    }
                } else Summon_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_skarvald_dalronn()
{
    new boss_skarvald_the_constructor();
    new boss_dalronn_the_controller();
}
