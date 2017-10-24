#include "bot_ai.h"
//#include "botmgr.h"
//#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
//#include "WorldSession.h"
/*
Blademaster NpcBot (by Graff onlysuffering@gmail.com)
Complete - Around 30%
TODO: MIRROR IMAGE (ILLUSION), BLADESTORM
*/

#define MAX_ILLUSION_POSITIONS 4

class blademaster_bot : public CreatureScript
{
public:
    blademaster_bot() : CreatureScript("blademaster_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new blademaster_botAI(creature);
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        return bot_minion_ai::OnGossipHello(player, creature, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (bot_minion_ai* ai = creature->GetBotMinionAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        if (bot_minion_ai* ai = creature->GetBotMinionAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }

    struct blademaster_botAI : public bot_minion_ai
    {
    private:
        //DelayedMeleeDamageEvent - Blademaster
        //deals critical damage, resets attack timer and sends fake log
        class DelayedMeleeDamageEvent : public BasicEvent
        {
            public:
                DelayedMeleeDamageEvent(uint64 botGuid, uint64 targetGuid, bool windwalk) :
                  _botGuid(botGuid), _targetGuid(targetGuid), _windwalk(windwalk), _dinfo(NULL) { }
                ~DelayedMeleeDamageEvent() { }

                void SetDamageInfo(CalcDamageInfo* dinfo)
                {
                    _dinfo = dinfo;
                }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    bool suc = false;
                    /*if (Creature* bot = sObjectAccessor->GetObjectInOrOutOfWorld(_botGuid, (Creature*)NULL))
                    {
                        ASSERT(bot->GetBotClass() == BOT_CLASS_BM);
                        (dynamic_cast<blademaster_bot::blademaster_botAI*>(bot->GetBotMinionAI()))->CriticalStrikeFinish(_targetGuid, _dinfo, _windwalk);
                        suc = true;
                    }*/

                    delete _dinfo;
                    return suc;
                }

            private:
                uint64 _botGuid;
                uint64 _targetGuid;
                bool _windwalk;
                CalcDamageInfo* _dinfo;
                DelayedMeleeDamageEvent(DelayedMeleeDamageEvent const&);
        };

        class EventTerminateEvent : public BasicEvent
        {
            public:
                EventTerminateEvent(uint64 botGuid) : _botGuid(botGuid) { }
                ~EventTerminateEvent() { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    /*if (Creature* bot = sObjectAccessor->GetObjectInOrOutOfWorld(_botGuid, (Creature*)NULL))
                    {
                        (dynamic_cast<blademaster_bot::blademaster_botAI*>(bot->GetBotMinionAI()))->TerminateEvent();
                        return true;
                    }*/
                    return false;
                }

            private:
                uint64 _botGuid;
                EventTerminateEvent(EventTerminateEvent const&);
        };

        class DelayedIllusionSummonEvent : public BasicEvent
        {
            public:
                DelayedIllusionSummonEvent(uint64 botGuid) : _botGuid(botGuid) { }
                ~DelayedIllusionSummonEvent() { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    /*if (Creature* bot = sObjectAccessor->GetObjectInOrOutOfWorld(_botGuid, (Creature*)NULL))
                    {
                        ASSERT(bot->GetBotClass() == BOT_CLASS_BM);
                        (dynamic_cast<blademaster_bot::blademaster_botAI*>(bot->GetBotMinionAI()))->MirrorImageFinish();
                        return true;
                    }*/

                    return false;
                }

            private:
                uint64 _botGuid;
                DelayedIllusionSummonEvent(DelayedIllusionSummonEvent const&);
        };

        class DisappearEvent : public BasicEvent
        {
            public:
                DisappearEvent(uint64 botGuid) : _botGuid(botGuid) { }
                ~DisappearEvent() { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    /*if (Creature* bot = sObjectAccessor->GetObjectInOrOutOfWorld(_botGuid, (Creature*)NULL))
                    {
                        ASSERT(bot->GetBotClass() == BOT_CLASS_BM);
                        (dynamic_cast<blademaster_bot::blademaster_botAI*>(bot->GetBotMinionAI()))->MirrorImageMid();
                        return true;
                    }*/

                    return false;
                }

            private:
                uint64 _botGuid;
                DisappearEvent(DisappearEvent const&);
        };

        void _calcIllusionPositions()
        {
            float x = me->m_positionX;
            float y = me->m_positionY;
            float o = me->m_orientation;

            //X     X
            //   C
            //X     X
            //
            //C - caster (Blademaster)
            //X - new positions (1-3 illusions + blademaster)

            float dist = 2.f; //not too far - 2 for x and y seems to be way to go
            for (uint8 i = 0; i != MAX_ILLUSION_POSITIONS; ++i)
            {
                _illusPos[i].m_positionX = x + ((i == 0 || i == 1) ? +dist : -dist); // +2+2-2-2
                _illusPos[i].m_positionY = y + (!(i & 1) ? +dist : -dist);           // +2-2+2-2
                _illusPos[i].m_orientation = o;
            }
        }

    public:
        blademaster_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_BM;
            //Blademaster cannot be disarmed
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, SPELL_AURA_MOD_DISARM, true);
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_BM) != SPELL_CAST_OK)
                return false;

            //custom
            if (_dmdevent)
                return false;
            if (IsTempBot()) //Illusion etc.
                return false;

            return bot_ai::doCast(victim, spellId, triggered);
        }

        void UpdateAI(uint32 diff)
        {
            ReduceCD(diff);
            if (!GlobalUpdate(diff))
                return;
            CheckAttackState();
            CheckAuras();
            if (wait == 0)
                wait = GetWait();
            else
                return;
            BreakCC(diff);
            if (CCed(me)) return;

            if (Potion_cd <= diff && me->GetPower(POWER_MANA) < 125)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            if (Potion_cd <= diff && GetHealthPCT(me) < 67)
            {
                temptimer = GC_Timer;
                if (doCast(me, HEALINGPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            CheckWindWalk(diff);
            CheckMirrorImage(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (!CheckAttackTarget(BOT_CLASS_BM))
                return;

            Attack(diff);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            Aggro(u);
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force);
        }

        void EnterCombat(Unit* u) { bot_minion_ai::EnterCombat(u); }
        void Aggro(Unit*) { }
        void AttackStart(Unit*) { }
        void KilledUnit(Unit* /*u*/) { }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }
        uint8 GetPlayerClass() const { return BOT_CLASS_WARRIOR; }

        bool CanSheath() const { return false; }
        bool CanSit() const { return false; }
        bool CanDrink() const { return false; }
        bool CanEat() const { return Windwalk_Timer == 0 && !illusion_Fade; }
        bool CanMount() const { return false; }
        bool CanChangeEquip(uint8 slot) const { return slot > BOT_SLOT_RANGED; }
        bool IgnoreEquipsAttackTime() const { return true; }
        bool CanSeeEveryone() const { return Windwalk_Timer > 0; }
        bool CanParry() const { return false; }
        bool CanCrit() const { return false; }
        bool CanDodge() const { return false; }
        bool CanMiss() const { return false; }

        void BreakCC(uint32 diff)
        {
            if (me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
            {
                if (IsSpellReady(WINDWALK_1, diff) && !IsTank(me) && Rand() < 30 &&
                    doCast(me, GetSpell(WINDWALK_1)))
                    return;
            }
            bot_minion_ai::BreakCC(diff);
        }

        void Attack(uint32 /*diff*/)
        {
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent, true);
            }
            else
                return;

            //AttackerSet m_attackers = master->getAttackers();
            //AttackerSet b_attackers = me->getAttackers();
            //float dist = me->GetExactDist(opponent);
            //float meleedist = me->GetDistance(opponent);
            ////charge + warbringer
            //if (IsSpellReady(CHARGE_1, diff, false) && dist > 11 && dist < 25 && me->HasInArc(M_PI, opponent) &&
            //    (me->getLevel() >= 50 ||
            //    (!me->IsInCombat() && (battleStance || stanceChange(diff, 1)))))
            //{
            //    temptimer = GC_Timer;
            //    if (me->getLevel() >= 29)
            //        me->RemoveMovementImpairingAuras();
            //    if (doCast(opponent, GetSpell(CHARGE_1), me->IsInCombat()))
            //    {
            //        SetSpellCooldown(CHARGE_1, 12000);
            //        GC_Timer = temptimer;
            //        return;
            //    }
            //}
            ////OVERPOWER
            //if (IsSpellReady(OVERPOWER_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50 && getrage() > 50 && meleedist <= 5 &&
            //    (battleStance || stancetimer <= diff))
            //{
            //    if (me->HasAura(TASTE_FOR_BLOOD_BUFF))
            //    {
            //        if (battleStance || stanceChange(diff, 1))
            //        {
            //            if (doCast(opponent, GetSpell(OVERPOWER_1)))
            //            {
            //                me->RemoveAura(TASTE_FOR_BLOOD_BUFF);
            //                return;
            //            }
            //        }
            //    }
            //}

            if (MoveBehind(*opponent))
                wait = 5;

            //////PLACEHOLDER - BLADESTORM
            ////BLADESTORM
            //if (IsSpellReady(BLADESTORM_1, diff) && HasRole(BOT_ROLE_DPS) &&
            //   getrage() >= 250 && (Rand() < 20 || me->HasAura(RECKLESSNESS_1)) &&
            //   (b_attackers.size() > 1 || opponent->GetHealth() > me->GetMaxHealth()))
            //{
            //    if (doCast(me, GetSpell(BLADESTORM_1)))
            //    {
            //        SetSpellCooldown(BLADESTORM_1, 60000);
            //        return;
            //    }
            //}
            //////PLACEHOLDER - SPELLCAST INTERRUPT POSSIBLE
            ////PUMMEL
            //if (IsSpellReady(PUMMEL_1, diff, false) && Rand() < 80 && getrage() > 100 && meleedist <= 5 &&
            //    opponent->IsNonMeleeSpellCast(false) &&
            //    (berserkerStance || stancetimer <= diff))
            //{
            //    temptimer = GC_Timer;
            //    if ((berserkerStance || stanceChange(diff, 3)) &&
            //        doCast(opponent, GetSpell(PUMMEL_1)))
            //    {
            //        SetSpellCooldown(PUMMEL_1, 10000);
            //        GC_Timer = temptimer;
            //        return;
            //    }
            //}
        }

        void DoBMMeleeAttackIfReady()
        {
            //Copied from UnitAI::DoMeleeAttackIfReady() with modifications
            //cannot attack while casting or jumping
            if (me->HasUnitState(UNIT_STATE_CASTING) || _dmdevent)
                return;

            Unit* victim = me->GetVictim();
            //Make sure our attack is ready and we aren't currently casting before checking distance
            if (me->isAttackReady() && me->IsWithinMeleeRange(victim))
            {
                if (!CCed(me, true) && !JumpingFlyingOrFalling())
                {
                    //Windwalk strike
                    if (Windwalk_Timer)
                    {
                        CriticalStrike(victim, true);
                        return;
                    }

                    //Critical Strike: 15% to deal x2,x3, etc... damage
                    if (criticalStikeMult >= 2 && !CCed(me, true) && !JumpingFlyingOrFalling() &&
                        roll_chance_f(15.f))
                    {
                        CriticalStrike(victim);
                        return;
                    }
                }

                me->AttackerStateUpdate(victim);
                me->resetAttackTimer();
                return;
            }
        }

        void CheckAttackState()
        {
            if (me->GetVictim())
            {
                if (HasRole(BOT_ROLE_DPS))
                    DoBMMeleeAttackIfReady();
            }
            else
                Evade();
        }

        void CheckWindWalk(uint32 diff)
        {
            if (!IsSpellReady(WINDWALK_1, diff) || Windwalk_Timer || illusion_Fade || IsCasting() ||
                Rand() > (10 + 20 * (me->IsInCombat() || master->IsInCombat())))
                return;

            if (!IAmFree() && master->isMoving())
            {
                if (me->GetDistance(master) > 30 &&
                    doCast(me, GetSpell(WINDWALK_1)))
                    return;

                return;
            }

            if (!IsTank(me))
            {
                //unit to strike
                Unit* u = IsMelee() ? me->GetVictim() : NULL;

                if ((u && u->isMoving() && me->GetDistance(u) > 18 &&
                    (u->GetVictim() != me || u->getAttackers().size() > uint8(u->IsControlledByPlayer() ? 0 : 1))) ||
                    me->getAttackers().size() > 2)
                {
                    if (doCast(me, GetSpell(WINDWALK_1)))
                        return;
                }
            }
        }

        void CheckMirrorImage(uint32 diff)
        {
            //only for controlled bot
            if (IAmFree())
                return;
            if (!IsSpellReady(MIRROR_IMAGE_1, diff) || !me->IsInCombat() || !illusionsCount || illusion_Fade ||
                IsCasting() || Rand() > 20)
                return;

            uint8 pct = GetHealthPCT(me);
            uint8 size = uint8(me->getAttackers().size());
            if (!size)
                return;

            if (pct > 25 && (size > 3 || pct < (80 + size * 5)))
                if (doCast(me, GetSpell(MIRROR_IMAGE_1)))
                    return;
        }

        void MirrorImageStart()
        {
            if (!illusionsCount)
                return;

            ASSERT(!illusion_Fade); //prevent double casts
            illusion_Fade = true;

            //OKAY

            //there is a restiction for illusions count - cannot summon more than 3 of them
            while (int8(_illusionGuids.size()) > (3 - illusionsCount))
            {
                std::list<uint64>::iterator itr = _illusionGuids.begin();
                if (Creature* illusion = ObjectAccessor::GetCreatureOrPetOrVehicle(*me, ObjectGuid(*itr)))
                    if (!illusion->IsDuringRemoveFromWorld())
                        illusion->ToCreature()->GetBotAI()->JustDied(NULL);

                _illusionGuids.erase(itr);
            }

            //mirror image renders BM invulnerable for a short period of time,
            //removing all auras. We exclude passive or invisible auras for they don't exist in W3
            Unit::AuraMap const auras = me->GetOwnedAuras(); //copy
            for (Unit::AuraMap::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            {
                Aura* aura = iter->second;
                if ((aura->GetSpellInfo()->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) ||
                    (aura->GetSpellInfo()->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR))
                    continue;
                AuraApplication* aurApp = aura->GetApplicationOfTarget(me->GetGUID());
                if (!aurApp)
                    continue;
                me->RemoveAura(aurApp, AURA_REMOVE_BY_DEFAULT);
            }

            me->BotStopMovement();
            me->AttackStop();
            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
            me->AddAura(BLACK_COLOR, me);//color
            me->AddAura(STUN_FREEZE, me);//stop/immunity

            //prepare to disappear
            DisappearEvent* devent = new DisappearEvent(me->GetGUID());
            events.AddEvent(devent, events.CalculateTime(300)); //immediatelly (almost)
        }

        void MirrorImageMid()
        {
            if (!me->IsInWorld() ||
                !me->IsAlive()/* || CCed(me)*/) //this is just ensurance
            {
                me->RemoveAura(BLACK_COLOR);
                me->RemoveAura(STUN_FREEZE);
                illusion_Fade = false;
                return;
            }
            //disappear
            me->SetPhaseMask(0, true);

            //INVISIBLE!
            //EVENT
            DelayedIllusionSummonEvent* disevent = new DelayedIllusionSummonEvent(me->GetGUID());
            events.AddEvent(disevent, events.CalculateTime(1250)); //1000 ms disappear time + 250 ms buffer
        }

        void MirrorImageFinish()
        {
            illusion_Fade = false;
            me->RemoveAura(BLACK_COLOR);
            me->RemoveAura(STUN_FREEZE);
            if (!me->IsInWorld() ||
                !me->IsAlive()) //this is just ensurance
                return;

            _calcIllusionPositions();

            std::set<uint8> usedposs;

            for (uint8 i = 0; i != illusionsCount; ++i)
            {
                Creature* illusion = master->SummonCreature(me->GetEntry(), *me, TEMPSUMMON_TIMED_DESPAWN, 1 * MINUTE * IN_MILLISECONDS);
                if (!illusion)
                    continue;

                illusion->GetBotAI()->SetBotIsTemp();
                illusion->GetBotAI()->FindMaster(true);
                illusion->SetMaxHealth(me->GetMaxHealth());
                illusion->SetHealth(me->GetHealth());
                illusion->SetMaxPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
                illusion->SetPower(POWER_MANA, me->GetPower(POWER_MANA));
                illusion->SetFloatValue(UNIT_FIELD_MINDAMAGE, me->GetFloatValue(UNIT_FIELD_MINDAMAGE));
                illusion->SetFloatValue(UNIT_FIELD_MAXDAMAGE, me->GetFloatValue(UNIT_FIELD_MAXDAMAGE));

                illusion->BotStopMovement();
                while (true)
                {
                    uint8 j = urand(0, MAX_ILLUSION_POSITIONS - 1);
                    if (usedposs.find(j) == usedposs.end())
                    {
                        illusion->GetMotionMaster()->MovePoint(me->GetMapId(), _illusPos[j]);
                        //illusion->Relocate(_illusPos[j]);
                        usedposs.insert(j);
                        break;
                    }
                }

                illusion->SetBotCommandState(COMMAND_ABANDON);

                _illusionGuids.push_back(illusion->GetGUID());
            }

            me->SetBotCommandState(COMMAND_ABANDON);

            for (uint8 i = 0; i != MAX_ILLUSION_POSITIONS; ++i)
            {
                if (usedposs.find(i) == usedposs.end())
                {
                    me->BotStopMovement();
                    me->GetMotionMaster()->MovePoint(me->GetMapId(), _illusPos[i]);
                    //me->Relocate(_illusPos[i]);
                    //usedposs.insert(i);
                    break;
                }
            }

            uint8 counter = 0;
            uint8 r = urand(0, uint8(_illusionGuids.size() - 1));

            for (std::list<uint64>::const_iterator itr = _illusionGuids.begin(); itr != _illusionGuids.end(); ++itr)
            {
                if (Creature* illusion = ObjectAccessor::GetCreatureOrPetOrVehicle(*me, ObjectGuid(*itr)))
                    illusion->SetPhaseMask(master->GetPhaseMask(), true);

                if (counter == r)
                    me->SetPhaseMask(master->GetPhaseMask(), true);
                else
                    ++counter;
            }

            me->getHostileRefManager().deleteReferences();

            if (me->GetPhaseMask() != master->GetPhaseMask())
                me->SetPhaseMask(master->GetPhaseMask(), true);

            //me->setAttackTimer(BASE_ATTACK, 3000);
            wait = 18;
            SetSpellCooldown(MIRROR_IMAGE_1, 8000);
            Potion_cd = std::max<uint32>(Potion_cd, 10000);
        }

        void CriticalStrike(Unit* target, bool windwalk = false)
        {
            //Okay critical strike must have jump and strike animation, doing delayed damage
            DelayedMeleeDamageEvent* dmdevent = new DelayedMeleeDamageEvent(me->GetGUID(), target->GetGUID(), windwalk);
            SetDelayedMeleeDamageEvent(dmdevent);

            //hack temp attack damage calc
            float mindam = me->GetFloatValue(UNIT_FIELD_MINDAMAGE);
            float maxdam = me->GetFloatValue(UNIT_FIELD_MAXDAMAGE);

            if (windwalk)
            {
                me->SetFloatValue(UNIT_FIELD_MINDAMAGE, mindam * 1.5f);
                me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, maxdam * 1.5f);
                me->RemoveAura(GetSpell(WINDWALK_1));
                me->RemoveAura(TRANSPARENCY);
            }
            else
            {
                me->SetFloatValue(UNIT_FIELD_MINDAMAGE, mindam * criticalStikeMult);
                me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, maxdam * criticalStikeMult);
            }

            CalcDamageInfo* dinfo = new CalcDamageInfo();
            me->CalculateMeleeDamage(target, 0, dinfo, BASE_ATTACK);

            me->SetFloatValue(UNIT_FIELD_MINDAMAGE, mindam);
            me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, maxdam);

            dmdevent->SetDamageInfo(dinfo);
            events.AddEvent(dmdevent, events.CalculateTime(450));

            BotJumpInPlaceInFrontOf(target, 0.32f, 4.1f); //jump - DO NOT CHANGE
            me->CastSpell(target, SPELL_COMBAT_SPECIAL_2H_ATTACK, true); //strike anim
            me->resetAttackTimer(BASE_ATTACK);
        }

        void CriticalStrikeFinish(uint64 targetGuid, CalcDamageInfo* dinfo, bool /*windwalk*/)
        {
            EventTerminateEvent* etevent = new EventTerminateEvent(me->GetGUID());
            events.AddEvent(etevent, events.CalculateTime(750));

            if (!me->IsInWorld() || !me->IsAlive() || CCed(me))
            {
                Windwalk_Timer = 0;
                return;
            }

            Unit* target = ObjectAccessor::GetUnit(*me, ObjectGuid(targetGuid));
            if (!target || !target->IsAlive())
            {
                me->PlayDistanceSound(SOUND_MISS_WHOOSH_2H);
                Windwalk_Timer = 0;
                return;
            }

            if (target->IsImmunedToDamage(SPELL_SCHOOL_MASK_NORMAL))
            {
                //target became immune
                me->SendSpellMiss(target, CRITICAL_STRIKE_1, SPELL_MISS_IMMUNE);
                target->PlayDistanceSound(SOUND_ABSORB_GET_HIT);
                Windwalk_Timer = 0;
                return;
            }
            else if (!CanSeeEveryone() && !me->CanSeeOrDetect(target, false, false))
            {
                //target disappeared
                me->SendSpellMiss(target, CRITICAL_STRIKE_1, SPELL_MISS_MISS/*SPELL_MISS_EVADE*/);
                me->PlayDistanceSound(SOUND_MISS_WHOOSH_2H);
                Windwalk_Timer = 0;
                return;
            }

            target->PlayDistanceSound(SOUND_AXE_2H_IMPACT_FLESH_CRIT);

            me->SendSpellNonMeleeDamageLog(target, CRITICAL_STRIKE_1,
                dinfo->damage + dinfo->absorb + dinfo->resist + dinfo->blocked_amount,
                SPELL_SCHOOL_MASK_NORMAL, dinfo->absorb, dinfo->resist, true, dinfo->blocked_amount, true);
            CleanDamage cl(0, 0, BASE_ATTACK, MELEE_HIT_CRIT);
            me->DealDamage(target, dinfo->damage, &cl);
            me->ProcSkillsAndReactives(false,target,PROC_FLAG_NONE, PROC_HIT_NONE, dinfo->attackType);
            me->CombatStart(target);

            Windwalk_Timer = 0;
        }

        void SetDelayedMeleeDamageEvent(DelayedMeleeDamageEvent* dmdevent)
        { _dmdevent = dmdevent; }

        void TerminateEvent()
        { _dmdevent = NULL; }

        MeleeHitOutcome GetNextAttackMeleeOutCome() const
        {
            return _dmdevent ? MELEE_HIT_NORMAL : bot_ai::GetNextAttackMeleeOutCome();
        }

        bool IsBotImmuneToSpell(SpellInfo const* spellInfo) const
        {
            //PLACEHOLDER BLADESTORM
            //return !spellInfo->HasEffect(SPELL_EFFECT_HEAL);
            return bot_ai::IsBotImmuneToSpell(spellInfo);
        }

        float GetBotArmorPenetrationCoef() const
        {
            //return _dmdevent ? 0.5f : bot_ai::GetBotArmorPenetrationCoef();
            return 0.5f;
        }

        float GetSpellMiscValue(uint32 basespell, uint8 offset) const
        {
            switch (basespell)
            {
                case CRITICAL_STRIKE_1:
                    return offset == 0 ? criticalStikeMult : 0;
                case MIRROR_IMAGE_1:
                    return offset == 0 ? illusionsCount : 0;
                default:
                    return 0;
            }
        }

        //void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        //{
        //    uint32 spellId = spellInfo->Id;
        //    uint8 lvl = me->getLevel();
        //    float fdamage = float(damage);
        //    //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
        //    if (!crit)
        //    {
        //        float aftercrit = 0.f;
        //        ////Incite: 15% additional critical chance for Cleave, Heroic Strike and Thunder Clap
        //        //if (lvl >= 15 && spellId == GetSpell(CLEAVE_1) /*|| spellId == HEROICSTRIKE || spellId == THUNDERCLAP*/)
        //        //    aftercrit += 15.f;

        //        //second roll (may be illogical)
        //        if (aftercrit > 0.f)
        //            crit = roll_chance_f(aftercrit);
        //    }

        //    //2) apply bonus damage mods
        //    float pctbonus = 0.0f;
        //    if (crit)
        //    {
        //        //!!!Melee spell damage is not yet critical, all reduced by half
        //        //Impale: 20% crit damage bonus for all abilities
        //        if (lvl >= 20)
        //            pctbonus += 0.10f;
        //    }

        //    ////Improved Rend: 20% bonus damage for Rend
        //    //if (spellId == GetSpell(REND_1))
        //    //    pctbonus += 0.2f;

        //    damage = int32(fdamage * (1.0f + pctbonus));
        //}

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if (spellId == GetSpell(WINDWALK_1))
            {
                Windwalk_Timer = 30000; //TODO:
                me->RemoveMovementImpairingAuras(true);
                me->PlayDistanceSound(SOUND_FREEZE_IMPACT_WINDWALK, !IAmFree() ? master : NULL);

                uint32 dur = 30000;
                if (Aura* aura = me->GetAura(spellId))
                {
                    aura->SetDuration(dur);
                    aura->SetMaxDuration(dur);
                }
                if (Aura* aura = me->GetAura(TRANSPARENCY))
                {
                    aura->SetDuration(dur);
                    aura->SetMaxDuration(dur);
                }

                if (GetHealthPCT(me) < 25 || !HasRole(BOT_ROLE_DPS))
                    me->AttackStop();

                //SpellEffectSanctuary
                me->getHostileRefManager().UpdateVisibility();
                AttackerSet attackers = me->getAttackers();
                for (AttackerSet::const_iterator itr = attackers.begin(); itr != attackers.end();)
                {
                    if (!(*itr)->CanSeeOrDetect(me))
                        (*(itr++))->AttackStop();
                    else
                        ++itr;
                }

                me->m_lastSanctuaryTime = getMSTime();
            }

            if (spellId == GetSpell(MIRROR_IMAGE_1))
            {
                MirrorImageStart();
            }

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) { }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            //Illusions deal no damage
            if (IsTempBot())
            {
                //manually add threat as if damage was done
                if (victim->GetTypeId() != TYPEID_PLAYER)
                    victim->AddThreat(me, float(damage * 2));

                damage = 0;
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage)
        {
            //illusions take twice damage
            if (IsTempBot())
            {
                damage *= 2;
                //return;
            }
            if (illusion_Fade)
            {
                damage = 0;
                return;
            }
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u)
        {
            OnOwnerDamagedBy(u);
        }

        void OnBotDespawn(Creature* /*summon*/)
        {}

        void UnsummonAll()
        {
            while (!_illusionGuids.empty())
            {
                std::list<uint64>::iterator itr = _illusionGuids.begin();
                if (Creature* illusion = ObjectAccessor::GetCreatureOrPetOrVehicle(*me, ObjectGuid(*itr)))
                    if (illusion->GetBotAI())
                        illusion->GetBotAI()->JustDied(NULL);

                _illusionGuids.erase(itr);
            }
        }

        void Reset()
        {
            _dmdevent = NULL;
            Windwalk_Timer = 0;
            criticalStikeMult = 1;
            illusionsCount = 0;
            illusion_Fade = false;

            me->setPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 75);

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (Windwalk_Timer > diff)          Windwalk_Timer -= diff;
            else if (Windwalk_Timer > 0)        Windwalk_Timer = 0;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();

 /*Special*/lvl >= 10 ? InitSpellMap(WINDWALK_1) : RemoveSpell(WINDWALK_1);
 /*Special*/lvl >= 20 ? InitSpellMap(MIRROR_IMAGE_1) : RemoveSpell(MIRROR_IMAGE_1);
        }

        void ApplyClassPassives()
        {
            uint8 level = me->getLevel();

            RefreshAura(SPELL_BURNING_BLADE_BLADEMASTER);

            criticalStikeMult =
                level < 10 ? 1 :
                level < 30 ? 2 :
                level < 50 ? 3 :
                level < 82 ? 4 : 5;

            illusionsCount =
                level < 20 ? 0 :
                level < 40 ? 1 :
                level < 70 ? 2 : 3;
                //level < 83 ? 3 : 4;
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case WINDWALK_1:
                case MIRROR_IMAGE_1:
                    return true;
                default:
                    break;
            }

            return false;
        }

    private:
        DelayedMeleeDamageEvent* _dmdevent;
        std::list<uint64> _illusionGuids;
        Position _illusPos[MAX_ILLUSION_POSITIONS];

        uint32 Windwalk_Timer;
        uint8 criticalStikeMult;
        uint8 illusionsCount;
        bool illusion_Fade;

        enum BlademasterBaseSpells
        {
            WINDWALK_1                              = SPELL_NETHERWALK,
            MIRROR_IMAGE_1                          = SPELL_MIRROR_IMAGE_BM,
            CRITICAL_STRIKE_1                       = SPELL_CRITICAL_STRIKE
        };
        enum BlademasterPassives
        {
        //Talents
        //other
        };
        enum BlademasterSpecial
        {
            TRANSPARENCY                            = SPELL_TRANSPARENCY_50,
            BLACK_COLOR                             = SPELL_VERTEX_COLOR_BLACK,
            STUN_FREEZE                             = SPELL_STUN_FREEZE_ANIM
        };
    };
};

void AddSC_blademaster_bot()
{
    new blademaster_bot();
}
