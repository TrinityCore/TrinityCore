/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Darkmaster_Gandling
SD%Complete: 75
SDComment: Doors missing in instance script.
SDCategory: Scholomance
EndScriptData */

#include "ScriptPCH.h"
#include "scholomance.h"

enum Spells
{
    SPELL_ARCANEMISSILES           = 15790,
    SPELL_SHADOWSHIELD             = 12040,
    SPELL_CURSE                    = 18702,
    SPELL_SHADOWPORTAL             = 17950 // not use
};

class boss_darkmaster_gandling : public CreatureScript
{
public:
    boss_darkmaster_gandling() : CreatureScript("boss_darkmaster_gandling") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_darkmaster_gandlingAI (creature);
    }

    struct boss_darkmaster_gandlingAI : public ScriptedAI
    {
        boss_darkmaster_gandlingAI(Creature* c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 ArcaneMissiles_Timer;
        uint32 ShadowShield_Timer;
        uint32 Curse_Timer;
        uint32 Teleport_Timer;

        void Reset()
        {
            ArcaneMissiles_Timer = 4500;
            ShadowShield_Timer = 12000;
            Curse_Timer = 2000;
            Teleport_Timer = 16000;
        }

        void EnterCombat(Unit* /*who*/)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            if (instance)
                instance->SetData(TYPE_GANDLING, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            //ArcaneMissiles_Timer
            if (ArcaneMissiles_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_ARCANEMISSILES);
                ArcaneMissiles_Timer = 8000;
            } else ArcaneMissiles_Timer -= diff;

            //ShadowShield_Timer
            if (ShadowShield_Timer <= diff)
            {
                DoCast(me, SPELL_SHADOWSHIELD);
                ShadowShield_Timer = urand(14000, 28000);
            } else ShadowShield_Timer -= diff;

            //Curse_Timer
            if (Curse_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CURSE);
                Curse_Timer = urand(15000, 27000);
            } else Curse_Timer -= diff;

            //Teleporting Random Target to one of the six pre boss rooms and spawn 3-4 skeletons near the gamer.
            //We will only telport if gandling has more than 3% of hp so teleported gamers can always loot.
            if (HealthAbovePct(3))
            {
                if (Teleport_Timer <= diff)
                {
                    Unit* target = NULL;
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);
                    if (target && target->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (DoGetThreat(target))
                            DoModifyThreatPercent(target, -100);

                        Creature* Summoned = NULL;
                        switch (rand()%6)
                        {
                            case 0:
                                DoTeleportPlayer(target, 250.0696f, 0.3921f, 84.8408f, 3.149f);
                                Summoned = me->SummonCreature(16119, 254.2325f, 0.3417f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 257.7133f, 4.0226f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 258.6702f, -2.60656f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                            case 1:
                                DoTeleportPlayer(target, 181.4220f, -91.9481f, 84.8410f, 1.608f);
                                Summoned = me->SummonCreature(16119, 184.0519f, -73.5649f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 179.5951f, -73.7045f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 180.6452f, -78.2143f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 283.2274f, -78.1518f, 84.8407f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                            case 2:
                                DoTeleportPlayer(target, 95.1547f, -1.8173f, 85.2289f, 0.043f);
                                Summoned = me->SummonCreature(16119, 100.9404f, -1.8016f, 85.2289f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 101.3729f, 0.4882f, 85.2289f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 101.4596f, -4.4740f, 85.2289f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                            case 3:
                                DoTeleportPlayer(target, 250.0696f, 0.3921f, 72.6722f, 3.149f);
                                Summoned = me->SummonCreature(16119, 240.34481f, 0.7368f, 72.6722f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 240.3633f, -2.9520f, 72.6722f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 240.6702f, 3.34949f, 72.6722f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                            case 4:
                                DoTeleportPlayer(target, 181.4220f, -91.9481f, 70.7734f, 1.608f);
                                Summoned = me->SummonCreature(16119, 184.0519f, -73.5649f, 70.7734f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 179.5951f, -73.7045f, 70.7734f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 180.6452f, -78.2143f, 70.7734f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 283.2274f, -78.1518f, 70.7734f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                            case 5:
                                DoTeleportPlayer(target, 106.1541f, -1.8994f, 75.3663f, 0.043f);
                                Summoned = me->SummonCreature(16119, 115.3945f, -1.5555f, 75.3663f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 257.7133f, 1.8066f, 75.3663f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                Summoned = me->SummonCreature(16119, 258.6702f, -5.1001f, 75.3663f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                                if (Summoned)
                                    Summoned->AI()->AttackStart(target);
                                break;
                        }
                    }
                    Teleport_Timer = urand(20000, 35000);
                } else Teleport_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_darkmaster_gandling()
{
    new boss_darkmaster_gandling();
}
