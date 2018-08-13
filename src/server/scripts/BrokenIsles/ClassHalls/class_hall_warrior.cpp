/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Spell.h"
#include "SpellPackets.h"
#include "ScriptedGossip.h"

// Jump to teleport out of the class hall
// 191473 (Dalaran), 225220 (Stormheim), 225163 (Aszuna), 225115 (Val'sharah),
// 205813 (Highmountain), 225233 (Suramar), 241928 (Broken Shore)
class spell_class_hall_warrior_jump_exit : public SpellScript
{
    PrepareSpellScript(spell_class_hall_warrior_jump_exit);

    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(Position(1108.74f, 7222.535f, 39.45004f));
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_class_hall_warrior_jump_exit::SetDest, EFFECT_0, TARGET_DEST_DEST_RANDOM);
    }
};

// Teleport to destination: override it to add TELE_TO_CAST_ON_ARRIVAL and cast the final animation
// 191474 (Dalaran), 225219 (Stormheim), 225162 (Aszuna), 225114 (Val'sharah),
// 205814 (Highmountain), 225232 (Suramar), 241931 (Broken Shore)
class spell_class_hall_warrior_jump_teleport : public SpellScript
{
    PrepareSpellScript(spell_class_hall_warrior_jump_teleport);

    void SaveDest(SpellDestination& dest)
    {
        _loc = dest._position;
    }

    void HandleTeleport(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Player* player = GetHitPlayer())
        {
            player->SendDirectMessage(WorldPackets::Spells::CustomLoadScreen(GetSpellInfo()->Id, GetSpellInfo()->GetEffect(effIndex)->MiscValue).Write());
            player->TeleportTo(_loc.GetMapId(), _loc.GetPositionX(), _loc.GetPositionY(), _loc.GetPositionZ(), _loc.GetOrientation(),
                TELE_TO_SPELL | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_CAST_ON_ARRIVAL, 247832); // 247832 = SkyJump, visual of the landing + stun removal
        }
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_class_hall_warrior_jump_teleport::SaveDest, EFFECT_0, TARGET_DEST_DB);
        OnEffectHitTarget += SpellEffectFn(spell_class_hall_warrior_jump_teleport::HandleTeleport, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
    }

private:
    WorldLocation _loc;
};

enum classHallTeleportSpells
{
    SPELL_TELE_DALARAN      = 191473,
    SPELL_TELE_STORMHEIM    = 225220,
    SPELL_TELE_ASZUNA       = 225163,
    SPELL_TELE_VALSHARAH    = 225115,
    SPELL_TELE_HIGHMOUNTAIN = 205813,
    SPELL_TELE_SURAMAR      = 225233,
    SPELL_TELE_BROKEN_SHORE = 241928
};

// 96679
struct npc_class_hall_warrior_aerylia : public ScriptedAI
{
    npc_class_hall_warrior_aerylia(Creature* creature) : ScriptedAI(creature) { }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        uint32 spellId = 0;
        switch (gossipListId)
        {
            case 2:
                spellId = SPELL_TELE_DALARAN;
                break;
            case 3:
                spellId = SPELL_TELE_STORMHEIM;
                break;
            case 4:
                spellId = SPELL_TELE_ASZUNA;
                break;
            case 5:
                spellId = SPELL_TELE_VALSHARAH;
                break;
            case 6:
                spellId = SPELL_TELE_HIGHMOUNTAIN;
                break;
            case 7:
                spellId = SPELL_TELE_SURAMAR;
                break;
            case 8:
                spellId = SPELL_TELE_BROKEN_SHORE;
                break;
            default:
                break;
        }

        if (spellId != 0)
        {
            player->InterruptNonMeleeSpells(true);
            player->CastSpell(player, spellId, false);
        }

        CloseGossipMenuFor(player);
    }
};

void AddSC_class_hall_warrior()
{
    RegisterSpellScript(spell_class_hall_warrior_jump_exit);
    RegisterSpellScript(spell_class_hall_warrior_jump_teleport);

    RegisterCreatureAI(npc_class_hall_warrior_aerylia);
}
