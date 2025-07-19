/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "nerubar_palace.h"

enum UlgraxTheDevourerSpells
{
    // Intro
    SPELL_SWALLOWING_DARKNESS          = 451409,
    SPELL_SWALLOWING_DARKNESS_TELEPORT = 451411,
    SPELL_SWALLOWING_DARKNESS_DAMAGE   = 451412
};

enum UlgraxTheDevourerConversations
{
    CONVERSATION_ULGRAX_INTRO   = 24332
};

enum UlgraxTheDevourerPoints
{
    POINT_ULGRAX_INTRO    = 1
};

constexpr Position UlgraxStartTeleportPosition = { -2991.9705f, -124.82639f, -1137.0024f };
constexpr Position UlgraxStartCombatPosition = { -2862.7395f, -251.90973f, -1189.6f, 5.550147f };

// Id xxxx - Areatrigger
struct at_ulgrax_intro : AreaTriggerAI
{
    at_ulgrax_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* queenAnsurek = instance->GetCreature(DATA_QUEEN_ANSUREK))
            Conversation::CreateConversation(CONVERSATION_ULGRAX_INTRO, queenAnsurek, queenAnsurek->GetPosition(), ObjectGuid::Empty);

        if (Creature* ulgrax = instance->GetCreature(DATA_ULGRAX_THE_DEVOURER))
            ulgrax->GetMotionMaster()->MovePoint(POINT_ULGRAX_INTRO, UlgraxStartTeleportPosition);

        at->Remove();
    }
};

// 215657 - Ulgrax the Devourer
struct boss_ulgrax_the_devourer : public BossAI
{
    boss_ulgrax_the_devourer(Creature* creature) : BossAI(creature, DATA_ULGRAX_THE_DEVOURER) { }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_ULGRAX_INTRO)
        {
            me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR);

            scheduler.Schedule(2s, [this](TaskContext context)
            {
                DoCastSelf(SPELL_SWALLOWING_DARKNESS);

                context.Schedule(11s, [this](TaskContext /*context*/)
                {
                    me->SetHomePosition(UlgraxStartCombatPosition);
                    me->SetImmuneToAll(false);
                });
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;
    }
};

// 451409 - Swallowing Darkness
class spell_ulgrax_the_devourer_swallowing_darkness_intro : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SWALLOWING_DARKNESS_TELEPORT });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SWALLOWING_DARKNESS_TELEPORT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ulgrax_the_devourer_swallowing_darkness_intro::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 451411 - Swallowing Darkness
class spell_ulgrax_the_devourer_swallowing_darkness_teleport : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SWALLOWING_DARKNESS_DAMAGE });
    }

    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(UlgraxStartCombatPosition);
    }

    void HandleAfterHit()
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_SWALLOWING_DARKNESS_DAMAGE, true);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_ulgrax_the_devourer_swallowing_darkness_teleport::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
        AfterHit += SpellHitFn(spell_ulgrax_the_devourer_swallowing_darkness_teleport::HandleAfterHit);
    }
};

void AddSC_boss_ulgrax_the_devourer()
{
    RegisterAreaTriggerAI(at_ulgrax_intro);
    RegisterNerubarPalaceCreatureAI(boss_ulgrax_the_devourer);
    RegisterSpellScript(spell_ulgrax_the_devourer_swallowing_darkness_intro);
    RegisterSpellScript(spell_ulgrax_the_devourer_swallowing_darkness_teleport);
}
