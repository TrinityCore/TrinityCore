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
//#include "ScriptMgr.h"
//#include "Player.h"
//#include "Creature.h"
//#include "CreatureAI.h"
//#include "ScriptedCreature.h"
//#include "GameObject.h"
//#include "GameObjectAI.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraEffects.h"
//#include "unitai.h"
//
//
//enum Says
//{
//    SAY_UNNERVING_HOWL = 0,
//    SAY_END = 1,
//    SAY_BLOOD = 1,
//};
//
//enum Spells
//{
//    SPELL_UNNERVING_HOWL = 196543,
//    SPELL_RAVENOUS_LEAP = 197558,
//    SPELL_RAVENOUS_LEAP_FILTER = 197549,
//    SPELL_RAVENOUS_LEAP_T_1 = 197560, //????? ????
//    SPELL_RAVENOUS_LEAP_JUMP = 196495,
//    SPELL_RAVENOUS_LEAP_DOT = 196497,
//    SPELL_RAVENOUS_LEAP_AOE = 196496,
//    SPELL_CLAW_FRENZY = 196512,
//    SPELL_SCENT_OF_BLOOD = 198800,
//    //Heroic
//    SPELL_SPAWN_WOLVES = 207708,
//    SPELL_STEALTH_WOLFS = 207707,
//    SPELL_STRENGTH_PACK = 199186,
//    SPELL_STRENGTH_PACK_MOD_DMG = 199184,
//
//    //Cosmetic
//    SPELL_STEALTH = 196567,
//    SPELL_LICKING_WOUNDS = 200561,
//    SPELL_BLOOD_SPLAT = 200553,
//
//    //Conversation
//    SPELL_ODYN_HUNTING_GROUND = 202153,
//};
//
//enum eEvents
//{
//    EVENT_UNNERVING_HOWL = 1,
//    EVENT_RAVENOUS_LEAP = 2,
//    EVENT_CLAW_FRENZY = 3,
//    EVENT_SCENT_OF_BLOOD = 4,
//    EVENT_SPAWN_WOLVES = 5,
//
//    //Other
//    EVENT_LOW_HP_MOVE_LAIR = 5,
//};
//
//Position const oneTrashPos[12] =
//{
//    {3006.39f, 2980.55f, 618.48f, 2.26f}, //npc 95674
//    {3075.17f, 3008.41f, 609.65f, 5.10f}, //go 246272
//    {3088.34f, 2989.26f, 614.69f, 5.63f},
//    {3016.72f, 3009.90f, 609.72f, 0.35f},
//    {3036.83f, 3021.59f, 607.72f, 0.31f},
//    {3066.19f, 3016.52f, 609.92f, 5.52f},
//    {2999.78f, 2996.95f, 615.46f, 1.04f},
//    {3048.63f, 3021.88f, 607.67f, 0.19f},
//    {3078.62f, 2995.89f, 612.31f, 5.37f},
//    {3029.34f, 3013.41f, 608.78f, 0.58f},
//    {3058.14f, 3023.87f, 607.94f, 6.06f},
//    {3009.28f, 3003.14f, 612.59f, 0.64f}
//};
//
//Position const secondTrashPos[13] =
//{
//    {3154.69f, 3166.24f, 593.60f, 3.29f}, //npc 95674
//    {3130.42f, 3104.78f, 597.30f, 4.24f}, //go 246272
//    {3088.16f, 2989.61f, 614.72f, 5.46f},
//    {3078.62f, 2996.61f, 612.20f, 5.23f},
//    {3076.25f, 3009.70f, 609.88f, 4.60f},
//    {3075.56f, 3029.13f, 606.97f, 4.30f},
//    {3093.55f, 3041.78f, 605.68f, 3.84f},
//    {3098.51f, 3055.33f, 603.27f, 4.06f},
//    {3109.60f, 3063.75f, 604.57f, 4.21f},
//    {3113.69f, 3076.36f, 602.11f, 4.15f},
//    {3126.08f, 3089.76f, 600.51f, 4.22f},
//    {3140.12f, 3117.60f, 597.83f, 4.38f},
//    {3142.36f, 3131.53f, 596.98f, 4.36f}
//};
//
//class boss_fenryr : public CreatureScript
//{
//public:
//    boss_fenryr() : CreatureScript("boss_fenryr") { }
//
//    struct boss_fenryrAI : public BossAI
//    {
//        boss_fenryrAI(Creature* creature) : BossAI(creature, DATA_FENRYR)
//        {
//            if (instance->GetData(DATA_FENRYR_EVENT) != DONE)
//            {
//                me->SetVisible(false);
//                me->SetReactState(REACT_PASSIVE);
//            }
//        }
//
//        uint8 jumpCount;
//        uint8 jumpMaxCount;
//
//        void Reset() override
//        {
//            _Reset();
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RAVENOUS_LEAP_DOT);
//            me->SetRegenerateHealth(false);
//            me->SetHealth(me->CountPctFromMaxHealth(60));
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//            //43:41(N) | 34:01(H)
//        {
//            _JustEngagedWith();
//            me->SetReactState(REACT_AGGRESSIVE);
//            events.RescheduleEvent(EVENT_UNNERVING_HOWL, 3000); //43:44, 44:23, 45:02, 45:38
//            events.RescheduleEvent(EVENT_RAVENOUS_LEAP, 28000); //44:09, 44:49, 45:26
//            events.RescheduleEvent(EVENT_CLAW_FRENZY, 40000);   //44:20, 44:47, 45:00, 45:36, 45:44
//            events.RescheduleEvent(EVENT_SCENT_OF_BLOOD, 9000); //43:50, 44:28, 45:07, 45:47
//
//            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                events.RescheduleEvent(EVENT_SPAWN_WOLVES, 4000); //34:05, 34:41
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RAVENOUS_LEAP_DOT);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == EFFECT_MOTION_TYPE)
//                if (id == SPELL_RAVENOUS_LEAP_JUMP)
//                    DoCast(me, SPELL_RAVENOUS_LEAP_T_1, true);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_RAVENOUS_LEAP_FILTER:
//                jumpMaxCount++;
//                break;
//            case SPELL_RAVENOUS_LEAP_T_1:
//                if (jumpCount < jumpMaxCount)
//                {
//                    DoCast(target, SPELL_RAVENOUS_LEAP_JUMP, true);
//                    jumpCount++;
//                }
//                break;
//            case SPELL_RAVENOUS_LEAP_AOE:
//                DoCast(target, SPELL_RAVENOUS_LEAP_DOT, true);
//                break;
//            }
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
//            {
//                if (me->GetVictim() && me->GetVictim()->HasAura(196838))
//                {
//                    DoMeleeAttackIfReady();
//                    return;
//                }
//                return;
//            }
//
//            if (me->GetDistance(me->GetHomePosition()) >= 60.0f)
//            {
//                EnterEvadeMode();
//                return;
//            }
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_UNNERVING_HOWL:
//                    Talk(SAY_UNNERVING_HOWL);
//                    DoCast(SPELL_UNNERVING_HOWL);
//                    events.RescheduleEvent(EVENT_UNNERVING_HOWL, 36000);
//                    break;
//                case EVENT_RAVENOUS_LEAP:
//                    jumpCount = 0;
//                    jumpMaxCount = 0;
//                    DoCast(me, SPELL_RAVENOUS_LEAP_FILTER, true);
//                    DoCast(SPELL_RAVENOUS_LEAP);
//                    events.RescheduleEvent(EVENT_RAVENOUS_LEAP, 36000);
//                    break;
//                case EVENT_CLAW_FRENZY:
//                    DoCast(SPELL_CLAW_FRENZY);
//                    events.RescheduleEvent(EVENT_CLAW_FRENZY, urand(10, 20) * IN_MILLISECONDS);
//                    break;
//                case EVENT_SCENT_OF_BLOOD:
//                    DoCast(me, SPELL_SCENT_OF_BLOOD, true);
//                    events.RescheduleEvent(EVENT_SCENT_OF_BLOOD, 38000);
//                    break;
//                case EVENT_SPAWN_WOLVES:
//                {
//                    Position pos;
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->GetNearPosition(40.0f, i);
//                        me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_SPAWN_WOLVES, true);
//                    }
//                    events.RescheduleEvent(EVENT_SPAWN_WOLVES, 36000);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_fenryrAI(creature);
//    }
//};
//
////95674
//class npc_fenryr : public CreatureScript
//{
//public:
//    npc_fenryr() : CreatureScript("npc_fenryr") {}
//
//    struct npc_fenryrAI : public ScriptedAI
//    {
//        npc_fenryrAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            SummonTraces();
//            loseFight = false;
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//        bool loseFight;
//        uint8 jumpCount;
//        uint8 jumpMaxCount;
//
//        void Reset() override
//        {
//            events.Reset();
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RAVENOUS_LEAP_DOT);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            DoZoneInCombat();
//            events.RescheduleEvent(EVENT_UNNERVING_HOWL, 7000);
//            events.RescheduleEvent(EVENT_RAVENOUS_LEAP, 12000);
//            events.RescheduleEvent(EVENT_CLAW_FRENZY, 20000);
//        }
//
//        void SummonTraces()
//        {
//           /* if (me->GetDistance(oneTrashPos[0]) < me->GetDistance(secondTrashPos[0]))
//            {
//                for (uint8 i = 1; i < 12; i++)
//                    me->SummonGameObject(GO_TRACES_OF_FENRIR,
//                        oneTrashPos[i].GetPositionX(),
//                        oneTrashPos[i].GetPositionY(),
//                        oneTrashPos[i].GetPositionZ(),
//                        oneTrashPos[i].GetOrientation(), 0, 0, 0, 0, 1000);
//            }
//            else
//            {
//                for (uint8 i = 1; i < 13; i++)
//                    me->SummonGameObject(GO_TRACES_OF_FENRIR,
//                        secondTrashPos[i].GetPositionX(),
//                        secondTrashPos[i].GetPositionY(),
//                        secondTrashPos[i].GetPositionZ(),
//                        secondTrashPos[i].GetOrientation(), 0, 0, 0, 0, 1000);
//            }*/
//
//            std::list<Creature*> trashList;
//            GetCreatureListWithEntryInGrid(trashList, me, 96609, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 96611, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 103801, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 96640, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 96934, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 99804, 30.0f);
//            GetCreatureListWithEntryInGrid(trashList, me, 96677, 30.0f);
//            for (std::list<Creature*>::iterator itr = trashList.begin(); itr != trashList.end(); ++itr)
//                if ((*itr))
//                    (*itr)->CastSpell((*itr), 29266, true); //Fake Death
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (me->HealthBelowPct(61) && !loseFight)
//            {
//                loseFight = true;
//                me->GetMotionMaster()->Clear(false);
//                events.Reset();
//                me->AttackStop();
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                events.RescheduleEvent(EVENT_LOW_HP_MOVE_LAIR, 500);
//                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_RAVENOUS_LEAP_DOT);
//            }
//
//            if (damage >= me->GetHealth() || loseFight)
//                damage = 0;
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == EFFECT_MOTION_TYPE)
//                if (id == SPELL_RAVENOUS_LEAP_JUMP)
//                    DoCast(me, SPELL_RAVENOUS_LEAP_T_1, true);
//
//            if (type == POINT_MOTION_TYPE)
//                if (id == 1)
//                    me->DespawnOrUnsummon();
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_RAVENOUS_LEAP_FILTER:
//                jumpMaxCount++;
//                break;
//            case SPELL_RAVENOUS_LEAP_T_1:
//                if (jumpCount < jumpMaxCount)
//                {
//                    jumpCount++;
//                    DoCast(target, SPELL_RAVENOUS_LEAP_JUMP, true);
//                }
//                break;
//            case SPELL_RAVENOUS_LEAP_AOE:
//                DoCast(target, SPELL_RAVENOUS_LEAP_DOT, true);
//                break;
//            }
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
//            if (!loseFight)
//                if (me->GetDistance(me->GetHomePosition()) >= 50.0f)
//                {
//                    EnterEvadeMode();
//                    return;
//                }
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_UNNERVING_HOWL:
//                    Talk(SAY_UNNERVING_HOWL);
//                    DoCast(SPELL_UNNERVING_HOWL);
//                    events.RescheduleEvent(EVENT_UNNERVING_HOWL, 32000);
//                    break;
//                case EVENT_RAVENOUS_LEAP:
//                    jumpCount = 0;
//                    jumpMaxCount = 0;
//                    DoCast(me, SPELL_RAVENOUS_LEAP_FILTER, true);
//                    DoCast(SPELL_RAVENOUS_LEAP);
//                    events.RescheduleEvent(EVENT_RAVENOUS_LEAP, 34000);
//                    break;
//                case EVENT_CLAW_FRENZY:
//                    DoCast(SPELL_CLAW_FRENZY);
//                    events.RescheduleEvent(EVENT_CLAW_FRENZY, 10000);
//                    break;
//                case EVENT_LOW_HP_MOVE_LAIR:
//                {
//                    DoCast(me, SPELL_LICKING_WOUNDS, true);
//                    DoCast(me, SPELL_BLOOD_SPLAT, true);
//                    DoCast(me, SPELL_STEALTH, true);
//                    Talk(SAY_END);
//                    if (instance && instance->GetData(DATA_FENRYR_EVENT) != DONE)
//                        instance->SetData(DATA_FENRYR_EVENT, DONE);
//
//                    if (me->GetDistance(oneTrashPos[0]) < me->GetDistance(secondTrashPos[0]))
//                        me->GetMotionMaster()->MovePoint(1, 2991.90f, 3071.94f, 605.72f);
//                    else
//                        me->GetMotionMaster()->MovePoint(1, 3100.44f, 3216.60f, 593.64f);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_fenryrAI(creature);
//    }
//};
//
////99922
//class npc_fenryr_ebonclaw_worg : public CreatureScript
//{
//public:
//    npc_fenryr_ebonclaw_worg() : CreatureScript("npc_fenryr_ebonclaw_worg") { }
//
//    struct npc_fenryr_ebonclaw_worgAI : public ScriptedAI
//    {
//        npc_fenryr_ebonclaw_worgAI(Creature* creature) : ScriptedAI(creature) { }
//
//        EventMap events;
//
//        uint16 checkStealhTimer;
//
//        void Reset() override
//        {
//            checkStealhTimer = 1000;
//            DoCast(me, SPELL_STRENGTH_PACK, true);
//            DoCast(me, SPELL_STEALTH_WOLFS, true);
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            me->SetSpeed(MOVE_RUN, 0.4f);
//            DoZoneInCombat(me, 100.0f);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == 200922) //Strength Pack Search
//                target->CastSpell(target, SPELL_STRENGTH_PACK_MOD_DMG, true);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            if (checkStealhTimer)
//            {
//                if (checkStealhTimer <= diff)
//                {
//                    if (me->HasAura(SPELL_STEALTH_WOLFS))
//                        checkStealhTimer = 1000;
//                    else
//                    {
//                        me->SetSpeed(MOVE_RUN, 1.0f);
//                        checkStealhTimer = 0;
//                    }
//                }
//                else
//                    checkStealhTimer -= diff;
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_fenryr_ebonclaw_worgAI(creature);
//    }
//};
//
////101712, 101712
//class npc_trigger_hov_conversation : public CreatureScript
//{
//public:
//    npc_trigger_hov_conversation() : CreatureScript("npc_trigger_hov_conversation") {}
//
//
//    bool OnGossipHello(Player* clicker, Creature* me)
//    {
//
//        if (!clicker->IsInCombat())
//            clicker->CastSpell(clicker, me->GetEntry() == 101697 ? 197575 : 197577, true);
//        return true;
//    }
//
//    struct npc_trigger_hov_conversationAI : public ScriptedAI
//    {
//        npc_trigger_hov_conversationAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetDisplayId(47641);
//            me->SetReactState(REACT_PASSIVE);
//            _introDone = false;
//        }
//
//        bool _introDone;
//
//        void Reset() override
//        {
//            DoCast(me, 200611, true);
//        }
//
//
//        void MoveInLineOfSight(Unit* who) override
//        {
//            if (who->GetTypeId() != TYPEID_PLAYER || me->GetEntry() == 101697)
//                return;
//
//            if (!_introDone && me->IsWithinDistInMap(who, 45.0f))
//            {
//                _introDone = true;
//                if (Player* target = me->SelectNearestPlayer(30.0f))
//                    target->CastSpell(target, SPELL_ODYN_HUNTING_GROUND, true);
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_trigger_hov_conversationAI(creature);
//    }
//};
//
////198800
//class spell_fenryr_scent_of_blood_filter : public SpellScriptLoader
//{
//public:
//    spell_fenryr_scent_of_blood_filter() : SpellScriptLoader("spell_fenryr_scent_of_blood_filter") { }
//
//    class spell_fenryr_scent_of_blood_filter_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_fenryr_scent_of_blood_filter_SpellScript);
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (!GetCaster() || targets.empty())
//                return;
//
//            if (targets.size() > 1)
//            {
//                if (GetCaster()->GetVictim())
//                    targets.remove(GetCaster()->GetVictim());
//
//                Trinity::Containers::RandomResize(targets, 1);
//            }
//        }
//
//        void Register() override
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fenryr_scent_of_blood_filter_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_fenryr_scent_of_blood_filter_SpellScript();
//    }
//};
//
////196838
//class spell_fenryr_scent_of_blood_fixate : public SpellScriptLoader
//{
//public:
//    spell_fenryr_scent_of_blood_fixate() : SpellScriptLoader("spell_fenryr_scent_of_blood_fixate") { }
//
//    class spell_fenryr_scent_of_blood_fixate_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_fenryr_scent_of_blood_fixate_AuraScript);
//
//        void OnApply(AuraEffect const* pAuraEffect, AuraEffectHandleModes eMode)
//        {
//            if (!GetCaster())
//                return;
//
//            if (Creature* fenryr = GetCaster()->ToCreature())
//            {
//                fenryr->SetReactState(REACT_PASSIVE);
//                fenryr->AttackStop();
//                fenryr->CastSpell(fenryr, 196801, true); //aura + %dmg
//                fenryr->ClearUnitState(UNIT_STATE_CASTING);
//                if (GetTarget())
//                {
//                    fenryr->AI()->AttackStart(GetTarget());
//                    if (Player* player = GetTarget()->ToPlayer())
//                        fenryr->AI()->Talk(SAY_BLOOD);
//                }
//            }
//        }
//
//        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//        {
//            if (!GetCaster())
//                return;
//
//            if (Creature* fenryr = GetCaster()->ToCreature())
//            {
//                fenryr->RemoveAurasDueToSpell(196828);
//                fenryr->SetReactState(REACT_AGGRESSIVE);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_fenryr_scent_of_blood_fixate_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_FIXATE, AURA_EFFECT_HANDLE_REAL);
//            OnEffectRemove += AuraEffectRemoveFn(spell_fenryr_scent_of_blood_fixate_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_FIXATE, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_fenryr_scent_of_blood_fixate_AuraScript();
//    }
//};
//
//void AddSC_boss_fenryr()
//{
//    new boss_fenryr();
//    new npc_fenryr();
//    new npc_fenryr_ebonclaw_worg();
//    new npc_trigger_hov_conversation();
//    new spell_fenryr_scent_of_blood_filter();
//    new spell_fenryr_scent_of_blood_fixate();
//}
