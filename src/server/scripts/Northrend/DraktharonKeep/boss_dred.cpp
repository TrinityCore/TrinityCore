/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 * Comment: MAYBE need more improve the "Raptor Call".
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "drak_tharon_keep.h"

enum Spells
{
    SPELL_BELLOWING_ROAR                          = 22686, // fears the group, can be resisted/dispelled
    SPELL_GRIEVOUS_BITE                           = 48920,
    SPELL_MANGLING_SLASH                          = 48873, //casted on the current tank, adds debuf
    SPELL_FEARSOME_ROAR                           = 48849,
    H_SPELL_FEARSOME_ROAR                         = 59422, //Not stacking, debuff
    SPELL_PIERCING_SLASH                          = 48878, //debuff -->Armor reduced by 75%
    SPELL_RAPTOR_CALL                             = 59416, //dummy
    SPELL_GUT_RIP                                 = 49710,
    SPELL_REND                                    = 13738
};

enum Creatures
{
    NPC_RAPTOR_1                                  = 26641,
    NPC_RAPTOR_2                                  = 26628
};

#define ACTION_RAPTOR_KILLED                      1
#define DATA_KING_DRED                            2

class boss_dred : public CreatureScript
{
    public:
        boss_dred() : CreatureScript("boss_dred") { }

        struct boss_dredAI : public ScriptedAI
        {
            boss_dredAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            uint32 uiBellowingRoarTimer;
            uint32 uiGrievousBiteTimer;
            uint32 uiManglingSlashTimer;
            uint32 uiFearsomeRoarTimer;
            uint32 uiPiercingSlashTimer;
            uint32 uiRaptorCallTimer;
            uint8 raptorsKilled;

            InstanceScript* instance;

            void Reset()
            {
                if (instance)
                    instance->SetData(DATA_DRED_EVENT, NOT_STARTED);

                uiBellowingRoarTimer = 33000;
                uiGrievousBiteTimer  = 20000;
                uiManglingSlashTimer = 18500;
                uiFearsomeRoarTimer  = urand(10000, 20000);
                uiPiercingSlashTimer = 17000;
                uiRaptorCallTimer    = urand(20000, 25000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                    instance->SetData(DATA_DRED_EVENT, IN_PROGRESS);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (uiBellowingRoarTimer <= diff)
                {
                    DoCastAOE(SPELL_BELLOWING_ROAR, false);
                    uiBellowingRoarTimer = 40000;
                }
                else
                    uiBellowingRoarTimer -=diff;

                if (uiGrievousBiteTimer <= diff)
                {
                    DoCastVictim(SPELL_GRIEVOUS_BITE, false);
                    uiGrievousBiteTimer = 20000;
                }
                else
                    uiGrievousBiteTimer -= diff;

                if (uiManglingSlashTimer <= diff)
                {
                    DoCastVictim(SPELL_MANGLING_SLASH, false);
                    uiManglingSlashTimer = 20000;
                }
                else
                    uiManglingSlashTimer -= diff;

                if (uiFearsomeRoarTimer <= diff)
                {
                    DoCastAOE(SPELL_FEARSOME_ROAR, false);
                    uiFearsomeRoarTimer = urand(16000, 18000);
                }
                else
                    uiFearsomeRoarTimer -= diff;

                if (uiPiercingSlashTimer <= diff)
                {
                    DoCastVictim(SPELL_PIERCING_SLASH, false);
                    uiPiercingSlashTimer = 20000;
                }
                else
                    uiPiercingSlashTimer -= diff;

                if (uiRaptorCallTimer <= diff)
                {
                    DoCastVictim(SPELL_RAPTOR_CALL, false);

                    float x, y, z;

                    me->GetClosePoint(x, y, z, me->GetObjectSize() / 3, 10.0f);
                    me->SummonCreature(RAND(NPC_RAPTOR_1, NPC_RAPTOR_2), x, y, z, 0, TEMPSUMMON_DEAD_DESPAWN, 1000);

                    uiRaptorCallTimer = urand(20000, 25000);
                }
                else
                    uiRaptorCallTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_RAPTOR_KILLED)
                    ++raptorsKilled;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_KING_DRED)
                    return raptorsKilled;

                return 0;
            }

            void JustDied(Unit* /*killer*/)
            {
                if (instance)
                    instance->SetData(DATA_DRED_EVENT, DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_dredAI(creature);
        }
};

class npc_drakkari_gutripper : public CreatureScript
{
    public:
        npc_drakkari_gutripper() : CreatureScript("npc_drakkari_gutripper") { }

        struct npc_drakkari_gutripperAI : public ScriptedAI
        {
            npc_drakkari_gutripperAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 GutRipTimer;

            void Reset()
            {
                GutRipTimer = urand(10000, 15000);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (GutRipTimer <= diff)
                {
                    DoCastVictim(SPELL_GUT_RIP, false);
                    GutRipTimer = urand(10000, 15000);
                }
                else
                    GutRipTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* Dred = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_DRED)))
                    Dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_drakkari_gutripperAI(creature);
        }
};

class npc_drakkari_scytheclaw : public CreatureScript
{
    public:
        npc_drakkari_scytheclaw() : CreatureScript("npc_drakkari_scytheclaw") { }

        struct npc_drakkari_scytheclawAI : public ScriptedAI
        {
            npc_drakkari_scytheclawAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = me->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 uiRendTimer;

            void Reset()
            {
                uiRendTimer = urand(10000, 15000);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (uiRendTimer <= diff)
                {
                    DoCastVictim(SPELL_REND, false);
                    uiRendTimer = urand(10000, 15000);
                }
                else
                    uiRendTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                if (Creature* Dred = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_DRED)))
                    Dred->AI()->DoAction(ACTION_RAPTOR_KILLED);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_drakkari_scytheclawAI(creature);
        }
};

class achievement_king_dred : public AchievementCriteriaScript
{
    public:
        achievement_king_dred() : AchievementCriteriaScript("achievement_king_dred")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            if (!target)
                return false;

            if (Creature* Dred = target->ToCreature())
                if (Dred->AI()->GetData(DATA_KING_DRED) >= 6)
                    return true;

            return false;
        }
};

void AddSC_boss_dred()
{
    new boss_dred;
    new npc_drakkari_gutripper;
    new npc_drakkari_scytheclaw;
    new achievement_king_dred();
}
