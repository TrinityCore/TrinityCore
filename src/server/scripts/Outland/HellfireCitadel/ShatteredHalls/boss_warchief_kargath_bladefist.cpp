/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "shattered_halls.h"

enum Says
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DEATH                      = 2
};

enum Spells
{
     SPELL_BLADE_DANCE             = 30739,
     H_SPELL_CHARGE                = 25821
};

enum Creatures
{
    NPC_SHATTERED_ASSASSIN         = 17695,
    NPC_HEARTHEN_GUARD             = 17621,
    NPC_SHARPSHOOTER_GUARD         = 17622,
    NPC_REAVER_GUARD               = 17623
};

#define TARGET_NUM                   5

float AssassEntrance[3] = { 275.136f, -84.29f, 2.3f  }; // y -8
float AssassExit[3]     = { 184.233f, -84.29f, 2.3f  }; // y -8
float AddsEntrance[3]   = { 306.036f, -84.29f, 1.93f };

class boss_warchief_kargath_bladefist : public CreatureScript
{
    public:
        boss_warchief_kargath_bladefist() : CreatureScript("boss_warchief_kargath_bladefist") { }

        struct boss_warchief_kargath_bladefistAI : public BossAI
        {
            boss_warchief_kargath_bladefistAI(Creature* creature) : BossAI(creature, DATA_KARGATH) { }

            void Reset() OVERRIDE
            {
                removeAdds();

                me->SetSpeed(MOVE_RUN, 2);
                me->SetWalk(false);

                summoned = 2;
                InBlade = false;
                Wait_Timer = 0;

                Charge_timer = 0;
                Blade_Dance_Timer = 45000;
                Summon_Assistant_Timer = 30000;
                Assassins_Timer = 5000;
                resetcheck_timer = 5000;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                Talk(SAY_DEATH);
                removeAdds();

                if (instance)
                    instance->SetBossState(DATA_KARGATH, DONE);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summoned) OVERRIDE
            {
                switch (summoned->GetEntry())
                {
                    case NPC_HEARTHEN_GUARD:
                    case NPC_SHARPSHOOTER_GUARD:
                    case NPC_REAVER_GUARD:
                        summoned->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM, 0));
                        adds.push_back(summoned->GetGUID());
                        break;
                    case NPC_SHATTERED_ASSASSIN:
                        assassins.push_back(summoned->GetGUID());
                        break;
                }
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_SLAY);
                }
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
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
                    Creature* creature = Unit::GetCreature(*me, *itr);
                    if (creature && creature->IsAlive())
                    {
                        creature->GetMotionMaster()->Clear(true);
                        me->DealDamage(creature, creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        creature->RemoveCorpse();
                    }
                }
                adds.clear();

                for (std::vector<uint64>::const_iterator itr = assassins.begin(); itr!= assassins.end(); ++itr)
                {
                    Creature* creature = Unit::GetCreature(*me, *itr);
                    if (creature && creature->IsAlive())
                    {
                        creature->GetMotionMaster()->Clear(true);
                        me->DealDamage(creature, creature->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                        creature->RemoveCorpse();
                    }
                }
                assassins.clear();
            }
            void SpawnAssassin()
            {
                me->SummonCreature(NPC_SHATTERED_ASSASSIN, AssassEntrance[0], AssassEntrance[1]+8, AssassEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_SHATTERED_ASSASSIN, AssassEntrance[0], AssassEntrance[1]-8, AssassEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_SHATTERED_ASSASSIN, AssassExit[0], AssassExit[1]+8, AssassExit[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_SHATTERED_ASSASSIN, AssassExit[0], AssassExit[1]-8, AssassExit[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                                me->GetMotionMaster()->MoveChase(me->GetVictim());
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
                                x = 210+ randx;
                                y = -60- randy;
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
                                    me->SummonCreature(NPC_HEARTHEN_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    break;
                                case 1:
                                    me->SummonCreature(NPC_SHARPSHOOTER_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                                    break;
                                case 2:
                                    me->SummonCreature(NPC_REAVER_GUARD, AddsEntrance[0], AddsEntrance[1], AddsEntrance[2], 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
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

            private:
                std::vector<uint64> adds;
                std::vector<uint64> assassins;
                uint32 Charge_timer;
                uint32 Blade_Dance_Timer;
                uint32 Summon_Assistant_Timer;
                uint32 resetcheck_timer;
                uint32 Wait_Timer;
                uint32 Assassins_Timer;
                uint32 summoned;
                uint32 target_num;
                bool InBlade;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_warchief_kargath_bladefistAI>(creature);
        }
};

void AddSC_boss_warchief_kargath_bladefist()
{
    new boss_warchief_kargath_bladefist();
}
