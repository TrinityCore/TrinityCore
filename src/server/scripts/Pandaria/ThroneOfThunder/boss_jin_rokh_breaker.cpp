/*
* Copyright 2023 AzgathCore
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

#include "throne_of_thunder.h"
#include "GridNotifiers.h"
#include "DynamicObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum eSpells : uint32
{
    SPELL_CONDUCTIVE_WATER_SUMMON = 137145,
    SPELL_CONDUCTIVE_WATERFALL = 137340,
    SPELL_CONDUCTIVE_WATER_VISUAL = 137277,
    SPELL_CONDUCTIVE_WATER_DUMMY = 137168,
    SPELL_CONDUCTIVE_WATER_GROW = 137694,
    SPELL_ELECTRIFY_WATERS = 138568,
    SPELL_ELECTRIFIED_WATER_VISUAL = 137978,

    SPELL_LIGHTNING_FISSURE_SUMMON = 137479,
    SPELL_LIGHTNING_FISSURE_VISUAL = 137480,
    SPELL_LIGHTNING_FISSURE_CONDUCTION = 138133,
    SPELL_LIGHTNING_FISSURE_AURA = 137484,

    SPELL_FOCUSED_LIGHTNING = 137399,
    //  SPELL_FOCUSED_LIGHTNING_VISUAL          = 137425,
    //  SPELL_FOCUSED_LIGHTNING_FIXATE          = 137422,
    SPELL_FOCUSED_LIGHTNING_SPEED = 137389,
    SPELL_FOCUSED_LIGHTNING_AOE = 137429,
    SPELL_FOCUSED_LIGHTNING_DETONATION = 137374,
    SPELL_VIOLENT_LIGHTNING_DETONATION = 138990,
    SPELL_FOCUSED_LIGHTNING_DAMAGE = 137423,
    SPELL_FOCUSED_LIGHTNING_TARGET = 137194,
    SPELL_FOCUSED_LIGHTNING_CONDUCTION = 137530,

    SPELL_IMPLOSION = 137507,

    SPELL_CONDUCTIVE_WATER_GROW_AURA = 137694,
    SPELL_CONDUCTIVE_WATERS = 138470,
    SPELL_ELECTRIFIED_WATERS = 138006,
    SPELL_FLUIDITY = 138002,

    SPELL_STATIC_BURST = 137162,
    SPELL_STATIC_WOUND = 138349,
    SPELL_STATIC_WOUND_DAMAGE = 138389,

    SPELL_LIGHTNING_STORM = 137313,
    SPELL_LIGHTNING_STORM_VISUAL = 138568,

    // Thundering Throw
    SPELL_THUNDERING_THROW = 137180, // Need SpellScript to handle ScriptEffect
    SPELL_THUNDERING_THROW_JUMP = 137173, // Casted by player on a statue
    SPELL_THUNDERING_THROW_SILENCE = 137161, // Silence, visuals
    SPELL_THUNDERING_THROW_FLY_VISUAL = 140594, // Visual in flight
    SPELL_THUNDERING_THROW_HIT_DAMAGE = 137370, // Damage on hit statue
    SPELL_THUNDERING_THROW_HIT_AOE_DAMAGE = 137167, // AOE Damage on hit statue
    SPELL_THUNDERING_THROW_STUN = 137371, // Stun after aoe damage on hit statue
    SPELL_THUNDERING_THROW_IMPACT_VISUAL = 140606, // Visual of the impact on ground

    // Heroic mode
    SPELL_LIGHTNING_STRIKE_DAMAGE = 137647, // used by diffuses & stalker
    SPELL_STORM_STALKER_SUMMON = 137283, // apply visual SPELL_LIGHTNING_STRIKE_VISUAL ( special ai )
    SPELL_LIGHTNING_STRIKE_DIFFUSE = 137966, // visual diffuses
    SPELL_LIGHTNING_STRIKE_VISUAL = 138299,

    SPELL_IONIZATION = 138732, // spellscript
    SPELL_IONIZATION_DAMAGE = 138733,
    SPELL_IONIZATION_CONDUCTION = 138743,
};

enum eCreatures : uint32
{
    NPC_LIGHTNING_FISSURE = 69609,
    NPC_CONDUCTIVE_WATER = 69469,
    NPC_FOCUSED_LIGHTNING = 69593,

    // Storm Stalkers
    NPC_STORM_MAIN_STALKER = 69676,
    NPC_STORM_EAST = 69713,
    NPC_STORM_WEST = 69715,
    NPC_STORM_NORTH = 69711,
    NPC_STORM_SOUTH = 69714,
};

enum iActions : int32
{
    ACTION_NONE,
    ACTION_DESTROYED,
    ACTION_RESET,
    ACTION_ELECTRIFY
};

static const float floorZ = 124.03f;

// added for general evets, it seems that all events are particularly added into main scripts, weird
enum HelperEvents
{
    EVENT_LIGHTNING_STRIKE_DAMAGE_PATH = 1,
    EVENT_HANDLE_SUMMON_AND_DAMAGE = 2,
};

enum eJDatas : uint32
{
    DATA_STATUE_DESTROYED,
};

class notInLosPredicate
{
public:
    notInLosPredicate(Unit* caster) : _caster(caster) {}
    bool operator()(WorldObject* target) const
    {
        return target && !target->IsWithinLOSInMap(_caster);
    }

private:
    Unit* _caster;
};

class validStatuePredicate
{
public:
    bool operator() (WorldObject* target) const
    {
        return target && target->ToPlayer() || ((target->ToCreature()->AI() && target->ToCreature()->AI()->GetData(DATA_STATUE_DESTROYED) == 1) || target->GetEntry() != NPC_JINROKH_STATUE);
    }
};

class electrifiedPredicate
{
public:
    bool operator()(Creature* target) const
    {
        return target && target->HasAura(SPELL_ELECTRIFIED_WATER_VISUAL);
    }
};

class scaleCheckPredicate
{
public:
    scaleCheckPredicate(Unit* caster) : _caster(caster) {}

    bool operator()(WorldObject* target) const
    {
        if (target && target->GetExactDist2d(_caster) > GetSizeProp(_caster))
            return true;
        return false;
    }
private:
    Unit* _caster;

    float GetSizeProp(Unit* propagator) const
    {
        if (Aura* pAura = propagator->GetAura(SPELL_CONDUCTIVE_WATER_GROW))
        {
            return ((float)0.4f * pAura->GetStackAmount());
        }

        return 0;
    }
};

class conductionPredicate
{
public:
    conductionPredicate(Creature* _waters) : waters(_waters) {}

    bool operator()(WorldObject* target) const
    {
        if (target && target->ToUnit())
        {
            if (target->ToUnit()->HasAura(SPELL_FLUIDITY, waters->GetGUID()))
                return false;
            if (target->ToUnit()->HasAura(SPELL_ELECTRIFIED_WATERS, waters->GetGUID()))
                return false;
        }

        return true;
    }
private:
    Creature* waters;
};

class notPlayerOrPetPredicate
{
public:
    bool operator()(WorldObject* target) const
    {
        return target && target->GetTypeId() != TYPEID_PLAYER;
    }
};

class focusedLightningPredicate
{
public:
    bool operator()(WorldObject* target) const
    {
        if (target)
        {
            if (target->ToCreature())
            {
                if (target->ToCreature()->GetEntry() != NPC_LIGHTNING_FISSURE)
                    return true;
                else
                    return false;
            }

            if (target->GetTypeId() == TYPEID_PLAYER)
                return false;

            return true;
        }
        return true;
    }
};

static const Position aWaterPos[4] =
{
    { 5864.490f, 6290.628f, 124.03f, 5.51f },
    { 5917.633f, 6289.476f, 124.03f, 3.93f },
    { 5918.487f, 6236.848f, 124.03f, 2.36f },
    { 5865.241f, 6236.743f, 128.03f, 0.77f }
};

static const Position aCenterPos = { 5892.16f, 6263.58f, 124.7f, 0.0f };

void AddSC_boss_jinrokh()
{
    
}
