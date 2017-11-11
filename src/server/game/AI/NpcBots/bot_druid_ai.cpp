#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Map.h"
//#include "WorldSession.h"
/*
Druid NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - Maybe 30%
TODO: Feral Spells (from scratch), More Forms, Balance Spells + treants...
*/
class druid_bot : public CreatureScript
{
public:
    druid_bot() : CreatureScript("druid_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new bot_druid_ai(creature);
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

    struct bot_druid_ai : public bot_minion_ai
    {
        bot_druid_ai(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_DRUID;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_DRUID) != SPELL_CAST_OK)
                return false;

            m_botSpellInfo = sSpellMgr->GetSpellInfo(spellId);
            if (me->GetShapeshiftForm() == FORM_NONE && swiftness && m_botSpellInfo->CalcCastTime() > 0)
            {
                DoCast(victim, spellId, true);
                me->RemoveAurasDueToSpell(NATURES_SWIFTNESS_1, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                me->RemoveAurasDueToSpell(CRIT_50, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                swiftness = false;
                return true;
            }
            if (spellId == GetSpell(BEAR_FORM_1) || GetSpell(spellId == CAT_FORM_1))
            {
                //me->ModifyPower(POWER_MANA, - int32(m_botSpellInfo->CalcPowerCost(me, m_botSpellInfo->GetSchoolMask())));
                if (me->GetVictim())
                    GetInPosition(true);
            }

            bool result = bot_ai::doCast(victim, spellId, triggered);

            if (result &&
                spellId != MANAPOTION && spellId != WARSTOMP_1 &&
                me->HasAura(OMEN_OF_CLARITY_BUFF))
            {
                cost = m_botSpellInfo->CalcPowerCost(me, m_botSpellInfo->GetSchoolMask());
                clearcast = true;
                power = me->getPowerType();
            }
            return result;
        }

        void EnterCombat(Unit* u) { bot_minion_ai::EnterCombat(u); }
        void Aggro(Unit*) { }
        void AttackStart(Unit*) { }
        void KilledUnit(Unit*) { }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { removeFeralForm(true, false); bot_minion_ai::JustDied(u); }

        uint8 GetBotStance() const
        {
            return Form;
        }

        void warstomp(uint32 diff)
        {
            if (me->getRace() != RACE_TAUREN) return;
            if (!IsSpellReady(WARSTOMP_1, diff, false)) return;
            if (me->GetShapeshiftForm() != FORM_NONE)
                return;

            AttackerSet b_attackers = me->getAttackers();

            if (b_attackers.empty())
            {
                Unit* u = me->SelectNearestTarget(5);
                if (u && u->IsInCombat() && u->isTargetableForAttack())
                {
                    if (doCast(me, WARSTOMP_1))
                        return;
                }
            }
            for (AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
            {
                if (!(*iter) || (*iter)->isDead()) continue;
                if (!(*iter)->isTargetableForAttack()) continue;
                if (me->GetDistance((*iter)) <= 5)
                {
                    if (doCast(me, WARSTOMP_1))
                        return;
                }
            }
        }

        bool DamagePossible()
        {
            return true;
            //return (GetManaPCT(me) < 30 || GetHealthPCT(master) < 50);
            /*if (GetHealthPCT(master) < 75 || GetHealthPCT(me) < 75) return false;

            if (Group* pGroup = master->GetGroup())
            {
                uint8 LHPcount = 0;
                uint8 DIScount = 0;
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* tPlayer = itr->GetSource();
                    if (!tPlayer || tPlayer->isDead()) continue;
                    if (me->GetExactDist(tPlayer) > 30) continue;
                    if (tPlayer->GetHealth()*100 / tPlayer->GetMaxHealth() < 75)
                        ++LHPcount;
                    Unit::AuraApplicationMap const& auras = tPlayer->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                        if (itr->second->GetBase()->GetSpellInfo()->Dispel == DISPEL_POISON)
                            ++DIScount;
                }
                uint8 members = master->GetGroup()->GetMembersCount();

                if (members > 10)
                {
                    if (LHPcount > 1 || DIScount > 2) return false;
                }
                if (members > 4)
                {
                    if (LHPcount > 0 || DIScount > 1) return false;
                }
                if (members < 5)
                {
                    if (LHPcount > 0 || DIScount > 0) return false;
                }
            }//endif unitlist

            Unit* u = master->GetVictim();
            if (master->getAttackers().size() > 4 ||
              (!master->getAttackers().empty() &&
                u != NULL && u->GetHealth() > me->GetMaxHealth()*17))
                return false;

            return true;*/
        }

        void removeFeralForm(bool force = false, bool /*init*/ = true, uint32 diff = 0)
        {
            if (!force && formtimer > diff)
                return;

            ShapeshiftForm form = me->GetShapeshiftForm();
            if (form != FORM_NONE)
            {
                switch (form)
                {
                    case FORM_DIREBEAR:
                    case FORM_BEAR:
                        me->RemoveAurasDueToSpell(GetSpell(BEAR_FORM_1));
                        break;
                    case FORM_CAT:
                        me->RemoveAurasDueToSpell(GetSpell(CAT_FORM_1));
                        me->RemoveAurasDueToSpell(ENERGIZE);
                        break;
                    default:
                        break;
                }

                setStats(BOT_CLASS_DRUID);
            }
            else if (Form != BOT_STANCE_NONE)
                Form = BOT_STANCE_NONE;
        }

        bool IsMelee() const
        {
            if (GetBotStance() == DRUID_BEAR_FORM || GetBotStance() == DRUID_CAT_FORM)
                return true;

            return bot_ai::IsMelee();
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            Aggro(u);
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force);
        }

        void doBearActions(uint32 diff)
        {
            if (me->getPowerType() != POWER_RAGE) return;

            if (GetHealthPCT(me) < 75)
                if (HealTarget(me, GetHealthPCT(me), diff))
                    return;
            opponent = me->GetVictim();
            if (opponent)
                StartAttack(opponent, true);
            else
                return;

            //range check (melee) to prevent fake casts
            if (me->GetDistance(opponent) > 5) return;

            if (IsSpellReady(MANGLE_BEAR_1, diff) && HasRole(BOT_ROLE_DPS) && rage >= 150 && Rand() < 35 &&
                doCast(opponent, GetSpell(MANGLE_BEAR_1)))
                return;

            if (IsSpellReady(SWIPE_1, diff) && HasRole(BOT_ROLE_DPS) && rage >= 150 && Rand() < 75 &&
                doCast(opponent, GetSpell(SWIPE_1)))
                return;

        }//end doBearActions

        void doCatActions(uint32 diff)
        {
            if (me->getPowerType() != POWER_ENERGY) return;

            if (GetHealthPCT(me) < 75)
                if (HealTarget(me, GetHealthPCT(me), diff))
                    return;
            opponent = me->GetVictim();
            if (opponent)
                StartAttack(opponent, true);
            else
                return;

            uint32 energy = me->GetPower(POWER_ENERGY);

            if (MoveBehind(*opponent))
                wait = 5;

            //range check (melee) to prevent fake casts
            if (me->GetDistance(opponent) > 5) return;

            if (IsSpellReady(MANGLE_CAT_1, diff) && energy > 45 && HasRole(BOT_ROLE_DPS) && Rand() < 35 &&
                doCast(opponent, GetSpell(MANGLE_CAT_1)))
                return;
            if (IsSpellReady(RAKE_1, diff) && energy > 40 && HasRole(BOT_ROLE_DPS) && Rand() < 30 &&
                doCast(opponent, GetSpell(RAKE_1)))
                return;
            if (IsSpellReady(SHRED_1, diff) && energy > 60 && HasRole(BOT_ROLE_DPS) && !opponent->HasInArc(M_PI, me) && Rand() < 50 &&
                doCast(opponent, GetSpell(SHRED_1)))
                return;
            if (IsSpellReady(RIP_1, diff) && energy > 30 && HasRole(BOT_ROLE_DPS) && Rand() < 30 &&
                doCast(opponent, GetSpell(RIP_1)))
                return;
            if (IsSpellReady(CLAW_1, diff) && energy > 45 && HasRole(BOT_ROLE_DPS) && Rand() < 80 &&
                doCast(opponent, GetSpell(CLAW_1)))
                return;
        }//end doCatActions

        void doBalanceActions(uint32 diff)
        {
            removeFeralForm(true, true);
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent);
            }
            else
                return;

            AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();

            //range check to prevent fake casts
            if (me->GetExactDist(opponent) > 30 || !DamagePossible()) return;

            if (IsSpellReady(HURRICANE_1, diff) && !me->isMoving() && HasRole(BOT_ROLE_DPS) && Rand() < 35)
            {
                Unit* target = FindAOETarget(30, true);
                if (target && doCast(target, GetSpell(HURRICANE_1)))
                    return;
                SetSpellCooldown(HURRICANE_1, 2000); //fail
            }
            if (uint32 FAERIE_FIRE = GetSpell(FAERIE_FIRE_1))
            {
                if (GC_Timer <= diff &&
                    opponent->getAttackers().size() > 1 &&//check if faerie fire is not useless 50/50
                    Rand() < 20 && !HasAuraName(opponent, FAERIE_FIRE_1))
                {
                    if (doCast(opponent, FAERIE_FIRE))
                        return;
                }
            }
            if (IsSpellReady(MOONFIRE_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 20 &&
                !HasAuraName(opponent, MOONFIRE_1, me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(MOONFIRE_1)))
                    return;
            }
            if (IsSpellReady(STARFIRE_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 50)
            {
                if (doCast(opponent, GetSpell(STARFIRE_1)))
                    return;
            }
            if (IsSpellReady(WRATH_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 40)
            {
                if (doCast(opponent, GetSpell(WRATH_1)))
                    return;
            }
        }

        bool MassGroupHeal(Player* gPlayer, uint32 diff)
        {
            if (!gPlayer || GC_Timer > diff || IAmFree()) return false;
            if (IsCasting()) return false; // if I'm already casting
            bool tranq = IsSpellReady(TRANQUILITY_1, diff, false);
            bool growt = IsSpellReady(WILD_GROWTH_1, diff, false);
            if (!tranq && !growt) return false;
            if (Rand() > 30) return false;
            Group* pGroup = gPlayer->GetGroup();
            if (!pGroup) return false;
            uint8 LHPcount = 0;
            uint8 pct = 100;
            Unit* healTarget = NULL;
            for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* tPlayer = itr->GetSource();
                if (!tPlayer || !tPlayer->IsInWorld() || tPlayer->GetMapId() != me->GetMapId() ||
                    (tPlayer->isDead() && !tPlayer->HaveBot())) continue;
                if (me->GetExactDist(tPlayer) > 39) continue;
                if (GetHealthPCT(tPlayer) < 80)
                {
                    if (GetHealthPCT(tPlayer) < pct)
                    {
                        pct = GetHealthPCT(tPlayer);
                        healTarget = tPlayer;
                    }
                    ++LHPcount;
                    if (LHPcount > 2) break;
                }
                if (tPlayer->HaveBot())
                {
                    BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* bot = it->second;
                        if (bot && bot->IsInWorld() && bot->GetExactDist(me) < 40 && GetHealthPCT(bot) < 80)
                        {
                            if (GetHealthPCT(bot) < pct)
                            {
                                pct = GetHealthPCT(bot);
                                healTarget = bot;
                            }
                            ++LHPcount;
                            if (LHPcount > 2) break;
                        }
                    }
                }
            }
            if (LHPcount > 2 && tranq &&
                doCast(me, GetSpell(TRANQUILITY_1)))
                return true;
            if (LHPcount > 0 && growt && healTarget &&
                doCast(healTarget, GetSpell(WILD_GROWTH_1)))
                return true;

            return false;
        }

        void UpdateAI(uint32 diff)
        {
            ReduceCD(diff);
            if (!GlobalUpdate(diff))
                return;
            CheckAttackState();

            if (me->getPowerType() == POWER_RAGE)
            {
                rage = me->GetPower(POWER_RAGE);
                if (ragetimer2 <= diff)
                {
                    if (me->IsInCombat() && me->getLevel() >= 30)
                    {
                        if (rage < 990)
                            me->SetPower(POWER_RAGE, rage + uint32(10.f*rageIncomeMult));//1 rage per 2 sec
                        else
                            me->SetPower(POWER_RAGE, 1000);
                    }
                    ragetimer2 = 2000;
                }
                if (ragetimer <= diff)
                {
                    if (!me->IsInCombat())
                    {
                        if (rage > 10.f*rageLossMult)
                            me->SetPower(POWER_RAGE, rage - uint32(10.f*rageLossMult)); //-1 rage per 1.5 sec
                        else
                            me->SetPower(POWER_RAGE, 0);
                    }
                    ragetimer = 1500;
                    if (rage > 1000) me->SetPower(POWER_RAGE, 1000);
                    if (rage < 10) me->SetPower(POWER_RAGE, 0);
                }
            }
            if (clearcast && me->HasAura(OMEN_OF_CLARITY_BUFF) && !me->IsNonMeleeSpellCast(false))
            {
                me->ModifyPower(power, cost);
                me->RemoveAurasDueToSpell(OMEN_OF_CLARITY_BUFF, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                clearcast = false;
            }
            CheckAuras();
            if (wait == 0)
                wait = GetWait();
            else
                return;
            BreakCC(diff);
            if (CCed(me)) return;
            warstomp(diff);

            if (Potion_cd <= diff && me->getPowerType() == POWER_MANA && GetManaPCT(me) < 20)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }

            //Heal master
            if (GetHealthPCT(master) < 85)
                HealTarget(master, GetHealthPCT(master), diff);
            //Innervate
            doInnervate(diff);

            MassGroupHeal(master, diff);
            if (!me->IsInCombat())
                DoNonCombatActions(diff);
            else
                CheckBattleRez(diff);
            BuffAndHealGroup(master, diff);
            //CureTarget(master, GetSpell(CURE_POISON_1), diff);
            CureGroup(master, GetSpell(CURE_POISON_1), diff);

            if (!CheckAttackTarget(BOT_CLASS_DRUID))
                return;

            //debug
            opponent = me->GetVictim();

            if (GetHealthPCT(me) < 75)
            {
                HealTarget(me, GetHealthPCT(me), diff);
                return;
            }

            if (IsCasting())
                return; //Casting heal or something

            CheckRoots(diff);

            if (DamagePossible() && opponent != NULL)
            {
                Unit* u = opponent->GetVictim();
                //if the target is attacking us, we want to go bear
                if (GetSpell(BEAR_FORM_1) && !CCed(opponent) &&
                    ((u == me || (IsTank() && IsInBotParty(u))) ||
                    (!me->getAttackers().empty() && (*me->getAttackers().begin()) == opponent && opponent->GetMaxHealth() > me->GetMaxHealth()*2)))
                {
                    //if we don't have bear yet
                    if (me->GetShapeshiftForm() != FORM_DIREBEAR &&
                        me->GetShapeshiftForm() != FORM_BEAR &&
                        formtimer <= diff &&
                        doCast(me, GetSpell(BEAR_FORM_1)))
                    {
                        formtimer = 1500;
                    }
                    if (me->GetShapeshiftForm() == FORM_DIREBEAR ||
                        me->GetShapeshiftForm() == FORM_BEAR)
                        doBearActions(diff);
                }
                else
                if (GetSpell(CAT_FORM_1) && master->GetVictim() != opponent && u &&
                    IsTank(u) && u != me &&
                    opponent->GetMaxHealth() < u->GetMaxHealth()*3)
                {
                    //if we don't have cat yet
                    if (me->GetShapeshiftForm() != FORM_CAT && formtimer <= diff)
                    {
                        if (doCast(me, GetSpell(CAT_FORM_1)))
                        {
                            formtimer = 1500;
                        }
                    }
                    if (me->GetShapeshiftForm() == FORM_CAT)
                        doCatActions(diff);
                }
                else if (!IsTank())
                    doBalanceActions(diff);
            }
            else if (!IsTank())
                doBalanceActions(diff);
        }

        bool HealTarget(Unit* target, uint8 hp, uint32 diff)
        {
            if (!HasRole(BOT_ROLE_HEAL)) return false;
            if (hp > 95) return false;
            if (!target || target->isDead()) return false;
            if (IsTank() && hp > 35) return false;
            if (hp > 50 && me->GetShapeshiftForm() != FORM_NONE) return false; //do not waste heal if in feral or so
            if (Rand() > 50 + 20*target->IsInCombat() + 50*master->GetMap()->IsRaid() - 50*me->GetShapeshiftForm()) return false;
            if (me->GetExactDist(target) > 40) return false;

            if (IsSpellReady(NATURES_SWIFTNESS_1, diff, false) &&
                (hp < 15 || (hp < 35 && target->getAttackers().size() > 2)) &&
                (target->IsInCombat() || !target->getAttackers().empty()))
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                if (doCast(me, GetSpell(NATURES_SWIFTNESS_1)) && RefreshAura(CRIT_50, 2))
                {
                    swiftness = true;
                    if (doCast(target, GetSpell(HEALING_TOUCH_1), true))
                        Heal_Timer = 3000;
                    return true;
                }
            }
            if (IsSpellReady(SWIFTMEND_1, diff, false, 3000) &&
                (hp < 25 || GetLostHP(target) > 5000) &&
                (HasAuraName(target, REGROWTH_1) || HasAuraName(target, REJUVENATION_1)))
            {
                if (doCast(target, GetSpell(SWIFTMEND_1)))
                {
                    if (GetHealthPCT(target) > 75)
                        return true;
                    else if (!target->getAttackers().empty())
                    {
                        if (doCast(target, GetSpell(REGROWTH_1)))
                        {
                            GC_Timer = 300;
                            return true;
                        }
                    }
                }
            }
            if (hp > 35 && (hp < 75 || GetLostHP(target) > 3000) && Heal_Timer <= diff && GetSpell(NOURISH_1))
            {
                switch (urand(1,3))
                {
                    case 1:
                    case 2:
                        if (doCast(target, GetSpell(NOURISH_1)))
                        {
                            Heal_Timer = 3000;
                            return true;
                        }
                        break;
                    case 3:
                        if (doCast(target, GetSpell(HEALING_TOUCH_1)))
                        {
                            Heal_Timer = 3000;
                            return true;
                        }
                        break;
                }
            }
            //maintain HoTs
            Unit* u = target->GetVictim();
            Creature* boss = u && u->ToCreature() && u->ToCreature()->isWorldBoss() ? u->ToCreature() : NULL;
            bool tanking = IsTank(target) && boss;
            bool regrowth = IsSpellReady(REGROWTH_1, diff);
            if ( ( (hp < 80 || GetLostHP(target) > 3500 || tanking) &&
                regrowth && !HasAuraName(target, REGROWTH_1, me->GetGUID()) )
                ||
                (HasAuraName(target, REGROWTH_1, me->GetGUID()) && HasAuraName(target, REJUVENATION_1, me->GetGUID()) &&
                (hp < 70 || GetLostHP(target) > 3000) && regrowth))
            {
                if (doCast(target, GetSpell(REGROWTH_1)))
                    return true;
            }
            if (GetSpell(REJUVENATION_1) && GC_Timer <= diff && hp > 25 &&
                (hp < 90 || GetLostHP(target) > 2000 || tanking) &&
                !HasAuraName(target, REJUVENATION_1, me->GetGUID()))
            {
                if (doCast(target, GetSpell(REJUVENATION_1)))
                {
                    if (!target->getAttackers().empty() && (hp < 75 || GetLostHP(target) > 4000))
                        if (IsSpellReady(SWIFTMEND_1, diff, false) && doCast(target, GetSpell(SWIFTMEND_1)))
                        {}
                    GC_Timer = 500;
                    return true;
                }
            }
            if (IsSpellReady(LIFEBLOOM_1, diff) &&
                ((hp < 85 && hp > 40) || (hp > 70 && tanking) ||
                (hp < 70 && hp > 25 && HasAuraName(target, REGROWTH_1) && HasAuraName(target, REJUVENATION_1)) ||
                (GetLostHP(target) > 1500 && hp > 35)))
            {
                Aura* bloom = target->GetAura(GetSpell(LIFEBLOOM_1), me->GetGUID());
                if ((!bloom || bloom->GetStackAmount() < 3) && doCast(target, GetSpell(LIFEBLOOM_1)))
                    return true;
            }
            if (hp > 30 && (hp < 70 || GetLostHP(target) > 3000) && Heal_Timer <= diff &&
                doCast(target, GetSpell(HEALING_TOUCH_1)))
            {
                Heal_Timer = 3000;
                return true;
            }
            return false;
        }

        bool BuffTarget(Unit* target, uint32 diff)
        {
            if (GC_Timer > diff || Rand() > 20) return false;
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;
            if (target && target->IsAlive() && me->GetExactDist(target) < 30)
            {
                if (uint32 MARK_OF_THE_WILD = GetSpell(MARK_OF_THE_WILD_1))
                    if (!HasAuraName(target, MARK_OF_THE_WILD_1))
                        if (doCast(target, MARK_OF_THE_WILD))
                            return true;
                if (uint32 THORNS = GetSpell(THORNS_1))
                    if (!HasAuraName(target, THORNS_1))
                        if (doCast(target, THORNS))
                            return true;
            }
            return false;
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            RezGroup(GetSpell(REVIVE_1), master);

            //if (Feasting()) return;

            //if (BuffTarget(master, diff))
            //{
            //    /*GC_Timer = 800;*/
            //    return;
            //}
            //if (BuffTarget(me, diff))
            //{
            //    /*GC_Timer = 800;*/
            //    return;
            //}
        }

        void doInnervate(uint32 diff, uint8 minmanaval = 30)
        {
            if (!IsSpellReady(INNERVATE_1, diff) || Rand() > 15)
                return;
            if (me->GetShapeshiftForm() != FORM_NONE && (IsTank() || me->getAttackers().size() > 3))
                return;

            uint32 INNERVATE = GetSpell(INNERVATE_1);
            Unit* iTarget = NULL;

            if (master->IsInCombat() && master->getPowerType() == POWER_MANA &&
                GetManaPCT(master) < 20 && !master->HasAura(INNERVATE))
                iTarget = master;
            else if (me->IsInCombat() && me->getPowerType() == POWER_MANA &&
                GetManaPCT(me) < 20 && !me->HasAura(INNERVATE))
                iTarget = me;

            if (!IAmFree())
            {
                Group* group = master->GetGroup();
                if (!iTarget && !group) //first check master's bots
                {
                    BotMap const* map = master->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                    {
                        Creature* bot = itr->second;
                        if (!bot || !bot->IsInCombat() || bot->isDead()) continue;
                        if (me->GetExactDist(bot) > 30) continue;
                        if (bot->getPowerType() != POWER_MANA) continue;
                        if (GetManaPCT(bot) < minmanaval && !bot->HasAura(INNERVATE))
                        {
                            iTarget = bot;
                            break;
                        }
                    }
                }
                if (!iTarget && group) //cycle through player members...
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* tPlayer = itr->GetSource();
                        if (tPlayer == NULL || !tPlayer->IsInWorld() || !tPlayer->IsInCombat() || tPlayer->isDead()) continue;
                        if (me->GetExactDist(tPlayer) > 30) continue;
                        if (tPlayer->getPowerType() != POWER_MANA) continue;
                        if (GetManaPCT(tPlayer) < minmanaval && !tPlayer->HasAura(INNERVATE))
                        {
                            iTarget = tPlayer;
                            break;
                        }
                        if (iTarget)
                            break;
                    }
                }
                if (!iTarget && group) //... and their bots.
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* tPlayer = itr->GetSource();
                        if (tPlayer == NULL || !tPlayer->HaveBot()) continue;
                        BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                        {
                            Creature* bot = it->second;
                            if (!bot || bot->isDead()) continue;
                            if (me->GetExactDist(bot) > 30) continue;
                            if (bot->getPowerType() != POWER_MANA) continue;
                            if (GetManaPCT(bot) < minmanaval && !bot->HasAura(INNERVATE))
                            {
                                iTarget = bot;
                                break;
                            }
                        }
                        if (iTarget)
                            break;
                    }
                }
            }

            if (iTarget && doCast(iTarget, INNERVATE))
            {
                if (iTarget->GetTypeId() == TYPEID_PLAYER)
                    BotWhisper("Innervate on You!", iTarget->ToPlayer());
                else if (!IAmFree())
                {
                    std::ostringstream msg;
                    msg << "Innervate on " << (iTarget == me ? "myself" : iTarget->GetName()) << '!';
                    BotWhisper(msg.str().c_str(), master);
                }

                return;
            }

            SetSpellCooldown(INNERVATE_1, 3000); //fail
        }

        void CheckRoots(uint32 diff)
        {
            if (GC_Timer > diff || Rand() > 35) return;
            if (me->GetShapeshiftForm() != FORM_NONE) return;
            uint32 ENTANGLING_ROOTS = GetSpell(ENTANGLING_ROOTS_1);
            if (!ENTANGLING_ROOTS) return;
            if (FindAffectedTarget(ENTANGLING_ROOTS, me->GetGUID(), 60)) return;
            if (Unit* target = FindRootTarget(30, ENTANGLING_ROOTS))
                if (doCast(target, ENTANGLING_ROOTS))
                    return;
        }

        void CheckBattleRez(uint32 diff)
        {
            if (!IsSpellReady(REBIRTH_1, diff, false) || IAmFree() || me->IsMounted() || IsCasting() || Rand() > 10) return;

            Group* gr = master->GetGroup();
            if (!gr)
            {
                Unit* target = master;
                if (master->IsAlive()) return;
                if (master->IsResurrectRequested()) return; //ressurected
                if (master->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                    target = (Unit*)master->GetCorpse();
                if (!target || !target->IsInWorld())
                    return;
                if (me->GetExactDist(target) > 30)
                {
                    me->GetMotionMaster()->MovePoint(master->GetMapId(), *target);
                    SetSpellCooldown(REBIRTH_1, 1500);
                    return;
                }
                else if (!target->IsWithinLOSInMap(me))
                    me->Relocate(*target);

                if (doCast(target, GetSpell(REBIRTH_1))) //rezzing
                    BotWhisper("Rezzing You", master);

                return;
            }
            for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* tPlayer = itr->GetSource();
                Unit* target = tPlayer;
                if (!tPlayer || tPlayer->IsAlive()) continue;
                if (tPlayer->IsResurrectRequested()) continue; //ressurected
                if (tPlayer->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
                    target = (Unit*)tPlayer->GetCorpse();
                if (!target || !target->IsInWorld()) continue;
                if (master->GetMap() != target->FindMap()) continue;
                if (me->GetExactDist(target) > 30)
                {
                    //me->GetMotionMaster()->MovePoint(target->GetMapId(), *target);
                    SetSpellCooldown(REBIRTH_1, 1500);
                    return;
                }
                else if (!target->IsWithinLOSInMap(me))
                    me->Relocate(*target);

                if (doCast(target, GetSpell(REBIRTH_1))) //rezzing
                {
                    BotWhisper("Rezzing You", tPlayer);
                    return;
                }
            }
        }

        void setStats(uint8 form)
        {
            switch (form)
            {
                case DRUID_BEAR_FORM:
                    Form = DRUID_BEAR_FORM;
                    break;
                case DRUID_CAT_FORM:
                    Form = DRUID_CAT_FORM;
                    RefreshAura(ENERGIZE, me->getLevel()/40);
                    break;
                case BOT_CLASS_DRUID:
                    Form = BOT_STANCE_NONE;
                    SetShouldUpdateStats();
                    me->setPowerType(POWER_MANA);
                    me->RemoveMovementImpairingAuras(true);
                    break;
                default:
                    return;
            }

            SetStats(false);
        }

        void ApplyClassDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const
        {
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;

            if (damageinfo.hitOutCome == MELEE_HIT_CRIT)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Primal Fury (white attacks): 100% to gain 5 rage at crit in (Dire) Bear Form
                if (lvl >= 25 && GetBotStance() == DRUID_BEAR_FORM)
                    me->CastSpell(me, PRIMAL_FURY_EFFECT_ENERGIZE, true);
                //Predatory Instincts (part 1): 10% additional crit damage bonus for melee attacks in Cat form
                if (lvl >= 45 && GetBotStance() == DRUID_CAT_FORM)
                    pctbonus += 0.05f;
            }

            //Naturalist: 10% bonus damage for all melee attacks
            if (lvl >= 15)
                pctbonus += 0.1f;

            damage = damage * (1.0f + pctbonus);
        }

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Rend and Tear (part 2): 25% additional critical chance on bleeding targets for Ferocious Bite
                if (lvl >= 55 && damageinfo.target && damageinfo.target->HasAuraState(AURA_STATE_BLEEDING) && spellId == GetSpell(FEROCIOUS_BITE_1))
                    aftercrit += 25.f;

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                ////Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost (all) spells
                //if (lvl >= 21)
                //    pctbonus += 0.25f;
            }

            //Feral Instinct: 30% bonus damage for Swipe (Bear)
            if (lvl >= 15 && spellId == GetSpell(SWIPE_1))
                pctbonus += 0.3f;
            //Savage Fury: 20% bonus damage for Claw, Rake, Mangle (Cat), Mangle (Bear) and Maul
            if (lvl >= 15 &&
                (spellId == GetSpell(CLAW_1) ||
                spellId == GetSpell(RAKE_1) ||
                spellId == GetSpell(MANGLE_CAT_1) ||
                spellId == GetSpell(MANGLE_BEAR_1) ||
                spellId == GetSpell(MAUL_1)))
                pctbonus += 0.2f;
            //Rend and Tear: 20% bonus damage on bleeding targets for Maul and Shred
            if (lvl >= 55 && damageinfo.target && damageinfo.target->HasAuraState(AURA_STATE_BLEEDING) &&
                (spellId == GetSpell(MAUL_1) || spellId == GetSpell(SHRED_1)))
                pctbonus += 0.2f;
            //Naturalist: 10% bonus damage for all melee attacks
            if (lvl >= 15)
                pctbonus += 0.1f;

            //Primal Fury (yellow attacks): 100% to gain 5 rage at crit in (Dire) Bear Form
            if (lvl >= 25 && crit && GetBotStance() == DRUID_BEAR_FORM)
                me->CastSpell(me, PRIMAL_FURY_EFFECT_ENERGIZE, true);

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Improved Moonfire
                if (lvl >= 15 && spellId == GetSpell(MOONFIRE_1))
                    aftercrit += 10.f;
                //Nature's Majesty: 4% additional critical chance for Wrath, Starfire and Starfall
                if (lvl >= 15 &&
                    (spellId == GetSpell(WRATH_1) ||
                    spellId == GetSpell(STARFIRE_1)/* ||
                    spellId == GetSpell(STARFALL_1)*/))
                    aftercrit += 4.f;
                //Eclipse (Lunar): 40% additional critical chance for Starfire
                if (lvl >= 50 && spellId == GetSpell(STARFIRE_1) && me->HasAura(ECLIPSE_LUNAR_BUFF))
                    aftercrit += 40.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Vengeance: 100% additional crit damage bonus for Starfire, Starfall, Moonfire and Wrath
                if (lvl >= 25 &&
                    (spellId == GetSpell(STARFIRE_1) ||
                    //spellId == GetSpell(STARFALL_1) ||
                    spellId == GetSpell(MOONFIRE_1) ||
                    spellId == GetSpell(WRATH_1)))
                    pctbonus += 0.333f;
            }
            //Brambles: 75% bonus damage for Throns and Entangling Roots
            if (lvl >= 20 &&
                (spellId == GetSpell(THORNS_1) ||
                spellId == GetSpell(ENTANGLING_ROOTS_1)))
                pctbonus += 0.75f;
            //Moonfury: 10% bonus damage for Starfire, Moonfire and Wrath
            if (lvl >= 35 &&
                (spellId == GetSpell(STARFIRE_1) ||
                spellId == GetSpell(MOONFIRE_1) ||
                spellId == GetSpell(WRATH_1)))
                pctbonus += 0.1f;
            //Wrath of Cenarius: 20%/10% Increased spellpower bonus for Starfire/Wrath
            if (lvl >= 45)
            {
                if (spellId == GetSpell(STARFIRE_1))
                    fdamage += spellpower * 0.2f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * 1.88f * me->CalculateLevelPenalty(spellInfo);
                if (spellId == GetSpell(WRATH_1))
                    fdamage += spellpower * 0.1f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * 1.88f * me->CalculateLevelPenalty(spellInfo);
            }
            //Eclipse (Solar): 40% bonus damage for Wrath
            if (lvl >= 50 && spellId == GetSpell(WRATH_1) && me->HasAura(ECLIPSE_SOLAR_BUFF))
                pctbonus += 0.4f;
            //Gale Winds: 30% bonus damage for Hurricane (no Typhon support yet)
            if (lvl >= 50 && spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(HURRICANE_DAMAGE_1)))
                pctbonus += 0.3f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Improved Rejuvenation: 15% bonus healing for Rejuvenation
            if (lvl >= 25 && spellId == GetSpell(REJUVENATION_1))
                pctbonus += 0.15f;
            //Gift of Nature: 10% bonus healing for all spells
            if (lvl >= 30)
                pctbonus += 0.1f;
            //Empowered Touch: 40% bonus (from spellpower) for Healing Touch and 20% bonus (from spellpower) for Nourish
            if (lvl >= 35)
            {
                if (spellId == GetSpell(HEALING_TOUCH_1))
                    flat_mod += spellpower * 0.4f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
                else if (spellId == GetSpell(NOURISH_1))
                    flat_mod += spellpower * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
            }
            //Empowered Rejuvenation: 20% bonus healing for healing over time effects (20% increase in our case)
            if (lvl >= 45 &&
                (spellId == GetSpell(TRANQUILITY_1) ||
                spellId == GetSpell(REJUVENATION_1) ||
                spellId == GetSpell(REGROWTH_1) ||
                spellId == GetSpell(LIFEBLOOM_1) ||
                spellId == GetSpell(WILD_GROWTH_1) ||
                spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(TRANQUILITY_HEAL_1))))
                pctbonus += 0.2f;
            //Empowered Touch: 15% bonus (from spirit) for healing spells (taking in consideration increased spirit (Living Spirit: 15%))
            if (lvl >= 50)
                flat_mod += me->GetTotalStatValue(STAT_SPIRIT) * 0.15f * 1.15f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassCritMultiplierHeal(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float aftercrit = 0.0f;

            //Nature's bounty: 25% additional critical chance for Regrowth
            if (lvl >= 35 && spellId == GetSpell(REGROWTH_1))
                aftercrit += 25.f;

            crit_chance += aftercrit;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            //Nature's Splendor: Increased duraion for
            //Moonfire (3 sec), Rejuvenation (3 sec, let 6), Regrowth (6 sec, let 9),
            //Insect Swarm (2 sec) and Lifebloom (2 sec, let 4)
            if (spellId == GetSpell(MOONFIRE_1) || spellId == GetSpell(REJUVENATION_1) ||
                spellId == GetSpell(REGROWTH_1)/* || spellId == GetSpell(INSECT_SWARM_1)*/ ||
                spellId == GetSpell(LIFEBLOOM_1))
            {
                if (me->getLevel() >= 20)
                {
                    if (Aura* aur = target->GetAura(spellId))
                    {
                        uint32 dur = aur->GetDuration();

                        switch (sSpellMgr->GetSpellInfo(spellId)->GetFirstRankSpell()->Id)
                        {
                            case MOONFIRE_1:
                                dur += 3000;
                                break;
                            case REJUVENATION_1:
                                dur += 6000;
                                break;
                            case REGROWTH_1:
                                dur += 9000;
                                break;
                            //case INSECT_SWARM_1:
                            //    dur += 3000;
                            //    break;
                            case LIFEBLOOM_1:
                                dur += 4000;
                                break;
                            default:
                                break;
                        }

                        aur->SetDuration(dur);
                        aur->SetMaxDuration(dur);
                    }
                }
            }

            if (spellId == GetSpell(THORNS_1))
            {
                //30 min duration for Thorns
                if (Aura* thorn = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = 30 * MINUTE * IN_MILLISECONDS;
                    thorn->SetDuration(dur);
                    thorn->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(MARK_OF_THE_WILD_1))
            {
                //1 hour duration for Mark of the Wild
                if (Aura* mark = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = 1 * HOUR * IN_MILLISECONDS;
                    mark->SetDuration(dur);
                    mark->SetMaxDuration(dur);
                }
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;
            //Eclipse (helper): cooldown
            if (spellId == ECLIPSE_SOLAR_BUFF || spellId == ECLIPSE_LUNAR_BUFF)
                SetSpellCooldown(spellId, 30000);
            //Forms helper
            if (spellId == GetSpell(CAT_FORM_1) || spellId == GetSpell(BEAR_FORM_1))
            {
                if (spellId == GetSpell(BEAR_FORM_1))
                    setStats(DRUID_BEAR_FORM);
                if (spellId == GetSpell(CAT_FORM_1))
                    setStats(DRUID_CAT_FORM);

                me->CastSpell(me, LEADER_OF_THE_PACK_BUFF, true);
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
            Heal_Timer = 0;
            formtimer = 0;
            Form = BOT_STANCE_NONE;

            clearcast = false;
            swiftness = false;

            power = POWER_MANA;

            rage = 0;

            rageIncomeMult = sWorld->getRate(RATE_POWER_RAGE_INCOME);
            rageLossMult = sWorld->getRate(RATE_POWER_RAGE_LOSS);

            ragetimer = 0;
            ragetimer2 = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (Heal_Timer > diff)                  Heal_Timer -= diff;
            if (formtimer > diff)                   formtimer -= diff;
            if (ragetimer > diff)                   ragetimer -= diff;
            if (ragetimer2 > diff)                  ragetimer2 -= diff;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();

            InitSpellMap(WARSTOMP_1, true);

            InitSpellMap(MARK_OF_THE_WILD_1);
            InitSpellMap(THORNS_1);
            InitSpellMap(HEALING_TOUCH_1);
            InitSpellMap(REGROWTH_1);
            InitSpellMap(REJUVENATION_1);
            InitSpellMap(LIFEBLOOM_1);
            InitSpellMap(NOURISH_1);
     /*tal*/lvl >= 60 ? InitSpellMap(WILD_GROWTH_1) : RemoveSpell(WILD_GROWTH_1);
     /*tal*/lvl >= 40 ? InitSpellMap(SWIFTMEND_1) : RemoveSpell(SWIFTMEND_1);
            InitSpellMap(TRANQUILITY_1);
            InitSpellMap(REVIVE_1);
            InitSpellMap(REBIRTH_1);
            InitSpellMap(BEAR_FORM_1);
            InitSpellMap(SWIPE_1);
     /*tal*/lvl >= 50 ? InitSpellMap(MANGLE_BEAR_1) : RemoveSpell(MANGLE_BEAR_1);
            InitSpellMap(BASH_1);
            InitSpellMap(CAT_FORM_1);
            InitSpellMap(CLAW_1);
            InitSpellMap(RAKE_1);
            InitSpellMap(SHRED_1);
            InitSpellMap(RIP_1);
     /*tal*/lvl >= 50 ? InitSpellMap(MANGLE_CAT_1) : RemoveSpell(MANGLE_CAT_1);
            InitSpellMap(MOONFIRE_1);
            InitSpellMap(STARFIRE_1);
            InitSpellMap(WRATH_1);
            InitSpellMap(HURRICANE_1);
            InitSpellMap(FAERIE_FIRE_1);
            InitSpellMap(CURE_POISON_1);
            InitSpellMap(INNERVATE_1);
            InitSpellMap(ENTANGLING_ROOTS_1);
     /*tal*/lvl >= 30 ? InitSpellMap(NATURES_SWIFTNESS_1) : RemoveSpell(NATURES_SWIFTNESS_1);

 /*SPECIAL*/InitSpellMap(ECLIPSE_SOLAR_BUFF, true);
 /*SPECIAL*/InitSpellMap(ECLIPSE_LUNAR_BUFF, true);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            //RefreshAura(SPELLDMG2, level >= 78 ? 3 : level >= 65 ? 2 : level >= 50 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION3, level >= 45 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION2, level >= 43 && level < 45 ? 1 : 0);
            RefreshAura(NATURAL_PERFECTION1, level >= 41 && level < 43 ? 1 : 0);
            RefreshAura(LIVING_SEED3, level >= 50 ? 1 : 0);
            RefreshAura(LIVING_SEED2, level >= 48 && level < 50 ? 1 : 0);
            RefreshAura(LIVING_SEED1, level >= 46 && level < 48 ? 1 : 0);
            RefreshAura(REVITALIZE3, level >= 55 ? 3 : 0);
            RefreshAura(REVITALIZE2, level >= 53 && level < 55 ? 2 : 0);
            RefreshAura(REVITALIZE1, level >= 51 && level < 53 ? 2 : 0);
            RefreshAura(GIFT_OF_THE_EARTHMOTHER, level >= 55 ? 1 : 0);
            RefreshAura(OMEN_OF_CLARITY, level >= 70 ? 3 : level >= 40 ? 2 : level >= 20 ? 1 : 0);
            RefreshAura(GLYPH_SWIFTMEND, level >= 45 ? 1 : 0);
            RefreshAura(GLYPH_INNERVATE, level >= 40 ? 1 : 0);
            RefreshAura(NATURESGRACE, level >= 20 ? 1 : 0);
            RefreshAura(ECLIPSE, level >= 50 ? 1 : 0);
            RefreshAura(EARTH_AND_MOON, level >= 55 ? 1 : 0);
            RefreshAura(SURVIVAL_OF_THE_FITTEST, level >= 55 ? 1 : 0);
            RefreshAura(HEART_OF_THE_WILD, level >= 35 ? 1 : 0);
            RefreshAura(NATURAL_REACTION, level >= 35 ? 1 : 0);
            RefreshAura(INFECTED_WOUNDS, level >= 45 ? 1 : 0);
            RefreshAura(FUROR, level >= 10 ? 1 : 0);
            RefreshAura(T9_RESTO_P4_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T8_RESTO_P4_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T9_BALANCE_P2_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T10_BALANCE_P2_BONUS, level >= 78 ? 1 : 0);
            RefreshAura(T10_BALANCE_P4_BONUS, level >= 78 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case MARK_OF_THE_WILD_1:
                case THORNS_1:
                case HEALING_TOUCH_1:
                case REJUVENATION_1:
                case LIFEBLOOM_1:
                case REGROWTH_1:
                case NOURISH_1:
                case WILD_GROWTH_1:
                case SWIFTMEND_1:
                case TRANQUILITY_1:
                case CURE_POISON_1:
                case INNERVATE_1:
                case BEAR_FORM_1:
                case CAT_FORM_1:
                    return true;
                default:
                    return false;
            }
        }

    private:
        //Timers/other
/*Heal*/uint32 Heal_Timer;
/*Misc*/uint32 formtimer, ragetimer, ragetimer2;
/*Form*/uint8 Form;
/*Chck*/bool clearcast, swiftness;
/*Misc*/Powers power; uint32 rage;
/*Misc*/float rageIncomeMult, rageLossMult;

        enum DruidBaseSpells
        {
            MARK_OF_THE_WILD_1                  = 1126,
            THORNS_1                            = 467,
            HEALING_TOUCH_1                     = 5185,
            REGROWTH_1                          = 8936,
            REJUVENATION_1                      = 774,
            LIFEBLOOM_1                         = 33763,
            NOURISH_1                           = 50464,
     /*tal*/WILD_GROWTH_1                       = 48438,
     /*tal*/SWIFTMEND_1                         = 18562,
            TRANQUILITY_1                       = 740,
            REVIVE_1                            = 50769,
            REBIRTH_1                           = 20484,
            BEAR_FORM_1                         = 5487,
            SWIPE_1                             = 779,
     /*tal*/MANGLE_BEAR_1                       = 33878,
            BASH_1                              = 5211, //NYI
            MAUL_1                              = 6807, //NYI
            CAT_FORM_1                          = 768,
            CLAW_1                              = 1082,
            RAKE_1                              = 1822,
            SHRED_1                             = 5221,
            RIP_1                               = 1079,
     /*tal*/MANGLE_CAT_1                        = 33876,
            FEROCIOUS_BITE_1                    = 22568, //NYI
            MOONFIRE_1                          = 8921,
            STARFIRE_1                          = 2912,
            WRATH_1                             = 5176,
            HURRICANE_1                         = 16914,
            FAERIE_FIRE_1                       = 770,
            CURE_POISON_1                       = 8946,
            INNERVATE_1                         = 29166,
            ENTANGLING_ROOTS_1                  = 339,
     /*tal*/NATURES_SWIFTNESS_1                 = 17116,
            WARSTOMP_1                          = 20549
        };
        enum DruidPassives
        {
        //Talents
            OMEN_OF_CLARITY                     = 16864,//clearcast
            NATURESGRACE                        = 61346,//haste 20% for 3 sec
            NATURAL_PERFECTION1                 = 33881,
            NATURAL_PERFECTION2                 = 33882,
            NATURAL_PERFECTION3                 = 33883,
            LIVING_SEED1                        = 48496,//rank 1
            LIVING_SEED2                        = 48499,//rank 2
            LIVING_SEED3                        = 48500,//rank 3
            REVITALIZE1                         = 48539,//rank 1
            REVITALIZE2                         = 48544,//rank 2
            REVITALIZE3                         = 48545,//rank 3
            GIFT_OF_THE_EARTHMOTHER             = 51183,//rank 5
            ECLIPSE                             = 48525,//rank 3
            EARTH_AND_MOON                      = 48511,//rank 3
            SURVIVAL_OF_THE_FITTEST             = 33856,//rank 3
            HEART_OF_THE_WILD                   = 24894,//rank 5
            FUROR                               = 17061,//rank 5
            NATURAL_REACTION                    = 57881,//rank 3
            INFECTED_WOUNDS                     = 48485,//rank 3
        //Glyphs
            GLYPH_SWIFTMEND                     = 54824,//no consumption
            GLYPH_INNERVATE                     = 54832,//self regen
        //other
            T9_RESTO_P4_BONUS                   = 67128,//rejuve crits
            T8_RESTO_P4_BONUS                   = 64760,//rejuve init heal
            T9_BALANCE_P2_BONUS                 = 67125,//moonfire crits
            T10_BALANCE_P2_BONUS                = 70718,//omen of doom (15%)
            T10_BALANCE_P4_BONUS                = 70723,//Languish(DOT)
            //SPELLDMG/*Arcane Instability-mage*/ = 15060,//rank3 3% dam/crit
            //SPELLDMG2/*Earth and Moon - druid*/ = 48511,//rank3 6% dam
            ENERGIZE                            = 27787,//Rogue Armor Energize (chance: +35 energy on hit)
            CRIT_50                             = 23434 //50% spell crit
        };
        enum DruidSpecial
        {
            HURRICANE_DAMAGE_1                  = 42231,
            TRANQUILITY_HEAL_1                  = 44203,
  /*Talent*/LEADER_OF_THE_PACK_BUFF             = 24932,
            //NATURESGRACEBUFF                    = 16886,
            ECLIPSE_SOLAR_BUFF                  = 48517,// from Starfire to Wrath
            ECLIPSE_LUNAR_BUFF                  = 48518,// from Wrath to Starfire
            OMEN_OF_CLARITY_BUFF                = 16870,//434 deprecated

            PRIMAL_FURY_EFFECT_ENERGIZE         = 16959 //5 rage
        };
    };
};

void AddSC_druid_bot()
{
    new druid_bot();
}
