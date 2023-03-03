//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "AchievementMgr.h"
//
//enum Achievements
//{
//    ACHIEVEMENT_RETURN_TO_SENDER = 6485,
//};
//enum Spells
//{
//    // Boss General Pa'valak spells - PLATFORMS
//    FORCE_AND_VERVE = 122713, // working, don't fix, please give me tities
//    CONVERT = 122740, // Player can't cast spells, but they can still freely move, and they don't all go fucking mental which they should.
//    ATTENUATION = 122440,
//
//    // Normal abilities
//    EXHALE = 122761,
//    AURA_EXHALE = 122760,
//    INHALE = 122852,
//
//    // last phase
//    INHALE_ZEAL = 124018,
//    SPELL_BERSERK = 47008,
//
//    // SMOKE
//    SMOKE_DOT = 123812,
//    SMOKE_VISUAL = 123811,
//
//    // Srathik Shield Master
//    MASS_SPELL_REFLECT = 124817,
//    SHIELD_SLAM = 124815,
//    SUNDER_ARMOR = 123417,
//
//};
//enum Mobs
//{
//    TRIGGER_SMOKE = 5436354,
//    ramp_1_trigger_id = 756775,
//    ramp_2_trigger_id = 756776,
//    ramp_3_trigger_id = 756777,
//    NOISE_CANCELING_TRIGGER = 756778,
//
//    TRIGGER_RP_AFTER_DEATH = 4365831,
//
//    // Heroic Adds
//    NPC_ECHO_OF_ATTENUATION = 65173,
//    NPC_ECHO_OF_FORCE_AND_VERVE = 65174,
//};
//enum Events
//{
//    // Encounter Events // RAMP1
//    EVENT_INHALE = 10,
//    EVENT_EXHALE = 11,
//    EVENT_ATTENUATION = 12,
//
//    // RAMP2
//    EVENT_FORCE_AND_VERSE = 13,
//    EVENT_NOISE_CANCELING = 14,
//
//    // RAMP 4
//    EVENT_CONVERT = 15,
//
//    // Phase 2
//    EVENT_ZEAL = 16,
//    EVENT_AFTER_ZEAL = 17,
//
//    SCHEDULE_RAMP_CHANGE = 18,
//
//    EVENT_BERSERK = 19,
//
//    EVENT_PULL_RAID = 20,
//};
//enum Objects
//{
//    GOB_ARENA_WALLS = 212916,
//    GOB_FINAL_PHASE_WALLS = 212943,
//};
//
///*
//BOSS SPELLS
//-----------
//
//INHALE = MAX 3 STACKS, 3 = + 400% DAMAGE
//EXHALE = 400 + JUDGING BY INHALSE STUCKS
//
//BOSS CASTS DIFFERNET SPELLS ON DIFFERENT PLATFORM + triggers inovlved to define each platform:
//BOSS CAHNGE PLATFORM EVERY 20% THAT HE LOSES / not accurate
//
//
//BOSS NOTIFCATION WHEN CHANGING PLATFORM: "Imperial Vizier Zor'lok flies to one of his platforms!"
//
//platform 1:
//ATTENUATION
//platform 2:
//FORCE AND VERVE
//NOISE CANCELING ZONES = MAX 4 PEOPLE IN GRID
//platform 3:
//CONVENT  = "Imperial Vizier Zor'lok uses his voice to Convent members of the raid to fight on his side" // infromation - only debuffs when player gets below 50%
//
//
//40% third phase
//
//notifcation: "Imperial Vizier Zor'lok inhales the Phermones of Zeal!"
//SPELL NAME: Phermones of Zeal
//
//WEAPON NAME FOR Trash
//amber flammard of klaxxi'vess
//
//He casts all the platform spells at once: order is  CONVENT, ATTENUTAION, FORCE AND VERVE
//*/
//
//
//Position const Ramp_Pos1 = { -2236.312744f, 217.689651f, 2.556486f };
//Position const Ramp_Pos2 = { -2317.847900f, 299.153625f, 409.896881f };
//Position const Ramp_Pos3 = { -2315.115967f, 218.375854f, 409.897125f };
//
//
//Position finalPhaseWalls1[3] =
//{
//    { -2299.195f, 282.5938f, 408.5445f, 2.383867f },
//    { -2250.401f, 234.0122f, 408.5445f, 2.333440f },
//    { -2299.63f, 233.3889f, 408.5445f, 0.7598741f }
//};
//Position finalPhaseWalls2[3] =
//{
//    { -2255.168f, 308.7326f, 406.0f, 0.7853968f },
//    { -2240.0f, 294.0f, 406.0f, 0.7853968f },
//    { -2225.753f, 280.1424f, 406.381f, 0.7853968f },
//};
//
//
//class boss_imperial_zorlok : public CreatureScript
//{
//public:
//    boss_imperial_zorlok() : CreatureScript("boss_imperial_zorlok") { }
//
//    struct boss_imperial_zorlokAI : public BossAI
//    {
//        boss_imperial_zorlokAI(Creature* creature) : BossAI(creature, 0)
//        {
//            me->SetLevel(93);
//            me->setFaction(16);
//            me->SetSpeed(MOVE_RUN, 3.5f, true);
//            me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
//
//            /*
//            if (IsHeroic() && Is25ManRaid())
//            {
//            me->SetMaxHealth(588784960);
//            me->SetHealth(588784960);
//            }
//            else if (Is25ManRaid())
//            {
//            me->SetMaxHealth(392523296);
//            me->SetHealth(392523296);
//            }
//            else if (IsHeroic())
//            {
//            me->SetMaxHealth(218067496);
//            me->SetHealth(218067496);
//            }
//            else
//            {
//            me->SetMaxHealth(174454800);
//            me->SetHealth(174454800);
//            }
//            */
//        }
//        InstanceScript* instance;
//
//        bool phase1;
//        bool phase2;
//        bool phase3;
//
//        bool Ramp_1;
//        bool Ramp_2;
//        bool Ramp_3;
//
//        bool SrathikEvent1;
//        bool SrathikEvent2;
//        bool SrathikEvent3;
//
//        bool found;
//
//        bool cdramp1;
//        bool cdramp2;
//        bool cdramp3;
//
//        void Reset()
//        {
//            _Reset();
//
//            // phases
//            phase1 = false;
//            phase2 = false;
//            phase3 = false;
//
//            // waypoints
//            Ramp_1 = false;
//            Ramp_2 = false;
//            Ramp_3 = false;
//
//            // Srathik Combat RP 
//            SrathikEvent1 = false;
//            SrathikEvent2 = false;
//            SrathikEvent3 = false;
//
//            // Auras
//            found = false;
//
//            // cd
//
//            cdramp1 = false;
//            cdramp2 = false;
//            cdramp3 = false;
//        }
//        void EnterCombat(Unit* who)
//        {
//            _EnterCombat();
//
//            // Set new home position
//            me->SetHomePosition(-2291.480957f, 243.480286f, 422.678986f, 0.753832f);
//
//            // Summon Smoke Trigger
//            if (!me->FindNearestCreature(TRIGGER_SMOKE, 100.0f, true))
//            {
//                me->SummonCreature(TRIGGER_SMOKE, -2275.247803f, 258.361877f, 406.381500f, 0.737245f, TEMPSUMMON_DEAD_DESPAWN, 0);
//            }
//
//            // Summon Ramp Change Triggers
//            if (!me->FindNearestCreature(ramp_1_trigger_id, 100.0f, true))
//            {
//                me->SummonCreature(ramp_1_trigger_id, -2232.568750f, 219.450623f, 409.897034f);
//            }
//            if (!me->FindNearestCreature(ramp_2_trigger_id, 100.0f, true))
//            {
//                me->SummonCreature(ramp_2_trigger_id, 2319.402832f, 300.782257f, 309.896942f);
//            }
//            if (!me->FindNearestCreature(ramp_3_trigger_id, 100.0f, true))
//            {
//                me->SummonCreature(ramp_3_trigger_id, -2315.075928f, 218.192123f, 409.896912f);
//            }
//
//            // Ramp Change
//            RampChange(true);
//
//            events.CancelEvent(EVENT_BERSERK);
//            // 10 minutes enrage timer
//            events.ScheduleEvent(EVENT_BERSERK, 600000);
//
//            // Say AGGRO
//            me->MonsterYell("The divine choose us to give mortal voice to her divine will. We are but the vessel that enhance her will.", LANG_UNIVERSAL, me->GetGUID());
//            //DoPlaySoundToSet(me, 29301);
//        }
//        void JustReachedHome()
//        {
//            std::list<Player*> PL_list;
//
//            JadeCore::AnyPlayerInObjectRangeCheck check(me, 50.0f);
//            JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//            me->VisitNearbyObject(50.0f, searcher);
//
//            for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//            {
//                if (!(*it))
//                    return;
//
//                (*it)->RemoveAura(CONVERT);
//
//                if ((*it)->GetTeam() == TEAM_HORDE)
//                {
//                    (*it)->setFaction(2);
//                }
//                else
//                {
//                    (*it)->setFaction(1);
//                }
//            }
//
//            //instance->SetBossState(DATA_PAVALAK, FAIL);
//            if (MotionMaster* motion = me->GetMotionMaster())
//            {
//                motion->Clear(true);
//                motion->MovePoint(1, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
//            }
//
//            if (Creature* smoke = me->FindNearestCreature(TRIGGER_SMOKE, 100.0f, true))
//            {
//                smoke->DespawnOrUnsummon(500);
//            }
//            summons.DespawnAll();
//        }
//        void DamageTaken(Unit* attacker, uint32& damage)
//        {
//            if (!me->HealthAbovePct(85) && !cdramp1) // ramps changes
//            {
//                cdramp1 = true;
//                PreFlight();
//            }
//            if (!me->HealthAbovePct(60) && !cdramp2)
//            {
//                cdramp2 = true;
//                PreFlight();
//            }
//            if (!me->HealthAbovePct(40) && !cdramp3)
//            {
//                CenterChange();
//                cdramp3 = true;
//            }
//        }
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//
//            if (!UpdateVictim())
//                return;
//            // Introduction RP	
//
//            if (found) // height bug check
//            {
//                if (Creature* ramp_1 = me->FindNearestCreature(ramp_1_trigger_id, 10.0f, true))
//                {
//                    if (MotionMaster* motion = me->GetMotionMaster())
//                    {
//                        motion->MovePoint(1, ramp_1->GetPositionX(), ramp_1->GetPositionY(), ramp_1->GetPositionZ());
//                        found = false;
//                    }
//                }
//                else if (Creature* ramp_2 = me->FindNearestCreature(ramp_2_trigger_id, 10.0f, true))
//                {
//                    if (MotionMaster* motion = me->GetMotionMaster())
//                    {
//                        motion->MovePoint(1, ramp_2->GetPositionX(), ramp_2->GetPositionY(), ramp_2->GetPositionZ());
//                        found = false;
//                    }
//                }
//                else if (Creature* ramp_3 = me->FindNearestCreature(ramp_3_trigger_id, 10.0f, true))
//                {
//                    if (MotionMaster* motion = me->GetMotionMaster())
//                    {
//                        motion->MovePoint(1, ramp_3->GetPositionX(), ramp_3->GetPositionY(), ramp_3->GetPositionZ());
//                        found = false;
//                    }
//                }
//            }
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                    // default
//                case SCHEDULE_RAMP_CHANGE:
//                    RampChange(true);
//                    break;
//                case EVENT_INHALE:
//                    if (!me->HasAura(INHALE))
//                    {
//                        me->CastSpell(me, INHALE);
//                        // Say Inhale
//                        me->MonsterYell("Through the air we breathe.. she strengthqen our voice!", LANG_UNIVERSAL, me->GetGUID());
//                        DoPlaySoundToSet(me, 29321);
//                    }
//                    else
//                    {
//                        AuraPtr aura_B = me->GetAura(INHALE);
//
//                        if (aura_B && aura_B->GetStackAmount() <= 2)
//                        {
//                            // Say Inhale
//                            me->MonsterYell("Through the air we breathe.. she strengthqen our voice!", LANG_UNIVERSAL, me->GetGUID());
//                            DoPlaySoundToSet(me, 29321);
//                            aura_B->SetStackAmount(aura_B->GetStackAmount() + 1);
//                        }
//                    }
//                    events.ScheduleEvent(EVENT_INHALE, urand(5000, 10000));
//                    break;
//                case EVENT_EXHALE:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//                    {
//                        // Say Exhale
//                        me->MonsterYell("Behold the voice of her divine wrath.", LANG_UNIVERSAL, me->GetGUID());
//                        DoPlaySoundToSet(me, 29320);
//
//                        me->CastSpell(target, EXHALE);
//                        events.ScheduleEvent(EVENT_EXHALE, urand(12000, 15000));
//                    }
//                    break;
//                    // RAMP 1 Attenuation
//                case EVENT_ATTENUATION:
//                    events.CancelEvent(EVENT_EXHALE);
//                    events.CancelEvent(EVENT_INHALE);
//
//                    me->CastSpell(me, ATTENUATION);
//                    events.ScheduleEvent(EVENT_ATTENUATION, urand(18000, 24000));
//                    events.ScheduleEvent(EVENT_INHALE, urand(12000, 12000));
//                    events.ScheduleEvent(EVENT_EXHALE, urand(20000, 20000));
//                    break;
//                    // RAMP 2 - noise and verse, noise cancelling
//                case EVENT_FORCE_AND_VERSE:
//                    events.CancelEvent(EVENT_EXHALE);
//                    events.CancelEvent(EVENT_INHALE);
//
//                    events.ScheduleEvent(EVENT_INHALE, urand(12000, 12000));
//                    events.ScheduleEvent(EVENT_EXHALE, urand(20000, 20000));
//
//                    me->CastSpell(me, FORCE_AND_VERVE);
//
//                    events.ScheduleEvent(EVENT_NOISE_CANCELING, 500);
//                    events.ScheduleEvent(EVENT_FORCE_AND_VERSE, 38000);
//                    break;
//                case EVENT_NOISE_CANCELING:
//                {
//                    Position Pos;
//                    Position Pos2;
//                    Position Pos3;
//                    me->GetRandomNearPosition(Pos, frand(3.0f, 10.0f));
//                    me->GetRandomNearPosition(Pos2, frand(3.0f, 10.0f));
//                    me->GetRandomNearPosition(Pos3, frand(3.0f, 10.0f));
//
//                    Creature* V_1 = me->SummonCreature(NOISE_CANCELING_TRIGGER, Pos, TEMPSUMMON_TIMED_DESPAWN, 12000);
//                    Creature* V_2 = me->SummonCreature(NOISE_CANCELING_TRIGGER, Pos2, TEMPSUMMON_TIMED_DESPAWN, 12000);
//                    Creature* V_3 = me->SummonCreature(NOISE_CANCELING_TRIGGER, Pos3, TEMPSUMMON_TIMED_DESPAWN, 12000);
//
//                    if (V_3 && V_2 && V_1)
//                    {
//                        me->CastSpell(V_1, 122731);
//                        me->CastSpell(V_2, 122731);
//                        me->CastSpell(V_3, 122731);
//                    }
//                }
//                    break;
//                case EVENT_BERSERK:
//                {
//                    me->CastSpell(me, SPELL_BERSERK, false);
//                    break;
//                }
//                    // RAMP 3 - 
//                case EVENT_CONVERT:
//                    if (!Is25ManRaid())
//                    {
//                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//                        {
//                            me->CastSpell(target, CONVERT);
//
//                            // Say Convert
//                            me->MonsterYell("Her will is greater then us all! You'll join us or you'll perish.", LANG_UNIVERSAL, me->GetGUID());
//                            DoPlaySoundToSet(me, 29322);
//
//                            events.ScheduleEvent(EVENT_CONVERT, urand(28000, 30000));
//                        }
//                    }
//                    else // 25 man difficulty 2 converts
//                    {
//                        me->MonsterYell("Her will is greater then us all! You'll join us or you'll perish.", LANG_UNIVERSAL, me->GetGUID());
//
//                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//                        {
//                            if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//                            {
//                                me->CastSpell(target, CONVERT);
//                                me->AddAura(CONVERT, target2);
//                                // Say Convert
//
//                                DoPlaySoundToSet(me, 29322);
//
//                                events.ScheduleEvent(EVENT_CONVERT, urand(28000, 30000));
//                            }
//                        }
//                    }
//                    break;
//
//                case EVENT_ZEAL:
//                    me->CastSpell(me, INHALE_ZEAL);
//                    events.ScheduleEvent(EVENT_AFTER_ZEAL, 4500);
//                    break;
//                case EVENT_AFTER_ZEAL:
//                    // say something
//
//                    // move
//                    if (MotionMaster* motion = me->GetMotionMaster())
//                    {
//                        motion->MovePoint(2, -2275.526f, 258.157928f, 406.381165f);
//                    }
//                    // remove unattackable flags
//                    me->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//                    me->SetReactState(REACT_DEFENSIVE);
//
//                    // Start All Events
//                    LastPhase();
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//        void JustDied(Unit* killer)
//        {
//            std::list<Player*> PL_list;
//
//            JadeCore::AnyPlayerInObjectRangeCheck check(me, 50.0f);
//            JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//            me->VisitNearbyObject(50.0f, searcher);
//
//            for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//            {
//                if (!(*it))
//                    return;
//
//                (*it)->RemoveAura(CONVERT);
//
//                if ((*it)->GetTeam() == TEAM_HORDE)
//                {
//                    (*it)->setFaction(2);
//                }
//                else
//                {
//                    (*it)->setFaction(1);
//                }
//            }
//
//            _JustDied();
//
//            me->MonsterYell("We will not given to the despair of the dark void, if her will to us is to perish - then it shall be so.", LANG_UNIVERSAL, me->GetGUID());
//            DoPlaySoundToSet(me, 29302);
//
//            me->SummonCreature(TRIGGER_RP_AFTER_DEATH, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
//        }
//        void KilledUnit(Unit* victim)
//        {
//            if (me->getVictim())
//            {
//                AttackStart(me->getVictim());                           // Start attack the victim (random?)
//                me->SetReactState(REACT_AGGRESSIVE);
//            }
//
//            if (victim->GetTypeId() == TYPEID_PLAYER)
//            {
//                switch (urand(0, 1))
//                {
//                case 0:
//                    me->MonsterYell("The divine will not suffer your tentear of a fighter!", LANG_UNIVERSAL, me->GetGUID());
//                    DoPlaySoundToSet(me, 29318);
//                    break;
//                case 1:
//                    me->MonsterYell("Ours is but to server, yours is but to die", LANG_UNIVERSAL, me->GetGUID());
//                    DoPlaySoundToSet(me, 29319);
//                    break;
//                }
//            }
//        }
//        void RampChange(bool message)
//        {
//            Creature* ramp_1_trigger = me->FindNearestCreature(ramp_1_trigger_id, 5, true);
//            Creature* ramp_2_trigger = me->FindNearestCreature(ramp_2_trigger_id, 5, true);
//            Creature* ramp_3_trigger = me->FindNearestCreature(ramp_3_trigger_id, 5, true);
//
//            MotionMaster* motion = me->GetMotionMaster();
//
//            if (message)
//            {
//                me->MonsterTextEmote("Imperial Vizier Zor'lok flies to one of his platforms!", me->GetGUID(), true);
//
//                if (motion)
//                    // Pre Fly Increase Z position
//                    motion->MovePoint(1, me->GetPositionX(), me->GetPositionY(), 423.399048f);
//
//                // Schedule Unattackable RemoveAble Events;
//                me->SetReactState(REACT_PASSIVE);
//                me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//                message = false;
//
//                //me->SetSpeed(MOVE_RUN, 3.5f, true);
//                //me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
//            }
//
//            switch (urand(1, 3))
//            {
//            case 1:
//                if (!ramp_1_trigger)
//                {
//                    if (motion)
//                    {
//                        // Cancel
//                        events.CancelEvent(EVENT_ATTENUATION);
//                        events.CancelEvent(EVENT_FORCE_AND_VERSE);
//                        events.CancelEvent(EVENT_NOISE_CANCELING);
//                        events.CancelEvent(EVENT_INHALE);
//                        events.CancelEvent(EVENT_EXHALE);
//                        events.CancelEvent(EVENT_CONVERT);
//
//                        // Aura
//                        found = true;
//
//                        // Move to Ramp 1
//
//                        if (Creature* ramp_1 = me->FindNearestCreature(ramp_1_trigger_id, 100.0f, true))
//                            motion->MovePoint(1, ramp_1->GetPositionX(), ramp_1->GetPositionY(), ramp_1->GetPositionZ());
//
//
//
//                        // Move to Ramp 1
//                        //motion->MovePoint(1, Ramp_Pos1);
//
//
//                        // start ramp 1 events
//                        events.ScheduleEvent(EVENT_ATTENUATION, urand(18000, 24000));
//                        events.ScheduleEvent(EVENT_INHALE, urand(5000, 10000));
//                        events.ScheduleEvent(EVENT_EXHALE, urand(12000, 15000));
//                    }
//                }
//                else
//                {
//                    RampChange(false);
//                }
//                break;
//            case 2:
//                if (!ramp_2_trigger)
//                {
//                    if (motion)
//                    {
//                        // Cancel
//                        events.CancelEvent(EVENT_ATTENUATION);
//                        events.CancelEvent(EVENT_FORCE_AND_VERSE);
//                        events.CancelEvent(EVENT_NOISE_CANCELING);
//                        events.CancelEvent(EVENT_INHALE);
//                        events.CancelEvent(EVENT_EXHALE);
//                        events.CancelEvent(EVENT_CONVERT);
//
//
//                        // Aura
//                        found = true;
//
//
//                        // Move to Ramp 3
//                        if (Creature* ramp_2 = me->FindNearestCreature(ramp_2_trigger_id, 100.0f, true))
//                            motion->MovePoint(1, ramp_2->GetPositionX(), ramp_2->GetPositionY(), ramp_2->GetPositionZ());
//
//
//
//                        // Move to Ramp 2
//                        //motion->MovePoint(1, Ramp_Pos2);
//
//                        // PreCancel
//                        // cancel all other ramps events
//                        events.CancelEvent(EVENT_INHALE);
//                        events.CancelEvent(EVENT_EXHALE);
//
//                        // start ramp 2 events
//                        events.ScheduleEvent(EVENT_FORCE_AND_VERSE, 38000);
//                        events.ScheduleEvent(EVENT_INHALE, urand(4000, 5500));
//                        events.ScheduleEvent(EVENT_EXHALE, urand(10000, 15000));
//
//                        // cancel all other ramps events
//                        events.CancelEvent(EVENT_ATTENUATION);
//                    }
//                }
//                else
//                {
//                    RampChange(false);
//                }
//                break;
//            case 3:
//                if (!ramp_3_trigger)
//                {
//                    if (motion)
//                    {
//                        // Cancel
//                        events.CancelEvent(EVENT_ATTENUATION);
//                        events.CancelEvent(EVENT_FORCE_AND_VERSE);
//                        events.CancelEvent(EVENT_NOISE_CANCELING);
//                        events.CancelEvent(EVENT_INHALE);
//                        events.CancelEvent(EVENT_EXHALE);
//                        events.CancelEvent(EVENT_CONVERT);
//
//
//                        // Move to Ramp 3
//                        if (Creature* ramp_3 = me->FindNearestCreature(ramp_3_trigger_id, 100.0f, true))
//                            motion->MovePoint(1, ramp_3->GetPositionX(), ramp_3->GetPositionY(), ramp_3->GetPositionZ());
//
//
//                        // Move to Ramp 3
//                        //motion->MovePoint(1, Ramp_Pos3);
//
//                        // Aura
//                        found = true;
//
//                        // Move Ramp 3
//                        //motion->MovePoint(1, Ramp_Pos3);
//
//                        // PreCancel
//                        // cancel all other ramps events
//                        events.CancelEvent(EVENT_INHALE);
//                        events.CancelEvent(EVENT_EXHALE);
//
//
//                        // start ramp 3 events
//                        events.ScheduleEvent(EVENT_INHALE, urand(4000, 5500));
//                        events.ScheduleEvent(EVENT_EXHALE, urand(12000, 15000));
//                        events.ScheduleEvent(EVENT_CONVERT, urand(25000, 30000));
//                    }
//                }
//                else
//                {
//                    RampChange(false);
//                }
//                break;
//            }
//        }
//
//        void PreFlight()
//        {
//            if (MotionMaster* motion = me->GetMotionMaster())
//            {
//                motion->MovePoint(1, me->GetPositionX(), me->GetPositionY(), 430.159821f);
//                events.ScheduleEvent(SCHEDULE_RAMP_CHANGE, 3500);
//            }
//        }
//
//        void CenterChange()
//        {
//            if (MotionMaster* motion = me->GetMotionMaster())
//            {
//                // cancels all
//                events.CancelEvent(EVENT_ATTENUATION);
//                events.CancelEvent(EVENT_FORCE_AND_VERSE);
//                events.CancelEvent(EVENT_NOISE_CANCELING);
//                events.CancelEvent(EVENT_INHALE);
//                events.CancelEvent(EVENT_EXHALE);
//                events.CancelEvent(EVENT_CONVERT);
//
//                me->SetReactState(REACT_PASSIVE);
//                me->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
//
//                me->MonsterYell("We are as unwavering as the ember that shapes our hall, with her might will vanquish all who dare intrude upon her divine home.", LANG_UNIVERSAL, me->GetGUID());
//                DoPlaySoundToSet(me, 29311);
//
//                if (Creature* smoke_Trigger = me->FindNearestCreature(TRIGGER_SMOKE, 100.0f, true))
//                    smoke_Trigger->DespawnOrUnsummon();
//
//                motion->MovePoint(1, -2274.567383f, 259.058289f, 420.271484f);
//                events.ScheduleEvent(EVENT_ZEAL, 4000);
//            }
//        }
//        void LastPhase()
//        {
//            events.ScheduleEvent(EVENT_ATTENUATION, 6000);
//            events.ScheduleEvent(EVENT_FORCE_AND_VERSE, 38000);
//            events.ScheduleEvent(EVENT_CONVERT, 25000);
//
//            if (Creature* smoke_Trigger = me->FindNearestCreature(TRIGGER_SMOKE, 100.0f, true))
//                smoke_Trigger->DespawnOrUnsummon();
//        }
//    private:
//        EventMap events;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_imperial_zorlokAI(creature);
//    }
//};
//class exhale : public SpellScriptLoader
//{
//public:
//    exhale() : SpellScriptLoader("exhale") {}
//
//    class exhaleSP : public SpellScript
//    {
//        PrepareSpellScript(exhaleSP);
//
//        void Unload()
//        {
//            if (GetCaster())
//            {
//                if (GetCaster()->HasAura(INHALE))
//                {
//                    GetCaster()->RemoveAura(INHALE);
//                }
//            }
//        }
//        void Register()
//        {
//
//        }
//    };
//    SpellScript* GetSpellScript() const
//    {
//        return new exhaleSP();
//    }
//};
//
//// Trigger to activate pre boss sayings
//class Cinematic_Triggers_Zorlok : public CreatureScript
//{
//public:
//    Cinematic_Triggers_Zorlok() : CreatureScript("Cinematic_Triggers_Zorlok") {}
//
//    struct Cinematic_Triggers_ZorlokAI : public ScriptedAI
//    {
//        Cinematic_Triggers_ZorlokAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetSpeed(MOVE_RUN, 0.0);
//            me->SetReactState(REACT_PASSIVE);
//            me->setFaction(35);
//        }
//
//        uint32 BossHasSpokedTimer_1;
//        uint32 BossHasSpokedTimer_2;
//        uint32 BossHasSpokedTimer_3;
//        uint32 BossHasSpokedTimer_4;
//        uint32 BossHasSpokedTimer_5;
//        uint32 BossHasSpokedTimer_6;
//
//        bool BossHasSpoked1;
//        bool BossHasSpoked2;
//        bool BossHasSpoked3;
//        bool BossHasSpoked4;
//        bool BossHasSpoked5;
//        bool BossHasSpoked6;
//        bool BossHasSpoked7;
//        bool BossHasSpoked8;
//
//        void Reset()
//        {
//            BossHasSpokedTimer_1 = 6000;
//            BossHasSpokedTimer_2 = 11000;
//            BossHasSpokedTimer_3 = 16000;
//            BossHasSpokedTimer_4 = 21000;
//            BossHasSpokedTimer_5 = 27000;
//            BossHasSpokedTimer_6 = 36000;
//
//            // Booleans -- OOC ROLEPLAYING
//            BossHasSpoked1 = false;
//            BossHasSpoked2 = false;
//            BossHasSpoked3 = false;
//            BossHasSpoked4 = false;
//            BossHasSpoked5 = false;
//            BossHasSpoked6 = false;
//            // OOC ROLEPLAYING ENDS
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//            {
//                if (!BossHasSpoked1 && BossHasSpokedTimer_1 <= diff)
//                {
//                    BossHasSpoked1 = true;
//
//                    DoPlaySoundToSet(me, 29303);
//                    me->MonsterYell("We are the extension of our Empress's will.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_1 -= diff;
//
//                if (!BossHasSpoked2 && BossHasSpokedTimer_2 <= diff)
//                {
//                    BossHasSpoked2 = true;
//
//                    DoPlaySoundToSet(me, 29304);
//                    me->MonsterYell("Ours is but to serve in Her divine name.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_1 -= diff;
//
//                if (!BossHasSpoked3 && BossHasSpokedTimer_3 <= diff)
//                {
//                    BossHasSpoked3 = true;
//
//                    DoPlaySoundToSet(me, 29305);
//                    me->MonsterYell("Never to question, nor to contemplate, we simple act.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_3 -= diff;
//                if (!BossHasSpoked4 && BossHasSpokedTimer_4 <= diff)
//                {
//                    BossHasSpoked4 = true;
//
//                    DoPlaySoundToSet(me, 29306);
//                    me->MonsterYell("We fight, toil and serve so that Her vision is made for us reality.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_4 -= diff;
//
//                if (!BossHasSpoked5 && BossHasSpokedTimer_5 <= diff)
//                {
//                    BossHasSpoked5 = true;
//
//                    DoPlaySoundToSet(me, 29307);
//                    me->MonsterYell("Her happiness is our reward, her sorrow our failure.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_5 -= diff;
//
//                if (!BossHasSpoked6 && BossHasSpokedTimer_6 <= diff)
//                {
//                    BossHasSpoked6 = true;
//
//                    DoPlaySoundToSet(me, 29308);
//                    me->MonsterYell("We will give our lives for the Empress without hesitation. She's our light and without her our lives will be lost to darkness.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_6 -= diff;
//            }
//        }
//    private:
//        EventMap events;
//        std::list<Player*> Player_List;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Cinematic_Triggers_ZorlokAI(creature);
//    }
//};
//
//// Trigger to activate pre boss sayings
//class Cinematic_Triggers_Zorlok_Death : public CreatureScript
//{
//public:
//    Cinematic_Triggers_Zorlok_Death() : CreatureScript("Cinematic_Triggers_Zorlok_Death") {}
//
//    struct Cinematic_Triggers_Zorlok_Death_AI : public ScriptedAI
//    {
//        Cinematic_Triggers_Zorlok_Death_AI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetSpeed(MOVE_RUN, 0.0);
//            me->SetReactState(REACT_PASSIVE);
//            me->setFaction(35);
//        }
//
//        uint32 BossHasSpokedTimer_1;
//        uint32 BossHasSpokedTimer_2;
//        uint32 BossHasSpokedTimer_3;
//        uint32 BossHasSpokedTimer_4;
//
//        bool BossHasSpoked1;
//        bool BossHasSpoked2;
//        bool BossHasSpoked3;
//        bool BossHasSpoked4;
//
//        void Reset()
//        {
//            BossHasSpokedTimer_1 = 6000;
//            BossHasSpokedTimer_2 = 11000;
//            BossHasSpokedTimer_3 = 16000;
//            BossHasSpokedTimer_4 = 20000;
//            // Booleans -- OOC ROLEPLAYING
//            BossHasSpoked1 = false;
//            BossHasSpoked2 = false;
//            BossHasSpoked3 = false;
//            BossHasSpoked4 = false;
//            // OOC ROLEPLAYING ENDS
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//            {
//                if (!BossHasSpoked1 && BossHasSpokedTimer_1 <= diff)
//                {
//                    BossHasSpoked1 = true;
//
//                    DoPlaySoundToSet(me, 29274);
//                    me->MonsterYell("My voice's gone.. how will my subject hear me? will they still love their empress? they will return to me as the Kl'axxi I am.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_1 -= diff;
//
//                if (!BossHasSpoked2 && BossHasSpokedTimer_2 <= diff)
//                {
//                    BossHasSpoked2 = true;
//
//                    DoPlaySoundToSet(me, 29275);
//                    me->MonsterYell("They sent you!? They wouldn't dare!.. would they?", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_1 -= diff;
//
//                if (!BossHasSpoked3 && BossHasSpokedTimer_3 <= diff)
//                {
//                    BossHasSpoked3 = true;
//
//                    DoPlaySoundToSet(me, 29276);
//                    me->MonsterYell("You! you will suffer for your insolence by the hand of my greatest champions! Surely they will protect their Empress.", LANG_UNIVERSAL, me->GetGUID());
//                }
//                else
//                    BossHasSpokedTimer_3 -= diff;
//
//                if (!BossHasSpoked4 && BossHasSpokedTimer_4 <= diff)
//                {
//                    BossHasSpoked4 = true;
//
//                    DoPlaySoundToSet(me, 29277);
//                    me->MonsterYell("Hear me subjects, your empress's is threatend by these outsiders - they wants to kill me. To Kill us all! DESTROY THEM!", LANG_UNIVERSAL, me->GetGUID());
//
//                    me->DespawnOrUnsummon(10000);
//                }
//                else
//                    BossHasSpokedTimer_4 -= diff;
//
//            }
//        }
//    private:
//        EventMap events;
//        std::list<Player*> Player_List;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Cinematic_Triggers_Zorlok_Death_AI(creature);
//    }
//};
//// OOC EXTERNAL NUM 1
//class Srathik_Shield_Master_SentenceTrigger : public CreatureScript
//{
//public:
//    Srathik_Shield_Master_SentenceTrigger() : CreatureScript("Srathik_Shield_Master_SentenceTrigger") {}
//
//    struct Srathik_Shield_MasterAI : public ScriptedAI
//    {
//        Srathik_Shield_MasterAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (Is25ManRaid())
//            {
//                me->SetMaxHealth(16020496);
//                me->SetHealth(16020496);
//            }
//            else
//            {
//                me->SetMaxHealth(6323880);
//                me->SetHealth(6323880);
//            }
//            me->setFaction(16);
//            me->SetLevel(92);
//        }
//
//        uint32 shieldSlamTimer;
//        uint32 spellReflectTimer;
//        uint32 sunderArmorTimer;
//
//        bool HasBossSpokeOnCombat;
//        bool HasBossSpokeOnDeath;
//
//
//        void Reset()
//        {
//            shieldSlamTimer = urand(4500, 12000);
//            spellReflectTimer = urand(30000, 60000); // 1m
//            sunderArmorTimer = urand(2000, 5000);
//
//            HasBossSpokeOnCombat = false;
//            HasBossSpokeOnDeath = false;
//        }
//        void JustDied(Unit* /*killer*/)
//        {
//            if (!HasBossSpokeOnDeath)
//            {
//                if (Creature* Boss = me->FindNearestCreature(62980, 200.0f, true))
//                {
//                    // other trigger changes it back.
//                    Boss->setFaction(35);
//
//                    HasBossSpokeOnDeath = true;
//                    DoPlaySoundToSet(me, 29313);
//                    Boss->MonsterYell("They were clearly unworthy of Her divine embrave.", LANG_UNIVERSAL, Boss->GetGUID());
//                }
//            }
//        }
//        void EnterCombat(Unit* /*who*/)
//        {
//            if (!HasBossSpokeOnCombat)
//            {
//                HasBossSpokeOnCombat = true;
//
//                DoPlaySoundToSet(me, 29312);
//
//                if (Creature* Boss = me->FindNearestCreature(62980, 100.0f, true))
//                {
//                    Boss->MonsterYell("The chaff of our world tumbles across our doorstep, driven by fear. Her royal storm will whisk them away.", LANG_UNIVERSAL, Boss->GetGUID());
//
//                    if (MotionMaster* motion = Boss->GetMotionMaster())
//                    {
//                        motion->MovePoint(1, -2216.300049f, 307.021729f, 443.719177f);
//                    }
//
//                    if (boss_imperial_zorlok::boss_imperial_zorlokAI* linkAI = CAST_AI(boss_imperial_zorlok::boss_imperial_zorlokAI, Boss->GetAI()))
//                    {
//                        if (!linkAI->SrathikEvent1)
//                        {
//                            linkAI->SrathikEvent1 = true;
//                        }
//                    }
//                }
//
//
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//            if (shieldSlamTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SHIELD_SLAM, true);
//                shieldSlamTimer = urand(4500, 12000);
//            }
//            else
//                shieldSlamTimer -= diff;
//
//            if (spellReflectTimer <= diff)
//            {
//                DoCastAOE(MASS_SPELL_REFLECT);
//                spellReflectTimer = urand(30000, 60000); // 1m
//            }
//            else
//                spellReflectTimer -= diff;
//
//            if (sunderArmorTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SUNDER_ARMOR);
//                sunderArmorTimer = urand(2000, 5000);
//            }
//            else
//                sunderArmorTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Srathik_Shield_MasterAI(creature);
//    }
//};
//// OOC external NUM 2
//class Srathik_Shield_Master_SentenceTrigger_1 : public CreatureScript
//{
//public:
//    Srathik_Shield_Master_SentenceTrigger_1() : CreatureScript("Srathik_Shield_Master_SentenceTrigger_1") {}
//
//    struct Srathik_Shield_MasterAI : public ScriptedAI
//    {
//        Srathik_Shield_MasterAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (Is25ManRaid())
//            {
//                me->SetMaxHealth(16020496);
//                me->SetHealth(16020496);
//            }
//            else
//            {
//                me->SetMaxHealth(6323880);
//                me->SetHealth(6323880);
//            }
//            me->setFaction(16);
//            me->SetLevel(92);
//        }
//        uint32 shieldSlamTimer;
//        uint32 spellReflectTimer;
//        uint32 sunderArmorTimer;
//
//        bool HasBossSpokeOnCombat;
//        bool HasBossSpokeOnDeath;
//
//        void Reset()
//        {
//            shieldSlamTimer = urand(4500, 12000);
//            spellReflectTimer = urand(30000, 60000); // 1m
//            sunderArmorTimer = urand(2000, 5000);
//
//            HasBossSpokeOnCombat = false;
//            HasBossSpokeOnDeath = false;
//        }
//        void JustDied(Unit* /*killer*/)
//        {
//            if (!HasBossSpokeOnDeath)
//            {
//                if (Creature* Boss = me->FindNearestCreature(62980, 100.0f, true))
//                {
//                    if (MotionMaster* motion = Boss->GetMotionMaster())
//                    {
//                        motion->MovePoint(2, -2306.118652f, 225.960373f, 424.621124f);
//                    }
//
//                    HasBossSpokeOnDeath = true;
//                    DoPlaySoundToSet(me, 29315);
//                    Boss->MonsterYell("We ae unfazed. We will stand firm.", LANG_UNIVERSAL, Boss->GetGUID());
//                }
//            }
//        }
//        void EnterCombat(Unit* /*who*/)
//        {
//            if (!HasBossSpokeOnCombat)
//            {
//                HasBossSpokeOnCombat = true;
//
//                DoPlaySoundToSet(me, 29314);
//
//                if (Creature* Boss = me->FindNearestCreature(62980, 100.0f, true))
//                {
//                    if (MotionMaster* motion = Boss->GetMotionMaster())
//                    {
//                        motion->MovePoint(1, -2307.963623f, 224.072723f, 424.528931f);
//                    }
//
//                    Boss->MonsterYell("They are but the waves that crashing upon the mountain of her divine will. They may rise again and again, but will accomplish nothing.. ", LANG_UNIVERSAL, Boss->GetGUID());
//
//                    if (boss_imperial_zorlok::boss_imperial_zorlokAI* linkAI = CAST_AI(boss_imperial_zorlok::boss_imperial_zorlokAI, Boss->GetAI()))
//                    {
//                        if (!linkAI->SrathikEvent2)
//                        {
//                            linkAI->SrathikEvent2 = true;
//                        }
//                    }
//                }
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//            if (shieldSlamTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SHIELD_SLAM, true);
//                shieldSlamTimer = urand(4500, 12000);
//            }
//            else
//                shieldSlamTimer -= diff;
//
//            if (spellReflectTimer <= diff)
//            {
//                DoCastAOE(MASS_SPELL_REFLECT);
//                spellReflectTimer = urand(30000, 60000); // 1m
//            }
//            else
//                spellReflectTimer -= diff;
//
//            if (sunderArmorTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SUNDER_ARMOR);
//                sunderArmorTimer = urand(2000, 5000);
//            }
//            else
//                sunderArmorTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Srathik_Shield_MasterAI(creature);
//    }
//};
//// OOC external NUM 2
//class Srathik_Shield_Master_SentenceTrigger_2 : public CreatureScript
//{
//public:
//    Srathik_Shield_Master_SentenceTrigger_2() : CreatureScript("Srathik_Shield_Master_SentenceTrigger_2") {}
//
//    struct Srathik_Shield_MasterAI : public ScriptedAI
//    {
//        Srathik_Shield_MasterAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (Is25ManRaid())
//            {
//                me->SetMaxHealth(16020496);
//                me->SetHealth(16020496);
//            }
//            else
//            {
//                me->SetMaxHealth(6323880);
//                me->SetHealth(6323880);
//            }
//            me->setFaction(16);
//            me->SetLevel(92);
//        }
//
//        uint32 shieldSlamTimer;
//        uint32 spellReflectTimer;
//        uint32 sunderArmorTimer;
//
//        bool HasBossSpokeOnCombat;
//        bool HasBossSpokeOnDeath;
//
//        void Reset()
//        {
//            shieldSlamTimer = urand(4500, 12000);
//            spellReflectTimer = urand(30000, 60000); // 1m
//            sunderArmorTimer = urand(2000, 5000);
//
//            HasBossSpokeOnCombat = false;
//            HasBossSpokeOnDeath = false;
//        }
//        void JustDied(Unit* /*killer*/)
//        {
//            if (!HasBossSpokeOnDeath)
//            {
//                if (Creature* Boss = me->FindNearestCreature(62980, 100.0f, true))
//                {
//                    HasBossSpokeOnDeath = true;
//                    DoPlaySoundToSet(me, 29317);
//                    Boss->MonsterYell("And so it falls to us, her chosen voice.", LANG_UNIVERSAL, Boss->GetGUID());
//
//                    // Set boss to be attackable.
//                    Boss->setFaction(16);
//
//                    if (MotionMaster* motion = Boss->GetMotionMaster())
//                    {
//                        motion->MovePoint(4, -2289.897949f, 242.967392f, 422.789215f);
//                        Boss->SetHomePosition(-2289.897949f, 242.967392f, 422.789215f, 0.735058f);
//                    }
//
//                    if (boss_imperial_zorlok::boss_imperial_zorlokAI* linkAI = CAST_AI(boss_imperial_zorlok::boss_imperial_zorlokAI, Boss->GetAI()))
//                    {
//                        if (!linkAI->SrathikEvent3)
//                        {
//                            linkAI->SrathikEvent3 = true;
//                        }
//                    }
//                }
//            }
//        }
//        void EnterCombat(Unit* /*who*/)
//        {
//            if (!HasBossSpokeOnCombat)
//            {
//                HasBossSpokeOnCombat = true;
//
//                DoPlaySoundToSet(me, 29316);
//
//                if (Creature* Boss = me->FindNearestCreature(62980, 100.0f, true))
//                {
//                    Boss->MonsterYell("The divine challenges us to face these intruders.", LANG_UNIVERSAL, Boss->GetGUID());
//                }
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//            if (shieldSlamTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SHIELD_SLAM, true);
//                shieldSlamTimer = urand(4500, 12000);
//            }
//            else
//                shieldSlamTimer -= diff;
//
//            if (spellReflectTimer <= diff)
//            {
//                DoCastAOE(MASS_SPELL_REFLECT);
//                spellReflectTimer = urand(30000, 60000); // 1m
//            }
//            else
//                spellReflectTimer -= diff;
//
//            if (sunderArmorTimer <= diff)
//            {
//                me->CastSpell(me->getVictim(), SUNDER_ARMOR);
//                sunderArmorTimer = urand(2000, 5000);
//            }
//            else
//                sunderArmorTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Srathik_Shield_MasterAI(creature);
//    }
//};
//// Trigger for smoke
//// OOC external NUM 2
//class Smoke_Trigger : public CreatureScript
//{
//public:
//    Smoke_Trigger() : CreatureScript("Smoke_Trigger") {}
//
//    struct Smoke_TriggerAI : public ScriptedAI
//    {
//        Smoke_TriggerAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetSpeed(MOVE_RUN, 0.0);
//            me->SetReactState(REACT_PASSIVE);
//            me->setFaction(35);
//        }
//        uint32 visualTimer;
//        void Reset()
//        {
//            visualTimer = 1000;
//
//            me->CastSpell(me->getVictim(), SMOKE_VISUAL, true);
//            if (me->HasAura(SMOKE_VISUAL))
//            {
//                if (AuraPtr smoke = me->GetAura(SMOKE_VISUAL))
//                {
//                    smoke->SetDuration(1000000, true);
//                }
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            // Visual
//            if (visualTimer <= diff)
//            {
//
//                visualTimer = 120000;
//            }
//            else
//                visualTimer -= diff;
//
//            // dot
//            std::list<Player*> PL_list;
//
//            JadeCore::AnyPlayerInObjectRangeCheck check(me, 20.0f);
//            JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, PL_list, check);
//            me->VisitNearbyObject(20.0f, searcher);
//
//            for (std::list<Player*>::const_iterator it = PL_list.begin(); it != PL_list.end(); ++it)
//            {
//                if (!(*it))
//                    return;
//
//                if (me->IsWithinDistInMap((*it), 20.0f, true))
//                {
//                    if (!(*it)->HasAura(SMOKE_DOT))
//                    {
//                        (*it)->AddAura(SMOKE_DOT, (*it));
//                    }
//                }
//            }
//        }
//    private:
//        EventMap events;
//        std::list<Player*> Player_List;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Smoke_TriggerAI(creature);
//    }
//};
//// Noise Canceling apply, removal is hanlded spellmgr.cpp
//class Noise_Canceling_Zone : public CreatureScript
//{
//public:
//    Noise_Canceling_Zone() : CreatureScript("Noise_Canceling_Zone") {}
//
//    struct Noise_Canceling_ZoneAI : public Scripted_NoMovementAI
//    {
//        Noise_Canceling_ZoneAI(Creature* creature) : Scripted_NoMovementAI(creature)
//        {
//            me->SetDisplayId(11668);
//            me->SetLevel(92);
//        }
//        void Reset()
//        {
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            std::list<Player*> targets_X;
//            JadeCore::AnyPlayerInObjectRangeCheck u_check(me, 5.0f);
//            JadeCore::PlayerListSearcher <JadeCore::AnyPlayerInObjectRangeCheck> searcher(me, targets_X, u_check);
//            me->VisitNearbyObject(5.0f, searcher);
//
//            for (std::list<Player*>::const_iterator it = targets_X.begin(); it != targets_X.end(); ++it)
//            {
//                if (!(*it))
//                    return;
//
//                if (!(*it)->HasAura(122706))
//                    me->AddAura(122706, (*it));
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Noise_Canceling_ZoneAI(creature);
//    }
//};
//// Id: 122440
//// Name : Attenuation
//class spell_gen_attenuation : public SpellScriptLoader {
//public:
//    spell_gen_attenuation() : SpellScriptLoader("spell_gen_attenuation") { }
//
//    class spell_gen_attenuation_AuraScript : public AuraScript {
//        PrepareAuraScript(spell_gen_attenuation_AuraScript);
//
//        float orientation; uint32 SpawnTimer; uint8 j; bool way;
//
//        bool Load()
//        {
//            way = true ? true : false;
//            if (way)
//                j = 0;
//            else
//                j = 12;
//            SpawnTimer = 0.76 * IN_MILLISECONDS;
//            return true;
//        }
//
//        void SpawnCreatures()
//        {
//            for (uint8 i = 0; i < 4; ++i)
//            {
//                switch (i)
//                {
//                case 0:
//                    GetCaster()->SummonCreature(122970, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), orientation, TEMPSUMMON_TIMED_DESPAWN, 10000); break;
//                case 1:
//                    GetCaster()->SummonCreature(122970, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), orientation + M_PI, TEMPSUMMON_TIMED_DESPAWN, 10000); break;
//                case 2:
//                    GetCaster()->SummonCreature(122970, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), orientation + 3 * M_PI / 2, TEMPSUMMON_TIMED_DESPAWN, 10000); break;
//                case 3:
//                    GetCaster()->SummonCreature(122970, GetCaster()->GetPositionX(), GetCaster()->GetPositionY(), GetCaster()->GetPositionZ(), orientation + M_PI / 2, TEMPSUMMON_TIMED_DESPAWN, 10000); break;
//                }
//            }
//        }
//
//        void OnUpdate(uint32 diff, AuraEffectPtr aurEff)
//        {
//            if (GetCaster())
//            {
//                if (SpawnTimer <= diff)
//                {
//                    SpawnTimer = 0.76 * IN_MILLISECONDS;
//                    switch (j)
//                    {
//                    case 0: orientation = 0.0f; break;
//                    case 1: orientation = 0.0f + M_PI / 6; break;
//                    case 2: orientation = 0.0f + M_PI / 3; break;
//                    case 3: orientation = 0.0f + M_PI / 2; break;
//                    case 4: orientation = 0.0f + 2 * M_PI / 3; break;
//                    case 5: orientation = 0.0f + 5 * M_PI / 6; break;
//                    case 6: orientation = 0.0f + M_PI; break;
//                    case 7: orientation = 0.0f + 7 * M_PI / 6; break;
//                    case 8: orientation = 0.0f + 4 * M_PI / 3; break;
//                    case 9: orientation = 0.0f + 3 * M_PI / 2; break;
//                    case 10: orientation = 0.0f + 5 * M_PI / 3; break;
//                    case 11: orientation = 0.0f + 11 * M_PI / 6; break;
//                    case 12: orientation = 0.0f; break;
//                    default: break;
//                    }
//                    SpawnCreatures();
//
//                    if (way)
//                        j++;
//                    else
//                        --j;
//                }
//                else
//                    SpawnTimer -= diff;
//            }
//        }
//
//        void Register()
//        {
//            OnEffectUpdate += AuraEffectUpdateFn(spell_gen_attenuation_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const
//    {
//        return new spell_gen_attenuation_AuraScript();
//    }
//};
//// 274090 creature_template id
//class npc_attenuation : public CreatureScript {
//public:
//    npc_attenuation() : CreatureScript("npc_attenuation") { }
//
//    struct npc_attenuationAI : ScriptedAI {
//        npc_attenuationAI(Creature* creature) : ScriptedAI(creature) { Initialize(); }
//
//        uint32 SpawnTimer;
//
//        void Initialize()
//        {
//            me->setFaction(16);
//            me->CastSpell(me, 71706, true); // Visual??
//            float x, y, z;
//            me->GetClosePoint(x, y, z, me->GetObjectSize(), 100.0f);
//            me->GetMotionMaster()->MovePoint(0, x, y, z);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (Player* target = me->SelectNearestPlayer())
//            {
//                if (target->IsWithinDistInMap(target, 1.5f, true))
//                {
//                    if (!target->HasAura(122706))
//                    {
//                        target->ToPlayer()->EnvironmentalDamage(DAMAGE_FIRE, 24000);
//                    }
//                    else
//                    {
//                        target->ToPlayer()->EnvironmentalDamage(DAMAGE_FIRE, 9000);
//                    }
//                }
//            }
//
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new npc_attenuationAI(creature);
//    }
//};
//
//void AddSC_imperial_zorlok()
//{
//    // boss
//    new boss_imperial_zorlok();
//
//    // spells
//    new exhale();
//    new spell_gen_attenuation();
//    new npc_attenuation();
//    new Noise_Canceling_Zone();
//    new Smoke_Trigger();
//
//    // rp
//    new Cinematic_Triggers_Zorlok();
//    new Cinematic_Triggers_Zorlok_Death();
//
//    // triggrers for rp
//    new Srathik_Shield_Master_SentenceTrigger_2();
//    new Srathik_Shield_Master_SentenceTrigger_1();
//    new Srathik_Shield_Master_SentenceTrigger();
//}
