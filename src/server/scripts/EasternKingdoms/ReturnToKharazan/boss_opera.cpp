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
//#include "new_karazhan.h"
//
//enum Says
//{
//    /// Opera: Wikket
//
//        // Galindre
//    SAY_GALINDRE_AGGRO = 0,
//    SAY_MAGNIFICENT = 1,
//    SAY_MAGNIFICENT_WARN = 2,
//
//    // Elfyra
//    SAY_ELFYRA_AGGRO = 0,
//    SAY_ELFYRA_GRAVITY = 1,
//    SAY_ELFYRA_ASSISTANTS = 2,
//    SAY_ELFYRA_DEATH = 3,
//
//    /// Opera: Westfall
//
//        //Toe
//        SAY_TOE_AGGRO = 0,
//        SAY_TOE_TIME_OUT = 1,
//        SAY_TOE_RETURN_FIGHT = 2,
//        SAY_TOE_FLAME_GALE = 3,
//        SAY_TOE_DEATH = 4,
//
//        /// Opera: Beautiful Beast
//        SAY_COGGLESTON_AGGRO = 0,
//        SAY_COGGLESTON_SUMMON = 1,
//        SAY_COGGLESTON_DEATH = 2,
//
//        SAY_CAULDRONS_LEFTOVERS = 0,
//        SAY_CAULDRONS_DEATH = 1,
//
//        SAY_LUMINORE_HEAT_WAVE = 0,
//        SAY_LUMINORE_DEATH = 1,
//
//        SAY_BABBLET_FIXATE = 0,
//        SAY_BABBLET_DEATH = 1,
//};
//
//enum Spells
//{
//    ///Opera: Other
//        //Monkey King
//    SPELL_SHADOWSTEP = 108611,
//
//    //Barnes
//    SPELL_FEIGN_DEATH = 196391,
//    SPELL_BLINK_VISUAL = 232198,
//
//    /// Opera: Wikket
//    SPELL_WIKKET_BOND = 231869,
//    SPELL_SHARED_HEALTH = 229010,
//    SPELL_NAUGHTY_INTRO_CONVERS = 227864,
//    //Galindre
//    SPELL_MAGIC_MAGNIFICENT = 232235, // Intro visual
//    SPELL_FLASHY_BOLT = 227341,
//    SPELL_WONDROUS_RADIANCE = 227410,
//    SPELL_MAGIC_MAGNIFICENT_IMMUNE = 227346,
//    SPELL_MAGIC_MAGNIFICENT_DMG = 227776,
//    SPELL_MAGIC_MAGNIFICENT_UNK = 227347, //?
//    //Elfyra
//    SPELL_RIDE_VEH_BROOM = 227821,
//    SPELL_DREARY_BOLT = 227543,
//    SPELL_SUMMON_ASSISTANTS = 227477,
//    SPELL_MODSCALE = 214567,
//    SPELL_DEFY_GRAVITY = 227447,
//
//    /// Opera: Westfall
//        //Mrrgria Summons
//        SPELL_POISONOUS_SHANK_FILTER = 228065,
//        SPELL_POISONOUS_SHANK_TP = 227319,
//        SPELL_POISONOUS_SHANK_DMG = 227325,
//
//        //Toe summons
//        SPELL_BUBBLE_BLAST = 227420,
//
//        //Toe
//        SPELL_BURNING_LEG_SWEEP = 227568,
//        SPELL_DASHING_FLAME_GALE = 227449,
//        SPELL_DASHING_FLAME_GALE_FILTER = 227452,
//        SPELL_DASHING_FLAME_GALE_CHARGE = 227453,
//        SPELL_DASHING_FLAME_GALE_AT = 227467,
//
//        //Mrrgria
//        SPELL_THUNDER_RITUAL = 227777,
//        SPELL_WASH_AWAY_FILTER = 227783,
//        SPELL_WASH_AWAY_AT = 227790,
//        SPELL_STUN = 78320,
//
//        /// Opera: Beautiful Beast
//        SPELL_EMINENCE = 228729,
//
//        //Coggleston
//        SPELL_SPECTRAL_SERVICE = 232156,
//        SPELL_DENT_ARMOR = 227985,
//        SPELL_DINNER_BELL = 227987,
//        SPELL_KARA_KAZHAM = 232153,
//
//        //Luminore
//        SPELL_CANDLE_HAT = 227497,
//        SPELL_BURNING_BLAZE = 228193,
//        SPELL_HEAT_WAVE = 228025,
//
//        //Babblet
//        SPELL_MAID_ATTIRE = 227505,
//        SPELL_SEVERE_DUSTING = 228213,
//        SPELL_SEVERE_DUSTING_CONFUSE = 228215,
//        SPELL_FIXATE = 228221,
//
//        //Cauldrons
//        SPELL_CAULDRON_DRESSING = 227898,
//        SPELL_SOUP_SPRAY = 228011,
//        SPELL_DRENCHED = 228013,
//        SPELL_LEFTOVERS = 228019,
//        SPELL_LEFTOVERS_VISUAL = 228015,
//};
//
//enum eEvents
//{
//    ///> Barnes
//    EVENT_START_TALK = 1,
//    EVENT_END_TALK = 2,
//    EVENT_TELEPORT = 3,
//
//    //Opera: Wikket
//    EVENT_WIKKET_1 = 4,
//    EVENT_WIKKET_2 = 5,
//    EVENT_WIKKET_3 = 6,
//
//    //Opera: Westfall
//    EVENT_WESTFALL = 7,
//
//    //Opera: Beautiful Beast
//    EVENT_BEAUTIFUL_BEAST = 8,
//    ///<
//
//        //Wikket bosses
//        EVENT_WIK_GALINDRE_1 = 1,
//        EVENT_WIK_GALINDRE_2 = 2,
//        EVENT_WIK_GALINDRE_3 = 3,
//        EVENT_WIK_GALINDRE_4 = 4,
//        EVENT_WIK_GALINDRE_FLASHY_BOLT = 5,
//        EVENT_WIK_GALINDRE_WONDROUS_RADIANCE = 6,
//        EVENT_WIK_GALINDRE_MAGIC_MAGNIFICENT = 7,
//        EVENT_WIK_GALINDRE_AGGRO_TALK = 8,
//
//        EVENT_WIK_ELFYRA_DREARY_BOLT = 1,
//        EVENT_WIK_ELFYRA_SUM_ASSISTANTS = 2,
//        EVENT_WIK_ELFYRA_SUM_ASSISTANTS_2 = 3,
//        EVENT_WIK_ELFYRA_DEFY_GRAVITY = 4,
//
//        //Westfall bosses
//        EVENT_TOE_BURNING_LEG_SWEEP = 1,
//        EVENT_TOE_DASHING_FLAME_GALE = 2,
//        EVENT_TOE_DASHING_FLAME_GALE_CHARGE = 3,
//
//        EVENT_MRRG_THUNDER_RITUAL = 1,
//        EVENT_MRRG_WASH_AWAY = 2,
//
//        //BB bosses
//        EVENT_LUMINORE_BURNING_BLAZE = 1,
//        EVENT_LUMINORE_HEAT_WAVE = 2,
//
//        EVENT_CAULDRON_SOUP_SPRAY = 1,
//        EVENT_CAULDRON_LEFTOVERS = 2,
//
//        EVENT_BABBLET_FIXATE = 1,
//        EVENT_BABBLET_FOLLOW_TARGET = 2,
//
//        EVENT_COGGLESTON_DENT_ARMOR = 1,
//        EVENT_SUMMON_HELPERS = 2,
//        EVENT_DINNER_BELL = 3,
//};
//
//enum eAnim // SMSG_PLAY_ONE_SHOT_ANIM_KIT
//{
//    MONKEY_KING_PUNCH_ANIM = 9782,
//    GALINDRE_UNK_ANIM = 1173,
//};
//
//enum eFaction
//{
//    WEST_FACTION_NEUTRAL_GANGSTERS = 1828,
//    WEST_FACTION_NEUTRAL_MURLOCS = 2220,
//    WEST_FACTION_AGGRESSIVE = 16,
//};
//
//enum Miscs
//{
//    ACTION_1 = 1,
//    ACTION_2,
//    ACTION_3,
//};
//
//enum MiscEvents
//{
//    EVENT_1 = 1,
//    EVENT_2 = 2,
//    EVENT_3 = 3,
//    EVENT_4 = 4,
//    EVENT_5 = 5,
//    EVENT_6 = 6,
//};
//
////114339
//class npc_rtk_barnes_encounter_starter : public CreatureScript
//{
//public:
//    npc_rtk_barnes_encounter_starter() : CreatureScript("npc_rtk_barnes_encounter_starter") {}
//
//    struct npc_rtk_barnes_encounter_starterAI : public ScriptedAI
//    {
//        npc_rtk_barnes_encounter_starterAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            me->SetReactState(REACT_PASSIVE);
//            me->SetWalk(true);
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//
//        bool startEvent = false;
//
//        bool GossipSelect(Player* player, uint32 sender, uint32 action) override
//        {
//            if (!startEvent && sender == 20468)
//            {
//                startEvent = true;
//                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
//                instance->SetData(DATA_OPERA_HALL_INTRO, SPECIAL);
//                //> DEBUG!!!
//                    //instance->SetData(DATA_OPERA_HALL_INTRO, IN_PROGRESS);
//                    //return;
//                //< DEBUG!!!
//                events.RescheduleEvent(EVENT_START_TALK, 1 * IN_MILLISECONDS);
//
//                switch (instance->GetData(DATA_OPERA_HALL_SCENE))
//                {
//                case DATA_OPERA_HALL_WIKKET:
//                    events.RescheduleEvent(EVENT_WIKKET_1, 10 * IN_MILLISECONDS);
//                    break;
//                case DATA_OPERA_HALL_WESTFALL:
//                    events.RescheduleEvent(EVENT_WESTFALL, 10 * IN_MILLISECONDS);
//                    break;
//                case DATA_OPERA_HALL_BEAUTIFUL_BEAST:
//                    events.RescheduleEvent(EVENT_BEAUTIFUL_BEAST, 10 * IN_MILLISECONDS);
//                    break;
//                default:
//                    break;
//                }
//            }
//
//        return true;
//        }
//
//        void Reset() override
//        {
//            if (instance->GetBossState(DATA_OPERA_HALL) == DONE)
//                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == POINT_MOTION_TYPE)
//            {
//                if (id == 1)
//                {
//                    DoCast(me, SPELL_BLINK_VISUAL, true);
//                    events.RescheduleEvent(EVENT_TELEPORT, 1 * IN_MILLISECONDS);
//                }
//            }
//        }
//
//        // Summon Spotlight and text delay event
//        void TextEvent(uint32 spotlightTimer, uint8 textIdx)
//        {
//            if (Creature* spotlight = me->SummonCreature(NPC_THEATRE_SPOTLIGHT, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, spotlightTimer))
//                spotlight->CastSpell(spotlight, 25824, true);
//
//            // Only Opera scene: "Westfall" and "Beautiful Beast".
//            if (!textIdx)
//                return;
//
//            bool westfall = instance->GetData(DATA_OPERA_HALL_SCENE) == DATA_OPERA_HALL_WESTFALL;
//
//            for (uint8 i = 0; i < 4; ++i)
//                DelayTalk(me, (westfall ? 8 : 12) * i, i + textIdx);
//
//            events.RescheduleEvent(EVENT_END_TALK, (westfall ? 38 : 44) * IN_MILLISECONDS);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_START_TALK:
//                    Talk(0); // Splendid. I'm going to get the audience ready. Break a leg!
//                    break;
//                case EVENT_WIKKET_1:
//                    me->SummonCreature(NPC_THE_MONKEY_KING, -10897.90f, -1805.59f, 91.55f, 1.46f);
//                    TextEvent(5000, 0);
//                    events.RescheduleEvent(EVENT_WIKKET_2, 1 * IN_MILLISECONDS);
//                    break;
//                case EVENT_WIKKET_2:
//                    Talk(1); // Welcome, ladies and gentlemen, to our--OOF!
//                    events.RescheduleEvent(EVENT_WIKKET_3, 4 * IN_MILLISECONDS);
//                    break;
//                case EVENT_WIKKET_3:
//                    DoCast(me, SPELL_FEIGN_DEATH, true);
//                    me->SetUnitFlags2(UNIT_FLAG2_FEIGN_DEATH);
//                    break;
//                case EVENT_WESTFALL:
//                    TextEvent(40000, 2);
//                    break;
//                case EVENT_BEAUTIFUL_BEAST:
//                    TextEvent(42000, 6);
//                    break;
//                case EVENT_END_TALK:
//                    me->GetMotionMaster()->MovePoint(1, -10876.70f, -1779.33f, 90.47f);
//                    break;
//                case EVENT_TELEPORT:
//                    me->NearTeleportTo(-10863.10f, -1782.65f, 90.46f, 1.48f);
//                    instance->SetData(DATA_OPERA_HALL_INTRO, IN_PROGRESS);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_rtk_barnes_encounter_starterAI(creature);
//    }
//};
//
////115022
//class npc_rtk_monkey_king : public CreatureScript
//{
//public:
//    npc_rtk_monkey_king() : CreatureScript("npc_rtk_monkey_king") {}
//
//    struct npc_rtk_monkey_kingAI : public ScriptedAI
//    {
//        npc_rtk_monkey_kingAI(Creature* creature) : ScriptedAI(creature)
//        {
//            instance = me->GetInstanceScript();
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        InstanceScript* instance;
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            DoCast(me, SPELL_SHADOWSTEP, true);
//            events.RescheduleEvent(EVENT_1, 1 * IN_MILLISECONDS);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == EFFECT_MOTION_TYPE)
//            {
//                switch (id)
//                {
//                case 1:
//                    events.RescheduleEvent(EVENT_2, 1 * IN_MILLISECONDS);
//                    events.RescheduleEvent(EVENT_3, 2 * IN_MILLISECONDS);
//                    break;
//                case 2:
//                {
//                    events.RescheduleEvent(EVENT_5, 30 * IN_MILLISECONDS);
//                    break;
//                }
//                case 3:
//                    events.RescheduleEvent(EVENT_6, 2 * IN_MILLISECONDS);
//                    break;
//                }
//            }
//
//            if (type == POINT_MOTION_TYPE)
//            {
//                if (id == 1)
//                    me->DespawnOrUnsummon();
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    me->GetMotionMaster()->MoveJump(-10894.74f, -1778.19f, 90.47f, 20.0f, 10.0f, 1);
//                    break;
//                case EVENT_2:
//                    me->SetFacingTo(4.62f);
//                    break;
//                case EVENT_3:
//                    events.RescheduleEvent(EVENT_4, 2 * IN_MILLISECONDS);
//                    break;
//                case EVENT_4:
//                    me->GetMotionMaster()->MoveJump(-10895.53f, -1785.79f, 92.34f, 10.0f, 10.0f, 2);
//                    break;
//                case EVENT_5:
//                    me->GetMotionMaster()->MoveJump(-10896.03f, -1792.25f, 78.39f, 15.0f, 15.0f, 3);
//                    break;
//                case EVENT_6:
//                    instance->SetData(DATA_OPERA_HALL_INTRO, IN_PROGRESS);
//                    me->GetMotionMaster()->MovePoint(1, -10868.11f, -1793.59f, 78.39f);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_rtk_monkey_kingAI(creature);
//    }
//};
//
//struct boss_opera_encounters : public BossAI
//{
//    boss_opera_encounters(Creature* creature) : BossAI(creature, DATA_OPERA_HALL) {}
//
//    void Reset() override
//    {
//        _Reset();
//    }
//
//    void JustEngagedWith(Unit* who) override
//    {
//        _JustEngagedWith();
//    }
//
//    void EnterEvadeMode(EvadeReason w) 
//    {
//        BossAI::EnterEvadeMode();
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        if (instance->GetData(DATA_OPERA_HALL_SCENE) == DATA_OPERA_HALL_BEAUTIFUL_BEAST)
//        {
//            if (Creature* coggleston = instance->instance->GetCreature(instance->GetGuidData(NPC_COGGLESTON)))
//                coggleston->AI()->DoAction(ACTION_3);
//
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//        }
//        else
//            _JustDied();
//    }
//
//    void DoAction(int32 const action) override
//    {
//        if (action == ACTION_1)
//        {
//            summons.DespawnAll();
//            me->DespawnOrUnsummon(100);
//        }
//
//        // Westfall event
//        if (action == ACTION_2)
//        {
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->SetFaction(WEST_FACTION_AGGRESSIVE);
//            me->SetReactState(REACT_AGGRESSIVE);
//            DoZoneInCombat();
//        }
//    }
//};
//
////114251
//class boss_rtk_galindre : public CreatureScript
//{
//public:
//    boss_rtk_galindre() : CreatureScript("boss_rtk_galindre") {}
//
//    struct boss_rtk_galindreAI : public boss_opera_encounters
//    {
//        boss_rtk_galindreAI(Creature* creature) : boss_opera_encounters(creature) {}
//
//        EventMap events;
//        bool intro = false;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//            events.Reset();
//            DoCast(me, SPELL_WIKKET_BOND, true);
//            DoCast(me, SPELL_SHARED_HEALTH, true);
//
//            if (instance->GetData(DATA_OPERA_HALL_INTRO) != IN_PROGRESS)
//            {
//                me->SetCanFly(true);
//                me->SetReactState(REACT_PASSIVE);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                DoCast(me, SPELL_MAGIC_MAGNIFICENT, true);
//
//                events.RescheduleEvent(EVENT_WIK_GALINDRE_1, 500);
//                events.RescheduleEvent(EVENT_WIK_GALINDRE_2, 12000);
//            }
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            events.RescheduleEvent(EVENT_WIK_GALINDRE_AGGRO_TALK, 3000);
//            events.RescheduleEvent(EVENT_WIK_GALINDRE_FLASHY_BOLT, 1000);
//            events.RescheduleEvent(EVENT_WIK_GALINDRE_WONDROUS_RADIANCE, 8000);
//            events.RescheduleEvent(EVENT_WIK_GALINDRE_MAGIC_MAGNIFICENT, 48000);
//        }
//
//        void EnterEvadeMode(EvadeReason w) 
//        {
//            boss_opera_encounters::EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            boss_opera_encounters::JustDied(NULL);
//        }
//
//        void MovementInform(uint32 type, uint32 id) override
//        {
//            if (type == EFFECT_MOTION_TYPE)
//            {
//                if (id == 1)
//                {
//                    me->SetFacingTo(4.61f);
//                    events.RescheduleEvent(EVENT_WIK_GALINDRE_3, 6000);
//                }
//            }
//        }
//
//        void MagnificentEvent()
//        {
//            me->NearTeleportTo(-10892.7f, -1762.93f, 90.47f, me->GetOrientation());
//
//            if (me && me->IsAlive())
//            {
//                Talk(SAY_MAGNIFICENT);
//                Talk(SAY_MAGNIFICENT_WARN);
//                DoCast(me, SPELL_MAGIC_MAGNIFICENT_IMMUNE, true);
//                DoCast(SPELL_MAGIC_MAGNIFICENT_DMG);
//            }
//
//
//            if (me && me->IsAlive())
//                me->RemoveAurasDueToSpell(SPELL_MAGIC_MAGNIFICENT_IMMUNE);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim() && intro)
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
//                case EVENT_WIK_GALINDRE_1:
//                    DoCast(me, SPELL_NAUGHTY_INTRO_CONVERS, true);
//                    break;
//                case EVENT_WIK_GALINDRE_2:
//                    me->GetMotionMaster()->MoveCharge(-10891.55f, -1761.89f, 90.47f, 20.0f);
//                    break;
//                case EVENT_WIK_GALINDRE_3:
//                    me->SetCanFly(false);
//                    me->RemoveAurasDueToSpell(SPELL_MAGIC_MAGNIFICENT);
//                    events.RescheduleEvent(EVENT_WIK_GALINDRE_4, 10000);
//                    break;
//                case EVENT_WIK_GALINDRE_4:
//                    intro = true;
//                    instance->SetData(DATA_OPERA_HALL_WIKKET, SPECIAL);
//                    break;
//                case EVENT_WIK_GALINDRE_AGGRO_TALK:
//                    Talk(SAY_GALINDRE_AGGRO);
//                    break;
//                case EVENT_WIK_GALINDRE_FLASHY_BOLT:
//                    DoCast(SPELL_FLASHY_BOLT);
//                    events.RescheduleEvent(EVENT_WIK_GALINDRE_FLASHY_BOLT, 4000);
//                    break;
//                case EVENT_WIK_GALINDRE_WONDROUS_RADIANCE:
//                    DoCastVictim(SPELL_WONDROUS_RADIANCE);
//                    events.RescheduleEvent(EVENT_WIK_GALINDRE_WONDROUS_RADIANCE, 10000);
//                    break;
//                case EVENT_WIK_GALINDRE_MAGIC_MAGNIFICENT:
//                    //DoCast(me, 227538, true); //Offlike
//                    MagnificentEvent();
//                    events.RescheduleEvent(EVENT_WIK_GALINDRE_MAGIC_MAGNIFICENT, 48000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_galindreAI(creature);
//    }
//};
//
////114284
//class boss_rtk_elfyra : public CreatureScript
//{
//public:
//    boss_rtk_elfyra() : CreatureScript("boss_rtk_elfyra") {}
//
//    struct boss_rtk_elfyraAI : public boss_opera_encounters
//    {
//        boss_rtk_elfyraAI(Creature* creature) : boss_opera_encounters(creature) {}
//
//        EventMap events;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//            events.Reset();
//            DoCast(me, SPELL_WIKKET_BOND, true);
//            DoCast(me, SPELL_SHARED_HEALTH, true);
//
//            if (instance->GetData(DATA_OPERA_HALL_INTRO) != IN_PROGRESS)
//            {
//                me->SetReactState(REACT_PASSIVE);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//
//                //Summon Vehicle
//                if (Creature* broom = me->SummonCreature(NPC_CRONE_BROOM, me->GetPosition()))
//                {
//                    DoCast(me, SPELL_RIDE_VEH_BROOM, true);
//                    broom->SetCanFly(true);
//                    broom->GetMotionMaster()->MovePath(11448600, false);
//                }
//            }
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//            Talk(SAY_ELFYRA_AGGRO);
//
//            events.RescheduleEvent(EVENT_WIK_ELFYRA_DREARY_BOLT, 4000);
//            events.RescheduleEvent(EVENT_WIK_ELFYRA_SUM_ASSISTANTS, 30000);
//            events.RescheduleEvent(EVENT_WIK_ELFYRA_DEFY_GRAVITY, 11000);
//        }
//
//        void EnterEvadeMode(EvadeReason w)
//        {
//            boss_opera_encounters::EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            boss_opera_encounters::JustDied(NULL);
//            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
//            Talk(SAY_ELFYRA_DEATH);
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_WIK_ELFYRA_DREARY_BOLT:
//                    DoCastVictim(SPELL_DREARY_BOLT);
//                    events.RescheduleEvent(EVENT_WIK_ELFYRA_DREARY_BOLT, 4000);
//                    break;
//                case EVENT_WIK_ELFYRA_SUM_ASSISTANTS:
//                    DoCast(SPELL_SUMMON_ASSISTANTS);
//                    Talk(SAY_ELFYRA_ASSISTANTS);
//                    events.RescheduleEvent(EVENT_WIK_ELFYRA_SUM_ASSISTANTS, 32000);
//                    events.RescheduleEvent(EVENT_WIK_ELFYRA_SUM_ASSISTANTS_2, 1000);
//                    break;
//                case EVENT_WIK_ELFYRA_SUM_ASSISTANTS_2:
//                {
//                    Position pos;
//                    for (uint8 i = 0; i < 3; i++)
//                    {
//                        me->GetRandomNearPosition(frand(5.0f, 10.0f));
//
//                        if (Creature* assistants = me->SummonCreature(NPC_WINGED_ASSISTANT, pos))
//                        {
//                            assistants->CastSpell(assistants, SPELL_MODSCALE, true);
//                            assistants->AI()->DoZoneInCombat(assistants, 60.0f);
//                        }
//                    }
//                    break;
//                }
//                case EVENT_WIK_ELFYRA_DEFY_GRAVITY:
//                    Talk(SAY_ELFYRA_GRAVITY);
//                    DoCast(SPELL_DEFY_GRAVITY);
//                    events.RescheduleEvent(EVENT_WIK_ELFYRA_DEFY_GRAVITY, 19000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_elfyraAI(creature);
//    }
//};
//
////114261
//class boss_rtk_toe_knee : public CreatureScript
//{
//public:
//    boss_rtk_toe_knee() : CreatureScript("boss_rtk_toe_knee") {}
//
//    struct boss_rtk_toe_kneeAI : public boss_opera_encounters
//    {
//        boss_rtk_toe_kneeAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        EventMap events;
//        uint8 limitHealthPct = 51;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//            summons.DoZoneInCombat(NPC_GANG_RUFFIAN);
//
//            Talk(SAY_TOE_AGGRO);
//            RunEvents();
//        }
//
//        void RunEvents()
//        {
//            events.RescheduleEvent(EVENT_TOE_BURNING_LEG_SWEEP, 10000);
//            events.RescheduleEvent(EVENT_TOE_DASHING_FLAME_GALE, 22000);
//        }
//
//        void EnterEvadeMode(EvadeReason w)
//        {
//            boss_opera_encounters::EnterEvadeMode(EVADE_REASON_BOUNDARY);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            summons.DespawnAll();
//            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//
//            Talk(SAY_TOE_DEATH);
//            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
//
//            if (Creature* Mrrgria = instance->instance->GetCreature(instance->GetGuidData(NPC_MRRGRIA)))
//                Mrrgria->AI()->DoAction(ACTION_3);
//        }
//
//        void JustReachedHome() override
//        {
//            if (me->IsInCombat())
//                me->SetStandState(UNIT_STAND_STATE_KNEEL);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_DASHING_FLAME_GALE_FILTER:
//                DoCast(target, SPELL_DASHING_FLAME_GALE_CHARGE, true);
//                break;
//            case SPELL_DASHING_FLAME_GALE_CHARGE:
//                DoCast(target, SPELL_DASHING_FLAME_GALE_AT, true);
//                events.RescheduleEvent(EVENT_TOE_DASHING_FLAME_GALE_CHARGE, 100);
//                break;
//            }
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (me->HealthBelowPct(limitHealthPct))
//            {
//                limitHealthPct = 0;
//                events.Reset();
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//                me->AttackStop();
//                me->GetMotionMaster()->MoveTargetedHome();
//                Talk(SAY_TOE_TIME_OUT);
//
//                EntryCheckPredicate pred(NPC_GANG_RUFFIAN);
//                summons.DoAction(ACTION_1, pred);
//
//                if (Creature* Mrrgria = instance->instance->GetCreature(instance->GetGuidData(NPC_MRRGRIA)))
//                    Mrrgria->AI()->DoAction(ACTION_2);
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            boss_opera_encounters::DoAction(action);
//
//            if (action == ACTION_2)
//            {
//                Talk(SAY_TOE_RETURN_FIGHT);
//                me->SetStandState(UNIT_STAND_STATE_STAND);
//                RunEvents();
//            }
//
//            if (action == ACTION_3)
//            {
//                boss_opera_encounters::JustDied(NULL);
//                me->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_TOE_BURNING_LEG_SWEEP:
//                    DoCast(SPELL_BURNING_LEG_SWEEP);
//                    events.RescheduleEvent(EVENT_TOE_BURNING_LEG_SWEEP, 20000);
//                    break;
//                case EVENT_TOE_DASHING_FLAME_GALE:
//                    Talk(SAY_TOE_FLAME_GALE);
//                    DoCast(SPELL_DASHING_FLAME_GALE);
//                    events.RescheduleEvent(EVENT_TOE_DASHING_FLAME_GALE, 30000);
//                    events.RescheduleEvent(EVENT_TOE_DASHING_FLAME_GALE_CHARGE, 100);
//                    break;
//                case EVENT_TOE_DASHING_FLAME_GALE_CHARGE:
//                    DoCast(SPELL_DASHING_FLAME_GALE_FILTER);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_toe_kneeAI(creature);
//    }
//};
//
////114260
//class boss_rtk_mrrgria : public CreatureScript
//{
//public:
//    boss_rtk_mrrgria() : CreatureScript("boss_rtk_mrrgria") {}
//
//    struct boss_rtk_mrrgriaAI : public boss_opera_encounters
//    {
//        boss_rtk_mrrgriaAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        EventMap events;
//        bool surrend = false;
//        uint8 limitHealthPct = 51;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//
//            for (uint8 i = 22; i < 33; i++)
//                me->SummonCreature(NPC_WASH_AWAY, operaSpawnPos[i]);
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            EntryCheckPredicate pred(NPC_SHORELINE_TIDESPEAKER);
//            summons.DoAction(ACTION_2, pred); //Go Fight
//
//            events.RescheduleEvent(EVENT_MRRG_THUNDER_RITUAL, 8000);
//            events.RescheduleEvent(EVENT_MRRG_WASH_AWAY, 16000);
//        }
//
//        void EnterEvadeMode(EvadeReason w)
//        {
//            boss_opera_encounters::EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
//        }
//
//        void JustDied(Unit* /*killer*/) override {}
//
//        void DoAction(int32 const action) override
//        {
//            boss_opera_encounters::DoAction(action);
//
//            if (action == ACTION_3 && surrend)
//            {
//                if (Creature* Toe = instance->instance->GetCreature(instance->GetGuidData(NPC_TOE_KNEE)))
//                {
//                    Toe->SetDynamicFlags(UNIT_DYNFLAG_LOOTABLE);
//                    boss_opera_encounters::JustDied(NULL);
//                }
//
//                me->RemoveAurasDueToSpell(SPELL_STUN);
//                summons.DespawnAll();
//                me->DespawnOrUnsummon(500);
//            }
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (me->HealthBelowPct(limitHealthPct))
//            {
//                limitHealthPct = 0;
//
//                if (Creature* Toe = instance->instance->GetCreature(instance->GetGuidData(NPC_TOE_KNEE)))
//                    Toe->AI()->DoAction(ACTION_2);
//            }
//
//            if (damage >= me->GetHealth())
//            {
//                damage = 0;
//
//                if (!surrend)
//                {
//                    surrend = true;
//                    events.Reset();
//                    me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);                    
//                    me->AttackStop();
//                    DoCast(me, SPELL_STUN, true);
//                    EntryCheckPredicate pred(NPC_SHORELINE_TIDESPEAKER);
//                    summons.DoAction(ACTION_1, pred); //GoHome
//
//                    if (Creature* Toe = instance->instance->GetCreature(instance->GetGuidData(NPC_TOE_KNEE)))
//                    {
//                        if (Toe && !Toe->IsAlive())
//                        {
//                            Toe->AI()->DoAction(ACTION_3);
//                            me->RemoveAurasDueToSpell(SPELL_STUN);
//                            summons.DespawnAll();
//                            me->DespawnOrUnsummon(500);
//                        }
//                    }
//                }
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_WASH_AWAY_FILTER:
//                target->CastSpell(target, SPELL_WASH_AWAY_AT, true, nullptr, nullptr, me->GetGUID());
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_MRRG_THUNDER_RITUAL:
//                    DoCast(SPELL_THUNDER_RITUAL);
//                    events.RescheduleEvent(EVENT_MRRG_THUNDER_RITUAL, 18000);
//                    break;
//                case EVENT_MRRG_WASH_AWAY:
//                    DoCast(SPELL_WASH_AWAY_FILTER);
//                    events.RescheduleEvent(EVENT_MRRG_WASH_AWAY, 23000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_mrrgriaAI(creature);
//    }
//};
//
////114328
//class boss_rtk_coggleston : public CreatureScript
//{
//public:
//    boss_rtk_coggleston() : CreatureScript("boss_rtk_coggleston") {}
//
//    struct boss_rtk_cogglestonAI : public boss_opera_encounters
//    {
//        boss_rtk_cogglestonAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        EventMap events;
//        uint8 diedCountBB;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//            diedCountBB = 0;
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            DoCast(me, SPELL_SPECTRAL_SERVICE, true);
//            Talk(SAY_COGGLESTON_AGGRO);
//
//            /*if (Creature* bella = me->FindNearestCreature(NPC_BELLA, 50.0f, true))
//            {
//                if (Creature* brute = me->FindNearestCreature(NPC_BRUTE, 50.0f, true))
//                {
//                    bella->AddDelayedEvent(1000, [bella]() -> void
//                    {
//                        bella->AI()->Talk(0);
//                    });
//
//                    brute->AddDelayedEvent(6000, [brute]() -> void
//                    {
//                        brute->AI()->Talk(0);
//                    });
//
//                    bella->AddDelayedEvent(12000, [bella]() -> void
//                    {
//                        bella->AI()->Talk(1);
//                    });
//
//                    brute->AddDelayedEvent(16000, [brute]() -> void // ??????? ? ??????!
//                    {
//                        brute->AI()->Talk(1);
//                    });
//                }
//            }*/
//        }
//
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            _JustDied();
//            Talk(SAY_COGGLESTON_DEATH);
//            /*if (Creature* bella = me->FindNearestCreature(NPC_BELLA, 50.0f, true))
//            {
//                if (Creature* brute = me->FindNearestCreature(NPC_BRUTE, 50.0f, true))
//                {
//                    brute->AddDelayedEvent(2000, [brute]() -> void
//                    {
//                        brute->AI()->Talk(4);
//                    });
//
//                    bella->AddDelayedEvent(6000, [bella]() -> void
//                    {
//                        bella->AI()->Talk(5);
//                    });
//
//                    brute->AddDelayedEvent(14000, [brute]() -> void
//                    {
//                        brute->AI()->Talk(5);
//                    });
//
//                    bella->AddDelayedEvent(19000, [bella, brute]() -> void
//                    {
//                        bella->AI()->Talk(6);
//                        brute->UpdateEntry(NPC_ADEM);
//                    });
//
//                    brute->AddDelayedEvent(25000, [brute]() -> void
//                    {
//                        brute->AI()->Talk(6);
//                    });
//
//                    bella->AddDelayedEvent(30000, [bella]() -> void
//                    {
//                        bella->AI()->Talk(7);
//                    });
//                }
//            }*/
//        }
//
//        void DoAction(int32 const action) override
//        {
//            boss_opera_encounters::DoAction(action);
//
//            if (action == ACTION_3)
//            {
//                uint32 bossId[4] = { NPC_COGGLESTON, NPC_LUMINORE, NPC_BABBLET, NPC_CAULDRONS };
//
//                for (uint8 i = 0; i < 4; i++)
//                {
//                    if (Creature* boss = instance->instance->GetCreature(instance->GetGuidData(bossId[i])))
//                        if (boss->IsAlive())
//                            boss->CastSpell(boss, SPELL_EMINENCE, true);
//                }
//
//                if (diedCountBB == 1)
//                {
//                    if (Creature* bella = me->FindNearestCreature(NPC_BELLA, 50.0f, true))
//                    {
//                        /* (Creature* brute = me->FindNearestCreature(NPC_BRUTE, 50.0f, true))
//                        {
//
//                            bella->AddDelayedEvent(1000, [bella]() -> void
//                            {
//                                bella->AI()->Talk(2);
//                            });
//
//                            brute->AddDelayedEvent(6000, [brute]() -> void
//                            {
//                                brute->AI()->Talk(2);
//                            });
//
//                            bella->AddDelayedEvent(12000, [bella]() -> void
//                            {
//                                bella->AI()->Talk(3);
//                            });
//
//                            brute->AddDelayedEvent(16000, [brute]() -> void
//                            {
//                                brute->AI()->Talk(3);
//                            });
//
//                            bella->AddDelayedEvent(20000, [bella]() -> void
//                            {
//                                bella->AI()->Talk(4);
//                            });
//                        }*/
//                    }
//                }
//
//                if (diedCountBB == 2)
//                {
//                    if (Creature* coggleston = instance->instance->GetCreature(instance->GetGuidData(NPC_COGGLESTON)))
//                    {
//                        coggleston->RemoveAurasDueToSpell(SPELL_SPECTRAL_SERVICE);
//
//                        events.RescheduleEvent(EVENT_COGGLESTON_DENT_ARMOR, 9000);
//                        events.RescheduleEvent(EVENT_SUMMON_HELPERS, 2000);
//                        events.RescheduleEvent(EVENT_DINNER_BELL, 12000);
//                    }
//                }
//                diedCountBB++;
//            }
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            if (spell->Id == SPELL_KARA_KAZHAM)
//                Talk(SAY_COGGLESTON_SUMMON);
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
//                case EVENT_COGGLESTON_DENT_ARMOR:
//                    DoCastVictim(SPELL_DENT_ARMOR);
//                    events.RescheduleEvent(EVENT_COGGLESTON_DENT_ARMOR, 9000);
//                    break;
//                case EVENT_SUMMON_HELPERS:
//                    DoCast(SPELL_KARA_KAZHAM);
//                    events.RescheduleEvent(EVENT_SUMMON_HELPERS, 20000);
//                    break;
//                case EVENT_DINNER_BELL:
//                    DoCast(SPELL_DINNER_BELL);
//                    events.RescheduleEvent(EVENT_DINNER_BELL, 20000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_cogglestonAI(creature);
//    }
//};
//
////114329
//class boss_rtk_luminore : public CreatureScript
//{
//public:
//    boss_rtk_luminore() : CreatureScript("boss_rtk_luminore") {}
//
//    struct boss_rtk_luminoreAI : public boss_opera_encounters
//    {
//        boss_rtk_luminoreAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        EventMap events;
//        uint8 castCount = 0;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//
//            DoCast(me, SPELL_CANDLE_HAT, true);
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            events.RescheduleEvent(EVENT_LUMINORE_BURNING_BLAZE, 2000);
//            events.RescheduleEvent(EVENT_LUMINORE_HEAT_WAVE, 30000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            boss_opera_encounters::JustDied(NULL);
//            Talk(SAY_LUMINORE_DEATH);
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
//                case EVENT_LUMINORE_BURNING_BLAZE:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                        DoCast(target, SPELL_BURNING_BLAZE, false);
//                    castCount++;
//                    if (castCount > 2)
//                    {
//                        castCount = 0;
//                        events.RescheduleEvent(EVENT_LUMINORE_BURNING_BLAZE, 9000);
//                    }
//                    else
//                        events.RescheduleEvent(EVENT_LUMINORE_BURNING_BLAZE, 3000);
//                    break;
//                case EVENT_LUMINORE_HEAT_WAVE:
//                    if (urand(0, 1))
//                        Talk(SAY_LUMINORE_HEAT_WAVE);
//                    DoCast(SPELL_HEAT_WAVE);
//                    events.RescheduleEvent(EVENT_LUMINORE_HEAT_WAVE, 30000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_luminoreAI(creature);
//    }
//};
//
////114330
//class boss_rtk_babblet : public CreatureScript
//{
//public:
//    boss_rtk_babblet() : CreatureScript("boss_rtk_babblet") {}
//
//    struct boss_rtk_babbletAI : public boss_opera_encounters
//    {
//        boss_rtk_babbletAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//        ObjectGuid playerGUID;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//
//            DoCast(me, SPELL_MAID_ATTIRE, true);
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            DoCast(me, SPELL_SEVERE_DUSTING, true);
//
//            events.RescheduleEvent(EVENT_BABBLET_FIXATE, 1000);
//        }
//
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            boss_opera_encounters::JustDied(NULL);
//            Talk(SAY_BABBLET_DEATH);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_BABBLET_FIXATE:
//                    playerGUID.Clear();
//                    me->StopMoving();
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true, -SPELL_FIXATE))
//                    {
//                        playerGUID = target->GetGUID();
//                        DoCast(target, SPELL_FIXATE, true);
//                        if (urand(0, 1))
//                            Talk(SAY_BABBLET_FIXATE);
//                    }
//                    events.RescheduleEvent(EVENT_BABBLET_FIXATE, 11000);
//                    events.RescheduleEvent(EVENT_BABBLET_FOLLOW_TARGET, 1000);
//                    break;
//                case EVENT_BABBLET_FOLLOW_TARGET:
//                    if (Unit* pTarget = ObjectAccessor::GetUnit(*me, playerGUID))
//                    {
//                        if (!pTarget || !pTarget->IsAlive())
//                        {
//                            events.RescheduleEvent(EVENT_BABBLET_FIXATE, 1000);
//                            break;
//                        }
//                        else
//                            me->GetMotionMaster()->MovePoint(1, pTarget->GetPosition());
//                    }
//                    events.RescheduleEvent(EVENT_BABBLET_FOLLOW_TARGET, 500);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_babbletAI(creature);
//    }
//};
//
////114522
//class boss_rtk_cauldrons : public CreatureScript
//{
//public:
//    boss_rtk_cauldrons() : CreatureScript("boss_rtk_cauldrons") {}
//
//    struct boss_rtk_cauldronsAI : public boss_opera_encounters
//    {
//        boss_rtk_cauldronsAI(Creature* creature) : boss_opera_encounters(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//        }
//
//        EventMap events;
//
//        void Reset() override
//        {
//            boss_opera_encounters::Reset();
//
//            DoCast(me, SPELL_CAULDRON_DRESSING, true);
//        }
//
//        void JustEngagedWith(Unit* who) override
//        {
//            boss_opera_encounters::JustEngagedWith(who);
//
//            events.RescheduleEvent(EVENT_CAULDRON_SOUP_SPRAY, 1000);
//            events.RescheduleEvent(EVENT_CAULDRON_LEFTOVERS, 8000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            boss_opera_encounters::JustDied(NULL);
//            Talk(SAY_CAULDRONS_DEATH);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_SOUP_SPRAY)
//                DoCast(target, SPELL_DRENCHED, true);
//        }
//
//        void SpellFinishCast(const SpellInfo* spell)
//        {
//            if (spell->Id == SPELL_LEFTOVERS)
//            {
//                for (uint8 i = 0; i < 20; i++)
//                    DoCast(me, SPELL_LEFTOVERS_VISUAL, true);
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
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_CAULDRON_SOUP_SPRAY:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                        DoCast(target, SPELL_SOUP_SPRAY, false);
//                    events.RescheduleEvent(EVENT_CAULDRON_SOUP_SPRAY, 3000);
//                    break;
//                case EVENT_CAULDRON_LEFTOVERS:
//                    if (urand(0, 1))
//                        Talk(SAY_CAULDRONS_LEFTOVERS);
//                    DoCast(SPELL_LEFTOVERS);
//                    events.RescheduleEvent(EVENT_CAULDRON_LEFTOVERS, 18000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_rtk_cauldronsAI(creature);
//    }
//};
//
////114265, 114266
//class npc_rtk_west_generic_trash : public CreatureScript
//{
//public:
//    npc_rtk_west_generic_trash() : CreatureScript("npc_rtk_west_generic_trash") {}
//
//    struct npc_rtk_west_generic_trashAI : public ScriptedAI
//    {
//        npc_rtk_west_generic_trashAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_DEFENSIVE);
//
//            if (me->GetEntry() == NPC_SHORELINE_TIDESPEAKER)
//                SetCombatMovement(false);
//        }
//
//        EventMap events;
//        bool surrend = false;
//
//        void Reset() override {}
//
//        void JustEngagedWith(Unit* who) override
//        {
//            if (me->GetEntry() == NPC_GANG_RUFFIAN)
//                events.RescheduleEvent(EVENT_1, urand(5, 8) * IN_MILLISECONDS);
//            else if (me->GetEntry() == NPC_SHORELINE_TIDESPEAKER)
//                events.RescheduleEvent(EVENT_2, 5 * IN_MILLISECONDS);
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_POISONOUS_SHANK_FILTER:
//                DoCast(target, SPELL_POISONOUS_SHANK_TP, true);
//                DoCast(target, SPELL_POISONOUS_SHANK_DMG, true);
//                break;
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_1)
//            {
//                if (!surrend)
//                    GoHome();
//            }
//            else if (action == ACTION_2)
//            {
//                if (me->GetEntry() == NPC_SHORELINE_TIDESPEAKER)
//                {
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                    me->SetFaction(WEST_FACTION_AGGRESSIVE);
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    DoZoneInCombat(me, 60.0f);
//                }
//            }
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (damage >= me->GetHealth())
//            {
//                damage = 0;
//
//                if (!surrend)
//                    GoHome();
//            }
//        }
//
//        void GoHome()
//        {
//            surrend = true;
//            events.Reset();
//            me->AttackStop();
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->GetMotionMaster()->MoveTargetedHome();
//        }
//
//        void JustReachedHome() override
//        {
//            if (me->GetEntry() == NPC_GANG_RUFFIAN)
//                me->SetFaction(WEST_FACTION_NEUTRAL_GANGSTERS);
//            else
//                me->SetFaction(WEST_FACTION_NEUTRAL_MURLOCS);
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
//                    DoCast(SPELL_POISONOUS_SHANK_FILTER);
//                    events.RescheduleEvent(EVENT_1, 10 * IN_MILLISECONDS);
//                    break;
//                case EVENT_2:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
//                    {
//                       // DoResetThreat();
//                        //me->AddThreat(target, 10000.0f);
//                        me->SetFacingToObject(target);
//                        DoCast(target, SPELL_BUBBLE_BLAST, true);
//                    }
//                    events.RescheduleEvent(EVENT_2, 5 * IN_MILLISECONDS);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_rtk_west_generic_trashAI(creature);
//    }
//};
//
//void AddSC_npc_kara_barnes_new()
//{
//    new npc_rtk_barnes_encounter_starter();
//    new npc_rtk_monkey_king();
//    new boss_rtk_galindre();
//    new boss_rtk_elfyra();
//    new boss_rtk_toe_knee();
//    new boss_rtk_mrrgria();
//    new boss_rtk_coggleston();
//    new boss_rtk_luminore();
//    new boss_rtk_babblet();
//    new boss_rtk_cauldrons();
//    new npc_rtk_west_generic_trash();
//}
