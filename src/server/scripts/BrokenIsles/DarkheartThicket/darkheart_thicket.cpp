/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "darkheart_thicket.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_STAR_SHOWER                 = 200658,
    SPELL_STAR_SHOWER_TRIGGER         = 204383,

    SPELL_PROPELLING_CHARGE_DAMAGE    = 200771,

    SPELL_VILE_MUSHROOM_DAMAGE        = 198916,
    SPELL_VILE_MUSHROOM_MODEL         = 198937,
    SPELL_VILE_MUSHROOM_AT            = 198915,

    SPELL_TORMENTING_FEAR             = 204246,

    SPELL_BLOOD_ASSAULT_DAMAGE        = 201227,

    SPELL_MALFURION_ROOT              = 199752,
};

enum Events
{
    EVENT_NONE,

    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3
};

enum Phase
{
    PHASE_NORMAL,
    PHASE_OUTRO,
};

enum Talks
{
    SAY_MALFURION_OUTRO   = 0
};

#define GOSSIP_MALFURION_OUTRO "Teleport me to Dalaran!"

// Vile Mushroom
// NPC ID - 100960
class npc_dt_trash_vile_mushroom : public CreatureScript
{
public:
    npc_dt_trash_vile_mushroom() : CreatureScript("npc_dt_trash_vile_mushroom") {}

    class npc_dt_trash_vile_mushroom_AI : public ScriptedAI
    {
    public:

        npc_dt_trash_vile_mushroom_AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->CastSpell(me, SPELL_VILE_MUSHROOM_MODEL, true);
            me->CastSpell(me, SPELL_VILE_MUSHROOM_AT, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dt_trash_vile_mushroom_AI(creature);
    }
};

// Malfurion Stormrage
// NPC ID - 100652
class npc_dt_malfurion_stormrage : public CreatureScript
{
public:
    npc_dt_malfurion_stormrage() : CreatureScript("npc_dt_malfurion_stormrage") {}

    class npc_dt_malfurion_stormrage_AI : public ScriptedAI
    {
    public:

        npc_dt_malfurion_stormrage_AI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;
        Phase phase;

        void Initialize()
        {
            phase = PHASE_NORMAL;
        }

        void Reset() override
        {
            events.Reset();
            Initialize();

            me->CastSpell(me, SPELL_MALFURION_ROOT, true);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_MALFURION_OUTRO)
            {
                phase = PHASE_OUTRO;
                events.Reset();
                events.ScheduleEvent(EVENT_OUTRO_1, 1000);
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == 0)
            {
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->SetFacingTo(0.922050f);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (phase == PHASE_OUTRO)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_OUTRO_1:
                        me->RemoveAurasDueToSpell(SPELL_MALFURION_ROOT);
                        events.ScheduleNextEvent(1s);
                        break;

                    case EVENT_OUTRO_2:
                        Talk(SAY_MALFURION_OUTRO);
                        events.ScheduleNextEvent(2s);
                        break;

                    case EVENT_OUTRO_3:
                        me->SetWalk(true);
                        me->GetMotionMaster()->MovePoint(0, 2712.7009f, 1329.9001f, 128.3684f);
                        break;
                }
            }
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player)
        {
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_MALFURION_OUTRO, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        }
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action) override
    {
        if (!player)
            return false;

        if (action == GOSSIP_ACTION_INFO_DEF + 1)
        {
            CloseGossipMenuFor(player);
            player->TeleportTo(1220, -843.0690f, 4431.4448f, 742.5369f, 4.8068f);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dt_malfurion_stormrage_AI(creature);
    }
};

// Star Shower - 200658
class spell_dt_trash_star_shower : public SpellScriptLoader
{
public:
    spell_dt_trash_star_shower() : SpellScriptLoader("spell_dt_trash_star_shower") { }

    class spell_dt_trash_star_shower_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dt_trash_star_shower_SpellScript);

        void HandleOnCast()
        {
            if (Unit* caster = GetCaster())
            {
                float radius = 40.0f;
                std::list<Unit*> targetList;
                caster->GetAttackableUnitListInRange(targetList, radius);

                if (!targetList.empty())
                {
                    for (auto itr : targetList)
                    {
                        caster->CastSpell(itr, SPELL_STAR_SHOWER_TRIGGER, true);
                    }
                }
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dt_trash_star_shower_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dt_trash_star_shower_SpellScript();
    }
};

// Tormenting Eye - 204243
class spell_dt_trash_tormenting_eye : public SpellScriptLoader
{
public:
    spell_dt_trash_tormenting_eye() : SpellScriptLoader("spell_dt_trash_tormenting_eye") { }

    class spell_dt_trash_tormenting_eye_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dt_trash_tormenting_eye_AuraScript);

        void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetTarget();
            if (!caster || !target)
                return;

            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                caster->CastSpell(target, SPELL_TORMENTING_FEAR, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_dt_trash_tormenting_eye_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dt_trash_tormenting_eye_AuraScript::HandleEffectRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dt_trash_tormenting_eye_AuraScript::HandleEffectRemove, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dt_trash_tormenting_eye_AuraScript();
    }
};

// Hatch Whelpling - 199313
class spell_dt_trash_hatch_whelpling : public SpellScriptLoader
{
public:
    spell_dt_trash_hatch_whelpling() : SpellScriptLoader("spell_dt_trash_hatch_whelpling") { }

    class spell_dt_trash_hatch_whelpling_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dt_trash_hatch_whelpling_SpellScript);

        void HandleOnCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->KillSelf(false);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_dt_trash_hatch_whelpling_SpellScript::HandleOnCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dt_trash_hatch_whelpling_SpellScript();
    }
};

// Propelling Charge - 200768
// AreaTriggerID - 5670
class at_dt_trash_propelling_charge : public AreaTriggerEntityScript
{
public:
    at_dt_trash_propelling_charge() : AreaTriggerEntityScript("at_dt_trash_propelling_charge") { }

    struct at_dt_trash_propelling_chargeAI : AreaTriggerAI
    {
        at_dt_trash_propelling_chargeAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
                caster->CastSpell(unit, SPELL_PROPELLING_CHARGE_DAMAGE, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_dt_trash_propelling_chargeAI(areatrigger);
    }
};

// Vile Mushroom - 198915
// AreaTriggerID - 5486
class at_dt_trash_vile_mushroom : public AreaTriggerEntityScript
{
public:
    at_dt_trash_vile_mushroom() : AreaTriggerEntityScript("at_dt_trash_vile_mushroom") { }

    struct at_dt_trash_vile_mushroomAI : AreaTriggerAI
    {
        at_dt_trash_vile_mushroomAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_VILE_MUSHROOM_DAMAGE, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_dt_trash_vile_mushroomAI(areatrigger);
    }
};

// Blood Assault - 201226
// AreaTriggerID - 5714
class at_dt_trash_blood_assault : public AreaTriggerEntityScript
{
public:
    at_dt_trash_blood_assault() : AreaTriggerEntityScript("at_dt_trash_blood_assault") { }

    struct at_dt_trash_blood_assaultAI : AreaTriggerAI
    {
        at_dt_trash_blood_assaultAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
                caster->CastSpell(unit, SPELL_BLOOD_ASSAULT_DAMAGE, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_dt_trash_blood_assaultAI(areatrigger);
    }
};

void AddSC_darkheart_thicket()
{
    // NPC Scripts
    new npc_dt_trash_vile_mushroom();
    new npc_dt_malfurion_stormrage();

    // Spell Scripts
    new spell_dt_trash_star_shower();
    new spell_dt_trash_tormenting_eye();
    new spell_dt_trash_hatch_whelpling();

    // AreaTrigger Scripts
    new at_dt_trash_propelling_charge();
    new at_dt_trash_vile_mushroom();
    new at_dt_trash_blood_assault();
}
