#include "bot_ai.h"
#include "botmgr.h"
#include "bottext.h"
#include "bottraits.h"
#include "DBCStores.h"
#include "GameEventMgr.h"
#include "Group.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "World.h"
/*
Death Knight NpcBot by Trickerer onlysuffering@gmail.com
Complete - around 85%
Note: Rune system adapted from TC
TODO: pet related
Notes: raise dead / army of the dead not working off the bat, summon garg crash, dancing rune weapon crash, need ai workarounds
*/

enum DeathKnightBaseSpells
{
    BLOOD_STRIKE_1                      = 45902,
    ICY_TOUCH_1                         = 45477,
    PLAGUE_STRIKE_1                     = 45462,
    DEATH_STRIKE_1                      = 49998,
    OBLITERATE_1                        = 49020,
    RUNE_STRIKE_1                       = 56815,
    HEART_STRIKE_1                      = 55050,
    FROST_STRIKE_1                      = 49143,
    SCOURGE_STRIKE_1                    = 55090,

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

    PATH_OF_FROST_1                     = 3714,
    HORN_OF_WINTER_1                    = 57330,
    EMPOWER_RUNE_WEAPON_1               = 47568,
    BLOOD_TAP_1                         = 45529,

    RUNE_TAP_1                          = 48982,
    LICHBORNE_1                         = 49039,
    //CE
    MARK_OF_BLOOD_1                     = 49005,
    DEATHCHILL_1                        = 49796,
    HYSTERIA_1                          = 49016,
    HUNGERING_COLD_1                    = 49203,
    ANTI_MAGIC_ZONE_1                   = 48707,
    VAMPIRIC_BLOOD_1                    = 55233,
    UNBREAKABLE_ARMOR_1                 = 51271,
    BONE_SHIELD_1                       = 49222,

    BLOOD_PRESENCE_1                    = 48266,
    FROST_PRESENCE_1                    = 48263,
    UNHOLY_PRESENCE_1                   = 48265//unused
};
enum DeathKnightPassives
{
//Talents
    BUTCHERY                            = 49483,//rank 2
    TOUGHNESS                           = 49789,//rank 5
    BLADED_ARMOR                        = 49393,//rank 5
    SCENT_OF_BLOOD                      = 49509,//rank 3
    TWO_HANDED_WEAPON_SPECIALIZATION    = 55108,//rank 2
    ICY_TALONS                          = 50887,//rank 5
    ANNIHILATION                        = 51473,//rank 3
    NECROSIS1                           = 51459,
    NECROSIS2                           = 51462,
    NECROSIS3                           = 51463,
    NECROSIS4                           = 51464,
    NECROSIS5                           = 51465,
    SPELL_DEFLECTION                    = 49497,//rank 3
    VENDETTA                            = 55136,//rank 3
    KILLING_MACHINE                     = 51130,//rank 5
    CHILL_OF_THE_GRAVE                  = 50115,//rank 2
    ON_A_PALE_HORSE_A                   = 51970,//rank 2
    ON_A_PALE_HORSE_B                   = 51986,//rank 2
    BLOOD_CAKED_BLADE1                  = 49219,
    BLOOD_CAKED_BLADE2                  = 49627,
    BLOOD_CAKED_BLADE3                  = 49628,
    FRIGID_DREADPLATE                   = 51109,//rank 3
    UNHOLY_BLIGHT                       = 49194,
    DIRGE                               = 51206,//rank 2
    BLOODY_VENGEANCE1                   = 48988,
    BLOODY_VENGEANCE2                   = 49503,
    BLOODY_VENGEANCE3                   = 49504,
    ABOMINATIONS_MIGHT                  = 53138,//rank 2
    IMPROVED_ICY_TALONS                 = 55610,
    DESECRATION                         = 55667,//rank 2
    //BLOODWORMS                          = 49543,//rank 3
    IMPROVED_BLOOD_PRESENCE             = 50371,//rank 2
    DESOLATION                          = 66817,//rank 5
    IMPROVED_UNHOLY_PRESENCE            = 50392,//rank 2
    THREAT_OF_THASSARIAN                = 66192,//rank 3
    CRYPT_FEVER                         = 49632,//rank 3
    WILL_OF_THE_NECROPOLIS              = 52286,//rank 3
    ACCLIMATION                         = 50152,//rank 3
    WANDERING_PLAGUE                    = 49655,//rank 3
    EBON_PLAGUEBRINGER                  = 51161,//rank 3

//Other
    //GLYPH_DANCING_RUNE_WEAPON           = 63330,
    GLYPH_DISEASE                       = 63334,
    GLYPH_CHAINS_OF_ICE                 = 58620,
    GLYPH_UNHOLY_BLIGHT                 = 63332,
    CHAINS_OF_ICE_FROST_RUNE_REFRESH    = 62459,//5 runic power gain

    ITEM_DEATH_KNIGHT_T8_MELEE_4P       = 64736,
    ITEM_DEATH_KNIGHT_T9_MELEE_4P       = 67118,

//Special
    FROST_FEVER                         = 59921,
    BLOOD_PLAGUE                        = 59879,
    RUNE_STRIKE_PASSIVE                 = 56816,//rune strike activation req aura
    RUNIC_POWER_MASTERY                 = 49455//rank 1
};
enum DeathKnightSpecial
{
    FROST_FEVER_AURA                    = 55095,
    BLOOD_PLAGUE_AURA                   = 55078,
    CRYPT_FEVER_AURA                    = 50510,//rank 3
    EBON_PLAGUE_AURA                    = 51735,//rank 3

    BLADE_BARRIER_BUFF                  = 64859,//rank 5
    KILLING_MACHINE_BUFF                = 51124,
    RIME_BUFF                           = 59052,//Freezing Fog
    ITEM_DEATH_KNIGHT_T10_TANK_4P_BUFF  = 70654,//Blood Armor
    ITEM_DEATH_KNIGHT_T10_MELEE_4P_BUFF = 70657,//Advantage

    CHILBLAINS_DEBUFF                   = 50436,//Icy Clutch rank 3

    BLOOD_PRESENCE_HEAL_EFFECT          = 50475,
    //UNHOLY_BLIGHT_AURA                  = 50536,

    DEATH_STRIKE_HEAL                   = 45470,
    DEATH_COIL_HEAL                     = 47633,
    DEATH_COIL_DAMAGE                   = 47632,

    GLYPH_HEART_STRIKE_DEBUFF           = 58617, //50% move slow
    GLYPH_RUNE_TAP_HEAL                 = 59754,
    GLYPH_SCOURGE_STRIKE_EFFECT         = 69961
};

static const uint32 Deathknight_spells_damage_arr[] =
{ BLOOD_BOIL_1, BLOOD_STRIKE_1, DEATH_AND_DECAY_1, DEATH_COIL_1,DEATH_STRIKE_1,
FROST_STRIKE_1, HEART_STRIKE_1, HOWLING_BLAST_1, HUNGERING_COLD_1, ICY_TOUCH_1,
OBLITERATE_1, PESTILENCE_1, PLAGUE_STRIKE_1, RUNE_STRIKE_1, SCOURGE_STRIKE_1 };

static const uint32 Deathknight_spells_cc_arr[] =
{ DEATH_GRIP_1, CHAINS_OF_ICE_1, MIND_FREEZE_1, STRANGULATE_1 };

static const uint32 Deathknight_spells_support_arr[] =
{ ANTI_MAGIC_SHELL_1, ANTI_MAGIC_ZONE_1, ARMY_OF_THE_DEAD_1, BLOOD_TAP_1, BONE_SHIELD_1,DARK_COMMAND_1, DEATHCHILL_1,
DEATH_COIL_1, EMPOWER_RUNE_WEAPON_1, HORN_OF_WINTER_1, HUNGERING_COLD_1,HYSTERIA_1, ICEBOUND_FORTITUDE_1,
LICHBORNE_1, MARK_OF_BLOOD_1, PATH_OF_FROST_1, PESTILENCE_1, RUNE_TAP_1,UNBREAKABLE_ARMOR_1, VAMPIRIC_BLOOD_1 };

static const std::vector<uint32> Deathknight_spells_damage(FROM_ARRAY(Deathknight_spells_damage_arr));
static const std::vector<uint32> Deathknight_spells_cc(FROM_ARRAY(Deathknight_spells_cc_arr));
static const std::vector<uint32> Deathknight_spells_support(FROM_ARRAY(Deathknight_spells_support_arr));

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
    int32 Cooldown;
};
class death_knight_bot : public CreatureScript
{
public:
    death_knight_bot() : CreatureScript("death_knight_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new death_knight_botAI(creature);
    }

    struct death_knight_botAI : public bot_ai
    {
/*
        bool OnGossipHello(Player* player) override
        {
            return OnGossipHello(player, 0);
        }

        bool OnGossipSelect(Player* player, uint32 sender, uint32 action) override
        {
            return OnGossipSelect(player, me, sender, action);
        }

        bool OnGossipSelectCode(Player* player, uint32 sender, uint32 action, char const* code) override
        {
            return OnGossipSelectCode(player, me, sender, action, code);
        }
*/
        death_knight_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_DEATH_KNIGHT;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;

            if (!HaveRunes(spellId))
                return false;

            return bot_ai::doCast(victim, spellId);
        }

        void SpendRunes(SpellInfo const* spellInfo, bool didHit) override
        {
            SpellRuneCostEntry const* src = sSpellRuneCostStore.LookupEntry(spellInfo->RuneCostID);
            if (!src || (src->NoRuneCost() && src->NoRunicPowerGain()))
                return;

            //Freezing Fog
            if (rimeProcTimer > GetLastDiff() && spellInfo->Id == HOWLING_BLAST_1)
            {
                for (uint8 i = 0; i != RUNE_DEATH; ++i)
                    runeCost[i] = 0;
            }
            else
            {
                for (uint8 i = 0; i != RUNE_DEATH; ++i)
                    runeCost[i] = src->RuneCost[i];
            }

            runeCost[RUNE_DEATH] = 0;

            //debug 1
            //std::ostringstream str;
            //str << "Casted " << spellInfo->SpellName[0] << " cost"
            //    << " " << runeCost[0] << " " << runeCost[1] << " " << runeCost[2] << " " << runeCost[3];

            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                uint8 rune = _runes[i].CurrentRune;
                if (runeCost[rune] > 0 && _runes[i].Cooldown <= 0)
                    if (SpendRune(rune, didHit))
                        runeCost[rune]--;
            }

            runeCost[RUNE_DEATH] = runeCost[RUNE_BLOOD] + runeCost[RUNE_UNHOLY] + runeCost[RUNE_FROST];

            if (runeCost[RUNE_DEATH] > 0)
            {
                for (uint8 i = 0; i != MAX_RUNES && runeCost[RUNE_DEATH] > 0; ++i)
                {
                    if (_runes[i].CurrentRune == RUNE_DEATH && _runes[i].Cooldown <= 0)
                        if (SpendRune(RUNE_DEATH, didHit))
                            runeCost[RUNE_DEATH]--;
                }
            }

            //debug 2
            //uint32 runesLeft[NUM_RUNE_TYPES] = { 0,0,0,0 };
            //for (uint8 i = 0; i != NUM_RUNE_TYPES; ++i)
            //    for (uint8 j = 0; j != MAX_RUNES; ++j)
            //        if (_runes[j].CurrentRune == i && _runes[j].Cooldown <= 0)
            //            runesLeft[i]++;
            //str << " left" << " " << runesLeft[0] << " " << runesLeft[1] << " " << runesLeft[2] << " " << runesLeft[3];
            //BotWhisper(str.str().c_str());

            me->ModifyPower(POWER_RUNIC_POWER, int32(src->RunicPower * runicpowerIncomeMult));

            //BladeBarrier
            if (/*src->RuneCost[RUNE_BLOOD] > 0 && */GetCooledRunesCount(RUNE_BLOOD) > 1)
                me->CastSpell(me, BLADE_BARRIER_BUFF, true);

            //Item - Death Knight T10 Melee 4P Bonus
            if (me->GetLevel() >= 80 && GetCooledRunesCount() == MAX_RUNES)
                me->CastSpell(me, ITEM_DEATH_KNIGHT_T10_MELEE_4P_BUFF, true);
        }

        void getpower()
        {
            runicpower = me->GetPower(POWER_RUNIC_POWER);
            if (me->FindCurrentSpellBySpellId(RUNE_STRIKE_1))
                runicpower = std::max<int32>(runicpower - 200, 0);
        }

        int32 rcost(uint32 spellId) const
        {
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
                return spellInfo->CalcPowerCost(me, spellInfo->GetSchoolMask());
            return 0;
        }

        uint8 GetBotStance() const override { return _presence; }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(false); bot_ai::JustDied(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || Rand() > 20 || IsCasting() || Feasting())
                return;

            //PATH OF FROST
            if (GetSpell(PATH_OF_FROST_1) && HaveRunes(PATH_OF_FROST_1)/* && !me->IsMounted()*/) //works while mounted
            {
                if ((me->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && !me->HasAuraType(SPELL_AURA_WATER_WALK)) ||
                    (master->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING) && !master->HasAuraType(SPELL_AURA_WATER_WALK)))
                {
                    if (doCast(me, GetSpell(PATH_OF_FROST_1)))
                        return;
                }
            }
        }

        void CheckHysteria(uint32 diff)
        {
            if (!IsSpellReady(HYSTERIA_1, diff) || Rand() > 35)
                return;

            Unit* target = nullptr;

            if (master->GetVictim() && master->IsInCombat() && IsMeleeClass(master->GetClass()) &&
                GetHealthPCT(master) > 60 && me->GetDistance(master) < 30 &&
                master->getAttackers().empty() && !CCed(master, true) &&
                !master->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DEATHKNIGHT, 0x20000000, 0x0, 0x0))
                target = master;

            if (IAmFree())
                return;

            if (!target)
            {
                Group const* gr = master->GetGroup();
                if (gr)
                {
                    for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
                    {
                        Player* player = itr->GetSource();
                        if (!player || player == master || player->IsBeingTeleported() ||
                            me->GetMap() != player->FindMap())
                            continue;

                        if (IsMeleeClass(player->GetClass()) && player->GetVictim() && GetHealthPCT(player) > 60 &&
                            me->GetDistance(player) < 30 && player->getAttackers().empty() && !CCed(player, true) &&
                            !player->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DEATHKNIGHT, 0x20000000, 0x0, 0x0))
                        {
                            target = player;
                            break;
                        }

                        if (!player->HaveBot())
                            continue;

                        BotMap const* map = player->GetBotMgr()->GetBotMap();
                        for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                        {
                            Creature* bot = it->second;
                            if (IsMeleeClass(bot->GetBotClass()) && bot->GetVictim() &&
                                bot->GetBotAI()->HasRole(BOT_ROLE_DPS) && !bot->GetBotAI()->HasRole(BOT_ROLE_RANGED) &&
                                GetHealthPCT(bot) > 60 && me->GetDistance(bot) < 30 && !CCed(bot, true) &&
                                !bot->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DEATHKNIGHT, 0x20000000, 0x0, 0x0))
                            {
                                target = bot;
                                break;
                            }
                        }

                        if (target)
                            break;
                    }
                }
            }

            if (!target && me->GetVictim() && HasRole(BOT_ROLE_DPS) && !HasRole(BOT_ROLE_RANGED) &&
                GetHealthPCT(me) > 60 && me->getAttackers().empty() && !CCed(me, true) &&
                !me->GetAuraEffect(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, SPELLFAMILY_DEATHKNIGHT, 0x20000000, 0x0, 0x0))
                target = me;

            if (target && doCast(target, GetSpell(HYSTERIA_1)))
            {
                if (target->GetTypeId() == TYPEID_PLAYER)
                    ReportSpellCast(HYSTERIA_1, LocalizedNpcText(target->ToPlayer(), BOT_TEXT__ON_YOU), target->ToPlayer());
                //if (target != master)
                //{
                //    std::string hystmsg = "Hysteria on " + (target == me ? "myself" : target->GetName()) + "!";
                //    BotWhisper(hystmsg.c_str());
                //}

                return;
            }

            SetSpellCooldown(HYSTERIA_1, 1000); //fail
        }

        void CheckAntiMagic(uint32 diff)
        {
            if (!me->GetVictim() || !me->GetVictim()->HasUnitState(UNIT_STATE_CASTING) || Rand() > 40)
                return;

            Spell const* spell = me->GetVictim()->GetCurrentSpell(CURRENT_GENERIC_SPELL);
            if (!spell || spell->GetTimer() >= 1000 || !spell->GetSpellInfo()->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE))
                return;

            Unit const* u = spell->m_targets.GetUnitTarget();
            if (!u || (IAmFree() ? (u != me) : !(master->GetGroup() && master->GetGroup()->IsMember(spell->m_targets.GetObjectTargetGUID()))))
                return;

            if (u == me && IsSpellReady(ANTI_MAGIC_SHELL_1, diff, false) && runicpower >= rcost(ANTI_MAGIC_SHELL_1))
            {
                if (doCast(me, GetSpell(ANTI_MAGIC_SHELL_1)))
                {
                    getpower();
                    return;
                }
            }

            if (Rand() > 20)
                return;

            u = ObjectAccessor::GetUnit(*me, spell->m_targets.GetObjectTargetGUID());
            if (u && !u->isMoving() && me->GetDistance(u) < 4 && IsSpellReady(ANTI_MAGIC_ZONE_1, diff, false) &&
                HaveRunes(ANTI_MAGIC_ZONE_1) &&
                !u->GetAuraEffect(SPELL_AURA_SCHOOL_ABSORB, SPELLFAMILY_DEATHKNIGHT, 0x20000, 0x0, 0x0))
            {
                if (doCast(me, GetSpell(ANTI_MAGIC_ZONE_1)))
                    return;
            }
        }

        void CheckPresence(uint32 diff)
        {
            if (presencetimer > diff || IAmFree() || IsCasting() || Rand() > 30)
                return;

            uint8 newpresence = IsTank() ? DEATH_KNIGHT_FROST_PRESENCE : DEATH_KNIGHT_BLOOD_PRESENCE;
            if (_presence == newpresence)
            {
                presencetimer = 5000;
                return;
            }

            if (newpresence == DEATH_KNIGHT_FROST_PRESENCE && HaveRunes(FROST_PRESENCE_1))
            {
                if (doCast(me, FROST_PRESENCE_1))
                    return;
            }
            else if (newpresence == DEATH_KNIGHT_BLOOD_PRESENCE && HaveRunes(BLOOD_PRESENCE_1))
            {
                if (doCast(me, BLOOD_PRESENCE_1))
                    return;
            }

            presencetimer = 1000; //fail
        }

        void BreakCC(uint32 diff) override
        {
            if (IsSpellReady(LICHBORNE_1, diff, false) && Rand() < 45 &&
                me->HasAuraWithMechanic((1<<MECHANIC_CHARM)|(1<<MECHANIC_FEAR)|(1<<MECHANIC_SLEEP)))
            {
                if (doCast(me, GetSpell(LICHBORNE_1)))
                    return;
            }

            bot_ai::BreakCC(diff);
        }

        void Counter(uint32 diff)
        {
            if (Rand() > 35)
                return;

            if (IsSpellReady(STRANGULATE_1, diff) && me->IsInCombat() && HaveRunes(STRANGULATE_1))
            {
                Unit* u = FindCastingTarget(CalcSpellMaxRange(STRANGULATE_1), 0, STRANGULATE_1);
                if (u && doCast(u, GetSpell(STRANGULATE_1)))
                    return;
            }

            Unit* target = me->GetVictim();
            if (IsSpellReady(MIND_FREEZE_1, diff, false) && target && me->GetDistance(target) < 5 &&
                runicpower >= rcost(MIND_FREEZE_1) && target->IsNonMeleeSpellCast(false,false,true))
            {
                if (doCast(me->GetVictim(), GetSpell(MIND_FREEZE_1)))
                    getpower();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (me->IsAlive())
            {
                if (runicpowertimer <= diff)
                {
                    if (!me->IsInCombat())
                    {
                        if (me->GetPower(POWER_RUNIC_POWER) > uint32(30.f * runicpowerLossMult))
                            me->SetPower(POWER_RUNIC_POWER, me->GetPower(POWER_RUNIC_POWER) - uint32(30.f * runicpowerLossMult)); //-3 runic power every 2 sec
                        else if (me->GetPower(POWER_RUNIC_POWER) > 0)
                            me->SetPower(POWER_RUNIC_POWER, 0);
                    }
                    runicpowertimer = 2000;
                }
                if (runicpowertimer2 <= diff)
                {
                    if (me->IsInCombat())
                    {
                        if (me->GetPower(POWER_RUNIC_POWER) < me->GetMaxPower(POWER_RUNIC_POWER))
                            me->SetPower(POWER_RUNIC_POWER, me->GetPower(POWER_RUNIC_POWER) + int32(20.f * runicpowerIncomeMult)); //+2 runic power every 5 sec
                        else if (me->GetPower(POWER_RUNIC_POWER) < me->GetMaxPower(POWER_RUNIC_POWER))
                            me->SetPower(POWER_RUNIC_POWER, me->GetMaxPower(POWER_RUNIC_POWER));
                    }
                    runicpowertimer2 = 5000;
                }
                getpower();
            }

            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            //pet is killed or unreachable
            if (GC_Timer <= diff && petSummonTimer <= diff && !me->IsInCombat() && !me->IsMounted() && !me->GetVictim() && !IsCasting() && Rand() < 25 &&
                (!botPet || me->GetDistance2d(botPet) > sWorld->GetMaxVisibleDistanceOnContinents()))
                SummonBotPet();

            if (IsPotionReady())
            {
                if (GetHealthPCT(me) < 40)
                    DrinkPotion(false);
            }

            CheckRacials(diff);
            CheckPresence(diff);

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (IsCasting())
                return;

            Counter(diff);

            //HORN OF WINTER
            if (IsSpellReady(HORN_OF_WINTER_1, diff) && !IAmFree() && Rand() < 25 &&
                ((me->IsInCombat() && runicpower <= 900) ||
                !me->GetAuraEffect(SPELL_AURA_MOD_STAT, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x40000000, 0x0)))
            {
                if (doCast(me, GetSpell(HORN_OF_WINTER_1)))
                    return;
            }
            //BONE SHIELD
            if (IsSpellReady(BONE_SHIELD_1, diff) && HaveRunes(BONE_SHIELD_1) && Rand() < 25 + 65 * IsTank())
            {
                Aura* bone = me->GetAura(GetSpell(BONE_SHIELD_1));
                if (!bone || bone->GetCharges() < 2 || bone->GetDuration() < 10000)
                {
                    if (doCast(me, GetSpell(BONE_SHIELD_1)))
                        return;
                }
            }

            CheckHysteria(diff);
            CheckAntiMagic(diff);

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            CheckUsableItems(diff);

            DoNormalAttack(diff);
        }

        void DoNormalAttack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            CheckAttackState();
            if (!me->IsAlive() || !mytar->IsAlive())
                return;

            //BLOOD TAP
            if (IsSpellReady(BLOOD_TAP_1, diff, false) && Rand() < 65)
            {
                if (doCast(me, GetSpell(BLOOD_TAP_1)))
                    getpower();
            }

            //ICEBOUND FORTITUDE
            if (IsSpellReady(ICEBOUND_FORTITUDE_1, diff, false) && Rand() < 50 && runicpower >= rcost(ICEBOUND_FORTITUDE_1) &&
                GetHealthPCT(me) < std::min<uint32>(60, 35 + uint8(me->getAttackers().size()) * 5) + 20 * IsTank())
            {
                if (doCast(me, GetSpell(ICEBOUND_FORTITUDE_1)))
                {
                    if (!IAmFree())
                        ReportSpellCast(ICEBOUND_FORTITUDE_1, LocalizedNpcText(master, BOT_TEXT__USED), master);

                    getpower();
                }
            }

            //SELFHEAL
            //VAMPIRIC BLOOD
            if (IsSpellReady(VAMPIRIC_BLOOD_1, diff, false) && GetHealthPCT(me) < 50 && (IsTank() || Rand() < 75))
            {
                if (HaveRunes(VAMPIRIC_BLOOD_1) || (IsSpellReady(EMPOWER_RUNE_WEAPON_1, diff, false) && doCast(me, GetSpell(EMPOWER_RUNE_WEAPON_1))))
                {
                    if (doCast(me, GetSpell(VAMPIRIC_BLOOD_1)))
                    {
                        if (!IAmFree())
                            ReportSpellCast(VAMPIRIC_BLOOD_1, LocalizedNpcText(master, BOT_TEXT__USED), master);

                        return;
                    }
                }
            }
            //RUNE TAP
            if (IsSpellReady(RUNE_TAP_1, diff, false) && GetHealthPCT(me) < 65 && Rand() < 50 && HaveRunes(RUNE_TAP_1))
            {
                if (doCast(me, GetSpell(RUNE_TAP_1)))
                    return;
            }
            //LICHBORNE + DEATH COIL
            if ((me->GetCreatureType() == CREATURE_TYPE_UNDEAD || IsSpellReady(LICHBORNE_1, diff, false)) &&
                IsSpellReady(DEATH_COIL_1, diff) && Rand() < 45 && GetHealthPCT(me) < 80 && runicpower >= rcost(DEATH_COIL_1))
            {
                if (me->GetCreatureType() == CREATURE_TYPE_UNDEAD || doCast(me, GetSpell(LICHBORNE_1)))
                {
                    if (doCast(me, GetSpell(DEATH_COIL_1)))
                        return;
                }
            }
            //END SELFHEAL

            //EMPOWER RUNE WEAPON
            if (IsSpellReady(EMPOWER_RUNE_WEAPON_1, diff, false) && Rand() < 50 &&
                GetCooledRunesCount() >= 5 && GetTotalRunesCooldown() >= (RUNE_BASE_COOLDOWN * 5) / 2)
            {
                if (doCast(me, GetSpell(EMPOWER_RUNE_WEAPON_1)))
                {
                    //BotWhisper("ERW used!");
                }
            }

            float dist = me->GetDistance(mytar);
            Unit const* u = mytar->GetVictim();

            //MARK OF BLOOD
            if (IsSpellReady(MARK_OF_BLOOD_1, diff) && u && Rand() < 55 && dist < 30 && HaveRunes(MARK_OF_BLOOD_1) &&
                IsInBotParty(u) && GetHealthPCT(u) < 75 && u->GetDistance(mytar) < 10 &&
                mytar->GetHealth() > me->GetMaxHealth() / 4 * (1 + mytar->getAttackers().size()) &&
                (u == me || IsTank(u) || u->GetTypeId() == TYPEID_PLAYER) &&
                !mytar->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 2285, 0))
            {
                if (doCast(mytar, GetSpell(MARK_OF_BLOOD_1)))
                    return;
            }

            //NON-DISEASE SECTION

            //PLACEHOLDER: ARMY OF THE DEAD

            //RANGED SECTION

            //DARK COMMAND
            if (IsSpellReady(DARK_COMMAND_1, diff, false) && u && u != me && dist < 30 &&
                mytar->GetTypeId() == TYPEID_UNIT && !mytar->IsControlledByPlayer() && Rand() < 50 &&
                !CCed(mytar) && !mytar->HasAuraType(SPELL_AURA_MOD_TAUNT) &&
                (!IsTank(u) || (IsTank() && GetHealthPCT(me) > 67 &&
                (GetHealthPCT(u) < 30 || (IsOffTank() && !IsOffTank(u) && IsPointedOffTankingTarget(mytar)) ||
                (!IsOffTank() && IsOffTank(u) && IsPointedTankingTarget(mytar))))) &&
                ((!IsTankingClass(u->GetClass()) && GetHealthPCT(u) < 80) || IsTank()) &&
                IsInBotParty(u))
            {
                if (doCast(mytar, GetSpell(DARK_COMMAND_1)))
                    return;
            }
            //DARK COMMAND 2 (distant)
            if (IsSpellReady(DARK_COMMAND_1, diff, false) && !IAmFree() && u == me && Rand() < 30 && IsTank() &&
                (IsOffTank() || master->GetBotMgr()->GetNpcBotsCountByRole(BOT_ROLE_TANK_OFF) == 0) &&
                !(me->GetLevel() >= 40 && mytar->GetTypeId() == TYPEID_UNIT &&
                (mytar->ToCreature()->IsDungeonBoss() || mytar->ToCreature()->isWorldBoss())))
            {
                if (Unit* tUnit = FindDistantTauntTarget())
                {
                    if (doCast(tUnit, GetSpell(DARK_COMMAND_1)))
                        return;
                }
            }

            ////DEATH GRIP - DISABLED
            //if (DEATH_GRIP && DeathGrip_cd <= diff && dist < 30 &&
            //    (tank == me && mytar->GetVictim() != me) ||
            //    (mytar->GetVictim() == me && mytar->ToPlayer() && mytar->IsNonMeleeSpellCast(false)) &&
            //    Rand() < 75)
            //{
            //    if (doCast(mytar, DEATH_GRIP))
            //    {
            //        DeathGrip_cd = 25000;
            //        return;
            //    }

            //    DeathGrip_cd = 1000; //fail
            //}

            //UNBREAKABLE ARMOR
            if (IsSpellReady(UNBREAKABLE_ARMOR_1, diff, false) && dist < 10 && HaveRunes(UNBREAKABLE_ARMOR_1) &&
                (IsTank() || !me->getAttackers().empty() || mytar->GetMaxHealth() > me->GetMaxHealth() || Rand() < 35))
            {
                if (doCast(me, GetSpell(UNBREAKABLE_ARMOR_1)))
                {}
            }

            if (!HasRole(BOT_ROLE_DPS))
                return;

            //CHAINS OF ICE
            if (IsSpellReady(CHAINS_OF_ICE_1, diff) && Rand() < 65 && dist < CalcSpellMaxRange(CHAINS_OF_ICE_1) && mytar->isMoving() &&
                !(mytar->GetTypeId() == TYPEID_UNIT && (mytar->ToCreature()->GetCreatureTemplate()->MechanicImmuneMask & (1<<(MECHANIC_SNARE-1)))) &&
                HaveRunes(CHAINS_OF_ICE_1) && !CCed(mytar, true) && (!u || (!IsTank(u) && IsInBotParty(u))) &&
                !mytar->HasAuraWithMechanic(1<<MECHANIC_SNARE))
            {
                if (doCast(mytar, GetSpell(CHAINS_OF_ICE_1)))
                    return;
            }

            //HUNGERING COLD
            if (IsSpellReady(HUNGERING_COLD_1, diff) && Rand() < 30 && runicpower >= rcost(HUNGERING_COLD_1))
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 9.f, 0);
                if (targets.size() >= 3)
                {
                    if (doCast(me, GetSpell(HUNGERING_COLD_1)))
                        return;
                }
            }

            //Diseases in general
            bool noDiseases = (mytar->GetTypeId() == TYPEID_UNIT && (mytar->ToCreature()->GetCreatureTemplate()->MechanicImmuneMask & (1<<(MECHANIC_INFECTED-1))));
            AuraEffect const* blop = noDiseases ? nullptr : mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x2000000, 0x0, me->GetGUID());
            AuraEffect const* frof = noDiseases ? nullptr : mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x4000000, 0x0, me->GetGUID());

            auto [can_do_frost, can_do_shadow, can_do_physical] = CanAffectVictimBools(mytar, SPELL_SCHOOL_FROST, SPELL_SCHOOL_SHADOW, SPELL_SCHOOL_NORMAL);

            //DISEASE SECTION

            //PESTILENCE
            if (IsSpellReady(PESTILENCE_1, diff) && can_do_shadow && blop && frof && dist < 5 && HaveRunes(PESTILENCE_1))
            {
                if (blop->GetBase()->GetDuration() < 5000 || frof->GetBase()->GetDuration() < 5000)
                {
                    if (doCast(mytar, GetSpell(PESTILENCE_1)))
                        return;
                }

                if (Rand() < 35 + 65 * me->GetMap()->IsDungeon())
                {
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets, 13.f, 0, mytar);
                    uint8 count = 0;
                    for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    {
                        //check existing blop and frof
                        if (!(*itr)->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x2000000, 0x0, me->GetGUID()) ||
                            !(*itr)->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x4000000, 0x0, me->GetGUID()))
                            if (++count > 1)
                                break;
                    }
                    if (count > 1 && doCast(mytar, GetSpell(PESTILENCE_1)))
                        return;
                }
            }
            //ICY TOUCH
            if (IsSpellReady(ICY_TOUCH_1, diff) && can_do_frost && !noDiseases && (!frof || frof->GetBase()->GetMaxDuration() < 3000) &&
                dist < CalcSpellMaxRange(ICY_TOUCH_1) && HaveRunes(ICY_TOUCH_1))
            {
                if (doCast(mytar, GetSpell(ICY_TOUCH_1)))
                    return;
            }
            //HOWLING BLAST
            if (IsSpellReady(HOWLING_BLAST_1, diff) && can_do_frost && (rimeProcTimer > diff || Rand() < 70) &&
                (!u || mytar->IsControlledByPlayer() || rimeProcTimer > diff ||
                (u && u != me && IsTank(u) && u->getAttackers().size() > 2)) &&
                dist < CalcSpellMaxRange(HOWLING_BLAST_1) && HaveRunes(HOWLING_BLAST_1))
            {
                if (u && u->getAttackers().size() > 4 &&
                    IsSpellReady(DEATHCHILL_1, diff, false) && doCast(me, GetSpell(DEATHCHILL_1)))
                {/* BotWhisper("Deathchill used!"); */}
                if (doCast(mytar, GetSpell(HOWLING_BLAST_1)))
                    return;
            }

            //END DISEASE SECTION

            //MELEE SECTION

            //FROST STRIKE
            if (IsSpellReady(FROST_STRIKE_1, diff) && can_do_frost && Rand() < 90 && dist < 5 &&
                runicpower >= rcost(FROST_STRIKE_1) &&
                (runicpower >= 1000 || !GetSpell(OBLITERATE_1) || !HaveRunes(OBLITERATE_1)))
            {
                if (doCast(mytar, GetSpell(FROST_STRIKE_1)))
                    return;
            }
            //BLOOD BOIL
            if (IsSpellReady(BLOOD_BOIL_1, diff) && can_do_shadow && IsTank() && Rand() < 25 && HaveRunes(BLOOD_BOIL_1))
            {
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 9.f, 1);
                if (targets.size() >= 4)
                    if (doCast(me, GetSpell(BLOOD_BOIL_1)))
                        return;
            }
            //DEATH AND DECAY
            if (IsSpellReady(DEATH_AND_DECAY_1, diff) && can_do_shadow && Rand() < (10 + 30 * IsTank()) && dist < 8 &&
                HaveRunes(DEATH_AND_DECAY_1))
            {
                if (Unit* target = FindAOETarget(10))
                {
                    if (doCast(target, GetSpell(DEATH_AND_DECAY_1)))
                        return;
                }
            }
            //DEATH COIL
            if (IsSpellReady(DEATH_COIL_1, diff) && can_do_shadow && Rand() < 50 && (dist > 6 || !GetSpell(FROST_STRIKE_1)) &&
                (dist < (IAmFree() ? 30 : 15)) && runicpower > 2 * rcost(DEATH_COIL_1))
            {
                if (doCast(mytar, GetSpell(DEATH_COIL_1)))
                    return;
            }

            MoveBehind(mytar);

            if (!can_do_physical || dist > 5)
                return;

            //PLAGUE STRIKE
            if (IsSpellReady(PLAGUE_STRIKE_1, diff) && !noDiseases && (!blop || blop->GetBase()->GetDuration() < 3000) &&
                HaveRunes(PLAGUE_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(PLAGUE_STRIKE_1)))
                    return;
            }

            //DISEASE SECTION

            //DEATH STRIKE
            if (IsSpellReady(DEATH_STRIKE_1, diff) && blop && frof && Rand() < 60 &&
                GetHealthPCT(me) < (80 - (10*(blop != nullptr) + 10*(frof != nullptr))) &&
                (!me->GetMap()->IsDungeon() || mytar->IsControlledByPlayer()) && HaveRunes(DEATH_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(DEATH_STRIKE_1)))
                    return;
            }
            //OBLITERATE
            if (IsSpellReady(OBLITERATE_1, diff) && (noDiseases || (blop && frof)) && HaveRunes(OBLITERATE_1))
            {
                //DEATHCHILL
                if (IsSpellReady(DEATHCHILL_1, diff, false) && doCast(me, GetSpell(DEATHCHILL_1)))
                {/* BotWhisper("Deathchill used!"); */}
                if (doCast(mytar, GetSpell(OBLITERATE_1)))
                    return;
            }
            //HEART STRIKE - splash
            if (IsSpellReady(HEART_STRIKE_1, diff) && (noDiseases || (blop && frof)) && (IsTank() || Rand() < 40) &&
                HaveRunes(HEART_STRIKE_1) && FindSplashTarget())
            {
                if (doCast(mytar, GetSpell(HEART_STRIKE_1)))
                    return;
            }
            //BLOOD STRIKE
            if (IsSpellReady(BLOOD_STRIKE_1, diff) && (noDiseases || (blop && frof)) && HaveRunes(BLOOD_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(BLOOD_STRIKE_1)))
                    return;
            }
            //SCOURGE STRIKE unused
            //if (IsSpellReady(SCOURGE_STRIKE_1, diff) && (noDiseases || (blop && frof)) && HaveRunes(SCOURGE_STRIKE_1))
            //{
            //    if (doCast(mytar, GetSpell(SCOURGE_STRIKE_1)))
            //        return;
            //}

            //END DISEASE SECTION

            //RUNE STRIKE tank
            if (IsSpellReady(RUNE_STRIKE_1, diff, false) && (IsTank() || runicpower >= 800) &&
                me->HasAuraState(AURA_STATE_DEFENSE) && !me->GetCurrentSpell(CURRENT_MELEE_SPELL) &&
                runicpower >= rcost(RUNE_STRIKE_1))
            {
                if (doCast(mytar, GetSpell(RUNE_STRIKE_1)))
                    return;
            }
        }

        void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& damageinfo) const override
        {
            uint8 lvl = me->GetLevel();
            float fdamage = float(damageinfo.Damages[0].Damage);
            float pctbonus = 0.0f;

            //Blood Gorged part 1 (white attacks): 10% bonus damage for all attacks
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 64 && me->HasAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT))
                pctbonus += 0.1f;

            damageinfo.Damages[0].Damage = uint32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Increased Plague Strike Crit (id 60130): 10% additional critical chance for Plague Strike
            if (baseId == PLAGUE_STRIKE_1)
                crit_chance += 10.f;
            //Scourge / Oblit Crit Up (60134): 5% additional critical chance for Scourge Strike and Obliterate
            if (lvl >= 80 && (baseId == SCOURGE_STRIKE_1 || baseId == OBLITERATE_1))
                crit_chance += 5.f;

            //Killing Machine
            if (AuraEffect const* mach = me->GetAuraEffect(KILLING_MACHINE_BUFF, 0))
                if (mach->IsAffectingSpell(spellInfo))
                    crit_chance += 100.f;
            //Deathchill
            if (AuraEffect const* chil = me->GetAuraEffect(DEATHCHILL_1, 0))
                if (chil->IsAffectingSpell(spellInfo))
                    crit_chance += 100.f;

            //Subversion: 9% additional critical chance for Blood Strike, Scourge Strike, Heart Strike and Obliterate
            if (baseId == BLOOD_STRIKE_1 || baseId == HEART_STRIKE_1 || baseId == SCOURGE_STRIKE_1 || baseId == OBLITERATE_1)
                crit_chance += 9.f;
            //Vicious Strikes (part 1): 6% additional critical chance for Plague Strike and Scourge Strike
            if (baseId == PLAGUE_STRIKE_1 || baseId == SCOURGE_STRIKE_1)
                crit_chance += 6.f;
            //Rime (part 1): 15% additional critical chance for Icy Touch and Obliterate
            if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 60 && (baseId == ICY_TOUCH_1 || baseId == OBLITERATE_1))
                crit_chance += 15.f;
            //Improved Death Strike (part 2): 6% additional critical chance for Death Strike
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 62 && baseId == DEATH_STRIKE_1)
                crit_chance += 6.f;

            //Glyph of Rune Strike: 10% additional critical chance for Rune Strike
            if (baseId == RUNE_STRIKE_1)
                crit_chance += 10.f;

            //Item - Death Knight T8 Melee 2P Bonus: 8% additional critical chance for Death Coil and Frost Strike
            if (lvl >= 80 &&
                (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_DAMAGE ||
                baseId == DEATH_COIL_HEAL || baseId == FROST_STRIKE_1))
                crit_chance += 8.f;
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half

                //Might of Mograine: 45% crit damage bonus for Blood Boil, Blood Strike, Death Strike and Heart Strike
                if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 63 &&
                    (baseId == BLOOD_BOIL_1 || baseId == BLOOD_STRIKE_1 || baseId == DEATH_STRIKE_1 || baseId == HEART_STRIKE_1))
                    pctbonus += 0.45f / 2.f;
                //Guile of Gorefiend (part 1 melee): 45% crit damage bonus for Blood Strike, Frost Strike, Howling Blast and Obliterate
                if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 63 &&
                    (baseId == BLOOD_STRIKE_1 || baseId == FROST_STRIKE_1 ||
                    baseId == HOWLING_BLAST_1 || baseId == OBLITERATE_1))
                    pctbonus += 0.45f / 2.f;
                //Vicious Strikes (part 2): 30% crit damage bonus for Plague Strike and Scourge Strike
                if (baseId == PLAGUE_STRIKE_1 || baseId == SCOURGE_STRIKE_1)
                    pctbonus += 0.3f / 2.f;
            }

            //Increased Blood Strike Damage (52394): 90 bonus damage for Blood Strike and Heart Strike
            if (lvl >= 70 && (baseId == BLOOD_STRIKE_1 || baseId == HEART_STRIKE_1))
                fdamage += 90.f;
            //Copy of Increased Blood Strike Damage (60825): 90 bonus damage for Blood Strike and Heart Strike
            if (lvl >= 80 && (baseId == BLOOD_STRIKE_1 || baseId == HEART_STRIKE_1))
                fdamage += 90.f;
            //Increased Scourge Strike Damage (54809): 91 bonus damage for Scourge Strike
            if (lvl >= 80 && baseId == SCOURGE_STRIKE_1)
                fdamage += 91.f;

            //Outbreak: 30% bonus damage for Plague Strike and 20% for Scourge Strike
            if (lvl >= 57)
            {
                if (baseId == PLAGUE_STRIKE_1)
                    pctbonus += 0.3f;
                else if (baseId == SCOURGE_STRIKE_1)
                    pctbonus += 0.2f;
            }
            //Bloody Strikes: 15% bonus damage for Blood Strike, 45% for Heart Strike and 30% for Blood Boil
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 59)
            {
                if (baseId == BLOOD_STRIKE_1)
                    pctbonus += 0.15f;
                else if (baseId == HEART_STRIKE_1)
                    pctbonus += 0.45f;
                else if (baseId == BLOOD_BOIL_1)
                    pctbonus += 0.3f;
            }
            //Merciless Combat (melee): 12% bonus damage for Icy Touch, Howling Blast, Obliterate and Frost Strike on targets with less than 35% hp
            if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 60 &&
                (baseId == ICY_TOUCH_1 || baseId == HOWLING_BLAST_1 || baseId == OBLITERATE_1 || baseId == FROST_STRIKE_1) &&
                damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                pctbonus += 0.12f;
            //Improved Death Strike (part 1): 30% bonus damage for Death Strike
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 62 && baseId == DEATH_STRIKE_1)
                pctbonus += 0.3f;
            //Blood of the North (part 1): 10% bonus damage for Blood Strike and Frost Strike
            if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 62 && (baseId == BLOOD_STRIKE_1 || baseId == FROST_STRIKE_1))
                pctbonus += 0.1f;
            //Blood Gorged part 1 (melee): 10% bonus damage for all spells
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 64 && me->HasAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT))
                pctbonus += 0.1f;
            //Tundra Stalker (melee): 15% damage bonus on targets affected with Frost Fever
            if ((GetSpec() == BOT_SPEC_DK_FROST) &&
                lvl >= 64 && damageinfo.target->GetAuraEffect(SPELL_AURA_MOD_RANGED_HASTE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x0, 0x2))
                pctbonus += 0.15f;
            //Rage of Rivendare (melee): 10% damage bonus on targets affected with Blood Plague
            if ((GetSpec() == BOT_SPEC_DK_UNHOLY) &&
                lvl >= 64 && damageinfo.target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x2000000, 0x0))
                pctbonus += 0.1f;

            //Glyph of Blood Strike: 20% bonus damage for Blood Strike on snared targets
            if (baseId == BLOOD_STRIKE_1 && damageinfo.target->HasAuraWithMechanic(1<<MECHANIC_SNARE))
                pctbonus += 0.2f;
            //Glyph of Death Strike: 1% bonus damage for every runic power point (max 25) for Death Strike
            if (baseId == DEATH_STRIKE_1 && runicpower >= 10)
            {
                //10 to 250 * 0.001 = 10 to 250 / 1000 = 0.01 to 0.25
                pctbonus += float(std::min<int32>(runicpower, 250)) * 0.001f;
            }
            //Glyph of Obliterate: 25% bonus damage for Obliterate
            if (baseId == OBLITERATE_1)
                pctbonus += 0.25f;
            //Glyph of Plague Strike: 20% bonus damage for Plague Strike
            if (baseId == PLAGUE_STRIKE_1)
                pctbonus += 0.2f;

            //Item - Death Knight T8 Tank 2P Bonus
            if (lvl >= 80 && baseId == RUNE_STRIKE_1)
                pctbonus += 0.1f;
            //Item - Death Knight T8 DPS Relic
            if (lvl >= 80 && baseId == FROST_STRIKE_1)
                fdamage += 380.f;
            //Item - Death Knight T9 Tank 2P Bonus
            if (lvl >= 80 && (baseId == BLOOD_STRIKE_1 || baseId == HEART_STRIKE_1))
                pctbonus += 0.05f;
            //Item - Death Knight T10 Melee 2P Bonus part 1
            if (lvl >= 80 && baseId == OBLITERATE_1)
                pctbonus += 0.1f;
            //Item - Death Knight T10 Melee 2P Bonus part 2
            if (lvl >= 80 && baseId == HEART_STRIKE_1)
                pctbonus += 0.07f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5

                //Runic Focus (class passive): 50% crit damage bonus for all spells
                pctbonus += 0.5f / 1.5f;

                //Guile of Gorefiend (part 1 spell): 45% crit damage bonus for Blood Strike, Frost Strike, Howling Blast and Obliterate
                if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 63 &&
                    (baseId == BLOOD_STRIKE_1 || baseId == FROST_STRIKE_1 ||
                    baseId == HOWLING_BLAST_1 || baseId == OBLITERATE_1))
                    pctbonus += 0.45f / 1.5f;
            }

            //Improved Icy Touch part 1: 15% bonus damage for Icy Touch
            if (baseId == ICY_TOUCH_1)
                pctbonus += 0.15f;
            //Black Ice: 10% bonus damage for Shadow and Frost spells
            if (spellInfo->GetSchoolMask() & (SPELL_SCHOOL_MASK_FROST|SPELL_SCHOOL_MASK_SHADOW))
                pctbonus += 0.1f;
            //Morbidity part 1: 15% damage bonus for Death Coil
            if (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_DAMAGE)
                pctbonus += 0.15f;
            //Glacier Rot: 20% bonus damage for Icy Touch, Howling Blast and Frost Strike on diseased targets
            if ((GetSpec() == BOT_SPEC_DK_FROST) &&
                lvl >= 59 && (baseId == ICY_TOUCH_1 || baseId == HOWLING_BLAST_1 || baseId == FROST_STRIKE_1) &&
                IsDiseased(damageinfo.target))
                pctbonus += 0.2f;
            //Impurity: 20% bonus (from attack power) damage for all spells
            if ((GetSpec() == BOT_SPEC_DK_UNHOLY) && lvl >= 59)
                if (SpellBonusEntry const* bonus = sSpellMgr->GetSpellBonusData(spellInfo->Id))
                    if (bonus->ap_bonus > 0.f)
                        fdamage += bonus->ap_bonus * 0.2f * me->GetTotalAttackPowerValue(BASE_ATTACK);
            //Merciless Combat (spell): 12% bonus damage for Icy Touch, Howling Blast, Obliterate and Frost Strike on targets with less than 35% hp
            if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 60 &&
                (baseId == ICY_TOUCH_1 || baseId == HOWLING_BLAST_1 || baseId == OBLITERATE_1 || baseId == FROST_STRIKE_1) &&
                damageinfo.target->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT))
                pctbonus += 0.12f;
            //Blood Gorged part 1 (spell): 10% bonus damage for all spells
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 64 && me->HasAuraState(AURA_STATE_HEALTH_ABOVE_75_PERCENT))
                pctbonus += 0.1f;
            //Tundra Stalker (spell): 15% damage bonus on targets affected with Frost Fever
            if ((GetSpec() == BOT_SPEC_DK_FROST) &&
                lvl >= 64 && damageinfo.target->GetAuraEffect(SPELL_AURA_MOD_RANGED_HASTE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x0, 0x2))
                pctbonus += 0.15f;
            //Rage of Rivendare (spell): 10% damage bonus on targets affected with Blood Plague
            if ((GetSpec() == BOT_SPEC_DK_UNHOLY) &&
                lvl >= 64 && damageinfo.target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0x0, 0x2000000, 0x0))
                pctbonus += 0.1f;

            //Glyph of Dark Death part 1: 15% damage bonus for Death Coil
            if (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_DAMAGE)
                pctbonus += 0.15f;
            //Glyph of Icy Touch: 20% damage bonus for Frost Fever
            if (baseId == FROST_FEVER || baseId == FROST_FEVER_AURA)
                pctbonus += 0.2f;

            //Item - Death Knight T8 DPS Relic
            if (lvl >= 80 && baseId == DEATH_COIL_DAMAGE)
                fdamage += 113.f;
            //Increased Icy Touch Damage (id 54800): 111 bonus damage for Icy Touch
            if (baseId == ICY_TOUCH_1)
                fdamage += 111.f;
            //Increased Death Coil Damage (id 54807): 80 bonus damage for Death Coil
            if (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_DAMAGE)
                fdamage += 80.f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType /*damagetype*/, uint32 /*stack*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //pct mods
            //Morbidity part 2: 15% bonus healing for Death Coil
            if (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_HEAL)
                pctbonus += 0.15f;
            //Improved Rune Tap part 1: 100% bonus healing for Rune Tap
            if (lvl >= 58 && baseId == RUNE_TAP_1)
                pctbonus += 1.f;
            //Improved Death Strike (part 3): 50% bonus healing for Death Strike
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 62 && baseId == DEATH_STRIKE_HEAL)
                pctbonus += 0.5f;

            //Glyph of Dark Death part 2: 15% bonus healing for Death Coil
            if (baseId == DEATH_COIL_1 || baseId == DEATH_COIL_HEAL)
                pctbonus += 0.15f;
            //Glyph of Rune Tap part 1: 10% bonus healing for Rune Tap
            if (baseId == RUNE_TAP_1)
                pctbonus += 0.1f;

            //flat mods
            //Improved Prayer of Mending: 100 additional heal for Prayer of Mending
            //if (baseId == PRAYER_OF_MENDING_HEAL)
            //    flat_mod += 100;

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //percent mods
            //Endless Winter part 2 -100% Runic Power cost for Mind Freeze
            if (lvl >= 58 && baseId == MIND_FREEZE_1)
                pctbonus += 1.f;

            //Glyph of Blood Tap: -100% Health cost for Blood Tap
            if (baseId == BLOOD_TAP_1)
                pctbonus += 1.f;

            //flat mods
            //Glyph of Frost Strike: -8 Runic Power cost for Frost Strike
            if (baseId == FROST_STRIKE_1)
                flatbonus += 80;
            //Glyph of Hungering Cold: -40 Runic Power cost for Hungering Cold
            if (lvl >= 60 && baseId == HUNGERING_COLD_1)
                flatbonus += 400;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
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
            //Aspiration
            //if (lvl >= 45 && (baseId == INNER_FOCUS_1 || baseId == POWER_INFUSION_1 || baseId == PAIN_SUPPRESSION_1))
            //    pctbonus += 0.2f;

            //flat mods
            //Unholy Command: -10 sec cooldown for Dark Command
            if (lvl >= 56 && baseId == DARK_COMMAND_1)
                timebonus += 10000;
            //Improved Rune Tap part 2: -30 sec cooldown for Rune Tap
            if (lvl >= 57 && baseId == RUNE_TAP_1)
                timebonus += 30000;

            //Glyph of Strangulate: -20 sec cooldown for Strangulate
            if (baseId == STRANGULATE_1)
                timebonus += 20000;

            //Item - Death Knight T9 Tank 2P Bonus
            if (lvl >= 80 && (baseId == UNBREAKABLE_ARMOR_1 || baseId == VAMPIRIC_BLOOD_1 || baseId == BONE_SHIELD_1))
                timebonus += 10000;
            //Strangulate Cooldown Reduction: -5 sec cooldown for Strangulate
            if (baseId == STRANGULATE_1)
                timebonus += 5000;

            //Empower Rune Weapon Cooldown Reduction For Bot: -3 min
            if (baseId == EMPOWER_RUNE_WEAPON_1)
                timebonus += 180000;

            cooldown = int32(std::max<float>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0.f));
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Aspiration
            //if (lvl >= 45 && baseId == PENANCE_1)
            //    pctbonus += 0.2f;

            //flat mods
            //Morbidity part 2
            if (baseId == DEATH_AND_DECAY_1)
                timebonus += 15000;

            //Item - Death Knight T9 Tank 2P Bonus
            if (lvl >= 80 && baseId == DARK_COMMAND_1)
                timebonus += 2000;

            cooldown = int32(std::max<float>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0.f));
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //Unholy Presence
            if (_presence == DEATH_KNIGHT_UNHOLY_PRESENCE &&
                ((spellInfo->SpellFamilyFlags[0] & 0xFFDFFE7F) ||
                (spellInfo->SpellFamilyFlags[0] & 0x480B11F7) ||
                (spellInfo->SpellFamilyFlags[0] & 0x20)))
                timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            ////Holy Reach
            //if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x18400200) || (spellInfo->SpellFamilyFlags[2] & 0x4)))
            //    pctbonus += 0.2f;

            //flat mods
            //Glyph of Corpse Explosion
            if (spellInfo->SpellFamilyFlags[1] & 0x20)
                flatbonus += 5.f;
            //Glyph of Pestilence
            if (baseId == PESTILENCE_1)
                flatbonus += 5.f;

            radius = radius * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            //uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Holy Reach: +20% range for Holy Spells
            //if (lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x100080))
            //    pctbonus += 0.2f;

            //flat mods
            //Icy Reach: +10 yd range for Icy Touch, Chains of Ice and Howling Blast
            if (baseId == ICY_TOUCH_1 || baseId == CHAINS_OF_ICE_1 || baseId == HOWLING_BLAST_1)
                flatbonus += 10.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //Glyph of Rune Tap part 2
            if (baseId == RUNE_TAP_1)
                me->CastSpell(me, GLYPH_RUNE_TAP_HEAL, true);

            //Empower Rune Weapon: rune activation helper
            if (baseId == EMPOWER_RUNE_WEAPON_1)
                ActivateAllRunes();

            //Improved Chains of Ice (62142): convert frost rune into death rune
            if (lvl >= 80 && baseId == CHAINS_OF_ICE_1)
            {
                ConvertRune(RUNE_FROST);
            }
            //Death Rune Mastery: convert Unholy and Frost Runes into Death Runes
            if (lvl >= 57 && (baseId == DEATH_STRIKE_1 || baseId == OBLITERATE_1))
            {
                ConvertRune(RUNE_UNHOLY);
                ConvertRune(RUNE_FROST);
            }
            //Reaping: Blood Strike and Pestilence convert Blood Rune to Death Rune
            if ((GetSpec() == BOT_SPEC_DK_UNHOLY) && lvl >= 60 && (baseId == BLOOD_STRIKE_1 || baseId == PESTILENCE_1))
            {
                ConvertRune(RUNE_BLOOD);
                //Blood of the North (part 2): same effect
                if (lvl >= 62)
                    ConvertRune(RUNE_BLOOD);
            }
            //Rime: consume buff
            if (baseId == HOWLING_BLAST_1 && rimeProcTimer > GetLastDiff() && me->HasAura(RIME_BUFF))
                me->RemoveAurasDueToSpell(RIME_BUFF);
            //Blood Tap
            if (baseId == BLOOD_TAP_1)
            {
                ConvertRune(RUNE_BLOOD);

                //Item - Death Knight T10 Tank 4P Bonus: Blood Armor (12% damage reduce)
                if (lvl >= 80)
                    me->CastSpell(me, ITEM_DEATH_KNIGHT_T10_TANK_4P_BUFF, true);
            }

            //stances
            if (spellInfo->GetCategory() == 47)
            {
                presencetimer = 1000;

                if (baseId == BLOOD_PRESENCE_1)
                    _presence = DEATH_KNIGHT_BLOOD_PRESENCE;
                else if (baseId == FROST_PRESENCE_1)
                    _presence = DEATH_KNIGHT_FROST_PRESENCE;
                else if (baseId == UNHOLY_PRESENCE_1)
                    _presence = DEATH_KNIGHT_UNHOLY_PRESENCE;
            }
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();

            //consume buffs (not on spell go)
            //Killing Machine
            //Deathchill
            AuraEffect const* mach = me->GetAuraEffect(KILLING_MACHINE_BUFF, 0);
            AuraEffect const* chil = me->GetAuraEffect(DEATHCHILL_1, 0);
            if (mach && mach->IsAffectingSpell(spell))
                me->RemoveAurasDueToSpell(KILLING_MACHINE_BUFF);
            else if (chil && chil->IsAffectingSpell(spell))
                me->RemoveAurasDueToSpell(DEATHCHILL_1);

            //Icy Touch tanking helper (TODO: remove this hack after threat mods implementation)
            //emulating passive mod +600% threat generated by Icy Touch while in Frost Presence
            if (baseId == ICY_TOUCH_1 && _presence == DEATH_KNIGHT_FROST_PRESENCE && target->CanHaveThreatList())
            {
                if (SpellThreatEntry const* threatEntry = sSpellMgr->GetSpellThreatEntry(spellId))
                {
                    int32 baseThreat = 0;
                    if (threatEntry->apPctMod != 0x0)
                        baseThreat += int32(threatEntry->apPctMod * me->GetTotalAttackPowerValue(BASE_ATTACK));
                    baseThreat += threatEntry->flatMod;

                    if (baseThreat)
                        target->GetThreatManager().AddThreat(me, baseThreat * 6.f, spell);
                }
            }

            //Improved Icy Touch part 2: 6% increased effect (flat)
            if (baseId == FROST_FEVER_AURA)
            {
                if (Aura const* feve = target->GetAura(spellId, me->GetGUID()))
                {
                    if (AuraEffect* fev1 = feve->GetEffect(1))
                        fev1->ChangeAmount(fev1->GetAmount() - 6);
                    if (AuraEffect* fev2 = feve->GetEffect(2))
                        fev2->ChangeAmount(fev2->GetAmount() - 6);
                }
            }
            //Rime (part 2): Obliterate has 15% chance to reset Howling Blast cooldown
            if ((GetSpec() == BOT_SPEC_DK_FROST) && baseId == OBLITERATE_1 && urand(1,100) <= 15)
            {
                ResetSpellCooldown(HOWLING_BLAST_1);
                me->CastSpell(me, RIME_BUFF, true);
            }

            //Glyph of Horn of Winter: 1 minute bonus duration (8 for bot)
            if (baseId == HORN_OF_WINTER_1)
            {
                if (Aura* horn = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = horn->GetDuration() + 480000;
                    horn->SetDuration(dur);
                    horn->SetMaxDuration(dur);
                }

                //Winter Veil addition
                if (sGameEventMgr->IsActiveEvent(GAME_EVENT_WINTER_VEIL))
                    target->AddAura(44755, target); //snowflakes
            }
            //Epidemic: 6 sec bonus duration for DK Diseases
            if (baseId == FROST_FEVER_AURA || baseId == BLOOD_PLAGUE_AURA ||
                baseId == CRYPT_FEVER_AURA || baseId == EBON_PLAGUE_AURA)
            {
                if (Aura* fever = target->GetAura(spellId, me->GetGUID()))
                {
                    uint32 dur = fever->GetDuration() + 6000;
                    fever->SetDuration(dur);
                    fever->SetMaxDuration(dur);
                }
            }
            //Chilblains: proc Icy Clutch
            if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 61 && baseId == FROST_FEVER_AURA)
                me->CastSpell(target, CHILBLAINS_DEBUFF, true);
            //Sudden Doom: 15% ctc Death Coil on Blood Strike or Heart Strike
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) &&
                (baseId == BLOOD_STRIKE_1 || baseId == HEART_STRIKE_1) && GetSpell(DEATH_COIL_1) && urand(1,100) <= 15)
                me->CastSpell(target, GetSpell(DEATH_COIL_1), true);
            //Glyph of Heart Strike
            if (baseId == HEART_STRIKE_1)
                me->CastSpell(target, GLYPH_HEART_STRIKE_DEBUFF, true);
            //Glyph of Howling Blast
            if (lvl >= 60 && baseId == HOWLING_BLAST_1)
                me->CastSpell(target, FROST_FEVER_AURA, true);
            //Glyph of Scourge Strike
            if (baseId == SCOURGE_STRIKE_1)
                me->CastSpell(target, GLYPH_SCOURGE_STRIKE_EFFECT, true);

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;
            uint32 spellId = spell->Id;
            uint8 lvl = me->GetLevel();

            //Rime helper (Freezing Fog)
            if (baseId == RIME_BUFF)
            {
                rimeProcTimer = 15000;
            }

            //Improved Blood Presence
            if ((GetSpec() == BOT_SPEC_DK_BLOOD) && lvl >= 61 && baseId == BLOOD_PRESENCE_1)
            {
                if (AuraEffect* pres = me->GetAuraEffect(spellId, 1))
                    pres->ChangeAmount(pres->GetAmount() + 10);
            }
            if (baseId == ANTI_MAGIC_SHELL_1)
            {
                if (Aura* shell = me->GetAura(spellId))
                {
                    //Glyph of Anti-Magic Shell: 2 sec increased duration
                    uint32 dur = shell->GetDuration() + 2000;
                    shell->SetDuration(dur);
                    shell->SetMaxDuration(dur);
                    //Magic Suppression part 2
                    if (AuraEffect* shab = shell->GetEffect(0))
                        shab->ChangeAmount(int32(shab->GetAmount() * 1.25f));
                }
            }
            if (baseId == VAMPIRIC_BLOOD_1)
            {
                //Glyph of Vampiric Blood: 5 sec increased duration
                if (Aura* bloo = me->GetAura(spellId))
                {
                    uint32 dur = bloo->GetDuration() + 5000;
                    bloo->SetDuration(dur);
                    bloo->SetMaxDuration(dur);
                }
            }
            if (baseId == BONE_SHIELD_1)
            {
                //Glyph of Bone Shield: 1 bonus charge (1 for bot, 3 for tank)
                if (Aura* bone = me->GetAura(spellId))
                    bone->SetCharges(bone->GetCharges() + (IsTank() ? 3 : 1));
            }
            if (baseId == ICEBOUND_FORTITUDE_1)
            {
                if (Aura* fort = me->GetAura(spellId))
                {
                    //Icebound Duration Increase: + 3 sec duration
                    uint32 dur = fort->GetDuration() + 3000;

                    //Guile of Gorefiend (part 2): Icebound Fortitude 6 sec increased duration
                    if ((GetSpec() == BOT_SPEC_DK_FROST) && lvl >= 63)
                        dur += 6000;

                    fort->SetDuration(dur);
                    fort->SetMaxDuration(dur);

                    if (AuraEffect* eff2 = fort->GetEffect(EFFECT_2))
                    {
                        //calc correct amount
                        int32 amount = eff2->GetAmount() - int32(0.15f * (std::max<int32>(0, GetBotDefense() - lvl*5)));
                        //Glyph of Icebound Fortitude
                        amount = std::min<int32>(amount, -40);
                        //Increased Icebound Fortitude Mitigation (54803)
                        if (lvl >= 70)
                            amount -= 2;
                        eff2->ChangeAmount(amount);
                    }
                }
            }
            if (baseId == UNBREAKABLE_ARMOR_1)
            {
                if (AuraEffect* armo = me->GetAuraEffect(spellId, 0))
                    armo->ChangeAmount(armo->GetAmount() + 5); //25 +20% = 30
            }

            OnSpellHit(caster, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
            if (victim == me)
                return;

            if (damageType == DIRECT_DAMAGE || damageType == SPELL_DIRECT_DAMAGE)
            {
                //Blood Presence Heal
                if (_presence == DEATH_KNIGHT_FROST_PRESENCE || _presence == DEATH_KNIGHT_UNHOLY_PRESENCE)
                {
                    if (int32 bp0 = int32(damage / 25)) //4%
                    {
                        CastSpellExtraArgs args(true);
                        args.AddSpellBP0(bp0);
                        me->CastSpell(me, BLOOD_PRESENCE_HEAL_EFFECT, args);
                    }
                }
            }

            bot_ai::DamageDealt(victim, damage, damageType);
        }

        void DamageTaken(Unit* u, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override
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

        uint8 GetPetPositionNumber(Creature const* /*summon*/) const override
        {
            //TODO: garg, aod, drw
            return 0;
        }

        void SummonBotPet()
        {
            if (botPet)
                UnsummonAll(false);

            uint32 entry = BOT_PET_GHOUL;

            Position pos;

            Creature* myPet = me->SummonCreature(entry, *me, TEMPSUMMON_CORPSE_DESPAWN);
            me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.f, float(me->GetOrientation() + M_PI / 2.f));
            myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            botPet = myPet;
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonPet(savePets);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDies: {}'s {}", me->GetName(), summon->GetName());
            //if (summon == botPet)
            //    botPet = nullptr;
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //all hunter bot pets despawn at death or manually (gossip, teleport, etc.)
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            if (summon == botPet)
            {
                petSummonTimer = 30000;
                botPet = nullptr;
            }
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_GHOUL;
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            UnsummonAll(false);

            petSummonTimer = 5000;

            presencetimer = 0;
            runicpowertimer = 2000;
            runicpowertimer2 = 5000;

            rimeProcTimer = 0;

            _presence = BOT_STANCE_NONE;

            runicpowerIncomeMult = sWorld->getRate(RATE_POWER_RUNICPOWER_INCOME);
            runicpowerLossMult = sWorld->getRate(RATE_POWER_RUNICPOWER_LOSS);

            DefaultInit();
            InitRunes();
        }

        void ReduceCD(uint32 diff) override
        {
            RuneTimers(diff);

            if (presencetimer > diff)               presencetimer -= diff;
            if (runicpowertimer > diff)             runicpowertimer -= diff;
            if (runicpowertimer2 > diff)            runicpowertimer2 -= diff;

            if (rimeProcTimer > diff)               rimeProcTimer -= diff;

            if (petSummonTimer > diff)              petSummonTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_RUNIC_POWER);
            me->SetMaxPower(POWER_RUNIC_POWER, 1300);
            //RefreshAura(RUNIC_POWER_MASTERY);
            //if (AuraEffect* mast = me->GetAuraEffect(RUNIC_POWER_MASTERY, 0))
            //{
            //    //Runic Power Mastery rank 2
            //    mast->ChangeAmount(1300);
            //}

            if (botPet && botPet->GetPowerType() != POWER_ENERGY)
                botPet->SetByteValue(UNIT_FIELD_BYTES_0, 3, POWER_ENERGY);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isBloo = GetSpec() == BOT_SPEC_DK_BLOOD;
            bool isFros = GetSpec() == BOT_SPEC_DK_FROST;
            bool isUnho = GetSpec() == BOT_SPEC_DK_UNHOLY;

            InitSpellMap(ICY_TOUCH_1);
            InitSpellMap(PLAGUE_STRIKE_1);
            InitSpellMap(BLOOD_STRIKE_1);
            InitSpellMap(DEATH_STRIKE_1);
            InitSpellMap(OBLITERATE_1);
            InitSpellMap(RUNE_STRIKE_1);
            InitSpellMap(BLOOD_BOIL_1);
            InitSpellMap(DEATH_AND_DECAY_1);
            InitSpellMap(DEATH_COIL_1);
            InitSpellMap(DEATH_GRIP_1);
            InitSpellMap(PESTILENCE_1);
            InitSpellMap(MIND_FREEZE_1);
            InitSpellMap(STRANGULATE_1);
            InitSpellMap(CHAINS_OF_ICE_1);
            InitSpellMap(ICEBOUND_FORTITUDE_1);
            InitSpellMap(DARK_COMMAND_1);
            InitSpellMap(ANTI_MAGIC_SHELL_1);
            InitSpellMap(ARMY_OF_THE_DEAD_1);
            InitSpellMap(PATH_OF_FROST_1);
            InitSpellMap(HORN_OF_WINTER_1);
            InitSpellMap(EMPOWER_RUNE_WEAPON_1);
            InitSpellMap(BLOOD_TAP_1);

  /*Talent*/lvl >= 57 ? InitSpellMap(RUNE_TAP_1) : RemoveSpell(RUNE_TAP_1);
  /*Talent*/lvl >= 59 && isBloo ? InitSpellMap(MARK_OF_BLOOD_1) : RemoveSpell(MARK_OF_BLOOD_1);
  /*Talent*/lvl >= 61 && isBloo ? InitSpellMap(HYSTERIA_1) : RemoveSpell(HYSTERIA_1);
  /*Talent*/lvl >= 62 && isBloo ? InitSpellMap(VAMPIRIC_BLOOD_1) : RemoveSpell(VAMPIRIC_BLOOD_1);
  /*Talent*/lvl >= 63 && isBloo ? InitSpellMap(HEART_STRIKE_1) : RemoveSpell(HEART_STRIKE_1);

  /*Talent*/lvl >= 57 ? InitSpellMap(LICHBORNE_1) : RemoveSpell(LICHBORNE_1);
  /*Talent*/lvl >= 59 && isFros ? InitSpellMap(DEATHCHILL_1) : RemoveSpell(DEATHCHILL_1);
  /*Talent*/lvl >= 61 && isFros ? InitSpellMap(HUNGERING_COLD_1) : RemoveSpell(HUNGERING_COLD_1);
  /*Talent*/lvl >= 62 && isFros ? InitSpellMap(UNBREAKABLE_ARMOR_1) : RemoveSpell(UNBREAKABLE_ARMOR_1);
  /*Talent*/lvl >= 63 && isFros ? InitSpellMap(FROST_STRIKE_1) : RemoveSpell(FROST_STRIKE_1);
  /*Talent*/lvl >= 65 && isFros ? InitSpellMap(HOWLING_BLAST_1) : RemoveSpell(HOWLING_BLAST_1);

  /*Talent*/lvl >= 61 && isUnho ? InitSpellMap(ANTI_MAGIC_ZONE_1) : RemoveSpell(ANTI_MAGIC_ZONE_1);
  /*Talent*/lvl >= 62 && isUnho ? InitSpellMap(BONE_SHIELD_1) : RemoveSpell(BONE_SHIELD_1);
  /*Talent*/lvl >= 63 && isUnho ? InitSpellMap(SCOURGE_STRIKE_1) : RemoveSpell(SCOURGE_STRIKE_1);

            InitSpellMap(BLOOD_PRESENCE_1, true);
            InitSpellMap(FROST_PRESENCE_1, true);
            InitSpellMap(UNHOLY_PRESENCE_1, true);
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isBloo = GetSpec() == BOT_SPEC_DK_BLOOD;
            bool isFros = GetSpec() == BOT_SPEC_DK_FROST;
            bool isUnho = GetSpec() == BOT_SPEC_DK_UNHOLY;

            RefreshAura(BUTCHERY, level >= 55 ? 1 : 0);
            RefreshAura(BLADED_ARMOR, level >= 56 ? 1 : 0);
            RefreshAura(SCENT_OF_BLOOD, level >= 56 ? 1 : 0);
            RefreshAura(TWO_HANDED_WEAPON_SPECIALIZATION, level >= 56 ? 1 : 0);
            RefreshAura(SPELL_DEFLECTION, isBloo && level >= 58 ? 1 : 0);
            RefreshAura(VENDETTA, isBloo && level >= 58 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE3, isBloo && level >= 62 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE2, isBloo && level >= 61 && level < 62 ? 1 : 0);
            RefreshAura(BLOODY_VENGEANCE1, isBloo && level >= 60 && level < 61 ? 1 : 0);
            RefreshAura(ABOMINATIONS_MIGHT, !IAmFree() && isBloo && level >= 60 ? 1 : 0);
            //RefreshAura(BLOODWORMS, isBloo && level >= 61 ? 1 : 0);
            RefreshAura(IMPROVED_BLOOD_PRESENCE, isBloo && level >= 61 ? 1 : 0);
            RefreshAura(WILL_OF_THE_NECROPOLIS, isBloo && level >= 63 ? 1 : 0);

            RefreshAura(TOUGHNESS, level >= 55 ? 1 : 0);
            RefreshAura(ICY_TALONS, level >= 57 ? 1 : 0);
            RefreshAura(ANNIHILATION, level >= 57 ? 1 : 0);
            RefreshAura(KILLING_MACHINE, isFros && level >= 58 ? 1 : 0);
            RefreshAura(CHILL_OF_THE_GRAVE, isFros && level >= 58 ? 1 : 0);
            RefreshAura(FRIGID_DREADPLATE, isFros && level >= 59 ? 1 : 0);
            RefreshAura(IMPROVED_ICY_TALONS, !IAmFree() && isFros && level >= 60 ? 1 : 0);
            RefreshAura(THREAT_OF_THASSARIAN, isFros && level >= 62 ? 1 : 0);
            RefreshAura(ACCLIMATION, isFros && level >= 63 ? 1 : 0);

            RefreshAura(NECROSIS5, isUnho && level >= 62 ? 1 : 0);
            RefreshAura(NECROSIS4, isUnho && level >= 60 && level < 61 ? 1 : 0);
            RefreshAura(NECROSIS3, isUnho && level >= 59 && level < 60 ? 1 : 0);
            RefreshAura(NECROSIS2, isUnho && level >= 58 && level < 59 ? 1 : 0);
            RefreshAura(NECROSIS1, isUnho && level >= 57 && level < 58 ? 1 : 0);
            RefreshAura(ON_A_PALE_HORSE_A, isUnho && level >= 58 ? 1 : 0);
            RefreshAura(ON_A_PALE_HORSE_B, isUnho && level >= 58 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE3, isUnho && level >= 60 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE2, isUnho && level >= 59 && level < 60 ? 1 : 0);
            RefreshAura(BLOOD_CAKED_BLADE1, isUnho && level >= 58 && level < 59 ? 1 : 0);
            RefreshAura(UNHOLY_BLIGHT, isUnho && level >= 59 ? 1 : 0);
            RefreshAura(DIRGE, isUnho && level >= 59 ? 1 : 0);
            RefreshAura(DESECRATION, isUnho && level >= 60 ? 1 : 0);
            RefreshAura(DESOLATION, isUnho && level >= 61 ? 1 : 0);
            RefreshAura(IMPROVED_UNHOLY_PRESENCE, isUnho && level >= 61 ? 1 : 0);
            RefreshAura(CRYPT_FEVER, isUnho && level >= 62 ? 1 : 0);
            RefreshAura(WANDERING_PLAGUE, isUnho && level >= 63 ? 1 : 0);
            RefreshAura(EBON_PLAGUEBRINGER, isUnho && level >= 63 ? 1 : 0);

            //RefreshAura(GLYPH_DANCING_RUNE_WEAPON, level >= 60 ? 1 : 0);
            RefreshAura(GLYPH_DISEASE);
            RefreshAura(GLYPH_CHAINS_OF_ICE);
            RefreshAura(GLYPH_UNHOLY_BLIGHT, level >= 60 ? 1 : 0);

            RefreshAura(CHAINS_OF_ICE_FROST_RUNE_REFRESH);
            RefreshAura(ITEM_DEATH_KNIGHT_T8_MELEE_4P, level >= 80 ? 1 : 0);
            RefreshAura(ITEM_DEATH_KNIGHT_T9_MELEE_4P, level >= 80 ? 1 : 0);

            RefreshAura(FROST_FEVER);
            RefreshAura(BLOOD_PLAGUE);
            RefreshAura(RUNE_STRIKE_PASSIVE);
        }

        bool CanUseManually(uint32 basespell) const override
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

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Deathknight_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Deathknight_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &Deathknight_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Deathknight_spells_support;
        }

    private:
        BotRuneInfo _runes[MAX_RUNES];

/*tmrs*/uint32 presencetimer, runicpowertimer, runicpowertimer2;
        uint32 rimeProcTimer;
/*misc*/int32 runicpower;
/*misc*/int32 runeCost[NUM_RUNE_TYPES];
/*misc*/float runicpowerIncomeMult, runicpowerLossMult;
/*Chck*/uint8 _presence;
        //Pet
        uint32 petSummonTimer;

        bool HaveRunes(uint32 spellId)
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
            return (spellInfo && HaveRunes(spellInfo));
        }

        bool HaveRunes(SpellInfo const* spellInfo)
        {
            if (spellInfo->PowerType != POWER_RUNE || !spellInfo->RuneCostID)
                return true;

            SpellRuneCostEntry const* src = sSpellRuneCostStore.LookupEntry(spellInfo->RuneCostID);
            if (!src || src->NoRuneCost())
                return true;

            //Freezing Fog
            if (rimeProcTimer > GetLastDiff() && spellInfo->Id == HOWLING_BLAST_1)
                return true;

            for (uint8 i = 0; i != RUNE_DEATH; ++i)
                runeCost[i] = src->RuneCost[i];

            runeCost[RUNE_DEATH] = MAX_RUNES;

            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                uint8 rune = _runes[i].CurrentRune;
                if (runeCost[rune] > 0 && _runes[i].Cooldown <= 0)
                    runeCost[rune]--;
            }

            for (uint8 i = 0; i != RUNE_DEATH; ++i)
                if (runeCost[i] > 0)
                    runeCost[RUNE_DEATH] += runeCost[i];

            if (runeCost[RUNE_DEATH] > MAX_RUNES)
                return false;

            return true;
        }

        bool SpendRune(uint8 runetype, bool didHit)
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                if (_runes[i].CurrentRune == runetype && _runes[i].Cooldown <= 0)
                {
                    _runes[i].CurrentRune = _runes[i].BaseRune;
                    uint32 cooldown = didHit ? RUNE_BASE_COOLDOWN : RUNE_MISS_COOLDOWN;

                    //Improved Unholy Presence
                    if (_presence == DEATH_KNIGHT_UNHOLY_PRESENCE)
                        cooldown -= 1000;

                    _runes[i].Cooldown += cooldown;
                    return true;
                }
            }

            return false;
        }

        uint8 GetCooledRunesCount(uint8 runetype) const
        {
            uint8 count = 0;
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                if (_runes[i].BaseRune == runetype && _runes[i].Cooldown > 0)
                    ++count;

            return count;
        }

        uint8 GetCooledRunesCount() const
        {
            uint8 count = 0;
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                if (_runes[i].Cooldown > 0)
                    ++count;

            return count;
        }

        uint32 GetTotalRunesCooldown() const
        {
            uint32 totalCd = 0;
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                totalCd += std::max<int32>(_runes[i].Cooldown, 0);

            return totalCd;
        }

        void ConvertRune(uint8 runetype)
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                if (_runes[i].CurrentRune == runetype)
                {
                    _runes[i].CurrentRune = RUNE_DEATH;
                    return;
                }
            }
        }

        void ActivateAllRunes()
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
                _runes[i].Cooldown = std::min<int32>(_runes[i].Cooldown, me->IsInCombat() ? -1 : 0);
        }

        void InitRunes()
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                _runes[i].BaseRune = runeSlotTypes[i];
                _runes[i].CurrentRune = _runes[i].BaseRune;
                _runes[i].Cooldown = 0;
            }
        }

        void RuneTimers(uint32 diff)
        {
            for (uint8 i = 0; i != MAX_RUNES; ++i)
            {
                int32 &cd = _runes[i].Cooldown;
                if (me->IsInCombat())
                {
                    //RGP
                    if (cd != 0)
                    {
                        if (cd >= int32(-2500 + diff))
                            cd -= diff;
                        else if (cd != -2500)
                            cd = -2500;
                        //ensurance
                        if (!cd)
                            --cd;
                    }
                }
                else
                {
                    if (cd >= int32(diff))
                        cd -= diff;
                    else if (cd)
                        cd = 0;
                }
            }
        }

        bool IsDiseased(Unit const* unit) const
        {
            static const AuraType botDiseaseAuraTypes[] =
            {
                SPELL_AURA_PERIODIC_DAMAGE, // Frost Fever and Blood Plague
                SPELL_AURA_LINKED,          // Crypt Fever and Ebon Plague
                SPELL_AURA_NONE
            };

            for (AuraType const* itr = botDiseaseAuraTypes; *itr != SPELL_AURA_NONE; ++itr)
            {
                Unit::AuraEffectList const& disAuras = unit->GetAuraEffectsByType(*itr);
                for (Unit::AuraEffectList::const_iterator ditr = disAuras.begin(); ditr != disAuras.end(); ++ditr)
                {
                    // Get auras with disease dispel type by caster
                    if ((*ditr)->GetSpellInfo()->Dispel == DISPEL_DISEASE)
                        return true;
                }
            }

            return false;
        }
    };
};

void AddSC_death_knight_bot()
{
    new death_knight_bot();
}
