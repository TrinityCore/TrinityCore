#include "bot_ai.h"
//#include "botmgr.h"
#include "GameEventMgr.h"
#include "Group.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
/*
Death Knight NpcBot by Graff onlysuffering@gmail.com
Complete - around 55%
Note: Rune system adapted from TC
TODO: REMEMBER ALREADY DK HAS MINIMUM LEVEL 55!
*/
const RuneType runeSlotTypes[MAX_RUNES] =
{
    RUNE_BLOOD,
    RUNE_BLOOD,
    RUNE_UNHOLY,
    RUNE_UNHOLY,
    RUNE_FROST,
    RUNE_FROST
};
struct BotRuneInfo
{
    uint8 BaseRune;
    uint8 CurrentRune;
    uint32 Cooldown;
    //AuraEffect const* ConvertAura;
};

struct BotRunes
{
    BotRuneInfo runes[MAX_RUNES];
    //uint8 runeState;          //UNUSED
    //uint8 lastUsedRune;       //UNUSED

    //void SetRuneState(uint8 index, bool set = true)
    //{
    //    if (set)
    //        runeState |= (1 << index);    // usable
    //    else
    //        runeState &= ~(1 << index);   // on cooldown
    //}
};
class death_knight_bot : public CreatureScript
{
public:
    death_knight_bot() : CreatureScript("death_knight_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new death_knight_botAI(creature);
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

    struct death_knight_botAI : public bot_minion_ai
    {
        death_knight_botAI(Creature* creature) : bot_minion_ai(creature)
        {
            _botclass = BOT_CLASS_DEATH_KNIGHT;
        }

        bool doCast(Unit* victim, uint32 spellId, bool triggered = false)
        {
            if (CheckBotCast(victim, spellId, BOT_CLASS_DEATH_KNIGHT) != SPELL_CAST_OK)
                return false;

            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
            int32 runecost[NUM_RUNE_TYPES];
            for (uint8 i = 0; i != NUM_RUNE_TYPES; ++i)
                runecost[i] = 0;

            if (!triggered)
            {
                if (!HaveRunes(spellInfo, runecost))
                    return false;
            }

            bool result = bot_ai::doCast(victim, spellId, triggered);

            if (result)
            {
                //std::ostringstream str;
                //str << "Casting " << spellInfo->SpellName[0] << " on " << victim->GetName();
                //me->MonsterWhisper(str.str().c_str(), master->GetGUID());
                //Set cooldown for runes
                if (!triggered)
                {
                    SpendRunes(runecost);
                    ////debug
                    //for (uint8 i = 0; i != NUM_RUNE_TYPES; ++i)
                    //    if (runecost[i])
                    //        TC_LOG_FATAL("entities.player", "doCast():: DK bot %s has casted spell %u (%s) without %u rune(s) (type %u)!",
                    //            me->GetName().c_str(), spellId, spellInfo->SpellName[0], runecost[i], i);
                }
                //runic power gain: all dk spells are instant but some have no unit target so
                //we gain runic power here instead of SpellHitTarget()
                if (SpellRuneCostEntry const* src = sSpellRuneCostStore.LookupEntry(spellInfo->RuneCostID))
                    if (int32 rp = int32(src->runePowerGain * runicpowerIncomeMult))
                        me->ModifyPower(POWER_RUNIC_POWER, int32(rp));
            }

            return result;
        }

        bool HaveRunes(SpellInfo const* spellInfo, int32 *runecost) const
        {
            if (spellInfo->PowerType != POWER_RUNE || !spellInfo->RuneCostID)
                return true;

            CalcRuneCost(spellInfo, runecost);

            if (runecost[RUNE_DEATH] != 0 && runecost[RUNE_DEATH] > GetDeathRunesCount())
                return false;

            return true;
        }

        void CalcRuneCost(SpellInfo const* spellInfo, int32 *runecost) const
        {
            SpellRuneCostEntry const* src = sSpellRuneCostStore.LookupEntry(spellInfo->RuneCostID);
            if (!src)
                return;

            if (src->NoRuneCost())
                return;

            for (uint8 i = 0; i != RUNE_DEATH; ++i)
                runecost[i] = src->RuneCost[i];

            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                uint8 rune = _runes.runes[i].BaseRune;
                if (_runes.runes[i].CurrentRune == rune && _runes.runes[i].Cooldown == 0 && runecost[rune] > 0)
                    runecost[rune]--;
            }

            for (uint8 i = 0; i != RUNE_DEATH; ++i)
                if (runecost[i] > 0)
                    runecost[RUNE_DEATH] += runecost[i];

            ////restore cost to allow cooldown set
            //for (uint8 i = 0; i != RUNE_DEATH; ++i)
            //    runecost[i] = src->RuneCost[i];
        }

        int32 GetDeathRunesCount() const
        {
            int32 count = 0;
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                if (_runes.runes[i].CurrentRune == RUNE_DEATH && _runes.runes[i].Cooldown == 0)
                    ++count;

            return count;
        }

        uint8 GetCooledRunesCount(uint8 runetype) const
        {
            uint8 count = 0;
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                if (_runes.runes[i].BaseRune == runetype && _runes.runes[i].Cooldown > 0)
                    ++count;

            return count;
        }

        void SpendRunes(int32* runecost)
        {
            for (uint8 i = 0; i != NUM_RUNE_TYPES; ++i)
            {
                if (runecost[i] <= 0)
                    continue;

                for (uint8 j = 0; j != MAX_RUNES && runecost[i] > 0; ++j)
                {
                    if (SpendRune(i))
                        runecost[i]--;
                }
            }

            if (GetCooledRunesCount(RUNE_BLOOD) > 1)
            {
                me->CastSpell(me, BLADE_BARRIER_AURA, true);
            }
        }

        bool SpendRune(uint8 runetype)
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                if (_runes.runes[i].CurrentRune == runetype && _runes.runes[i].Cooldown == 0)
                {
                    _runes.runes[i].CurrentRune = _runes.runes[i].BaseRune;
                    //_runes.lastUsedRune = _runes.runes[i].CurrentRune;        //UNUSED
                    //_runes.SetRuneState(i, false);                            //UNUSED
                    //DK receives rune regen bonus from mana regen
                    uint32 cooldown = RUNE_BASE_COOLDOWN - std::min<uint32>(uint32(GetManaRegen() * 10), RUNE_BASE_COOLDOWN);
                    _runes.runes[i].Cooldown = cooldown;
                    //std::ostringstream str;
                    //str << "Spent rune " << uint32(i) << " (type: " << uint32(runetype) << ')';
                    //me->MonsterWhisper(str.str().c_str(), master->GetGUID());
                    return true;
                }
            }

            return false;
        }

        bool HaveRune(uint8 runetype) const
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                if ((_runes.runes[i].CurrentRune == runetype || _runes.runes[i].CurrentRune == RUNE_DEATH) &&
                    _runes.runes[i].Cooldown == 0)
                {
                    return true;
                }
            }

            return false;
        }

        void ConvertRune(uint8 runetype, uint8 count)
        {
            if (runetype == RUNE_DEATH)
                return;

            uint8 failcount = 0;
            for (uint8 i = 0; i != MAX_RUNES && count > 0; ++i)
            {
                if (_runes.runes[i].BaseRune == runetype)
                {
                    if (_runes.runes[i].CurrentRune == RUNE_DEATH)
                    {
                        ++failcount;
                        continue;
                    }

                    if (_runes.runes[i].Cooldown > 3000)
                        _runes.runes[i].Cooldown -= 3000;

                    _runes.runes[i].CurrentRune = RUNE_DEATH;
                    --count;
                }
            }

            if (!count && !failcount)
                return;

            //std::ostringstream str;
            //str << "Failed to convert rune of type: " << uint32(runetype) << ")!";
            //me->MonsterWhisper(str.str().c_str(), master->GetGUID());
        }

        void ActivateAllRunes()
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                _runes.runes[i].Cooldown = 0;
                //_runes.SetRuneState(i, true);       //UNUSED
            }
        }

        void InitRunes()
        {
            //_runes.runeState = 0;                   //UNUSED
            //_runes.lastUsedRune = RUNE_BLOOD;       //UNUSED

            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                _runes.runes[i].BaseRune = runeSlotTypes[i];
                _runes.runes[i].CurrentRune = _runes.runes[i].BaseRune;
                _runes.runes[i].Cooldown = 0;
                //_runes.runes[i].ConvertAura = NULL; //UNUSED
                //_runes.SetRuneState(i, true);       //UNUSED
            }
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            Aggro(u);
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force);
        }

        void RuneTimers(uint32 diff)
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                if (_runes.runes[i].Cooldown <= diff)
                {
                    _runes.runes[i].Cooldown = 0;
                    //_runes.SetRuneState(i, true);     //UNUSED
                }
                else
                    _runes.runes[i].Cooldown -= diff;
            }
        }

        void modpower(int32 mod, bool set = false)
        {
            if (set && mod < 0)
                return;
            if (mod < 0 && runicpower < uint32(abs(mod)))
            {
                //debug set runic power to 0
                mod = 0;
                set = true;
                return;
            }

            if (set)
                runicpower = mod ? mod * 10 : 0;
            else
                runicpower += mod * 10;

            me->SetPower(POWER_RUNIC_POWER, runicpower);
        }

        uint32 getpower()
        {
            runicpower = me->GetPower(POWER_RUNIC_POWER);
            return runicpower;
        }

        uint8 GetBotStance() const { return Presence; }

        void EnterCombat(Unit* u) { bot_minion_ai::EnterCombat(u); }
        void Aggro(Unit*) { }
        void AttackStart(Unit*) { }
        void EnterEvadeMode(EvadeReason /*why*/) { bot_minion_ai::EnterEvadeMode(); }
        void MoveInLineOfSight(Unit* u) { bot_minion_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) { bot_minion_ai::JustDied(u); }
        void KilledUnit(Unit*) { }
        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || IsCasting() || Feasting() || Rand() > 20)
                return;

            //PATH OF FROST
            if (GetSpell(PATH_OF_FROST_1) && HaveRune(RUNE_FROST)/* && !me->IsMounted()*/) //works while mounted
            {
                if ((me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && !me->HasAuraType(SPELL_AURA_WATER_WALK)) ||
                    (master->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && !master->HasAuraType(SPELL_AURA_WATER_WALK) && me->GetDistance(master) < 50))
                {
                    if (doCast(me, GetSpell(PATH_OF_FROST_1)))
                        return;
                }
            }
        }

        void CheckHysteria(uint32 diff)
        {
            if (!IsSpellReady(HYSTERIA_1, diff) || IsCasting() || Rand() > 15)
                return;

            Unit* target = NULL;

            if (master->IsAlive() && IsMeleeClass(master->getClass()) && master->IsInCombat() &&
                GetHealthPCT(master) > 80 && me->GetDistance(master) < 30 &&
                master->getAttackers().empty() && !CCed(master, true))
            {
                if (Unit* u = master->GetVictim())
                    if (u->GetHealth() > me->GetMaxHealth() / 2)
                        target = master;
            }

            if (!target && IsMeleeClass(_botclass) && GetHealthPCT(me) > 80 &&
                me->getAttackers().empty() && !CCed(me, true))
            {
                if (Unit* u = me->GetVictim())
                    if (u->GetHealth() > me->GetMaxHealth() / 2)
                        target = me;
            }

            if (!target && !IAmFree())
            {
                Group* gr = master->GetGroup();
                if (gr)
                {
                    for (GroupReference* itr = gr->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* tPlayer = itr->GetSource();
                        if (tPlayer == master) continue;
                        if (!tPlayer || !tPlayer->IsInWorld() || tPlayer->IsBeingTeleported()) continue;
                        if (!tPlayer->IsAlive() || me->GetMap() != tPlayer->FindMap()) continue;
                        if (!IsMeleeClass(tPlayer->getClass()) || !tPlayer->IsInCombat()) continue;
                        if (GetHealthPCT(tPlayer) < 80 || me->GetDistance(tPlayer) > 30) continue;
                        if (!tPlayer->getAttackers().empty() || CCed(tPlayer, true)) continue;
                        if (Unit* u = tPlayer->GetVictim())
                        {
                            if (u->GetHealth() > (me->GetMaxHealth() * 2) / 3)
                            {
                                target = tPlayer;
                                break;
                            }
                        }
                    }
                }
            }

            if (target && doCast(target, GetSpell(HYSTERIA_1)))
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                    BotWhisper("Hysteria on You!", target->ToPlayer());

                GC_Timer = 800;
                return;
            }

            SetSpellCooldown(HYSTERIA_1, 2000); //fail
        }

        void CheckAntiMagicShell(uint32 diff)
        {
            if (!IsSpellReady(ANTI_MAGIC_SHELL_1, diff, false) || GetHealthPCT(me) > 55 ||
                getpower() < 200 || IsCasting() || Rand() > 50)
                return;

            AttackerSet b_attackers = me->getAttackers();

            if (b_attackers.empty())
                return;

            bool cast = false;
            uint8 count = 0;

            for (AttackerSet::const_iterator itr = b_attackers.begin(); itr != b_attackers.end(); ++itr)
            {
                if (!(*itr) || !(*itr)->IsAlive()) continue;
                if (Spell* spell = (*itr)->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                {
                    if (spell->m_targets.GetUnitTargetGUID() == me->GetGUID())
                    {
                        if ((*itr)->ToCreature() && (*itr)->ToCreature()->isWorldBoss())
                        {
                            cast = true;
                            break;
                        }

                        if (++count >= 3)
                        {
                            cast = true;
                            break;
                        }
                    }
                }
            }

            if (cast)
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(ANTI_MAGIC_SHELL_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            SetSpellCooldown(ANTI_MAGIC_SHELL_1, 1500); //fail
        }

        void CheckPresence(uint32 diff)
        {
            if (presencetimer > diff || IsCasting() || Rand() > 30) //no GCD
                return;

            uint8 newpresence = IsTank() ? DEATH_KNIGHT_FROST_PRESENCE : DEATH_KNIGHT_BLOOD_PRESENCE;
            if (Presence == newpresence)
            {
                presencetimer = 500;
                return;
            }

            Presence = newpresence;

            if (Presence == DEATH_KNIGHT_FROST_PRESENCE && HaveRune(RUNE_FROST))
            {
                temptimer = GC_Timer;
                if (doCast(me, FROST_PRESENCE_1))
                {
                    GC_Timer = temptimer;
                    presencetimer = 1000;
                    return;
                }
            }
            else if (Presence == DEATH_KNIGHT_BLOOD_PRESENCE && HaveRune(RUNE_BLOOD))
            {
                temptimer = GC_Timer;
                if (doCast(me, BLOOD_PRESENCE_1))
                {
                    GC_Timer = temptimer;
                    presencetimer = 1000;
                    return;
                }
            }

            presencetimer = 500; //fail
        }

        void BreakCC(uint32 diff)
        {
            if (IsSpellReady(LICHBORNE_1, diff, false) &&/* Rand() < 75 &&*/
                me->HasAuraWithMechanic((1<<MECHANIC_CHARM)|(1<<MECHANIC_FEAR)|(1<<MECHANIC_SLEEP)))
            {
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(LICHBORNE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }

            bot_minion_ai::BreakCC(diff);
        }

        void UpdateAI(uint32 diff)
        {
            me->SetMaxPower(POWER_RUNIC_POWER, me->GetCreatePowers(POWER_RUNIC_POWER));
            ReduceCD(diff);
            if (!GlobalUpdate(diff))
                return;
            CheckAttackState();

            if (me->getPowerType() != POWER_RUNIC_POWER)
                InitPowers();

            if (runicpowertimer <= diff)
            {
                if (!me->IsInCombat())
                {
                    if (getpower() > uint32(30 * runicpowerLossMult))
                        me->SetPower(POWER_RUNIC_POWER, runicpower - uint32(30 * runicpowerLossMult)); //-3 runic power every 2 sec
                    else
                        me->SetPower(POWER_RUNIC_POWER, 0);
                }
                runicpowertimer = 2000;
            }
            if (runicpowertimer2 <= diff)
            {
                if (me->IsInCombat())
                {
                    if (getpower() < me->GetMaxPower(POWER_RUNIC_POWER))
                        me->SetPower(POWER_RUNIC_POWER, runicpower + uint32(20 * runicpowerIncomeMult)); //+2 runic power every 5 sec
                    else
                        me->SetPower(POWER_RUNIC_POWER, me->GetMaxPower(POWER_RUNIC_POWER));
                }
                runicpowertimer2 = 5000;
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
            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            CheckPresence(diff);

            //HORN OF WINTER
            if (IsSpellReady(HORN_OF_WINTER_1, diff, false, (me->IsInCombat() ? 45000 : 0)) && Rand() < 30 &&
                (me->IsInCombat() || (me->GetDistance(master) < 28 && master->IsWithinLOSInMap(me))))
            {
                Aura* horn = master->GetAura(GetSpell(HORN_OF_WINTER_1));
                if (!horn || horn->GetDuration() < 5000)
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(HORN_OF_WINTER_1)))
                    {
                        GC_Timer = temptimer;
                        return;
                    }
                }
            }
            //BONE SHIELD
            if (IsSpellReady(BONE_SHIELD_1, diff) && HaveRune(RUNE_UNHOLY) && Rand() < 25)
            {
                Aura* bone = me->GetAura(GetSpell(BONE_SHIELD_1));
                if (!bone || bone->GetCharges() < 2 || (!me->IsInCombat() && bone->GetDuration() < 60000))
                {
                    if (doCast(me, GetSpell(BONE_SHIELD_1)))
                    {
                        GC_Timer = 800;
                        return;
                    }
                }

                SetSpellCooldown(BONE_SHIELD_1, 1000); //fail
            }

            if (me->IsInCombat())
            {
                //ICEBOUND FORTITUDE
                if (IsSpellReady(ICEBOUND_FORTITUDE_1, diff, false) && getpower() >= 200 &&
                    GetHealthPCT(me) < std::min<uint32>(85, 45 + uint8(me->getAttackers().size()) * 7) &&
                    Rand() < 40 + IsTank() * 50)
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(ICEBOUND_FORTITUDE_1)))
                        GC_Timer = temptimer;
                }

                CheckAntiMagicShell(diff);
                CheckHysteria(diff);
            }

            if (!CheckAttackTarget(BOT_CLASS_DEATH_KNIGHT))
                return;

            Attack(diff);
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

            //SELFHEAL

            //RUNE TAP
            if (IsSpellReady(RUNE_TAP_1, diff) && GetHealthPCT(me) < 40 && Rand() < 50)
            {
                if (!HaveRune(RUNE_BLOOD) && IsSpellReady(EMPOWER_RUNE_WEAPON_1, diff, false))
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(EMPOWER_RUNE_WEAPON_1)))
                    {
                        ActivateAllRunes();
                        GC_Timer = temptimer;
                    }
                }
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(RUNE_TAP_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //VAMPIRIC BLOOD
            if (IsSpellReady(VAMPIRIC_BLOOD_1, diff, false) && GetHealthPCT(me) < 26/* && Rand() < 75*/)
            {
                if (!HaveRune(RUNE_BLOOD) && IsSpellReady(EMPOWER_RUNE_WEAPON_1, diff, false, 40000))
                {
                    temptimer = GC_Timer;
                    if (doCast(me, GetSpell(EMPOWER_RUNE_WEAPON_1)))
                    {
                        ActivateAllRunes();
                        GC_Timer = temptimer;
                    }
                }
                temptimer = GC_Timer;
                if (doCast(me, GetSpell(VAMPIRIC_BLOOD_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //END SELFHEAL

            //MARK OF BLOOD
            Unit* u = opponent->GetVictim();
            if (IsSpellReady(MARK_OF_BLOOD_1, diff) && HaveRune(RUNE_BLOOD) &&
                u && GetHealthPCT(u) < 85 && opponent->GetHealth() > u->GetMaxHealth() / 3 &&
                (IsTank(u) || u->GetTypeId() == TYPEID_PLAYER) &&
                Rand() < 35 && !opponent->HasAura(MARK_OF_BLOOD_1) && IsInBotParty(u))
            {
                if (doCast(opponent, GetSpell(MARK_OF_BLOOD_1)))
                {
                    GC_Timer = 800;
                    return;
                }
            }

            //AttackerSet m_attackers = master->getAttackers();
            //AttackerSet b_attackers = me->getAttackers();
            float dist = me->GetExactDist(opponent);
            float meleedist = me->GetDistance(opponent);

            //NON-DISEASE SECTION

            //PLACEHOLDER: ARMY OF THE DEAD

            //RANGED SECTION

            //STRANGULATE
            if (IsSpellReady(STRANGULATE_1, diff) && meleedist <= 30 && HaveRune(RUNE_BLOOD) &&
                opponent->IsNonMeleeSpellCast(false) && Rand() < 40)
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                if (doCast(opponent, GetSpell(STRANGULATE_1)))
                {
                    GC_Timer = 800;
                    return;
                }

                SetSpellCooldown(STRANGULATE_1, 500); //fail
            }

            //DARK COMMAND
            if (IsSpellReady(DARK_COMMAND_1, diff, false) && dist < 30 && IsTank() &&
                opponent->GetVictim() != me && Rand() < 70)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(DARK_COMMAND_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            ////DEATH GRIP - DISABLED
            //if (DEATH_GRIP && DeathGrip_cd <= diff && dist < 30 &&
            //    (tank == me && opponent->GetVictim() != me) ||
            //    (opponent->GetVictim() == me && opponent->ToPlayer() && opponent->IsNonMeleeSpellCast(false)) &&
            //    Rand() < 75)
            //{
            //    temptimer = GC_Timer;
            //    if (doCast(opponent, DEATH_GRIP))
            //    {
            //        DeathGrip_cd = 25000;
            //        GC_Timer = temptimer;
            //        return;
            //    }

            //    DeathGrip_cd = 1000; //fail
            //}
            //CHAINS OF ICE
            if (uint32 CHAINS_OF_ICE = GetSpell(CHAINS_OF_ICE_1))
            {
                if (GC_Timer <= diff && dist < 20 && HaveRune(RUNE_FROST) && opponent->isMoving() &&
                    !CCed(opponent) && !IsTank(opponent->GetVictim()) && IsInBotParty(opponent->GetVictim()) && Rand() < 25)
                {
                    Aura* chains = opponent->GetAura(CHAINS_OF_ICE);
                    if (!chains || chains->GetDuration() < chains->GetMaxDuration() / 4)
                    {
                        if (doCast(opponent, CHAINS_OF_ICE))
                        {
                            //Improved Chains of Ice: convert frost rune into death rune
                            ConvertRune(RUNE_FROST, 1);
                            return;
                        }
                    }
                }
            }

            //AOE SECTION

            //HOWLING BLAST
            if (IsSpellReady(HOWLING_BLAST_1, diff) && IsTank() && meleedist < 8 && HasRole(BOT_ROLE_DPS) &&
                me->getAttackers().size() > 2 && HaveRune(RUNE_UNHOLY) && HaveRune(RUNE_FROST) && Rand() < 50)
            {
                if (doCast(me, GetSpell(HOWLING_BLAST_1)))
                {
                    GC_Timer = 800;
                    return;
                }

                SetSpellCooldown(HOWLING_BLAST_1, 500); //fail
            }
            //BLOOD BOIL
            if (IsSpellReady(BLOOD_BOIL_1, diff) && HasRole(BOT_ROLE_DPS) && HaveRune(RUNE_BLOOD) && Rand() < (10 + 40 * IsTank()))
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 9.5f);
                if (targets.size() >= 5)
                    if (doCast(me, GetSpell(BLOOD_BOIL_1)))
                        return;
            }
            //DEATH AND DECAY
            if (IsSpellReady(DEATH_AND_DECAY_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < (30 + 30 * IsTank()) &&
                HaveRune(RUNE_BLOOD) && HaveRune(RUNE_UNHOLY) && HaveRune(RUNE_FROST))
            {
                if (Unit* target = FindAOETarget(30, true))
                {
                    if (doCast(target, GetSpell(DEATH_AND_DECAY_1)))
                        return;
                }

                SetSpellCooldown(DEATH_AND_DECAY_1, 500); //fail
            }

            //END AOE SECTION

            //ICY TOUCH
            if (IsSpellReady(ICY_TOUCH_1, diff) && HasRole(BOT_ROLE_DPS) && dist < 20 && HaveRune(RUNE_FROST) && Rand() < 25 &&
                !opponent->HasAura(FROST_FEVER_AURA, me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(ICY_TOUCH_1)))
                    return;
            }
            //DEATH COIL //custom cd condition
            if (GetSpell(DEATH_COIL_1) && GC_Timer <= 600 && dist < 20 && HasRole(BOT_ROLE_DPS) &&
                int32(getpower()) >= (400 + 200 * (GetSpell(RUNE_STRIKE_1) != 0 || GetSpell(MIND_FREEZE_1) != 0 || GetSpell(ANTI_MAGIC_SHELL_1) != 0) + 400 * (GetSpell(HUNGERING_COLD_1) != 0)) &&
                Rand() < 60)
            {
                if (doCast(opponent, GetSpell(DEATH_COIL_1)))
                    return;
            }

            //MELEE SECTION

            //MIND FREEZE
            if (IsSpellReady(MIND_FREEZE_1, diff, false) && meleedist <= 5 && getpower() >= 200 &&
                opponent->IsNonMeleeSpellCast(false) && Rand() < 60)
            {
                if (me->IsNonMeleeSpellCast(false))
                    me->InterruptNonMeleeSpells(false);

                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(MIND_FREEZE_1)))
                {
                    GC_Timer = temptimer;
                    return;
                }
            }
            //HUNGERING COLD
            if (IsSpellReady(HUNGERING_COLD_1, diff) && HasRole(BOT_ROLE_DPS) && getpower() >= 400 && Rand() < 20)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 9.f, 0, true);
                if (targets.size() >= 3)
                {
                    if (doCast(me, GetSpell(HUNGERING_COLD_1)))
                        return;
                }

                SetSpellCooldown(HUNGERING_COLD_1, 500); //fail
            }

            if (MoveBehind(*opponent))
                wait = 5;

            //RUNE STRIKE
            if (IsSpellReady(RUNE_STRIKE_1, diff, false) && runestriketimer > me->getAttackTimer(BASE_ATTACK) &&
                HasRole(BOT_ROLE_DPS) && meleedist <= 5 && getpower() >= 200/* && Rand() < 75*/)
            {
                temptimer = GC_Timer;
                if (doCast(opponent, GetSpell(RUNE_STRIKE_1)))
                {
                    runestriketimer = 0; //do not remove aura, just disable ability
                    GC_Timer = temptimer;
                }
            }
            //PLAGUE STRIKE
            if (IsSpellReady(PLAGUE_STRIKE_1, diff) && HasRole(BOT_ROLE_DPS) && meleedist <= 5 && HaveRune(RUNE_UNHOLY) && Rand() < 35 &&
                !opponent->HasAura(BLOOD_PLAGUE_AURA, me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(PLAGUE_STRIKE_1)))
                    return;
            }

            //DISEASE SECTION
            uint32 diseases = opponent->GetDiseasesByCaster(me->GetGUID());

            //PESTILENCE //custom cd condition
            if (GetSpell(PESTILENCE_1) && pestilencetimer == 0 && HasRole(BOT_ROLE_DPS) && GC_Timer <= 600 &&
                diseases > 1 && meleedist <= 5 &&
                HaveRune(RUNE_BLOOD) && Rand() < 15)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 9.f);
                if (targets.size() > 2)
                {
                    if (doCast(opponent, GetSpell(PESTILENCE_1)))
                    {
                        pestilencetimer = 10000;
                        return;
                    }
                }

                pestilencetimer = 1000; //fail
            }
            //DEATH STRIKE
            if (IsSpellReady(DEATH_STRIKE_1, diff) && diseases > 0 && HasRole(BOT_ROLE_DPS) && meleedist <= 5 &&
                HaveRune(RUNE_UNHOLY) && HaveRune(RUNE_FROST) &&
                GetHealthPCT(me) < (91 - 10 * diseases) && Rand() < 70)
            {
                if (doCast(opponent, GetSpell(DEATH_STRIKE_1)))
                    return;
            }
            //OBLITERATE
            if (IsSpellReady(OBLITERATE_1, diff) && diseases > 2 && HasRole(BOT_ROLE_DPS) && meleedist <= 5 &&
                HaveRune(RUNE_UNHOLY) && HaveRune(RUNE_FROST) && Rand() < 20)
            {
                if (doCast(opponent, GetSpell(OBLITERATE_1)))
                    return;
            }
            //BLOOD STRIKE //custom
            if (BLOOD_STRIKE && GC_Timer <= diff && HasRole(BOT_ROLE_DPS) && diseases > 1 && meleedist <= 5 &&
                HaveRune(RUNE_BLOOD) && Rand() < 25)
            {
                if (doCast(opponent, BLOOD_STRIKE))
                    return;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& /*damageinfo*/) const {}

        void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool& crit) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float fdamage = float(damage);
            //1) apply additional crit chance. This additional chance roll will replace original (balance safe)
            if (!crit)
            {
                float aftercrit = 0.f;

                //Increased Plague Strike Crit (id 60130): 10% additional critical chance for Plague Strike
                if (spellId == GetSpell(PLAGUE_STRIKE_1))
                    aftercrit += 0.1f;
                //Glyph of Rune Strike: 10% additional critical chance for Rune Strike
                if (spellId == GetSpell(RUNE_STRIKE_1))
                    aftercrit += 0.1f;
                //Subversion: 9% additional critical chance for Blood Strike, Scourge Strike, Heart Strike and Obliterate
                if (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1) ||
                    /*spellId == GetSpell(SCOURGE_STRIKE_1) || */spellId == GetSpell(OBLITERATE_1))
                    aftercrit += 0.09f;
                //Improved Death Strike (part 2): 6% additional critical chance for Death Strike
                if (spellId == GetSpell(DEATH_STRIKE_1))
                    aftercrit += 0.06f;
                //Rime (part 1 melee): 15% additional critical chance for Obliterate
                if (lvl >= 68 && spellId == GetSpell(OBLITERATE_1))
                    aftercrit += 15.f;
                //Vicious Strikes (part 1): 6% additional critical chance for Plague Strike and Scourge Strike
                if (lvl >= 57 && (spellId == GetSpell(PLAGUE_STRIKE_1)/* || spellId == GetSpell(SCOURGE_STRIKE_1)*/))
                    aftercrit += 6.f;

                //Annihilation: 3% additional critical chance for melee special abilities
                if (lvl >= 57)
                    aftercrit += 0.03f;

                //second roll (may be illogical)
                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half

                //Might of Mograine: 45% crit damage bonus for Blood Boil, Blood Strike, Death Strike and Heart Strike
                if (lvl >= 68 &&
                    (spellId == GetSpell(BLOOD_BOIL_1) || spellId == BLOOD_STRIKE ||
                    spellId == GetSpell(DEATH_STRIKE_1) || spellId == GetSpell(HEART_STRIKE_1)))
                    pctbonus += 0.45f / 2.f;
                //Guile of Gorefiend (part 1 melee): 45% crit damage bonus for Blood Strike, Frost Strike and Obliterate
                if (lvl >= 69 &&
                    (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1) ||
                    spellId == GetSpell(OBLITERATE_1)/* || spellId == GetSpell(FROST_STRIKE_1)*/))
                    pctbonus += 0.45f / 2.f;
                //Vicious Strikes (part 2): 30% crit damage bonus for Plague Strike and Scourge Strike
                if (lvl >= 57 && (spellId == GetSpell(PLAGUE_STRIKE_1)/* || spellId == GetSpell(SCOURGE_STRIKE_1)*/))
                    pctbonus += 0.3f / 2.f;
            }

            //Glypg of Plague Strike: 20% bonus damage for Plague Strike
            if (spellId == GetSpell(PLAGUE_STRIKE_1))
                pctbonus += 0.2f;
            //Glyph of Blood Strike: 20% bonus damage for Blood Strike on snared targets (Heart Strike too for bots)
            //warning unsafe
            if (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1))
                if (damageinfo.target->HasAuraWithMechanic((1<<MECHANIC_SNARE)|(1<<MECHANIC_SLOW_ATTACK)))
                    pctbonus += 0.2f;
            //Increased Blood Strike Damage: 90 bonus damage for Blood Strike and Heart Strike
            if (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1))
                fdamage += 90.f;
            //Glyph of Death Strike: 1% bonus damage for every runic power point (max 25) for Death Strike
            if (spellId == GetSpell(DEATH_STRIKE_1) && me->GetPower(POWER_RUNIC_POWER) >= 10)
            {
                //10 to 250 * 0.001 = 10 to 250 / 1000 = 0.01 to 0.25
                pctbonus += float(std::min<uint32>(me->GetPower(POWER_RUNIC_POWER), 250)) * 0.001f;
            }
            //Glyph of Obliterate: 25% bonus damage for Obliterate
            if (spellId == GetSpell(OBLITERATE_1))
                pctbonus += 0.25f;
            //Bloody Strikes: 15% bonus damage for Blood Strike, 45% for Heart Strike and 30% for Blood Boil
            if (lvl >= 60)
            {
                if (spellId == BLOOD_STRIKE)
                    pctbonus += 0.15f;
                else if (spellId == GetSpell(HEART_STRIKE_1))
                    pctbonus += 0.45f;
                else if (spellId == GetSpell(BLOOD_BOIL_1))
                    pctbonus += 0.3f;
            }
            //Improved Death Strike (part 1): 30% bonus damage for Death Strike
            if (spellId == GetSpell(DEATH_STRIKE_1))
                pctbonus += 0.3f;
            //Merciless Combat (melee): 12% bonus damage for Obliterate on targets with less than 35% hp
            //warning unsafe
            if (lvl >= 67 && spellId == GetSpell(OBLITERATE_1) && damageinfo.target->GetHealthPct() < 35)
                pctbonus += 0.12f;
            //Blood of the North (part 1): 10% bonus damage for Blood Strike and Frost Strike (make Heart strike too)
            if (lvl >= 69 && (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1)/* || spellId == GetSpell(FROST_STRIKE_1)*/))
                pctbonus += 0.1f;
            //Tundra Stalker (melee): 40% damage bonus on targets affected with Frost Fever (20% for bot, regardless of caster)
            //warning unsafe
            if (lvl >= 70 && damageinfo.target->HasAura(FROST_FEVER_AURA))
                pctbonus += 0.2f;
            //Outbreak: 30% bonus damage for Plague Strike and 20% for Scourge Strike
            if (lvl >= 59)
            {
                if (spellId == GetSpell(PLAGUE_STRIKE_1))
                    pctbonus += 0.3f;
                //else if (spellId == GetSpell(SCOURGE_STRIKE_1))
                //    pctbonus += 0.2f;
            }

            damage = int32(fdamage * (1.0f + pctbonus));
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
                //Rime (part 1 spell): 15% additional critical chance for Icy Touch
                if (lvl >= 68 && spellId == GetSpell(ICY_TOUCH_1))
                    aftercrit += 15.f;

                if (aftercrit > 0.f)
                    crit = roll_chance_f(aftercrit);
            }

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (crit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5

                //Guile of Gorefiend (part 1 spell): 45% crit damage bonus for Howling Blast
                if (lvl >= 69 && spellId == GetSpell(HOWLING_BLAST_1))
                    pctbonus += 0.45f / 1.5f;

                //Runic Focus: 50% crit damage bonus for all spells
                pctbonus += 0.5f / 1.5f;
            }

            //Improved Icy Touch: 15% bonus damage for Icy Touch
            if (spellId == GetSpell(ICY_TOUCH_1))
                pctbonus += 0.15f;
            //Increased Icy Touch Damage (id 54800): 111 bonus damage for Icy Touch
            if (spellId == GetSpell(ICY_TOUCH_1))
                fdamage += 111.f;
            //Increased Death Coil Damage (id 54807): 80 bonus damage for Death Coil
            if (spellId == GetSpell(DEATH_COIL_1))
                fdamage += 80.f;
            //Black Ice: 10% bonus damage for all Shadow and Frost spells
            if (lvl >= 58 &&
                ((SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()) ||
                (SPELL_SCHOOL_MASK_SHADOW & spellInfo->GetSchoolMask())))
                pctbonus += 0.1f;
            //Glacier Rot: 20% bonus damage for Icy Touch, Howling Blast and Frost Strike
            //warning unsafe
            if (lvl >= 63 && (spellId == GetSpell(ICY_TOUCH_1) || spellId == GetSpell(HOWLING_BLAST_1)/* || spellId == GetSpell(FROST_STRIKE_1)*/) &&
                damageinfo.target->GetDiseasesByCaster(me->GetGUID()) > 0)
                pctbonus += 0.2f;
            //Merciless Combat (spell): 12% bonus damage for Icy Touch, Howling Blast and Frost Strike on targets with less than 35% hp
            //warning unsafe
            if (lvl >= 67 &&
                (spellId == GetSpell(ICY_TOUCH_1) || spellId == GetSpell(HOWLING_BLAST_1)/* || spellId == GetSpell(FROST_STRIKE_1)*/) &&
                damageinfo.target->GetHealthPct() < 35)
                pctbonus += 0.12f;
            //Tundra Stalker (spell): 40% damage bonus on targets affected with Frost Fever (20% for bot, regardless of caster)
            //warning unsafe
            if (lvl >= 70 && damageinfo.target->HasAura(FROST_FEVER_AURA))
                pctbonus += 0.2f;
            //Morbidity: 15% damage bonus for Death Coil
            if (lvl >= 58 && spellId == GetSpell(DEATH_COIL_1))
                pctbonus += 0.15f;

            //temp
            if (spellId == GetSpell(RUNE_TAP_1))
                pctbonus += 1.f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierEffect(SpellInfo const* spellInfo, uint8 effect_index, float& value) const
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->getLevel();
            float pct_mod = 1.f;

            //Periodic damage bonuses
            if (spellInfo->Effects[effect_index].ApplyAuraName == SPELL_AURA_PERIODIC_DAMAGE)
            {
                //float ticksnum = float(spellInfo->GetMaxDuration() / spellInfo->Effects[effect_index].Amplitude);

                //Increased Plague Strike DoT Damage (id 54802): increased DoT damage by 100
                if (spellId == BLOOD_PLAGUE_AURA)
                    value += 100.f;
                //Glyph of Icy Touch: 20% bonus damage for Frost Fever
                if (spellId == FROST_FEVER_AURA)
                    pct_mod += 0.2f;
                //Black Ice: 10% bonus damage for all Shadow and Frost spells
                if (lvl >= 58 &&
                    ((SPELL_SCHOOL_MASK_FROST & spellInfo->GetSchoolMask()) ||
                    (SPELL_SCHOOL_MASK_SHADOW & spellInfo->GetSchoolMask())))
                    pct_mod += 0.1f;
                //Glyph of Unholy Blight: 40% damage bonus for Unholy Blight (100% for bot)
                if (spellId == UNHOLY_BLIGHT_AURA)
                    pct_mod += 1.f;
            }
            //Heal bonuses
            if (spellInfo->Effects[effect_index].Effect == SPELL_EFFECT_HEAL)
            {
                //Improved Rune Tap: 100% bonus healing from Rune Tap
                if (spellId == GetSpell(RUNE_TAP_1))
                    pct_mod += 1.f;
            }

            value *= pct_mod;
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            //Glyph of Horn of Winter: 1 minute bonus duration (3 for bot)
            if (spellId == GetSpell(HORN_OF_WINTER_1))
            {
                if (Aura* horn = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = horn->GetDuration() + 180000;
                    horn->SetDuration(dur);
                    horn->SetMaxDuration(dur);
                }

                //Winter Veil addition
                if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
                    me->AddAura(44755, target); //snowflakes
            }

            if (target == me)
                return;

            //Epidemic: 10 sec bonus duration for all diseases
            if (spellId == FROST_FEVER_AURA || spellId == BLOOD_PLAGUE_AURA ||
                spellId == CRYPT_FEVER_AURA || spellId == EBON_PLAGUE_AURA)
            {
                if (Aura* fever = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = fever->GetDuration() + 10000;
                    fever->SetDuration(dur);
                    fever->SetMaxDuration(dur);
                }
            }
            //Sudden Doom: 15% ctc Death Coil on Blood Strike or Heart Strike (up to 30% for bot)
            if (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1))
            {
                if (GetSpell(DEATH_COIL_1) && me->getLevel() >= 65 && irand(1,100) <= (me->getLevel() - 50))
                {
                    //debug: dk bot cannot cast without runic power even triggered spells
                    modpower(40);
                    me->CastSpell(target, GetSpell(DEATH_COIL_1), true);
                }
            }
            //Rime (part 2): Obliterate has 15% chance to reset Howling Blast cooldown (25% for bot, screw runes part)
            if (spellId == GetSpell(OBLITERATE_1))
            {
                if (me->getLevel() >= 67 && urand(1,100) <= 25)
                    ResetSpellCooldown(HOWLING_BLAST_1);
            }
            //Chillblains Improved: increase duration by 10 sec (disable on players)
            if (spellId == ICY_CLUTCH)
            {
                if (target->GetTypeId() != TYPEID_PLAYER)
                {
                    if (Aura* chill = target->GetAura(spellId, me->GetGUID()))
                    {
                        uint32 dur = chill->GetDuration() + 10000;
                        chill->SetDuration(dur);
                        chill->SetMaxDuration(dur);
                    }
                }
            }
            //Blood of the North (part 2): Blood Strike and Pestilence convert Blood Rune to Dark Rune (make Heart Strike too)
            if (spellId == BLOOD_STRIKE || spellId == GetSpell(HEART_STRIKE_1) || GetSpell(spellId == PESTILENCE_1))
            {
                if (me->getLevel() >= 69)
                    ConvertRune(RUNE_BLOOD, 1);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            uint32 spellId = spell->Id;

            if (spellId == RUNE_STRIKE_ACIVATION_AURA)
            {
                //Rune Strike activation and timer set
                runestriketimer = 10000;
            }
            if (spellId == GetSpell(ANTI_MAGIC_SHELL_1))
            {
                //Glyph of Anti-Magic Shell: 2 sec increased duration (5 for bot)
                if (Aura* shell = me->GetAura(spellId))
                {
                    uint32 dur = shell->GetDuration() + 5000;
                    shell->SetDuration(dur);
                    shell->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(VAMPIRIC_BLOOD_1))
            {
                //Glyph of Vampiric Blood: 5 sec increased duration
                if (Aura* blood = me->GetAura(spellId))
                {
                    uint32 dur = blood->GetDuration() + 5000;
                    blood->SetDuration(dur);
                    blood->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(BONE_SHIELD_1))
            {
                //Glyph of Bone Shield: 1 bonus charge (2 for bot, 7 for tank)
                if (Aura* bone = me->GetAura(spellId))
                {
                    bone->SetCharges(bone->GetCharges() + (IsTank() ? 3 : 1));
                }
            }
            if (spellId == ICY_TALONS_AURA1 || spellId == ICY_TALONS_AURA2 ||
                spellId == ICY_TALONS_AURA3 || spellId == ICY_TALONS_AURA4 || spellId == ICY_TALONS_AURA5)
            {
                //Icy Talons: Synchronize with Epidemic, add 10 sec duration
                if (Aura* talons = me->GetAura(spellId))
                {
                    uint32 dur = talons->GetDuration() + 10000;
                    talons->SetDuration(dur);
                    talons->SetMaxDuration(dur);
                }
            }
            if (spellId == GetSpell(DEATH_STRIKE_1) || spellId == GetSpell(OBLITERATE_1))
            {
                //Death Rune Mastery: convert Unholy and Frost Runes into Death Runes
                ConvertRune(RUNE_UNHOLY, 1);
                ConvertRune(RUNE_FROST, 1);
            }
            if (spellId == GetSpell(ICEBOUND_FORTITUDE_1))
            {
                //Guile of Gorefiend (part 2): Icebound Fortitude 6 sec increased duration (18 for bot)
                if (Aura* fort = me->GetAura(spellId))
                {
                    uint32 dur = fort->GetDuration() + 18000;
                    fort->SetDuration(dur);
                    fort->SetMaxDuration(dur);
                }
            }

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType)
        {
            if (victim == me)
                return;

            if (damageType == DIRECT_DAMAGE || damageType == SPELL_DIRECT_DAMAGE)
            {
                //Blood Presence Heal
                if (me->HasAura(IMPROVED_BLOOD_PRESENCE_AURA))
                {
                    int32 bp0 = int32(damage / 25); //4%
                    me->CastCustomSpell(me, BLOOD_PRESENCE_HEAL_EFFECT, &bp0, NULL, NULL, true);
                }
            }

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
            presencetimer = 0;
            runicpowertimer = 2000;
            runicpowertimer2 = 5000;
            runestriketimer = 0;
            pestilencetimer = 0;

            Presence = BOT_STANCE_NONE;

            runicpowerIncomeMult = sWorld->getRate(RATE_POWER_RUNICPOWER_INCOME);
            runicpowerLossMult = sWorld->getRate(RATE_POWER_RUNICPOWER_LOSS);
            me->setPowerType(POWER_RUNIC_POWER);
            me->SetMaxPower(POWER_RUNIC_POWER, me->GetCreatePowers(POWER_RUNIC_POWER));            

            DefaultInit();
            InitRunes();
        }

        void ReduceCD(uint32 diff)
        {
            RuneTimers(diff);

            if (presencetimer > diff)               presencetimer -= diff;
            if (runicpowertimer > diff)             runicpowertimer -= diff;
            if (runicpowertimer2 > diff)            runicpowertimer2 -= diff;

            if (runestriketimer > diff)             runestriketimer -= diff;
            else                                    runestriketimer = 0;
            if (pestilencetimer > diff)             pestilencetimer -= diff;
            else                                    pestilencetimer = 0;
        }

        void InitPowers()
        {
            if (master->getLevel() >= 70)
                RefreshAura(RUNIC_POWER_MASTERY,5);
            else if (master->getLevel() >= 58)
                RefreshAura(RUNIC_POWER_MASTERY,4);
            else
            {
                RefreshAura(RUNIC_POWER_MASTERY,0);
                me->SetMaxPower(POWER_RUNIC_POWER, me->GetCreatePowers(POWER_RUNIC_POWER));
            }

            if (runicpower)
                me->SetPower(POWER_RUNIC_POWER, runicpower);
        }

        void InitSpells()
        {
            uint8 lvl = me->getLevel();
            //InitSpellMap(BLOOD_STRIKE_1);
            InitSpellMap(ICY_TOUCH_1);
            InitSpellMap(PLAGUE_STRIKE_1);
            InitSpellMap(DEATH_STRIKE_1);
            InitSpellMap(OBLITERATE_1);
            InitSpellMap(RUNE_STRIKE_1);
  /*Talent*/InitSpellMap(HEART_STRIKE_1);

            InitSpellMap(BLOOD_BOIL_1);
            InitSpellMap(DEATH_AND_DECAY_1);
  /*Talent*/lvl >= 63 ? InitSpellMap(HOWLING_BLAST_1) : RemoveSpell(HOWLING_BLAST_1);

            InitSpellMap(DEATH_COIL_1);
            InitSpellMap(DEATH_GRIP_1, true);
            InitSpellMap(PESTILENCE_1);
            InitSpellMap(MIND_FREEZE_1);
            InitSpellMap(STRANGULATE_1);
            InitSpellMap(CHAINS_OF_ICE_1);
            InitSpellMap(ICEBOUND_FORTITUDE_1);
            InitSpellMap(DARK_COMMAND_1);
            InitSpellMap(ANTI_MAGIC_SHELL_1);
            InitSpellMap(ARMY_OF_THE_DEAD_1);
  /*Talent*/InitSpellMap(LICHBORNE_1, true);
  /*Talent*/lvl >= 60 ? InitSpellMap(HUNGERING_COLD_1) : RemoveSpell(HUNGERING_COLD_1);

            InitSpellMap(PATH_OF_FROST_1);
            InitSpellMap(HORN_OF_WINTER_1);
  /*Talent*/InitSpellMap(RUNE_TAP_1, true);
  /*Talent*/lvl >= 58 ? InitSpellMap(BONE_SHIELD_1) : RemoveSpell(BONE_SHIELD_1);
            InitSpellMap(EMPOWER_RUNE_WEAPON_1);
  /*Talent*/InitSpellMap(MARK_OF_BLOOD_1, true);
  /*Talent*/InitSpellMap(VAMPIRIC_BLOOD_1, true);
  /*Talent*/lvl >= 59 ? InitSpellMap(HYSTERIA_1) : RemoveSpell(HYSTERIA_1);

            InitSpellMap(BLOOD_PRESENCE_1, true);
            InitSpellMap(FROST_PRESENCE_1, true);
            //InitSpellMap(UNHOLY_PRESENCE_1, true);

  /*Custom*/BLOOD_STRIKE = lvl >= 65 ? GetSpell(HEART_STRIKE_1) : InitSpell(me, BLOOD_STRIKE_1);
            InitSpellMap(BLOOD_STRIKE);
        }

        void ApplyClassPassives()
        {
            uint8 level = master->getLevel();

            RefreshAura(GLYPH_OF_CHAINS_OF_ICE, level >= 58 ? 1 : 0);
            RefreshAura(CHAINS_OF_ICE_FROST_RUNE_REFRESH, level >= 80 ? 4 : level >= 77 ? 3 : level >= 68 ? 2 : level >= 58 ? 1 : 0);
            RefreshAura(GLYPH_OF_HEART_STRIKE, level >= 65 ? 1 : 0);
            RefreshAura(GLYPH_OF_RUNE_TAP, level >= 68 ? 2 : level >= 60 ? 1 : 0);
            RefreshAura(GLYPH_OF_HOWLING_BLAST, level >= 63 ? 1 : 0);
            RefreshAura(BUTCHERY, level >= 57 ? 1 : 0);
            RefreshAura(SCENT_OF_BLOOD, level >= 58 ? 1 : 0);
            RefreshAura(VENDETTA, level >= 59 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE3, level >= 65 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE2, level >= 60 && level < 65 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE1, level >= 57 && level < 60 ? 1 : 0);
            RefreshAura(ABOMINATIONS_MIGHT, level >= 60 ? 1 : 0);
            RefreshAura(IMPROVED_BLOOD_PRESENCE, level >= 67 ? 1 : 0);
            RefreshAura(BLOODWORMS, level >= 65 ? 2 : 0);
            //RefreshAura(IMPROVED_DEATH_STRIKE, level >= 66 ? 1 : 0);
            RefreshAura(TOUGHNESS, level >= 57 ? 1 : 0);
            RefreshAura(ANNIHILATION, level >= 57 ? 1 : 0);
            RefreshAura(ICY_TALONS, level >= 60 ? 1 : 0);
            RefreshAura(CHILL_OF_THE_GRAVE, level >= 68 ? 2 : level >= 58 ? 1 : 0);
            RefreshAura(IMPROVED_ICY_TALONS, level >= 64 ? 1 : 0);
            RefreshAura(CHILBLAINS, level >= 68 ? 1 : 0);
            RefreshAura(ACCLIMATION, level >= 69 ? 1 : 0);
            RefreshAura(NECROSIS5, level >= 63 ? 1 : 0);
            RefreshAura(NECROSIS4, level >= 62 && level < 63 ? 1 : 0);
            RefreshAura(NECROSIS3, level >= 61 && level < 62 ? 1 : 0);
            RefreshAura(NECROSIS2, level >= 60 && level < 61 ? 1 : 0);
            RefreshAura(NECROSIS1, level >= 59 && level < 60 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE3, level >= 65 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE2, level >= 62 && level < 65 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE1, level >= 60 && level < 62 ? 1 : 0);
            RefreshAura(DIRGE, level >= 67 ? 2 : level >= 61 ? 1 : 0);
            RefreshAura(UNHOLY_BLIGHT, level >= 61 ? 1 : 0);
            RefreshAura(DESECRATION, level >= 62 ? 1 : 0);
            RefreshAura(CRYPT_FEVER, level >= 64 ? 1 : 0);
            RefreshAura(EBON_PLAGUEBRINGER, level >= 68 ? 1 : 0);
            RefreshAura(WANDERING_PLAGUE, level >= 67 ? 1 : 0);

            RefreshAura(FROST_FEVER);
            RefreshAura(BLOOD_PLAGUE);
        }

        bool CanUseManually(uint32 basespell) const
        {
            switch (basespell)
            {
                case LICHBORNE_1:
                case PATH_OF_FROST_1:
                case HORN_OF_WINTER_1:
                case BONE_SHIELD_1:
                case RUNE_TAP_1:
                case EMPOWER_RUNE_WEAPON_1:
                case VAMPIRIC_BLOOD_1:
                case HYSTERIA_1:
                    return true;
                default:
                    return false;
            }
        }

    private:
        uint32 BLOOD_STRIKE;
/*tmrs*/uint32 presencetimer, runicpowertimer, runicpowertimer2, runestriketimer, pestilencetimer;
/*misc*/uint32 runicpower;
/*misc*/float runicpowerIncomeMult, runicpowerLossMult;
/*Chck*/uint8 Presence;

        BotRunes _runes;

        enum DeathKnightBaseSpells
        {
            BLOOD_STRIKE_1                      = 45902,
            ICY_TOUCH_1                         = 45477,
            PLAGUE_STRIKE_1                     = 45462,
            DEATH_STRIKE_1                      = 49998,
            OBLITERATE_1                        = 49020,
            RUNE_STRIKE_1                       = 56815,
            HEART_STRIKE_1                      = 55050,

            BLOOD_BOIL_1                        = 48721,
            DEATH_AND_DECAY_1                   = 43265,
            HOWLING_BLAST_1                     = 49184,

            DEATH_COIL_1                        = 47541,
            DEATH_GRIP_1                        = 49576,
            PESTILENCE_1                        = 50842,
            MIND_FREEZE_1                       = 47528,
            STRANGULATE_1                       = 47476,
            CHAINS_OF_ICE_1                     = 45524,
            ICEBOUND_FORTITUDE_1                = 48792,
            DARK_COMMAND_1                      = 56222,
            ANTI_MAGIC_SHELL_1                  = 48707,
            ARMY_OF_THE_DEAD_1                  = 42650,
            LICHBORNE_1                         = 49039,
            HUNGERING_COLD_1                    = 49203,

            PATH_OF_FROST_1                     = 3714,
            HORN_OF_WINTER_1                    = 57330,
            BONE_SHIELD_1                       = 49222,
            RUNE_TAP_1                          = 48982,
            EMPOWER_RUNE_WEAPON_1               = 47568,
            MARK_OF_BLOOD_1                     = 49005,
            VAMPIRIC_BLOOD_1                    = 55233,
            HYSTERIA_1                          = 49016,

            BLOOD_PRESENCE_1                    = 48266,
            FROST_PRESENCE_1                    = 48263
            //UNHOLY_PRESENCE_1                   = 48265
        };
        enum DeathKnightPassives
        {
        //Talents
            BUTCHERY                            = 49483,//rank 2
            SCENT_OF_BLOOD                      = 49509,//rank 3
            VENDETTA                            = 55136,//rank 3
            BLOODY_VENGEANCE1                   = 48988,
            BLOODY_VENGEANCE2                   = 49503,
            BLOODY_VENGEANCE3                   = 49504,
            ABOMINATIONS_MIGHT                  = 53138,//rank 2
            IMPROVED_BLOOD_PRESENCE             = 50371,//rank 2
            BLOODWORMS                          = 49543,//rank 3
            IMPROVED_DEATH_STRIKE               = 62908,//rank 2
            TOUGHNESS                           = 49789,//rank 5
            ANNIHILATION                        = 51473,//rank 3
            ICY_TALONS                          = 50887,//rank 5
            CHILL_OF_THE_GRAVE                  = 50115,//rank 2
            IMPROVED_ICY_TALONS                 = 55610,
            CHILBLAINS                          = 50043,//rank 3
            ACCLIMATION                         = 50152,//rank 3
            NECROSIS1                           = 51459,
            NECROSIS2                           = 51462,
            NECROSIS3                           = 51463,
            NECROSIS4                           = 51464,
            NECROSIS5                           = 51465,
            BLOOD_CAKED_BLADE1                  = 49219,
            BLOOD_CAKED_BLADE2                  = 49627,
            BLOOD_CAKED_BLADE3                  = 49628,
            DIRGE                               = 51206,//rank 2
            UNHOLY_BLIGHT                       = 49194,
            DESECRATION                         = 55667,//rank 2
            CRYPT_FEVER                         = 49632,//rank 3
            EBON_PLAGUEBRINGER                  = 51161,//rank 3
            WANDERING_PLAGUE                    = 49655,//rank 3
        //Special
  /*Talent*/RUNIC_POWER_MASTERY                 = 50147,//rank 2
            FROST_FEVER                         = 59921,
            BLOOD_PLAGUE                        = 59879,
        //Other
            GLYPH_OF_CHAINS_OF_ICE              = 58620,//damage proc
            CHAINS_OF_ICE_FROST_RUNE_REFRESH    = 62459,//5 runic power gain
            GLYPH_OF_HEART_STRIKE               = 58616,//snare 50% for 10 sec
            GLYPH_OF_RUNE_TAP                   = 59327,//10% heal for party
            GLYPH_OF_HOWLING_BLAST              = 63335 //frost fever on targets
        };
        enum DeathKnightSpecial
        {
            FROST_FEVER_AURA                    = 55095,
            BLOOD_PLAGUE_AURA                   = 55078,
            CRYPT_FEVER_AURA                    = 50510,//rank 3
            EBON_PLAGUE_AURA                    = 51735,//rank 3

            RUNE_STRIKE_ACIVATION_AURA          = 56817,

            IMPROVED_BLOOD_PRESENCE_AURA        = 63611,
            BLOOD_PRESENCE_HEAL_EFFECT          = 50475,
            BLADE_BARRIER_AURA                  = 64859,//rank 5
            UNHOLY_BLIGHT_AURA                  = 50536,

            ICY_TALONS_AURA1                    = 50882,//rank 1
            ICY_TALONS_AURA2                    = 58575,//rank 2
            ICY_TALONS_AURA3                    = 58576,//rank 3
            ICY_TALONS_AURA4                    = 58577,//rank 4
            ICY_TALONS_AURA5                    = 58578,//rank 5

            DEATH_COIL_ENEMY                    = 47632,
            ICY_CLUTCH                          = 50436 //rank 3 Chilblains proc
        };
        //enum RunePlacing
        //{
        //    RUNE_BLOOD_FIRST,
        //    RUNE_BLOOD_SECOND,
        //    RUNE_UNHOLY_FIRST,
        //    RUNE_UNHOLY_SECOND,
        //    RUNE_FROST_FIRST,
        //    RUNE_FROST_SECOND,
        //    NO_RUNE
        //};
    };
};

void AddSC_death_knight_bot()
{
    new death_knight_bot();
}
