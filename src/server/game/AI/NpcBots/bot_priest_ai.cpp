#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Map.h"
//#include "WorldSession.h"
/*
Priest NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - Around 50%
TODO: maybe remove Divine Spirit or so, too much buffs
*/
class priest_bot : public CreatureScript
{
public:
    priest_bot() : CreatureScript("priest_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new priest_botAI(creature);
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

    struct priest_botAI : public bot_minion_ai
    {
        priest_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_PRIEST;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_PRIEST) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId, triggered);
        }

        bool MassGroupHeal(Player* player, uint32 diff)
        {
            if (IAmFree() || !player->GetGroup()) return false;
            if (IsCasting()) return false;
            if (Rand() > 35) return false;

            if (IsSpellReady(DIVINE_HYMN_1, diff, false))
            {
                Group* gr = player->GetGroup();
                uint8 LHPcount = 0;
                for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* tPlayer = itr->GetSource();
                    if (!tPlayer || !tPlayer->IsInWorld() || me->GetMap() != tPlayer->FindMap() ||
                        tPlayer->IsBeingTeleported() || tPlayer->isPossessed() || tPlayer->IsCharmed()) continue;
                    if (tPlayer->IsAlive())
                    {
                        if (me->GetExactDist(tPlayer) > 35) continue;
                        uint8 pct = 50 + tPlayer->getAttackers().size()*10;
                        pct = pct < 80 ? pct : 80;
                        if (GetHealthPCT(tPlayer) < pct && GetLostHP(tPlayer) > 4000)
                            ++LHPcount;
                    }
                    if (LHPcount > 1)
                        break;
                    if (!tPlayer->HaveBot()) continue;
                    BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* bot = it->second;
                        if (bot && GetHealthPCT(bot) < 40 && me->GetExactDist(bot) < 30)
                            ++LHPcount;
                        if (LHPcount > 1)
                            break;
                    }
                }
                if (LHPcount > 1 && doCast(me, GetSpell(DIVINE_HYMN_1)))
                    return true;
            }
            if (GetSpell(PRAYER_OF_HEALING_1))
            {
                Group* gr = player->GetGroup();
                Unit* castTarget = NULL;
                uint8 LHPcount = 0;
                for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    uint8 lowestPCT = 100;
                    Player* tPlayer = itr->GetSource();
                    if (!tPlayer || !tPlayer->IsInWorld() || me->GetMap() != tPlayer->GetMap() ||
                        tPlayer->IsBeingTeleported() || tPlayer->isPossessed() || tPlayer->IsCharmed()) continue;
                    if (tPlayer->IsAlive())
                    {
                        if (me->GetExactDist(tPlayer) > 25) continue;
                        if (GetHealthPCT(tPlayer) < 85)
                        {
                            ++LHPcount;
                            if (GetHealthPCT(tPlayer) < lowestPCT)
                            lowestPCT = GetHealthPCT(tPlayer);
                            castTarget = tPlayer;
                        }
                    }
                    if (LHPcount > 2)
                        break;
                    if (!tPlayer->HaveBot()) continue;
                    BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Creature* bot = it->second;
                        if (bot && GetHealthPCT(bot) < 70 && me->GetExactDist(bot) < 15)
                        {
                            ++LHPcount;
                            if (GetHealthPCT(bot) < lowestPCT)
                            lowestPCT = GetHealthPCT(bot);
                            castTarget = bot;
                        }
                        if (LHPcount > 2)
                            break;
                    }
                }

                if (LHPcount > 2 && castTarget && doCast(castTarget, GetSpell(PRAYER_OF_HEALING_1)))
                    return true;
            }

            return false;
        }

        bool ShieldTarget(Unit* target, uint32 diff)
        {
            if (!IsSpellReady(PW_SHIELD_1, diff, false) || IsCasting() || Rand() > 50)
                return false;
            if (me->GetExactDist(target) > 40)
                return false;
            if (target->getAttackers().empty() && GetHealthPCT(target) > 33 &&
                !target->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE))
                return false;
            if (target->HasAura(WEAKENED_SOUL_DEBUFF) || HasAuraName(target, PW_SHIELD_1))
                return false;

            if (doCast(target, GetSpell(PW_SHIELD_1)))
            {
                GC_Timer = 800;
                return true;
            }
            return false;
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
            Disperse(diff);
            BreakCC(diff);
            if (CCed(me)) return;
            DoDevCheck(diff);

            if (Potion_cd <= diff && GetManaPCT(me) < 33)
            {
                temptimer = GC_Timer;
                if (doCast(me, MANAPOTION))
                {
                    Potion_cd = POTION_CD;
                    GC_Timer = temptimer;
                }
            }
            //check possible fear
            doDefend(diff);
            //buff and heal master's group
            MassGroupHeal(master, diff);
            BuffAndHealGroup(master, diff);
            CureGroup(master, GetSpell(DISPEL_MAGIC_1), diff);
            CureGroup(master, GetSpell(CURE_DISEASE_1), diff);
            //ShieldGroup(master);
            if (master->IsInCombat() || me->IsInCombat())
            {
                CheckDispel(diff);
                CheckSilence(diff);
            }

            if (me->IsInCombat())
                CheckShackles(diff);
            else
                DoNonCombatActions(diff);

            if (!CheckAttackTarget(BOT_CLASS_PRIEST))
                return;

            AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();

            if (GetHealthPCT(master) > 90 && GetManaPCT(me) > 35 && GetHealthPCT(me) > 90 &&
                (m_attackers.size() < 4 || b_attackers.size() + m_attackers.size() < 3) &&
                !IsCasting())
                //general rule
            {
                opponent = me->GetVictim();
                if (opponent)
                {
                    if (!IsCasting())
                        StartAttack(opponent);
                }
                else
                    return;
                float dist = me->GetExactDist(opponent);
                if (HasRole(BOT_ROLE_DPS) && dist < 30)
                {
                    if (IsSpellReady(SW_DEATH_1, diff, false) && Rand() < 50 &&
                        (GetHealthPCT(opponent) < 15 || opponent->GetHealth() < me->GetMaxHealth()/6) &&
                        doCast(opponent, GetSpell(SW_DEATH_1)))
                        return;
                    if (IsSpellReady(SW_PAIN_1, diff) && Rand() < 25 &&
                        opponent->GetHealth() > me->GetMaxHealth()/4 &&
                        !HasAuraName(opponent, SW_PAIN_1, me->GetGUID()) &&
                        doCast(opponent, GetSpell(SW_PAIN_1)))
                        return;
                    if (IsSpellReady(VAMPIRIC_TOUCH_1, diff) && Rand() < 50 &&
                        opponent->GetHealth() > me->GetMaxHealth()/4 &&
                        !HasAuraName(opponent, VAMPIRIC_TOUCH_1, me->GetGUID()) &&
                        doCast(opponent, GetSpell(VAMPIRIC_TOUCH_1)))
                        return;
                    if (IsSpellReady(DEVOURING_PLAGUE_1, diff) && !Devcheck && Rand() < 30 &&
                        opponent->GetHealth() > me->GetMaxHealth()/3 &&
                        !HasAuraName(opponent, DEVOURING_PLAGUE_1, me->GetGUID()) &&
                        doCast(opponent, GetSpell(DEVOURING_PLAGUE_1)))
                        return;
                    if (IsSpellReady(MIND_BLAST_1, diff) && Rand() < 35 &&
                        (!GetSpell(VAMPIRIC_TOUCH_1) || HasAuraName(opponent, VAMPIRIC_TOUCH_1, me->GetGUID())) &&
                        doCast(opponent, GetSpell(MIND_BLAST_1)))
                        return;
                    if (IsSpellReady(MIND_FLAY_1, diff, false) && Rand() < 20 &&
                        (opponent->isMoving() || opponent->GetHealth() < me->GetMaxHealth()/5 ||
                        (HasAuraName(opponent, SW_PAIN_1, me->GetGUID()) && HasAuraName(opponent, DEVOURING_PLAGUE_1, me->GetGUID()))) &&
                        doCast(opponent, GetSpell(MIND_FLAY_1)))
                        return;
                    if (IsSpellReady(MIND_SEAR_1, diff, false) && !opponent->isMoving() && dist < 35 && Rand() < 50 &&
                        HasAuraName(opponent, SW_PAIN_1, me->GetGUID()) &&
                        HasAuraName(opponent, DEVOURING_PLAGUE_1, me->GetGUID()))
                    {
                        if (Unit* u = FindSplashTarget(30, opponent))
                            if (doCast(u, GetSpell(MIND_SEAR_1)))
                                return;
                    }
                    if (Item const* item = GetEquips(2))
                    if (IsSpellReady(WAND_SHOOT_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 30 && GC_Timer <= diff &&
                        doCast(opponent, GetSpell(WAND_SHOOT_1)))
                    {
                        uint32 WandSpeed = me->GetAttackTime(RANGED_ATTACK);
                        GC_Timer = WandSpeed;
                        return;
                    }
                }//endif opponent
            }//endif damage
            //check horror after dots/damage
            if (IsSpellReady(PSYCHIC_HORROR_1, diff, false) &&
                opponent->GetCreatureType() != CREATURE_TYPE_UNDEAD &&
                opponent->GetHealth() > me->GetMaxHealth()/5 && !CCed(opponent) && Rand() < 30 &&
                me->GetExactDist(opponent) < 30 && !HasAuraName(opponent, PSYCHIC_HORROR_1))
            {
                if (doCast(opponent, GetSpell(PSYCHIC_HORROR_1)))
                    return;
            }
        }//end UpdateAI

        bool HealTarget(Unit* target, uint8 hp, uint32 diff)
        {
            if (!HasRole(BOT_ROLE_HEAL))
                return false;
            if (hp > 98)
                return false;
            if (!target || !target->IsAlive() || me->GetExactDist(target) > 40)
                return false;
            if (Rand() > 50 + 20*target->IsInCombat() + 50*master->GetMap()->IsRaid())
                return false;

            //GUARDIAN SPIRIT
            if (IsSpellReady(GUARDIAN_SPIRIT_1, diff, false) && !IAmFree() && target->IsInCombat() &&
                !target->getAttackers().empty() && hp < (5 + std::min(20, uint8(target->getAttackers().size())*5)) &&
                IsInBotParty(target) &&
                Rand() < 80 && !target->HasAura(GetSpell(GUARDIAN_SPIRIT_1)))
            {
                temptimer = GC_Timer;
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                if (doCast(target, GetSpell(GUARDIAN_SPIRIT_1)))
                {
                    GC_Timer = temptimer;
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        BotWhisper("Guardian Spirit on you!", target->ToPlayer());
                    else if (!IAmFree())
                    {
                        std::ostringstream msg;
                        msg << "Guardian Spirit on " << (target == me ? "myself" : target->GetName()) << '!';
                        BotWhisper(msg.str().c_str(), master);
                    }

                    return true;
                }
            }

            if (IsCasting()) return false;

            //PAIN SUPPRESSION
            if (hp < 35 && IsSpellReady(PAIN_SUPPRESSION_1, diff, false) &&
                (target->IsInCombat() || !target->getAttackers().empty()) && Rand() < 50 &&
                !target->HasAura(GetSpell(PAIN_SUPPRESSION_1)))
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);
                temptimer = GC_Timer;
                if (doCast(target, GetSpell(PAIN_SUPPRESSION_1)))
                {
                    GC_Timer = temptimer;
                    if (target->GetTypeId() == TYPEID_PLAYER)
                        BotWhisper("Pain Suppression on you!", target->ToPlayer());
                    else if (!IAmFree())
                    {
                        std::ostringstream msg;
                        msg << "Guardin Spirit on " << (target == me ? "myself" : target->GetName()) << '!';
                        BotWhisper(msg.str().c_str(), master);
                    }

                    return true;
                }
            }

            //Now Heals Requires GCD
            if ((hp < 80 || !target->getAttackers().empty()) &&
                ShieldTarget(target, diff))
                return true;

            //PENANCE/Greater Heal
            if (hp < 75 || GetLostHP(target) > 4000)
            {
                if (IsSpellReady(PENANCE_1, diff, false) && !me->isMoving() && Rand() < 80 &&
                    (target->GetTypeId() != TYPEID_PLAYER ||
                    !(target->ToPlayer()->IsCharmed() || target->ToPlayer()->isPossessed())) &&
                    doCast(target, GetSpell(PENANCE_1)))
                    return true;
                else if (HEAL && Heal_Timer <= diff && GC_Timer <= diff && hp > 50 && Rand() < 70 &&
                    doCast(target, HEAL))
                {
                    Heal_Timer = 2500;
                    return true;
                }
            }
            //Flash Heal
            if (IsSpellReady(FLASH_HEAL_1, diff) &&
                ((hp > 75 && hp < 90) || hp < 50 || GetLostHP(target) > 1500) &&
                doCast(target, GetSpell(FLASH_HEAL_1)))
                return true;
            //maintain HoTs
            Unit* u = target->GetVictim();
            Creature* boss = u && u->ToCreature() && u->ToCreature()->isWorldBoss() ? u->ToCreature() : NULL;
            bool tanking = IsTank(target) && boss;
            //Renew
            if (IsSpellReady(RENEW_1, diff) &&
                ((hp < 98 && hp > 70) || GetLostHP(target) > 500 || tanking) &&
                !HasAuraName(target, RENEW_1, me->GetGUID()) &&
                doCast(target, GetSpell(RENEW_1)))
            {
                GC_Timer = 800;
                return true;
            }

            return false;
        }

        bool BuffTarget(Unit* target, uint32 diff)
        {
            if (!target || !target->IsInWorld() || target->isDead() ||
                GC_Timer > diff || me->GetExactDist(target) > 30 || Rand() > 20)
                return false;

            if (IsSpellReady(FEAR_WARD_1, diff, false) &&
                !target->HasAuraTypeWithMiscvalue(SPELL_AURA_MECHANIC_IMMUNITY, MECHANIC_FEAR) &&
                doCast(target, GetSpell(FEAR_WARD_1)))
            {
                GC_Timer = 800;
                return true;
            }

            if (target == me)
            {
                uint32 INNER_FIRE = GetSpell(INNER_FIRE_1);
                if (INNER_FIRE && !me->HasAura(INNER_FIRE) &&
                    doCast(me, INNER_FIRE))
                {
                    GC_Timer = 800;
                    return true;
                }
                uint32 VAMPIRIC_EMBRACE = GetSpell(VAMPIRIC_EMBRACE_1);
                if (VAMPIRIC_EMBRACE && !me->HasAura(VAMPIRIC_EMBRACE) &&
                    doCast(me, VAMPIRIC_EMBRACE))
                {
                    GC_Timer = 800;
                    return true;
                }
            }

            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (uint32 PW_FORTITUDE = GetSpell(PW_FORTITUDE_1))
            {
                if (!HasAuraName(target, PW_FORTITUDE) &&
                    doCast(target, PW_FORTITUDE))
                {
                    /*GC_Timer = 800;*/
                    return true;
                }
            }
            if (uint32 SHADOW_PROTECTION = GetSpell(SHADOW_PROTECTION_1))
            {
                if (!HasAuraName(target, SHADOW_PROTECTION) &&
                    doCast(target, SHADOW_PROTECTION))
                {
                    /*GC_Timer = 800;*/
                    return true;
                }
            }
            if (uint32 DIVINE_SPIRIT = GetSpell(DIVINE_SPIRIT_1))
            {
                if (!HasAuraName(target, DIVINE_SPIRIT) &&
                    doCast(target, DIVINE_SPIRIT))
                {
                    /*GC_Timer = 800;*/
                    return true;
                }
            }

            return false;
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting())
                return;

            RezGroup(GetSpell(RESURRECTION_1), master);

            //if (Feasting())
            //    return;

            //if (BuffTarget(master, diff))
            //    return;
            //if (BuffTarget(me, diff))
            //    return;
        }

        void CheckDispel(uint32 diff)
        {
            if (CheckDispelTimer > diff || Rand() > 25 || IsCasting())
                return;

            uint32 DM = GetSpell(DISPEL_MAGIC_1);
            uint32 MD = GetSpell(MASS_DISPEL_1);

            if (!DM && !MD)
                return;

            if (Unit* target = FindHostileDispelTarget())
            {
                uint32 dm = DM && !target->IsImmunedToSpell(sSpellMgr->GetSpellInfo(DM),me) ? DM : MD;
                if (target && doCast(target, dm))
                {
                    CheckDispelTimer = 1000;
                    GC_Timer = 800;
                    return;
                }
            }

            CheckDispelTimer = 2000; //fail
        }

        void CheckShackles(uint32 diff)
        {
            if (!IsSpellReady(SHACKLE_UNDEAD_1, diff) || IsCasting() || Rand() > 50)
                return;

            uint32 SHACKLE_UNDEAD = GetSpell(SHACKLE_UNDEAD_1);
            if (FindAffectedTarget(SHACKLE_UNDEAD, me->GetGUID()))
            {
                Shackle_Timer = 1500;
                return;
            }
            Unit* target = FindUndeadCCTarget(30, SHACKLE_UNDEAD);
            if (target && doCast(target, SHACKLE_UNDEAD))
            {
                Shackle_Timer = 3000;
                GC_Timer = 800;
            }
        }

        void CheckSilence(uint32 diff)
        {
            if (IsCasting()) return;
            temptimer = GC_Timer;
            if (IsSpellReady(SILENCE_1, diff, false))
            {
                if (Unit* target = FindCastingTarget(30))
                    if (doCast(target, GetSpell(SILENCE_1)))
                    {}
            }
            else if (IsSpellReady(PSYCHIC_HORROR_1, diff, false, 20000))
            {
                if (Unit* target = FindCastingTarget(30))
                    if (doCast(target, GetSpell(PSYCHIC_HORROR_1)))
                    {}
            }
            GC_Timer = temptimer;
        }

        void doDefend(uint32 diff)
        {
            AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();

            //fear master's attackers
            if (IsSpellReady(PSYCHIC_SCREAM_1, diff, false))
            {
                if (!m_attackers.empty() && (!IsTank(master) || GetHealthPCT(master) < 75))
                {
                    uint8 tCount = 0;
                    for (AttackerSet::iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->ToCreature() && (*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetExactDist((*iter)) > 7) continue;
                        if (CCed(*iter) && me->GetExactDist((*iter)) > 5) continue;
                        if (me->IsValidAttackTarget(*iter))
                            ++tCount;
                    }
                    if (tCount > 1 && doCast(me, GetSpell(PSYCHIC_SCREAM_1)))
                        return;
                }

                // Defend myself (psychic horror)
                if (!b_attackers.empty())
                {
                    uint8 tCount = 0;
                    for (AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->ToCreature() && (*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetExactDist((*iter)) > 7) continue;
                        if (CCed(*iter) && me->GetExactDist((*iter)) > 5) continue;
                        if (me->IsValidAttackTarget(*iter))
                            ++tCount;
                    }
                    if (tCount > 0 && doCast(me, GetSpell(PSYCHIC_SCREAM_1)))
                        return;
                }
            }
            // Heal myself
            if (GetHealthPCT(me) < 98 && !b_attackers.empty())
            {
                if (ShieldTarget(me, diff)) return;

                if (IsSpellReady(FADE_1, diff, false) && me->IsInCombat())
                {
                    if (b_attackers.empty()) return;
                    uint8 Tattackers = 0;
                    for (AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->isDead()) continue;
                        if (!(*iter)->ToCreature()) continue;
                        if (!(*iter)->CanHaveThreatList()) continue;
                        if (me->GetExactDist((*iter)) < 15)
                            Tattackers++;
                    }
                    if (Tattackers > 0)
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(FADE_1)))
                        {
                            for (AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                                if ((*iter)->GetThreatManager().getThreat(me) > 0.f)
                                    (*iter)->GetThreatManager().ModifyThreatByPercent(me, -50);
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                }
                if (GetHealthPCT(me) < 90 && HealTarget(me, GetHealthPCT(me), diff))
                    return;
            }
        }

        void DoDevCheck(uint32 diff)
        {
            if (DevcheckTimer <= diff)
            {
                Devcheck = FindAffectedTarget(GetSpell(DEVOURING_PLAGUE_1), me->GetGUID());
                DevcheckTimer = 5000;
            }
        }

        void Disperse(uint32 diff)
        {
            if (!IsSpellReady(DISPERSION_1, diff) || IsCasting() || Rand() > 60)
                return;
            if ((me->getAttackers().size() > 3 && !IsSpellReady(FADE_1, diff, false) && GetHealthPCT(me) < 90) ||
                (GetHealthPCT(me) < 20 && me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
                (GetManaPCT(me) < 30) ||
                (me->getAttackers().size() > 1 && me->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT))))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(DISPERSION_1)))
                {}
                GC_Timer = temptimer;
                return;
            }

            SetSpellCooldown(DISPERSION_1, 2000); //fail
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //434 new
                //Improved Fire Blast (part 1): 8% additional crit chance for Fire Blast
                //if (lvl >= 11 && spellId == FLAMESTRIKE)
                //    aftercrit += 8.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                ////!!!spell damage is not yet critical and will be multiplied by 1.5
                ////so we should put here bonus damage mult /1.5
                ////Ice Shards: 50% additional crit damage bonus for Frost spells
                //else if (lvl >= 15 && (SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()))
                //    pctbonus += 0.333f;
            }
            //Focused Power: 4% bonus damage for all spells
            if (lvl >= 35)
                pctbonus += 0.04f;
            //Darkness: 10% bonus damage for shadow spells
            if (lvl >= 10 && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_SHADOW))
                pctbonus += 0.1f;
            //Twin Disciplines (damage part): 5% bonus damage for instant spells
            if (lvl >= 13 && !spellInfo->CalcCastTime())
                pctbonus += 0.05f;
            //Twisted Faith (part 1): 10% bonus damage for Mind Blast and Mind Flay if target is affected BY SW: Pain
            if (lvl >= 55 && (spellId == GetSpell(SW_PAIN_1) || spellId == GetSpell(MIND_FLAY_1)) &&
                damageinfo.target && damageinfo.target->HasAura(GetSpell(SW_PAIN_1), me->GetGUID()))
                pctbonus += 0.1f;
            //Mind Melt (part 1): 30% bonus damage for Shadow Word: Death
            if (lvl >= 41 && spellId == GetSpell(SW_DEATH_1))
                pctbonus += 0.3f;

            //Glyph of Mind Flay: 10% damage bonus for Mind Flay
            if (lvl >= 25 && spellId == GetSpell(MIND_FLAY_1))
                pctbonus += 0.1f;

            //other
            if (spellId == SW_DEATH_BACKLASH)
            {
                ////T13 Shadow 2P Bonus (Shadow Word: Death), part 2
                //if (lvl >= 60) //buffed
                //    pctbonus -= 0.95f;
                //Pain and Suffering (part 2): 40% reduced backlash damage
                if (lvl >= 50)
                    pctbonus -= 0.4f;

                pctbonus = std::min<float>(pctbonus, 1.0f);
            }

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Improved Renew: 15% bonus healing for Renew
            if (lvl >= 10 && spellId == GetSpell(RENEW_1))
                pctbonus += 0.15f;
            //Spiritual Healing: 10% bonus healing for all spells
            if (lvl >= 35)
                pctbonus += 0.15f;
            //Blessend Resilience: 3% bonus healing for all spells
            if (lvl >= 40)
                pctbonus += 0.03f;
            //Empowered Healing: 40% bonus (from spellpower) for Greater Heal and 20% bonus (from spellpower) for Flash Heal
            if (lvl >= 45)
            {
                if (spellId == HEAL)
                    flat_mod += spellpower * 0.4f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
                else if (spellId == GetSpell(FLASH_HEAL_1))
                    flat_mod += spellpower * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
            }
            //Impowered Renew (heal bonus part): 15% bonus healing for Renew
            if (lvl >= 50 && spellId == GetSpell(RENEW_1))
                flat_mod += spellpower *  0.15f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * int32(stack) * 1.88f * me->CalculateLevelPenalty(spellInfo) * stack;
            //Test of Faith: 12% bonus healing on targets at or below 50% health
            if (lvl >= 50 && GetHealthPCT(victim) <= 50)
                pctbonus += 0.12f;
            //Test of Faith: 10 bonus healing for Circle of Healing, Binding Heal, Holy Nova, Prayer of Healing, Divine Hymn and Prayer of Mending
            if (lvl >= 55 &&
                (/*spellId == GetSpell(CIRCLE_OF_HEALING_1) || spellId == GetSpell(BINDING_HEAL_1) ||
                spellId == GetSpell(HOLY_NOVA_1) || */spellId == GetSpell(PRAYER_OF_HEALING_1) ||
                spellId == DIVINE_HYMN_HEAL/* || spellId == GetSpell(PRAYER_OF_MENDING_1)*/))
                pctbonus += 0.12f;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassCritMultiplierHeal(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float aftercrit = 0.0f;

            //Improved Flash Heal (part 2): 10% additional critical chance on targets at or below 50% hp for Flash Heal
            if (lvl >= 40 && spellId == GetSpell(FLASH_HEAL_1) && GetHealthPCT(victim) <= 50)
                aftercrit += 10.f;
            //Holy Specialization: 5% additional critical chance for Holy spells
            if (lvl >= 10 && (schoolMask & SPELL_SCHOOL_MASK_HOLY))
                aftercrit += 5.f;

            crit_chance += aftercrit;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            ////Strength of Soul: direct heals reduce Weakened Soul duration on target by 4 sec
            //if (spellId == HEAL || spellId == GetSpell(FLASH_HEAL_1))
            //{
            //    if (me->getLevel() >= 51)
            //    {
            //        if (Aura* soul = target->GetAura(WEAKENED_SOUL_DEBUFF))
            //        {
            //            if (soul->GetDuration() > 4000)
            //                soul->SetDuration(soul->GetDuration() - 4000);
            //            else
            //                target->RemoveAura(soul, AURA_REMOVE_BY_EXPIRE);
            //        }
            //    }
            //}

            //Weakened Soul Reduction (id: 33333 lol): -2 sec to Weakened Soul duration
            if (spellId == WEAKENED_SOUL_DEBUFF)
                if (me->getLevel() >= 51)
                    if (Aura* soul = target->GetAura(WEAKENED_SOUL_DEBUFF))
                        soul->SetDuration(soul->GetDuration() - 2000);

            //Pain and Suffering (part 1, 335 version): 100% to refresh Shadow Word: Pain on target hit by Mind Flay
            if (spellId == GetSpell(MIND_FLAY_1))
                if (me->getLevel() >= 51)
                    if (Aura* pain = target->GetAura(GetSpell(SW_PAIN_1), me->GetGUID()))
                        pain->RefreshDuration();

            if (spellId == GetSpell(FEAR_WARD_1))
            {
                //2 minutes bonus duration for Fear Ward
                if (Aura* ward = target->GetAura(GetSpell(FEAR_WARD_1), me->GetGUID()))
                {
                    uint32 dur = ward->GetDuration() + 120000;
                    ward->SetDuration(dur);
                    ward->SetMaxDuration(dur);
                }
            }

            if (spellId == GetSpell(INNER_FIRE_1) || spellId == GetSpell(VAMPIRIC_EMBRACE_1) || spellId == GetSpell(PW_FORTITUDE_1) ||
                spellId == GetSpell(SHADOW_PROTECTION_1) || spellId == GetSpell(DIVINE_SPIRIT_1))
            {
                //1 hour duration for all buffs
                if (Aura* buff = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = HOUR * IN_MILLISECONDS;
                    buff->SetDuration(dur);
                    buff->SetMaxDuration(dur);
                }
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
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
            Shackle_Timer = 0;

            CheckDispelTimer = 0;
            DevcheckTimer = 0;

            Devcheck = false;

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (Heal_Timer > diff)                  Heal_Timer -= diff;
            if (Shackle_Timer > diff)               Shackle_Timer -= diff;

            if (CheckDispelTimer > diff)            CheckDispelTimer -= diff;
            if (DevcheckTimer > diff)               DevcheckTimer -= diff;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(DISPEL_MAGIC_1);
            InitSpellMap(MASS_DISPEL_1);
            InitSpellMap(CURE_DISEASE_1);
            InitSpellMap(FEAR_WARD_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(PAIN_SUPPRESSION_1) : RemoveSpell(PAIN_SUPPRESSION_1);
            InitSpellMap(PSYCHIC_SCREAM_1);
            InitSpellMap(FADE_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(PSYCHIC_HORROR_1) : RemoveSpell(PSYCHIC_HORROR_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(SILENCE_1) : RemoveSpell(SILENCE_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(PENANCE_1) : RemoveSpell(PENANCE_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(VAMPIRIC_EMBRACE_1) : RemoveSpell(VAMPIRIC_EMBRACE_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(DISPERSION_1) : RemoveSpell(DISPERSION_1);
            InitSpellMap(MIND_SEAR_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(GUARDIAN_SPIRIT_1) : RemoveSpell(GUARDIAN_SPIRIT_1);
            InitSpellMap(SHACKLE_UNDEAD_1);
            InitSpellMap(GREATER_HEAL_1);
            InitSpellMap(NORMAL_HEAL_1);
            InitSpellMap(LESSER_HEAL_1);
            InitSpellMap(RENEW_1);
            InitSpellMap(FLASH_HEAL_1);
            InitSpellMap(PRAYER_OF_HEALING_1);
            InitSpellMap(DIVINE_HYMN_1);
            InitSpellMap(RESURRECTION_1);
            InitSpellMap(PW_SHIELD_1);
            InitSpellMap(INNER_FIRE_1);
            InitSpellMap(PW_FORTITUDE_1);
            InitSpellMap(SHADOW_PROTECTION_1);
            InitSpellMap(DIVINE_SPIRIT_1);
            InitSpellMap(SW_PAIN_1);
            InitSpellMap(MIND_BLAST_1);
            InitSpellMap(WAND_SHOOT_1);
            InitSpellMap(SW_DEATH_1);
            InitSpellMap(DEVOURING_PLAGUE_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(MIND_FLAY_1) : RemoveSpell(MIND_FLAY_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(VAMPIRIC_TOUCH_1) : RemoveSpell(VAMPIRIC_TOUCH_1);

            HEAL = GetSpell(GREATER_HEAL_1) ? GetSpell(GREATER_HEAL_1) :
                GetSpell(NORMAL_HEAL_1) ? GetSpell(NORMAL_HEAL_1) :
                GetSpell(LESSER_HEAL_1);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            RefreshAura(BORROWED_TIME, level >= 65 ? 1 : 0);
            RefreshAura(DIVINE_AEGIS, level >= 55 ? 1 : 0);
            RefreshAura(EMPOWERED_RENEW3, level >= 55 ? 1 : 0);
            RefreshAura(EMPOWERED_RENEW2, level >= 50 && level < 55 ? 1 : 0);
            RefreshAura(EMPOWERED_RENEW1, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(BODY_AND_SOUL1, level >= 45 ? 1 : 0);
            RefreshAura(RENEWED_HOPE, level >= 45 ? 1 : 0);
            RefreshAura(PAINANDSUFFERING3, level >= 50 ? 1 : 0);
            RefreshAura(PAINANDSUFFERING2, level >= 48 && level < 50 ? 1 : 0);
            RefreshAura(PAINANDSUFFERING1, level >= 45 && level < 48 ? 1 : 0);
            RefreshAura(MISERY3, level >= 50 ? 1 : 0);
            RefreshAura(MISERY2, level >= 48 && level < 50 ? 1 : 0);
            RefreshAura(MISERY1, level >= 45 && level < 48 ? 1 : 0);
            RefreshAura(GRACE, level >= 25 ? 1 : 0);
            RefreshAura(ENLIGHTENMENT, level >= 35 ? 1 : 0);
            RefreshAura(RAPTURE, level >= 45 ? 1 : 0);
            RefreshAura(IMPROVED_DEVOURING_PLAGUE, level >= 25 ? 1 : 0);
            RefreshAura(INSPIRATION3, level >= 25 ? 1 : 0);
            RefreshAura(INSPIRATION2, level >= 23 && level < 25 ? 1 : 0);
            RefreshAura(INSPIRATION1, level >= 20 && level < 23 ? 1 : 0);
            RefreshAura(SHADOW_WEAVING3, level >= 30 ? 1 : 0);
            RefreshAura(SHADOW_WEAVING2, level >= 28 && level < 30 ? 1 : 0);
            RefreshAura(SHADOW_WEAVING1, level >= 25 && level < 28 ? 1 : 0);
            RefreshAura(GLYPH_SW_PAIN, level >= 15? 1 : 0);
            RefreshAura(GLYPH_PW_SHIELD, level >= 15 ? 1 : 0);
            RefreshAura(SHADOWFORM, level >= 40 ? 1 : 0);
            RefreshAura(PRIEST_T10_2P_BONUS, level >= 70 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case DISPEL_MAGIC_1:
                case MASS_DISPEL_1:
                case CURE_DISEASE_1:
                case FEAR_WARD_1:
                case PAIN_SUPPRESSION_1:
                case FADE_1:
                case PENANCE_1:
                case VAMPIRIC_EMBRACE_1:
                case DISPERSION_1:
                case GUARDIAN_SPIRIT_1:
                case LESSER_HEAL_1:
                case NORMAL_HEAL_1:
                case GREATER_HEAL_1:
                case RENEW_1:
                case FLASH_HEAL_1:
                case PRAYER_OF_HEALING_1:
                case DIVINE_HYMN_1:
                case PW_SHIELD_1:
                case INNER_FIRE_1:
                case PW_FORTITUDE_1:
                case SHADOW_PROTECTION_1:
                case DIVINE_SPIRIT_1:
                    return true;
                default:
                    return false;
            }
        }

    private:
        uint32 HEAL;
        uint32 Heal_Timer, Shackle_Timer;
/*Misc*/uint16 CheckDispelTimer, DevcheckTimer;
/*Misc*/bool Devcheck;

        enum PriestBaseSpells
        {
            DISPEL_MAGIC_1                      = 527,
            MASS_DISPEL_1                       = 32375,
            CURE_DISEASE_1                      = 528,
            FEAR_WARD_1                         = 6346,
  /*Talent*/PAIN_SUPPRESSION_1                  = 33206,
            PSYCHIC_SCREAM_1                    = 8122,
            FADE_1                              = 586,
  /*Talent*/PSYCHIC_HORROR_1                    = 64044,
  /*Talent*/SILENCE_1                           = 15487,
  /*Talent*/PENANCE_1                           = 47540,
  /*Talent*/VAMPIRIC_EMBRACE_1                  = 15286,
  /*Talent*/DISPERSION_1                        = 47585,
            MIND_SEAR_1                         = 48045,
  /*Talent*/GUARDIAN_SPIRIT_1                   = 47788,
            SHACKLE_UNDEAD_1                    = 9484,
            LESSER_HEAL_1                       = 2050,
            NORMAL_HEAL_1                       = 2054,
            GREATER_HEAL_1                      = 2060,
            RENEW_1                             = 139,
            FLASH_HEAL_1                        = 2061,
            PRAYER_OF_HEALING_1                 = 596,
            DIVINE_HYMN_1                       = 64843,
            RESURRECTION_1                      = 2006,
            PW_SHIELD_1                         = 17,
            INNER_FIRE_1                        = 588,
            PW_FORTITUDE_1                      = 1243,
            SHADOW_PROTECTION_1                 = 976,
            DIVINE_SPIRIT_1                     = 14752,
            SW_PAIN_1                           = 589,
            MIND_BLAST_1                        = 8092,
            SW_DEATH_1                          = 32379,
            WAND_SHOOT_1                        = 5019,
            DEVOURING_PLAGUE_1                  = 2944,
  /*Talent*/MIND_FLAY_1                         = 15407,
  /*Talent*/VAMPIRIC_TOUCH_1                    = 34914
        };
        enum PriestPassives
        {
            SHADOWFORM  /*For DOT crits*/   = 49868,
        //Talents
            IMPROVED_DEVOURING_PLAGUE       = 63627,//rank 3
            MISERY1                         = 33191,
            MISERY2                         = 33192,
            MISERY3                         = 33193,
            PAINANDSUFFERING1               = 47580,
            PAINANDSUFFERING2               = 47581,
            PAINANDSUFFERING3               = 47582,
            SHADOW_WEAVING1                 = 15257,
            SHADOW_WEAVING2                 = 15331,
            SHADOW_WEAVING3                 = 15332,
            DIVINE_AEGIS                    = 47515,//rank 3
            BORROWED_TIME                   = 52800,//rank 5
            GRACE                           = 47517,//rank 2
            EMPOWERED_RENEW1                = 63534,
            EMPOWERED_RENEW2                = 63542,
            EMPOWERED_RENEW3                = 63543,
            INSPIRATION1                    = 14892,
            INSPIRATION2                    = 15362,
            INSPIRATION3                    = 15363,
            BODY_AND_SOUL1                  = 64127,
            RENEWED_HOPE                    = 57472,//rank 3
            ENLIGHTENMENT                   = 34910,//rank 3
            RAPTURE                         = 47537,//rank 3
        //Glyphs
            GLYPH_SW_PAIN                   = 55681,
            GLYPH_PW_SHIELD                 = 55672,
        //other
            PRIEST_T10_2P_BONUS             = 70770 //33% renew
        };
        enum PriestSpecial
        {
            IMPROVED_DEVOURING_PLAGUE_DAMAGE= 63675,
            MIND_SEAR_DAMAGE                = 49821,
            SW_DEATH_BACKLASH               = 32409,
            WEAKENED_SOUL_DEBUFF            = 6788,
            DIVINE_HYMN_HEAL                = 64844
        };
    };
};

void AddSC_priest_bot()
{
    new priest_bot();
}
