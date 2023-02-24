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
#include "ScriptedGossip.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
};

// 127233
struct npc_atbt_flamewear : public ScriptedAI
{
    npc_atbt_flamewear(Creature* cre) : ScriptedAI(cre) {}

    EventMap events;
    std::vector<ObjectGuid> targs{};

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        events.RescheduleEvent(EVENT_1, 1500);
        events.RescheduleEvent(EVENT_2, 10000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(252614);
                events.RescheduleEvent(EVENT_1, 3500);
                break;
            case EVENT_2:
                targs.clear();
                DoCast(252621);
                events.RescheduleEvent(EVENT_2, urand(1000, 14000));
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

};

// 125819
struct npc_atbt_battleship_controller : public ScriptedAI
{
    npc_atbt_battleship_controller(Creature* cre) : ScriptedAI(cre)
    {
        SetCanSeeEvenInPassiveMode(true);
    }

    EventMap events;
    bool start = false;

    void Reset() override
    {
        events.Reset();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (start)
            return;

        if (!who->IsPlayer())
            return;

        if (me->GetDistance(who) > 98.0f)
            return;

        start = true;

        events.RescheduleEvent(EVENT_1, 3000);

        if (Creature* cre = me->FindNearestCreature(125480, 90.0, true)) // really need it =C
            cre->AI()->Talk(0);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!start)
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                me->SummonCreature(NPC_BATTLE_SHIP, -3268.71f, 10120.37f, -67.19f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 9000);
                events.RescheduleEvent(EVENT_1, urand(3000, 5000));
                break;
            }
        }
    }

};

// 125771
struct npc_atbt_battleship : public ScriptedAI
{
    npc_atbt_battleship(Creature* cre) : ScriptedAI(cre) {}

    void IsSummonedBy(Unit* owner) override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCanFly(true);
        me->GetMotionMaster()->MovePoint(0, -3312.39f, 9992.18f, -87.09f);

        AddDelayedEvent(urand(2000, 3000), [this]() -> void
        {
            uint8 i = 0;
            for (float y = 10099.79f; y >= 9980.05f; y -= frand(2, 7))
            {
                AddDelayedEvent(100 * ++i, [this, y]() -> void
                {
                    float x = frand(-3305.59f, -3286.11f);
                    me->CastSpell(x, y, -115.73f, 249933, true);
                });
            }
        });
    }
};

//125720, 128303 128304
class npt_atbt_tele_gates : public CreatureScript
{
public:
    npt_atbt_tele_gates() : CreatureScript("npt_atbt_tele_gates") {}

    bool OnGossipHello(Player* player, Creature* me)  override
    {
        InstanceScript* instance = me->GetInstanceScript();
        if (!instance)
            return false;

        bool isDone = true;
        for (uint8 i = DATA_WORLDBREAKER; i <= DATA_EONAR; ++i)
            if (instance->GetBossState(i) != DONE)
                isDone = false;

        if (isDone && me->GetEntry() != 128303)
            AddGossipItemFor(player, 0, "Imonar", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

        if (me->GetEntry() != 125720)
            AddGossipItemFor(player, 0, "Start", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        isDone = true;
        for (uint8 i = DATA_IMONAR; i <= DATA_KINGAROTH; ++i)
            if (instance->GetBossState(i) != DONE)
                isDone = false;

        if (me->GetEntry() != 128304)
            AddGossipItemFor(player, 0, "Varithmas", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* me, uint32 sender, uint32 action)  override
    {
        if (me->GetEntry() == 125720)
            player->CastSpell(player, 254498);
        else if (me->GetEntry() == 128303)
            player->CastSpell(player, 254499);

        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            player->NearTeleportTo(-10574.47f, 8772.07f, 1871.46f, 4.68f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 2:
            player->NearTeleportTo(-3437.5f, 10156.9f, -150.022f, 0.0f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 3:
            player->NearTeleportTo(-12633.91f, -3369.47f, 2513.82f, 0.0f);
            break;
        }
        return true;
    }
};

// 128169
class npc_atbt_muradin : public CreatureScript
{
public:
    npc_atbt_muradin() : CreatureScript("npc_atbt_muradin") {}

    bool OnGossipSelect(Player* player, Creature* me, uint32 sender, uint32 action)  override
    {
        player->CastSpell(player, 254311);
        player->NearTeleportTo(2825.47f, -4567.23f, 291.94f, 0.0f);
        return true;
    }
};

// 252621
class spell_atbt_bound_by_fel : public AuraScript
{
    PrepareAuraScript(spell_atbt_bound_by_fel);

    ObjectGuid second{};

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (target->GetAuraCount(252621) >= 20)
        {
            target->RemoveAurasDueToSpell(252621);
            return;
        }

        if (second.IsEmpty())
            return;

        Unit* second_targ = ObjectAccessor::GetPlayer(*target, second);
        if (!second_targ)
            return;

        target->CastSpell(second_targ, 252622);
        if (target->GetDistance(second_targ) <= 10)
            target->CastSpell(second_targ, 252623);
        else if (Unit* caster = GetCaster())
            if (caster->IsAlive())
                caster->CastSpell(target, 252621);
    }

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        if (!GetCaster() || !GetTarget())
            return;

        Creature* cre = GetCaster()->ToCreature();
        if (!cre)
            return;

        Unit* target = GetTarget();
        cre->AI()->SetGUID(target->GetGUID());
    }


    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_atbt_bound_by_fel::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectApply += AuraEffectApplyFn(spell_atbt_bound_by_fel::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 253600
class spell_atbt_soulburn : public AuraScript
{
    PrepareAuraScript(spell_atbt_soulburn);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        target->CastSpell(target, 253601);

        std::list<Player*> players;
        target->GetPlayerListInGrid(players, 8.0f);
        players.remove_if([](Player* player)
        {
            if (!player)
                return true;

            return !player->HasAura(253600);
        });
        Trinity::Containers::RandomResize(players, 5);
        for (Player* player : players)
            player->CastSpell(player, 253600);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectApplyFn(spell_atbt_soulburn::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 252740
class spell_atbt_anihilation : public SpellScript
{
    PrepareSpellScript(spell_atbt_anihilation);

    bool check = false;

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (uint8 i = 0; i < 3; ++i)
        {
            Position pos(caster->GetPosition());
            //caster->GetFirstCollisionPosition(pos, 15.0f * frand(0.3f, 1.0f), static_cast<float>(rand_norm()) * static_cast<float>(2.0f * M_PI));
            caster->CastSpell(pos, 252742, false);
            caster->CastSpell(pos, 252741, false);
        }
    }

    void Register()
void AddSC_antorus()
    {
        AfterCast += SpellCastFn(spell_atbt_anihilation::HandleAfterCast);
    }
};

class spell_vantus_rune_antorus : public SpellScriptLoader
{
public:
    spell_vantus_rune_antorus() : SpellScriptLoader("spell_vantus_rune_antorus") {}

    class spell_vantus_rune_antorus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_vantus_rune_antorus_AuraScript);

        uint16 checkOnProc;
        uint16 checkOnRemove;

        bool Load()
        {
            checkOnProc = 1000;
            checkOnRemove = 1000;
            return true;
        }

        void OnUpdate(AuraEffect const* aurEff)
        {
            Unit* player = GetCaster();
            if (!player)
                return;

            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return;

            switch (aurEff->GetSpellInfo()->Id)
            {
            case 250153:
                if (instance->GetBossState(DATA_WORLDBREAKER) == IN_PROGRESS && !player->HasAura(250152))
                    player->CastSpell(player, 250152, false);
                break;
            case 250156:
                if (instance->GetBossState(DATA_FELHOUNDS) == IN_PROGRESS && !player->HasAura(250155))
                    player->CastSpell(player, 250155, false);
                break;
            case 250167:
                if (instance->GetBossState(DATA_ANTORAN) == IN_PROGRESS && !player->HasAura(250166))
                    player->CastSpell(player, 250166, false);
                break;
            case 250160:
                if (instance->GetBossState(DATA_HASABEL) == IN_PROGRESS && !player->HasAura(250159))
                    player->CastSpell(player, 250159, false);
                break;
            case 250150:
                if (instance->GetBossState(DATA_EONAR) == IN_PROGRESS && !player->HasAura(250149))
                    player->CastSpell(player, 250149, false);
                break;
            case 250158:
                if (instance->GetBossState(DATA_IMONAR) == IN_PROGRESS && !player->HasAura(250157))
                    player->CastSpell(player, 250157, false);
                break;
            case 250148:
                if (instance->GetBossState(DATA_KINGAROTH) == IN_PROGRESS && !player->HasAura(250147))
                    player->CastSpell(player, 250147, false);
                break;
            case 250165:
                if (instance->GetBossState(DATA_VARIMATHRAS) == IN_PROGRESS && !player->HasAura(250164))
                    player->CastSpell(player, 250164, false);
                break;
            case 250163:
                if (instance->GetBossState(DATA_COVEN) == IN_PROGRESS && !player->HasAura(250162))
                    player->CastSpell(player, 250162, false);
                break;
            case 250144:
                if (instance->GetBossState(DATA_AGGRAMAR) == IN_PROGRESS && !player->HasAura(250143))
                    player->CastSpell(player, 250143, false);
                break;
            case 250146:
                if (instance->GetBossState(DATA_ARGUS) == IN_PROGRESS && !player->HasAura(250145))
                    player->CastSpell(player, 250145, false);
                break;
            }


            if (player->HasAura(250152))
            {
                if (instance->GetBossState(DATA_WORLDBREAKER) == DONE || instance->GetBossState(DATA_WORLDBREAKER) == NOT_STARTED)
                {
                    player->RemoveAura(250152);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250155))
            {
                if (instance->GetBossState(DATA_FELHOUNDS) == DONE || instance->GetBossState(DATA_FELHOUNDS) == NOT_STARTED)
                {
                    player->RemoveAura(250155);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250166))
            {
                if (instance->GetBossState(DATA_ANTORAN) == DONE || instance->GetBossState(DATA_ANTORAN) == NOT_STARTED)
                {
                    player->RemoveAura(250166);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250159))
            {
                if (instance->GetBossState(DATA_HASABEL) == DONE || instance->GetBossState(DATA_HASABEL) == NOT_STARTED)
                {
                    player->RemoveAura(250159);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250149))
            {
                if (instance->GetBossState(DATA_EONAR) == DONE || instance->GetBossState(DATA_EONAR) == NOT_STARTED)
                {
                    player->RemoveAura(250149);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250157))
            {
                if (instance->GetBossState(DATA_IMONAR) == DONE || instance->GetBossState(DATA_IMONAR) == NOT_STARTED)
                {
                    player->RemoveAura(250157);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250147))
            {
                if (instance->GetBossState(DATA_KINGAROTH) == DONE || instance->GetBossState(DATA_KINGAROTH) == NOT_STARTED)
                {
                    player->RemoveAura(250147);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250164))
            {
                if (instance->GetBossState(DATA_VARIMATHRAS) == DONE || instance->GetBossState(DATA_VARIMATHRAS) == NOT_STARTED)
                {
                    player->RemoveAura(250164);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250162))
            {
                if (instance->GetBossState(DATA_COVEN) == DONE || instance->GetBossState(DATA_COVEN) == NOT_STARTED)
                {
                    player->RemoveAura(250162);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250143))
            {
                if (instance->GetBossState(DATA_AGGRAMAR) == DONE || instance->GetBossState(DATA_AGGRAMAR) == NOT_STARTED)
                {
                    player->RemoveAura(250143);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

            if (player->HasAura(250145))
            {
                if (instance->GetBossState(DATA_ARGUS) == DONE || instance->GetBossState(DATA_ARGUS) == NOT_STARTED)
                {
                    player->RemoveAura(250145);
                    checkOnProc = 1000;
                    checkOnRemove = 1000;
                }
            }

        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_vantus_rune_antorus_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_vantus_rune_antorus_AuraScript();
    }

    class spell_vantus_rune_antorus_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_vantus_rune_antorus_SpellScript);

        SpellCastResult CheckCast()
        {
            if (auto player = GetCaster()->ToPlayer())
                if (!player->GetQuestRewardStatus(39695))
                    return SPELL_CAST_OK;

            SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_VANTUS_RUNE);
            return SPELL_FAILED_CUSTOM_ERROR;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_vantus_rune_antorus_SpellScript::CheckCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_vantus_rune_antorus_SpellScript();
    }
};

class spell_vantus_rune_antorus_choose : public SpellScript
{
    PrepareSpellScript(spell_vantus_rune_antorus_choose);

    SpellCastResult CheckCast()
    {
        if (auto player = GetCaster()->ToPlayer())
        {
            if (player->GetMapId() != 1712)
                return SPELL_FAILED_NOT_HERE;

            if (player->GetQuestRewardStatus(39695))
            {
                SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_YOU_ALREADY_USED_VANTUS_RUNE);
                return SPELL_FAILED_CUSTOM_ERROR;
            }
        }

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Unit* boss = GetHitUnit();
        if (!boss)
            return;

        switch (boss->GetEntry())
        {
        case 122450:
            if (!caster->HasAura(250153))
                caster->CastSpell(caster, 250153, true);
            break;
        case 122477:
        case 122135:
            if (!caster->HasAura(250156))
                caster->CastSpell(caster, 250156, true);
            break;
        case 122367:
            if (!caster->HasAura(250167))
                caster->CastSpell(caster, 250167, true);
            break;
        case 122104:
            if (!caster->HasAura(250160))
                caster->CastSpell(caster, 250160, true);
            break;
        case 122500:
            if (!caster->HasAura(250150))
                caster->CastSpell(caster, 250150, true);
            break;
        case 124158:
            if (!caster->HasAura(250158))
                caster->CastSpell(caster, 250158, true);
            break;
        case 122578:
            if (!caster->HasAura(250148))
                caster->CastSpell(caster, 250148, true);
            break;
        case 122366:
            if (!caster->HasAura(250165))
                caster->CastSpell(caster, 250165, true);
            break;
        case 122468:
        case 122467:
        case 122469:
            if (!caster->HasAura(250163))
                caster->CastSpell(caster, 250163, true);
            break;
        case 124691:
            if (!caster->HasAura(250144))
                caster->CastSpell(caster, 250144, true);
            break;
        case 124828:
            if (!caster->HasAura(250146))
                caster->CastSpell(caster, 250146, true);
            break;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_vantus_rune_antorus_choose::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_vantus_rune_antorus_choose::CheckCast);
    }
};

void AddSC_antorus()
{
    RegisterCreatureAI(npc_atbt_flamewear);
    RegisterCreatureAI(npc_atbt_battleship_controller);
    RegisterCreatureAI(npc_atbt_battleship);
    new npt_atbt_tele_gates;
    new npc_atbt_muradin();
    RegisterAuraScript(spell_atbt_bound_by_fel);
    RegisterAuraScript(spell_atbt_soulburn);
    RegisterSpellScript(spell_atbt_anihilation);
    RegisterSpellScript(spell_vantus_rune_antorus_choose);
    new spell_vantus_rune_antorus;
}
