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
#include "GameObject.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "halls_of_valor.h"

enum godKingKovaldSpells
{
    SPELL_AEGIS_OF_AGGRAMAR         = 193765,
    SPELL_AEGIS_OF_AGGRAMAR_ABS     = 193743,
    SPELL_AEGIS_SHIELD_VISUAL       = 194214,
    SPELL_AEGIS_SUMMON              = 193781,
    SPELL_AEGIS_SPAWN               = 193769,
    SPELL_CLAIM_THE_AEGIS           = 194112,
    SPELL_AEGIS_RANDOM_POINT        = 193991,
    SPELL_AEGIS_SHIELD_PLAYER       = 193783,
    SPELL_RAGNAROK_CHANNEL          = 193826,
    SPELL_RAGNAROK_DAMAGE           = 193827,
    SPELL_FELBLAZE_RUSH             = 193659,
    SPELL_INFERNAL_FLAMES           = 193702,
    SPELL_INFERNAL_FLAMES_AT        = 193704,
    SPELL_INFERNAL_FLAMES_DAMAGE    = 193701,
    SPELL_FLAME_OF_WOE              = 193706, // HEROIC
    SPELL_CONSUMING_FLAME           = 221093,
    SPELL_SAVAGE_BLADE              = 193668,
    SPELL_RAGGED_SLASH              = 193686
};

enum godKingKovaldEvents
{
    EVENT_AEGIS_OF_AGGRAMAR = 1,
    EVENT_RAGNAROK,
    EVENT_FELBLAZE_RUSH,
    EVENT_FLAME_OF_WOE, // HEROIC
    EVENT_CHECK_FOR_AEGIS,
    EVENT_SAVAGE_BLADE,
    EVENT_CLAIM_THE_AEGIS,
    EVENT_SUMMON_AEGIS,
    EVENT_START_TALK,
    EVENT_START_COMBAT,
};

enum godKingKovaldSays
{
    SAY_EVENT_1 = 7,
    SAY_EVENT_2 = 8,
    SAY_ENTER_COMBAT = 0,
    SAY_ETERNAL = 2,
    SAY_POWER = 4,
    SAY_RAGNAROK = 3,
    SAY_DIE = 6,
};

struct boss_god_king_kovald : public BossAI
{
    boss_god_king_kovald(Creature* creature) : BossAI(creature, DATA_GODKING_SKOVALD)
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetVisible(false);
    }

    Position aegisSpawn;

    void Reset() override
    {
        _Reset();

        me->SetReactState(REACT_DEFENSIVE);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();

        if (Unit* target = me->GetVictim())
            me->AddAura(SPELL_AEGIS_SHIELD_PLAYER, target);

        me->SetWalk(true);

        events.ScheduleEvent(EVENT_CHECK_FOR_AEGIS, 10000);
        events.ScheduleEvent(EVENT_FELBLAZE_RUSH, 10000);
        events.ScheduleEvent(EVENT_RAGNAROK, 14000);
        events.ScheduleEvent(EVENT_SAVAGE_BLADE, 22000);
    }

    bool PlayerHasAegisAura()
    {
        Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player *player = i->GetSource())
                if (player->IsAlive() && player->GetDistance(me) <= 150.0f)
                    if (player->HasAura(202711))
                        return true;

        return false;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_EVENT_START)
        {
            me->SetReactState(REACT_DEFENSIVE);
            instance->SetBossState(DATA_GODKING_SKOVALD, NOT_STARTED);
            me->SetVisible(true);
            Talk(SAY_EVENT_1);
            me->SetWalk(false);
            me->GetMotionMaster()->MovePoint(0, 2402.76f, 528.64f, 748.99f, true);
            events.ScheduleEvent(EVENT_START_TALK, 25 * IN_MILLISECONDS);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {

                case EVENT_AEGIS_OF_AGGRAMAR:
                    me->CastSpell(me, SPELL_AEGIS_OF_AGGRAMAR, true);
                    me->CastSpell(me, SPELL_AEGIS_OF_AGGRAMAR_ABS, true);
                    me->SummonGameObject(251991, me->GetPosition(), QuaternionData(), 0);

                    events.ScheduleEvent(EVENT_SUMMON_AEGIS, 9000);
                    break;

                case EVENT_SUMMON_AEGIS:
                    me->CastSpell(me, SPELL_AEGIS_SUMMON, true);

                    if (GameObject* aegis = me->FindNearestGameObject(251991, 500.0f))
                        aegis->SendGameObjectDespawn();

                    break;

                case EVENT_RAGNAROK:
                    if (roll_chance_i(50))
                        Talk(SAY_ETERNAL);
                    else
                        Talk(SAY_POWER);

                    Talk(SAY_RAGNAROK);
                    me->AddAura(SPELL_RAGNAROK_CHANNEL, me);
                    break;

                case EVENT_FELBLAZE_RUSH:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true, 0))
                        me->CastSpell(target, SPELL_FELBLAZE_RUSH, true);
                    break;

                case EVENT_CHECK_FOR_AEGIS:
                    if (!PlayerHasAegisAura())
                        events.ScheduleEvent(EVENT_CLAIM_THE_AEGIS, 1000);
                    else
                        events.ScheduleEvent(EVENT_CHECK_FOR_AEGIS, 1000);
                    break;

                case EVENT_CLAIM_THE_AEGIS:
                    me->CastSpell(me, SPELL_CLAIM_THE_AEGIS, true);
                    me->CastSpell(me, SPELL_AEGIS_SHIELD_VISUAL, true);

                    events.ScheduleEvent(EVENT_AEGIS_OF_AGGRAMAR, 1000);
                    break;

                case EVENT_SAVAGE_BLADE:
                    if (Unit* target = me->GetVictim())
                    {
                        me->CastSpell(target, SPELL_SAVAGE_BLADE, true);
                        me->CastSpell(target, SPELL_RAGGED_SLASH, true);
                    }

                    events.ScheduleEvent(EVENT_SAVAGE_BLADE, 12000);
                    break;

                case EVENT_START_TALK:
                    Talk(SAY_EVENT_2);
                    me->SetHomePosition(me->GetPosition());
                    events.ScheduleEvent(EVENT_START_COMBAT, 5 * IN_MILLISECONDS);
                    break;

                case EVENT_START_COMBAT:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 98364 - Aegis of Aggramar
struct npc_aegis_of_aggramar : public ScriptedAI
{
    npc_aegis_of_aggramar(Creature* creature) : ScriptedAI(creature) { }

    void sGossipHello(Player* player) override
    {
        player->CastSpell(player, SPELL_AEGIS_SHIELD_PLAYER, true);
        if (player->HasAura(193720))
            player->RemoveAurasDueToSpell(193720);

        me->DespawnOrUnsummon(0);
    }

    void Reset() override
    {
        me->CastSpell(me, SPELL_AEGIS_SPAWN, true);
        me->CastSpell(me, SPELL_AEGIS_RANDOM_POINT, true);
    }
};

// 193828 - Ragnarok
class spell_kovald_ragnarok : public SpellScript
{
    PrepareSpellScript(spell_kovald_ragnarok);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            if (WorldLocation* dest = GetHitDest())
                caster->CastSpell(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), SPELL_RAGNAROK_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kovald_ragnarok::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 9758 - Aegis of Aggramar AT
struct areatrigger_aegis_of_aggramar : AreaTriggerAI
{
    areatrigger_aegis_of_aggramar(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        at->SetDuration(12000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->HasAura(SPELL_AEGIS_OF_AGGRAMAR_ABS))
            target->CastSpell(target, SPELL_AEGIS_OF_AGGRAMAR_ABS, true);
    }

    void OnUnitExit(Unit* target) override
    {
        target->RemoveAurasDueToSpell(SPELL_AEGIS_OF_AGGRAMAR_ABS);
    }
};

// 194222 - Infernal flames
class spell_kovald_infernal_flames : public SpellScript
{
    PrepareSpellScript(spell_kovald_infernal_flames);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            Position dest;
            caster->GetRandomPoint(dest, 100.0f);
            caster->CastSpell(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), SPELL_INFERNAL_FLAMES_AT, true);

            if (caster->GetMap()->IsHeroic())
            {
                caster->CastSpell(caster, 207509, true);
                caster->CastSpell(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), SPELL_FLAME_OF_WOE, true);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kovald_infernal_flames::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 9758 - Aegis of Aggramar AT
struct areatrigger_infernal_flames : AreaTriggerAI
{
    areatrigger_infernal_flames(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->HasAura(SPELL_INFERNAL_FLAMES))
            target->CastSpell(target, SPELL_INFERNAL_FLAMES_DAMAGE, true);

        if (Aura* aura = target->GetAura(SPELL_INFERNAL_FLAMES))
            aura->SetDuration(12000);
    }

    void OnUnitExit(Unit* target) override
    {
        target->RemoveAurasDueToSpell(SPELL_INFERNAL_FLAMES_DAMAGE);
    }
};

// 104822 - Flame of Woe
struct npc_flame_of_woe : public ScriptedAI
{
    npc_flame_of_woe(Creature* creature) : ScriptedAI(creature) { }

    ObjectGuid targetGuid;

    void Reset() override
    {
        me->SetLevel(110);
        me->CastSpell(me, 221093, true);

        events.Reset();

        if (Unit* target = me->SelectNearestPlayer(300.0f))
        {
            targetGuid = target->GetGUID();
            me->Attack(target, true);
        }

        events.ScheduleEvent(EVENT_FLAME_OF_WOE, 1000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->GetVictim() && me->GetVictim()->GetGUID() != targetGuid && targetGuid != ObjectGuid::Empty)
            me->SetTarget(targetGuid);
        else if (Unit* target = me->SelectNearestPlayer(300.0f))
        {
            targetGuid = target->GetGUID();
            me->Attack(target, true);
        }

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {

            case EVENT_FLAME_OF_WOE:
                me->CastSpell(me, 193661, true);

                events.ScheduleEvent(EVENT_SUMMON_AEGIS, 1000);
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 5029 - Flame of WoE AT
struct areatrigger_flame_of_woe : AreaTriggerAI
{
    areatrigger_flame_of_woe(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->HasAura(SPELL_INFERNAL_FLAMES))
            target->CastSpell(target, SPELL_INFERNAL_FLAMES_DAMAGE, true);
    }
};

void AddSC_boss_godking_skovald()
{
    RegisterCreatureAI(boss_god_king_kovald);
    RegisterCreatureAI(npc_aegis_of_aggramar);
    RegisterSpellScript(spell_kovald_ragnarok);
    RegisterAreaTriggerAI(areatrigger_aegis_of_aggramar);
    RegisterSpellScript(spell_kovald_infernal_flames);
    RegisterAreaTriggerAI(areatrigger_infernal_flames);
    RegisterAreaTriggerAI(areatrigger_flame_of_woe);
    RegisterCreatureAI(npc_flame_of_woe);
}
