///*
//* Copyright (C) 2016-20XX JadeCore <https://github.com/cooler-SAI/JadeCore548-patched>
//* Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
//*
//* This program is free software; you can redistribute it and/or modify it
//* under the terms of the GNU General Public License as published by the
//* Free Software Foundation; either version 2 of the License, or (at your
//* option) any later version.
//*
//* This program is distributed in the hope that it will be useful, but WITHOUT
//* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//* more details.
//*
//* You should have received a copy of the GNU General Public License along
//* with this program. If not, see <http://www.gnu.org/licenses/>.
//*
//* Raid: Throne of Thunder.
//* Boss: Jin'rokh the Breaker.
//*
//* Wowpedia boss history:
//*
//* "Jin'rokh was once part of an envoy sent to Stranglethorn Vale in order to stop Hakkar the Soulflayer from escaping Zul'Gurub.
//*  This Zandalari troll was a dire troll that aided warriors and paladins with the strength that they would have needed to defeat the powerful loa.
//*
//*  After Hakkar was defeated Jin'rokh and his fellow trolls left Yojamba Isle back to Zandalar. That was until the Cataclysm destroyed their land.
//*  He, along with any survivors, made their way back to the main lands to reunite the tribes, and eventually to Pandaria.
//*  He has since undergone a transformation after being enchanted with powers over storm by the Thunder King."
//*/
//
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "SpellScript.h"
//#include "SpellAuraEffects.h"
//#include "SpellAuras.h"
//#include "MapManager.h"
//#include "Spell.h"
//#include "Vehicle.h"
//#include "Cell.h"
//#include "CellImpl.h"
//#include "GridNotifiers.h"
//#include "GridNotifiersImpl.h"
//#include "CreatureTextMgr.h"
//#include "Unit.h"
//#include "Player.h"
//#include "Creature.h"
//#include "InstanceScript.h"
//#include "Map.h"
//#include "VehicleDefines.h"
//#include "SpellInfo.h"
//
//#include "throne_of_thunder.h"
//
//enum Yells
//{
//	SAY_AGGRO				= 0, // I must break you.. (35547)
//	SAY_INTRO				= 1, // The Thunda' King give me power.. come.. I'll show you! (35550)
//	SAY_DEATH				= 2, // How.. you.. beat.. me.. (35549)
//	SAY_BERSERK				= 3, // Bored.. you die now! (35548)
//	SAY_KILL				= 4, // Weak... (35551) / So easy to break..(35552)
//	SAY_STATIC_BURST		= 5, // Smash... (35553)
//	SAY_THUNDERING_THROW	= 6, // I'll crush your bones! (35554)
//	SAY_LIGHTNING_STORM		= 7, // I call the storm! (35555)
//	SAY_FOCUSED_LIGHTNING	= 8, // Zap... (35556)
//
//	ANN_THUNDERING_THROW	= 9,
//	ANN_FOCUSED_LIGHTNING	= 10,
//	ANN_LIGHTNING_STORM		= 11
//};
//
//enum Spells
//{
//    // Boss
//
//    // Thundering Throw.
//    SPELL_RIDE_VEHICLE          = 43671,  // Grab spell (Control Vehicle).
//
//    SPELL_THUNDERING_THROW      = 137180, // Main cast time spell, dummy effect 0 for SPELL_THUNDERING_THROW_GRAB.
//    SPELL_THUNDERING_THROW_GRAB = 137161, // Silence, pacify, eff. 0 script effect for SPELL_RIDE_VEHICLE.
//    SPELL_THUNDERING_THROW_JMP  = 137173, // Jump behind target spell cast on Statue npc.
//    SPELL_THUNDERING_THROW_PLR  = 137370, // Dmg dealed to player on impact.
//    SPELL_THUNDERING_THROW_AOE  = 137167, // Additional 190000 to 210000 Nature damage to other players within 8 yards of the point of impact.
//    SPELL_THUNDERING_THROW_STUN = 137371, // Stun for 5 seconds on other players within 8 yards of the point of impact.
//
//    // Conductive Waters.
//    SPELL_CONDUCTIVE_WATER_SUMM = 137145, // Summons Conductive Waters npc NPC_CONDUCTIVE_WATER.
//    SPELL_CONDUCTIVE_VISUAL     = 137277, // Water effect visual ground.
//    SPELL_CONDUCTIVE_VISUAL_2   = 137340, // Mogu fountain visual shooted by statue (orientation!).
//    SPELL_CONDUCTIVE_VISUAL_3   = 137978, // Electrified waters visual ground.
//    SPELL_CONDUCTIVE_WATER_GROW = 137676, // Aura size increase 137694 11 % each 100 ms.
//    SPELL_CONDUCTIVE_WATER      = 138470, // Debuff, + 80% Nature damage.
//    SPELL_FLUIDITY              = 138002, // Buff 40% damage dealt.
//
//    // Static burst + Wound.
//    SPELL_STATIC_BURST          = 137162, // Does 95000 to 105000 Nature damage to all players. After 3 sec., expires and applies 10 Static Wound stacks to current target (eff 1).
//
//    SPELL_STATIC_WOUND          = 138349, // Aura. Inflicts 20000 Nature damage / stack when taking melee damage. - 1 stack / 3 secs (eff 1).
//    SPELL_STATIC_WOUND_COND     = 138375, // Static Wound Conduction damage, inflicting 20000 / 3 Nature damage / stack to all players in the Conductive Water. If tank is in it.
//    SPELL_STATIC_WOUND_DMG      = 138389, // Inflicts 20000 / 3 Nature damage / stack to all players when taking melee damage. On SPELL_STATIC_WOUND.
//
//    // Focused Lightning + Lightning Fissure left after FL explosion (If the Focused Lightning detonates outside of Conductive Water, a Lightning Fissure forms).
//    SPELL_FOCUSED_LIGHTNING     = 137399, // Cast time + dummy on eff 0 (to summon Focused Lightning npc NPC_FOCUSED_LIGHTNING).
//    SPELL_FOCUSED_LIGHTNING_VIS = 137425, // Focused Lightning visual.
//    SPELL_FOCUSED_LIGHTNING_SPD = 137389, // Aura, each 500 ms increase movement speed (triggers 137437).
//    SPELL_FOCUSED_LIGHTNING_DMG = 137423, // Pulses 38000 to 42000 Nature damage every half second to other players within 5 yards.
//    SPELL_FOCUSED_LIGHTNING_FIX = 137422, // Fixated aura (player).
//    SPELL_FOCUSED_LIGHTNING_DET = 137374, // Focused Lightning Detonation damage, 170625 to 179375 Nature damage to players in 8 yards of fixated victim.
//    SPELL_FOCUSED_LIGHTNING_CND = 137530, // Focused Lightning Conduction damage, 170625 to 179375 Nature damage to all players standing in Conductive Water.
//    SPELL_FL_VIOLENT_DETONATION = 138990, // If touches ELECTRIFIED Conductive Water.
//
//    SPELL_LIGHTNING_FISSURE_SUM = 137479, // Summons Lightning Fissure npc NPC_LIGHTNING_FISSURE.
//    SPELL_LIGHTNING_FISSURE_VIS = 137480, // Fissure visual.
//    SPELL_LIGHTNING_FISSURE_DMG = 137484, // Aura.
//    SPELL_LIGHTNING_FISS_COND   = 138133, // Contacts Conductive Water, removing Lightning Fissure + 71250 - 78750 dmg to players standing in Conductive Water.
//    SPELL_IMPLOSION             = 137507, // LF implodes upon contact with another Focused Lightning, 237500 - 262500 dmg to all players + 10% damage taken from Implosion. 
//
//    // Lightning Storm.
//    SPELL_LIGHTNING_STORM       = 137313, // Aura.
//    SPELL_LIGHTNING_STORM_VIS   = 140555, // Visual.
//    SPELL_LIGHTNING_STRIKE_VIS  = 140507, // Visual too.
//    SPELL_LIGHTNING_STORM_VIS2  = 140775, // Visual 2.
//    SPELL_LIGHTNING_STORM_DMG   = 137261, // Effect 0 damage from aura.
//    SPELL_LIGHTNING_STORM_DUMMY = 140819, // Effect 1 dummy from aura.
//    SPELL_LIGHTNING_STORM_H_DMG = 137647, // Heroic, triggered on SPELL_LIGHTNING_STORM_DUMMY.
//    SPELL_LIGHTNING_DIFFUSION   = 137905, // Each Lightning Strike diffuses, 195000 to 205000 Nature damage to all players in a line. On SPELL_LIGHTNING_STORM_H_DMG.
//    SPELL_ELECTRIFIED_WATERS    = 138006, // Removes Fluidity, 35000 Nature damage / sec. to players in Conductive Water. Electrifies the water (visual change).
//
//    // Ionization - Heroic only.
//    SPELL_IONIZATION_AURA       = 138732, // Dummy on effect 1 for SPELL_IONIZATION_DMG when dispelled or duration expires.
//    SPELL_IONIZATION_DMG        = 138733, // HEROIC. Inflicts 450000 Nature damage to players within 8 yards.
//    SPELL_IONIZATION_CONDUCTION = 138743, // Ionization damage travels through Conductive Water, inflicting 450000 Nature damage to players standing in Conductive Water.
//
//    SPELL_BERSERK               = 144369  // Berserk, Enrage, Bye - Bye or, simply put, a wipe. :)
//};
//
//enum Npcs
//{
//    NPC_STATUE_TRIGGER          = 69467,
//    NPC_CONDUCTIVE_WATER        = 69469,
//	NPC_FOCUSED_LIGHTNING       = 69593,
//    NPC_LIGHTNING_FISSURE       = 69609
//};
//
//enum Events
//{
//    // Boss
//    EVENT_THUNDERING_THROW      = 1,
//    EVENT_THUNDERING_THROW_TOSS,
//    EVENT_THUNDERING_THROW_DMG,
//    EVENT_STATIC_BURST,
//    EVENT_FOCUSED_LIGHTNING,
//    EVENT_LIGHTNING_STORM_JUMP,
//    EVENT_LIGHTNING_STORM,
//    EVENT_IONIZATION,
//
//    EVENT_BERSERK,
//
//    // Focused Lightning   
//    EVENT_FOCUSED_LIGHTNING_DMG,
//
//    // Lightning Fissure
//    EVENT_FISSURE_SEARCH,
//
//    // Conductive    
//    EVENT_BUFF_DEBUFF
//};
//
//enum Actions
//{
//    // Statue trigger
//    ACTION_STATUE_WATER         = 1 // Break Mogu statue and form Conductive Water.
//};
//
//enum Timers
//{
//    TIMER_THUNDERING_THROW_F    = 28000, // 30 seconds into the fight counted with below.
//    TIMER_THUNDERING_THROW_S    = 90000, // Every 90 seconds after that.
//
//    TIMER_THUNDERING_THROW_TOSS = 2000,  // Actual throwing timer.
//    TIMER_THUNDERING_THROW_DMG  = 1500,  // Player damage timer.
//
//    TIMER_BUFF_DEBUFF           = 1100,  // Conductive Water buff / debuff refresh timer.
//
//    TIMER_STATIC_BURST_F        = 15000, // 15 seconds into the fight.
//    TIMER_STATIC_BURST_S        = 22000, // Every 22 seconds after that.
//
//    TIMER_FOCUSED_LIGHTNING_F   = 10000, // 10 seconds into the fight.
//    TIMER_FOCUSED_LIGHTNING_S   = 15000, // Every 15 seconds after that.
//
//    TIMER_FOCUSED_LIGHTNING_DMG = 500,   // Focused Lightning periodic damage.
//
//    TIMER_LIGHTNING_STORM_JUMPF = 88500, // Jump timer before Storm phase.
//    TIMER_LIGHTNING_STORM_JUMPS = 88500, // Jump timer before Storm phase.
//
//    TIMER_LIGHTNING_STORM       = 1500,  // Every 90sec counted with above.
//
//    TIMER_IONIZATION_F          = 45000, // HEROIC, once per normal phase.
//    TIMER_IONIZATION_S          = 90000,
//
//    TIMER_BERSERK               = 540000,
//};
//
//Position const middlePos        = { 5891.60f, 6263.18f, 124.11f };
//
//Position const statueTriggerPlace[4] =
//{
//    { 5841.659f, 6313.456f, 162.212f }, // South-east
//    { 5838.741f, 6210.887f, 159.103f }, // North-east
//    { 5943.230f, 6210.887f, 161.288f }, // North-west
//    { 5943.678f, 6315.564f, 163.020f }, // South-west
//};
//
//float triggerOrientations[4] =
//{
//    5.38f, // South-east O 218675
//    0.74f, // North-east O 218676
//    2.30f, // North-west O 218677
//    3.88f, // South-west O 218678
//};
//
//Position const statueThrowPlace[4] =
//{
//    { 5855.366f,  6301.588f, 157.095f }, // Jump South-east 2.39f O
//    { 5853.612f,  6227.119f, 156.869f }, // Jump North-east 3.95f O
//    { 5927.603f,  6224.533f, 158.019f }, // Jump North-west 5.69f O
//    { 5928.242f,  6301.532f, 156.285f }, // Jump South-west 0.72f O
//};
//
//Position const waterSummonPlace[4] =
//{
//    { 5861.975f, 6293.226f, 124.035f }, // South-east
//    { 5860.412f, 6232.429f, 124.035f }, // North-east
//    { 5922.794f, 6237.926f, 124.035f }, // North-west
//    { 5921.287f, 6288.865f, 124.035f }, // South-west
//};
//
//#define MAX_MOGU_STATUES 4
//
//class boss_jin_rokh_breaker : public CreatureScript
//{
//    public:
//        boss_jin_rokh_breaker() : CreatureScript("boss_jin_rokh_breaker") { }
//
//        struct boss_jin_rokh_breakerAI : public BossAI
//        {
//            boss_jin_rokh_breakerAI(Creature* creature) : BossAI(creature, DATA_JIN_ROKH_BREAKER_EVENT), summons(me), vehicle(creature->GetVehicleKit())
//            {
//                instance  = creature->GetInstanceScript();
//                introDone = false;
//                ASSERT(vehicle);
//            }
//
//            InstanceScript* instance;
//            SummonList summons;
//            EventMap events;
//            Vehicle* vehicle;
//            Unit* thunderingPlayer;
//            Creature* moguTrigger;
//            bool introDone;
//            uint8 statueUsed;
//
//            void Reset()
//            {
//                events.Reset();
//                summons.DespawnAll();
//
//                for (uint8 i = 0; i < MAX_MOGU_STATUES; ++i)
//                    if (GameObject* statue = me->FindNearestGameObject(GO_MOGU_FOUNTAIN_NW + i, 300.0f))
//                        statue->SetGoState(GO_STATE_READY);
//
//                // The statues are used in order to create Conductive water in all 4 corners before wipe.
//                statueUsed = 0;
//
//                // Thundering Throw target.
//                thunderingPlayer = NULL;
//                moguTrigger      = NULL;
//
//                if (instance)
//                    instance->SetData(DATA_JIN_ROKH_BREAKER_EVENT, NOT_STARTED);
//
//                _Reset();
//            }
//
//            void MoveInLineOfSight(Unit* who)
//            {
//                if (!introDone && me->IsWithinDistInMap(who, 40) && who->GetTypeId() == TYPEID_PLAYER)
//                {
//                    Talk(SAY_INTRO);
//                    introDone = true;
//                }
//            }
//
//            void EnterCombat(Unit* who)
//            {
//                Talk(SAY_AGGRO);
//
//                // Summon statue triggers.
//                for (uint8 i = 0; i < MAX_MOGU_STATUES; i++)
//                    if (Creature* trigger = me->SummonCreature(NPC_STATUE_TRIGGER, statueTriggerPlace[i], TEMPSUMMON_MANUAL_DESPAWN))
//                        trigger->SetFacingTo(triggerOrientations[i]);
//
//				events.ScheduleEvent(EVENT_THUNDERING_THROW, TIMER_THUNDERING_THROW_F);
//				events.ScheduleEvent(EVENT_STATIC_BURST, TIMER_STATIC_BURST_F);
//				events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING, TIMER_FOCUSED_LIGHTNING_F);
//				events.ScheduleEvent(EVENT_LIGHTNING_STORM_JUMP, TIMER_LIGHTNING_STORM_JUMPF);
//
//                if (IsHeroic())
//                    events.ScheduleEvent(EVENT_IONIZATION, TIMER_IONIZATION_F);
//
//				events.ScheduleEvent(EVENT_BERSERK, TIMER_BERSERK);
//
//                if (instance)
//                {
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                    instance->SetData(DATA_JIN_ROKH_BREAKER_EVENT, IN_PROGRESS);
//                }
//
//                _EnterCombat();
//            }
//
//			void EnterEvadeMode()
//            {
//                me->AddUnitState(UNIT_STATE_EVADE);
//
//                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
//                if (!PlayerList.isEmpty())
//                {
//                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                    {
//                        if (Player* player = i->getSource())
//                        {
//                            player->RemoveAurasDueToSpell(SPELL_FOCUSED_LIGHTNING_FIX);
//                            player->RemoveAurasDueToSpell(SPELL_FLUIDITY);
//                            player->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_WATER);
//                            player->RemoveAurasDueToSpell(SPELL_ELECTRIFIED_WATERS);
//                        }
//                    }
//                }
//
//                DespawnSummon(NPC_FOCUSED_LIGHTNING);
//                DespawnSummon(NPC_LIGHTNING_FISSURE);
//
//                me->RemoveAllAuras();
//                Reset();
//                me->DeleteThreatList();
//                me->CombatStop(true);
//                me->GetMotionMaster()->MovementExpired();
//                me->GetMotionMaster()->MoveTargetedHome();
//
//                if (instance)
//                {
//                    instance->SetData(DATA_JIN_ROKH_BREAKER_EVENT, FAIL);
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
//                }
//
//                _EnterEvadeMode();
//            }
//
//            void JustReachedHome()
//            {
//                me->ClearUnitState(UNIT_STATE_EVADE);
//
//                _JustReachedHome();
//            }
//
//            void JustSummoned(Creature* summon)
//            {
//                summons.Summon(summon);
//				summon->setActive(true);
//
//				if (me->isInCombat())
//					summon->SetInCombatWithZone();
//            }
//
//            void KilledUnit(Unit* victim)
//            {
//                if (victim->GetTypeId() == TYPEID_PLAYER)
//                    Talk(SAY_KILL);
//            }
//
//            void JustDied(Unit* killer)
//            {
//                Talk(SAY_DEATH);
//
//                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
//                if (!PlayerList.isEmpty())
//                {
//                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                    {
//                        if (Player* player = i->getSource())
//                        {
//                            player->RemoveAurasDueToSpell(SPELL_FOCUSED_LIGHTNING_FIX);
//                            player->RemoveAurasDueToSpell(SPELL_FLUIDITY);
//                            player->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_WATER);
//                            player->RemoveAurasDueToSpell(SPELL_ELECTRIFIED_WATERS);
//                        }
//                    }
//                }
//
//                DespawnSummon(NPC_FOCUSED_LIGHTNING);
//                DespawnSummon(NPC_LIGHTNING_FISSURE);
//
//                summons.DespawnAll();
//                thunderingPlayer = NULL;
//
//                if (instance)
//                {
//                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//                    instance->SetData(DATA_JIN_ROKH_BREAKER_EVENT, DONE);
//                }
//
//                _JustDied();
//            }
//
//            void DespawnSummon(uint32 entry)
//            {
//                std::list<Creature*> summonsList;
//                GetCreatureListWithEntryInGrid(summonsList, me, entry, 200.0f);
//                if (!summonsList.empty())
//                    for (std::list<Creature*>::iterator summs = summonsList.begin(); summs != summonsList.end(); summs++)
//                        (*summs)->DespawnOrUnsummon();
//            }
//
//            void UpdateAI(uint32 const diff)
//            {
//                if (!UpdateVictim() || !CheckInRoom() || me->HasUnitState(UNIT_STATE_CASTING))
//                    return;
//
//                if (instance && instance->IsWipe())
//                {
//                    EnterEvadeMode();
//                    return;
//                }
//
//                events.Update(diff);
//
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                        case EVENT_THUNDERING_THROW:
//                            Talk(SAY_THUNDERING_THROW);
//                            Talk(ANN_THUNDERING_THROW);
//                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f, true))
//                            {
//                                DoCast(target, SPELL_THUNDERING_THROW);
//                                thunderingPlayer = target;
//                            }
//				            events.ScheduleEvent(EVENT_THUNDERING_THROW_TOSS, TIMER_THUNDERING_THROW_TOSS);
//				            events.ScheduleEvent(EVENT_THUNDERING_THROW, TIMER_THUNDERING_THROW_S);
//                            break;
//
//                        case EVENT_THUNDERING_THROW_TOSS:
//                        {
//                            if (thunderingPlayer)
//                            {
//                                thunderingPlayer->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);
//                                thunderingPlayer->RemoveAurasDueToSpell(SPELL_THUNDERING_THROW);
//                                thunderingPlayer->RemoveAurasDueToSpell(SPELL_THUNDERING_THROW_GRAB);
//                                if (me->HasAura(SPELL_RIDE_VEHICLE))
//                                    me->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);
//                                // Get the statue trigger to perform the actions.
//                                std::list<Creature*> triggerList;
//                                GetCreatureListWithEntryInGrid(triggerList, me, NPC_STATUE_TRIGGER, 250.0f);
//                                if (!triggerList.empty())
//                                for (std::list<Creature*>::iterator statueTrigger = triggerList.begin(); statueTrigger != triggerList.end(); statueTrigger++)
//                                {
//                                    if ((*statueTrigger)->GetPositionX() == statueTriggerPlace[statueUsed].GetPositionX() && 
//                                        (*statueTrigger)->GetPositionY() == statueTriggerPlace[statueUsed].GetPositionY())
//                                    {
//                                        (*statueTrigger)->AI()->DoAction(ACTION_STATUE_WATER);
//                                        // Activate and "brake" statue.
//                                        if (GameObject* statue = me->FindNearestGameObject(GO_MOGU_FOUNTAIN_NW + statueUsed, 300.0f))
//                                            statue->SetGoState(GO_STATE_ACTIVE);
//                                        // Spell doesn't work. Throw player at statue.
//                                        thunderingPlayer->GetMotionMaster()->MoveJump(statueThrowPlace[statueUsed].GetPositionX(), statueThrowPlace[statueUsed].GetPositionY(), statueThrowPlace[statueUsed].GetPositionZ(), 25.0f, 25.0f);
//                                        // Summon Conductive Water (by position, not spell).
//                                        me->SummonCreature(NPC_CONDUCTIVE_WATER, waterSummonPlace[statueUsed], TEMPSUMMON_MANUAL_DESPAWN);
//                                        moguTrigger = (*statueTrigger);
//                                        // Select next statue.
//                                        if (statueUsed < 3)
//                                            statueUsed++;
//                                        else
//                                            statueUsed = 0;
//                                        break; // Break the loop.
//                                    }
//                                }
//                                events.ScheduleEvent(EVENT_THUNDERING_THROW_DMG, TIMER_THUNDERING_THROW_DMG);
//                            }
//                            break;
//                        }
//
//                        case EVENT_THUNDERING_THROW_DMG:
//                            if (thunderingPlayer && moguTrigger)
//                            {
//                                moguTrigger->CastSpell(thunderingPlayer, SPELL_THUNDERING_THROW_PLR, true);
//                                moguTrigger->CastSpell(thunderingPlayer, SPELL_THUNDERING_THROW_AOE, true);
//                                thunderingPlayer = NULL;
//                                moguTrigger      = NULL;
//                            }
//                            break;
//
//                        case EVENT_STATIC_BURST:
//                            Talk(SAY_STATIC_BURST);
//                            DoCastVictim(SPELL_STATIC_BURST);
//				            events.ScheduleEvent(EVENT_STATIC_BURST, TIMER_STATIC_BURST_S);
//                            break;
//
//                        case EVENT_FOCUSED_LIGHTNING:
//                            Talk(SAY_FOCUSED_LIGHTNING);
//                            DoCast(me, SPELL_FOCUSED_LIGHTNING);
//				            events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING, TIMER_FOCUSED_LIGHTNING_S);
//                            break;
//
//                        case EVENT_LIGHTNING_STORM_JUMP:
//                            Talk(SAY_LIGHTNING_STORM);
//                            Talk(ANN_LIGHTNING_STORM);
//                            me->GetMotionMaster()->MoveJump(middlePos.GetPositionX(), middlePos.GetPositionY(), middlePos.GetPositionZ(), 15.0f, 15.0f);
//				            events.ScheduleEvent(EVENT_LIGHTNING_STORM, TIMER_LIGHTNING_STORM);
//				            events.ScheduleEvent(EVENT_LIGHTNING_STORM_JUMP, TIMER_LIGHTNING_STORM_JUMPS);
//                            break;
//
//                        case EVENT_LIGHTNING_STORM:
//                        {
//                            // Remove Pouring Water visual from triggers.
//                            std::list<Creature*> triggerList;
//                            GetCreatureListWithEntryInGrid(triggerList, me, NPC_STATUE_TRIGGER, 200.0f);
//                            if (!triggerList.empty())
//                            for (std::list<Creature*>::iterator statueTrigger = triggerList.begin(); statueTrigger != triggerList.end(); statueTrigger++)
//                                if ((*statueTrigger)->HasAura(SPELL_CONDUCTIVE_VISUAL_2))
//                                    (*statueTrigger)->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_VISUAL_2);
//                            // Remove Conductive Water visual from the npc's and add the Electrified one.
//                            std::list<Creature*> waterList;
//                            GetCreatureListWithEntryInGrid(waterList, me, NPC_CONDUCTIVE_WATER, 200.0f);
//                            if (!waterList.empty())
//                            for (std::list<Creature*>::iterator water = waterList.begin(); water != waterList.end(); water++)
//                            {
//                                if ((*water)->HasAura(SPELL_CONDUCTIVE_VISUAL))
//                                {
//                                    (*water)->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_VISUAL);
//                                    (*water)->AddAura(SPELL_CONDUCTIVE_VISUAL_3, (*water));
//                                }
//                            }
//                            me->AddAura(SPELL_LIGHTNING_STORM_VIS, me);
//                            if (AuraPtr visual = me->GetAura(SPELL_LIGHTNING_STORM_VIS))
//                                visual->SetMaxDuration(15000);
//                            me->AddAura(SPELL_LIGHTNING_STORM_VIS2, me);
//                            if (AuraPtr visual2 = me->GetAura(SPELL_LIGHTNING_STORM_VIS2))
//                                visual2->SetMaxDuration(15000);
//                            DoCast(me, SPELL_LIGHTNING_STORM);
//                            break;
//                        }
//
//                        case EVENT_IONIZATION:
//                        {
//                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
//                            if (!PlayerList.isEmpty())
//                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                                    if (Player* player = i->getSource())
//                                        if (player->GetRoleForGroup(player->GetSpecializationId(player->GetActiveSpec())) != ROLES_TANK)
//                                            me->AddAura(SPELL_IONIZATION_AURA, player);
//                            events.ScheduleEvent(EVENT_IONIZATION, TIMER_IONIZATION_S);
//                            break;
//                        }
//
//                        case EVENT_BERSERK:
//                            Talk(SAY_BERSERK);
//				            DoCast(me, SPELL_BERSERK);
//                            break;
//
//                        default: break;
//                    }
//                }
//
//                DoMeleeAttackIfReady();
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new boss_jin_rokh_breakerAI(creature);
//        }
//};
//
//class npc_mogu_statue_trigger : public CreatureScript
//{
//    public:
//        npc_mogu_statue_trigger() : CreatureScript("npc_mogu_statue_trigger") { }
//
//        struct npc_mogu_statue_trigger_AI : public ScriptedAI
//        {
//            npc_mogu_statue_trigger_AI(Creature* creature) : ScriptedAI(creature) { }
//
//            void IsSummonedBy(Unit* /*summoner*/)
//            {
//                Reset();
//            }
//
//            void Reset()
//            {
//                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
//                me->SetReactState(REACT_PASSIVE);
//            }
//
//            void DoAction(int32 const action)
//            {
//                switch (action)
//                {
//                    case ACTION_STATUE_WATER:
//                        me->AddAura(SPELL_CONDUCTIVE_VISUAL_2, me);
//                        break;
//
//                    default: break;
//                }
//            };
//
//            void JustSummoned(Creature* summon)
//            {
//				summon->setActive(true);
//
//				if (me->isInCombat())
//					summon->SetInCombatWithZone();
//            }
//
//            void UpdateAI(uint32 const diff) { }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_mogu_statue_trigger_AI(creature);
//        }
//};
//
//class npc_conductive_water : public CreatureScript
//{
//    public:
//        npc_conductive_water() : CreatureScript("npc_conductive_water") { }
//
//        struct npc_conductive_water_AI : public ScriptedAI
//        {
//            npc_conductive_water_AI(Creature* creature) : ScriptedAI(creature) { }
//
//            EventMap events;
//            float waterRadius; // used to determine the current radius of the Conductive Water. May grow to 11 scale * 4 = 44 yards.
//
//            void IsSummonedBy(Unit* /*summoner*/)
//            {
//                Reset();
//                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
//                me->AddAura(SPELL_CONDUCTIVE_VISUAL, me);
//                me->AddAura(SPELL_CONDUCTIVE_WATER_GROW, me);
//                me->SetReactState(REACT_PASSIVE);
//                waterRadius = me->GetObjectScale() * 4.0f; // 4 yards original radius.
//            }
//
//            void Reset()
//            {
//                events.Reset();
//                events.ScheduleEvent(EVENT_BUFF_DEBUFF, TIMER_BUFF_DEBUFF);
//            }
//
//            void UpdateAI(uint32 const diff)
//            {
//                events.Update(diff);
//
//                while(uint32 eventId = events.ExecuteEvent())
//                {
//                    switch(eventId)
//                    {
//                        case EVENT_BUFF_DEBUFF:
//                        {
//                            // Check the scale.
//                            waterRadius = me->GetObjectScale() * 4.0f; // Scale is adjusted by spell.
//                            // Add the auras to the players in the water.
//                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
//                            if (!PlayerList.isEmpty())
//                            {
//                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                                {
//                                    if (Player* player = i->getSource())
//                                    {
//                                        if (player->IsWithinDistInMap(me, waterRadius))
//                                        {
//                                            me->AddAura(SPELL_CONDUCTIVE_WATER, player);
//                                            // Add Fluidity or Electrified Waters depending on the visual.
//                                            if (me->HasAura(SPELL_CONDUCTIVE_VISUAL))
//                                                me->AddAura(SPELL_FLUIDITY, player);
//                                            else if (me->HasAura(SPELL_CONDUCTIVE_VISUAL_3))
//                                                me->AddAura(SPELL_ELECTRIFIED_WATERS, player);
//                                        }
//                                        else
//                                        {
//                                            if (player->HasAura(SPELL_CONDUCTIVE_WATER, me->GetGUID()))
//                                                player->RemoveAurasDueToSpell(SPELL_CONDUCTIVE_WATER, me->GetGUID());
//                                            if (player->HasAura(SPELL_FLUIDITY, me->GetGUID()))
//                                                player->RemoveAurasDueToSpell(SPELL_FLUIDITY, me->GetGUID());
//                                            if (player->HasAura(SPELL_ELECTRIFIED_WATERS, me->GetGUID()))
//                                                player->RemoveAurasDueToSpell(SPELL_ELECTRIFIED_WATERS, me->GetGUID());
//                                        }
//                                    }
//                                }
//                            }
//                            events.ScheduleEvent(EVENT_BUFF_DEBUFF, TIMER_BUFF_DEBUFF);
//                            break;
//                        }
//
//                        default: break;
//                    }
//                }
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_conductive_water_AI(creature);
//        }
//};
//
//class npc_focused_lightning : public CreatureScript
//{
//    public:
//        npc_focused_lightning() : CreatureScript("npc_focused_lightning") { }
//
//        struct npc_focused_lightningAI : public ScriptedAI
//        {
//            npc_focused_lightningAI(Creature* creature) : ScriptedAI(creature) { }
//
//            EventMap events;
//            Unit* playerTarget;
//            bool exploded;
//
//            void IsSummonedBy(Unit* summoner)
//            {
//                Reset();
//                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//                // me->AddAura(SPELL_FOCUSED_LIGHTNING_SPD, me);
//                me->AddAura(SPELL_FOCUSED_LIGHTNING_VIS, me);
//                me->SetReactState(REACT_PASSIVE);
//
//                if (!playerTarget)
//                {
//                    if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 150.0f, true))
//                    {
//                        summoner->ToCreature()->AI()->Talk(ANN_FOCUSED_LIGHTNING, target->GetGUID());
//                        target->AddAura(SPELL_FOCUSED_LIGHTNING_FIX, target);
//                        me->Attack(target, false);
//                        me->GetMotionMaster()->MoveChase(target);
//                        playerTarget = target;
//                    }
//                }
//
//                events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING_DMG, TIMER_FOCUSED_LIGHTNING_DMG);
//            }
//
//            void Reset()
//            {
//                playerTarget = NULL;
//                exploded = false;
//
//                events.Reset();
//            }
//
//            void JustSummoned(Creature* summon)
//            {
//				summon->setActive(true);
//
//				if (me->isInCombat())
//					summon->SetInCombatWithZone();
//            }
//
//            void UpdateAI(uint32 const diff)
//            {
//                // Check for player in range for normal Detonation.
//                if (!exploded && playerTarget)
//                {
//                    if (playerTarget->IsWithinDistInMap(me, 2.0f))
//                    {
//                        playerTarget->RemoveAurasDueToSpell(SPELL_FOCUSED_LIGHTNING_FIX);
//                        me->CastSpell(playerTarget, SPELL_FOCUSED_LIGHTNING_DET, true);
//                        me->SummonCreature(NPC_LIGHTNING_FISSURE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//                        me->DespawnOrUnsummon(200);
//                        exploded = true;
//                    }
//                }
//
//                // Check for Electrified Waters near for Violent Detonation.
//                if (!exploded)
//                {
//                    if (Creature* water = me->FindNearestCreature(NPC_CONDUCTIVE_WATER, 44.0f, true))
//                    {
//                        if (water->HasAura(SPELL_CONDUCTIVE_VISUAL_3))
//                        {
//                            if (me->IsWithinDistInMap(water, CAST_AI(npc_conductive_water::npc_conductive_water_AI, water->ToCreature()->AI())->waterRadius))
//                            {
//                                DoCast(me, SPELL_FL_VIOLENT_DETONATION);
//                                me->DespawnOrUnsummon(200);
//                                exploded = true;
//                            }
//                        }
//                    }
//                }
//
//                events.Update(diff);
//
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                        case EVENT_FOCUSED_LIGHTNING_DMG:
//                            DoCast(me, SPELL_FOCUSED_LIGHTNING_DMG);
//                            events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING_DMG, TIMER_FOCUSED_LIGHTNING_DMG);
//                            break;
//                    }
//                }
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_focused_lightningAI(creature);
//        }
//};
//
//class npc_lightning_fissure : public CreatureScript
//{
//    public:
//        npc_lightning_fissure() : CreatureScript("npc_lightning_fissure") { }
//
//        struct npc_lightning_fissureAI : public ScriptedAI
//        {
//            npc_lightning_fissureAI(Creature* creature) : ScriptedAI(creature) { }
//
//            EventMap events;
//            bool casted;
//
//            void IsSummonedBy(Unit* /*summoner*/)
//            {
//                Reset();
//                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//                me->AddAura(SPELL_LIGHTNING_FISSURE_VIS, me);
//                me->AddAura(SPELL_LIGHTNING_FISSURE_DMG, me);
//                me->SetSpeed(MOVE_RUN, 1.1f);
//                me->SetSpeed(MOVE_WALK, 1.2f);
//                me->GetMotionMaster()->MoveRandom(50.0f);
//                me->SetReactState(REACT_PASSIVE);
//                events.ScheduleEvent(EVENT_FISSURE_SEARCH, 1000);
//            }
//
//            void Reset()
//            {
//                events.Reset();
//                casted = false;
//            }
//
//            void UpdateAI(uint32 const diff)
//            {
//                events.Update(diff);
//
//                while (uint32 eventId = events.ExecuteEvent())
//                {
//                    switch (eventId)
//                    {
//                        case EVENT_FISSURE_SEARCH:
//                            if (!casted && me->FindNearestCreature(NPC_FOCUSED_LIGHTNING, 3.0f, true))
//                            {
//                                me->CastSpell(me, SPELL_IMPLOSION, true);
//                                me->DespawnOrUnsummon(200);
//                                casted = true;
//                            }
//                            events.ScheduleEvent(EVENT_FISSURE_SEARCH, 300);
//                            break;
//                    }
//                }
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const
//        {
//            return new npc_lightning_fissureAI(creature);
//        }
//};
//
//// Thundering Throw (main cast spell) - 137180
//class spell_thundering_throw : public SpellScriptLoader
//{
//    public:
//        spell_thundering_throw() : SpellScriptLoader("spell_thundering_throw") { }
//
//        class spell_thundering_throw_SpellScript : public SpellScript
//        {
//            PrepareSpellScript(spell_thundering_throw_SpellScript);
//
//            void HandleDummy(SpellEffIndex /*effIndex*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetHitUnit();
//
//                if (!caster || !target)
//                    return;
//
//                caster->CastSpell(target, SPELL_THUNDERING_THROW_GRAB, true);
//            }
//
//            void Register()
//            {
//                OnEffectHitTarget += SpellEffectFn(spell_thundering_throw_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//            }
//        };
//
//        SpellScript* GetSpellScript() const
//        {
//            return new spell_thundering_throw_SpellScript();
//        }
//};
//
//// Thundering Throw (vehicle grab spell) - 137161
//class spell_thundering_throw_grab : public SpellScriptLoader
//{
//    public:
//        spell_thundering_throw_grab() : SpellScriptLoader("spell_thundering_throw_grab") { }
//
//        class spell_thundering_throw_grab_SpellScript : public SpellScript
//        {
//            PrepareSpellScript(spell_thundering_throw_grab_SpellScript);
//
//            void HandleScript(SpellEffIndex /*effIndex*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetHitUnit();
//
//                if (!caster || !target)
//                    return;
//
//                target->CastSpell(caster, SPELL_RIDE_VEHICLE, true);
//            }
//
//            void Register()
//            {
//                OnEffectHitTarget += SpellEffectFn(spell_thundering_throw_grab_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//            }
//        };
//
//        SpellScript* GetSpellScript() const
//        {
//            return new spell_thundering_throw_grab_SpellScript();
//        }
//};
//
//// Thundering Throw (AOE) - 137167
//class spell_thundering_throw_aoe : public SpellScriptLoader
//{
//    public:
//        spell_thundering_throw_aoe() : SpellScriptLoader("spell_thundering_throw_aoe") { }
//
//        class spell_thundering_throw_aoe_SpellScript : public SpellScript
//        {
//            PrepareSpellScript(spell_thundering_throw_aoe_SpellScript);
//
//            void HandleHit(SpellEffIndex /*effIndex*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetHitUnit();
//
//                if (!caster || !target)
//                    return;
//
//                if (target = CAST_AI(boss_jin_rokh_breaker::boss_jin_rokh_breakerAI, GetCaster()->ToCreature()->AI())->thunderingPlayer)
//                    return;
//
//                caster->AddAura(SPELL_THUNDERING_THROW_STUN, target);
//            }
//
//            void CalculateDamage(SpellEffIndex /*effIndex*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetHitUnit();
//
//                if (!caster || !target)
//                    return;
//
//                if (target = CAST_AI(boss_jin_rokh_breaker::boss_jin_rokh_breakerAI, GetCaster()->ToCreature()->AI())->thunderingPlayer)
//                    SetHitDamage(0);
//            }
//
//            void Register()
//            {
//                OnEffectHitTarget += SpellEffectFn(spell_thundering_throw_aoe_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//                OnEffectHitTarget += SpellEffectFn(spell_thundering_throw_aoe_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//            }
//        };
//
//        SpellScript* GetSpellScript() const
//        {
//            return new spell_thundering_throw_aoe_SpellScript();
//        }
//};
//
//// Static Burst 137162.
//class spell_static_burst : public SpellScriptLoader
//{
//    public:
//        spell_static_burst() : SpellScriptLoader("spell_static_burst") { }
//
//        class spell_static_burst_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_static_burst_AuraScript);
//
//            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//            {
//                Unit* caster = GetCaster();
//
//                if (!caster || !caster->getVictim())
//                    return;
//
//                caster->CastCustomSpell(SPELL_STATIC_WOUND, SPELLVALUE_AURA_STACK, 10, caster->getVictim());
//            }
//
//            void Register()
//            {
//                OnEffectRemove += AuraEffectRemoveFn(spell_static_burst_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_static_burst_AuraScript();
//        }
//};
//
//// Static Wound 138349.
//class spell_static_wound : public SpellScriptLoader
//{
//    public:
//        spell_static_wound() : SpellScriptLoader("spell_static_wound") { }
//
//        class spell_static_wound_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_static_wound_AuraScript)
//
//            void OnPeriodic(constAuraEffectPtr /*aurEff*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetTarget();
//
//                if (!caster || !target)
//                    return;
//
//                // Deal damage to the player and to the other players and decrease a stack.
//                if (AuraPtr dot = target->GetAura(SPELL_STATIC_WOUND))
//                {
//                    int32 stacks = dot->GetStackAmount();
//
//                    // Tank damage.
//                    const SpellInfo* woundSpell = sSpellMgr->GetSpellInfo(SPELL_STATIC_WOUND, caster->GetMap()->GetDifficulty());
//                    caster->DealDamage(target, woundSpell->Effects[0].BasePoints * stacks, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, woundSpell);
//
//                    // All other players damage.
//                    const SpellInfo* woundAllSpell = sSpellMgr->GetSpellInfo(SPELL_STATIC_WOUND_DMG, caster->GetMap()->GetDifficulty());
//                    Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
//                    if (!PlayerList.isEmpty())
//                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                            if (Player* player = i->getSource())
//                                if (player != target->ToPlayer())
//                                    caster->DealDamage(player, (woundSpell->Effects[0].BasePoints + 1000) / 3, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, woundAllSpell);
//
//                    // Stack handling.
//                    if (stacks > 1)
//                        dot->SetStackAmount(stacks - 1);
//                    else
//                        target->RemoveAurasDueToSpell(SPELL_STATIC_WOUND);
//                }
//            }
//
//            void Register()
//            {
//                OnEffectPeriodic += AuraEffectPeriodicFn(spell_static_wound_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_static_wound_AuraScript();
//        }
//};
//
//// Focus Lightning (main cast spell) - 137399.
//class spell_focused_lightning : public SpellScriptLoader
//{
//    public:
//        spell_focused_lightning() : SpellScriptLoader("spell_focused_lightning") { }
//
//        class spell_focused_lightning_SpellScript : public SpellScript
//        {
//            PrepareSpellScript(spell_focused_lightning_SpellScript);
//
//            void HandleDummy(SpellEffIndex /*effIndex*/)
//            {
//                Unit* caster = GetCaster();
//
//                if (!caster)
//                    return;
//
//                caster->SummonCreature(NPC_FOCUSED_LIGHTNING, caster->GetPositionX() + 5.0f, caster->GetPositionY(), caster->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//            }
//
//            void Register()
//            {
//                OnEffectHitTarget += SpellEffectFn(spell_focused_lightning_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//            }
//        };
//
//        SpellScript* GetSpellScript() const
//        {
//            return new spell_focused_lightning_SpellScript();
//        }
//};
//
//// Lightning Storm (Heroic dummy damage) - 140819
//class spell_lightning_storm_heroic_dummy : public SpellScriptLoader
//{
//    public:
//        spell_lightning_storm_heroic_dummy() : SpellScriptLoader("spell_lightning_storm_heroic_dummy") { }
//
//        class spell_lightning_storm_heroic_dummy_SpellScript : public SpellScript
//        {
//            PrepareSpellScript(spell_lightning_storm_heroic_dummy_SpellScript);
//
//            void HandleDummy(SpellEffIndex /*effIndex*/)
//            {
//                Unit* target = GetHitUnit();
//
//                if (!target)
//                    return;
//
//                Unit* caster = target->FindNearestCreature(BOSS_JINROKH_BREAKER, 200.0f, true) ? target->FindNearestCreature(BOSS_JINROKH_BREAKER, 200.0f, true)->ToUnit() : NULL;
//
//                if (!caster)
//                    return;
//
//                caster->CastSpell(caster, SPELL_LIGHTNING_STRIKE_VIS, true);
//
//                // Only happens on Heroic difficulties.
//                if (!caster->GetMap()->IsHeroic())
//                    return;
//
//                if (urand(1, 4) == 1) // 25 % chance means 1 in 4 ticks and should comply with the restrictions, we don't want to kill everybody :).
//                {
//                    caster->CastSpell(target, SPELL_LIGHTNING_STORM_H_DMG, true);
//
//                    // Cast Lightning Diffusion on players in the back of the target in a line.
//                    Map::PlayerList const &PlayerList = caster->GetMap()->GetPlayers();
//                    if (!PlayerList.isEmpty())
//                    {
//                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
//                        {
//                            if (Player* player = i->getSource())
//                            {
//                                if (player->ToUnit()->isInBack(target))
//                                {
//                                    caster->CastSpell(player, SPELL_LIGHTNING_DIFFUSION, true);
//                                    break; // break the loop, the spell is chained.
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//
//            void Register()
//            {
//                OnEffectHitTarget += SpellEffectFn(spell_lightning_storm_heroic_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//            }
//        };
//
//        SpellScript* GetSpellScript() const
//        {
//            return new spell_lightning_storm_heroic_dummy_SpellScript();
//        }
//};
//
//// Ionization aura 138732.
//class spell_ionization : public SpellScriptLoader
//{
//    public:
//        spell_ionization() : SpellScriptLoader("spell_ionization") { }
//
//        class spell_ionization_AuraScript : public AuraScript
//        {
//            PrepareAuraScript(spell_ionization_AuraScript);
//
//            void OnRemove(constAuraEffectPtr /*aurEff*/, AuraEffectHandleModes /*mode*/)
//            {
//                Unit* caster = GetCaster();
//                Unit* target = GetTarget();
//
//                if (!caster || !target)
//                    return;
//
//                caster->CastSpell(target, SPELL_IONIZATION_DMG, false);
//            }
//
//            void Register()
//            {
//                OnEffectRemove += AuraEffectRemoveFn(spell_ionization_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
//            }
//        };
//
//        AuraScript* GetAuraScript() const
//        {
//            return new spell_ionization_AuraScript();
//        }
//};
//
//class npc_throneofthunder_teleporter : public CreatureScript
//{
//    public:
//        npc_throneofthunder_teleporter() : CreatureScript("npc_throneofthunder_teleporter") { }
//
//        bool OnGossipHello(Player* player, Creature* creature)
//        {
//            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Exit Throne of Thunder.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
//            player->SEND_GOSSIP_MENU(42915, creature->GetGUID());
//            return true;
//        }
//
//        bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
//        {
//            player->PlayerTalkClass->ClearMenus();
//
//            if (action == GOSSIP_ACTION_INFO_DEF + 1)
//            {
//                player->TeleportTo(1064, 7254.155f, 5025.962f, 76.164f, 2.364f);
//                player->CLOSE_GOSSIP_MENU();
//            }
//
//            return true;
//        }
//};
//
//void AddSC_boss_jin_rokh_breaker()
//{
//    new boss_jin_rokh_breaker();
//    new npc_mogu_statue_trigger();
//    new npc_conductive_water();
//    new npc_focused_lightning();
//    new npc_lightning_fissure();
//    new spell_thundering_throw();
//    new spell_thundering_throw_grab();
//    new spell_thundering_throw_aoe();
//    new spell_static_burst();
//    new spell_static_wound();
//    new spell_focused_lightning();
//    new spell_lightning_storm_heroic_dummy();
//    new spell_ionization();
//	new npc_throneofthunder_teleporter();
//}
