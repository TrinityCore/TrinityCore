/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Warchief_Kargath_Bladefist
SD%Complete: 90
SDComment:
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

/* ContentData
boss_warchief_kargath_bladefist
EndContentData */

#include "ScriptPCH.h"

enum eSays
{
    SAY_AGGRO1                     = -1540042,
    SAY_AGGRO2                     = -1540043,
    SAY_AGGRO3                     = -1540044,
    SAY_SLAY1                      = -1540045,
    SAY_SLAY2                      = -1540046,
    SAY_DEATH                      = -1540047,
};

enum eSpells
{
     SPELL_BLADE_DANCE              = 30739,
     H_SPELL_CHARGE                 = 25821,
};

enum eCreatures
{
    MOB_SHATTERED_ASSASSIN         = 17695,
    MOB_HEARTHEN_GUARD             = 17621,
    MOB_SHARPSHOOTER_GUARD         = 17622,
    MOB_REAVER_GUARD               = 17623,
};

#define TARGET_NUM                      5

float AssassEntrance[3] = {275.136f, -84.29f, 2.3f}; // y -8
float AssassExit[3] = {184.233f, -84.29f, 2.3f}; // y -8
float AddsEntrance[3] = {306.036f, -84.29f, 1.93f};

class boss_warchief_kargath_bladefist : public CreatureScript
{
    public:

        boss_warchief_kargath_bladefist()
            : CreatureScript("boss_warchief_kargath_bladefist")
        {
        }

        struct boss_warchief_kargath_bladefistAI : public ScriptedAI
        {
            boss_warchief_kargath_bladefistAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            std::vector<uint64> adds;
            std::vector<uint64> assassins;

            uint32 Charge_timer;
            uint32 Blade_Dance_Timer;
            uint32 Summon_Assistant_Timer;
            uint32 resetcheck_timer;
            uint32 Wait_Timer;

            uint32 Assassins_Timer;

            uint32 summoned;
            bool InBlade;

            uint32 target_num;

            void Reset()
            {
                removeAdds();

                me->SetSpeed(MOVE_RUN, 2);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);

                summoned = 2;
                InBlade = false;
                Wait_Timer = 0;

                Charge_timer = 0;
                Blade_Dance_Timer = 45000;
                Summon_Assistant_Timer = 30000;
                Assassins_Timer = 5000;
                resetcheck_timer = 5000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoScriptText(RAND(SAY_AGGRO1, SAY_AGGRO2, SAY_AGGRO3), me);
            }

            void JustSummoned(Creature* summoned)
            {
                switch (summoned->GetEntry())
                {
                    case MOB_HEARTHEN_GUARD:
                    case MOB_SHARPSHOOTER_GUARD:
                    case MOB_REAVER_GUARD:
                        summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        adds.push_back(summoned->GetGUID());
                        break;
                    case MOB_SHATTERED_ASSASSIN:
                        assassins.push_back(summoned->GetGUID());
                        break;
                }
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                {
                    DoScriptText(RAND(SAY_SLAY1, SAY_SLAY2), me);
                }
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DEATH, me);
                removeAdds();
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (InBlade)
                {
                    if (type != POINT_MOTION_TYPE)
                        return;

                    if (id != 1)
                        return;

                    if (target_num > 0) // to prevent loops
                    {
                        Wait_Timer = 1;
                        DoCast(me, SPELL_BLADE_DANCE, true);
                        target_num--;
                    }
                }
            }

            void removeAdds()
            {
                for (std::vector<uint64>::const_iterator itr = adds.begin(); itr!= adds.end(); ++itr)
                {
                    Unit* temp = Unit::GetUnit((*me), *itr);
                    if (temp && temp->isAlive())
                    {
                        (*temp).GetMotionMaster()->Clear(true);
                        me->DealDamage(temp, temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        CAST_CRE(temp)->RemoveCorpse();
                    }
                }
                adds.clear();

                for (std::vector<uint64>::const_iterator itr = assassins.begin(); itr!= assassins.end(); ++itr)
                {
                    Unit* temp = Unit::GetUnit((*me), *itr);
                    if (temp && temp->isAlive())
                    {
                        (*temp).GetMotionMaster()->Clear(true);
                        me->DealDamage(temp, temp->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        CAST_CRE(temp)->RemoveCorpse();
                    }
                }
                assassins.clear();
            }
            void SpawnAssassin()
            {
                me->SummonCreature(MOB_SHATTERED_ASSASSIN, AssassEntrance[0], AssassEntrance[1]+8, AssassEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(MOB_SHATTERED_ASSASSIN, AssassEntrance[0], AssassEntrance[1]-8, AssassEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(MOB_SHATTERED_ASSASSIN, AssassExit[0], AssassExit[1]+8, AssassExit[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(MOB_SHATTERED_ASSASSIN, AssassExit[0], AssassExit[1]-8, AssassExit[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            }

            void UpdateAI(const uint32 diff)
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                if (Assassins_Timer)
                {
                    if (Assassins_Timer <= diff)
                    {
                        SpawnAssassin();
                        Assassins_Timer = 0;
                    }
                    else
                        Assassins_Timer -= diff;
                }

                if (InBlade)
                {
                    if (Wait_Timer)
                    {
                        if (Wait_Timer <= diff)
                        {
                            if (target_num <= 0)
                            {
                                // stop bladedance
                                InBlade = false;
                                me->SetSpeed(MOVE_RUN, 2);
                                me->GetMotionMaster()->MoveChase(me->getVictim());
                                Blade_Dance_Timer = 30000;
                                Wait_Timer = 0;
                                if (IsHeroic())
                                    Charge_timer = 5000;
                            }
                            else
                            {
                                //move in bladedance
                                float x, y, randx, randy;
                                randx = 0.0f + rand()%40;
                                randy = 0.0f + rand()%40;
                                x = 210+ randx ;
                                y = -60- randy ;
                                me->GetMotionMaster()->MovePoint(1, x, y, me->GetPositionZ());
                                Wait_Timer = 0;
                            }
                        }
                        else
                            Wait_Timer -= diff;
                    }
                }
                else
                {
                    if (Blade_Dance_Timer)
                    {
                        if (Blade_Dance_Timer <= diff)
                        {
                            target_num = TARGET_NUM;
                            Wait_Timer = 1;
                            InBlade = true;
                            Blade_Dance_Timer = 0;
                            me->SetSpeed(MOVE_RUN, 4);
                            return;
                        }
                        else
                            Blade_Dance_Timer -= diff;
                    }

                    if (Charge_timer)
                    {
                        if (Charge_timer <= diff)
                        {
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), H_SPELL_CHARGE);
                            Charge_timer = 0;
                        }
                        else
                            Charge_timer -= diff;
                    }

                    if (Summon_Assistant_Timer <= diff)
                    {
                        for (uint8 i = 0; i < summoned; ++i)
                        {
                            switch (urand(0, 2))
                            {
                                case 0:
                                    me->SummonCreature(MOB_HEARTHEN_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    break;
                                case 1:
                                    me->SummonCreature(MOB_SHARPSHOOTER_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    break;
                                case 2:
                                    me->SummonCreature(MOB_REAVER_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    break;
                            }
                        }
                        if (urand(0, 9) < 2)
                            ++summoned;
                        Summon_Assistant_Timer = urand(25000, 35000);
                    }
                    else
                        Summon_Assistant_Timer -= diff;

                    DoMeleeAttackIfReady();
                }

                if (resetcheck_timer <= diff)
                {
                    uint32 tempx = uint32(me->GetPositionX());
                    if (tempx > 255 || tempx < 205)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    resetcheck_timer = 5000;
                }
                else
                    resetcheck_timer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_warchief_kargath_bladefistAI (Creature);
        }
};

void AddSC_boss_warchief_kargath_bladefist()
{
    new boss_warchief_kargath_bladefist();
}

