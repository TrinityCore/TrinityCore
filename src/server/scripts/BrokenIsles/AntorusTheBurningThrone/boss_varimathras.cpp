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

#include "antorus.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NECROTIC_EMBRACE = 1,
    SAY_DARK_FISSURE = 2,
    SAY_MARKED_PREY = 3,
    SAY_DEATH = 4
};

enum Spells
{
    SPELL_CHRISTMAS_VARIMATHRAS = 254076, //Winter Veil Holidays
    SPELL_INTRO_CONV = 250026,
    SPELL_DAILY_ESSENCE_VARIMATHRAS = 305314,

    SPELL_BERSERK = 26662,
    SPELL_ENERGY_GAIN = 244697,
    SPELL_CONTROL_AURA_AT = 243975,
    SPELL_TORMENT_OF_FLAMES_AT = 243967,
    SPELL_TORMENT_OF_FROST_AT = 243976,
    SPELL_TORMENT_OF_FEL_AT = 243979,
    SPELL_TORMENT_OF_SHADOWS_AT = 243974,
    SPELL_SHADOW_STRIKE = 243960,
    SPELL_MISERY = 243961,
    SPELL_ALONE_IN_DARKNESS_DMG = 243963,
    SPELL_ALONE_IN_DARKNESS_VISUAL = 244326,
    SPELL_DARK_FISSURE = 243999,
    SPELL_DARK_FISSURE_AT = 244003,
    SPELL_DARK_ERUPTION = 244006,
    SPELL_MARKED_PREY_FILTER = 244042,
    SPELL_MARKED_PREY_BETWEEN = 244068,
    SPELL_MARKED_PREY_VISUAL = 244522,
    SPELL_SHADOW_HUNTER_DMG = 244070,
    SPELL_SHADOW_HUNTER_KNOCK = 252105,

    //Heroic+
    SPELL_NECROTIC_EMBRACE_FILTER = 244093,
    SPELL_NECROTIC_EMBRACE_DOT = 244094,
    SPELL_NECROTIC_EMBRACE_PLR_FILTER = 244097,

    //Mythic
    SPELL_ECHOES_OF_DOOM_CHANNEL = 248732,
    SPELL_ECHOES_OF_DOOM_AT = 248725,
};

enum Events
{
    EVENT_DARK_FISSURE = 1,
    EVENT_MARKED_PREY = 2,
    EVENT_NECROTIC_EMBRACE = 3,
};

//122366
struct boss_varimathras : BossAI
{
    boss_varimathras(Creature* creature) : BossAI(creature, DATA_VARIMATHRAS) {}

    uint8 tormentCount = 0;
    uint32 tormentTimer = 0;
    uint32 berserkTimer = 0;

    void Reset() override
    {
        _Reset();
        me->SetPower(POWER_ENERGY, 0);
        //me->ClearSpellTargets(SPELL_ALONE_IN_DARKNESS_DMG);
        tormentCount = 0;
        tormentTimer = 0;
        berserkTimer = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);

        me->CastSpell(me, SPELL_INTRO_CONV, true);
        DoCast(me, SPELL_ENERGY_GAIN, true);
        DoCast(me, SPELL_CONTROL_AURA_AT, true);

        tormentTimer = 5000;
        berserkTimer = 310 * IN_MILLISECONDS;
        events.RescheduleEvent(EVENT_DARK_FISSURE, 16000);
        events.RescheduleEvent(EVENT_NECROTIC_EMBRACE, 35500);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();

        instance->DoOnPlayers([](Player* player)
        {
            player->CastSpell(player, SPELL_DAILY_ESSENCE_VARIMATHRAS, true);
        });

        AddDelayedEvent(1000, [this]() -> void
        {
            if (auto azara = instance->instance->GetCreature(instance->GetGuidData(NPC_AZARA)))
                azara->AI()->Talk(0);
        });
    }

    void EnterEvadeMode(EvadeReason w) override
    {
        BossAI::EnterEvadeMode();
        instance->SetData(DATA_COSMETIC_TORMENT, 5); //Disable
    }

    void SpellFinishCast(const SpellInfo* spell)
    {
        if (spell->Id == SPELL_DARK_FISSURE)
            Talk(SAY_DARK_FISSURE);
            uint32 delayTimer = 0;
                    me->CastSpell(SPELL_DARK_FISSURE_AT, true);
                    delayTimer += 100;
        if (spell->Id == SPELL_NECROTIC_EMBRACE_FILTER)
            Talk(SAY_NECROTIC_EMBRACE);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_MARKED_PREY_BETWEEN)
        {
            me->SummonCreature(NPC_SHADOW_OF_VARIMATHRAS_2, target->GetPosition());
            me->CastSpell(target, SPELL_SHADOW_HUNTER_DMG, true);
            me->CastSpell(target, SPELL_SHADOW_HUNTER_KNOCK, true);
        }
    }

    void OnAreaTriggerDespawn(uint32 spellId, Position pos, bool duration)
    {
        if (!duration)
            return;

        if (spellId == SPELL_DARK_FISSURE_AT)
            me->CastSpell(pos, SPELL_DARK_ERUPTION, true);
    }

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (!me->IsInCombat() || mode != AURA_REMOVE_BY_EXPIRE)
            return;

        switch (spellId)
        {
        case SPELL_MARKED_PREY_FILTER:
            me->CastSpell(target, SPELL_MARKED_PREY_BETWEEN, true);
            break;
        case SPELL_NECROTIC_EMBRACE_DOT:
            target->CastSpell(target, SPELL_NECROTIC_EMBRACE_PLR_FILTER, true);
            break;
        }
    }

    void SwitchTorment()
    {
        instance->SetData(DATA_COSMETIC_TORMENT, tormentCount);

        switch (tormentCount)
        {
        case 0: // Flames
            if (IsHeroicPlusRaid())
                tormentTimer = 100 * IN_MILLISECONDS; //1m40s
            else
            {
                tormentCount = 3;
                tormentTimer = 290 * IN_MILLISECONDS; //4m50s
            }
            DoCast(me, SPELL_TORMENT_OF_FLAMES_AT, true);
            break;
        case 1: // Frost
            if (IsHeroicPlusRaid())
                tormentTimer = 99 * IN_MILLISECONDS; //1m39s
            DoCast(me, SPELL_TORMENT_OF_FROST_AT, true);
            break;
        case 2: // Fel
            if (IsHeroicPlusRaid())
                tormentTimer = 90 * IN_MILLISECONDS; //1m30s
            DoCast(me, SPELL_TORMENT_OF_FEL_AT, true);
            break;
        case 3: // Shadows
            DoCast(me, SPELL_TORMENT_OF_SHADOWS_AT, true);
            break;
        }

        if (IsHeroicPlusRaid())
            ++tormentCount;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (berserkTimer)
        {
            if (berserkTimer <= diff)
            {
                berserkTimer = 0;
                DoCast(me, SPELL_BERSERK, true);
            }
            else
                berserkTimer -= diff;
        }

        if (tormentTimer)
        {
            if (tormentTimer <= diff)
            {
                tormentTimer = 0;
                SwitchTorment();
            }
            else
                tormentTimer -= diff;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_DARK_FISSURE:
                DoCast(SPELL_DARK_FISSURE);
                events.RescheduleEvent(EVENT_DARK_FISSURE, 30000);
                events.RescheduleEvent(EVENT_MARKED_PREY, urandms(6, 8));
                break;
            case EVENT_MARKED_PREY:
                Talk(SAY_MARKED_PREY);
                DoCast(SPELL_MARKED_PREY_FILTER);
                break;
            case EVENT_NECROTIC_EMBRACE:
                DoCast(SPELL_NECROTIC_EMBRACE_FILTER);
                events.RescheduleEvent(EVENT_NECROTIC_EMBRACE, 30000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//122590, 122643
struct npc_shadow_of_varimathras : public ScriptedAI
{
    npc_shadow_of_varimathras(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    uint32 doomTimer = 0;

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (me->GetEntry() == NPC_SHADOW_OF_VARIMATHRAS)
        {
            DoCast(me, SPELL_ALONE_IN_DARKNESS_VISUAL, true);

            AddDelayedEvent(100, [this]() -> void
            {
               // me->PlayOneShotAnimKit(13242);
                me->SendPlaySpellVisualKit(0, 83768, 100);
            });
        }

        if (me->GetEntry() == NPC_SHADOW_OF_VARIMATHRAS_2)
        {
            DoCast(me, SPELL_MARKED_PREY_VISUAL, true);
        }

        if (!IsMythicRaid())
        {
            AddDelayedEvent(600, [this]() -> void { me->NearTeleportTo(0.0f, 0.0f, 0.0f, 0.0f); });
            AddDelayedEvent(800, [this]() -> void { me->DespawnOrUnsummon(); });
        }
        else
        {
            doomTimer = 1000;
            //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void Reset() override {}

    void OnRemoveAuraTarget(Unit* target, uint32 spellId, AuraRemoveMode mode)
    {
        if (mode != AURA_REMOVE_BY_EXPIRE)
            return;

        if (spellId == SPELL_ECHOES_OF_DOOM_CHANNEL)
        {
            if (auto owner = me->GetOwner())
                owner->CastSpell(target, SPELL_ECHOES_OF_DOOM_AT, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (doomTimer)
        {
            if (doomTimer <= diff)
            {
                doomTimer = 4000;

                if (auto owner = me->GetOwner())
                {
                    if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 60.0f, true))
                        me->CastSpell(target, SPELL_ECHOES_OF_DOOM_CHANNEL);
                    else if (auto target = owner->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        me->CastSpell(target, SPELL_ECHOES_OF_DOOM_CHANNEL);
                }
            }
            else
                doomTimer -= diff;
        }
    }
};

//244697
class spell_varimathras_energy_gain : public AuraScript
{
    PrepareAuraScript(spell_varimathras_energy_gain);

    uint8 energyGain = 0;

    void OnTick(AuraEffect const* auraEffect)
    {
        auto caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        auto powerCount = caster->GetPower(POWER_ENERGY);

        if (energyGain == 5 && powerCount && powerCount != 44 && powerCount != 94)
            energyGain = 6;
        else
            energyGain = 5;

        caster->SetPower(POWER_ENERGY, powerCount + energyGain);

    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_varimathras_energy_gain::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//243957
class spell_varimathras_control_aura : public AuraScript
{
    PrepareAuraScript(spell_varimathras_control_aura);

    bool isAlone = false;
    uint32 tickCounter = 0;

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        SpellInfo const* spellInfo = eventInfo.GetDamageInfo()->GetSpellInfo();
        if (!spellInfo || !GetTarget() || eventInfo.GetActor()->GetGUID() == GetTarget()->GetGUID())
            return;

        if (!(spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_SHADOW))
            return;

        if (spellInfo->Id == SPELL_ALONE_IN_DARKNESS_DMG)
        {
            tickCounter = 0;
            isAlone = true;
        }
        GetTarget()->CastSpell(GetTarget(), SPELL_MISERY, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_varimathras_control_aura::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        //OnEffectPeriodic += AuraEffectPeriodicFn(spell_varimathras_control_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//243980
class spell_varimathras_torment_of_fel : public AuraScript
{
    PrepareAuraScript(spell_varimathras_torment_of_fel);

    void HandleTick(AuraEffect const* aurEff)
    {
        uint32 amount = 0;

        if (aurEff->GetTickNumber() > 1)
            amount = aurEff->GetAmount() * aurEff->GetTickNumber() * 0.75f;
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_varimathras_torment_of_fel::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};


//244097
class spell_varimathras_necrotic_embrace : public SpellScript
{
    PrepareSpellScript(spell_varimathras_necrotic_embrace);

    void HandleDummy(SpellEffIndex /*effectIndex*/)
    {
        if (!GetCaster() || !GetHitUnit() || GetCaster()->GetGUID() == GetHitUnit()->GetGUID())
            return;

        auto instance = GetCaster()->GetInstanceScript();
        if (!instance || instance->GetBossState(DATA_VARIMATHRAS) != IN_PROGRESS)
            return;

        if (auto varimathras = instance->instance->GetCreature(instance->GetGuidData(NPC_VARIMATHRAS)))
            varimathras->CastSpell(GetHitUnit(), SPELL_NECROTIC_EMBRACE_DOT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_varimathras_necrotic_embrace::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_varimathras()
{
    RegisterCreatureAI(boss_varimathras);
    RegisterCreatureAI(npc_shadow_of_varimathras);
    RegisterAuraScript(spell_varimathras_energy_gain);
    RegisterAuraScript(spell_varimathras_control_aura);
    RegisterAuraScript(spell_varimathras_torment_of_fel);
    RegisterSpellScript(spell_varimathras_necrotic_embrace);
}
