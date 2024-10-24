#include "bot_ai.h"
#include "botdatamgr.h"
#include "botspell.h"
#include "bottext.h"
#include "CellImpl.h"
#include "Containers.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "WorldPacket.h"
/*
Crypt Lord NpcBot (by Trickerer onlysuffering@gmail.com)
Description:
Ancient behemoth, once one of the kings of Azjol-Nerub, now an undead monster within ranks of Lich King's mightiest warriors
Specifics:
Very high armor, increased resistances, partially immune to control effects, immune to poison-based effects, mail/plate armor,
deals melee/spellshadow damage, spell power bonus: 200% strength
Abilities:
1) Impale. Crypt Lord slams the ground with his massive claws, shooting spikes out in a frontal cone,
dealing damage and hurling enemy units into the air in their wake, stunning them. Unlocked at level 20.
2) Spiked Carapace. Crypt Lord's chitinous armor increases damage resistance and returns 15% to 50% damage to enemy melee attackers.
3) Carrion Beetles. Crypt Lord progenerates a Carrion Beetle from a fresh corpse of an enemy to attack his enemies.
Beetles are permanent but do not regenerate health and only 6 can be controlled at a time.
Higher levels allow Crypt Lord to summon more powerful beetles. Unlocked at level 10.
4) Locust Swarm. Crypt Lord releases a swarm of 20-40 (depends on Crypt Lord's level) angry locusts
that bite and tear at nearby enemy units, reducing their ability to move or attack. As they chew the enemy flesh,
they convert it into a substance that restores hit points to the Crypt Lord when they return. Unlocked at level 40.
Complete - 100%
TODO:
*/

#ifdef _MSC_VER
# pragma warning(push, 4)
#endif

static constexpr float IMPALE_DAMAGE_TIME_MS_FULL = 400.0f;
static constexpr float IMPALE_DAMAGE_DIST_MAX = 40.0f;
static constexpr float IMPALE_DAMAGE_DELAY_MS_PER_YD = IMPALE_DAMAGE_TIME_MS_FULL / IMPALE_DAMAGE_DIST_MAX;

enum CryptLordBaseSpells
{
//28786
//54022
    IMPALE_1                = SPELL_IMPALE,
    CARRION_BEETLES_1       = SPELL_CARRION_BEETLES,
    LOCUST_SWARM_1          = SPELL_LOCUST_SWARM
};
enum CryptLordPassives
{
};
enum CryptLordSpecial
{
    MH_ATTACK_ANIM          = SPELL_ATTACK_MELEE_1H,

    SPIKED_CARAPACE_DAMAGE  = SPELL_SPIKED_CARAPACE_DAMAGE,
    IMPALE_DAMAGE           = SPELL_IMPALE_DAMAGE,
    IMPALE_VISUAL           = SPELL_IMPALE_VISUAL,
    STUN_VISUAL             = 18970, // "Self Stun - (Visual only)"

    IMPALE_COST             = 100 * 5,
    CARRION_BEETLES_COST    = 30 * 5,
    LOCUST_SWARM_COST       = 150 * 5,

    MAX_MINIONS             = 6,

    SPELL_BLOODY_EXPLOSION  = 36599,

    MODEL_BLOODY_BONES      = 25538,

    IMPALE_MIN_TARGETS      = 3,

    LOCUST_SWARM_MIN_LEVEL  = 40,

    MAX_LOCUSTS_BASE        = 20,
    MAX_LOCUSTS_70          = 30,
    MAX_LOCUSTS_MAXLEVEL    = 40
};

static const uint32 CryptLord_spells_damage_arr[] =
{ IMPALE_1, LOCUST_SWARM_1 };

static const uint32 CryptLord_spells_cc_arr[] =
{ IMPALE_1, LOCUST_SWARM_1 };

static const uint32 CryptLord_spells_support_arr[] =
{ CARRION_BEETLES_1 };

static const std::vector<uint32> CryptLord_spells_damage(FROM_ARRAY(CryptLord_spells_damage_arr));
static const std::vector<uint32> CryptLord_spells_cc(FROM_ARRAY(CryptLord_spells_cc_arr));
static const std::vector<uint32> CryptLord_spells_support(FROM_ARRAY(CryptLord_spells_support_arr));

class crypt_lord_bot : public CreatureScript
{
public:
    crypt_lord_bot() : CreatureScript("crypt_lord_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new crypt_lord_botAI(creature);
    }
/*
    bool OnGossipHello(Player* player, Creature* creature) override
    {
        return creature->GetBotAI()->OnGossipHello(player, 0);
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelect(player, creature, sender, action);
        return true;
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code) override
    {
        if (bot_ai* ai = creature->GetBotAI())
            return ai->OnGossipSelectCode(player, creature, sender, action, code);
        return true;
    }
*/
    struct crypt_lord_botAI : public bot_ai
    {
        crypt_lord_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_CRYPT_LORD;

            InitUnitFlags();

            //crypt_lord immunities
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_POSSESS, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_SHAPESHIFT, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_TRANSFORM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_DISARM_OFFHAND, true);
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_TURN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SLEEP, true);

            _locusts.resize(MAX_LOCUSTS_MAXLEVEL, ObjectGuid::Empty);
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            if (spellId == GetSpell(IMPALE_1))
            {
                me->AttackStop();
                me->BotStopMovement();
                me->SetInFront(victim);
            }
            else if (spellId == GetSpell(LOCUST_SWARM_1))
            {
                me->AttackStop();
                me->BotStopMovement();
            }
            return bot_ai::doCast(victim, spellId);
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonLocusts(true); UnsummonAll(false); bot_ai::JustDied(u); }

        void DoNonCombatActions(uint32 diff)
        {
            CheckCarrionBeetles(diff);
        }

        void CheckCarrionBeetles(uint32 diff)
        {
            if (!IsSpellReady(CARRION_BEETLES_1, diff) || _carrionBeetlesCheckTimer > diff || _minions.size() >= MAX_MINIONS ||
                me->GetPower(POWER_MANA) < CARRION_BEETLES_COST || Rand() > 50)
                return;

            _carrionBeetlesCheckTimer = urand(2000, 3000);

            auto corpse_pred = [this, mindist = 30.f](Creature const* c) mutable {
                if (_isUsableCorpse(c) && c->GetDistance(me) < mindist)
                {
                    mindist = c->GetDistance(me);
                    return true;
                }
                return false;
            };
            Creature* creature = nullptr;
            Trinity::CreatureSearcher searcher(me, creature, corpse_pred);
            Cell::VisitAllObjects(me, searcher, 30.f);

            if (creature)
            {
                me->SetInFront(creature);
                if (doCast(creature, GetSpell(CARRION_BEETLES_1)))
                    return;
            }
        }

        void CheckLocustSwarm(uint32 diff)
        {
            if (!IsSpellReady(LOCUST_SWARM_1, diff) || _locustSwarmCheckTimer > diff || me->GetPower(POWER_MANA) < LOCUST_SWARM_COST ||
                GetHealthPCT(me) > 40 || Rand() > 35)
                return;

            _locustSwarmCheckTimer = urand(1500, 3500);

            std::list<Unit*> targets;
            GetNearbyTargetsList(targets, 50.0f, 0);

            if (targets.empty()) // impossible
                return;

            if (targets.size() > 1u || targets.front()->IsControlledByPlayer())
            {
                if (doCast(me, GetSpell(LOCUST_SWARM_1)))
                    return;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (IsPotionReady())
            {
                if (me->GetPower(POWER_MANA) < 550)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50)
                    DrinkPotion(false);
            }

            if (IsCasting())
                return;

            //if (IsSpellReady(INFERNO_1, diff) && !botPet && me->IsInCombat() &&
            //    me->GetPower(POWER_MANA) >= INFERNAL_COST && Rand() < 60)
            //{
            //    Unit* target = FindAOETarget(CalcSpellMaxRange(INFERNO_1));

            //    if (target)
            //        _infernoPos = target->GetPosition();
            //    else
            //        me->GetNearPoint(me, _infernoPos.m_positionX, _infernoPos.m_positionY, _infernoPos.m_positionZ, 5.f, 0.f);

            //    me->CastSpell(_infernoPos, GetSpell(INFERNO_1), false);
            //    return;
            //}

            if (ProcessImmediateNonAttackTarget())
                return;

            if (!CheckAttackTarget())
                return;

            CheckLocustSwarm(diff);

            CheckUsableItems(diff);

            Attack(diff);
        }

        void Attack(uint32 diff)
        {
            Unit* mytar = opponent ? opponent : disttarget ? disttarget : nullptr;
            if (!mytar)
                return;

            StartAttack(mytar, IsMelee());

            MoveBehind(mytar);

            if (!HasRole(BOT_ROLE_DPS))
                return;

            if (IsSpellReady(IMPALE_1, diff) && _impaleCheckTimer <= diff && me->GetPower(POWER_MANA) >= IMPALE_COST &&
                me->isAttackReady() && Rand() < 75)
            {
                _impaleCheckTimer = urand(800, 1600);

                SpellInfo const* impaleSpellInfo = sSpellMgr->AssertSpellInfo(GetSpell(IMPALE_1));
                impaleSpellInfo = impaleSpellInfo->TryGetSpellInfoOverride(me);
                if (me->GetExactDist(mytar) < IMPALE_DAMAGE_DIST_MAX &&
                    (mytar->IsNonMeleeSpellCast(false) || GetManaPCT(me) > 90 || mytar->GetHealth() < me->GetMaxHealth() / 4 ||
                        (mytar->IsControlledByPlayer() && mytar->GetHealth() > me->GetHealth())) &&
                    !(mytar->IsImmunedToSpellEffect(impaleSpellInfo, impaleSpellInfo->GetEffect(EFFECT_1), me) &&
                     mytar->IsImmunedToSpellEffect(impaleSpellInfo, impaleSpellInfo->GetEffect(EFFECT_2), me)))
                {
                    Spell const* tarSpell = mytar->GetCurrentSpell(CURRENT_GENERIC_SPELL);
                    tarSpell = tarSpell ? tarSpell : mytar->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
                    if (!tarSpell || tarSpell->GetTimer() > 500)
                    {
                        if (doCast(mytar, GetSpell(IMPALE_1)))
                            return;
                    }
                }

                static const std::array my_angles = { 0.0f, float(M_PI / 2), float(M_PI / 2) * 2.0f, float(M_PI / 2) * 3.0f };

                std::list<Unit*> impale_targets;
                GetNearbyTargetsList(impale_targets, IMPALE_DAMAGE_DIST_MAX, 0);

                std::array<decltype(impale_targets), std::size(my_angles)> direction_targets{};
                for (Unit* u : impale_targets)
                {
                    float angle = me->GetRelativeAngle(u);
                    for (size_t i = 0; i < std::size(my_angles); ++i)
                    {
                        float rborder = Position::NormalizeOrientation(my_angles[i] - float(M_PI) * 0.25f);
                        float lborder = Position::NormalizeOrientation(my_angles[i] + float(M_PI) * 0.25f);
                        if ((angle > rborder && angle < lborder) || u->IsWithinMeleeRange(me))
                        {
                            direction_targets[i].push_back(u);
                            break;
                        }
                    }
                }

                std::add_pointer_t<std::add_const_t<decltype(impale_targets)>> chosen_targets = nullptr;
                size_t max_count = IMPALE_MIN_TARGETS - 1;
                for (decltype(direction_targets)::value_type const& tlist : direction_targets)
                {
                    if (tlist.size() > max_count)
                    {
                        chosen_targets = &tlist;
                        max_count = tlist.size();
                    }
                }

                if (chosen_targets)
                {
                    Unit* target = Trinity::Containers::SelectRandomContainerElement(*chosen_targets);
                    if (target && doCast(target, GetSpell(IMPALE_1)))
                        return;
                }
            }

            CheckAttackState();
            //if (!me->IsAlive() || !mytar->IsAlive())
            //    return;
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool /*iscrit*/) const override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            // apply bonus damage mods
            float pctbonus = 1.0f;

            //Impale Damage scaling from AP
            if (lvl >= 40 && baseId == IMPALE_DAMAGE)
            {
                float ap_factor = lvl >= 60 ? 0.125f : 0.0625f;
                float total_ap = me->GetTotalAttackPowerValue(BASE_ATTACK);
                fdamage += total_ap * ap_factor;
                if (lvl >= 70)
                    pctbonus *= 1.1f;
                if (lvl >= DEFAULT_MAX_LEVEL)
                    pctbonus *= 1.2f;
            }

            damage = int32(fdamage * pctbonus);
        }

        //void ApplyClassSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const override
        //{
        //    uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
        //    float flatbonus = 0.0f;
        //    float pctbonus = 0.0f;

        //    //100% mods
        //    if (baseId == IMPALE_DAMAGE)
        //        radius = 0.0f;

        //    radius = radius * (1.0f + pctbonus) + flatbonus;
        //}

        void OnClassSpellStart(SpellInfo const* spellInfo) override
        {
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            switch (baseId)
            {
                case IMPALE_1:
                case CARRION_BEETLES_1:
                    me->CastSpell(me, MH_ATTACK_ANIM, true);
                    break;
                case LOCUST_SWARM_1:
                    _handleLocustSwarm();
                    break;
                default:
                    break;
            }
        }

        void OnClassSpellGo(SpellInfo const* /*spellInfo*/) override
        {
        }

        void OnClassChannelFinish(Spell const* spell) override
        {
            SpellInfo const* spellInfo = spell->GetSpellInfo();
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            if (baseId == IMPALE_1 || baseId == CARRION_BEETLES_1 || baseId == LOCUST_SWARM_1)
            {
                if (baseId == CARRION_BEETLES_1)
                {
                    ObjectGuid target_guid = spell->m_targets.GetUnitTargetGUID();
                    if (Unit* spellTarget = ObjectAccessor::GetUnit(*me, target_guid))
                    {
                        ASSERT(!IsInBotParty(spellTarget));
                        spellTarget->CastSpell(spellTarget, SPELL_BLOODY_EXPLOSION, true);
                        spellTarget->SetDisplayId(MODEL_BLOODY_BONES);

                        for (int32 i = 0; i < spellInfo->GetEffect(EFFECT_0).BasePoints; ++i)
                            SummonBotPet(spellTarget);
                    }
                }

                me->CastSpell(me, SPELL_BRIEF_STUN, true);
            }
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 baseId = spell->GetFirstRankSpell()->Id;

            if (baseId == IMPALE_1)
            {
                if (me->IsValidAttackTarget(target))
                {
                    uint32 base_delay = uint32(std::max<int32>(spell->GetDuration(), 0));
                    uint32 ms_delay = base_delay + uint32(IMPALE_DAMAGE_DELAY_MS_PER_YD * me->GetExactDist2d(target));
                    //BotWhisper("Impale hit " + target->GetName() + " (" + std::to_string(target->GetGUID().GetCounter()) + "), delay: " + std::to_string(ms_delay));
                    //We use WO events container since bot ai events get cleaned at death, see JustDied()
                    me->m_Events.AddEventAtOffset([this, guid = target->GetGUID()]() {
                        if (Unit* u = ObjectAccessor::GetUnit(*me, guid))
                        {
                            if (u->GetDistance(me) < IMPALE_DAMAGE_DIST_MAX + 5.0f)
                                me->CastSpell(u, IMPALE_DAMAGE, true);
                        }
                    }, std::chrono::milliseconds(ms_delay));
                }
            }
            else if (baseId == IMPALE_DAMAGE)
            {
                //BotWhisper("Impale damage hit " + target->GetName() + " (" + std::to_string(target->GetGUID().GetCounter()) + ')');
                me->CastSpell(target, IMPALE_VISUAL, true);
                if (Aura* stun = target->AddAura(STUN_VISUAL, target))
                {
                    int32 dur = std::max<int32>(spell->GetMaxDuration(), 6000);
                    stun->SetDuration(dur);
                    stun->SetMaxDuration(dur);
                }
            }

            OnSpellHitTarget(target, spell);
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            OnSpellHit(caster, spell);
        }

        void DamageTaken(Unit* u, uint32& damage, DamageEffectType damageType, SpellInfo const* spellInfo) override
        {
            if (u && damage && (damageType == DIRECT_DAMAGE || damageType == SPELL_DIRECT_DAMAGE) &&
                (!spellInfo || spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE) && me->IsValidAttackTarget(u))
            {
                SpellInfo const* damageSpellInfo = sSpellMgr->AssertSpellInfo(SPIKED_CARAPACE_DAMAGE);
                if (u->IsImmunedToDamage(damageSpellInfo))
                {
                    me->SendSpellDamageImmune(u, SPIKED_CARAPACE_DAMAGE);
                }
                else
                {
                    uint32 damage_returned_pct = _getSpikesDamageReflectPct();
                    uint32 damage_returned = CalculatePct(damage, damage_returned_pct);
                    if (damage_returned)
                    {
                        WorldPacket data(SMSG_SPELLDAMAGESHIELD, 8 + 8 + 4 + 4 + 4 + 4 + 4);
                        data << uint64(me->GetGUID());
                        data << uint64(u->GetGUID());
                        data << uint32(damageSpellInfo->Id);
                        data << uint32(damage_returned);
                        data << uint32(std::max<int32>(int32(damage_returned) - int32(u->GetHealth()), 0));
                        data << uint32(damageSpellInfo->SchoolMask);
                        me->SendMessageToSet(&data, true);
                        Unit::DealDamage(me, u, damage_returned, nullptr, SPELL_DIRECT_DAMAGE, damageSpellInfo->GetSchoolMask(), damageSpellInfo, true);
                    }
                }
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

        uint8 GetPetPositionNumber(Creature const* summon) const override
        {
            uint8 i = 0;
            for (Summons::const_iterator citr = _minions.begin(); citr != _minions.end(); ++citr)
            {
                if ((*citr)->GetGUID() == summon->GetGUID())
                    return i;
                ++i;
            }
            return 0;
        }

        void SummonBotPet(Unit const* from)
        {
            if (_minions.size() >= MAX_MINIONS)
            {
                Unit* u = nullptr;
                //try 1: by minimal level
                uint8 minlevel = me->GetLevel();
                for (Summons::const_iterator itr = _minions.begin(); itr != _minions.end(); ++itr)
                {
                    if ((*itr)->GetLevel() < minlevel)
                    {
                        minlevel = (*itr)->GetLevel();
                        u = *itr;
                    }
                }
                //try 2: last resort
                if (!u)
                    u = *(_minions.begin());

                u->ToTempSummon()->UnSummon();
            }

            uint32 entry = _getCarrionBeetleEntry();
            Position pos = from->GetPosition();

            Creature* myPet = me->SummonCreature(entry, pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 2s);
            myPet->SetCreator(master);
            myPet->SetOwnerGUID(me->GetGUID());
            myPet->SetFaction(master->GetFaction());
            myPet->SetControlledByPlayer(!IAmFree());
            myPet->SetPvP(me->IsPvP());
            myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, CARRION_BEETLES_1);

            //myPet->SetMeleeDamageSchool(SPELL_SCHOOL_FIRE);
            if (Aura* stun = myPet->AddAura(SUMMONING_DISORIENTATION, myPet))
            {
                stun->SetDuration(1500);
                stun->SetMaxDuration(1500);
            }

            myPet->GetAI()->SetData(BOTPETAI_MISC_MAXLEVEL, me->GetLevel());
            _minions.insert(myPet);
        }

        void SummonLocust(uint32 offset)
        {
            ObjectGuid old_locust_guid = _locusts[offset];
            if (!old_locust_guid.IsEmpty())
            {
                if (Creature* old_locust = ObjectAccessor::GetCreature(*me, old_locust_guid))
                    old_locust->KillSelf();
            }

            uint32 entry = BOT_PET_LOCUST_SWARM;
            Position pos = me->GetNearPosition(frand(5.0f, 15.0f), frand(float(M_PI * 0.75), float(M_PI * 1.25)));

            Creature* locust = me->SummonCreature(entry, *me, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1s);
            locust->SetCreator(master);
            locust->SetOwnerGUID(me->GetGUID());
            locust->SetFaction(master->GetFaction());
            locust->SetControlledByPlayer(!IAmFree());
            locust->SetPvP(me->IsPvP());
            locust->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));

            locust->SetUInt32Value(UNIT_CREATED_BY_SPELL, LOCUST_SWARM_1);

            locust->GetMotionMaster()->MovePoint(1, pos, false);

            locust->GetAI()->SetData(BOTPETAI_MISC_CAPACITY, CalculatePct(me->GetMaxHealth(), uint32(2)));
            locust->GetAI()->SetData(BOTPETAI_MISC_MAX_ATTACKERS, CalculatePct(me->GetMaxHealth(), (_getMaxLocusts() + 2) / 3));
            _locusts[offset] = locust->GetGUID();
        }

        void UnsummonAll(bool savePets = true) override
        {
            UnsummonCreatures(_minions, savePets);
            UnsummonLocusts(false);
        }

        void UnsummonLocusts(bool kill)
        {
            for (ObjectGuid locust_guid : _locusts)
            {
                if (!locust_guid.IsEmpty())
                {
                    if (Creature* locust = ObjectAccessor::GetCreature(*me, locust_guid))
                    {
                        if (kill)
                           locust->KillSelf(false);
                        else
                            locust->ToTempSummon()->UnSummon();
                    }
                }
            }
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (_minions.find(summon) != _minions.end())
                _minions.erase(summon);
            else
            {
                Swarm::iterator it = std::find(std::begin(_locusts), std::end(_locusts), summon->GetGUID());
                if (it != std::end(_locusts))
                    *it = ObjectGuid::Empty;
            }
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_PET_TYPE:
                    return _getCarrionBeetleEntry();
                default:
                    return 0;
            }
        }

        void Reset() override
        {
            _impaleCheckTimer = 0;
            _carrionBeetlesCheckTimer = 0;
            _locustSwarmCheckTimer = 0;

            UnsummonAll(false);

            DefaultInit();
        }

        void ReduceCD(uint32 diff) override
        {
            if (_impaleCheckTimer > diff)                   _impaleCheckTimer -= diff;
            if (_carrionBeetlesCheckTimer > diff)           _carrionBeetlesCheckTimer -= diff;
            if (_locustSwarmCheckTimer > diff)              _locustSwarmCheckTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, BASE_MANA_1_CRYPT_LORD);
        }

        void InitSpells() override
        {
            InitSpellMap(IMPALE_1);
            InitSpellMap(CARRION_BEETLES_1);
            InitSpellMap(LOCUST_SWARM_1);
        }

        void ApplyClassPassives() const override
        {
            RefreshAura(SPELL_NULLIFY_POISON);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case IMPALE_1:
                //case CARRION_BEETLES_1:
                case LOCUST_SWARM_1:
                    return true;
                default:
                    return false;
            }
        }

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_REFLECT) + ": " + std::to_string(_getSpikesDamageReflectPct()) + '%');
            if (me->GetLevel() >= LOCUST_SWARM_MIN_LEVEL)
                specList.push_back(LocalizedNpcText(player, BOT_TEXT_LOCUSTS) + ": " + std::to_string(_getMaxLocusts()));
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &CryptLord_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &CryptLord_spells_cc;
        }
        //std::vector<uint32> const* GetHealingSpellsList() const override
        //{
        //    return &CryptLord_spells_heal;
        //}
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &CryptLord_spells_support;
        }

    private:
        void _handleLocustSwarm()
        {
            static const uint32 LOCUSTS_RELEASE_TIME = 4000u;
            uint32 max_locusts = _getMaxLocusts();
            for (uint32 i = 0; i < max_locusts; ++i)
            {
                uint32 offset = LOCUSTS_RELEASE_TIME / max_locusts * (i + 1);
                Events.AddEventAtOffset([this, num = i]() {
                    SummonLocust(num);
                }, std::chrono::milliseconds(offset));
            }
        }

        uint32 _getMaxLocusts() const
        {
            uint8 lvl = me->GetLevel();
            uint32 max_locusts;
            if (lvl >= DEFAULT_MAX_LEVEL + BotDataMgr::GetLevelBonusForBotRank(me->GetCreatureTemplate()->rank))
                max_locusts = MAX_LOCUSTS_MAXLEVEL;
            else if (lvl >= 70)
                max_locusts = MAX_LOCUSTS_70;
            else
                max_locusts = MAX_LOCUSTS_BASE;

            return max_locusts;
        }

        uint32 _getSpikesDamageReflectPct() const
        {
            uint8 lvl = me->GetLevel();
            uint32 damage_returned_pct;
            if (lvl >= 70)
                damage_returned_pct = 50;
            else if (lvl >= 60)
                damage_returned_pct = 35;
            else if (lvl >= 40)
                damage_returned_pct = 25;
            else if (lvl >= 20)
                damage_returned_pct = 20;
            else
                damage_returned_pct = 15;
            return damage_returned_pct;
        }

        uint32 _getCarrionBeetleEntry() const
        {
            uint32 entry;
            uint8 lvl = me->GetLevel();
            if (lvl >= 60)
                entry = BOT_PET_CARRION_BEETLE3;
            else if (lvl >= 30)
                entry = BOT_PET_CARRION_BEETLE2;
            else
                entry = BOT_PET_CARRION_BEETLE1;
            return entry;
        }

        bool _isUsableCorpse(Creature const* c) const
        {
            static const uint32 ViableCreatureTypesMask =
                (1 << (CREATURE_TYPE_BEAST-1)) | (1 << (CREATURE_TYPE_DRAGONKIN-1)) | (1 << (CREATURE_TYPE_HUMANOID-1));

            return c->getDeathState() == DeathState::CORPSE && c->GetDisplayId() == c->GetNativeDisplayId() &&
                !c->IsVehicle() && !c->isWorldBoss() && !c->IsDungeonBoss() &&
                ((1 << (c->GetCreatureType()-1)) & ViableCreatureTypesMask) &&
                !c->IsControlledByPlayer() && !c->IsNPCBot();
        }

        uint32 _impaleCheckTimer;
        uint32 _carrionBeetlesCheckTimer;
        uint32 _locustSwarmCheckTimer;

        typedef std::set<Creature*> Summons;
        Summons _minions;
        typedef std::vector<ObjectGuid> Swarm;
        Swarm _locusts;
    };
};

void AddSC_crypt_lord_bot()
{
    new crypt_lord_bot();
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif
