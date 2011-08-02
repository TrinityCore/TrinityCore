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
SDName: boss_Akilzon
SD%Complete: 75%
SDComment: Missing timer for Call Lightning and Sound ID's
SQLUpdate:
#Temporary fix for Soaring Eagles

EndScriptData */

#include "ScriptPCH.h"
#include "zulaman.h"
#include "Weather.h"

enum Spells
{
    SPELL_STATIC_DISRUPTION     = 43622,
    SPELL_STATIC_VISUAL         = 45265,
    SPELL_CALL_LIGHTNING        = 43661, //Missing timer
    SPELL_GUST_OF_WIND          = 43621,
    SPELL_ELECTRICAL_STORM      = 43648,
    SPELL_BERSERK               = 45078,
    SPELL_ELECTRICAL_OVERLOAD   = 43658,
    SPELL_EAGLE_SWOOP           = 44732
};

//"Your death gonna be quick, strangers. You shoulda never have come to this place..."
#define SAY_ONAGGRO "I be da predator! You da prey..."
#define SAY_ONDEATH "You can't... kill... me spirit!"
#define SAY_ONSLAY1 "Ya got nothin'!"
#define SAY_ONSLAY2 "Stop your cryin'!"
#define SAY_ONSUMMON "Feed, me bruddahs!"
#define SAY_ONENRAGE "All you be doing is wasting my time!"
#define SOUND_ONAGGRO 12013
#define SOUND_ONDEATH 12019
#define SOUND_ONSLAY1 12017
#define SOUND_ONSLAY2 12018
#define SOUND_ONSUMMON 12014
#define SOUND_ONENRAGE 12016

#define MOB_SOARING_EAGLE 24858
#define SE_LOC_X_MAX 400
#define SE_LOC_X_MIN 335
#define SE_LOC_Y_MAX 1435
#define SE_LOC_Y_MIN 1370

class boss_akilzon : public CreatureScript
{
    public:

        boss_akilzon()
            : CreatureScript("boss_akilzon")
        {
        }

        struct boss_akilzonAI : public ScriptedAI
        {
            boss_akilzonAI(Creature* c) : ScriptedAI(c)
            {
                pInstance = c->GetInstanceScript();
            }
            InstanceScript *pInstance;

            uint64 BirdGUIDs[8];
            uint64 TargetGUID;
            uint64 CycloneGUID;
            uint64 CloudGUID;

            uint32 StaticDisruption_Timer;
            uint32 GustOfWind_Timer;
            uint32 CallLighting_Timer;
            uint32 ElectricalStorm_Timer;
            uint32 SummonEagles_Timer;
            uint32 Enrage_Timer;

            uint32 StormCount;
            uint32 StormSequenceTimer;

            bool isRaining;

            void Reset()
            {
                if (pInstance)
                    pInstance->SetData(DATA_AKILZONEVENT, NOT_STARTED);

                StaticDisruption_Timer = urand(10000, 20000); //10 to 20 seconds (bosskillers)
                GustOfWind_Timer = urand(20000, 30000); //20 to 30 seconds(bosskillers)
                CallLighting_Timer = urand(10000, 20000); //totaly random timer. can't find any info on this
                ElectricalStorm_Timer = 60000; //60 seconds(bosskillers)
                Enrage_Timer = 10*MINUTE*IN_MILLISECONDS; //10 minutes till enrage(bosskillers)
                SummonEagles_Timer = 99999;

                TargetGUID = 0;
                CloudGUID = 0;
                CycloneGUID = 0;
                DespawnSummons();
                for (uint8 i = 0; i < 8; ++i)
                    BirdGUIDs[i] = 0;

                StormCount = 0;
                StormSequenceTimer = 0;

                isRaining = false;

                SetWeather(WEATHER_STATE_FINE, 0.0f);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->MonsterYell(SAY_ONAGGRO, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_ONAGGRO);
                //DoZoneInCombat();
                if (pInstance)
                    pInstance->SetData(DATA_AKILZONEVENT, IN_PROGRESS);
            }

            void JustDied(Unit* /*Killer*/)
            {
                me->MonsterYell(SAY_ONDEATH, LANG_UNIVERSAL, 0);
                DoPlaySoundToSet(me, SOUND_ONDEATH);
                if (pInstance)
                    pInstance->SetData(DATA_AKILZONEVENT, DONE);
                DespawnSummons();
            }

            void KilledUnit(Unit* /*victim*/)
            {
                switch (urand(0, 1))
                {
                    case 0:
                        me->MonsterYell(SAY_ONSLAY1, LANG_UNIVERSAL, 0);
                        DoPlaySoundToSet(me, SOUND_ONSLAY1);
                        break;
                    case 1:
                        me->MonsterYell(SAY_ONSLAY2, LANG_UNIVERSAL, 0);
                        DoPlaySoundToSet(me, SOUND_ONSLAY2);
                        break;
                }
            }

            void DespawnSummons()
            {
                for (uint8 i = 0; i < 8; ++i)
                {
                    Unit* bird = Unit::GetUnit(*me, BirdGUIDs[i]);
                    if (bird && bird->isAlive())
                    {
                        bird->SetVisible(false);
                        bird->setDeathState(JUST_DIED);
                    }
                }
            }

            void SetWeather(uint32 weather, float grade)
            {
                Map* pMap = me->GetMap();
                if (!pMap->IsDungeon())
                    return;

                WorldPacket data(SMSG_WEATHER, (4+4+4));
                data << uint32(weather) << float(grade) << uint8(0);

                pMap->SendToPlayers(&data);
            }

            void HandleStormSequence(Unit* Cloud) // 1: begin, 2-9: tick, 10: end
            {
                if (StormCount < 10 && StormCount > 1)
                {
                    // deal damage
                    int32 bp0 = 800;
                    for (uint8 i = 2; i < StormCount; ++i)
                        bp0 *= 2;

                    CellPair p(Trinity::ComputeCellPair(me->GetPositionX(), me->GetPositionY()));
                    Cell cell(p);
                    cell.data.Part.reserved = ALL_DISTRICT;
                    cell.SetNoCreate();

                    std::list<Unit* > tempUnitMap;

                    {
                        Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(me, me, 999);
                        Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(me, tempUnitMap, u_check);

                        TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, WorldTypeMapContainer > world_unit_searcher(searcher);
                        TypeContainerVisitor<Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck>, GridTypeMapContainer >  grid_unit_searcher(searcher);

                        cell.Visit(p, world_unit_searcher, *(me->GetMap()));
                        cell.Visit(p, grid_unit_searcher, *(me->GetMap()));
                    }
                    //dealdamege
                    for (std::list<Unit*>::const_iterator i = tempUnitMap.begin(); i != tempUnitMap.end(); ++i)
                    {
                        if (!Cloud->IsWithinDist(*i, 6, false))
                        {
                            Cloud->CastCustomSpell(*i, 43137, &bp0, NULL, NULL, true, 0, 0, me->GetGUID());
                        }
                    }
                    // visual
                    float x, y, z;
                    z = me->GetPositionZ();
                    for (uint8 i = 0; i < 5+rand()%5; ++i)
                    {
                        x = 343.0f+rand()%60;
                        y = 1380.0f+rand()%60;
                        if (Unit* trigger = me->SummonTrigger(x, y, z, 0, 2000))
                        {
                            trigger->setFaction(35);
                            trigger->SetMaxHealth(100000);
                            trigger->SetHealth(100000);
                            trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            if (Cloud)
                                Cloud->CastCustomSpell(trigger, /*43661*/43137, &bp0, NULL, NULL, true, 0, 0, Cloud->GetGUID());
                        }
                    }
                }
                ++StormCount;
                if (StormCount > 10)
                {
                    StormCount = 0; // finish
                    SummonEagles_Timer = 5000;
                    me->InterruptNonMeleeSpells(false);
                    CloudGUID = 0;
                    if (Cloud)
                        Cloud->DealDamage(Cloud, Cloud->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                    SetWeather(WEATHER_STATE_FINE, 0.0f);
                    isRaining = false;
                }
                StormSequenceTimer = 1000;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (StormCount)
                {
                    Unit* target = Unit::GetUnit(*me, CloudGUID);
                    if (!target || !target->isAlive())
                    {
                        EnterEvadeMode();
                        return;
                    }
                    else if (Unit* Cyclone = Unit::GetUnit(*me, CycloneGUID))
                        Cyclone->CastSpell(target, 25160, true); // keep casting or...

                    if (StormSequenceTimer <= diff)
                        HandleStormSequence(target);
                    else
                        StormSequenceTimer -= diff;

                    return;
                }

                if (Enrage_Timer <= diff)
                {
                    me->MonsterYell(SAY_ONENRAGE, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, SOUND_ONENRAGE);
                    DoCast(me, SPELL_BERSERK, true);
                    Enrage_Timer = 600000;
                } else Enrage_Timer -= diff;

                if (StaticDisruption_Timer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                    if (!target) target = me->getVictim();
                    TargetGUID = target->GetGUID();
                    DoCast(target, SPELL_STATIC_DISRUPTION, false);
                    me->SetInFront(me->getVictim());
                    StaticDisruption_Timer = (10+rand()%8)*1000; // < 20s

                    /*if (float dist = me->IsWithinDist3d(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 5.0f) dist = 5.0f;
                    SDisruptAOEVisual_Timer = 1000 + floor(dist / 30 * 1000.0f);*/
                } else StaticDisruption_Timer -= diff;

                if (GustOfWind_Timer <= diff)
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                    if (!target) target = me->getVictim();
                    DoCast(target, SPELL_GUST_OF_WIND);
                    GustOfWind_Timer = (20+rand()%10)*1000; //20 to 30 seconds(bosskillers)
                } else GustOfWind_Timer -= diff;

                if (CallLighting_Timer <= diff)
                {
                    DoCast(me->getVictim(), SPELL_CALL_LIGHTNING);
                    CallLighting_Timer = (12 + rand()%5)*1000; //totaly random timer. can't find any info on this
                } else CallLighting_Timer -= diff;

                if (!isRaining && ElectricalStorm_Timer < uint32(8000 + rand() % 5000))
                {
                    SetWeather(WEATHER_STATE_HEAVY_RAIN, 0.9999f);
                    isRaining = true;
                }

                if (ElectricalStorm_Timer <= diff) {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                    if (!target)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    target->CastSpell(target, 44007, true);//cloud visual
                    DoCast(target, SPELL_ELECTRICAL_STORM, false);//storm cyclon + visual
                    float x, y, z;
                    target->GetPosition(x, y, z);
                    if (target)
                    {
                        target->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                        target->SendMonsterMove(x, y, me->GetPositionZ()+15, 0);
                    }
                    Unit* Cloud = me->SummonTrigger(x, y, me->GetPositionZ()+16, 0, 15000);
                    if (Cloud)
                    {
                        CloudGUID = Cloud->GetGUID();
                        Cloud->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
                        Cloud->StopMoving();
                        Cloud->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                        Cloud->setFaction(35);
                        Cloud->SetMaxHealth(9999999);
                        Cloud->SetHealth(9999999);
                        Cloud->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    ElectricalStorm_Timer = 60000; //60 seconds(bosskillers)
                    StormCount = 1;
                    StormSequenceTimer = 0;
                } else ElectricalStorm_Timer -= diff;

                if (SummonEagles_Timer <= diff)
                {
                    me->MonsterYell(SAY_ONSUMMON, LANG_UNIVERSAL, 0);
                    DoPlaySoundToSet(me, SOUND_ONSUMMON);

                    float x, y, z;
                    me->GetPosition(x, y, z);

                    for (uint8 i = 0; i < 8; ++i)
                    {
                        Unit* bird = Unit::GetUnit(*me, BirdGUIDs[i]);
                        if (!bird) //they despawned on die
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                x = target->GetPositionX() + irand(-10, 10);
                                y = target->GetPositionY() + irand(-10, 10);
                                z = target->GetPositionZ() + urand(16, 20);
                                if (z > 95)
                                    z = 95.0f - urand(0, 5);
                            }
                            Creature* creature = me->SummonCreature(MOB_SOARING_EAGLE, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                            if (creature)
                            {
                                creature->AddThreat(me->getVictim(), 1.0f);
                                creature->AI()->AttackStart(me->getVictim());
                                BirdGUIDs[i] = creature->GetGUID();
                            }
                        }
                    }
                    SummonEagles_Timer = 999999;
                } else SummonEagles_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_akilzonAI(creature);
        }
};

class mob_akilzon_eagle : public CreatureScript
{
    public:

        mob_akilzon_eagle()
            : CreatureScript("mob_akilzon_eagle")
        {
        }

        struct mob_akilzon_eagleAI : public ScriptedAI
        {
            mob_akilzon_eagleAI(Creature* c) : ScriptedAI(c) {}

            uint32 EagleSwoop_Timer;
            bool arrived;
            uint64 TargetGUID;

            void Reset()
            {
                EagleSwoop_Timer = 5000 + rand()%5000;
                arrived = true;
                TargetGUID = 0;
                me->SetUnitMovementFlags(MOVEMENTFLAG_LEVITATING);
            }

            void EnterCombat(Unit* /*who*/) {DoZoneInCombat();}

            void MoveInLineOfSight(Unit* /*who*/) {}

            void MovementInform(uint32, uint32)
            {
                arrived = true;
                if (TargetGUID)
                {
                    if (Unit* target = Unit::GetUnit(*me, TargetGUID))
                        DoCast(target, SPELL_EAGLE_SWOOP, true);
                    TargetGUID = 0;
                    me->SetSpeed(MOVE_RUN, 1.2f);
                    EagleSwoop_Timer = 5000 + rand()%5000;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (EagleSwoop_Timer <= diff)
                    EagleSwoop_Timer = 0;
                else
                    EagleSwoop_Timer -= diff;

                if (arrived)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        float x, y, z;
                        if (EagleSwoop_Timer)
                        {
                            x = target->GetPositionX() + irand(-10, 10);
                            y = target->GetPositionY() + irand(-10, 10);
                            z = target->GetPositionZ() + urand(10, 15);
                            if (z > 95)
                                z = 95.0f - urand(0, 5);
                        }
                        else
                        {
                            target->GetContactPoint(me, x, y, z);
                            z += 2;
                            me->SetSpeed(MOVE_RUN, 5.0f);
                            TargetGUID = target->GetGUID();
                        }
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                        arrived = false;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_akilzon_eagleAI(creature);
        }
};

void AddSC_boss_akilzon()
{
    new boss_akilzon();
    new mob_akilzon_eagle();
}

