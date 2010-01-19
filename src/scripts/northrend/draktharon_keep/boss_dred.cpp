/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss dred
SDAuthor: Manuel
SD%Complete: 100 %
SDComment: MAYBE need more improve the "Raptor Call".
SDCategory:
Script Data End */

#include "ScriptedPch.h"
#include "drak_tharon_keep.h"

enum eSpells
{
    SPELL_BELLOWING_ROAR                                   = 22686, // fears the group, can be resisted/dispelled
    SPELL_GRIEVOUS_BITE                                    = 48920,
    SPELL_MANGLING_SLASH                                   = 48873, //casted on the current tank, adds debuf
    SPELL_FEARSOME_ROAR                                    = 48849,
    H_SPELL_FEARSOME_ROAR                                  = 59422, //Not stacking, debuff
    SPELL_PIERCING_SLASH                                   = 48878, //debuff -->Armor reduced by 75%
    SPELL_RAPTOR_CALL                                      = 59416, //dummy
    SPELL_GUT_RIP                                          = 49710,
    SPELL_REND                                             = 13738
};

enum eArchivements
{
    ACHIEV_BETTER_OFF_DRED                                 = 2039
};

enum Creatures
{
    NPC_RAPTOR_1                                           = 26641,
    NPC_RAPTOR_2                                           = 26628
};

struct TRINITY_DLL_DECL boss_dredAI : public ScriptedAI
{
    boss_dredAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    uint32 BellowingRoarTimer;
    uint32 GrievousBiteTimer;
    uint32 ManglingSlashTimer;
    uint32 FearsomeRoarTimer;
    uint32 PiercingSlashTimer;
    uint32 RaptorCallTimer;

    ScriptedInstance* pInstance;

    void Reset()
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_DRED_EVENT,NOT_STARTED);
            pInstance->SetData(DATA_KING_DRED_ACHIEV, 0);
        }

        BellowingRoarTimer = 33000;
        GrievousBiteTimer  = 20000;
        ManglingSlashTimer = 18500;
        FearsomeRoarTimer  = urand(10000,20000);
        PiercingSlashTimer = 17000;
        RaptorCallTimer    = urand(20000,25000);
    }

    void EnterCombat(Unit* who)
    {
        if (pInstance)
            pInstance->SetData(DATA_DRED_EVENT,IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (BellowingRoarTimer < diff)
        {
            DoCastAOE(SPELL_BELLOWING_ROAR, false);
            BellowingRoarTimer = 40000;
        } else BellowingRoarTimer -=diff;

        if (GrievousBiteTimer < diff)
        {
            DoCastVictim(SPELL_GRIEVOUS_BITE ,false);
            GrievousBiteTimer = 20000;
        } else GrievousBiteTimer -=diff;

        if (ManglingSlashTimer < diff)
        {
            DoCastVictim(SPELL_MANGLING_SLASH,false);
            ManglingSlashTimer = 20000;
        } else ManglingSlashTimer -=diff;

        if (FearsomeRoarTimer < diff)
        {
            DoCastAOE(DUNGEON_MODE(SPELL_FEARSOME_ROAR, H_SPELL_FEARSOME_ROAR),false);
            FearsomeRoarTimer = urand(16,18)*1000;
        } else FearsomeRoarTimer -=diff;

        if (PiercingSlashTimer < diff)
        {
            DoCastVictim(SPELL_PIERCING_SLASH,false);
            PiercingSlashTimer = 20000;
        } else PiercingSlashTimer -=diff;

        if (RaptorCallTimer < diff)
        {
            DoCastVictim(SPELL_RAPTOR_CALL,false);

            float x,y,z;

            m_creature->GetClosePoint(x,y,z,m_creature->GetObjectSize()/3,10.0f);
            m_creature->SummonCreature(RAND(NPC_RAPTOR_1,NPC_RAPTOR_2),x,y,z,0,TEMPSUMMON_DEAD_DESPAWN,1000);

            RaptorCallTimer = urand(20000,25000);
        } else RaptorCallTimer -=diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
    {
        if (pInstance)
        {
            pInstance->SetData(DATA_DRED_EVENT,DONE);

            if (IsHeroic() && pInstance->GetData(DATA_KING_DRED_ACHIEV) == 6)
                pInstance->DoCompleteAchievement(ACHIEV_BETTER_OFF_DRED);
        }
    }
};

CreatureAI* GetAI_boss_dred(Creature* pCreature)
{
    return new boss_dredAI (pCreature);
}

struct TRINITY_DLL_DECL npc_drakkari_gutripperAI : public ScriptedAI
{
    npc_drakkari_gutripperAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

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

    void JustDied(Unit* killer)
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

CreatureAI* GetAI_npc_drakkari_gutripper(Creature* pCreature)
{
    return new npc_drakkari_gutripperAI (pCreature);
}

struct TRINITY_DLL_DECL npc_drakkari_scytheclawAI : public ScriptedAI
{
    npc_drakkari_scytheclawAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance* pInstance;

    uint32 RendTimer;

    void Reset()
    {
        RendTimer = urand(10000,15000);
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        if (RendTimer < diff)
        {
            DoCastVictim(SPELL_REND,false);
            RendTimer = urand(10000,15000);
        }else RendTimer -=diff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* killer)
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

CreatureAI* GetAI_npc_drakkari_scytheclaw(Creature* pCreature)
{
    return new npc_drakkari_scytheclawAI (pCreature);
}

void AddSC_boss_dred()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_drakkari_gutripper";
    newscript->GetAI = &GetAI_npc_drakkari_gutripper;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_drakkari_scytheclaw";
    newscript->GetAI = &GetAI_npc_drakkari_scytheclaw;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_dred";
    newscript->GetAI = &GetAI_boss_dred;
    newscript->RegisterSelf();
}
