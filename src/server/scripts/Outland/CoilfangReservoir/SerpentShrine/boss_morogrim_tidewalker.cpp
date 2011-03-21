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
SDName: Boss_Morogrim_Tidewalker
SD%Complete: 90
SDComment: Water globules don't explode properly, remove hacks
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "ScriptPCH.h"
#include "serpent_shrine.h"

enum eEnums
{
    // Yell
    SAY_AGGRO = -1548030,
    SAY_SUMMON1 = -1548031,
    SAY_SUMMON2 = -1548032,
    SAY_SUMMON_BUBL1 = -1548033,
    SAY_SUMMON_BUBL2 = -1548034,
    SAY_SLAY1 = -1548035,
    SAY_SLAY2 = -1548036,
    SAY_SLAY3 = -1548037,
    SAY_DEATH = -1548038,
    // Emotes
    EMOTE_WATERY_GRAVE = -1548039,
    EMOTE_EARTHQUAKE = -1548040,
    EMOTE_WATERY_GLOBULES = -1548041,
    // Spells
    SPELL_TIDAL_WAVE = 37730,
    SPELL_WATERY_GRAVE = 38049,
    SPELL_EARTHQUAKE = 37764,
    SPELL_WATERY_GRAVE_EXPLOSION = 37852,

    SPELL_WATERY_GRAVE_1 = 38023,
    SPELL_WATERY_GRAVE_2 = 38024,
    SPELL_WATERY_GRAVE_3 = 38025,
    SPELL_WATERY_GRAVE_4 = 37850,

    SPELL_SUMMON_WATER_GLOBULE_1 = 37854,
    SPELL_SUMMON_WATER_GLOBULE_2 = 37858,
    SPELL_SUMMON_WATER_GLOBULE_3 = 37860,
    SPELL_SUMMON_WATER_GLOBULE_4 = 37861,
    // Creatures
    NPC_WATER_GLOBULE = 21913,
    NPC_TIDEWALKER_LURKER = 21920,
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

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_morogrim_tidewalkerAI (pCreature);
    }

    struct boss_morogrim_tidewalkerAI : public ScriptedAI
    {
        boss_morogrim_tidewalkerAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        Map::PlayerList const *PlayerList;

        uint32 TidalWave_Timer;
        uint32 WateryGrave_Timer;
        uint32 Earthquake_Timer;
        uint32 WateryGlobules_Timer;
        uint32 globulespell[4];
        int8 Playercount;
        int8 counter;

        bool Earthquake;
        bool Phase2;

        void Reset()
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

            if (pInstance)
                pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, NOT_STARTED);
        }

        void StartEvent()
        {
            DoScriptText(SAY_AGGRO, me);

            if (pInstance)
                pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, IN_PROGRESS);
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY1,SAY_SLAY2,SAY_SLAY3), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);

            if (pInstance)
                pInstance->SetData(DATA_MOROGRIMTIDEWALKEREVENT, DONE);
        }

        void EnterCombat(Unit * /*who*/)
        {
            PlayerList = &me->GetMap()->GetPlayers();
            Playercount = PlayerList->getSize();
            StartEvent();
        }

        void ApplyWateryGrave(Unit* pPlayer, uint8 i)
        {
            switch(i)
            {
            case 0: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_1, true); break;
            case 1: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_2, true); break;
            case 2: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_3, true); break;
            case 3: pPlayer->CastSpell(pPlayer, SPELL_WATERY_GRAVE_4, true); break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            //Earthquake_Timer
            if (Earthquake_Timer <= diff)
            {
                if (!Earthquake)
                {
                    DoCast(me->getVictim(), SPELL_EARTHQUAKE);
                    Earthquake = true;
                    Earthquake_Timer = 10000;
                }
                else
                {
                    DoScriptText(RAND(SAY_SUMMON1,SAY_SUMMON2), me);

                    for (uint8 i = 0; i < 10; ++i)
                    {
                        Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0);
                        Creature* Murloc = me->SummonCreature(NPC_TIDEWALKER_LURKER, MurlocCords[i][0], MurlocCords[i][1], MurlocCords[i][2], MurlocCords[i][3], TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10000);
                        if (pTarget && Murloc)
                            Murloc->AI()->AttackStart(pTarget);
                    }
                    DoScriptText(EMOTE_EARTHQUAKE, me);
                    Earthquake = false;
                    Earthquake_Timer = 40000+rand()%5000;
                }
            } else Earthquake_Timer -= diff;

            //TidalWave_Timer
            if (TidalWave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TIDAL_WAVE);
                TidalWave_Timer = 20000;
            } else TidalWave_Timer -= diff;

            if (!Phase2)
            {
                //WateryGrave_Timer
                if (WateryGrave_Timer <= diff)
                {
                    //Teleport 4 players under the waterfalls
                    Unit *pTarget;
                    std::set<uint64> list;
                    std::set<uint64>::const_iterator itr;
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        counter = 0;
                        do
                        {
                            pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 50, true);    //target players only
                            if (counter < Playercount)
                                break;
                            if (pTarget)
                                itr = list.find(pTarget->GetGUID());
                            ++counter;
                        } while (itr != list.end());

                        if (pTarget)
                        {
                            list.insert(pTarget->GetGUID());
                            ApplyWateryGrave(pTarget, i);
                        }
                    }

                    DoScriptText(RAND(SAY_SUMMON_BUBL1,SAY_SUMMON_BUBL2), me);

                    DoScriptText(EMOTE_WATERY_GRAVE, me);
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
                    DoScriptText(EMOTE_WATERY_GLOBULES, me);
                    WateryGlobules_Timer = 25000;
                } else WateryGlobules_Timer -= diff;
            }

            DoMeleeAttackIfReady();
        }
    };

};

//Water Globule AI
#define SPELL_GLOBULE_EXPLOSION 37871

class mob_water_globule : public CreatureScript
{
public:
    mob_water_globule() : CreatureScript("mob_water_globule") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_water_globuleAI (pCreature);
    }

    struct mob_water_globuleAI : public ScriptedAI
    {
        mob_water_globuleAI(Creature *c) : ScriptedAI(c) {}

        uint32 Check_Timer;

        void Reset()
        {
            Check_Timer = 1000;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(14);
        }

        void EnterCombat(Unit * /*who*/) {}

        void MoveInLineOfSight(Unit *who)
        {
            if (!who || me->getVictim())
                return;

            if (who->isTargetableForAttack() && who->isInAccessiblePlaceFor(me) && me->IsHostileTo(who))
            {
                //no attack radius check - it attacks the first target that moves in his los
                //who->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
                AttackStart(who);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (Check_Timer <= diff)
            {
                if (me->IsWithinDistInMap(me->getVictim(), 5))
                {
                    DoCast(me->getVictim(), SPELL_GLOBULE_EXPLOSION);

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
    new mob_water_globule();
}
