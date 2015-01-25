/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_Hydross_The_Unstable
SD%Complete: 90
SDComment: Some details and adjustments left to do, probably nothing major. Spawns may be spawned in different way/location.
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"

enum HydrossTheUnstable
{
    SAY_AGGRO                   = 0,
    SAY_SWITCH_TO_CLEAN         = 1,
    SAY_CLEAN_SLAY              = 2,
    SAY_CLEAN_DEATH             = 3,
    SAY_SWITCH_TO_CORRUPT       = 4,
    SAY_CORRUPT_SLAY            = 5,
    SAY_CORRUPT_DEATH           = 6,

    SWITCH_RADIUS               = 18,

    MODEL_CORRUPT               = 20609,
    MODEL_CLEAN                 = 20162,

    SPELL_WATER_TOMB            = 38235,
    SPELL_MARK_OF_HYDROSS1      = 38215,
    SPELL_MARK_OF_HYDROSS2      = 38216,
    SPELL_MARK_OF_HYDROSS3      = 38217,
    SPELL_MARK_OF_HYDROSS4      = 38218,
    SPELL_MARK_OF_HYDROSS5      = 38231,
    SPELL_MARK_OF_HYDROSS6      = 40584,
    SPELL_MARK_OF_CORRUPTION1   = 38219,
    SPELL_MARK_OF_CORRUPTION2   = 38220,
    SPELL_MARK_OF_CORRUPTION3   = 38221,
    SPELL_MARK_OF_CORRUPTION4   = 38222,
    SPELL_MARK_OF_CORRUPTION5   = 38230,
    SPELL_MARK_OF_CORRUPTION6   = 40583,
    SPELL_VILE_SLUDGE           = 38246,
    SPELL_ENRAGE                = 27680,                   //this spell need verification
    SPELL_SUMMON_WATER_ELEMENT  = 36459,                   //not in use yet(in use ever?)
    SPELL_ELEMENTAL_SPAWNIN     = 25035,
    SPELL_BLUE_BEAM             = 40227,                   //channeled Hydross Beam Helper (not in use yet)

    ENTRY_PURE_SPAWN            = 22035,
    ENTRY_TAINTED_SPAWN         = 22036,
    ENTRY_BEAM_DUMMY            = 21934
};


#define HYDROSS_X                   -239.439f
#define HYDROSS_Y                   -363.481f

#define SPAWN_X_DIFF1               6.934003f
#define SPAWN_Y_DIFF1               -11.255012f
#define SPAWN_X_DIFF2               -6.934003f
#define SPAWN_Y_DIFF2               11.255012f
#define SPAWN_X_DIFF3               -12.577011f
#define SPAWN_Y_DIFF3               -4.72702f
#define SPAWN_X_DIFF4               12.577011f
#define SPAWN_Y_DIFF4               4.72702f

class boss_hydross_the_unstable : public CreatureScript
{
public:
    boss_hydross_the_unstable() : CreatureScript("boss_hydross_the_unstable") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_hydross_the_unstableAI>(creature);
    }

    struct boss_hydross_the_unstableAI : public ScriptedAI
    {
        boss_hydross_the_unstableAI(Creature* creature) : ScriptedAI(creature), Summons(me)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            beams[0].Clear();
            beams[1].Clear();
            PosCheck_Timer = 2500;
            MarkOfHydross_Timer = 15000;
            MarkOfCorruption_Timer = 15000;
            WaterTomb_Timer = 7000;
            VileSludge_Timer = 7000;
            MarkOfHydross_Count = 0;
            MarkOfCorruption_Count = 0;
            EnrageTimer = 600000;

            CorruptedForm = false;
            beam = false;
        }

        InstanceScript* instance;

        ObjectGuid beams[2];
        uint32 PosCheck_Timer;
        uint32 MarkOfHydross_Timer;
        uint32 MarkOfCorruption_Timer;
        uint32 WaterTomb_Timer;
        uint32 VileSludge_Timer;
        uint32 MarkOfHydross_Count;
        uint32 MarkOfCorruption_Count;
        uint32 EnrageTimer;
        bool CorruptedForm;
        bool beam;
        SummonList Summons;

        void Reset() override
        {
            DeSummonBeams();
            Initialize();

            me->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
            me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);

            me->SetDisplayId(MODEL_CLEAN);

            instance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, NOT_STARTED);
            Summons.DespawnAll();
        }

        void SummonBeams()
        {
            Creature* beamer = me->SummonCreature(ENTRY_BEAM_DUMMY, -258.333f, -356.34f, 22.0499f, 5.90835f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            if (beamer)
            {
                beamer->CastSpell(me, SPELL_BLUE_BEAM, true);
                beamer->SetDisplayId(11686);  //invisible
                beamer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                beams[0] = beamer->GetGUID();
            }
            beamer = me->SummonCreature(ENTRY_BEAM_DUMMY, -219.918f, -371.308f, 22.0042f, 2.73072f, TEMPSUMMON_CORPSE_DESPAWN, 0);
            if (beamer)
            {
                beamer->CastSpell(me, SPELL_BLUE_BEAM, true);
                beamer->SetDisplayId(11686);  //invisible
                beamer->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                beams[1] = beamer->GetGUID();
            }
        }
        void DeSummonBeams()
        {
            for (uint8 i = 0; i < 2; ++i)
            {
                if (Creature* mob = ObjectAccessor::GetCreature(*me, beams[i]))
                {
                    mob->setDeathState(DEAD);
                    mob->RemoveCorpse();
                }
            }
        }
        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            instance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(CorruptedForm ? SAY_CORRUPT_SLAY : SAY_CLEAN_SLAY);
        }

        void JustSummoned(Creature* summoned) override
        {
            if (summoned->GetEntry() == ENTRY_PURE_SPAWN)
            {
                summoned->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                summoned->CastSpell(summoned, SPELL_ELEMENTAL_SPAWNIN, true);
                Summons.Summon(summoned);
            }
            if (summoned->GetEntry() == ENTRY_TAINTED_SPAWN)
            {
                summoned->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
                summoned->CastSpell(summoned, SPELL_ELEMENTAL_SPAWNIN, true);
                Summons.Summon(summoned);
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            Summons.Despawn(summon);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(CorruptedForm ? SAY_CORRUPT_DEATH : SAY_CLEAN_DEATH);

            instance->SetData(DATA_HYDROSSTHEUNSTABLEEVENT, DONE);
            Summons.DespawnAll();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!beam)
            {
                SummonBeams();
                beam=true;
            }
            //Return since we have no target
            if (!UpdateVictim())
                return;

            // corrupted form
            if (CorruptedForm)
            {
                //MarkOfCorruption_Timer
                if (MarkOfCorruption_Timer <= diff)
                {
                    if (MarkOfCorruption_Count <= 5)
                    {
                        uint32 mark_spell = 0;

                        switch (MarkOfCorruption_Count)
                        {
                            case 0:
                                mark_spell = SPELL_MARK_OF_CORRUPTION1;
                                break;

                            case 1:
                                mark_spell = SPELL_MARK_OF_CORRUPTION2;
                                break;

                            case 2:
                                mark_spell = SPELL_MARK_OF_CORRUPTION3;
                                break;

                            case 3:
                                mark_spell = SPELL_MARK_OF_CORRUPTION4;
                                break;

                            case 4:
                                mark_spell = SPELL_MARK_OF_CORRUPTION5;
                                break;

                            case 5:
                                mark_spell = SPELL_MARK_OF_CORRUPTION6;
                                break;
                        }

                        DoCastVictim(mark_spell);

                        if (MarkOfCorruption_Count < 5)
                            ++MarkOfCorruption_Count;
                    }

                    MarkOfCorruption_Timer = 15000;
                } else MarkOfCorruption_Timer -= diff;

                //VileSludge_Timer
                if (VileSludge_Timer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_VILE_SLUDGE);

                    VileSludge_Timer = 15000;
                } else VileSludge_Timer -= diff;

                //PosCheck_Timer
                if (PosCheck_Timer <= diff)
                {
                    if (me->IsWithinDist2d(HYDROSS_X, HYDROSS_Y, SWITCH_RADIUS))
                    {
                        // switch to clean form
                        me->SetDisplayId(MODEL_CLEAN);
                        CorruptedForm = false;
                        MarkOfHydross_Count = 0;

                        Talk(SAY_SWITCH_TO_CLEAN);
                        DoResetThreat();
                        SummonBeams();

                        // spawn 4 adds
                        DoSpawnCreature(ENTRY_PURE_SPAWN, SPAWN_X_DIFF1, SPAWN_Y_DIFF1, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_PURE_SPAWN, SPAWN_X_DIFF2, SPAWN_Y_DIFF2, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_PURE_SPAWN, SPAWN_X_DIFF3, SPAWN_Y_DIFF3, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_PURE_SPAWN, SPAWN_X_DIFF4, SPAWN_Y_DIFF4, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);

                        me->SetMeleeDamageSchool(SPELL_SCHOOL_FROST);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, false);
                    }

                    PosCheck_Timer = 2500;
                } else PosCheck_Timer -=diff;
            }
            // clean form
            else
            {
                //MarkOfHydross_Timer
                if (MarkOfHydross_Timer <= diff)
                {
                    if (MarkOfHydross_Count <= 5)
                    {
                        uint32 mark_spell = 0;

                        switch (MarkOfHydross_Count)
                        {
                            case 0:
                                mark_spell = SPELL_MARK_OF_HYDROSS1;
                                break;

                            case 1:
                                mark_spell = SPELL_MARK_OF_HYDROSS2;
                                break;

                            case 2:
                                mark_spell = SPELL_MARK_OF_HYDROSS3;
                                break;

                            case 3:
                                mark_spell = SPELL_MARK_OF_HYDROSS4;
                                break;

                            case 4:
                                mark_spell = SPELL_MARK_OF_HYDROSS5;
                                break;

                            case 5:
                                mark_spell = SPELL_MARK_OF_HYDROSS6;
                                break;
                        }

                        DoCastVictim(mark_spell);

                        if (MarkOfHydross_Count < 5)
                            ++MarkOfHydross_Count;
                    }

                    MarkOfHydross_Timer = 15000;
                } else MarkOfHydross_Timer -= diff;

                //WaterTomb_Timer
                if (WaterTomb_Timer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true);
                    if (target)
                        DoCast(target, SPELL_WATER_TOMB);

                    WaterTomb_Timer = 7000;
                } else WaterTomb_Timer -= diff;

                //PosCheck_Timer
                if (PosCheck_Timer <= diff)
                {
                    if (!me->IsWithinDist2d(HYDROSS_X, HYDROSS_Y, SWITCH_RADIUS))
                    {
                        // switch to corrupted form
                        me->SetDisplayId(MODEL_CORRUPT);
                        MarkOfCorruption_Count = 0;
                        CorruptedForm = true;

                        Talk(SAY_SWITCH_TO_CORRUPT);
                        DoResetThreat();
                        DeSummonBeams();

                        // spawn 4 adds
                        DoSpawnCreature(ENTRY_TAINTED_SPAWN, SPAWN_X_DIFF1, SPAWN_Y_DIFF1, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_TAINTED_SPAWN, SPAWN_X_DIFF2, SPAWN_Y_DIFF2, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_TAINTED_SPAWN, SPAWN_X_DIFF3, SPAWN_Y_DIFF3, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                        DoSpawnCreature(ENTRY_TAINTED_SPAWN, SPAWN_X_DIFF4, SPAWN_Y_DIFF4, 3, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);

                        me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
                        me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, false);
                    }

                    PosCheck_Timer = 2500;
                } else PosCheck_Timer -=diff;
            }

            //EnrageTimer
            if (EnrageTimer <= diff)
            {
                DoCast(me, SPELL_ENRAGE);
                EnrageTimer = 60000;
            } else EnrageTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_hydross_the_unstable()
{
    new boss_hydross_the_unstable();
}
