/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
##### Script Info #####
Author: Nagash
Progress: 100%
Website: www.forgottenlands.eu
*/

// DA AGGIUNGERE/SISTEMARE:
//gli achievements vengon dati tutti alla prima uccisione senza criterio

#include "ScriptMgr.h"
#include "ScriptMgr.h"
#include "bastion_of_twilight.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "math.h"
#include "time.h"

enum Creatures
{
    //BOSS_ELEMENTIUM               = 43735,
    //BOSS_IGNACIOUS                = 43686,
    //BOSS_FELUDIUS                 = 43687,
    //BOSS_ARION                    = 43688,
    //BOSS_TERRASTRA                = 43689,
    NPC_INFERNO_RUSH                = 47501,
    NPC_WATER_BOMB                  = 44201,
    NPC_VIOLENT_CYCLONE             = 44747,
    NPC_GRAVITY_WELL                = 44824,
    NPC_LIQUID_ICE                  = 45452,
    NPC_LAVA_SEED                   = 45420,
    NPC_FROZEN_ORB_COUNCIL          = 49518,
    NPC_FLAMESTRIKE_COUNCIL         = 50297,
};

#define SAY_AGGRO1    "You dare invade our lord's sanctum?"
#define SOU_AGGRO1    20162
#define SAY_AGGRO2    "You will die for your insolence!"
#define SOU_AGGRO2    20285
#define SAY_AGGRO3    "Enough of this foolishness!"
#define SOU_AGGRO3    20237
#define SAY_AGGRO4    "We will handle them!"
#define SOU_AGGRO4    21843

#define SAY_MONSTR1   "An impressive display..."
#define SOU_MONSTR1   20240
#define SAY_MONSTR2   "...to have made it this far."
#define SOU_MONSTR2   21845
#define SAY_MONSTR3   "But now, witness true power..."
#define SOU_MONSTR3   20165
#define SAY_MONSTR4   "...the fury of the elements!"
#define SOU_MONSTR4   20288
#define SAY_MONSTR5   "BEHOLD YOUR DOOM!"
#define SOU_MONSTR5   20396 //20289 20166 20241 21846
#define SOU_MONSTR6   20289
#define SOU_MONSTR7   20166
#define SOU_MONSTR8   20241
#define SOU_MONSTR9   21846

#define SAY_KILL_FEL  "Perish!"
#define SOU_KILL_FEL  20163
#define SAY_KILL_IGN  "More fuel for the fire!"
#define SOU_KILL_IGN  20286
#define SAY_KILL_ARI  "Merely a whisper in the wind...."
#define SOU_KILL_ARI  20238
#define SAY_KILL_TER  "The soil welcomes your bones!"
#define SOU_KILL_TER  21842
#define SAY_KILL_MON1 "Annihilate...."
#define SOU_KILL_MON1 20397
#define SAY_KILL_MON2 "Eradicate...."
#define SOU_KILL_MON2 20398

#define SAY_GLACIATE  "I will freeze the blood in your veins!"
#define SOU_GLACIATE  20164
#define SAY_RISING    "BURN!"
#define SOU_RISING    20287
#define SAY_CALL_WIND "Wind, hear my call!"
#define SOU_CALL_WIND 20239
#define SAY_QUAKE     "The earth will devour you!"
#define SOU_QUAKE     21844
#define SAY_CRUSH     "FEEL THE POWER!"
#define SOU_CRUSH     20400

#define SAY_DEATH     "Impossible...."
#define SOU_DEATH     20399


enum spell_c
{
    SPELL_TELEPORT_VISUAL        = 26638, //ok
    SPELL_EXPLOSION_VISUAL       = 84207, //ok
    SPELL_ELEMENTAL_STASIS       = 82285, //works
    // Feludius
    SPELL_FROZEN                 = 82772, //works
    SPELL_GLACIATE               = 82746, //works
    SPELL_HEART_OF_ICE           = 82665, //works
    SPELL_ICY_REPRISAL           = 82817, //(heart of ice damage)
    SPELL_HYDRO_LANCE            = 82752, //works
    SPELL_WATER_BOMB             = 82699, //works
    SPELL_WATER_BOMB_EXPLO       = 82700, //works
    SPELL_WATER_BOMB_VISUAL      = 54260, //ok
    SPELL_WATERLOGGED            = 82762, //works
    SPELL_FROST_IMBUED           = 82666, //works
    // Ignacious
    SPELL_AEGIS_OF_FLAME         = 82631, //works
    SPELL_BURNING_BLOOD          = 82660, //works
    SPELL_BURNING_SPITE          = 82813, //(burning blood damage)
    SPELL_FLAME_TORRENT          = 82777, //works
    SPELL_INFERNO_LEAP           = 82856, //works
    SPELL_INFERNO_RUSH           = 82859, //works
    SPELL_INFERNO_AURA           = 88579, //works (only aura, tick the next one)
    SPELL_INFERNO_PERIODIC       = 82860, //works (DoT tick)
    SPELL_RISING_FLAMES          = 82636, //works
    SPELL_RISING_FLAMES_TICK     = 82643, //works
    SPELL_RISING_FLAMES_BUFF     = 82639, //works
    SPELL_FIRE_IMBUED            = 82663, //works
    // Arion
    SPELL_THUNDERSHOCK           = 83067, //works
    SPELL_LIGHTNING_ROD          = 83099, //works
    SPELL_CHAIN_LIGHTNING        = 83282, //ok
    SPELL_DISPERSION             = 83087, //ok
    SPELL_LIGHTNING_BLAST        = 83070, //works
    SPELL_CALL_WINDS             = 83491, //works
    SPELL_VIOLENT_CYCLONE        = 83500, //works
    SPELL_SWIRLING_WINDS         = 83500, //works
    // Terrastra
    SPELL_QUAKE                  = 83565, //works
    SPELL_MAGNETIC_PULL          = 28337, //works
    SPELL_GRAVITY_WELL_AURA      = 83579,
    SPELL_GROUNDED               = 83581, //works
    SPELL_HARDEN_SKIN            = 83718, //works
    SPELL_ERUPTION               = 83692, //works
    // Elementium Monstrosity
    SPELL_GROW                   = 84917, //works
    SPELL_LIQUID_ICE             = 84914, //works
    SPELL_CRYOGENIC_AURA         = 84918, //ok
    SPELL_LAVA_SEED              = 84913, //works
    SPELL_LAVA_PLUME             = 84912, //works
    SPELL_LAVA_SEED_AURA         = 84911,
    SPELL_GRAVITY_CRUSH          = 84948, //works
    SPELL_GRAVITY_LAPSE_AURA     = 39432,
    SPELL_ELECTRICAL_INSTABILITY = 84529,
    // Heroics
    SPELL_STATIC_OVERLOAD        = 92067, // ok
    SPELL_GRAVITY_CORE           = 92075, // ok
    SPELL_FLAMESTRIKE            = 92215, // works
    SPELL_FLAMESTRIKE_VISUAL     = 92211, // Hell yeah!
    SPELL_FROZEN_ORB_GLACIATE    = 92548, // works
    SPELL_FROST_AURA             = 92302, // works
    SPELL_FROST_BEACON           = 92307, // ok

};

enum Events
{
    // General
    EVENT_SAY = 1,
    //Feludius
    EVENT_GLACIATE,
    EVENT_HYDRO_LANCE,
    EVENT_WATER_BOMB,
    EVENT_WATER_BOMB_SPAWN,
    EVENT_HEART_OF_ICE,
    //Ignacious
    EVENT_AEGIS_OF_FLAME,
    EVENT_RISING_FLAMES,
    EVENT_INFERNO_LEAP,
    EVENT_INFERNO_RUSH,
    EVENT_SPAWN_FLAME,
    EVENT_FLAME_TORRENT,
    EVENT_BURNING_BLOOD,
    //Arion
    EVENT_THUNDERSHOCK,
    EVENT_DISPERSION,
    EVENT_TELEPORT,
    EVENT_LIGHTNING_BLAST,
    EVENT_LIGHTNING_ROD,
    EVENT_CHAIN_LIGHTNING,
    EVENT_CYCLONE,
    //Terrastra
    EVENT_QUAKE,
    EVENT_ERUPTION,
    EVENT_HARDEN_SKIN,
    EVENT_GRAVITY_WELL,
    //Elementium Monstrosity
    EVENT_ZAP,
    EVENT_ELECTRICAL_INSTABILITY,
    EVENT_CRYOGENIC_AURA,
    EVENT_LAVA_SEED,
    EVENT_LAVA_SEED_SPAWN,
    EVENT_GRAVITY_CRUSH,
    // Heroics
    EVENT_OVERLOAD_AND_CORE,
    EVENT_FLAMESTRIKE_AND_ORB,

    DATA_ELEMENTARY,
};

enum BossActions
{
    COUNCIL_START_EVENT,
    COUNCIL_EVENT_RESET,
    COUNCIL_EVENT_FINISHED,
    COUNCIL_EVENT_FAILED,
    COUNCIL_PHASE_1,
    COUNCIL_PHASE_2,
};

Position const wayPos[2] =
{
    {-1048.587f, -565.365f, 835.250f, 5.87f},
    {-1049.343f, -598.859f, 835.250f, 0.401f},
};

Position const center[5] =
{
    {-1008.665f, -582.682f, 831.900f, 0.0f   }, //center
    {-983.665f,  -582.682f, 831.900f, 3.14f  }, //feludius
    {-1033.665f, -582.682f, 831.900f, 0.0f   }, //ignacious
    {-1008.665f, -557.682f, 831.900f, 4.71f  }, //arion
    {-1008.665f, -607.682f, 831.900f, 1.57f  }, //terrastra
};

Position const cyclone[9] =
{
    { -993.250f,  -543.682f,  832.000f,  0.0f }, //start
    { -971.665f,  -581.682f,  831.900f,  0.0f },
    { -981.800f,  -609.682f,  831.900f,  0.0f },
    {-1016.860f,  -619.882f,  831.900f,  0.0f },
    {-1032.665f,  -619.282f,  835.250f,  0.0f },
    {-1049.995f,  -610.282f,  835.250f,  0.0f },
    {-1053.165f,  -559.282f,  835.250f,  0.0f },
    {-1030.965f,  -544.392f,  835.250f,  0.0f },
    {-1016.965f,  -542.782f,  832.250f,  0.0f },
};

class boss_elementium_monstrosity : public CreatureScript
{
public:
    boss_elementium_monstrosity() : CreatureScript("boss_elementium_monstrosity") { }

    struct boss_elementium_monstrosityAI : public BossAI
    {
        boss_elementium_monstrosityAI(Creature* creature) : BossAI(creature, DATA_COUNCIL_EVENT), initialized(false), eventActive(false)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Unit* prevtarget;
        Unit* chaintargets[3];
        bool initialized;
        bool isEncounterDone;
        bool phasechange;
        uint8 phase;
        uint8 count;
        uint32 killtimer;
        uint8 zap;

        Creature* ascendant[4];

        bool eventActive;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            me->SetVisible(false);
            ascendant[0] = instance->GetCreature(DATA_IGNACIOUS);
            ascendant[1] = instance->GetCreature(DATA_FELUDIUS);
            ascendant[2] = instance->GetCreature(DATA_ARION);
            ascendant[3] = instance->GetCreature(DATA_TERRASTRA);
            initialized = true;
            summons.DespawnAll();
            me->LowerPlayerDamageReq(me->GetMaxHealth());

            for(uint8 i = 0; i<=3; i++)
            {
                if(ascendant[i] == NULL)
                {
                    initialized = false;
                    return;
                }

                ascendant[i]->SetMaxHealth(ascendant[i]->GetMaxHealth());
            }


            phase       = 0;
            count       = 0;
            killtimer   = 0;
            zap = 1;
            phasechange = false;
            DoAction(COUNCIL_EVENT_RESET);
            eventActive = false;
            chaintargets[0]=NULL;
            chaintargets[1]=NULL;
            chaintargets[2]=NULL;
        }

        void UpdateAI(uint32 diff) override

        {
                if (!UpdateVictim() || !initialized)
                    return;

                if (killtimer>=diff)
                    killtimer -= diff;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                    case EVENT_SAY:
                        if (phase == 0)
                        {
                            ascendant[0]->Yell(SAY_AGGRO2, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[0], SOU_AGGRO2);
                        }
                        else if (phase == 1)
                        {
                            //###############
                            //    phase 2
                            //###############
                            std::list<Creature*> unitList;
                            ascendant[0]->GetCreatureListWithEntryInGrid(unitList, NPC_INFERNO_RUSH, 100.0f);
                            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                            {// this will despawn the flames
                                if (*itr)
                                    (*itr)->DespawnOrUnsummon();
                            }

                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STATIC_OVERLOAD);
                            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRAVITY_CORE);
                            //visibility
                            ascendant[0]->SetReactState(REACT_PASSIVE);
                            ascendant[1]->SetReactState(REACT_PASSIVE);
                            ascendant[2]->SetReactState(REACT_AGGRESSIVE);
                            ascendant[3]->SetReactState(REACT_AGGRESSIVE);
                            ascendant[0]->SetVisible(false);
                            ascendant[1]->SetVisible(false);
                            ascendant[2]->SetVisible(true);
                            ascendant[3]->SetVisible(true);
                            ascendant[0]->AttackStop();
                            ascendant[1]->AttackStop();
                            ascendant[0]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[1]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[2]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[3]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[2]->SetPosition(wayPos[0]);
                            ascendant[3]->SetPosition(wayPos[1]);
                            ascendant[3]->Yell(SAY_AGGRO4, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[3], SOU_AGGRO4);

                            DoZoneInCombat(ascendant[3]);
                            DoZoneInCombat(ascendant[2]);

                            //AI schedules
                            events.ScheduleEvent(EVENT_CYCLONE, 6000);
                            events.ScheduleEvent(EVENT_GRAVITY_WELL, 7000);
                            events.ScheduleEvent(EVENT_LIGHTNING_ROD, 7600);
                            events.ScheduleEvent(EVENT_DISPERSION, 24000);
                            events.ScheduleEvent(EVENT_ERUPTION, 7000);
                            events.ScheduleEvent(EVENT_HARDEN_SKIN, 20000);
                            events.ScheduleEvent(EVENT_QUAKE, 30000);
                            events.ScheduleEvent(EVENT_THUNDERSHOCK, 60000);
                            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                                events.ScheduleEvent(EVENT_FLAMESTRIKE_AND_ORB, 19000);
                        }
                        else if (phase == 2)
                        {
                            //###############
                            //    phase 3
                            //###############
                            switch (count)
                            {
                            case 0:
                                ascendant[3]->Yell(SAY_MONSTR1, LANG_UNIVERSAL);
                                DoPlaySoundToSet(ascendant[3], SOU_MONSTR1);
                                ascendant[3]->GetMotionMaster()->MovePoint(0, center[0]);
                                events.ScheduleEvent(EVENT_SAY, 3000);
                                break;
                            case 1:
                                ascendant[2]->Yell(SAY_MONSTR2, LANG_UNIVERSAL);
                                DoPlaySoundToSet(ascendant[2], SOU_MONSTR2);
                                events.ScheduleEvent(EVENT_SAY, 3000);
                                ascendant[2]->GetMotionMaster()->MovePoint(0, center[0]);
                                break;
                            case 2:
                                ascendant[1]->Yell(SAY_MONSTR3, LANG_UNIVERSAL);
                                DoPlaySoundToSet(ascendant[1], SOU_MONSTR3);
                                events.ScheduleEvent(EVENT_SAY, 3000);
                                ascendant[1]->GetMotionMaster()->MovePoint(0, center[0]);
                                break;
                            case 3:
                                ascendant[0]->Yell(SAY_MONSTR4, LANG_UNIVERSAL);
                                DoPlaySoundToSet(ascendant[0], SOU_MONSTR4);
                                events.ScheduleEvent(EVENT_SAY, 3000);
                                ascendant[0]->GetMotionMaster()->MovePoint(0, center[0]);
                                break;
                            case 4:
                                me->NearTeleportTo(center[0].GetPositionX(), center[0].GetPositionY(), center[0].GetPositionZ(), center[0].GetOrientation());
                                me->SetMaxHealth(ascendant[0]->GetMaxHealth()+ascendant[1]->GetMaxHealth()+ascendant[2]->GetMaxHealth()+ascendant[3]->GetMaxHealth());
                                me->SetHealth(ascendant[0]->GetHealth()+ascendant[1]->GetHealth()+ascendant[2]->GetHealth()+ascendant[3]->GetHealth());
                                me->SetVisible(true);
                                me->CastSpell(me, SPELL_EXPLOSION_VISUAL, false);
                                ascendant[0]->SetReactState(REACT_PASSIVE);
                                ascendant[1]->SetReactState(REACT_PASSIVE);
                                ascendant[2]->SetReactState(REACT_PASSIVE);
                                ascendant[3]->SetReactState(REACT_PASSIVE);
                                ascendant[0]->SetVisible(false);
                                ascendant[1]->SetVisible(false);
                                ascendant[2]->SetVisible(false);
                                ascendant[3]->SetVisible(false);
                                ascendant[0]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                ascendant[1]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                ascendant[2]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                ascendant[3]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                events.ScheduleEvent(EVENT_SAY, 500);
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEMENTAL_STASIS);
                                break;
                            case 5:
                                DoZoneInCombat(me);
                                me->Yell(SAY_MONSTR5, LANG_UNIVERSAL);
                                DoPlaySoundToSet(me, SOU_MONSTR5);
                                DoPlaySoundToSet(me, SOU_MONSTR6);
                                DoPlaySoundToSet(me, SOU_MONSTR7);
                                DoPlaySoundToSet(me, SOU_MONSTR8);
                                DoPlaySoundToSet(me, SOU_MONSTR9);
                                events.ScheduleEvent(EVENT_SAY, 1000);
                                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ELEMENTAL_STASIS);
                                break;
                            case 6:
                                me->SetReactState(REACT_AGGRESSIVE);
                                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                                me->SetVisible(true);
                                //AI Schedules
                                events.ScheduleEvent(EVENT_ZAP, 2000);
                                events.ScheduleEvent(EVENT_CRYOGENIC_AURA, 6000);
                                events.ScheduleEvent(EVENT_ELECTRICAL_INSTABILITY, 15000);
                                events.ScheduleEvent(EVENT_LAVA_SEED, 20000);
                                events.ScheduleEvent(EVENT_GRAVITY_CRUSH, 10000);
                                break;
                            default:
                                break;
                            }
                            count++;
                        }
                        return;
                        break;
                    //##############
                    // Feludius
                    //##############
                    case EVENT_GLACIATE:
                        if (ascendant[1] && ascendant[1]->GetVictim() && !ascendant[1]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[1]->CastSpell(ascendant[1]->GetVictim(), SPELL_GLACIATE, false);
                            ascendant[1]->Yell(SAY_GLACIATE, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[1], SOU_GLACIATE);
                            events.ScheduleEvent(EVENT_GLACIATE, 56000);
                        }
                        else
                            events.ScheduleEvent(EVENT_GLACIATE, 1000);
                        return;
                        break;
                    case EVENT_HYDRO_LANCE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0)){
                            if (ascendant[1] != NULL && !ascendant[1]->HasUnitState(UNIT_STATE_CASTING))
                            {
                                ascendant[1]->CastSpell(pTarget, SPELL_HYDRO_LANCE, false);
                                events.ScheduleEvent(EVENT_HYDRO_LANCE, 18000);
                            }
                            else
                                events.ScheduleEvent(EVENT_HYDRO_LANCE, 1000);
                        }
                        return;
                        break;
                    case EVENT_WATER_BOMB:
                        if (ascendant[1] && !ascendant[1]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            if (ascendant[1]->GetVictim())
                                ascendant[1]->CastSpell(ascendant[1]->GetVictim(), SPELL_WATER_BOMB, false);
                            events.ScheduleEvent(EVENT_WATER_BOMB, 26000);
                            events.ScheduleEvent(EVENT_WATER_BOMB_SPAWN, 2000);
                        }
                        else
                            events.ScheduleEvent(EVENT_WATER_BOMB, 1000);
                        return;
                        break;
                    case EVENT_WATER_BOMB_SPAWN:
                        {
                            if (!ascendant[1])
                                return;
                            uint32 num = urand(10, 16);
                            for(uint32 i=0; i<num; i++)
                            {
                                float dir  = float(rand_norm())*static_cast<float>(2*M_PI);
                                float dist = 50.0f * (float)rand_norm() + 10.0f;
                                ascendant[1]->SummonCreature(NPC_WATER_BOMB,
                                                        ascendant[1]->GetPositionX() + dist*cos(dir),
                                                        ascendant[1]->GetPositionY() + dist*sin(dir),
                                                        ascendant[1]->GetPositionZ(),
                                                        ascendant[1]->GetOrientation());
                            }
                            return;
                        }
                        break;
                    case EVENT_HEART_OF_ICE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0)){
                            if (ascendant[1] != NULL){
                                ascendant[1]->CastSpell(pTarget, SPELL_HEART_OF_ICE, true);
                            }
                        }
                        events.ScheduleEvent(EVENT_HEART_OF_ICE, urand(20000, 40000));
                        return;
                        break;
                    //##############
                    // Ignacious
                    //##############
                    case EVENT_AEGIS_OF_FLAME:
                        if (ascendant[0] != NULL && !ascendant[0]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[0]->CastSpell(ascendant[0], SPELL_AEGIS_OF_FLAME, true);
                            ascendant[0]->CastSpell(ascendant[0], SPELL_RISING_FLAMES, false);
                            ascendant[0]->Yell(SAY_RISING, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[0], SOU_RISING);
                            events.ScheduleEvent(EVENT_AEGIS_OF_FLAME, 56000);
                            //events.ScheduleEvent(EVENT_RISING_FLAMES, 1550);
                        }
                        else
                            events.ScheduleEvent(EVENT_AEGIS_OF_FLAME, 1000);
                        return;
                        break;
                    //case EVENT_RISING_FLAMES:
                        //if (ascendant[0] != NULL)
                        //{
                            //ascendant[0]->CastSpell(ascendant[0], SPELL_RISING_FLAMES, true);
                            //ascendant[0]->Yell(SAY_RISING, LANG_UNIVERSAL);
                            //DoPlaySoundToSet(ascendant[0], SOU_RISING);
                        //}
                        //return;
                        //break;
                    case EVENT_INFERNO_LEAP:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0)){
                            if (ascendant[0] != NULL && !ascendant[0]->HasUnitState(UNIT_STATE_CASTING))
                            {
                                ascendant[0]->CastSpell(pTarget, SPELL_INFERNO_LEAP, true);
                                events.ScheduleEvent(EVENT_INFERNO_RUSH, 2000);
                                events.ScheduleEvent(EVENT_INFERNO_LEAP, 26000);
                            }
                            else
                            {
                                events.ScheduleEvent(EVENT_INFERNO_LEAP, 1000);
                            }
                        }

                        return;
                        break;
                    case EVENT_INFERNO_RUSH:
                        if (Unit* pTarget = ascendant[0]->GetVictim()){
                            if (ascendant[0] != NULL){
                                ascendant[0]->CastSpell(pTarget, SPELL_INFERNO_RUSH, true);
                                events.ScheduleEvent(EVENT_SPAWN_FLAME, 50);
                            }
                        }
                        return;
                        break;
                    case EVENT_SPAWN_FLAME:
                        if (ascendant[0] != NULL)
                        {
                            std::list<Creature*> unitList;
                            ascendant[0]->GetCreatureListWithEntryInGrid(unitList, NPC_INFERNO_RUSH, 100.0f);
                            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                            {// this will despawn the previous flame trail
                                if (*itr)
                                    (*itr)->DespawnOrUnsummon();
                            }
                            ascendant[0]->SummonCreature(NPC_INFERNO_RUSH, ascendant[0]->GetPositionX(),ascendant[0]->GetPositionY(), ascendant[0]->GetPositionZ(),ascendant[0]->GetOrientation());
                        }
                        return;
                        break;
                    case EVENT_FLAME_TORRENT:
                        if (ascendant[0] != NULL && !ascendant[0]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            if (Aura* aur = ascendant[0]->GetAura(RAID_MODE(82639, 101415, 101416, 101417)))
                                aur->Remove();
                            if (Unit *pTarget = ascendant[0]->GetVictim())
                            {
                                ascendant[0]->CastSpell(pTarget, SPELL_FLAME_TORRENT, false);
                            }
                            events.ScheduleEvent(EVENT_FLAME_TORRENT, 30000);
                        }
                        else
                        {
                            events.ScheduleEvent(EVENT_FLAME_TORRENT, 1000);
                        }
                        return;
                        break;
                    case EVENT_BURNING_BLOOD:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0)){
                            if (ascendant[0] != NULL){
                                ascendant[0]->CastSpell(pTarget, SPELL_BURNING_BLOOD, true);
                            }
                        }
                        events.ScheduleEvent(EVENT_BURNING_BLOOD, urand(20000, 40000));
                        return;
                        break;
                    //##############
                    // Arion
                    //##############
                    case EVENT_LIGHTNING_ROD:
                        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                        {//25 man mode, 3 targets
                            if (ascendant[2] != NULL)
                            {
                                std::list<Unit*> chaintargetList;
                                SelectTargetList(chaintargetList, 3, SELECT_TARGET_RANDOM, 100, true);
                                int i=0;
                                for (std::list<Unit*>::const_iterator iter = chaintargetList.begin(); iter != chaintargetList.end(); ++iter)
                                {
                                    ascendant[2]->AddAura(SPELL_LIGHTNING_ROD, (*iter));
                                    if (i<3)
                                        chaintargets[i]= *iter;
                                    i++;
                                }
                            }
                        }
                        else if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {// 10 man mode, 1 target
                            if (ascendant[2] != NULL)
                            {
                                chaintargets[0] = pTarget;
                                ascendant[2]->AddAura(SPELL_LIGHTNING_ROD, pTarget);
                            }
                        }
                        events.ScheduleEvent(EVENT_LIGHTNING_ROD, 30000);
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 13000);
                        return;
                        break;
                    case EVENT_CHAIN_LIGHTNING:
                        if (!ascendant[2]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                            {//25 man mode, 3 targets
                                for (int i=0; i<3; i++)
                                {
                                    if (ascendant[2] != NULL && chaintargets[i]!= NULL)
                                    {
                                        ascendant[2]->CastSpell(chaintargets[i], SPELL_CHAIN_LIGHTNING, false);
                                    }
                                }
                            }
                            else
                            {// 10 man mode, 1 target
                                if (ascendant[2] != NULL && chaintargets[0] != NULL)
                                {
                                    ascendant[2]->CastSpell(chaintargets[0], SPELL_CHAIN_LIGHTNING, false);
                                }
                            }
                        }
                        else
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 1000);
                        return;
                        break;
                    case EVENT_DISPERSION:
                        if (Unit *pTarget = ascendant[2]->GetVictim())
                            prevtarget=pTarget;
                        if (ascendant[2] != NULL && !ascendant[2]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[2]->CastSpell(ascendant[2], SPELL_DISPERSION, false);
                            events.DelayEvents(4000);
                            events.ScheduleEvent(EVENT_TELEPORT, 1550);
                            events.ScheduleEvent(EVENT_LIGHTNING_BLAST, 3000);
                            events.ScheduleEvent(EVENT_DISPERSION, 30000);
                        }
                        else
                            events.ScheduleEvent(EVENT_DISPERSION, 1000);
                        return;
                        break;
                    case EVENT_TELEPORT:
                        if (ascendant[2] != NULL)
                        {
                            ascendant[2]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[2]->SetVisible(false);
                        }
                        return;
                        break;
                    case EVENT_LIGHTNING_BLAST:
                        if (prevtarget && ascendant[2] != NULL)
                        {
                            me->NearTeleportTo(urand(-1019,-975), urand(-624,-535), me->GetPositionZ(), me->GetOrientation());
                            ascendant[2]->SetVisible(true);
                            ascendant[2]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                            ascendant[2]->CastSpell(prevtarget, SPELL_LIGHTNING_BLAST, false);
                        }
                        return;
                        break;
                    case EVENT_CYCLONE:
                        if (ascendant[2] != NULL && !ascendant[2]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[2]->CastSpell(ascendant[2], SPELL_CALL_WINDS, false);
                            ascendant[2]->Yell(SAY_CALL_WIND, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[2], SOU_CALL_WIND);
                            events.ScheduleEvent(EVENT_CYCLONE, 40000);
                        }
                        else
                            events.ScheduleEvent(EVENT_CYCLONE, 40000);
                        return;
                        break;
                    case EVENT_THUNDERSHOCK:
                        if (ascendant[2] != NULL && !ascendant[2]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[2]->CastSpell(ascendant[2], SPELL_THUNDERSHOCK, false);
                            events.ScheduleEvent(EVENT_THUNDERSHOCK, 56000);
                        }
                        else
                            events.ScheduleEvent(EVENT_THUNDERSHOCK, 1000);
                        return;
                        break;
                    //##############
                    // Terrastra
                    //##############
                    case EVENT_QUAKE:
                        if (ascendant[3] != NULL && !ascendant[3]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[3]->CastSpell(ascendant[3], SPELL_QUAKE, false);
                            ascendant[3]->Yell(SAY_QUAKE, LANG_UNIVERSAL);
                            DoPlaySoundToSet(ascendant[3], SOU_QUAKE);
                            events.ScheduleEvent(EVENT_QUAKE, 56000);
                        }
                        else
                            events.ScheduleEvent(EVENT_QUAKE, 1000);
                        return;
                        break;
                    case EVENT_HARDEN_SKIN:
                        if (ascendant[3] != NULL && !ascendant[3]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[3]->CastSpell(ascendant[2], SPELL_HARDEN_SKIN, true);
                            events.ScheduleEvent(EVENT_HARDEN_SKIN, 35000);
                        }
                        else
                            events.ScheduleEvent(EVENT_HARDEN_SKIN, 1000);
                        return;
                        break;
                    case EVENT_GRAVITY_WELL:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, -10.0f))
                        {
                            if (ascendant[3] != NULL)
                            {
                                ascendant[3]->SummonCreature(NPC_GRAVITY_WELL, pTarget->GetPositionX(),pTarget->GetPositionY(), pTarget->GetPositionZ(),pTarget->GetOrientation());
                            }
                        }
                        events.ScheduleEvent(EVENT_GRAVITY_WELL, 60000);
                        return;
                        break;
                    case EVENT_ERUPTION:
                        if (ascendant[3] != NULL && !ascendant[3]->HasUnitState(UNIT_STATE_CASTING))
                        {
                            ascendant[3]->CastSpell(ascendant[3], SPELL_ERUPTION, true);
                            events.ScheduleEvent(EVENT_ERUPTION, 15000);
                        }
                        else
                            events.ScheduleEvent(EVENT_ERUPTION, 15000);
                        return;
                        break;
                    //##############
                    // Monstrosity
                    //##############
                    case EVENT_ZAP:
                        for (int i=0; i<zap; i++)
                        {
                            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                me->CastSpell(pTarget, SPELL_ELECTRICAL_INSTABILITY, true);
                            }
                        }
                        events.ScheduleEvent(EVENT_ZAP, 1000);
                        return;
                        break;
                    case EVENT_ELECTRICAL_INSTABILITY:
                        zap++;
                        events.ScheduleEvent(EVENT_ELECTRICAL_INSTABILITY, urand(13000, 15000));
                        return;
                        break;
                    case EVENT_CRYOGENIC_AURA:
                        {
                            std::list<Creature*> unitList;
                            ascendant[0]->GetCreatureListWithEntryInGrid(unitList, NPC_LIQUID_ICE, 100.0f);
                            bool newspawn = true;
                            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                            {
                                float dist = 4.001f;
                                if ((*itr)->GetAura(SPELL_GROW))
                                { //stack auras should be additive, not multiplicative :V
                                    dist *= 1.2f * (*itr)->GetAura(SPELL_GROW)->GetStackAmount();
                                    //uint32 stack=(*itr)->GetAura(SPELL_GROW)->GetStackAmount();
                                    //for (int i=0; i<stack; i++)
                                    //    dist *= 1.4;
                                }
                                dist -= 4.0f;
                                if (*itr && me->IsWithinDist2d(*itr, dist))
                                {
                                    newspawn = false;
                                    (*itr)->AddAura(SPELL_GROW, *itr);
                                }
                            }
                            if (newspawn)
                            {
                                me->SummonCreature(NPC_LIQUID_ICE, me->GetPositionX(),me->GetPositionY(), me->GetPositionZ(),me->GetOrientation());
                            }

                            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                                events.ScheduleEvent(EVENT_CRYOGENIC_AURA, 3000);
                            else
                                events.ScheduleEvent(EVENT_CRYOGENIC_AURA, 5000);
                            return;
                            break;
                        }
                    case EVENT_GRAVITY_CRUSH:
                        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_25_N || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                        {//25 man mode, 3 targets
                            if (ascendant[2] != NULL)
                            {
                                std::list<Unit*> chaintargetList;
                                SelectTargetList(chaintargetList, 3, SELECT_TARGET_RANDOM, 100, true);
                                for (std::list<Unit*>::const_iterator iter = chaintargetList.begin(); iter != chaintargetList.end(); ++iter)
                                {
                                                ascendant[2]->AddAura(SPELL_GRAVITY_CRUSH, (*iter));
                                    DoTeleportPlayer((*iter), (*iter)->GetPositionX(), (*iter)->GetPositionY(), (*iter)->GetPositionZ()+20, (*iter)->GetOrientation());
                                }
                            }
                        }
                        else if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {// 10 man mode, 1 target
                            if (ascendant[2] != NULL)
                            {
                                ascendant[2]->AddAura(SPELL_GRAVITY_CRUSH, pTarget);
                                DoTeleportPlayer(pTarget, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ()+20, pTarget->GetOrientation());
                            }
                        }
                        //me->CastSpell(me, SPELL_GRAVITY_CRUSH, false);
                        me->Yell(SAY_CRUSH, LANG_UNIVERSAL);
                        DoPlaySoundToSet(me, SOU_CRUSH);
                        events.ScheduleEvent(EVENT_GRAVITY_CRUSH, 24000);
                        return;
                        break;
                    case EVENT_LAVA_SEED:
                        me->CastSpell(me, SPELL_LAVA_SEED, false);
                        events.ScheduleEvent(EVENT_LAVA_SEED, 24000);
                        events.ScheduleEvent(EVENT_LAVA_SEED_SPAWN, 2000);
                        return;
                        break;
                    case EVENT_LAVA_SEED_SPAWN:
                        {
                            uint32 num = urand(20, 26);
                            for(uint32 i=0; i<num; i++)
                            {
                                float dir  = float(rand_norm())*static_cast<float>(2*M_PI);
                                float dist = 50.0f * (float)rand_norm();
                                me->SummonCreature(NPC_LAVA_SEED,
                                                       me->GetPositionX() + dist*cos(dir),
                                                       me->GetPositionY() + dist*sin(dir),
                                                       me->GetPositionZ() + 35,
                                                       me->GetOrientation());
                            }
                            return;
                        }
                        break;
                    //##############
                    // Heroics
                    //##############
                    case EVENT_OVERLOAD_AND_CORE:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            me->AddAura(SPELL_STATIC_OVERLOAD, pTarget);
                            if (Unit *rTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true, -SPELL_STATIC_OVERLOAD))
                            {
                                me->AddAura(SPELL_GRAVITY_CORE, rTarget);
                            }
                        }
                        events.ScheduleEvent(EVENT_OVERLOAD_AND_CORE, 45000);
                        return;
                        break;
                    case EVENT_FLAMESTRIKE_AND_ORB:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        {
                            me->SummonCreature(NPC_FLAMESTRIKE_COUNCIL, pTarget->GetPositionX(),pTarget->GetPositionY(), pTarget->GetPositionZ(),pTarget->GetOrientation());
                            if (Unit *rTarget = SelectTarget(SELECT_TARGET_NEAREST, 0))
                            {
                                //if the same target get chosen it is the only one left
                                me->SummonCreature(NPC_FROZEN_ORB_COUNCIL, rTarget->GetPositionX(),rTarget->GetPositionY(), rTarget->GetPositionZ(),rTarget->GetOrientation());
                            }
                        }
                        events.ScheduleEvent(EVENT_FLAMESTRIKE_AND_ORB, 45000);
                        return;
                        break;
                    default:
                        break;
                    }
                }
            DoMeleeAttackIfReady();
        }

        void DoAction(int32 action) override
        {
            if (!initialized)
                return;
            switch(action)
            {
            case COUNCIL_START_EVENT:

                if (phase != 0 || eventActive)
                    return;
                if (instance)
                    instance->SetData(DATA_COUNCIL_EVENT, IN_PROGRESS);
                eventActive = true;
                events.Reset();
                //visibility
                ascendant[2]->SetReactState(REACT_PASSIVE);
                ascendant[2]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                ascendant[2]->SetVisible(false);
                ascendant[3]->SetReactState(REACT_PASSIVE);
                ascendant[3]->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                ascendant[3]->SetVisible(false);
                DoZoneInCombat(me);
                DoZoneInCombat(ascendant[0]);
                DoZoneInCombat(ascendant[1]);
                //AI schedules
                ascendant[1]->Yell(SAY_AGGRO1, LANG_UNIVERSAL);
                DoPlaySoundToSet(ascendant[0], SOU_AGGRO1);
                events.ScheduleEvent(EVENT_SAY, 4000);
                events.ScheduleEvent(EVENT_GLACIATE, 25000);
                events.ScheduleEvent(EVENT_HYDRO_LANCE, 15500);
                events.ScheduleEvent(EVENT_WATER_BOMB, urand(12000, 14000));
                events.ScheduleEvent(EVENT_HEART_OF_ICE, urand(20000, 40000));
                events.ScheduleEvent(EVENT_AEGIS_OF_FLAME, urand(50000, 60000));
                events.ScheduleEvent(EVENT_INFERNO_LEAP, urand(10000, 10000));
                events.ScheduleEvent(EVENT_FLAME_TORRENT, 15500);
                events.ScheduleEvent(EVENT_BURNING_BLOOD, urand(20000, 40000));
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_10_HC || me->GetMap()->GetDifficultyID() == DIFFICULTY_25_HC)
                    events.ScheduleEvent(EVENT_OVERLOAD_AND_CORE, 19000);
                break;
            case COUNCIL_PHASE_1:
                if (phase==0)
                {//here will comes arion and terrastra
                    phase = 1;
                    if (ascendant[1]->GetVictim()) //this is to prevent reset if the players are distant from the spawnpoint
                    {
                        ascendant[2]->CombatStart(ascendant[1]->GetVictim());
                        ascendant[2]->AddThreat(ascendant[1]->GetVictim(), 1);
                    }
                    if (ascendant[0]->GetVictim())                               //read this ^
                    {
                        ascendant[3]->CombatStart(ascendant[0]->GetVictim());
                        ascendant[3]->AddThreat(ascendant[0]->GetVictim(), 1);
                    }
                    ascendant[2]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[3]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[2]->NearTeleportTo(wayPos[0].GetPositionX(), wayPos[0].GetPositionY(), wayPos[0].GetPositionZ(), wayPos[0].GetOrientation());
                    ascendant[3]->NearTeleportTo(wayPos[1].GetPositionX(), wayPos[1].GetPositionY(), wayPos[1].GetPositionZ(), wayPos[1].GetOrientation());
                    ascendant[2]->SetVisible(true);
                    ascendant[3]->SetVisible(true);
                    events.Reset();
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRAVITY_CORE);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STATIC_OVERLOAD);
                    ascendant[2]->Yell(SAY_AGGRO3, LANG_UNIVERSAL);
                    DoPlaySoundToSet(ascendant[2], SOU_AGGRO3);

                    events.ScheduleEvent(EVENT_SAY, 4000);
                }
                break;
            case COUNCIL_PHASE_2:
                if (phase==1)
                {//here will summon the elementium monstrosity
                    DoCast(SPELL_ELEMENTAL_STASIS); // freeze all!
                    std::list<Creature*> unitList;
                    ascendant[2]->GetCreatureListWithEntryInGrid(unitList, NPC_VIOLENT_CYCLONE, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {// this will despawn the cyclones
                        if (*itr)
                            (*itr)->DespawnOrUnsummon();
                    }
                    ascendant[3]->GetCreatureListWithEntryInGrid(unitList, NPC_GRAVITY_WELL, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {// this will despawn the gravity wells
                        if (*itr)
                            (*itr)->DespawnOrUnsummon();
                    }
                    me->GetCreatureListWithEntryInGrid(unitList, NPC_FLAMESTRIKE_COUNCIL, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {// this will despawn the flamestrike
                        if (*itr)
                            (*itr)->DespawnOrUnsummon();
                    }
                    me->GetCreatureListWithEntryInGrid(unitList, NPC_FROZEN_ORB_COUNCIL, 100.0f);
                    for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                    {// this will despawn the frozen orb
                        if (*itr)
                            (*itr)->DespawnOrUnsummon();
                    }
                    phase = 2;
                    events.Reset();
                    std::list<Unit*> targets;
                    ascendant[0]->AttackStop();
                    ascendant[1]->AttackStop();
                    ascendant[2]->AttackStop();
                    ascendant[3]->AttackStop();
                    ascendant[0]->GetMotionMaster()->Clear();
                    ascendant[1]->GetMotionMaster()->Clear();
                    ascendant[2]->GetMotionMaster()->Clear();
                    ascendant[3]->GetMotionMaster()->Clear();
                    ascendant[0]->SetReactState(REACT_PASSIVE);
                    ascendant[1]->SetReactState(REACT_PASSIVE);
                    ascendant[2]->SetReactState(REACT_PASSIVE);
                    ascendant[3]->SetReactState(REACT_PASSIVE);
                    ascendant[0]->SetVisible(true);
                    ascendant[1]->SetVisible(true);
                    ascendant[2]->SetVisible(true);
                    ascendant[3]->SetVisible(true);
                    ascendant[0]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[1]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[2]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[3]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    ascendant[0]->NearTeleportTo(center[2].GetPositionX(), center[2].GetPositionY(), center[2].GetPositionZ(), center[2].GetOrientation());
                    ascendant[1]->NearTeleportTo(center[1].GetPositionX(), center[1].GetPositionY(), center[1].GetPositionZ(), center[1].GetOrientation());
                    ascendant[2]->NearTeleportTo(center[3].GetPositionX(), center[3].GetPositionY(), center[3].GetPositionZ(), center[3].GetOrientation());
                    ascendant[3]->NearTeleportTo(center[4].GetPositionX(), center[4].GetPositionY(), center[4].GetPositionZ(), center[4].GetOrientation());
                    ascendant[0]->CastSpell(ascendant[0], SPELL_TELEPORT_VISUAL, false);
                    ascendant[1]->CastSpell(ascendant[0], SPELL_TELEPORT_VISUAL, false);
                    ascendant[2]->CastSpell(ascendant[0], SPELL_TELEPORT_VISUAL, false);
                    ascendant[3]->CastSpell(ascendant[0], SPELL_TELEPORT_VISUAL, false);
                    events.ScheduleEvent(EVENT_SAY, 1000);
                }
                break;
            case COUNCIL_EVENT_RESET:
                // Resets Encounter
                //################
                //  da scriptare
                //################

                me->SetFullHealth();

                events.Reset();

                if (instance && eventActive == true)
                    instance->SetData(DATA_COUNCIL_EVENT, FAIL);
                eventActive = false;

                DespawnCreatures(NPC_INFERNO_RUSH );
                DespawnCreatures(NPC_WATER_BOMB);
                DespawnCreatures(NPC_VIOLENT_CYCLONE);
                DespawnCreatures(NPC_GRAVITY_WELL );
                DespawnCreatures(NPC_LIQUID_ICE );
                DespawnCreatures(NPC_LAVA_SEED);
                DespawnCreatures(NPC_FROZEN_ORB_COUNCIL);
                DespawnCreatures(NPC_FLAMESTRIKE_COUNCIL);
                ascendant[0]->SetFullHealth();
                ascendant[1]->SetFullHealth();
                ascendant[2]->SetFullHealth();
                ascendant[3]->SetFullHealth();
                ascendant[1]->NearTeleportTo(wayPos[0].GetPositionX(), wayPos[0].GetPositionY(), wayPos[0].GetPositionZ(), wayPos[0].GetOrientation());
                ascendant[0]->NearTeleportTo(wayPos[1].GetPositionX(), wayPos[1].GetPositionY(), wayPos[1].GetPositionZ(), wayPos[1].GetOrientation());
                ascendant[2]->NearTeleportTo(wayPos[0].GetPositionX(), wayPos[0].GetPositionY(), wayPos[0].GetPositionZ(), wayPos[0].GetOrientation());
                ascendant[3]->NearTeleportTo(wayPos[1].GetPositionX(), wayPos[1].GetPositionY(), wayPos[1].GetPositionZ(), wayPos[1].GetOrientation());
                ascendant[0]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                ascendant[1]->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                ascendant[0]->SetReactState(REACT_AGGRESSIVE);
                ascendant[1]->SetReactState(REACT_AGGRESSIVE);
                ascendant[2]->SetReactState(REACT_PASSIVE);
                ascendant[3]->SetReactState(REACT_PASSIVE);
                ascendant[0]->SetVisible(true);
                ascendant[1]->SetVisible(true);
                ascendant[2]->SetVisible(false);
                ascendant[3]->SetVisible(false);
                break;

            case COUNCIL_EVENT_FINISHED:
                //################
                //  da scriptare
                //################

                if (instance)
                    instance->SetData(DATA_COUNCIL_EVENT, DONE);

                events.Reset();
                ascendant[0]->DisappearAndDie();
                ascendant[1]->DisappearAndDie();
                ascendant[2]->DisappearAndDie();
                ascendant[3]->DisappearAndDie();
                eventActive = false;
                break;

            default:
                break;
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->AI()->DoAction(COUNCIL_EVENT_FINISHED);
            me->Yell(SAY_DEATH, LANG_UNIVERSAL);
            DoPlaySoundToSet(me, SOU_DEATH);
            std::list<Creature*> unitList;
            me->GetCreatureListWithEntryInGrid(unitList, NPC_LIQUID_ICE, 100.0f);

            for (uint8 i = 0; i < 4; i++)
                ascendant[i]->DisappearAndDie();

            for (std::list<Creature*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
            {// this will despawn the liquid ice
                if (*itr)
                    (*itr)->DespawnOrUnsummon();
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER || killtimer > 0)
                return;
            switch (urand(1, 2))
            {
            case 1:
                me->Yell(SAY_KILL_MON1, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_MON1);
                break;
            case 2:
                me->Yell(SAY_KILL_MON2, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_MON2);
                break;
            default:
                break;
            }
            killtimer = 10000;
        }

    private:
        void DespawnCreatures(uint32 entry)
        {
            std::list<Creature*> creatures;
            GetCreatureListWithEntryInGrid(creatures, me, entry, 100.0f);

            if (creatures.empty())
                return;

            for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                (*iter)->DespawnOrUnsummon();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_elementium_monstrosityAI (creature);
    }

};

class boss_ascendants : public CreatureScript
{
public:
    boss_ascendants() : CreatureScript("boss_ascendants") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_ascendantsAI (creature);
    }

    struct boss_ascendantsAI : public ScriptedAI
    {
        boss_ascendantsAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);

            homePosition = creature->GetHomePosition();
        }

        InstanceScript* instance;
        EventMap events;
        Position homePosition;
        Creature* elementium;
        uint32 killtimer;

        void EnterCombat(Unit* /*who*/) override
        {
            if (Creature* monstrosity = instance->GetCreature(DATA_MONSTROSITY))
            {
                monstrosity->AI()->DoAction(COUNCIL_START_EVENT);
            }

            killtimer =0;
        }

        void Reset() override
        {
            if (me->GetEntry() != BOSS_FELUDIUS && me->GetEntry() != BOSS_IGNACIOUS)
                me->SetVisible(false);

            if (Creature* elementium = instance->GetCreature(DATA_MONSTROSITY))
                elementium->AI()->DoAction(COUNCIL_EVENT_RESET);
        };

        void UpdateAI(uint32 diff) override

        {
            if (!UpdateVictim())
                return;

            if (killtimer>=diff)
                killtimer -= diff;

            DoMeleeAttackIfReady();
        }

        void DamageTaken(Unit* who, uint32& damage) override
        {
            if (me->GetEntry() == BOSS_FELUDIUS && who->HasAura(SPELL_FIRE_IMBUED))
                damage *=1.5;
            else if (me->GetEntry() == BOSS_IGNACIOUS && who->HasAura(SPELL_FROST_IMBUED))
                damage *=1.5;

            if (Creature* elementium = instance->GetCreature(DATA_MONSTROSITY))
            {
                elementium->SetHealth(elementium->GetHealth()-damage);

                // phase change when an attack will put an ascendant under 25% hp
                if (me->GetHealthPct() <= 25.0f )
                {
                    if (me->GetEntry() == BOSS_FELUDIUS || me->GetEntry() == BOSS_IGNACIOUS)
                        elementium->AI()->DoAction(COUNCIL_PHASE_1);
                    else
                        elementium->AI()->DoAction(COUNCIL_PHASE_2);
                }
            }
        }

        void KilledUnit(Unit* victim) override
        {
            if (!victim || victim->GetTypeId() != TYPEID_PLAYER || killtimer > 0)
                return;
            switch (me->GetEntry())
            {
            case BOSS_FELUDIUS:
                me->Yell(SAY_KILL_FEL, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_FEL);
                break;
            case BOSS_IGNACIOUS:
                me->Yell(SAY_KILL_IGN, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_IGN);
                break;
            case BOSS_ARION:
                me->Yell(SAY_KILL_ARI, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_ARI);
                break;
            case BOSS_TERRASTRA:
                me->Yell(SAY_KILL_TER, LANG_UNIVERSAL);
                DoPlaySoundToSet(me, SOU_KILL_TER);
                break;
            default:
                break;
            }
            killtimer = 8000;
        }

        void JustSummoned(Creature* summon) override
        {
            summon->SetFaction(me->getFaction());
            summon->SetInCombatWithZone();
        }

    };
};

class npc_council_violent_cyclone : public CreatureScript
{
public: npc_council_violent_cyclone() : CreatureScript("npc_council_violent_cyclone") { }

    struct npc_council_violent_cycloneAI : public ScriptedAI
    {
        npc_council_violent_cycloneAI(Creature* c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 checkTimer;
        uint32 checkMovement;
        int chase;

        void InitializeAI() override
        {
            me->SetSpeed(MOVE_WALK,   0.5f);
            me->SetSpeed(MOVE_RUN,    0.5f);
            me->SetSpeed(MOVE_FLIGHT, 0.5f);

            checkTimer    = 100;
            checkMovement = 100;
            chase         =   0;

            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(true);
            me->AddAura(32332, me); //cyclone visual effect
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetHover(true);
        }

        void Reset() override
        {
            InitializeAI();
        }

        void CheckViolentCyclone(Unit *who)
        {
                        if (who->IsAlive() && !who->HasAura(SPELL_VIOLENT_CYCLONE))
                                me->CastSpell(who, SPELL_VIOLENT_CYCLONE, true);
                }

        void UpdateAI(uint32 diff) override

        {
            if (checkTimer <= diff || checkMovement <= diff)
            {
                if (checkMovement <= diff)
                {
                    checkMovement = urand(5000, 8000);
                    chase= (chase+1) %10;
                    me->GetMotionMaster()->MovePoint(0, cyclone[chase]);

                    if (!me->HasAura(32332)) //cyclone visual effect repeat, just to be sure it's visible
                        me->AddAura(32332, me);
                }
                if (checkTimer <= diff)
                {
                    checkTimer = 1000;
                    std::list<Unit*> targets;
                    me->GetAttackableUnitListInRange(targets, 5.0f);
                    for (std::list<Unit*>::const_iterator iter = targets.begin();iter != targets.end(); ++iter)
                    {
                        CheckViolentCyclone(*iter);
                    }
                }
            }
            else
            {
                checkTimer -= diff;
                checkMovement -= diff;
            }
        }

    };
        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_council_violent_cycloneAI(creature);
        }
};

class npc_council_frozen_orb : public CreatureScript
{
public: npc_council_frozen_orb() : CreatureScript("npc_council_frozen_orb") { }

    struct npc_council_frozen_orbAI : public ScriptedAI
    {
        npc_council_frozen_orbAI(Creature* c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 checkTimer;
        bool dying;
        float speed;
        Unit* chase;
        Unit* flamestrike;

        void InitializeAI() override
        {
            InstanceScript* instance = me->ToCreature()->GetInstanceScript();
            Unit* monstrosity = nullptr;
            if (instance)
                monstrosity = instance->GetCreature(DATA_TERRASTRA);
            else
                me->DespawnOrUnsummon();

            if (monstrosity != nullptr && monstrosity->GetVictim())
            {
                me->Attack(monstrosity->GetVictim(), false);
                DoZoneInCombat(me);
                me->AttackStop();
            }
            else
                me->DespawnOrUnsummon();
            me->SetFaction(monstrosity->getFaction());
            speed = 0.8f;
            me->SetSpeed(MOVE_WALK,   speed);
            me->SetSpeed(MOVE_RUN,    speed);
            me->SetSpeed(MOVE_FLIGHT, speed);
            chase = SelectTarget(SELECT_TARGET_FARTHEST, 0);
            if (chase != nullptr)
            {
                me->AddAura(SPELL_FROST_BEACON, chase);
                me->AddAura(SPELL_FROST_AURA, me);
                me->GetMotionMaster()->MoveChase(chase, 0, 0);
            }
            if (me->GetInstanceScript())
                flamestrike = me->FindNearestCreature(NPC_FLAMESTRIKE_COUNCIL, 100, true);
            checkTimer = 100;
            dying = false;

            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            me->SetReactState(REACT_PASSIVE);
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetHover(true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
        }

        void UpdateAI(uint32 diff) override

        {
            if (checkTimer <= diff)
            {
                if (chase == NULL)
                    chase = SelectTarget(SELECT_TARGET_FARTHEST, 0);
                if (flamestrike == NULL && me->GetInstanceScript())
                    flamestrike = me->FindNearestCreature(NPC_FLAMESTRIKE_COUNCIL, 100, true);
                if (dying || chase == NULL || flamestrike == NULL)
                {
                    me->DespawnOrUnsummon();
                    return;
                }
                me->GetMotionMaster()->MoveChase(chase, 0, 0);

                me->SetSpeed(MOVE_WALK,   speed);
                me->SetSpeed(MOVE_RUN,    speed);
                me->SetSpeed(MOVE_FLIGHT, speed);
                speed =  speed * 1.05;
                checkTimer = 1000;
                if(me->GetDistance2d(flamestrike) < 3.0f)
                {
                    me->DespawnOrUnsummon();
                    if (flamestrike != NULL && flamestrike->ToCreature())
                        flamestrike->ToCreature()->DespawnOrUnsummon();
                }
                if(me->GetDistance2d(chase) < 3.0f)
                {
                    me->CastSpell(me, SPELL_FROZEN_ORB_GLACIATE, false);
                    dying=true;
                }


            }
            else
                checkTimer -= diff;
        }

    };
        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_council_frozen_orbAI(creature);
        }
};

class npc_council_gravity_well : public CreatureScript
{
public: npc_council_gravity_well() : CreatureScript("npc_council_gravity_well") { }

    struct npc_council_gravity_wellAI : public ScriptedAI
    {
        npc_council_gravity_wellAI(Creature* c) : ScriptedAI(c)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        uint32 checkTimer;

        void Reset() override
        {
            checkTimer = 100;
            me->AddAura(83579, me);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
            me->SetReactState(REACT_PASSIVE);
            //me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
            //me->SetCanFly(true);
        }

        void Checkgravitywell(Unit *who)
        {
            if (who->IsAlive() && !who->HasAura(SPELL_GROUNDED))
            {
                me->AddAura(SPELL_GROUNDED, who);
                me->CastSpell(who, SPELL_MAGNETIC_PULL, true);
                if (who->HasAura(SPELL_SWIRLING_WINDS))
                    who->GetAura(SPELL_SWIRLING_WINDS)->Remove();
            }
        }

        void UpdateAI(uint32 diff) override

        {
            if (checkTimer <= diff)
            {
                checkTimer = 1000;
                std::list<Unit*> targets;

                me->GetAttackableUnitListInRange(targets, 5.0f);

                for (std::list<Unit*>::const_iterator iter = targets.begin();iter != targets.end(); ++iter)
                    Checkgravitywell(*iter);
            }
            else
                checkTimer -= diff;
        }

    };
        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_council_gravity_wellAI(creature);
        }
};

class npc_council_water_bomb: public CreatureScript
{
public: npc_council_water_bomb() : CreatureScript("npc_council_water_bomb") {}

    struct npc_council_water_bombAI: public ScriptedAI
    {
        npc_council_water_bombAI(Creature *c) :ScriptedAI(c) {}

        float distanza;
        uint32 timer;
        uint32 death;
        Unit* feludius;

        void InitializeAI() override
        {
            death = 5000;
            InstanceScript* instance = me->ToCreature()->GetInstanceScript();
            if (instance)
                feludius = instance->GetCreature(DATA_FELUDIUS);
            else
                me->DespawnOrUnsummon();
            distanza = me->GetDistance2d(feludius);
            if (distanza <10.0f) distanza=10.0f;
            timer = uint32((distanza - 10) * 75 + 500);
            feludius->CastSpell(me, SPELL_WATER_BOMB_VISUAL, true);
            me->AddAura(76406, me);
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

        }

        void UpdateAI(uint32 diff) override

        {
            if (death <=diff)
                me->DespawnOrUnsummon();
            else
                death -=diff;

            if (timer <= diff)
            {
                me->CastSpell(me, SPELL_WATER_BOMB_EXPLO, true);
                if (me->GetAura(76406))
                    me->GetAura(76406)->Remove();
                timer = 10000;
            }
            else
                timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_council_water_bombAI(pCreature);
    }
};

class npc_council_lava_seed: public CreatureScript
{
public: npc_council_lava_seed() : CreatureScript("npc_council_lava_seed") {}

    struct npc_council_lava_seedAI: public ScriptedAI
    {
        npc_council_lava_seedAI(Creature *c) :ScriptedAI(c) {}

        uint32 timer;
        uint32 death;
        Unit* monstrosity;
        bool casted;

        void InitializeAI() override
        {
            casted = false;
            InstanceScript* instance = me->ToCreature()->GetInstanceScript();
            if (instance)
                monstrosity =  instance->GetCreature(DATA_MONSTROSITY);
            if (!monstrosity)
                me->DisappearAndDie();
            death = 7000;
            me->SetFaction(monstrosity->getFaction());
            timer = 5000;
            me->AddAura(SPELL_LAVA_SEED_AURA, me);
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetUnitMovementFlags(MOVEMENTFLAG_FLYING);
            me->SetSpeed(MOVE_WALK,   3.0f);
            me->SetSpeed(MOVE_RUN,    3.0f);
            me->SetSpeed(MOVE_FLIGHT, 3.0f);
            me->GetMotionMaster()->MovePoint(0,me->GetPositionX(),me->GetPositionY(), me->GetPositionZ() - 35);
        }

        void UpdateAI(uint32 diff) override

        {
            if (death <=diff)
                me->DespawnOrUnsummon();
            else
                death -=diff;
            if (timer <= diff && !casted)
            {
                me->CastSpell(me, SPELL_LAVA_PLUME, false);
                casted = true;
            }
            else
                timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_council_lava_seedAI(pCreature);
    }
};

class npc_council_inferno_rush: public CreatureScript {
public: npc_council_inferno_rush() : CreatureScript("npc_council_inferno_rush") {}

    struct npc_council_inferno_rushAI: public ScriptedAI
    {
        npc_council_inferno_rushAI(Creature *c) :ScriptedAI(c) {}

        bool Isready;
        uint32 timer;
        Unit* igna;

         void InitializeAI() override
        {
            Isready = false;
            timer = 250;
            InstanceScript* instance = me->ToCreature()->GetInstanceScript();
            if (instance)
                igna = instance->GetCreature(DATA_IGNACIOUS);
            else
                me->DespawnOrUnsummon();
            me->SetFaction(igna->getFaction());
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(uint32 diff) override

        {
            if (timer <= diff && !Isready)
            {
                Isready = true;
                me->AddAura(88579, me);
                if (!igna)
                    return;
                me->SetFacingToObject(igna);
                float ori = me->GetOrientation();
                if(me->GetDistance2d(igna) > 5.0f)
                {
                    igna->SummonCreature(NPC_INFERNO_RUSH,
                                         me->GetPositionX()+ 6*cos(ori),
                                         me->GetPositionY()+ 6*sin(ori),
                                         me->GetPositionZ(),
                                         me->GetOrientation());
                }
            }
            else
            {
                timer -= diff;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_council_inferno_rushAI(pCreature);
    }
};

class npc_council_flamestrike: public CreatureScript {
public: npc_council_flamestrike() : CreatureScript("npc_council_flamestrike") {}

    struct npc_council_flamestrikeAI: public ScriptedAI
    {
    npc_council_flamestrikeAI(Creature *c) :ScriptedAI(c) {}

    uint32 timer;
    bool casted;

    void InitializeAI() override
    {
        casted= false;
        InstanceScript* instance = me->ToCreature()->GetInstanceScript();
        Unit* monstrosity = nullptr;
        if (instance)
            monstrosity = instance->GetCreature(DATA_MONSTROSITY);

        if (monstrosity == nullptr || !instance)
        {
            me->DespawnOrUnsummon();
            return;
        }

        me->SetFaction(monstrosity->getFaction());
        timer = 5000;
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->AddAura(SPELL_FLAMESTRIKE_VISUAL, me);
    }

    void UpdateAI(uint32 diff) override

    {
        if (timer <= diff && !casted)
        {
            casted = true;
            me->AddAura(SPELL_FLAMESTRIKE, me);
            me->RemoveAura(SPELL_FLAMESTRIKE_VISUAL);
        }
        else
            timer -= diff;
    }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_council_flamestrikeAI(pCreature);
    }
};

class npc_council_liquid_ice: public CreatureScript {
public: npc_council_liquid_ice() : CreatureScript("npc_council_liquid_ice") {}

    struct npc_council_liquid_iceAI: public ScriptedAI
    {
        npc_council_liquid_iceAI(Creature *c) :ScriptedAI(c) {}

        void InitializeAI() override
        {
            InstanceScript* instance = me->ToCreature()->GetInstanceScript();
            Unit* monstrosity = nullptr;

            if (instance)
                monstrosity = instance->GetCreature(DATA_MONSTROSITY);
            else
                me->DespawnOrUnsummon();

            me->SetFaction(monstrosity->getFaction());
            me->AddAura(SPELL_LIQUID_ICE, me);
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_council_liquid_iceAI(pCreature);
    }
};

class spell_council_glaciate : public SpellScriptLoader
{
    public: spell_council_glaciate() : SpellScriptLoader("spell_council_glaciate") { }

        class spell_council_glaciate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_glaciate_SpellScript);

            void HandleGlaciate()
            {
                Unit* target = GetHitUnit();
                Unit* caster = GetCaster();
                if (!target || !caster)
                    return;
                if (target->HasAura(SPELL_WATERLOGGED))
                    caster->AddAura(SPELL_FROZEN, target);
            }

            void GlaciateDamage(SpellMissInfo /*missInfo*/)
            {
                Unit* target = GetHitUnit();
                Unit* caster = GetCaster();
                if (!target || !caster)
                    return;
                uint32 damage = GetHitDamage();
                float dist = target->GetDistance(caster);
                if (dist > 5.0f)
                    damage = uint32 (damage/(dist-4.0f));
                SetHitDamage(damage);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_council_glaciate_SpellScript::HandleGlaciate);
                BeforeHit += BeforeSpellHitFn(spell_council_glaciate_SpellScript::GlaciateDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_glaciate_SpellScript();
        }
};

class spell_council_thundershock : public SpellScriptLoader
{
    public: spell_council_thundershock() : SpellScriptLoader("spell_council_thundershock") { }

        class spell_council_thundershock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_thundershock_SpellScript);

            void ThundershockDamage(SpellMissInfo /*missInfo*/)
            {
                Unit* target = GetHitUnit();
                if (!target)
                    return;
                uint32 damage = GetHitDamage();
                if (target->HasAura(SPELL_GROUNDED))
                    damage = uint32 (damage/4);
                SetHitDamage(damage);
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_council_thundershock_SpellScript::ThundershockDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_thundershock_SpellScript();
        }
};

class spell_council_static_overload : public SpellScriptLoader
{
    public: spell_council_static_overload() : SpellScriptLoader("static_overload") { }

        class spell_council_static_overload_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_static_overload_SpellScript);

            void StaticOverloadDamage(SpellMissInfo /*missInfo*/)
            {
                Unit* target = GetHitUnit();

                if (!target)
                    return;

                if (target->HasAura(SPELL_GRAVITY_CORE))
                {
                    target->GetAura(SPELL_GRAVITY_CORE)->Remove();
                    if (target->GetInstanceScript())
                        target->GetInstanceScript()->DoRemoveAurasDueToSpellOnPlayers(SPELL_STATIC_OVERLOAD);
                }
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_council_static_overload_SpellScript::StaticOverloadDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_static_overload_SpellScript();
        }
};

class spell_council_quake : public SpellScriptLoader
{
    public: spell_council_quake() : SpellScriptLoader("spell_council_quake") { }

        class spell_council_quake_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_quake_SpellScript);

            void QuakeDamage(SpellMissInfo /*missInfo*/)
            {
                Unit* target = GetHitUnit();
                if (!target)
                    return;
                if (target->HasAura(SPELL_SWIRLING_WINDS))
                    SetHitDamage(0);
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_council_quake_SpellScript::QuakeDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_quake_SpellScript();
        }
};

class spell_council_rising_flames : public SpellScriptLoader
{
    public:
        spell_council_rising_flames() : SpellScriptLoader("spell_council_rising_flames") { }

        class spell_council_rising_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_rising_flames_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return SPELL_FAILED_ERROR;

                if (!caster->GetAura(SPELL_RISING_FLAMES_BUFF))
                    caster->AddAura(SPELL_RISING_FLAMES_BUFF, caster);
                else
                {
                    Aura* buff =caster->GetAura(SPELL_RISING_FLAMES_BUFF);
                    buff->SetStackAmount(buff->GetStackAmount()+1);
                    buff->RefreshDuration();
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_council_rising_flames_SpellScript::CheckCast);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_rising_flames_SpellScript();
        }
};

 class spell_council_burning_blood : public SpellScriptLoader
{
    public:
        spell_council_burning_blood() : SpellScriptLoader("spell_council_burning_blood") { }

        class spell_council_burning_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_council_burning_blood_AuraScript);

            void azzera(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetEffect(EFFECT_0)->SetAmount(0);
            }

            void periodic(AuraEffect const* /*aurEff*/)
            {
                GetEffect(EFFECT_0)->SetAmount(this->GetEffect(EFFECT_0)->GetAmount() + 2000);

                if (!GetUnitOwner() )
                    return;

                Unit *target = GetUnitOwner();
                target->CastSpell(target, SPELL_FIRE_IMBUED, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_council_burning_blood_AuraScript::azzera, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_council_burning_blood_AuraScript::periodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_council_burning_blood_AuraScript();
        }
};

 class spell_council_heart_of_ice : public SpellScriptLoader
{
    public:
        spell_council_heart_of_ice() : SpellScriptLoader("spell_council_heart_of_ice") { }

        class spell_council_heart_of_ice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_council_heart_of_ice_AuraScript);

            void azzera(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetEffect(EFFECT_0)->SetAmount(0);
            }

            void periodic(AuraEffect const* /*aurEff*/)
            {
                GetEffect(EFFECT_0)->SetAmount(this->GetEffect(EFFECT_0)->GetAmount() + 2000);
                if (!GetUnitOwner() )
                    return;
                Unit *target = GetUnitOwner();
                target->CastSpell(target, SPELL_FROST_IMBUED, true);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_council_heart_of_ice_AuraScript::azzera, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_council_heart_of_ice_AuraScript::periodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE);
            }

        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_council_heart_of_ice_AuraScript();
        }
};

class spell_council_liquid_ice : public SpellScriptLoader
{
    public: spell_council_liquid_ice() : SpellScriptLoader("spell_council_liquid_ice") { }

        class spell_council_liquid_ice_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_council_liquid_ice_SpellScript);

            void LiquidIceDamage(SpellMissInfo /*missInfo*/)
            {
                Unit *target = GetHitUnit();
                Unit *caster = GetCaster();
                if (!target || !caster)
                    return;
                uint32 stack =0;
                if (caster->HasAura(SPELL_GROW))
                    stack = caster->GetAura(SPELL_GROW)->GetStackAmount();
                float distance = 5.0f;
                if (stack !=0)
                    distance *= (1.2f * stack);
                distance -= 5.0f;
                if (target->GetDistance2d(caster) > distance )
                    SetHitDamage(0);
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_council_liquid_ice_SpellScript::LiquidIceDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_council_liquid_ice_SpellScript();
        }
};

void AddSC_boss_ascendant_council()
{
    new boss_elementium_monstrosity();
    new boss_ascendants();
    new npc_council_violent_cyclone();
    new npc_council_frozen_orb();
    new npc_council_gravity_well();
    new npc_council_water_bomb();
    new npc_council_lava_seed();
    new npc_council_inferno_rush();
    new npc_council_flamestrike();
    new npc_council_liquid_ice();
    new spell_council_glaciate();
    new spell_council_thundershock();
    new spell_council_static_overload();
    new spell_council_quake();
    new spell_council_rising_flames();
    new spell_council_burning_blood();
    new spell_council_heart_of_ice();
    new spell_council_liquid_ice();
}
