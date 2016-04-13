/* 
 * Copyright (C) 2014-2015 Warlegend-Project <http://www.warlegend-project.com> 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "throne_of_thunder.h"

/**************************************/
/* Some reasearches about the spells. */
/**************************************/

//=======================================================================
// Thundering Throw

/*
 *  Jin'Rokh throws his current target (me->GetVictim()) at a distant Mogu Statue
 * (the farthest from it's position); this breaks the statue (probably a gameobject), inflicts
 * 240k - 250k damages (Physical) to the target, and inflicts 190k - 210k damages (Nature) to all
 * players within 8 yards of the point of impact + stuns them.
 *
 *  Related spells:
 *      137167 => School Damage (Nature) in a 8 yards radius (190k - 210k 10 nm) (final phase of impact) (casted by player (TARGET_UNIT_SRC_AREA_ALLY)) // Casted by the player to aoe damage after impact
 *      137161 => Script Effect (43671), AA: Silence, AA: Pacify, AA: 321 (?), Dummy (200 yards)
 *      137173 => Jump Behind Target (TARGET_DEST_DEST) + Trigger Spell 137274 (No spell found ?!) // Works, maybe the one that sends the player on the statue ?
 *      137175 => Dummy (TARGET_UNIT_NEARBY_ENTRY) // Does nothing
 *      137371 => Stun for 5 seconds (final phase of impact) (casted by player (TARGET_UNIT_TARGET_ANY)) // Casted by the player to stun the others after impact
 *      140567 => Script Effect (56687), AA: Periodic Trigger Spell (140594, 2 seconds), AA: Periodic Trigger Spell (140606, 2 seconds) // Combined visuals
 *      140580 => Jump Behind Target (TARGET_DEST_NEARBY_ENTRY) + Trigger Spell 140595 // Does nothing actually
 *      140594 => AA: Dummy (TARGET_UNIT_CASTER) // Visual, like the caster is surrounded by lightnings
 *      140595 => Dummy (TARGET_UNIT_CASTER) // Does nothing
 *      140597 => Script Effect (TARGET_UNIT_CASTER) // Looks like a cast, maybe it send the whole event
 *      140605 => Dummy (30 yards) (TARGET_DEST_CASTER => TARGET_DEST_DEST_RANDOM) // Trigger visual of impact
 *      140606 => AA: Periodic Trigger Spell (140605) (TARGET_UNIT_CASTER) // Periodic trigger visual
 *      140612 => AA: Dummy (TRGET_UNIT_CASTER) // Does nothing
 *      137370 => School Damage (Physical) (240k - 250k) (TARGET_UNIT_TARGET_ANY)
 *
 *  Behaviour:
 *      140597 => Begin the cast and send the event (need SpellScript); caster (Jin'Rokh) selects a victim (GetCaster()->GetVictim()), then
 * selects a dest (the farthest mogu statue). The selected target then casts 137173 on this dest : it make him jump, and casts 137161 on himself
 * (silence him, trigger 140606 (140605) and 140594; we send an information to the statue to look for the distance with this player, and when it
 * is short enough, the selected target casts 137370 on himself, casts 137167 on himself (aoe damage), and in the handler of the 137167, all hit unit
 * cast 137371 on themselves.
 *
 *      Used spells : 137167, 137161, 137173, 137371, 140567, 140594, 140597, 140605, 140606, 137370
 *      Unused spells : 137175, 140580, 140595, 140612
 */


//=======================================================================
// Conductive Waters / Conduction (need tests)

/*
 *  After Thundering Throw destroys a statue, a pool of water pours forth (stalker). It increases healing done, damages done,
 * but also increases Nature damage taken by 80%. In addition, Jin'Rokh abilities behave differently when players stand in
 * Conductive Water.
 *
 *  Related Spells:
 *      138470 => Nature damage taken + 80% (TARGET_UNIT_TARGET_ANY) // Aura doesn't stay, need to be reapplied regularly
 *      137145 => Summon Conductive Water (targets not important) // // Okay
 *      137168 => AA: Dummy (40 yards) (visual ?) (on players) (TARGET_UNIT_SRC_AREA_ENTRY) // Don't know use
 *      137276 => Script Effect (137340)  (TARGET_UNIT_SUMMONER) // Don't know use
 *      137277 => AA: Dummy (CASTER) // Visual
 *      137340 => AA: Dummy (CASTER) // Water pouring forth the broken mogu statue
 *      137676 => AA: Periodic Trigger Spell (137694) (CASTER) // Okay
 *      137694 => AA: Mod Size % (11) (CASTER) // Okay
 *      137978 => AA: Dummy (CASTER) // Electric visual YEAH
 *      138568 => AA: Periodic Trigger Spell (138647) (CASTER) // Make lightnings appear arround
 *      138647 => Dummy (18 yards) (DEST_RADIUS) // A lightning appear somewhere in radius
 *      138002 => Fluidity // Doesn't stay on player, need to be reapplied regularly
 *
 *  Behaviour:
 *      137145 => Summon Conductive Water (CW); CW casts 137277 on itself (137340 on the statue), then 137676 to grow ; UPDATE AI to
 * apply 138470 and 138002 on players. When Electrified, use 137978, and upon electrification use 138568 (PTS 138647) to show it is
 * electric (maybe need to be cast regularly too).
 *
 *      Used spells : 134870, 137145, 137277, 137340, 137676, 137694, 137978, 138568, 138647, 138002
 *      Unused spells : 137168, 137276
 */


//=======================================================================
// Static Wound

/*
 *  After performing Static Burst, Jin'Rokh leaves 10 stack of Static Wound on all players. When a player with static burst charges
 * takes melee damage, static wound ticks for 20k damages (10 nm) and a third of this amount is applied to other players. In addition,
 * players lose a stack of Static Wound every 3 seconds.
 *
 *  Need Unit::HandleDummyAuraProc and AuraScript to remove charges.
 */


//=======================================================================
// Focused lightning (needs test)

/*
 *  Jin'Rokh summons an orb of Focused Lightning. The orb fixates upon a player, and travel the room towards it. When it reaches the player,
 * it detonates, inflicting 170k - 180k damages to this player, and all players within 8 yards; if the hit player is buffer with Conductive
 * Water, the spell inflicts 170k - 180k damages to all players bufer; if player is not, a Lightning Fissure is created. While travelling, the
 * orb pulses for 38k - 42k damages every 0.5 seconds.
 *
 *  Related spells:
 *      137422 => AA: Control of Pet ? // THE FUCK ?
 *      137194 => Dummy to all enemies within 200 yards
 *      137389 => AA: Periodic Trigger Spell (137437) // Works
 *      137425 => AA: Dummy (CASTER) // Visual of the orb
 *      137429 => Dummy to all entries in range 5 yards
 *      137437 => AA: Increase run speed % (15) (caster) // Works
 *      139203 => Dummy to all enemies within 200 yards
 *      139209 => Dummy to all enemies within 5 yards
 *      139233 => AA: Dummy (caster) // Another visual for the orb
 *      139210 => School Damage (Nature) 38k - 42k (TARGET_UNIT_TARGET_ANY) // Works (can target other)
 *      137423 => School Damage (Nature) 38k - 42k (TARGET_UNIT_TARGET_ANY)
 *      139211 => School Damage (Nature) 142k - 157k (8 yards) // Works
 *      137374 => School Damage (Nature) 170k - 180k (8 yards) // Works
 *      137530 => School Damage (Nature) 170k - 180k (8 yards) CONDUCTION VERSION // Works
 *      138990 => School Damage (Nature) 712k - 187k (8 yards) ELECTRIC WATER VERSION // Wierd
 *      139206 => Summon Focused Lightning // Works
 *
 *  Behaviour :
 *      139206 => Summon orb; casts 139233 / 137425 for visual, then 137389 (PTS 137437) for speed; every 0.5s, casts 139210 / 137423; when
 * reaches player, casts 139211 / 137374 / 137530 / 138990 according to the situation.
 *
 *      Used spells: 137389, 137425, 137437, 139233, 139210, 137423, 139211, 137374, 137530, 138990, 139206
 *      Unused spells: 137194, 137429, 139203, 139203
 */


//=======================================================================
// Lightning Fissure (needs some tests)

/*
 *  When an Ord of Focused Lightning detonates out of Conductive Waters, a Lightning Fissure appears on the ground. The Lightning Fissure
 * radiates for 47k to 52k damages every 1 second to player within 5 yards; if it comes in contact with Conductive Water, it disappears,
 * inflicting 71k to 78k damages to all players in Conductive Water.
 *
 *  Related Spells:
 *      137479 => Summon a Lightning Fissure at a random dest (mob)
 *      139464 => Summon a Lightning Fissure at a random dest in radius (guardian)
 *      137484 => AA: PTS (137485) (TARGET_UNIT_TARGET_ANY ?!) // Works, but need change target
 *      137485 => School Damage (Nature) 47k - 52k (CASTER ?!) // Works but need change target or handle it wierdly
 *      140031 => Same as 137484 (139467) // Same
 *      139467 => Same as 137485 // Same
 *      137480 => AA: Dummy (visual ?), Spawn Effect ?! // Visual
 *      138133 => School Damage (Nature) 71k - 78k 100 yards CONDUCTION VERSION // Works
 *      139468 => ScriptEffect (139464) // Unknown
 *
 *  Behaviour:
 *      137479 => Spawn; then cast 137480; UPDATE AI to find players and cast 137485 on them (by them); when conductive waters hit the fissure, cancel_state
 * 138133.
 */


//=======================================================================
// Implosion

/*
 *
 *  If a Focused Lightning crosses the Lightning Fissure, the Lighting Fissure Implose, inflicting 237k to 262k damages to all players, increasing
 * damages taken from Implosion by 10%.
 *  If a Focused Lightning comes in contact with Electrified Waters, it violently implode, inflicting 712k to 787k damages to all players within 8 yards.
 *
 *  Related Spells:
 *      137507 => School Damage (Nature) 237k - 262k (crossing Focused Lightning)
 *      138990 => School Damage (Nature) 712k - 787k (contacting Electrified Waters)
 */


//=======================================================================
// Lightning Storm

/*
 *  Jin'Rokh commands a fierce Lightning Storm; it inflicts 8k - 9k damages / s to all players for 15 seconds. This electrifies all the Conductive Water
 * turning them into Electrified Waters.
 *  In Heroic Mode, Lightning Strikes appear through the room. They strike random location, inflicting 46k - 49k damages; also, they diffuse, inflicting
 * 23k - 24k damages to all players in a line
 *
 *  Related Spells (Lightning Storm):
 *      // Npc Abilities
 *      137313 => AA: PTS (137261), (HM) AA: PTS (140819)
 *
 *      // Uncategorized spells
 *      137261 => School Damage (Nature) (need SpellScript)
 *      137283 => Summon NPC (Not usefull)
 *      137966 => Visual, like the target is a micro storm
 *      138192 => Visual, lightning striking everywhere (real visual of the spell)
 *      138193 => Same as 138192
 *      138194 => Same as 138192
 *      138234 => Periodic damages // Why ?
 *      138299 => Visual, a lightning column surrounds the caster
 *      140549 => Periodic trigger 140551
 *      140551 => Visual of lightnings (target dest) where we can summon stalkers for Lightning Strike
 *      140555 => Single pool under the caster
 *      140560 => Periodic damages
 *      140774 => Summon NPC
 *      140775 => Shadowy visual on the ground
 *      140808 => Lightning visual near caster
 *      140811 => Same as 140808
 *
 *  Behaviour (not sure cause it is extremely hard to understand all those spells):
 *      137313 => Trigger 137261 for damages ; right after, apply the aura 140549 on Jin'Rokh (visual of the storm); if Heroic, use the handler of 140551 to
 * summon creatures where lightning lands, and make them cast 138299, and after the cast is completed, make them cast 137647 (aoe damage 4 yards); after that
 * summon 6 stalkers and make them go in random direction casting 137905 on players nearby (or 138273).
 */

/**************************************/
/********* Jin'Rokh the Breaker *******/
/**************************************/

//=======================================================================
// Enums

enum eJinRokhSpells
{
    // Thundering Throw
    SPELL_THUNDERING_THROW                  = 140597, // Need SpellScript to handle ScriptEffect
    SPELL_THUNDERING_THROW_JUMP             = 137173, // Casted by player on a statue
    SPELL_THUNDERING_THROW_SILENCE          = 137161, // Silence, visuals
    SPELL_THUNDERING_TRHOW_FLY_VISUAL       = 140594, // Visual in flight
    SPELL_THUNDERING_THROW_HIT_DAMAGE       = 137370, // Damage on hit statue
    SPELL_THUNDERING_THROW_HIT_AOE_DAMAGE   = 137167, // AOE Damage on hit statue
    SPELL_THUNDERING_THROW_STUN             = 137371, // Stun after aoe damage on hit statue
    SPELL_THUNDERING_THROW_IMPACT_VISUAL    = 140606, // Visual of the impact on ground

    // Conductive Water / Conduction
    SPELL_CONDUCTIVE_WATER_VISUAL           = 137277,
    SPELL_CONDUCTIVE_WATER_STATUE_FLOW      = 137340, // Water flows from the broken statue
    SPELL_CONDUCTIVE_WATER_SUMMON           = 137145, // Summon stalker
    SPELL_CONDUCTIVE_WATER_PERIODIC_GROW    = 137676, // Periodically grows stalker
    SPELL_CONDUCTIVE_WATER_GROW             = 137694, // Grow stalker
    SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN = 138470, // Increase player damage taken
    SPELL_CONDUCTIVE_WATER_ELECTRIC         = 137978, // Electric visual
    SPELL_CONDUCTIVE_WATER_ELECTRIC_POWER   = 138568, // Lightnings appear
    SPELL_FLUIDITY                          = 138002, // Empower player

    // Static Burst / Static Wound
    SPELL_STATIC_BURST                      = 137162, // Need AuraScript for periodic dummy (on expire, trigger 138349)
    SPELL_STATIC_WOUND                      = 138349, // Need AuraScript
    SPELL_STATIC_WOUND_SHARED               = 138389, // Amount is calculated as follow : SPELL_STATIC_WOUND proc base amount * nbr of stacks / 3

    // Focused Lightning
    SPELL_FOCUSED_LIGHTNING_FOLLOW          = 137422,
    SPELL_FOCUSED_LIGHTNING_SUMMON          = 139206, // Summon the orb
    SPELL_FOCUSED_LIGHTNING_VISUAL          = 139233, // Make it appear
    SPELL_FOCUSED_LIGHTNING_PERIODIC_SPEED  = 137389, // Periodically increase speed
    SPELL_FOCUSED_LIGHTNING_PERIODIC_DAMAGE = 139210, // Casted every 0.5 seconds
    SPELL_FOCUSED_LIGHTNING_DETONATE_LOWER  = 139211, // Detonation damages lowered (why ?)
    SPELL_FOCUSED_LIGHTNING_DETONATE        = 137374, // Not in Conductive Water
    SPELL_FOCUSED_LIGHTNING_CONDUCTION      = 137530, // Detonate in conductive water
    SPELL_FOCUSED_LIGHTNING_ELECTRIC        = 138990, // Detonate in Electrified Waters

    // Lightning Fissure
    SPELL_LIGHTNING_FISSURE_SUMMON          = 137479, // Summon the fissure
    SPELL_LIGHTNING_FISSURE_VISUAL          = 137480, // Make it appear
    SPELL_LIGHTNING_FISSURE_PERIODIC        = 137485, // Casted by players
    SPELL_LIGHTNING_FISSURE_CONDUCTION      = 138133, // In contact with Conductive Water

    // Implosion
    SPELL_IMPLOSION                         = 137507, // When crossed by a Focused Lightning
    SPELL_IMPLOSION_CONDUCTIVE_WATERS       = 138990, // When in contact with a Conductive Water

    // Lightning Storm
    SPELL_LIGHTNING_STORM                   = 137313, // Trigger damages
    // SPELL_LIGHTNING_STORM_VISUAL         = 140549, // Visual of the Storm
    SPELL_LIGHTNING_STORM_VISUAL            = 140753, // Visual of the storm (actually a multi use visual since it is also used during Lei Shen encounter)

    // Lightning Strike (Heroic)
    SPELL_LIGHTNING_STRIKE_VISUAL           = 138299, // Visual (blue column)
    SPELL_LIGHTNING_STRIKE_EXPLOSION        = 137647, // AOE Damages
    SPELL_LIGHTNING_STRIKE_MOB_VISUAL       = 137966, // Visual of the stalker
    SPELL_LIGHTNING_STRIKE_MOB_DAMAGES      = 137905, // To check, damages to any target

    // Electrified Waters
    SPELL_ELECTRIFIED_WATERS                = 138006, // Damages

    // Ionization (Heroic)
    SPELL_IONIZATION                        = 138732, // Aura Script needed (OnEffectRemove)
    SPELL_IONIZATION_DAMAGES                = 138733, // Damages in 8 yards
    SPELL_IONIZATION_DAMAGES_CONDUCTION     = 138743, // Damages in Conductive Waters

    // Berserk
    SPELL_BERSERK                           = 47008,
};

enum eEvents
{
    // Jin'Rokh
    EVENT_THUNDERING_THROW                  = 1,
    EVENT_STATIC_BURST                      = 2,
    EVENT_FOCUSED_LIGHTNING                 = 3,
    EVENT_LIGHTNING_STORM                   = 4,
    EVENT_LIGHTNING_STORM_END               = 5,
    EVENT_IONIZATION                        = 6,
    EVENT_BERSERK                           = 7,

    // Conductive Water
    EVENT_WATER_CHECK_PLAYERS               = 8, // To (re)apply auras if needed
    EVENT_WATER_GROW                        = 9, // Cause aura is wierdly buged

    // Orb of Focused Lightning
    EVENT_INITIALIZE_MOTION                 = 10, // Little delay to fix the Motion Master
    EVENT_ORB_CHECK_PLAYER                  = 11, // Check distance with the targeted player

    // Lightning Fissure
    EVENT_FISSURE_PERIODIC                  = 12, // Cast spell on players
    EVENT_FISSURE_CHECK_WATER               = 13, // Check distance from pools of water

    // Lightning Strike Stalker (Heroic)
    EVENT_STRIKE_LIGHTNING                  = 14,
    EVENT_STRIKE_STALKER_EXPLOSION          = 15, // Explosion when column bursts and summon other stalkers

    // Lightning Strike (Heroic)
    EVENT_STRIKE_CAST                       = 16, // Check players in line

    // Mogu statue stalker
    EVENT_STATUE_CHECK_PLAYER_THROW         = 17, // Check distance with the thrown player
    EVENT_STATUE_CHECK_PLAYER_CRASH         = 18, // Check distance ground - thrown player
    EVENT_STOP_SPRAYING                     = 19, // Stop spraying water after 8 seconds
};

enum eJinRokhCreatures
{
    NPC_MOGU_STATUE_STALKER                 = 662200,
    NPC_CONDUCTIVE_WATER                    = 69469,
    NPC_LIGHTNING_ORB                       = 70174,
    NPC_LIGHTNING_FISSURE                   = 69609, // Maybe 70307 ?
    NPC_LIGHTNING_STRIKE                    = 69753, // Heroic only
    NPC_LIGHTNING_STRIKE_STORM              = 662201, // Heroic only
};

enum eJinRokhTalks
{
    TALK_INTRO                              = 0, // When players enter room I assume
    TALK_AGGRO                              = 1, // EnterCombat
    TALK_BERSERK                            = 2, // On Berserk ?
    TALK_DEATH                              = 3, // JustDied
    TALK_KILLED_PLAYER_FIRST                = 4, // KilledUnit
    TALK_KILLED_PLAYER_SECOND               = 5, // KilledUnit
    TALK_THUNDERING_THROW                   = 6, // On Thundering Throw
    TALK_LIGNTING_STORM                     = 7, // On Lightning Storm
};

enum eJinRokhDatas
{
    // Mogu Statue Stalker
    DATA_STATUE_DESTROYED                   = 0, // Value returned at this index set to 1 when statue has been destroyed
    DATA_STATUE_THROW_PLAYER                = 1,

    // Stalker Strike
    DATA_STRIKE_STORM_COUNT                 = 2,
    
    // Lightning Strike
    DATA_LIGHTNING_STRIKE_TIMER             = 3, // Timer before casting lightning visual
};

enum eMotions
{
    POINT_MIDDLE                            = 1, // When returning to middle
};

enum eActions
{
    // Conductive Water
    ACTION_WATER_SET_ELECTRIC               = 0, // Turn into Electrified Waters
};

//=======================================================================
// Variables
static const Position summonConductiveWaterPosition[] =
{
    { 5919.130371f, 6291.044922f, 124.034798f, 3.925846f }, // North west
    { 5918.745117f, 6236.436523f, 124.034798f, 2.359413f }, // North east
    { 5865.178711f, 6236.843750f, 124.034798f, 0.778800f }, // South east
    { 5864.652344f, 6290.865234f, 124.034798f, 5.490538f }  // South west
};

static const Position centerPosition = { 5891.990234f, 6263.640137f, 123.533661f, 1.570769327f };

// .go 5864.652344 6290.865234 124.034798 1098

//=======================================================================
// AI Scripts


// Helper for Focused Lightning selection
class FocusedLightningSelection : public std::unary_function<Unit*, bool>
{
public:
    FocusedLightningSelection() { }

    bool operator()(Unit const* pTarget) const
    {
        if(!pTarget->ToPlayer())
            return false;

        Player const* pPlayer = pTarget->ToPlayer();

       /* switch(pPlayer->getClass())
        {
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
            return false;

        case CLASS_PALADIN:
            return pPlayer->GetActiveTalentGroup() == CHAR_SPECIALIZATION_PALADIN_HOLY;
            return pPlayer->GetSpecializationId(pPlayer->GetActiveSpec()) == CHAR_SPECIALIZATION_PALADIN_HOLY;

        case CLASS_DRUID:
            return pPlayer->GetSpecializationId(pPlayer->GetActiveSpec()) == CHAR_SPECIALIZATION_DRUID_BALANCE || pPlayer->GetSpecializationId(pPlayer->GetActiveSpec()) == CHAR_SPECIALIZATION_DRUID_RESTORATION;

        case CLASS_MONK:
            return pPlayer->GetSpecializationId(pPlayer->GetActiveSpec()) == CHAR_SPECIALIZATION_MONK_MISTWEAVER;

        case CLASS_SHAMAN:
            return pPlayer->GetSpecializationId(pPlayer->GetActiveSpec()) != CHAR_SPECIALIZATION_SHAMAN_ENHANCEMENT;

        case CLASS_MAGE:
        case CLASS_PRIEST:
        case CLASS_WARLOCK:
        case CLASS_HUNTER:
            return true;

        default:
            return false;
        }*/
    }
};


// Jin'Rokh
#define uiLightningStrikePerSecond 5UL
static_assert(uiLightningStrikePerSecond > 0, "uiLightningStrikePerSecond can't be null or negative !");
class boss_jin_rokh : public CreatureScript
{
public:
    boss_jin_rokh() : CreatureScript("boss_jin_rokh") { }

    class boss_jin_rokh_AI : public ScriptedAI
    {
    public:
        boss_jin_rokh_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), bIntroDone(false)
        {
            events.Reset();
        }

        void Reset()
        {
            events.Reset();
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            pInstance->SetBossState(DATA_JINROKH, NOT_STARTED);
            me->SetSpeed(MOVE_RUN, 1.0f, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE); // Cause we may have the flag if we reset during the storm
            
            CleanArea();
        }

        void MoveInLineOfSight(Unit *pWho)
        {
            if(!bIntroDone && !me->IsInCombat() && pWho && me->IsWithinDistInMap(pWho, 50.0f))
            {
                Talk(TALK_INTRO);
                bIntroDone = true;
            }
        }

        void EnterCombat(Unit *pAggro)
        {
            Talk(TALK_AGGRO);
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            pInstance->SetBossState(DATA_JINROKH, IN_PROGRESS);

            events.ScheduleEvent(EVENT_THUNDERING_THROW,    30 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_STATIC_BURST,        urand(15, 20) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING,   urand(12, 17) * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_LIGHTNING_STORM,     75 * IN_MILLISECONDS);
            if(IsHeroic())
            {
                events.ScheduleEvent(EVENT_BERSERK,         6 * MINUTE * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_IONIZATION,      60 * IN_MILLISECONDS);
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_THUNDERING_THROW:
                    if(Unit* pVictim = me->GetVictim())
                    {
                        Talk(TALK_THUNDERING_THROW);
                        DoCast(pVictim, SPELL_THUNDERING_THROW);
                    }
                    events.ScheduleEvent(EVENT_THUNDERING_THROW, 90 * IN_MILLISECONDS);
                    break;

                case EVENT_STATIC_BURST:
                    if(Unit* pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_STATIC_BURST);
                    events.ScheduleEvent(EVENT_STATIC_BURST, urand(10, 20) * IN_MILLISECONDS);
                    break;

                case EVENT_FOCUSED_LIGHTNING:
                    DoCast(me, SPELL_FOCUSED_LIGHTNING_SUMMON);
                    events.ScheduleEvent(EVENT_FOCUSED_LIGHTNING, urand(15, 20) * IN_MILLISECONDS);
                    break;

                case EVENT_LIGHTNING_STORM:
                {
                    me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN) * 10.0f, true);
                    me->GetMotionMaster()->MovePoint(POINT_MIDDLE, centerPosition);
                    uint32 uiTimer = 2600;
                    
                    // Let's say it spawns uiLightningStrikePerSecond npcs for each second ; we have uiLightningStrikePerSecond * 15 npcs to spawn.
                    for(uint8 i = 0; i < uiLightningStrikePerSecond * 15; ++i)
                    {
                        float fx=0.0f, fy=0.0f;
                        //GetRandPosFromCenterInDist(me->GetPositionX(), me->GetPositionY(), frand(10.0f, 100.0f), fx, fy);
                        
                        if(Creature *pSummon = me->SummonCreature(NPC_LIGHTNING_STRIKE, fx, fy, me->GetPositionZ() + 0.5f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 100000))
                        {
                            if(pSummon->AI())
                            {
                                pSummon->AI()->SetData(DATA_LIGHTNING_STRIKE_TIMER, uiTimer);
                                uiTimer += (1000 / uiLightningStrikePerSecond);
                            }
                        }
                    }
                    Talk(TALK_LIGNTING_STORM);
                    DoCast(me, SPELL_LIGHTNING_STORM);
                    events.ScheduleEvent(EVENT_LIGHTNING_STORM, 90 * IN_MILLISECONDS);
                    break;
                }
                
                case EVENT_LIGHTNING_STORM_END:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        ScriptedAI::AttackStart(pTarget);
                    events.CancelEvent(EVENT_LIGHTNING_STORM_END);
                    break;

                case EVENT_IONIZATION:
                {
                    char const *pszEmote = "Jin'Rokh le Briseur inflige une Ionisation à ses ennemis !";
                   // me->Talk(pszEmote, 0, true);
                    DoCastAOE(SPELL_IONIZATION);
                    events.ScheduleEvent(EVENT_IONIZATION, urand(60, 75) * IN_MILLISECONDS);
                    break;
                }

                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    events.CancelEvent(EVENT_BERSERK);
                    break;

                default:
                    break;
                }
            }
            
            if(!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
                DoMeleeAttackIfReady();
        }
        
        void MovementInform(uint32 uiMotionType, uint32 uiPointMotionId)
        {
            if(uiMotionType == POINT_MOTION_TYPE && uiPointMotionId == POINT_MIDDLE)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->SetSpeed(MOVE_RUN, me->GetSpeedRate(MOVE_RUN) / 10.0f, true);
                if(SpellInfo const* pLightningStorm = sSpellMgr->GetSpellInfo(SPELL_LIGHTNING_STORM))
                {
                    events.DelayEvents(pLightningStorm->GetMaxDuration());
                    events.ScheduleEvent(EVENT_LIGHTNING_STORM_END, pLightningStorm->GetMaxDuration());
                }
            }
        }

        void JustDied(Unit *pKiller)
        {
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            pInstance->SetBossState(DATA_JINROKH, DONE);

            Talk(TALK_DEATH);
            CleanArea(false);
        }

        void KilledUnit(Unit *pKilled)
        {
            Talk(RAND<uint8>(TALK_KILLED_PLAYER_FIRST, TALK_KILLED_PLAYER_SECOND));
        }
        
        Creature* GetFarthestNotDestroyedStatue() const
        {
            std::list<Creature*> statues;
            std::vector<Creature*> availables;
            GetCreatureListWithEntryInGrid(statues, me, NPC_MOGU_STATUE_STALKER, 500.0f);

            for(Creature* statue: statues)
            {
                if(statue->AI()->GetData(DATA_STATUE_DESTROYED) == 0)
                    availables.push_back(statue);
            }

            std::sort(availables.begin(), availables.end(), [this](Creature const* first, Creature const* second) -> bool
            {
                return this->me->GetExactDist2d(first) > this->me->GetExactDist2d(second) ;
            });
            
            if(availables.empty())
                return NULL;
                
            return availables.front();
        }

    private:
        InstanceScript  *pInstance;
        EventMap        events;

        bool bIntroDone;

        void CleanArea(bool bWithWaters = true) const
        {
            if(bWithWaters)
            {
                RemoveMinionsByEntry(NPC_CONDUCTIVE_WATER);
                std::list<Creature*> moguStalkersList;
                GetCreatureListWithEntryInGrid(moguStalkersList, me, NPC_MOGU_STATUE_STALKER, 500.0f);
                
                for(Creature* stalker: moguStalkersList)
                {
                    stalker->AI()->SetData(DATA_STATUE_DESTROYED, 0);
                    stalker->RemoveAllAuras();
                }
            }
                
            RemoveMinionsByEntry(NPC_LIGHTNING_ORB);
            RemoveMinionsByEntry(NPC_LIGHTNING_FISSURE);
            RemoveMinionsByEntry(NPC_LIGHTNING_STRIKE);
            RemoveMinionsByEntry(NPC_LIGHTNING_STRIKE_STORM);
        }

        void RemoveMinionsByEntry(uint32 uiEntry) const
        {
            std::list<Creature*> minions;
            GetCreatureListWithEntryInGrid(minions, me, uiEntry, 500.0f);

            for(Creature* minion: minions)
                minion->DisappearAndDie();
        }
    };

    CreatureAI* GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_jin_rokh_AI, Creature>(pCreature);
    }
};


// Conductive Water
class npc_conductive_water : public CreatureScript
{
public:
    npc_conductive_water() : CreatureScript("npc_conductive_water") { }

    class npc_conductive_water_AI : public ScriptedAI
    {
    public:
        npc_conductive_water_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            events.Reset();
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            DoCast(me, SPELL_CONDUCTIVE_WATER_VISUAL);
            // DoCast(me, SPELL_CONDUCTIVE_WATER_PERIODIC_GROW);

            events.ScheduleEvent(EVENT_WATER_CHECK_PLAYERS, 1000);
            events.ScheduleEvent(EVENT_WATER_GROW, 200);
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_WATER_SET_ELECTRIC:
                DoCast(me, SPELL_CONDUCTIVE_WATER_ELECTRIC_POWER);
                DoCast(me, SPELL_CONDUCTIVE_WATER_ELECTRIC);
                break;

            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_WATER_CHECK_PLAYERS:                    
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, 500.0f);
                        
                        for(Player* pPlayer : playerList)
                        {
                            float fDist = me->GetExactDist2d(pPlayer);
                            float minDist = 3.6f;
                            if(Aura* pGrow = me->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
                                minDist += (0.4f * (pGrow->GetStackAmount()));
                                
                            uint32 spellId = me->HasAura(SPELL_CONDUCTIVE_WATER_ELECTRIC) ? SPELL_ELECTRIFIED_WATERS : SPELL_FLUIDITY;

                            if(fDist <= minDist)
                            {
                                DoCast(pPlayer, spellId, false);
                                DoCast(pPlayer, SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN, false);
                            }
                        }
                    }
                    events.ScheduleEvent(EVENT_WATER_CHECK_PLAYERS, 1000);
                    break;
                    
                case EVENT_WATER_GROW:
                    DoCast(me, SPELL_CONDUCTIVE_WATER_GROW);
                    events.ScheduleEvent(EVENT_WATER_GROW, 200);
                    break;
                    
                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_conductive_water_AI, Creature>(pCreature);
    }
};


// Orb of Focused Lightning
class npc_orb_of_focused_lightning : public CreatureScript
{
public:
    npc_orb_of_focused_lightning() : CreatureScript("npc_orb_of_focused_lightning") { }

    class npc_orb_of_focused_lightning_AI : public ScriptedAI
    {
    public:
        npc_orb_of_focused_lightning_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), pTarget(NULL)
        {
            
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            if(!pSummoner || !pSummoner->GetAI())
                me->DisappearAndDie();
                
            me->setFaction(35);
            
            events.ScheduleEvent(EVENT_INITIALIZE_MOTION, 200);
        }
        
        /*void MovementInform(uint32 uiMotionType, uint32 uiPointMotionId)
        {
            if (uiMotionType == CHASE_MOTION_TYPE)
            {
                if(me->GetMap()->GetDifficulty() != RAID_TOOL_DIFFICULTY)
                {
                    DoCastAOE(SPELL_FOCUSED_LIGHTNING_DETONATE);
                }
                else // Targets are weird
                {
                    pTarget->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING_DETONATE, false);
                }

                if(pTarget->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN))
                {
                    if(pTarget->HasAura(SPELL_ELECTRIFIED_WATERS))
                    {
                        DoCastAOE(SPELL_FOCUSED_LIGHTNING_ELECTRIC);
                    }
                    else
                    {
                        pTarget->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING_CONDUCTION, false);
                    }
                }
                else
                {
                    DoCast(me, SPELL_LIGHTNING_FISSURE_SUMMON);
                }

                me->Kill(me);
                events.Reset();
            }
        }*/

        void UpdateAI(uint32 uiDiff)
        {
            if (pTarget)
            {
                if(me->GetExactDist2d(pTarget) <= 3.0f) // Can't do better for now
                {
                    if(me->GetMap()->GetDifficultyID() != DIFFICULTY_25_N)
                        DoCastAOE(SPELL_FOCUSED_LIGHTNING_DETONATE);
                    else // Targets are weird
                        pTarget->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING_DETONATE, false);

                    if(pTarget->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN))
                    {
                        if(pTarget->HasAura(SPELL_ELECTRIFIED_WATERS))
                            DoCastAOE(SPELL_FOCUSED_LIGHTNING_ELECTRIC);
                        else
                            pTarget->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING_CONDUCTION, false);
                    }
                    else
                        DoCast(me, SPELL_LIGHTNING_FISSURE_SUMMON);

                    me->Kill(me);
                    return;
                }
            }
        
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_ORB_CHECK_PLAYER:
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 5.0f);
                    
                    for(Player* pPlayer: playerList)
                    {
                        if(pPlayer != pTarget)
                            DoCast(pPlayer, SPELL_FOCUSED_LIGHTNING_PERIODIC_DAMAGE);
                    }
                    events.ScheduleEvent(EVENT_ORB_CHECK_PLAYER, 500);
                    break;
                }
                
                case EVENT_INITIALIZE_MOTION:
                    if (Creature *pJinrokh = ObjectAccessor::GetCreature(*me, me->GetInstanceScript()->GetObjectGuid(BOSS_JINROKH)))
                    {
                        if(pTarget = pJinrokh->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, FocusedLightningSelection()))
                        {
                            DoCast(me, SPELL_FOCUSED_LIGHTNING_PERIODIC_SPEED, false);
                            me->CastSpell(pTarget, SPELL_FOCUSED_LIGHTNING_FOLLOW, false);
                                
                            me->GetMotionMaster()->MoveFollow(pTarget, 0.0f, 0.0f);
                            
                            events.ScheduleEvent(EVENT_ORB_CHECK_PLAYER, 500);
                        }
                        else
                            me->DisappearAndDie();
                    }
                    break;

                default:
                    break;
                }
            }
        }
        
        void JustDied(Unit *pKiller)
        {
            if(pTarget)
                pTarget->RemoveAurasDueToSpell(SPELL_FOCUSED_LIGHTNING_FOLLOW);
        }

    private:
        InstanceScript  *pInstance;
        EventMap        events;
        Unit            *pTarget;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_orb_of_focused_lightning_AI, Creature>(pCreature);
    }
};


// Lightning Fissure
class npc_lightning_fissure : public CreatureScript
{
public:
    npc_lightning_fissure() : CreatureScript("npc_lightning_fissure") { }

    class npc_lightning_fissure_AI : public ScriptedAI
    {
    public:
        npc_lightning_fissure_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            events.Reset();
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            DoCast(me, SPELL_LIGHTNING_FISSURE_VISUAL);

            events.ScheduleEvent(EVENT_FISSURE_PERIODIC,    1000);
            events.ScheduleEvent(EVENT_FISSURE_CHECK_WATER, 500);
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_FISSURE_PERIODIC:
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 5.0f);

                    for(Player* player: playerList)
                        player->CastSpell(player, SPELL_LIGHTNING_FISSURE_PERIODIC);

                    events.ScheduleEvent(EVENT_FISSURE_PERIODIC, 1000);
                    break;
                }

                case EVENT_FISSURE_CHECK_WATER:
                {
                    std::list<Creature*> waters;
                    GetCreatureListWithEntryInGrid(waters, me, NPC_CONDUCTIVE_WATER, 500.0f);

                    waters.sort([this](Creature const* first, Creature const* second) -> bool
                    {
                        return this->me->GetExactDist2d(first) < this->me->GetExactDist2d(second);
                    });

                    for(Creature *pWater: waters)
                    {
                        if(Aura *pGrow = pWater->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
                        {
                            uint32 uiTicks = pGrow->GetStackAmount();
                            float fBase = 3.6f;

                            fBase += (0.4f * uiTicks);

                            float fDist = me->GetExactDist2d(pWater) - fBase;

                            if(fDist <= 5.0f)
                            {
                                DoCastAOE(SPELL_IMPLOSION_CONDUCTIVE_WATERS);
                                me->Kill(me);
                                return;
                            }
                        }
                    }

                    if(GetClosestCreatureWithEntry(me, NPC_LIGHTNING_ORB, 5.0f, true))
                        DoCastAOE(SPELL_IMPLOSION);

                    events.ScheduleEvent(EVENT_FISSURE_CHECK_WATER, 500);
                    break;
                }

                default:
                    break;
                }
            }
        }

    private:
        InstanceScript  *pInstance;
        EventMap        events;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_lightning_fissure_AI, Creature>(pCreature);
    }
};


// Lightning Strike (Heroic)
class npc_lightning_strike : public CreatureScript
{
public:
    npc_lightning_strike() : CreatureScript("npc_lightning_strike") { }

    class npc_lightning_strike_AI : public ScriptedAI
    {
    public:
        npc_lightning_strike_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            events.Reset();
        }
        
        void SetData(uint32 uiIndex, uint32 uiValue)
        {
            if(uiIndex == DATA_LIGHTNING_STRIKE_TIMER)
                events.ScheduleEvent(EVENT_STRIKE_LIGHTNING, uiValue);
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_STRIKE_LIGHTNING:
                    DoCast(me, SPELL_LIGHTNING_STORM_VISUAL, false);
                    if(IsHeroic())
                    {
                        DoCast(me, SPELL_LIGHTNING_STRIKE_VISUAL);
                        events.ScheduleEvent(EVENT_STRIKE_STALKER_EXPLOSION, 6000);
                    }
                    break;
                    
                case EVENT_STRIKE_STALKER_EXPLOSION:
                    DoCastAOE(SPELL_LIGHTNING_STRIKE_EXPLOSION);
                    for(uint8 i = 0; i < 6; ++i)
                    {
                        if(Creature *pStalkerStorm = me->SummonCreature(NPC_LIGHTNING_STRIKE_STORM, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 0.5f, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            pStalkerStorm->AI()->SetData(DATA_STRIKE_STORM_COUNT, i + 1);
                    }
                    me->Kill(me);
                    break;

                default:
                    break;
                }
            }
        }

    private:
        InstanceScript  *pInstance;
        EventMap        events;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_lightning_strike_AI, Creature>(pCreature);
    }
};


// Lightning Strike Storm (Heroic)
#define LIGHTNING_STRIKE_MAX_DIST 10.0f
class npc_lightning_strike_storm : public CreatureScript
{
public:
    npc_lightning_strike_storm() : CreatureScript("npc_lightning_strike_storm") { }

    class npc_lightning_strike_storm_AI : public ScriptedAI
    {
    public:
        npc_lightning_strike_storm_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiCount(0)
        {
            me->SetReactState(REACT_PASSIVE);
            events.Reset();
        }

        void SetData(uint32 uiIndex, uint32 uiValue)
        {
            if(uiIndex == DATA_STRIKE_STORM_COUNT)
                uiCount = uiValue;
                
            // Do NOT divise by ZERO !
            float fx = me->GetPositionX() + LIGHTNING_STRIKE_MAX_DIST * std::cos(2 * M_PI / (uiCount ? uiCount : 1));
            float fy = me->GetPositionY() + LIGHTNING_STRIKE_MAX_DIST * std::sin(2 * M_PI / (uiCount ? uiCount : 1));
            me->GetMotionMaster()->MovePoint(0, fx, fy, me->GetPositionZ() + 0.5f);

            DoCast(me, SPELL_LIGHTNING_STRIKE_MOB_VISUAL);

            events.ScheduleEvent(EVENT_STRIKE_CAST, 500);
        }

        void UpdateAI(uint32 uiDiff)
        {
            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_STRIKE_CAST:
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 3.0f);

                    for(Player* pPlayer: playerList)
                        DoCast(pPlayer, SPELL_LIGHTNING_STRIKE_MOB_DAMAGES);

                    events.ScheduleEvent(EVENT_STRIKE_CAST, 500);
                    break;
                }

                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;

        uint32          uiCount;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_lightning_strike_storm_AI, Creature>(pCreature);
    }
};


// Mogu Statue Stalker
class npc_mogu_statue_stalker : public CreatureScript
{
public:
    npc_mogu_statue_stalker() : CreatureScript("npc_mogu_statue_stalker") { }

    class npc_mogu_statue_stalker_AI : public ScriptedAI
    {
    public:
        npc_mogu_statue_stalker_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            uiIsDestroyed = 0;
            events.Reset();
        }

        void SetGUID(uint64 uiGuid, int32 iIndex)
        {
            if(iIndex == DATA_STATUE_THROW_PLAYER)
            {
                uiWatchPlayerGuid = uiGuid;
                events.ScheduleEvent(EVENT_STATUE_CHECK_PLAYER_THROW, 500);
            }
        }
        
        void SetData(uint32 uiIndex, uint32 uiValue)
        {
            if(uiIndex == DATA_STATUE_DESTROYED)
                uiIsDestroyed = uiValue;
        }

        uint32 GetData(uint32 uiIndex) const
        {
            if(uiIndex == DATA_STATUE_DESTROYED)
                return uiIsDestroyed;

            return 0;
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(events.Empty())
                return;

            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_STATUE_CHECK_PLAYER_THROW:
                    if(Player *pThrown = ObjectAccessor::GetPlayer(*me, GetGUID(uiWatchPlayerGuid)))
                    {
                        if(me->GetExactDist2d(pThrown) <= 3.0f)
                        {
                            uiIsDestroyed = 1;

                            DoCast(me, SPELL_CONDUCTIVE_WATER_STATUE_FLOW);

                            pThrown->GetMotionMaster()->Clear(true);

                            pWaterTarget = GetClosestPositionOfWater();
                            // pThrown->GetMotionMaster()->MoveJump(pWaterTarget, 32.2795181f, 15.0f); // Same as the values computed in fly
                            events.ScheduleEvent(EVENT_STATUE_CHECK_PLAYER_CRASH, 500);
                            events.ScheduleEvent(EVENT_STOP_SPRAYING, 8 * IN_MILLISECONDS);

                        }
                        else
                            events.ScheduleEvent(EVENT_STATUE_CHECK_PLAYER_THROW, 500);
                    }
                    break;

                case EVENT_STATUE_CHECK_PLAYER_CRASH:
                    if(Player *pThrown = ObjectAccessor::GetPlayer(*me, GetGUID(uiWatchPlayerGuid)))
                    {
                        if(std::fabs(me->GetPositionZ() - pThrown->GetPositionZ()) > 25.0f)
                        {
                            pThrown->CastSpell(pThrown, SPELL_CONDUCTIVE_WATER_SUMMON, false);

                            pThrown->CastSpell(pThrown, SPELL_THUNDERING_THROW_IMPACT_VISUAL, false);
                            pThrown->CastSpell(pThrown, SPELL_THUNDERING_THROW_HIT_AOE_DAMAGE, false);
                            pThrown->CastSpell(pThrown, SPELL_THUNDERING_THROW_HIT_DAMAGE);

                            pThrown->RemoveAura(SPELL_THUNDERING_THROW_SILENCE);
                            pThrown->RemoveAura(SPELL_THUNDERING_TRHOW_FLY_VISUAL);

                            std::list<Player*> playerList;
                            pThrown->GetPlayerListInGrid(playerList, 8.0f);

                            for(Player *pPlayer : playerList)
                                pThrown->CastSpell(pPlayer, SPELL_THUNDERING_THROW_STUN, false);
                        }
                        else
                            events.ScheduleEvent(EVENT_STATUE_CHECK_PLAYER_CRASH, 500);

                    }
                    else
                        events.ScheduleEvent(EVENT_STATUE_CHECK_PLAYER_CRASH, 500);
                    break;
                    
                case EVENT_STOP_SPRAYING:
                    me->RemoveAura(SPELL_CONDUCTIVE_WATER_STATUE_FLOW);
                    break;

                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        Position        pWaterTarget;

        uint32          uiIsDestroyed;
        uint64          uiWatchPlayerGuid;

        Position GetClosestPositionOfWater() const
        {
            std::vector<Position> waterPositions;
            for(auto i: summonConductiveWaterPosition)
                waterPositions.push_back(i);

            std::sort(waterPositions.begin(), waterPositions.end(), [this](Position const& first, Position const& second) -> bool
            {
                return this->me->GetExactDist2d(&first) < this->me->GetExactDist2d(&second);
            });

            return waterPositions.front();
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
	return GetThroneOfThunderAI<npc_mogu_statue_stalker_AI, Creature>(pCreature);
    }
};

//=======================================================================
// Spells Scripts


// Conductive Water Helper
class ConductiveWaterCheckPredicate
{
    public:
        ConductiveWaterCheckPredicate(uint64 _uiCasterGuid, bool _bPresent) :
            uiCasterGuid(_uiCasterGuid), bPresent(_bPresent)
        {

        }

        bool operator()(WorldObject const* pTarget)
        {
            if(!pTarget)
                return true;

            if(!pTarget->ToUnit())
                return true;

            if(!uiCasterGuid)
            {
                if(bPresent)
                    return !pTarget->ToUnit()->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN);
                else
                    return pTarget->ToUnit()->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN);
            }
            else
            {
                if(bPresent)
                    return !pTarget->ToUnit()->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN);
                else
                    return pTarget->ToUnit()->HasAura(SPELL_CONDUCTIVE_WATER_MOD_DAMAGE_TAKEN);
            }
        }

    private:
        uint64  uiCasterGuid;
        bool    bPresent;
};


// Thundering Throw
class spell_jinrokh_thundering_throw : public SpellScriptLoader
{
public:
    spell_jinrokh_thundering_throw() : SpellScriptLoader("spell_jinrokh_thundering_throw") { }

    class spell_jinrokh_thundering_throw_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jinrokh_thundering_throw_SpellScript);

        void HandleScriptEffect(SpellEffIndex effIndex)
        {
            if(Unit *pCaster = GetCaster())
            {
                if(Unit *pVictim = pCaster->GetVictim())
                {
                    if(boss_jin_rokh::boss_jin_rokh_AI* ai = dynamic_cast<boss_jin_rokh::boss_jin_rokh_AI*>(pCaster->GetAI()))
                    {
                        if(Creature *pStatue = ai->GetFarthestNotDestroyedStatue())
                        {
                            pVictim->CastSpell(pVictim, SPELL_THUNDERING_THROW_SILENCE);
                            pVictim->CastSpell(pVictim, SPELL_THUNDERING_TRHOW_FLY_VISUAL);
                            pVictim->CastSpell(pStatue, SPELL_THUNDERING_THROW_JUMP);

                            pStatue->AI()->SetGUID(pVictim->GetGUID(), DATA_STATUE_THROW_PLAYER);
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_jinrokh_thundering_throw_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_jinrokh_thundering_throw_SpellScript();
    }
};


// Static Burst
class spell_jinrokh_static_burst : public SpellScriptLoader
{
public:
    spell_jinrokh_static_burst() : SpellScriptLoader("spell_jinrokh_static_burst") { }

    class spell_jinrokh_static_burst_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_jinrokh_static_burst_AuraScript);

        void HandleDummyRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes mode)
        {
            if(WorldObject *pOwner = GetOwner())
            {
                if(Player *pPlayerOwner = pOwner->ToPlayer())
                {
                    for(uint8 i = 0; i < 10; ++i)
                        pPlayerOwner->CastSpell(pPlayerOwner, SPELL_STATIC_WOUND);
                }
            }
        }

        void Register()
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_jinrokh_static_burst_AuraScript::HandleDummyRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript *GetAuraScript() const
    {
        return new spell_jinrokh_static_burst_AuraScript();
    }
};


// Static Wound
class spell_jinrokh_static_wound : public SpellScriptLoader
{
    public:
        spell_jinrokh_static_wound() : SpellScriptLoader("spell_jinrokh_static_wound") {}
        
        class spell_jinrokh_static_wound_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jinrokh_static_wound_AuraScript);
            
            void HandleOnProc(ProcEventInfo& procInfo)
            {
                PreventDefaultAction();
                
                int32 iDamage = GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints * GetStackAmount();
                
                if(Unit *pCaster = GetCaster())
                {
                    if(!GetOwner())
                        return;
                        
                    if(Unit *pOwner = GetOwner()->ToUnit())
                    {
                        std::list<Player*> playerList;
                        pCaster->GetPlayerListInGrid(playerList, 500.0f);
                        
                        for(Player *pPlayer: playerList)
                        {
                            if(pPlayer != pOwner)
                            {
                                iDamage /= 3;
                                pOwner->CastCustomSpell(pPlayer, SPELL_STATIC_WOUND_SHARED, &iDamage, NULL, NULL, NULL, NULL, NULL);
                            }
                            else
                            {
                                pOwner->CastCustomSpell(pPlayer, SPELL_STATIC_WOUND_SHARED, &iDamage, NULL, NULL, NULL, NULL, NULL);
                            }
                        }
                    }
                }
            }
            
            void HandlePeriodicDummy(AuraEffect const* pAuraEffect)
            {
                ModStackAmount(-1);
            }
            
            void Register()
            {
                OnProc              += AuraProcFn(spell_jinrokh_static_wound_AuraScript::HandleOnProc);
                OnEffectPeriodic    += AuraEffectPeriodicFn(spell_jinrokh_static_wound_AuraScript::HandlePeriodicDummy, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };
        
        AuraScript *GetAuraScript() const
        {
            return new spell_jinrokh_static_wound_AuraScript();
        }
};


// Focused Lightning (Conduction)
class spell_jinrokh_focused_lightning_conduction : public SpellScriptLoader
{
    public:
        spell_jinrokh_focused_lightning_conduction() : SpellScriptLoader("spell_jinrokh_focused_lightning_conduction") { }

        class spell_jinrokh_focused_lightning_conduction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinrokh_focused_lightning_conduction_SpellScript);

            void HandleTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ConductiveWaterCheckPredicate(0, true));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jinrokh_focused_lightning_conduction_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_jinrokh_focused_lightning_conduction_SpellScript();
        }
};


// Implosion (Conduction)
class spell_jinrokh_implosion_conduction : public SpellScriptLoader
{
    public:
        spell_jinrokh_implosion_conduction() : SpellScriptLoader("spell_jinrokh_implosion_conduction") { }

        class spell_jinrokh_implosion_conduction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinrokh_implosion_conduction_SpellScript);

            void HandleTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ConductiveWaterCheckPredicate(GetCaster() ? GetCaster()->GetGUID() : 0, true));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jinrokh_implosion_conduction_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_jinrokh_implosion_conduction_SpellScript();
        }
};


// Lightning Storm
class spell_jinrokh_lightning_storm : public SpellScriptLoader
{
    public:
        spell_jinrokh_lightning_storm() : SpellScriptLoader("spell_jinrokh_lightning_storm") { }

        class spell_jinrokh_lightning_storm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jinrokh_lightning_storm_AuraScript);

            bool Load()
            {
                bElectrified = false;
                return true;
            }

            /*void HandleEffectApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes mode)
            {
                if(Unit *pCaster = GetCaster())
                {
                    pCaster->AddAura(SPELL_LIGHTNING_STORM_VISUAL, pCaster);
                }
            }*/

            void HandlePeriodic(AuraEffect const* pAuraEffect)
            {
                if(!bElectrified)
                {
                    if(Unit *pCaster = GetCaster())
                    {
                        std::list<Creature*> waters;
                        GetCreatureListWithEntryInGrid(waters, pCaster, NPC_CONDUCTIVE_WATER, 500.0f);

                        waters.remove_if([](Creature const* water) -> bool
                        {
                            return water->HasAura(SPELL_CONDUCTIVE_WATER_ELECTRIC) || !water->HasAura(SPELL_CONDUCTIVE_WATER_VISUAL) ;
                        });

                        if(!waters.empty())
                        {
                            if(urand(0, 100) <= 50)
                            {
                                if(Creature *pWater = Trinity::Containers::SelectRandomContainerElement(waters))
                                {
                                    pWater->AI()->DoAction(ACTION_WATER_SET_ELECTRIC);
                                    bElectrified = true;
                                }
                            }
                        }
                    }
                }
            }

            void Register()
            {
                // AfterEffectApply += AuraEffectApplyFn(spell_jinrokh_lightning_storm_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_jinrokh_lightning_storm_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

            bool bElectrified;
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_jinrokh_lightning_storm_AuraScript();
        }
};


// Lightning Storm Visual
/*class spell_jinrokh_lightning_storm_visual : public SpellScriptLoader
{
public:
    spell_jinrokh_lightning_storm_visual() : SpellScriptLoader("spell_jinrokh_lightning_storm_visual") { }

    class spell_jinrokh_lightning_storm_visual_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_jinrokh_lightning_storm_visual_SpellScript)

        void HandleSummon(SpellEffIndex effIndex)
        {
            if(WorldLocation* pHitLoc = GetHitDest())
            {
                if(Unit *pCaster = GetCaster())
                {
                    if(Map *pMap = pCaster->GetMap())
                    {
                        if(pMap->GetDifficulty() == RAID_DIFFICULTY_10MAN_HEROIC || pMap->GetDifficulty() == RAID_DIFFICULTY_25MAN_HEROIC)
                            pCaster->SummonCreature(NPC_LIGHTNING_STRIKE, *pHitLoc);
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_jinrokh_lightning_storm_visual_SpellScript::HandleSummon, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_jinrokh_lightning_storm_visual_SpellScript();
    }
};*/


// Ionization
class spell_jinrokh_ionization : public SpellScriptLoader
{
    public:
        spell_jinrokh_ionization() : SpellScriptLoader("spell_jinrokh_ionization") { }

        class spell_jinrokh_ionization_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_jinrokh_ionization_AuraScript);

            void HandleEffectRemove(AuraEffect const* pAuraEff, AuraEffectHandleModes mode)
            {
                if(AuraApplication const* pAuraApp = GetTargetApplication())
                {
                    if(pAuraApp->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL || pAuraApp->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    {
                        if(Unit *pCaster = GetCaster())
                        {
                            int32 bp = 450000;
                            pCaster->CastCustomSpell(pCaster, SPELL_IONIZATION_DAMAGES, &bp, NULL, NULL, NULL, NULL, NULL);

                            if(Unit *pTarget = pCaster->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true)) // Targets allies, so use an enemy as caster
                                pTarget->CastCustomSpell(pTarget, SPELL_IONIZATION_DAMAGES_CONDUCTION, &bp, NULL, NULL, NULL, NULL, NULL);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_jinrokh_ionization_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript *GetAuraScript() const
        {
            return new spell_jinrokh_ionization_AuraScript();
        }
};


// Ionization (Conduction)
class spell_jinrokh_ionization_conduction : public SpellScriptLoader
{
    public:
        spell_jinrokh_ionization_conduction() : SpellScriptLoader("spell_jinrokh_ionization_conduction") { }

        class spell_jinrokh_ionization_conduction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_jinrokh_ionization_conduction_SpellScript);

            void HandleTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ConductiveWaterCheckPredicate(0, true));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_jinrokh_ionization_conduction_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_jinrokh_ionization_conduction_SpellScript();
        }
};

//=======================================================================

void AddSC_boss_jin_rokh()
{
    // Creatures
    new boss_jin_rokh();
    new npc_conductive_water();
    new npc_orb_of_focused_lightning();
    new npc_lightning_fissure();
    new npc_lightning_strike();
    new npc_lightning_strike_storm();
    new npc_mogu_statue_stalker();

    // Spells
    new spell_jinrokh_thundering_throw();
    new spell_jinrokh_static_burst();
    new spell_jinrokh_static_wound();
    new spell_jinrokh_focused_lightning_conduction();
    new spell_jinrokh_implosion_conduction();
    new spell_jinrokh_lightning_storm();
    // new spell_jinrokh_lightning_storm_visual());
    new spell_jinrokh_ionization();
    new spell_jinrokh_ionization_conduction();
}
