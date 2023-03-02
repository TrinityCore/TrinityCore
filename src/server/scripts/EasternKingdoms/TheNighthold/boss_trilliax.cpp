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
//#include "thenighthold.h"
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//#include "AreaTriggerTemplate.h"
//
//Position const sludgeraxSumPos[8] =
//{
//    {427.32f, 3336.66f, -225.69f, 2.21f}, //112251
//    {429.49f, 3340.25f, -225.69f, 0.73f},
//    {459.06f, 3344.21f, -225.59f, 1.59f},
//    {466.09f, 3280.36f, -225.64f, 2.11f},
//    {475.85f, 3291.92f, -225.66f, 0.70f},
//    {477.00f, 3278.06f, -225.63f, 3.26f},
//    {494.54f, 3319.75f, -225.69f, 2.81f},
//    {495.03f, 3313.42f, -225.69f, 1.97f}
//};
//
//Position const trilliaxCentrPos = { 458.19f, 3309.75f, -224.126f };
//
//Position const scrubberPos[5] =
//{
//    {413.16f, 3285.52f, -225.67f, 3.64f}, //104596
//    {459.70f, 3360.98f, -225.67f, 1.52f},
//    {479.96f, 3355.19f, -225.69f, 1.11f},
//    {453.32f, 3259.95f, -225.69f, 4.62f},
//    {502.97f, 3331.67f, -225.69f, 0.44f}
//};
//
//enum Says
//{
//    SAY_INTRO = 0,
//    SAY_AGGRO = 1,
//    SAY_TIDY_UP = 3,
//    CONV_TOXIC = 2092,
//    CONV_BONDS = 2200,
//    CONV_ANNIGILATION = 2098,
//    CONV_AFTER_ANNIG = 2206,
//    CONV_AFTER_ANNIG_1 = 2204,
//    CONV_FEAST = 2096,
//    CONV_TIDY_UP = 2097,
//    CONV_STERILIZE = 2195,
//    CONV_STERILIZE_1 = 2194,
//    CONV_RAGE = 2093,
//    CONV_DIED = 2205
//};
//
//enum Spells
//{
//    //Intro
//    SPELL_DEAD_COSMETIC = 223945,
//    SPELL_BURSTING_SLIME = 223710,
//    SPELL_DEATH_COSMETIC_2 = 223721,
//
//    SPELL_ARCANE_SEEPAGE = 206482,
//    SPELL_ARCANE_SEEPAGE_FILTER = 208875,
//    SPELL_ARCANE_SEEPAGE_AT = 206487,
//    SPELL_ARCANE_SLASH = 206641,
//    SPELL_FORM_CLEANER_DUMMY = 206570,
//    SPELL_FORM_CLEANER = 206560,
//    SPELL_FORM_MANIAC = 206557,
//    SPELL_FORM_CARETAKER = 206559,
//    SPELL_ANNIHILATION_JUMP = 207620,
//    SPELL_ANNIHILATION_AT = 207630,
//    SPELL_TOXIC_SLICE = 206788,
//    SPELL_TOXIC_SLICE_TRIG = 206789,
//    SPELL_TOXIC_SLICE_AT = 206796,
//    SPELL_STERILIZE = 208506,
//    SPELL_STERILIZE_AURA = 208499,
//    SPELL_STERILIZE_AURA_2 = 218247,
//    SPELL_CLEANSING_RAGE_FILTER = 206834,
//    SPELL_CLEANSING_RAGE_FILTER_2 = 206820,
//    SPELL_MANA_RUPTURE = 206645,
//    SPELL_ARCING_BONDS_FILTER = 208924,
//    SPELL_ARCING_BONDS_DMG = 208918,
//    SPELL_ARCING_BONDS_VISUAL = 209023,
//    SPELL_SUCCULENT_FEAST = 207502,
//    SPELL_SUCCULENT_FEAST_SUM = 207503,
//    SPELL_SUCCULENT_FEAST_AT = 206835,
//    SPELL_TIDY_UP = 207513,
//    SPELL_TIDY_UP_SUM = 207531,
//
//    //Heroic
//    SPELL_TOXIC_SLICE_HEROIC = 214573,
//
//    //Mythic
//    SPELL_DEACTIVATED_CONSTRUCT = 214881,
//    SPELL_ENERGIZED = 214670,
//    SPELL_DUAL_PERSONALITIES_CLEANER = 214882,
//    SPELL_DUAL_PERSONALITIES_MANIAC = 215066,
//    SPELL_TOXIC_SLICE_COPY = 215062,
//    SPELL_CLEANSING_RAGE_COPY = 215072,
//    SPELL_ANNIHILATION_AT_COPY = 214672,
//
//    //Scrubber
//    SPELL_ENERGY_AURA = 224470,
//    SPELL_STERILIZE_DEBUFF = 214583,
//    SPELL_SCRUBBING_MAX = 211897,
//    SPELL_SCRUBBING_MIN = 211907,
//    SPELL_ENERGY_STATE_1 = 215048,
//    SPELL_ENERGY_STATE_2 = 224472,
//    SPELL_CLEANSING_DESTRUCTION = 207327,
//    SPELL_CLEANSING_DESTRUCTION_PLR = 207328,
//};
//
//enum eEvents
//{
//    EVENT_ARCANE_SLASH = 1,
//    EVENT_ANNIHILATION = 2,
//    EVENT_TOXIC_SLICE = 3,
//    EVENT_STERILIZE = 4,
//    EVENT_CLEANSING_RAGE = 5,
//    EVENT_MANA_RUPTURE = 6,
//    EVENT_ARCING_BONDS = 7,
//    EVENT_SUCCULENT_FEAST = 8,
//    EVENT_TIDY_UP = 9
//};
//
//enum Misc
//{
//    ACTION_1 = 1,
//    ACTION_2,
//
//    EVENT_1,
//    EVENT_2,
//    EVENT_3,
//    EVENT_4,
//    EVENT_5,
//    EVENT_6,
//};
//
////104288
//class boss_trilliax : public CreatureScript
//{
//public:
//    boss_trilliax() : CreatureScript("boss_trilliax") {}
//
//    struct boss_trilliaxAI : BossAI
//    {
//        boss_trilliaxAI(Creature* creature) : BossAI(creature, DATA_TRILLIAX)
//        {
//            if (instance->GetData(DATA_TRILLIAX_INTRO) != DONE)
//                Intro();
//        }
//
//        uint32 annihilationTimer;
//        uint32 sumImprintTimer;
//        uint32 imprintEntry;
//
//        void Intro()
//        {
//            DoCast(me, SPELL_DEAD_COSMETIC, true);
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->SummonCreature(NPC_SLUDGERAX, 454.26f, 3307.14f, -225.61f, 3.92f);
//        }
//
//        void Reset() override
//        {
//            _Reset();
//            annihilationTimer = 0;
//            sumImprintTimer = 0;
//
//            RemoveAuras();
//
//            if (instance->GetData(DATA_TRILLIAX_INTRO) == DONE)
//                me->SetReactState(REACT_DEFENSIVE);
//
//            me->SummonCreature(NPC_TRILLIAX_COPY_CLEANER, 475.52f, 3237.49f, -226.73f, 1.83f);
//            me->SummonCreature(NPC_TRILLIAX_COPY_MANIAC, 383.61f, 3330.26f, -226.64f, 6.01f);
//
//            if (IsMythicRaid())
//            {
//                instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 0); //Close Cleaner door
//                instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 2); //Close Maniac door
//            }
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//            DoCast(me, SPELL_ARCANE_SEEPAGE, true);
//            DoCast(me, SPELL_FORM_CLEANER_DUMMY, true);
//
//            events.RescheduleEvent(EVENT_ARCANE_SLASH, 7000);
//            events.RescheduleEvent(EVENT_TOXIC_SLICE, 10000);
//
//            if (IsMythicRaid())
//            {
//                imprintEntry = NPC_TRILLIAX_COPY_CLEANER;
//                sumImprintTimer = 150 * IN_MILLISECONDS; //2m30s
//            }
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//            RemoveAuras();
//
//            if (Creature* talysra = me->FindNearestCreature(NPC_TALYSRA, 140.f, true)) // there we need it
//                talysra->AI()->DoAction(ACTION_MOVE_AFTER_THIRD);
//        }
//
//        void RemoveAuras()
//        {
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STERILIZE);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STERILIZE_AURA);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_STERILIZE_AURA_2);
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_1)
//            {
//                Talk(SAY_INTRO);
//                me->SetReactState(REACT_DEFENSIVE);
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                me->RemoveAurasDueToSpell(SPELL_DEAD_COSMETIC);
//            }
//        }
//
//        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//        {
//            if (apply || mode != AURA_REMOVE_BY_EXPIRE)
//                return;
//
//            switch (spellId)
//            {
//            case SPELL_FORM_CLEANER_DUMMY:
//            case SPELL_FORM_CLEANER:
//            {
//                events.Reset();
//                me->InterruptNonMeleeSpells(false);
//                DoCast(me, SPELL_FORM_MANIAC, true);
//                events.RescheduleEvent(EVENT_ARCANE_SLASH, 7000);
//                events.RescheduleEvent(EVENT_MANA_RUPTURE, 2000);
//                events.RescheduleEvent(EVENT_ARCING_BONDS, 5000);
//                annihilationTimer = 20000;
//                if (IsMythicRaid())
//                {
//                    EntryCheckPredicate pred1(NPC_TRILLIAX_COPY_MANIAC);
//                    summons.DoAction(ACTION_2, pred1);
//                }
//            }
//            break;
//            case SPELL_FORM_MANIAC:
//            {
//                events.Reset();
//                me->InterruptNonMeleeSpells(false);
//                me->RemoveAurasDueToSpell(SPELL_MANA_RUPTURE);
//                DoCast(me, SPELL_FORM_CARETAKER, true);
//                me->RemoveUnitFlag(UNIT_FLAG_STUNNED);
//                events.RescheduleEvent(EVENT_SUCCULENT_FEAST, 5000);
//                events.RescheduleEvent(EVENT_TIDY_UP, 12000);
//                break;
//            }
//            case SPELL_FORM_CARETAKER:
//            {
//                events.Reset();
//                me->SetReactState(REACT_AGGRESSIVE);
//                DoCast(me, SPELL_FORM_CLEANER, true);
//                events.RescheduleEvent(EVENT_ARCANE_SLASH, 7000);
//                events.RescheduleEvent(EVENT_TOXIC_SLICE, 10000);
//                events.RescheduleEvent(EVENT_STERILIZE, 1000);
//                events.RescheduleEvent(EVENT_CLEANSING_RAGE, 10000);
//                if (IsMythicRaid())
//                {
//                    EntryCheckPredicate pred(NPC_TRILLIAX_COPY_CLEANER);
//                    summons.DoAction(ACTION_2, pred);
//                }
//                break;
//            }
//            }
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == EFFECT_MOTION_TYPE)
//            {
//                if (id == SPELL_ANNIHILATION_JUMP)
//                {
//                    me->GetMotionMaster()->Clear();
//                    events.RescheduleEvent(EVENT_ANNIHILATION, 2500);
//                }
//            }
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_TOXIC_SLICE)
//            {
//                Position pos;
//                for (uint8 i = 0; i < 5; ++i)
//                {
//                    me->CastSpell(pos, SPELL_TOXIC_SLICE_TRIG, true);
//                }
//            }
//            if (spell->Id == SPELL_SUCCULENT_FEAST)
//            {
//                Position pos;
//                uint8 count = IsMythicRaid() ? 4 : IsHeroicRaid() ? 3 : 2;
//
//                for (uint8 i = 0; i < count; ++i)
//                {
//                    me->GetNearPosition(25.0f, frand(0.0f, 6.28f));
//                    me->CastSpell(pos, SPELL_SUCCULENT_FEAST_SUM, true);
//                }
//            }
//            if (spell->Id == SPELL_TIDY_UP)
//            {
//                for (uint8 i = 0; i < 5; ++i)
//                {
//                    if (me && me->IsAlive())
//                        me->CastSpell(scrubberPos[i], SPELL_TIDY_UP_SUM, true);
//                }
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
//            if (annihilationTimer)
//            {
//                if (annihilationTimer <= diff)
//                {
//                    annihilationTimer = 0;
//                    events.Reset();
//                    me->InterruptNonMeleeSpells(false);
//                    me->AttackStop();
//                    DoCast(me, SPELL_ANNIHILATION_JUMP, true);
//                }
//                else
//                    annihilationTimer -= diff;
//            }
//
//            if (sumImprintTimer)
//            {
//                if (sumImprintTimer <= diff)
//                {
//                    sumImprintTimer = 135 * IN_MILLISECONDS; //2m15s
//
//                    EntryCheckPredicate pred(imprintEntry);
//                    summons.DoAction(ACTION_1, pred); //Activate Golem
//
//                    if (imprintEntry == NPC_TRILLIAX_COPY_CLEANER)
//                        imprintEntry = NPC_TRILLIAX_COPY_MANIAC;
//                    else
//                        sumImprintTimer = 0;
//                }
//                else
//                    sumImprintTimer -= diff;
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_ARCANE_SLASH:
//                    DoCastVictim(SPELL_ARCANE_SLASH);
//                    if (me->HasAura(SPELL_FORM_MANIAC))
//                        events.RescheduleEvent(EVENT_ARCANE_SLASH, 8000);
//                    else
//                        events.RescheduleEvent(EVENT_ARCANE_SLASH, 11000);
//                    break;
//                case EVENT_ANNIHILATION:
//                   // me->CreateConversation(CONV_ANNIGILATION);
//                    DoCast(me, SPELL_ANNIHILATION_AT, true);
//                    break;
//                case EVENT_TOXIC_SLICE:
//                    DoCast(SPELL_TOXIC_SLICE);
//                    //me->CreateConversation(CONV_TOXIC);
//                    events.RescheduleEvent(EVENT_TOXIC_SLICE, 26000);
//                    break;
//                case EVENT_STERILIZE:
//                    DoCast(SPELL_STERILIZE);
//                   // me->CreateConversation(urand(0, 1) == 1 ? CONV_STERILIZE : CONV_STERILIZE_1);
//                    break;
//                case EVENT_CLEANSING_RAGE:
//                    DoCast(me, SPELL_CLEANSING_RAGE_FILTER, true);
//                   // me->CreateConversation(CONV_RAGE);
//                    break;
//                case EVENT_MANA_RUPTURE:
//                    DoCast(me, SPELL_MANA_RUPTURE, true);
//                    break;
//                case EVENT_ARCING_BONDS:
//                    DoCast(SPELL_ARCING_BONDS_FILTER);
//                    //me->CreateConversation(CONV_BONDS);
//                    break;
//                case EVENT_SUCCULENT_FEAST:
//                    DoCast(SPELL_SUCCULENT_FEAST);
//                    break;
//                case EVENT_TIDY_UP:
//                    DoCast(SPELL_TIDY_UP);
//                    Talk(SAY_TIDY_UP);
//                   // me->CreateConversation(CONV_TIDY_UP);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_trilliaxAI(creature);
//    }
//};
//
////112255
//class npc_trilliax_sludgerax : public CreatureScript
//{
//public:
//    npc_trilliax_sludgerax() : CreatureScript("npc_trilliax_sludgerax") {}
//
//    struct npc_trilliax_sludgeraxAI : public ScriptedAI
//    {
//        npc_trilliax_sludgeraxAI(Creature* creature) : ScriptedAI(creature), putridDies(0)
//        {
//            instance = me->GetInstanceScript();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//        uint8 putridDies;
//
//        void Reset() override
//        {
//            events.Reset();
//            //events.RescheduleEvent(EVENT_1, 1000);
//        }
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            for (const auto& sludgeraxSumPo : sludgeraxSumPos)
//                me->SummonCreature(NPC_PUTRID_SLUDGE, sludgeraxSumPo);
//
//            putridDies = 0;
//            DoCast(me, SPELL_BURSTING_SLIME, true);
//            DoCast(me, SPELL_DEATH_COSMETIC_2, true);
//        }
//
//        void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//        {
//            if (summon->GetEntry() == NPC_PUTRID_SLUDGE)
//            {
//                putridDies++;
//
//                if (putridDies == 8)
//                {
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                    me->RemoveAurasDueToSpell(SPELL_DEATH_COSMETIC_2);
//                }
//            }
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            if (instance->GetData(DATA_TRILLIAX_INTRO) != DONE)
//            {
//                instance->SetData(DATA_TRILLIAX_INTRO, DONE);
//
//                if (Unit* owner = me->GetOwner())
//                    owner->GetAI()->DoAction(ACTION_1);
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
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_trilliax_sludgeraxAI(creature);
//    }
//};
//
////104547, 104561
//class npc_trilliax_toxic_slice_succulent_feast : public CreatureScript
//{
//public:
//    npc_trilliax_toxic_slice_succulent_feast() : CreatureScript("npc_trilliax_toxic_slice_succulent_feast") {}
//
//    struct npc_trilliax_toxic_slice_succulent_feastAI : public ScriptedAI
//    {
//        npc_trilliax_toxic_slice_succulent_feastAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        uint32 despawnTimer = 0;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            if (me->GetEntry() == NPC_TOXIC_SLICE)
//                DoCast(me, SPELL_TOXIC_SLICE_AT, true);
//            else
//                DoCast(me, SPELL_SUCCULENT_FEAST_AT, true);
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == 206824)
//            {
//                despawnTimer = 500;
//
//                if (me->GetEntry() == NPC_TOXIC_SLICE)
//                    me->RemoveAurasDueToSpell(SPELL_TOXIC_SLICE_AT);
//                else
//                    me->RemoveAurasDueToSpell(SPELL_SUCCULENT_FEAST_AT);
//            }
//        }
//
//        void OnAreaTriggerCast(Unit* caster, Unit* target, uint32 spellId, uint32 createATSpellId)
//        {
//            if (spellId == 206798 || spellId == 206838)
//            {
//                if (target && IsHeroicPlusRaid() && spellId == 206798)
//                    target->CastSpell(target, SPELL_TOXIC_SLICE_HEROIC, true);
//
//                me->DespawnOrUnsummon(100);
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (despawnTimer)
//            {
//                if (despawnTimer <= diff)
//                {
//                    despawnTimer = 0;
//                    me->DespawnOrUnsummon();
//                }
//                else
//                    despawnTimer -= diff;
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_trilliax_toxic_slice_succulent_feastAI(creature);
//    }
//};
//
////104596
//class npc_trilliax_scrubber : public CreatureScript
//{
//public:
//    npc_trilliax_scrubber() : CreatureScript("npc_trilliax_scrubber") {}
//
//    struct npc_trilliax_scrubberAI : public ScriptedAI
//    {
//        npc_trilliax_scrubberAI(Creature* creature) : ScriptedAI(creature), onClick(false)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//        ObjectGuid areaTriggerGuid;
//        ObjectGuid sliceGuid;
//        bool onClick;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            onClick = false;
//            me->SetPowerType(POWER_MANA);
//            me->SetMaxPower(POWER_MANA, 100);
//            me->SetPower(POWER_MANA, 0);
//            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
//            DoCast(me, SPELL_ENERGY_AURA, true);
//            events.RescheduleEvent(EVENT_1, 2000);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == POINT_MOTION_TYPE)
//            {
//                if (id == 1)
//                    events.RescheduleEvent(EVENT_2, 100);
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_1)
//            {
//                events.Reset();
//                if (!me->HasAura(SPELL_ENERGY_STATE_2))
//                    DoCast(me, SPELL_ENERGY_STATE_2, true);
//                DoCast(SPELL_CLEANSING_DESTRUCTION);
//                me->SetNpcFlags(UNIT_NPC_FLAG_SPELLCLICK);
//            }
//        }
//
//        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//        {
//            if (apply || mode != AURA_REMOVE_BY_EXPIRE)
//                return;
//
//            if (spellId == SPELL_CLEANSING_DESTRUCTION)
//            {
//                onClick = true;
//                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
//                me->DespawnOrUnsummon(500);
//            }
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == 207433 && !onClick) //Ride me
//            {
//                onClick = true;
//                me->InterruptNonMeleeSpells(false);
//                DoCast(caster, SPELL_CLEANSING_DESTRUCTION_PLR, true);
//                me->DespawnOrUnsummon(500);
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
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
//                {
//                    areaTriggerGuid.Clear();
//                    sliceGuid.Clear();
//                    std::list<AreaTrigger*> atList;
//                    if (Unit* owner = me->GetOwner())
//                    {
//                        if (Creature* slice = me->FindNearestCreature(NPC_TOXIC_SLICE, 100.0f, true))
//                        {
//                            sliceGuid = slice->GetGUID();
//                            me->GetMotionMaster()->MovePoint(1, slice->GetPosition());
//                            break;
//                        }
//                        owner->GetAreaTriggerListWithSpellIDInRange(atList, SPELL_ARCANE_SEEPAGE_AT, 100.0f);
//                        if (!atList.empty())
//                        {
//                            for (auto& itr : atList)
//                            {
//                                areaTriggerGuid = itr->GetGUID();
//                                me->GetMotionMaster()->MovePoint(1, itr->GetPosition());
//                                break;
//                            }
//                        }
//                    }
//                    if (sliceGuid.IsEmpty() && areaTriggerGuid.IsEmpty())
//                        events.RescheduleEvent(EVENT_1, urand(2, 4) * IN_MILLISECONDS);
//                    break;
//                }
//                case EVENT_2:
//                    if (Creature* slice = ObjectAccessor::GetCreature(*me, sliceGuid))
//                    {
//                        me->RemoveAurasDueToSpell(SPELL_STERILIZE_DEBUFF);
//                        me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_STERILIZE_DEBUFF, true);
//                        DoCast(SPELL_SCRUBBING_MAX);
//                        slice->DespawnOrUnsummon();
//                        break;
//                    }
//                    else if (AreaTrigger* areaTrigger = ObjectAccessor::GetAreaTrigger(*me, areaTriggerGuid))
//                    {
//                        areaTrigger->Remove();
//                        DoCast(SPELL_SCRUBBING_MIN);
//                    }
//                    events.RescheduleEvent(EVENT_1, 2000);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_trilliax_scrubberAI(creature);
//    }
//};
//
////108144, 108303
//class npc_trilliax_imprint : public CreatureScript
//{
//public:
//    npc_trilliax_imprint() : CreatureScript("npc_trilliax_imprint") {}
//
//    struct npc_trilliax_imprintAI : public ScriptedAI
//    {
//        npc_trilliax_imprintAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            me->SetMaxPower(POWER_MANA, 100);
//            me->SetPower(POWER_MANA, 0);
//            DoCast(me, SPELL_DEACTIVATED_CONSTRUCT, true);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == POINT_MOTION_TYPE)
//            {
//                if (id == 1)
//                {
//                    if (me->GetEntry() == NPC_TRILLIAX_COPY_CLEANER)
//                    {
//                        instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 0); //Close Cleaner Door
//                        events.RescheduleEvent(EVENT_3, 20000);
//                    }
//                    else
//                    {
//                        instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 2); //Close Maniac Door
//                        DoCast(me, SPELL_MANA_RUPTURE, true);
//                    }
//                    events.RescheduleEvent(EVENT_6, 1000);
//                }
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            switch (action)
//            {
//            case ACTION_1:
//                me->RemoveAurasDueToSpell(SPELL_DEACTIVATED_CONSTRUCT);
//                if (me->GetEntry() == NPC_TRILLIAX_COPY_CLEANER)
//                    instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 1); //Open Cleaner Door
//                else
//                    instance->SetData(DATA_TRILLIAX_IMPRINT_DOOR, 3); //Open Maniac Door
//                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//                events.RescheduleEvent(EVENT_1, 2000);
//                break;
//            case ACTION_2:
//                if (me->IsInCombat())
//                    if (Unit* owner = me->GetOwner())
//                    {
//                        if (me->GetEntry() == NPC_TRILLIAX_COPY_CLEANER)
//                            owner->CastSpell(me, SPELL_DUAL_PERSONALITIES_CLEANER, true);
//                        else
//                            owner->CastSpell(me, SPELL_DUAL_PERSONALITIES_MANIAC, true);
//                    }
//                break;
//            }
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_TOXIC_SLICE)
//            {
//                Position pos;
//                if (Unit* owner = me->GetOwner())
//                    me->CastSpell(pos, SPELL_TOXIC_SLICE_TRIG, true);
//            }
//        }
//
//        void OnApplyOrRemoveAura(uint32 spellId, AuraRemoveMode mode, bool apply)
//        {
//            if (apply || mode != AURA_REMOVE_BY_EXPIRE)
//                return;
//
//            if (spellId == SPELL_ANNIHILATION_AT_COPY)
//                events.RescheduleEvent(EVENT_5, 500);
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    if (me->GetEntry() == NPC_TRILLIAX_COPY_CLEANER)
//                        me->GetMotionMaster()->MovePoint(1, 466.93f, 3271.80f, -225.67f);
//                    else
//                        me->GetMotionMaster()->MovePoint(1, 420.84f, 3319.18f, -225.69f);
//                    break;
//                case EVENT_2:
//                    DoCast(me, SPELL_ENERGIZED, true);
//                    events.RescheduleEvent(EVENT_2, 20000);
//                    break;
//                case EVENT_3:
//                    DoCast(SPELL_TOXIC_SLICE_COPY);
//                    events.RescheduleEvent(EVENT_3, 16000);
//                    break;
//                case EVENT_4:
//                    if (me->GetPower(POWER_MANA) >= 100)
//                    {
//                        if (me->GetEntry() == NPC_TRILLIAX_COPY_CLEANER)
//                            DoCast(SPELL_CLEANSING_RAGE_COPY);
//                        else
//                        {
//                            me->AttackStop();
//                            DoCast(SPELL_ANNIHILATION_AT_COPY);
//                        }
//                    }
//                    events.RescheduleEvent(EVENT_4, 2000);
//                    break;
//                case EVENT_5:
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    break;
//                case EVENT_6:
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//
//                    //me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    DoZoneInCombat(me, 100.0f);
//                    events.RescheduleEvent(EVENT_2, 100);
//                    events.RescheduleEvent(EVENT_4, 2000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_trilliax_imprintAI(creature);
//    }
//};
//
////207630, 214672
//class spell_trilliax_annihilation : public SpellScriptLoader
//{
//public:
//    spell_trilliax_annihilation() : SpellScriptLoader("spell_trilliax_annihilation") {}
//
//    class spell_trilliax_annihilation_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_trilliax_annihilation_AuraScript);
//
//        float curr_o;
//        bool leftOrient = (urand(0, 1));
//        uint32 timer = 0;
//        uint32 randTimer = 0;
//
//        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
//        {
//            if (GetCaster() && GetCaster()->GetMap()->IsMythic() && GetCaster()->GetEntry() == NPC_TRILLIAX)
//                randTimer = urand(3, 9) * IN_MILLISECONDS;
//        }
//
//        void OnUpdate(AuraEffect const* AurEff)
//        {
//            if (GetCaster())
//            {
//                    timer = 100;
//                    curr_o = GetCaster()->GetOrientation();
//
//                    if (leftOrient)
//                        GetCaster()->SetFacingTo(curr_o - 0.04f);
//                    else
//                        GetCaster()->SetFacingTo(curr_o + 0.04f);
//               
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_trilliax_annihilation_AuraScript::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_trilliax_annihilation_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_AREA_TRIGGER);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_trilliax_annihilation_AuraScript();
//    }
//};
////208910
//class spell_trilliax_arcing_bonds : public SpellScriptLoader
//{
//public:
//    spell_trilliax_arcing_bonds() : SpellScriptLoader("spell_trilliax_arcing_bonds") {}
//
//    class spell_trilliax_arcing_bonds_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_trilliax_arcing_bonds_AuraScript);
//
//            void OnPeriodic(AuraEffect const* aurEff)
//        {
//            if (!GetCaster() || !GetTarget())
//                return;
//
//            if (!GetCaster()->HasAura(208915))
//            {
//                aurEff->GetBase()->Remove();
//                return;
//            }
//
//            if (GetCaster()->GetDistance(GetTarget()) >= 5.0f)
//            {
//                GetCaster()->CastSpell(GetTarget(), SPELL_ARCING_BONDS_DMG, true);
//                GetTarget()->CastSpell(GetCaster(), SPELL_ARCING_BONDS_DMG, true);
//            }
//            else
//            {
//                GetCaster()->CastSpell(GetTarget(), SPELL_ARCING_BONDS_VISUAL, true);
//                GetTarget()->CastSpell(GetCaster(), SPELL_ARCING_BONDS_VISUAL, true);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_trilliax_arcing_bonds_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_trilliax_arcing_bonds_AuraScript();
//    }
//};
//
////224470
//class spell_trilliax_energy_aura : public SpellScriptLoader
//{
//public:
//    spell_trilliax_energy_aura() : SpellScriptLoader("spell_trilliax_energy_aura") {}
//
//    class spell_trilliax_energy_aura_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_trilliax_energy_aura_AuraScript);
//
//        void OnTick(AuraEffect const* aurEff)
//        {
//            if (Creature* caster = GetCaster()->ToCreature())
//            {
//                if (caster->GetPower(POWER_MANA) >= 100)
//                {
//                    caster->AI()->DoAction(ACTION_1);
//                    aurEff->GetBase()->Remove();
//                }
//                else if (caster->GetPower(POWER_MANA) > 70)
//                {
//                    if (!caster->HasAura(SPELL_ENERGY_STATE_2))
//                        caster->CastSpell(caster, SPELL_ENERGY_STATE_2, true);
//                }
//                else if (caster->GetPower(POWER_MANA) > 20)
//                {
//                    if (!caster->HasAura(SPELL_ENERGY_STATE_1))
//                        caster->CastSpell(caster, SPELL_ENERGY_STATE_1, true);
//                }
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_trilliax_energy_aura_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_trilliax_energy_aura_AuraScript();
//    }
//};
//
//void AddSC_boss_trilliax()
//{
//    new boss_trilliax();
//    new npc_trilliax_sludgerax();
//    new npc_trilliax_toxic_slice_succulent_feast();
//    new npc_trilliax_scrubber();
//    new npc_trilliax_imprint();
//    new spell_trilliax_annihilation();
//    new spell_trilliax_arcing_bonds();
//    new spell_trilliax_energy_aura();
//}
