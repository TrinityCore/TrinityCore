/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"

enum eSays
{
    SAY_AGGRO          = -1553007,
    SAY_SLAY_1         = -1553008,
    SAY_SLAY_2         = -1553009,
    SAY_SUMMON_1       = -1553010,
    SAY_SUMMON_2       = -1553011,
    SAY_DEATH          = -1553012,
};

enum eSpells
{
    WAR_STOMP          = 34716,
    SUMMON_TREANTS     = 34727, // DBC: 34727, 34731, 34733, 34734, 34736, 34739, 34741 (with Ancestral Life spell 34742)   // won't work (guardian summon)
    ARCANE_VOLLEY      = 36705,
    ARCANE_VOLLEY_H    = 39133,
    SPELL_HEAL_FATHER  = 6262,
};

enum eOthers
{
    CREATURE_TREANT    = 19949,
    TREANT_SPAWN_DIST  = 50, //50 yards from Warp Splinter's spawn point
};

float treant_pos[6][3] =
{
    {24.301233, 427.221100, -27.060635},
    {16.795492, 359.678802, -27.355425},
    {53.493484, 345.381470, -26.196192},
    {61.867096, 439.362732, -25.921030},
    {109.861877, 423.201630, -27.356019},
    {106.780159, 355.582581, -27.593357}
};

/*#####
# mob_treant (Sapling)
#####*/
class mob_warp_splinter_treant : public CreatureScript
{
    public:

        mob_warp_splinter_treant()
            : CreatureScript("mob_warp_splinter_treant")
        {
        }
        struct mob_warp_splinter_treantAI  : public ScriptedAI
        {
            mob_warp_splinter_treantAI (Creature* pCreature) : ScriptedAI(pCreature)
            {
                WarpGuid = 0;
            }

            uint64 WarpGuid;
            uint32 check_Timer;

            void Reset()
            {
                check_Timer = 0;
            }

            void EnterCombat(Unit * /*who*/) {}

            void MoveInLineOfSight(Unit* /*who*/) {}

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                {
                    if (WarpGuid && check_Timer <= diff)
                    {
                        if (Unit *Warp = Unit::GetUnit(*me, WarpGuid))
                        {
                            if (me->IsWithinMeleeRange(Warp,2.5f))
                            {
                                int32 CurrentHP_Treant = (int32)me->GetHealth();
                                Warp->CastCustomSpell(Warp,SPELL_HEAL_FATHER,&CurrentHP_Treant, 0, 0, true,0 ,0, me->GetGUID());
                                me->DealDamage(me, me->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                                return;
                            }
                            me->GetMotionMaster()->MoveFollow(Warp,0,0);
                        }
                        check_Timer = 1000;
                    }
                    else
                        check_Timer -= diff;
                    return;
                }

                if (me->getVictim()->GetGUID() !=  WarpGuid)
                    DoMeleeAttackIfReady();
            }
        };
        CreatureAI* GetAI(Creature* Creature) const
        {
            return new mob_warp_splinter_treantAI (Creature);
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
        struct boss_warp_splinterAI : public ScriptedAI
        {
            boss_warp_splinterAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                Treant_Spawn_Pos_X = pCreature->GetPositionX();
                Treant_Spawn_Pos_Y = pCreature->GetPositionY();
            }

            uint32 War_Stomp_Timer;
            uint32 Summon_Treants_Timer;
            uint32 Arcane_Volley_Timer;

            float Treant_Spawn_Pos_X;
            float Treant_Spawn_Pos_Y;

            void Reset()
            {
                War_Stomp_Timer = 25000 + rand()%15000;
                Summon_Treants_Timer = 45000;
                Arcane_Volley_Timer = 8000 + rand()%12000;

                me->SetSpeed(MOVE_RUN, 0.7f, true);
            }

            void EnterCombat(Unit * /*who*/)
            {
                DoScriptText(SAY_AGGRO, me);
            }

            void KilledUnit(Unit* /*victim*/)
            {
                DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
            }

            void JustDied(Unit* /*Killer*/)
            {
                DoScriptText(SAY_DEATH, me);
            }

            void SummonTreants()
            {
                for (uint8 i = 0; i < 6; ++i)
                {
                    float angle = (M_PI / 3) * i;

                    float X = Treant_Spawn_Pos_X + TREANT_SPAWN_DIST * cos(angle);
                    float Y = Treant_Spawn_Pos_Y + TREANT_SPAWN_DIST * sin(angle);
                    float O = - me->GetAngle(X,Y);

                    if (Creature *pTreant = me->SummonCreature(CREATURE_TREANT,treant_pos[i][0],treant_pos[i][1],treant_pos[i][2],O,TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN,25000))
                        CAST_AI(mob_warp_splinter_treant::mob_warp_splinter_treantAI, pTreant->AI())->WarpGuid = me->GetGUID();
                }
                DoScriptText(RAND(SAY_SUMMON_1,SAY_SUMMON_2), me);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                //Check for War Stomp
                if (War_Stomp_Timer <= diff)
                {
                    DoCast(me->getVictim(), WAR_STOMP);
                    War_Stomp_Timer = 25000 + rand()%15000;
                }
                else
                    War_Stomp_Timer -= diff;

                //Check for Arcane Volley
                if (Arcane_Volley_Timer <= diff)
                {
                    DoCast(me->getVictim(), DUNGEON_MODE(ARCANE_VOLLEY,ARCANE_VOLLEY_H));
                    Arcane_Volley_Timer = 20000 + rand()%15000;
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

        CreatureAI* GetAI(Creature* Creature) const
        {
            return new boss_warp_splinterAI (Creature);
        }
};

void AddSC_boss_warp_splinter()
{
    new boss_warp_splinter();
    new mob_warp_splinter_treant();
}

