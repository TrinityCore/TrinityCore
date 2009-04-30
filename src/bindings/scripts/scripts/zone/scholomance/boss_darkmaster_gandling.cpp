/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Boss_Darkmaster_Gandling
SD%Complete: 99
SDComment: Doors missing in instance script.
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"

#define SPELL_ARCANEMISSILES           22272
#define SPELL_SHADOWSHIELD             22417                //Not right ID. But 12040 is wrong either.
#define SPELL_CURSE                    18702

#define ADD_1X 170.205
#define ADD_1Y 99.413
#define ADD_1Z 104.733
#define ADD_1O 3.16

#define ADD_2X 170.813
#define ADD_2Y 97.857
#define ADD_2Z 104.713
#define ADD_2O 3.16

#define ADD_3X 170.720
#define ADD_3Y 100.900
#define ADD_3Z 104.739
#define ADD_3O 3.16

#define ADD_4X 171.866
#define ADD_4Y 99.373
#define ADD_4Z 104.732
#define ADD_4O 3.16

struct TRINITY_DLL_DECL boss_darkmaster_gandlingAI : public ScriptedAI
{
    boss_darkmaster_gandlingAI(Creature *c) : ScriptedAI(c) {}

    uint32 ArcaneMissiles_Timer;
    uint32 ShadowShield_Timer;
    uint32 Curse_Timer;
    uint32 Teleport_Timer;
    Creature *Summoned;

    void Reset()
    {
        ArcaneMissiles_Timer = 4500;
        ShadowShield_Timer = 12000;
        Curse_Timer = 2000;
        Teleport_Timer = 16000;
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //ArcaneMissiles_Timer
        if (ArcaneMissiles_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_ARCANEMISSILES);
            ArcaneMissiles_Timer = 8000;
        }else ArcaneMissiles_Timer -= diff;

        //ShadowShield_Timer
        if (ShadowShield_Timer < diff)
        {
            DoCast(m_creature,SPELL_SHADOWSHIELD);
            ShadowShield_Timer = 14000 + rand()%14000;
        }else ShadowShield_Timer -= diff;

        //Curse_Timer
        if (Curse_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CURSE);
            Curse_Timer = 15000 + rand()%12000;
        }else Curse_Timer -= diff;

        //Teleporting Random Target to one of the six pre boss rooms and spawn 3-4 skeletons near the gamer.
        //We will only telport if gandling has more than 3% of hp so teleported gamers can always loot.
        if ( m_creature->GetHealth()*100 / m_creature->GetMaxHealth() > 3 )
        {
            if(Teleport_Timer < diff)
            {
                Unit* target = NULL;
                target = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    if(DoGetThreat(target))
                        DoModifyThreatPercent(target, -100);

                    switch(rand()%6)
                    {
                        case 0:
                            DoTeleportPlayer(target, 250.0696,0.3921,84.8408,3.149);
                            Summoned = m_creature->SummonCreature(16119,254.2325,0.3417,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,257.7133,4.0226,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,258.6702,-2.60656,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                        case 1:
                            DoTeleportPlayer(target, 181.4220,-91.9481,84.8410,1.608);
                            Summoned = m_creature->SummonCreature(16119,184.0519,-73.5649,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,179.5951,-73.7045,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,180.6452,-78.2143,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,283.2274,-78.1518,84.8407,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                        case 2:
                            DoTeleportPlayer(target, 95.1547,-1.8173,85.2289,0.043);
                            Summoned = m_creature->SummonCreature(16119,100.9404,-1.8016,85.2289,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,101.3729,0.4882,85.2289,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,101.4596,-4.4740,85.2289,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                        case 3:
                            DoTeleportPlayer(target, 250.0696,0.3921,72.6722,3.149);
                            Summoned = m_creature->SummonCreature(16119,240.34481,0.7368,72.6722,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,240.3633,-2.9520,72.6722,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,240.6702,3.34949,72.6722,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                        case 4:
                            DoTeleportPlayer(target, 181.4220,-91.9481,70.7734,1.608);
                            Summoned = m_creature->SummonCreature(16119,184.0519,-73.5649,70.7734,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,179.5951,-73.7045,70.7734,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,180.6452,-78.2143,70.7734,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,283.2274,-78.1518,70.7734,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                        case 5:
                            DoTeleportPlayer(target, 106.1541,-1.8994,75.3663,0.043);
                            Summoned = m_creature->SummonCreature(16119,115.3945,-1.5555,75.3663,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,257.7133,1.8066,75.3663,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            Summoned = m_creature->SummonCreature(16119,258.6702,-5.1001,75.3663,0,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT,10000);
                            if(Summoned)
                                ((CreatureAI*)Summoned->AI())->AttackStart(target);
                            break;
                    }
                }
                Teleport_Timer = 20000 + rand()%15000;
            }else Teleport_Timer -= diff;
        }

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_darkmaster_gandling(Creature *_Creature)
{
    return new boss_darkmaster_gandlingAI (_Creature);
}

void AddSC_boss_darkmaster_gandling()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_darkmaster_gandling";
    newscript->GetAI = &GetAI_boss_darkmaster_gandling;
    newscript->RegisterSelf();
}

