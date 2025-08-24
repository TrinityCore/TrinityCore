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

#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum WitchHuntData
{
    NPC_HELENA_GENTLE_HUMAN     = 124922,
    NPC_HEXBOUND_SNARLER        = 128347,

    SAY_HELENA_AGGRO            = 0,
    SAY_HELENA_HALF_LIFE        = 1,
    SAY_HELENA_DEATH            = 2,

    EVENT_HELENA_RUINED_BOLT    = 1,
    EVENT_HELENA_SUMMON_ALIVE,
    EVENT_HELENA_SUMMON_ATTACK,

    SPELL_TAKE_A_SEAT_CURSED    = 248423,
    SPELL_HELENA_EMPOWERING     = 257877,
    SPELL_HELENA_RUINED_BOLT    = 256865
};

// EventID: 59332
class event_listen_to_helenas_story : public EventScript
{
public:
    event_listen_to_helenas_story() : EventScript("event_listen_to_helenas_story") {}

    void OnTrigger(WorldObject* /*object*/, WorldObject* invoker, uint32 /*eventId*/) override
    {
        if (Player* player = invoker->ToPlayer())
        {
            player->CastSpell(player, SPELL_TAKE_A_SEAT_CURSED);

            if (Creature* helenaObject = player->FindNearestCreatureWithOptions(25.0f, { .CreatureId = NPC_HELENA_GENTLE_HUMAN, .IgnorePhases = true }))
                helenaObject->SummonPersonalClone(helenaObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
        }
    }
};

constexpr Position HelenaPetSummonPos = { 181.513885f, 1987.2222f, 101.9137f, 1.667730f };

// 124953 - Helena Gentle
struct npc_helena_gentle_witch_hunt : public ScriptedAI
{
    npc_helena_gentle_witch_hunt(Creature* creature) : ScriptedAI(creature), _halfLifeTriggered(false) { }

    void JustAppeared() override
    {
        _oocScheduler.Schedule(0ms, [this](TaskContext context)
        {
            if (Creature* hexboundSnarler = me->FindNearestCreatureWithOptions(50.0f, { .CreatureId = NPC_HEXBOUND_SNARLER, .StringId = "HelenaSummon", .IsAlive = FindCreatureAliveState::Alive }))
            {
                if (!hexboundSnarler->IsInCombat())
                    _hexboundSnarlerGuid = hexboundSnarler->GetGUID();
                else
                    context.Repeat(1s);
            }
            else
                SummonHexboundSnarler();
        });
    }

    void Reset() override
    {
        _halfLifeTriggered = false;
        _events.Reset();
        _oocScheduler.CancelAll();
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_HELENA_AGGRO);
        _events.ScheduleEvent(EVENT_HELENA_RUINED_BOLT, 9s);
        _events.ScheduleEvent(EVENT_HELENA_SUMMON_ALIVE, 1s);

        _oocScheduler.CancelAll();

        if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
            hexboundSnarler->AI()->AttackStart(who);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_halfLifeTriggered && me->HealthBelowPctDamaged(50, damage))
        {
            Talk(SAY_HELENA_HALF_LIFE);
            _halfLifeTriggered = true;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon(0ms, 1min);

        if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
            hexboundSnarler->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_HELENA_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            _oocScheduler.Update(diff);
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HELENA_RUINED_BOLT:
                    DoCastVictim(SPELL_HELENA_RUINED_BOLT);
                    _events.ScheduleEvent(EVENT_HELENA_RUINED_BOLT, 9s);
                    break;
                case EVENT_HELENA_SUMMON_ALIVE:
                    if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
                    {
                        hexboundSnarler->SetAIAnimKitId(0);
                        hexboundSnarler->PlayOneShotAnimKitId(1099);
                        _events.ScheduleEvent(EVENT_HELENA_SUMMON_ATTACK, 2s);
                    }
                    break;
                case EVENT_HELENA_SUMMON_ATTACK:
                    if (Creature* hexboundSnarler = ObjectAccessor::GetCreature(*me, _hexboundSnarlerGuid))
                    {
                        hexboundSnarler->SetImmuneToAll(false);
                        hexboundSnarler->SetUninteractible(false);
                        hexboundSnarler->SetReactState(REACT_AGGRESSIVE);
                    }
                    break;
                default:
                    break;
            }
        }
    }

    void SummonHexboundSnarler()
    {
        if (TempSummon* hexboundSnarler = me->SummonCreature(NPC_HEXBOUND_SNARLER, HelenaPetSummonPos))
        {
            me->CastSpell(hexboundSnarler, SPELL_HELENA_EMPOWERING);

            _hexboundSnarlerGuid = hexboundSnarler->GetGUID();
            hexboundSnarler->SetScriptStringId("HelenaSummon");
            hexboundSnarler->SetAIAnimKitId(730);
            hexboundSnarler->SetReactState(REACT_PASSIVE);
            hexboundSnarler->SetImmuneToAll(true);
            hexboundSnarler->SetUninteractible(true);
        }
    }

private:
    EventMap _events;
    TaskScheduler _oocScheduler;
    ObjectGuid _hexboundSnarlerGuid;
    bool _halfLifeTriggered;
};

enum TheFinalEffigyData
{
    NPC_CYRIL_WHITE_CURSED          = 130419,

    SPELL_DRUSTVAR_FALLHAVEN_SCENE  = 281070
};

// 254558 - Cancel Deathcurse
class spell_drustvar_cancel_deathcurse : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRUSTVAR_FALLHAVEN_SCENE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DRUSTVAR_FALLHAVEN_SCENE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_drustvar_cancel_deathcurse::HandleHit, EFFECT_0, SPELL_EFFECT_REMOVE_AURA_2);
    }
};

// Scene 2131
class scene_drustvar_cleanse_fallhaven : public SceneScript
{
public:
    scene_drustvar_cleanse_fallhaven() : SceneScript("scene_drustvar_cleanse_fallhaven") {}

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::OnConditionChange(player);
        CloneCyril(player);
    }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        PhasingHandler::OnConditionChange(player);
        CloneCyril(player);
    }

    void CloneCyril(Player* player) const
    {
        if (Creature* cyrilObject = player->FindNearestCreatureWithOptions(25.0f, { .CreatureId = NPC_CYRIL_WHITE_CURSED, .IgnorePhases = true }))
            cyrilObject->SummonPersonalClone(cyrilObject->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 0s, 0, 0, player);
    }
};

void AddSC_drustvar_chapter_1_the_final_effigy()
{
    // Creature
    RegisterCreatureAI(npc_helena_gentle_witch_hunt);

    // Scene
    new scene_drustvar_cleanse_fallhaven();

    // EventScripts
    new event_listen_to_helenas_story();

    // Spells
    RegisterSpellScript(spell_drustvar_cancel_deathcurse);
}
