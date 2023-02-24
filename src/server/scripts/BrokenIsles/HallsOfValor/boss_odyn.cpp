///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "halls_of_valor.h"
//
//enum Says
//{
//    SAY_FIRST = 0,
//    SAY_INTRO_1 = 2,
//    SAY_INTRO_2 = 3,
//    SAY_INTRO_3 = 4,
//    SAY_RADIANT = 5,
//    SAY_SPEARS = 6,
//    SAY_RUNIC = 7,
//    SAY_RUNIC_1 = 8,
//    SAY_DEATH = 9,
//};
//
//enum Spells
//{
//    SPELL_HONOR_BOUND = 198187, //? 01:44
//    SPELL_SPEAR_OF_LIGHT = 198072,
//    SPELL_RADIANT_TEMPEST = 201006,
//    SPELL_SHATTER_SPEARS = 198077,
//    SPELL_GLOWING_FRAGMENT = 198078,
//    SPELL_UNWORTHY = 198190,
//    SPELL_RUNIC_BRAND = 197961,
//
//    SPELL_RUNIC_BRAND_PURE = 197963,
//    SPELL_RUNIC_BRAND_RED = 197964,
//    SPELL_RUNIC_BRAND_YELLOW = 197965,
//    SPELL_RUNIC_BRAND_BLUE = 197966,
//    SPELL_RUNIC_BRAND_GREEN = 197967,
//
//    SPELL_RUNIC_BRAND_PURE_AT = 197968,
//    SPELL_RUNIC_BRAND_RED_AT = 197971,
//    SPELL_RUNIC_BRAND_YELLOW_AT = 197972,
//    SPELL_RUNIC_BRAND_BLUE_AT = 197975,
//    SPELL_RUNIC_BRAND_GREEN_AT = 197977,
//
//    //Heroic
//    SPELL_SUMMON_STORMFORGED = 201209,
//    SPELL_SURGE = 198750,
//    SPELL_CONDUIT = 199787,
//};
//
//enum eEvents
//{
//    EVENT_SKOVALD_DONE_1 = 1,
//    EVENT_SKOVALD_DONE_2 = 2,
//    EVENT_SPEAR_OF_LIGHT = 3,
//    EVENT_RADIANT_TEMPEST = 4,
//    EVENT_SHATTER_SPEARS = 5,
//    EVENT_RUNIC_BRAND = 6,
//    EVENT_SUMMON_STORMFORGED = 7,
//
//    EVENT_1,
//    EVENT_2,
//};
//
//enum Misc
//{
//    DATA_ACHIEVEMENT,
//};
//
//uint32 SpellsRunicColour[5] =
//{
//    SPELL_RUNIC_BRAND_PURE,
//    SPELL_RUNIC_BRAND_RED,
//    SPELL_RUNIC_BRAND_YELLOW,
//    SPELL_RUNIC_BRAND_BLUE,
//    SPELL_RUNIC_BRAND_GREEN
//};
//
//uint32 SpellsRunicAt[5] =
//{
//    SPELL_RUNIC_BRAND_PURE_AT,
//    SPELL_RUNIC_BRAND_RED_AT,
//    SPELL_RUNIC_BRAND_YELLOW_AT,
//    SPELL_RUNIC_BRAND_BLUE_AT,
//    SPELL_RUNIC_BRAND_GREEN_AT
//};
//
//Position const centrPos = { 2429.13f, 528.55f, 748.99f };
//
////95676
//class boss_odyn_hov : public CreatureScript
//{
//public:
//    boss_odyn_hov() : CreatureScript("boss_odyn_hov") { }
//
//    struct boss_odyn_hov_AI : public BossAI
//    {
//        boss_odyn_hov_AI(Creature* creature) : BossAI(creature, DATA_ODYN)
//        {
//            me->SetFaction(35);
//            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
//        }
//
//        bool intro = true;
//        bool _firstSay = false;
//        bool encounterComplete = false;
//        bool achievement = false;
//        uint8 runicBrandCount = 0;
//        uint32 CheckTimer = 3000;
//
//        uint32 GetData(uint32 type) const override
//        {
//            switch (type)
//            {
//            case DATA_ACHIEVEMENT:
//                return achievement ? 1 : 0;
//            }
//
//            return 0;
//        }
//
//        void Reset() override
//        {
//            if (instance->GetBossState(DATA_ODYN) == DONE)
//            {
//                me->DespawnOrUnsummon();
//                return;
//            }
//
//            _Reset();
//            achievement = false;
//            instance->DoRemoveAurasDueToSpellOnPlayers(200988);
//
//            for (uint8 i = 0; i < 5; i++)
//                instance->DoRemoveAurasDueToSpellOnPlayers(SpellsRunicColour[i]);
//
//            if (instance->GetBossState(DATA_SKOVALD) == DONE && intro)
//                DoAction(true);
//        }
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (who->GetTypeId() != TYPEID_PLAYER)
//                return;
//
//            if (instance->GetData(DATA_SKOVALD_EVENT) != DONE)
//                if (!_firstSay && me->IsWithinDistInMap(who, 150.0f))
//                {
//                    _firstSay = true;
//                    Talk(SAY_FIRST);
//                }
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            _JustEngagedWith();
//            achievement = true;
//            events.RescheduleEvent(EVENT_SPEAR_OF_LIGHT, 8000);
//            events.RescheduleEvent(EVENT_RADIANT_TEMPEST, 24000);
//            events.RescheduleEvent(EVENT_SHATTER_SPEARS, 40000);
//            events.RescheduleEvent(EVENT_RUNIC_BRAND, 44000);
//
//            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                events.RescheduleEvent(EVENT_SUMMON_STORMFORGED, 18000);
//
//            DoCast(me, 202366, true); //Remove Odyn's Blessing - Speed buff
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (!intro)
//                return;
//
//            intro = false;
//            Talk(SAY_INTRO_1); //Most impressive! I never thought I would meet anyone who could match the Valarjar's strength... and yet here you stand.
//            events.RescheduleEvent(EVENT_SKOVALD_DONE_1, 5000);
//        }
//
//        void SpellHit(Unit* caster, SpellInfo const* spell) override
//        {
//            if (spell->Id == SPELL_SPEAR_OF_LIGHT)
//                DoCast(me, 198284, true); //spear of light searcher
//        }
//
//        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
//        {
//            if (spell->Id == SPELL_SHATTER_SPEARS)
//                if (target->GetEntry() == NPC_SPEAR_OF_LIGHT)
//                {
//                    Position pos;
//                    float angle;
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        angle = 0.0f + (i * 2);
//                        target->GetNearPosition(1.0f, angle);
//                        me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_GLOWING_FRAGMENT, true);
//                    }
//                    target->ToCreature()->DespawnOrUnsummon(1000);
//                }
//            if (spell->Id == SPELL_RUNIC_BRAND)
//            {
//                DoCast(target, SpellsRunicColour[runicBrandCount], true);
//                DoCast(me, SpellsRunicAt[runicBrandCount], true);
//                Talk(SAY_RUNIC_1);
//                instance->SetData(DATA_RUNES_ACTIVATED, runicBrandCount);
//                runicBrandCount++;
//            }
//        }
//
//        void SetData(uint32 type, uint32 data) override
//        {
//            me->RemoveDynObject(SpellsRunicAt[data]);
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (me->HealthBelowPct(81) && !encounterComplete)
//            {
//                encounterComplete = true;
//                me->AttackStop();
//                Talk(SAY_DEATH);
//                _JustDied();
//                instance->DoUpdateCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 1809);
//                instance->DoRemoveAurasDueToSpellOnPlayers(200988);
//
//                instance->DoOnPlayers([this](Player* player)
//                {
//                    player->KilledMonsterCredit(me->GetEntry());
//                });
//
//                me->SetFaction(35);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                me->CombatStop();
//                me->GetMotionMaster()->MoveTargetedHome();
//                me->DespawnOrUnsummon(5000);
//
//                if (GetData(DATA_ACHIEVEMENT))
//                    instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 208534);
//            }
//
//            if (damage >= me->GetHealth())
//            {
//                damage = 0;
//                me->SetHealth(me->CountPctFromMaxHealth(80));
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim() && me->IsInCombat())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (CheckTimer <= diff)
//            {
//                if (me->IsInCombat() && (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_KEYSTONE))
//                {
//                    std::list<Creature*> creList;
//                    GetCreatureListWithEntryInGrid(creList, me, 102019, 150.0f);
//                    for (auto const& adds : creList)
//                        if (adds->HasAura(199787))
//                            achievement = false;
//                }
//                CheckTimer = 3000;
//            }
//            else
//                CheckTimer -= diff;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_SKOVALD_DONE_1:
//                    Talk(SAY_INTRO_2); //There is one final trial that awaits......
//                    me->GetMotionMaster()->MoveJump(2399.30f, 528.85f, 749.0f, 25.0f, 15.0f, 1);
//                    events.RescheduleEvent(EVENT_SKOVALD_DONE_2, 10000);
//                    break;
//                case EVENT_SKOVALD_DONE_2:
//                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
//                    Talk(SAY_INTRO_3); //It has been ages since I faced a worthy opponent. Let the battle begin!
//                    me->SetFaction(16);
//                    break;
//                case EVENT_SPEAR_OF_LIGHT:
//                    DoCast(SPELL_SPEAR_OF_LIGHT);
//                    events.RescheduleEvent(EVENT_SPEAR_OF_LIGHT, 10000);
//                    break;
//                case EVENT_RADIANT_TEMPEST:
//                    DoCast(SPELL_RADIANT_TEMPEST);
//                    Talk(SAY_RADIANT);
//                    events.RescheduleEvent(EVENT_RADIANT_TEMPEST, 48000);
//                    break;
//                case EVENT_SHATTER_SPEARS:
//                    DoCast(SPELL_SHATTER_SPEARS);
//                    Talk(SAY_SPEARS);
//                    events.RescheduleEvent(EVENT_SHATTER_SPEARS, 56000);
//                    break;
//                case EVENT_RUNIC_BRAND:
//                    runicBrandCount = 0;
//                    DoCast(SPELL_RUNIC_BRAND);
//                    Talk(SAY_RUNIC);
//                    events.RescheduleEvent(EVENT_RUNIC_BRAND, 56000);
//                    break;
//                case EVENT_SUMMON_STORMFORGED:
//                   // Talk();
//                    me->CastSpell(centrPos.GetPositionX(), centrPos.GetPositionY(), centrPos.GetPositionZ(), SPELL_SUMMON_STORMFORGED, true);
//                    events.RescheduleEvent(EVENT_SUMMON_STORMFORGED, 52000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_odyn_hov_AI(creature);
//    }
//};
//
////102019
//class npc_odyn_stormforged_obliterator : public CreatureScript
//{
//public:
//    npc_odyn_stormforged_obliterator() : CreatureScript("npc_odyn_stormforged_obliterator") {}
//
//    struct npc_odyn_stormforged_obliteratorAI : public ScriptedAI
//    {
//        npc_odyn_stormforged_obliteratorAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//
//        void Reset() override
//        {
//            events.Reset();
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            me->SetMovementAnimKitId(6973);
//            events.RescheduleEvent(EVENT_1, 2000);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    DoZoneInCombat(me, 100.0f);
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    events.RescheduleEvent(EVENT_2, 1000);
//                    break;
//                case EVENT_2:
//                    DoCast(SPELL_SURGE);
//                    events.RescheduleEvent(EVENT_2, 4000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_odyn_stormforged_obliteratorAI(creature);
//    }
//};
//
////201006
//class spell_odyn_radiant_tempest : public SpellScriptLoader
//{
//public:
//    spell_odyn_radiant_tempest() : SpellScriptLoader("spell_odyn_radiant_tempest") { }
//
//    class spell_odyn_radiant_tempest_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_odyn_radiant_tempest_SpellScript);
//
//        void HandleOnHit()
//        {
//            if (!GetCaster() || !GetHitUnit())
//                return;
//
//            if (GetHitUnit() != GetCaster())
//                GetHitUnit()->CastSpell(GetCaster(), GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints, true);
//        }
//
//        void HandleOnCast()
//        {
//            if (!GetCaster())
//                return;
//
//            GetCaster()->CastSpell(GetCaster(), 198263, false);
//        }
//
//        void Register() override
//        {
//            OnHit += SpellHitFn(spell_odyn_radiant_tempest_SpellScript::HandleOnHit);
//            OnCast += SpellCastFn(spell_odyn_radiant_tempest_SpellScript::HandleOnCast);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_odyn_radiant_tempest_SpellScript();
//    }
//};
//
////197963, 197964, 197965, 197966, 197967
//class spell_odyn_runic_brand : public SpellScriptLoader
//{
//public:
//    spell_odyn_runic_brand() : SpellScriptLoader("spell_odyn_runic_brand") { }
//
//    class spell_odyn_runic_brand_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_odyn_runic_brand_AuraScript);
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            Unit* target = GetTarget();
//            if (!target)
//                return;
//
//            InstanceScript* instance = target->GetInstanceScript();
//            if (!instance)
//                return;
//
//            for (uint8 i = 0; i < 5; i++)
//                if (GetId() == SpellsRunicColour[i])
//                    instance->SetData(DATA_RUNES_DEACTIVATED, i);
//        }
//
//        void Register() override
//        {
//            OnEffectRemove += AuraEffectRemoveFn(spell_odyn_runic_brand_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_odyn_runic_brand_AuraScript();
//    }
//};
//
//void AddSC_boss_odyn_hov()
//{
//    new boss_odyn_hov();
//    new npc_odyn_stormforged_obliterator();
//    new spell_odyn_radiant_tempest();
//    new spell_odyn_runic_brand();
//}
