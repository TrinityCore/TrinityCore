#ifndef _BOT_AI_H
#define _BOT_AI_H

#include "CreatureAI.h"
#include "botcommon.h"
/*
NpcBot System by Trickerer (onlysuffering@gmail.com)
Original patch from: LordPsyan https://bitbucket.org/lordpsyan/trinitycore-patches/src/3b8b9072280e/Individual/11185-BOTS-NPCBots.patch
*/

struct PlayerClassLevelInfo;

class TeleportHomeEvent;
class TeleportFinishEvent;

class bot_ai : public CreatureAI
{
    public:
        virtual ~bot_ai();

        bool canUpdate;

        void InitializeAI() override { Reset(); }
        void Reset() override { }

        void JustDied(Unit*) override;
        void KilledUnit(Unit* u) override;
        void JustEnteredCombat(Unit* u) override;
        void MoveInLineOfSight(Unit* u) override;
        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override;
        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override { }
        void ReceiveEmote(Player* player, uint32 emote) override;
        void EnterEvadeMode(EvadeReason why = EVADE_REASON_OTHER) override { }

        virtual void OnBotSummon(Creature* /*summon*/) {}
        virtual void OnBotDespawn(Creature* /*summon*/) {}
        virtual void UnsummonAll() {}

        virtual void OnBotDamageDealt(Unit* /*victim*/, uint32 /*damage*/, CleanDamage const* /*cleanDamage*/, DamageEffectType /*damagetype*/, SpellInfo const* /*spellInfo*/) {}
        virtual void OnBotDispelDealt(Unit* /*dispelled*/, uint8 /*num*/) {}

        bool GossipHello(Player* player) override;
        bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override;
        bool GossipSelectCode(Player* player, uint32 menuId, uint32 gossipListId, char const* code) override;

        bool OnGossipHello(Player* player, uint32 option);
        bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action);
        bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code);

        Creature* GetBotsPet() const { return botPet; }

        void Evade();
        void Follow(bool force = false, Position* newpos = nullptr)
        {
            if (force ||
                (me->IsAlive() && (!me->IsInCombat() || !opponent) && m_botCommandState != COMMAND_STAY))
                SetBotCommandState(COMMAND_FOLLOW, force, newpos);
        }

        EventProcessor* GetEvents() { return &Events; }
        ObjectGuid::LowType GetBotOwnerGuid() const { return _ownerGuid; }
        Player* GetBotOwner() const { return master; }
        bool SetBotOwner(Player* newowner);
        uint8 GetBotClass() const { return _botclass; }
        uint32 GetLastDiff() const { return lastdiff; }
        virtual void UpdateDeadAI(uint32 diff) {}
        void ReturnHome() { _atHome = false; }
        void CommonTimers(uint32 diff);
        void ResetBotAI(uint8 resetType);
        void KillEvents(bool force);
        bool CanRespawn() { return IAmFree(); }
        void SetBotCommandState(CommandStates st, bool force = false, Position* newpos = nullptr);
        bool IsInBotParty(Unit const* unit) const;
        bool CanBotAttack(Unit const* target, int8 byspell = 0) const;
        CommandStates GetBotCommandState() const { return m_botCommandState; }
        void ApplyBotDamageMultiplierMelee(uint32& damage, CalcDamageInfo& damageinfo) const;
        void ApplyBotDamageMultiplierMelee(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const;
        void ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const;
        void ApplyBotDamageMultiplierHeal(Unit const* victim, float& heal, SpellInfo const* spellInfo, DamageEffectType damagetype, uint32 stack) const;
        void ApplyBotCritMultiplierAll(Unit const* victim, float& crit_chance, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType) const;
        void ApplyBotSpellCostMods(SpellInfo const* spellInfo, int32& cost) const;
        void ApplyBotSpellCastTimeMods(SpellInfo const* spellInfo, int32& casttime) const;
        void ApplyBotSpellCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const;
        void ApplyBotSpellCategoryCooldownMods(SpellInfo const* spellInfo, uint32& cooldown) const;
        void ApplyBotSpellGlobalCooldownMods(SpellInfo const* spellInfo, float& cooldown) const;
        void ApplyBotSpellRadiusMods(SpellInfo const* spellInfo, float& radius) const;
        void ApplyBotSpellRangeMods(SpellInfo const* spellInfo, float& maxrange) const;
        void ApplyBotSpellMaxTargetsMods(SpellInfo const* spellInfo, uint32& targets) const;
        void ApplyBotSpellChanceOfSuccessMods(SpellInfo const* spellInfo, float& chance) const;
        void ApplyBotEffectMods(SpellInfo const* spellInfo, uint8 effIndex, float& value) const;
        void ApplyBotEffectMods(Unit const* target, SpellInfo const* spellInfo, uint8 effIndex, float& value) const;
        virtual uint8 GetBotStance() const;
        uint16 GetBotRoles() const { return _roleMask; }
        bool HasRole(uint16 role) const { return _roleMask & role; }
        uint8 GetRoleIcon(uint16 role) const;
        char const* GetRoleString(uint16 role) const;
        void ToggleRole(uint16 role, bool force);
        bool IsTank(Unit const* unit = nullptr) const;
        bool IAmFree() const;

        static bool CCed(Unit const* target, bool root = false);

        void TeleportHome();
        bool FinishTeleport(/*uint32 mapId, uint32 instanceId, float x, float y, float z, float o*/);

        bool IsDuringTeleport() const { return teleFinishEvent || teleHomeEvent; }
        void SetTeleportFinishEvent(TeleportFinishEvent* tfevent) { ASSERT(!teleFinishEvent); teleFinishEvent = tfevent; }
        void AbortTeleport();

        uint8 GetPlayerClass() const;
        uint8 GetPlayerRace() const;

        //bool IsTempBot() const { return me->GetSpawnId() == 0; }
        bool IsTempBot() const { return me->GetEntry() == BOT_ENTRY_MIRROR_IMAGE_BM; }

        void SetShouldUpdateStats() { shouldUpdateStats = true; }
        void UpdateHealth() { doHealth = true; }
        void UpdateMana() { doMana = true; }

        //float GetHitRating() const { return hit; }
        int32 GetHaste() const { return haste; }
        float GetBotParryChance() const { return parry; }
        float GetBotDodgeChance() const { return dodge; }
        float GetBotBlockChance() const { return block; }
        float GetBotCritChance() const { return crit; }
        float GetBotMissChance() const { return -hit; }
        float GetBotDamageTakenMod(bool magic) const { return magic ? dmg_taken_mag : dmg_taken_phy; }
        uint32 GetBotExpertise() const { return expertise; }
        uint32 GetBotSpellPenetration() const { return spellpen; }
        uint32 GetBotSpellPower() const { return spellpower; }
        uint32 GetBotDefense() const { return defense; }
        uint32 GetShieldBlockValue() const { return blockvalue; }
        int32 GetBotResistanceBonus(SpellSchoolMask mask) const;
        int32 GetBotResistanceBonus(uint8 school) const { return (school > SPELL_SCHOOL_NORMAL && school < MAX_SPELL_SCHOOL) ? resistbonus[school-1] : 0; }
        bool CanBlock() const;
        bool CanParry() const;
        bool CanDodge() const;
        bool CanCrit() const;
        bool CanMiss() const;
        bool CanSheath() const;
        bool CanSit() const;
        virtual bool CanEat() const;
        bool CanDrink() const;
        bool CanRegenInCombat() const;
        bool CanMount() const;
        bool CanUseAmmo() const;
        bool RespectEquipsAttackTime() const;
        bool CanChangeEquip(uint8 slot) const;
        virtual bool CanSeeEveryone() const { return false; }
        virtual float GetBotArmorPenetrationCoef() const { return armor_pen; }
        virtual uint32 GetAIMiscValue(uint32 /*data*/) const { return 0; }
        virtual void SetAIMiscValue(uint32 /*data*/, uint32 /*value*/) {}
        uint8 GetBotComboPoints() const;
        float GetBotAmmoDPS() const;

        MeleeHitOutcome BotRollCustomMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const;

        float GetTotalBotStat(uint8 stat) const { return _getTotalBotStat(stat); }

        Item* GetEquips(uint8 slot) const { return _equips[slot]; }
        Item* GetEquipsByGuid(ObjectGuid itemGuid) const;

        void CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx);
        void CastBotItemCombatSpell(Unit* target, WeaponAttackType attType, uint32 procVictim, uint32 procEx, Item* item, ItemTemplate const* proto);
        void OnBotSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs);
        void OnBotSpellGo(Spell const* spell);
        virtual void OnClassSpellGo(SpellInfo const* /*spell*/) {}

        static void InitBotCustomSpells();
        static bool IsBotCustomSpell(uint32 spellId);

        uint32 GetReviveTimer() const { return _reviveTimer; }
        void SetReviveTimer(uint32 newtime) { _reviveTimer = newtime; }
        void UpdateReviveTimer(uint32 diff);

        void StartBoot() { _bootTimer = 60000; }
        void CancelBoot() { _bootTimer = -1; }

        bool IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD = true) const;
        void SetSpellCooldown(uint32 basespell, uint32 msCooldown);
        void SetSpellCategoryCooldown(SpellInfo const* spellInfo, uint32 msCooldown);
        void ReleaseSpellCooldown(uint32 basespell);

        virtual void SpendRunes(SpellInfo const* /*spellInfo*/, bool /*didHit*/) {}

        void ReInitFaction() { InitFaction(); }
        void ReinitOwner() { InitOwner(); }

        static bool IsMeleeClass(uint8 m_class);
        static bool IsTankingClass(uint8 m_class);
        static bool IsBlockingClass(uint8 m_class);
        static bool IsCastingClass(uint8 m_class);
        static bool IsHealingClass(uint8 m_class);
        static bool IsHumanoidClass(uint8 m_class);
        static bool IsHeroExClass(uint8 m_class);

        //Pet stuff
        static uint32 GetPetOriginalEntry(uint32 entry);
        static bool IsPetMelee(uint32 entry);
        virtual uint8 GetPetPositionNumber(Creature const* /*summon*/) const { return 0; }

        Unit* HelpFindStunTarget(float dist = 20) const { return FindStunTarget(dist); }
        Unit* HelpFindCastingTarget(float maxdist = 10, float mindist = 0, uint32 spellId = 0, uint8 minHpPct = 0) const { return FindCastingTarget(maxdist, mindist, spellId, minHpPct); }
        void HelpGetNearbyTargetsList(std::list<Unit*> &targets, float maxdist, uint8 CCoption, WorldObject const* source = nullptr) const { GetNearbyTargetsList(targets, maxdist, CCoption, source); }

    protected:
        explicit bot_ai(Creature* creature);

        virtual void ReduceCD(uint32 /*diff*/) {}
        bool GlobalUpdate(uint32 diff);

        virtual bool HealTarget(Unit* /*target*/, uint32 /*diff*/) { return false; }
        virtual bool BuffTarget(Unit* /*target*/, uint32 /*diff*/) { return false; }

        void BuffAndHealGroup(uint32 diff);
        void RezGroup(uint32 REZZ);
        void CureGroup(uint32 cureSpell, uint32 diff);
        void SetStats(bool force);
        void DefaultInit();

        void OnOwnerDamagedBy(Unit* attacker);

        static uint32 InitSpell(Unit const* caster, uint32 spell);
        void InitSpellMap(uint32 basespell, bool forceadd = false, bool forwardRank = true);
        uint32 GetSpell(uint32 basespell) const;
        uint32 GetSpellCooldown(uint32 basespell) const;
        void ResetSpellCooldown(uint32 basespell) { SetSpellCooldown(basespell, 0); }
        void RemoveSpell(uint32 basespell);
        void SpellTimers(uint32 diff);
        static uint32 RaceSpellForClass(uint8 myrace, uint8 myclass);

        virtual bool CanUseManually(uint32 /*basespell*/) const { return false; }
        virtual bool HasAbilitiesSpecifics() const { return false; }
        /*virtual */bool HasAblitiesAllowedList() const { return true; }
        virtual void FillAbilitiesSpecifics(std::list<std::string> &/*specList*/) {}

        uint32 GetDPSTaken(Unit const* u) const;
        int32 GetHPSTaken(Unit const* u) const;
        int32 GetHPS(Unit const* u) const;
        int32 GetHPPCTPS(Unit const* u) const;
        uint8 GetExpectedHPPCT(Unit const* u, uint32 mseconds) const;

        void RefreshAura(uint32 spellId, int8 count = 1, Unit* target = nullptr) const;
        bool CheckAttackTarget();
        void MoveBehind(Unit const* target) const;

        void AdjustTankingPosition() const;
        void OnStartAttack(Unit const* u);

        virtual void BreakCC(uint32 diff);
        void CheckRacials(uint32 diff);

        void DrinkPotion(bool mana);
        bool IsPotionReady() const;
        uint32 GetPotion(bool mana) const;

        //everything cast-related
        bool doCast(Unit* victim, uint32 spellId, bool triggered = false);
        bool doCast(Unit* victim, uint32 spellId, TriggerCastFlags flags);
        SpellCastResult CheckBotCast(Unit const* victim, uint32 spellId) const;
        virtual bool removeShapeshiftForm() { return true; }

        bool CanAffectVictim(uint32 schoolMask) const;
        bool CanRemoveReflectSpells(Unit const* target, uint32 spellId) const;

        bool IsMelee() const;

        bool IsShootingWand(Unit const* u = nullptr) const;

        bool IsChanneling(Unit const* u = nullptr) const { if (!u) u = me; return u->GetCurrentSpell(CURRENT_CHANNELED_SPELL); }
        bool IsCasting(Unit const* u = nullptr) const { if (!u) u = me; return (u->HasUnitState(UNIT_STATE_CASTING) || IsChanneling(u) || u->IsNonMeleeSpellCast(false, false, true, false, false)); }
        bool JumpingFlyingOrFalling() const { return Jumping() || me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_SPLINE_ELEVATION|MOVEMENTFLAG_FALLING_SLOW); }
        bool JumpingOrFalling() const { return Jumping() || me->IsFalling() || me->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_FALLING_SLOW); }
        bool Jumping() const { return me->HasUnitState(UNIT_STATE_JUMPING); }

        float CalcSpellMaxRange(uint32 spellId, bool enemy = true) const;
        float InitAttackRange(float origRange, bool ranged) const;
        void CalculateAttackPos(Unit const* target, Position &pos) const;
        void GetInPosition(bool force, Unit* newtarget, Position* pos = nullptr);
        virtual float GetSpellAttackRange(bool longRange) const { return longRange ? 25.f : 15.f; }
        virtual void CheckAttackState();
        void OnSpellHit(Unit* caster, SpellInfo const* spell);

        //Searchers
        WorldObject* GetNearbyRezTarget(float dist = 30) const;
        Unit* FindImmunityShieldDispelTarget(float dist = 30) const;
        Unit* FindHostileDispelTarget(float dist = 30, bool stealable = false) const;
        Unit* FindAffectedTarget(uint32 spellId, ObjectGuid caster = ObjectGuid::Empty, float dist = DEFAULT_VISIBILITY_DISTANCE, uint8 hostile = 0) const;
        Unit* FindPolyTarget(float dist = 30) const;
        Unit* FindFearTarget(float dist = 30) const;
        Unit* FindStunTarget(float dist = 20) const;
        Unit* FindUndeadCCTarget(float dist, uint32 spellId, bool unattacked = true) const;
        Unit* FindRootTarget(float dist, uint32 spellId) const;
        Unit* FindCastingTarget(float maxdist = 10, float mindist = 0, uint32 spellId = 0, uint8 minHpPct = 0) const;
        Unit* FindAOETarget(float dist) const;
        Unit* FindSplashTarget(float dist = 5, Unit* To = nullptr, float splashdist = 4) const;
        Unit* FindSplashTarget(float dist, Unit* To, float splashdist, uint8 minTargets) const;
        Unit* FindTranquilTarget(float mindist = 5, float maxdist = 35) const;
        Unit* FindDistantTauntTarget(float maxdist = 30, bool ally = false) const;
        Unit* FindDrainTarget(float maxdist = 30) const;
        void GetNearbyTargetsList(std::list<Unit*> &targets, float maxdist, uint8 CCoption, WorldObject const* source = nullptr) const;
        void GetNearbyTargetsInConeList(std::list<Unit*> &targets, float maxdist = 10) const;
        void GetNearbyFriendlyTargetsList(std::list<Unit*> &targets, float maxdist = 30) const;

        //Bot specific player-like mods hooks
        //todo remove &damage ApplyClassDamageMultiplierMelee (uint&, CalcDamageInfo&)
        virtual void ApplyClassDamageMultiplierMelee(uint32& /*damage*/, CalcDamageInfo& /*damageinfo*/) const {}
        virtual void ApplyClassDamageMultiplierMelee(int32& /*damage*/, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool /*crit*/) const {}
        virtual void ApplyClassDamageMultiplierSpell(int32& /*damage*/, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool /*crit*/) const {}
        virtual void ApplyClassDamageMultiplierHeal(Unit const* /*victim*/, float& /*heal*/, SpellInfo const* /*spellInfo*/, DamageEffectType /*damagetype*/, uint32 /*stack*/) const {}
        virtual void ApplyClassSpellCritMultiplierAll(Unit const* /*victim*/, float& /*crit_chance*/, SpellInfo const* /*spellInfo*/, SpellSchoolMask /*schoolMask*/, WeaponAttackType /*attackType*/) const {}
        virtual void ApplyClassSpellCostMods(SpellInfo const* /*spellInfo*/, int32& /*cost*/) const {}
        virtual void ApplyClassSpellCastTimeMods(SpellInfo const* /*spellInfo*/, int32& /*casttime*/) const {}
        virtual void ApplyClassSpellCooldownMods(SpellInfo const* /*spellInfo*/, uint32& /*cooldown*/) const {}
        virtual void ApplyClassSpellCategoryCooldownMods(SpellInfo const* /*spellInfo*/, uint32& /*cooldown*/) const {}
        virtual void ApplyClassSpellGlobalCooldownMods(SpellInfo const* /*spellInfo*/, float& /*cooldown*/) const {}
        virtual void ApplyClassSpellRadiusMods(SpellInfo const* /*spellInfo*/, float& /*radius*/) const {}
        virtual void ApplyClassSpellRangeMods(SpellInfo const* /*spellInfo*/, float& /*maxrange*/) const {}
        virtual void ApplyClassSpellMaxTargetsMods(SpellInfo const* /*spellInfo*/, uint32& /*targets*/) const {}
        virtual void ApplyClassSpellChanceOfSuccessMods(SpellInfo const* /*spellInfo*/, float& /*chance*/) const {}
        virtual void ApplyClassEffectMods(SpellInfo const* /*spellInfo*/, uint8 /*effIndex*/, float& /*value*/) const {}
        virtual void ApplyClassEffectMods(Unit const* /*target*/, SpellInfo const* /*spellInfo*/, uint8 /*effIndex*/, float& /*value*/) const {}

        virtual void InitPowers() {}
        virtual void InitSpells() = 0;
        virtual void ApplyClassPassives() const = 0;
        virtual void InitHeals() {}

        void Regenerate();
        void RegenerateEnergy();
        bool Feasting() const;
        uint32 GetRation(bool drink) const;

        bool Wait();
        uint16 Rand() const;
        void GenerateRand() const;

        static uint32 GetLostHP(Unit const* unit) { return unit->GetMaxHealth() - unit->GetHealth(); }
        static uint8 GetHealthPCT(Unit const* u) { if (!u || !u->IsAlive() || u->GetMaxHealth() <= 1) return 100; return uint8(((float(u->GetHealth()))/u->GetMaxHealth()) * 100); }
        static uint8 GetManaPCT(Unit const* u) { if (!u || !u->IsAlive() || u->GetMaxPower(POWER_MANA) <= 1) return 100; return (u->GetPower(POWER_MANA)*10/(1 + u->GetMaxPower(POWER_MANA)/10)); }

        virtual MeleeHitOutcome GetNextAttackMeleeOutCome() const { return MELEE_HIT_CRUSHING; }

        //event helpers
        void BotJumpInPlaceInFrontOf(Position const* pos, float speedXY, float maxHeight);

        void BuildGrouUpdatePacket(WorldPacket* data);

        void BotSay(char const* text, Player const* target = nullptr) const;
        void BotWhisper(char const* text, Player const* target = nullptr) const;
        void BotYell(char const* text, Player const* target = nullptr) const;

        void ApplyItemBonuses(uint8 slot);

        Player* master;
        Unit* opponent;
        Creature* botPet;
        EventProcessor Events;
        ObjectGuid aftercastTargetGuid;
        uint32 GC_Timer;

        uint8 _botclass;

    private:
        void FindMaster();

        void _OnHealthUpdate() const;
        void _OnManaUpdate() const;
        void _OnManaRegenUpdate() const;

        void RemoveItemBonuses(uint8 slot);
        void RemoveItemEnchantments(Item const* item);
        void RemoveItemEnchantment(Item const* item, EnchantmentSlot eslot);
        void RemoveItemClassEnchants();
        void ApplyItemEnchantments(Item* item, uint8 slot);
        void ApplyItemEnchantment(Item* item, EnchantmentSlot eslot, uint8 slot);
        void ApplyItemEquipSpells(Item* item, bool apply);
        void ApplyItemEquipEnchantmentSpells(Item* item);
        void ApplyItemSetBonuses(Item* item, bool apply);
        void ApplyItemsSpells();

        bool IsPotionSpell(uint32 spellId) const;
        void StartPotionTimer();

        void BotJump(Position const* pos);
        bool UpdateImpossibleChase(Unit const* target);
        void ResetChaseTimer(Position const* pos);
        void ResetChase(Position const* pos);

        void ApplyRacials();
        void InitRoles();
        void InitEquips();
        void InitOwner();
        void InitFaction();
        void InitRace();

        bool _canCureTarget(Unit const* target, uint32 cureSpell) const;
        void _getBotDispellableAuraList(Unit const* target, uint32 dispelMask, std::list<Aura const*> &dispelList) const;
        void _calculatePos(Position& pos) const;
        void _updateMountedState();
        void _updateStandState() const;
        void _updateRations();
        char const* _getNameForSlot(uint8 slot) const;
        void _updateEquips(uint8 slot, Item* item);

        bool _canUseOffHand() const;
        bool _canUseRanged() const;
        bool _canUseRelic() const;
        bool _canEquip(ItemTemplate const* item, uint8 slot, bool ignoreItemLevel = false) const;
        bool _unequip(uint8 slot);
        bool _equip(uint8 slot, Item* newItem);
        bool _resetEquipment(uint8 slot);

        void _castBotItemUseSpell(Item const* item, SpellCastTargets const& targets/*, uint8 cast_count = 0, uint32 glyphIndex = 0*/);

        Unit* _getTarget(bool byspell, bool ranged, bool &reset) const;
        void _listAuras(Player const* player, Unit const* unit) const;
        bool _checkImmunities(Unit const* target, SpellInfo const* spellInfo) const;
        static float _getAttackDistance(float distance) { return distance*0.72f; }

        //for moved
        void GetHomePosition(uint16& mapid, Position* pos) const;

        //utilities
        void _AddItemTemplateLink(Player const* forPlayer, ItemTemplate const* item, std::ostringstream &str) const;
        void _AddItemLink(Player const* forPlayer, Item const* item, std::ostringstream &str, bool addIcon = true) const;
        void _AddQuestLink(Player const* forPlayer, Quest const* quest, std::ostringstream &str) const;
        void _AddWeaponSkillLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillid) const;
        void _AddSpellLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, bool color = true) const;
        void _AddProfessionLink(Player const* forPlayer, SpellInfo const* spellInfo, std::ostringstream &str, uint32 skillId) const;
        void _LocalizeItem(Player const* forPlayer, std::string &itemName, uint32 entry) const;
        void _LocalizeItem(Player const* forPlayer, std::string &itemName, std::string &suffix, Item const* item) const;
        void _LocalizeQuest(Player const* forPlayer, std::string &questTitle, uint32 entry) const;
        void _LocalizeCreature(Player const* forPlayer, std::string &creatureName, uint32 entry) const;
        void _LocalizeGameObject(Player const* forPlayer, std::string &gameobjectName, uint32 entry) const;

        float _getBotStat(uint8 slot, uint8 stat) const;
        float _getTotalBotStat(uint8 stat) const;
        float _getRatingMultiplier(CombatRating cr) const;

        PlayerClassLevelInfo* _classinfo;
        SpellInfo const* m_botSpellInfo;
        Position pos, attackpos;

        CommandStates m_botCommandState;

        //stats
        float hit, parry, dodge, block, crit, dmg_taken_phy, dmg_taken_mag, armor_pen;
        uint32 expertise, spellpower, spellpen, defense, blockvalue;
        int32 haste, resistbonus[6];

        //timers
        uint32 _reviveTimer, _powersTimer, _chaseTimer, _potionTimer;
        uint32 lastdiff, checkAurasTimer, checkMasterTimer, roleTimer, waitTimer, regenTimer, _updateTimerMedium, _updateTimerEx1;
        int32 _bootTimer;

        uint8 _jumpCount, _evadeCount;
        uint16 _roleMask;
        ObjectGuid::LowType _ownerGuid;
        ObjectGuid _lastTargetGuid;
        bool doHealth, doMana, shouldUpdateStats;
        bool feast_health, feast_mana;
        bool spawned;
        bool firstspawn;
        bool _evadeMode;
        bool _atHome;

        float _energyFraction;

        //counters (this session)
        uint16 _deathsCount;
        uint16 _killsCount;
        uint16 _pvpKillsCount;
        uint16 _playerKillsCount;

        TeleportHomeEvent* teleHomeEvent;
        TeleportFinishEvent* teleFinishEvent;

        struct BotSpell
        {
            explicit BotSpell() : cooldown(0), enabled(true) {}
            uint32 spellId;
            uint32 cooldown;
            bool enabled;
        private:
            BotSpell(BotSpell const&);
        };

        typedef std::unordered_map<uint32 /*stat*/, int32 /*statvalue*/> BotStat;
        BotStat _stats[BOT_INVENTORY_SIZE];
        Item* _equips[BOT_INVENTORY_SIZE];

    protected:
        typedef std::unordered_map<uint32 /*firstrankspellid*/, BotSpell* /*spell*/> BotSpellMap;
        BotSpellMap const& GetSpellMap() const { return _spells; }

    private:
        BotSpellMap _spells;
};

#endif
