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

/*
 * Comment: MAYBE need more improve the "Raptor Call".
 */

#include "ScriptPCH.h"
#include "drak_tharon_keep.h"

enum eSpells
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

enum eArchivements
{
    ACHIEV_BETTER_OFF_DRED                        = 2039
};

enum Creatures
{
    NPC_RAPTOR_1                                  = 26641,
    NPC_RAPTOR_2                                  = 26628
};

class boss_dred : public CreatureScript
{
public:
    boss_dred() : CreatureScript("boss_dred") { }

    struct boss_dredAI : public ScriptedAI
    {
        boss_dredAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        uint32 uiBellowingRoarTimer;
        uint32 uiGrievousBiteTimer;
        uint32 uiManglingSlashTimer;
        uint32 uiFearsomeRoarTimer;
        uint32 uiPiercingSlashTimer;
        uint32 uiRaptorCallTimer;

        InstanceScript* pInstance;

        void Reset()
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_DRED_EVENT,NOT_STARTED);
                pInstance->SetData(DATA_KING_DRED_ACHIEV, 0);
            }

            uiBellowingRoarTimer = 33*IN_MILLISECONDS;
            uiGrievousBiteTimer  = 20*IN_MILLISECONDS;
            uiManglingSlashTimer = 18500;
            uiFearsomeRoarTimer  = urand(10*IN_MILLISECONDS,20*IN_MILLISECONDS);
            uiPiercingSlashTimer = 17*IN_MILLISECONDS;
            uiRaptorCallTimer    = urand(20*IN_MILLISECONDS,25*IN_MILLISECONDS);
        }

        void EnterCombat(Unit* /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_DRED_EVENT,IN_PROGRESS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiBellowingRoarTimer < diff)
            {
                DoCastAOE(SPELL_BELLOWING_ROAR, false);
                uiBellowingRoarTimer = 40*IN_MILLISECONDS;
            } else uiBellowingRoarTimer -=diff;

            if (uiGrievousBiteTimer < diff)
            {
                DoCastVictim(SPELL_GRIEVOUS_BITE ,false);
                uiGrievousBiteTimer = 20*IN_MILLISECONDS;
            } else uiGrievousBiteTimer -=diff;

            if (uiManglingSlashTimer < diff)
            {
                DoCastVictim(SPELL_MANGLING_SLASH,false);
                uiManglingSlashTimer = 20*IN_MILLISECONDS;
            } else uiManglingSlashTimer -=diff;

            if (uiFearsomeRoarTimer < diff)
            {
                DoCastAOE(SPELL_FEARSOME_ROAR,false);
                uiFearsomeRoarTimer = urand(16*IN_MILLISECONDS,18*IN_MILLISECONDS);
            } else uiFearsomeRoarTimer -=diff;

            if (uiPiercingSlashTimer < diff)
            {
                DoCastVictim(SPELL_PIERCING_SLASH,false);
                uiPiercingSlashTimer = 20*IN_MILLISECONDS;
            } else uiPiercingSlashTimer -=diff;

            if (uiRaptorCallTimer < diff)
            {
                DoCastVictim(SPELL_RAPTOR_CALL,false);

                float x,y,z;

                me->GetClosePoint(x,y,z,me->GetObjectSize()/3,10.0f);
                me->SummonCreature(RAND(NPC_RAPTOR_1,NPC_RAPTOR_2),x,y,z,0,TEMPSUMMON_DEAD_DESPAWN,1*IN_MILLISECONDS);

                uiRaptorCallTimer = urand(20*IN_MILLISECONDS,25*IN_MILLISECONDS);
            } else uiRaptorCallTimer -=diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
            {
                pInstance->SetData(DATA_DRED_EVENT,DONE);

                if (IsHeroic() && pInstance->GetData(DATA_KING_DRED_ACHIEV) == 6)
                    pInstance->DoCompleteAchievement(ACHIEV_BETTER_OFF_DRED);
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
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
        npc_drakkari_gutripperAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 GutRipTimer;

        void Reset()
        {
            GutRipTimer = urand(10000,15000);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (GutRipTimer < diff)
            {
                DoCastVictim(SPELL_GUT_RIP,false);
                GutRipTimer = urand(10000,15000);
            }else GutRipTimer -=diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
            {
                if (IsHeroic() && pInstance->GetData(DATA_DRED_EVENT) == IN_PROGRESS && pInstance->GetData(DATA_KING_DRED_ACHIEV) < 6)
                {
                    pInstance->SetData(DATA_KING_DRED_ACHIEV, pInstance->GetData(DATA_KING_DRED_ACHIEV) + 1);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
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
        npc_drakkari_scytheclawAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        uint32 uiRendTimer;

        void Reset()
        {
            uiRendTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiRendTimer < diff)
            {
                DoCastVictim(SPELL_REND,false);
                uiRendTimer = urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS);
            }else uiRendTimer -=diff;

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/)
        {
            if (pInstance)
            {
                if (IsHeroic() && pInstance->GetData(DATA_DRED_EVENT) == IN_PROGRESS && pInstance->GetData(DATA_KING_DRED_ACHIEV) < 6)
                {
                    pInstance->SetData(DATA_KING_DRED_ACHIEV, pInstance->GetData(DATA_KING_DRED_ACHIEV) + 1);
                }
            }
        }
    };

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_drakkari_scytheclawAI(creature);
    }
};

void AddSC_boss_dred()
{
    new npc_drakkari_gutripper;
    new npc_drakkari_scytheclaw;
    new boss_dred;
}
