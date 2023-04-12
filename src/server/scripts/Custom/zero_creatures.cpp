///* Copyright (C) 2009 - 2010 ScriptDevZero <http://github.com/scriptdevzero/scriptdevzero>
// * This program is free software; you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation; either version 2 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program; if not, write to the Free Software
// * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
// */
//
//#include "scriptPCH.h"
//#include "custom.h"
//
//
// /* ScriptData
// SDName: Boss_Razorgore
// SD%Complete: 70%
// SDComment:
// Lack of support for Orb of Command
// implemented that Razorgore is unattackable during phase 1 instead of the use of Orb of Command, more playable then before now.
// SDCategory: Blackwing Lair
// EndScriptData */
//
//#include "scriptPCH.h"
//#include "../eastern_kingdoms/burning_steppes/blackwing_lair/blackwing_lair.h"
//
// // Razorgore Phase 2 Script
//#define SAY_EGGS_BROKEN1        -1469022
//#define SAY_EGGS_BROKEN2        -1469023
//#define SAY_EGGS_BROKEN3        -1469024
//#define SAY_DEATH               -1469025
//#define SAY_AGGRO  "Intruders have breached the Hatchery! Sound the alarm! Protect the eggs at all costs!"
//
//// Razorgore The Untamed Spells
//#define SPELL_CLEAVE             22540
//#define SPELL_WARSTOMP           24375
//#define SPELL_FIREBALLVOLLEY     22425
//#define SPELL_CONFLAGRATION      23023
//#define SPELL_PHASE_1            22663
//
//// Grethok The Controller Spells
//#define SPELL_GREATER_POLYMORPH  22274
//#define SPELL_DOMINATE_MIND      14515
//#define SPELL_ARCANE_MISSILES    22273 // Spell Doesn't Work 100%, should be three charges instead of one 
//#define SPELL_SLOW               13747
//
//// Creature Spawns
//#define BLACKWING_LEGGIONAIRE      12416
//#define DEATH_TALON_DRAGONSPAWN    12422
//#define BLACKWING_MAGE             12420
//
//// North
//#define SPAWN_X1              -7540.8f
//#define SPAWN_Y1              -1052.6f
//#define SPAWN_Z1              408.490f
//// South
//#define SPAWN_X2              -7648.8f
//#define SPAWN_Y2              -1053.8f
//#define SPAWN_Z2              408.490f
//// Eeast
//#define SPAWN_X3              -7614.1f
//#define SPAWN_Y3              -1103.6f
//#define SPAWN_Z3              408.490f
//// West
//#define SPAWN_X4              -7578.1f
//#define SPAWN_Y4              -1003.5f
//#define SPAWN_Z4              408.490f
//// Razorgore Spawn
//#define RAZOR_SPAWN_X         -7570.6f
//#define RAZOR_SPAWN_Y         -1090.0f
//#define RAZOR_SPAWN_Z         413.559f
//
//
//struct Zero_boss_razorgoreAI : public ScriptedAI
//{
//    Zero_boss_razorgoreAI(Creature* pCreature) : ScriptedAI(pCreature)
//    {
//        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
//        Reset();
//    }
//
//    ScriptedInstance* m_pInstance;
//
//    uint32 Cleave_Timer;
//    uint32 WarStomp_Timer;
//    uint32 FireballVolley_Timer;
//    uint32 Conflagration_Timer;
//
//    uint32 SpawnedAdds;
//    uint32 AddSpawnTimer;
//    uint32 SpawnType1;
//    uint32 SpawnType2;
//    uint32 SpawnType3;
//    uint32 SpawnType4;
//    uint32 Despawn_Timer;
//    uint32 Razor_Spawn_Delay;
//
//    uint32 Razor_Phase_1;
//    uint32 Razor_Phase_2;
//    uint32 Razor_Remove_Auras;
//
//    void Reset() override
//    {
//        Cleave_Timer = 15000;                               //These times are probably wrong
//        WarStomp_Timer = 35000;
//        FireballVolley_Timer = 7000;
//        Conflagration_Timer = 12000;
//        SpawnedAdds = 0;
//        AddSpawnTimer = 60000;
//        Despawn_Timer = 240000;
//
//        Razor_Phase_1 = 1;
//        Razor_Phase_2 = 300000;
//        Razor_Remove_Auras = 300000;
//
//        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SPAWNING);
//
//
//    }
//
//    void Aggro(Unit* pWho) override
//    {
//        m_creature->SetInCombatWithZone();
//
//        //m_creature->MonsterYell(SAY_AGGRO, LANG_UNIVERSAL, nullptr);
//        DoPlaySoundToSet(m_creature, 8272);
//    }
//
//    void JustDied(Unit* Killer) override
//    {
//        DoScriptText(SAY_DEATH, m_creature);
//        m_pInstance->SetData(TYPE_RAZORGORE, DONE);
//    }
//
//    void UpdateAI(uint32 const diff) override
//    {
//        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
//            return;
//
//        if (Razor_Phase_1 == 1)
//        {
//
//
//
//            m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SPAWNING);
//
//            m_creature->GetMap()->CreatureRelocation(m_creature, -7595, -1053, 408, 0.0f);
//            DoCastSpellIfCan(m_creature, 31366);
//            Razor_Phase_1 = 0;
//
//        }
//
//
//        if (Razor_Remove_Auras < diff)
//        {
//
//            Unit* target = nullptr;
//            target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
//            m_creature->AI()->AttackStart(target);
//
//            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
//            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SPAWNING);
//
//            m_creature->RemoveAurasDueToSpell(31366);
//
//            Razor_Remove_Auras = 1000000;
//        }
//        else Razor_Remove_Auras -= diff;
//
//        if (Razor_Phase_2 < diff)
//        {
//
//            //Cleave_Timer
//            if (Cleave_Timer < diff)
//            {
//                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CLEAVE);
//                Cleave_Timer = urand(7000, 10000);
//            }
//            else Cleave_Timer -= diff;
//
//
//            //WarStomp_Timer
//            if (WarStomp_Timer < diff)
//            {
//                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_WARSTOMP);
//                WarStomp_Timer = urand(15000, 25000);
//            }
//            else WarStomp_Timer -= diff;
//
//
//            //FireballVolley_Timer
//            if (FireballVolley_Timer < diff)
//            {
//                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FIREBALLVOLLEY);
//                FireballVolley_Timer = urand(12000, 15000);
//            }
//            else FireballVolley_Timer -= diff;
//
//            //Conflagration_Timer
//            if (Conflagration_Timer < diff)
//            {
//                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CONFLAGRATION);
//
//                Conflagration_Timer = 12000;
//            }
//            else Conflagration_Timer -= diff;
//
//            // Aura Check. If the gamer is affected by confliguration we attack a random gamer.
//            if (m_creature->GetVictim()->HasAura(SPELL_CONFLAGRATION, EFFECT_INDEX_0))
//            {
//                Unit* target = nullptr;
//                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1);
//                if (target)
//                    m_creature->TauntApply(target);
//            }
//            Razor_Phase_2 = 0;
//        }
//        else Razor_Phase_2 -= diff;
//
//
//        if (SpawnedAdds < 42)
//        {
//
//            // spawn add
//            if (AddSpawnTimer < diff)
//            {
//                // Spawn North (40% Blackwing_Mage, 40% Blackwing_Leggionaire 20% Death_Talon_Dragonspawn)
//                switch (urand(0, 4))
//
//                {
//                case 0:
//                    SpawnType1 = BLACKWING_MAGE;
//                    break;
//                case 1:
//                    SpawnType1 = BLACKWING_MAGE;
//                    break;
//                case 2:
//                    SpawnType1 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 3:
//                    SpawnType1 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 4:
//                    SpawnType1 = DEATH_TALON_DRAGONSPAWN;
//                    break;
//                }
//
//                // Spawn South (40% Blackwing_Mage, 40% Blackwing_Leggionaire 20% Death_Talon_Dragonspawn)
//                switch (urand(0, 4))
//
//                {
//                case 0:
//                    SpawnType2 = BLACKWING_MAGE;
//                    break;
//                case 1:
//                    SpawnType2 = BLACKWING_MAGE;
//                    break;
//                case 2:
//                    SpawnType2 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 3:
//                    SpawnType2 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 4:
//                    SpawnType2 = DEATH_TALON_DRAGONSPAWN;
//                    break;
//                }
//
//                // Spawn East (40% Blackwing_Mage, 40% Blackwing_Leggionaire 20% Death_Talon_Dragonspawn)
//                switch (urand(0, 4))
//
//                {
//                case 0:
//                    SpawnType3 = BLACKWING_MAGE;
//                    break;
//                case 1:
//                    SpawnType3 = BLACKWING_MAGE;
//                    break;
//                case 2:
//                    SpawnType3 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 3:
//                    SpawnType3 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 4:
//                    SpawnType3 = DEATH_TALON_DRAGONSPAWN;
//                    break;
//                }
//
//                // Spawn West (40% Blackwing_Mage, 40% Blackwing_Leggionaire 20% Death_Talon_Dragonspawn)
//                switch (urand(0, 4))
//
//                {
//                case 0:
//                    SpawnType4 = BLACKWING_MAGE;
//                    break;
//                case 1:
//                    SpawnType4 = BLACKWING_MAGE;
//                    break;
//                case 2:
//                    SpawnType4 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 3:
//                    SpawnType4 = BLACKWING_LEGGIONAIRE;
//                    break;
//                case 4:
//                    SpawnType4 = DEATH_TALON_DRAGONSPAWN;
//                    break;
//                }
//
//                Creature* Spawned = nullptr;
//                Unit* target = nullptr;
//
//                ++SpawnedAdds;
//
//                //Spawn creature and force it to start attacking a random target
//
//                Spawned = m_creature->SummonCreature(SpawnType1, SPAWN_X1, SPAWN_Y1, SPAWN_Z1, 5.000, TEMPSUMMON_TIMED_DESPAWN, Despawn_Timer);
//                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
//
//                if (target && Spawned)
//                {
//                    Spawned->AI()->AttackStart(target);
//                    Spawned->SetFactionTemplateId(103);
//                }
//
//                ++SpawnedAdds;
//
//                //Spawn creature and force it to start attacking a random target
//                target = nullptr;
//                Spawned = nullptr;
//                Spawned = m_creature->SummonCreature(SpawnType2, SPAWN_X2, SPAWN_Y2, SPAWN_Z2, 5.000, TEMPSUMMON_TIMED_DESPAWN, Despawn_Timer);
//                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
//
//                if (target && Spawned)
//                {
//                    Spawned->AI()->AttackStart(target);
//                    Spawned->SetFactionTemplateId(103);
//                }
//
//
//                ++SpawnedAdds;
//
//                //Spawn creature and force it to start attacking a random target
//                target = nullptr;
//                Spawned = nullptr;
//                Spawned = m_creature->SummonCreature(SpawnType3, SPAWN_X3, SPAWN_Y3, SPAWN_Z3, 5.000, TEMPSUMMON_TIMED_DESPAWN, Despawn_Timer);
//                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
//
//                if (target && Spawned)
//                {
//                    Spawned->AI()->AttackStart(target);
//                    Spawned->SetFactionTemplateId(103);
//
//                }
//
//                ++SpawnedAdds;
//
//                //Spawn creature and force it to start attacking a random target
//                target = nullptr;
//                Spawned = nullptr;
//                Spawned = m_creature->SummonCreature(SpawnType4, SPAWN_X4, SPAWN_Y4, SPAWN_Z4, 5.000, TEMPSUMMON_TIMED_DESPAWN, Despawn_Timer);
//                target = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
//
//                if (target && Spawned)
//                {
//                    Spawned->AI()->AttackStart(target);
//                    Spawned->SetFactionTemplateId(103);
//                }
//                Despawn_Timer = Despawn_Timer - 15000;
//                AddSpawnTimer = 15000;
//            }
//            else AddSpawnTimer -= diff;
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
//// Grethok The Controller Script
//
//struct Mob_Grethok_The_ControllerAI : public ScriptedAI
//{
//    Mob_Grethok_The_ControllerAI(Creature* pCreature) : ScriptedAI(pCreature)
//    {
//        Reset();
//    }
//
//    ScriptedInstance* m_pInstance;
//
//    uint32 Greater_Polymorph_Timer;
//    uint32 Dominate_Mind_Timer;
//    uint32 Arcane_Missiles_Timer;
//    uint32 Slow_Timer;
//    uint32 Razorgore_Spawn;
//
//    void Reset() override
//    {
//        Greater_Polymorph_Timer = 3000;
//        Dominate_Mind_Timer = 1000;
//        Arcane_Missiles_Timer = 5000;
//        Slow_Timer = 7000;
//        Razorgore_Spawn = 1;
//    }
//
//    void Aggro(Unit* pWho) override
//    {
//        m_creature->SetInCombatWithZone();
//
//    }
//    void UpdateAI(uint32 const diff) override
//    {
//
//        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
//            return;
//
//        // Greater Polymorph
//        if (Greater_Polymorph_Timer < diff)
//        {
//            DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_GREATER_POLYMORPH);
//            Greater_Polymorph_Timer = 10000;
//        }
//        else Greater_Polymorph_Timer -= diff;
//
//        // Dominate Mind
//        if (Dominate_Mind_Timer < diff)
//        {
//            DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_DOMINATE_MIND);
//            Dominate_Mind_Timer = 15000;
//        }
//        else Dominate_Mind_Timer -= diff;
//
//        // Arcane Missiles
//        if (Arcane_Missiles_Timer < diff)
//        {
//            DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_ARCANE_MISSILES);
//            Arcane_Missiles_Timer = 3000;
//        }
//        else Arcane_Missiles_Timer -= diff;
//
//        // Slow
//        if (Slow_Timer < diff)
//        {
//            DoCastSpellIfCan(m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0), SPELL_SLOW);
//            Slow_Timer = 8000;
//        }
//        else Slow_Timer -= diff;
//
//
//        DoMeleeAttackIfReady();
//    }
//};
//CreatureAI* GetZeroAI_boss_razorgore(Creature* pCreature)
//{
//    return new Zero_boss_razorgoreAI(pCreature);
//}
//
//CreatureAI* GetZeroAI_Mob_Grethok_The_Controller(Creature* pCreature)
//{
//    return new Mob_Grethok_The_ControllerAI(pCreature);
//}
//
//
//
//
//
//void AddSC_zero_creatures()
//{
//    Script* newscript;
//    newscript = new Script;
//    newscript->Name = "zero_boss_razorgore";
//    newscript->GetAI = &GetZeroAI_boss_razorgore;
//    newscript->RegisterSelf(true);
//
//    newscript = new Script;
//    newscript->Name = "zero_Mob_Grethok_The_Controller";
//    newscript->GetAI = &GetZeroAI_Mob_Grethok_The_Controller;
//    newscript->RegisterSelf(true);
//}
