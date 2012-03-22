/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "pit_of_saron.h"
#include "Vehicle.h"

enum eSpells
{
    SPELL_FIREBALL              = 69583, //Ymirjar Flamebearer
    SPELL_HELLFIRE              = 69586,
    SPELL_TACTICAL_BLINK        = 69584,
    SPELL_FROST_BREATH          = 69527, //Iceborn Proto-Drake
    SPELL_BLINDING_DIRT         = 70302, //Wrathbone Laborer
    SPELL_PUNCTURE_WOUND        = 70278,
    SPELL_SHOVELLED             = 69572,
    SPELL_LEAPING_FACE_MAUL     = 69504, // Geist Ambusher
};

enum eEvents
{
    // Ymirjar Flamebearer
    EVENT_FIREBALL              = 1,
    EVENT_TACTICAL_BLINK        = 2,

    //Wrathbone Laborer
    EVENT_BLINDING_DIRT         = 3,
    EVENT_PUNCTURE_WOUND        = 4,
    EVENT_SHOVELLED             = 5,
};

const Position spawnPoints1[4] =
{
    {877.666199f, 61.523361f, 527.974243f, 3.624145f},
    {885.715027f, 65.515602f, 533.431030f, 3.857180f},
    {912.531189f, 63.785076f, 547.925720f, 3.235373f},
    {909.602722f, 83.248398f, 551.600403f, 3.251082f},
};
const Position spawnPoints2[4] =
{    
    {879.286743f, 41.535030f, 521.009338f, 3.486701f},
    {889.974548f, 45.270569f, 527.154236f, 3.612364f},
    {919.853027f, 88.957771f, 558.705993f, 3.592729f},
    {921.595520f, 69.234627f, 557.946716f, 3.145053f},    
};
const Position spawnPointsYmirjar[2] =
{
    {883.150024f, 54.626401f, 528.262024f, 3.678787f},
    {915.107971f, 75.316299f, 553.531006f, 3.678787f},
};
const Position spawnPointsFallenWarrior[8] =
{
    {937.606506f, 0.776727f, 578.888000f, 1.090893f},
    {928.419006f, 8.786335f, 577.693970f, 1.122307f},
    {924.478699f, -7.662051f, 582.044983f, 1.489874f},
    {935.244568f, -10.427516f, 583.265503f, 1.358702f},
    {935.098694f, -24.272480f, 588.035400f, 1.653226f},
    {921.272644f, -22.194103f, 585.452576f, 1.331212f},
    {930.109009f, -56.889900f, 591.848999f, 2.353980f},
    {924.945984f, -60.164799f, 591.879028f, 2.237270f},
};

const Position spawnPointsWrathboneColdwraith[4] =
{
    {925.477234f, -1.383301f, 580.479980f, 1.240126f},
    {935.6500513f, -6.321967f, 582.133972f, 1.141952f},
    {920.783020f, -44.854099f, 590.411987f, 1.590680f},
    {933.810974f, -45.009399f, 591.658997f, 1.582540f},
};

const Position IceCiclespawnPointsFallenWarrior[8] =
{
    {997.252991f, -139.257004f, 615.875000f, 2.722710f},
    {1000.400024f, -127.873001f, 616.247009f, 3.403390f},
    {1049.770020f, -113.330002f, 629.814026f, 4.101520f},
    {1042.160034f, -104.300003f, 630.038025f, 3.892080f},
    {1062.150024f, -29.850700f, 633.879028f, 4.433140f},
    {1073.599976f, -31.012199f, 633.408997f, 4.607670f},
    {1069.910034f, 100.042000f, 631.062012f, 4.869470f},
    {1059.170044f, 95.906303f, 630.781006f, 4.939280f},
};

const Position IceCiclespawnPointsWrathboneSkeleton[12] =
{
    {1033.609863f, -113.968132f, 627.523987f, 3.794239f},
    {1043.910034f, -124.613998f, 627.747986f, 3.595380f},
    {1068.930054f, -88.752602f, 632.828003f, 4.223700f},
    {1050.0f, -69.646599f, 633.078979f, 4.363320f},
    {1055.680054f, -52.713402f, 633.510986f, 4.607670f},
    {1069.369995f, -52.008701f, 633.919983f, 4.520400f},
    {1069.390015f, -12.805800f, 633.627014f, 4.537860f},
    {1077.579956f, -14.718200f, 632.726013f, 4.450590f},
    {1079.089966f, 34.306599f, 629.799988f, 4.607670f},
    {1071.270020f, 38.016102f, 629.828979f, 4.956740f},
    {1058.099976f, 92.909897f, 630.413025f, 5.074410f},
    {1070.369995f, 96.143799f, 631.075012f, 4.910200f},
};

const Position IceCiclespawnPointsWrathboneSorcerer[2] =
{
    {1073.608643f, 49.570923f, 630.635559f, 4.996680f},
    {1067.034912f, 47.677979f, 630.472473f, 4.851380f},
};

static const Position MoveLocations2[9] =
{
    {1025.534790f, 129.039612f, 628.156189f, 0.000000f},
    {1035.394897f, 144.298599f, 628.156189f, 0.000000f},
    {1042.624390f, 156.986679f, 628.156189f, 0.000000f},
    {1037.534790f, 132.039612f, 628.156189f, 0.000000f},
    {1050.534790f, 140.039612f, 628.156189f, 0.000000f},
    {1043.534790f, 141.039612f, 628.156189f, 0.000000f},
    {1038.534790f, 130.039612f, 628.156189f, 0.000000f},
    {1029.534790f, 125.039612f, 628.156189f, 0.000000f},
    {1028.534790f, 158.039612f, 628.156189f, 0.000000f},
};

static const Position triggerPos1 = {1048.629150f, 110.203377f, 628.224060f, 2.118303f};
static const Position triggerPos2 = {1063.679932f, 119.296852f, 628.156189f, 2.251821f};
static const Position sindraPos = {986.353271f, 174.938004f, 670.492798f, 0.000000f};
static const Position leaderPosOutro2 = {988.998962f, 172.250290f, 628.156128f, 0.000000f};

class mob_ymirjar_flamebearer : public CreatureScript
{
    public:
        mob_ymirjar_flamebearer() : CreatureScript("mob_ymirjar_flamebearer") { }

        struct mob_ymirjar_flamebearerAI: public ScriptedAI
        {
            mob_ymirjar_flamebearerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_FIREBALL, 4000);
                _events.ScheduleEvent(EVENT_TACTICAL_BLINK, 15000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIREBALL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FIREBALL);
                            _events.RescheduleEvent(EVENT_FIREBALL, 5000);
                            break;
                        case EVENT_TACTICAL_BLINK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_TACTICAL_BLINK);
                            DoCast(me, SPELL_HELLFIRE);
                            _events.RescheduleEvent(EVENT_TACTICAL_BLINK, 12000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_ymirjar_flamebearerAI(creature);
        }
};

class mob_iceborn_protodrake : public CreatureScript
{
    public:
        mob_iceborn_protodrake() : CreatureScript("mob_iceborn_protodrake") { }

        struct mob_iceborn_protodrakeAI: public ScriptedAI
        {
            mob_iceborn_protodrakeAI(Creature* creature) : ScriptedAI(creature), _vehicle(creature->GetVehicleKit())
            {
                ASSERT(_vehicle);
            }

            void Reset()
            {
                _frostBreathCooldown = 5000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _vehicle->RemoveAllPassengers();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_frostBreathCooldown < diff)
                {
                    DoCastVictim(SPELL_FROST_BREATH);
                    _frostBreathCooldown = 10000;
                }
                else
                    _frostBreathCooldown -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            Vehicle* _vehicle;
            uint32 _frostBreathCooldown;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_iceborn_protodrakeAI(creature);
        }
};

class mob_wrathbone_laborer : public CreatureScript
{
    public:
        mob_wrathbone_laborer() : CreatureScript("mob_wrathbone_laborer") { }

        struct mob_wrathbone_laborerAI: public ScriptedAI
        {
            mob_wrathbone_laborerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void Reset()
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_BLINDING_DIRT, 8000);
                _events.ScheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
                _events.ScheduleEvent(EVENT_SHOVELLED, 5000);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BLINDING_DIRT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 10.0f, true))
                                DoCast(target, SPELL_BLINDING_DIRT);
                            _events.RescheduleEvent(EVENT_BLINDING_DIRT, 10000);
                            return;
                        case EVENT_PUNCTURE_WOUND:
                            DoCastVictim(SPELL_PUNCTURE_WOUND);
                            _events.RescheduleEvent(EVENT_PUNCTURE_WOUND, 9000);
                            return;
                        case EVENT_SHOVELLED:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, -5.0f))
                                DoCast(target, SPELL_SHOVELLED);
                            _events.RescheduleEvent(EVENT_SHOVELLED, 7000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_wrathbone_laborerAI(creature);
        }
};

class spell_trash_mob_glacial_strike : public SpellScriptLoader
{
    public:
        spell_trash_mob_glacial_strike() : SpellScriptLoader("spell_trash_mob_glacial_strike") { }

        class spell_trash_mob_glacial_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_trash_mob_glacial_strike_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (GetTarget()->IsFullHealth())
                {
                    GetTarget()->RemoveAura(GetId(), 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
                    PreventDefaultAction();
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_trash_mob_glacial_strike_AuraScript::PeriodicTick, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_trash_mob_glacial_strike_AuraScript();
        }
};

/*
Script Complete: 100%
Name: Start Pit Of Saron
Author: Cemak
*/
enum SAYTyrranusEvent
{
    SAY_TYRRANUS_1                 = -1658074,
    SAY_TYRRANUS_2                 = -1658075,
    SAY_TYRRANUS_3                 = -1658078,
    SAY_TYRRANUS_4                 = -1658082,
    
    SAY_SYLVANAS_1                 = -1658076,
    SAY_SYLVANAS_2                 = -1658080,
    SAY_SYLVANAS_3                 = -1658085,
    SAY_SYLVANAS_4                 = -1658087,
    
    SAY_JAINA_1                    = -1658077,
    SAY_JAINA_2                    = -1658081,
    SAY_JAINA_3                    = -1658084,
    SAY_JAINA_4                    = -1658086,
    
    SAY_SOUND                      = 16750,
};

enum SPELLSTyrranusEvent
{
    SPELL_NECROMANTIC_POWER         = 69347,
    SPELL_DEATH_ARMY_VISUAL         = 67693,
    SPELL_BLIZZARD_JAINA            = 70132,
    SPELL_ICE_LANCE_JAINA           = 70464,
    SPELL_SHADOW_BOLT_SYLVANAS      = 70512,
    SPELL_MULTI_SHOT_SYLVANAS       = 70513,
};

struct startPosition
{
    uint32 entry[2];
    Position movePosition;
} startPositions[] =
{
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 446.739990f, 228.576996f, 528.830994f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 449.187988f, 226.212006f, 528.830994f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 447.351990f, 222.753998f, 528.830994f } },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 442.691010f, 223.524994f, 528.830994f} },
    { { NPC_CHAMPION_1_ALLIANCE, NPC_CHAMPION_1_HORDE }, { 442.967010f, 219.535004f, 528.830994f} },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 447.290009f, 213.916000f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 450.540985f, 212.276993f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 452.884003f, 209.141006f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 449.834991f, 206.682007f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 445.794006f, 206.057007f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_2_HORDE }, { 446.541992f, 209.985992f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 446.29299f, 195.046997f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 444.035004f, 197.669006f, 528.830994f } },
    { { NPC_CHAMPION_2_ALLIANCE, NPC_CHAMPION_3_HORDE }, { 443.346008f, 192.343002f, 528.830994f } },

    //{ { NPC_KORLAEN, NPC_KORALEN }, { 438.505005f, 211.539993f, 528.708008f } },
    //{ { NPC_ELANDRA, NPC_KILARA }, { 438.946014f, 215.427002f, 528.708984f } },
    //{ { NPC_JAINA_PART1, NPC_SYLVANAS_PART1 }, { 440.787994f, 213.759003f, 528.710022f } },

    { { 0, 0 }, { 0.0f, 0.0f, 0.0f, 0.0f } }
};

class pos_intro : public CreatureScript
{
public:
    pos_intro() : CreatureScript("pos_intro") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new pos_introAI(pCreature);
    }

    struct pos_introAI : public ScriptedAI
    {
        pos_introAI(Creature *c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
            Reset();
        }

        void Reset()
        {
            StartPhase = 0;
            StartTimer = 5000;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
            event = true;
        }

        void UpdateAI(const uint32 diff)
        {
            if(instance->GetData(DATA_TYRANNUS_START) == IN_PROGRESS && event)
            {
                if (StartTimer <= diff)
                {
                    switch (StartPhase)
                    {
                        case 0:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                            {
                                sTyrannus->SetCanFly(true);
                                DoScriptText(SAY_TYRRANUS_1, sTyrannus);
                                
                                int32 entryIndex;
                               if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                     entryIndex = 0;
                                  else
                                     entryIndex = 1;
                                     
                               Position spawnPoint = {427.36f, 212.636f, 529.47f, 6.2564f};
                               
                              for (int8 i = 0; startPositions[i].entry[entryIndex] != 0; ++i)
                              {
                                 if (Creature* summon = me->SummonCreature(startPositions[i].entry[entryIndex], spawnPoint, TEMPSUMMON_DEAD_DESPAWN))
                                  summon->GetMotionMaster()->MovePoint(0, startPositions[i].movePosition);
                              }
                            }
                            ++StartPhase;
                            StartTimer = 5000;
                            break;
                        case 1:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                DoScriptText(SAY_TYRRANUS_2, sTyrannus);
                            ++StartPhase;
                            StartTimer = 15000;
                            break;
                        case 2:
                            if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                DoScriptText(SAY_SYLVANAS_1, me);
                            else if(me->GetEntry() == NPC_JAINA_PART1)
                                DoScriptText(SAY_JAINA_1, me);

                            if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            {
                                GetCreatureListWithEntryInGrid(Champion1, me, NPC_CHAMPION_1_ALLIANCE, 250.0f);
                                for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                                {
                                    Creature *sChampions = *itr;
                                    if (!sChampions)
                                        continue;

                                    if (sChampions->isAlive())
                                        sChampions->GetMotionMaster()->MovePoint(0, 487.463989f, 246.891006f, 528.708984f);
                                }

                                GetCreatureListWithEntryInGrid(Champion2, me, NPC_CHAMPION_2_ALLIANCE, 250.0f);
                                for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                                {
                                    Creature *sChampions = *itr;
                                    if (!sChampions)
                                        continue;

                                    if (sChampions->isAlive())
                                       sChampions->GetMotionMaster()->MovePoint(0, 504.444000f, 211.061996f, 528.710022f);
                                }
                            }
                            else
                            {
                                GetCreatureListWithEntryInGrid(Champion1, me, NPC_CHAMPION_1_HORDE, 250.0f);
                                for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                                {
                                    Creature *sChampions = *itr;
                                    if (!sChampions)
                                        continue;

                                    if (sChampions->isAlive())
                                        sChampions->GetMotionMaster()->MovePoint(0, 487.463989f, 246.891006f, 528.708984f);
                                        
                                }

                                GetCreatureListWithEntryInGrid(Champion2, me, NPC_CHAMPION_2_HORDE, 250.0f);
                                for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                                {
                                    Creature *sChampions = *itr;
                                    if (!sChampions)
                                        continue;

                                    if (sChampions->isAlive())
                                        sChampions->GetMotionMaster()->MovePoint(0, 504.444000f, 211.061996f, 528.710022f);
                                }

                                GetCreatureListWithEntryInGrid(Champion3, me, NPC_CHAMPION_3_HORDE, 250.0f);
                                for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                                {
                                    Creature *sChampions = *itr;
                                    if (!sChampions)
                                        continue;

                                    if (sChampions->isAlive())
                                       sChampions->GetMotionMaster()->MovePoint(0, 504.444000f, 211.061996f, 528.710022f);
                                }
                            }
                            ++StartPhase;
                            StartTimer = 1000;
                            break;
                        case 3:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                DoScriptText(SAY_TYRRANUS_3, sTyrannus);
                            ++StartPhase;
                            StartTimer = 2000;
                            break;
                        case 4:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                DoPlaySoundToSet(sTyrannus, SAY_SOUND);

                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                {
                                    sChampions->AttackStop();
                                    sChampions->GetMotionMaster()->MoveFall();
                                }
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                {
                                    sChampions->AttackStop();
                                    sChampions->GetMotionMaster()->MoveFall();
                                }
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                {
                                    sChampions->AttackStop();
                                    sChampions->GetMotionMaster()->MoveFall();
                                }
                            }
                            ++StartPhase;
                            StartTimer = 5000;
                            break;
                        case 5:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                sTyrannus->CastSpell(sTyrannus, SPELL_NECROMANTIC_POWER, false);

                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                    sChampions->Kill(sChampions, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                    sChampions->Kill(sChampions, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (sChampions->isAlive())
                                    sChampions->Kill(sChampions, false);
                            }

                            if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                DoScriptText(SAY_SYLVANAS_2, me);
                            else if(me->GetEntry() == NPC_JAINA_PART1)
                                DoScriptText(SAY_JAINA_2, me);
                            ++StartPhase;
                            StartTimer = 5000;
                            break;
                        case 6:
                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                sChampions->Respawn();
                                sChampions->CastSpell(sChampions, SPELL_DEATH_ARMY_VISUAL, true);
                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    sChampions->UpdateEntry(36796, ALLIANCE);
                                else
                                    sChampions->UpdateEntry(36796, HORDE);
                                sChampions->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                sChampions->SetReactState(REACT_PASSIVE);
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                sChampions->Respawn();
                                sChampions->CastSpell(sChampions, SPELL_DEATH_ARMY_VISUAL, true);
                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    sChampions->UpdateEntry(36796, ALLIANCE);
                                else
                                    sChampions->UpdateEntry(36796, HORDE);
                                sChampions->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                sChampions->SetReactState(REACT_PASSIVE);
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                sChampions->Respawn();
                                sChampions->CastSpell(sChampions, SPELL_DEATH_ARMY_VISUAL, true);
                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    sChampions->UpdateEntry(36796, ALLIANCE);
                                else
                                    sChampions->UpdateEntry(36796, HORDE);
                                sChampions->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                sChampions->SetReactState(REACT_PASSIVE);
                            }

                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                DoScriptText(SAY_TYRRANUS_4, sTyrannus);

                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (Creature* pHelper = me->FindNearestCreature(NPC_KORALEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                                else if (Creature* pHelper = me->FindNearestCreature(NPC_KORLAEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (Creature* pHelper = me->FindNearestCreature(NPC_KORALEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                                else if (Creature* pHelper = me->FindNearestCreature(NPC_KORLAEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if (Creature* pHelper = me->FindNearestCreature(NPC_KORALEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                                else if (Creature* pHelper = me->FindNearestCreature(NPC_KORLAEN, 250.0f, true))
                                {
                                    sChampions->Attack(pHelper, true);
                                    sChampions->GetMotionMaster()->MoveChase(pHelper);
                                }
                            }
                            ++StartPhase;
                            StartTimer = 3000;
                            break;
                        case 7:
                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_MULTI_SHOT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_BLIZZARD_JAINA, true);
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_MULTI_SHOT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_BLIZZARD_JAINA, true);
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_MULTI_SHOT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_BLIZZARD_JAINA, true);
                            }
                            ++StartPhase;
                            StartTimer = 500;
                            break;
                        case 8:
                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_SHADOW_BOLT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_ICE_LANCE_JAINA, true);
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_SHADOW_BOLT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_ICE_LANCE_JAINA, true);
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                if(me->GetEntry() == NPC_SYLVANAS_PART1)
                                    me->CastSpell(sChampions, SPELL_SHADOW_BOLT_SYLVANAS, true);
                                else
                                    me->CastSpell(sChampions, SPELL_ICE_LANCE_JAINA, true);
                            }
                            ++StartPhase;
                            StartTimer = 500;
                            break;
                        case 9:
                            for(std::list<Creature*>::iterator itr = Champion1.begin(); itr != Champion1.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;
                                me->Kill(sChampions, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champion2.begin(); itr != Champion2.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                me->Kill(sChampions, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champion3.begin(); itr != Champion3.end(); ++itr)
                            {
                                Creature *sChampions = *itr;
                                if (!sChampions)
                                    continue;

                                me->Kill(sChampions, false);
                            }
                            ++StartPhase;
                            StartTimer = 3000;
                            break;
                        case 10:
                            if(me->GetEntry() == NPC_JAINA_PART1)
                                DoScriptText(SAY_JAINA_3, me);
                            else 
                                DoScriptText(SAY_SYLVANAS_3, me);
                            ++StartPhase;
                            StartTimer = 10000;
                            break;
                        case 11:
                            if(me->GetEntry() == NPC_JAINA_PART1)
                            DoScriptText(SAY_JAINA_4, me);
                            else 
                                DoScriptText(SAY_SYLVANAS_4, me);
                            ++StartPhase;
                            StartTimer = 10000;
                            break;
                        case 12:
                            if (Creature* sTyrannus = me->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                                sTyrannus->GetMotionMaster()->MovePoint(0, 938.125f, 93.928f, 585.39f);
                            instance->SetData(DATA_TYRANNUS_START, DONE);
                            event = false;
                            ++StartPhase;
                            StartTimer = 10000;
                            break;
                        return;					
                    }
                } else StartTimer -= diff;
            }
        }

    private:
        InstanceScript* instance;
        std::list<Creature*> Champion1;
        std::list<Creature*> Champion2;
        std::list<Creature*> Champion3;
        uint32 StartTimer;
        uint8 StartPhase;
        bool event;
    };
};
class at_pos_intro : public AreaTriggerScript
{
    public:
        at_pos_intro() : AreaTriggerScript("at_pos_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {
         if (InstanceScript* instance = player->GetInstanceScript())
         {
            if(instance->GetData(DATA_TYRANNUS_START) == IN_PROGRESS || instance->GetData(DATA_TYRANNUS_START) == DONE || player->isGameMaster() || !instance)
                return false;

            instance->SetData(DATA_TYRANNUS_START, IN_PROGRESS);

            return false;
          }
          return false;
        }
};

enum sTyrannus
{
     SAY_TYRANNUS_AMBUSH_1                      = -1658050,
     SAY_TYRANNUS_AMBUSH_2                      = -1658051,
     SAY_GAUNTLET_START                         = -1658052,
     SAY_RESCUED_HORDE_ALLIANCE                 = -1658071, // TODO: sound
};

class at_ymirjar_flamebearer_pos : public AreaTriggerScript
{
    public:
        at_ymirjar_flamebearer_pos() : AreaTriggerScript("at_ymirjar_flamebearer_pos") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {
            InstanceScript* instance = player->GetInstanceScript();
               if(instance->GetData(DATA_AREA_TRIGGER_YMIRJAR) == DONE || player->isGameMaster() || !instance)
                      return false;
                      
                if (instance->GetBossState(DATA_GARFROST) == DONE && instance->GetBossState(DATA_ICK) == DONE)
                {
                   instance->SetData(DATA_AREA_TRIGGER_YMIRJAR, DONE);
                   if(Creature *pTyrannus = player->SummonCreature(NPC_TYRANNUS_EVENTS, 940.076355f, 91.047089f, 576.178040f, 3.596342f, TEMPSUMMON_DEAD_DESPAWN, 0))
                   {
                     DoScriptText(SAY_TYRANNUS_AMBUSH_1, pTyrannus);
                     pTyrannus->SetSpeed(MOVE_FLIGHT, 8.5f, true);
                     pTyrannus->GetMotionMaster()->MovePoint(0, 916.282104f, -71.079742f, 606.430359f);
                   }
                   for (uint8 i = 0; i < 4; i++)
                   {
                      player->SummonCreature(NPC_YMIRJAR_FLAMEBEARER, spawnPoints1[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                      player->SummonCreature(NPC_YMIRJAR_WRATBRINGER, spawnPoints2[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                   }
                   for(uint8 k = 0; k < 2; k++)
                   {
                      player->SummonCreature(NPC_YMIRJAR_DEATHBRINGER, spawnPointsYmirjar[k], TEMPSUMMON_DEAD_DESPAWN, 0);
                   }
                   
                   return false;
                }
                return false;
        }
};
class at_fallen_warrior_pos : public AreaTriggerScript
{
    public:
        at_fallen_warrior_pos() : AreaTriggerScript("at_fallen_warrior_pos") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {
            InstanceScript* instance = player->GetInstanceScript();
            if(instance->GetData(DATA_AREA_TRIGGER_FALLEN) == DONE || player->isGameMaster() || !instance)
                      return false;
                      
                if (instance->GetData(DATA_AREA_TRIGGER_YMIRJAR) == DONE)  
                {
                   instance->SetData(DATA_AREA_TRIGGER_FALLEN, DONE);
                   if(Creature *pTyrannus = player->FindNearestCreature(NPC_TYRANNUS_EVENTS, 250.0f, true))
                   {
                     DoScriptText(SAY_TYRANNUS_AMBUSH_2, pTyrannus);
                   }
                   for (uint8 i = 0; i < 8; i++)
                   {
                      player->SummonCreature(NPC_FALLEN_WARRIOR, spawnPointsFallenWarrior[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                   }
                   for (uint8 i = 0; i < 4; i++)
                   {
                      player->SummonCreature(NPC_WRATHBONE_COLDWRAITH, spawnPointsWrathboneColdwraith[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                   }
                   return false;
                }
                
            return false;
        }
};
class at_ice_cicle_pos : public AreaTriggerScript
{
    public:
        at_ice_cicle_pos() : AreaTriggerScript("at_ice_cicle_pos") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {    
            InstanceScript* instance = player->GetInstanceScript();
            if(instance->GetData(DATA_AREA_TRIGGER_ICE_CICLE) == IN_PROGRESS || instance->GetData(DATA_AREA_TRIGGER_ICE_CICLE) == DONE || player->isGameMaster() || !instance)
                      return false;
            if (instance->GetData(DATA_AREA_TRIGGER_FALLEN) == DONE && instance->GetData(DATA_AREA_TRIGGER_YMIRJAR) == DONE)  
            {
                instance->SetData(DATA_AREA_TRIGGER_ICE_CICLE, IN_PROGRESS);
                if (Creature* pTyrannus = player->FindNearestCreature(NPC_TYRANNUS_EVENTS, 150.0f, true))
                {
                    DoScriptText(SAY_GAUNTLET_START, pTyrannus);
                    pTyrannus->DespawnOrUnsummon();
                }
                for (uint8 i = 0; i < 8; i++)
                {
                   player->SummonCreature(NPC_FALLEN_WARRIOR, IceCiclespawnPointsFallenWarrior[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                }
                for (uint8 i = 0; i < 12; i++)
                {
                   player->SummonCreature(NPC_WRATHBONE_SKELETON, IceCiclespawnPointsWrathboneSkeleton[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                }
                for (uint8 i = 0; i < 2; i++)
                {
                   player->SummonCreature(NPC_WRATHBONE_SORCERER, IceCiclespawnPointsWrathboneSorcerer[i], TEMPSUMMON_DEAD_DESPAWN, 0);
                }
                return false;
            }
              return false;   
        }    
};

class at_slave_rescued_pos : public AreaTriggerScript
{
    public:
        at_slave_rescued_pos() : AreaTriggerScript("at_slave_rescued_pos") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {
          InstanceScript* instance = player->GetInstanceScript();
         
          if(instance->GetData(DATA_SLAVE_OUTRO_GARFROST) == DONE || player->isGameMaster() || !instance)
               return false;
               
           if(instance->GetData(DATA_SLAVE_OUTRO_GARFROST) == IN_PROGRESS)
           {
               instance->SetData(DATA_SLAVE_OUTRO_GARFROST, DONE);
               if(Creature *rSlave = player->FindNearestCreature(36888, 50.0f, true))
               {
                     DoScriptText(SAY_RESCUED_HORDE_ALLIANCE, rSlave);
                     rSlave->GetMotionMaster()->MovePoint(0, 831.654968f, 6.049870f, 509.910583f); // not correct 
               }
               uint8 i = 0;
               GetCreatureListWithEntryInGrid(Rescued1, player, 36889, 50.0f);
                for(std::list<Creature*>::iterator itr = Rescued1.begin(); itr != Rescued1.end(); ++itr)
                {
                   Creature *rescued = *itr;
                    if(!rescued)
                     continue;

                   if (rescued->isAlive())
                      rescued->GetMotionMaster()->MovePoint(0, 840.661987f, 5.974489f, 510.107910f);
                      ++i;
               }            
               return false;
            }
            
          return false;
        }
        
        private:
        std::list<Creature*> Rescued1;
};

class at_geist_ambusher_pos : public AreaTriggerScript
{
    public:
        at_geist_ambusher_pos() : AreaTriggerScript("at_geist_ambusher_pos") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* areaTrigger)
        {
          InstanceScript* instance = player->GetInstanceScript();
         
          if(player->isGameMaster() || !instance)
               return false;
               
           if(instance->GetData(DATA_SLAVE_OUTRO_GARFROST) == DONE)
           {
               uint8 i = 0;
               GetCreatureListWithEntryInGrid(Geist, player, 36886, 300.0f);
                for(std::list<Creature*>::iterator itr = Geist.begin(); itr != Geist.end(); ++itr)
                {
                   Creature *geist = *itr;
                    if(!geist)
                     continue;

                   if (geist->isAlive())  //TODO sound.
                      geist->GetMotionMaster()->MoveJump(835.122620f, 1.335451f, 509.846619f, 30.0f, 20.0f);
                      ++i;
               } 
               return true;
            }
            
          return false;
        }
        
        private:
        std::list<Creature*> Geist;
};

enum SAYPosOutro
{
    SAY_GORKUN_OUTRO_1              = -1658064,
    SAY_GORKUN_OUTRO_2              = -1658065,
    SAY_JAYNA_OUTRO_3               = -1658066,
    SAY_SYLVANAS_OUTRO_3            = -1658067,
    SAY_JAYNA_OUTRO_4               = -1658068,
    SAY_SYLVANAS_OUTRO_4            = -1658069,
    SAY_JAYNA_OUTRO_5               = -1658070,
};

class pos_outro : public CreatureScript
{
public:
    pos_outro() : CreatureScript("pos_outro") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new pos_outroAI(pCreature);
    }

    struct pos_outroAI : public ScriptedAI
    {
        pos_outroAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            instance = pCreature->GetInstanceScript();
            Reset();
        }
		
        void Reset()
        {
            uiIntroTimer1 = 0;
            uiIntroPhase1 = 0;
            me->SetVisible(false);
            Champions1.clear();
            Champions2.clear();
            Champions3.clear();
        }

        void UpdateAI(const uint32 diff)
        {
            if(instance->GetBossState(DATA_TYRANNUS) == DONE)
            {
                if (uiIntroTimer1 <= diff)
                {
                    switch (uiIntroPhase1)
                    {
                        case 0:
                            if (Creature* GorkunOrVictus = me->GetCreature(*me, instance->GetData64(DATA_VICTUS_OR_GORKUN_FREED)))
                                GorkunOrVictus->GetMotionMaster()->MovePoint(0, leaderPosOutro2);

                            if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            {
                                uint8 i = 0;
                                GetCreatureListWithEntryInGrid(Champions1, me, NPC_FREED_SLAVE_3_ALLIANCE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions1.begin(); itr != Champions1.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }

                                i = 4;
                                GetCreatureListWithEntryInGrid(Champions2, me, NPC_FREED_SLAVE_1_ALLIANCE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions2.begin(); itr != Champions2.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }

                                i = 7;
                                GetCreatureListWithEntryInGrid(Champions3, me, NPC_FREED_SLAVE_2_ALLIANCE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions3.begin(); itr != Champions3.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }
                            }
                            else
                            {
                                uint8 i = 0;
                                GetCreatureListWithEntryInGrid(Champions1, me, NPC_FREED_SLAVE_3_HORDE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions1.begin(); itr != Champions1.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }

                                i = 4;
                                GetCreatureListWithEntryInGrid(Champions2, me, NPC_FREED_SLAVE_1_HORDE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions2.begin(); itr != Champions2.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }

                                i = 7;
                                GetCreatureListWithEntryInGrid(Champions3, me, NPC_FREED_SLAVE_2_HORDE, 100.0f);
                                for(std::list<Creature*>::iterator itr = Champions3.begin(); itr != Champions3.end(); ++itr)
                                {
                                    Creature *slave = *itr;
                                    if(!slave)
                                        continue;

                                    if (slave->isAlive())
                                        slave->GetMotionMaster()->MovePoint(0, MoveLocations2[i]);
                                    ++i;
                                }
                            }
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 15000;
                            break;
                        case 1:
                            if (Creature* GorkunOrVictus = me->GetCreature(*me, instance->GetData64(DATA_VICTUS_OR_GORKUN_FREED)))
                                DoScriptText(SAY_GORKUN_OUTRO_1, GorkunOrVictus);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 15000;
                            break;
                        case 2:
                            if (Creature* GorkunOrVictus = me->GetCreature(*me, instance->GetData64(DATA_VICTUS_OR_GORKUN_FREED)))
                                DoScriptText(SAY_GORKUN_OUTRO_2, GorkunOrVictus);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 5000;
                            break;
                        case 3:
                            me->SetVisible(true);
                            if(Creature* pSindragosa = me->SummonCreature(NPC_SINDRAGOSA, sindraPos, TEMPSUMMON_CORPSE_DESPAWN, 3000))
                                pSindragosa->SetCanFly(true);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 5000;
                            break;
                        case 4:
                            if (Creature* portal = me->SummonCreature(22517, triggerPos1, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            {
                                portal->CastSpell(portal, 51807, false);
                                portal->SetDisplayId(17612);
                            }
                            if (Creature* portal = me->SummonCreature(22517, triggerPos2, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            {
                                portal->CastSpell(portal, 51807, false);
                                portal->SetDisplayId(17612);
                            }
                            if(me->GetEntry() == NPC_SYLVANAS_PART2)
                                DoScriptText(SAY_SYLVANAS_OUTRO_3, me);
                            else
                                DoScriptText(SAY_JAYNA_OUTRO_3, me);

                            if(instance)
                            {
                                Map* pMap = me->GetMap();
                                if(!pMap)
                                    return;

                                Map::PlayerList const &lPlayers = pMap->GetPlayers();
                                for(Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                                {
                                    if(!itr->getSource()->isAlive())
                                        continue;
                                    me->CastSpell(itr->getSource(), 36937, true);
                                    itr->getSource()->NearTeleportTo(1065.114746f, 96.392105f, 630.999573f, 2.063386f);
                                }
                            }
                            if (Creature* GorkunOrVictus = me->GetCreature(*me, instance->GetData64(DATA_VICTUS_OR_GORKUN_FREED)))
                                if (Creature* pSindragosa = me->GetCreature(*me, instance->GetData64(DATA_SINDRAGOSA)))
                                    pSindragosa->CastSpell(GorkunOrVictus, 70521, true);

                            if (Creature* GorkunOrVictus = me->GetCreature(*me, instance->GetData64(DATA_VICTUS_OR_GORKUN_FREED)))
                                if (GorkunOrVictus->isAlive() && GorkunOrVictus->IsInWorld())
                                    me->Kill(GorkunOrVictus, false);

                            for(std::list<Creature*>::iterator itr = Champions1.begin(); itr != Champions1.end(); ++itr)
                            {
                                Creature *slave = *itr;
                                if(!slave)
                                    continue;

                                if (slave->isAlive() && slave->IsInWorld())
                                    slave->Kill(slave, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champions2.begin(); itr != Champions2.end(); ++itr)
                            {
                                Creature *slave = *itr;
                                if(!slave)
                                    continue;

                                if (slave->isAlive() && slave->IsInWorld())
                                    slave->Kill(slave, false);
                            }

                            for(std::list<Creature*>::iterator itr = Champions3.begin(); itr != Champions3.end(); ++itr)
                            {
                                Creature *slave = *itr;
                                if(!slave)
                                    continue;

                                if (slave->isAlive() && slave->IsInWorld())
                                    slave->Kill(slave, false);
                            }
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 5000;
                            break;
                        case 5:
                            if (Creature* pSindragosa = me->GetCreature(*me, instance->GetData64(DATA_SINDRAGOSA)))
                                pSindragosa->GetMotionMaster()->MoveCharge(804.957214f, 102.497406f, 728.966370f, 42.00f, 0);

                            if(me->GetEntry() == NPC_SYLVANAS_PART2)
                                DoScriptText(SAY_SYLVANAS_OUTRO_4, me);
                            else
                                DoScriptText(SAY_JAYNA_OUTRO_4, me);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 7000;
                            break;
                        case 6:
                            if(me->GetEntry() == NPC_JAINA_PART2)
                                DoScriptText(SAY_JAYNA_OUTRO_5, me);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 7000;
                            break;
                        case 7:
                            if (Creature* jainaOrSylvanas = me->GetCreature(*me, instance->GetData64(DATA_JAINA_SYLVANAS_2)))
                                jainaOrSylvanas->GetMotionMaster()->MovePoint(0, 1100.734497f, 246.650696f, 628.182190f);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 20000;
                            break;
                        case 8:
                            instance->HandleGameObject(instance->GetData64(GO_HALLS_OF_REFLECT_PORT), true);
                            ++uiIntroPhase1;
                            uiIntroTimer1 = 25000;
                            break;                            
                    return;					
                    }
                } else uiIntroTimer1 -= diff;
            }
        }

    private:
        InstanceScript* instance;
        uint32 uiIntroTimer1;
        uint8 uiIntroPhase1;
        std::list<Creature*> Champions1;
        std::list<Creature*> Champions2;
        std::list<Creature*> Champions3;
    };
};
void AddSC_pit_of_saron()
{
    new mob_ymirjar_flamebearer();
    new mob_wrathbone_laborer();
    new mob_iceborn_protodrake();
    new spell_trash_mob_glacial_strike();
    new pos_intro();
    new at_pos_intro();
    new at_ymirjar_flamebearer_pos();
    new at_fallen_warrior_pos();
    new at_ice_cicle_pos();
    new at_slave_rescued_pos();
    new at_geist_ambusher_pos();
    new pos_outro();
}