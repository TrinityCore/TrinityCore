#include "bot_ai.h"
#include "botmgr.h"
#include "Group.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
/*
Warlock NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - 85%
TODO: rituals (not directly feasable), demonic circle, demonic empowerment, demonic pact, health funnel, healthstones for bots, etc...
*/

enum WarlockBaseSpells
{
    CURSE_OF_WEAKNESS_1                 = 702,
    CURSE_OF_AGONY_1                    = 980,
    CURSE_OF_TONGUES_1                  = 1714,
    CURSE_OF_EXHAUSTION_1               = 18223,
    CURSE_OF_THE_ELEMENTS_1             = 1490,
    CURSE_OF_DOOM_1                     = 603,//NI
    SHADOW_BOLT_1                       = 686,
    IMMOLATE_1                          = 348,
    CORRUPTION_1                        = 172,
    SEED_OF_CORRUPTION_1                = 27243,
    INCINERATE_1                        = 29722,
    SEARING_PAIN_1                      = 5676,
    SHADOWBURN_1                        = 17877,
    CONFLAGRATE_1                       = 17962,
    SOUL_FIRE_1                         = 6353,
    CHAOS_BOLT_1                        = 50796,
    RAIN_OF_FIRE_1                      = 5740,
    HELLFIRE_1                          = 1949,
    SHADOWFLAME_1                       = 47897,
    SHADOWFURY_1                        = 30283,
    HAUNT_1                             = 48181,
    UNSTABLE_AFFLICTION_1               = 30108,//NI
    FEAR_1                              = 5782,
    HOWL_OF_TERROR_1                    = 5484,
    DEATH_COIL_1                        = 6789,
    SOULSHATTER_1                       = 29858,

    DRAIN_SOUL_1                        = 1120,
    DRAIN_MANA_1                        = 5138,
    BANISH_1                            = 710,

    DEMON_SKIN_1                        = 687,
    DEMON_ARMOR_1                       = 706,
    FEL_ARMOR_1                         = 28176,
    DETECT_INVISIBILITY_1               = 132,
    UNENDING_BREATH_1                   = 5697,
    SHADOW_WARD_1                       = 6229,
    LIFE_TAP_1                          = 1454,
    DARK_PACT_1                         = 18220,

    CREATE_HEALTHSTONE_1                = 6201,
    CREATE_SOULSTONE_1                  = 693,

    CHAOTIC_MIND                        = 61188, //8 sec duration, no cd

    RITUAL_OF_SUMMONING_1               = 698,
    RITUAL_OF_SOULS_1                   = 29893
};
enum WarlockPassives
{
    IMPROVED_SHADOW_BOLT                = 17803,//rank 5
    IMPROVED_DRAIN_SOUL                 = 18372,//rank 2
    SOUL_SIPHON                         = 17805,//rank 2
    AFTERMATH                           = 18120,//rank 2
    IMPROVED_FEAR                       = 53759,//rank 2
    NIGHTFALL                           = 18095,//rank 2
    SHADOW_EMBRACE                      = 32394,//rank 5
    SIPHON_LIFE                         = 63108,
    BACKLASH                            = 34939,//rank 3
    MOLTEN_CORE                         = 47247,//rank 3
    NETHER_PROTECTION                   = 30302,//rank 3
    ERADICATION                         = 47197,//rank 3
    DEMONIC_RESILIENCE                  = 30321,//rank 3
    SOUL_LEECH                          = 30296,//rank 3
    PYROCLASM                           = 63245,//rank 3
    DECIMATION                          = 63158,//rank 2
    IMPROVED_SOUL_LEECH                 = 54118,//rank 2
    PANDEMIC                            = 58435,
    BACKDRAFT                           = 47260,//rank 3
    EVERLASTING_AFFLICTION              = 47205,//rank 5

    //Special
    GLYPH_CORRUPTION                    = 56218,
    GLYPH_FEAR                          = 56244,
    GLYPH_QUICK_DECAY                   = 70947,
    GLYPH_CONFLAGRATE                   = 56235,
    GLYPH_SHADOWFLAME                   = 63310
};

enum WarlockSpecial
{
    CHAOS_BOLT_PASSIVE                  = 58284,
    DEMONIC_IMMOLATE_PASSIVE            = 75445,

    BACKLASH_BUFF                       = 34936,
    BACKDRAFT_BUFF                      = 54277,//rank 3
    SHADOW_TRANCE_BUFF                  = 17941,
    MOLTEN_CORE_BUFF                    = 71165,//rank 3
    DECIMATION_BUFF                     = 63167,//rank 2
    CHAOTIC_MIND_BUFF                   = 61189,// "Soul Fire!" 6 sec duration Soul Fire instant cast

    SHADOW_MASTERY_DEBUFF               = 17800,// Improved Shadow Bolt talent debuff

    SIPHON_LIFE_HEAL                    = 63106,
    LIFE_TAP_ENERGIZE                   = 31818,

    SEED_OF_CORRUPTION_FINAL_DAMAGE_1   = 27285,

    SOULSTONE_RESURRECTION_1            = 20707,
    SOULSTONE_RESURRECTION_2            = 20762,
    SOULSTONE_RESURRECTION_3            = 20763,
    SOULSTONE_RESURRECTION_4            = 20764,
    SOULSTONE_RESURRECTION_5            = 20765,
    SOULSTONE_RESURRECTION_6            = 27239,
    SOULSTONE_RESURRECTION_7            = 47883,

    BLOOD_PACT_1                        = 6307,
    FEL_INTELLIGENCE_1                  = 54424,

    SOUL_LINK_PET                       = 25228,//split effect lvl 20 req
    FEL_SYNERGY_HEAL                    = 54181,
    LIFE_TAP_ENERGIZE_PET               = 32553
};

class warlock_bot : public CreatureScript
{
public:
    warlock_bot() : CreatureScript("warlock_bot") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new warlock_botAI(creature);
    }
/*
    bool OnGossipHello(Player* player, Creature* creature)
    {
        return creature->GetBotAI()->OnGossipHello(player, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }
*/
    struct warlock_botAI : public bot_ai
    {
        static uint32 const _healthStoneSpells[8/*createHealthstoneRank*/];

        warlock_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_WARLOCK;
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        void JustEnteredCombat(Unit* u) override { canShadowWard = false; bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(); bot_ai::JustDied(u); }
        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting() || Feasting() || Rand() > 20)
                return;

            if (GetSpell(FEL_ARMOR_1) && !IsTank())
            {
                if (!me->GetAuraEffect(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT, SPELLFAMILY_WARLOCK, 0x0, 0x20000000, 0x0)
                    /*!HasAuraName(me, FEL_ARMOR_1)*/ &&
                    doCast(me, GetSpell(FEL_ARMOR_1)))
                    return;
            }
            else if (GetSpell(DEMON_ARMOR_1))
            {
                if (!me->GetAuraEffect(SPELL_AURA_MOD_RESISTANCE, SPELLFAMILY_WARLOCK, 0x0, 0x20, 0x0)
                    /*!HasAuraName(me, DEMON_ARMOR_1)*/ &&
                    doCast(me, GetSpell(DEMON_ARMOR_1)))
                    return;
            }
            else if (!GetSpell(FEL_ARMOR_1) && !GetSpell(DEMON_ARMOR_1) && GetSpell(DEMON_SKIN_1))
            {
                if (!me->GetAuraEffect(SPELL_AURA_MOD_RESISTANCE, SPELLFAMILY_WARLOCK, 0x0, 0x0, 0x10)
                    /*!HasAuraName(me, DEMON_SKIN_1)*/ &&
                    doCast(me, GetSpell(DEMON_SKIN_1)))
                    return;
            }

            if (me->GetVictim())
                return;

            if (!hasHealthstone && GetSpell(CREATE_HEALTHSTONE_1))
            {
                if (doCast(me, GetSpell(CREATE_HEALTHSTONE_1)))
                    return;
            }

            if (!hasSoulstone && GetSpell(CREATE_SOULSTONE_1))
            {
                if (doCast(me, GetSpell(CREATE_SOULSTONE_1)))
                    return;
            }

            if (GetSpell(DETECT_INVISIBILITY_1))
            {
                if (master->IsAlive() && !master->HasAuraType(SPELL_AURA_MOD_INVISIBILITY_DETECT) &&
                    doCast(master, GetSpell(DETECT_INVISIBILITY_1)))
                    return;
            }

            //TODO: soulstone on self/bots
            if (!IAmFree() && hasSoulstone && soulstoneTimer <= diff && GetSpell(CREATE_SOULSTONE_1))
            {
                Group const* gr = master->GetGroup();
                Unit* u = master;
                if (!gr)
                {
                    if (!u->IsAlive() || u->isPossessed() || u->IsCharmed() ||
                        me->GetDistance(u) > 30 || u->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 92, 0))
                        u = nullptr;
                }
                else
                {
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        u = itr->GetSource();
                        if (!u || u->GetLevel() < 18 || !u->IsAlive() || me->GetMap() != u->FindMap() ||
                            u->isPossessed() || u->IsCharmed() || me->GetDistance(u) > 30 ||
                            u->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 92, 0))
                        {
                            u = nullptr;
                            continue;
                        }
                        if (u->GetClass() == CLASS_PRIEST || u->GetClass() == CLASS_PALADIN ||
                            u->GetClass() == CLASS_DRUID || u->GetClass() == CLASS_SHAMAN)
                            break;
                    }
                    if (!u)
                    {
                        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                        {
                            u = itr->GetSource();
                            if (!u || u->GetLevel() < 18 || !u->IsAlive() || me->GetMap() != u->FindMap() ||
                                u->isPossessed() || u->IsCharmed() || me->GetDistance(u) > 30 ||
                                u->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 92, 0))
                            {
                                u = nullptr;
                                continue;
                            }
                            break;
                        }
                    }
                }

                if (u)
                {
                    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(CREATE_SOULSTONE_1);
                    uint32 rank = spellInfo->GetRank();

                    while (rank < 7 && u->GetLevel() > spellInfo->SpellLevel && spellInfo->GetNextRankSpell())
                    {
                        spellInfo = spellInfo->GetNextRankSpell();
                        rank = spellInfo->GetRank();
                    }

                    uint32 spellId;
                    switch (spellInfo->Id)
                    {
                        case   693: spellId = SOULSTONE_RESURRECTION_1; break; //rank 1
                        case 20752: spellId = SOULSTONE_RESURRECTION_2; break; //rank 2
                        case 20755: spellId = SOULSTONE_RESURRECTION_3; break; //rank 3
                        case 20756: spellId = SOULSTONE_RESURRECTION_4; break; //rank 4
                        case 20757: spellId = SOULSTONE_RESURRECTION_5; break; //rank 5
                        case 27238: spellId = SOULSTONE_RESURRECTION_6; break; //rank 6
                        case 47884: spellId = SOULSTONE_RESURRECTION_7; break; //rank 7
                        default:
                            TC_LOG_ERROR("entities.player", "bot_warlockAI: unknown soulstone Id %u", spellInfo->Id);
                            spellId = SOULSTONE_RESURRECTION_1;
                            break;
                    }
                    me->CastSpell(u, spellId, false);
                }
            }
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (GetBotCommandState() == COMMAND_ATTACK && !force) return;
            SetBotCommandState(COMMAND_ATTACK);
            OnStartAttack(u);
            GetInPosition(force, u);
            fearTimer = std::max<uint32>(fearTimer, 1000);
        }

        //uint8 Afflicted(Unit* target) const
        //{
        //    if (!target || target->isDead()) return 0;
        //    bool aff = HasAuraName(target, UNSTABLE_AFFLICTION_1, me->GetGUID());
        //    bool imm = HasAuraName(target, IMMOLATE_1, me->GetGUID());
        //    if (imm) return 1;
        //    if (aff) return 2;
        //    return 0;
        //}

        void CheckFear(uint32 diff)
        {
            if (fearTimer > diff || GC_Timer > diff || !me->IsInCombat() || IsTank() || IsCasting())
                return;

            fearTimer = 1600;

            uint32 FEAR = GetSpell(FEAR_1);
            if (!FEAR)
                return;

            if (FindAffectedTarget(FEAR, me->GetGUID(), 70, 255))
                return;

            Unit* feartarget = FindFearTarget(CalcSpellMaxRange(FEAR_1));
            if (feartarget && doCast(feartarget, FEAR))
                return;
        }

        void CheckBanish(uint32 diff)
        {
            if (banishTimer > diff || GC_Timer > diff || !me->IsInCombat() || IsTank() || IsCasting() || Rand() > 50)
                return;

            banishTimer = 1600;

            uint32 BANISH = GetSpell(BANISH_1);
            if (!BANISH)
                return;

            if (FindAffectedTarget(BANISH, me->GetGUID(), 70, 255))
                return;

            Unit* banishTarget = FindUndeadCCTarget(CalcSpellMaxRange(BANISH_1), BANISH_1);
            if (banishTarget && doCast(banishTarget, BANISH))
                return;
        }

        void CheckUnBanish(uint32 diff)
        {
            if (unbanishTimer > diff || GC_Timer > diff || me->GetVictim() || IsCasting() || Rand() > 30)
                return;

            unbanishTimer = 2000;

            //we check only our spell rank which is enough in 99% cases
            uint32 BANISH = GetSpell(BANISH_1);
            if (!BANISH)
                return;

            //looks like you cannot dispel other people's banish
            Unit* unbanishTarget = FindAffectedTarget(BANISH, me->GetGUID(), CalcSpellMaxRange(BANISH_1));
            if (unbanishTarget && doCast(unbanishTarget, BANISH))
                return;
        }

        void CheckDrainMana(uint32 diff)
        {
            if (drainManaTimer > diff || IsPotionReady() || !IsSpellReady(DRAIN_MANA_1, diff) ||
                !me->getAttackers().empty() || IsTank() || IsCasting() || GetManaPCT(me) > 25 || Rand() > 60)
                return;

            drainManaTimer = 1000;

            //1 case: feared mana pot running around
            Unit* drainTarget = FindDrainTarget(CalcSpellMaxRange(DRAIN_MANA_1));

            if (!drainTarget)
            {
                Unit* u = me->GetVictim();
                if (u && u->GetPowerType() == POWER_MANA && u->GetMaxPower(POWER_MANA) >= me->GetMaxPower(POWER_MANA) &&
                    GetManaPCT(u) >= 15 && me->GetDistance(u) < CalcSpellMaxRange(DRAIN_MANA_1))
                    drainTarget = u;
            }

            if (drainTarget && doCast(drainTarget, GetSpell(DRAIN_MANA_1)))
                return;
        }

        void CheckWard(uint32 diff)
        {
            if (!canShadowWard || (!me->IsInCombat() && !me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE)) ||
                !IsSpellReady(SHADOW_WARD_1, diff) || IsCasting())
                return;

            if (doCast(me, GetSpell(SHADOW_WARD_1)))
                return;
        }

        void CheckSoulShatter(uint32 diff)
        {
            if (!IsSpellReady(SOULSHATTER_1, diff) || me->getAttackers().empty() || Rand() < 80)
                return;

            Unit* u = *(me->getAttackers().begin());
            if (u->GetThreatManager().GetThreatListSize() < 3 || u->GetThreatManager().GetThreat(me) < 100.f)
                return;

            if (doCast(me, GetSpell(SOULSHATTER_1)))
                return;
        }

        void Counter(uint32 diff)
        {
            if (GC_Timer > diff || IsCasting() || Rand() > 25)
                return;

            bool busyCasting = me->IsNonMeleeSpellCast(true,true,true);

            //Fear
            if (!busyCasting && IsSpellReady(FEAR_1, diff))
            {
                Unit* u = FindCastingTarget(CalcSpellMaxRange(FEAR_1), 0, FEAR_1);
                if (u && doCast(u, GetSpell(FEAR_1)))
                    return;
            }
            //Howl of Terror (only instant cast)
            if (!busyCasting && me->GetLevel() >= 45 && IsSpellReady(HOWL_OF_TERROR_1, diff))
            {
                Unit* u = FindCastingTarget(8, 0, FEAR_1); //same immunity
                if (u && doCast(u, GetSpell(HOWL_OF_TERROR_1)))
                    return;
            }
            //Shadowfury
            if (HasRole(BOT_ROLE_DPS) && IsSpellReady(SHADOWFURY_1, diff))
            {
                if (Unit* u = FindCastingTarget(CalcSpellMaxRange(SHADOWFURY_1), 0, SHADOWFURY_1))
                {
                    if (busyCasting)
                        me->InterruptNonMeleeSpells(true);
                    if (doCast(u, GetSpell(SHADOWFURY_1)))
                        return;
                }
            }
             //Death Coil
            if (HasRole(BOT_ROLE_DPS) && IsSpellReady(DEATH_COIL_1, diff))
            {
                if (Unit* u = FindCastingTarget(CalcSpellMaxRange(DEATH_COIL_1), 0, DEATH_COIL_1))
                {
                    if (busyCasting)
                        me->InterruptNonMeleeSpells(true);
                    if (doCast(u, GetSpell(DEATH_COIL_1)))
                        return;
                }
            }
        }

        void DoDefend(uint32 diff)
        {
            if (GC_Timer > diff || !me->IsInCombat() || Rand() > 120)
                return;

            Unit::AttackerSet m_attackers = master->getAttackers();
            Unit::AttackerSet b_attackers = me->getAttackers();
            bool needFearM = !IAmFree() && !m_attackers.empty() && (!IsTank(master) || GetHealthPCT(master) < 75);

            //HOWL
            //fear master's attackers
            if (IsSpellReady(HOWL_OF_TERROR_1, diff))
            {
                if (needFearM)
                {
                    uint8 tCount = 0;
                    for (Unit::AttackerSet::iterator iter = m_attackers.begin(); iter != m_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if (CCed(*iter, true)) continue;
                        if ((*iter)->ToCreature() && (*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetDistance(*iter) > 9) continue;
                        if (me->IsValidAttackTarget(*iter))
                            ++tCount;
                    }
                    if (tCount > 1 && doCast(me, GetSpell(HOWL_OF_TERROR_1)))
                        return;
                }
                // Defend myself
                if (!b_attackers.empty())
                {
                    uint8 tCount = 0;
                    for (Unit::AttackerSet::iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
                    {
                        if (!(*iter)) continue;
                        if (CCed(*iter, true)) continue;
                        if ((*iter)->ToCreature() && (*iter)->GetCreatureType() == CREATURE_TYPE_UNDEAD) continue;
                        if (me->GetDistance(*iter) > 9) continue;
                        if (me->IsValidAttackTarget(*iter))
                            ++tCount;
                    }
                    if (tCount > 1 && doCast(me, GetSpell(HOWL_OF_TERROR_1)))
                        return;
                }
            }
            //COIL
            if (HasRole(BOT_ROLE_DPS) && IsSpellReady(DEATH_COIL_1, diff))
            {
                Unit* u = needFearM ? *(m_attackers.begin()) : nullptr;
                if (u && u->GetMaxHealth() > master->GetMaxHealth() * 2 &&
                    u->GetDistance(me) < 30)
                {
                    if (doCast(u, GetSpell(DEATH_COIL_1)))
                        return;
                }
                u = !b_attackers.empty() ? *(b_attackers.begin()) : nullptr;
                if (u && u->GetMaxHealth() > me->GetMaxHealth() * 2 && u->GetDistance(me) < 8)
                {
                    if (doCast(u, GetSpell(DEATH_COIL_1)))
                        return;
                }
            }
        }

        bool BuffTarget(Unit* target, uint32 diff) override
        {
            if (target->GetTypeId() != TYPEID_PLAYER) return false;
            if (me->IsInCombat() && !master->GetMap()->IsRaid()) return false;

            if (GetSpell(UNENDING_BREATH_1) && target->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) &&
                !target->HasAuraType(SPELL_AURA_WATER_BREATHING))
            {
                if (doCast(target, GetSpell(UNENDING_BREATH_1)))
                    return true;
            }

            return false;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            //pet is killed or unreachable
            if (GC_Timer <= diff && !me->IsInCombat() && !me->IsMounted() && !me->GetVictim() && !IsCasting() && Rand() < 25 &&
                (!botPet || me->GetDistance2d(botPet) > sWorld->GetMaxVisibleDistanceOnContinents()))
                SummonBotPet();

            //Hellfire interrupt
            Spell const* spell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
            if (spell && spell->GetSpellInfo()->GetFirstRankSpell()->Id == HELLFIRE_1 &&
                ((!IAmFree() && !master->GetBotMgr()->IsPartyInCombat()) || GetHealthPCT(me) < 25))
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
            else
            {
                spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL);
                if (spell)
                {
                    //Fear interrupt
                    if (spell->GetSpellInfo()->GetFirstRankSpell()->Id == FEAR_1 && spell->m_targets.GetUnitTarget() &&
                        spell->m_targets.GetUnitTarget()->HasAuraType(SPELL_AURA_MOD_FEAR))
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    //Banish interrupt
                    else if (spell->GetSpellInfo()->GetFirstRankSpell()->Id == BANISH_1 && spell->m_targets.GetUnitTarget())
                    {
                        if (AuraEffect const* bani = spell->m_targets.GetUnitTarget()->GetAuraEffect(SPELL_AURA_SCHOOL_IMMUNITY, SPELLFAMILY_WARLOCK, 0x0, 0x8000000, 0x0))
                        {
                            //Already banished
                            //check spell cast time
                            if (bani->GetBase()->GetDuration() > bani->GetBase()->GetMaxDuration() - 1500)
                                me->InterruptSpell(CURRENT_GENERIC_SPELL);
                        }
                        else if (!spell->m_targets.GetUnitTarget()->getAttackers().empty())
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    }
                    //Soulstone resurrection interrupt
                    else if (spell->GetSpellInfo()->SpellVisual[0] == 99 && spell->m_targets.GetUnitTarget() &&
                        spell->m_targets.GetUnitTarget()->GetDummyAuraEffect(SPELLFAMILY_GENERIC, 92, 0))
                        me->InterruptSpell(CURRENT_GENERIC_SPELL);
                }
            }

            if (hasHealthstone && healthstoneTimer <= diff &&
                /*GetSpell(CREATE_HEALTHSTONE_1) && */!IsCasting() && GetHealthPCT(me) < 65)
            {
                uint32 healthStone = InitSpell(me, CREATE_HEALTHSTONE_1);
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(healthStone);
                //ASSERT(spellInfo);
                uint32 rank = spellInfo->GetRank();
                //ASSERT(rank >= 1 && rank <= 8);
                spellInfo = sSpellMgr->GetSpellInfo(_healthStoneSpells[rank - 1]);
                ASSERT(spellInfo);
                int32 healing = spellInfo->Effects[0].BasePoints;
                //Glyph of Healthstone
                if (me->GetLevel() >= 15)
                    healing = int32(float(healing) * 1.3f);
                CastSpellExtraArgs args(true);
                args.AddSpellBP0(healing);
                me->CastSpell(me, _healthStoneSpells[rank - 1], args);
                healthstoneTimer = 120000; //2 min
                hasHealthstone = false;
                return;
            }
            else if (IsPotionReady() && GetHealthPCT(me) < 50)
            {
                DrinkPotion(false);
            }

            if (IsSpellReady(DARK_PACT_1, diff) && !IsCasting() && botPet && botPet->GetPower(POWER_MANA) >= 300 &&
                GetManaPCT(me) < 20)
            {
                //it is possible that CheckCast will return SPELL_FAILED_NO_POWER if not enough hp
                if (doCast(me, GetSpell(DARK_PACT_1)))
                    return;
            }
            else if (IsSpellReady(LIFE_TAP_1, diff) && !IsCasting() && GetHealthPCT(me) > (me->IsInCombat() ? 30 : 15) &&
                GetManaPCT(me) < 15 && Rand() < 50)
            {
                //it is possible that CheckCast will return SPELL_FAILED_NO_POWER if not enough hp
                if (doCast(me, GetSpell(LIFE_TAP_1)))
                    return;
            }
            else if (IsPotionReady() && GetManaPCT(me) < 10)
            {
                DrinkPotion(true);
            }

            CheckRacials(diff);

            CheckSoulShatter(diff);
            DoDefend(diff);
            CheckFear(diff);
            CheckWard(diff);

            BuffAndHealGroup(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            Counter(diff);

            CheckBanish(diff);
            CheckUnBanish(diff);

            CheckDrainMana(diff);

            if (!CheckAttackTarget())
                return;

            if (IsCasting())
                return;

            DoNormalAttack(diff);
        }

        void DoNormalAttack(uint32 diff)
        {
            StartAttack(opponent, IsMelee());

            if (GC_Timer > diff)
                return;

            if (!CanAffectVictim(SPELL_SCHOOL_MASK_SHADOW|SPELL_SCHOOL_MASK_FIRE))
                return;

            float dist = me->GetDistance(opponent);

            //spell reflections
            if (IsSpellReady(CURSE_OF_THE_ELEMENTS_1, diff) && dist < CalcSpellMaxRange(CURSE_OF_THE_ELEMENTS_1) &&
                CanRemoveReflectSpells(opponent, CURSE_OF_THE_ELEMENTS_1) &&
                doCast(opponent, CURSE_OF_THE_ELEMENTS_1))
                return;
            else if (IsSpellReady(CURSE_OF_WEAKNESS_1, diff) && dist < CalcSpellMaxRange(CURSE_OF_WEAKNESS_1) &&
                CanRemoveReflectSpells(opponent, CURSE_OF_WEAKNESS_1) &&
                doCast(opponent, CURSE_OF_WEAKNESS_1))
                return;

            //Offensive heal (Death Coil)
            if (IsSpellReady(DEATH_COIL_1, diff) && HasRole(BOT_ROLE_DPS) && dist < CalcSpellMaxRange(DEATH_COIL_1) &&
                GetHealthPCT(me) < 35)
            {
                //if (me->IsNonMeleeSpellCast(true))
                //    me->InterruptNonMeleeSpells(true);
                if (doCast(opponent, GetSpell(DEATH_COIL_1)))
                    return;
            }

            //Shadowfury
            if (IsSpellReady(SHADOWFURY_1, diff) && HasRole(BOT_ROLE_DPS) && !CCed(opponent, true) && Rand() < 55)
            {
                if (FindSplashTarget(CalcSpellMaxRange(SHADOWFURY_1)) &&
                    doCast(opponent, GetSpell(SHADOWFURY_1)))
                    return;
            }
            //Hellfire
            if (IsSpellReady(HELLFIRE_1, diff) && HasRole(BOT_ROLE_DPS) && !IAmFree() && !JumpingOrFalling() &&
                GetHealthPCT(me) > 90 && Rand() < 25)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 12.f, 0);
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end();)
                {
                    Unit* u = *itr;
                    bool erase = false;
                    if (u->isMoving())
                    {
                        if (me->GetDistance(u) > 10.f && !u->HasInArc(M_PI/2, me))
                            erase = true;
                    }
                    else if (me->GetDistance(u) > 9.5f)
                        erase = true;

                    if (erase)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                    ++itr;
                }
                if (targets.size() >= 4 && doCast(me, GetSpell(HELLFIRE_1)))
                    return;
            }
            //Rain of Fire
            if (IsSpellReady(RAIN_OF_FIRE_1, diff) && HasRole(BOT_ROLE_DPS) && !JumpingOrFalling() && Rand() < 45)
            {
                if (Unit* raintarget = FindAOETarget(CalcSpellMaxRange(RAIN_OF_FIRE_1)))
                {
                    if (doCast(raintarget, GetSpell(RAIN_OF_FIRE_1)))
                        return;
                }
            }
            //Searing Pain (PvP)
            if (longCasted && IsSpellReady(SEARING_PAIN_1, diff) && HasRole(BOT_ROLE_DPS) &&
                opponent->GetTypeId() == TYPEID_PLAYER && Rand() < 35 && dist < CalcSpellMaxRange(SEARING_PAIN_1))
            {
                if (doCast(opponent, GetSpell(SEARING_PAIN_1)))
                    return;
            }
            //Shadowflame
            if (longCasted && IsSpellReady(SHADOWFLAME_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 65)
            {
                std::list<Unit*> targets;
                GetNearbyTargetsInConeList(targets, 8); //radius 10 yd
                if (!targets.empty() && doCast(me, GetSpell(SHADOWFLAME_1)))
                    return;
            }
            //Curse, checking affliction range
            if (GetSpellCooldown(CURSE_OF_WEAKNESS_1) <= diff && Rand() < 25 &&
                dist < CalcSpellMaxRange(CURSE_OF_WEAKNESS_1) && opponent->GetHealth() > me->GetMaxHealth() / 8)
            {
                bool skipCurse = false;
                uint32 CURSE = 0;
                if (/*!skipCurse && !CURSE && */GetSpell(CURSE_OF_THE_ELEMENTS_1) && !IAmFree() &&
                    master->GetGroup() && master->GetGroup()->GetMembersCount() > 2)
                {
                    AuraEffect const* elem = opponent->GetAuraEffect(SPELL_AURA_MOD_RESISTANCE, SPELLFAMILY_WARLOCK, 0x0, 0x200, 0x0);
                    if (!elem || elem->GetBase()->GetDuration() < 30000)
                        CURSE = CURSE_OF_THE_ELEMENTS_1;
                    else if (elem->GetCasterGUID() == me->GetGUID())
                        skipCurse = true;
                }
                if (!skipCurse && !CURSE && GetSpell(CURSE_OF_TONGUES_1) && opponent->GetHealth() > me->GetMaxHealth() / 2 &&
                    opponent->IsNonMeleeSpellCast(false, false, true))
                {
                    AuraEffect const* tong = opponent->GetAuraEffect(SPELL_AURA_MOD_LANGUAGE, SPELLFAMILY_WARLOCK, 692, 1);
                    if (!tong || tong->GetBase()->GetDuration() < 5000)
                        CURSE = CURSE_OF_TONGUES_1;
                    else if (tong->GetCasterGUID() == me->GetGUID())
                        skipCurse = true;
                }
                if (!skipCurse && !CURSE && GetSpell(CURSE_OF_WEAKNESS_1) && opponent->GetMaxHealth() > me->GetMaxHealth() * 2)
                {
                    AuraEffect const* weak = opponent->GetAuraEffect(SPELL_AURA_MOD_RESISTANCE_PCT, SPELLFAMILY_WARLOCK, 0x8000, 0x0, 0x0);
                    if (!weak || weak->GetBase()->GetDuration() < 10000)
                        CURSE = CURSE_OF_WEAKNESS_1;
                    else if (weak->GetCasterGUID() == me->GetGUID())
                        skipCurse = true;
                }
                if (!skipCurse && !CURSE && GetSpell(CURSE_OF_AGONY_1) &&
                    opponent->GetHealth() > me->GetMaxHealth() / 2 * (1 + opponent->getAttackers().size()) &&
                    !opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x400, 0x0, 0x0, me->GetGUID()))
                {
                    CURSE = CURSE_OF_AGONY_1;
                }
                if (!skipCurse && !CURSE && GetSpell(CURSE_OF_EXHAUSTION_1) && !CCed(opponent, true) &&
                    !opponent->HasAuraWithMechanic(1<<MECHANIC_SNARE))
                {
                    CURSE = CURSE_OF_EXHAUSTION_1;
                }

                if (!skipCurse && CURSE && doCast(opponent, GetSpell(CURSE)))
                    return;
            }

            if (!HasRole(BOT_ROLE_DPS))
                return;

            //Chaos Bolt
            if (IsSpellReady(CHAOS_BOLT_1, diff) && dist < CalcSpellMaxRange(CHAOS_BOLT_1))
            {
                if (doCast(opponent, GetSpell(CHAOS_BOLT_1)))
                    return;
            }
            //Soul Fire 1
            if (IsSpellReady(SOUL_FIRE_1, diff) && Rand() < 150 && dist < CalcSpellMaxRange(SOUL_FIRE_1) &&
                (opponent->IsPolymorphed() || me->HasAuraTypeWithAffectMask(SPELL_AURA_NO_REAGENT_USE, sSpellMgr->GetSpellInfo(SOUL_FIRE_1))))
            {
                if (doCast(opponent, GetSpell(SOUL_FIRE_1)))
                    return;
            }
            //Conflagrate (always glyphed, does not consume dot)
            if (longCasted && IsSpellReady(CONFLAGRATE_1, diff) && dist < CalcSpellMaxRange(CONFLAGRATE_1) &&
                opponent->HasAuraState(AURA_STATE_CONFLAGRATE) &&
                opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0x0, 0x0, me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(CONFLAGRATE_1)))
                    return;
            }
            //Shadowburn
            if (longCasted && IsSpellReady(SHADOWBURN_1, diff) && dist < CalcSpellMaxRange(SHADOWBURN_1) &&
                opponent->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
            {
                if (doCast(opponent, GetSpell(SHADOWBURN_1)))
                    return;
            }
            //Immolate
            if (IsSpellReady(IMMOLATE_1, diff) && Rand() < 85 && dist < CalcSpellMaxRange(IMMOLATE_1) &&
                (GetSpell(CONFLAGRATE_1) || opponent->GetHealth() > me->GetMaxHealth()/4 * (1 + opponent->getAttackers().size())) &&
                !opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0x0, 0x0, me->GetGUID()))
            {
                if (doCast(opponent, GetSpell(IMMOLATE_1)))
                    return;
            }
            //Haunt
            if (IsSpellReady(HAUNT_1, diff) && opponent->GetHealth() > me->GetMaxHealth()/4 * (1 + opponent->getAttackers().size()) &&
                Rand() < 45 && GetHealthPCT(me) < 90 && dist < CalcSpellMaxRange(HAUNT_1) &&
                !opponent->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_FROM_CASTER, SPELLFAMILY_WARLOCK, 0x0, 0x40000, 0x0, me->GetGUID()) &&
                opponent->GetDoTsByCaster(me->GetGUID()) > 1)
            {
                if (doCast(opponent, GetSpell(HAUNT_1)))
                    return;
            }
            //Seed of Corruption
            if (IsSpellReady(SEED_OF_CORRUPTION_1, diff) && Rand() < 85)
            {
                Unit* target = FindAOETarget(CalcSpellMaxRange(SEED_OF_CORRUPTION_1));
                if (target && !target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x0, 0x10, 0x0, me->GetGUID()))
                {
                    if (doCast(target, GetSpell(SEED_OF_CORRUPTION_1)))
                        return;
                }

                SetSpellCooldown(SEED_OF_CORRUPTION_1, 1000); //fail
            }
            //Corruption
            if (IsSpellReady(CORRUPTION_1, diff) && Rand() < 90 && dist < CalcSpellMaxRange(CORRUPTION_1) &&
                opponent->GetHealth() > me->GetMaxHealth()/4 * (1 + opponent->getAttackers().size()) &&
                !opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x2, 0x0, 0x0, me->GetGUID()) &&//corruption
                !opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x0, 0x10, 0x0, me->GetGUID()))//seed of corruption
            {
                if (doCast(opponent, GetSpell(CORRUPTION_1)))
                    return;
            }
            //Drain Soul: only if can quad damage
            if (IsSpellReady(DRAIN_SOUL_1, diff) && opponent->GetTypeId() == TYPEID_UNIT &&
                /*!opponent->ToCreature()->isWorldBoss() && */GetHealthPCT(opponent) < 25 &&
                opponent->GetHealth() > me->GetMaxHealth() / 4 * (1 + opponent->getAttackers().size()) &&
                dist < CalcSpellMaxRange(DRAIN_SOUL_1) && opponent->GetDoTsByCaster(me->GetGUID()) > 1
                //abs(int32(me->GetLevel()) - int32(opponent->GetLevel())) <= 5
                //!opponent->HasAuraType(SPELL_AURA_CHANNEL_DEATH_ITEM)
                )
            {
                if (doCast(opponent, GetSpell(DRAIN_SOUL_1)))
                    return;
            }
            //Soul Fire (conditional)
            if (IsSpellReady(SOUL_FIRE_1, diff) && Rand() < 90 && dist < CalcSpellMaxRange(SOUL_FIRE_1) &&
                opponent->GetHealth() > me->GetMaxHealth()/8 * (1 + opponent->getAttackers().size()) && me->HasAura(BACKDRAFT_BUFF))
            {
                if (doCast(opponent, GetSpell(SOUL_FIRE_1)))
                    return;
            }
            //Main: Shadow Bolt, Incinerate, Searing Pain (tank), checking destruction range
            if (dist < CalcSpellMaxRange(SHADOW_BOLT_1))
            {
                uint32 boltinerate =
                    IsTank() && GetSpell(SEARING_PAIN_1) ? SEARING_PAIN_1 :
                    GetSpell(INCINERATE_1) && opponent->HasAuraState(AURA_STATE_CONFLAGRATE) &&
                    opponent->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0x0, 0x0) &&
                    opponent->GetAuraEffect(SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE, SPELLFAMILY_WARLOCK, 213, 0) &&
                    (me->GetMap()->IsRaid() || !me->HasAura(SHADOW_TRANCE_BUFF)) ?
                    INCINERATE_1 : SHADOW_BOLT_1;

                if (doCast(opponent, GetSpell(boltinerate)))
                    return;
            }

            if (Spell const* shot = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
            {
                if (shot->GetSpellInfo()->Id == SHOOT_WAND && shot->m_targets.GetUnitTarget() != opponent)
                    me->InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
            }
            else if (IsSpellReady(SHOOT_WAND, diff, false) && me->GetDistance(opponent) < 30 && GetEquips(BOT_SLOT_RANGED) &&
                doCast(opponent, SHOOT_WAND))
                return;
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const override
        {
            //victim can be NULL
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Molten Core part 2.2: 15% additional critical chance for Soul Fire
            if (lvl >= 35 && baseId == SOUL_FIRE_1)
            {
                const_cast<warlock_botAI*>(this)->moltencore = me->HasAura(MOLTEN_CORE_BUFF);
                if (moltencore)
                    crit_chance += 15.f;
            }

            //Devastation: 5% additional critical chance for Destruction spells
            if (lvl >= 30 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x3E5) || (spellInfo->SpellFamilyFlags[1] & 0x8310C0)))
                crit_chance += 5.f;
            //Fire and Brimstone part 2: 25% additional critical chance for Conflagrate
            if (lvl >= 55 && baseId == CONFLAGRATE_1)
                crit_chance += 25.f;
            //Malediction part 2: 9% additional critical chance for Corruption and Unstable Affliction
            if (lvl >= 45 && (baseId == CORRUPTION_1 || baseId == UNSTABLE_AFFLICTION_1))
                crit_chance += 9.f;
            //Glyph of Shadowburn: 20% additional critical chance for Shadowburn on targets 35% hp and below
            if (lvl >= 20 && baseId == SHADOWBURN_1 && victim && victim->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                crit_chance += 20.f;
            //Improved Corruption part 2: 5% additional critical chance for Seed of Corruption
            if (lvl >= 10 && (baseId == SEED_OF_CORRUPTION_1 || baseId == SEED_OF_CORRUPTION_FINAL_DAMAGE_1))
                crit_chance += 5.f;
            //Improved Searing Pain: 10% additional critical chance for Searing Pain
            if (lvl >= 25 && baseId == SEARING_PAIN_1)
                crit_chance += 10.f;

            //Master Demonologist part 1.2 (me): 5% additional critical chance for Fire spells
            if (lvl >= 35 && botPet && myPetType == BOT_PET_IMP && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE))
                crit_chance += 5.f;
            //Master Demonologist part 3.2 (me): 5% additional critical chance for Shadow spells
            if (lvl >= 35 && botPet && myPetType == BOT_PET_SUCCUBUS && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_SHADOW))
                crit_chance += 5.f;

            //Warlock T84P Bonus (64932): 5% additional critical chance for Shadow Bolt and Incinerate
            if (lvl >= 80 && (baseId == SHADOW_BOLT_1 || baseId == INCINERATE_1))
                crit_chance += 5.f;
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool crit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //2) apply bonus damage mods
            float pctbonus = 1.0f; //Special condition
            if (crit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Ruin: 50% additional crit damage bonus for Destruction spells
                if (lvl >= 20 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                    ((spellInfo->SpellFamilyFlags[0] & 0x13E5) || (spellInfo->SpellFamilyFlags[1] & 0xC310C0)))
                    pctbonus += 0.333f;
                //Pandemic part 2,3: crit damage for periodics and haunt
                if (lvl >= 50 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                    ((spellInfo->SpellFamilyFlags[0] & 0x2) || (spellInfo->SpellFamilyFlags[1] & 0x40100)))
                    pctbonus += 0.333f;
                //Glyph of Searing Pain: 20% additional crit damage bonus for Searing Pain
                if (lvl >= 18 && baseId == SEARING_PAIN_1)
                    pctbonus += 0.133f;
            }
            //Improved Shadow Bolt and Incinerate (38393): 6% bonus damage for Shadow bolt and Incinerate
            if (baseId == SHADOW_BOLT_1 || baseId == INCINERATE_1)
                pctbonus += 0.06f;
            //Glyph of Incinerate: 5% bonus damage for Incinerate
            if (baseId == INCINERATE_1)
                pctbonus += 0.05f;
            //Improved Immolate: 30% bonus damage for Immolate
            if (lvl >= 30 && baseId == IMMOLATE_1)
                pctbonus += 0.3f;
            //EmberStorm part 1: 15% bonus damage for Fire spells
            if (lvl >= 35 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x364) || (spellInfo->SpellFamilyFlags[1] & 0x8200C0)))
                pctbonus += 0.15f;
            //Fire and Brimstone part 1: 10% bonus damage for Incinerate and Chaos Bolt
            if (lvl >= 55 && (baseId == INCINERATE_1 || baseId == CHAOS_BOLT_1) &&
                damageinfo.target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0x0, 0x0, me->GetGUID()))
                pctbonus += 0.1f;
            //Molten Core part 1: 18% bonus damage for Incinerate and Soul Fire
            if (lvl >= 35 && (baseId == INCINERATE_1 || baseId == SOUL_FIRE_1))
            {
                if (me->HasAura(MOLTEN_CORE_BUFF))
                    pctbonus += 0.18f;
            }
            //Improved Corruption part 1: 10% bonus damage for Corruption
            if (lvl >= 10 && baseId == CORRUPTION_1)
                pctbonus += 0.1f;
            //Corruption (28829): 12% bonus damage for Corruption
            if (lvl >= 40 && baseId == CORRUPTION_1)
                pctbonus += 0.12f;
            //Malediction part 1: 3% bonus damage for All spells
            if (lvl >= 45)
                pctbonus += 0.03f;
            //Death's Embrace part 2: 12% bonus damage for Shadow spells on targets below 35 pct health
            if (lvl >= 50 && damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT) &&
                ((spellInfo->SpellFamilyFlags[0] & 0x8248B) || (spellInfo->SpellFamilyFlags[1] & 0x59913)))
                pctbonus += 0.12f;

            //Empowered Corruption: 36% spellpower bonus for Corruption
            if (lvl >= 25 && baseId == CORRUPTION_1)
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.36f * me->CalculateDefaultCoefficient(spellInfo, DOT) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Shadow and Flame: 20% spellpower bonus for Shadow Bolt, Shadowburn, Chaos Bolt and Incineration
            if (lvl >= 45 &&
                (baseId == SHADOW_BOLT_1 || baseId == CHAOS_BOLT_1 || baseId == SHADOWBURN_1 || baseId == INCINERATE_1))
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            //Everlasting Affliction part 1: 5% spellpower bonus for Corruption and Unstable Affliction
            if (lvl >= 55 && (baseId == CORRUPTION_1 || baseId == UNSTABLE_AFFLICTION_1))
                fdamage += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.05f * me->CalculateDefaultCoefficient(spellInfo, DOT) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);

            //Firestone/Spellstone: 1% bonus damage for all spells
            if (lvl >= 28)
                pctbonus += 0.01f;

            //Improved Shadow Bolt part 1: 10% bonus damage for Shadow Bolt
            if (lvl >= 10 && baseId == SHADOW_BOLT_1)
                pctbonus += 0.1f;
            //Improved Corruption and Immolate (Updated) (61992): 5% bonus damage for Corruption and Immolate
            if (lvl >= 10 && (baseId == CORRUPTION_1 || baseId == IMMOLATE_1))
                pctbonus += 0.05f;
            //Improved Curse of Agony: 10% bonus damage for Curse of Agony
            if (lvl >= 10 && baseId == CURSE_OF_AGONY_1)
                pctbonus += 0.1f;
            //Shadow Mastery: 15% bonus damage for Shadow Spells
            if (lvl >= 35 && ((spellInfo->SpellFamilyFlags[0] & 0x80091) || spellInfo->SpellFamilyFlags[1] & 0x451910))
                pctbonus += 0.15f;
            //Contagion: 5% bonus damage for Curse of Agony, Corruption and Seed of Corruption
            if (lvl >= 40 && (baseId == CORRUPTION_1 || baseId == SEED_OF_CORRUPTION_1 ||
                baseId == SEED_OF_CORRUPTION_FINAL_DAMAGE_1 || baseId == CURSE_OF_AGONY_1))
                pctbonus += 0.05f;

            //Warlock T82P Bonus (64931): 20/10% bonus damage for Unstable Affliction and Immolate
            if (lvl >= 80 && baseId == UNSTABLE_AFFLICTION_1)
                pctbonus += 0.2f;
            if (lvl >= 80 && baseId == IMMOLATE_1)
                pctbonus += 0.1f;
            //Warlock T94P Bonus (67231): 10% bonus damage for Immolate, Corruption and Unstable Affliction
            if (lvl >= 80 && (baseId == IMMOLATE_1 || baseId == CORRUPTION_1 || baseId == UNSTABLE_AFFLICTION_1))
                pctbonus += 0.2f;

            //Glyph of Immolate: 10% bonus damage for Immolate
            if (lvl >= 15 && baseId == IMMOLATE_1)
                pctbonus += 0.1f;

            //Demonic Pact part 1: 10% bonus damage for all spells
            if (lvl >= 55)
                pctbonus *= 1.1f;
            //Master Demonologist part 1.1 (me): 5% bonus damage for Fire spells
            if (lvl >= 35 && botPet && myPetType == BOT_PET_IMP && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_FIRE))
                pctbonus *= 1.05f;
            //Master Demonologist part 3.1 (me): 5% bonus damage for Shadow spells
            if (lvl >= 35 && botPet && myPetType == BOT_PET_SUCCUBUS && (spellInfo->GetSchoolMask() & SPELL_SCHOOL_MASK_SHADOW))
                pctbonus *= 1.05f;

            damage = int32(fdamage * pctbonus);
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType /*damagetype*/, uint32 /*stack*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;

            //Glyph of Siphon Life: 25% bonus healing for Siphon Life effect (50% for bots)
            if (baseId == SIPHON_LIFE_HEAL)
                pctbonus += 0.5f;
            //Improved Death Coil (30052): 30% bonus healing for Death Coil
            if (lvl >= 60 && baseId == DEATH_COIL_1)
                pctbonus += 0.3f;

            heal = heal * (1.0f + pctbonus);
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            float pctbonus = 0.0f;

            //pct mods
            //Doomcaller Reduced Shadow Bolt Cost (26117): -15% mana cost for Shadow Bolt
            if (baseId == SHADOW_BOLT_1)
                pctbonus += 0.15f;
            //Glyph of Shadow Bolt: -10% mana cost for Shadow Bolt
            if (lvl >= 15 && baseId == SHADOW_BOLT_1)
                pctbonus += 0.1f;
            //Cataclysm: -10% mana cost for Destruction spells
            if (lvl >= 15 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x3E5) || (spellInfo->SpellFamilyFlags[1] & 0x8310C0)))
                pctbonus += 0.1f;
            //Suppression: -6% mana cost for Affliction spells
            if (lvl >= 10 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x814CC41A) || (spellInfo->SpellFamilyFlags[1] & 0x248F1B)))
                pctbonus += 0.06f;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus));
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Backlash: -100% cast time for Shadow Bolt or Incinerate
            if (lvl >= 15 && (baseId == SHADOW_BOLT_1 || baseId == INCINERATE_1))
            {
                const_cast<warlock_botAI*>(this)->backlash = me->HasAura(BACKLASH_BUFF);
                const_cast<warlock_botAI*>(this)->shadowtrance = (baseId == SHADOW_BOLT_1 && me->HasAura(SHADOW_TRANCE_BUFF));
                if (backlash || shadowtrance)
                    timebonus += casttime;
            }
            //Improved Howl of Terror: -1.5sec (-100%) cast time for Howl of Terror
            if (lvl >= 45 && baseId == HOWL_OF_TERROR_1)
                timebonus += casttime;
            //Chaotic Mind (custom)
            if (baseId == SOUL_FIRE_1)
            {
                const_cast<warlock_botAI*>(this)->chaoticmind = me->HasAura(CHAOTIC_MIND_BUFF);
                if (chaoticmind)
                    timebonus += casttime;
            }

            //pct mods
            //BackDraft part 1: -30% cast time for Destruction spells
            if (lvl >= 50 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x165) || (spellInfo->SpellFamilyFlags[1] & 0x310C0)))
            {
                //skip soul fire insta cast
                const_cast<warlock_botAI*>(this)->backdraft = me->HasAura(BACKDRAFT_BUFF) && !(chaoticmind && baseId == SOUL_FIRE_1);
                if (backdraft)
                    pctbonus += 0.3f;
            }
            //Molten Core part 2.1: -30% cast time for Incinerate
            if (lvl >= 35 && baseId == INCINERATE_1)
            {
                const_cast<warlock_botAI*>(this)->moltencore = me->HasAura(MOLTEN_CORE_BUFF);
                if (moltencore)
                    pctbonus += 0.3f;
            }
            //Decimation: -40% cast time for Soul Fire
            if (baseId == SOUL_FIRE_1 && me->HasAura(DECIMATION_BUFF))
                pctbonus += 0.4f;

            //flat mods
            //Bane: -0.5 sec cast time for Shadow Bolt, Immolate and Chaos Bolt, -2 sec cast for Soul Fire
            if (lvl >= 10)
            {
                if (baseId == SHADOW_BOLT_1 || baseId == IMMOLATE_1 || baseId == CHAOS_BOLT_1)
                    timebonus += 500;
                else if (baseId == SOUL_FIRE_1)
                    timebonus += 2000;
            }
            //EmberStorm part 2: -0.25 sec cast time for Incinerate
            if (lvl >= 35 && baseId == INCINERATE_1)
                timebonus += 250;
            //Fear Cast Time Reduction (23047): -0.2 sec cast time for Fear
            if (baseId == FEAR_1)
                timebonus += 200;

            casttime = std::max<int32>((float(casttime) * (1.0f - pctbonus)) - timebonus, 0);

            const_cast<warlock_botAI*>(this)->instaCast = (casttime <= 500); //triggered GCD is too long
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Glyph of Rapid Charge: -7% cooldown for Charge
            //if (lvl >= 40 && spellId == GetSpell(CHARGE_1))
            //    pctbonus += 0.07f;

            //flat mods

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //Glyph of Chaos Bolt: -2 sec cooldown for Chaos Bolt
            if (lvl >= 60 && baseId == CHAOS_BOLT_1)
                timebonus += 2000;
            //Improved Death Coil (24487): -15% cooldown for Death Coil (30 sec for bots)
            if (baseId == DEATH_COIL_1)
                timebonus += 30000;
            //Glyph of Howl of Terror: -8 sec cooldown for Howl of Terror
            if (lvl >= 45 && baseId == HOWL_OF_TERROR_1)
                timebonus += 8000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //BackDraft: -30% global cooldown for Destruction spells
            if (lvl >= 50 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x165) || (spellInfo->SpellFamilyFlags[1] & 0x310C0)) &&
                me->HasAura(BACKDRAFT_BUFF))
                pctbonus += 0.3f;

            //flat mods
            //Amplify Curse: -0.5 sec global cooldown for Curses
            if (lvl >= 25 && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x408400) || (spellInfo->SpellFamilyFlags[1] & 0x200202) ||
                (spellInfo->SpellFamilyFlags[2] & 0x800)))
                timebonus += 500.f;

            //Fear Cast Time Reduction (23047): -0.2 sec global cooldown for Fear
            if (baseId == FEAR_1)
                timebonus += 200;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods

            //flat mods
            //Improved Rain of Fire / Hellfire
            if (lvl >= 40 && (spellInfo->SpellFamilyFlags[0] & 0x60))
                flatbonus += 2.f;

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Grim Reach: +20% range for Affliction Spells
            if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x8048C41A) || (spellInfo->SpellFamilyFlags[1] & 0x40713)))
                pctbonus += 0.2f;
            //Destructive Reach: +20% range for Destruction Spells
            if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x13A5) || (spellInfo->SpellFamilyFlags[1] & 0x8210C0)))
                pctbonus += 0.2f;

            //flat mods
            //Glyph of Curse of Exhaustion: +5 yd range for Curse of Exhaustion
            if (lvl >= 70 && baseId == CURSE_OF_EXHAUSTION_1)
                flatbonus += 5.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //Instacast buffs handling
            if (baseId == SHADOW_BOLT_1)
            {
                if (backlash)
                    me->RemoveAurasDueToSpell(BACKLASH_BUFF);
                else if (shadowtrance)
                    me->RemoveAurasDueToSpell(SHADOW_TRANCE_BUFF);
            }
            if (baseId == INCINERATE_1)
            {
                if (backlash)
                    me->RemoveAurasDueToSpell(BACKLASH_BUFF);
            }
            if (chaoticmind && baseId == SOUL_FIRE_1)
                me->RemoveAurasDueToSpell(CHAOTIC_MIND_BUFF);

            //Backdraft
            if (backdraft && spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                ((spellInfo->SpellFamilyFlags[0] & 0x165) || (spellInfo->SpellFamilyFlags[1] & 0x310C0)))
            {
                if (Aura* bd = me->GetAura(BACKDRAFT_BUFF))
                    bd->DropCharge();
            }
            //Molten Core
            if (moltencore && (baseId == INCINERATE_1 || baseId == SOUL_FIRE_1))
            {
                if (Aura* mc = me->GetAura(MOLTEN_CORE_BUFF))
                    mc->DropCharge();
            }
            //Decimation: NOT DROPPED ON CAST
            //if (baseId == SOUL_FIRE_1)
            //{
            //    if (Aura* mc = me->GetAura(DECIMATION_BUFF))
            //        mc->DropCharge();
            //}
            longCasted = !instaCast &&
                (baseId == SHADOW_BOLT_1 || baseId == INCINERATE_1 || baseId == CHAOS_BOLT_1 ||
                baseId == SOUL_FIRE_1 || baseId == HAUNT_1 || baseId == SEARING_PAIN_1); //damaging spells
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Shadow Ward helper
            if (!canShadowWard && (spell->GetSchoolMask() & SPELL_SCHOOL_MASK_SHADOW) &&
                (spell->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE) || spell->HasAura(SPELL_AURA_PERIODIC_DAMAGE)))
                canShadowWard = true;

            //Create Healthstone trigger
            if (baseId == CREATE_HEALTHSTONE_1)
            {
                hasHealthstone = true;
            }
            //Create Soulstone trigger
            if (baseId == CREATE_SOULSTONE_1)
            {
                hasSoulstone = true;
            }

            //Glyph of Soul Link: +5% increased effect
            if (baseId == SOUL_LINK_PET)
            {
                if (AuraEffect* link = me->GetAuraEffect(spellId, 0))
                    link->ChangeAmount(link->GetAmount() + 5);
            }

            //Life Tap energize
            if (baseId == LIFE_TAP_1)
            {
                //level * 3 based on in-game tooltip and spellwork (BasePoints = 2000 + Level * 4,00)
                int32 damage = spell->Effects[0].CalcValue(me);
                int32 manaGain = damage;
                damage += int32(me->GetLevel() * 3);
                manaGain += 0.5f * me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC);

                //Life Tap (id: 28830)
                //damage = int32(float(damage) * 0.88f);
                //Improved Life Tap
                if (me->GetLevel() >= 15)
                    manaGain = int32(float(manaGain) * 1.2f);

                me->ModifyHealth(-damage);
                CastSpellExtraArgs args(true);
                args.AddSpellBP0(manaGain);
                me->CastSpell(me, LIFE_TAP_ENERGIZE, args);

                //Mana Feed
                if (botPet)
                    me->EnergizeBySpell(botPet, LIFE_TAP_ENERGIZE_PET, manaGain, POWER_MANA);
            }

            if (baseId == DEMON_ARMOR_1 || baseId == FEL_ARMOR_1)
            {
                if (Aura* armo = me->GetAura(spellId, me->GetGUID()))
                {
                    //Armors duration
                    uint32 dur = 1 * HOUR * IN_MILLISECONDS;
                    armo->SetDuration(dur);
                    armo->SetMaxDuration(dur);

                    //Demonic Aegis
                    if (lvl >= 20)
                    {
                        for (uint8 i = 0; i != MAX_SPELL_EFFECTS; ++i)
                            if (AuraEffect* eff = armo->GetEffect(i))
                                eff->ChangeAmount(eff->GetAmount() * 13 / 10);
                    }
                }
            }
            //Chaotic Mind (custom)
            if (baseId == CHAOTIC_MIND)
            {
                if (Aura* mind = me->GetAura(spellId))
                {
                    uint32 dur = 30000; //30 sec
                    mind->SetDuration(dur);
                    mind->SetMaxDuration(dur);
                }
            }
            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Soulstone resurrection trigger (not ranked)
            if (spellId == SOULSTONE_RESURRECTION_1 || spellId == SOULSTONE_RESURRECTION_2 ||
                spellId == SOULSTONE_RESURRECTION_3 || spellId == SOULSTONE_RESURRECTION_4 ||
                spellId == SOULSTONE_RESURRECTION_5 || spellId == SOULSTONE_RESURRECTION_6 ||
                spellId == SOULSTONE_RESURRECTION_7)
            {
                hasSoulstone = false;
                //reduced for bot
                //soulstoneTimer = 15 * MINUTE * IN_MILLISECONDS;
                soulstoneTimer = 10 * MINUTE * IN_MILLISECONDS;
            }

            //Improved Imp part 3
            if (lvl >= 10 && baseId == BLOOD_PACT_1 && botPet)
            {
                AuraEffect* pact = target->GetAuraEffect(spellId, 0, botPet->GetGUID());
                if (pact)
                    pact->ChangeAmount(pact->GetAmount() * 1.3f);
            }

            //Improved Felhunter part 3
            if (lvl >= 35 && baseId == FEL_INTELLIGENCE_1 && botPet)
            {
                Aura const* feli = target->GetAura(spellId, botPet->GetGUID());
                if (feli)
                {
                    for (uint8 i = EFFECT_0; i != EFFECT_2; ++i)
                    {
                        if (AuraEffect* effi = feli->GetEffect(i))
                            effi->ChangeAmount(effi->GetAmount() + effi->GetAmount() / 10);
                    }
                }
            }

            //Glyph of Unending Breath: swim speed
            if (/*lvl >= 15 && */baseId == UNENDING_BREATH_1)
            {
                AuraEffect* brea = target->GetAuraEffect(spellId, 1, me->GetGUID());
                if (brea)
                    brea->ChangeAmount(brea->GetAmount() + 20);
            }

            //Chaotic Mind (custom)
            if (lvl >= 60 && target != me && spell->SpellFamilyName == SPELLFAMILY_WARLOCK && !spell->IsPositive())
            {
                if (urand(1,100) <= 5)
                    me->CastSpell(me, CHAOTIC_MIND, true);
            }
            if (baseId == IMMOLATE_1 || baseId == CORRUPTION_1)
            {
                if (Aura* per = target->GetAura(spellId, me->GetGUID()))
                {
                    //Improved Corruption and Immolate (37380): +3 sec duration for Immolate and Corruption
                    uint32 dur = per->GetDuration() + 3000;
                    //Molten Core: + 9 sec duration for Immolate
                    if (lvl >= 35 && baseId == IMMOLATE_1)
                        dur += 9000;
                    per->SetDuration(dur);
                    per->SetMaxDuration(dur);
                }
            }
            //Glyph of Death Coil: + 0.5 sec duration for Death Coil (2 sec on creatures)
            if (baseId == DEATH_COIL_1)
            {
                if (Aura* dc = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = dc->GetDuration() + (target->GetTypeId() == TYPEID_PLAYER ? 500 : 2000);
                    dc->SetDuration(dur);
                    dc->SetMaxDuration(dur);
                }
            }
            //Improved Curse of Weakness: +20% increased effect
            if (baseId == CURSE_OF_WEAKNESS_1)
            {
                if (AuraEffect* weak = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                {
                    weak->ChangeAmount(weak->GetAmount() * 12 / 10);
                }
            }
            //Glyph of Haunt: +3% increased effect
            if (lvl >= 60 && baseId == HAUNT_1)
            {
                if (AuraEffect* haun = target->GetAuraEffect(spellId, 2, me->GetGUID()))
                {
                    haun->ChangeAmount(haun->GetAmount() + 3);
                }
            }
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            //Fel Synergy (Life Tap)
            if (damage && botPet && me->GetLevel() >= 10 && (damageType == SPELL_DIRECT_DAMAGE || damageType == DOT))
            {
                uint32 healVal = float(damage) * 0.15f;
                if (healVal)
                {
                    SpellInfo const* synhealInfo = sSpellMgr->GetSpellInfo(FEL_SYNERGY_HEAL);
                    HealInfo hinfo(me, botPet, healVal, synhealInfo, synhealInfo->GetSchoolMask());
                    botPet->HealBySpell(hinfo);
                }
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/) override
        {
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

        void SummonBotPet()
        {
            if (botPet)
                UnsummonAll();

            if (myPetType == BOT_PET_INVALID) //disabled
                return;

            if (petSummonTimer > GetLastDiff())
                return;

            uint32 entry;

            if (myPetType)
                entry = myPetType;
            else if (!IAmFree())
            {
                if (me->GetLevel() >= 30 && master->GetMaxPower(POWER_MANA) > 1 &&
                    !master->GetBotMgr()->HasBotClass(BOT_CLASS_MAGE) &&
                    !master->GetBotMgr()->HasBotClass(BOT_CLASS_PRIEST) &&
                    !master->GetBotMgr()->HasBotPetType(BOT_PET_FELHUNTER))
                    entry = BOT_PET_FELHUNTER;
                else if ((me->GetLevel() < 68 || !master->GetBotMgr()->HasBotClass(BOT_CLASS_WARRIOR)) &&
                    !master->GetBotMgr()->HasBotPetType(BOT_PET_IMP))
                    entry = BOT_PET_IMP;
                else if (me->GetLevel() >= 10 && IsTank())
                    entry = BOT_PET_VOIDWALKER;
                else if (me->GetLevel() >= 50)
                    entry = BOT_PET_FELGUARD;
                else if (me->GetLevel() >= 20 && !IsMeleeClass(master->GetClass()))
                    entry = BOT_PET_SUCCUBUS;
                else if (me->GetLevel() >= 10)
                    entry = BOT_PET_VOIDWALKER;
                else
                    entry = BOT_PET_IMP;
            }
            else
                entry = urand(BOT_PET_WARLOCK_START, BOT_PET_WARLOCK_END);

            //ensurance
            if ((entry == BOT_PET_VOIDWALKER && me->GetLevel() < 10) ||
                (entry == BOT_PET_SUCCUBUS && me->GetLevel() < 20) ||
                (entry == BOT_PET_FELHUNTER && me->GetLevel() < 30) ||
                (entry == BOT_PET_FELGUARD && me->GetLevel() < 50) ||
                (entry != BOT_PET_IMP && entry != BOT_PET_VOIDWALKER && entry != BOT_PET_SUCCUBUS &&
                entry != BOT_PET_FELHUNTER && entry != BOT_PET_FELGUARD))
                entry = 0;

            myPetType = entry;

            //try next time
            if (!myPetType)
                return;

            ResetSpellCooldown(BLOOD_PACT_1);
            ResetSpellCooldown(FEL_INTELLIGENCE_1);

            Position pos;

            me->CastSpell(me, SUMMON_DEMON_VISUAL, true);
            Creature* myPet = me->SummonCreature(myPetType, *me, TEMPSUMMON_CORPSE_DESPAWN);
            me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0, me->GetOrientation() + M_PI / 2);
            myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreatorGUID(master->GetGUID());
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            //fix scale and equips
            switch (myPetType)
            {
                case BOT_PET_FELHUNTER:
                    myPet->SetObjectScale(1.1f);
                    break;
                case BOT_PET_FELGUARD:
                    myPet->SetObjectScale(0.75f);
                    myPet->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0, 22199);
                    break;
            }

            botPet = myPet;
        }

        void UnsummonAll() override
        {
            if (botPet)
                botPet->ToTempSummon()->UnSummon();
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //all warlock bot pets despawn at death or manually (gossip, teleport, etc.)
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: %s's %s", me->GetName().c_str(), summon->GetName().c_str());
            if (summon == botPet)
            {
                petSummonTimer = 10000;
                botPet = nullptr;

                //party aura hack removal helper
                switch (summon->GetEntry())
                {
                    case BOT_PET_IMP:
                        me->RemoveAurasDueToSpell(InitSpell(me, BLOOD_PACT_1));
                        break;
                    case BOT_PET_FELHUNTER:
                        me->RemoveAurasDueToSpell(InitSpell(me, FEL_INTELLIGENCE_1));
                        break;
                }
            }
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(SHADOW_BOLT_1) : 20.f;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case CREATE_HEALTHSTONE_1:
                    return uint32(hasHealthstone);
                case BOTAI_MISC_PET_TYPE:
                    return myPetType;
                case BOTAI_MISC_PET_AVAILABLE_1:
                    return BOT_PET_IMP;
                case BOTAI_MISC_PET_AVAILABLE_2:
                    return me->GetLevel() >= 10 ? BOT_PET_VOIDWALKER : 0;
                case BOTAI_MISC_PET_AVAILABLE_3:
                    return me->GetLevel() >= 20 ? BOT_PET_SUCCUBUS : 0;
                case BOTAI_MISC_PET_AVAILABLE_4:
                    return me->GetLevel() >= 30 ? BOT_PET_FELHUNTER : 0;
                case BOTAI_MISC_PET_AVAILABLE_5:
                    return me->GetLevel() >= 50 ? BOT_PET_FELGUARD : 0;
                default:
                    return 0;
            }
        }

        void SetAIMiscValue(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case CREATE_HEALTHSTONE_1:
                    hasHealthstone = bool(value);
                    break;
                case BOTAI_MISC_PET_TYPE:
                    myPetType = value;
                    UnsummonAll();
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            UnsummonAll();

            myPetType = 0;

            fearTimer = 0;
            banishTimer = 0;
            unbanishTimer = 0;
            drainManaTimer = 0;
            healthstoneTimer = 0;
            soulstoneTimer = 0;

            petSummonTimer = 5000;

            hasHealthstone = false;
            hasSoulstone = false;

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (fearTimer > diff)                   fearTimer -= diff;
            if (banishTimer > diff)                 banishTimer -= diff;
            if (unbanishTimer > diff)               unbanishTimer -= diff;
            if (drainManaTimer > diff)              drainManaTimer -= diff;
            if (healthstoneTimer > diff)            healthstoneTimer -= diff;
            if (soulstoneTimer > diff)              soulstoneTimer -= diff;

            if (petSummonTimer > diff)              petSummonTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);

            if (botPet && botPet->GetPowerType() != POWER_MANA)
                botPet->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_MANA);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();

            InitSpellMap(CURSE_OF_WEAKNESS_1);
            InitSpellMap(CURSE_OF_AGONY_1);
            InitSpellMap(CURSE_OF_TONGUES_1);
  /*Talent*/lvl >= 30 ? InitSpellMap(CURSE_OF_EXHAUSTION_1) : RemoveSpell(CURSE_OF_EXHAUSTION_1);
            InitSpellMap(CURSE_OF_THE_ELEMENTS_1);
            InitSpellMap(SHADOW_BOLT_1);
            InitSpellMap(IMMOLATE_1);
            InitSpellMap(CORRUPTION_1);
            InitSpellMap(SEED_OF_CORRUPTION_1);
            InitSpellMap(INCINERATE_1);
            InitSpellMap(SEARING_PAIN_1);
  /*Talent*/lvl >= 20 ? InitSpellMap(SHADOWBURN_1) : RemoveSpell(SHADOWBURN_1);
  /*Talent*/lvl >= 40 ? InitSpellMap(CONFLAGRATE_1) : RemoveSpell(CONFLAGRATE_1);
            InitSpellMap(SOUL_FIRE_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(CHAOS_BOLT_1) : RemoveSpell(CHAOS_BOLT_1);
            InitSpellMap(RAIN_OF_FIRE_1);
            InitSpellMap(HELLFIRE_1);
            InitSpellMap(SHADOWFLAME_1);
  /*Talent*/lvl >= 50 ? InitSpellMap(SHADOWFURY_1) : RemoveSpell(SHADOWFURY_1);
  /*Talent*/lvl >= 60 ? InitSpellMap(HAUNT_1) : RemoveSpell(HAUNT_1);
///*Talent*/lvl >= 50 ? InitSpellMap(UNSTABLE_AFFLICTION_1) : RemoveSpell(UNSTABLE_AFFLICTION_1);
            InitSpellMap(FEAR_1);
            InitSpellMap(HOWL_OF_TERROR_1);
            InitSpellMap(DEATH_COIL_1);
            InitSpellMap(SOULSHATTER_1);

            InitSpellMap(DRAIN_SOUL_1);
            InitSpellMap(DRAIN_MANA_1);
            InitSpellMap(BANISH_1);

            InitSpellMap(DEMON_SKIN_1);
            InitSpellMap(DEMON_ARMOR_1);
            InitSpellMap(FEL_ARMOR_1);
            InitSpellMap(DETECT_INVISIBILITY_1);
            InitSpellMap(UNENDING_BREATH_1);
            InitSpellMap(SHADOW_WARD_1);
            InitSpellMap(LIFE_TAP_1);
            InitSpellMap(DARK_PACT_1);
            InitSpellMap(CREATE_HEALTHSTONE_1);
            InitSpellMap(CREATE_SOULSTONE_1);

            InitSpellMap(RITUAL_OF_SUMMONING_1); //manual only
            InitSpellMap(RITUAL_OF_SOULS_1); //not casted
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();

            RefreshAura(CHAOS_BOLT_PASSIVE);
            RefreshAura(DEMONIC_IMMOLATE_PASSIVE);

            RefreshAura(IMPROVED_SHADOW_BOLT, level >= 10 ? 1 : 0);
            RefreshAura(IMPROVED_DRAIN_SOUL, level >= 15 ? 1 : 0);
            RefreshAura(SOUL_SIPHON, level >= 15 ? 1 : 0);
            RefreshAura(AFTERMATH, level >= 15 ? 1 : 0);
            RefreshAura(IMPROVED_FEAR, level >= 20 ? 1 : 0);
            RefreshAura(NIGHTFALL, level >= 25 ? 1 : 0);
            RefreshAura(SHADOW_EMBRACE, level >= 30 ? 1 : 0);
            RefreshAura(SIPHON_LIFE, level >= 30 ? 1 : 0);
            RefreshAura(BACKLASH, level >= 30 ? 1 : 0);
            RefreshAura(MOLTEN_CORE, level >= 35 ? 1 : 0);
            RefreshAura(NETHER_PROTECTION, level >= 35 ? 1 : 0);
            RefreshAura(ERADICATION, level >= 40 ? 1 : 0);
            RefreshAura(DEMONIC_RESILIENCE, level >= 40 ? 1 : 0);
            RefreshAura(SOUL_LEECH, level >= 40 ? 1 : 0);
            RefreshAura(PYROCLASM, level >= 40 ? 1 : 0);
            RefreshAura(DECIMATION, level >= 45 ? 1 : 0);
            RefreshAura(IMPROVED_SOUL_LEECH, level >= 45 ? 1 : 0);
            RefreshAura(PANDEMIC, level >= 50 ? 1 : 0);
            RefreshAura(BACKDRAFT, level >= 50 ? 1 : 0);
            RefreshAura(EVERLASTING_AFFLICTION, level >= 55 ? 1 : 0);

            RefreshAura(GLYPH_CORRUPTION, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_FEAR, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_QUICK_DECAY, level >= 15 ? 1 : 0);
            RefreshAura(GLYPH_CONFLAGRATE, level >= 40 ? 1 : 0);
            RefreshAura(GLYPH_SHADOWFLAME, level >= 75 ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case RAIN_OF_FIRE_1:
                case SHADOWFLAME_1:
                case HOWL_OF_TERROR_1:
                case DETECT_INVISIBILITY_1:
                case UNENDING_BREATH_1:
                //case RITUAL_OF_SUMMONING_1:
                case SHADOW_WARD_1:
                case LIFE_TAP_1:
                case DARK_PACT_1:
                    return true;
                //case FEL_ARMOR_1:
                //    return true;
                //case DEMON_ARMOR_1:
                //    return !GetSpell(FEL_ARMOR_1);
                //case DEMON_SKIN_1:
                //    return !GetSpell(FEL_ARMOR_1) && !GetSpell(DEMON_ARMOR_1);
                default:
                    return false;
            }
        }

    private:
        //Timers
        uint32 fearTimer, banishTimer, unbanishTimer, drainManaTimer, healthstoneTimer, soulstoneTimer;
        //Pet
        uint32 myPetType;
        uint32 petSummonTimer;
        //Special
        bool backlash, shadowtrance, backdraft, moltencore, chaoticmind;
        bool canShadowWard;
        bool longCasted, instaCast; //some sort of rotation thing
        bool hasHealthstone, hasSoulstone;
    };
};

//HealthstoneSpellIds (Improved Healthstone rank 2)
uint32 const warlock_bot::warlock_botAI::_healthStoneSpells[8/*createHealthstoneRank*/] =
{
    23469,// Minor
    23471,// Lesser
    23473,//
    23475,// Greater
    23477,// Major
    27237,// Master
    47872,// Demonic
    47877 // Fel
};

void AddSC_warlock_bot()
{
    new warlock_bot();
}
