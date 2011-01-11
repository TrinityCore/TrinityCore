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
SDName: Boss_Majordomo_Executus
SD%Complete: 30
SDComment: Correct spawning and Event NYI
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"
#include "molten_core.h"

#define SAY_AGGRO           -1409003
#define SAY_SPAWN           -1409004
#define SAY_SLAY            -1409005
#define SAY_SPECIAL         -1409006
#define SAY_DEFEAT          -1409007

#define SAY_SUMMON_MAJ      -1409008
#define SAY_ARRIVAL1_RAG    -1409009
#define SAY_ARRIVAL2_MAJ    -1409010
#define SAY_ARRIVAL3_RAG    -1409011
#define SAY_ARRIVAL5_RAG    -1409012

#define ENTRY_RAGNAROS 11502

#define EMOTE_EMERGE 449

#define TELE_TO_RAG_X         829.159f
#define TELE_TO_RAG_Y         -815.773f
#define TELE_TO_RAG_Z         -228.972f
#define TELE_TO_RAG_O         5.305f

#define SPELL_MAGIC_REFLECTION      20619
#define SPELL_DAMAGE_REFLECTION     21075

#define SPELL_BLASTWAVE             20229
#define SPELL_AEGIS                 20620                   //This is self casted whenever we are below 50%
#define SPELL_TELEPORT              20618
#define SPELL_SUMMON_RAGNAROS       19774

#define ENTRY_FLAMEWALKER_HEALER    11663
#define ENTRY_FLAMEWALKER_ELITE     11664

#define GOSSIP_HELLO 4995
#define GOSSIP_SELLECT "Tell me more."

class boss_majordomo : public CreatureScript
{
public:
    boss_majordomo() : CreatureScript("boss_majordomo") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_majordomoAI (pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELLECT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_HELLO, pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 /*uiAction*/)
    {   
        //ScriptedInstance* pInstance = pCreature->GetInstanceData();

        BossAI* pBossAI = CAST_AI(boss_majordomoAI, pCreature->AI());

        if (/*pInstance && */pBossAI)
        {  
            pPlayer->CLOSE_GOSSIP_MENU();
            CAST_AI(boss_majordomoAI, pCreature->AI())->StartRagsEvent(); 
        }
        return true;                              
    }

    struct boss_majordomoAI : public BossAI
    {
        boss_majordomoAI(Creature *pCreature) : BossAI(pCreature, BOSS_MAJORDOMO) 
        {
            m_pInstance = pCreature->GetInstanceScript(); 
        }
        InstanceScript* m_pInstance;

        uint32 MagicReflection_Timer;
        uint32 DamageReflection_Timer;
        uint32 Blastwave_Timer;
        uint32 Teleport_Timer;
        uint32 Phase_Timer; //for teleport and ragnaros's intro
        uint8 Phase;

        void Reset()
        {
            MagicReflection_Timer =  30000;                     //Damage reflection first so we alternate
            DamageReflection_Timer = 15000;
            Blastwave_Timer = 10000;
            Teleport_Timer = 20000;
            Phase = 0;
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (rand()%5)
                return;

            DoScriptText(SAY_SLAY, me);
        }

        void EnterCombat(Unit * /*who*/)
        {
            DoScriptText(SAY_AGGRO, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (Phase == 0)
            {
                if (!UpdateVictim())
                    return;

                 if (((!me->FindNearestCreature(ENTRY_FLAMEWALKER_HEALER,100.0f)) && (!me->FindNearestCreature(ENTRY_FLAMEWALKER_ELITE,100.0f))) && (!m_pInstance->GetData(DATA_MAJORDOMOISDEAD)))
                 {      
                    me->setFaction(35);
                    me->AI()->EnterEvadeMode();
                    DoScriptText(SAY_DEFEAT, me);
                    //DoCast(SPELL_SUMMON_RAGNAROS); Not working atm ,doing workaround
                    if (m_pInstance)
                        m_pInstance->SetData(DATA_MAJORDOMO, DONE);
                        //m_pInstance->SetBossState(DATA_MAJORDOMO, DONE);
                    Phase_Timer = 32000;
                    Phase = 1;
                 }

                //Cast Ageis if less than 50% hp
                if (HealthBelowPct(50))
                    DoCast(me, SPELL_AEGIS);

                if (MagicReflection_Timer <= diff)
                {
                    DoCast(me, SPELL_MAGIC_REFLECTION);
                    MagicReflection_Timer = 30000;
                    } else MagicReflection_Timer -= diff;

                if (DamageReflection_Timer <= diff)
                {
                    DoCast(me, SPELL_DAMAGE_REFLECTION);
                    DamageReflection_Timer = 30000;
                    } else DamageReflection_Timer -= diff;

                //Blastwave_Timer
                if (Blastwave_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_BLASTWAVE);
                    Blastwave_Timer = 10000;
                   } else Blastwave_Timer -= diff;

                if (Teleport_Timer <= diff)
                {
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1)) 
                         DoCast(pTarget, SPELL_TELEPORT); 
                    Teleport_Timer = 20000;
                } else Teleport_Timer -= diff;

                DoMeleeAttackIfReady();
            }
            else
            {
                if (Phase == 1)
                {
                    if (Phase_Timer <= diff)
                    {
                        me->NearTeleportTo(TELE_TO_RAG_X, TELE_TO_RAG_Y, TELE_TO_RAG_Z, TELE_TO_RAG_O);
                        Phase = 2;
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    } else Phase_Timer -= diff;
                }
                if (Phase == 3)
                {
                    if (Phase_Timer <= diff)
                    {
                        if (m_pInstance)
                            m_pInstance->SetData(DATA_RAGNAROS, true);
                        Phase = 4;
                        Phase_Timer = 16000; 
                    } else Phase_Timer -= diff;
                }
                if (Phase == 4)
                {
                    if (Phase_Timer <= diff)
                    {
                        DoScriptText(SAY_ARRIVAL2_MAJ, me);
                        Phase = 5;
                    } else Phase_Timer -= diff;
                }
            }
        }

        void StartRagsEvent()
        {
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Phase = 3;
            DoScriptText(SAY_SUMMON_MAJ, me);
            Phase_Timer = 8000;
        }
    };

};

void AddSC_boss_majordomo()
{
    new boss_majordomo();
}
