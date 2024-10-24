#include "bot_ai.h"
#include "botmgr.h"
#include "bottext.h"
#include "bottraits.h"
#include "Containers.h"
#include "Group.h"
#include "Item.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "SpellMgr.h"
#include "Totem.h"
#include "WorldSession.h"
/*
Shaman NpcBot (reworked by Trickerer onlysuffering@gmail.com)
Complete - around 90%
TODO: Elemental mastery (exclusive cd with NatSw), Lava Lash
Problems:
Unsummon elemental totems if Elementals are killed
Aura application bug for bot in other subgroup, maybe caused by creatorGUID mismatch
*/

#define MAX_WOLVES 2
#define MAX_TOTEMS 4

enum ShamanBaseSpells
{
    HEALING_WAVE_1                      = 331,
    CHAIN_HEAL_1                        = 1064,
    LESSER_HEALING_WAVE_1               = 8004,
    RIPTIDE_1                           = 61295,
    ANCESTRAL_SPIRIT_1                  = 2008,
    CURE_TOXINS_1                       = 526,
    CLEANSE_SPIRIT_1                    = 51886,
    FLAME_SHOCK_1                       = 8050,
    EARTH_SHOCK_1                       = 8042,
    FROST_SHOCK_1                       = 8056,
    STORMSTRIKE_1                       = 17364,
    LIGHTNING_BOLT_1                    = 403,
    CHAIN_LIGHTNING_1                   = 421,
    LAVA_BURST_1                        = 51505,
    THUNDERSTORM_1                      = 51490,
    LIGHTNING_SHIELD_1                  = 324,
    EARTH_SHIELD_1                      = 974,
    WATER_SHIELD_1                      = 52127,
    WATER_BREATHING_1                   = 131,
    WATER_WALKING_1                     = 546,
    PURGE_1                             = 370,
    WIND_SHEAR_1                        = 57994,
    HEX_1                               = 51514,
    BLOODLUST_1                         = 2825,
    HEROISM_1                           = 32182,
    SHAMANISTIC_RAGE_1                  = 30823,
    NATURES_SWIFTNESS_1                 = 16188,//castegory = 1202
    //ELEMENTAL_MASTERY_1                 = 16166,//castegory = 1202 NYI
    TIDAL_FORCE_1                       = 55198,

    GHOST_WOLF_1                        = 2645,

    FIRE_NOVA_1                         = 1535,//shaman spell
    EARTHBIND_TOTEM_1                   = 2484,
    MAGMA_TOTEM_1                       = 8190,
    SEARING_TOTEM_1                     = 3599,
    STONECLAW_TOTEM_1                   = 5730,
    FIRE_ELEMENTAL_TOTEM_1              = 2894,
    EARTH_ELEMENTAL_TOTEM_1             = 2062,
    FIRE_RESISTANCE_TOTEM_1             = 8184,
    FROST_RESISTANCE_TOTEM_1            = 8181,
    NATURE_RESISTANCE_TOTEM_1           = 10595,
    FLAMETONGUE_TOTEM_1                 = 8227,
    GROUNDING_TOTEM_1                   = 8177,
    SENTRY_TOTEM_1                      = 6495,
    STONESKIN_TOTEM_1                   = 8071,
    STRENGTH_OF_EARTH_TOTEM_1           = 8075,
    WINDFURY_TOTEM_1                    = 8512,
    WRATH_OF_AIR_TOTEM_1                = 3738,
    CLEANSING_TOTEM_1                   = 8170,
    HEALING_STREAM_TOTEM_1              = 5394,
    MANA_SPRING_TOTEM_1                 = 5675,
    TOTEM_OF_WRATH_1                    = 30706,
    MANA_TIDE_TOTEM_1                   = 16190,
    TREMOR_TOTEM_1                      = 8143,

    TOTEMIC_RECALL_1                    = 36936,

    REINCARNATION_1                     = 21169,

    FERAL_SPIRIT_1                      = 51533, //not casted

    //ROCKBITER_WEAPON_1                  = 8017, //disabled due to bonus handling method
    FLAMETONGUE_WEAPON_1                = 8024,
    FROSTBRAND_WEAPON_1                 = 8033,
    WINDFURY_WEAPON_1                   = 8232,
    EARTHLIVING_WEAPON_1                = 51730
};

enum ShamanPassives
{
    //Elemental
    ELEMENTAL_FOCUS                     = 16164,//clearcast
    ELEMENTAL_DEVASTATION1              = 30160,
    ELEMENTAL_DEVASTATION2              = 29179,
    ELEMENTAL_DEVASTATION3              = 29180,
    ELEMENTAL_OATH                      = 51470,//rank 2
    //STORM_EARTH_AND_FIRE                = 51486,//rank 3
    //Enchancement
    TOUGHNESS                           = 16309,//rank 5
    FLURRY1                             = 16256,
    FLURRY2                             = 16281,
    FLURRY3                             = 16282,
    FLURRY4                             = 16283,
    FLURRY5                             = 16284,
    WEAPON_MASTERY                      = 29086,//rank 3
    UNLEASHED_RAGE                      = 30809,//rank 3
    STATIC_SHOCK                        = 51527,//rank 3
    IMPROVED_STORMSTRIKE                = 51522,//rank 2
    MAELSTROM_WEAPON1                   = 51528,
    MAELSTROM_WEAPON2                   = 51529,
    MAELSTROM_WEAPON3                   = 51530,
    MAELSTROM_WEAPON4                   = 51531,
    MAELSTROM_WEAPON5                   = 51532,
    EARTHEN_POWER                       = 51524,//rank 2
    //Restoration
    ANCESTRAL_HEALING                   = 16240,//rank 3
    ANCESTRAL_AWAKENING                 = 51558,//rank 3
    IMPROVED_WATER_SHIELD               = 16198,//rank 3
    TIDAL_WAVES                         = 51566,//rank 5
    //Special
    GLYPH_THUNDERSTORM                  = 62132,
    GLYPH_TOTEM_OF_WRATH                = 63280,
    SHAMAN_T10_RESTO_4P                 = 70808 //Chain Heal HoT
};

enum ShamanSpecial
{
    SHAMAN_FLAME_SHOCK_PASSIVE          = 75461,//flame shock damage can be critical in 3.3.5, innate

    ELEMENTAL_FOCUS_BUFF                = 16246,
    TIDAL_FORCE_BUFF                    = 55166,//Unit::HandleAuraDummy(): case 55198:

    MAELSTROM_WEAPON_BUFF               = 53817,
    TIDAL_WAVES_BUFF                    = 53390,
    STORMSTRIKE_DAMAGE                  = 32175,
    STORMSTRIKE_DAMAGE_OFFHAND          = 32176,

    LIGHTNING_SHIELD_DAMAGE_1           = 26364,
    EARTH_SHIELD_HEAL                   = 379,

    RESURRECTION_VISUAL_SPELL           = 21074, //Test NPC Resurrection

    EXHAUSTION_AURA                     = 57723,
    SATED_AURA                          = 57724,

    WINDFURY_ATTACK_MAINHAND            = 25504,
    WINDFURY_ATTACK_OFFHAND             = 33750,

    STORMEARTHANDFIRE_EARTHGRAB         = 64695,

    //TOTEM_AURA_WRATH_AURA1              = 57658,//100
    //TOTEM_AURA_WRATH_AURA2              = 57660,//120
    //TOTEM_AURA_WRATH_AURA3              = 57662,//140
    //TOTEM_AURA_WRATH_AURA4              = 57663,//280
    //TOTEM_AURA_RESISTANCE_FIRE_1        = 8185,
    //TOTEM_AURA_RESISTANCE_FROST_1       = 8182,
    //TOTEM_AURA_RESISTANCE_NATURE_1      = 10596,
    //TOTEM_AURA_FLAMETONGUE_1            = 52109,
    //TOTEM_AURA_GROUNDING                = 8178,
    //TOTEM_AURA_STONESKIN_1              = 8072,
    //TOTEM_AURA_STRENGTH_OF_EARTH_1      = 8076,
    //TOTEM_AURA_WINDFURY                 = 8515,
    //TOTEM_AURA_WRATH_OF_AIR             = 2895,
    //TOTEM_AURA_MANA_SPRING_1            = 5677
};

enum TotemSlot
{
    T_FIRE  = 0,//m_SummonSlot[1]
    T_EARTH = 1,//m_SummonSlot[2]
    T_WATER = 2,//m_SummonSlot[3]
    T_AIR   = 3,//m_SummonSlot[4]
};
enum BotTotemType : uint32
{
    BOT_TOTEM_NONE                  = 0,
    BOT_TOTEM_STRENGTH_OF_EARTH     = 1, //main earth totem
    BOT_TOTEM_FLAMETONGUE           = 2, //main fire totem
    BOT_TOTEM_WRATH                 = 3, //main fire totem
    BOT_TOTEM_MANA_SPRING           = 4, //main water totem
    BOT_TOTEM_WINDFURY              = 5, //main air totem
    BOT_TOTEM_WRATH_OF_AIR          = 6, //main air totem
    BOT_TOTEM_STONESKIN             = 7, //secondary earth totem UNUSED
    BOT_TOTEM_HEALING_STREAM        = 8, //secondary water totem UNUSED
    BOT_TOTEM_TREMOR                = 9, //situative earth 1
    BOT_TOTEM_EARTHBIND             = 10, //situative earth 2
    BOT_TOTEM_MAGMA                 = 11, //situative fire 1
    BOT_TOTEM_MANA_TIDE             = 12, //situative water 1
    BOT_TOTEM_CLEANSING             = 13, //situative water 2 non-raid
    BOT_TOTEM_GROUNDING             = 14, //situative air 1
    BOT_TOTEM_RESISTANCE_FROST      = 15, //manual fire 1
    BOT_TOTEM_RESISTANCE_FIRE       = 16, //manual water 1
    BOT_TOTEM_RESISTANCE_NATURE     = 17, //manual air 1
    BOT_TOTEM_ELEMENTAL_EARTH       = 18, //manual earth 1
    BOT_TOTEM_ELEMENTAL_FIRE        = 19, //manual fire 2
    BOT_TOTEM_SENTRY                = 20, //UNUSED
    BOT_TOTEM_STONECLAW             = 21, //UNUSED
    BOT_TOTEM_SEARING               = 22, //UNUSED, annoying as hell too
    BOT_TOTEM_END,

    BOT_TOTEM_FLAG_MY_TOTEM_FIRE,
    BOT_TOTEM_FLAG_MY_TOTEM_EARTH,
    BOT_TOTEM_FLAG_MY_TOTEM_WATER,
    BOT_TOTEM_FLAG_MY_TOTEM_AIR,

    BOT_TOTEM_MASK_SUMMONS          = ((1<<BOT_TOTEM_ELEMENTAL_EARTH)|(1<<BOT_TOTEM_ELEMENTAL_FIRE)),

    //BOT_TOTEM_MASK_MY_TOTEM         = (1<<BOT_TOTEM_NONE),

    BOT_TOTEM_MASK_STRENGTH_OF_EARTH= (1<<BOT_TOTEM_STRENGTH_OF_EARTH),
    BOT_TOTEM_MASK_FLAMETONGUE      = (1<<BOT_TOTEM_FLAMETONGUE),
    BOT_TOTEM_MASK_WRATH            = (1<<BOT_TOTEM_WRATH),
    BOT_TOTEM_MASK_MANA_SPRING      = (1<<BOT_TOTEM_MANA_SPRING),
    BOT_TOTEM_MASK_WINDFURY         = (1<<BOT_TOTEM_WINDFURY),
    BOT_TOTEM_MASK_WRATH_OF_AIR     = (1<<BOT_TOTEM_WRATH_OF_AIR),
    //BOT_TOTEM_MASK_STONESKIN        = (1<<BOT_TOTEM_STONESKIN),
    BOT_TOTEM_MASK_MANA_TIDE        = (1<<BOT_TOTEM_MANA_TIDE),
    BOT_TOTEM_MASK_GROUNDING        = (1<<BOT_TOTEM_GROUNDING),
    BOT_TOTEM_MASK_RESISTANCE_FROST = (1<<BOT_TOTEM_RESISTANCE_FROST),
    BOT_TOTEM_MASK_RESISTANCE_FIRE  = (1<<BOT_TOTEM_RESISTANCE_FIRE),
    BOT_TOTEM_MASK_RESISTANCE_NATURE= (1<<BOT_TOTEM_RESISTANCE_NATURE),

    BOT_TOTEM_MASK_PRIMARY_FIRE     = (BOT_TOTEM_MASK_FLAMETONGUE | BOT_TOTEM_MASK_WRATH),

    BOT_TOTEM_MASK_MY_TOTEM_FIRE    = (1<<BOT_TOTEM_FLAG_MY_TOTEM_FIRE),
    BOT_TOTEM_MASK_MY_TOTEM_EARTH   = (1<<BOT_TOTEM_FLAG_MY_TOTEM_EARTH),
    BOT_TOTEM_MASK_MY_TOTEM_WATER   = (1<<BOT_TOTEM_FLAG_MY_TOTEM_WATER),
    BOT_TOTEM_MASK_MY_TOTEM_AIR     = (1<<BOT_TOTEM_FLAG_MY_TOTEM_AIR),

    BOT_TOTEM_MASK_PRIMARY_USE      = (BOT_TOTEM_MASK_STRENGTH_OF_EARTH | BOT_TOTEM_MASK_FLAMETONGUE | \
                                    BOT_TOTEM_MASK_WRATH | BOT_TOTEM_MASK_MANA_SPRING | \
                                    BOT_TOTEM_WINDFURY | BOT_TOTEM_MASK_WRATH_OF_AIR),

    BOT_TOTEM_MASK_MY_TOTEM_ALL     = (BOT_TOTEM_MASK_MY_TOTEM_FIRE | BOT_TOTEM_MASK_MY_TOTEM_EARTH | \
                                    BOT_TOTEM_MASK_MY_TOTEM_WATER | BOT_TOTEM_MASK_MY_TOTEM_AIR)
};

static const uint32 Shaman_spells_damage_arr[] =
{ EARTH_SHOCK_1, FLAME_SHOCK_1, FROST_SHOCK_1, STORMSTRIKE_1, CHAIN_LIGHTNING_1, LAVA_BURST_1, LIGHTNING_BOLT_1,
FIRE_NOVA_1, MAGMA_TOTEM_1, SEARING_TOTEM_1, LIGHTNING_SHIELD_1, THUNDERSTORM_1, EARTH_ELEMENTAL_TOTEM_1, FIRE_ELEMENTAL_TOTEM_1 };

static const uint32 Shaman_spells_cc_arr[] =
{ EARTHBIND_TOTEM_1, FROST_SHOCK_1, HEX_1, WIND_SHEAR_1 };

static const uint32 Shaman_spells_heal_arr[] =
{ EARTH_SHIELD_1, CHAIN_HEAL_1, LESSER_HEALING_WAVE_1, HEALING_WAVE_1, RIPTIDE_1, HEALING_STREAM_TOTEM_1 };

static const uint32 Shaman_spells_support_arr[] =
{ ANCESTRAL_SPIRIT_1, GHOST_WOLF_1, FERAL_SPIRIT_1, BLOODLUST_1, HEROISM_1, CURE_TOXINS_1, CLEANSE_SPIRIT_1,
LIGHTNING_SHIELD_1, NATURES_SWIFTNESS_1, PURGE_1, REINCARNATION_1, SHAMANISTIC_RAGE_1, TIDAL_FORCE_1,
/*WATER_BREATHING_1, */WATER_SHIELD_1, WATER_WALKING_1, /*ELEMENTAL_MASTERY_1, STONECLAW_TOTEM_1,*/
FIRE_RESISTANCE_TOTEM_1, FROST_RESISTANCE_TOTEM_1, NATURE_RESISTANCE_TOTEM_1, FLAMETONGUE_TOTEM_1, GROUNDING_TOTEM_1,
/*SENTRY_TOTEM_1, STONESKIN_TOTEM_1, */STRENGTH_OF_EARTH_TOTEM_1, WINDFURY_TOTEM_1, WRATH_OF_AIR_TOTEM_1,
CLEANSING_TOTEM_1, MANA_SPRING_TOTEM_1, TOTEM_OF_WRATH_1, MANA_TIDE_TOTEM_1, TREMOR_TOTEM_1/*, TOTEMIC_RECALL_1,
ROCKBITER_WEAPON_1, FLAMETONGUE_WEAPON_1, FROSTBRAND_WEAPON_1, WINDFURY_WEAPON_1, EARTHLIVING_WEAPON_1*/ };

static const std::vector<uint32> Shaman_spells_damage(FROM_ARRAY(Shaman_spells_damage_arr));
static const std::vector<uint32> Shaman_spells_cc(FROM_ARRAY(Shaman_spells_cc_arr));
static const std::vector<uint32> Shaman_spells_heal(FROM_ARRAY(Shaman_spells_heal_arr));
static const std::vector<uint32> Shaman_spells_support(FROM_ARRAY(Shaman_spells_support_arr));

class shaman_bot : public CreatureScript
{
public:
    shaman_bot() : CreatureScript("shaman_bot") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new shaman_botAI(creature);
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
    struct shaman_botAI : public bot_ai
    {
        shaman_botAI(Creature* creature) : bot_ai(creature)
        {
            _botclass = BOT_CLASS_SHAMAN;

            InitUnitFlags();
        }

        bool doCast(Unit* victim, uint32 spellId)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            return bot_ai::doCast(victim, spellId);
        }

        //only for totems
        bool doCast(Unit* victim, uint32 spellId, TriggerCastFlags flags)
        {
            if (CheckBotCast(victim, spellId) != SPELL_CAST_OK)
                return false;
            if (bot_ai::doCast(victim, spellId, flags))
            {
                //Calls: 1.5 sec, totems: 1 sec
                GC_Timer = (flags & TRIGGERED_CAST_DIRECTLY) ? 1500 : 1000;
                return true;
            }

            return false;
        }

        void StartAttack(Unit* u, bool force = false)
        {
            if (!bot_ai::StartAttack(u, force))
                return;
            GetInPosition(force, u);
        }

        void JustEnteredCombat(Unit* u) override { TotemsCheckTimer = 0; canTremor = false; bot_ai::JustEnteredCombat(u); }
        void KilledUnit(Unit* u) override { bot_ai::KilledUnit(u); }
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { bot_ai::EnterEvadeMode(why); }
        void MoveInLineOfSight(Unit* u) override { bot_ai::MoveInLineOfSight(u); }
        void JustDied(Unit* u) override { UnsummonAll(false); removeShapeshiftForm(); bot_ai::JustDied(u); }

        bool removeShapeshiftForm() override
        {
            ShapeshiftForm form = me->GetShapeshiftForm();
            if (form != FORM_NONE)
            {
                switch (form)
                {
                    case FORM_GHOSTWOLF:
                        me->RemoveAurasDueToSpell(GHOST_WOLF_1);
                        break;
                    default:
                        break;
                }
            }

            return true;
        }

        void CheckBloodlust(uint32 diff)
        {
            if (BloodlustCheckTimer > diff || (!me->IsInCombat() && !master->IsInCombat()) ||
                me->GetDistance(master) > 18 || Rand() > 35)
                return;

            BloodlustCheckTimer = 3000;

            uint32 BLOODLUST = (me->GetRaceMask() & RACEMASK_ALLIANCE) ? HEROISM_1 : BLOODLUST_1;
            if (!IsSpellReady(BLOODLUST, diff))
                return;

            //already rockin'
            if (me->GetAuraEffect(SPELL_AURA_MOD_MELEE_RANGED_HASTE, SPELLFAMILY_SHAMAN, 0x0, 0x40, 0x0) ||
                master->GetAuraEffect(SPELL_AURA_MOD_MELEE_RANGED_HASTE, SPELLFAMILY_SHAMAN, 0x0, 0x40, 0x0))
                return;

            //environment conditions
            Unit const* u = me->GetVictim();
            Creature const* cre = u ? u->ToCreature() : nullptr;
            if (!(u && (u->GetHealth() > me->GetMaxHealth() * 10 || u->GetTypeId() == TYPEID_PLAYER ||
                (cre && (cre->IsDungeonBoss() || cre->isWorldBoss())) ||
                me->getAttackers().size() + master->getAttackers().size() >= 8)))
                return;

            //BLOODLUST = GetSpell(BLOODLUST); //not ranked

            uint32 sateSpell = (me->GetRaceMask() & RACEMASK_ALLIANCE) ? EXHAUSTION_AURA : SATED_AURA;
            Unit::AuraEffectList const& dummies = me->GetAuraEffectsByType(SPELL_AURA_DUMMY);
            for (Unit::AuraEffectList::const_iterator itr = dummies.begin(); itr != dummies.end(); ++itr)
            {
                if ((*itr)->GetEffIndex() != 0) continue;
                SpellInfo const* spellInfo = (*itr)->GetSpellInfo();
                if (spellInfo->SpellFamilyName != SPELLFAMILY_GENERIC || spellInfo->SpellIconID != 44) continue;
                if (spellInfo->Id == sateSpell)
                    return; //can't cast my type of bloodlust
            }

            me->InterruptNonMeleeSpells(true);
            if (doCast(me, BLOODLUST))
                return;
        }

        void CheckTotems(uint32 diff)
        {
            if (TotemsCheckTimer > diff)
                return;

            TotemsCheckTimer = urand(1500, 2000) + (!IAmFree() ? 100 * master->GetNpcBotsCount() / 2 : 0);

            //Unsummon
            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
            {
                if (_totems[i].first != ObjectGuid::Empty &&
                    (!master->IsAlive() || master->GetDistance(_totems[i].second._pos) > _totems[i].second._effradius) &&
                    me->GetDistance(_totems[i].second._pos) > _totems[i].second._effradius)
                {
                    //Check if we can use totemic recall and regain some mana
                    if (!me->GetVictim()/* && GetManaPCT(me) < 90*/ && IsSpellReady(TOTEMIC_RECALL_1, diff))
                    {
                        uint8 count = 0;
                        for (uint8 j = 0; j != MAX_TOTEMS; ++j)
                        {
                            if (j == i || _totems[j].first == ObjectGuid::Empty) continue;
                            if (me->GetDistance(_totems[j].second._pos) > 20.f)
                                ++count;
                        }
                        if (count > 1)
                        {
                            if (doCast(me, GetSpell(TOTEMIC_RECALL_1)))
                                return;
                        }
                    }
                    Unit* to = ObjectAccessor::GetUnit(*me, _totems[i].first);
                    if (!to)
                    {
                        TC_LOG_ERROR("entities.player", "{} has unexpectingly lost totem in slot {}!", me->GetName(), i);
                        _totems[i].first = ObjectGuid::Empty;
                        continue;
                    }
                    to->ToTotem()->UnSummon();
                    //reset summon check timer;
                    TotemTimer[i] = 0;
                }
            }
            //global cooldown is not performed below, intead there is a special condition for Calls
            if (GC_Timer > diff || me->IsMounted() || Feasting() || IsCasting() ||
                (master->IsAlive() && me->GetDistance(master) > 15))
                return;

            bool CotE = me->GetLevel() >= 30; //Call of the Elements is at level 30;

            std::map<uint32, uint32> idMap;
            uint32 mask = _getTotemsMask(idMap);
            Group const* gr = GetGroup();
            std::vector<Unit*> members = BotMgr::GetAllGroupMembers(gr);
            uint8 subgr = GetSubGroup();

            //EARTH
            //EARTHsituative1 : tremor
            if (TotemTimer[T_EARTH] <= diff && me->IsInCombat() && !IAmFree() &&
                IsSpellReady(TREMOR_TOTEM_1, diff, false) && _totems[T_EARTH].second._type != BOT_TOTEM_TREMOR)
            {
                //Tremor no cd
                if (Unit const* victim = me->GetVictim())
                {
                    if (Spell const* vspell = victim->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                    {
                        if (vspell->m_targets.GetUnitTargetGUID() == me->GetGUID())
                        {
                            SpellInfo const* vspellInfo = vspell->GetSpellInfo();
                            static const std::array<uint32, 3> TremorMechanics = { MECHANIC_FEAR, MECHANIC_CHARM, MECHANIC_SLEEP };
                            static const auto is_tremor_effect = [](SpellEffectInfo const& effect) {  return effect.IsAura(SPELL_AURA_MOD_FEAR) || effect.IsAura(SPELL_AURA_MOD_CHARM); };
                            if (std::find(TremorMechanics.cbegin(), TremorMechanics.cend(), vspellInfo->Mechanic) != TremorMechanics.cend() ||
                                std::any_of(vspellInfo->_effects.cbegin(), vspellInfo->_effects.cend(), is_tremor_effect))
                            {
                                canTremor = true;
                            }
                        }
                    }
                }
                if (!canTremor)
                {
                    uint8 count = 0;
                    for (Unit const* member : members)
                    {
                        if (me->GetMap() != member->FindMap() || !member->InSamePhase(me) ||
                            !member->IsAlive() || me->GetDistance(member) > 20 ||
                            (member->IsPlayer() ? member->ToPlayer()->GetSubGroup() : member->ToCreature()->GetSubGroup()) != subgr ||
                            (member->IsNPCBot() && member->ToCreature()->IsTempBot()) ||
                            !member->HasAuraWithMechanic((1<<MECHANIC_CHARM)|(1<<MECHANIC_FEAR)|(1<<MECHANIC_SLEEP)))
                            continue;
                        ++count;
                    }
                    canTremor = count >= (1 + 1*(!!(mask & BOT_TOTEM_MASK_MY_TOTEM_EARTH)));
                }
                if (canTremor)
                {
                    if (doCast(me, GetSpell(TREMOR_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
                //check if casted
                if (_totems[T_EARTH].second._type != BOT_TOTEM_TREMOR)
                    SetSpellCooldown(TREMOR_TOTEM_1, 3000); //fail
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_EARTH) && TotemTimer[T_EARTH] <= diff && me->IsInCombat())
            {
                //EARTHsituative2 : earthbind
                if (GetSpell(EARTHBIND_TOTEM_1)/* && _totems[T_EARTH].second.type != BOT_TOTEM_EARTHBIND*/)
                {
                    //15 sec cd, nearby enemies, instant effect
                    std::list<Unit*> targets;
                    GetNearbyTargetsList(targets, 15.f, 1);
                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end();)
                    {
                        Unit* u = *itr;
                        bool erase = false;
                        if (u->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED) || u->HasAuraType(SPELL_AURA_MOD_SPEED_SLOW_ALL))
                            erase = true;
                        else if (u->isMoving())
                        {
                            if (me->GetDistance(u) > 10.f && !u->HasInArc(float(M_PI)/2, me))
                                erase = true;
                        }
                        else if (me->GetDistance(u) > 9.f)
                            erase = true;

                        if (erase)
                        {
                            targets.erase(itr++);
                            continue;
                        }
                        ++itr;
                    }

                    if (uint8(targets.size()) >= (1 + 2*((mask & BOT_TOTEM_MASK_MY_TOTEM_EARTH) != 0)))
                    {
                        if (doCast(me, GetSpell(EARTHBIND_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                            if (!CotE)
                                return;
                    }
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_EARTH) && TotemTimer[T_EARTH] <= diff && me->IsInCombat())
            {
                //EARTHmain : strength of earth
                uint32 SoE = GetSpell(STRENGTH_OF_EARTH_TOTEM_1); //tripple check
                if (SoE &&
                    (!(mask & BOT_TOTEM_MASK_STRENGTH_OF_EARTH) || idMap[STRENGTH_OF_EARTH_TOTEM_1] < SoE))
                {
                    //no cd
                    if (doCast(me, SoE, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }

                //EARTHlast : earth elemental (for mass taunt)
                //uint32 earthElem = GetSpell(EARTH_ELEMENTAL_TOTEM_1);
                //if (earthElem && IsSpellReady(EARTH_ELEMENTAL_TOTEM_1, diff) && !me->GetMap()->IsDungeon() &&
                //    me->getAttackers().size() > 1)
                //{
                //    //no cd
                //    if (doCast(me, earthElem, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                //        if (!CotE)
                //            return;
                //}
            }

            //FIRE
            //FIREsituative1 : magma
            if (TotemTimer[T_FIRE] <= diff && me->IsInCombat() && !IAmFree() && HasRole(BOT_ROLE_DPS) &&
                GetSpell(MAGMA_TOTEM_1)/* && _totems[T_FIRE].second.type != BOT_TOTEM_MAGMA*/)
            {
                //magma no cd 8 yd, 2 sec delay before first tick
                std::list<Unit*> targets;
                GetNearbyTargetsList(targets, 13.f, 1);
                for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end();)
                {
                    Unit* u = *itr;
                    bool erase = false;
                    if (u->isMoving())
                    {
                        if (me->GetDistance(u) > 10.f && !u->HasInArc(float(M_PI)/2, me))
                            erase = true;
                    }
                    else if (me->GetDistance(u) > 7.f)
                        erase = true;

                    if (erase)
                    {
                        targets.erase(itr++);
                        continue;
                    }
                    ++itr;
                }

                if (uint8(targets.size()) >= (3 + 3*((mask & BOT_TOTEM_MASK_MY_TOTEM_FIRE) != 0)))
                {
                    if (doCast(me, GetSpell(MAGMA_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_FIRE) && me->IsInCombat() && TotemTimer[T_FIRE] <= diff)
            {
                //FIREMain : wrath or flametongue no cd
                //aura is exclusive so check mask
                uint32 base = TOTEM_OF_WRATH_1;
                uint32 wrathTotem = GetSpell(TOTEM_OF_WRATH_1);
                uint32 fMask = BOT_TOTEM_MASK_WRATH;
                if (!wrathTotem)
                {
                    base = FLAMETONGUE_TOTEM_1;
                    wrathTotem = GetSpell(FLAMETONGUE_TOTEM_1);
                    fMask = BOT_TOTEM_MASK_FLAMETONGUE;
                }
                if (wrathTotem &&
                    ((mask & BOT_TOTEM_MASK_PRIMARY_FIRE) < fMask ||
                    ((mask & BOT_TOTEM_MASK_PRIMARY_FIRE) == fMask && idMap[base] < wrathTotem)))
                {
                    if (doCast(me, wrathTotem, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }

                //FIREaddin : fire elemental
                //uint32 fireElem = GetSpell(FIRE_ELEMENTAL_TOTEM_1);
                //if (fireElem && IsSpellReady(FIRE_ELEMENTAL_TOTEM_1, diff) && !me->GetMap()->IsDungeon())
                //{
                //    if (doCast(me, fireElem, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                //        if (!CotE)
                //            return;
                //}
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_FIRE) && me->IsInCombat() && TotemTimer[T_FIRE] <= diff)
            {
                //FIRElastresort : frostres (3 shamans of same level req)
                uint32 frostRes = GetSpell(FROST_RESISTANCE_TOTEM_1);
                if (frostRes && !IAmFree() &&
                    (!(mask & BOT_TOTEM_MASK_RESISTANCE_FROST) || idMap[FROST_RESISTANCE_TOTEM_1] < frostRes))
                {
                    if (doCast(me, frostRes, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
            }

            //WATER
            //WATERsituative1 : manatide
            if (TotemTimer[T_WATER] <= diff && me->IsInCombat() && !IAmFree() &&
                IsSpellReady(MANA_TIDE_TOTEM_1, diff, false))
            {
                //5 min cd, party members only, instant effect +4 ticks in 12 secs
                bool cast = false;
                if (master->IsInCombat() && master->GetPowerType() == POWER_MANA &&
                    GetManaPCT(master) < 35 && me->GetDistance(master) < 18)
                    cast = true;
                else if (me->IsInCombat() && GetManaPCT(me) < 35)
                    cast = true;
                else
                {
                    uint8 count = 0;
                    for (Unit const* member : members)
                    {
                        if (me->GetMap() != member->FindMap() || !member->InSamePhase(me) ||
                            !member->IsAlive() || !member->IsInCombat() || member->GetPowerType() != POWER_MANA ||
                            (member->IsPlayer() ? member->ToPlayer()->GetSubGroup() : member->ToCreature()->GetSubGroup()) != subgr ||
                            GetManaPCT(member) > 35 || me->GetDistance(member) > 20 ||
                            (member->IsNPCBot() && member->ToCreature()->IsTempBot()))
                            continue;
                        ++count;
                    }
                    cast = (count >= (3 + 1*(!!(mask & BOT_TOTEM_MASK_MY_TOTEM_WATER))));
                }
                if (cast)
                {
                    if (doCast(me, GetSpell(MANA_TIDE_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
                //check if casted
                if (_totems[T_WATER].second._type != BOT_TOTEM_MANA_TIDE)
                    SetSpellCooldown(MANA_TIDE_TOTEM_1, 3000); //fail
            }

            //WATERsituative2 : cleansing
            //REMOVED CHECKS ARE TOO HEAVY

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_WATER) && TotemTimer[T_WATER] <= diff)
            {
                //WATERmain : manaspring
                uint32 MSpring = GetSpell(MANA_SPRING_TOTEM_1); //tripple check
                if (MSpring && (me->IsInCombat() || !master->isMoving()) &&
                    (!(mask & BOT_TOTEM_MASK_MANA_SPRING) || idMap[MANA_SPRING_TOTEM_1] < MSpring))
                {
                    //no cd
                    bool cast = false;
                    if (!master->isMoving() && master->GetPowerType() == POWER_MANA && GetManaPCT(master) < 85)
                        cast = true;
                    else if (!me->isMoving() && GetManaPCT(me) < 95)
                        cast = true;
                    else
                    {
                        for (Unit const* member : members)
                        {
                            if (me->GetMap() != member->FindMap() || !member->InSamePhase(me) ||
                                !member->IsAlive() || member->GetPowerType() != POWER_MANA ||
                                GetManaPCT(member) > 85 || me->GetDistance(member) > 25 ||
                                (member->IsNPCBot() && member->ToCreature()->IsTempBot()))
                                continue;
                            cast = true;
                            break;
                        }
                    }
                    if (cast)
                    {
                        if (doCast(me, MSpring, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                            if (!CotE)
                                return;
                    }
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_WATER) && TotemTimer[T_WATER] <= diff)
            {
                //WATERlastresort : fireres (2-3 shamans of same level req)
                uint32 fireRes = GetSpell(FIRE_RESISTANCE_TOTEM_1);
                if (fireRes && TotemTimer[T_WATER] <= diff && me->IsInCombat() && !IAmFree() &&
                    (!(mask & BOT_TOTEM_MASK_RESISTANCE_FIRE) || idMap[FIRE_RESISTANCE_TOTEM_1] < fireRes))
                {
                    if (doCast(me, fireRes, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
            }

            //AIR
            //AIRsituative1 : grounding
            if (TotemTimer[T_AIR] <= diff && me->IsInCombat() &&/* !IAmFree() &&*/
                IsSpellReady(GROUNDING_TOTEM_1, diff, false))
            {
                //grounding 15 sec cd, party members only (and bot and master of course)
                bool cast = false;
                if (Unit const* u = FindCastingTarget(27)) //totem must be within cast distance
                {
                    if (Spell const* spell = u->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                    {
                        ObjectGuid tGuid = spell->m_targets.GetUnitTargetGUID();
                        if (tGuid == me->GetGUID() || tGuid == master->GetGUID() || (gr && gr->IsMember(tGuid) && gr->SameSubGroup(tGuid, me->GetGUID())))
                        {
                            Unit const* t = ObjectAccessor::GetUnit(*me, tGuid);
                            if (t && t->GetDistance(me) < 27 && !t->HasAuraType(SPELL_AURA_SPELL_MAGNET))
                                cast = true;
                        }
                    }
                }
                if (cast)
                {
                    if (doCast(me, GetSpell(GROUNDING_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        if (!CotE)
                            return;
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_AIR) && TotemTimer[T_AIR] <= diff && me->IsInCombat())
            {
                //AIRmain1 : wrathofair - if windfury is disabled or me and master both casters
                if (!(mask & BOT_TOTEM_MASK_WRATH_OF_AIR) && GetSpell(WRATH_OF_AIR_TOTEM_1))
                {
                    bool cast = false;

                    if (!IsMelee() && HasRole(BOT_ROLE_DPS|BOT_ROLE_HEAL) && !IsMeleeClass(master->GetClass()))
                        cast = true;
                    else if (!GetSpell(WINDFURY_TOTEM_1)) //disabled
                        cast = true;
                    else if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_AIR))
                        if (mask & BOT_TOTEM_MASK_WINDFURY) //already have windfury from someone else
                            cast = true;

                    if (cast)
                    {
                        if (doCast(me, GetSpell(WRATH_OF_AIR_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                            //if (!CotE)
                                return;
                    }
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_AIR) && TotemTimer[T_AIR] <= diff && me->IsInCombat())
            {
                //AIRmain2 : windfury
                if (!(mask & BOT_TOTEM_MASK_WINDFURY) && GetSpell(WINDFURY_TOTEM_1))
                {
                    bool cast = false;

                    if ((IsMelee() && HasRole(BOT_ROLE_DPS)) || (!IAmFree() && IsMeleeClass(master->GetClass())))
                        cast = true;
                    else if (!GetSpell(WRATH_OF_AIR_TOTEM_1)) //disabled or not available yet
                        cast = true;
                    else if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_AIR))
                        if (mask & BOT_TOTEM_MASK_WRATH_OF_AIR) //already have wrath of air from someone else
                            cast = true;

                    if (cast)
                    {
                        if (doCast(me, GetSpell(WINDFURY_TOTEM_1), CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                            //if (!CotE)
                                return;
                    }
                }
            }

            if (!(mask & BOT_TOTEM_MASK_MY_TOTEM_AIR) && TotemTimer[T_AIR] <= diff && me->IsInCombat())
            {
                //AIRlastresort : natureres (3-4 shamans of same level req)
                uint32 natureRes = GetSpell(NATURE_RESISTANCE_TOTEM_1);
                if (natureRes && !IAmFree() &&
                    (!(mask & BOT_TOTEM_MASK_RESISTANCE_NATURE) || idMap[NATURE_RESISTANCE_TOTEM_1] < natureRes))
                {
                    if (doCast(me, natureRes, CotE ? TRIGGERED_CAST_DIRECTLY : TRIGGERED_NONE))
                        //if (!CotE)
                            return;
                }
            }
        }

        void CheckShamanisticRage(uint32 diff)
        {
            if (!IsSpellReady(SHAMANISTIC_RAGE_1, diff) || !me->IsInCombat() || IsCasting() || Rand() > 35)
                return;

            bool cast = false;
            //case 1: hp pressure
            if (GetHealthPCT(me) < (50 + 20 * me->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) + 5 * uint32(me->getAttackers().size())))
                cast = true;
            //case 2: low mana (melee)
            else if (me->GetVictim() && !CCed(me, true) && HasRole(BOT_ROLE_DPS) && IsMelee() && GetManaPCT(me) < 40)
                cast = true;

            if (cast && doCast(me, GetSpell(SHAMANISTIC_RAGE_1)))
                return;
        }

        void CheckThunderStorm(uint32 diff)
        {
            if (!IsSpellReady(THUNDERSTORM_1, diff) || !me->IsAlive() || !HasRole(BOT_ROLE_DPS) || IsCasting() || Rand() > 25)
                return;

            //case 1: low mana
            if (GetManaPCT(me) < 25)
            {
                if (doCast(me, GetSpell(THUNDERSTORM_1)))
                    return;
            }

            //case 2: AoE damage
            //AttackerSet m_attackers = master->getAttackers();
            Unit::AttackerSet const& b_attackers = me->getAttackers();
            if (b_attackers.empty())
                return;

            uint8 tCount = 0;
            for (Unit::AttackerSet::const_iterator iter = b_attackers.begin(); iter != b_attackers.end(); ++iter)
            {
                if (!(*iter)) continue;
                if (me->GetDistance((*iter)) > 9) continue;
                if (me->IsValidAttackTarget(*iter))
                {
                    ++tCount;
                    break;
                }
            }

            if (tCount > 1)
            {
                if (doCast(me, GetSpell(THUNDERSTORM_1)))
                    return;
            }
        }

        void Counter(uint32 diff)
        {
            if (!IsSpellReady(WIND_SHEAR_1, diff, false) || (HasRole(BOT_ROLE_HEAL) && IsCasting()) || Rand() > 40)
                return;

            if (Unit* target = FindCastingTarget(CalcSpellMaxRange(WIND_SHEAR_1), 0, WIND_SHEAR_1))
            {
                me->InterruptNonMeleeSpells(false);
                if (doCast(target, GetSpell(WIND_SHEAR_1)))
                    return;
            }
        }

        void CheckShield(uint32 diff)
        {
            if (GC_Timer > diff || ShieldCheckTimer > diff || IsCasting() || Rand() > 15)
                return;

            ShieldCheckTimer = 2000;

            //Aura const* shield = nullptr;
            uint32 SHIELD =
                HasRole(BOT_ROLE_TANK)   ? GetSpell(EARTH_SHIELD_1) :
                HasRole(BOT_ROLE_HEAL)   ? GetSpell(WATER_SHIELD_1) :
                HasRole(BOT_ROLE_DPS)    ? GetSpell(LIGHTNING_SHIELD_1) :
                0;
            SHIELD =
                SHIELD ? SHIELD :
                GetSpell(WATER_SHIELD_1) ? GetSpell(WATER_SHIELD_1) :
                GetSpell(EARTH_SHIELD_1) ? GetSpell(EARTH_SHIELD_1) :
                0;

            if (!SHIELD && HasRole(BOT_ROLE_DPS))
                SHIELD = GetSpell(LIGHTNING_SHIELD_1);

            if (!SHIELD)
                return;

            AuraApplication const* sh = me->GetAuraApplicationOfRankedSpell(SHIELD);
            if (!sh || sh->GetBase()->GetCharges() < 5 || sh->GetBase()->GetDuration() < 30000 ||
                sh->GetBase()->GetSpellInfo()->GetRank() < sSpellMgr->GetSpellInfo(SHIELD)->GetRank())
            {
                if (doCast(me, SHIELD))
                    return;
            }
        }

        void UpdateDeadAI(uint32 diff) override
        {
            if (IsSpellReady(REINCARNATION_1, diff, false) && (IAmFree() || master->IsInCombat()) && Rand() < 20)
                if (doCast(me, GetSpell(REINCARNATION_1)))
                    return;

            bot_ai::UpdateDeadAI(diff);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!GlobalUpdate(diff))
                return;

            DoVehicleActions(diff);
            if (!CanBotAttackOnVehicle())
                return;

            CheckShamanisticRage(diff);
            CheckThunderStorm(diff);

            CheckHexy(diff);
            CheckEarthy(diff);

            if (IsPotionReady())
            {
                if (GetManaPCT(me) < 33)
                    DrinkPotion(true);
                else if (GetHealthPCT(me) < 50 && (!HasRole(BOT_ROLE_HEAL) || me->HasAuraType(SPELL_AURA_MOD_SILENCE)))
                    DrinkPotion(false);
            }

            CheckRacials(diff);

            CheckBloodlust(diff);
            BuffAndHealGroup(diff);
            CheckEarthShield(diff);
            CureGroup(CURE_TOXINS, diff);
            CheckTotems(diff);
            CheckShield(diff);

            if (master->IsInCombat() || me->IsInCombat())
            {
                CheckDispel(diff);
                CheckFireNova(diff);
            }

            if (!me->IsInCombat())
                DoNonCombatActions(diff);

            if (ProcessImmediateNonAttackTarget())
                return;

            CheckGhostWolf(diff);

            if (!CheckAttackTarget())
                return;

            CheckHex(diff);
            Counter(diff);

            if (IsCasting())
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

            auto [can_do_frost, can_do_fire, can_do_nature] = CanAffectVictimBools(mytar, SPELL_SCHOOL_FROST, SPELL_SCHOOL_FIRE, SPELL_SCHOOL_NATURE);

            //AttackerSet m_attackers = master->getAttackers();
            //AttackerSet b_attackers = me->getAttackers();
            float dist = me->GetDistance(mytar);

            //spell reflections
            if (IsSpellReady(EARTH_SHOCK_1, diff) && can_do_nature && HasRole(BOT_ROLE_DPS) && dist < 25 && CanRemoveReflectSpells(mytar, EARTH_SHOCK_1) &&
                doCast(mytar, EARTH_SHOCK_1))
                return;

            MoveBehind(mytar);

            //STORMSTRIKE
            if (IsSpellReady(STORMSTRIKE_1, diff) && can_do_nature && HasRole(BOT_ROLE_DPS) && IsMelee() && dist <= 5 && Rand() < 120)
            {
                if (doCast(mytar, GetSpell(STORMSTRIKE_1)))
                    return;
            }
            //SHOCKS
            if (GetSpellCooldown(EARTH_SHOCK_1) <= diff && HasRole(BOT_ROLE_DPS) &&
                (GetSpell(FLAME_SHOCK_1) || GetSpell(EARTH_SHOCK_1) || GetSpell(FROST_SHOCK_1)) &&
                dist < 25 && Rand() < 70)
            {
                if (GetSpell(FLAME_SHOCK_1) && can_do_fire)
                {
                    AuraEffect const* fsh = mytar->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_SHAMAN, 0x10000000, 0x0, 0x0, me->GetGUID());
                    if (!fsh || fsh->GetBase()->GetDuration() < 3000)
                    {
                        if (doCast(mytar, GetSpell(FLAME_SHOCK_1)))
                            return;
                    }
                }

                uint32 SHOCK = can_do_frost ? GetSpell(FROST_SHOCK_1) : 0;
                if (!SHOCK && can_do_nature)
                    SHOCK = GetSpell(EARTH_SHOCK_1);

                if (SHOCK)
                {
                    if (doCast(mytar, SHOCK))
                        return;
                }
            }

            //Feral Spirit
            if (IsSpellReady(FERAL_SPIRIT_1, diff) && HasRole(BOT_ROLE_DPS) && Rand() < 40 && dist < 5)
            {
                SummonBotPet(mytar);
                SetSpellCooldown(FERAL_SPIRIT_1, 180000);
                return;
            }

            //LAVA BURST
            if (IsSpellReady(LAVA_BURST_1, diff) && can_do_fire && HasRole(BOT_ROLE_DPS) &&
                (GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL || (IsRanged() && (!can_do_nature || !GetSpell(LIGHTNING_BOLT_1)))) &&
                dist < CalcSpellMaxRange(LAVA_BURST_1) && Rand() < 60 &&
                (me->getAttackers().empty() || dist > 10))
            {
                if (doCast(mytar, GetSpell(LAVA_BURST_1)))
                    return;
            }

            if (((MaelstromCount < 5 || MaelstromTimer == 0 || me->GetLevel() < 55) && IsMelee()) ||
                (HasRole(BOT_ROLE_HEAL) && GetManaPCT(me) < 25))
                return;

            //CHAIN LIGHTNING
            if (IsSpellReady(CHAIN_LIGHTNING_1, diff) && can_do_nature && HasRole(BOT_ROLE_DPS) && dist < CalcSpellMaxRange(CHAIN_LIGHTNING_1) && Rand() < 80)
            {
                Unit* u = FindSplashTarget(35.f, mytar, 5.f);
                if (u && doCast(mytar, GetSpell(CHAIN_LIGHTNING_1)))
                    return;
            }
            //LIGHTNING BOLT
            if (IsSpellReady(LIGHTNING_BOLT_1, diff) && can_do_nature && HasRole(BOT_ROLE_DPS) && dist < CalcSpellMaxRange(LIGHTNING_BOLT_1))
            {
                uint32 LIGHTNING_BOLT = GetSpell(LIGHTNING_BOLT_1);
                if (doCast(mytar, LIGHTNING_BOLT))
                    return;
            }
        }

        void CheckHexy(uint32 diff)
        {
            if (HexyCheckTimer > diff)
                return;

            HexyCheckTimer = 2000;
            Hexy = FindAffectedTarget(GetSpell(HEX_1), me->GetGUID());
        }

        void CheckHex(uint32 diff)
        {
            if (Hexy || !IsSpellReady(HEX_1, diff))
                return;

            if (Unit* target = FindPolyTarget(20))
            {
                if (doCast(target, GetSpell(HEX_1)))
                    return;
            }
        }

        void CheckEarthy(uint32 diff)
        {
            if (EarthyCheckTimer > diff)
                return;

            EarthyCheckTimer = 1000;
            Unit const* u = FindAffectedTarget(GetSpell(EARTH_SHIELD_1), me->GetGUID(), 90.f, 3);
            Earthy = (u && (IsTank(u) || u == master));
        }

        void CheckGhostWolf(uint32 diff)
        {
            if (!IsSpellReady(GHOST_WOLF_1, diff) || (!IAmFree() && !HasBotCommandState(BOT_COMMAND_FOLLOW)) ||
                Rand() > 35 || me->GetShapeshiftForm() != FORM_NONE || me->IsMounted() || !IsOutdoors() || IsCasting())
                return;

            if (IAmFree())
            {
                InstanceTemplate const* instt = sObjectMgr->GetInstanceTemplate(me->GetMap()->GetId());
                bool map_allows_mount = (!me->GetMap()->IsDungeon() || me->GetMap()->IsBattlegroundOrArena()) && (!instt || instt->AllowMount);
                if (me->HasUnitMovementFlag(MOVEMENTFLAG_FORWARD) &&
                    (!me->GetVictim() ?
                        (me->IsInCombat() || !map_allows_mount || IsFlagCarrier(me)) :
                        !me->IsWithinDist(me->GetVictim(), 8.0f + (IsMelee() ? 5.0f : GetSpellAttackRange(true)))))
                {
                    if (doCast(me, GetSpell(GHOST_WOLF_1)))
                        return;
                }

                return;
            }

            if (me->GetExactDist2d(master) > std::max<uint8>(master->GetBotMgr()->GetBotFollowDist(), 30))
            {
                if (doCast(me, GetSpell(GHOST_WOLF_1)))
                    return;
            }
        }

        void DoNonCombatActions(uint32 diff)
        {
            if (GC_Timer > diff || me->IsMounted() || IsCasting() || Rand() > 25)
                return;

            ResurrectGroup(GetSpell(ANCESTRAL_SPIRIT_1));

            if (mhEnchantExpireTimer > 0 && mhEnchantExpireTimer <= diff)
                RemoveItemClassEnchantment(BOT_SLOT_MAINHAND);
            if (ohEnchantExpireTimer > 0 && ohEnchantExpireTimer <= diff)
                RemoveItemClassEnchantment(BOT_SLOT_OFFHAND);

            // Weapon Enchants
            if (me->isMoving())
                return;

            Item* mhWeapon = GetEquips(BOT_SLOT_MAINHAND);
            Item* ohWeapon = GetEquips(BOT_SLOT_OFFHAND);
            //item must be non-standard, otherwise combat spells won't be rolled anyway
            bool mhReady = mhWeapon && !mhWeapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT);
            bool ohReady = ohWeapon && !ohWeapon->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT);

            if (!mhReady && !ohReady)
                return; //no ecnhantable weapons

            //OK choose the enchants
            //MH 1+ Rockbiter, 10+ Flametongue, 30+ Windfury/Earthliving
            //OH 1+ Rockbiter, 10+ Flametongue, 20+ Frostbrand, 30+ Windfury/Earthliving
            if (needChooseMHEnchant && mhReady)
                mhEnchant = HasRole(BOT_ROLE_HEAL) ? (me->GetLevel() >= 30 ? EARTHLIVING_WEAPON_1 :
                    me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/) :
                    HasRole(BOT_ROLE_RANGED) ? (me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/) :
                    (me->GetLevel() >= 30 ? WINDFURY_WEAPON_1 :
                    //me->GetLevel() >= 20 ? FROSTBRAND_WEAPON_1 :
                    me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/);

            if (needChooseOHEnchant && ohReady) //basically only lvl 40+
                ohEnchant = HasRole(BOT_ROLE_HEAL) ? (me->GetLevel() >= 30 ? EARTHLIVING_WEAPON_1 :
                    me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/) :
                    HasRole(BOT_ROLE_RANGED) ? (me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/) :
                    (me->GetLevel() >= 30 ? WINDFURY_WEAPON_1 :
                    me->GetLevel() >= 20 ? FROSTBRAND_WEAPON_1 :
                    me->GetLevel() >= 10 ? FLAMETONGUE_WEAPON_1 :
                    0/*ROCKBITER_WEAPON_1*/);

            uint32 MhEnchant = !mhReady ? 0 : GetSpell(mhEnchant);
            uint32 OhEnchant = !ohReady ? 0 : GetSpell(ohEnchant);

            SpellInfo const* MhEnchantInfo = mhReady && MhEnchant ? sSpellMgr->GetSpellInfo(MhEnchant) : nullptr;
            SpellInfo const* OhEnchantInfo = ohReady && OhEnchant ? sSpellMgr->GetSpellInfo(OhEnchant) : nullptr;

            Item* targetWeapon = nullptr;
            SpellInfo const* targetInfo = nullptr;

            if (mhReady && MhEnchant && mhWeapon->IsFitToSpellRequirements(MhEnchantInfo))
            {
                targetWeapon = mhWeapon;
                targetInfo = MhEnchantInfo;
            }
            if (!targetWeapon && ohReady && OhEnchant && ohWeapon->IsFitToSpellRequirements(OhEnchantInfo))
            {
                targetWeapon = ohWeapon;
                targetInfo = OhEnchantInfo;
            }
            if (targetWeapon)
            {
                Spell* spell = new Spell(me, targetInfo, TRIGGERED_NONE);
                SpellCastTargets targets;
                targets.SetItemTarget(targetWeapon);
                spell->prepare(targets);
                return;
            }
        }

        bool BuffTarget(Unit* target, uint32 /*diff*/) override
        {
            if (me->IsInCombat() && !master->GetMap()->IsRaid())
                return false;

            if (target->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING))
            {
                //water walking breaks on any damage
                if (GetSpell(WATER_WALKING_1) && target->getAttackers().empty() &&
                    !target->HasAuraType(SPELL_AURA_PERIODIC_DAMAGE) && !target->HasAuraType(SPELL_AURA_WATER_WALK) &&
                    doCast(target, GetSpell(WATER_WALKING_1)))
                {
                    //GC_Timer = 1000;
                    return true;
                }
                //bots don't need water breathing
                if (GetSpell(WATER_BREATHING_1) && target->GetTypeId() == TYPEID_PLAYER &&
                    !target->HasAuraType(SPELL_AURA_WATER_BREATHING) &&
                    doCast(target, GetSpell(WATER_BREATHING_1)))
                {
                    //GC_Timer = 1000;
                    return true;
                }
            }
            return false;
        }

        void CheckEarthShield(uint32 diff)
        {
            if (!IsSpellReady(EARTH_SHIELD_1, diff) || Earthy == true || Rand() > (65 - 45 * me->IsInCombat()))
                return;

            static const auto can_affect = [](WorldObject const* o, Unit const* unit)
            {
                if (!unit->IsAlive())
                    return false;
                AuraEffect const* eShield = unit->GetAuraEffect(SPELL_AURA_REDUCE_PUSHBACK, SPELLFAMILY_SHAMAN, 0x0, 0x400, 0x0);
                return (!eShield || eShield->GetBase()->GetCharges() < 5 || eShield->GetBase()->GetDuration() < 30000) && o->GetDistance(unit) < 40 && (unit->IsInCombat() || !unit->isMoving());
            };

            Group const* gr = !IAmFree() ? master->GetGroup() : GetGroup();
            if (!gr)
            {
                if (IsTank(master) && can_affect(me, master) && doCast(master, GetSpell(EARTH_SHIELD_1)))
                    return;

                if (!IAmFree())
                {
                    BotMap const* map = master->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator it = map->begin(); it != map->end(); ++it)
                    {
                        Unit* u = it->second;
                        if (!u || !u->IsInWorld() || me->GetMap() != u->FindMap() || !u->InSamePhase(me))
                            continue;
                        if (IsTank(u) && can_affect(me, u) && doCast(u, GetSpell(EARTH_SHIELD_1)))
                            return;
                    }
                }
            }
            else
            {
                std::set<Unit*> tanks;
                for (Unit* member : BotMgr::GetAllGroupMembers(gr))
                {
                    if (me->GetMap() == member->FindMap() && member->IsAlive() && member->InSamePhase(me) && IsTank(member) && can_affect(me, member))
                        tanks.insert(member);
                }

                if (!tanks.empty())
                {
                    Unit* target = tanks.size() == 1 ? *tanks.begin() : Trinity::Containers::SelectRandomContainerElement(tanks);
                    if (doCast(target, GetSpell(EARTH_SHIELD_1)))
                        return;
                }
            }

            if (!IAmFree() && can_affect(me, master) && doCast(master, GetSpell(EARTH_SHIELD_1)))
                return;
        }

        void CheckDispel(uint32 diff)
        {
            if (!IsSpellReady(PURGE_1, diff) || IsCasting())
                return;

            Unit* target = FindHostileDispelTarget(CalcSpellMaxRange(PURGE_1));
            if (target && doCast(target, GetSpell(PURGE_1)))
                return;

            SetSpellCooldown(PURGE_1, 500); //fail
        }

        void CheckFireNova(uint32 diff)
        {
            if (!HasRole(BOT_ROLE_DPS) || _totems[T_FIRE].second._type == BOT_TOTEM_NONE ||
                !IsSpellReady(FIRE_NOVA_1, diff) || IsCasting() || Rand() > 25)
                return;

            std::list<Unit*> targets;
            GetNearbyTargetsList(targets, 9.f, 0, ObjectAccessor::GetUnit(*me, _totems[T_FIRE].first));
            if (targets.size() > 1 || (!targets.empty() && *(targets.begin()) == me->GetVictim()))
            {
                if (doCast(me, GetSpell(FIRE_NOVA_1)))
                    return;
            }
        }

        bool HealTarget(Unit* target, uint32 diff) override
        {
            if (!target || !target->IsAlive() || target->GetShapeshiftForm() == FORM_SPIRITOFREDEMPTION || me->GetDistance(target) > 40)
                return false;
            uint8 hp = GetHealthPCT(target);
            if (hp > GetHealHpPctThreshold())
                return false;
            bool pointed = IsPointedHealTarget(target);
            if (hp > 90 && !(pointed && me->GetMap()->IsRaid()) &&
                (!target->IsInCombat() || target->getAttackers().empty() || !IsTank(target) || !me->GetMap()->IsRaid()))
                return false;

            int32 hps = GetHPS(target);
            int32 xphp = target->GetHealth() + hps * 2.5f;
            int32 hppctps = int32(hps * 100.f / float(target->GetMaxHealth()));
            int32 xphploss = xphp > int32(target->GetMaxHealth()) ? 0 : abs(int32(xphp - target->GetMaxHealth()));
            int32 xppct = hp + hppctps * 2.5f;
            if (xppct >= 95 && hp >= 25 && !pointed)
                return false;

            if (IsSpellReady(NATURES_SWIFTNESS_1, diff, false) && Rand() < 80 &&
                (me->IsInCombat() || target->IsInCombat()) &&//may just revive
                hp <= 20 && xppct <= 0 && xphploss > _heals[HEALING_WAVE_1] / 2 &&
                (target->GetTypeId() == TYPEID_PLAYER || IsTank(target) || target->IsInCombat() || !target->getAttackers().empty()))
            {
                me->InterruptNonMeleeSpells(false);
                if (doCast(me, GetSpell(NATURES_SWIFTNESS_1)))
                {
                    if (doCast(target, GetSpell(HEALING_WAVE_1)))
                        return true;
                }
            }

            if (IsCasting()) return false;

            Unit const* u = target->GetVictim();
            bool tanking = u && IsTank(target) && u->ToCreature() && u->ToCreature()->isWorldBoss();

            if (IsSpellReady(HEALING_WAVE_1, diff) &&
                (xppct >= 15 || !GetSpell(LESSER_HEALING_WAVE_1)) && xphploss > _heals[HEALING_WAVE_1])
            {
                if (doCast(target, GetSpell(HEALING_WAVE_1)))
                    return true;
            }
            //Riptide stacks from different casters
            if (IsSpellReady(RIPTIDE_1, diff) && hp <= 85 && (tanking || hps < 0 || xphploss > _heals[RIPTIDE_1]) &&
                !target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_SHAMAN, 0x0, 0x0, 0x10, me->GetGUID())
                /*!target->HasAura(GetSpell(RIPTIDE_1), me->GetGUID())*/)
            {
                if (doCast(target, GetSpell(RIPTIDE_1)))
                    return true;
            }
            if (IsSpellReady(CHAIN_HEAL_1, diff) && !IAmFree() && xppct > 35 && xphploss > _heals[CHAIN_HEAL_1] &&
                (!tanking || Rand() < 60 || target->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_SHAMAN, 0x0, 0x0, 0x10, me->GetGUID())))
            {
                if (doCast(target, GetSpell(CHAIN_HEAL_1)))
                    return true;
            }

            if (IsSpellReady(LESSER_HEALING_WAVE_1, diff) && xphploss > _heals[LESSER_HEALING_WAVE_1])
            {
                if (doCast(target, GetSpell(LESSER_HEALING_WAVE_1)))
                    return true;
            }

            return false;
        }

        void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType /*attackType*/) const override
        {
            //if (spellInfo->DmgClass != SPELL_DAMAGE_CLASS_MAGIC)
            //    return;

            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();

            //Call of Thunder: 5% additional critical chance for Lightning Bolt, Chain Lightning and Thunderstorm
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 30 &&
                (spellId == GetSpell(LIGHTNING_BOLT_1) ||
                spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                spellId == GetSpell(THUNDERSTORM_1)))
                crit_chance += 5.f;
            //Tidal Mastery: 5% additional critical chance for lightning spells
            if (lvl >= 25 && (SPELL_SCHOOL_MASK_NATURE & schoolMask))
                crit_chance += 5.f;
            //Blessing of the Eternals: 4% additional critical chance for all spells
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 45)
                crit_chance += 4.f;
            //Tidal Waves (Lesser Healing Wave crit)
            if (spellInfo->SpellFamilyFlags[0] & 0x80)
                if (AuraEffect const* eff = me->GetAuraEffect(TIDAL_WAVES_BUFF, 1, me->GetGUID()))
                    if (eff->IsAffectingSpell(spellInfo))
                        crit_chance += 25.f;
            //Tidal Force
            if (spellInfo->SpellFamilyFlags[0] & 0x1C0)
                if (AuraEffect const* eff = me->GetAuraEffect(TIDAL_FORCE_BUFF, 0, me->GetGUID()))
                    if (eff->IsAffectingSpell(spellInfo))
                        crit_chance += 20.f * eff->GetBase()->GetStackAmount();
        }

        void ApplyClassDamageMultiplierMeleeSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);

            //apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!Melee spell damage is not yet critical, all reduced by half
                //Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost (all) spells
                if (lvl >= 21)
                    pctbonus += 0.25f;
            }

            //SHAMAN_T8_ENCHANCEMENT_2P_BONUS: 20% bonus damage for Lava Lash and Stormstrike
            if (lvl >= 60 &&
                (spellId == STORMSTRIKE_DAMAGE || spellId == STORMSTRIKE_DAMAGE_OFFHAND/* || spellId == LAVA_LASH*/))
                pctbonus += 0.2f;

            //custom bonus to make stormstrike useful
            if (spellId == STORMSTRIKE_DAMAGE || spellId == STORMSTRIKE_DAMAGE_OFFHAND)
                pctbonus += 1.0f;

            damage = int32(fdamage * (1.0f + pctbonus));
        }

        void ApplyClassDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* spellInfo, WeaponAttackType /*attackType*/, bool iscrit) const override
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();
            float fdamage = float(damage);
            float flat_mod = 0.f;

            //2) apply bonus damage mods
            float pctbonus = 0.0f;
            if (iscrit)
            {
                //!!!spell damage is not yet critical and will be multiplied by 1.5
                //so we should put here bonus damage mult /1.5
                //Elemental Fury (part 2): 50% additional crit damage bonus for Nature, Fire and Frost spells
                if (lvl >= 21 &&
                    (spellInfo->GetSchoolMask() & (SPELL_SCHOOL_MASK_NATURE|SPELL_SCHOOL_MASK_FIRE|SPELL_SCHOOL_MASK_FROST)))
                    pctbonus += 0.333f;
                //Lava Flows (part 1): 24% additional crit damage bonus for Lava Burst
                if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 50 && spellId == GetSpell(LAVA_BURST_1))
                    pctbonus += 0.16f;
            }
            //Concussion: 5% bonus damage for Lightning Bolt, Chain Lightning, Thunderstorm, Lava Burst and Shocks
            if (lvl >= 10 &&
                (spellId == GetSpell(LIGHTNING_BOLT_1) ||
                spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                spellId == GetSpell(THUNDERSTORM_1) ||
                spellId == GetSpell(LAVA_BURST_1) ||
                spellId == GetSpell(EARTH_SHOCK_1) ||
                spellId == GetSpell(FROST_SHOCK_1) ||
                spellId == GetSpell(FLAME_SHOCK_1)))
                pctbonus += 0.05f;
            //Call of Flame (part 2): 6% bonus damage for Lava burst
            if (lvl >= 15 && spellId == GetSpell(LAVA_BURST_1))
                pctbonus += 0.06f;
            //Storm, Earth and fire (part 3): 60% bonus damage for Flame Shock (periodic damage in fact but who cares?)
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 40 && spellId == GetSpell(FLAME_SHOCK_1))
                pctbonus += 0.6f;
            //Booming Echoes (part 2): 20% bonus damage for Flame Shock and Frost Shock (direct damage)
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 45 &&
                (spellId == GetSpell(FLAME_SHOCK_1) ||
                spellId == GetSpell(FROST_SHOCK_1)))
                pctbonus += 0.2f;
            //Improved Shields (part 1): 15% bonus damage for Lightning Shield orbs
            if (lvl >= 15 && spellInfo->IsRankOf(sSpellMgr->GetSpellInfo(LIGHTNING_SHIELD_DAMAGE_1)))
                pctbonus += 0.15f;
            //Shamanism: +20/25% bonus from spp
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 45)
            {
                if (spellId == GetSpell(CHAIN_LIGHTNING_1) || spellId == GetSpell(LIGHTNING_BOLT_1))
                    flat_mod += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
                else if (spellId == GetSpell(LAVA_BURST_1))
                    flat_mod += me->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.25f * me->CalculateDefaultCoefficient(spellInfo, SPELL_DIRECT_DAMAGE) * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo);
            }
            //Elemental Oath (part 1): 10% bonus damage
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) &&
                lvl >= 45 && me->GetAuraEffect(ELEMENTAL_FOCUS_BUFF, 0, me->GetGUID()))
                pctbonus += 0.1f;
            //Elemental Weapons (part 1): 40% bonus damage
            if (lvl >= 20 && (spellId == WINDFURY_ATTACK_MAINHAND || spellId == WINDFURY_ATTACK_OFFHAND))
                pctbonus += 0.4f;

            //Totemic Recall: bots have reduced base mana so increase mana gain here
            //if (lvl >= 30 && spellId == GetSpell(TOTEMIC_RECALL_1))
            //    pctbonus += 0.5f;

            damage = int32(fdamage * (1.0f + pctbonus) + flat_mod);
        }

        void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const override
        {
            uint32 spellId = spellInfo->Id;
            uint8 lvl = me->GetLevel();
            float pctbonus = 0.0f;
            float flat_mod = 0.0f;

            //Healing Way: 25% bonus healing for Healing Wave
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 30 && spellId == GetSpell(HEALING_WAVE_1))
                pctbonus += 0.25f;
            //Purification: 10% bonus healing for all spells
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 35)
                pctbonus += 0.1f;
            //Nature's Blessing: 15% of Intellect to healing
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 45)
                flat_mod += GetTotalBotStat(BOT_STAT_MOD_INTELLECT) * 0.15f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * stack * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;
            //Improved Chain Heal: 20% bonus healing for Chain Heal
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 45 && spellId == GetSpell(CHAIN_HEAL_1))
                pctbonus += 0.2f;
            //Improved Earth Shield: 10% bonus healing for Earth Shield
            //Glyph of Earth Shield: 20% bonus healing for Earth Shield
            if (lvl >= 50 && spellId == EARTH_SHIELD_HEAL)
                pctbonus += (GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) ? 0.3f : 0.2f;
            //Improved Shields (part 3): 15% bonus healing for Earth Shield
            if (lvl >= 15 && spellId == EARTH_SHIELD_HEAL)
                pctbonus += 0.15f;
            //Tidal Waves (part 2): 20% bonus (from spellpower) for Healing Wave and 10% bonus (from spellpower) for Lesser Healing Wave
            if ((GetSpec() == BOT_SPEC_SHAMAN_RESTORATION) && lvl >= 55)
            {
                if (spellId == GetSpell(HEALING_WAVE_1))
                    flat_mod += me->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.2f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;
                else if (spellId == GetSpell(LESSER_HEALING_WAVE_1))
                    flat_mod += me->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_MAGIC) * 0.1f * me->CalculateDefaultCoefficient(spellInfo, damagetype) * 1.88f * me->CalculateSpellpowerCoefficientLevelPenalty(spellInfo) * stack;
            }

            heal = heal * (1.0f + pctbonus) + flat_mod;
        }

        void ApplyClassSpellCostMods(SpellInfo const* spellInfo, int32& cost) const override
        {
            //uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float fcost = float(cost);
            int32 flatbonus = 0;
            float pctbonus = 0.0f;

            //percent mods
            //Clearcasting: -40% mana cost
            if (AuraEffect const* eff = me->GetAuraEffect(ELEMENTAL_FOCUS_BUFF, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo))
                    pctbonus += 0.4f;
            //Convection
            if (lvl >= 10 && ((spellInfo->SpellFamilyFlags[0] & 0x90100003) || (spellInfo->SpellFamilyFlags[1] & 0x8001000)))
                pctbonus += 0.1f;
            //Shamanistic Focus
            if (lvl >= 20 && (spellInfo->SpellFamilyFlags[0] & 0x90100000))
                pctbonus += 0.45f;
            //Mental Quickness:
            if ((GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT) && lvl >= 50 && !spellInfo->CalcCastTime())
                pctbonus += 0.06f;
            //Totemic Focus:
            if (lvl >= 10 && (spellInfo->AttributesEx7 & SPELL_ATTR7_SUMMON_PLAYER_TOTEM))
                pctbonus += 0.25f;
            //Tidal Focus:
            if (lvl >= 15 &&
                ((spellInfo->SpellFamilyFlags[0] & 0x1C0) ||
                (spellInfo->SpellFamilyFlags[1] & 0x400) ||
                (spellInfo->SpellFamilyFlags[2] & 0x10)))
                pctbonus += 0.05f;

            //flat mods
            //!1 rage = 10 pts!
            ////Improved Heroic Strike: -3 rage cost for Heroic Strike
            //if (lvl >= 10 && spellId == GetSpell(HEROIC_STRIKE_1))
            //    flatbonus += 30;

            //cost can be < 0
            cost = int32(fcost * (1.0f - pctbonus)) - flatbonus;
        }

        void ApplyClassSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const override
        {
            //casttime is in milliseconds
            uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //100% mods
            //Nature's Swiftness: -100% cast time
            if (AuraEffect const* eff = me->GetAuraEffect(NATURES_SWIFTNESS_1, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo))
                    pctbonus += 1.0f;

            //pct mods
            if (spellId == GetSpell(LIGHTNING_BOLT_1) || spellId == GetSpell(CHAIN_LIGHTNING_1) ||
                spellId == GetSpell(HEALING_WAVE_1) || spellId == GetSpell(LESSER_HEALING_WAVE_1) ||
                spellId == GetSpell(CHAIN_HEAL_1) || spellId == GetSpell(HEX_1))
            {
                Aura* maelstrom = me->GetAura(MAELSTROM_WEAPON_BUFF);
                if (maelstrom)
                {
                    pctbonus += 0.2f * maelstrom->GetStackAmount();
                    maelUseUp = true;
                }
            }
            //Tidal Waves (Healing Wave cast time)
            if (spellInfo->SpellFamilyFlags[0] & 0x40)
                if (AuraEffect const* eff = me->GetAuraEffect(TIDAL_WAVES_BUFF, 0, me->GetGUID()))
                    if (eff->IsAffectingSpell(spellInfo))
                        pctbonus += 0.3f;

            //flat mods
            //Improved Ghost Wolf: -2 sec
            if (lvl >= 10 && spellId == GetSpell(GHOST_WOLF_1))
                timebonus += 2000;
            //Improved Healing Wave: -0.5 sec
            if (lvl >= 10 && spellId == GetSpell(HEALING_WAVE_1))
                timebonus += 500;
            //Lightning Mastery: -0.5 sec
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) &&
                lvl >= 35 && ((spellInfo->SpellFamilyFlags[0] & 0x3) || (spellInfo->SpellFamilyFlags[1] & 0x1000)))
                timebonus += 500;
            //Stormcaller Chain Heal Bonus (26122): -0.4 sec
            if (lvl >= 60 && spellId == GetSpell(CHAIN_HEAL_1))
                timebonus += 400;

            casttime = std::max<int32>((float(casttime) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //pct mods
            //Glyph of Rapid Charge: -7% cooldown for Charge
            //if (lvl >= 40 && spellId == GetSpell(CHARGE_1))
            //    pctbonus += 0.07f;

            //flat mods
            //Reverberation
            if (lvl >= 20 && ((spellInfo->SpellFamilyFlags[0] & 0x90100000) || (spellInfo->SpellFamilyFlags[1] & 0x8000000)))
                timebonus += 1000;
            //Booming Echoes (part 1)
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 45 && (spellInfo->SpellFamilyFlags[0] & 0x90000000))
                timebonus += 2000;
            //Storm, Earth and Fire (part 1)
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 40 && (spellInfo->SpellFamilyFlags[0] & 0x2))
                timebonus += 2500;
            //Improved Fire Nova (part 2)
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && lvl >= 25 && (spellInfo->SpellFamilyFlags[0] & 0x8000000))
                timebonus += 4000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const override
        {
            //cooldown is in milliseconds
            uint32 spellId = spellInfo->Id;
            //uint8 lvl = me->GetLevel();
            int32 timebonus = 0;
            float pctbonus = 0.0f;

            //Improved Reincarnation + Reduced Reincarnation Cooldown: -20 min cooldown for Reincarnation
            if (spellId == GetSpell(REINCARNATION_1))
                timebonus += 1200000;

            cooldown = std::max<int32>((float(cooldown) * (1.0f - pctbonus)) - timebonus, 0);
        }

        void ApplyClassSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const override
        {
            //cooldown is in milliseconds
            //uint32 spellId = spellInfo->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float timebonus = 0.0f;
            float pctbonus = 0.0f;

            //Glyph of Shocking: -0.5 sec global cooldown for Shocks
            if (lvl >= 15 && ((spellInfo->SpellFamilyFlags[0] & 0x90100000) || (spellInfo->SpellFamilyFlags[1] & 0x8000000)))
                timebonus += 500.f;

            cooldown = (cooldown * (1.0f - pctbonus)) - timebonus;
        }

        void ApplyClassSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const override
        {
            //uint32 spellId = spellInfo->Id;
            //uint32 baseId = spellInfo->GetFirstRankSpell()->Id;
            //SpellSchool school = GetFirstSchoolInMask(spellInfo->GetSchoolMask());
            uint8 lvl = me->GetLevel();
            float flatbonus = 0.0f;
            float pctbonus = 0.0f;

            //pct mods
            //Grim Reach: +20% range for Affliction Spells
            //if (lvl >= 25 && ((spellInfo->SpellFamilyFlags[0] & 0x8048C41A) || (spellInfo->SpellFamilyFlags[1] & 0x40713)))
            //    pctbonus += 0.2f;

            //flat mods
            //Elemental Reach part 1: +6 yd
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) &&
                lvl >= 30 && ((spellInfo->SpellFamilyFlags[0] & 0x8000003) || (spellInfo->SpellFamilyFlags[1] & 0x1000)))
                flatbonus += 6.f;
            //Elemental Reach part 2: +15 yd
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) &&
                lvl >= 30 && (spellInfo->SpellFamilyFlags[0] & 0x10000000))
                flatbonus += 15.f;

            maxrange = maxrange * (1.0f + pctbonus) + flatbonus;
        }

        void ApplyClassSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const override
        {
            uint32 bonusTargets = 0;

            //Glyph of Chain Heal
            if (spellInfo->SpellFamilyFlags[0] & 0x100)
                bonusTargets += 1;
            //Glyph of Chain Lightning
            if (spellInfo->SpellFamilyFlags[0] & 0x2)
                bonusTargets += 1;
            //Chain Healing Wave (23573)
            if (me->GetLevel() >= 60 && spellInfo->SpellFamilyFlags[0] & 0x100)
                bonusTargets += 2;

            targets = targets + bonusTargets;
        }

        void OnClassSpellGo(SpellInfo const* spellInfo) override
        {
            //uint32 spellId = spellInfo->Id;
            uint32 baseId = spellInfo->GetFirstRankSpell()->Id;

            //reincarnation: notify master
            if (baseId == REINCARNATION_1 && !IAmFree())
            {
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);

                //no spellHit trigger - do it here
                SpellHit(me, spellInfo);
                me->CastSpell(me, RESURRECTION_VISUAL_SPELL, true);
            }
            //manatide: notify
            if (baseId == MANA_TIDE_TOTEM_1 && !IAmFree())
            {
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);
            }
            //Nature's Swiftness: notify master
            if (baseId == NATURES_SWIFTNESS_1 && !IAmFree())
            {
                ReportSpellCast(baseId, LocalizedNpcText(master, BOT_TEXT__USED), master);
            }

            //Handle Clearcasting
            if (AuraEffect* eff = me->GetAuraEffect(ELEMENTAL_FOCUS_BUFF, 0, me->GetGUID()))
                if (eff->IsAffectingSpell(spellInfo))
                    eff->GetBase()->DropCharge();
            //Handle Tidal Focus
            //Healing Wave (cast time): if full Maelstrom than don't use up charge
            if (MaelstromCount < 5 && (spellInfo->SpellFamilyFlags[0] & 0x40))
                if (AuraEffect* eff = me->GetAuraEffect(TIDAL_WAVES_BUFF, 0, me->GetGUID()))
                    if (eff->IsAffectingSpell(spellInfo))
                        eff->GetBase()->DropCharge();
            //Lesser Healing Wave (crit)
            if (spellInfo->SpellFamilyFlags[0] & 0x80)
                if (AuraEffect* eff = me->GetAuraEffect(TIDAL_WAVES_BUFF, 1, me->GetGUID()))
                    if (eff->IsAffectingSpell(spellInfo))
                        eff->GetBase()->DropCharge();

            //Nature's Swiftness
            if (AuraEffect const* eff = me->GetAuraEffect(NATURES_SWIFTNESS_1, 0, me->GetGUID()))
            {
                if (eff->IsAffectingSpell(spellInfo))
                    me->RemoveAurasDueToSpell(NATURES_SWIFTNESS_1);
            }

            //Tidal Force: Handled in Unit::HandleDummyAuraProc(): case 55166:
            //if (spellInfo->SpellFamilyFlags[0] & 0x1C0)
            //    if (AuraEffect const* eff = me->GetAuraEffect(TIDAL_FORCE_BUFF, 0, me->GetGUID()))
            //        if (eff->IsAffectingSpell(spellInfo))
            //            me->RemoveAuraFromStack(TIDAL_FORCE_BUFF);

            //Shield cd
            if (baseId == LIGHTNING_SHIELD_DAMAGE_1)
                SetSpellCooldown(LIGHTNING_SHIELD_DAMAGE_1, 3000); //is that right? from spell_proc_event

            //autouse totems
            if (baseId == EARTHBIND_TOTEM_1 || baseId == STRENGTH_OF_EARTH_TOTEM_1)
                TotemTimer[T_EARTH] = 5000;
            if (baseId == TREMOR_TOTEM_1)
                TotemTimer[T_EARTH] = 12000;
            if (baseId == MAGMA_TOTEM_1)
                TotemTimer[T_FIRE] = 12000;
            if (baseId == TOTEM_OF_WRATH_1 || baseId == FLAMETONGUE_TOTEM_1)
                TotemTimer[T_FIRE] = 5000;
            if (baseId == FROST_RESISTANCE_TOTEM_1)
                TotemTimer[T_FIRE] = 120000;
            if (baseId == MANA_TIDE_TOTEM_1)
                TotemTimer[T_WATER] = 12000;
            if (baseId == MANA_SPRING_TOTEM_1)
                TotemTimer[T_WATER] = 5000;
            if (baseId == FIRE_RESISTANCE_TOTEM_1)
                TotemTimer[T_WATER] = 120000;
            if (baseId == GROUNDING_TOTEM_1)
                TotemTimer[T_AIR] = me->GetLevel() >= 15 ? 13000 : 15000;
            if (baseId == WRATH_OF_AIR_TOTEM_1 || baseId == WINDFURY_TOTEM_1)
                TotemTimer[T_AIR] = 5000;
            if (baseId == NATURE_RESISTANCE_TOTEM_1)
                TotemTimer[T_AIR] = 120000;
            //other (manual use)
            if (baseId == STONECLAW_TOTEM_1)
                TotemTimer[T_EARTH] = 15000;
            if (baseId == STONESKIN_TOTEM_1)
                TotemTimer[T_EARTH] = 300000;
            if (baseId == EARTH_ELEMENTAL_TOTEM_1)
                TotemTimer[T_EARTH] = 120000;
            if (baseId == SEARING_TOTEM_1)
                TotemTimer[T_FIRE] = 60000;
            if (baseId == FIRE_ELEMENTAL_TOTEM_1)
                TotemTimer[T_FIRE] = 120000;
            if (baseId == CLEANSING_TOTEM_1)
                TotemTimer[T_WATER] = 300000;
            if (baseId == HEALING_STREAM_TOTEM_1)
                TotemTimer[T_WATER] = 300000;

            //Totemic Recall totems resummon helper
            if (baseId == TOTEMIC_RECALL_1)
            {
                TotemsCheckTimer = GC_Timer;
                for (uint8 i = 0; i != MAX_TOTEMS; ++i)
                    TotemTimer[i] = 0;
            }

            if (maelUseUp)
            {
                if (baseId == LIGHTNING_BOLT_1 || baseId == CHAIN_LIGHTNING_1 || baseId == HEALING_WAVE_1 ||
                    baseId == LESSER_HEALING_WAVE_1 || baseId == CHAIN_HEAL_1 || baseId == HEX_1)
                {
                    MaelstromCount = 0;
                    me->RemoveAurasDueToSpell(MAELSTROM_WEAPON_BUFF);
                }
            }

            //Item enchant
            //We don't know which item is targeted
            //Actually it is mh, then oh
            if (/*baseId == ROCKBITER_WEAPON_1 || */baseId == FLAMETONGUE_WEAPON_1 || baseId == FROSTBRAND_WEAPON_1 ||
                baseId == WINDFURY_WEAPON_1 || baseId == EARTHLIVING_WEAPON_1)
            {
                //We set duration to 2 seconds to prevent exploiting unequip mechanic
                //to get enchanted weapons for player (for non-shaman bots it won't work)
                uint32 slot = TEMP_ENCHANTMENT_SLOT;
                uint32 duration = 2 * IN_MILLISECONDS;
                uint32 charges = 0;
                uint32 enchant_id = spellInfo->_effects[0].MiscValue;
                //SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
                Item* mh = GetEquips(BOT_SLOT_MAINHAND);
                Item* oh = GetEquips(BOT_SLOT_OFFHAND);
                Item* item = nullptr;
                uint8 itemSlot = 0;

                if (mh && !mh->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT)/* && mh->IsFitToSpellRequirements(spellInfo)*/)
                {
                    item = mh;
                    itemSlot = BOT_SLOT_MAINHAND;
                }
                else if (oh && !oh->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT)/* && oh->IsFitToSpellRequirements(spellInfo)*/)
                {
                    item = oh;
                    itemSlot = BOT_SLOT_OFFHAND;
                }
                else
                    ASSERT(false, "shaman bot attempted to enchant his weapons but cannot find a weapon to apply it!");

                if (!IAmFree())
                    master->GetSession()->SendEnchantmentLog(me->GetGUID(), me->GetGUID(), item->GetEntry(), enchant_id);

                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_ID_OFFSET, enchant_id);
                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_DURATION_OFFSET, duration);
                item->SetUInt32Value(ITEM_FIELD_ENCHANTMENT_1_1 + slot*MAX_ENCHANTMENT_OFFSET + ENCHANTMENT_CHARGES_OFFSET, charges);
                ApplyItemEnchantment(item, TEMP_ENCHANTMENT_SLOT, itemSlot);
                if (itemSlot == BOT_SLOT_MAINHAND)
                    mhEnchantExpireTimer = ITEM_ENCHANTMENT_EXPIRE_TIMER;
                else if (itemSlot == BOT_SLOT_OFFHAND)
                    ohEnchantExpireTimer = ITEM_ENCHANTMENT_EXPIRE_TIMER;
                GC_Timer = 1500; //needed
            }
        }

        void SpellHit(WorldObject* wcaster, SpellInfo const* spell) override
        {
            Unit* caster = wcaster->ToUnit();
            if (!caster)
                return;

            uint32 spellId = spell->Id;

            //Maelstrom Weapon helper
            if (spellId == MAELSTROM_WEAPON_BUFF)
            {
                if (Aura const* mwb = me->GetAura(MAELSTROM_WEAPON_BUFF))
                    MaelstromCount = mwb->GetStackAmount();

                MaelstromTimer = 30000; //30 sec duration then reset
            }

            OnSpellHit(caster, spell);
        }

        void SpellHitTarget(WorldObject* wtarget, SpellInfo const* spell) override
        {
            Unit* target = wtarget->ToUnit();
            if (!target)
                return;

            uint32 spellId = spell->Id;
            uint32 baseId = spell->GetFirstRankSpell()->Id;

            if (baseId == EARTH_SHIELD_1)
                Earthy = true;

            if (baseId == HEX_1)
            {
                Hexy = true;
                HexyCheckTimer += 2000;
            }

            //Earthen Power part 2
            if ((GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT) && me->GetLevel() >= 50 && baseId == EARTH_SHOCK_1)
            {
                if (AuraEffect* eff = target->GetAuraEffect(spellId, 0, me->GetGUID()))
                    eff->ChangeAmount(eff->GetAmount() * 2);
            }

            //Lightning Overload
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) &&
                me->GetLevel() >= 45 && (baseId == LIGHTNING_BOLT_1 || baseId == CHAIN_LIGHTNING_1) &&
                urand(1,100) <= 33)
            {
                uint32 procId = 0;
                switch (spellId)
                {
                    // Lightning Bolt
                    case   403: procId = 45284; break; // Rank  1
                    case   529: procId = 45286; break; // Rank  2
                    case   548: procId = 45287; break; // Rank  3
                    case   915: procId = 45288; break; // Rank  4
                    case   943: procId = 45289; break; // Rank  5
                    case  6041: procId = 45290; break; // Rank  6
                    case 10391: procId = 45291; break; // Rank  7
                    case 10392: procId = 45292; break; // Rank  8
                    case 15207: procId = 45293; break; // Rank  9
                    case 15208: procId = 45294; break; // Rank 10
                    case 25448: procId = 45295; break; // Rank 11
                    case 25449: procId = 45296; break; // Rank 12
                    case 49237: procId = 49239; break; // Rank 13
                    case 49238: procId = 49240; break; // Rank 14
                    // Chain Lightning
                    case   421: procId = 45297; break; // Rank  1
                    case   930: procId = 45298; break; // Rank  2
                    case  2860: procId = 45299; break; // Rank  3
                    case 10605: procId = 45300; break; // Rank  4
                    case 25439: procId = 45301; break; // Rank  5
                    case 25442: procId = 45302; break; // Rank  6
                    case 49270: procId = 49268; break; // Rank  7
                    case 49271: procId = 49269; break; // Rank  8
                    default:                    break;
                }

                if (procId)
                {
                    if (baseId == LIGHTNING_BOLT_1)
                        me->CastSpell(target, procId, true);
                    if (baseId == CHAIN_LIGHTNING_1)
                    {
                        //Normalize chance
                        if (urand(1,100) <= (100.f / spell->_effects[0].ChainTarget))
                            me->CastSpell(target, procId, true);
                    }
                }
            }

            //Shields improvement, replaces Static Shock (part 2) and Improved Earth Shield (part 1)
            if (baseId == LIGHTNING_SHIELD_1 || baseId == EARTH_SHIELD_1 || baseId == WATER_SHIELD_1)
            {
                if (Aura* shield = target->GetAura(spellId, me->GetGUID()))
                {
                    shield->SetCharges(shield->GetCharges() + 6);
                }
            }

            OnSpellHitTarget(target, spell);
        }

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override
        {
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

        uint8 GetPetPositionNumber(Creature const* summon) const override
        {
            for (uint8 i = 0; i != MAX_WOLVES; ++i)
                if (_wolves[i] == summon->GetGUID())
                    return i;

            return 0;
        }

        void SummonBotPet(Unit* target)
        {
            UnsummonWolves();

            uint32 entry = BOT_PET_SPIRIT_WOLF;

            for (uint8 i = 0; i != MAX_WOLVES; ++i)
            {
                //Position pos;

                //45 sec duration
                Creature* myPet = me->SummonCreature(entry, *me, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 5s);
                //me->GetNearPoint(myPet, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0, 2, me->GetOrientation());
                //myPet->GetMotionMaster()->MovePoint(me->GetMapId(), pos);
                myPet->SetCreator(master);
                myPet->SetOwnerGUID(me->GetGUID());
                myPet->SetFaction(master->GetFaction());
                myPet->SetControlledByPlayer(!IAmFree());
                myPet->SetPvP(me->IsPvP());
                myPet->SetByteValue(UNIT_FIELD_BYTES_2, 1, master->GetByteValue(UNIT_FIELD_BYTES_2, 1));
                myPet->SetUInt32Value(UNIT_CREATED_BY_SPELL, FERAL_SPIRIT_1);

                //botPet = myPet;

                myPet->Attack(target, true);
                if (!HasBotCommandState(BOT_COMMAND_MASK_UNCHASE))
                    myPet->GetMotionMaster()->MoveChase(target);
            }
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == BOT_PET_SPIRIT_WOLF)
            {
                bool found = false;
                for (uint8 i = 0; i != MAX_WOLVES; ++i)
                {
                    if (!_wolves[i])
                    {
                        _wolves[i] = summon->GetGUID();
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    TC_LOG_ERROR("entities.unit", "Shaman_bot:JustSummoned() wolves array is full");
                    ASSERT(false);
                }
            }
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            //TC_LOG_ERROR("entities.unit", "SummonedCreatureDespawn: {}'s {}", me->GetName(), summon->GetName());
            //if (summon == botPet)
            //    botPet = nullptr;
            if (summon->GetEntry() == BOT_PET_SPIRIT_WOLF)
            {
                //bool found = false;
                for (uint8 i = 0; i != MAX_WOLVES; ++i)
                {
                    if (_wolves[i] == summon->GetGUID())
                    {
                        _wolves[i] = ObjectGuid::Empty;
                        //found = true;
                        break;
                    }
                }
                //if (!found)
                //{
                //    TC_LOG_ERROR("entities.unit", "Shaman_bot:SummonedCreatureDespawn() wolf is not found in array");
                //    ASSERT(false);
                //}
            }
        }

        void UnsummonWolves()
        {
            for (uint8 i = 0; i != MAX_WOLVES; ++i)
            {
                if (_wolves[i])
                {
                    if (Unit* wo = ObjectAccessor::GetUnit(*me, _wolves[i]))
                        wo->ToTempSummon()->UnSummon();
                    else
                        _wolves[i] = ObjectGuid::Empty;
                }
            }
        }

        void UnsummonAll(bool /*savePets*/ = true) override
        {
            UnsummonWolves();

            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
            {
                if (_totems[i].first != ObjectGuid::Empty)
                {
                    Unit* to = ObjectAccessor::GetUnit(*me, _totems[i].first);
                    if (!to)
                    {
                        //TC_LOG_ERROR("entities.player", "{} has no totem in slot {} during remove!", me->GetName(), i);
                        continue;
                    }
                    to->ToTotem()->UnSummon();
                }
            }
        }

        void OnBotDespawn(Creature* summon) override
        {
            if (!summon)
            {
                TC_LOG_ERROR("entities.player", "OnBotDespawn(): Shaman bot {} received NULL", me->GetName());
                ASSERT(false);
                //UnsummonAll(false);
                return;
            }

            TempSummon const* totem = summon->ToTempSummon();
            if (!totem || !totem->IsTotem())
            {
                //TC_LOG_ERROR("entities.player", "OnBotDespawn(): Shaman bot {} has despawned summon {} which is not a temp summon or not a totem...", me->GetName(), summon->GetName());
                return;
            }

            int8 slot = -1;
            switch (totem->m_Properties->Slot)
            {
                case SUMMON_SLOT_TOTEM_FIRE:    slot = T_FIRE;  break;
                case SUMMON_SLOT_TOTEM_EARTH:   slot = T_EARTH; break;
                case SUMMON_SLOT_TOTEM_WATER:   slot = T_WATER; break;
                case SUMMON_SLOT_TOTEM_AIR:     slot = T_AIR;   break;
                default:
                    TC_LOG_ERROR("entities.player", "OnBotDespawn(): Shaman bot {} has despawned totem {} in unknown slot {}", me->GetName(), summon->GetName(), totem->m_Properties->ID);
                    return;
            }

            if (_totems[slot].first == ObjectGuid::Empty)
                TC_LOG_ERROR("entities.player", "OnBotDespawn(): Shaman bot {} has despawned totem {} while not having it registered!", me->GetName(), summon->GetName());
            else if (_totems[slot].second._type == BOT_TOTEM_NONE || _totems[slot].second._type >= BOT_TOTEM_END)
                TC_LOG_ERROR("entities.player", "OnBotDespawn(): Shaman bot {} has despawned totem {} with no type assigned!", me->GetName(), summon->GetName());

            //here we reset totem category cd (not totem spell cd) if totem is destroyed
            //TC_LOG_ERROR("entities.player", "OnBotDespawn(): {} despawned ({} : {})", summon->GetName(), summon->IsAlive() ? "alive" : summon->isDying() ? "justdied" : "unk", (uint32)summon->getDeathState());
            if (!summon->IsAlive()) // alive here means totem is being replaced or unsummoned through other means
                TotemTimer[slot] = 0;

            _totems[slot].first = ObjectGuid::Empty;
            _totems[slot].second._type = BOT_TOTEM_NONE;
            me->m_SummonSlot[slot+1] = ObjectGuid::Empty;
        }

        void OnBotSummon(Creature* summon) override
        {
            TempSummon const* totem = summon->ToTempSummon();
            if (!totem || !totem->IsTotem())
            {
                //TC_LOG_ERROR("entities.player", "OnBotSummon(): Shaman bot {} has summoned creature {} which is not a temp summon or not a totem...", me->GetName(), summon->GetName());
                return;
            }

            int8 slot = -1;
            switch (totem->m_Properties->Slot)
            {
                case SUMMON_SLOT_TOTEM_FIRE:    slot = T_FIRE;  break;
                case SUMMON_SLOT_TOTEM_EARTH:   slot = T_EARTH; break;
                case SUMMON_SLOT_TOTEM_WATER:   slot = T_WATER; break;
                case SUMMON_SLOT_TOTEM_AIR:     slot = T_AIR;   break;
                default:
                    TC_LOG_ERROR("entities.player", "OnBotSummon(): Shaman bot {} has summoned totem {} with unknown type {}", me->GetName(), summon->GetName(), totem->m_Properties->ID);
                    return;
            }

            //Unsummon current totem
            ObjectGuid curTotemGUID = _totems[slot].first;
            if (curTotemGUID)
            {
                Unit* curTotem = ObjectAccessor::GetUnit(*me, curTotemGUID);
                if (curTotem)
                    curTotem->ToTotem()->UnSummon();
            }

            float radius = 30.f;
            if (SpellInfo const* info = sSpellMgr->GetSpellInfo(summon->m_spells[0]))
                if (SpellRadiusEntry const* entry = info->_effects[0].RadiusEntry)
                    radius = std::max<float>(entry->RadiusMax, radius);

            uint32 createSpell = summon->GetUInt32Value(UNIT_CREATED_BY_SPELL);
            if (createSpell)
                createSpell = sSpellMgr->GetSpellInfo(createSpell)->GetFirstRankSpell()->Id;
            //DEBUG
            //if (!IAmFree())
            //{
            //    std::ostringstream msg;
            //    msg << "Summoned " << summon->GetName() << " by basespell: " << createSpell;
            //    BotWhisper(msg.str().c_str());
            //}
            uint32 btype;
            switch (createSpell)
            {
                case SEARING_TOTEM_1:           btype = BOT_TOTEM_SEARING;              break;
                case STONECLAW_TOTEM_1:         btype = BOT_TOTEM_STONECLAW;            break;
                case SENTRY_TOTEM_1:            btype = BOT_TOTEM_SENTRY;               break;
                case STONESKIN_TOTEM_1:         btype = BOT_TOTEM_STONESKIN;            break;
                case HEALING_STREAM_TOTEM_1:    btype = BOT_TOTEM_HEALING_STREAM;       break;
                case EARTHBIND_TOTEM_1:         btype = BOT_TOTEM_EARTHBIND;            break;
                case EARTH_ELEMENTAL_TOTEM_1:   btype = BOT_TOTEM_ELEMENTAL_EARTH;      break;
                case FIRE_ELEMENTAL_TOTEM_1:    btype = BOT_TOTEM_ELEMENTAL_FIRE;       break;
                case MAGMA_TOTEM_1:             btype = BOT_TOTEM_MAGMA;                break;
                case FLAMETONGUE_TOTEM_1:       btype = BOT_TOTEM_FLAMETONGUE;          break;
                case FROST_RESISTANCE_TOTEM_1:  btype = BOT_TOTEM_RESISTANCE_FROST;     break;
                case FIRE_RESISTANCE_TOTEM_1:   btype = BOT_TOTEM_RESISTANCE_FIRE;      break;
                case NATURE_RESISTANCE_TOTEM_1: btype = BOT_TOTEM_RESISTANCE_NATURE;    break;
                case GROUNDING_TOTEM_1:         btype = BOT_TOTEM_GROUNDING;            break;
                case STRENGTH_OF_EARTH_TOTEM_1: btype = BOT_TOTEM_STRENGTH_OF_EARTH;    break;
                case WINDFURY_TOTEM_1:          btype = BOT_TOTEM_WINDFURY;             break;
                case WRATH_OF_AIR_TOTEM_1:      btype = BOT_TOTEM_WRATH_OF_AIR;         break;
                case CLEANSING_TOTEM_1:         btype = BOT_TOTEM_CLEANSING;            break;
                case MANA_SPRING_TOTEM_1:       btype = BOT_TOTEM_MANA_SPRING;          break;
                case MANA_TIDE_TOTEM_1:         btype = BOT_TOTEM_MANA_TIDE;            break;
                case TREMOR_TOTEM_1:            btype = BOT_TOTEM_TREMOR;               break;
                case TOTEM_OF_WRATH_1:          btype = BOT_TOTEM_WRATH;                break;
                default:
                {
                    TC_LOG_ERROR("scripts", "Unknown totem create spell {}!", createSpell);
                    btype = BOT_TOTEM_NONE;
                    break;
                }
            }
            _totems[slot].first = summon->GetGUID();
            _totems[slot].second._pos.Relocate(*summon);
            _totems[slot].second._effradius = !((1<<btype) & BOT_TOTEM_MASK_SUMMONS) ? radius : SIZE_OF_GRIDS;
            _totems[slot].second._type = btype;
            me->m_SummonSlot[slot+1] = _totems[slot].first; //needed for scripts handlers

            //TC_LOG_ERROR("entities.player", "shaman bot: summoned {} (type {}) at x={}, y={}, z={}",
            //    summon->GetName(), slot + 1, _totems[slot].second.pos.GetPositionX(), _totems[slot].second.pos.GetPositionY(), _totems[slot].second.pos.GetPositionZ());

            //TODO: gets overriden in Spell::EffectSummonType (end)
            //Without setting creator correctly it will be impossible to use summon X elemental totems
            summon->SetCreator(me);
            summon->SetDisplayId(sObjectMgr->GetModelForTotem(SummonSlot(slot+1), Races(me->GetRace())));
            summon->SetFaction(me->GetFaction());
            summon->SetPvP(me->IsPvP());
            summon->SetOwnerGUID(master->GetGUID());
            summon->SetControlledByPlayer(!IAmFree());
            //summon->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
            // totem will claim master's summon slot
            // free it to avoid conflicts with other shaman bots and master
            // if master is a shaman his totem will despawn
            // fixed in summoning sequence
            //master->m_SummonSlot[++slot] = 0;

            //After summon effects which are not handled for bot totems
            //check by btype

            // Storm, Earth and Fire: Earthbind totem AoE root
            if ((GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL) && btype == BOT_TOTEM_EARTHBIND && me->GetLevel() >= 40)
            {
                //master's talent will be found so do not cast earthgrab twice, instead let spell script roll the chance
                //see spell_shaman.cpp
                if (!master->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 3063, EFFECT_1))
                    summon->CastSpell(summon, STORMEARTHANDFIRE_EARTHGRAB, false);
            }
        }

        float GetSpellAttackRange(bool longRange) const override
        {
            return longRange ? CalcSpellMaxRange(LIGHTNING_BOLT_1) : 20.f;
        }

        uint32 GetAIMiscValue(uint32 data) const override
        {
            switch (data)
            {
                case BOTAI_MISC_ENCHANT_IS_AUTO_MH:
                    return needChooseMHEnchant;
                case BOTAI_MISC_ENCHANT_IS_AUTO_OH:
                    return needChooseOHEnchant;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH:
                    return mhEnchantExpireTimer;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH:
                    return ohEnchantExpireTimer;
                case BOTAI_MISC_ENCHANT_CURRENT_MH:
                    return mhEnchant;
                case BOTAI_MISC_ENCHANT_CURRENT_OH:
                    return ohEnchant;
                case BOTAI_MISC_ENCHANT_AVAILABLE_1:
                    return /*GetSpell(ROCKBITER_WEAPON_1) ? ROCKBITER_WEAPON_1 : */0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_2:
                    return GetSpell(FLAMETONGUE_WEAPON_1) ? FLAMETONGUE_WEAPON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_3:
                    return GetSpell(FROSTBRAND_WEAPON_1) ? FROSTBRAND_WEAPON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_4:
                    return GetSpell(WINDFURY_WEAPON_1) ? WINDFURY_WEAPON_1 : 0;
                case BOTAI_MISC_ENCHANT_AVAILABLE_5:
                    return GetSpell(EARTHLIVING_WEAPON_1) ? EARTHLIVING_WEAPON_1 : 0;
                case BOTAI_MISC_PET_TYPE:
                    return BOT_PET_SPIRIT_WOLF;
                default:
                    return 0;
            }
        }

        void SetAIMiscValue(uint32 data, uint32 value) override
        {
            switch (data)
            {
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_MH:
                    if (value)
                        mhEnchantExpireTimer = 0;
                    break;
                case BOTAI_MISC_ENCHANT_CAN_EXPIRE_OH:
                    if (value)
                        ohEnchantExpireTimer = 0;
                    break;
                case BOTAI_MISC_ENCHANT_CURRENT_MH:
                    mhEnchant = value;
                    needChooseMHEnchant = value ? false : true;
                    break;
                case BOTAI_MISC_ENCHANT_CURRENT_OH:
                    ohEnchant = value;
                    needChooseOHEnchant = value ? false : true;
                    break;
                default:
                    break;
            }
        }

        void Reset() override
        {
            UnsummonAll(false);
            for (uint8 i = 0; i != MAX_WOLVES; ++i)
                _wolves[i] = ObjectGuid::Empty;
            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
                TotemTimer[i] = 0;

            removeShapeshiftForm();

            TotemsCheckTimer = 1500;

            HexyCheckTimer = 3000;
            EarthyCheckTimer = 2000;
            ShieldCheckTimer = 2000;
            BloodlustCheckTimer = 5000;
            MaelstromTimer = 0;

            MaelstromCount = 0;

            Hexy = false;
            Earthy = false;
            maelUseUp = false;

            mhEnchantExpireTimer = 1;
            ohEnchantExpireTimer = 1;

            DefaultInit();

            mhEnchant = 0;
            ohEnchant = 0;
            needChooseMHEnchant = true;
            needChooseOHEnchant = true;
        }

        void ReduceCD(uint32 diff) override
        {
            for (uint8 i = 0; i != MAX_TOTEMS; ++i)
                if (TotemTimer[i] > diff)
                    TotemTimer[i] -= diff;

            if (TotemsCheckTimer > diff)        TotemsCheckTimer -= diff;

            if (HexyCheckTimer > diff)          HexyCheckTimer -= diff;
            if (EarthyCheckTimer > diff)        EarthyCheckTimer -= diff;
            if (ShieldCheckTimer > diff)        ShieldCheckTimer -= diff;
            if (BloodlustCheckTimer > diff)     BloodlustCheckTimer -= diff;

            if (MaelstromTimer > diff)          MaelstromTimer -= diff;
            else if (MaelstromCount) { MaelstromCount = 0; maelUseUp = false; }

            if (mhEnchantExpireTimer > diff)    mhEnchantExpireTimer -= diff;
            if (ohEnchantExpireTimer > diff)    ohEnchantExpireTimer -= diff;
        }

        void InitPowers() override
        {
            me->SetPowerType(POWER_MANA);
        }

        void InitSpells() override
        {
            uint8 lvl = me->GetLevel();
            bool isElem = GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL;
            bool isEnha = GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT;
            bool isRest = GetSpec() == BOT_SPEC_SHAMAN_RESTORATION;

            InitSpellMap(HEALING_WAVE_1);
            InitSpellMap(CHAIN_HEAL_1);
            InitSpellMap(LESSER_HEALING_WAVE_1);
            InitSpellMap(ANCESTRAL_SPIRIT_1);
            InitSpellMap(CURE_TOXINS_1);
            InitSpellMap(FLAME_SHOCK_1);
            InitSpellMap(EARTH_SHOCK_1);
            InitSpellMap(FROST_SHOCK_1);
            InitSpellMap(LIGHTNING_BOLT_1);
            InitSpellMap(CHAIN_LIGHTNING_1);
            InitSpellMap(LAVA_BURST_1);
            InitSpellMap(LIGHTNING_SHIELD_1);
            InitSpellMap(WATER_SHIELD_1);
            InitSpellMap(WATER_BREATHING_1);
            InitSpellMap(WATER_WALKING_1);
            InitSpellMap(PURGE_1);
            InitSpellMap(WIND_SHEAR_1);
            InitSpellMap(HEX_1);
            InitSpellMap((me->GetRaceMask() & RACEMASK_ALLIANCE) ? HEROISM_1 : BLOODLUST_1); //at least race is constant

            InitSpellMap(GHOST_WOLF_1);

            InitSpellMap(FIRE_NOVA_1);
            //totems
            InitSpellMap(EARTHBIND_TOTEM_1);
            InitSpellMap(MAGMA_TOTEM_1);
            //InitSpellMap(SEARING_TOTEM_1);
            //InitSpellMap(STONECLAW_TOTEM_1);
            InitSpellMap(FIRE_ELEMENTAL_TOTEM_1);
            InitSpellMap(EARTH_ELEMENTAL_TOTEM_1);
            InitSpellMap(FIRE_RESISTANCE_TOTEM_1);
            InitSpellMap(FROST_RESISTANCE_TOTEM_1);
            InitSpellMap(NATURE_RESISTANCE_TOTEM_1);
            InitSpellMap(FLAMETONGUE_TOTEM_1);
            InitSpellMap(GROUNDING_TOTEM_1);
            //InitSpellMap(SENTRY_TOTEM_1);
            //InitSpellMap(STONESKIN_TOTEM_1);
            InitSpellMap(STRENGTH_OF_EARTH_TOTEM_1);
            InitSpellMap(WINDFURY_TOTEM_1);
            InitSpellMap(WRATH_OF_AIR_TOTEM_1);
            InitSpellMap(CLEANSING_TOTEM_1);
            //InitSpellMap(HEALING_STREAM_TOTEM_1);
            InitSpellMap(MANA_SPRING_TOTEM_1);
            InitSpellMap(TREMOR_TOTEM_1);

            InitSpellMap(TOTEMIC_RECALL_1);

            InitSpellMap(REINCARNATION_1); //base lvl 30, 30 min cd

  /*Talent*///lvl >= 40 && isElem ? InitSpellMap(ELEMENTAL_MASTERY_1) : RemoveSpell(ELEMENTAL_MASTERY_1);
  /*Talent*/lvl >= 60 && isElem ? InitSpellMap(THUNDERSTORM_1) : RemoveSpell(THUNDERSTORM_1);

  /*Talent*/lvl >= 40 && isEnha ? InitSpellMap(STORMSTRIKE_1) : RemoveSpell(STORMSTRIKE_1);
  /*Talent*/lvl >= 50 && isEnha ? InitSpellMap(SHAMANISTIC_RAGE_1) : RemoveSpell(SHAMANISTIC_RAGE_1);
  /*Talent*/lvl >= 60 && isEnha ? InitSpellMap(FERAL_SPIRIT_1) : RemoveSpell(FERAL_SPIRIT_1); //not casted

  /*Talent*/lvl >= 20 && isRest ? InitSpellMap(TIDAL_FORCE_1) : RemoveSpell(TIDAL_FORCE_1);
  /*Talent*/lvl >= 30 && isRest ? InitSpellMap(NATURES_SWIFTNESS_1) : RemoveSpell(NATURES_SWIFTNESS_1);
  /*Talent*/lvl >= 50 && isRest ? InitSpellMap(EARTH_SHIELD_1) : RemoveSpell(EARTH_SHIELD_1);
  /*Talent*/lvl >= 60 && isRest ? InitSpellMap(RIPTIDE_1) : RemoveSpell(RIPTIDE_1);

  /*Talent*/lvl >= 50 && isElem ? InitSpellMap(TOTEM_OF_WRATH_1) : RemoveSpell(TOTEM_OF_WRATH_1);

  /*Talent*/lvl >= 40 && isRest ? InitSpellMap(MANA_TIDE_TOTEM_1) : RemoveSpell(MANA_TIDE_TOTEM_1);

            CURE_TOXINS = InitSpell(me, CLEANSE_SPIRIT_1) ? CLEANSE_SPIRIT_1 : CURE_TOXINS_1;
            RemoveSpell(CLEANSE_SPIRIT_1);
            RemoveSpell(CURE_TOXINS_1);
            InitSpellMap(CURE_TOXINS);

            //InitSpellMap(ROCKBITER_WEAPON_1); //lvl 1
            InitSpellMap(FLAMETONGUE_WEAPON_1); //lvl 10
            InitSpellMap(FROSTBRAND_WEAPON_1); //lvl 20
            InitSpellMap(WINDFURY_WEAPON_1); //lvl 30
            InitSpellMap(EARTHLIVING_WEAPON_1); //lvl 30
        }

        void ApplyClassPassives() const override
        {
            uint8 level = master->GetLevel();
            bool isElem = GetSpec() == BOT_SPEC_SHAMAN_ELEMENTAL;
            bool isEnha = GetSpec() == BOT_SPEC_SHAMAN_ENHANCEMENT;
            bool isRest = GetSpec() == BOT_SPEC_SHAMAN_RESTORATION;

            RefreshAura(ELEMENTAL_DEVASTATION3, isEnha && level >= 18 ? 1 : 0);
            RefreshAura(ELEMENTAL_DEVASTATION2, isEnha && level >= 15 && level < 18 ? 1 : 0);
            RefreshAura(ELEMENTAL_DEVASTATION1, isEnha && level >= 12 && level < 15 ? 1 : 0);
            RefreshAura(ELEMENTAL_FOCUS, isElem && level >= 20 ? 1 : 0);
            RefreshAura(ELEMENTAL_OATH, !IAmFree() && isElem && level >= 40 ? 1 : 0);
            //RefreshAura(STORM_EARTH_AND_FIRE, isElem && level >= 45 ? 1 : 0);

            RefreshAura(TOUGHNESS, level >= 25 ? 1 : 0);
            RefreshAura(FLURRY5, isEnha && level >= 29 ? 1 : 0);
            RefreshAura(FLURRY4, isEnha && level >= 28 && level < 29 ? 1 : 0);
            RefreshAura(FLURRY3, isEnha && level >= 27 && level < 28 ? 1 : 0);
            RefreshAura(FLURRY2, isEnha && level >= 26 && level < 27 ? 1 : 0);
            RefreshAura(FLURRY1, isEnha && level >= 25 && level < 26 ? 1 : 0);
            RefreshAura(WEAPON_MASTERY, isEnha && level >= 30 ? 1 : 0);
            RefreshAura(UNLEASHED_RAGE, !IAmFree() && isEnha && level >= 35 ? 1 : 0);
            RefreshAura(IMPROVED_STORMSTRIKE, isEnha && level >= 40 ? 1 : 0);
            RefreshAura(STATIC_SHOCK, isEnha && level >= 41 ? 1 : 0);
            RefreshAura(EARTHEN_POWER, isEnha && level >= 50 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON5, isEnha && level >= 59 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON4, isEnha && level >= 58 && level < 59 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON3, isEnha && level >= 57 && level < 58 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON2, isEnha && level >= 56 && level < 57 ? 1 : 0);
            RefreshAura(MAELSTROM_WEAPON1, isEnha && level >= 55 && level < 56 ? 1 : 0);

            RefreshAura(IMPROVED_WATER_SHIELD, isRest && level >= 20 ? 1 : 0);
            RefreshAura(ANCESTRAL_HEALING, isRest && level >= 20 ? 1 : 0);
            RefreshAura(ANCESTRAL_AWAKENING, isRest && level >= 50 ? 1 : 0);
            RefreshAura(TIDAL_WAVES, isRest && level >= 55 ? 1 : 0);

            RefreshAura(SHAMAN_FLAME_SHOCK_PASSIVE);

            RefreshAura(SHAMAN_T10_RESTO_4P, level >= 70 ? 1 : 0);

            RefreshAura(GLYPH_THUNDERSTORM, GetSpell(THUNDERSTORM_1) ? 1 : 0);
            RefreshAura(GLYPH_TOTEM_OF_WRATH, GetSpell(TOTEM_OF_WRATH_1) ? 1 : 0);
        }

        bool CanUseManually(uint32 basespell) const override
        {
            switch (basespell)
            {
                case HEALING_WAVE_1:
                case CHAIN_HEAL_1:
                case LESSER_HEALING_WAVE_1:
                case RIPTIDE_1:
                case CLEANSE_SPIRIT_1:
                case WATER_WALKING_1:
                case WATER_BREATHING_1:
                case BLOODLUST_1:
                case HEROISM_1:
                case SHAMANISTIC_RAGE_1:
                //case ELEMENTAL_MASTERY_1:
                case TIDAL_FORCE_1:
                //Totems
                //case EARTHBIND_TOTEM_1:
                //case MAGMA_TOTEM_1:
                //case SEARING_TOTEM_1:
                //case STONECLAW_TOTEM_1:
                //case FIRE_ELEMENTAL_TOTEM_1:
                //case EARTH_ELEMENTAL_TOTEM_1:
                //case FIRE_RESISTANCE_TOTEM_1:
                //case FROST_RESISTANCE_TOTEM_1:
                //case NATURE_RESISTANCE_TOTEM_1:
                //case FLAMETONGUE_TOTEM_1:
                case GROUNDING_TOTEM_1:
                //case SENTRY_TOTEM_1:
                //case STONESKIN_TOTEM_1:
                //case STRENGTH_OF_EARTH_TOTEM_1:
                //case WINDFURY_TOTEM_1:
                //case WRATH_OF_AIR_TOTEM_1:
                case CLEANSING_TOTEM_1:
                //case HEALING_STREAM_TOTEM_1:
                //case MANA_SPRING_TOTEM_1:
                //case TOTEM_OF_WRATH_1:
                case MANA_TIDE_TOTEM_1:
                case TREMOR_TOTEM_1:
                case TOTEMIC_RECALL_1:
                    return true;
                case CURE_TOXINS_1:
                    return !GetSpell(CLEANSE_SPIRIT_1);
                case FIRE_NOVA_1:
                    return _totems[T_FIRE].second._type != BOT_TOTEM_NONE;
                default:
                    return false;
            }
        }

        bool HasAbilitiesSpecifics() const override { return true; }
        void FillAbilitiesSpecifics(Player const* player, std::list<std::string> &specList) override
        {
            uint32 textId1, textId2;
            switch (mhEnchant)
            {
                //case ROCKBITER_WEAPON_1:   textId1 = BOT_TEXT_"Rockbiter";  break;
                case FLAMETONGUE_WEAPON_1: textId1 = BOT_TEXT_FLAMETONGUE;  break;
                case FROSTBRAND_WEAPON_1:  textId1 = BOT_TEXT_FROSTBRAND;   break;
                case WINDFURY_WEAPON_1:    textId1 = BOT_TEXT_WINDFURY;     break;
                case EARTHLIVING_WEAPON_1: textId1 = BOT_TEXT_EARTHLIVING;  break;
                default:                   textId1 = BOT_TEXT_NOTHING_C;    break;
            }
            switch (ohEnchant)
            {
                //case ROCKBITER_WEAPON_1:   textId2 = BOT_TEXT_"Rockbiter";  break;
                case FLAMETONGUE_WEAPON_1: textId2 = BOT_TEXT_FLAMETONGUE;  break;
                case FROSTBRAND_WEAPON_1:  textId2 = BOT_TEXT_FROSTBRAND;   break;
                case WINDFURY_WEAPON_1:    textId2 = BOT_TEXT_WINDFURY;     break;
                case EARTHLIVING_WEAPON_1: textId2 = BOT_TEXT_EARTHLIVING;  break;
                default:                   textId2 = BOT_TEXT_NOTHING_C;    break;
            }
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_SLOT_MH) + ": " + LocalizedNpcText(player, textId1));
            specList.push_back(LocalizedNpcText(player, BOT_TEXT_SLOT_OH) + ": " + LocalizedNpcText(player, textId2));
        }

        std::vector<uint32> const* GetDamagingSpellsList() const override
        {
            return &Shaman_spells_damage;
        }
        std::vector<uint32> const* GetCCSpellsList() const override
        {
            return &Shaman_spells_cc;
        }
        std::vector<uint32> const* GetHealingSpellsList() const override
        {
            return &Shaman_spells_heal;
        }
        std::vector<uint32> const* GetSupportSpellsList() const override
        {
            return &Shaman_spells_support;
        }

        void InitHeals() override
        {
            SpellInfo const* spellInfo;
            if (InitSpell(me, HEALING_WAVE_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, HEALING_WAVE_1));
                _heals[HEALING_WAVE_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[HEALING_WAVE_1] = 0;

            if (InitSpell(me, LESSER_HEALING_WAVE_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, LESSER_HEALING_WAVE_1));
                _heals[LESSER_HEALING_WAVE_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[LESSER_HEALING_WAVE_1] = 0;

            if (InitSpell(me, RIPTIDE_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, RIPTIDE_1));
                _heals[RIPTIDE_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[RIPTIDE_1] = 0;

            if (InitSpell(me, CHAIN_HEAL_1))
            {
                spellInfo = sSpellMgr->GetSpellInfo(InitSpell(me, CHAIN_HEAL_1));
                _heals[CHAIN_HEAL_1] = me->SpellHealingBonusDone(me, spellInfo, spellInfo->_effects[0].CalcValue(me), HEAL, spellInfo->GetEffect(EFFECT_0), {});
            }
            else
                _heals[CHAIN_HEAL_1] = 0;
        }

    private:
        //Totem system
        struct BotTotemParam
        {
            BotTotemParam() : _effradius(0.f) {}
            uint32 _type;
            Position _pos;
            float _effradius;
        };

        typedef std::pair<ObjectGuid /*guid*/, BotTotemParam /*param*/> BotTotem;
        BotTotem _totems[MAX_TOTEMS];
        uint32 TotemTimer[MAX_TOTEMS];
        //Wolves
        ObjectGuid _wolves[MAX_WOLVES];
        //Spells
        uint32 CURE_TOXINS;
        //Timers
        uint32 TotemsCheckTimer;
        uint32 HexyCheckTimer, EarthyCheckTimer, ShieldCheckTimer, BloodlustCheckTimer, MaelstromTimer;
        uint8 MaelstromCount;
        bool Hexy, Earthy;
        mutable bool maelUseUp;
        uint32 mhEnchantExpireTimer, ohEnchantExpireTimer;
        uint32 mhEnchant, ohEnchant;
        bool needChooseMHEnchant, needChooseOHEnchant;

        bool canTremor;

        typedef std::unordered_map<uint32 /*baseId*/, int32 /*amount*/> HealMap;
        HealMap _heals;

        uint32 _getTotemsMask(std::map<uint32 /*type*/, uint32 /*curId*/>& idMap) const
        {
            uint32 mask = 0;

            Unit* cre;
            uint32 sumonSpell;
            uint32 baseId;
            bool isTotem;
            int8 mytype = -1;
            Unit::AuraApplicationMap const& aurapps = me->GetAppliedAuras();
            for (Unit::AuraApplicationMap::const_iterator itr = aurapps.begin(); itr != aurapps.end(); ++itr)
            {
                //from totem aura extract base spell it could be summoned by
                if (itr->second->GetBase()->GetType() != UNIT_AURA_TYPE) continue;
                cre = itr->second->GetBase()->GetUnitOwner();
                //DEBUG
                //uint32 base = cre->GetUInt32Value(UNIT_CREATED_BY_SPELL);
                //if (base)
                //    baseId = sSpellMgr->GetSpellInfo(base)->GetFirstRankSpell()->Id;
                //if (target->GetEntry() == 70025 && cre->GetGUID() != me->GetGUID())
                //{
                //    TC_LOG_ERROR("spells","totemMask: unit {}, {} ({}), owner {} (crSp {}, base {}), istotem {}", target->GetName(),
                //        itr->second->GetBase()->GetSpellInfo()->SpellName[0], itr->second->GetBase()->GetId(),
                //        cre ? cre->GetName() : "unk", base, baseId, uint32(cre->IsTotem()));
                //}
                sumonSpell = cre ? cre->GetUInt32Value(UNIT_CREATED_BY_SPELL) : 0;
                if (!sumonSpell || !cre->IsTotem())
                    continue;

                isTotem = true;
                baseId = sSpellMgr->GetSpellInfo(sumonSpell)->GetFirstRankSpell()->Id;
                switch (baseId)
                {
                    case FIRE_RESISTANCE_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_RESISTANCE_FIRE;     mytype = T_WATER;   break;
                    case FROST_RESISTANCE_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_RESISTANCE_FROST;    mytype = T_FIRE;    break;
                    case NATURE_RESISTANCE_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_RESISTANCE_NATURE;   mytype = T_AIR;     break;
                    case FLAMETONGUE_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_FLAMETONGUE;         mytype = T_FIRE;    break;
                    case GROUNDING_TOTEM_1: //no ranking
                        mask |= BOT_TOTEM_MASK_GROUNDING;           mytype = T_AIR;     break;
                    //case STONESKIN_TOTEM_1:
                    //    mask |= BOT_TOTEM_MASK_STONESKIN;           mytype = T_EARTH;   break;
                    case STRENGTH_OF_EARTH_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_STRENGTH_OF_EARTH;   mytype = T_EARTH;   break;
                    case WINDFURY_TOTEM_1: //no ranking
                        mask |= BOT_TOTEM_MASK_WINDFURY;            mytype = T_AIR;     break;
                    case WRATH_OF_AIR_TOTEM_1: //no ranking
                        mask |= BOT_TOTEM_MASK_WRATH_OF_AIR;        mytype = T_AIR;     break;
                    case MANA_SPRING_TOTEM_1:
                        mask |= BOT_TOTEM_MASK_MANA_SPRING;         mytype = T_WATER;   break;
                    case TOTEM_OF_WRATH_1:
                        mask |= BOT_TOTEM_MASK_WRATH;               mytype = T_FIRE;    break;
                    default:
                        isTotem = false; //next aura
                        break;
                }

                if (isTotem)
                {
                    idMap[baseId] = sumonSpell;
                    for (uint8 i = 0; i != MAX_TOTEMS; ++i)
                    {
                        if (itr->second->GetBase()->GetCasterGUID() == me->m_SummonSlot[i+1])
                        {
                            //mask |= BOT_TOTEM_MASK_MY_TOTEM;
                            switch (mytype)
                            {
                                case T_FIRE:    mask |= BOT_TOTEM_MASK_MY_TOTEM_FIRE;   break;
                                case T_EARTH:   mask |= BOT_TOTEM_MASK_MY_TOTEM_EARTH;  break;
                                case T_WATER:   mask |= BOT_TOTEM_MASK_MY_TOTEM_WATER;  break;
                                case T_AIR:     mask |= BOT_TOTEM_MASK_MY_TOTEM_AIR;    break;
                                default:                                                break;
                            }
                            break;
                        }
                    }
                }
            }

            return mask;
        }
    };
};

void AddSC_shaman_bot()
{
    new shaman_bot();
}
