//
//#include "ObjectMgr.h"
//#include "Player.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "AchievementMgr.h"
//#include "Group.h"
//
//enum Spells
//{ // wtf
//    CRASH_FULL_SPELL = 122774, // crash happens when pheremones are being switched.
//    CRASH_PURPLE_CRICLE = 122082,
//
//    FURIOUS_SWIPE = 122735,
//
//    // PHERMONE
//    PHEREMONE_FULL = 122835,
//    PHERMONE_TRAIL = 123106, // added to trigger
//    PHEROMONE_ARTIFICIAL_COOLDOWN = 123092, // being used as a cd for pheremone switch
//    AURA_PHEREMONE_DMG = 122835,
//    AURA_PHEREMONE = 123081, // PUNGENCY
//    SPELL_BERSERK          = 120207, // Enrage, 420 seconds, or 7 minutes.
//};
//enum Mobs
//{
//    LEG_TRIGGER = 63053,
//    PHEREMONE_TRIGGER = 63201,
//    GARALON_ID = 62164,
//    GHOST_GATE = 180322,
//    SPAWNING_NPC_ID = 1231249,
//};
//enum Events
//{
//    EVENT_PHEROMONES = 1,
//    EVENT_CAST_FURIOUS_SWIPE = 2,
//    EVENT_CAST_CRASH = 3,
//    EVENT_CAST_CRASH_MSG = 4,
//    EVENT_CAST_CRUSH_RANGE_CD = 5,
//    EVENT_RE_PHEREMONE = 6,
//    EVENT_GARALON_BERSERK = 7,
//
//};
//enum Actions
//{
//    ACTION_PHEROMONES_JUMP_OR_PLAYERS_UNDERNEATH,
//    PHEROMONE_ACTION,
//};
//
//
//class boss_garalon : public CreatureScript
//{
//public:
//    boss_garalon() : CreatureScript("boss_garalon") { }
//
//    struct boss_garalonAI : public BossAI
//    {
//        boss_garalonAI(Creature* creature) : BossAI(creature, 0), _vehicle(creature->GetVehicleKit())
//        {
//            ASSERT(_vehicle);
//
//            me->SetLevel(93);
//            me->setFaction(16);
//
//            if (!Is25ManRaid())
//            {
//                me->SetMaxHealth(500943840);
//                me->SetHealth(500943840);
//            }
//            else
//            {
//                me->SetMaxHealth(218943840);
//                me->SetHealth(218943840);
//            }
//        }
//        bool crush_bool;
//        bool ranged_crush_bool;
//        bool recheckpheremone;
//        bool castingCrush;
//        int32 timepheremone;
//        std::list<GameObject*> ghost_list;
//        void Reset()
//        {
//            _Reset();
//            crush_bool = false;
//
//            me->AddAura(CRASH_PURPLE_CRICLE, me);
//
//            events.CancelEvent(EVENT_PHEROMONES);
//            events.CancelEvent(EVENT_CAST_FURIOUS_SWIPE);
//            events.CancelEvent(EVENT_GARALON_BERSERK);
//
//            timepheremone = 7000;
//
//            castingCrush = false; 
//
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                    if (Player* player = itr->getSource())
//                    {
//                player->RemoveAura(122835);
//                player->RemoveAura(123081);
//                    }
//
//            me->setFaction(35);
//            me->SummonCreature(SPAWNING_NPC_ID, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
//        }
//        void EnterCombat(Unit* who)
//        {
//            _EnterCombat();
//            events.ScheduleEvent(EVENT_CAST_FURIOUS_SWIPE, 10000);
//            events.ScheduleEvent(EVENT_PHEROMONES, 1000);
//            events.ScheduleEvent(EVENT_GARALON_BERSERK, 7 * MINUTE * IN_MILLISECONDS); // 7 min enrage timer.
//
//            crush_bool = true;
//        }
//        void JustReachedHome()
//        {
//            //	instance->SetBossState(DATA_TAYAK, FAIL);
//            summons.DespawnAll();
//
//            me->DespawnCreaturesInArea(63053);
//            me->DespawnCreaturesInArea(5435246);
//            me->DespawnCreaturesInArea(63021);
//
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                    if (Player* player = itr->getSource())
//                    {
//                player->RemoveAura(122835);
//                player->RemoveAura(123081);
//                    }
//            Reset();
//        }
//        void DoAction(int32 const action)
//        {
//            switch (action)
//            {
//            case ACTION_PHEROMONES_JUMP_OR_PLAYERS_UNDERNEATH:
//            {
//                if (!castingCrush)
//                {
//                    castingCrush = true;
//                    events.CancelEvent(EVENT_CAST_CRASH);
//                    events.ScheduleEvent(EVENT_CAST_CRASH_MSG, 1000);
//                    events.ScheduleEvent(EVENT_CAST_CRASH, 4000);
//                }
//                break;
//            }
//            case PHEROMONE_ACTION:
//            {
//                events.ScheduleEvent(EVENT_PHEROMONES, 4000);
//            }
//                break;
//            default:
//                break;
//            }
//        }
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//
//            if (!UpdateVictim())
//            {
//                if (instance)
//                {
//                    Map::PlayerList const& players = me->GetMap()->GetPlayers();
//                    if (!players.isEmpty())
//                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                            if (Player* player = itr->getSource())
//                            {
//                        instance->DoRemoveAurasDueToSpellOnPlayers(AURA_PHEREMONE);
//                        instance->DoRemoveAurasDueToSpellOnPlayers(AURA_PHEREMONE_DMG);
//                        instance->DoRemoveAurasDueToSpellOnPlayers(PHEREMONE_FULL);
//                            }
//                }
//            }
//            while (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_CAST_CRASH_MSG:
//                    me->MonsterTextEmote("Garalon smells the scent of Pheromones and casts [Crush]!", LANG_UNIVERSAL, me->GetGUID());
//                    break;
//                case EVENT_CAST_CRASH:
//                    me->CastSpell(me, CRASH_FULL_SPELL);     
//                    events.ScheduleEvent(EVENT_CAST_CRUSH_RANGE_CD, 4000);
//                    castingCrush = false;
//                    break;
//                case EVENT_CAST_CRUSH_RANGE_CD:
//                    ranged_crush_bool = false;
//                    break;
//                    // Pheremones
//                case EVENT_PHEROMONES:
//                {
//                    DoCast(me, 123808); // Spell script handles aura apply.
//                    break;
//                }
//                    // Furious Swipe
//                case EVENT_CAST_FURIOUS_SWIPE:
//                    me->CastSpell(me->getVictim(), FURIOUS_SWIPE);
//                    events.ScheduleEvent(EVENT_CAST_FURIOUS_SWIPE, 14000);
//                    break;
//                case EVENT_GARALON_BERSERK:
//                    me->AddAura(SPELL_BERSERK, me);
//                    DoCast(me, CRASH_FULL_SPELL);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//        void JustDied(Unit* killer)
//        {
//            _JustDied();
//
//            me->DespawnCreaturesInArea(63053);
//            me->DespawnCreaturesInArea(5435246);
//
//            Map::PlayerList const& players = me->GetMap()->GetPlayers();
//            if (!players.isEmpty())
//                for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
//                    if (Player* player = itr->getSource())
//                    {
//                player->RemoveAura(122835);
//                player->RemoveAura(123081);
//                    }
//        }
//        void KilledUnit(Unit* victim)
//        {
//        }
//    private:
//        EventMap events;
//        Vehicle* _vehicle;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_garalonAI(creature);
//    }
//};
//class boss_summoner_trigger : public CreatureScript
//{
//public:
//    boss_summoner_trigger() : CreatureScript("boss_summoner_trigger") { }
//
//    struct boss_summoner_triggerAI : public Scripted_NoMovementAI
//    {
//        boss_summoner_triggerAI(Creature* creature) : Scripted_NoMovementAI(creature)
//        {
//            me->SetPhaseMask(1, true);
//            InstanceScript* instance = me->GetInstanceScript();
//        }
//        std::list<Creature*> Dead_Quarter_Creatures;
//        bool BossHasStart;
//        void Reset()
//        {
//            BossHasStart = false;
//            events.Reset();
//        }
//        void EnterCombat(Unit* who)
//        {
//        }
//        void JustDied(Unit* killer)
//        {
//        }
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//
//            if (Dead_Quarter_Creatures.size() >= 16 && !BossHasStart && me->GetPhaseMask() != 1902)
//            {
//                if (me->FindNearestCreature(GARALON_ID, 100.0f, true))
//                    return;
//
//                BossHasStart = true;
//                Creature * boss = me->SummonCreature(GARALON_ID, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 0);
//
//                me->SetPhaseMask(1902, true);
//            }
//            if (me->GetEntry() == SPAWNING_NPC_ID)
//            {
//                if (Creature* boss_alive = me->FindNearestCreature(62164, 50.0f, true))
//                {
//                    if (/*!me->FindNearestCreature(63053, 50.0f, true) && */boss_alive->getFaction() == 35)
//                    {
//                        Creature* Gal = me->SummonCreature(63053, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//                        Creature* Gal1 = me->SummonCreature(63053, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//                        Creature* Gal2 = me->SummonCreature(63053, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//                        Creature* Gal3 = me->SummonCreature(63053, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN);
//
//                        boss_alive->setFaction(16);
//
//                        if (Gal && Gal1 && Gal2 && Gal3)
//                        {
//                            Gal->EnterVehicle(boss_alive, 0);
//                            Gal1->EnterVehicle(boss_alive, 1);
//                            Gal2->EnterVehicle(boss_alive, 2);
//                            Gal3->EnterVehicle(boss_alive, 3);
//                        }
//                        me->DespawnOrUnsummon(500);
//                    }
//                }
//            }
//        }
//    private:
//        EventMap events;
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new boss_summoner_triggerAI(creature);
//    }
//};
//// spellls122835
//
//// Corrosive Resin Stack
//class Pheremone_stack : public SpellScriptLoader
//{
//public:
//    Pheremone_stack() : SpellScriptLoader("Pheremone_stack") { }
//
//    class Pheremone_stack_reapply : public SpellScript
//    {
//        PrepareSpellScript(Pheremone_stack_reapply);
//
//        void HAfterCast()
//        {
//            if (!GetCaster())
//                return;
//
//            GetCaster()->CastSpell(GetCaster(), 123081);
//        }
//        void Register()
//        {
//            AfterCast += SpellCastFn(Pheremone_stack_reapply::HAfterCast);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new Pheremone_stack_reapply();
//    }
//};
//class npc_pheremone_trail : public CreatureScript
//{
//public:
//    npc_pheremone_trail() : CreatureScript("npc_pheremone_trail") { }
//
//    struct npc_pheremone_trailAI : public CreatureAI
//    {
//        npc_pheremone_trailAI(Creature* creature) : CreatureAI(creature)
//        {
//            me->SetObjectScale(1.0f);
//        }
//        uint32 visual;
//        void Reset()
//        {
//            visual = 5000;
//
//            me->CastSpell(me, PHERMONE_TRAIL);
//            me->AddAura(131620, me);
//
//            if (me->HasAura(131620))
//            {
//                AuraPtr aura = me->GetAura(131620);
//
//                if (aura)
//                {
//                    aura->SetDuration(100000, true);
//                }
//            }
//        }
//
//        void UpdateAI(uint32 const diff)
//        {
//            events.Update(diff);
//
//            if (visual <= diff)
//            {
//                me->CastSpell(me, 129776);
//                visual = 5000;
//            }
//            else
//                visual -= diff;
//
//            if (Creature * garalon = me->FindNearestCreature(62164, 200.0f, true))
//            {
//                if (garalon->isDead() || !garalon->isInCombat())
//                {
//                    me->DespawnOrUnsummon();
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
//        return new npc_pheremone_trailAI(creature);
//    }
//};
//class garalon_leg : public VehicleScript
//{
//public:
//    garalon_leg() : VehicleScript("garalon_leg") {}
//
//    void OnAddPassenger(Vehicle* veh, Unit* /*passenger*/, int8 /*seatId*/)
//    {
//        if (veh->GetBase())
//            if (veh->GetBase()->ToCreature())
//                if (veh->GetBase()->ToCreature()->AI())
//                    veh->GetBase()->ToCreature()->AI()->DoAction(0);
//    }
//
//    struct garalon_legAI : public ScriptedAI
//    {
//        garalon_legAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetObjectScale(0.5f);
//        }
//
//        bool cdchange;
//        bool canbleed;
//        uint32 restorehpflag;
//        uint32 bleeding;
//        uint32 restoring;
//        void Reset()
//        {
//            me->AddAura(CRASH_PURPLE_CRICLE, me);
//
//            canbleed = false;
//            cdchange = false;
//            restoring = urand(60000, 80000);     
//
//            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
//            me->ClearUnitState(UNIT_STATE_ONVEHICLE);
//            me->ToCreature()->SetInCombatWithZone();
//        }
//        void DamageTaken(Unit* attacker, uint32& damage)
//        {
//            if (!me->HealthAbovePct(10) && !cdchange) // ramps changes
//            {
//                me->setFaction(35);
//
//                if (Creature* Boss = me->FindNearestCreature(GARALON_ID, 50.0f, true))
//                {
//                    me->DealDamage(Boss, Boss->GetMaxHealth() * 0.03, NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
//                    Boss->SetSpeed(MOVE_RUN, Boss->GetSpeed(MOVE_RUN) - Boss->GetSpeed(MOVE_RUN) * 0.15, true);
//                }
//                cdchange = true;
//                canbleed = true;
//                bleeding = 3000;
//            }
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (cdchange)
//            {
//                if (restorehpflag <= diff)
//                {
//                    if (Creature* Boss = me->FindNearestCreature(GARALON_ID, 50.0f, true))
//                    {
//                        Boss->CastSpell(me, 123495);
//
//                        cdchange = false;
//                        canbleed = false;
//
//                        me->SetHealth(me->GetMaxHealth());
//                        me->setFaction(16);
//
//                        if (Creature* Boss = me->FindNearestCreature(GARALON_ID, 50.0f, true))
//                        {
//                            Boss->SetSpeed(MOVE_RUN, Boss->GetSpeed(MOVE_RUN) + Boss->GetSpeed(MOVE_RUN) * 0.15, true);
//                        }
//                    }
//                }
//            }
//            else
//                restorehpflag -= diff;
//
//            if (canbleed)
//            {
//                if (bleeding <= diff)
//                {
//                    me->CastSpell(me, 123472);
//                    bleeding = 3000;
//                }
//                else
//                    bleeding -= diff;
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new garalon_legAI(creature);
//    }
//};
//// 2ND QUARTER
//class Gustwing_NPC : public CreatureScript
//{
//public:
//    Gustwing_NPC() : CreatureScript("Gustwing_NPC") {}
//
//    struct Korthik_ExtremistAI : public ScriptedAI
//    {
//        Korthik_ExtremistAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (Is25ManRaid())
//            {
//                me->SetMaxHealth(3301009);
//                me->SetHealth(3301009);
//            }
//            else
//            {
//                me->SetMaxHealth(1222596);
//                me->SetHealth(1222596);
//            }
//            me->SetLevel(91);
//            me->setFaction(16);
//        }
//
//        uint32 GustTimer;
//
//        void Reset()
//        {
//            GustTimer = urand(5000, 20000);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            if (GustTimer <= diff)
//            {
//                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true))
//                {
//                    if (target->getFaction() != me->getFaction())
//                    {
//                        me->CastSpell(target, 124072);
//                        GustTimer = urand(10000, 20000);
//                    }
//                }
//            }
//            else
//                GustTimer -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//        void JustDied(Unit* killer)
//        {
//            if (Creature* garalontrigger = me->FindNearestCreature(5465464, 80.0f, true))
//            {
//                if (boss_summoner_trigger::boss_summoner_triggerAI* triggerg = CAST_AI(boss_summoner_trigger::boss_summoner_triggerAI, garalontrigger->GetAI()))
//                {
//                    triggerg->Dead_Quarter_Creatures.push_back(me);
//                }
//            }
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Korthik_ExtremistAI(creature);
//    }
//};
//
//class Zephyr_Caster : public CreatureScript
//{
//public:
//    Zephyr_Caster() : CreatureScript("Zephyr_Caster") {}
//
//    struct Zephyr_CasterAI : public ScriptedAI
//    {
//        Zephyr_CasterAI(Creature* creature) : ScriptedAI(creature)
//        {
//            if (Is25ManRaid())
//            {
//                me->SetMaxHealth(17074476);
//                me->SetHealth(17074476);
//            }
//            else
//            {
//                me->SetMaxHealth(6323880);
//                me->SetHealth(6323880);
//            }
//            me->SetLevel(91);
//            me->setFaction(16);
//        }
//
//        uint32 ZephyrCast;
//
//        void Reset()
//        {
//            ZephyrCast = urand(10000, 20000);
//        }
//        void UpdateAI(const uint32 diff)
//        {
//            if (!UpdateVictim())
//                return;
//
//            if (ZephyrCast <= diff)
//            {
//                me->CastSpell(me, 124085);
//                ZephyrCast = urand(10000, 20000);
//            }
//            else
//                ZephyrCast -= diff;
//
//            DoMeleeAttackIfReady();
//        }
//        void JustDied(Unit* killer)
//        {
//            if (Creature* garalontrigger = me->FindNearestCreature(5465464, 80.f, true))
//            {
//                if (boss_summoner_trigger::boss_summoner_triggerAI* triggerg = CAST_AI(boss_summoner_trigger::boss_summoner_triggerAI, garalontrigger->GetAI()))
//                {
//                    triggerg->Dead_Quarter_Creatures.push_back(me);
//                }
//            }
//
//        }
//    };
//    CreatureAI* GetAI(Creature* creature) const
//    {
//        return new Zephyr_CasterAI(creature);
//    }
//};
//
//
//// Pheromone Trail Dmg 123120
//class spell_garalon_pheromones_trail_dmg : public SpellScriptLoader
//{
//public:
//    spell_garalon_pheromones_trail_dmg() : SpellScriptLoader("spell_garalon_pheromones_trail_dmg") { }
//
//    class spell_garalon_pheromones_trail_dmg_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_garalon_pheromones_trail_dmg_SpellScript);
//
//        bool Validate(SpellEntry const * spellEntry)
//        {
//            if (!sSpellStore.LookupEntry(spellEntry->Id))
//                return false;
//
//            return true;
//        }
//
//        bool Load()
//        {
//            return true;
//        }
//
//        void HandleOnHit()
//        {
//            if (Unit* target = GetHitUnit())
//            {
//                if (AuraPtr aur = target->GetAura(123081))
//                    SetHitDamage(int32(GetHitDamage() * (1.0f + float(aur->GetStackAmount() / 10.0f))));
//            }
//        }
//
//
//        void Register()
//        {
//            OnHit += SpellHitFn(spell_garalon_pheromones_trail_dmg_SpellScript::HandleOnHit);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_garalon_pheromones_trail_dmg_SpellScript();
//    }
//};
//
//// Pheromones Switch 123100
//class spell_garalon_pheromones_switch : public SpellScriptLoader
//{
//public:
//    spell_garalon_pheromones_switch() : SpellScriptLoader("spell_garalon_pheromones_switch") { }
//
//    class spell_garalon_pheromones_switch_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_garalon_pheromones_switch_SpellScript);
//
//        bool Validate(SpellEntry const * spellEntry)
//        {
//            if (!sSpellStore.LookupEntry(spellEntry->Id))
//                return false;
//
//            return true;
//        }
//
//        bool Load()
//        {
//            return true;
//        }
//
//        void HandleScript(SpellEffIndex /*effIndex*/)
//        {
//            if (!GetCaster() || !GetHitUnit())
//                return;
//
//            GetCaster()->RemoveAurasDueToSpell(122835);
//                if (Creature* garalon = GetCaster()->FindNearestCreature(62164, 200.0f, true))
//                    garalon->GetAI()->DoAction(ACTION_PHEROMONES_JUMP_OR_PLAYERS_UNDERNEATH);
//        }
//
//        void FillTargets(std::list<WorldObject*>& targets)
//        {
//            if (!targets.empty())
//                targets.resize(1);
//        }
//
//        void Register()
//        {
//            OnEffectHitTarget += SpellEffectFn(spell_garalon_pheromones_switch_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_switch_SpellScript::FillTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_garalon_pheromones_switch_SpellScript();
//    }
//};
//
//// Pheromones (Force_Cast, 2 sec. cast time): 123808.
//class spell_garalon_pheromones_forcecast : public SpellScriptLoader
//{
//public:
//    spell_garalon_pheromones_forcecast() : SpellScriptLoader("spell_garalon_pheromones_forcecast") { }
//
//    class spell_garalon_pheromones_forcecastSpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_garalon_pheromones_forcecastSpellScript);
//
//        bool Validate(SpellEntry const * spellEntry)
//        {
//            if (!sSpellStore.LookupEntry(spellEntry->Id))
//                return false;
//
//            return true;
//        }
//
//        bool Load()
//        {
//            return true;
//        }
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (targets.empty())
//                return;
//
//            // Find the nearest player in 100 yards, and that will be the target (done like that on off).
//            WorldObject* target = GetCaster()->ToCreature()->SelectNearestPlayer(100.0f);
//
//            targets.clear();
//            targets.push_back(target);
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_forcecastSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_garalon_pheromones_forcecastSpellScript();
//    }
//};
//
//// Mend Leg target check for Garalon's Legs.
//class TargetCheck : public std::unary_function < Unit*, bool >
//{
//public:
//    explicit TargetCheck(Unit* _caster) : caster(_caster) { }
//
//    bool operator()(WorldObject* object)
//    {
//        return object->GetEntry() != 63053;
//    }
//
//private:
//    Unit* caster;
//};
//// Target check for Pheromones  Taunt / Attack Me + Broken Leg spells.
//class BossCheck : public std::unary_function < Unit*, bool >
//{
//public:
//    explicit BossCheck(Unit* _caster) : caster(_caster) { }
//
//    bool operator()(WorldObject* object)
//    {
//        return object->GetEntry() != 62164;
//    }
//
//private:
//    Unit* caster;
//};
//
//// Pheromones Taunt: 123109.
//class spell_garalon_pheromones_taunt : public SpellScriptLoader
//{
//public:
//    spell_garalon_pheromones_taunt() : SpellScriptLoader("spell_garalon_pheromones_taunt") { }
//
//    class spell_garalon_pheromones_tauntSpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_garalon_pheromones_tauntSpellScript);
//
//        bool Validate(SpellEntry const * spellEntry)
//        {
//            if (!sSpellStore.LookupEntry(spellEntry->Id))
//                return false;
//
//            return true;
//        }
//
//        bool Load()
//        {
//            return true;
//        }
//
//        void FilterTargets(std::list<WorldObject*>& targets)
//        {
//            if (targets.empty())
//                return;
//
//            // Only the boss gets taunted.
//            targets.remove_if(BossCheck(GetCaster()));
//        }
//
//        void Register()
//        {
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_tauntSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_garalon_pheromones_tauntSpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const
//    {
//        return new spell_garalon_pheromones_tauntSpellScript();
//    }
//};
//
//void AddSC_boss_garalon()
//{
//    // spell
//    new Pheremone_stack();
//    new npc_pheremone_trail();
//    //new pheremone_transfer();
//    // boss + vehicle
//    new boss_summoner_trigger();
//    new garalon_leg();
//    new boss_garalon();
//    //new npc_galion_veh();
//    // adds
//    new Gustwing_NPC();
//    new Zephyr_Caster();
//    new spell_garalon_pheromones_forcecast();   // 123808
//    new spell_garalon_pheromones_taunt();       // 123109
//    new spell_garalon_pheromones_trail_dmg();   // 123120 INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (123120, "spell_garalon_pheromones_trail_dmg");
//    new spell_garalon_pheromones_switch();      // 123100 INSERT INTO spell_script_names (spell_id, ScriptName) VALUES (123100, "spell_garalon_pheromones_switch");
//}
