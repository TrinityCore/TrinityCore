#include "bot_ai.h"
#include "botmgr.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
/*
Blademaster NpcBot (by Trickerer onlysuffering@gmail.com)
DISABLED: movement mechanics incompatibility
Complete - 75%
TODO: BLADESTORM, Convert illusions to bot_pet_ai
*/

#define MAX_ILLUSION_POSITIONS 4
#define MIRROR_IMAGE_DURATION 90000

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
    NPC_MIRROR_IMAGE                        = 70552,
    TRANSPARENCY                            = SPELL_TRANSPARENCY_50,
    BLACK_COLOR                             = SPELL_VERTEX_COLOR_BLACK,
    STUN_FREEZE                             = SPELL_STUN_FREEZE_ANIM,

    MIRROR_COST                             = 125 * 5
};

static const uint32 Blademaster_spells_support_arr[] =
{ MIRROR_IMAGE_1, WINDWALK_1 };

static const std::vector<uint32> Blademaster_spells_support(FROM_ARRAY(Blademaster_spells_support_arr));

class blademaster_bot : public CreatureScript
{
public:
    blademaster_bot() : CreatureScript("blademaster_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new blademaster_botAI(creature);
    }

    struct blademaster_botAI : public bot_ai
    {
/*
        bool GossipHello(Player* player) override
        {
            return OnGossipHello(player, 0);
        }

        bool GossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            return OnGossipSelect(player, me, sender, action);
        }

        bool GossipSelectCode(Player* player, uint32 sender, uint32 action, char const* code) override
        {
            return OnGossipSelectCode(player, me, sender, action, code);
        }
*/
    private:
        //DelayedMeleeDamageEvent - Blademaster
        //deals critical damage, resets attack timer and sends fake log
        class DelayedMeleeDamageEvent : public BasicEvent
        {
            public:
                DelayedMeleeDamageEvent(Creature* bot, ObjectGuid targetGuid, bool windwalk) :
                  _bot(bot), _targetGuid(targetGuid), _windwalk(windwalk), _dinfo(nullptr) { }

                void SetDamageInfo(CalcDamageInfo* dinfo)
                {
                    _dinfo = dinfo;
                }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    (dynamic_cast<blademaster_botAI*>(_bot->GetAI()))->CriticalStrikeFinish(_targetGuid, _dinfo, _windwalk);

                    if (_dinfo)
                        delete _dinfo;
                    return true;
                }

            private:
                Creature* _bot;
                ObjectGuid _targetGuid;
                bool _windwalk;
                CalcDamageInfo* _dinfo;
                DelayedMeleeDamageEvent(DelayedMeleeDamageEvent const&);
        };

        class EventTerminateEvent : public BasicEvent
        {
            public:
                EventTerminateEvent(Creature* bot) : _bot(bot) { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    (dynamic_cast<blademaster_botAI*>(_bot->GetAI()))->TerminateEvent();
                    return true;
                }

            private:
                Creature* _bot;
                EventTerminateEvent(EventTerminateEvent const&);
        };

        class IllusionUnsummonEvent : public BasicEvent
        {
            public:
                IllusionUnsummonEvent(Creature const* bot) : _bot(bot) { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    (dynamic_cast<blademaster_botAI*>(_bot->GetAI()))->UnsummonAll();

                    return true;
                }

            private:
                Creature const* _bot;
                IllusionUnsummonEvent(IllusionUnsummonEvent const&);
        };

        class DelayedIllusionSummonEvent : public BasicEvent
        {
            public:
                DelayedIllusionSummonEvent(Creature const* bot) : _bot(bot) { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    (dynamic_cast<blademaster_botAI*>(_bot->GetAI()))->MirrorImageFinish();

                    return true;
                }

            private:
                Creature const* _bot;
                DelayedIllusionSummonEvent(DelayedIllusionSummonEvent const&);
        };

        class DisappearEvent : public BasicEvent
        {
            public:
                DisappearEvent(Creature* bot) : _bot(bot) { }

            protected:
                bool Execute(uint64 /*e_time*/, uint32 /*p_time*/)
                {
                    (dynamic_cast<blademaster_botAI*>(_bot->GetAI()))->MirrorImageMid();

                    return true;
                }

            private:
                Creature* _bot;
                DisappearEvent(DisappearEvent const&);
        };

        void _calcIllusionPositions()
        {
            float x = me->m_positionX;
            float y = me->m_positionY;
            float z = me->m_positionZ;
            float o = me->GetOrientation();

            //X     X
            //   C
            //X     X
            //
            //C - caster (Blademaster)
            //X - new positions (1-3 illusions + blademaster)

            float dist = 3.f; //not too far - 3 for x and y seems to be way to go
            for (uint8 i = 0; i != MAX_ILLUSION_POSITIONS; ++i)
            {
                _illusPos[i].m_positionX = x + ((i <= 1) ? +dist : -dist); // +2+2-2-2
                _illusPos[i].m_positionY = y + (!(i & 1) ? +dist : -dist); // +2-2+2-2
                _illusPos[i].m_positionZ = z;
                me->UpdateAllowedPositionZ(_illusPos[i].m_positionX, _illusPos[i].m_positionY, _illusPos[i].m_positionZ);
                _illusPos[i].SetOrientation(o);
            }
        }

    public:
        blademaster_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_BM;
            //Blademaster cannot be disarmed
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM, true);
        }

        void IllusionsCheck(uint32 diff)
        {
            if (!me->IsAlive())
                return;
            if (Illusions_Check_Timer > diff)
                return;

            Illusions_Check_Timer = 250;

            if (_illusionGuids.empty())
                return;

            for (std::list<ObjectGuid>::const_iterator itr = _illusionGuids.begin(); itr != _illusionGuids.end(); ++itr)
            {
                Creature* ill = ObjectAccessor::GetCreature(*me, *itr);
                if (!ill)
                {
                    TC_LOG_ERROR("entities.player", "bm_bot::IllusionsCheck(): unit %u is not found in world!", (*itr).GetCounter());
                    continue;
                }

                ill->SetCanModifyStats(false);
                float hpct = ill->GetHealthPct();
                float mpct = (float(ill->GetPower(POWER_MANA)) * 100.f) / float(ill->GetMaxPower(POWER_MANA));

                ill->SetMaxHealth(me->GetMaxHealth());
                ill->SetHealth(uint32(0.5f + float(ill->GetMaxHealth()) * hpct / 100.f));
                ill->SetMaxPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
                ill->SetPower(POWER_MANA, uint32(0.5f + float(ill->GetMaxPower(POWER_MANA)) * mpct / 100.f));
                ill->SetFloatValue(UNIT_FIELD_MINDAMAGE, me->GetFloatValue(UNIT_FIELD_MINDAMAGE));
                ill->SetFloatValue(UNIT_FIELD_MAXDAMAGE, me->GetFloatValue(UNIT_FIELD_MAXDAMAGE));
                ill->m_modAttackSpeedPct[BASE_ATTACK] = me->m_modAttackSpeedPct[BASE_ATTACK];
            }
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            //custom
            if (_dmdevent)
                return false;
            if (IsTempBot()) //Illusion etc.
                return false;

            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;

            return bot_ai::doCast(victim, spellId);
        }

        void UpdateAI(uint32 diff) override
        {
            IllusionsCheck(diff);

            if (!GlobalUpdate(diff))
                return;

            if (IsPotionReady() && !IsTempBot())
            {
                if (me->GetPower(POWER_MANA) < MIRROR_COST)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            //CheckRacials(diff);

            CheckWindWalk(diff);
            CheckMirrorImage(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (IsCasting())
                return;

            if (!CheckAttackTarget())
                return;

            Attack(diff);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void AttackStart(Unit*) override { }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        bool CanEat() const override { return Windwalk_Timer <= GetLastDiff() && !illusion_Fade; }
        bool CanSeeEveryone() const override { return Windwalk_Timer > GetLastDiff(); }

        void BreakCC(uint32 diff) override
        {
            if (me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
            {
                if (IsSpellReady(WINDWALK_1, diff) && !IsTank(me) && Rand() < 30 &&
                    doCast(me, GetSpell(WINDWALK_1)))
                    return;
            }
            bot_ai::BreakCC(diff);
        }

        void Attack(uint32 /*diff*/)
        {
            StartAttack(opponent, IsMelee());

            MoveBehind(opponent);
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
                    if (Windwalk_Timer > GetLastDiff())
                    {
                        CriticalStrike(victim, true);
                        return;
                    }
                    //Critical Strike: 15% to deal x2,x3, etc... damage
                    else if (criticalStikeMult >= 2 && !CCed(me, true) && roll_chance_f(15.f))
                    {
                        CriticalStrike(victim);
                        return;
                    }
                }

                DoMeleeAttackIfReady();
                return;
            }
        }

        void CheckAttackState() override
        {
            if (me->GetVictim())
            {
                if (HasRole(BOT_ROLE_DPS))
                    DoBMMeleeAttackIfReady();
            }
        }

        void CheckWindWalk(uint32 diff)
        {
            if (!IsSpellReady(WINDWALK_1, diff) || Windwalk_Timer > GetLastDiff() || illusion_Fade || IsCasting() ||
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
                Unit* u = IsMelee() ? me->GetVictim() : nullptr;

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
            //if (IAmFree())
            //    return;
            if (!IsSpellReady(MIRROR_IMAGE_1, diff) || !me->IsInCombat() || !illusionsCount || illusion_Fade ||
                !HasRole(BOT_ROLE_DPS) || IsCasting() || Rand() > 20)
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

            ASSERT(!illusion_Fade);
            illusion_Fade = true;

            //OKAY

            //destroy existing illusions if any
            UnsummonAll();
            //mirror image renders BM invulnerable for a short period of time,
            //removing all but passive auras
            Unit::AuraMap const auras = me->GetOwnedAuras(); //copy
            for (Unit::AuraMap::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            {
                Aura* aura = iter->second;
                if (aura->GetSpellInfo()->Attributes & SPELL_ATTR0_PASSIVE)
                    continue;
                if (aura->GetId() == SPELL_BURNING_BLADE_BLADEMASTER)
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
            DisappearEvent* devent = new DisappearEvent(me);
            Events.AddEvent(devent, Events.CalculateTime(std::chrono::milliseconds(300))); //immediatelly (almost)
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
            DelayedIllusionSummonEvent* disevent = new DelayedIllusionSummonEvent(me);
            Events.AddEvent(disevent, Events.CalculateTime(std::chrono::milliseconds(1250))); //1000 ms disappear time + 250 ms buffer
        }

        void MirrorImageFinish()
        {
            illusion_Fade = false;
            me->RemoveAura(BLACK_COLOR);
            me->RemoveAura(STUN_FREEZE);
            if (!me->IsInWorld() ||
                !me->IsAlive()/* || CCed(me)*/) //this is just ensurance
                return;

            _calcIllusionPositions();

            std::set<uint8> usedposs;

            for (uint8 i = 0; i != illusionsCount; ++i)
            {
                Creature* illusion = me->SummonCreature(NPC_MIRROR_IMAGE, *me, TEMPSUMMON_MANUAL_DESPAWN);
                if (!illusion)
                    continue;

                if (!IAmFree())
                    master->GetBotMgr()->AddBot(illusion, false);

                illusion->SetCreatorGUID(me->GetGUID()); //TempSummon* Map::SummonCreature()

                //copy visuals
                //illusion->SetEntry(me->GetEntry());
                illusion->UpdateEntry(me->GetEntry());
                illusion->SetFaction(me->GetFaction());
                illusion->SetLevel(me->GetLevel());
                illusion->SetDisplayId(me->GetDisplayId());
                illusion->SetNativeDisplayId(me->GetDisplayId());
                illusion->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0));

                //copy stats
                illusion->SetCanModifyStats(false);
                illusion->SetMaxHealth(me->GetMaxHealth());
                illusion->SetHealth(me->GetHealth());
                illusion->SetMaxPower(POWER_MANA, me->GetMaxPower(POWER_MANA));
                illusion->SetPower(POWER_MANA, me->GetPower(POWER_MANA));
                illusion->SetFloatValue(UNIT_FIELD_MINDAMAGE, me->GetFloatValue(UNIT_FIELD_MINDAMAGE));
                illusion->SetFloatValue(UNIT_FIELD_MAXDAMAGE, me->GetFloatValue(UNIT_FIELD_MAXDAMAGE));
                illusion->m_modAttackSpeedPct[BASE_ATTACK] = me->m_modAttackSpeedPct[BASE_ATTACK];

                illusion->BotStopMovement();
                while (true)
                {
                    //move illusion to a random corner
                    uint8 j = urand(0, MAX_ILLUSION_POSITIONS - 1);
                    if (usedposs.find(j) == usedposs.end())
                    {
                        illusion->GetMotionMaster()->MovePoint(me->GetMapId(), _illusPos[j]);
                        //illusion->Relocate(_illusPos[j]);
                        usedposs.insert(j);
                        break;
                    }
                }

                illusion->GetBotAI()->SetBotCommandState(BOT_COMMAND_COMBATRESET);

                _illusionGuids.push_back(illusion->GetGUID());
            }

            SetBotCommandState(BOT_COMMAND_COMBATRESET);

            for (uint8 i = 0; i != MAX_ILLUSION_POSITIONS; ++i)
            {
                if (usedposs.find(i) == usedposs.end())
                {
                    //me->BotStopMovement();
                    me->GetMotionMaster()->MovePoint(me->GetMapId(), _illusPos[i]);
                    //me->Relocate(_illusPos[i]);
                    //usedposs.insert(i);
                    break;
                }
            }

            uint8 counter = 0;
            uint8 r = urand(0, uint8(_illusionGuids.size() - 1));
            uint32 phaseMask = IAmFree() ? PHASEMASK_NORMAL : master->GetPhaseMask();

            for (std::list<ObjectGuid>::const_iterator itr = _illusionGuids.begin(); itr != _illusionGuids.end(); ++itr)
            {
                if (Creature* illusion = ObjectAccessor::GetCreature(*me, *itr))
                    illusion->SetPhaseMask(phaseMask, true);

                if (counter == r)
                    me->SetPhaseMask(phaseMask, true);
                else
                    ++counter;
            }

            me->GetCombatManager().EndAllPvECombat();

            if (me->GetPhaseMask() != phaseMask)
                me->SetPhaseMask(phaseMask, true);

            //me->setAttackTimer(BASE_ATTACK, 3000);
            //waitTimer += 800;
            SetSpellCooldown(MIRROR_IMAGE_1, 8000);

            //EVENT
            IllusionUnsummonEvent* unsevent = new IllusionUnsummonEvent(me);
            Events.AddEvent(unsevent, Events.CalculateTime(std::chrono::milliseconds(MIRROR_IMAGE_DURATION)));
        }

        void CriticalStrike(Unit* target, bool windwalk = false)
        {
            //Okay critical strike must have jump and strike animation, doing delayed damage
            _dmdevent = new DelayedMeleeDamageEvent(me, target->GetGUID(), windwalk);

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
            me->CalculateMeleeDamage(target, dinfo, BASE_ATTACK);

            me->SetFloatValue(UNIT_FIELD_MINDAMAGE, mindam);
            me->SetFloatValue(UNIT_FIELD_MAXDAMAGE, maxdam);

            _dmdevent->SetDamageInfo(dinfo);
            Events.AddEvent(_dmdevent, Events.CalculateTime(std::chrono::milliseconds(250)));

            BotJumpInPlaceInFrontOf(target, 0.25f, 4.1f); //jump - DO NOT CHANGE
            me->CastSpell(target, SPELL_COMBAT_SPECIAL_2H_ATTACK, true); //strike anim
            me->resetAttackTimer(BASE_ATTACK);
        }

        void CriticalStrikeFinish(ObjectGuid targetGuid, CalcDamageInfo* calcdinfo, bool /*windwalk*/)
        {
            EventTerminateEvent* etevent = new EventTerminateEvent(me);
            Events.AddEvent(etevent, Events.CalculateTime(std::chrono::milliseconds(750)));

            if (!me->IsInWorld() || !me->IsAlive() || CCed(me))
            {
                Windwalk_Timer = 0;
                return;
            }

            Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
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

            DamageInfo dinfo(*calcdinfo, 0);

            me->SendSpellNonMeleeDamageLog(target, CRITICAL_STRIKE_1,
                dinfo.GetDamage() + dinfo.GetAbsorb() + dinfo.GetResist() + dinfo.GetBlock(),
                SPELL_SCHOOL_MASK_NORMAL, dinfo.GetAbsorb(), dinfo.GetResist(), false, dinfo.GetBlock(), true, false);
            CleanDamage cl(0, 0, BASE_ATTACK, MELEE_HIT_CRIT);
            Unit::DealDamage(me, target, dinfo.GetDamage(), &cl);
            Unit::ProcSkillsAndAuras((Unit*)me, calcdinfo->Target, calcdinfo->ProcAttacker, calcdinfo->ProcVictim, 0, 0, calcdinfo->HitInfo, nullptr, &dinfo, nullptr);
            me->AtTargetAttacked(target, false);

            me->resetAttackTimer(BASE_ATTACK);
            Windwalk_Timer = 0;
        }

        void TerminateEvent()
        { _dmdevent = nullptr; }

        MeleeHitOutcome GetNextAttackMeleeOutCome() const override
        {
            return _dmdevent ? MELEE_HIT_NORMAL : bot_ai::GetNextAttackMeleeOutCome();
        }

        float GetBotArmorPenetrationCoef() const override
        {
            return 80.0f + bot_ai::GetBotArmorPenetrationCoef();
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 spellId = spell->Id;

            if (spellId == GetSpell(WINDWALK_1))
            {
                Windwalk_Timer = 30000; //TODO:
                me->RemoveMovementImpairingAuras(true);
                me->PlayDistanceSound(SOUND_FREEZE_IMPACT_WINDWALK, !IAmFree() ? master : nullptr);

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
                me->GetCombatManager().SuppressPvPCombat();
                Unit::AttackerSet const& attackers = me->getAttackers();
                for (Unit::AttackerSet::const_iterator itr = attackers.begin(); itr != attackers.end();)
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

        void SpellHitTarget(WorldObject* /*wtarget*/, SpellInfo const* /*spell*/) override
        {
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            //Illusions deal no damage
            if (IsTempBot())
            {
                //manually add threat as if damage was done
                if (victim->GetTypeId() == TYPEID_UNIT)
                    victim->GetThreatManager().AddThreat(me, float(damage + damage));

                damage = 0;
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& damage) override
        {
            //illusions take twice as much damage
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
            if (!u)
                return;
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u) override
        {
            if (!u)
                return;
            OnOwnerDamagedBy(u);
        }

        void JustDied(Unit* u) override
        {
            TerminateEvent();

            if (IsTempBot())
                if (me->GetCreatorGUID().IsCreature())
                    if (Unit* bot = ObjectAccessor::GetUnit(*me, me->GetCreatorGUID()))
                        if (bot->ToCreature()->IsNPCBot())
                            bot->ToCreature()->OnBotDespawn(me);

            bot_ai::JustDied(u);

            if (!IsTempBot())
                UnsummonAll();
        }

        void OnBotDespawn(Creature* summon) override
        {
            if (!summon)
                return;

            for (std::list<ObjectGuid>::iterator itr = _illusionGuids.begin(); itr != _illusionGuids.end(); ++itr)
            {
                if (*itr == summon->GetGUID())
                {
                    _illusionGuids.erase(itr);
                    return;
                }
            }
        }

        void UnsummonAll() override
        {
            while (!_illusionGuids.empty())
            {
                std::list<ObjectGuid>::iterator itr = _illusionGuids.begin();
                if (Creature* illusion = ObjectAccessor::GetCreature(*me, *itr))
                    illusion->AI()->JustDied(nullptr);
                else
                    _illusionGuids.erase(itr);
            }
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case CRITICAL_STRIKE_1:
                    return criticalStikeMult;
                case MIRROR_IMAGE_1:
                    return illusionsCount;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            UnsummonAll();

            _dmdevent = nullptr;
            Windwalk_Timer = 0;
            criticalStikeMult = 1;
            illusionsCount = 0;
            illusion_Fade = false;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (Windwalk_Timer > diff)          Windwalk_Timer -= diff;
            if (Illusions_Check_Timer > diff)   Illusions_Check_Timer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 75);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();

 /*Special*/lvl >= 10 ? InitSpellMap(WINDWALK_1) : RemoveSpell(WINDWALK_1);
 /*Special*/lvl >= 20 ? InitSpellMap(MIRROR_IMAGE_1) : RemoveSpell(MIRROR_IMAGE_1);

            criticalStikeMult =
                lvl < 10 ? 1 :
                lvl < 30 ? 2 :
                lvl < 50 ? 3 :
                lvl < 82 ? 4 : 5;

            illusionsCount =
                lvl < 20 ? 0 :
                lvl < 40 ? 1 :
                lvl < 70 ? 2 : 3;
        }

        void ApplyClassPassives() const override
        {
            RefreshAura(SPELL_BURNING_BLADE_BLADEMASTER);
        }

        bool CanUseManually(uint32 basespell) const override
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

        //std::vector<uint32> const* GetDamagingSpellsList() const
        //{
        //    return &Blademaster_spells_damage;
        //}
        //std::vector<uint32> const* GetCCSpellsList() const
        //{
        //    return &Blademaster_spells_cc;
        //}
        //std::vector<uint32> const* GetHealingSpellsList() const
        //{
        //    return &Blademaster_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const
        {
            return &Blademaster_spells_support;
        }

    private:
        DelayedMeleeDamageEvent* _dmdevent;
        std::list<ObjectGuid> _illusionGuids;
        Position _illusPos[MAX_ILLUSION_POSITIONS];

        uint32 Windwalk_Timer;
        uint32 Illusions_Check_Timer;
        uint8 criticalStikeMult;
        uint8 illusionsCount;
        bool illusion_Fade;
    };
};

void AddSC_blademaster_bot()
{
    new blademaster_bot();
}
