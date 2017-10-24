#include "bot_ai.h"
//#include "botmgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
/*
Hunter NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - around 35%
TODO:
*/
class hunter_bot : public CreatureScript
{
public:
    hunter_bot() : CreatureScript("hunter_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new hunter_botAI(creature);
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

    struct hunter_botAI : public bot_minion_ai
    {
        hunter_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_HUNTER;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_HUNTER) != SPELL_CAST_OK)
                return false;

            return bot_ai::doCast(victim, spellId, triggered);
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
        void KilledUnit(Unit*) { }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void Counter(uint32 diff)
        {
            if (IsCasting() || Rand() > 35)
                return;

            Unit* target = NULL;

            if (IsSpellReady(SCATTER_SHOT_1, diff, false, 10000) && HasRole(BOT_ROLE_DPS) && Rand() < 40)
            {
                target = FindCastingTarget(15, 0, false, GetSpell(SCATTER_SHOT_1));
                temptimer = GC_Timer;
                if (target && doCast(target, GetSpell(SCATTER_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            if (!target && IsSpellReady(WYVERN_STING_1, diff, true, 10000) && HasRole(BOT_ROLE_DPS) && Rand() < 70)
            {
                target = FindCastingTarget(35, 5, false, GetSpell(WYVERN_STING_1));
                if (target && doCast(target, GetSpell(WYVERN_STING_1)))
                    return;
            }
            //if (!target && FREEZING_ARROW && Trap_cd <= 10000 && Rand() < 40)
            //{
            //    target = FindCastingTarget(40, 0, false, FREEZING_ARROW);
            //    temptimer = GC_Timer;
            //    if (target && doCast(target, FREEZING_ARROW))
            //    {
            //        Trap_cd = 20000;
            //        GC_Timer = temptimer;
            //        return;
            //    }
            //}
            if (!target && IsSpellReady(SCARE_BEAST_1, diff, true, 7500) && Rand() < 35)
            {
                target = FindCastingTarget(30, 0, false, GetSpell(SCARE_BEAST_1));
                if (target && doCast(target, GetSpell(SCARE_BEAST_1)))
                {
                    GC_Timer = 800;
                    return;
                }
            }
            if (!target && IsSpellReady(SILENCING_SHOT_1, diff, false, 7500) && Rand() < 30)
            {
                target = FindCastingTarget(35, 5, false, GetSpell(SILENCING_SHOT_1));
                temptimer = GC_Timer;
                if (target && doCast(target, GetSpell(SILENCING_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
        }

        void CheckScatter(uint32 diff)
        {
            if (!IsSpellReady(SCATTER_SHOT_1, diff, false) || !HasRole(BOT_ROLE_DPS) || IsCasting() || Rand() > 50)
                return;

            if (Unit* target = FindStunTarget(15))
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(SCATTER_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            SetSpellCooldown(SCATTER_SHOT_1, 1000); //fail
        }

        void CheckWyvernSting(uint32 diff)
        {
            if (!IsSpellReady(WYVERN_STING_1, diff, false) || !HasRole(BOT_ROLE_DPS) || IsCasting() || Rand() > 50)
                return;

            if (Unit* target = FindStunTarget(35))
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(WYVERN_STING_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            SetSpellCooldown(WYVERN_STING_1, 1000); //fail
        }

        void CheckFreezingArrow(uint32 diff)
        {
            //Freezing Trap shares cooldown with traps
            if (!GetSpell(FREEZING_ARROW_1) || Trap_cd > diff || IsCasting() || Rand() > 75)
                return;

            if (Unit* target = FindStunTarget(40))
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(FREEZING_ARROW_1)))
                {
                    GC_Timer = temptimer;
                    Trap_cd = 20000;
                    return;
                }
            }

            Trap_cd = 1000; //fail
        }

        void CheckTraps(uint32 diff)
        {
            if (!GetSpell(FROST_TRAP_1) || Trap_cd > diff || IsCasting() || Rand() > 90)
                return;

            Unit* target = me->GetVictim();
            if (!(target && me->GetDistance(target) < 6 && me->HasInArc(M_PI, target) &&
                IsInBotParty(target->GetVictim())))
                target = NULL;
            if (!target)
                target = FindAOETarget(3.f, true);

            if (target)
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(FROST_TRAP_1)))
                {
                    GC_Timer = temptimer;
                    Trap_cd = 20000;
                    return;
                }
            }

            Trap_cd = 500; //fail
        }

        void CheckScare(uint32 diff)
        {
            if (!IsSpellReady(SCARE_BEAST_1, diff) || IsCasting() || Rand() > 35)
                return;

            if (Unit* scareTarget = FindFearTarget())
            {
                if (doCast(scareTarget, GetSpell(SCARE_BEAST_1), true))
                {
                    GC_Timer = 800;
                    return;
                }
            }

            SetSpellCooldown(SCARE_BEAST_1, 1500); //fail
        }

        void CheckAspects(uint32 diff)
        {
            if (Aspect_Timer > diff || GC_Timer > diff || IsCasting() || Feasting() || Rand() > 35)
                return;

            uint32 ASPECT_OF_THE_VIPER = GetSpell(ASPECT_OF_THE_VIPER_1);
            uint32 ASPECT_OF_THE_PACK = GetSpell(ASPECT_OF_THE_PACK_1);
            if (!ASPECT_OF_THE_VIPER && !ASPECT_OF_THE_PACK)
                return;

            uint32 needaspect = 0;
            uint8 pct = GetManaPCT(me);

            if (ASPECT_OF_THE_VIPER && pct < 25)
                needaspect = ASPECT_OF_THE_VIPER;
            else if (ASPECT_OF_THE_PACK && (pct > 70 || !Aspect))
                needaspect = ASPECT_OF_THE_PACK;

            if (!needaspect || (needaspect == Aspect && HasAuraName(me, needaspect)))
            {
                Aspect_Timer = 2000;
                return;
            }

            if (Aspect)
                me->RemoveAurasDueToSpell(Aspect);

            if (doCast(me, needaspect))
            {
                Aspect = needaspect;
                GC_Timer = 800;
                return;
            }
        }

        void doDefend(uint32 diff)
        {
            //No GCD abilities
            if (!IsSpellReady(FEIGN_DEATH_1, diff, false) && !IsSpellReady(DETERRENCE_1, diff, false))
                return;
            if (IsTank() || Rand() > 35)
                return;

            AttackerSet b_attackers = me->getAttackers();
            bool cast = false;

            if (b_attackers.size() == 1)
            {
                if (Creature* cre = (*b_attackers.begin())->ToCreature())
                {
                    if (cre->isWorldBoss() || cre->IsDungeonBoss() || cre->GetMaxHealth() > me->GetMaxHealth() * 10)
                    {
                        cast = true;
                        //need feign death
                        SetSpellCooldown(DETERRENCE_1, std::max<uint32>(GetSpellCooldown(DETERRENCE_1), diff + 500));
                    }
                }
            }
            else
                cast = (uint8(b_attackers.size()) > (GetHealthPCT(me) > 20 ? 1 : 0));

            if (!cast || b_attackers.empty())
            {
                //delay next try
                SetSpellCooldown(FEIGN_DEATH_1, std::max<uint32>(GetSpellCooldown(FEIGN_DEATH_1), 1000));
                SetSpellCooldown(DETERRENCE_1, std::max<uint32>(GetSpellCooldown(DETERRENCE_1), 1000));
                return;
            }

            if (IsSpellReady(FEIGN_DEATH_1, diff, false) && (*b_attackers.begin())->getAttackers().size() > 1)
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                temptimer = GC_Timer;
                if (doCast(me, GetSpell(FEIGN_DEATH_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            if (IsSpellReady(DETERRENCE_1, diff, false))
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                temptimer = GC_Timer;
                if (doCast(me, GetSpell(DETERRENCE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
        }

        void CheckAutoShot()
        {
            //Auto Shot is always present
            //if (!AUTO_SHOT)
            //    return;

            Unit* target = me->GetVictim();
            if (!target)
                return;

            if (!HasRole(BOT_ROLE_DPS))
                return;

            if (IsCasting())
                return;

            if (Spell* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id != AUTO_SHOT_1)
                {
                    ////casting some other autorepeat spell, wtf?
                    //TC_LOG_ERROR("entities.player", "CheckAutoShot(): Bot %s is casting autorepeatable spell %u (%s) during check!",
                    //    me->GetName().c_str(), shot->GetSpellInfo()->Id, shot->GetSpellInfo()->SpellName[0]);
                    return;
                }
                else if (shot->m_targets.GetUnitTarget() != target)
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }

            float dist = me->GetExactDist(target);
            if (dist < 5 || dist > 35)
                return;

            temptimer = GC_Timer;
            if (doCast(target, AUTO_SHOT_1))
            {
                GC_Timer = temptimer;
                return;
            }
        }

        void CheckTranquil(uint32 diff)
        {
            if (!IsSpellReady(TRANQ_SHOT_1, diff, false) || Rand() > 35) //No GCD
                return;

            //First check current target
            Unit* target = me->GetVictim();
            if (target)
            {
                Unit::AuraMap const &auras = target->GetOwnedAuras();
                for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    SpellInfo const* spellInfo = itr->second->GetSpellInfo();
                    if (spellInfo->Dispel != DISPEL_MAGIC && spellInfo->Dispel != DISPEL_ENRAGE) continue;
                    if (spellInfo->Attributes & (SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE)) continue;
                    //if (spellInfo->AttributesEx & SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR) continue;
                    AuraApplication const* aurApp = itr->second->GetApplicationOfTarget(target->GetGUID());
                    if (aurApp && aurApp->IsPositive())
                    {
                        temptimer = GC_Timer;
                        //me->InterruptNonMeleeSpells(true, AUTO_SHOT);
                        if (doCast(target, GetSpell(TRANQ_SHOT_1)))
                        {
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                }
            }

            target = FindTranquilTarget();
            if (target)
            {
                temptimer = GC_Timer;
                //me->InterruptNonMeleeSpells(true, AUTO_SHOT);
                if (doCast(target, GetSpell(TRANQ_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            SetSpellCooldown(TRANQ_SHOT_1, 2000); //fail
        }

        void CheckSilence(uint32 diff)
        {
            if (!IsSpellReady(SILENCING_SHOT_1, diff, false) || IsCasting() || Rand() > 50) //No GCD
                return;

            Unit* target = me->GetVictim();
            if (target && target->IsNonMeleeSpellCast(false))
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(SILENCING_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    //return;
                }

                return; //succeed or failed, our hightest priority target casts spell and it must be interrupted above all else
            }

            target = FindCastingTarget(35, 5);
            if (target)
            {
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(SILENCING_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            SetSpellCooldown(SILENCING_SHOT_1, 1000); //fail
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

            if (Potion_cd <= diff && GetHealthPCT(me) < 67)
            {
                temptimer = GC_Timer;
                if (doCast(me, HEALINGPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            if (Potion_cd <= diff && GetManaPCT(me) < 40)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            //Deterrence check
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            {
                if (!me->isMoving())
                    GetInPosition(true);
                return;
            }

            if (!me->IsInCombat())
                DoNonCombatActions(diff);
            else
                doDefend(diff);

            CheckAspects(diff);

            if (master->IsInCombat() || me->IsInCombat())
            {
                CheckTranquil(diff);
                CheckSilence(diff);
            }

            if (!CheckAttackTarget(BOT_CLASS_HUNTER))
            {
                me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                return;
            }

            DoRangedAttack(diff);
        }

        void DoRangedAttack(uint32 diff)
        {
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent, true);
            }
            else
                return;

            Counter(diff);

            CheckAutoShot();
            CheckScare(diff);
            CheckScatter(diff);

            //AttackerSet m_attackers = master->getAttackers();
            //AttackerSet b_attackers = me->getAttackers();
            //float dist = me->GetExactDist(opponent);
            float meleedist = me->GetDistance(opponent);

            //special
            if (IsSpellReady(SCATTER_SHOT_1, diff, false) && HasRole(BOT_ROLE_DPS) && meleedist < 15 && Rand() < 60)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(SCATTER_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
                    me->AttackStop();
                    return;
                }
            }

            //MELEE SECTION
            if (!(meleedist > 5))
            {
                //TRAPS
                CheckTraps(diff);

                //RAPTOR STRIKE
                if (IsSpellReady(RAPTOR_STRIKE_1, diff, false) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
                {
                    temptimer = GC_Timer;
                    if (doCast(opponent, GetSpell(RAPTOR_STRIKE_1), true))
                    {
                        GC_Timer = temptimer;
                        return;
                    }
                }
                //WING CLIP
                if (IsSpellReady(WING_CLIP_1, diff) && (!IsTank() || opponent->isMoving()) &&
                    Rand() < 80 && !opponent->HasAuraWithMechanic(/*(1<<MECHANIC_SNARE)|*/(1<<MECHANIC_ROOT)))
                {
                    if (doCast(opponent, GetSpell(WING_CLIP_1)))
                    {
                        GC_Timer = 1000;
                        return;
                    }
                }
                //DISENGAGE
                if (IsSpellReady(DISENGAGE_1, diff, false) && me->IsInCombat() && !IsTank() &&
                    !me->getAttackers().empty() && me->HasInArc(M_PI, *me->getAttackers().begin()) && Rand() < 30)
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(DISENGAGE_1)))
                        GC_Timer = temptimer;
                }

                return; //don't try to do anything else in melee
            }

            //RANGED SECTION

            //HUNTERS MARK
            if (IsSpellReady(HUNTERS_MARK_1, diff, false) && Rand() < 25 &&
                !HasAuraName(opponent, HUNTERS_MARK_1)) //100 yd range so don't check it
            {
                //Hunter's Mark has exclusive GCD
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(HUNTERS_MARK_1)))
                {
                    markTarget = opponent;
                    GC_Timer = temptimer;
                    //return;
                }
            }

            //FREEZING ARROW
            CheckFreezingArrow(diff);
            CheckWyvernSting(diff);

            //attack range check 1
            if (!(meleedist < 45))
                return;

            //KILL SHOT //No GCD
            if (IsSpellReady(KILL_SHOT_1, diff, false) && HasRole(BOT_ROLE_DPS) && GetHealthPCT(opponent) < 20 && Rand() < 95)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(KILL_SHOT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            //attack range check 2
            if (!(meleedist < 35))
                return;

            //CONCUSSIVE SHOT
            if (IsSpellReady(CONCUSSIVE_SHOT_1, diff) && Rand() < 80)
            {
                if (doCast(opponent, GetSpell(CONCUSSIVE_SHOT_1)))
                {
                    GC_Timer = 800;
                    return;
                }
            }
            //DISTRACTING SHOT
            if (Unit* u = opponent->GetVictim())
            {
                if (IsSpellReady(DISTRACTING_SHOT_1, diff, false) && IsTank() && u != me && !CCed(opponent) &&
                    Rand() < 75 && IsInBotParty(u))
                {
                    temptimer = GC_Timer;
                    if (doCast(opponent, GetSpell(DISTRACTING_SHOT_1)))
                        GC_Timer = temptimer;
                }
            }
            //BLACK ARROW //custom cd condition
            //Black Arrow shares cooldown with traps, but we'll have it only partially
            if (IsSpellReady(BLACK_ARROW_1, diff) && Trap_cd <= 10000 && HasRole(BOT_ROLE_DPS) &&
                opponent->GetHealth() > me->GetMaxHealth()/3 && Rand() < 75)
            {
                if (doCast(opponent, GetSpell(BLACK_ARROW_1)))
                {
                    Trap_cd = 20000;
                    return;
                }
            }
            //RAPID FIRE
            if (IsSpellReady(RAPID_FIRE_1, diff, false) && HasRole(BOT_ROLE_DPS) &&
                opponent->GetHealth() > me->GetMaxHealth() / 2 && Rand() < 25)
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(RAPID_FIRE_1)))
                    GC_Timer = temptimer;
            }
            //EXPLOSIVE SHOT
            if (IsSpellReady(EXPLOSIVE_SHOT_1, diff) && HasRole(BOT_ROLE_DPS))
            {
                if (doCast(opponent, GetSpell(EXPLOSIVE_SHOT_1)))
                    return;

                SetSpellCooldown(EXPLOSIVE_SHOT_1, 500); //fail
            }
            //SCORPID STING //custom cd condition
            if (uint32 SCORPID_STING = GetSpell(SCORPID_STING_1))
            {
                if (GC_Timer <= diff && (ScorpidSting_Timer <= diff || stingTargetGuid != opponent->GetGUID()))
                {
                    Aura* sSting = opponent->GetAura(SCORPID_STING);
                    if (sSting && sSting->GetDuration() > 3000)
                    {
                        stingTargetGuid = opponent->GetGUID();
                        SetSpellCooldown(SCORPID_STING_1, 2000);
                    }
                    else if (Rand() < 40 && doCast(opponent, SCORPID_STING))
                    {
                        stingTargetGuid = opponent->GetGUID();
                        GC_Timer = 800;
                        return;
                    }
                }
            }
            //CHIMERA SHOT TODO:
            if (IsSpellReady(CHIMERA_SHOT_1, diff) && HasRole(BOT_ROLE_DPS) && stingTargetGuid == opponent->GetGUID() &&
                !opponent->HasAuraType(SPELL_AURA_MOD_DISARM) && Rand() < 30)
            {
                if (doCast(opponent, GetSpell(CHIMERA_SHOT_1)))
                    return;
            }
            //MULTI-SHOT
            if (IsSpellReady(MULTISHOT_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 60)
            {
                if (Unit* target = FindSplashTarget(35, opponent))
                {
                    if (doCast(target, GetSpell(MULTISHOT_1)))
                    {
                        GC_Timer = 800;
                        return;
                    }
                }

                SetSpellCooldown(MULTISHOT_1, 1000); //fail
            }
            //VOLLEY
            if (IsSpellReady(VOLLEY_1, diff) && HasRole(BOT_ROLE_DPS) && !me->isMoving() && Rand() < 25)
            {
                if (Unit* target = FindAOETarget(35, true, false))
                {
                    if (doCast(target, GetSpell(VOLLEY_1)))
                        return;
                }

                SetSpellCooldown(VOLLEY_1, 1000); //fail
            }
            //AIMED SHOT
            if (IsSpellReady(AIMED_SHOT_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 80)
            {
                if (doCast(opponent, GetSpell(AIMED_SHOT_1)))
                    return;
            }
            //ARCANE SHOT
            if (IsSpellReady(ARCANE_SHOT_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
            {
                if (doCast(opponent, GetSpell(ARCANE_SHOT_1)))
                    return;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& /*damageinfo*/) const {}

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;

                //Glyph of TrueShot Aura (req lvl 40): 10% additional critical chance for Aimed Shot
                if (lvl >= 40 && spellId == GetSpell(AIMED_SHOT_1))
                    aftercrit += 10.f;
                //Improved Barrage: 12% additional critical chance for Multi-Shot and Aimed Shot
                if (lvl >= 40 && (spellId == GetSpell(AIMED_SHOT_1) || spellId == GetSpell(MULTISHOT_1)))
                    aftercrit += 12.f;
                //Survival Instincts: 4% additional critical chance for Arcane Shot, Steady Shot and Explosive Shot
                if (lvl >= 15 && (spellId == GetSpell(ARCANE_SHOT_1)/* || spellId == GetSpell(STEADY_SHOT_1)*/ || spellId == GetSpell(EXPLOSIVE_SHOT_1)))
                    aftercrit += 4.f;
                //Sniper Training (part 1): 15% additional critical chance for Kill Shot
                if (lvl >= 50 && spellId == GetSpell(KILL_SHOT_1))
                    aftercrit += 15.f;
                //Point of No Escape: 6% additional critical chance on victims of any kind of frost trap (crew this condition)
                if (lvl >= 50)
                    aftercrit += 6.f;

                //Savage Strikes: 20% additional critical chance for Raptor Strike, Mongoose Bite and Counterattack
                if (lvl >= 10 && (spellId == GetSpell(RAPTOR_STRIKE_1)/* || spellId == GetSpell(MONGOOSE_BITE_1) || spellId == GetSpell(COUNTERATTACK_1)*/))

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Mortal Shots: 30% crit damage bonus for all ranged abilities
                if (lvl >= 15 && attackType == RANGED_ATTACK)
                    pctbonus += 0.15f;
                //Marked for Death (part 2): 10% crit damage bonus for Aimed Shot, Arcane Shot, Steady Shot, Kill Shot and Chimera Shot
                if (lvl >= 55 &&
                    (spellId == GetSpell(AIMED_SHOT_1) ||
                    spellId == GetSpell(ARCANE_SHOT_1) ||
                    //spellId == GetSpell(STEADY_SHOT_1) ||
                    spellId == GetSpell(KILL_SHOT_1) ||
                    spellId == GetSpell(CHIMERA_SHOT_1)))
                    pctbonus += 0.05f;
            }

            //Ranged Weapon Specialization: 5% bonus damage for ranged attacks
            if (lvl >= 35 && attackType == RANGED_ATTACK)
                pctbonus += 0.05f;
            //Improved Arcane Shot: 15% bonus damage for Arcane Shot
            if (lvl >= 20 && spellId == GetSpell(ARCANE_SHOT_1))
                pctbonus += 0.15f;
            //Rapid Killing (buff): 20% bonus damage for Aimed Shot, Arcane Shot or Chimera Shot (removed in SpellHitTarget())
            if (lvl >= 20 && (spellId == GetSpell(AIMED_SHOT_1) || spellId == GetSpell(ARCANE_SHOT_1) || spellId == GetSpell(CHIMERA_SHOT_1)) &&
                me->HasAura(RAPID_KILLING_BUFF))
                pctbonus += 0.2f;
            //Barrage: 12% bonus damage for Aimed Shot, Multi-Shot or Volley (removed in SpellHitTarget())
            if (lvl >= 30 && (spellId == GetSpell(AIMED_SHOT_1) || spellId == GetSpell(MULTISHOT_1) ||
                spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(VOLLEY_DAMAGE_1))))
                pctbonus += 0.12f;
            //Marked for Death (part 1): 5% bonus damage for all ranged shots on marked target
            if (lvl >= 55 && attackType == RANGED_ATTACK && damageinfo.target == markTarget)
                pctbonus += 0.05f;
            //T.N.T: 6% bonus damage for Explosive Shot (handled here) and Black Arrow (can be handler in ApplyClassDamageMultiplierEffect())
            if (lvl >= 25 && spellId == GetSpell(EXPLOSIVE_SHOT_1))
                pctbonus += 0.06f;
            //Sniper Training (part 2): 6% bonus damage for Steady Shot, Aimed Shot, Black Arrow and Explosive Shot (screw aura stuff, just increase)
            if (lvl >= 50 &&
                (spellId == GetSpell(AIMED_SHOT_1) ||
                //spellId == GetSpell(STEADY_SHOT_1) ||
                //spellId == GetSpell(BLACK_ARROW_1) ||//cannot be handled here
                spellId == GetSpell(EXPLOSIVE_SHOT_1)))

            damage = int32(fdamage * (1.0f + pctbonus));

            //Thrill of the Hunt additive (stage 1): store mana restore value (50%) while ability crits
            if (lvl >= 40)
                (static_cast<ManaRestoreList>(TotH))[spellId] = crit && attackType == RANGED_ATTACK ? spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask()) / 2 : 0;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            if (target == me)
                return;

            uint32 spellId = spell->Id;

            //Thrill of the Hunt additive (stage 1): store mana restore value while ability crits
            if (me->getLevel() >= 40 && TotH[spellId] > 0 && uint32(TotH[spellId]) < me->GetMaxPower(POWER_MANA))
            {
                me->EnergizeBySpell(me, THRILL_OF_THE_HUNT_EFFECT, TotH[spellId], POWER_MANA);
                TotH[spellId] = 0;
            }

            if (spellId == GetSpell(WING_CLIP_1))
            {
                //zzzOLD Improved Wing Clip (only on creatures): 30% to root target with Wing Clip
                //normal creatures are rooted for 10 sec, elites+ for 6 sec
                if (target->GetTypeId() == TYPEID_UNIT)
                {
                    if (urand(1,100) <= 30)
                    {
                        uint32 clip = target->ToCreature()->GetCreatureTemplate()->rank == CREATURE_ELITE_NORMAL ? IMPROVED_WING_CLIP_NORMAL : IMPROVED_WING_CLIP_EX;
                        me->CastSpell(target, clip, true);
                    }
                }
            }
            if (spellId == GetSpell(CONCUSSIVE_SHOT_1))
            {
                //Improved Concussion Shot rank 2: 2 sec increased daze duration
                if (Aura* concus = target->GetAura(spellId, me->GetGUID()))
                {
                    int32 dur = concus->GetDuration() + 2000;
                    concus->SetDuration(dur);
                    concus->SetMaxDuration(dur);
                }

                //zzzOLD Improved Concussion Shot: chance to stun target for 3 sec
                if (urand(1,100) <= 15)
                {
                    me->CastSpell(target, IMPROVED_CONCUSSION, true);
                }
            }

            //Rapid Killing: use up buff manually
            if (spellId == GetSpell(AIMED_SHOT_1) || spellId == GetSpell(ARCANE_SHOT_1) || spellId == GetSpell(CHIMERA_SHOT_1))
            {
                if (me->HasAura(RAPID_KILLING_BUFF))
                    me->RemoveAura(RAPID_KILLING_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if (spellId == GetSpell(RAPID_FIRE_1))
            {
                //Rapid Fire (id 28755): 4 sec increased duration
                if (Aura* rapid = me->GetAura(spellId))
                {
                    uint32 dur = rapid->GetDuration() + 4000;
                    rapid->SetDuration(dur);
                    rapid->SetMaxDuration(dur);
                }
            }

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/)
        {
            if (!u->IsInCombat() && !me->IsInCombat())
                return;
            OnOwnerDamagedBy(u);
        }

        void OwnerAttackedBy(Unit* u)
        {
            OnOwnerDamagedBy(u);
        }

        void Reset()
        {
            Trap_cd = 0;

            ScorpidSting_Timer = 0;
            Aspect_Timer = 0;

            Aspect = 0;

            stingTargetGuid = 0;

            markTarget = NULL;

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (Trap_cd > diff)                     Trap_cd -= diff;

            if (ScorpidSting_Timer > diff)          ScorpidSting_Timer -= diff;
            if (Aspect_Timer > diff)                Aspect_Timer -= diff;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(AUTO_SHOT_1, true);
            InitSpellMap(TRANQ_SHOT_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(SILENCING_SHOT_1) : RemoveSpell(SILENCING_SHOT_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(CHIMERA_SHOT_1) : RemoveSpell(CHIMERA_SHOT_1);
            InitSpellMap(ARCANE_SHOT_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(AIMED_SHOT_1) : RemoveSpell(AIMED_SHOT_1);
            InitSpellMap(KILL_SHOT_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(EXPLOSIVE_SHOT_1) : RemoveSpell(EXPLOSIVE_SHOT_1);
            InitSpellMap(MULTISHOT_1);
            InitSpellMap(VOLLEY_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(SCATTER_SHOT_1) : RemoveSpell(SCATTER_SHOT_1);
            InitSpellMap(CONCUSSIVE_SHOT_1);
            InitSpellMap(DISTRACTING_SHOT_1);
            InitSpellMap(SCORPID_STING_1);
            //InitSpellMap(VIPER_STING_1);
            InitSpellMap(RAPID_FIRE_1);
            InitSpellMap(WING_CLIP_1);
            InitSpellMap(RAPTOR_STRIKE_1);
            InitSpellMap(DISENGAGE_1);
            InitSpellMap(FROST_TRAP_1);
            InitSpellMap(FREEZING_ARROW_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(WYVERN_STING_1) : RemoveSpell(WYVERN_STING_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(BLACK_ARROW_1) : RemoveSpell(BLACK_ARROW_1);
            InitSpellMap(HUNTERS_MARK_1);
            InitSpellMap(SCARE_BEAST_1);
            InitSpellMap(FEIGN_DEATH_1);
            InitSpellMap(DETERRENCE_1);
            //InitSpellMap(ASPECT_OF_THE_VIPER_1);
  /*Custom*///ASPECT_OF_THE_PACK                      = ASPECT_OF_THE_VIPER ? ASPECT_OF_THE_PACK_1 : 0;
  /*Custom*/lvl >= 20 ? InitSpellMap(ASPECT_OF_THE_PACK_1, true) : RemoveSpell(ASPECT_OF_THE_PACK_1);
            //InitSpellMap(ASPECT_OF_THE_DRAGONHAWK_1);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            RefreshAura(RAPID_KILLING, level >= 20 ? 1 : 0);
            RefreshAura(CONCUSSIVE_BARRAGE, level >= 30 ? 1 : 0);
            RefreshAura(PIERCING_SHOTS, level >= 40 ? 1 : 0);
            RefreshAura(TRUESHOT_AURA, level >= 40 ? 1 : 0);
            RefreshAura(RAPID_RECUPERATION, level >= 45 ? 1 : 0);
            RefreshAura(MASTER_MARKSMAN, level >= 45 ? 1 : 0);
            RefreshAura(WILD_QUIVER, level >= 70 ? 3 : level >= 60 ? 2 : level >= 50 ? 1 : 0);
            RefreshAura(SUREFOOTED, level >= 15 ? 1 : 0);
            RefreshAura(ENTRAPMENT, level >= 15 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN5, level >= 67 ? 3 : level >= 58 ? 2 : level >= 50 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN4, level >= 49 && level < 50 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN3, level >= 48 && level < 49 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN2, level >= 47 && level < 48 ? 1 : 0);
            RefreshAura(MASTER_TACTICIAN1, level >= 46 && level < 47 ? 1 : 0);
            RefreshAura(NOXIOUS_STINGS, level >= 45 ? 1 : 0);
            RefreshAura(HUNTING_PARTY, level >= 55 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case RAPID_FIRE_1:
                case FROST_TRAP_1:
                case ASPECT_OF_THE_PACK_1:
                case ASPECT_OF_THE_VIPER_1:
                    return true;
                default:
                    return false;
            }
        }

    private:
        typedef std::unordered_map<uint32 /*spellId*/, int32 /*manaCost*/> ManaRestoreList;
        ManaRestoreList TotH;
        uint32 Trap_cd;
        uint32 ScorpidSting_Timer, Aspect_Timer;
        uint32 Aspect;
        uint64 stingTargetGuid;
        Unit* markTarget;

        enum HunterBaseSpells
        {
            AUTO_SHOT_1                         = 75,
            TRANQ_SHOT_1                        = 19801,
            SILENCING_SHOT_1                    = 34490,
            CHIMERA_SHOT_1                      = 53209,
            ARCANE_SHOT_1                       = 3044,
            AIMED_SHOT_1                        = 19434,
            KILL_SHOT_1                         = 53351,
            EXPLOSIVE_SHOT_1                    = 53301,
            MULTISHOT_1                         = 2643,
            VOLLEY_1                            = 1510,
            SCATTER_SHOT_1                      = 1991,
            CONCUSSIVE_SHOT_1                   = 5116,
            DISTRACTING_SHOT_1                  = 20736,
            SCORPID_STING_1                     = 3043,
            //VIPER_STING_1                       = 3034,
            RAPID_FIRE_1                        = 3045,
            WING_CLIP_1                         = 2974,
            RAPTOR_STRIKE_1                     = 2973,
            DISENGAGE_1                         = 781,
            FROST_TRAP_1                        = 13809,
            FREEZING_ARROW_1                    = 60192,
            WYVERN_STING_1                      = 19386,
            BLACK_ARROW_1                       = 3674,
            HUNTERS_MARK_1                      = 1130,
            SCARE_BEAST_1                       = 1513,
            FEIGN_DEATH_1                       = 5384,
            DETERRENCE_1                        = 19263,
            ASPECT_OF_THE_PACK_1                = 36613,//Aspect of the Spirit Hunter
            ASPECT_OF_THE_VIPER_1               = 34074
            //ASPECT_OF_THE_DRAGONHAWK_1          = 61846
        };

        enum HunterPassives
        {
        //Talents
            RAPID_KILLING                       = 34949,//rank 2
            CONCUSSIVE_BARRAGE                  = 35102,//rank 2
            PIERCING_SHOTS                      = 53238,//rank 3
            TRUESHOT_AURA                       = 19506,
            RAPID_RECUPERATION                  = 53232,//rank 2
            MASTER_MARKSMAN                     = 34489,//rank 5
            WILD_QUIVER                         = 53217,//rank 3
            SUREFOOTED                          = 24283,//rank 3
            ENTRAPMENT                          = 19388,//rank 3
            MASTER_TACTICIAN1                   = 34506,
            MASTER_TACTICIAN2                   = 34507,
            MASTER_TACTICIAN3                   = 34508,
            MASTER_TACTICIAN4                   = 34838,
            MASTER_TACTICIAN5                   = 34839,
            NOXIOUS_STINGS                      = 53297,//rank 3
            HUNTING_PARTY                       = 53292 //rank 3
        };

        enum HunterSpecial
        {
            IMPROVED_CONCUSSION                 = 28445,
            IMPROVED_WING_CLIP_NORMAL           = 47168,
            IMPROVED_WING_CLIP_EX               = 35963,

            RAPID_KILLING_BUFF                  = 35099,//rank 2
            THRILL_OF_THE_HUNT_EFFECT           = 34720,
            FROST_TRAP_AURA                     = 13810,
            FREEZING_ARROW_EFFECT               = 60210,
            //FREEZING_TRAP_EFFECT_1              = 3355,
            //FREEZING_TRAP_EFFECT_2              = 14308,
            //FREEZING_TRAP_EFFECT_3              = 14309,
            VOLLEY_DAMAGE_1                     = 42243 //rank 1
        };
    };
};

void AddSC_hunter_bot()
{
    new hunter_bot();
}
