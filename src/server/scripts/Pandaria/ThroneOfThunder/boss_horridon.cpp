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
#include "GridNotifiers.h"
#include "Vehicle.h"
#include "GameObjectAI.h"

//=========================================================
// Spells Analysis

//=========================================================
// Enums

enum eCreatures
{
    //===============================================
    // Farraki
    MOB_SUL_LITHUZ_STONEGAZER               = 69172,
    MOB_FARRAKI_SKIRMISHER                  = 69173,
    MOB_FARRAKI_WASTEWALKER                 = 69175, // Total of three will be called to action

    //===============================================
    // Gurubashi
    MOB_GURUBASHI_BLOODLORD                 = 69167,
    MOB_GURUBASHI_VENOM_PRIEST              = 69164, // Total of three will be called to action

    //===============================================
    // Drakkari
    MOB_RISEN_DRAKKARI_WARRIOR              = 69184,
    MOB_RISEN_DRAKKARI_CHAMPION             = 69185,
    MOB_DRAKKARI_FROZEN_WARLORD             = 69178, // Total of three will be called to action

    //===============================================
    // Amani
    MOB_AMANI_SHI_PROTECTOR                 = 69169,
    MOB_AMANI_SHI_FLAME_CASTER              = 69168,
    MOB_AMANI_WARBEAR                       = 69177, // Total of three will be called to action
    MOB_AMANI_SHI_BEAST_SHAMAN              = 69176, // Riding Amani Warbears, attackable once Amani Warbear has fallen

    //===============================================
    // Zandalari
    MOB_ZANDALARI_DINOMANCER                = 69221, // Jumping periodically during subphases

    //===============================================
    // Summons
    MOB_DIREHORN_SPIRIT                     = 70688, // Only spawn in Heroic
    MOB_SAND_TRAP                           = 69346, // Summoned by Farraki Wastewalker
    MOB_VENOMOUS_EFFUSION                   = 69314, // Summoned by Gurubashi Venom Priests
    MOB_LIVING_POISON                       = 69313, // Created when a Venomous Effusion is created
    MOB_FROZEN_ORB                          = 69268, // Summoned by Drakkari Frozen Warlords
    MOB_LIGHTNING_NOVA_TOTEM                = 69215, // Summoned by Amani'Shi Beast Shaman

    //===============================================
    // Others
};


enum eGameObjects
{
    //===============================================
    // Orbs of Control
    GOB_ORB_OF_CONTROL_FARRAKI              = 218193,
    GOB_ORB_OF_CONTROL_GURUBASHI            = 218374,
    GOB_ORB_OF_CONTROL_DRAKKARI             = 218375,
    GOB_ORB_OF_CONTROL_AMANI                = 218376,
    
    //===============================================
    // Others
    GOB_HORRIDON_PRISON_DOOR                = 218674,
};


enum eSpells
{
    //===============================================
    // Horridon

    // Triple Puncture
    SPELL_TRIPLE_PUNCTURE                   = 136767, // Casted on Main Tank

    // Double Swipe
    SPELL_DOUBLE_SWIPE                      = 136741, // Launch everything
    SPELL_DOUBLE_SWIPE_FRONT                = 136740, // Frontal damages
    SPELL_DOUBLE_SWIPE_BACK                 = 136739, // Back damages

    // Charge
    SPELL_CHARGE                            = 136769, // Only the charge effect is interesting, dummy may be used by bli² to replace our MovementInform (watch for EffectTriggerSpell)

    // Dire Call
    SPELL_DIRE_CALL                         = 137458, // Launch everything
    SPELL_SUMMON_DIREHORN_SPIRIT_SELECTOR   = 140947,
    SPELL_SUMMON_DIREHORN_SPIRIT            = 140945,

    // After a charge at a door
    SPELL_HEADACHE                          = 137294,
    SPELL_CRACKED_SHELL                     = 137240,

    // Enrage
    SPELL_RAMPAGE                           = 136821,

    //===============================================
    // Farraki
    SPELL_STONE_GAZE                        = 136708, // Stonegazer
    SPELL_BLAZING_SUNLIGHT                  = 136719, // Wastewalker
    SPELL_SUMMON_SAND_TRAP                  = 136725, // Wastewalker

    //===============================================
    // Gurubashi
    SPELL_RENDING_CHARGE                    = 136653, // Bloodlord
    SPELL_RENDING_CHARGE_DAMAGES            = 136654, // Bloodlord (triggered when Rending Charge hits target)
    SPELL_VENOM_BOLT_VOLLEY                 = 136587, // Venom Priest
    SPELL_SUMMON_VENOMOUS_EFFUSION          = 136644, // Venom Priest

    //===============================================
    // Drakkari
    SPELL_UNCONTROLLED_ABOMINATION          = 136709, // Risen Drakkari Champion / Warrior
    SPELL_DEADLY_PLAGUE                     = 136710, // Risen Drakkari Champion / Warrior (procs from Uncontrolled Abomination)
    SPELL_MORTAL_STRIKE                     = 136670, // Frozen Warlord
    SPELL_SUMMON_FROZEN_ORB                 = 136564, // Frozen Warlord

    //===============================================
    // Amani
    SPELL_FIREBALL                          = 136465, // Flame Caster
    SPELL_SWIPE                             = 136463, // Warbear
    SPELL_CHAIN_LIGHTNING                   = 136480, // Beast Shaman
    SPELL_HEX_OF_CONFUSION                  = 136512, // Beast Shaman
    SPELL_SUMMON_LIGHTNING_NOVA_TOTEM       = 136487, // Beast Shaman

    //===============================================
    // Zandalari
    SPELL_DINO_MENDING                      = 136797, // Dinomancer
    SPELL_DINO_FORM                         = 137237, // Dinomancer
    SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI     = 137445, // Dinomancer
    SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI   = 137447, // Dinomancer
    SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI    = 137448, // Dinomancer
    SPELL_SUMMON_ORB_OF_CONTROL_AMANI       = 137449, // Dinomancer

    //===============================================
    // Summons
    SPELL_DIRE_FIXATION                     = 140946, // Dire Horn Spirit
    SPELL_WEAK_LINK                         = 140948, // Dire Horn Spirit
    SPELL_SAND_TRAP_PERIODIC                = 136724,
    SPELL_SAND_TRAP                         = 136723, // SpellScript needed (radius)
    SPELL_SUMMON_LIVING_POISON              = 136644, // Three times ?
    SPELL_LIVING_POISON_PERIODIC            = 136645,
    SPELL_LIVING_POISON                     = 136646,
    SPELL_FROZEN_BOLT_PERIODIC              = 136572,
    SPELL_FROZEN_BOLT                       = 136573, // Frozen Orb
    SPELL_LIGHTNING_NOVA_PERIODIC           = 136489, // Lightning Nova Totem
    SPELL_LIGHTNING_NOVA                    = 136490,

    //===============================================
    // Jalak
    SPELL_BESTIAL_CRY                       = 136817,
    
    //===============================================
    // Orb of Control
    SPELL_CONTROL_HORRIDON_FARRAKI          = 137433,
    SPELL_CONTROL_HORRIDON_GURUBASHI        = 137442,
    SPELL_CONTROL_HORRIDON_DRAKKARI         = 137443,
    SPELL_CONTROL_HORRIDON_AMANI            = 137444,
};


enum eEvents
{
    //===============================================
    // Horridon
    EVENT_TRIPLE_PUNCTURE                   = 1,
    EVENT_DOUBLE_SWIPE                      = 2,
    EVENT_HORRIDON_CHARGE                   = 3, // Conflict with EventId::EVENT_CHARGE
    EVENT_DIRE_CALL                         = 4,
    EVENT_PREPARE_CHARGE                    = 5, // Pseudo hack
    EVENT_CHARGE_AT_DOOR                    = 6,

    //===============================================
    // Farraki
    EVENT_STONE_GAZE                        = 7,
    EVENT_BLAZING_LIGHT                     = 8,
    EVENT_SUMMON_SAND_TRAP                  = 9,

    //===============================================
    // Gurubashi
    EVENT_RENDING_CHARGE                    = 10,
    EVENT_GURUBASHI_VENOM_BOLT_VOLLEY       = 11,
    EVENT_SUMMON_VENOMOUS_EFFUSION          = 12,

    //===============================================
    // Drakkari
    EVENT_SWITCH_TARGET                     = 13, // Risen Drakkari doesn't have a real threat list
    EVENT_MORTAL_STRIKE                     = 14,
    EVENT_SUMMON_FROZEN_ORB                 = 15,

    //===============================================
    // Amani
    EVENT_FIREBALL                          = 16,
    EVENT_SWIPE                             = 17,
    EVENT_CHAIN_LIGHTNING                   = 18,
    EVENT_HEX_OF_CONFUSION                  = 19,
    EVENT_SUMMON_LIGHTNING_NOVA_TOTEM       = 20,

    //===============================================
    // Zandalari
    EVENT_DINO_MENDING                      = 21,

    //===============================================
    // Summons
    EVENT_EFFUSION_VENOM_BOLT_VOLLEY        = 22,

    //===============================================
    // Jalak
    EVENT_BESTIAL_CRY                       = 23,

    //===============================================
    // Helper
    EVENT_SUMMON_MINOR                      = 24, // Summon minor or medium, because they spawn at the same moment
    EVENT_SUMMON_MAJOR                      = 25, // Make a major npc jump, because they appear on a different timer
    EVENT_SUMMON_ZANDALARI_DINOMANCER       = 26, // Make a Zandalari Dinomancer jump (they are not on the same timer)
    EVENT_SUMMON_MINOR_DRAKKARI             = 27, // Special case for Drakkari
    EVENT_TRANSITION                        = 28, // Pseudo hack for now, as long as the charge to door is not fixed
    
    //===============================================
    // RP Event Helper
    EVENT_CHECK_PLAYERS                     = 29, // Every 500 ms to not flood the world
    EVENT_INTRO_PART_I                      = 30, // Jalak begins it's speech... so annoying
    EVENT_INTRO_PART_II                     = 31, // Continues
    EVENT_INTRO_PART_III                    = 32, // Horridon breaks free and go and kill every... oh wait... that's not the time
    EVENT_INTRO_PART_IV                     = 33, // Now Horridon breaks free 
};


enum eActions
{
    //===============================================
    // Controller
    ACTION_FIGHT_BEGIN                      = 0,
    ACTION_FIGHT_RESET                      = 1,
    ACTION_ENTER_NEXT_TRASH_PHASE           = 2,
    ACTION_FIGHT_END                        = 3,
    ACTION_PREPARE_TRANSITION               = 4,

    //===============================================
    // Jalak
    ACTION_ENTER_PHASE_TWO                  = 5,
    
    //===============================================
    // Horridon
    ACTION_INTRO                            = 6,
    ACTION_PREPARE_CHARGE                   = 7,
    ACTION_CONTROL_APPLY                    = 8,
};


enum eMotions
{
    //===============================================
    // Majors
    MOTION_MAJOR_JUMP                       = 0,

    //===============================================
    // Zandalari Dinomancers
    MOTION_DINOMANCER_JUMP                  = 1,

    //===============================================
    // Horridon
    MOTION_HORRIDON_CHARGE                  = 2,
    MOTION_HORRIDON_DOOR_CHARGE             = 3,
    
};


enum eTalks
{
    TALK_ENTER_PHASE_2                      = 0, // Hahaha, now it be my turn
    TALK_ON_HORRIDON_KILLED_UNIT            = 1, // Da'kala koraste
    TALK_INTRO_FIRST                        = 2, // Welcome weaklings
    TALK_INTRO_SECOND                       = 3, // The tribes have assembled
    TALK_INTRO_THIRD                        = 4, // Now, witness the true might
    TALK_ON_JALAK_KILLED_UNIT               = 5, // Ya skull
    TALK_DRAKKARI                           = 6, // Drakkari tribe
    TALK_GURUBASHI                          = 7,
    TALK_FARRAKI                            = 8,
    TALK_AMANI                              = 9,
};


enum eDatas
{
    DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT = 0, // To know how many time we stroke
};


enum eBossPhases
{
    BOSS_PHASE_SUMMONS                      = 0,
    BOSS_PHASE_JALAK                        = 1
};
#define MAX_BOSS_PHASE BOSS_PHASE_JALAK + 1


enum eTrashPhases
{
    TRASH_PHASE_FARRAKI                     = 0,
    TRASH_PHASE_GURUBASHI                   = 1,
    TRASH_PHASE_DRAKKARI                    = 2,
    TRASH_PHASE_AMANI                       = 3,

    MAX_TRASH_PHASE                         = TRASH_PHASE_AMANI + 1,
};


enum eMajorsCycle
{
    MAJOR_CYCLE_FIRST                       = 0,
    MAJOR_CYCLE_SECOND                      = 1,
    
    MAX_MAJOR_CYCLE                         = 2,
};


enum eDrakkariCycle
{
    DRAKKARI_CYCLE_FIRST                    = 0,
    DRAKKARI_CYCLE_SECOND                   = 1,
    
    MAX_DRAKKARI_CYCLE                      = 2,
};


//=========================================================
// Variables


#define MAX_SUMMON_POSITIONS_BY_PHASE   3
#define MAX_JUMP_POSITIONS_BY_PHASE     3

// Major trashes jump positions
static const Position farrakiWastewalkerJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5467.254395f, 5816.405762f, 129.902646f, 4.075048f },
    { 5483.035645f, 5790.856445f, 129.902646f, 3.160844f },
    { 5468.463867f, 5797.777344f, 129.902646f, 3.943101f },
};

static const Position gurubashiVenomPriestJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5498.676270f, 5716.721680f, 129.902646f, 1.986669f },
    { 5474.693359f, 5712.250000f, 129.902646f, 2.587496f },
    { 5465.093750f, 5962.224609f, 129.902646f, 2.188514f },
};

static const Position drakkariFrozenWarlordJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5400.352051f, 5693.921875f, 129.902646f, 0.728940f },
    { 5392.058105f, 5711.792969f, 129.902646f, 0.918221f },
    { 5371.409809f, 5728.193848f, 129.902646f, 0.607201f },
};

static const Position amaniWarbearJumpPositions[MAX_JUMP_POSITIONS_BY_PHASE] =
{
    { 5363.801270f, 5787.882812f, 129.902646f, 5.383204f },
    { 5385.030273f, 5793.059570f, 129.902646f, 5.625892f },
    { 5397.149902f, 5811.657227f, 129.902646f, 5.167220f },
};


// Summoning of minor and medium trashes positions
static const Position farrakiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5505.863281f, 5841.025391f, 130.537231f, 0.000000f },
    { 5514.541992f, 5841.049316f, 130.537231f, 0.000000f },
    { 5513.420898f, 5827.835938f, 130.537231f, 0.000000f },
};

static const Position gurubashiTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5520.958008f, 5675.670898f, 130.537231f, 0.000000f },
    { 5519.500000f, 5667.600098f, 130.537231f, 0.000000f },
    { 5509.516113f, 5668.375000f, 130.537231f, 0.000000f },
};

static const Position drakkariTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5358.775391f, 5662.011719f, 130.537231f, 0.000000f },
    { 5346.132324f, 5668.255859f, 130.537231f, 0.000000f },
    { 5346.598633f, 5677.144043f, 130.537231f, 0.000000f },
};

static const Position amaniTrashSummonPositions[MAX_SUMMON_POSITIONS_BY_PHASE] =
{
    { 5346.283203f, 5824.987305f, 130.537231f, 0.000000f },
    { 5348.529785f, 5839.762207f, 130.537231f, 0.000000f },
    { 5360.542969f, 5844.966309f, 130.537231f, 0.000000f },
};


// Jump positions for Zandalari Dinomancers
static const Position zandalariDinomancersJumpPositions[MAX_TRASH_PHASE][MAX_JUMP_POSITIONS_BY_PHASE] =
{
    {
        { 5467.254395f, 5816.405762f, 129.902646f, 4.075048f },
        { 5483.035645f, 5790.856445f, 129.902646f, 3.160844f },
        { 5468.463867f, 5797.777344f, 129.902646f, 3.943101f },
    },
    {
        { 5498.676270f, 5716.721680f, 129.902646f, 1.986669f },
        { 5474.693359f, 5712.250000f, 129.902646f, 2.587496f },
        { 5465.093750f, 5962.224609f, 129.902646f, 2.188514f },
    },
    {
        { 5400.352051f, 5693.921875f, 129.902646f, 0.728940f },
        { 5392.058105f, 5711.792969f, 129.902646f, 0.918221f },
        { 5371.409809f, 5728.193848f, 129.902646f, 0.607201f },
    },
    {
        { 5363.801270f, 5787.882812f, 129.902646f, 5.383204f },
        { 5385.030273f, 5793.059570f, 129.902646f, 5.625892f },
        { 5397.149902f, 5811.657227f, 129.902646f, 5.167220f },    
    }
};

// Summoning positions for Zandalari Dinomancers
static const Position zandalariDinomancersSummonPositions[] = 
{
    { 5326.83f,	5787.72f, 169.237f,	6.10253f },
    { 5536.14f,	5721.06f, 169.238f,	2.95279f },
    { 5325.51f,	5720.81f, 169.237f,	0.32948f },
    { 5418.50f,	5666.55f, 192.349f,	1.45472f },
    { 5447.01f,	5667.53f, 192.352f,	1.64919f },
    { 5340.08f,	5648.40f, 190.758f,	0.87616f },
    { 5521.05f,	5649.76f, 190.653f,	2.39193f },
    { 5537.03f,	5784.27f, 169.238f,	3.67703f },
    { 5534.14f,	5838.86f, 190.416f,	3.98585f },
    { 5377.32f,	5884.95f, 190.356f, 5.23621f },
};

// Relocation of Horridon's Home Position
static const Position middlePosition = { 5431.621094f, 5763.865723f, 129.606461f, 1.57860f };

// Jump position for Jalak
// static const Position jalakJumpPosition = { 0.0f, 0.0f, 0.0f, 0.0f };

//=========================================================
// Helper functions


static Creature *GetHorridon(WorldObject *source) 
{
    return ObjectAccessor::GetCreature(*source, source->GetInstanceScript()->GetData64(BOSS_HORRIDON));
}

static Creature *GetJalak(WorldObject *source)
{
    return ObjectAccessor::GetCreature(*source, source->GetInstanceScript()->GetData64(MOB_WAR_GOD_JALAK));
}

static Creature *GetHorridonHelper(WorldObject *source)
{
    return ObjectAccessor::GetCreature(*source, source->GetInstanceScript()->GetData64(NPC_HORRIDON_EVENT_HELPER));
}

static GameObject *GetDoorByPhase(eTrashPhases phase, WorldObject *source)
{
    switch(phase)
    {
    case TRASH_PHASE_FARRAKI:
        return ObjectAccessor::GetGameObject(*source, source->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_FARRAKI));

    case TRASH_PHASE_GURUBASHI:
        return ObjectAccessor::GetGameObject(*source, source->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_GURUBASHI));

    case TRASH_PHASE_DRAKKARI:
        return ObjectAccessor::GetGameObject(*source, source->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_DRAKKARI));

    case TRASH_PHASE_AMANI:
        return ObjectAccessor::GetGameObject(*source, source->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_AMANI));

    default:
        return NULL;
    }
}

static GameObject *GetDoorByOrb(GameObject *orb)
{
    switch(orb->GetEntry())
    {
    case GOB_ORB_OF_CONTROL_FARRAKI:
        return ObjectAccessor::GetGameObject(*orb, orb->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_FARRAKI));

    case GOB_ORB_OF_CONTROL_GURUBASHI:
        return ObjectAccessor::GetGameObject(*orb, orb->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_GURUBASHI));

    case GOB_ORB_OF_CONTROL_DRAKKARI:
        return ObjectAccessor::GetGameObject(*orb, orb->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_DRAKKARI));

    case GOB_ORB_OF_CONTROL_AMANI:
        return ObjectAccessor::GetGameObject(*orb, orb->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_AMANI));

    default:
        return NULL;
    }
}

static GameObject *GetDoorBySpell(uint32 uiSpellId, WorldObject *pSource)
{
    switch(uiSpellId)
    {
    case SPELL_CONTROL_HORRIDON_FARRAKI:
        return ObjectAccessor::GetGameObject(*pSource, pSource->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_FARRAKI));

    case SPELL_CONTROL_HORRIDON_GURUBASHI:
        return ObjectAccessor::GetGameObject(*pSource, pSource->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_GURUBASHI));

    case SPELL_CONTROL_HORRIDON_DRAKKARI:
        return ObjectAccessor::GetGameObject(*pSource, pSource->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_DRAKKARI));

    case SPELL_CONTROL_HORRIDON_AMANI:
        return ObjectAccessor::GetGameObject(*pSource, pSource->GetInstanceScript()->GetData64(GOB_TRIBAL_DOOR_AMANI));

    default:
        return 0;
    }
}

static uint32 GetSummoningOrbSpellByPhase(eTrashPhases phase)
{
    switch(phase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_SUMMON_ORB_OF_CONTROL_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_SUMMON_ORB_OF_CONTROL_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_SUMMON_ORB_OF_CONTROL_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_SUMMON_ORB_OF_CONTROL_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByOrb(GameObject *pOrb)
{
    switch(pOrb->GetEntry())
    {
    case GOB_ORB_OF_CONTROL_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case GOB_ORB_OF_CONTROL_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case GOB_ORB_OF_CONTROL_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case GOB_ORB_OF_CONTROL_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}

static uint32 GetControlSpellByPhase(eTrashPhases ePhase)
{
    switch(ePhase)
    {
    case TRASH_PHASE_FARRAKI:
        return SPELL_CONTROL_HORRIDON_FARRAKI;

    case TRASH_PHASE_GURUBASHI:
        return SPELL_CONTROL_HORRIDON_GURUBASHI;

    case TRASH_PHASE_DRAKKARI:
        return SPELL_CONTROL_HORRIDON_DRAKKARI;

    case TRASH_PHASE_AMANI:
        return SPELL_CONTROL_HORRIDON_AMANI;

    default:
        return 0;
    }
}


static Position GetChargePositionByDoor(GameObject *pDoor)
{
    switch(pDoor->GetEntry())
    {
    case GOB_TRIBAL_DOOR_FARRAKI:
        return { 5502.53f, 5826.19f, 130.53f, 0.82f };
        
    case GOB_TRIBAL_DOOR_GURUBASHI:
        return { 5501.19f, 5865.15f, 130.53f, 5.39f };
        
    case GOB_TRIBAL_DOOR_DRAKKARI:
        return { 5361.72f, 5863.75f, 130.53f, 3.89f };
        
    case GOB_TRIBAL_DOOR_AMANI:
        return { 5363.09f, 5823.77f, 130.53f, 2.35f };
        
    default:
        return { 0.0f, 0.0f, 0.0f, 0.0f };
    }
}
//=========================================================
// Creature Scripts


// Helper AI
class npc_horridon_event_helper : public CreatureScript
{
public:
    npc_horridon_event_helper() : CreatureScript("npc_horrion_event_helper") { }

    class npc_horridon_event_helper_AI : public ScriptedAI
    {
    public:
        npc_horridon_event_helper_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())
        {
            events.Reset();
            summons.clear();
            jumpers.clear();

            uiTrashPhase    = MAX_TRASH_PHASE;
            uiMinorTrashId  = 0;
            memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
            uiMajorTrashId  = 0;
            uiMajorCycle    = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;

            summonPositions = NULL;
            jumpPositions   = NULL;
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_FIGHT_BEGIN:
                FightBegin();
                break;

            case ACTION_ENTER_NEXT_TRASH_PHASE:
                EnterNextPhase();
                break;

            case ACTION_FIGHT_RESET:
                FightReset();
                break;
                
            case ACTION_FIGHT_END:
                FightEnd();
                break;
                
            case ACTION_PREPARE_TRANSITION:
                PrepareTransition();
                break;

            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(uiTrashPhase == MAX_TRASH_PHASE)
                return;

            events.Update(uiDiff);

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_SUMMON_MINOR:
                    if(summonPositions)
                    {
                        std::list<uint32> entries;

                        if(uiMinorTrashId)
                            entries.push_back(uiMinorTrashId);
                        if(uiMediumTrashId[0])
                            entries.push_back(uiMediumTrashId[0]);
                        if(uiMediumTrashId[1])
                            entries.push_back(uiMediumTrashId[1]);

                        if(entries.empty()) // Entries is empty, no need to reschedule event
                            break;

                        for(uint8 i = 0; i < MAX_SUMMON_POSITIONS_BY_PHASE; ++i)
                        {
                            uint32 uiSummonEntry = Trinity::Containers::SelectRandomContainerElement(entries);
                            me->SummonCreature(uiSummonEntry, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                        }

                        if(GameObject *pDoor = GetDoorByPhase((eTrashPhases)uiTrashPhase, me))
                            pDoor->Use(me);

                        events.ScheduleEvent(EVENT_SUMMON_MINOR, urand(10, 20) * IN_MILLISECONDS);
                    }
                    break;

                case EVENT_SUMMON_MAJOR:
                    if(jumpPositions)
                    {
                        std::list<Creature*> majors;
                        GetCreatureListWithEntryInGrid(majors, me, uiMajorTrashId, 50000.0f);

                        if(!majors.empty())
                        {
                            if(uiMajorCycle == MAJOR_CYCLE_FIRST)
                            {
                                if(Creature *pCreature = Trinity::Containers::SelectRandomContainerElement(majors))
                                {
                                    pCreature->GetMotionMaster()->MoveJump(jumpPositions[urand(0, MAX_JUMP_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_MAJOR_JUMP);
                                    jumpers.push_back(pCreature);
                                }
                            }
                            else
                            {
                                for(Creature *pCreature: majors)
                                {
                                    if(!pCreature->IsInCombat())
                                    {
                                        pCreature->GetMotionMaster()->MoveJump(jumpPositions[urand(0, MAX_JUMP_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_MAJOR_JUMP);
                                        jumpers.push_back(pCreature);
                                    }
                                }
                            }
                        }
                        
                        ++uiMajorCycle;
                        events.ScheduleEvent(EVENT_SUMMON_MAJOR, 20 * IN_MILLISECONDS);
                    }
                    break;

                case EVENT_SUMMON_ZANDALARI_DINOMANCER:
                {
                    Position const summonPosition = zandalariDinomancersSummonPositions[urand(0, 9)];
                    if(Creature *pDinomancer = me->SummonCreature(MOB_ZANDALARI_DINOMANCER, summonPosition))
                        pDinomancer->GetMotionMaster()->MoveJump(zandalariDinomancersJumpPositions[uiTrashPhase][urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)], 20.0f, 42.0f, MOTION_DINOMANCER_JUMP);
                    events.ScheduleEvent(EVENT_SUMMON_ZANDALARI_DINOMANCER, MINUTE * IN_MILLISECONDS);
                    break;
                }
                
                case EVENT_SUMMON_MINOR_DRAKKARI:
                {
                    switch(uiDrakkariCycle)
                    {
                    case DRAKKARI_CYCLE_FIRST:
                        uiDrakkariCycle = DRAKKARI_CYCLE_SECOND;
                        if(summonPositions)
                        {
                            me->SummonCreature(MOB_RISEN_DRAKKARI_CHAMPION, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            me->SummonCreature(MOB_RISEN_DRAKKARI_WARRIOR, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI, urand(6, 10) * IN_MILLISECONDS);
                        }
                        break;
                        
                    case DRAKKARI_CYCLE_SECOND:
                        uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;
                        if(summonPositions)
                        {
                            me->SummonCreature(MOB_RISEN_DRAKKARI_CHAMPION, summonPositions[urand(0, MAX_SUMMON_POSITIONS_BY_PHASE - 1)]);
                            events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI, urand(8, 15) * IN_MILLISECONDS);
                        }
                        break;
                    }
                    
                    if(GameObject *pDoor = GetDoorByPhase((eTrashPhases)uiTrashPhase, me))
                        pDoor->Use(me);
                    break;
                }
                
                case EVENT_TRANSITION:
                    EnterNextPhase();
                    break;

                default:
                    break;
                }
            }
        }

        void JustSummoned(Creature *pSummoned)
        {
            summons.push_back(pSummoned);
        }
        
        void SummonedCreatureDespawn(Creature *pSummoned)
        {
            summons.remove(pSummoned);
        }

        eTrashPhases GetTrashPhase() const
        {
            return (eTrashPhases)uiTrashPhase;
        }

    private:
        EventMap                events;
        InstanceScript          *pInstance;
        const Position*         summonPositions;
        const Position*         jumpPositions;
        std::list<Creature*>    summons;
        std::list<Creature*>    jumpers;
        uint32                  uiTrashPhase;
        uint32                  uiMinorTrashId;
        uint32                  uiMediumTrashId[2];
        uint32                  uiMajorTrashId;
        uint32                  uiMajorCycle;
        uint32                  uiDrakkariCycle;

        void FightReset()
        {
            // Be sure that we have not already reset
            if(uiTrashPhase == MAX_TRASH_PHASE && summonPositions == NULL && jumpPositions == NULL)
                return;

            // Despawn all the summoned creatures
            /*for(Creature *pCreatureIter: summons)
                pCreatureIter->DespawnOrUnsummon();*/

            // Respawn dead jumpers
            for(Creature *pCreatureIter: jumpers)
            {
                if(pCreatureIter->isDead())
                {
                    pCreatureIter->Respawn();
                    if(pCreatureIter->AI())
                        pCreatureIter->AI()->EnterEvadeMode();
                }

                // Creature will automatically reset because it is registered in DB; no need to make them
                // return to home position or Reset() them.
            }

            // Boss reset by themselves, but won't revive if dead
            if(Creature *pHorridon = GetHorridon(me))
            {
                if(pHorridon->isDead())
                    pHorridon->Respawn();
            }

            if(Creature *pWarGodJalak = GetJalak(me))
            {
                if(pWarGodJalak->isDead())
                {
                    pWarGodJalak->Respawn();
                    pWarGodJalak->AI()->EnterEvadeMode();
                }
            }

            events.Reset();
            summons.clear();
            jumpers.clear();

            uiTrashPhase    = MAX_TRASH_PHASE;
            uiMinorTrashId  = 0;
            memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
            uiMajorTrashId  = 0;
            uiMajorCycle    = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;

            summonPositions = NULL;
            jumpPositions   = NULL;
        }

        void FightBegin()
        {
            uiTrashPhase        = TRASH_PHASE_FARRAKI;
            uiMinorTrashId      = MOB_SUL_LITHUZ_STONEGAZER;
            uiMediumTrashId[0]  = MOB_FARRAKI_SKIRMISHER;
            uiMediumTrashId[1]  = 0;
            uiMajorTrashId      = MOB_FARRAKI_WASTEWALKER;
            summonPositions     = farrakiTrashSummonPositions;
            jumpPositions       = farrakiWastewalkerJumpPositions;
            
            if(Creature *pJalak = GetJalak(me))
                pJalak->AI()->Talk(TALK_FARRAKI);

            events.ScheduleEvent(EVENT_SUMMON_MINOR, 5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUMMON_MAJOR, 20 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_SUMMON_ZANDALARI_DINOMANCER, MINUTE * IN_MILLISECONDS);
        }
        
        void FightEnd()
        {
            // Cause crash...
            /*for(Creature *pIter: summons)
                pIter->DespawnOrUnsummon();
            
            for(Creature *pIter: jumpers)
                pIter->DespawnOrUnsummon();*/
                
            summons.clear();
            jumpers.clear();
            events.Reset();
            
            uiTrashPhase = MAX_TRASH_PHASE;
        }

        void EnterNextPhase()
        {
            uiMajorCycle    = MAJOR_CYCLE_FIRST;
            uiDrakkariCycle = DRAKKARI_CYCLE_FIRST;
            
            ++uiTrashPhase;
            if(Creature *pJalak = GetJalak(me))
            {
                switch(uiTrashPhase)
                {
                case TRASH_PHASE_FARRAKI:
                    break;

                case TRASH_PHASE_GURUBASHI:
                    uiMinorTrashId      = MOB_GURUBASHI_BLOODLORD;
                    uiMajorTrashId      = MOB_GURUBASHI_VENOM_PRIEST;
                    memset(&uiMediumTrashId, 0, sizeof(uiMediumTrashId));
                    summonPositions     = gurubashiTrashSummonPositions;
                    jumpPositions       = gurubashiVenomPriestJumpPositions;
                    pJalak->AI()->Talk(TALK_GURUBASHI);
                    break;

                case TRASH_PHASE_DRAKKARI:
                    uiMajorTrashId      = MOB_DRAKKARI_FROZEN_WARLORD;
                    summonPositions     = drakkariTrashSummonPositions;
                    jumpPositions       = drakkariFrozenWarlordJumpPositions;
                    pJalak->AI()->Talk(TALK_DRAKKARI);
                    break;

                case TRASH_PHASE_AMANI:
                    uiMinorTrashId      = MOB_AMANI_SHI_PROTECTOR;
                    uiMediumTrashId[0]  = MOB_AMANI_SHI_FLAME_CASTER;
                    uiMediumTrashId[1]  = 0;
                    uiMajorTrashId      = MOB_AMANI_WARBEAR;
                    summonPositions     = amaniTrashSummonPositions;
                    jumpPositions       = amaniWarbearJumpPositions;
                    pJalak->AI()->Talk(TALK_AMANI);
                    break;

                case MAX_TRASH_PHASE:
                    if(Creature *pJalak = GetJalak(me))
                        pJalak->AI()->DoAction(ACTION_ENTER_PHASE_TWO);
                    return;

                default:
                    return;
                }

                events.Reset();

                
                if(uiTrashPhase != TRASH_PHASE_DRAKKARI)
                {
                    events.ScheduleEvent(EVENT_SUMMON_MINOR,                 5 * IN_MILLISECONDS);
                }
                else
                {
                    events.ScheduleEvent(EVENT_SUMMON_MINOR_DRAKKARI,        5 * IN_MILLISECONDS);
                }
                                
                events.ScheduleEvent(EVENT_SUMMON_MAJOR,                20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_ZANDALARI_DINOMANCER, 30 * IN_MILLISECONDS);
            }
        }
        
        void PrepareTransition()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_TRANSITION, 45 * IN_MILLISECONDS);
        }
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_horridon_event_helper_AI, Creature>(pCreature);
    }
};
typedef npc_horridon_event_helper::npc_horridon_event_helper_AI HorridonHelperAI;


// RP Event Helper AI
class npc_horridon_rp_event_helper : public CreatureScript
{
public:
    npc_horridon_rp_event_helper() : CreatureScript("npc_horridon_rp_event_helper") { }
    
    class npc_horridon_rp_event_helper_AI : public ScriptedAI
    {
    public:
        npc_horridon_rp_event_helper_AI(Creature *pCreature):
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), bIntroDone(false)
        {
            events.Reset();
        }
        
        void Reset()
        {
            bIntroDone = false;
            events.Reset();
            events.ScheduleEvent(EVENT_CHECK_PLAYERS, 500);
        }
        
        void UpdateAI(uint32 uiDiff)
        {
            if(bIntroDone)
                return;
                
            events.Update(uiDiff);
            
            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_CHECK_PLAYERS:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 25.0f);
                    
                    if(playerList.empty())
                    {
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 500);
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_INTRO_PART_I, 1000);
                        events.ScheduleEvent(EVENT_INTRO_PART_II, 7500);
                        events.ScheduleEvent(EVENT_INTRO_PART_III, 27500);
                        events.ScheduleEvent(EVENT_INTRO_PART_IV, 29500);
                    }
                    
                    break;
                }
                
                case EVENT_INTRO_PART_I:
                    if(Creature *pJalak = GetJalak(me))
                        pJalak->AI()->Talk(TALK_INTRO_FIRST);
                    break;
                    
                case EVENT_INTRO_PART_II:
                    if(Creature *pJalak = GetJalak(me))
                        pJalak->AI()->Talk(TALK_INTRO_SECOND);
                    break;
                  
                case EVENT_INTRO_PART_III:
                    if(Creature *pJalak = GetJalak(me))
                        pJalak->AI()->Talk(TALK_INTRO_THIRD);
                    
                    // Shatter door here, to simulate Horridon is breaking it
                    if(GameObject *pDoor = me->FindNearestGameObject(GOB_HORRIDON_PRISON_DOOR, 50000.0f))
                        pDoor->SetGoState(GO_STATE_ACTIVE);
                    break;
                    
                case EVENT_INTRO_PART_IV:
                    if(Creature *pHorridon = GetHorridon(me))
                        pHorridon->AI()->DoAction(ACTION_INTRO);
                    bIntroDone = true;
                    break;
                    
                default:
                    break;
                }
            }
        }
        
    private:
        EventMap        events;
        InstanceScript  *pInstance;
        
        bool            bIntroDone;
    };
    
    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<npc_horridon_rp_event_helper_AI, Creature>(pCreature);
    }
};


// Horridon AI
class boss_horridon : public CreatureScript
{
public:
    boss_horridon() : CreatureScript("boss_horridon") { }

    class boss_horridon_AI : public ScriptedAI
    {
    public:
        boss_horridon_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), bJalakCalled(false)
        {
            pChargeDoor = NULL;
            events.Reset();
        }

        void Reset()
        {
            pInstance->SetBossState(DATA_HORRIDON, NOT_STARTED);

            events.Reset();
            pChargeDoor = NULL;
            bJalakCalled = false;

            me->RemoveAurasDueToSpell(SPELL_HEADACHE);
            me->RemoveAurasDueToSpell(SPELL_CRACKED_SHELL);
            me->RemoveAurasDueToSpell(SPELL_RAMPAGE);

            if(Creature *pHorridonHelper = GetHorridonHelper(me))
            {
                if(CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_RESET);
            }
        }

        void EnterCombat(Unit *pVictim)
        {
            pInstance->SetBossState(DATA_HORRIDON, IN_PROGRESS);
            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

            events.ScheduleEvent(EVENT_TRIPLE_PUNCTURE, 10 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_DOUBLE_SWIPE,    15 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HORRIDON_CHARGE, 13 * IN_MILLISECONDS);

            if(IsHeroic())
                events.ScheduleEvent(EVENT_DIRE_CALL,   8 * IN_MILLISECONDS);

            if(Creature *pHorridonHelper = GetHorridonHelper(me))
            {
                if(CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_BEGIN);
            }
        }
        
        void DoAction(int32 iAction)
        {
            switch(iAction)
            {                
            case ACTION_INTRO:                    
                me->GetMotionMaster()->MoveCharge(middlePosition.GetPositionX(), middlePosition.GetPositionY(), middlePosition.GetPositionZ(), 42.0f, MOTION_HORRIDON_CHARGE);
                me->SetHomePosition(middlePosition);
                break;
                
            default:
                break;
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;
                
            if(HealthBelowPct(30) && !bJalakCalled)
            {
                bJalakCalled = true;
                if(Creature *pJalak = GetJalak(me))
                {
                    if(CreatureAI* pJalakAI = pJalak->AI())
                        pJalakAI->DoAction(ACTION_ENTER_PHASE_TWO);
                }
            }

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_TRIPLE_PUNCTURE:
                    if(Unit *pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_TRIPLE_PUNCTURE);
                    events.ScheduleEvent(EVENT_TRIPLE_PUNCTURE, urand(10, 15) * IN_MILLISECONDS);
                    break;

                case EVENT_DOUBLE_SWIPE:
                    DoCastAOE(SPELL_DOUBLE_SWIPE);
                    events.ScheduleEvent(EVENT_DOUBLE_SWIPE, urand(12, 18) * IN_MILLISECONDS);
                    break;

                case EVENT_HORRIDON_CHARGE:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                        DoCast(pTarget, SPELL_CHARGE);
                    events.ScheduleEvent(EVENT_HORRIDON_CHARGE, urand(15, 25) * IN_MILLISECONDS);
                    break;

                case EVENT_DIRE_CALL:
                    DoCastAOE(SPELL_DIRE_CALL);
                    events.ScheduleEvent(EVENT_DIRE_CALL, urand(8, 15) * IN_MILLISECONDS);
                    break;
                    
                case EVENT_CHARGE_AT_DOOR:
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit *pKiller)
        {
            if(GetJalak(me) && GetJalak(me)->isDead())
            {
                pInstance->SetBossState(DATA_HORRIDON, DONE);
                if(Creature *pController = GetHorridonHelper(me))
                    pController->AI()->DoAction(ACTION_FIGHT_END);
            }

            pInstance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if(uiMotionType == EFFECT_MOTION_TYPE)
            {
                switch(uiMovementId)
                {
                case EVENT_CHARGE:
                    DoCastAOE(SPELL_DOUBLE_SWIPE);
                    break;

                default:
                    break;
                }
            }
        }
        
        void KilledUnit(Unit *pKilled)
        {
            if(Creature *pJalak = GetJalak(me))
                pJalak->AI()->Talk(TALK_ON_HORRIDON_KILLED_UNIT);
        }

        void ChargeAtDoor(GameObject *pDoor)
        {
            if(!pDoor)
                return;
                
            pChargeDoor = pDoor;
            Position chargePosition = GetChargePositionByDoor(pDoor);
            me->GetMotionMaster()->MoveCharge(chargePosition.GetPositionX(), chargePosition.GetPositionY(), chargePosition.GetPositionZ(), 42.0f, MOTION_HORRIDON_DOOR_CHARGE);
            DoCast(me, SPELL_HEADACHE);
        }

    private:
        EventMap        events;
        GameObject      *pChargeDoor;
        InstanceScript  *pInstance;
        bool            bJalakCalled;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<boss_horridon_AI, Creature>(pCreature);
    }
};
typedef boss_horridon::boss_horridon_AI HorridonAI;


// Jalak AI
class mob_war_god_jalak : public CreatureScript
{
public:
    mob_war_god_jalak() : CreatureScript("mob_war_god_jalak") { }

    class mob_war_god_jalak_AI : public ScriptedAI
    {
    public:
        mob_war_god_jalak_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), uiPhase(BOSS_PHASE_SUMMONS)
        {

        }

        void Reset()
        {
            events.Reset();
            uiPhase = BOSS_PHASE_SUMMONS;

            if(Creature *pHorridonHelper = GetHorridonHelper(me))
            {
                if(CreatureAI* pHelperAI = pHorridonHelper->AI())
                    pHelperAI->DoAction(ACTION_FIGHT_RESET);
            }
        }

        void DoAction(int32 iAction)
        {
            switch(iAction)
            {
            case ACTION_ENTER_PHASE_TWO:
                if(uiPhase != BOSS_PHASE_JALAK)
                {
                    Talk(TALK_ENTER_PHASE_2);
                    uiPhase = BOSS_PHASE_JALAK;

                    if(Creature* pHorridon = GetHorridon(me))
                    {
                        Position toRelocate = *pHorridon;
                        Position relocater  = { frand(0.0f, 5.0f), frand(0.0f, 5.0f), 0.0f, 0.0f };
                        toRelocate.RelocateOffset(relocater);
                        me->GetMotionMaster()->MoveJump(toRelocate, 32.0f, 32.0f);
                    }
                }
                break;
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if(uiMotionType == EFFECT_MOTION_TYPE)
            {
                switch(uiMovementId)
                {
                case EVENT_JUMP:
                {
                    me->SetInCombatWithZone();
                    std::list<Player*> playerList;

                    me->GetPlayerListInGrid(playerList, 500.0f);
                    playerList.sort([this](Player const* first, Player const* second) -> bool
                    {
                        return first->GetExactDist2d(this->me) < second->GetExactDist2d(this->me);
                    });

                    if(!playerList.empty() && playerList.front())
                    {
                        Player *pFirst = playerList.front();
                        me->AddThreat(pFirst, 100000.0f);
                        ScriptedAI::AttackStart(pFirst);
                    }

                    break;
                }

                default:
                    break;
                }
            }
        }

        void EnterCombat(Unit *pVictim)
        {
            events.ScheduleEvent(EVENT_BESTIAL_CRY, 10 * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(uiPhase == BOSS_PHASE_SUMMONS)
                return;

            if(!UpdateVictim())
                return;

            events.Update(uiDiff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_BESTIAL_CRY:
                    DoCastAOE(SPELL_BESTIAL_CRY);
                    events.ScheduleEvent(EVENT_BESTIAL_CRY, urand(10, 20) * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
        
        void KilledUnit(Unit *pKilled)
        {
            Talk(TALK_ON_JALAK_KILLED_UNIT);
        }

        void JustDied(Unit *pKiller)
        {
            if(GetHorridon(me) && GetHorridon(me)->isDead())
            {
                pInstance->SetBossState(DATA_HORRIDON, DONE);
                if(Creature *pController = GetHorridonHelper(me))
                    pController->AI()->DoAction(ACTION_FIGHT_END);
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        uint32          uiPhase;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_war_god_jalak_AI, Creature>(pCreature);
    }
};


// Trashs AI (does not include summons of spells)
class mob_horridon_trashs : public CreatureScript
{
public:
    mob_horridon_trashs() : CreatureScript("mob_horridon_trashs") { }

    class mob_horridon_trashs_AI : public ScriptedAI
    {
    public:
        mob_horridon_trashs_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()),
            pRendingChargeTarget(NULL), uiChainLightningCount(0)
        {
            events.Reset();
        }

        void Reset()
        {
            events.Reset();
            pRendingChargeTarget = NULL;
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 500.0f);
            playerList.sort(Trinity::DistanceCompareOrderPred(me, true));
            
            if(!playerList.empty() && playerList.front())
            {
                Player *pPlayer = playerList.front();
                me->SetInCombatWith(pPlayer);
                ScriptedAI::AttackStart(pPlayer);
            }
            else
                me->DisappearAndDie();

            // Schedule events
            switch(me->GetEntry())
            {
            case MOB_SUL_LITHUZ_STONEGAZER:
                events.ScheduleEvent(EVENT_STONE_GAZE,                          5 * IN_MILLISECONDS);
                break;

            case MOB_GURUBASHI_BLOODLORD:
                events.ScheduleEvent(EVENT_RENDING_CHARGE,                      5 * IN_MILLISECONDS);
                break;

            case MOB_RISEN_DRAKKARI_CHAMPION:
            case MOB_RISEN_DRAKKARI_WARRIOR:
                DoCast(me, SPELL_UNCONTROLLED_ABOMINATION);
                events.ScheduleEvent(EVENT_SWITCH_TARGET,                       10 * IN_MILLISECONDS);
                break;

            case MOB_AMANI_SHI_FLAME_CASTER:
                events.ScheduleEvent(EVENT_FIREBALL,                            5 * IN_MILLISECONDS);
                break;
                
            case MOB_AMANI_SHI_BEAST_SHAMAN:
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING,                     5 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEX_OF_CONFUSION,                    10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_LIGHTNING_NOVA_TOTEM,         15 * IN_MILLISECONDS);
                break;

            default:
                break;
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if(uiMotionType == EFFECT_MOTION_TYPE)
            {
                switch(uiMovementId)
                {
                case MOTION_MAJOR_JUMP:
                    me->SetInCombatWithZone(); // Call it now to not bug the npcs around
                    // Schedule events first
                    switch(me->GetEntry())
                    {
                    case MOB_FARRAKI_WASTEWALKER:
                        events.ScheduleEvent(EVENT_BLAZING_LIGHT,               10 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SUMMON_SAND_TRAP,            15 * IN_MILLISECONDS);
                        break;

                    case MOB_GURUBASHI_VENOM_PRIEST:
                        events.ScheduleEvent(EVENT_GURUBASHI_VENOM_BOLT_VOLLEY, 10 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SUMMON_VENOMOUS_EFFUSION,    15 * IN_MILLISECONDS);
                        break;

                    case MOB_DRAKKARI_FROZEN_WARLORD:
                        events.ScheduleEvent(EVENT_MORTAL_STRIKE,               10 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_SUMMON_FROZEN_ORB,           15 * IN_MILLISECONDS);
                        break;

                    case MOB_AMANI_WARBEAR:
                        events.ScheduleEvent(EVENT_SWIPE,                       10 * IN_MILLISECONDS);
                        break;

                    default:
                        break;
                    }
                    
                    // Then select a target and move towards it (must be using Horridon AI to select targets)
                    if(Creature *pHorridon = GetHorridon(me))
                    {
                        if(CreatureAI *pHorridonAI = pHorridon->AI())
                        {
                            if(Unit *pTarget = pHorridonAI->SelectTarget(SELECT_TARGET_RANDOM))
                            {
                                me->SetInCombatWith(pTarget);
                                ScriptedAI::AttackStart(pTarget);
                            }
                        }
                    }
                    break;

                case EVENT_CHARGE:
                    DoCast(pRendingChargeTarget, SPELL_RENDING_CHARGE_DAMAGES);
                    break;

                default:
                    break;
                }
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
                // Farraki
                case EVENT_STONE_GAZE:
                    if(Unit *pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_STONE_GAZE);

                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_STONE_GAZE))
                        ScriptedAI::AttackStart(pTarget);

                    events.ScheduleEvent(EVENT_STONE_GAZE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_BLAZING_LIGHT:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_BLAZING_SUNLIGHT))
                        DoCast(pTarget, SPELL_BLAZING_SUNLIGHT);
                    events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_SAND_TRAP:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_SUMMON_SAND_TRAP);
                    events.ScheduleEvent(EVENT_SUMMON_SAND_TRAP, 30 * IN_MILLISECONDS);
                    break;

                // Gurubashi
                case EVENT_RENDING_CHARGE:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    {
                        pRendingChargeTarget = pTarget;
                        DoCast(pTarget, SPELL_RENDING_CHARGE);
                    }
                    events.ScheduleEvent(EVENT_RENDING_CHARGE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_GURUBASHI_VENOM_BOLT_VOLLEY:
                    DoCastAOE(SPELL_VENOM_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_GURUBASHI_VENOM_BOLT_VOLLEY, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_VENOMOUS_EFFUSION:
                    DoCast(me, SPELL_SUMMON_VENOMOUS_EFFUSION);
                    events.ScheduleEvent(EVENT_SUMMON_VENOMOUS_EFFUSION, 30 * IN_MILLISECONDS);
                    break;

                // Drakkari
                case EVENT_SWITCH_TARGET:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    {
                        DoResetThreat();
                        me->AddThreat(pTarget, 100000.0f);
                        ScriptedAI::AttackStart(pTarget);
                    }
                    events.ScheduleEvent(EVENT_SWITCH_TARGET, 7 * IN_MILLISECONDS);
                    break;

                case EVENT_MORTAL_STRIKE:
                    if(Unit *pVictim = me->GetVictim())
                        DoCast(pVictim, SPELL_MORTAL_STRIKE);
                    events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_FROZEN_ORB:
                    DoCast(me, SPELL_SUMMON_FROZEN_ORB);
                    events.ScheduleEvent(EVENT_SUMMON_FROZEN_ORB, 30 * IN_MILLISECONDS);
                    break;

                // Amani
                case EVENT_FIREBALL:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pTarget, SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SWIPE:
                    DoCastAOE(SPELL_SWIPE);
                    events.ScheduleEvent(EVENT_SWIPE, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_CHAIN_LIGHTNING:
                    if(Unit *pPrimaryTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(pPrimaryTarget, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_HEX_OF_CONFUSION:
                    if(Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_HEX_OF_CONFUSION))
                        DoCast(pTarget, SPELL_HEX_OF_CONFUSION);
                    events.ScheduleEvent(EVENT_HEX_OF_CONFUSION, 10 * IN_MILLISECONDS);
                    break;

                case EVENT_SUMMON_LIGHTNING_NOVA_TOTEM:
                    DoCast(me, SPELL_SUMMON_LIGHTNING_NOVA_TOTEM);
                    events.ScheduleEvent(EVENT_SUMMON_LIGHTNING_NOVA_TOTEM, 30 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit *pKiller)
        {
            if(me->GetEntry() == MOB_AMANI_WARBEAR)
            {
                if(Vehicle *pKit = me->GetVehicleKit())
                    pKit->RemoveAllPassengers(); // Check this >_<
                else
                    me->SummonCreature(MOB_AMANI_SHI_BEAST_SHAMAN, *me);
            }
        }

        uint32 GetData(uint32 uiIndex) const
        {
            if(uiIndex == DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT)
                return uiChainLightningCount;

            return 0;
        }

        void SetData(uint32 uiIndex, uint32 uiValue)
        {
            if(uiIndex == DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT)
            {
                if(++uiChainLightningCount == 3)
                    uiChainLightningCount = 0;
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        Unit            *pRendingChargeTarget;
        uint32          uiChainLightningCount;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_horridon_trashs_AI, Creature>(pCreature);
    }
};


// Summons AI
class mob_horridon_summons : public CreatureScript
{
public:
    mob_horridon_summons() : CreatureScript("mob_horridon_summons") { }

    class mob_horridon_summons_AI : public ScriptedAI
    {
    public:
        mob_horridon_summons_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript())/*, fSandTrapRadius(0.0f) */
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            // me->SetReactState(REACT_PASSIVE);
            events.Reset();
        }

        void IsSummonedBy(Unit *pSummoner)
        {
            me->SetInCombatWithZone();
            switch(me->GetEntry())
            {
            case MOB_SAND_TRAP:
                // fSandTrapRadius = 3.0f;
                DoCast(me, SPELL_SAND_TRAP_PERIODIC);
                break;

            case MOB_VENOMOUS_EFFUSION:
                DoCast(me, SPELL_SUMMON_LIVING_POISON);
                events.ScheduleEvent(EVENT_EFFUSION_VENOM_BOLT_VOLLEY, 10 * IN_MILLISECONDS);
                break;

            case MOB_FROZEN_ORB:
                DoCast(me, SPELL_FROZEN_BOLT_PERIODIC);
                break;

            case MOB_LIGHTNING_NOVA_TOTEM:
                DoCast(me, SPELL_LIGHTNING_NOVA_PERIODIC);
                break;

            case MOB_LIVING_POISON:
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                DoCast(me, SPELL_LIVING_POISON_PERIODIC);
                me->GetMotionMaster()->MovementExpired();
                me->GetMotionMaster()->MoveRandom(5.0f);
                break;

            default:
                break;
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
                case EVENT_EFFUSION_VENOM_BOLT_VOLLEY:
                    DoCastAOE(SPELL_VENOM_BOLT_VOLLEY);
                    events.ScheduleEvent(EVENT_EFFUSION_VENOM_BOLT_VOLLEY, 5 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        // float           fSandTrapRadius;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_horridon_summons_AI, Creature>(pCreature);
    }
};
typedef mob_horridon_summons::mob_horridon_summons_AI HorridonSummonsAI;


// Zandalari Dinomancer AI
class mob_zandalari_dinomancer : public CreatureScript
{
public:
    mob_zandalari_dinomancer() : CreatureScript("mob_zandalari_dinomancer") { }

    class mob_zandalari_dinomancer_AI : public ScriptedAI
    {
    public:
        mob_zandalari_dinomancer_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pInstance(pCreature->GetInstanceScript()), bIsUnderFiftyPercent(false)
        {
            events.Reset();
        }

        void MovementInform(uint32 uiMotionType, uint32 uiMovementId)
        {
            if(uiMotionType == EFFECT_MOTION_TYPE && uiMovementId == MOTION_DINOMANCER_JUMP)
            {
                me->SetInCombatWithZone();
                if(Creature *pHorridon = GetHorridon(me))
                {
                    // me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    DoCast(pHorridon, SPELL_DINO_MENDING);
                    events.ScheduleEvent(EVENT_DINO_MENDING, 30 * IN_MILLISECONDS);
                }
            }
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            events.Update(uiDiff);


            if(HealthBelowPct(50) && !bIsUnderFiftyPercent)
            {
                bIsUnderFiftyPercent = true;

                me->InterruptNonMeleeSpells(true);
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                // me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                if(Creature *pHelper = GetHorridonHelper(me))
                {
                    if(HorridonHelperAI* pHelperAI = dynamic_cast<HorridonHelperAI*>(pHelper->AI()))
                    {
                        if(uint32 uiSummonSpellId = GetSummoningOrbSpellByPhase(pHelperAI->GetTrashPhase()))
                            DoCast(me, uiSummonSpellId);
                    }
                }

                events.CancelEvent(EVENT_DINO_MENDING);
                DoCast(me, SPELL_DINO_FORM);
            }

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;
                
            while(uint32 uiEventId = events.ExecuteEvent())
            {
                switch(uiEventId)
                {
                case EVENT_DINO_MENDING:
                    if(Creature *pHorridon = GetHorridon(me))
                        DoCast(pHorridon, SPELL_DINO_MENDING);
                    events.ScheduleEvent(EVENT_DINO_MENDING, 30 * IN_MILLISECONDS);
                    break;

                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap        events;
        InstanceScript  *pInstance;
        bool            bIsUnderFiftyPercent;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_zandalari_dinomancer_AI, Creature>(pCreature);
    }
};


// Direhorn Spirit AI
class mob_direhorn_spirit : public CreatureScript
{
public:
    mob_direhorn_spirit() : CreatureScript("mob_direhorn_spirit") { }

    class mob_direhorn_spirit_AI : public ScriptedAI
    {
    public:
        mob_direhorn_spirit_AI(Creature *pCreature) :
            ScriptedAI(pCreature), pTarget(NULL)
        {

        }

        void IsSummonedBy(Unit *pSummoner)
        {
            if(pSummoner)
            {
                if(Player *pAsPlayer = pSummoner->ToPlayer())
                {
                    me->SetPhaseMask(2, true);
                    pAsPlayer->SetPhaseMask(3, true);
                    pTarget = pAsPlayer;

                    DoCast(pTarget, SPELL_DIRE_FIXATION);
                    DoCast(me, SPELL_WEAK_LINK);
                }
            }

            if(!pTarget)
                me->DisappearAndDie();
        }

        void JustDied(Unit *pKiller)
        {
            ASSERT(pKiller == pTarget);
            pTarget->SetPhaseMask(1, true);
        }

    private:
        Player *pTarget;
    };

    CreatureAI *GetAI(Creature *pCreature) const
    {
        return GetThroneOfThunderAI<mob_direhorn_spirit_AI, Creature>(pCreature);
    }
};


//=========================================================
// GameObject Scripts


// Orb of Control AI
class gob_horridon_orb_of_control : public GameObjectScript
{
public:
    gob_horridon_orb_of_control() : GameObjectScript("gob_horridon_orb_of_control") { }

    class gob_horridon_orb_of_control_AI : public GameObjectAI
    {
    public:
        gob_horridon_orb_of_control_AI(GameObject *pGo) : GameObjectAI(pGo) { }

        bool GossipHello(Player *pSource)
        {
            if(Creature *pHorridon = GetHorridon(go))
            {
                if(GameObject *pChargeDoor = GetDoorByOrb(go))
                {
                    // Visual spell
                    if(uint32 uiSpellId = GetControlSpellByOrb(go))
                    {
                        if(pSource)
                            pSource->CastSpell(pHorridon, uiSpellId, false);
                            
                        go->RemoveFromWorld();
                    }
                }
            }

            return true;
        }
    };

    GameObjectAI *GetAI(GameObject *pGo) const
    {
        return GetThroneOfThunderAI<gob_horridon_orb_of_control_AI, GameObject>(pGo);
    }
};


//=========================================================
// Spell Scripts


// Helper for Double Swipe
class DoubleSwipeTargetSelector
{
public:
    DoubleSwipeTargetSelector(Unit *caster, bool front) :
        pCaster(caster), bFront(front) { }

    bool operator()(WorldObject const* object) const
    {
        if(object->GetTypeId() != TYPEID_PLAYER)
            return false;

        if(bFront)
        {
            return pCaster->HasInArc(45.0f, object);
        }
        else
        {
            bool bToReturn = false;

            pCaster->SetOrientation(-pCaster->GetOrientation());
            if(pCaster->HasInArc(45.0f, object))
                bToReturn = true;
            pCaster->SetOrientation(-pCaster->GetOrientation());

            return bToReturn;
        }
    }

private:
    Unit *pCaster;
    bool bFront;
};


// Target selection for Double Swipe
class spell_horridon_double_swipe : public SpellScriptLoader
{
public:
    spell_horridon_double_swipe() : SpellScriptLoader("spell_horridon_double_swipe") { }

    class spell_horridon_double_swipe_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_double_swipe_SpellScript)

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;

            targets.clear();

            DoubleSwipeTargetSelector predi(GetCaster(), GetSpellInfo()->Id == SPELL_DOUBLE_SWIPE_FRONT);
            Trinity::WorldObjectListSearcher<DoubleSwipeTargetSelector> u_search(GetCaster(), targets, predi);
            GetCaster()->VisitNearbyObject(35.0f, u_search);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_horridon_double_swipe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_104);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_horridon_double_swipe_SpellScript();
    }
};


// Chain Lightning
class spell_horridon_chain_lightning : public SpellScriptLoader
{
public:
    spell_horridon_chain_lightning() : SpellScriptLoader("spell_horridon_chain_lightning") { }

    class spell_horridon_chain_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_chain_lightning_SpellScript)

        void HandleEffectHitTarget(SpellEffIndex effectIndex)
        {
            if(Unit *pHitUnit = GetHitUnit())
            {
                Unit *pCaster = GetOriginalCaster();
                if(!pCaster)
                    pCaster = GetCaster();

                if(!pCaster)
                    return;

                if(UnitAI *pCasterAI = pCaster->GetAI())
                {
                    uint32 uiCount = pCasterAI->GetData(DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT);

                    if(uiCount == 0 && pCaster == GetOriginalCaster())
                        return;

                    Unit *pNewTarget = NULL;
                    uint32 uiLoopCount = 0; // Prevent infinite loop in case boss is being soloed

                    do
                    {
                        pNewTarget = pCasterAI->SelectTarget(SELECT_TARGET_RANDOM);
                        ++uiLoopCount;
                    }
                    while(pNewTarget == pHitUnit && uiLoopCount <= 10);

                    if(!pNewTarget || pNewTarget == pHitUnit)
                        return;

                    pHitUnit->CastSpell(pNewTarget, SPELL_CHAIN_LIGHTNING, false, NULL, NULL, pCaster->GetGUID());

                    pCasterAI->SetData(DATA_AMANI_BEAST_SHAMAN_LIGHTNING_COUNT, 0);
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_horridon_chain_lightning_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript *GetSpellScript() const
    {
        return new spell_horridon_chain_lightning_SpellScript();
    }
};


// Control Horridon Spells
class spell_control_horridon : public SpellScriptLoader
{
public:
    spell_control_horridon() : SpellScriptLoader("spell_control_horridon") { }
    
    class spell_control_horridon_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_control_horridon_AuraScript)
        
        void HandleRemove(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(AuraApplication const* pAuraApp = GetTargetApplication())
            {
                if(pAuraApp->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                {
                    if(WorldObject *pOwner = GetOwner())
                    {
                        if(Creature *pHorridon = pOwner->ToCreature())
                        {
                            if(HorridonAI *pHorridonAI = dynamic_cast<HorridonAI*>(pHorridon->AI()))
                            {
                                pHorridonAI->ChargeAtDoor(GetDoorBySpell(GetSpellInfo()->Id, pHorridon));
                            }
                        }
                    }
                }
            }
        }
        
        void HandleApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
        {
            if(WorldObject *pOwner = GetOwner())
            {
                if(Creature *pHelper = GetHorridonHelper(pOwner))
                    pHelper->AI()->DoAction(ACTION_PREPARE_TRANSITION);
            }
        }
        
        void Register()
        {
            OnEffectApply       += AuraEffectApplyFn(spell_control_horridon_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove      += AuraEffectRemoveFn(spell_control_horridon_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_MOD_PACIFY_SILENCE, AURA_EFFECT_HANDLE_REAL);
        }
        
        uint32 uiCount;
    };
    
    AuraScript *GetAuraScript() const
    {
        return new spell_control_horridon_AuraScript();
    }
};


// Living Sand (radius calc)
class spell_horridon_sand_trap : public SpellScriptLoader
{
public:
    spell_horridon_sand_trap() : SpellScriptLoader("spell_horridon_sand_trap") {  }
    
    class spell_horridon_sand_trap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_horridon_sand_trap_SpellScript)
        
        void HandleSelectTargets(std::list<WorldObject*>& targets)
        {
            if(!GetCaster())
                return;
                
            Creature *pCaster = GetCaster()->ToCreature();
            float fRadius = 1.0f; // Basis
            
            // Recalc radius according to stack amount
            if(Aura *pGrow = pCaster->GetAura(GetSpellInfo()->Id))
            {
                uint8 uiCount = pGrow->GetStackAmount();
                for(uint8 i = 0; i < uiCount; ++i)
                    fRadius *= 1.1f;
            }
            
            // Remove target that are not in the radius
            targets.remove_if([pCaster, fRadius](WorldObject const* pTarget) -> bool 
            {
                return pCaster->GetExactDist2d(pTarget) >= fRadius;
            });
        }
        
        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_horridon_sand_trap_SpellScript::HandleSelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };
    
    SpellScript *GetSpellScript() const 
    {
        return new spell_horridon_sand_trap_SpellScript();
    }
};
void AddSC_boss_horridon()
{
    // Boss
    new npc_horridon_event_helper();
    new npc_horridon_rp_event_helper();
    new boss_horridon();
    new mob_war_god_jalak();

    // Trashs
    new mob_horridon_trashs();
    new mob_horridon_summons();
    new mob_zandalari_dinomancer();
    new mob_direhorn_spirit();

    // GameObjects
    new gob_horridon_orb_of_control();

    // Spells
    new spell_horridon_double_swipe();
    new spell_horridon_chain_lightning();
    new spell_control_horridon();
    new spell_horridon_sand_trap();
}
