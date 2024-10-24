#ifndef _BOT_PET_AI_H
#define _BOT_PET_AI_H

#include "botcommon.h"

#include "CreatureAI.h"
#include "Position.h"

/*
NpcBot Pet System by Trickerer (onlysuffering@gmail.com)
*/

struct SpellNonMeleeDamage;

class Aura;
class Spell;
class Unit;

class bot_pet_ai : public CreatureAI
{
    public:
        virtual ~bot_pet_ai();

        bool canUpdate;

        void InitializeAI() override { Reset(); }
        void Reset() override {}

        void JustDied(Unit*) override;
        void KilledUnit(Unit* u) override;
        void AttackStart(Unit* u) override;
        //virtual void JustEnteredCombat(Unit* u) override;
        void MoveInLineOfSight(Unit* /*u*/) override {}
        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType damageType) override;
        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo*/) override { }
        //void ReceiveEmote(Player* player, uint32 emote);
        void EnterEvadeMode(EvadeReason/* why*/ = EVADE_REASON_OTHER) override { }
        uint32 GetData(uint32 data) const override;
        void IsSummonedBy(WorldObject* summoner) override;

        Creature* GetPetsOwner() const { return petOwner; }
        void CalculatePetsOwnerFollowPosition(Position &pos) { _calculatePos(pos); }

        //EventProcessor* GetEvents() { return &_petEvents; }
        uint32 GetLastDiff() const { return lastdiff; }
        void CommonTimers(uint32 diff);
        void KillEvents(bool force);
        void SetBotCommandState(uint32 st, bool force = false, Position* newpos = nullptr);
        void RemoveBotCommandState(uint32 st);
        bool HasBotCommandState(uint32 st) const { return (m_botCommandState & st); }
        uint8 GetBotCommandState() const { return m_botCommandState; }
        bool IsInBotParty(Unit const* unit) const;
        virtual void ApplyBotPetSpellRadiusMods(SpellInfo const* /*spellInfo*/, float& /*radius*/) const {}
        bool IsTank(Unit const* unit) const;
        bool IsOffTank(Unit const* unit) const;

        bool IAmFree() const;

        //wandering bots
        bool IsWanderer() const { return _wanderer; }
        void SetWanderer() { if (IAmFree()) _wanderer = true; }

        uint64 GetAuraUpdateMaskForRaid() const { return _auraRaidUpdateMask; }
        void SetAuraUpdateMaskForRaid(uint8 slot) { _auraRaidUpdateMask |= (uint64(1) << slot); }
        void ResetAuraUpdateMaskForRaid() { _auraRaidUpdateMask = 0; }

        static bool CCed(Unit const* target, bool root = false);

        inline void SetShouldUpdateStats() { shouldUpdateStats = true; }

        //virtual uint32 GetAIMiscValue(uint32 /*data*/) const { return 0; }
        //virtual void SetAIMiscValue(uint32 /*data*/, uint32 /*value*/) {}

        void OnBotPetSpellInterrupted(SpellSchoolMask schoolMask, uint32 unTimeMs);
        void OnBotPetSpellGo(Spell const* spell, bool ok = true);
        virtual void OnPetClassSpellGo(SpellInfo const* /*spellInfo*/) {}

        bool IsSpellReady(uint32 basespell, uint32 diff, bool checkGCD = true) const;
        void SetSpellCooldown(uint32 basespell, uint32 msCooldown);
        void SetSpellCategoryCooldown(SpellInfo const* spellInfo, uint32 msCooldown);
        void ReleaseSpellCooldown(uint32 basespell);

        void ApplyBotDamageMultiplierSpell(int32& damage, SpellNonMeleeDamage& damageinfo, SpellInfo const* spellInfo, WeaponAttackType attackType, bool crit) const;

    protected:
        explicit bot_pet_ai(Creature* creature);

        virtual void ApplyClassDamageMultiplierSpell(int32& /*damage*/, SpellNonMeleeDamage& /*damageinfo*/, SpellInfo const* /*spellInfo*/, WeaponAttackType /*attackType*/, bool /*crit*/) const {}

        virtual void ReduceCD(uint32 /*diff*/) {}
        bool GlobalUpdate(uint32 diff);

        void CureGroup(uint32 cureSpell, uint32 diff);
        void SetPetStats(bool force);

        void OnOwnerDamagedBy(Unit* attacker);

        bool IsPetMelee() const;
        uint8 Spec() const;

        static uint32 InitSpell(Unit const* caster, uint32 spell);
        void InitSpellMap(uint32 basespell, bool forceadd = false, bool forwardRank = true);
        uint32 GetSpell(uint32 basespell) const;
        uint32 GetSpellCooldown(uint32 basespell) const;
        void ResetSpellCooldown(uint32 basespell) { SetSpellCooldown(basespell, 0); }
        void RemoveSpell(uint32 basespell);
        void SpellTimers(uint32 diff);

        void RefreshAura(uint32 spellId, int8 count = 1, Unit* target = nullptr) const;
        bool CheckAttackTarget();
        void MoveBehind(Unit const* target) const;

        void AdjustTankingPosition() const;
        void OnStartAttack(Unit const* /*u*/);
        bool StartAttack(Unit const* u, bool force = false);

        bool IsChanneling(Unit const* u = nullptr) const;
        bool IsCasting(Unit const* u = nullptr) const;
        bool JumpingFlyingOrFalling() const;
        bool JumpingOrFalling() const;
        bool Jumping() const;
        bool IsIndoors() const;
        bool IsOutdoors() const;

        float CalcSpellMaxRange(uint32 spellId, bool enemy = true) const;
        void CalculateAttackPos(Unit* target, Position &pos) const;
        void GetInPosition(bool force, Unit* newtarget, Position* pos = nullptr);
        virtual float GetSpellAttackRange(bool longRange) const { return longRange ? 25.f : 15.f; }
        virtual void CheckAttackState();
        void OnSpellHit(Unit* caster, SpellInfo const* spell);

        virtual void InitPetSpells() {}
        virtual void ApplyPetPassives() const {}

        void Regenerate();
        void RegeneratePetFocus();
        void RegeneratePetEnergy();

        bool Wait();
        uint16 Rand() const;
        void GenerateRand() const;

        static uint32 GetLostHP(Unit const* unit);
        static uint8 GetHealthPCT(Unit const* u);
        static uint8 GetManaPCT(Unit const* u);

        Unit* opponent;
        Creature* petOwner;
        //EventProcessor _petEvents;
        uint32 GC_Timer;
        uint32 myType;

    private:
        bool _canCureTarget(Unit const* target, uint32 cureSpell) const;
        void _getBotDispellableAuraList(Unit const* target, Unit const* caster, uint32 dispelMask, std::list<Aura const*> &dispelList) const;
        void _calculatePos(Position& pos) const;

        bool _canRegenerate() const;

        Unit* _getTarget(bool &reset) const;
        bool _checkImmunities(Unit const* target, SpellInfo const* spellInfo) const;
        static inline float _getAttackDistance(float distance) { return distance*0.72f; }

        Position movepos, attackpos;
        uint32 m_botCommandState;

        //timers
        uint32 lastdiff, checkAurasTimer, regenTimer, _updateTimerMedium, _updateTimerEx1;
        uint32 waitTimer;
        uint32 _moveBehindTimer;
        uint32 indoorsTimer;
        uint32 outdoorsTimer;

        //wandering bots
        bool _wanderer;

        uint64 _auraRaidUpdateMask;

        float _energyFraction;

        bool shouldUpdateStats;

        struct BotPetSpell
        {
            explicit BotPetSpell() : spellId(0), cooldown(0), enabled(true) {}
            uint32 spellId;
            uint32 cooldown;
            bool enabled;
        private:
            BotPetSpell(BotPetSpell const&);
        };

        typedef std::unordered_map<uint32 /*firstrankspellid*/, BotPetSpell* /*spell*/> BotPetSpellMap;
        BotPetSpellMap const& GetSpellMap() const { return _spells; }
        BotPetSpellMap _spells;
};

#endif
