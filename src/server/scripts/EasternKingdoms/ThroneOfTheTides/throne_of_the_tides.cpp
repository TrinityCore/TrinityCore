/*
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

#include "throne_of_the_tides.h"
#include "AreaBoundary.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "MoveSplineInit.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Transport.h"
#include "Vehicle.h"

enum OzumatVehicleBig
{
    SEAT_TENTACLE_BLOCK = 0,
    SEAT_DEFENSE_SYSTEM = 1,
    SEAT_ESCAPE         = 2,

    EVENT_CHANGE_TO_SHOCK_SEAT = 1,
    EVENT_CHANGE_TO_ESCAPE_SEAT,
};

Position const OzumatEscapePos = { 75.f, 0.f, 0.f, 3.141593f }; // Looks odd but it's sniffed

struct npc_tott_ozumat_vehicle_big : public ScriptedAI
{
    npc_tott_ozumat_vehicle_big(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (_instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED)
            if (Creature* ozumat = DoSummon(NPC_OZUMAT, me->GetPosition()))
                me->HandleSpellClick(ozumat, SEAT_TENTACLE_BLOCK);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_DEFENSE_SYSTEM_ACTIVATED)
            _events.ScheduleEvent(EVENT_CHANGE_TO_SHOCK_SEAT, 2s);
    }

    void PassengerBoarded(Unit* who, int8 seatId, bool apply) override
    {
        if (!who)
            return;
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHANGE_TO_SHOCK_SEAT:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                        if (Unit* ozumat = vehicle->GetPassenger(SEAT_TENTACLE_BLOCK))
                            me->HandleSpellClick(ozumat, SEAT_DEFENSE_SYSTEM);
                    _events.ScheduleEvent(EVENT_CHANGE_TO_ESCAPE_SEAT, 29s);
                    break;
                case EVENT_CHANGE_TO_ESCAPE_SEAT:
                    if (Vehicle* vehicle = me->GetVehicleKit())
                    {
                        if (Unit* ozumat = vehicle->GetPassenger(SEAT_DEFENSE_SYSTEM))
                        {
                            me->HandleSpellClick(ozumat, SEAT_ESCAPE);
                            me->DespawnOrUnsummon(6s);
                            if (Creature* creature = ozumat->ToCreature())
                                creature->DespawnOrUnsummon(6s);
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

enum LadyNazjarGauntlet
{
    // Texts
    SAY_CALL_INVADERS               = 0,
    SAY_RETREAT                     = 1,

    // Spells
    SPELL_MURLOC_LEASH_VISUAL_RIGHT = 74563,
    SPELL_MURLOC_LEASH_VISUAL_LEFT  = 74568,
    SPELL_TRIGGER_MURLOC            = 74889,
    SPELL_TRIGGER_MURLOC_END        = 76890,

    // Creatures
    NPC_DEEP_MURLOC_DRUDGE          = 39960,

    // Events
    EVENT_SUMMON_MURLOC_GROUP_LEFT  = 1,
    EVENT_SUMMON_MURLOC_GROUP_RIGHT,
    EVENT_TRIGGER_MURLOC,
    EVENT_ESCAPE,
};

Position const DeepMurlocDrudgePositions[] =
{
    // Left Side
    { -25.83854f, 796.2708f, 805.673f,  3.124139f },
    { -25.75174f, 799.0087f, 805.7594f, 3.141593f },
    { -29.20486f, 799.5851f, 803.6364f, 3.141593f },
    { -30.29688f, 794.8941f, 803.2464f, 3.106686f },
    { -32.35243f, 798.1597f, 801.7277f, 3.124139f },

    // Right Side
    { -29.51736f, 810.2552f, 803.2809f, 3.193953f },
    { -25.79167f, 809.467f,  805.1479f, 3.176499f },
    { -27.95139f, 805.7361f, 804.0556f, 3.159046f },
    { -31.125f,   807.9219f, 802.3655f, 3.176499f },
    { -34.05556f, 810.4774f, 801.454f,  3.193953f }
};

Position const NazjarEscapePath[] =
{
    { -3.8368f,  802.2631f, 808.4081f },
    { 17.6632f,  802.5131f, 806.6581f },
    { 30.1632f,  791.0131f, 806.6581f },
    { 50.6632f,  780.7631f, 806.6581f },
    { 70.6632f,  792.5131f, 806.6581f },
    { 88.6632f,  804.0131f, 806.9081f },
    { 108.5174f, 802.9653f, 808.2791f }
};

struct npc_tott_lady_nazjar : public ScriptedAI
{
    npc_tott_lady_nazjar(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void Reset() override
    {
        _killedInvaders = 0;
        me->SetReactState(REACT_PASSIVE);
        Talk(SAY_CALL_INVADERS);

        for (uint8 i = 0; i < 5; i++)
        {
            if (Creature* murloc = DoSummon(NPC_DEEP_MURLOC_DRUDGE, DeepMurlocDrudgePositions[i]))
            {
                _leftMurlocGUIDs.insert(murloc->GetGUID());
                murloc->CastSpell(me, SPELL_MURLOC_LEASH_VISUAL_LEFT);
            }
        }

        for (uint8 i = 5; i < 10; i++)
        {
            if (Creature* murloc = DoSummon(NPC_DEEP_MURLOC_DRUDGE, DeepMurlocDrudgePositions[i]))
            {
                _rightMurlocGUIDs.insert(murloc->GetGUID());
                murloc->CastSpell(me, SPELL_MURLOC_LEASH_VISUAL_RIGHT);
            }
        }

        _events.ScheduleEvent(EVENT_TRIGGER_MURLOC, 37s + 500ms);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_NAZJAR_INVADER_2 || summon->GetEntry() == NPC_NAZJAR_SPIRITMENDER_2)
        {
            _killedInvaders++;
            if (_killedInvaders == 6)
            {
                Talk(SAY_RETREAT);
                DoCastAOE(SPELL_TRIGGER_MURLOC_END);
                if (GameObject* door = _instance->GetGameObject(DATA_ABYSSAL_MAW_DOOR_1))
                    door->SetGoState(GO_STATE_ACTIVE);
                _events.Reset();
                _events.ScheduleEvent(EVENT_ESCAPE, 5s + 300ms);
            }
        }
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        bool useLeftGUIDs = false;
        if (spell->Id == SPELL_TRIGGER_MURLOC)
        {
            for (ObjectGuid guid : _leftMurlocGUIDs)
                if (target->GetGUID() == guid)
                    useLeftGUIDs = true;

            for (ObjectGuid guid : useLeftGUIDs ? _leftMurlocGUIDs : _rightMurlocGUIDs)
            {
                if (Creature* murloc = ObjectAccessor::GetCreature(*me, guid))
                {
                    if (murloc->IsAIEnabled)
                    {
                        murloc->InterruptNonMeleeSpells(false);
                        murloc->AI()->DoZoneInCombat();
                    }
                }
            }

            if (useLeftGUIDs)
            {
                _leftMurlocGUIDs.clear();
                _events.ScheduleEvent(EVENT_SUMMON_MURLOC_GROUP_LEFT, 13s);
            }
            else
            {
                _rightMurlocGUIDs.clear();
                _events.ScheduleEvent(EVENT_SUMMON_MURLOC_GROUP_RIGHT, 13s);
            }
        }
        else if (spell->Id == SPELL_TRIGGER_MURLOC_END)
        {
            if (Creature* murloc = target->ToCreature())
            {
                if (murloc->IsAIEnabled)
                {
                    murloc->InterruptNonMeleeSpells(false);
                    murloc->AI()->DoZoneInCombat();
                }
            }
        }
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_DEEP_MURLOC_DRUDGE)
            summon->SetNoCallAssistance(true);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TRIGGER_MURLOC:
                    DoCastAOE(SPELL_TRIGGER_MURLOC, true);
                    _events.Repeat(11s);
                    break;
                case EVENT_SUMMON_MURLOC_GROUP_LEFT:
                    for (uint8 i = 0; i < 5; i++)
                    {
                        if (Creature* murloc = DoSummon(NPC_DEEP_MURLOC_DRUDGE, DeepMurlocDrudgePositions[i]))
                        {
                            _leftMurlocGUIDs.insert(murloc->GetGUID());
                            murloc->CastSpell(me, SPELL_MURLOC_LEASH_VISUAL_LEFT);
                        }
                    }
                    break;
                case EVENT_SUMMON_MURLOC_GROUP_RIGHT:
                    for (uint8 i = 5; i < 10; i++)
                    {
                        if (Creature* murloc = DoSummon(NPC_DEEP_MURLOC_DRUDGE, DeepMurlocDrudgePositions[i]))
                        {
                            _rightMurlocGUIDs.insert(murloc->GetGUID());
                            murloc->CastSpell(me, SPELL_MURLOC_LEASH_VISUAL_RIGHT);
                        }
                    }
                    break;
                case EVENT_ESCAPE:
                    me->GetMotionMaster()->MoveSmoothPath(0, NazjarEscapePath, 7, false, false);
                    me->DespawnOrUnsummon(12s + 600ms);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    GuidSet _leftMurlocGUIDs;
    GuidSet _rightMurlocGUIDs;
    uint8 _killedInvaders;

};

class InCombatCheck
{
    public:
        InCombatCheck() { }

        bool operator()(WorldObject* object)
        {
            return (object->ToUnit()->IsInCombat());
        }
};

class spell_tott_trigger_murloc : public SpellScript
{
    PrepareSpellScript(spell_tott_trigger_murloc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TRIGGER_MURLOC_END });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if(InCombatCheck());

        if (targets.empty())
            return;

        if (GetSpellInfo()->Id != SPELL_TRIGGER_MURLOC_END)
            Trinity::Containers::RandomResize(targets, GetSpellInfo()->Effects[EFFECT_0].BasePoints);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tott_trigger_murloc::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class at_tott_first_invader_event : public AreaTriggerScript
{
    public:
        at_tott_first_invader_event() : AreaTriggerScript("at_tott_first_invader_event") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_FIRST_INVADERS)
                    instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_FIRST_INVADERS);

            return true;
        }
};

struct go_tott_defense_system : public GameObjectAI
{
    go_tott_defense_system(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnReportUse(Player* /*player*/) override
    {
        if (GameObject* system = me->ToGameObject())
        {
            system->SendCustomAnim(0);
            _instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED);
        }

        return true;
    }
private:
    InstanceScript * _instance;
};

class spell_tott_camera: public SpellScript
{
    PrepareSpellScript(spell_tott_camera);

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Player* player = GetHitPlayer())
            player->SendCinematicStart(CINEMATIC_DEFENSE_SYSTEM_ACTIVE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tott_camera::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum ShockDefense
{
    SPELL_SHOCK_DEFENSE_DEST = 86618
};

class spell_tott_shock_defense_script : public SpellScript
{
    PrepareSpellScript(spell_tott_shock_defense_script);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHOCK_DEFENSE_DEST });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetHitUnit(), SPELL_SHOCK_DEFENSE_DEST, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tott_shock_defense_script::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_tott_ulthok_intro_visual_impact: public SpellScript
{
    PrepareSpellScript(spell_tott_ulthok_intro_visual_impact);

    void HandleScriptEffect(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->RemoveAurasDueToSpell(GetSpellInfo()->Effects[effIndex].BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tott_ulthok_intro_visual_impact::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_tott_shock_defense : public SpellScript
{
    PrepareSpellScript(spell_tott_shock_defense);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        float x = caster->GetPositionX() + frand(-80.0f, 80.0f);
        float y = caster->GetPositionY() + frand(-80.0f, 80.0f);
        float z = caster->GetPositionZ() + frand(-80.0f, 80.0f);

        dest.Relocate({ x, y, z, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_tott_shock_defense::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

enum OzumatTentacle
{
    SPELL_TENTACLE_KNOCKBACK = 84566
};

class at_tott_tentacle_knockback : public AreaTriggerScript
{
    public:
        at_tott_tentacle_knockback() : AreaTriggerScript("at_tott_tentacle_knockback") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED)
                    if (Creature* trigger = player->FindNearestCreature(NPC_WORLD_TRIGGER_NOT_IMMUNE_PC, 100.0f, true))
                        trigger->CastSpell(player, SPELL_TENTACLE_KNOCKBACK, true);

            return true;
        }
};

class at_tott_lady_nazjar_gauntlet : public AreaTriggerScript
{
    public:
        at_tott_lady_nazjar_gauntlet() : AreaTriggerScript("at_tott_lady_nazjar_gauntlet") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_LADY_NAZJAR_GAUNTLET)
                    instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_LADY_NAZJAR_GAUNTLET);

            return true;
        }
};

class at_tott_commander_ulthok_summon : public AreaTriggerScript
{
    public:
        at_tott_commander_ulthok_summon() : AreaTriggerScript("at_tott_commander_ulthok_summon") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) == EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED)
                    instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_ULTHOK_ARRIVED);

            return true;
        }
};

class at_tott_neptulon_intro : public AreaTriggerScript
{
    public:
        at_tott_neptulon_intro() : AreaTriggerScript("at_tott_neptulon_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) <= EVENT_INDEX_ULTHOK_ARRIVED)
                    instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_NEPTULON_INTRO_DONE);

            return true;
        }
};

void AddSC_throne_of_the_tides()
{
    RegisterThroneOfTheTidesCreatureAI(npc_tott_ozumat_vehicle_big);
    RegisterThroneOfTheTidesCreatureAI(npc_tott_lady_nazjar);
    RegisterSpellScript(spell_tott_trigger_murloc);
    RegisterGameObjectAI(go_tott_defense_system);
    RegisterSpellScript(spell_tott_camera);
    RegisterSpellScript(spell_tott_shock_defense_script);
    RegisterSpellScript(spell_tott_ulthok_intro_visual_impact);
    RegisterSpellScript(spell_tott_shock_defense);
    new at_tott_first_invader_event();
    new at_tott_tentacle_knockback();
    new at_tott_lady_nazjar_gauntlet();
    new at_tott_commander_ulthok_summon();
    new at_tott_neptulon_intro();
}
