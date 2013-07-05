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
SDName: Boss_Warp_Splinter
SD%Complete: 80
SDComment: Includes Sapling (need some better control with these).
SDCategory: Tempest Keep, The Botanica
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_botanica.h"

enum Says
{
    SAY_AGGRO          = 0,
    SAY_SLAY           = 1,
    SAY_SUMMON         = 2,
    SAY_DEATH          = 3
};

enum Spells
{
    WAR_STOMP          = 34716,
    SUMMON_TREANTS     = 34727, // DBC: 34727, 34731, 34733, 34734, 34736, 34739, 34741 (with Ancestral Life spell 34742)   // won't work (guardian summon)
    ARCANE_VOLLEY      = 36705,
    ARCANE_VOLLEY_H    = 39133,
    SPELL_HEAL_FATHER  = 6262
};

enum Misc
{
    CREATURE_TREANT    = 19949,
    TREANT_SPAWN_DIST  = 50 //50 yards from Warp Splinter's spawn point
};

float treant_pos[6][3] =
{
    {24.301233f, 427.221100f, -27.060635f},
    {16.795492f, 359.678802f, -27.355425f},
    {53.493484f, 345.381470f, -26.196192f},
    {61.867096f, 439.362732f, -25.921030f},
    {109.861877f, 423.201630f, -27.356019f},
    {106.780159f, 355.582581f, -27.593357f}
};

/*#####
# npc_treant (Sapling)
#####*/
class npc_warp_splinter_treant : public CreatureScript
{
    public:

        npc_warp_splinter_treant()
            : CreatureScript("npc_warp_splinter_treant")
        {
        }
        struct npc_warp_splinter_treantAI  : public ScriptedAI
        {
            npc_warp_splinter_treantAI (Creature* creature) : ScriptedAI(creature)
            {
                WarpGuid = 0;
            }

            uint64 WarpGuid;
            uint32 check_Timer;

            void Reset()
            {
                check_Timer = 0;
            }

            void EnterCombat(Unit* /*who*/) {}

            void MoveInLineOfSight(Unit* /*who*/) {}

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (WarpGuid && check_Timer <= diff)
                    {
                        if (Unit* Warp = Unit::GetUnit(*me, WarpGuid))
                        {
                            if (me->IsWithinMeleeRange(Warp, 2.5f))
                            {
                                int32 CurrentHP_Treant = (int32)me->GetHealth();
                                Warp->CastCustomSpell(Warp, SPELL_HEAL_FATHER, &CurrentHP_Treant, 0, 0, true, 0, 0, me->GetGUID());
                                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                                return;
                            }
                            me->GetMotionMaster()->MoveFollow(Warp, 0, 0);
                        }
                        check_Timer = 1000;
                    }
                    else
                        check_Timer -= diff;
                    return;
                }

                if (me->GetVictim()->GetGUID() !=  WarpGuid)
                    DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_warp_splinter_treantAI(creature);
        }
};

/*#####
# boss_warp_splinter
#####*/
class boss_warp_splinter : public CreatureScript
{
    public:

        boss_warp_splinter()
            : CreatureScript("boss_warp_splinter")
        {
        }
        struct boss_warp_splinterAI : public BossAI
        {
            boss_warp_splinterAI(Creature* creature) : BossAI(creature, DATA_WARP_SPLINTER)
            {
                Treant_Spawn_Pos_X = creature->GetPositionX();
                Treant_Spawn_Pos_Y = creature->GetPositionY();
            }

            uint32 War_Stomp_Timer;
            uint32 Summon_Treants_Timer;
            uint32 Arcane_Volley_Timer;

            float Treant_Spawn_Pos_X;
            float Treant_Spawn_Pos_Y;

            void Reset()
            {
                War_Stomp_Timer = urand(25000, 40000);
                Summon_Treants_Timer = 45000;
                Arcane_Volley_Timer = urand(8000, 20000);

                me->SetSpeed(MOVE_RUN, 0.7f, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);
            }

            void SummonTreants()
            {
                for (uint8 i = 0; i < 6; ++i)
                {
                    float angle = (M_PI / 3) * i;

                    float X = Treant_Spawn_Pos_X + TREANT_SPAWN_DIST * std::cos(angle);
                    float Y = Treant_Spawn_Pos_Y + TREANT_SPAWN_DIST * std::sin(angle);
                    float O = - me->GetAngle(X, Y);

                    if (Creature* pTreant = me->SummonCreature(CREATURE_TREANT, treant_pos[i][0], treant_pos[i][1], treant_pos[i][2], O, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 25000))
                        CAST_AI(npc_warp_splinter_treant::npc_warp_splinter_treantAI, pTreant->AI())->WarpGuid = me->GetGUID();
                }
                Talk(SAY_SUMMON);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                //Check for War Stomp
                if (War_Stomp_Timer <= diff)
                {
                    DoCastVictim(WAR_STOMP);
                    War_Stomp_Timer = urand(25000, 40000);
                }
                else
                    War_Stomp_Timer -= diff;

                //Check for Arcane Volley
                if (Arcane_Volley_Timer <= diff)
                {
                    DoCastVictim(DUNGEON_MODE(ARCANE_VOLLEY, ARCANE_VOLLEY_H));
                    Arcane_Volley_Timer = urand(20000, 35000);
                }
                else
                    Arcane_Volley_Timer -= diff;

                //Check for Summon Treants
                if (Summon_Treants_Timer <= diff)
                {
                    SummonTreants();
                    Summon_Treants_Timer = 45000;
                }
                else
                    Summon_Treants_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_warp_splinterAI(creature);
        }
};

void AddSC_boss_warp_splinter()
{
    new boss_warp_splinter();
    new npc_warp_splinter_treant();
}

