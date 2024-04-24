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

/* ScriptData
SDName: Sunken_Temple
SD%Complete: 100
SDComment: Area Trigger + Puzzle event support
SDCategory: Sunken Temple
EndScriptData */

/* ContentData
at_malfurion_Stormrage_trigger
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "sunken_temple.h"

/*#####
# at_malfurion_Stormrage_trigger
#####*/

enum MalfurionMisc
{
    NPC_MALFURION_STORMRAGE           = 15362,
    QUEST_ERANIKUS_TYRANT_OF_DREAMS   = 8733,
    QUEST_THE_CHARGE_OF_DRAGONFLIGHTS = 8555,
};

class at_malfurion_stormrage : public AreaTriggerScript
{
    public:
        at_malfurion_stormrage() : AreaTriggerScript("at_malfurion_stormrage") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
        {
            if (player->GetInstanceScript() && !player->FindNearestCreature(NPC_MALFURION_STORMRAGE, 15.0f) &&
                player->GetQuestStatus(QUEST_THE_CHARGE_OF_DRAGONFLIGHTS) == QUEST_STATUS_REWARDED && player->GetQuestStatus(QUEST_ERANIKUS_TYRANT_OF_DREAMS) != QUEST_STATUS_REWARDED)
                player->SummonCreature(NPC_MALFURION_STORMRAGE, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), -1.52f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 100s);
            return false;
        }
};

/*#####
# npc_hakkari_bloodkeeper
#####*/

enum HakkariBloodkeeper
{
    EVENT_CAST_SHADOW_BOLT = 1,
    EVENT_CAST_CORRUPTION,
    SPELL_SHADOW_BOLT      = 12471,
    SPELL_CORRUPTION       = 11671,
};

class npc_hakkari_bloodkeeper : public CreatureScript
{
public:
    npc_hakkari_bloodkeeper() : CreatureScript("npc_hakkari_bloodkeeper") { }

    struct npc_hakkari_bloodkeeperAI : public ScriptedAI
    {
        npc_hakkari_bloodkeeperAI(Creature* creature) : ScriptedAI(creature), _instance(*creature->GetInstanceScript()) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _events.ScheduleEvent(EVENT_CAST_SHADOW_BOLT, 0s, 2s);
            _events.ScheduleEvent(EVENT_CAST_CORRUPTION, 13s, 17s);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                 return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_SHADOW_BOLT:
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    _events.ScheduleEvent(EVENT_CAST_SHADOW_BOLT, 3s, 4s);
                    break;
                case EVENT_CAST_CORRUPTION:
                    DoCastVictim(SPELL_CORRUPTION);
                    _events.ScheduleEvent(EVENT_CAST_CORRUPTION, 11s, 15s);
                    break;
                default:
                    break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunkenTempleAI<npc_hakkari_bloodkeeperAI>(creature);
    }
};

/*#####
# npc_nightmare_suppressor
#####*/

enum NightmareSuppressor
{
    EVENT_CAST_SUPPRESSOR     = 1,
    SAY_RANDOM_SPAWN          = 0,
    POINT_ID_AVATAR_OF_HAKKAR = 0
};

Position const AvatarHakkarSpawnPos = { -467.107f, 273.063f, -90.449f, 3.0f };

class npc_nightmare_suppressor : public CreatureScript
{
public:
    npc_nightmare_suppressor() : CreatureScript("npc_nightmare_suppressor") { }

    struct npc_nightmare_suppressorAI : public ScriptedAI
    {
        npc_nightmare_suppressorAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

        InstanceScript* instance;

        void DoAction(int32 action) override
        {
            switch (action)
            {
            case ACTION_CAST_SUPPRESSOR_NIGHTMARE:
                //me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_RUN, 2);
                me->GetMotionMaster()->MovePoint(POINT_ID_AVATAR_OF_HAKKAR, AvatarHakkarSpawnPos);
                Talk(SAY_RANDOM_SPAWN);
                _events.ScheduleEvent(EVENT_CAST_SUPPRESSOR, 12s);
                break;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (Creature* shade = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADE_OF_HAKKAR)))
                shade->AI()->DoAction(ACTION_REMOVE_SUPPRESSOR);
            _events.CancelEvent(EVENT_CAST_SUPPRESSOR);
            me->CastStop();
            me->SetSpeed(MOVE_RUN, 5);
            //AttackStart(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->IsEngaged())
                 return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CAST_SUPPRESSOR:
                    if (!me->IsInCombat())
                        DoCast(SPELL_SUPPRESSION);
                    break;
                default:
                    break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetSunkenTempleAI<npc_nightmare_suppressorAI>(creature);
    }
};

/*#####
# go_atalai_statue
#####*/

class go_atalai_statue : public GameObjectScript
{
    public:
        go_atalai_statue() : GameObjectScript("go_atalai_statue") { }

        struct go_atalai_statueAI : public GameObjectAI
        {
            go_atalai_statueAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* /*player*/) override
            {
                instance->SetData(EVENT_STATE, me->GetEntry());
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetSunkenTempleAI<go_atalai_statueAI>(go);
        }
};

/*#####
# go_eternal_flame
#####*/

class go_eternal_flame : public GameObjectScript
{
public:
    go_eternal_flame() : GameObjectScript("go_eternal_flame") { }

    struct go_eternal_flameAI : public GameObjectAI
    {
        go_eternal_flameAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

        InstanceScript* instance;

        bool OnGossipHello(Player* /*player*/) override
        {
            me->SetGoState(GO_STATE_ACTIVE);
            me->SetFlag(GO_FLAG_NOT_SELECTABLE);
            instance->SetData(DATA_ETERNAL_FLAME, instance->GetData(DATA_ETERNAL_FLAME) + 1);
            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetSunkenTempleAI<go_eternal_flameAI>(go);
    }
};

enum HexOfJammalan
{
    SPELL_HEX_OF_JAMMALAN_TRANSFORM    = 12480,
    SPELL_HEX_OF_JAMMALAN_CHARM        = 12483
};

// 12479 - Hex of Jammal'an
class spell_sunken_temple_hex_of_jammalan : public AuraScript
{
    PrepareAuraScript(spell_sunken_temple_hex_of_jammalan);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HEX_OF_JAMMALAN_TRANSFORM, SPELL_HEX_OF_JAMMALAN_CHARM });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        Unit* caster = GetCaster();

        if (!caster || !caster->IsAlive())
            return;

        caster->CastSpell(target, SPELL_HEX_OF_JAMMALAN_TRANSFORM, true);
        caster->CastSpell(target, SPELL_HEX_OF_JAMMALAN_CHARM, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sunken_temple_hex_of_jammalan::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 12480 - Hex of Jammal'an
class spell_sunken_temple_hex_of_jammalan_transform : public AuraScript
{
    PrepareAuraScript(spell_sunken_temple_hex_of_jammalan_transform);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HEX_OF_JAMMALAN_CHARM });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_HEX_OF_JAMMALAN_CHARM);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sunken_temple_hex_of_jammalan_transform::AfterRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 12346 - Awaken the Soulflayer
class spell_sunken_temple_awaken_the_soulflayer : public SpellScript
{
    PrepareSpellScript(spell_sunken_temple_awaken_the_soulflayer);

    bool Load() override
    {
        _instance = GetCaster()->GetInstanceScript();
        _map = GetCaster()->FindMap();
        return _instance && _map;
    }

    void HandleSendEvent(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (_instance->GetBossState(BOSS_AVATAR_OF_HAKKAR) != NOT_STARTED)
            return;
        if (TempSummon* shade = _map->SummonCreature(NPC_SHADE_OF_HAKKAR, AvatarHakkarSpawnPos))
        {
            shade->AI()->Talk(SAY_SPAWN_SHADE);
            _instance->SetBossState(BOSS_AVATAR_OF_HAKKAR, IN_PROGRESS);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sunken_temple_awaken_the_soulflayer::HandleSendEvent, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
    }
private:
    InstanceScript* _instance = nullptr;
    Map* _map = nullptr;
};

void AddSC_sunken_temple()
{
    new at_malfurion_stormrage();
    new go_atalai_statue();
    new go_eternal_flame();
    new npc_nightmare_suppressor();
    new npc_hakkari_bloodkeeper();
    RegisterSpellScript(spell_sunken_temple_hex_of_jammalan);
    RegisterSpellScript(spell_sunken_temple_hex_of_jammalan_transform);
    RegisterSpellScript(spell_sunken_temple_awaken_the_soulflayer);
}
