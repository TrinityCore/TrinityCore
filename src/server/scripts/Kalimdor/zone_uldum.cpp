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
    SPELL_SUMMON_CAMERA_BUNNY   = 86792,
    SPELL_PING_ALL_ACTORS_00    = 86843
};

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
    PHASE_DEFAULT                       = 169,
    PHASE_ENTRANCE_TO_ULDUM             = 298,

    SPELL_PING_CAMERA_00                = 86815,
    SPELL_PING_CAMERA_01                = 86943,
    SPELL_PING_BEAM_TARGET              = 86944,
    SPELL_INVISIBLE_BEAM                = 86822,
    SPELL_MASTER_PING_ALL_ACTORS        = 86848,
    SPELL_REVERSE_CAST_RIDE_VEHICLE     = 82721,

    EVENT_MOVE_PATH_1                   = 1,
    EVENT_PING_BEAM_TARGET              = 2,

    POINT_NONE                          = 0,

    SPLINE_CHAIN_ID_CAMERA_PATH_1       = 1,
    SPLINE_CHAIN_ID_CAMERA_PATH_2       = 2,
    SPLINE_CHAIN_ID_BEAM_TARGET_PATH_1  = 1
};

Position const UldumCameraBunny04Path1[] =
{
    { -8922.04f, -2274.03f, 14.4508f },
    { -8915.17f, -2282.37f, 21.0023f }
};

Position const UldumCameraBunny04Path2[] =
{
    {-8921.55f, -2291.59f, 18.5897f },
    { -8928.08f, -2291.1f, 16.9801f },
    { -8932.17f, -2279.79f, 14.2697f },
    { -8933.72f, -2263.06f, 12.12f }
};


Position const UldumCameraBunny04Path3[] =
{
    { -8951.25f, -2174.06f, 17.2353f },
    { -8943.43f, -2161.06f, 54.8142f }
};


struct npc_uldum_camera_bunny_04 : public ScriptedAI
{
    npc_uldum_camera_bunny_04(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _pingCount = 0;
    }

    void InitializeAI() override
    {
        PhasingHandler::AddPhase(me, PHASE_DEFAULT, false);
        PhasingHandler::AddPhase(me, PHASE_ENTRANCE_TO_ULDUM, false);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (!caster)
            return;

        switch (spell->Id)
        {
            case SPELL_PING_CAMERA_00:
                printf("ping SPELL_PING_CAMERA_00 landed \n");
                if (_pingCount == 1)
                {
                    DoCast(caster, SPELL_INVISIBLE_BEAM);
                    DoCastSelf(SPELL_REVERSE_CAST_RIDE_VEHICLE, true);
                    DoCastSelf(SPELL_MASTER_PING_ALL_ACTORS, true);
                    _events.ScheduleEvent(EVENT_MOVE_PATH_1, 11s);
                }
                else if (_pingCount == 2)
                {
                    printf("EVENT_PING_BEAM_TARGET scheduled \n");
                    _events.ScheduleEvent(EVENT_PING_BEAM_TARGET, 3s + 600ms);
                }

                _pingCount++;
                break;
            case SPELL_PING_CAMERA_01:
            {
               
                me->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_CAMERA_PATH_2, true);
                DoCast(caster, SPELL_INVISIBLE_BEAM, true);
                break;
            }
            default:
                break;
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_PING_BEAM_TARGET)
        {
            printf("ping camera beam hit \n");
            target->CastSpell(target, SPELL_PING_CAMERA_01);
            target->GetMotionMaster()->MoveAlongSplineChain(POINT_NONE, SPLINE_CHAIN_ID_BEAM_TARGET_PATH_1, true);
        }
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
                    printf("EVENT_PING_BEAM_TARGET triggered \n");
                    me->CastStop();
                    me->ReleaseFocus(nullptr, false);
                    DoCastSelf(SPELL_PING_BEAM_TARGET, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    uint8 _pingCount;
    EventMap _events;
};

void AddSC_uldum()
{
    RegisterCreatureAI(npc_uldum_camera_bunny_04);
    RegisterSpellScript(spell_uldum_master_ping_all_actors);
    RegisterSpellScript(spell_uldum_player_summon_camera);
}
