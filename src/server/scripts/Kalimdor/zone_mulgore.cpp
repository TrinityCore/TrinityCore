/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "MotionMaster.h"
#include "ScriptedCreature.h"

/*######
## npc_eagle_spirit
######*/

enum EagleSpirit
{
    SPELL_EJECT_ALL_PASSENGERS = 50630,
    SPELL_SPIRIT_FORM          = 69324
};

Position const EagleSpiritflightPath[] =
{
    { -2884.155f, -71.08681f, 242.0678f },
    { -2720.592f, -111.0035f, 242.5955f },
    { -2683.951f, -382.9010f, 231.1792f },
    { -2619.148f, -484.9288f, 231.1792f },
    { -2543.868f, -525.3333f, 231.1792f },
    { -2465.321f, -502.4896f, 190.7347f },
    { -2343.872f, -401.8281f, -8.320873f }
};
size_t const EagleSpiritflightPathSize = std::extent<decltype(EagleSpiritflightPath)>::value;

struct npc_eagle_spirit : public ScriptedAI
{
    npc_eagle_spirit(Creature* creature) : ScriptedAI(creature) { }

    void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        me->GetMotionMaster()->MoveSmoothPath(uint32(EagleSpiritflightPathSize), EagleSpiritflightPath, EagleSpiritflightPathSize, false, true);
        me->CastSpell(me, SPELL_SPIRIT_FORM);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == EFFECT_MOTION_TYPE && pointId == EagleSpiritflightPathSize)
        {
            DoCast(SPELL_EJECT_ALL_PASSENGERS);
        }
    }
};

// 71898 Funeral Offering
class spell_mulgore_funeral_offering : public SpellScript
{
    PrepareSpellScript(spell_mulgore_funeral_offering);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            if (GetCaster()->IsPlayer())
                GetCaster()->ToPlayer()->KilledMonsterCredit(target->GetEntry());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_mulgore_funeral_offering::HandleHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_mulgore()
{
    RegisterCreatureAI(npc_eagle_spirit);
    RegisterSpellScript(spell_mulgore_funeral_offering);
}
