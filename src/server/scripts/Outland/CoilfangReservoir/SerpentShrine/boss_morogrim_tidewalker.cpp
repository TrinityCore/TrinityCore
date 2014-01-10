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
SDName: Boss_Morogrim_Tidewalker
SD%Complete: 90
SDComment: Water globules don't explode properly, remove hacks
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"

enum Yells
{
    // Yell
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_SUMMON_BUBL                 = 2,
    SAY_SLAY                        = 3,
    SAY_DEATH                       = 4,
    // Emotes
    EMOTE_WATERY_GRAVE              = 5,
    EMOTE_EARTHQUAKE                = 6,
    EMOTE_WATERY_GLOBULES           = 7
};

enum Spells
{
    SPELL_TIDAL_WAVE                = 37730,
    SPELL_WATERY_GRAVE              = 38049,
    SPELL_EARTHQUAKE                = 37764,
    SPELL_WATERY_GRAVE_EXPLOSION    = 37852,

    SPELL_WATERY_GRAVE_1            = 38023,
    SPELL_WATERY_GRAVE_2            = 38024,
    SPELL_WATERY_GRAVE_3            = 38025,
    SPELL_WATERY_GRAVE_4            = 37850,

    SPELL_SUMMON_WATER_GLOBULE_1    = 37854,
    SPELL_SUMMON_WATER_GLOBULE_2    = 37858,
    SPELL_SUMMON_WATER_GLOBULE_3    = 37860,
    SPELL_SUMMON_WATER_GLOBULE_4    = 37861,

    // Water Globule
    SPELL_GLOBULE_EXPLOSION         = 37871
};

enum Creatures
{
    // Creatures
    NPC_WATER_GLOBULE               = 21913,
    NPC_TIDEWALKER_LURKER           = 21920
};

float MurlocCords[10][4] =
{
      {424.36f, -715.4f,  -7.14f,  0.124f},
      {425.13f, -719.3f,  -7.14f,  0.124f},
      {425.05f, -724.23f, -7.14f,  0.124f},
      {424.91f, -728.68f, -7.14f,  0.124f},
      {424.84f, -732.18f, -7.14f,  0.124f},
      {321.05f, -734.2f,  -13.15f, 0.124f},
      {321.05f, -729.4f,  -13.15f, 0.124f},
      {321.05f, -724.03f, -13.15f, 0.124f},
      {321.05f, -718.73f, -13.15f, 0.124f},
      {321.05f, -714.24f, -13.15f, 0.124f}
};

//Morogrim Tidewalker AI
class boss_morogrim_tidewalker : public CreatureScript
{
public:
    boss_morogrim_tidewalker() : CreatureScript("boss_morogrim_tidewalker") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_morogrim_tidewalkerAI>(creature);
    }

    struct boss_morogrim_tidewalkerAI : public ScriptedAI
    {
        boss_morogrim_tidewalkerAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        Map::PlayerList const* PlayerList;

        uint32 TidalWave_Timer;
        uint32 WateryGrave_Timer;
        uint32 Earthquake_Timer;
        uint32 WateryGlobules_Timer;
        uint32 globulespell[4];
        int8 Playercount;
        int8 counter;

        bool Earthquake;
        bool Phase2;

        void Reset() OVERRIDE
        {
            TidalWave_Timer = 10000;
            WateryGrave_Timer = 30000;
            Earthquake_Timer = 40000;
            WateryGlobules_Timer = 0;
            globulespell[0] = SPELL_SUMMON_WATER_GLOBULE_1;
            globulespell[1] = SPELL_SUMMON_WATER_GLOBULE_2;
            globulespell[2] = SPELL_SUMMON_WATER_GLOBULE_3;
            globulespell[3] = SPELL_SUMMON_WATER_GLOBULE_4;

            Earthquake = false;
            Phase2 = false;

            instance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
        }

        void StartEvent()
        {
            Talk(SAY_AGGRO);

            instance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);

            instance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, DONE);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            PlayerList = &me->GetMap()->GetPlayers();
            Playercount = PlayerList->getSize();
            StartEvent();
        }

        void ApplyWateryGrave(Unit* player, uint8 i)
        {
            switch (i)
            {
            case 0: player->CastSpell(player, SPELL_WATERY_GRAVE_1, true); break;
            case 1: player->CastSpell(player, SPELL_WATERY_GRAVE_2, true); break;
            case 2: player->CastSpell(player, SPELL_WATERY_GRAVE_3, true); break;
            case 3: player->CastSpell(player, SPELL_WATERY_GRAVE_4, true); break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Earthquake_Timer
            if (Earthquake_Timer <= diff)
            {
                if (!Earthquake)
                {
                    DoCastVictim(SPELL_EARTHQUAKE);
                    Earthquake = true;
                    Earthquake_Timer = 10000;
                }
                else
                {
                    Talk(SAY_SUMMON);

                    for (uint8 i = 0; i < 10; ++i)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            if (Creature* Murloc = me->SummonCreature(NPC_TIDEWALKER_LURKER, MurlocCords[i][0], MurlocCords[i][1], MurlocCords[i][2], MurlocCords[i][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000))
                                Murloc->AI()->AttackStart(target);
                    }
                    Talk(EMOTE_EARTHQUAKE);
                    Earthquake = false;
                    Earthquake_Timer = 40000+rand()%5000;
                }
            } else Earthquake_Timer -= diff;

            //TidalWave_Timer
            if (TidalWave_Timer <= diff)
            {
                DoCastVictim(SPELL_TIDAL_WAVE);
                TidalWave_Timer = 20000;
            } else TidalWave_Timer -= diff;

            if (!Phase2)
            {
                //WateryGrave_Timer
                if (WateryGrave_Timer <= diff)
                {
                    //Teleport 4 players under the waterfalls
                    Unit* target;
                    std::set<uint64> list;
                    std::set<uint64>::const_iterator itr;
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        counter = 0;
                        do
                        {
                            target = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);    //target players only
                            if (counter < Playercount)
                                break;
                            if (target)
                                itr = list.find(target->GetGUID());
                            ++counter;
                        } while (itr != list.end());

                        if (target)
                        {
                            list.insert(target->GetGUID());
                            ApplyWateryGrave(target, i);
                        }
                    }

                    Talk(SAY_SUMMON_BUBL);

                    Talk(EMOTE_WATERY_GRAVE);
                    WateryGrave_Timer = 30000;
                } else WateryGrave_Timer -= diff;

                //Start Phase2
                if (HealthBelowPct(25))
                    Phase2 = true;
            }
            else
            {
                //WateryGlobules_Timer
                if (WateryGlobules_Timer <= diff)
                {
                    Unit* pGlobuleTarget;
                    std::set<uint64> globulelist;
                    std::set<uint64>::const_iterator itr;
                    for (uint8 g = 0; g < 4; g++)  //one unit can't cast more than one spell per update, so some players have to cast for us XD
                    {
                        counter = 0;
                        do
                        {
                            pGlobuleTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                            if (pGlobuleTarget)
                                itr = globulelist.find(pGlobuleTarget->GetGUID());
                            if (counter > Playercount)
                                break;
                            ++counter;
                        } while (itr != globulelist.end());
                        if (pGlobuleTarget)
                        {
                            globulelist.insert(pGlobuleTarget->GetGUID());
                            pGlobuleTarget->CastSpell(pGlobuleTarget, globulespell[g], true);
                        }
                    }
                    Talk(EMOTE_WATERY_GLOBULES);
                    WateryGlobules_Timer = 25000;
                } else WateryGlobules_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_water_globule : public CreatureScript
{
public:
    npc_water_globule() : CreatureScript("npc_water_globule") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_water_globuleAI(creature);
    }

    struct npc_water_globuleAI : public ScriptedAI
    {
        npc_water_globuleAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 Check_Timer;

        void Reset() OVERRIDE
        {
            Check_Timer = 1000;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(14);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!who || me->GetVictim())
                return;

            if (me->CanCreatureAttack(who))
            {
                //no attack radius check - it attacks the first target that moves in his los
                //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (Check_Timer <= diff)
            {
                if (me->IsWithinDistInMap(me->GetVictim(), 5))
                {
                    DoCastVictim(SPELL_GLOBULE_EXPLOSION);

                    //despawn
                    me->DespawnOrUnsummon();
                    return;
                }
                Check_Timer = 500;
            } else Check_Timer -= diff;

            //do NOT deal any melee damage to the target.
        }
    };

};

void AddSC_boss_morogrim_tidewalker()
{
    new boss_morogrim_tidewalker();
    new npc_water_globule();
}
