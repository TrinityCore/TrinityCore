/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "tomb_of_sargeras.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CALL = 1,
    SAY_DRAW_IN = 2,
    SAY_DEATH = 3,
};

enum Spells
{
    SPELL_DRAW_IN = 232061, // 
    SPELL_FRIGID_BLOWS = 233429, // 
    SPELL_DRENCHING_SLOUGH = 233526, // dummy
    SPELL_FROSTY_DISCHARGE = 232174, // at end link

    SPELL_UNCHECKED_RAGE = 231854, // 100%
    SPELL_UNCHECKED_RAGE_VICTIM = 247403, // 
    SPELL_CALL_ADDS = 232192, //

    SPELL_CANCEL_DRENCHED = 239926, // link
    SPELL_CHANGE_ENERGY = 241486, //
    SPELL_REGENERATE_ENERGY = 232379, //

    SPELL_ENQUBATION = 240347,
    SPELL_HARDENED_SHELL = 240315,

    SPELL_ENQUBATION_RED = 242027,
    SPELL_ENQUBATION_BLUE = 242030,
    SPELL_ENQUBATION_GREEN = 242031,

    SPELL_ENRAGE = 64238,  //

    SPELL_JAGGED_ABRASION = 231998,

    //achievement npc spells
    SPELL_SONIC_WAVE = 241436,
    SPELL_SPLASH = 241393,
    SPELL_ELDERS_RAGE = 241416,
};

enum eEvents
{
    EVENT_CHECK_ENERGY = 1,
    EVENT_CALL_ADDS,
    EVENT_DRAW_IN,
    EVENT_HATCHING,
    EVENT_HATCHING_CLEAN_UP,

    EVENT_ENRAGE,

    EVENT_ELDER1,
    EVENT_ELDER2,
    EVENT_ELDER3,
};

enum Misc
{
    DATA_COMPLETE,
};

enum Action
{
    ACTION_COMPLETE,
};

Position const addsPos[4]
{
    {5877.17f, -906.50f, 2920.25f, 6.20f},
    {5880.17f, -896.95f, 2920.35f, 5.73f},
    {5889.86f, -886.83f, 2920.35f, 5.42f},
    {5946.16f, -919.47f, 2919.52f, 2.62f}

};

Position const eggsPos[4]
{
    {5915.40f, -876.02f, 2919.83f, 0.0f},
    {5944.42f, -900.28f, 2919.46f, 0.0f},
    {5918.47f, -945.27f, 2919.86f, 0.0f},
    {5882.26f, -920.99f, 2920.99f, 0.0f}
};

uint32 const eggsCasts[3]
{
    SPELL_ENQUBATION_BLUE,
    SPELL_ENQUBATION_RED,
    SPELL_ENQUBATION_GREEN
};

// 116407
class boss_harjatan : public CreatureScript
{
public:
    boss_harjatan() : CreatureScript("boss_harjatan") {}

    struct boss_harjatanAI : BossAI
    {
        boss_harjatanAI(Creature* creature) : BossAI(creature, DATA_HARJATAN), achievecomplete(false)
        {
            me->SetReactState(REACT_DEFENSIVE);
            achievecomplete = false;
        }

        std::map<uint8, std::vector<ObjectGuid>> eggs{};
        bool achievecomplete;

        void Reset() override
        {
            if (me->IsAlive())
            {
                _Reset();
                achievecomplete = false;

                if (Creature* elder = instance->instance->GetCreature(instance->GetGuidData(NPC_ELDER)))
                    if (!elder->IsAlive())
                        elder->Respawn();
            }

            eggs.clear();

            instance->DoRemoveAurasDueToSpellOnPlayers(231770);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_JAGGED_ABRASION);

            std::list<AreaTrigger*> list;
          //  me->GetAreaTriggersWithEntryInRange(list, 13251, ObjectGuid::Empty, 80.0f);
            for (std::list<AreaTrigger*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->RemoveFromWorld();
            if (IsMythic())
            {
                for (uint8 j = 0; j < 4; ++j)
                {
                    const auto& pos = eggsPos[j];
                    for (uint8 i = 0; i < 5; ++i)
                        if (Creature* add = me->SummonCreature(NPC_EGGS, pos.GetPositionX() + frand(-4, 4), pos.GetPositionY() + frand(-4, 4), pos.GetPositionZ(), 0.0f))
                        {
                           // add->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
                            add->CastSpell(add, SPELL_HARDENED_SHELL);
                            eggs[j].push_back(add->GetGUID());
                        }
                }
            }
        }

        void DoAction(int32 const action)
        {
            if (action == ACTION_COMPLETE)
                achievecomplete = true;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_COMPLETE:
                return achievecomplete ? 1 : 0;
            }
            return 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            Talk(SAY_AGGRO);

            me->SetPower(POWER_ENERGY, 0);
            DoCast(SPELL_REGENERATE_ENERGY);
            events.RescheduleEvent(EVENT_CHECK_ENERGY, 500);

            events.RescheduleEvent(EVENT_ENRAGE, IsMythic() ? 360000 : 480000);
            events.RescheduleEvent(EVENT_DRAW_IN, 58000);
            events.RescheduleEvent(EVENT_CALL_ADDS, 17000);
            if (IsMythic())
                events.RescheduleEvent(EVENT_HATCHING, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            Reset();
        }

        void JustSummoned(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_EGGS:
               // creature->SetReactState(REACT_ATTACK_OFF);
                creature->SetControlled(true, UNIT_STATE_ROOT);
                break;
            case NPC_TADPOLE_3:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                {
                    //creature->SetTargetGUID(target->GetGUID());
                    creature->AI()->DoAction(true);
                }
                break;
            }
            }

            BossAI::JustSummoned(creature);
        }

      /*  void SpellFinishCast(SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_UNCHECKED_RAGE:
                DoCastVictim(SPELL_UNCHECKED_RAGE_VICTIM, true);
                for (const auto& vector : eggs)
                    for (const auto& guid : vector.second)
                        if (Creature* egg = instance->instance->GetCreature(guid))
                            if (me->isInFront(egg) && me->GetDistance(egg) <= 20.0f)
                                egg->RemoveAurasDueToSpell(SPELL_HARDENED_SHELL);
                break;
            case SPELL_CALL_ADDS:
                for (uint8 i = 0; i < 4; ++i)
                    me->SummonCreature(i < 2 ? 117596 : 116569, addsPos[i]);
                break;
            case SPELL_FROSTY_DISCHARGE:
                events.RescheduleEvent(EVENT_DRAW_IN, 59000);
                events.RescheduleEvent(EVENT_CALL_ADDS, 17000);
                if (IsMythicRaid())
                    events.RescheduleEvent(EVENT_HATCHING, 30000);
                break;
            }
        }
        */
    //    void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode /*mode*/, bool apply) override
      /*  {
            switch (spellId)
            {
            case SPELL_FRIGID_BLOWS:
                if (apply)
                    return;

                me->SetPower(me->getPowerType(), 0);
                DoCast(SPELL_FROSTY_DISCHARGE);
                break;
            case SPELL_DRAW_IN:
                if (apply)
                    return;
                if (!me->HasAura(SPELL_FRIGID_BLOWS))
                {
                    DoCast(SPELL_FROSTY_DISCHARGE);
                    me->SetPower(me->getPowerType(), 0);
                }
                break;
            }
        }
        */
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

           // if (CheckHomeDistToEvade(diff, 50.0f))
            //    return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ENERGY:
                    if (me->GetPower(POWER_ENERGY) >= 100)
                        DoCast(SPELL_UNCHECKED_RAGE);
                    events.RescheduleEvent(EVENT_CHECK_ENERGY, 500);
                    break;
                case EVENT_CALL_ADDS:
                    Talk(SAY_CALL);
                    DoCast(SPELL_CALL_ADDS);
                    events.RescheduleEvent(EVENT_CALL_ADDS, 36000);
                    break;
                case EVENT_DRAW_IN:
                    Talk(SAY_DRAW_IN);
                    DoCast(SPELL_DRAW_IN);
                    break;
                case EVENT_HATCHING:
                {
                    DoCast(SPELL_ENQUBATION);

                    std::vector<uint8> eggsIndexes{ 0, 1, 2, 3 };
                    std::list<uint8> eggsColors{ 0, 1, 2 };

                    Trinity::Containers::RandomResize(eggsIndexes, 2);
                    Trinity::Containers::RandomResize(eggsColors, 2);

                    for (auto i : eggsIndexes)
                    {
                        uint8 color = eggsColors.front();
                        eggsColors.pop_front();
                        if (eggsCasts[color] == SPELL_ENQUBATION_GREEN)
                        {
                            for (const auto& guid : eggs[i])
                                if (Creature* egg = instance->instance->GetCreature(guid))
                                {
                                    if (!egg->IsAlive())
                                        egg->Respawn(true);
                                    egg->AI()->EnterCombat(me->GetVictim());
                                    egg->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                                    egg->CastSpell(egg, SPELL_HARDENED_SHELL);
                                  //  egg->CastSpellDelay(egg, eggsCasts[color], false, 100);
                                }
                        }
                        else
                            if (Creature* egg = instance->instance->GetCreature(eggs[i][urand(0, eggs[i].size())]))
                            {
                                if (!egg->IsAlive())
                                    egg->Respawn(true);
                                egg->AI()->EnterCombat(me->GetVictim());
                                egg->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_ATTACKABLE_1));
                                egg->CastSpell(egg, SPELL_HARDENED_SHELL);
                               // egg->CastSpellDelay(egg, eggsCasts[color], false, 100);
                            }
                    }

                    events.RescheduleEvent(EVENT_HATCHING_CLEAN_UP, 28000);
                    break;
                }
                case EVENT_HATCHING_CLEAN_UP:
                {
                    for (const auto& vector : eggs)
                        for (const auto& guid : vector.second)
                            if (Creature* egg = instance->instance->GetCreature(guid))
                            {
                                if (!egg->IsAlive())
                                    egg->Respawn(true);
                                else
                                    egg->SetHealth(egg->GetMaxHealth());

                                for (const auto& spell : eggsCasts)
                                    egg->RemoveAurasDueToSpell(spell);
                                egg->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1));

                            }
                    break;
                }
                case EVENT_ENRAGE:
                    DoCast(SPELL_ENRAGE);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_harjatanAI(creature);
    }
};


// 121184
class npc_mistress_sasszine : public CreatureScript
{
public:
    npc_mistress_sasszine() : CreatureScript("npc_mistress_sasszine") {}

    struct npc_mistress_sasszineAI : ScriptedAI
    {
        npc_mistress_sasszineAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            SetCanSeeEvenInPassiveMode(true);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }

        bool _introDone = false;
        uint32 introAdds = 0;

        void DoAction(const int32) override
        {
            if (!introAdds)
                introAdds = 1;

            switch (--introAdds)
            {
            case 1:
                Talk(2);
                break;
            case 0:
                me->CastSpell(me, 241744);

              //  me->CastSpellDelay(me, 241680, false, 11000);
                me->DespawnOrUnsummon(13500);
                break;
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who->IsPlayer())
                return;

            if (me->GetDistance(who) < 100.0f && !_introDone)
            {
                _introDone = true;
                InstanceScript* instance = me->GetInstanceScript();
                if (!instance)
                    return;

                if (instance->GetBossState(DATA_HARJATAN) != NOT_STARTED)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                Talk(0);

                for (auto id : { NPC_EVENT_1, NPC_EVENT_2 })
                    if (Creature* add = instance->instance->GetCreature(instance->GetGuidData(id)))
                        if (add->IsAlive())
                            ++introAdds;

                if (introAdds)
                    return;

                //me->CastSpellDelay(me, 241744, false, 11000);
               // me->CastSpellDelay(me, 241680, false, 21000);
                me->DespawnOrUnsummon(23500);
            }
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mistress_sasszineAI(creature);
    }
};

// 121155
struct npc_tos_tadpole : ScriptedAI
{
    npc_tos_tadpole(Creature* creature) : ScriptedAI(creature) {}

    uint32 timer;
    bool canDoEvent = false;
    /*
    void DoAction(const int32) override
    {
        me->SetReactState(REACT_PASSIVE);

        //me->AddDelayedEvent(1500, [this]()-> void
        {
         //   if (Unit* target = me->GetTargetUnit())
            {
               // me->GetMotionMaster()->MoveFollow(target, 0, 0);
              //  me->CastSpell(target, 241600);
            }

            timer = 1000;
            canDoEvent = true;
        //});
    }
        */
    void JustDied(Unit*) override
    {
        DoCast(me, 241587, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (canDoEvent)
        {
            if (timer <= diff)
            {
             //   if (Unit* target = me->GetTargetUnit())
                {
                   // if (me->GetDistance2d(target) <= 2.2f)
                    {
                        DoCast(241603);
                        me->DespawnOrUnsummon(100);
                    }
                 //   else
                       // me->GetMotionMaster()->MoveFollow(target, 0, 0);
                }
              //  else
                    me->DespawnOrUnsummon();
                timer = 1000;
            }
            else
                timer -= diff;
        }
    }
};

// 121071 achievement npc
class npc_elder_murk_eye : public CreatureScript
{
public:
    npc_elder_murk_eye() : CreatureScript("npc_elder_murk_eye") {}

    struct npc_elder_murk_eyeAI : ScriptedAI
    {
        npc_elder_murk_eyeAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            instance = me->GetInstanceScript();
        }

        EventMap events;

        InstanceScript* instance;

        uint32 CheckTimer;
        uint32 EvadeTimer;
        Position const jumppoint = { 5892.11f, -898.21f, 2919.83f, 5.7f };


        void Initialize()
        {
            CheckTimer = 2000;
            EvadeTimer = 5000;
        }

        void Reset() override
        {
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            me->SetVisible(false);
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
            me->RemoveAura(241416);
            me->RemoveAura(241393);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.RescheduleEvent(EVENT_ELDER1, 6000); //wave
            events.RescheduleEvent(EVENT_ELDER2, 8000); //splash
            events.RescheduleEvent(EVENT_ELDER3, 25000); //rage
        }

        void UpdateAI(uint32 diff) override
        {
            if ((!me->IsInCombat()) && (instance->GetBossState(DATA_HARJATAN) == FAIL) || (!me->IsInCombat()) && (instance->GetBossState(DATA_HARJATAN) == NOT_STARTED))
            {
                if (EvadeTimer <= diff)
                {
                    EnterEvadeMode();

                    EvadeTimer = 5000;
                }

                else EvadeTimer -= diff;
            }

            if ((!me->IsInCombat()) && (instance->GetBossState(DATA_HARJATAN) == IN_PROGRESS))
            {
                if (CheckTimer <= diff)
                {
                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        if (Player* player = itr->GetSource())
                            if (player->HasAura(232454))
                            {
                                me->SetVisible(true);
                                me->GetMotionMaster()->MoveJump(jumppoint, 10.0f, 10.0f);
                                me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                                me->SetReactState(REACT_AGGRESSIVE);
                                break;
                            }
                    CheckTimer = 2000;

                }
                else CheckTimer -= diff;
            }

            if (!UpdateVictim())
                return;

            events.Update(diff);


            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ELDER1:
                    DoCast(SPELL_SONIC_WAVE);
                    events.RescheduleEvent(EVENT_ELDER1, 6000);
                    break;
                case EVENT_ELDER2:
                    DoCast(SPELL_SPLASH);
                    events.RescheduleEvent(EVENT_ELDER2, 20000);
                    break;
                case EVENT_ELDER3:
                    DoCast(SPELL_ELDERS_RAGE);
                    events.RescheduleEvent(EVENT_ELDER3, 45000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* Harjatan = instance->instance->GetCreature(instance->GetGuidData(NPC_HARJATAN)))
            {
                Harjatan->AI()->DoAction(ACTION_COMPLETE);
            }
            instance->DoRemoveAurasDueToSpellOnPlayers(231770);

        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_elder_murk_eyeAI(creature);
    }
};


// 231854
class spell_tos_unchecked_rage : public SpellScriptLoader
{
public:
    spell_tos_unchecked_rage() : SpellScriptLoader("spell_tos_unchecked_rage") { }

    class spell_tos_unchecked_rage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tos_unchecked_rage_SpellScript);

        void CorrectTargets(std::list<WorldObject*>& targets)
        {
            if (!GetCaster())
                return;

            auto caster = GetCaster();

            if (targets.size() < 5)
                caster->CastSpell(caster, 247782, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tos_unchecked_rage_SpellScript::CorrectTargets, SpellEffIndex::EFFECT_0, Targets::TARGET_UNIT_CONE_ENEMY_104);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_tos_unchecked_rage_SpellScript();
    };
};

// 234016
class spell_tos_fixate : public AuraScript
{
    PrepareAuraScript(spell_tos_fixate);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!target || !caster)
            return;

        caster->AddAura(234128, caster);

        caster->AddThreat(target, std::numeric_limits<float>::max());
        caster->TauntApply(target);
    }

    void OnRemove(AuraEffect const* /*auraEffect*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster() && GetTarget())
            GetCaster()->TauntFadeOut(GetTarget());
    }

    void Register()
    {
        //OnEffectApply += AuraEffectApplyFn(spell_tos_fixate::OnApply, EFFECT_0, SPELL_AURA_FIXATE, AURA_EFFECT_HANDLE_REAL);
      //  AfterEffectRemove += AuraEffectRemoveFn(spell_tos_fixate::OnRemove, SpellEffIndex::EFFECT_0, AuraType::SPELL_AURA_FIXATE, AuraEffectHandleModes::AURA_EFFECT_HANDLE_REAL);

    }
};


// 232061
class spell_tos_draw_in : public AuraScript
{
    PrepareAuraScript(spell_tos_draw_in);

    uint8 counter = 0;

    void OnTick(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<AreaTrigger*> list;
        //caster->GetAreaTriggersWithEntryInRange(list, 13251, ObjectGuid::Empty, 80.0f);
        uint8 realCount = 0;
        for (std::list<AreaTrigger*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
        {
            if ((*itr)->GetDuration() <= 9000)
                continue;

            AreaTrigger* areaTrigger = new AreaTrigger;
         //   if (!areaTrigger->CreateAreaTrigger(sObjectMgr->GetGenerator<HighGuid::AreaTrigger>()->Generate(), 9230, caster, sSpellMgr->GetSpellInfo(231754), (*itr)->GetPosition(), caster->GetPosition()))
                delete areaTrigger;
          //  else
                areaTrigger->SetDuration(9000);

            (*itr)->RemoveFromWorld();
            ++realCount;
        }

       // for (uint8 i = 0; i < realCount; ++i)
         //   caster->CastSpellDelay(caster, SPELL_FRIGID_BLOWS, true, (1 + i) * GetDuration() / realCount);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_tos_draw_in::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

class achievement_grand_fin_ale : public AchievementCriteriaScript
{
public:
    achievement_grand_fin_ale() : AchievementCriteriaScript("achievement_grand_fin_ale") { }

    bool OnCheck(Player* /*player*/, Unit* target) override
    {
        if (!target)
            return false;

        if (Creature* boss = target->ToCreature())
            if (boss->AI()->GetData(DATA_COMPLETE))
                return true;

        return false;
    }
};

void AddSC_boss_harjatan()
{
    new boss_harjatan();
    new npc_mistress_sasszine();
    new npc_elder_murk_eye();
    new achievement_grand_fin_ale();
    RegisterCreatureAI(npc_tos_tadpole);
    new spell_tos_unchecked_rage();
    RegisterAuraScript(spell_tos_fixate);
    RegisterAuraScript(spell_tos_draw_in);
}
