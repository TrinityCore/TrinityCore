#ifndef _BOT_AI_H
#define _BOT_AI_H

#include "ScriptedCreature.h"
#include "SpellMgr.h"
//#include "EventProcessor.h"
/*
NpcBot System by Graff (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

struct PlayerClassLevelInfo;

//class VisibilityUpdateEvent;
class TeleportHomeEvent;
//class EvadeEvent;
class TeleportFinishEvent;
//class MotionMaster;
//class Mail;

enum CommonValues
{
//MISC
    BOT_ENTRY_BEGIN                     = 70001,
    BOT_ENTRY_END                       = 71000,
    BOT_ICON_ON                         = 9,    //GOSSIP_ICON_BATTLE,
    BOT_ICON_OFF                        = 7,    //GOSSIP_ICON_TALK,
    BOT_MAX_CHASE_RANGE                 = 120,  //yds
    BOT_EVADE_TIME                      = 3000, //ms
//COMMON SPELLS
    MANAPOTION                          = 32453,//"Uses a Holy elixir to heal the caster for 32000"
    HEALINGPOTION                       = 15504,//"Drinks Holy Elixir to heal the caster"
    DRINK                               = 66041,//"Restores 4% mana per sec for 30 sec"
    EAT                                 = 66478,//"Restores Health"
    PVPTRINKET                          = 42292,//PvP Trinket no CD
    BERSERK                             = 46587,//68378,//900%/150%
//COMMON CDs
    POTION_CD                           = 60000,//default 60sec potion cd
    RATIONS_CD                          = 1000, //update rations every X milliseconds
//COMMON PASSIVES
  //1) DEPRECATED"Increase(d) @whatever"
    //SPELL_BONUS_10                      = 33021,//10spp
    //SPELL_BONUS_50                      = 45011,//50spp
    //SPELL_BONUS_150                     = 28141,//150spp
    //SPELL_BONUS_250                     = 69709,//250spp
    //FIREDAM_86                          = 33816,//86 fire spp
    //MANAREGEN45                         = 35867,//45 mp5
    //MANAREGEN100                        = 45216,//100 mp5
    //SPELL_PEN_5                         = 31921,//5 sppen
    //SPELL_PEN_20                        = 26283,//20 sppen
  //2) DEPRECATEDTalents
    //HASTE    /*Gift of the EarthMother*/= 51183,//rank 5 10% spell haste
    //HASTE2   /*Blood Frenzy - warrior*/ = 29859,//rank 2 10% melee haste, bonus for rend (warriors only)
    //HASTE3   /*       "Haste"       */  = 29418,//rank 0 10% increased ranged attack speed
    //CRITS    /*Thundering Strikes-sham*/= 16305,//rank 5 5% crit melee/spell
    //HOLYCRIT /*Holy Spec - priest*/     = 15011,//rank 5 5% holy crit
    //DODGE    /*Anticipation - paladin*/ = 20100,//rank 5 5% dodge
    //PARRY    /*Deflection - warrior*/   = 16466,//rank 5 5% parry
    //BLOCK/*zzOLD Shield Specialization*/= 16253,//rank 1 5% block 10% amount, 3.3.5 & 4.3.4 deprecated
    //PRECISION /*Precision - rogue*/     = 13843,//rank 3 3% melee/spell hit
    //PRECISION /*Precision - warrior*/   = 29592,//rank 3 3% melee hit
    //PRECISION2/*Precision - mage*/      = 29440,//rank 3 3% spell hit, -3% mana cost
    //DMG_TAKEN/*Deadened Nerves - rogue*/= 31383,//rank 3 6% reduced damage taken all
    //EXPERTISE /*Weapon Expertise-rogue*/= 30919,//rank 1 5 expertise
    //EXPERTISE2/*Weapon Expertise-rogue*/= 30920,//rank 2 10 expertise
  //3) Pet/Special
    THREAT   /****  (unused)  ****/     = 57339,//+43% threat generated
    //BOR      /*Blood of Rhino - pet*/   = 53482,//rank 2 +40% healing taken
    //BOAR     /*Boar's Speed - pet*/     = 19596,//rank 1 +30% movement speed
    RCP      /*Rogue Class Passive*/    = 21184,//-27% threat caused
    DEFENSIVE_STANCE_PASSIVE /*Warrior*/= 7376, //+45% threat -10% damage taken -5% damage done
//COMMON GOSSIPS
    GOSSIP_SERVE_MASTER                 = 70001, //"I live only to serve the master."
    GOSSIP_NEED_SMTH                    = 70002, //"You need something?"
    GOSSIP_MURDER                       = 70003,//"Mortals... usually I kill wretches like you at sight"
    GOSSIP_CLASS_BM                     = 70004,
    GOSSIP_SENDER_BEGIN                 = 6000,
    GOSSIP_SENDER_CLASS,
    //thesawolf - mage portals
    GOSSIP_SENDER_PORTAL,
    GOSSIP_SENDER_PORTCHOICE,
    //thesawolf - lock soulwell
    GOSSIP_SENDER_SOULWELL,
    //thesawolf - mage table
    GOSSIP_SENDER_TABLE,
    GOSSIP_SENDER_EQUIPMENT,
    GOSSIP_SENDER_EQUIPMENT_LIST,
    GOSSIP_SENDER_EQUIPMENT_SHOW,
    GOSSIP_SENDER_EQUIPMENT_INFO,
    GOSSIP_SENDER_UNEQUIP,
    GOSSIP_SENDER_UNEQUIP_ALL,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BEGIN           = GOSSIP_SENDER_EQUIP_AUTOEQUIP_EQUIP,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_MHAND           = GOSSIP_SENDER_EQUIP_AUTOEQUIP_BEGIN,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_OHAND,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_RANGED,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_HEAD,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_SHOULDERS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_CHEST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_WAIST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_LEGS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FEET,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_WRIST,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_HANDS,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BACK,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_BODY,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER1,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_FINGER2,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET1,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_TRINKET2,
    GOSSIP_SENDER_EQUIP_AUTOEQUIP_NECK,
    GOSSIP_SENDER_EQUIP_RESET,
    GOSSIP_SENDER_EQUIP,
    GOSSIP_SENDER_EQUIP_BEGIN           = GOSSIP_SENDER_EQUIP,
    GOSSIP_SENDER_EQUIP_MHAND           = GOSSIP_SENDER_EQUIP_BEGIN,
    GOSSIP_SENDER_EQUIP_OHAND,
    GOSSIP_SENDER_EQUIP_RANGED,
    GOSSIP_SENDER_EQUIP_HEAD,
    GOSSIP_SENDER_EQUIP_SHOULDERS,
    GOSSIP_SENDER_EQUIP_CHEST,
    GOSSIP_SENDER_EQUIP_WAIST,
    GOSSIP_SENDER_EQUIP_LEGS,
    GOSSIP_SENDER_EQUIP_FEET,
    GOSSIP_SENDER_EQUIP_WRIST,
    GOSSIP_SENDER_EQUIP_HANDS,
    GOSSIP_SENDER_EQUIP_BACK,
    GOSSIP_SENDER_EQUIP_BODY,
    GOSSIP_SENDER_EQUIP_FINGER1,
    GOSSIP_SENDER_EQUIP_FINGER2,
    GOSSIP_SENDER_EQUIP_TRINKET1,
    GOSSIP_SENDER_EQUIP_TRINKET2,
    GOSSIP_SENDER_EQUIP_NECK,
    GOSSIP_SENDER_ROLES,
    GOSSIP_SENDER_ROLES_TOGGLE,
    GOSSIP_SENDER_ABILITIES,
    GOSSIP_SENDER_ABILITIES_USE,
    GOSSIP_SENDER_HIRE,
    GOSSIP_SENDER_DISMISS,
    // thesawolf - changed dismiss->delete to separate fire option
    GOSSIP_SENDER_FIRE,
    GOSSIP_SENDER_JOIN_GROUP,
    GOSSIP_SENDER_LEAVE_GROUP,
    GOSSIP_SENDER_FORMATION,
    GOSSIP_SENDER_FORMATION_DISTANCE,
    GOSSIP_SENDER_SCAN,
    GOSSIP_SENDER_SCAN_OWNER,
    GOSSIP_SENDER_SCAN_OWNER_ABILITY,
    GOSSIP_SENDER_DEBUG,
    GOSSIP_SENDER_DEBUG_ACTION,
    //thesawolf - add in faction set gossip
    GOSSIP_SENDER_EARLYDISMISS,
    GOSSIP_SENDER_FACTION,
    GOSSIP_SENDER_FACTION_ALLIANCE,
    GOSSIP_SENDER_FACTION_HORDE,
    GOSSIP_SENDER_FACTION_MONSTER,
    GOSSIP_SENDER_FACTION_FRIEND,
    //thesawolf - relase (reset owner)
    GOSSIP_SENDER_RELEASE,
//COMMON NPCS
    NPC_WORLD_TRIGGER                   = 22515,
//COMMON GAMEEVENTS
    GAME_EVENT_WINTER_VEIL              = 2,
//COMMON MOUNTS SPELLS
    REINDEER                            = 25859,
    REINDEER_FLY                        = 44827,
//ADVANCED
    COSMETIC_TELEPORT_EFFECT            = 52096,//visual instant cast omni
    //COSMETIC_SMOKING_CORPSE_AURA        = 51201,//black model + fire step (permanent)


////CUSTOM SPELLS
//ARCHMAGE
  //modify
/**/BLIZZARD_VISUAL_PERSISTENT_AURA     = 34167,
    BLIZZARD_VISUAL_PROC                = 29969,

//BLADEMASTER
/**/ //- used explicitly within the script
  //SPELLS
  //unmodify
    SPELL_DEATH_GRIP_JUMP               = 49575,
/**/SPELL_CRITICAL_STRIKE               = 1132,
    SPELL_BURNING_BLADE_BLADEMASTER     = 32281,//horde flag visual
    SPELL_POSESS                        = 17250,//immunity,invis,stun
    //SPELL_SELFSTUN                      = 24883,//green smoke, transparency, stun
    SPELL_STUN_FREEZE_ANIM              = 59123,//stun forever, full stop
  //modify
    SPELL_TRANSPARENCY_50               = 44816,
/**/SPELL_NETHERWALK                    = 31599,
/**/SPELL_MIRROR_IMAGE_BM               = 69936,//blank spell
  //SOUNDS
    SOUND_FREEZE_IMPACT_WINDWALK        = 29,
    SOUND_AXE_2H_IMPACT_FLESH_CRIT      = 158,
    SOUND_ABSORB_GET_HIT                = 3334,
    SOUND_MISS_WHOOSH_2H                = 7081,

//OTHER
  //unmodify
    SPELL_VERTEX_COLOR_BLACK            = 39662,//black color model full
    //SPELL_NIGHTMARE_VULNERABILITY       = 54199,//100% dmg taken, 100% crit chance taken (x4 dmg taken)
  //modify
    SPELL_COMBAT_SPECIAL_2H_ATTACK      = 44079
};

enum BotClasses
{
    BOT_CLASS_NONE                      = CLASS_NONE,
    BOT_CLASS_WARRIOR                   = CLASS_WARRIOR,
    BOT_CLASS_PALADIN                   = CLASS_PALADIN,
    BOT_CLASS_HUNTER                    = CLASS_HUNTER,
    BOT_CLASS_ROGUE                     = CLASS_ROGUE,
    BOT_CLASS_PRIEST                    = CLASS_PRIEST,
    BOT_CLASS_DEATH_KNIGHT              = CLASS_DEATH_KNIGHT,
    BOT_CLASS_SHAMAN                    = CLASS_SHAMAN,
    BOT_CLASS_MAGE                      = CLASS_MAGE,
    BOT_CLASS_WARLOCK                   = CLASS_WARLOCK,
    BOT_CLASS_DRUID                     = CLASS_DRUID,

    BOT_CLASS_BM,

    BOT_CLASS_END,

    BOT_CLASS_NORMAL_START              = BOT_CLASS_WARRIOR,
    BOT_CLASS_NORMAL_END                = BOT_CLASS_BM,
    BOT_CLASS_EX_START                  = BOT_CLASS_BM,
    BOT_CLASS_EX_END
};

enum BotStances
{
    BOT_STANCE_NONE                     = 0,
    WARRIOR_BATTLE_STANCE               = BOT_CLASS_EX_END,
    WARRIOR_DEFENSIVE_STANCE,
    WARRIOR_BERSERKER_STANCE,
    DEATH_KNIGHT_BLOOD_PRESENCE,
    DEATH_KNIGHT_FROST_PRESENCE,
    DEATH_KNIGHT_UNHOLY_PRESENCE,
    DRUID_BEAR_FORM,
    DRUID_CAT_FORM,
    //DRUID_TRAVEL_FORM,                //NYI
    //DRUID_FLY_FORM,                   //NYI
    DRUID_MOONKIN_FORM                  //NYI
};

enum BotRoles
{
    BOT_ROLE_NONE                       = 0x00,
    BOT_ROLE_TANK                       = 0x01,
    BOT_ROLE_DPS                        = 0x02,
    BOT_ROLE_HEAL                       = 0x04,
    BOT_ROLE_RANGED                     = 0x08,

    BOT_ROLE_PARTY                      = 0x10, //hidden

    //BOT_ROLE_TANK_MELEE                 = (BOT_ROLE_TANK | BOT_ROLE_DPS),
    //BOT_ROLE_TANK_RANGED                = (BOT_ROLE_TANK | BOT_ROLE_DPS | BOT_ROLE_RANGED),

    BOT_MAX_ROLE                        = 0x20
};

enum BotPetTypes
{
    PET_TYPE_NONE,
//Warlock
    PET_TYPE_IMP,
    PET_TYPE_VOIDWALKER,
    PET_TYPE_SUCCUBUS,
    PET_TYPE_FELHUNTER,
    PET_TYPE_FELGUARD,
//Mage
    PET_TYPE_WATER_ELEMENTAL,
//Shaman
    //PET_TYPE_GHOSTLY_WOLF,
    PET_TYPE_FIRE_ELEMENTAL,
    PET_TYPE_EARTH_ELEMENTAL,
//Hunter
    PET_TYPE_VULTURE,

    MAX_PET_TYPES
};

enum WarlockBotPets
{
    PET_IMP                     = 70249,
    PET_VOIDWALKER              = 70247
    //PET_SUCCUBUS                =
};

enum HunterBotPets
{
    PET_VULTURE                 = 70248
};

enum BotPetsOriginalEntries
{
    ORIGINAL_ENTRY_VOIDWALKER   = 1860,
    ORIGINAL_ENTRY_IMP          = 416
};

enum BotEquipSlot
{
    BOT_SLOT_NONE               = 0,
    BOT_SLOT_MAINHAND           = 1,
    BOT_SLOT_OFFHAND            = 2,
    BOT_SLOT_RANGED             = 3,
    BOT_SLOT_HEAD               = 4,
    BOT_SLOT_SHOULDERS          = 5,
    BOT_SLOT_CHEST              = 6,
    BOT_SLOT_WAIST              = 7,
    BOT_SLOT_LEGS               = 8,
    BOT_SLOT_FEET               = 9,
    BOT_SLOT_WRIST              = 10,
    BOT_SLOT_HANDS              = 11,
    BOT_SLOT_BACK               = 12,
    BOT_SLOT_BODY               = 13,
    BOT_SLOT_FINGER1            = 14,
    BOT_SLOT_FINGER2            = 15,
    BOT_SLOT_TRINKET1           = 16,
    BOT_SLOT_TRINKET2           = 17,
    BOT_SLOT_NECK               = 18,
    BOT_MAX_SLOTS,
    BOT_INVENTORY_SIZE = BOT_MAX_SLOTS - 1
};

enum BotItemStat
{
    //ItemProtoType.h
    BOT_ITEM_MOD_MANA                       = 0,
    BOT_ITEM_MOD_HEALTH                     = 1,
    BOT_ITEM_MOD_AGILITY                    = 3,
    BOT_ITEM_MOD_STRENGTH                   = 4,
    BOT_ITEM_MOD_INTELLECT                  = 5,
    BOT_ITEM_MOD_SPIRIT                     = 6,
    BOT_ITEM_MOD_STAMINA                    = 7,
    BOT_ITEM_MOD_DEFENSE_SKILL_RATING       = 12,
    BOT_ITEM_MOD_DODGE_RATING               = 13,
    BOT_ITEM_MOD_PARRY_RATING               = 14,
    BOT_ITEM_MOD_BLOCK_RATING               = 15,
    BOT_ITEM_MOD_HIT_MELEE_RATING           = 16,
    BOT_ITEM_MOD_HIT_RANGED_RATING          = 17,
    BOT_ITEM_MOD_HIT_SPELL_RATING           = 18,
    BOT_ITEM_MOD_CRIT_MELEE_RATING          = 19,
    BOT_ITEM_MOD_CRIT_RANGED_RATING         = 20,
    BOT_ITEM_MOD_CRIT_SPELL_RATING          = 21,
    BOT_ITEM_MOD_HIT_TAKEN_MELEE_RATING     = 22,
    BOT_ITEM_MOD_HIT_TAKEN_RANGED_RATING    = 23,
    BOT_ITEM_MOD_HIT_TAKEN_SPELL_RATING     = 24,
    BOT_ITEM_MOD_CRIT_TAKEN_MELEE_RATING    = 25,
    BOT_ITEM_MOD_CRIT_TAKEN_RANGED_RATING   = 26,
    BOT_ITEM_MOD_CRIT_TAKEN_SPELL_RATING    = 27,
    BOT_ITEM_MOD_HASTE_MELEE_RATING         = 28,
    BOT_ITEM_MOD_HASTE_RANGED_RATING        = 29,
    BOT_ITEM_MOD_HASTE_SPELL_RATING         = 30,
    BOT_ITEM_MOD_HIT_RATING                 = 31,
    BOT_ITEM_MOD_CRIT_RATING                = 32,
    BOT_ITEM_MOD_HIT_TAKEN_RATING           = 33,
    BOT_ITEM_MOD_CRIT_TAKEN_RATING          = 34,
    BOT_ITEM_MOD_RESILIENCE_RATING          = 35,
    BOT_ITEM_MOD_HASTE_RATING               = 36,
    BOT_ITEM_MOD_EXPERTISE_RATING           = 37,
    BOT_ITEM_MOD_ATTACK_POWER               = 38,
    BOT_ITEM_MOD_RANGED_ATTACK_POWER        = 39,
    BOT_ITEM_MOD_FERAL_ATTACK_POWER         = 40,
    BOT_ITEM_MOD_SPELL_HEALING_DONE         = 41,                 // deprecated
    BOT_ITEM_MOD_SPELL_DAMAGE_DONE          = 42,                 // deprecated
    BOT_ITEM_MOD_MANA_REGENERATION          = 43,
    BOT_ITEM_MOD_ARMOR_PENETRATION_RATING   = 44,
    BOT_ITEM_MOD_SPELL_POWER                = 45,
    BOT_ITEM_MOD_HEALTH_REGEN               = 46,
    BOT_ITEM_MOD_SPELL_PENETRATION          = 47,
    BOT_ITEM_MOD_BLOCK_VALUE                = 48,
    //END ItemProtoType.h

    BOT_ITEM_MOD_DAMAGE                     = MAX_ITEM_MOD,
    BOT_ITEM_MOD_ARMOR,
    BOT_ITEM_MOD_RESIST_HOLY,
    BOT_ITEM_MOD_RESIST_FIRE,
    BOT_ITEM_MOD_RESIST_NATURE,
    BOT_ITEM_MOD_RESIST_FROST,
    BOT_ITEM_MOD_RESIST_SHADOW,
    BOT_ITEM_MOD_RESIST_ARCANE,
    BOT_ITEM_MOD_EX,
    MAX_BOT_ITEM_MOD,

    BOT_ITEM_MOD_RESISTANCE_START = BOT_ITEM_MOD_ARMOR
};

enum BotAIResetType
{
    BOTAI_RESET_INIT                    = 0x01,
    BOTAI_RESET_DISMISS                 = 0x02,
    BOTAI_RESET_LOST                    = 0x04,
    BOTAI_RESET_LOGOUT                  = 0x08, //NYI

    BOTAI_RESET_ABANDON_MASTER          = (BOTAI_RESET_INIT | BOTAI_RESET_DISMISS)
};

class bot_ai : public ScriptedAI
{
    friend class BotMgr;
    friend class script_bot_commands;
    private:
        void SetBotOwnerGUID(uint32 guidlow) { _ownerGuid = guidlow; }
    public:
        virtual ~bot_ai();
        bot_ai(Creature* creature);
        //void OnCharmed(bool /*apply*/) { }
        EventProcessor* GetEvents() { return &events; }
        uint32 GetBotOwnerGuid() const { return _ownerGuid; }
        Player* GetBotOwner() const { return master; }
        bool SetBotOwner(Player* newowner);
        uint8 GetBotClass() const { return _botclass; }
        uint32 GetLastDiff() const { return lastdiff; }
        virtual void Reset() {}
		virtual void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) {}
        virtual void JustDied(Unit*) {}
        virtual void EnterCombat(Unit*) {}
        virtual void MoveInLineOfSight(Unit*) {}
        virtual void ReturnHome() {}
        virtual void CommonTimers(uint32 /*diff*/) = 0;
        void ResetBotAI(uint8 resetType = BOTAI_RESET_INIT);
        void KillEvents(bool force);
        void FindMaster(bool force = false);
        virtual bool IsMinionAI() const = 0;
        virtual bool IsPetAI() const = 0;
        virtual bool CanRespawn() = 0;
        virtual void SetBotCommandState(CommandStates /*st*/, bool /*force*/ = false, Position* /*newpos*/ = NULL) = 0;
        virtual const bot_minion_ai* GetMinionAI() const { return NULL; }
        virtual const bot_pet_ai* GetPetAI() const { return NULL; }
        bot_minion_ai const* ToMinionAI() const { return IsMinionAI() ? GetMinionAI() : NULL; }
        bot_minion_ai* ToMinionAI() { return IsMinionAI() ? const_cast<bot_minion_ai*>(GetMinionAI()) : NULL; }
        bot_pet_ai const* ToPetAI() const { return IsPetAI() ? GetPetAI() : NULL; }
        bot_pet_ai* ToPetAI() { return IsPetAI() ? const_cast<bot_pet_ai*>(GetPetAI()) : NULL; }
        bool IsInBotParty(Unit const* unit) const;
        bool CanBotAttack(Unit const* target, int8 byspell = 0) const;
        bool InDuel(Unit const* target) const;
        CommandStates GetBotCommandState() const { return m_botCommandState; }
        void ApplyBotDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const;
        void ApplyBotDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const;
        void ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool& crit) const;
        void ApplyBotDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const;
        void ApplyBotCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType) const;
        void ApplyBotSpellCostMods(SpellInfo const* spellInfo, int32& cost) const;
        void ApplyBotSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const;
        void ApplyBotSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const;
        void ApplyBotSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const;
        void ApplyBotSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const;
        //inline void SendPartyEvadeAbort() const;
        inline void SetNeedParty(bool need) { needparty = need; }
        inline void SetShouldUpdateStats() { shouldUpdateStats = true; }
        inline void UpdateHealth() { doHealth = true; }
        inline void UpdateMana() { doMana = true; }
        inline uint32 GetManaRegen() const { return regen_mp; }
        inline float GetHitRating() const { return hit; }
        inline int32 GetHaste() const { return haste; }
        inline float GetShieldBlockValue() const { return blockvalue; }
        virtual uint8 GetBotStance() const { return BOT_STANCE_NONE; }
        inline uint8 GetBotRoles() const { return _roleMask; }
        inline bool HasRole(uint8 role) const { return _roleMask & role; }
        void ToggleRole(uint8 role, bool force);
        char const* GetRoleString(uint8 role) const;

        virtual void OnBotSummon(Creature* /*summon*/) {}
        virtual void OnBotDespawn(Creature* /*summon*/) {}
        virtual void UnsummonAll() {}

        void ReceiveEmote(Player* player, uint32 emote);
        void ApplyPassives() const;

        virtual void RemoveItemBonuses(uint8 /*slot*/) {}
        virtual void ApplyItemBonuses(uint8 /*slot*/) {}

        static inline bool CCed(Unit* target, bool root = false)
        {
            return target ? target->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING | UNIT_STATE_DISTRACTED | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE) || (root && (target->HasUnitState(UNIT_STATE_ROOT) || target->isFrozen() || target->isInRoots())) : true;
        }

        //virtual bool CanUseOffHand() const { return false; }
        //virtual bool CanUseRanged() const { return false; }
        //virtual bool CanEquip(ItemTemplate const* /*item*/, uint8 /*slot*/) const { return false; }
        //virtual bool Unequip(uint8 /*slot*/) { return false; }
        //virtual bool Equip(uint8 /*slot*/, Item* /*item*/) { return false; }
        //virtual bool ResetEquipment(uint8 /*slot*/) { return false; }

        static void BotSpeak(std::string const& text, uint8 msgtype, uint32 language, ObjectGuid sender, ObjectGuid receiver);

        virtual void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType);
        virtual bool IAmFree() const { return false; }

        virtual void SetStats(bool, bool = false) = 0;
        void DefaultInit();

        void GetHomePosition(uint16& mapid, Position* pos);

        virtual bool UpdateImpossibleChase(Unit* /*target*/) { return false; }
        virtual bool IsDuringTeleport() const { return false; }
        virtual void AbortTeleport() {}
        virtual void ResetChase(Position* /*pos*/) {}

        virtual uint8 GetPlayerClass() const { ASSERT(_botclass < BOT_CLASS_EX_START); return _botclass; }

        virtual float GetBotParryChance() const { return CanParry() ? parry : 0.0f; }
        virtual bool CanParry() const = 0;
        virtual float GetBotDodgeChance() const { return CanDodge() ? dodge : 0.0f; }
        virtual bool CanDodge() const = 0;
        virtual float GetBotBlockChance() const { return CanBlock() ? block : 0.0f; }
        virtual bool CanBlock() const = 0;
        virtual float GetBotCritChance() const { return CanCrit() ? crit : 0.0f; }
        virtual bool CanCrit() const = 0;
        virtual float GetBotMissChance() const { return -hit; }
        virtual bool CanMiss() const = 0;
        virtual float GetBotEvasion() const { return 0.0f; }
        virtual float GetBotArmorPenetrationCoef() const { return 0.0f; }
        virtual float GetSpellMiscValue(uint32 /*basespell*/, uint8 /*offset*/ = 0) const { return 0.0f; }
        virtual float GetBotDamageTakenMod() const { return dmg_taken; }
        virtual uint32 GetBotExpertise() const { return expertise; }
        virtual uint32 GetBotSpellPenetration() const { return spellpen; }
        virtual uint32 GetBotSpellPower() const { return spellpower; }

        virtual bool IsBotImmuneToSpell(SpellInfo const* spellInfo) const;

        MeleeHitOutcome BotRollCustomMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const;

        virtual void CastBotItemCombatSpell(Unit* /*target*/, WeaponAttackType /*attType*/, uint32 /*procVictim*/, uint32 /*procEx*/, Spell const* /*spell = NULL*/) {}
        virtual void OnBotSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs);
        virtual void OnBotSpellGo(Spell const* spell);
        virtual void OnClassSpellGo(SpellInfo const* /*spellInfo*/) {}

        static void InitBotCustomSpells();
        static bool IsBotCustomSpell(uint32 spellId);

        bool IsTempBot() const { return _temp; }
        void SetBotIsTemp() { _temp = true; }

        void StartBoot() { _bootTimer = 60000; }
        void CancelBoot() { _bootTimer = -1; }

        bool IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD = true, uint32 forcedTime = 0) const;
        void SetSpellCooldown(uint32 basespell, uint32 msCooldown);
        void SetSpellCategoryCooldown(SpellInfo const* spellInfo, uint32 msCooldown);
        virtual void InitFaction() {}
    protected:
        static uint32 InitSpell(Unit const* caster, uint32 spell);
        void InitSpellMap(uint32 basespell, bool forceadd = false, bool forwardRank = true);
        uint32 GetSpell(uint32 basespell) const;
        uint32 GetSpellCooldown(uint32 basespell) const;
        void ResetSpellCooldown(uint32 basespell) { SetSpellCooldown(basespell, 0); }
        void RemoveSpell(uint32 basespell);
        void SpellTimers(uint32 diff);

        virtual void InitRoles() = 0;
        bool IsTank(Unit* unit = NULL) const;

        bool HasAuraName(Unit* unit, uint32 spellId, ObjectGuid casterGuid = ObjectGuid::Empty, bool exclude = false) const;
        bool RefreshAura(uint32 spellId, int8 count = 1) const;
        bool CheckAttackTarget(uint8 botOrPetType);
        bool MoveBehind(Unit &target) const;
        bool CheckImmunities(uint32 spell, Unit* target = NULL) const { return (spell && target && !target->ToCorpse() && target->IsHostileTo(me) ? !target->IsImmunedToDamage(sSpellMgr->GetSpellInfo(spell)) : true); }

        //everything cast-related
        bool doCast(Unit* victim, uint32 spellId, bool triggered = false, ObjectGuid originalCaster = ObjectGuid::Empty);
        SpellCastResult CheckBotCast(Unit* victim, uint32 spellId, uint8 botclass) const;
        virtual void removeFeralForm(bool /*force*/ = false, bool /*init*/ = true, uint32 /*diff*/ = 0) {}

        //inline bool JumpingFlyingOrFalling() const { return me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_SPLINE_ELEVATION|MOVEMENTFLAG_FALLING_SLOW); }
        inline bool JumpingFlyingOrFalling() const { return me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP | MOVEMENTFLAG_PITCH_DOWN | MOVEMENTFLAG_SPLINE_ELEVATION | MOVEMENTFLAG_FALLING_SLOW | MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR | MOVEMENTFLAG_DISABLE_GRAVITY); }
        inline bool Feasting() const { return (me->HasAura(EAT) || me->HasAura(DRINK)); }
        inline bool IsMeleeClass(uint8 m_class) const { return (m_class == CLASS_WARRIOR || m_class == CLASS_ROGUE || m_class == CLASS_PALADIN || m_class == CLASS_DEATH_KNIGHT || m_class == BOT_CLASS_BM); }
        inline bool IsTankingClass(uint8 m_class) const { return (m_class == CLASS_WARRIOR || m_class == CLASS_PALADIN || m_class == CLASS_DEATH_KNIGHT); }
        inline bool IsChanneling(Unit* u = NULL) const { if (!u) u = me; return u->GetCurrentSpell(CURRENT_CHANNELED_SPELL); }
        inline bool IsCasting(Unit* u = NULL) const { if (!u) u = me; return (u->HasUnitState(UNIT_STATE_CASTING) || IsChanneling(u) || u->IsNonMeleeSpellCast(false, false, true)); }

        void GetInPosition(bool force = false, Unit* newtarget = NULL, Position* pos = NULL);
        void OnSpellHit(Unit* caster, SpellInfo const* spell);
        void CalculateAttackPos(Unit* target, Position &pos) const;
        virtual void CheckAttackState();
        virtual void Evade(bool = false) {}
        virtual void OnStartAttack(Unit* /*u*/) {}

        //thesawolf melee fix test
        virtual void ApplyClassDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const {}
        virtual void ApplyClassDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool& /*crit*/) const {}
        virtual void ApplyClassDamageMultiplierSpell(int32& /*damage*/, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool& /*crit*/) const {}
        virtual void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& /*heal*/, SpellInfo const* /*spellInfo*/, DamageEffectType /*damagetype*/, uint32 /*stack*/) const {}
        virtual void ApplyClassCritMultiplierHeal(Unit const* /*victim*/, float& /*crit_chance*/, SpellInfo const* /*spellInfo*/, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const {}
        virtual void ApplyClassSpellCostMods(SpellInfo const* /*spellInfo*/, int32& /*cost*/) const {}
        virtual void ApplyClassSpellCastTimeMods(SpellInfo const* /*spellInfo*/, int32& /*casttime*/) const {}
        virtual void ApplyClassSpellCooldownMods(SpellInfo const* /*spellInfo*/, uint32& /*cooldown*/) const {}
        virtual void ApplyClassSpellCategoryCooldownMods(SpellInfo const* /*spellInfo*/, uint32& /*cooldown*/) const {}
        virtual void ApplyClassSpellGlobalCooldownMods(SpellInfo const* /*spellInfo*/, float& /*cooldown*/) const {}
        virtual void CureGroup(Player* /*pTarget*/, uint32 /*cureSpell*/, uint32 /*diff*/) {}
        virtual void CheckAuras(bool /*force*/ = false) {}
        virtual void BuffAndHealGroup(Player* /*gPlayer*/, uint32 /*diff*/) {}
        virtual void RezGroup(uint32 /*REZZ*/, Player* /*gPlayer*/) {}
        //virtual void DoNonCombatActions(uint32 /*diff*/) {}
        //virtual void StartAttack(Unit* /*u*/, bool /*force*/ = false) {}
        virtual void InitSpells() {}
        virtual void InitPowers() {}
        virtual void InitEquips() {}
        virtual void InitOwner() {}
        virtual void SavePosition() {}
        virtual void ApplyClassPassives() = 0;
        virtual void _OnHealthUpdate() const = 0;
        virtual void _OnManaUpdate(bool /*shapeshift*/ = false) = 0;
        //thesawolf melee fix test
        virtual void _OnMeleeDamageUpdate(uint8 /*myclass*/) const = 0;
        virtual void Regenerate() = 0;

        //virtual void ReceiveEmote(Player* /*player*/, uint32 /*emote*/) {}
        //virtual void CommonTimers(uint32 diff) = 0;

        virtual bool HealTarget(Unit* /*target*/, uint8 /*pct*/, uint32 /*diff*/) { return false; }
        virtual bool BuffTarget(Unit* /*target*/, uint32 /*diff*/) { return false; }
        virtual bool CureTarget(Unit* /*target*/, uint32 /*cureSpell*/, uint32 /*diff*/) { return false; }
        virtual bool IsMelee() const { return HasRole(BOT_ROLE_DPS) && !HasRole(BOT_ROLE_RANGED); }
        virtual bool CanHeal() const { return false; }
        virtual bool CanSheath() const { return true; }
        virtual bool CanSit() const { return true; }
        virtual bool CanDrink() const { return true; }
        virtual bool CanEat() const { return true; }
        virtual bool CanMount() const { return true; }
        virtual bool CanChangeEquip(uint8 /*slot*/) const { return true; }
        virtual bool IgnoreEquipsAttackTime() const { return false; }
        virtual bool CanSeeEveryone() const { return false; }

        uint8 GetWait(bool bypassGetCount = false);
        inline float InitAttackRange(float origRange, bool ranged) const;
        uint16 Rand() const;
        static inline uint32 GetLostHP(Unit const* unit) { return unit->GetMaxHealth() - unit->GetHealth(); }
        static inline uint8 GetHealthPCT(Unit const* hTarget) { if (!hTarget || hTarget->isDead()) return 100; return (hTarget->GetHealth()*100/hTarget->GetMaxHealth()); }
        static inline uint8 GetManaPCT(Unit const* hTarget) { if (!hTarget || hTarget->isDead() || hTarget->GetMaxPower(POWER_MANA) <= 1) return 100; return (hTarget->GetPower(POWER_MANA)*100/(hTarget->GetMaxPower(POWER_MANA))); }

        typedef std::set<Unit*> AttackerSet;

        virtual MeleeHitOutcome GetNextAttackMeleeOutCome() const { return MELEE_HIT_CRUSHING; }

        //event helpers
        void BotJumpInPlaceInFrontOf(Position* pos, float speedXY, float maxHeight);

        //utilities
        void _AddItemTemplateLink(Player* forPlayer, ItemTemplate const* item, std::ostringstream &str) const;
        void _AddItemLink(Player* forPlayer, Item const* item, std::ostringstream &str) const;
        void _AddQuestLink(Player* forPlayer, Quest const* quest, std::ostringstream &str) const;
        void _AddWeaponSkillLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillid) const;
        void _AddSpellLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, bool color = true, const std::string& colorstr = "ffffffff") const;
        void _AddProfessionLink(Player* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillId) const;
        void _LocalizeItem(Player* forPlayer, std::string &itemName, uint32 entry) const;
        void _LocalizeItem(Player* forPlayer, std::string &itemName, std::string &suffix, Item const* item) const;
        void _LocalizeQuest(Player* forPlayer, std::string &questTitle, uint32 entry) const;
        void _LocalizeCreature(Player* forPlayer, std::string &creatureName, uint32 entry) const;
        void _LocalizeGameObject(Player* forPlayer, std::string &gameobjectName, uint32 entry) const;

        void BuildGrouUpdatePacket(WorldPacket* data);

        void BotSay(char const* text, Player const* target = NULL) const;
        void BotWhisper(char const* text, Player* target = NULL) const;
        void BotYell(char const* text, Player const* target = NULL) const;
        // thesawolf - let's add audio cues
        bool PlaySound(uint32 emote);

        typedef std::pair<uint32 /*spellId*/, uint32 /*cooldown*/> BotSpell;
        typedef std::unordered_map<uint32 /*spellId_1*/, BotSpell /*spell*/> BotSpellMap;

        BotSpellMap const& GetSpellMap() const { return spells; }

        Player* master;
        Unit* opponent;
        CommandStates m_botCommandState;
        SpellInfo const* m_botSpellInfo;
        Position pos, attackpos;
        float atpower, maxdist, ap_mod, spp_mod, crit_mod;
        ObjectGuid aftercastTargetGuid;
        int32 cost, value, sppower;
        uint32 GC_Timer, temptimer, checkAurasTimer, checkMasterTimer, roleTimer, wait, regenTimer_hp, regenTimer_mp, regenTimer_nrg,
            currentSpell;
        uint8 clear_cd;
        bool doHealth, doMana, shouldUpdateStats;

        //stats
        float hit, parry, dodge, block, blockvalue, crit, dmg_taken;
        uint32 expertise, spellpower, spellpen, regen_hp, regen_mp;
        int32 haste;
        uint32 lastdiff;

        uint8 _botclass;
        uint8 _roleMask;
        uint32 _ownerGuid;
        bool needparty;
        bool spawned;
        bool firstspawn;
        bool _evadeMode;
        bool _atHome;

        bool _temp;

        int32 _bootTimer;
        uint32 _updateTimerMedium;

        EventProcessor events;

        //VisibilityUpdateEvent* visUpEvent;
        TeleportHomeEvent* teleHomeEvent;
        //EvadeEvent* evadeEvent;
        TeleportFinishEvent* teleFinishEvent;

    private:
        Unit* _getTarget(bool byspell, bool ranged, bool &reset) const;
        bool _hasAuraName(Unit* unit, const std::string spell, ObjectGuid casterGuid = ObjectGuid::Empty, bool exclude = false) const;
        void _listAuras(Player* player, Unit* unit) const;
        static inline float _getAttackDistance(float distance) { return distance > 0.0f ? distance*0.72f : 0.0f; }

        BotSpellMap spells;
};

class bot_minion_ai : public bot_ai
{
    public:
        virtual ~bot_minion_ai();
        bot_minion_ai(Creature* creature);
        virtual void Reset() {}
		virtual void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) { EnterEvadeMode(false); }
        void EnterEvadeMode(bool force);
        virtual void JustDied(Unit*);
        virtual void EnterCombat(Unit* u);
        virtual void MoveInLineOfSight(Unit* u);
        virtual void ReturnHome() { _atHome = false; }
        void CommonTimers(uint32 diff);
        const bot_minion_ai* GetMinionAI() const { return this; }
        bool IsMinionAI() const { return true; }
        bool IsPetAI() const { return false; }
        bool CanRespawn() { return IAmFree(); }
        void SummonBotsPet(uint32 entry);
        void SetBotCommandState(CommandStates st, bool force = false, Position* newpos = NULL);
        //virtual bool HealTarget(Unit* /*target*/, uint8 /*pct*/, uint32 /*diff*/) { return false; }
        //virtual bool BuffTarget(Unit* /*target*/, uint32 /*diff*/) { return false; }
        //virtual bool doCast(Unit*  /*victim*/, uint32 /*spellId*/, bool /*triggered*/ = false) { return false; }
        void CureGroup(Player* pTarget, uint32 cureSpell, uint32 diff);
        bool CureTarget(Unit* target, uint32 cureSpell, uint32 diff);
        void CheckAuras(bool force = false);
        //virtual void DoNonCombatActions(uint32 /*diff*/) {}
        //virtual void StartAttack(Unit* /*u*/, bool /*force*/ = false) {}
        void SetStats(bool force, bool shapeshift = false);

        static bool OnGossipHello(Player* player, Creature* creature, uint32 option);
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action);
        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code);

        void InitSpells() {}
        void InitPowers() {}
        void _OnHealthUpdate() const;
        void _OnManaUpdate(bool shapeshift = false);
        void _OnMeleeDamageUpdate(uint8 myclass) const;
        void Regenerate();

        void RemoveItemBonuses(uint8 slot);
        void ApplyItemBonuses(uint8 slot);
        void RemoveItemEnchantments(Item* item, uint8 slot);
        void RemoveItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 slot);
        void ApplyItemEnchantments(Item* item, uint8 slot);
        void ApplyItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 slot);
        void ApplyItemEquipSpell(Item* item, bool apply);
        void ApplyItemsSpells();

        void OnOwnerDamagedBy(Unit* attacker);

        //inline void SetEvadeTimer(uint8 time) { evade_cd = time; }

        bool CanHeal() const;

        uint32 GetReviveTimer() const { return _reviveTimer; }
        void SetReviveTimer(uint32 newtime) { _reviveTimer = newtime; }
        void UpdateReviveTimer(uint32 diff);

        bool IAmFree() const;
        void SavePosition();
        void TeleportHome();
        bool FinishTeleport(/*uint32 mapId, uint32 instanceId, float x, float y, float z, float o*/);

        bool IsDuringTeleport() const { return teleFinishEvent || teleHomeEvent; }
        void SetTeleportFinishEvent(TeleportFinishEvent* tfevent) { ASSERT(!teleFinishEvent); teleFinishEvent = tfevent; }
        void AbortTeleport();

        void ResetChase(Position* pos);
        void ResetChaseTimer(Position* pos);
        bool UpdateImpossibleChase(Unit* target);
        void BotJump(Position* pos);

        virtual bool CanParry() const { return me->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 0) != 0 && parry_mod > 0.0f && me->CanUseAttackType(BASE_ATTACK); }
        virtual bool CanDodge() const { return dodge_mod > 0.0f; }
        virtual bool CanBlock() const { return !(me->GetCreatureTemplate()->flags_extra & CREATURE_FLAG_EXTRA_NO_BLOCK) && me->CanUseAttackType(OFF_ATTACK); }
        virtual bool CanCrit() const { return crit_mod > 0.0f; }
        virtual bool CanMiss() const { return true; }

        void CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Spell const* spell = NULL);
        void CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Item* item, ItemTemplate const* proto, Spell const* spell = NULL);

        float GetTotalBotStat(uint8 stat) const { return _getTotalBotStat(stat); }
        void InitRoles();
        void InitEquips();
        void InitOwner();
        void InitFaction();
        Item const* GetEquips(uint8 slot) const { return _equips[slot]; }
    protected:
        bool GlobalUpdate(uint32 diff);

        

        virtual bool CanUseManually(uint32 /*basespell*/) const { return false; }
        void BuffAndHealGroup(Player* gPlayer, uint32 diff);
        void RezGroup(uint32 REZZ, Player* gPlayer);

        void Follow(bool force = false, Position* newpos = NULL)
        {
            if (force ||
                (me->IsAlive() && (!me->IsInCombat() || !opponent) && m_botCommandState != COMMAND_STAY))
                SetBotCommandState(COMMAND_FOLLOW, force, newpos);
        }

        //void CheckAttackState();
        void Evade(bool force = false);
        void OnStartAttack(Unit* u);

        virtual void BreakCC(uint32 diff);



        WorldObject* GetNearbyRezTarget(float dist = 30) const;
        Unit* FindHostileDispelTarget(float dist = 30, bool stealable = false) const;
        Unit* FindAffectedTarget(uint32 spellId, ObjectGuid caster = ObjectGuid::Empty, float dist = DEFAULT_VISIBILITY_DISTANCE, uint8 hostile = 0) const;
        Unit* FindPolyTarget(float dist = 30, Unit* currTarget = NULL) const;
        Unit* FindFearTarget(float dist = 30) const;
        Unit* FindStunTarget(float dist = 20) const;
        Unit* FindUndeadCCTarget(float dist = 30, uint32 spellId = 0) const;
        Unit* FindRootTarget(float dist = 30, uint32 spellId = 0) const;
        Unit* FindCastingTarget(float maxdist = 10, float mindist = 0, bool isFriend = false, uint32 spellId = 0) const;
        Unit* FindAOETarget(float dist = 30, bool checkbots = false, bool targetfriend = true) const;
        Unit* FindSplashTarget(float dist = 5, Unit* To = NULL, float splashdist = 4) const;
        Unit* FindTranquilTarget(float mindist = 5, float maxdist = 35) const;
        void GetNearbyTargetsList(std::list<Unit*> &targets, float maxdist = 10, float mindist = 0, bool forCC = false) const;
        void GetNearbyFriendlyTargetsList(std::list<Unit*>  &targets, float maxdist = 30) const;

        uint32 Potion_cd;

    private:
        bool _canCureTarget(Unit* target, uint32 cureSpell, uint32 diff) const;
        void _getBotDispellableAuraList(Unit* target, Unit* caster, uint32 dispelMask, std::list<std::pair<Aura*, uint8>>& dispelList) const;
        void _calculatePos(Position& pos);
        void _updateMountedState();
        void _updateStandState() const;
        void _updateRations();
        char const* _getNameForSlot(uint8 slot) const;
        uint8 _onOffIcon(uint8 role) const;
        void _updateEquips(uint8 slot, Item* item);

        bool _canUseOffHand() const;
        bool _canUseRanged() const;
        bool _canEquip(ItemTemplate const* item, uint8 slot, bool ignoreItemLevel = false) const;
        bool _unequip(uint8 slot);
        bool _equip(uint8 slot, Item* newItem);
        bool _resetEquipment(uint8 slot);

        typedef std::unordered_map<uint32 /*stat*/, int32 /*statvalue*/> BotStat;
        BotStat _stats[BOT_INVENTORY_SIZE];
        float _getBotStat(uint8 slot, uint8 stat) const;
        float _getTotalBotStat(uint8 stat) const;
        float _getRatingMultiplier(CombatRating cr) const;

        Item* _equips[BOT_INVENTORY_SIZE];
        PlayerClassLevelInfo* _classinfo;
        float myangle, armor_mod, haste_mod, dodge_mod, parry_mod;
        uint32 mana_cd, health_cd, pvpTrinket_cd;
        bool feast_health, feast_mana;
        uint8 rezz_cd;
        uint32 _reviveTimer, _saveTimer, _powersTimer, _chaseTimer;
        uint8 _jumpCount;
        uint8 _evadeCount;
        ObjectGuid _lastTargetGuid; //unused
};

class bot_pet_ai : public bot_ai
{
    public:
        virtual ~bot_pet_ai();
        bot_pet_ai(Creature* creature);
        virtual void Reset() {}
        const bot_pet_ai* GetPetAI() const { return this; }
        Creature* GetCreatureOwner() const { return m_creatureOwner; }
        bool IsMinionAI() const { return false; }
        bool IsPetAI() const { return true; }
        bool CanRespawn() { return false; }
        void CommonTimers(uint32 diff);
        inline bool IAmDead() const { return (!master || !m_creatureOwner || me->isDead()); }
        //void SetCreatureOwner(Creature* newowner) { m_creatureOwner = newowner; }
        void SetBotCommandState(CommandStates st, bool force = false, Position* newpos = NULL);
        //virtual bool HealTarget(Unit* /*target*/, uint8 /*pct*/, uint32 /*diff*/) { return false; }
        //virtual bool BuffTarget(Unit* /*target*/, uint32 /*diff*/) { return false; }
        //void BuffAndHealGroup(Player* /*gPlayer*/, uint32 /*diff*/) {}
        //void RezGroup(uint32 /*REZZ*/, Player* /*gPlayer*/) {}
        //virtual bool doCast(Unit*  /*victim*/, uint32 /*spellId*/, bool /*triggered*/ = false) { return false; }
        //void CureGroup(Player* /*pTarget*/, uint32 /*cureSpell*/, uint32 /*diff*/) {}
        //bool CureTarget(Unit* /*target*/, uint32 /*cureSpell*/, uint32 /*diff*/) { return false; }
        void CheckAuras(bool force = false);
        //virtual void DoNonCombatActions(uint32 /*diff*/) {}
        //virtual void StartAttack(Unit* /*u*/, bool /*force*/ = false) {}
        void SetStats(bool force, bool = false);

        static uint8 GetPetType(Creature* pet);
        static uint8 GetPetClass(Creature* pet);
        static uint32 GetPetOriginalEntry(uint32 entry);

        //debug
        //virtual void ListSpells(ChatHandler* /*handler*/) const {}

        void InitSpells() {}
        void _OnHealthUpdate() const;
        void _OnManaUpdate(bool shapeshift = false);
        // thesawolf melee fix test
        void _OnMeleeDamageUpdate(uint8 /*myclass*/) const {}
        void Regenerate();
        void SetBaseArmor(uint32 armor) { basearmor = armor; }

        virtual bool CanParry() const { return false; }
        virtual bool CanDodge() const { return true; }
        virtual bool CanBlock() const { return false; }
        virtual bool CanCrit() const { return true; }
        virtual bool CanMiss() const { return true; }

    protected:
        void InitRoles();

        Creature* m_creatureOwner;
    private:
        uint32 basearmor;
};

#endif
