/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "Creature.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum QuestRollingWithMyHomiesMisc
{
    NPC_SUMMONED_ACE                = 34957,
    NPC_SUMMONED_GOBBER             = 34958,
    NPC_SUMMONED_IZZY               = 34959,

    SPELL_SERVERSIDE_ABANDON_QUEST  = 78976,
    SPELL_SERVERSIDE_HOT_ROD_MOUNT  = 66618,

    SEAT_PLAYER                     = 0,
    SEAT_ACE                        = 2,
    SEAT_GROBBER                    = 3,
    SEAT_IZZY                       = 4,

    RADIO_SOUND                     = 23406
};

// 66298 - Honk Horn
class spell_hot_rod_honk_horn : public SpellScript
{
    PrepareSpellScript(spell_hot_rod_honk_horn);

    void Beep(SpellEffIndex /*effIndex*/)
    {
        Player* player = nullptr;

        if (Unit* caster = GetCaster())
            if (Vehicle* vehicle = caster->GetVehicleKit())
                if (Unit* passenger = vehicle->GetPassenger(SEAT_PLAYER))
                    player = passenger->ToPlayer();

        if (!player)
            return;
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_hot_rod_honk_horn::Beep, EFFECT_0, SPELL_EFFECT_PLAY_SOUND);
    }
};

// 66299 - Radio
class spell_hot_rod_radio : public SpellScript
{
    PrepareSpellScript(spell_hot_rod_radio);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        radioOn = false;
        return true;
    }

    void HandleOnHit()
    {
        if (radioOn)
            return;

        if (Unit* caster = GetCaster()->GetOwner())
        {
            if (caster->GetTypeId() == TYPEID_PLAYER)
                GetCaster()->PlayDistanceSound(RADIO_SOUND, caster->ToPlayer());

            radioOn = true;
        }
    }
private:
    bool radioOn;

    void Register() override
    {
        OnHit += SpellHitFn(spell_hot_rod_radio::HandleOnHit);
    }
};

// 66617 - (Serverside/Non-DB2) Rolling with my Homies: Get Into The Hot Rod Trigger
class spell_hot_rod_periodic_check : public AuraScript
{
    PrepareAuraScript(spell_hot_rod_periodic_check);

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();

        if (caster->GetVehicle())
            return;

        caster->CastSpell(caster, SPELL_SERVERSIDE_HOT_ROD_MOUNT, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_hot_rod_periodic_check::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 66618 - (Serverside/Non-DB2) Rolling with my Homies: Get Into The Hot Rod Effect
class spell_hot_rod_mount : public SpellScript
{
    PrepareSpellScript(spell_hot_rod_mount);

    bool Load() override
    {
        return GetCaster()->GetOwner();
    }

    void HandleMountHotRod(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Creature* vehicle = GetCaster()->GetOwner()->ToPlayer()->GetVehicleCreatureBase();
        CastSpellExtraArgs args;

        switch (caster->GetEntry())
        {
            case NPC_SUMMONED_ACE:
                args.AddSpellBP0(SEAT_ACE);
                break;
            case NPC_SUMMONED_GOBBER:
                args.AddSpellBP0(SEAT_GROBBER);
                break;
            case NPC_SUMMONED_IZZY:
                args.AddSpellBP0(SEAT_IZZY);
                break;
        }

        caster->CastSpell(vehicle, VEHICLE_SPELL_RIDE_HARDCODED, args);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_hot_rod_mount::HandleMountHotRod, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 66612 - (Serverside/Non-DB2) Rolling with my Homies: Despawn Summoned Friends
class spell_despawn_summoned_friends : public SpellScript
{
    PrepareSpellScript(spell_despawn_summoned_friends);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* hitCreature = GetHitCreature())
        {
            if (hitCreature->GetOwner() == GetCaster())
                hitCreature->DespawnOrUnsummon();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_despawn_summoned_friends::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 14017 - Rolling with my homies
class quest_rolling_with_my_homies : public QuestScript
{
    public:
        quest_rolling_with_my_homies() : QuestScript("quest_rolling_with_my_homies") { }

        void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
        {
            if (newStatus == QUEST_STATUS_NONE)
                player->CastSpell(player, SPELL_SERVERSIDE_ABANDON_QUEST, true);
        }
};

void AddSC_kezan()
{
    RegisterSpellScript(spell_hot_rod_honk_horn);
    RegisterSpellScript(spell_hot_rod_radio);
    RegisterSpellScript(spell_hot_rod_periodic_check);
    RegisterSpellScript(spell_hot_rod_mount);
    RegisterSpellScript(spell_despawn_summoned_friends);

    new quest_rolling_with_my_homies();
}
