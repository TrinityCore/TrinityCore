#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Item.h"
//#include "WorldSession.h"
/*
Warrior NpcBot (reworked by Graff onlysuffering@gmail.com)
Complete - 94-97%
*/
class warrior_bot : public CreatureScript
{
public:
    warrior_bot() : CreatureScript("warrior_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new warrior_botAI(creature);
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

    struct warrior_botAI : public bot_minion_ai
    {
        warrior_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_WARRIOR;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_WARRIOR) != SPELL_CAST_OK)
                return false;

            if (spellId == BATTLESTANCE_1 || spellId == DEFENSIVESTANCE_1 || spellId == BERSERKERSTANCE_1)
                temptimer = GC_Timer;

            return bot_ai::doCast(victim, spellId, triggered);
        }

        uint8 GetBotStance() const
        {
            if (battleStance)
                return WARRIOR_BATTLE_STANCE;
            else if (defensiveStance)
                return WARRIOR_DEFENSIVE_STANCE;
            else if (berserkerStance)
                return WARRIOR_BERSERKER_STANCE;

            return BOT_STANCE_NONE;
        }

        void UpdateAI(uint32 diff)
        {
            ReduceCD(diff);
            if (!GlobalUpdate(diff))
                return;
            CheckAttackState();
            getrage();
            if (ragetimer2 <= diff)
            {
                if (me->IsInCombat() && me->getLevel() >= 20)
                {
                    if (me->GetPower(POWER_RAGE) < 990)
                        me->SetPower(POWER_RAGE, me->GetPower(POWER_RAGE) + uint32(10.f * rageIncomeMult)); //1 rage per 2 sec
                    else
                        me->SetPower(POWER_RAGE, 1000); //max
                }
                ragetimer2 = 2000;
            }
            if (ragetimer <= diff)
            {
                if (!me->IsInCombat() && !HasAuraName(me, BLOODRAGE_1))
                {
                    if (me->GetPower(POWER_RAGE) > uint32(10.f * rageLossMult))
                        me->SetPower(POWER_RAGE, me->GetPower(POWER_RAGE) - uint32(10.f * rageLossMult)); //-1 rage per 1.5 sec
                    else
                        me->SetPower(POWER_RAGE, 0); //min
                }
                ragetimer = 1500;
            }
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
            CheckShouts(diff);
            CheckVigilance(diff);
            CheckIntervene(diff);
            CheckSpellReflect(diff);
            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (!CheckAttackTarget(BOT_CLASS_WARRIOR))
            {
                if (!IsTank() && !me->IsInCombat() && battleStance != true && master->getAttackers().empty() &&
                    stancetimer <= diff && Rand() < 25)
                    stanceChange(diff, 1);
                return;
            }

            if (IsSpellReady(BLOODRAGE_1, diff, false) && me->IsInCombat() && rage < 600 &&
                Rand() < 20 && !me->HasAura(ENRAGED_REGENERATION_1))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(BLOODRAGE_1)))
                {
                    GC_Timer = temptimer;
                    getrage();
                }
            }

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
        void KilledUnit(Unit* u)
        {
            //Victorious State spell
            //only on targets which give xp or honor
            if (me->getLevel() >= 5 && u->getLevel() + 9 >= me->getLevel())
                me->CastSpell(me, VICTORIOUS_SPELL, true);
        }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }
        void DoNonCombatActions(uint32 /*diff*/) { }

        void modrage(int32 mod, bool set = false)
        {
            if (set && mod < 0)
                return;
            if (mod < 0 && rage < abs(mod))
            {
                //debug set rage to 0
                mod = 0;
                set = true;
                return;
            }

            if (set)
                rage = mod ? mod*10 : 0;
            else
                rage += mod*10;

            me->SetPower(POWER_RAGE, rage);
        }

        int32 getrage()
        {
            rage = me->GetPower(POWER_RAGE);
            if (me->FindCurrentSpellBySpellId(GetSpell(CLEAVE_1)))
                rage = std::max<int32>(rage - 200, 0);
            else if (me->FindCurrentSpellBySpellId(GetSpell(HEROIC_STRIKE_1)))
                rage = std::max<int32>(rage - 150, 0);

            return rage;
        }

        int32 rcost(uint32 spellId) const
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                return spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
            return 0;
        }

        void BreakCC(uint32 diff)
        {
            if (me->HasAuraWithMechanic((1<<MECHANIC_FEAR)|(1<<MECHANIC_SAPPED)|(1<<MECHANIC_DISORIENTED)))
            {
                if (IsSpellReady(BERSERKERRAGE_1, diff) && Rand() < 35 && !me->HasAura(ENRAGED_REGENERATION_1) &&
                    doCast(me, GetSpell(BERSERKERRAGE_1)))
                    return;
            }
            bot_minion_ai::BreakCC(diff);
        }

        void Attack(uint32 diff)
        {
            opponent = me->GetVictim();
            if (opponent)
            {
                if (!IsCasting())
                    StartAttack(opponent, true);
            }
            else
                return;
            //Keep defensive stance if tank
            if (IsTank() && defensiveStance != true && stancetimer <= diff)
                stanceChange(diff, 2);
            //SelfHeal
            if (IsSpellReady(ENRAGED_REGENERATION_1, diff) && rage > rcost(ENRAGED_REGENERATION_1) &&
                GetHealthPCT(me) < 40 && Rand() < 40 && me->HasAuraWithMechanic(uint32(1<<MECHANIC_ENRAGED)))
            {
                if (doCast(me, GetSpell(ENRAGED_REGENERATION_1)))
                    return;
            }

            AttackerSet m_attackers = master->getAttackers();
            AttackerSet b_attackers = me->getAttackers();
            float dist = me->GetExactDist(opponent);
            float meleedist = me->GetDistance(opponent);
            //charge + warbringer
            if (IsSpellReady(CHARGE_1, diff, false) && dist > 11 && dist < 25 && me->HasInArc(M_PI, opponent) &&
                (me->getLevel() >= 50 ||
                (!me->IsInCombat() && (battleStance || stanceChange(diff, 1)))))
            {
                temptimer = GC_Timer;
                if (me->getLevel() >= 29)
                    me->RemoveMovementImpairingAuras(true);
                if (doCast(opponent, GetSpell(CHARGE_1), me->IsInCombat()))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //intercept
            if (IsSpellReady(INTERCEPT_1, diff, false) && !IsTank() &&
                rage > rcost(INTERCEPT_1) && dist > 11 && dist < 25 && me->HasInArc(M_PI, opponent) &&
                !CCed(opponent) && (berserkerStance || stanceChange(diff, 3)))
            {
                if (doCast(opponent, GetSpell(INTERCEPT_1)))
                    return;
            }
            //SelfHeal 2 - LAST STAND
            if (IsSpellReady(LAST_STAND_1, diff, false) && IsTank() && Rand() < 67 &&
                GetHealthPCT(me) < (30 + 20 * (b_attackers.size() > 1) + 10 * me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(LAST_STAND_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //FEAR
            if (IsSpellReady(INTIMIDATING_SHOUT_1, diff) && Rand() < 70 && rage > rcost(INTIMIDATING_SHOUT_1))
            {
                if (opponent->IsNonMeleeSpellCast(false, false, true) && dist <= 8 &&
                    !(opponent->ToCreature() && opponent->ToCreature()->GetCreatureType() == CREATURE_TYPE_UNDEAD))
                {
                    if (doCast(opponent, GetSpell(INTIMIDATING_SHOUT_1)))
                        return;
                }
                Unit* fearTarget = NULL;
                bool triggered = false;
                uint8 tCount = 0;
                //fear master's attackers
                if (!m_attackers.empty() &&
                    ((master->getClass() != BOT_CLASS_DEATH_KNIGHT &&
                    master->getClass() != BOT_CLASS_WARRIOR &&
                    master->getClass() != BOT_CLASS_PALADIN) ||
                    GetHealthPCT(master) < 70))
                {
                    for(AttackerSet::iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetExactDist((*iter)) <= 8 && (*iter)->isTargetableForAttack())
                        {
                            ++tCount;
                            fearTarget = (*iter);
                            if (tCount > 1) break;
                        }
                    }
                    if (tCount > 0 && !fearTarget)
                    {
                        fearTarget = opponent;
                        triggered = true;
                    }
                    if (tCount > 1 && doCast(fearTarget, GetSpell(INTIMIDATING_SHOUT_1), triggered))
                        return;
                }
                //Defend myself
                if (b_attackers.size() > 1)
                {
                    tCount = 0;
                    fearTarget = NULL;
                    triggered = false;
                    for(AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if ((*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetExactDist((*iter)) <= 8 && (*iter)->isTargetableForAttack())
                        {
                            ++tCount;
                            fearTarget = (*iter);
                            if (tCount > 1) break;
                        }
                    }
                    if (tCount > 0 && !fearTarget)
                    {
                        fearTarget = opponent;
                        triggered = true;
                    }
                    if (tCount > 1 && doCast(fearTarget, GetSpell(INTIMIDATING_SHOUT_1), triggered))
                        return;
                }
            }//end FEAR
            //TAUNT //No GCD
            Unit* u = opponent->GetVictim();
            if (IsSpellReady(TAUNT_1, diff, false) && u && u != me && !IsTank(u) && dist <= 30 &&
                !CCed(opponent) && (!IsTankingClass(u->getClass()) || IsTank()) && IsInBotParty(u) &&
                (defensiveStance || (stancetimer <= diff && stanceChange(diff, 2))))
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(TAUNT_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //CHALLENGING SHOUT
            if (IsSpellReady(CHALLENGING_SHOUT_1, diff))
            {
                u = opponent->GetVictim();
                if (u && u != me && !IsTank(u) && !CCed(opponent) && dist <= 10 && rage > rcost(CHALLENGING_SHOUT_1) &&
                    Rand() < 30 && (!IsTankingClass(u->getClass()) || IsTank()) && IsInBotParty(u))
                {
                    if (doCast(me, GetSpell(CHALLENGING_SHOUT_1)))
                        return;
                }
                if (IsTank() && rage > rcost(CHALLENGING_SHOUT_1) && Rand() < 20)
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets);
                    if (int8(targets.size()) - int8(b_attackers.size()) >= 1)
                        if (doCast(me, GetSpell(CHALLENGING_SHOUT_1)))
                            return;
                }
            }
            u = opponent->GetVictim();
            //MOCKING BLOW
            if (IsSpellReady(MOCKING_BLOW_1, diff) && HasRole(BOT_ROLE_DPS) && u && u != me && !IsTank(u) &&
                meleedist <= 5 && rage > rcost(MOCKING_BLOW_1) &&
                !CCed(opponent) && Rand() < 70 && (!IsTankingClass(u->getClass()) || IsTank()) && IsInBotParty(u) &&
                (battleStance || defensiveStance || (stancetimer <= diff && stanceChange(diff, 4))))
            {
                if (doCast(opponent, GetSpell(MOCKING_BLOW_1)))
                    return;
            }
            //SHIELD SLAM
            if (IsSpellReady(SHIELD_SLAM_1, diff) && HasRole(BOT_ROLE_DPS) &&
                (battleStance || defensiveStance || stancetimer <= diff) &&
                meleedist <= 5 && rage > rcost(SHIELD_SLAM_1) && CanBlock() &&
                Rand() < (55 + 200*me->HasAura(SWORD_AND_BOARD_BUFF)))
            {
                //check Shield Block
                if (IsSpellReady(SHIELD_BLOCK_1, diff, false) && (defensiveStance || stanceChange(diff, 2)))
                {
                    temptimer = GC_Timer;

                    if (!doCast(me, GetSpell(SHIELD_BLOCK_1)))
                        return;

                    GC_Timer = temptimer;
                }
                if (battleStance || defensiveStance || stanceChange(diff, 4))
                {
                    if (doCast(opponent, GetSpell(SHIELD_SLAM_1)))
                        return;
                }
            }
            //SHIELD BLOCK
            if (IsSpellReady(SHIELD_BLOCK_1, diff, false) && CanBlock() && IsTank() &&
                ((u == me && meleedist <= 8) || (!b_attackers.empty() && me->GetDistance2d(*(b_attackers.begin())) <= 8)) &&
                GetHealthPCT(me) < (65 + 8 * uint8(b_attackers.size())) && Rand() < 50 &&
                (defensiveStance || stancetimer <= diff))
            {
                temptimer = GC_Timer;
                if ((defensiveStance || stanceChange(diff, 2)) &&
                    doCast(me, GetSpell(SHIELD_BLOCK_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //HEROIC THROW
            if (IsSpellReady(HEROIC_THROW_1, diff) && HasRole(BOT_ROLE_DPS) && dist <= 30 &&
                Rand() < (20 + 70 * opponent->IsNonMeleeSpellCast(false)))
            {
                if (doCast(opponent, GetSpell(HEROIC_THROW_1)))
                    return;
            }
            //SHOCKWAVE - frontal cone
            if (IsSpellReady(SHOCKWAVE_1, diff) && HasRole(BOT_ROLE_DPS) && CanBlock() && dist <= 10 && !CCed(opponent) &&
                rage > rcost(SHOCKWAVE_1) && Rand() < (30 + 50 * opponent->IsNonMeleeSpellCast(true)) &&
                me->HasInArc(M_PI / 2.f, opponent) && opponent->IsWithinLOSInMap(me))
            {
                if (doCast(me, GetSpell(SHOCKWAVE_1)))
                    return;
            }
            //OVERPOWER
            if (IsSpellReady(OVERPOWER_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                meleedist <= 5 && rage > rcost(OVERPOWER_1) &&
                (battleStance || stancetimer <= diff) &&/* Rand() < 80 &&*/
                (me->HasReactive(REACTIVE_OVERPOWER) ||
                (IsSpellReady(TASTE_FOR_BLOOD_BUFF, diff, false) && me->HasAura(TASTE_FOR_BLOOD_BUFF))))
            {
                if (battleStance || stanceChange(diff, 1))
                {
                    //custom
                    me->CastSpell(opponent, GetSpell(OVERPOWER_1));
                    return;
                }
            }
            //THUNDER CLAP
            if (IsSpellReady(THUNDER_CLAP_1, diff) && HasRole(BOT_ROLE_DPS) &&
                dist <= 8 && rage > rcost(THUNDER_CLAP_1) && Rand() < 20 &&
                (battleStance || defensiveStance || stancetimer <= diff) &&
                (IsTank() || !HasAuraName(opponent, THUNDER_CLAP_1)))
            {
                if (battleStance || defensiveStance || stanceChange(diff, 4))
                {
                    if (doCast(me, GetSpell(THUNDER_CLAP_1)))
                        return;
                }
            }
            //DEVASTATE - only with shield
            if (IsSpellReady(DEVASTATE_1, diff) && HasRole(BOT_ROLE_DPS)/* && IsTank()*/ && CanBlock() &&
                meleedist <= 5 && rage > rcost(DEVASTATE_1) && Rand() < 70)
            {
                if (doCast(opponent, GetSpell(DEVASTATE_1)))
                    return;
            }
            //REVENGE
            if (IsSpellReady(REVENGE_1, diff) && me->HasAuraState(AURA_STATE_DEFENSE) && HasRole(BOT_ROLE_DPS) && IsTank() &&
                meleedist <= 5 && rage > rcost(REVENGE_1) && Rand() < 30 &&
                (defensiveStance || stancetimer <= diff))
            {
                if (defensiveStance || stanceChange(diff, 2))
                {
                    if (doCast(opponent, GetSpell(REVENGE_1)))
                    {
                        //Improved Revenge (part 2): find second target
                        if (me->getLevel() >= 25)
                            if (Unit* u = FindSplashTarget(5, opponent))
                                me->CastSpell(u, GetSpell(REVENGE_1), true);
                        return;
                    }
                }
            }

            if (MoveBehind(*opponent))
                wait = 15;

            //CONCUSSION_BLOW
            if (IsSpellReady(CONCUSSION_BLOW_1, diff) && HasRole(BOT_ROLE_DPS) && IsTank() &&
                meleedist <= 5 && rage > rcost(CONCUSSION_BLOW_1) && !CCed(opponent) &&
                Rand() < (30 + 60 * opponent->IsNonMeleeSpellCast(false)))
            {
                if (doCast(opponent, GetSpell(CONCUSSION_BLOW_1)))
                    return;
            }
            //HAMSTRING
            if (IsSpellReady(HAMSTRING_1, diff) && (!GetSpell(PIERCING_HOWL_1) || opponent->GetTypeId() == TYPEID_PLAYER) &&
                opponent->isMoving() && meleedist <= 5 && rage > rcost(HAMSTRING_1) &&
                Rand() < 50 && (battleStance || berserkerStance || stancetimer <= diff) &&
                !opponent->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
            {
                if (battleStance || berserkerStance || stanceChange(diff, 5))
                    if (doCast(opponent, GetSpell(HAMSTRING_1)))
                        return;
            }
            //PIERCING HOWL
            if (IsSpellReady(PIERCING_HOWL_1, diff) && opponent->isMoving() && meleedist <= 9 && rage > rcost(PIERCING_HOWL_1) &&
                Rand() < 70 && !opponent->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_ROOT)))
            {
                if (doCast(me, GetSpell(PIERCING_HOWL_1)))
                    return;
            }
            //DISARM
            if (IsSpellReady(DISARM_1, diff) && meleedist <= 5 && rage > rcost(DISARM_1) &&
                opponent->GetHealth() > me->GetMaxHealth() / 4 &&
                !opponent->HasAuraType(SPELL_AURA_MOD_DISARM) && Rand() < 50 &&
                (defensiveStance || stancetimer <= diff))
            {
                //check weapons
                bool hasWeapon = true;
                if (opponent->GetTypeId() == TYPEID_UNIT && !opponent->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID))
                    hasWeapon = false;
                else if (Player* pla = opponent->ToPlayer())
                    if (!pla->GetWeaponForAttack(BASE_ATTACK) || !pla->IsUseEquipedWeapon(true))
                        hasWeapon = false;

                if (hasWeapon && (defensiveStance || stanceChange(diff, 2)) &&
                    doCast(opponent, GetSpell(DISARM_1)))
                    return;
            }
            //Victory Rush
            if (IsSpellReady(VICTORY_RUSH_1, diff) && VICTORIOUS && HasRole(BOT_ROLE_DPS) && !IsTank() && meleedist <= 5/* &&
                (b_attackers.size() <= 1 || (GetHealthPCT(me) < std::max<int32>(100 - b_attackers.size() * 10, 75)))*/ &&
                (battleStance || berserkerStance || stancetimer <= diff))
            {
                if (battleStance || berserkerStance || stanceChange(diff, 5))
                    if (doCast(opponent, GetSpell(VICTORY_RUSH_1)))
                        return;
            }
            //UBERS
            //Shield Wall
            if (IsSpellReady(SHIELD_WALL_1, diff, false) && CanBlock() &&
                GetHealthPCT(me) < (30 + 4 * b_attackers.size() + 10 * (opponent->GetTypeId() == TYPEID_UNIT && opponent->ToCreature()->isWorldBoss())) &&
                Rand() < 70 &&
                (defensiveStance || stanceChange(diff, 2)))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(SHIELD_WALL_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //Retaliation
            if (IsSpellReady(RETALIATION_1, diff) && HasRole(BOT_ROLE_DPS) && b_attackers.size() > 4 && Rand() < 30 &&
                (battleStance || stanceChange(diff, 1)))
            {
                if (doCast(me, GetSpell(RETALIATION_1)))
                    return;
            }
            //Recklessness
            if (IsSpellReady(RECKLESSNESS_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                b_attackers.size() < 2 && opponent->GetHealth() > (me->GetMaxHealth() * 3) && Rand() < 20 &&
                (berserkerStance || stanceChange(diff, 3)))
            {
                if (doCast(me, GetSpell(RECKLESSNESS_1)))
                    return;
            }
            //DEATHWISH
            if (IsSpellReady(DEATHWISH_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() && dist <= 20 && rage > rcost(DEATHWISH_1) &&
                opponent->GetHealth() > me->GetHealth()/2 && Rand() < 20 &&
                !me->HasAura(ENRAGED_REGENERATION_1))
            {
                if (doCast(me, GetSpell(DEATHWISH_1)))
                    return;
            }
            //EXECUTE
            if (IsSpellReady(EXECUTE_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                meleedist <= 5 && rage > rcost(EXECUTE_1) &&
                opponent->HasAuraState(AURA_STATE_HEALTHLESS_20_PERCENT) && Rand() < 70 &&
                (battleStance || berserkerStance || (stancetimer <= diff && stanceChange(diff, 5))))
            {
                if (doCast(opponent, GetSpell(EXECUTE_1)))
                {
                    //sudden death
                    if (me->getLevel() >= 50 && rage <= 400)
                        modrage(10, true);
                    else if (rage > 300)
                        modrage(-30);
                    else
                        modrage(0, true);
                    return;
                }
            }
            //SUNDER ARMOR
            if (IsSpellReady(SUNDER_1, diff) && !GetSpell(DEVASTATE_1) && IsTank() &&
                meleedist <= 5 && rage > rcost(SUNDER_1) &&
                opponent->GetHealth() > me->GetMaxHealth() && Rand() < 45)
            {
                Aura* sunder = opponent->GetAura(GetSpell(SUNDER_1), me->GetGUID());
                if ((!sunder || sunder->GetStackAmount() < 5 || sunder->GetDuration() < 15000) &&
                    doCast(opponent, GetSpell(SUNDER_1)))
                    return;
            }
            //SS //no GCD
            if (IsSpellReady(SWEEPING_STRIKES_1, diff, false) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                dist <= 20 && rage > rcost(SWEEPING_STRIKES_1) &&
                (battleStance || berserkerStance || stancetimer <= diff) && Rand() < 25 &&
                (b_attackers.size() > 1 || FindSplashTarget(7, opponent)))
            {
                temptimer = GC_Timer;
                if ((battleStance || berserkerStance || stanceChange(diff, 5)) &&
                    doCast(me, GetSpell(SWEEPING_STRIKES_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //WHIRLWIND
            if (IsSpellReady(WHIRLWIND_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                (berserkerStance || stancetimer <= diff) &&
                dist <= 10 && rage > rcost(WHIRLWIND_1) && Rand() < 50 &&
               ((rage > 800 && dist <= 7) || FindSplashTarget(7, opponent)))
            {
                if ((berserkerStance || stanceChange(diff, 3)) &&
                    doCast(me, GetSpell(WHIRLWIND_1)))
                    return;
            }
            //BLADESTORM
            if (IsSpellReady(BLADESTORM_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
               dist <= 10 && rage > rcost(BLADESTORM_1) &&
               (b_attackers.size() > 1 || opponent->GetHealth() > me->GetMaxHealth()) &&
               (Rand() < 20 || me->HasAura(RECKLESSNESS_1)))
            {
                if (doCast(me, GetSpell(BLADESTORM_1)))
                    return;
            }
            //Mortal Strike
            if (IsSpellReady(MORTALSTRIKE_1, diff) && HasRole(BOT_ROLE_DPS) &&
                meleedist <= 5 && rage > rcost(MORTALSTRIKE_1) && Rand() < 50)
            {
                if (doCast(opponent, GetSpell(MORTALSTRIKE_1)))
                    return;
            }
            //Slam
            if (IsSpellReady(SLAM_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() && !opponent->isMoving() &&
                meleedist <= 5 && rage > rcost(SLAM_1) && Rand() < (20 + 80 * me->HasAura(BLOODSURGE_BUFF)))
            {
                if (doCast(opponent, GetSpell(SLAM_1)))
                    return;
            }
            //SHIELD BASH - shared cd with pummel
            if (IsSpellReady(SHIELD_BASH_1, diff, false) && CanBlock() &&
                meleedist <= 5 && rage > rcost(SHIELD_BASH_1) && Rand() < 80 &&
                opponent->IsNonMeleeSpellCast(false) &&
                (battleStance || defensiveStance || stancetimer <= diff))
            {
                temptimer = GC_Timer;
                if ((battleStance || defensiveStance || stanceChange(diff, 4)) &&
                    doCast(opponent, GetSpell(SHIELD_BASH_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //PUMMEL - shared cd with shield bash
            if (IsSpellReady(PUMMEL_1, diff, false) && !IsTank() &&
                meleedist <= 5 && rage > rcost(PUMMEL_1) && Rand() < 80 &&
                opponent->IsNonMeleeSpellCast(false) &&
                (berserkerStance || stancetimer <= diff))
            {
                temptimer = GC_Timer;
                if ((berserkerStance || stanceChange(diff, 3)) &&
                    doCast(opponent, GetSpell(PUMMEL_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //REND
            if (IsSpellReady(REND_1, diff) && HasRole(BOT_ROLE_DPS) && !IsTank() &&
                opponent->GetHealth() > me->GetMaxHealth()/2 && meleedist <= 5 && rage > rcost(REND_1) &&
                Rand() < 50 && !opponent->HasAura(GetSpell(REND_1), me->GetGUID()) &&
                (battleStance || defensiveStance || (stancetimer <= diff && stanceChange(diff, 4))))
            {
                if (doCast(opponent, GetSpell(REND_1)))
                    return;
            }

            //skip if already have cleave of heroic strike casted
            if (me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                return;

            //CLEAVE //no GCD
            if (IsSpellReady(CLEAVE_1, diff, false) && HasRole(BOT_ROLE_DPS) &&
                meleedist <= 5 && (!IsTank() || rage > 500) && rage > rcost(CLEAVE_1) && Rand() < 25)
            {
                temptimer = GC_Timer;
                u = FindSplashTarget(5);
                if (u && doCast(opponent, GetSpell(CLEAVE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //HEROIC STRIKE
            if (IsSpellReady(HEROIC_STRIKE_1, diff, false) && HasRole(BOT_ROLE_DPS) && IsTank() &&
                meleedist <= 5 && rage > rcost(HEROIC_STRIKE_1) && Rand() < (15 + rage / 10))
            {
                temptimer = GC_Timer;
                if (u && doCast(opponent, GetSpell(HEROIC_STRIKE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
        }//end Attack

        void CheckShouts(uint32 diff)
        {
            if (shoutCheckTimer > diff || GC_Timer > diff || me->IsMounted() || IsCasting() ||
                /*rage < rcost(BATTLESHOUT_1) || */Rand() > 35)
                return;

            shoutCheckTimer = 3000;

            if (IAmFree())
            {
                if (!HasAuraName(me, BATTLESHOUT_1, me->GetGUID()))
                {
                    if (rage < rcost(BATTLESHOUT_1) && IsSpellReady(BLOODRAGE_1, diff, false))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(BLOODRAGE_1)))
                        {
                            GC_Timer = temptimer;
                            if (doCast(me, GetSpell(BATTLESHOUT_1)))
                                return;
                        }
                    }
                }

                return;
            }

            bool hasBS = HasAuraName(me, BATTLESHOUT_1/*, me->GetGUID()*/);
            bool hasCS = HasAuraName(me, COMMANDING_SHOUT_1/*, me->GetGUID()*/);
            if (hasCS || hasBS)
                return;

            if (me->GetDistance2d(master) < 30/* && master->IsWithinLOSInMap(me)*/)
            {
                bool battleshout = !hasBS && (!IsTank(me) || !GetSpell(COMMANDING_SHOUT_1));
                bool commandingshout = !hasCS && GetSpell(COMMANDING_SHOUT_1);

                if (battleshout || commandingshout)
                {
                    if (rage < rcost(BATTLESHOUT_1) && IsSpellReady(BLOODRAGE_1, diff, false))
                    {
                        temptimer = GC_Timer;
                        if (doCast(me, GetSpell(BLOODRAGE_1)))
                            GC_Timer = temptimer;
                    }

                    if ((battleshout && doCast(me, GetSpell(BATTLESHOUT_1))) ||
                        (commandingshout && doCast(me, GetSpell(COMMANDING_SHOUT_1))))
                    {
                        shoutCheckTimer = 10000;
                        return;
                    }
                }
            }
        }

        void CheckVigilance(uint32 diff)
        {
            if (!IsSpellReady(VIGILANCE_1, diff) || me->IsInCombat() || me->IsMounted() || IsCasting() || Rand() > 50)
                return;

            uint32 VIGILANCE = GetSpell(VIGILANCE_1);

            Unit* u = ObjectAccessor::FindConnectedPlayer(ObjectGuid(vigilanceTargetGuid));

            if (u)
            {
                if (!IsTank())
                {
                    u->RemoveAura(VIGILANCE, me->GetGUID(), 0, AURA_REMOVE_BY_EXPIRE);
                    vigilanceTargetGuid = 0;
                }
                if (IAmFree())
                    return;
            }
            else if (IsTank())
            {
                Group* pGroup = master->GetGroup();
                if (!pGroup)
                {
                    if (me->GetExactDist(master) < 30 && !master->HasAura(VIGILANCE))
                        u = master;
                }
                else
                {
                    for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* pPlayer = itr->GetSource();
                        if (!pPlayer || !pPlayer->IsInWorld() || pPlayer->isDead()) continue;
                        if (me->GetMapId() != pPlayer->GetMapId()) continue;
                        if (!IsTankingClass(pPlayer->getClass()) && me->GetExactDist(pPlayer) < 30 &&
                            !pPlayer->HasAura(VIGILANCE))
                        {
                            u = pPlayer;
                            break;
                        }
                    }
                    if (!u)
                    {
                        for (GroupReference* itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                        {
                            Player* pPlayer = itr->GetSource();
                            if (!pPlayer || !pPlayer->IsInWorld() || !pPlayer->HaveBot()) continue;
                            if (me->GetMapId() != pPlayer->GetMapId()) continue;
                            BotMap const* map = pPlayer->GetBotMgr()->GetBotMap();
                            for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                            {
                                Creature* cre = it->second;
                                if (!cre || !cre->IsInWorld() || cre == me || cre->isDead()) continue;
                                if (!IsTankingClass(cre->GetBotClass()) && me->GetExactDist(cre) < 30 &&
                                    !cre->HasAura(VIGILANCE))
                                {
                                    u = cre;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (u && doCast(u, VIGILANCE))
                {
                    vigilanceTargetGuid = u->GetGUID();
                    return;
                }
            }

            SetSpellCooldown(VIGILANCE_1, 10000); //fail
        }

        void CheckIntervene(uint32 diff)
        {
            if (IsSpellReady(INTERVENE_1, diff, false) && GetBotCommandState() != COMMAND_STAY &&
                !me->IsMounted() && rage > rcost(INTERVENE_1) &&
                !IAmFree() && !IsCasting() && Rand() < (IsTank() ? 80 : 30) &&
                (defensiveStance || stancetimer <= diff))
            {
                if (!master->IsInCombat() && master->getAttackers().empty() && master->isMoving())
                {
                    float mydist = me->GetExactDist(master);
                    if (mydist < 24 && mydist > 19 && (defensiveStance || stanceChange(diff, 2)))
                    {
                        temptimer = GC_Timer;
                        if (doCast(master, GetSpell(INTERVENE_1)))
                        {
                            GC_Timer = temptimer;
                            Follow(true);
                            return;
                        }
                    }
                }
                Group* gr = master->GetGroup();
                if (!gr)
                {
                    if (GetHealthPCT(master) < 95 && !master->getAttackers().empty() &&
                        me->getAttackers().size() <= master->getAttackers().size())
                    {
                        float dist = me->GetExactDist(master);
                        if (dist > 25 || dist < 10) return;
                        if (!(defensiveStance || stanceChange(diff, 2))) return;
                        temptimer = GC_Timer;
                        if (doCast(master, GetSpell(INTERVENE_1)))
                        {
                            GC_Timer = temptimer;
                            return;
                        }
                    }
                }
                else
                {
                    bool Bots = false;
                    float dist;
                    for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* tPlayer = itr->GetSource();
                        if (!tPlayer) continue;
                        if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
                        if (tPlayer->FindMap() != me->GetMap()) continue;
                        if (tPlayer->HaveBot())
                            Bots = true;
                        if (tPlayer->isDead() || GetHealthPCT(tPlayer) > 90 || IsTank(tPlayer)) continue;
                        if (tPlayer->getAttackers().size() < me->getAttackers().size()) continue;
                        dist = me->GetExactDist(tPlayer);
                        if (dist > 24 || dist < 10) continue;
                        if (defensiveStance || stanceChange(diff, 2))
                        {
                            temptimer = GC_Timer;
                            if (doCast(tPlayer, GetSpell(INTERVENE_1)))
                            {
                                GC_Timer = temptimer;
                                return;
                            }
                        }
                    }
                    if (!Bots) return;
                    for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* tPlayer = itr->GetSource();
                        if (!tPlayer || !tPlayer->HaveBot()) continue;
                        if (!tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
                        if (tPlayer->FindMap() != me->GetMap()) continue;
                        BotMap const* map = tPlayer->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                        {
                            Creature* bot = it->second;
                            if (!bot || !bot->IsInWorld() || bot == me || bot->isDead()) continue;
                            if (GetHealthPCT(bot) > 90 || IsTank(bot)) continue;
                            dist = me->GetExactDist(bot);
                            if (dist > 25 || dist < 10) continue;
                            if (bot->getAttackers().size() <= me->getAttackers().size()) continue;
                            if (defensiveStance || stanceChange(diff, 2))
                            {
                                temptimer = GC_Timer;
                                if (doCast(bot, GetSpell(INTERVENE_1)))
                                {
                                    GC_Timer = temptimer;
                                    return;
                                }
                            }
                        }
                    }
                }

                SetSpellCooldown(INTERVENE_1, 2000); //fail
            }
        }

        void CheckSpellReflect(uint32 diff)
        {
            if (!IsSpellReady(SPELL_REFLECTION_1, diff, false) || me->IsMounted() || IsCasting() ||
                !CanBlock() || !(battleStance || defensiveStance || stancetimer <= diff) ||
                rage < rcost(SPELL_REFLECTION_1) || Rand() > 35)
                return;

            //use simpliest finder - first match (covers most cases)
            if (Unit* target = FindCastingTarget(70))
            {
                temptimer = GC_Timer;
                for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
                    if (Spell* spell = target->GetCurrentSpell(CurrentSpellTypes(i)))
                        if (!spell->GetSpellInfo()->IsChanneled())
                            if (spell->GetSpellInfo()->DmgClass == SPELL_DAMAGE_CLASS_MAGIC &&
                                !(spell->GetSpellInfo()->Attributes & SPELL_ATTR0_ABILITY) &&
                                !(spell->GetSpellInfo()->AttributesEx & SPELL_ATTR1_CANT_BE_REFLECTED) &&
                                !(spell->GetSpellInfo()->Attributes & SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY) &&
                                !spell->GetSpellInfo()->IsPassive() && !spell->GetSpellInfo()->IsPositive())
                                if (Unit* u = spell->m_targets.GetUnitTarget())
                                    if (u == me || (me->GetDistance(u) < 20 && !IAmFree() && IsInBotParty(u)))
                                        if (doCast(me, GetSpell(SPELL_REFLECTION_1)))
                                        {
                                            GC_Timer = temptimer;
                                            return;
                                        }
            }

            SetSpellCooldown(SPELL_REFLECTION_1, 1000); //fail
        }

        bool stanceChange(uint32 diff, uint8 stance)
        {
            if (stancetimer > diff || !stance)
                return false;

            if (stance == 5)
                stance = (me->getLevel() >= 30 && !IsTank() && urand(1,100) > 70) ? 3 : 1;
            else if (stance == 4)
                stance = (me->getLevel() >= 10 && (IsTank() || urand(1,100) > 50)) ? 2 : 1;

            if (stance == 2 && me->getLevel() < 10)
                return false;
            if (stance == 3 && me->getLevel() < 30)
                return false;

            switch (stance)
            {
                case 1:
                    if (doCast(me, GetSpell(BATTLESTANCE_1)))
                    {
                        if (me->HasAura(BATTLESTANCE_1))
                        {
                            GC_Timer = temptimer;
                            return true;
                        }
                    }
                    break;
                case 2:
                    if (doCast(me, GetSpell(DEFENSIVESTANCE_1)))
                    {
                        if (me->HasAura(DEFENSIVESTANCE_1))
                        {
                            GC_Timer = temptimer;
                            return true;
                        }
                    }
                    break;
                case 3:
                    if (doCast(me, GetSpell(BERSERKERSTANCE_1)))
                    {
                        if (me->HasAura(BERSERKERSTANCE_1))
                        {
                            GC_Timer = temptimer;
                            return true;
                        }
                    }
                    break;
                default:
                    break;
            }

            GC_Timer = temptimer;
            return false;
        }

        void ApplyClassDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const
        {
            uint8 lvl = me->getLevel();
            float pctbonus = 0.0f;

            if (damageinfo.hitOutCome == MELEE_HIT_CRIT)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Poleaxe Specialization: 5% additional critical damage for all attacks
                if (lvl >= 30)
                    if (Item const* weap = GetEquips(damageinfo.attackType))
                        if (ItemTemplate const* proto = weap->GetTemplate())
                            if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                                proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                                pctbonus += 0.025f;
            }

            damage = damage * (1.0f + pctbonus);
        }

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;
                //Poleaxe Specialization: 5% additional critical chance for all attacks
                if (lvl >= 30)
                    if (Item const* weap = GetEquips(attackType))
                        if (ItemTemplate const* proto = weap->GetTemplate())
                            if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                                proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                                aftercrit += 5.f;
                //Incite: 15% additional critical chance for Cleave, Heroic Strike and Thunder Clap
                if (lvl >= 15 &&
                    (spellId == GetSpell(CLEAVE_1) ||
                    spellId == GetSpell(HEROIC_STRIKE_1) ||
                    spellId == GetSpell(THUNDER_CLAP_1)))
                    aftercrit += 15.f;
                //Improved Overpower: 50% additional critical chance for Overpower
                if (lvl >= 20 && spellId == GetSpell(OVERPOWER_1))
                    aftercrit += 50.f;
                //Critical Block: 15% additional critical chance for Shield Slam
                if (lvl >= 50 && spellId == GetSpell(SHIELD_SLAM_1))
                    aftercrit += 15.f;
                //Sword and Board: 15% additional critical chance for Devastate
                if (lvl >= 55 && spellId == GetSpell(DEVASTATE_1))
                    aftercrit += 15.f;
                //Warrior T8 Protection Bonus (id: 64933): 10% additional critical chance for Devastate (tanks only)
                if (lvl >= 78 && IsTank() && spellId == GetSpell(DEVASTATE_1))
                    aftercrit += 10.f;
                //Recklessness: 100% additional critical chance for damaging abilities
                if (damage > 0 && me->HasAura(GetSpell(RECKLESSNESS_1)))
                    aftercrit += 100.f;

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Impale: 20% crit damage bonus for all abilities
                if (lvl >= 20)
                    pctbonus += 0.10f;
                //Poleaxe Specialization: 5% additional critical damage for all attacks
                if (lvl >= 30)
                    if (Item const* weap = GetEquips(attackType))
                        if (ItemTemplate const* proto = weap->GetTemplate())
                            if (proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE || proto->SubClass == ITEM_SUBCLASS_WEAPON_AXE2 ||
                                proto->SubClass == ITEM_SUBCLASS_WEAPON_POLEARM)
                                pctbonus += 0.025f;
            }

            //Improved Rend: 20% bonus damage for Rend
            if (spellId == GetSpell(REND_1))
                pctbonus += 0.2f;
            //Improved Whirlwind: 20% bonus damage for Whirlwind
            if (lvl >= 40 && spellId == GetSpell(WHIRLWIND_1))
                pctbonus += 0.2f;
            //Glyph of Mortal Strike: 10% bonus damage for Mortal Strike
            if (lvl >= 40 && spellId == GetSpell(MORTALSTRIKE_1))
                pctbonus += 0.1f;
            //Unrelenting Assault (part 2): 20% bonus damage for Overpower and Revenge
            if (lvl >= 45 && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
                pctbonus += 0.2f;
            //Improved Mortal Strike (part 1): 10% bonus damage for Mortal Strike
            if (lvl >= 45 && spellId == GetSpell(MORTALSTRIKE_1))
                pctbonus += 0.1f;
            //Undending Fury: 10% bonus damage for Whirlwind, Slam and Bloodthirst
            if (lvl >= 55 && (spellId == GetSpell(WHIRLWIND_1) || spellId == GetSpell(SLAM_1) /*|| spellId == BLOODTHIRST*/))
                pctbonus += 0.1f;
            //Improved Thunder Clap (part 2): 30% bonus damage for Thunder Clap
            if (lvl >= 15 && spellId == GetSpell(THUNDER_CLAP_1))
                pctbonus += 0.3f;
            ////Improved Revenge (part 1): 60% bonus damage for Revenge
            //if (lvl >= 20 && spellId == GetSpell(REVENGE_1))
            //    pctbonus += 0.6f;
            //Gag Order (part 2): 10% bonus damage for Shield Slam
            if (lvl >= 30 && spellId == GetSpell(SHIELD_SLAM_1))
                pctbonus += 0.1f;
            //Improved Shield Slam (id: 38407): 10% bonus damage for Shield Slam
            if (lvl >= 50 && spellId == GetSpell(SHIELD_SLAM_1))
                pctbonus += 0.1f;
            //Shield Slam Damage Up (id: 60173): 10% bonus damage for Shield Slam
            if (lvl >= 70 && spellId == GetSpell(SHIELD_SLAM_1))
                pctbonus += 0.1f;
            //Warrior T10 Protection 2P Bonus (id: 70843): 20% bonus damage for Shield Slam and Shockwave (tanks only)
            if (lvl >= 78 && IsTank() && (spellId == GetSpell(SHIELD_SLAM_1) || spellId == GetSpell(SHOCKWAVE_1)))
                pctbonus += 0.2f;
            //One-Handed Weapon Specialization: 10% bonus damage with 1H weapons (for bot - Devastate only)
            if (lvl >= 35 && spellId == GetSpell(DEVASTATE_1))
                pctbonus += 0.1f;
            //Warrior T9 Protection 2P Bonus (id: 67269): 5% bonus damage for Devastate
            if (lvl >= 77 && spellId == GetSpell(DEVASTATE_1))
                pctbonus += 0.05f;
            //Glyph of Mocking Blow: 25% bonus damage for Mocking Blow
            if (lvl >= 15 && spellId == GetSpell(MOCKING_BLOW_1))
                pctbonus += 0.25f;

            //Improved Cleave: 120% increased '!bonus damage!' done by Cleave (flat mod)
            if (lvl >= 25 && spellId == GetSpell(CLEAVE_1))
            {
                float bp = spellInfo->Effects[EFFECT_0].BasePoints; //SPELL_EFFECT_WEAPON_DAMAGE (values: 15 - 222)
                fdamage += bp * 1.2;
            }

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const
        {
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->getLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //percent mods
            //Glyph of Bloodrage: -100% health cost for Bloodrage
            if (lvl >= 10 && spellId == GetSpell(BLOODRAGE_1))
                pctbonus += 1.0f;
            //Sword and Board: -100% rage cost for Shield Slam
            if (lvl >= 55 && spellId == GetSpell(SHIELD_SLAM_1) && me->HasAura(SWORD_AND_BOARD_BUFF))
                pctbonus += 1.0f;
            //Glyph of Sweeping Strikes: -100% rage cost for Sweeping Strikes
            if (lvl >= 30 && spellId == GetSpell(SWEEPING_STRIKES_1))
                pctbonus += 1.0f;
            //Glyph of Revenge: -100% rage cost for Heroic Strike
            if (lvl >= 20 && spellId == GetSpell(HEROIC_STRIKE_1) && me->HasAura(GLYPH_OF_REVENGE_BUFF))
                pctbonus += 1.0f;

            //flat mods
            //!1 rage = 10 pts!
            //Improved Heroic Strike: -3 rage cost for Heroic Strike
            if (lvl >= 10 && spellId == GetSpell(HEROIC_STRIKE_1))
                flatbonus += 30;
            //Bloodthirst and Mortal Strike Discount (id: 37535): -5 rage cost for Bloodthirst and Mortal Strike
            if (lvl >= 40 && (/*spellId == GetSpell(BLOODTHIRST_1) || */spellId == GetSpell(MORTALSTRIKE_1)))
                flatbonus += 50;
            //Improved Execute: -5 rage cost for Execute
            if (lvl >= 25 && spellId == GetSpell(EXECUTE_1))
                flatbonus += 50;
            //Improved Thunder Clap (part 1): -4 rage cost for Execute
            if (lvl >= 15 && spellId == GetSpell(THUNDER_CLAP_1))
                flatbonus += 40;
            //Puncture: -3 rage cost for Sunder Armor and Devastate
            if (lvl >= 25 && (spellId == GetSpell(SUNDER_1) || spellId == GetSpell(DEVASTATE_1)))
                flatbonus += 30;
            //Glyph of Shockwave: -3 rage cost for Shockwave
            if (lvl >= 65 && spellId == GetSpell(SHOCKWAVE_1))
                flatbonus += 30;
            //Improved Hamstring (id: 24428): -2 rage cost for Hamstring (for bot Piercing Howl also)
            if (lvl >= 25 && (spellId == GetSpell(HAMSTRING_1) || spellId == GetSpell(PIERCING_HOWL_1)))
                flatbonus += 20;
            //Focused Rage: -3 rage cost for all offensive abilities (using rage)
            if (lvl >= 40 && spellInfo->PowerType == POWER_RAGE && !spellInfo->IsPositive())
                flatbonus += 30;
            //Glyph of Resonating Power: -5 rage cost for Thunder Clap
            if (lvl >= 15 && spellId == GetSpell(THUNDER_CLAP_1))
                flatbonus += 50;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const
        {
            //casttime is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->getLevel();
            int32 timebonus = 0;
            //float pctbonus = 0.0f;

            //100% mods
            //Improved Slam: -100% cast time for Slam
            if (lvl >= 40 && spellId == GetSpell(SLAM_1) && me->HasAura(BLOODSURGE_BUFF))
                timebonus += casttime;

            //flat mods
            //Improved Slam: -1.0 sec cast time for Slam
            if (lvl >= 40 && spellId == GetSpell(SLAM_1))
                timebonus += 1000;

            casttime = std::max<int32>(casttime - timebonus, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const
        {
            //cooldown is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->getLevel();
            uint32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Intensify Rage: -33% cooldown for Bloodrage, Berserker Rage, Recklessness and Death Wish
            if (lvl >= 40 &&
                (spellId == GetSpell(BLOODRAGE_1) || spellId == GetSpell(BERSERKERRAGE_1) ||
                spellId == GetSpell(RECKLESSNESS_1) || spellId == GetSpell(DEATHWISH_1)))
                pctbonus += 0.33f;
            //Glyph of Rapid Charge: -7% cooldown for Charge
            if (lvl >= 40 && spellId == GetSpell(CHARGE_1))
                pctbonus += 0.07f;

            //flat mods
            //Improved Disciplines: -60 sec cooldown for Shield Wall, Retaliation and Recklessness
            if (lvl >= 35 &&
                (spellId == GetSpell(SHIELD_WALL_1) ||
                spellId == GetSpell(RETALIATION_1) ||
                spellId == GetSpell(RECKLESSNESS_1)))
                timebonus += 60000;
            //Unrelenting Assault (part 1): -4 sec cooldown for Overpower and Revenge (not for tanks)
            if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
                timebonus += 4000;
            //Improved Intercept: -10 sec cooldown for Intercept
            if (lvl >= 30 && spellId == GetSpell(INTERCEPT_1))
                timebonus += 10000;
            //Shield Mastery (part 2): -20 sec cooldown for Shield Block
            if (lvl >= 20 && spellId == GetSpell(SHIELD_BLOCK_1))
                timebonus += 20000;
            //Improved Disarm (part 1): -20 sec cooldown for Disarm
            if (lvl >= 25 && spellId == GetSpell(DISARM_1))
                timebonus += 20000;
            //Improved Mortal Strike (part 2): -1 sec cooldown for Mortal Strike
            if (lvl >= 25 && spellId == GetSpell(MORTALSTRIKE_1))
                timebonus += 1000;
            //Glyph of Bladestorm: -15 sec cooldown for Bladestorm
            if (lvl >= 60 && spellId == GetSpell(BLADESTORM_1))
                timebonus += 15000;
            //Glyph of Last Stand: -1 min cooldown for Last Stand
            if (lvl >= 20 && spellId == GetSpell(LAST_STAND_1))
                timebonus += 60000;
            //Glyph of Spell Reflection: -1 sec cooldown for Spell Reflection
            if (lvl >= 65 && spellId == GetSpell(SPELL_REFLECTION_1))
                timebonus += 1000;
            //Glyph of Whirlwind: -2 sec cooldown for Whirlwind
            if (lvl >= 36 && spellId == GetSpell(WHIRLWIND_1))
                timebonus += 2000;
            //Warrior T9 2P Bonus (id: 67269): -2 sec cooldown for Taunt (tanks only)
            if (lvl >= 68 && IsTank() && spellId == GetSpell(TAUNT_1))
                timebonus += 2000;
            //Improved Challenging Shout (id: 12327): -2 min cooldown for Challenging Shout (tanks only)
            if (lvl >= 30 && IsTank() && spellId == GetSpell(CHALLENGING_SHOUT_1))
                timebonus += 120000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const
        {
            //cooldown is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->getLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //Unrelenting Assault (part 1): -4 sec cooldown for Overpower and Revenge (not for tanks)
            if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
                timebonus += 4000;
            //Improved Mortal Strike (part 2): -1 sec cooldown for Mortal Strike
            if (lvl >= 25 && spellId == GetSpell(MORTALSTRIKE_1))
                timebonus += 1000;
            //Warrior T9 2P Bonus (id: 67269): -2 sec cooldown for Taunt (tanks only)
            if (lvl >= 68 && IsTank() && spellId == GetSpell(TAUNT_1))
                timebonus += 2000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const
        {
            //cooldown is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->getLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //Unrelenting Assault (part 1, special): -0.5 sec global cooldown for Overpower and Revenge (not for tanks)
            if (lvl >= 50 && !IsTank() && (spellId == GetSpell(OVERPOWER_1) || spellId == GetSpell(REVENGE_1)))
                timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo)
        {
            uint32 spellId = spellInfo->Id;

            if (spellId == GetSpell(LAST_STAND_1))
            {
                BotWhisper("Last Stand used!");
            }
            if (spellId == GetSpell(SHIELD_WALL_1))
            {
                BotWhisper("Shield Wall used!");
            }
            if (spellId == GetSpell(OVERPOWER_1))
            {
                //custom
                float gcd = 1500.f;
                ApplyBotSpellGlobalCooldownMods(spellInfo, gcd);
                GC_Timer = uint32(gcd);
            }
            if (spellId == GetSpell(CLEAVE_1) || spellId == GetSpell(HEROIC_STRIKE_1) || spellId == GetSpell(SLAM_1))
            {
                //once per swing
                SetSpellCooldown(spellId, me->getAttackTimer(BASE_ATTACK));
            }
            if (spellId == GetSpell(VIGILANCE_1))
            {
                SetSpellCooldown(VIGILANCE_1, 30000); //no initial cooldown
            }
            if (spellId == GetSpell(SLAM_1) && me->HasAura(BLOODSURGE_BUFF))
            {
                me->RemoveAura(BLOODSURGE_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }
            if (spellId == GetSpell(HEROIC_STRIKE_1) && me->HasAura(GLYPH_OF_REVENGE_BUFF))
            {
                me->RemoveAura(GLYPH_OF_REVENGE_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }
            if (spellId == GetSpell(SHIELD_SLAM_1) && me->HasAura(SWORD_AND_BOARD_BUFF))
            {
                me->RemoveAura(SWORD_AND_BOARD_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }
            if (spellId == GetSpell(OVERPOWER_1) && me->HasAura(TASTE_FOR_BLOOD_BUFF))
            {
                me->RemoveAura(TASTE_FOR_BLOOD_BUFF, ObjectGuid::Empty, 0, AURA_REMOVE_BY_EXPIRE);
            }
            if (spellId == TASTE_FOR_BLOOD_BUFF)
            {
                SetSpellCooldown(TASTE_FOR_BLOOD_BUFF, 6000);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if (spellId == BATTLESTANCE_1 || spellId == DEFENSIVESTANCE_1 || spellId == BERSERKERSTANCE_1)
            {
                //stance mastery impl
                uint32 temprage = 0;
                uint32 myrage = rage;
                if (me->getLevel() >= 20)
                    temprage = myrage > 250 ? 250 : myrage;
                else if (me->getLevel() >= 15)
                    temprage = myrage > 100 ? 100 : myrage;

                battleStance = (spellId == BATTLESTANCE_1);
                defensiveStance = (spellId == DEFENSIVESTANCE_1);
                berserkerStance = (spellId == BERSERKERSTANCE_1);
                me->SetPower(POWER_RAGE, temprage);
                stancetimer = 2100 - me->getLevel() * 20; //500 on 80
                GC_Timer = temptimer;
            }
            if (spellId == GetSpell(RETALIATION_1))
            {
                //Increase duration by 3 sec and give 10 additional charges to bot
                if (Aura* ret = me->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = ret->GetDuration() + 3000;
                    ret->SetDuration(dur);
                    ret->SetMaxDuration(dur);
                    ret->SetCharges(ret->GetCharges() + 10);
                }
            }
            if (spellId == GetSpell(BERSERKERRAGE_1))
            {
                //Improved Berserker Rage: 20 rage bonus when used
                if (me->getLevel() >= 35)
                    me->CastSpell(me, BERSERKER_RAGE_EFFECT, true);
            }
            if (spellId == SWORD_AND_BOARD_BUFF)
            {
                //Sword And Board: remove Shield Slam cooldown
                ResetSpellCooldown(SHIELD_SLAM_1);
            }
            if (spellId == VIGILANCE_PROC)
            {
                //Vigilance: remove Taunt cooldown
                ResetSpellCooldown(TAUNT_1);
            }
            if (spellId == GetSpell(SHIELD_WALL_1))
            {
                //Shield Wall Duration (id: 60175): 3 sec increased Shield Wall duration
                if (Aura* wall = me->GetAura(spellId))
                {
                    int32 dur = wall->GetDuration() + 3000;
                    wall->SetDuration(dur);
                    wall->SetMaxDuration(dur);
                }
            }

            switch (spellId)
            {
                case VICTORIOUS_SPELL:
                    VICTORIOUS = true;
                    break;
                default:
                    break;
            }
            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if (GetSpell(RECKLESSNESS_1))
            {
                //Recklessness: handle charge drop
                AuraEffect* eff = me->GetAuraEffect(GetSpell(RECKLESSNESS_1), EFFECT_0, me->GetGUID());
                if (eff && eff->IsAffectedOnSpell(spell))
                    eff->GetBase()->DropCharge(AURA_REMOVE_BY_EXPIRE);
            }
            if (spellId == GetSpell(PIERCING_HOWL_1))
            {
                //Piercing Howl: 4 sec duraion increase (exclude players)
                if (target->GetTypeId() != TYPEID_PLAYER)
                {
                    if (Aura* howl = target->GetAura(spellId, me->GetGUID()))
                    {
                        uint32 dur = howl->GetDuration() + 4000;
                        howl->SetDuration(dur);
                        howl->SetMaxDuration(dur);
                    }
                }
            }
            if (spellId == GetSpell(BATTLESHOUT_1) || spellId == GetSpell(COMMANDING_SHOUT_1))
            {
                if (me->getLevel() >= 15)
                {
                    //Commanding Presence: +25% increased effect (melee AP / HP)
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_0, me->GetGUID());
                    if (eff)
                    {
                        int32 amount = eff->GetAmount();
                        amount = amount * 5 / 4;
                        eff->ChangeAmount(amount);
                    }
                }
            }
            if (spellId == GetSpell(REVENGE_1))
            {
                //zzzOLD Revenge Stun (25% chance)
                if (me->getLevel() >= 25 && urand(1,100) <= 25)
                    me->CastSpell(target, REVENGE_STUN_SPELL, true);
            }
            if (spellId == GetSpell(THUNDER_CLAP_1))
            {
                //We make it tanking bonus only, to prevent imbalance
                if (me->getLevel() >= 15 && IsTank())
                {
                    AuraEffect* eff = target->GetAuraEffect(spellId, EFFECT_1, me->GetGUID());
                    if (eff)
                    {
                        int32 amount = eff->GetAmount();
                        //Improved Thunder Clap (part 3): 10% extra slow
                        amount += (-10);
                        //Conqueror Thunder Clap Bonus: 50% increased effect
                        if (me->getLevel() >= 60)
                            amount = amount * 3 / 2;

                        eff->ChangeAmount(amount);
                    }
                }
            }
            if (spellId == GetSpell(OVERPOWER_1))
            {
                me->ClearReactive(REACTIVE_OVERPOWER);
                //Unrelenting Assault (part 3): reduce spells efficiency
                if (UNRELENTING_ASSAULT && target->HasUnitState(UNIT_STATE_CASTING))
                    target->CastSpell(target, UNRELENTING_ASSAULT_SPELL, true);
            }
            if (spellId == GetSpell(BATTLESHOUT_1) || spellId == GetSpell(COMMANDING_SHOUT_1))
            {
                //Glyph of Battle/Command + 2 min duration (8 for bots)
                if (Aura* shout = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = shout->GetDuration() + 480000;
                    shout->SetDuration(dur);
                    shout->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(REND_1))
            {
                //Glyph of Rending + 6 sec duration
                if (Aura* rend = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = rend->GetDuration() + 6000;
                    rend->SetDuration(dur);
                    rend->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(INTERVENE_1))
            {
                //Glyph of Intervene + 2 bonus charges
                if (Aura* vene = target->GetAura(spellId, me->GetGUID()))
                {
                    vene->SetCharges(vene->GetCharges() + 2);
                }
            }
            if (spellId == GetSpell(VICTORY_RUSH_1))
            {
                me->RemoveAura(VICTORIOUS_SPELL);
                VICTORIOUS = false;
            }
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
            stancetimer = 0;
            ragetimer = 1500;
            ragetimer2 = 3000;
            shoutCheckTimer = 5000;

            vigilanceTargetGuid = 0;

            battleStance = true;
            defensiveStance = false;
            berserkerStance = false;

            rageIncomeMult = sWorld->getRate(RATE_POWER_RAGE_INCOME);
            rageLossMult = sWorld->getRate(RATE_POWER_RAGE_LOSS);
            me->setPowerType(POWER_RAGE);
            rage = 0;

            DefaultInit();
        }

        void ReduceCD(uint32 diff)
        {
            if (stancetimer > diff)                 stancetimer -= diff;
            if (ragetimer > diff)                   ragetimer -= diff;
            if (ragetimer2 > diff)                  ragetimer2 -= diff;
            if (shoutCheckTimer > diff)             shoutCheckTimer -= diff;
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            InitSpellMap(INTIMIDATING_SHOUT_1);
            InitSpellMap(ENRAGED_REGENERATION_1);
            InitSpellMap(CHARGE_1);
            InitSpellMap(OVERPOWER_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(TAUNT_1) : RemoveSpell(TAUNT_1);
            InitSpellMap(BLOODRAGE_1);
            InitSpellMap(BERSERKERRAGE_1);
            InitSpellMap(INTERCEPT_1);
            InitSpellMap(CLEAVE_1);
            InitSpellMap(HAMSTRING_1);
            InitSpellMap(INTERVENE_1);
            InitSpellMap(WHIRLWIND_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(BLADESTORM_1) : RemoveSpell(BLADESTORM_1);
            InitSpellMap(BATTLESHOUT_1);
            InitSpellMap(REND_1);
            InitSpellMap(EXECUTE_1);
            InitSpellMap(PUMMEL_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(MORTALSTRIKE_1) : RemoveSpell(MORTALSTRIKE_1);
            InitSpellMap(SLAM_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(SUNDER_1) : RemoveSpell(SUNDER_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(SWEEPING_STRIKES_1) : RemoveSpell(SWEEPING_STRIKES_1);
            InitSpellMap(BATTLESTANCE_1);
   /*Quest*/lvl >= 10 ? InitSpellMap(DEFENSIVESTANCE_1) : RemoveSpell(DEFENSIVESTANCE_1);
   /*Quest*/lvl >= 30 ? InitSpellMap(BERSERKERSTANCE_1) : RemoveSpell(BERSERKERSTANCE_1);
            InitSpellMap(RECKLESSNESS_1);
            InitSpellMap(RETALIATION_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(DEATHWISH_1) : RemoveSpell(DEATHWISH_1);
            InitSpellMap(VICTORY_RUSH_1);
            InitSpellMap(THUNDER_CLAP_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(LAST_STAND_1) : RemoveSpell(LAST_STAND_1);
            InitSpellMap(REVENGE_1);
            InitSpellMap(SHIELD_BLOCK_1);
            InitSpellMap(SHIELD_SLAM_1);
            InitSpellMap(SPELL_REFLECTION_1);
            InitSpellMap(DISARM_1);
            InitSpellMap(SHIELD_WALL_1);
            InitSpellMap(SHIELD_BASH_1);
            InitSpellMap(HEROIC_THROW_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(CONCUSSION_BLOW_1) : RemoveSpell(CONCUSSION_BLOW_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(VIGILANCE_1) : RemoveSpell(VIGILANCE_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(DEVASTATE_1) : RemoveSpell(DEVASTATE_1);
            InitSpellMap(MOCKING_BLOW_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(SHOCKWAVE_1) : RemoveSpell(SHOCKWAVE_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(PIERCING_HOWL_1) : RemoveSpell(PIERCING_HOWL_1);
            InitSpellMap(HEROIC_STRIKE_1);
            InitSpellMap(CHALLENGING_SHOUT_1);
            InitSpellMap(COMMANDING_SHOUT_1);

 /*SPECIAL*/InitSpellMap(TASTE_FOR_BLOOD_BUFF, true);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            UNRELENTING_ASSAULT = (level >= 35);
            RefreshAura(WC5, level >= 70 ? 1 : 0);
            RefreshAura(WC4, level >= 68 && level < 70 ? 1 : 0);
            RefreshAura(WC3, level >= 66 && level < 68 ? 1 : 0);
            RefreshAura(WC2, level >= 64 && level < 66 ? 1 : 0);
            RefreshAura(WC1, level >= 62 && level < 64 ? 1 : 0);
            RefreshAura(FLURRY5, level >= 39 ? 1 : 0);
            RefreshAura(FLURRY4, level >= 38 && level < 39 ? 1 : 0);
            RefreshAura(FLURRY3, level >= 37 && level < 38 ? 1 : 0);
            RefreshAura(FLURRY2, level >= 36 && level < 37 ? 1 : 0);
            RefreshAura(FLURRY1, level >= 35 && level < 36 ? 1 : 0);
            RefreshAura(SWORD_SPEC5, level >= 60 ? 2 : level >= 50 ? 1 : 0);
            RefreshAura(SWORD_SPEC4, level >= 45 && level < 50 ? 1 : 0);
            RefreshAura(SWORD_SPEC3, level >= 40 && level < 45 ? 1 : 0);
            RefreshAura(SWORD_SPEC2, level >= 35 && level < 40 ? 1 : 0);
            RefreshAura(SWORD_SPEC1, level >= 30 && level < 35 ? 1 : 0);
            RefreshAura(RAMPAGE, level >= 60 ? 1 : 0);
            RefreshAura(TRAUMA2, level >= 55 ? 1 : 0);
            RefreshAura(TRAUMA1, level >= 35 && level < 55 ? 1 : 0);
            RefreshAura(BLOOD_FRENZY, level >= 45 ? 1 : 0);
            RefreshAura(SECOND_WIND, level >= 40 ? 1 : 0);
            RefreshAura(TOUGHNESS, level >= 40 ? 2 : level >= 15 ? 1 : 0);
            RefreshAura(IMP_HAMSTRING, level >= 40 ? 2 : level >= 35 ? 1 : 0);
            RefreshAura(SHIELD_SPECIALIZATION, level >= 15 ? 1 : 0);
            RefreshAura(GAG_ORDER, level >= 30 ? 1 : 0);
            RefreshAura(IMPROVED_SPELL_REFLECTION, level >= 25 ? 1 : 0);
            RefreshAura(IMPROVED_DISARM, level >= 25 ? 1 : 0);
            RefreshAura(VITALITY, level >= 45 ? 1 : 0);
            RefreshAura(CRITICAL_BLOCK, level >= 50 ? 1 : 0);
            RefreshAura(SWORD_AND_BOARD, level >= 55 ? 1 : 0);
            RefreshAura(ARMORED_TO_THE_TEETH, level >= 20 ? 1 : 0);
            RefreshAura(ENDLESS_RAGE, level >= 55 ? 1 : 0);
            RefreshAura(BLOODSURGE, level >= 50 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD3, level >= 30 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD2, level >= 28 && level < 30 ? 1 : 0);
            RefreshAura(TASTE_FOR_BLOOD1, level >= 25 && level < 28 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE3, level >= 30 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE2, level >= 25 && level < 30 ? 1 : 0);
            RefreshAura(BLOOD_CRAZE1, level >= 20 && level < 25 ? 1 : 0);
            RefreshAura(WARRIOR_T10_4P, level >= 60 ? 1 : 0);
            RefreshAura(GLYPH_BLOCKING);
            RefreshAura(GLYPH_DEVASTATE);
            RefreshAura(GLYPH_EXECUTION);
            RefreshAura(GLYPH_HEROIC_STRIKE);
            RefreshAura(GLYPH_REVENGE);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case ENRAGED_REGENERATION_1:
                case BLOODRAGE_1:
                case BERSERKERRAGE_1:
                case BATTLESHOUT_1:
                case COMMANDING_SHOUT_1:
                case DEATHWISH_1:
                    return true;
                case BATTLESTANCE_1:
                    return !battleStance;
                case DEFENSIVESTANCE_1:
                    return !defensiveStance;
                case BERSERKERSTANCE_1:
                    return !berserkerStance;
                case SWEEPING_STRIKES_1:
                    return battleStance || berserkerStance;
                case RETALIATION_1:
                    return battleStance;
                case RECKLESSNESS_1:
                    return berserkerStance;
                case SHIELD_WALL_1:
                    return CanBlock() && defensiveStance;
                case SHIELD_BLOCK_1:
                    return CanBlock();
                case LAST_STAND_1:
                case VIGILANCE_1:
                    return IsTank();
                default:
                    return false;
            }
        }

        float GetBotArmorPenetrationCoef() const
        {
            float bonus = 0.0f;

            if (battleStance)
            {
                bonus += 0.1f;
                //Warrior T10 4P Bonus (part 1): 6% additional armor penetration in Battle Stance
                if (me->getLevel() >= 75)
                    bonus += 0.06f;
            }

            //Mace Specialization: 15% armor penetration
            if (me->getLevel() >= 30)
                if (Item const* weap = GetEquips(0))
                    if (ItemTemplate const* proto = weap->GetTemplate())
                        if (proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE || proto->SubClass == ITEM_SUBCLASS_WEAPON_MACE2)
                            bonus += 0.15f;

            return bonus;
        }

    private:
/*tmrs*/uint32 stancetimer, ragetimer, ragetimer2, shoutCheckTimer;
/*misc*/int32 rage;
/*misc*/uint64 vigilanceTargetGuid;
/*misc*/float rageIncomeMult, rageLossMult;
/*Chck*/bool battleStance, defensiveStance, berserkerStance, UNRELENTING_ASSAULT, VICTORIOUS;

        enum WarriorBaseSpells
        {
            INTIMIDATING_SHOUT_1                    = 5246,
            ENRAGED_REGENERATION_1                  = 55694,
            CHARGE_1                                = 11578,
            OVERPOWER_1                             = 7384,
            TAUNT_1                                 = 355,
            BLOODRAGE_1                             = 2687,
            BERSERKERRAGE_1                         = 18499,
            INTERCEPT_1                             = 20252,
            CLEAVE_1                                = 845,
            HAMSTRING_1                             = 1715,
            INTERVENE_1                             = 3411,
            WHIRLWIND_1                             = 1680,
            BLADESTORM_1                            = 46924,
            BATTLESHOUT_1                           = 6673,
            REND_1                                  = 772,
            EXECUTE_1                               = 5308,
            PUMMEL_1                                = 6552,
  /*Talent*/MORTALSTRIKE_1                          = 12294,
            SLAM_1                                  = 1464,
            SUNDER_1                                = 7386,
  /*Talent*/SWEEPING_STRIKES_1                      = 12328,
            BATTLESTANCE_1                          = 2457,
            DEFENSIVESTANCE_1                       = 71,
            BERSERKERSTANCE_1                       = 2458,
            RECKLESSNESS_1                          = 1719,
            RETALIATION_1                           = 20230,
  /*Talent*/DEATHWISH_1                             = 12292,
            VICTORY_RUSH_1                          = 34428,
            THUNDER_CLAP_1                          = 6343,
  /*Talent*/LAST_STAND_1                            = 12975,
            REVENGE_1                               = 6572,
            SHIELD_BLOCK_1                          = 2565,
            SHIELD_SLAM_1                           = 23922,
            SPELL_REFLECTION_1                      = 23920,
            DISARM_1                                = 676,
            SHIELD_WALL_1                           = 871,
            SHIELD_BASH_1                           = 72,
            HEROIC_THROW_1                          = 57755,
  /*Talent*/CONCUSSION_BLOW_1                       = 12809,
  /*Talent*/VIGILANCE_1                             = 50720,
  /*Talent*/DEVASTATE_1                             = 20243,
            MOCKING_BLOW_1                          = 694,
            SHOCKWAVE_1                             = 46968,
            PIERCING_HOWL_1                         = 12323,
            HEROIC_STRIKE_1                         = 78,
            CHALLENGING_SHOUT_1                     = 1161,
            COMMANDING_SHOUT_1                      = 469
        };
        enum WarriorPassives
        {
        //Talents
            WC1  /*WRECKING CREW1*/                 = 46867,
            WC2  /*WRECKING CREW2*/                 = 56611,
            WC3  /*WRECKING CREW3*/                 = 56612,
            WC4  /*WRECKING CREW4*/                 = 56613,
            WC5  /*WRECKING CREW5*/                 = 56614,
            FLURRY1                                 = 16256,
            FLURRY2                                 = 16281,
            FLURRY3                                 = 16282,
            FLURRY4                                 = 16283,
            FLURRY5                                 = 16284,
            SWORD_SPEC1                             = 12281,
            SWORD_SPEC2                             = 12812,
            SWORD_SPEC3                             = 12813,
            SWORD_SPEC4                             = 12814,
            SWORD_SPEC5                             = 12815,
            BLOOD_CRAZE1                            = 16487,
            BLOOD_CRAZE2                            = 16489,
            BLOOD_CRAZE3                            = 16492,
            TASTE_FOR_BLOOD1                        = 56636,
            TASTE_FOR_BLOOD2                        = 56637,
            TASTE_FOR_BLOOD3                        = 56638,
            UNRELENTING_ASSAULT1                    = 46859,
            UNRELENTING_ASSAULT2                    = 46860,
            TRAUMA1                                 = 46854,
            TRAUMA2                                 = 46855,
            BLOOD_FRENZY                            = 29859,
            RAMPAGE                                 = 29801,
            SECOND_WIND                             = 29838,//rank 2
            TOUGHNESS                               = 12764,//rank 5
            IMP_HAMSTRING                           = 23695,//rank 3
            SHIELD_SPECIALIZATION                   = 12727,//rank 5
            GAG_ORDER                               = 12958,//rank 2
            IMPROVED_SPELL_REFLECTION               = 59089,//rank 2
            IMPROVED_DISARM                         = 12804,//rank 2
            VITALITY                                = 29144,//rank 3
            CRITICAL_BLOCK                          = 47296,//rank 3
            SWORD_AND_BOARD                         = 46953,//rank 3
            ARMORED_TO_THE_TEETH                    = 61222,//rank 3
            ENDLESS_RAGE                            = 29623,
            BLOODSURGE                              = 46915,//rank 3
        //other
            WARRIOR_T10_4P                          = 70844,
            GLYPH_BLOCKING                          = 58375,
            GLYPH_DEVASTATE                         = 58388,
            GLYPH_EXECUTION                         = 58367,
            GLYPH_HEROIC_STRIKE                     = 58357,
            GLYPH_REVENGE                           = 58364
        };
        enum WarriorSpecial
        {
            TASTE_FOR_BLOOD_BUFF                    = 60503,
            //LAMBS_TO_THE_SLAUGHTER_BUFF             = 84586,
            SWORD_AND_BOARD_BUFF                    = 50227,
            BLOODSURGE_BUFF                         = 46916,//"Slam!"
            GLYPH_OF_REVENGE_BUFF                   = 58363,
            UNRELENTING_ASSAULT_SPELL               = 65925,//64849
            VICTORIOUS_SPELL                        = 32216,
            REVENGE_STUN_SPELL                      = 12798,
            //COLOSSUS_SMASH_EFFECT                   = 108126,
            //SWORD_SPECIALIZATION_TRIGGERED          = 16459,
            VIGILANCE_PROC                          = 50725,
            BERSERKER_RAGE_EFFECT                   = 23691,//rank 2

            BLESSING_OF_MIGHT_1                     = 19740,
            GREATER_BLESSING_OF_MIGHT_1             = 25782
        };
    };
};

void AddSC_warrior_bot()
{
    new warrior_bot();
}
