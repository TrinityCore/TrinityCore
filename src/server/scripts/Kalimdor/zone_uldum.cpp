/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "GameObjectData.h"
#include "GameObject.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Spell.h"
#include "Vehicle.h"

enum UldumIntro
{
    // Phase IDs
    PHASE_ENTRANCE_TO_ULDUM             = 298,

    // Spells
    SPELL_SUMMON_CAMERA_BUNNY           = 86792,
    SPELL_PING_ALL_ACTORS_00            = 86843,
    SPELL_SUMMON_ADARRAH                = 86751,
    SPELL_SUMMON_CARAVAN                = 86752,
    SPELL_SUMMON_LADY_HUMPS             = 86753,
    SPELL_SUMMON_PACK_MULE              = 86754,
    SPELL_SUMMON_BUDDS_CAMEL            = 86755,
    SPELL_SUMMON_SAMIRS_CAMEL           = 86756,
    SPELL_SUMMON_MACKS_CAMEL            = 86757,
    SPELL_SUMMON_ADARRAHS_CAMEL         = 86758,
    SPELL_SUMMON_CLONED_IMAGE           = 86782,
    SPELL_SUMMON_BEAM_TARGET_BUNNY      = 86942,
    SPELL_SUMMON_BEAM_TARGET_BUNNY_02   = 86964
};

// 86748 - Intialize Uldum Intro
class spell_uldum_initialize_uldum_intro : public SpellScript
{
    PrepareSpellScript(spell_uldum_initialize_uldum_intro);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUMMON_ADARRAH,
                SPELL_SUMMON_CARAVAN,
                SPELL_SUMMON_LADY_HUMPS,
                SPELL_SUMMON_PACK_MULE,
                SPELL_SUMMON_BUDDS_CAMEL,
                SPELL_SUMMON_SAMIRS_CAMEL,
                SPELL_SUMMON_MACKS_CAMEL,
                SPELL_SUMMON_ADARRAHS_CAMEL,
                SPELL_SUMMON_CLONED_IMAGE,
                SPELL_SUMMON_BEAM_TARGET_BUNNY
            });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        PhasingHandler::AddPhase(target, PHASE_ENTRANCE_TO_ULDUM, true);
        target->CastSpell(target, SPELL_SUMMON_ADARRAH, true);
        target->CastSpell(target, SPELL_SUMMON_CARAVAN, true);
        target->CastSpell(target, SPELL_SUMMON_LADY_HUMPS, true);
        target->CastSpell(target, SPELL_SUMMON_PACK_MULE, true);
        target->CastSpell(target, SPELL_SUMMON_BUDDS_CAMEL, true);
        target->CastSpell(target, SPELL_SUMMON_SAMIRS_CAMEL, true);
        target->CastSpell(target, SPELL_SUMMON_MACKS_CAMEL, true);
        target->CastSpell(target, SPELL_SUMMON_ADARRAHS_CAMEL, true);
        target->CastSpell(target, SPELL_SUMMON_CLONED_IMAGE, true);
        target->CastSpell(target, SPELL_SUMMON_BEAM_TARGET_BUNNY, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_uldum_initialize_uldum_intro::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 86848 - Master Ping all Actors
class spell_uldum_master_ping_all_actors : public SpellScript
{
    PrepareSpellScript(spell_uldum_master_ping_all_actors);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PING_ALL_ACTORS_00 });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_PING_ALL_ACTORS_00, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_uldum_master_ping_all_actors::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 86960 - Master Summon Beam Target 02
class spell_uldum_master_summon_beam_target_02 : public SpellScript
{
    PrepareSpellScript(spell_uldum_master_summon_beam_target_02);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_BEAM_TARGET_BUNNY_02 });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_BEAM_TARGET_BUNNY_02, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_uldum_master_summon_beam_target_02::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 95747 - Player Summon Camera
class spell_uldum_player_summon_camera : public SpellScript
{
    PrepareSpellScript(spell_uldum_player_summon_camera);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_CAMERA_BUNNY });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_CAMERA_BUNNY, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_uldum_player_summon_camera::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum UldumCameraBunny
{
    // Spells
    SPELL_PING_CAMERA_00                        = 86815,
    SPELL_PING_CAMERA_01                        = 86943,
    SPELL_PING_CAMERA_02                        = 86970,
    SPELL_PING_BEAM_TARGET                      = 86944,
    SPELL_INVISIBLE_BEAM                        = 86822,
    SPELL_MASTER_PING_ALL_ACTORS                = 86848,
    SPELL_REVERSE_CAST_RIDE_VEHICLE             = 82721,
    SPELL_REVERSE_CAST_RIDE_SEAT_2              = 82315,
    SPELL_REVERSE_CAST_RIDE_CAMERA_BUNNY_SEAT_3 = 84301,
    SPELL_FADE_TO_BLACK                         = 88267,
    SPELL_TELEPORT_CAMERA                       = 86952,
    SPELL_MASTER_SUMMON_BEAM_TARGET_02          = 86960,

    // Events
    EVENT_MOVE_PATH_1                           = 1,
    EVENT_PING_BEAM_TARGET                      = 2,
    EVENT_FADE_TO_BLACK_1                       = 3,
    EVENT_TELEPORT_CAMERA_1                     = 4,
    EVENT_TARGET_BEAM_BUNNY_2                   = 5,

    // Move Points
    POINT_NONE                                  = 0,

    // Spline Chains
    SPLINE_CHAIN_ID_CAMERA_PATH_1               = 1, // Uldum Camera Bunny 04 - Move behind next to the caravan
    SPLINE_CHAIN_ID_CAMERA_PATH_2               = 2, // Uldum Camera Bunny 04 - Move behind the caravan
    SPLINE_CHAIN_ID_CAMERA_PATH_3               = 3, // Uldum Camera Bunny 04 - Move along the statue
    SPLINE_CHAIN_ID_BEAM_TARGET_PATH_1          = 1, // Beam Target Bunny - Move up
    SPLINE_CHAIN_ID_BEAM_TARGET_2_PATH_1        = 1, // Beam Target Bunny 02 - Move down

    // Ping Counter
    PING_INDEX_PING_ALL_ACTORS                  = 1, // 2nd ping spell - master ping all actors, get caster into the vehicle, schedule movement
    PING_INDEX_PING_BEAM_TARGET                 = 2  // 3rd ping spell - ping beam target in 3.6s
};

Position const TeleportGridPosition1 = { -8958.0f, -1658.0f };

struct npc_uldum_uldum_camera_bunny_04 : public ScriptedAI
{
    npc_uldum_uldum_camera_bunny_04(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _pingCount = 0;
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!caster)
            return;

        switch (spell->Id)
        {
            case SPELL_PING_CAMERA_00:
                if (_pingCount == PING_INDEX_PING_ALL_ACTORS)
                {
                    DoCast(caster, SPELL_INVISIBLE_BEAM);
                    DoCastSelf(SPELL_REVERSE_CAST_RIDE_VEHICLE, true);
                    DoCastSelf(SPELL_MASTER_PING_ALL_ACTORS, true);
                    _events.ScheduleEvent(EVENT_MOVE_PATH_1, 11s);
                }
                else if (_pingCount == PING_INDEX_PING_BEAM_TARGET)
                    _events.ScheduleEvent(EVENT_PING_BEAM_TARGET, 3s + 600ms);

                _pingCount++;
                break;
            case SPELL_PING_CAMERA_01:
                me->CastStop();
                DoCast(caster, SPELL_INVISIBLE_BEAM, true);
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_CAMERA_PATH_2, true);
                caster->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_BEAM_TARGET_PATH_1, false);
                _events.ScheduleEvent(EVENT_FADE_TO_BLACK_1, 8s + 500ms);
                break;
            case SPELL_PING_CAMERA_02:
                _cameraBunnyGUID = caster->GetGUID();
                _events.ScheduleEvent(EVENT_TARGET_BEAM_BUNNY_2, 1s + 500ms);
                break;
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_PING_BEAM_TARGET)
            target->CastSpell(me, SPELL_PING_CAMERA_01, true);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_PATH_1:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_CAMERA_PATH_1, true);
                    break;
                case EVENT_PING_BEAM_TARGET:
                    DoCastAOE(SPELL_PING_BEAM_TARGET, true);
                    break;
                case EVENT_FADE_TO_BLACK_1:
                    // Pre-load grid to avoid getting stuck on the next location
                    me->GetMap()->LoadGrid(TeleportGridPosition1.GetPositionX(), TeleportGridPosition1.GetPositionY());
                    DoCastSelf(SPELL_FADE_TO_BLACK, true);
                    _events.ScheduleEvent(EVENT_TELEPORT_CAMERA_1, 1s);
                    break;
                case EVENT_TELEPORT_CAMERA_1:
                    me->CastStop();
                    DoCastSelf(SPELL_REVERSE_CAST_RIDE_SEAT_2, true);
                    DoCastSelf(SPELL_TELEPORT_CAMERA, true);
                    DoCastSelf(SPELL_MASTER_SUMMON_BEAM_TARGET_02, true);
                    DoCastSelf(SPELL_MASTER_PING_ALL_ACTORS, true);
                    break;
                case EVENT_TARGET_BEAM_BUNNY_2:
                    if (Creature* bunny = ObjectAccessor::GetCreature(*me, _cameraBunnyGUID))
                    {
                        DoCastSelf(SPELL_REVERSE_CAST_RIDE_CAMERA_BUNNY_SEAT_3, true);
                        DoCast(bunny, SPELL_INVISIBLE_BEAM, true);
                        me->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_CAMERA_PATH_3, false);
                        bunny->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_BEAM_TARGET_2_PATH_1, false);
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    uint8 _pingCount;
    EventMap _events;
    ObjectGuid _cameraBunnyGUID;
};

// Gobbles! Quest
enum SummonSchnottz
{
    NPC_SCHNOTTZ                  = 47159,
    SPELL_SUMMON_SCHNOTTZ_00      = 88108,
    SPELL_SUMMON_VEVAH            = 88109,
    SPELL_PHASE_PLAYER            = 88111
};

// 88107 - Gobbles Initialize
class spell_gobbles_initialize : public SpellScript
{
    PrepareSpellScript(spell_gobbles_initialize);

    void HandleScript(SpellEffIndex /*eff*/)
    {
        if (Player* player = GetHitUnit()->ToPlayer())
        {
            // Does not work correctly if done in db
            player->CastSpell(player, SPELL_SUMMON_SCHNOTTZ_00);
            player->CastSpell(player, SPELL_SUMMON_VEVAH);
            player->CastSpell(player, SPELL_PHASE_PLAYER);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_gobbles_initialize::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 88108 - Summon Schnottz
class spell_summon_schnottz : public SpellScript
{
    PrepareSpellScript(spell_summon_schnottz);

    void SetDest(SpellDestination& dest)
    {
        if (Creature * Schnottz = GetCaster()->FindNearestCreature(NPC_SCHNOTTZ, 10.0f, true))
            dest.Relocate(Schnottz->GetPosition());
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_summon_schnottz::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

void AddSC_uldum()
{
    RegisterCreatureAI(npc_uldum_uldum_camera_bunny_04);
    RegisterSpellScript(spell_uldum_initialize_uldum_intro);
    RegisterSpellScript(spell_uldum_master_ping_all_actors);
    RegisterSpellScript(spell_uldum_master_summon_beam_target_02);
    RegisterSpellScript(spell_uldum_player_summon_camera);
    RegisterSpellScript(spell_gobbles_initialize);
    RegisterSpellScript(spell_summon_schnottz);
}
