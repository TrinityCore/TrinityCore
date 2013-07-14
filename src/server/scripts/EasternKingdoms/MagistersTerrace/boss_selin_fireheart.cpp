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
SDName: Boss_Selin_Fireheart
SD%Complete: 90
SDComment: Heroic and Normal Support. Needs further testing.
SDCategory: Magister's Terrace
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "magisters_terrace.h"

enum Says
{
    SAY_AGGRO                       = 0,
    SAY_ENERGY                      = 1,
    SAY_EMPOWERED                   = 2,
    SAY_KILL                        = 3,
    SAY_DEATH                       = 4,
    EMOTE_CRYSTAL                   = 5
};

enum Spells
{
    //Crystal effect spells
    SPELL_FEL_CRYSTAL_COSMETIC      = 44374,
    SPELL_FEL_CRYSTAL_DUMMY         = 44329,
    SPELL_FEL_CRYSTAL_VISUAL        = 44355,
    SPELL_MANA_RAGE                 = 44320,               // This spell triggers 44321, which changes scale and regens mana Requires an entry in spell_script_target

    //Selin's spells
    SPELL_DRAIN_LIFE                = 44294,
    SPELL_FEL_EXPLOSION             = 44314,

    SPELL_DRAIN_MANA                = 46153               // Heroic only
};

enum Misc
{
    CRYSTALS_NUMBER                 = 5,
    DATA_CRYSTALS                   = 6,
    CREATURE_FEL_CRYSTAL            = 24722
};

class boss_selin_fireheart : public CreatureScript
{
public:
    boss_selin_fireheart() : CreatureScript("boss_selin_fireheart") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_selin_fireheartAI(creature);
    };

    struct boss_selin_fireheartAI : public ScriptedAI
    {
        boss_selin_fireheartAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            Crystals.clear();
            //GUIDs per instance is static, so we only need to load them once.
            if (instance)
            {
                uint32 size = instance->GetData(DATA_FEL_CRYSTAL_SIZE);
                for (uint8 i = 0; i < size; ++i)
                {
                    instance->SetData64(DATA_FEL_CRYSTAL, i);
                    uint64 guid = instance->GetData64(DATA_FEL_CRYSTAL);
                    TC_LOG_DEBUG(LOG_FILTER_TSCR, "Selin: Adding Fel Crystal " UI64FMTD " to list", guid);
                    Crystals.push_back(guid);
                }
            }
        }

        InstanceScript* instance;

        std::list<uint64> Crystals;

        uint32 DrainLifeTimer;
        uint32 DrainManaTimer;
        uint32 FelExplosionTimer;
        uint32 DrainCrystalTimer;
        uint32 EmpowerTimer;

        bool IsDraining;
        bool DrainingCrystal;

        uint64 CrystalGUID;                                     // This will help us create a pointer to the crystal we are draining. We store GUIDs, never units in case unit is deleted/offline (offline if player of course).

        void Reset() OVERRIDE
        {
            if (instance)
            {
                //for (uint8 i = 0; i < CRYSTALS_NUMBER; ++i)
                for (std::list<uint64>::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
                {
                    //Unit* unit = Unit::GetUnit(*me, FelCrystals[i]);
                    if (Creature* creature = Unit::GetCreature(*me, *itr))
                    {
                        if (!creature->IsAlive())
                            creature->Respawn();      // Let the core handle setting death state, etc.

                        // Only need to set unselectable flag. You can't attack unselectable units so non_attackable flag is not necessary here.
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                }

                // Set Inst data for encounter
                instance->SetData(DATA_SELIN_EVENT, NOT_STARTED);
            } else TC_LOG_ERROR(LOG_FILTER_TSCR, ERROR_INST_DATA);

            DrainLifeTimer = urand(3000, 7000);
            DrainManaTimer = DrainLifeTimer + 5000;
            FelExplosionTimer = 2100;
            if (IsHeroic())
                DrainCrystalTimer = urand(10000, 15000);
            else
                DrainCrystalTimer = urand(20000, 25000);
            EmpowerTimer = 10000;

            IsDraining = false;
            DrainingCrystal = false;
            CrystalGUID = 0;
        }

        void SelectNearestCrystal()
        {
            if (Crystals.empty())
                return;

            //float ShortestDistance = 0;
            CrystalGUID = 0;
            Unit* pCrystal = NULL;
            Unit* CrystalChosen = NULL;
            //for (uint8 i =  0; i < CRYSTALS_NUMBER; ++i)
            for (std::list<uint64>::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
            {
                pCrystal = NULL;
                //pCrystal = Unit::GetUnit(*me, FelCrystals[i]);
                pCrystal = Unit::GetUnit(*me, *itr);
                if (pCrystal && pCrystal->IsAlive())
                {
                    // select nearest
                    if (!CrystalChosen || me->GetDistanceOrder(pCrystal, CrystalChosen, false))
                    {
                        CrystalGUID = pCrystal->GetGUID();
                        CrystalChosen = pCrystal;               // Store a copy of pCrystal so we don't need to recreate a pointer to closest crystal for the movement and yell.
                    }
                }
            }
            if (CrystalChosen)
            {
                Talk(SAY_ENERGY);
                Talk(EMOTE_CRYSTAL);

                CrystalChosen->CastSpell(CrystalChosen, SPELL_FEL_CRYSTAL_COSMETIC, true);

                float x, y, z;                                  // coords that we move to, close to the crystal.
                CrystalChosen->GetClosePoint(x, y, z, me->GetObjectSize(), CONTACT_DISTANCE);

                me->SetWalk(false);
                me->GetMotionMaster()->MovePoint(1, x, y, z);
                DrainingCrystal = true;
            }
        }

        void ShatterRemainingCrystals()
        {
            if (Crystals.empty())
                return;

            //for (uint8 i = 0; i < CRYSTALS_NUMBER; ++i)
            for (std::list<uint64>::const_iterator itr = Crystals.begin(); itr != Crystals.end(); ++itr)
            {
                //Creature* pCrystal = (Unit::GetCreature(*me, FelCrystals[i]));
                Creature* pCrystal = Unit::GetCreature(*me, *itr);
                if (pCrystal && pCrystal->IsAlive())
                    pCrystal->Kill(pCrystal);
            }
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            if (instance)
                instance->SetData(DATA_SELIN_EVENT, IN_PROGRESS);
         }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_KILL);
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type == POINT_MOTION_TYPE && id == 1)
            {
                Unit* CrystalChosen = Unit::GetUnit(*me, CrystalGUID);
                if (CrystalChosen && CrystalChosen->IsAlive())
                {
                    // Make the crystal attackable
                    // We also remove NON_ATTACKABLE in case the database has it set.
                    CrystalChosen->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE + UNIT_FLAG_NOT_SELECTABLE);
                    CrystalChosen->CastSpell(me, SPELL_MANA_RAGE, true);
                    IsDraining = true;
                }
                else
                {
                    // Make an error message in case something weird happened here
                    TC_LOG_ERROR(LOG_FILTER_TSCR, "Selin Fireheart unable to drain crystal as the crystal is either dead or despawned");
                    DrainingCrystal = false;
                }
            }
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            if (!instance)
                return;

            instance->SetData(DATA_SELIN_EVENT, DONE);         // Encounter complete!
            ShatterRemainingCrystals();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            if (!DrainingCrystal)
            {
                uint32 maxPowerMana = me->GetMaxPower(POWER_MANA);
                if (maxPowerMana && ((me->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
                {
                    if (DrainLifeTimer <= diff)
                    {
                        DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0), SPELL_DRAIN_LIFE);
                        DrainLifeTimer = 10000;
                    } else DrainLifeTimer -= diff;

                    // Heroic only
                    if (IsHeroic())
                    {
                        if (DrainManaTimer <= diff)
                        {
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 1), SPELL_DRAIN_MANA);
                            DrainManaTimer = 10000;
                        } else DrainManaTimer -= diff;
                    }
                }

                if (FelExplosionTimer <= diff)
                {
                    if (!me->IsNonMeleeSpellCasted(false))
                    {
                        DoCast(me, SPELL_FEL_EXPLOSION);
                        FelExplosionTimer = 2000;
                    }
                } else FelExplosionTimer -= diff;

                // If below 10% mana, start recharging
                maxPowerMana = me->GetMaxPower(POWER_MANA);
                if (maxPowerMana && ((me->GetPower(POWER_MANA)*100 / maxPowerMana) < 10))
                {
                    if (DrainCrystalTimer <= diff)
                    {
                        SelectNearestCrystal();
                        if (IsHeroic())
                            DrainCrystalTimer = urand(10000, 15000);
                        else
                            DrainCrystalTimer = urand(20000, 25000);
                    } else DrainCrystalTimer -= diff;
                }
            }else
            {
                if (IsDraining)
                {
                    if (EmpowerTimer <= diff)
                    {
                        IsDraining = false;
                        DrainingCrystal = false;

                        Talk(SAY_EMPOWERED);

                        Unit* CrystalChosen = Unit::GetUnit(*me, CrystalGUID);
                        if (CrystalChosen && CrystalChosen->IsAlive())
                            // Use Deal Damage to kill it, not setDeathState.
                            CrystalChosen->Kill(CrystalChosen);

                        CrystalGUID = 0;

                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveChase(me->GetVictim());
                    } else EmpowerTimer -= diff;
                }
            }

            DoMeleeAttackIfReady();                             // No need to check if we are draining crystal here, as the spell has a stun.
        }
    };
};

class npc_fel_crystal : public CreatureScript
{
public:
    npc_fel_crystal() : CreatureScript("npc_fel_crystal") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_fel_crystalAI(creature);
    };

    struct npc_fel_crystalAI : public ScriptedAI
    {
        npc_fel_crystalAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() OVERRIDE {}
        void EnterCombat(Unit* /*who*/) OVERRIDE {}
        void AttackStart(Unit* /*who*/) OVERRIDE {}
        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE {}

        void UpdateAI(uint32 /*diff*/) OVERRIDE {}

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                Creature* Selin = (Unit::GetCreature(*me, instance->GetData64(DATA_SELIN)));
                if (Selin && Selin->IsAlive())
                {
                    if (CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->CrystalGUID == me->GetGUID())
                    {
                        // Set this to false if we are the Creature that Selin is draining so his AI flows properly
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->DrainingCrystal = false;
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->IsDraining = false;
                        CAST_AI(boss_selin_fireheart::boss_selin_fireheartAI, Selin->AI())->EmpowerTimer = 10000;
                        if (Selin->GetVictim())
                        {
                            Selin->AI()->AttackStart(Selin->GetVictim());
                            Selin->GetMotionMaster()->MoveChase(Selin->GetVictim());
                        }
                    }
                }
            } else TC_LOG_ERROR(LOG_FILTER_TSCR, ERROR_INST_DATA);
        }
    };
};

void AddSC_boss_selin_fireheart()
{
    new boss_selin_fireheart();
    new npc_fel_crystal();
}
