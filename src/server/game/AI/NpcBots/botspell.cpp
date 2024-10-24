#include "botspell.h"
#include "DBCStores.h"
#include "Log.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Timer.h"

#include <unordered_map>

typedef std::unordered_map<uint32, SpellInfo> SpellInfoOverridesMap;
typedef std::unordered_map<uint32, SpellProcEntry> SpellProcOverridesMap;
static SpellInfoOverridesMap botSpellInfoOverrides;
static SpellProcOverridesMap botSpellProcOverrides;

void GenerateBotCustomSpellProcs()
{
    botSpellProcOverrides.clear();

    bool isTriggerAura[TOTAL_AURAS];
    bool isAlwaysTriggeredAura[TOTAL_AURAS];
    uint32 spellTypeMask[TOTAL_AURAS];
    for (uint16 i = 0; i < TOTAL_AURAS; ++i)
    {
        isTriggerAura[i] = false;
        isAlwaysTriggeredAura[i] = false;
        spellTypeMask[i] = PROC_SPELL_TYPE_MASK_ALL;
    }

    isTriggerAura[SPELL_AURA_DUMMY] = true;                                 // Most dummy auras should require scripting, but there are some exceptions (ie 12311)
    isTriggerAura[SPELL_AURA_MOD_CONFUSE] = true;                           // "Any direct damaging attack will revive targets"
    isTriggerAura[SPELL_AURA_MOD_THREAT] = true;                            // Only one spell: 28762 part of Mage T3 8p bonus
    isTriggerAura[SPELL_AURA_MOD_STUN] = true;                              // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_RESISTANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_STEALTH] = true;
    isTriggerAura[SPELL_AURA_MOD_FEAR] = true;                              // Aura does not have charges but needs to be removed on trigger
    isTriggerAura[SPELL_AURA_MOD_ROOT] = true;
    isTriggerAura[SPELL_AURA_TRANSFORM] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS] = true;
    isTriggerAura[SPELL_AURA_DAMAGE_IMMUNITY] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_DAMAGE] = true;
    isTriggerAura[SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_POWER_COST_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_REFLECT_SPELLS_SCHOOL] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER] = true;
    isTriggerAura[SPELL_AURA_ADD_CASTER_HIT_TRIGGER] = true;
    isTriggerAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isTriggerAura[SPELL_AURA_MOD_MELEE_HASTE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE] = true;
    isTriggerAura[SPELL_AURA_RAID_PROC_FROM_CHARGE_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE] = true;
    isTriggerAura[SPELL_AURA_MOD_SPELL_CRIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_ADD_FLAT_MODIFIER] = true;
    isTriggerAura[SPELL_AURA_ADD_PCT_MODIFIER] = true;
    isTriggerAura[SPELL_AURA_ABILITY_IGNORE_AURASTATE] = true;
    isTriggerAura[SPELL_AURA_MOD_INVISIBILITY] = true;
    isTriggerAura[SPELL_AURA_FORCE_REACTION] = true;
    isTriggerAura[SPELL_AURA_MOD_TAUNT] = true;
    isTriggerAura[SPELL_AURA_MOD_DETAUNT] = true;
    isTriggerAura[SPELL_AURA_MOD_DAMAGE_PERCENT_DONE] = true;
    isTriggerAura[SPELL_AURA_MOD_ATTACK_POWER_PCT] = true;
    isTriggerAura[SPELL_AURA_MOD_HIT_CHANCE] = true;
    isTriggerAura[SPELL_AURA_MOD_WEAPON_CRIT_PERCENT] = true;
    isTriggerAura[SPELL_AURA_MOD_BLOCK_PERCENT] = true;

    isAlwaysTriggeredAura[SPELL_AURA_OVERRIDE_CLASS_SCRIPTS] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STEALTH] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_CONFUSE] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_FEAR] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_ROOT] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_STUN] = true;
    isAlwaysTriggeredAura[SPELL_AURA_TRANSFORM] = true;
    isAlwaysTriggeredAura[SPELL_AURA_MOD_INVISIBILITY] = true;

    spellTypeMask[SPELL_AURA_MOD_STEALTH] = PROC_SPELL_TYPE_DAMAGE | PROC_SPELL_TYPE_NO_DMG_HEAL;
    spellTypeMask[SPELL_AURA_MOD_CONFUSE] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_FEAR] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_ROOT] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_STUN] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_TRANSFORM] = PROC_SPELL_TYPE_DAMAGE;
    spellTypeMask[SPELL_AURA_MOD_INVISIBILITY] = PROC_SPELL_TYPE_DAMAGE;

    for (auto const& p : botSpellInfoOverrides)
    {
        SpellInfo const& spellInfo = p.second;

        if (!spellInfo.ProcFlags)
            continue;

        bool addTriggerFlag = false;
        uint32 procSpellTypeMask = PROC_SPELL_TYPE_NONE;
        uint32 nonProcMask = 0;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
        {
            if (!spellEffectInfo.IsEffect())
                continue;

            uint32 auraName = spellEffectInfo.ApplyAuraName;
            if (!auraName)
                continue;

            if (!isTriggerAura[auraName])
            {
                // explicitly disable non proccing auras to avoid losing charges on self proc
                nonProcMask |= 1 << spellEffectInfo.EffectIndex;
                continue;
            }

            procSpellTypeMask |= spellTypeMask[auraName];
            if (isAlwaysTriggeredAura[auraName])
                addTriggerFlag = true;

            if (!addTriggerFlag && (spellInfo.ProcFlags & TAKEN_HIT_PROC_FLAG_MASK) != 0)
            {
                switch (auraName)
                {
                    case SPELL_AURA_PROC_TRIGGER_SPELL:
                    case SPELL_AURA_PROC_TRIGGER_DAMAGE:
                        addTriggerFlag = true;
                        break;
                    default:
                        break;
                }
            }
        }

        if (!procSpellTypeMask)
        {
            for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
            {
                if (spellEffectInfo.IsAura())
                {
                    TC_LOG_ERROR("scripts", "Bot spell {} has ProcFlags {}, but it's of non-proc aura type, needs a correction", spellInfo.Id, spellInfo.ProcFlags);
                    break;
                }
            }
            continue;
        }

        SpellProcEntry procEntry;
        procEntry.SchoolMask = 0;
        procEntry.ProcFlags = spellInfo.ProcFlags;
        procEntry.SpellFamilyName = 0;
        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
            if (spellEffectInfo.IsEffect() && isTriggerAura[spellEffectInfo.ApplyAuraName])
                procEntry.SpellFamilyMask |= spellEffectInfo.SpellClassMask;

        if (procEntry.SpellFamilyMask)
            procEntry.SpellFamilyName = spellInfo.SpellFamilyName;

        procEntry.SpellTypeMask   = procSpellTypeMask;
        procEntry.SpellPhaseMask  = PROC_SPELL_PHASE_HIT;
        procEntry.HitMask         = PROC_HIT_NONE;

        for (SpellEffectInfo const& spellEffectInfo : spellInfo.GetEffects())
        {
            if (!spellEffectInfo.IsAura())
                continue;

            switch (spellEffectInfo.ApplyAuraName)
            {
                case SPELL_AURA_REFLECT_SPELLS:
                case SPELL_AURA_REFLECT_SPELLS_SCHOOL:
                    procEntry.HitMask = PROC_HIT_REFLECT;
                    break;
                case SPELL_AURA_MOD_WEAPON_CRIT_PERCENT:
                    procEntry.HitMask = PROC_HIT_CRITICAL;
                    break;
                case SPELL_AURA_MOD_BLOCK_PERCENT:
                    procEntry.HitMask = PROC_HIT_BLOCK;
                    break;
                case SPELL_AURA_MOD_HIT_CHANCE:
                    if (spellEffectInfo.CalcValue() <= -100)
                        procEntry.HitMask = PROC_HIT_MISS;
                    break;
                default:
                    continue;
            }
            break;
        }

        procEntry.AttributesMask  = 0;
        procEntry.DisableEffectsMask = nonProcMask;
        if (spellInfo.ProcFlags & PROC_FLAG_KILL)
            procEntry.AttributesMask |= PROC_ATTR_REQ_EXP_OR_HONOR;
        if (addTriggerFlag)
            procEntry.AttributesMask |= PROC_ATTR_TRIGGERED_CAN_PROC;

        procEntry.ProcsPerMinute  = 0;
        procEntry.Chance          = spellInfo.ProcChance;
        procEntry.Cooldown        = Milliseconds::zero();
        procEntry.Charges         = spellInfo.ProcCharges;

        botSpellProcOverrides[spellInfo.Id] = std::move(procEntry);
    }

    TC_LOG_INFO("server.loading", ">> Bot spell proc overrides generated for {} spells", uint32(botSpellProcOverrides.size()));

}

SpellInfo const* GetBotSpellInfoOverride(uint32 spellId)
{
    decltype(botSpellInfoOverrides)::const_iterator ci = botSpellInfoOverrides.find(spellId);
    return ci != botSpellInfoOverrides.cend() ? &ci->second : nullptr;
}

SpellInfo const* AssertBotSpellInfoOverride(uint32 spellId)
{
    decltype(botSpellInfoOverrides)::const_iterator ci = botSpellInfoOverrides.find(spellId);
    ASSERT(ci != botSpellInfoOverrides.cend(), "AssertBotSpellInfoOverride failed for spell Id %u!", spellId);
    return &ci->second;
}

SpellProcEntry const* GetBotSpellProceEntryOverride(uint32 spellId)
{
    decltype(botSpellProcOverrides)::const_iterator ci = botSpellProcOverrides.find(spellId);
    return ci != botSpellProcOverrides.cend() ? &ci->second : nullptr;
}

void GenerateBotCustomSpells()
{
    botSpellInfoOverrides.clear();

    uint32 spellId, triggerSpellId;
    SpellInfo* sinfo;

    //COMMON
    //1) SPELL_TELEPORT_LOCAL
    spellId = SPELL_TELEPORT_LOCAL; //7794
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->InterruptFlags = SPELL_INTERRUPT_FLAG_ABORT_ON_DMG;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(6); //5000ms
    //sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(4); //1000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //self
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->Attributes |= SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY | SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;

    sinfo->_effects[0].Effect = SPELL_EFFECT_TELEPORT_UNITS;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    sinfo->_effects[0].BasePoints = 1;

    // SPELL_NULLIFY_POISON
    spellId = SPELL_NULLIFY_POISON; //550
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->RecoveryTime = 0;
    sinfo->StartRecoveryCategory = 0;
    sinfo->StartRecoveryTime = 0;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(21); //-1
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //self
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT);
    sinfo->Attributes |= SPELL_ATTR0_PASSIVE | SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].BasePoints = -200;
    sinfo->_effects[0].MiscValue = DISPEL_POISON;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    // END SPELL_NULLIFY_POISON

    //BLADEMASTER
    //2) SPELL_COMBAT_SPECIAL_2H_ATTACK
    spellId = SPELL_COMBAT_SPECIAL_2H_ATTACK; //44079
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //6 - 100 yds
    sinfo->Attributes &= ~(SPELL_ATTR0_CANT_USED_IN_COMBAT);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_DEAD;
    //2) END SPELL_COMBAT_SPECIAL_2H_ATTACK

    //3) WINDWALK
    //3.1) TRANSPARENCY
    spellId = SPELL_TRANSPARENCY_50; //44816
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);
    triggerSpellId = spellId;

    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_CASTABLE_WHILE_SITTING);
    sinfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH);
    sinfo->AuraInterruptFlags =
        AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
    sinfo->CasterAuraStateNot = 0;
    //3.1) END TRANSPARENCY

    spellId = SPELL_NETHERWALK; //31599
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->RecoveryTime = 5000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY);
    sinfo->AttributesEx &= ~SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST;
    sinfo->AttributesEx |= (SPELL_ATTR1_NOT_BREAK_STEALTH | SPELL_ATTR1_NO_THREAT);
    sinfo->AttributesEx2 |= SPELL_ATTR2_UNK1;
    sinfo->AuraInterruptFlags =
        AURA_INTERRUPT_FLAG_SPELL_ATTACK | AURA_INTERRUPT_FLAG_MELEE_ATTACK |
        AURA_INTERRUPT_FLAG_NOT_ABOVEWATER | AURA_INTERRUPT_FLAG_MOUNT; //0x00003C07;vanish
    sinfo->CasterAuraStateNot = 0;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].BasePoints = 100;
    sinfo->_effects[0].RealPointsPerLevel = 2.5f;
    sinfo->_effects[0].ValueMultiplier = 1.0f;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_INVISIBILITY;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].TriggerSpell = 0;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].BasePoints = 10;
    sinfo->_effects[1].RealPointsPerLevel = 0.5f;
    sinfo->_effects[1].ValueMultiplier = 1.0f;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_SPEED;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].TriggerSpell = 0;
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14

    sinfo->_effects[2].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->_effects[2].BasePoints = 0;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[2].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[2].Amplitude = 0;
    sinfo->_effects[2].TriggerSpell = triggerSpellId;
    sinfo->_effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS); //14
    //3) END WINDWALK

    //4) MIRROR IMAGE (BLADEMASTER)
    spellId = SPELL_MIRROR_IMAGE_BM; //69936
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //1 - self only //6 - 100 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(566); //566 - 0 sec //3 - 60 sec //1 - 10 sec //32 - 6 seconds
    sinfo->RecoveryTime = 8000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 125 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->Attributes |= (SPELL_ATTR0_NOT_SHAPESHIFT/* | SPELL_ATTR0_CASTABLE_WHILE_SITTING | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY*/);
    sinfo->AttributesEx2 &= ~(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS);
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    //4) END MIRROR IMAGE (BLADEMASTER)

    //SPHYNX
    //5) SHADOW BLAST (SPLASH ATTACK)
    //TODO: balance
    spellId = SPELL_SHADOW_BLAST; //38085
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 60;
    sinfo->MaxLevel = 83;
    sinfo->ManaCost = BASE_MANA_SPHYNX / 16;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT | TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 1000;
    //sinfo->Attributes |= SPELL_ATTR0_HIDE_IN_COMBAT_LOG | SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->Attributes &= ~(SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION);
    //sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].BasePoints = 300;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 0.f;
    sinfo->_effects[0].DamageMultiplier = 0.75f;
    sinfo->_effects[0].RealPointsPerLevel = 50.f;
    //sinfo->_effects[0].ValueMultiplier = 1.f;

    sinfo->_effects[1].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->_effects[1].BasePoints = 50;
    sinfo->_effects[1].BonusMultiplier = 1.0f;
    sinfo->_effects[1].DamageMultiplier = 0.5f;
    sinfo->_effects[1].DieSides = /*17*/25;
    sinfo->_effects[1].RealPointsPerLevel = 30.f;
    //sinfo->_effects[1].ValueMultiplier = 1.f;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_12_YARDS);
    //5) END SHADOW BLAST (SPLASH ATTACK)

    //6) SHADOW BOLT (BASE ATTACK)
    spellId = SPELL_SHADOW_BOLT1; //16408
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 60;
    sinfo->MaxLevel = 83;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->Attributes |= SPELL_ATTR0_HIDE_IN_COMBAT_LOG | SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->_effects[0].BasePoints = 200;
    sinfo->_effects[0].DieSides = /*12*/25;
    sinfo->_effects[0].BonusMultiplier = 1.15f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 10.f;
    //sinfo->_effects[0].ValueMultiplier = 1.f;
    //6) END SHADOW BOLT (BASE ATTACK)

    //7) ATTACK ANIMATION
    spellId = SPELL_ATTACK_MELEE_RANDOM; //42902
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->Attributes &= ~(SPELL_ATTR0_CANT_USED_IN_COMBAT);
    //7) END ATTACK ANIMATION

    //8) SPLASH ANIMATION
    spellId = SHADOWFURY_VISUAL; //48582
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //100 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->MaxAffectedTargets = 1;
    sinfo->Stances = 0;
    sinfo->Speed = 0.f;
    sinfo->Attributes |= SPELL_ATTR0_CASTABLE_WHILE_DEAD | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_DEAD | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_USABLE_WHILE_STUNNED | SPELL_ATTR5_USABLE_WHILE_CONFUSED | SPELL_ATTR5_USABLE_WHILE_FEARED;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].ValueMultiplier = 0.f;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].DamageMultiplier = 0.f;
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    //8) END SPLASH ANIMATION

    //9) DEVOUR MAGIC
    spellId = SPELL_DEVOUR_MAGIC; //17012
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RecoveryTime = 7000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(4); //1000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 100;
    sinfo->Attributes |= SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
    //sinfo->Attributes &= ~(SPELL_ATTR0_HIDE_IN_COMBAT_LOG);
    //sinfo->AttributesEx3 |= SPELL_ATTR3_DONT_DISPLAY_RANGE;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DISPEL;
    sinfo->_effects[0].BasePoints = 2;
    sinfo->_effects[0].MiscValue = DISPEL_MAGIC;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ALLY);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);

    sinfo->_effects[1].Effect = SPELL_EFFECT_DISPEL;
    sinfo->_effects[1].BasePoints = 2;
    sinfo->_effects[1].MiscValue = DISPEL_CURSE;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ALLY);
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);

    sinfo->_effects[2].Effect = SPELL_EFFECT_DISPEL;
    sinfo->_effects[2].BasePoints = 2;
    sinfo->_effects[2].MiscValue = DISPEL_MAGIC;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->_effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_20_YARDS);
    //9) END DEVOUR MAGIC

    //10) DRAIN MANA
    spellId = SPELL_DRAIN_MANA; //25755
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RecoveryTime = 0;//60000;
    //sinfo->PowerType = POWER_MANA;
    //sinfo->ManaCost = 0;
    //sinfo->ManaCostPercentage = 0;
    //sinfo->ManaCostPerlevel = 0;
    sinfo->Speed = 0.f;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(4); //1000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_POWER_DRAIN;
    sinfo->_effects[0].BasePoints = 999999;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);

    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //10) END DRAIN MANA

    //11) REPLENISH MANA
    spellId = SPELL_REPLENISH_MANA; //33394
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 0;
    sinfo->RecoveryTime = 3000;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->CategoryEntry = nullptr;
    sinfo->PowerType = POWER_MANA;
    sinfo->CastTimeEntry = nullptr;//sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->MaxAffectedTargets = 100;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_IS_REPLENISHMENT | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_DRAIN_ALL_POWER/* | SPELL_ATTR1_CANT_TARGET_SELF*/;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->_effects[0].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->_effects[0].BasePoints = 3;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].ValueMultiplier = 0.f;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].DamageMultiplier = 0.f;
    sinfo->_effects[0].TriggerSpell = SPELL_TRIGGERED_ENERGIZE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS);
    //11) END REPLENISH MANA

    //12) REPLENISH HEALTH
    spellId = SPELL_REPLENISH_HEALTH; //34756
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 0;
    sinfo->RecoveryTime = 3000;
    sinfo->CategoryEntry = nullptr;
    sinfo->PowerType = POWER_MANA;
    sinfo->CastTimeEntry = nullptr;//sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->MaxAffectedTargets = 100;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_IS_REPLENISHMENT | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_DRAIN_ALL_POWER/* | SPELL_ATTR1_CANT_TARGET_SELF*/;
    sinfo->AttributesEx &= ~(SPELL_ATTR1_CANT_TARGET_SELF);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->_effects[0].Effect = SPELL_EFFECT_TRIGGER_SPELL;
    sinfo->_effects[0].BasePoints = 3;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].ValueMultiplier = 0.f;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].DamageMultiplier = 0.f;
    sinfo->_effects[0].TriggerSpell = SPELL_TRIGGERED_HEAL;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ALLY);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_25_YARDS);
    //12) END REPLENISH HEALTH

    //ARCHMAGE
    //13) BRILLIANCE AURA
    spellId = SPELL_BRILLIANCE_AURA; //1234
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 0;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //0 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_PASSIVE;
    sinfo->AttributesEx4 |= SPELL_ATTR4_DONT_REMOVE_IN_ARENA;
    sinfo->AttributesEx7 |= SPELL_ATTR7_CONSOLIDATED_RAID_BUFF;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_POWER_REGEN_PERCENT;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].BasePoints = 100;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[1].BasePoints = 10;
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    //for stacking rule
    /*
    sinfo->_effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[2].BasePoints = 1;
    sinfo->_effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    */
    //13) END BRILLIANCE AURA

    //14) FIREBALL (MAIN_ATTACK)
    //TODO: balance
    spellId = SPELL_FIREBALL; //9488
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 81;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FIRE | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    //sinfo->MaxAffectedTargets = 1000;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_ABILITY | SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
    sinfo->Attributes &= ~(SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION);
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].BasePoints = 15;
    sinfo->_effects[0].DieSides = 9;
    sinfo->_effects[0].BonusMultiplier = 0.5f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 15.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    //14) END FIREBALL (MAIN ATTACK)

    //15) BLIZZARD
    //TODO: balance
    spellId = SPELL_BLIZZARD; //15783
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 0;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RecoveryTime = 6000;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    ///sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    //sinfo->MaxAffectedTargets = 1000;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_ABILITY | SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS | SPELL_ATTR2_UNK22;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_HASTE_AFFECT_DURATION;

    sinfo->_effects[0].BasePoints = 26;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 1.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 15.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_13_YARDS);
    sinfo->_effects[0].Amplitude = 1000;
    //15) END BLIZZARD

    //16) SUMMON WATER ELEMENTAL (dummy spell)
    spellId = SPELL_SUMMON_WATER_ELEMENTAL; //35593
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 0;
    sinfo->RecoveryTime = 20000;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 125 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    //sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    //16) END SUMMON WATER ELEMENTAL

    //17) WATERBOLT (MAIN_ATTACK)
    //TODO: balance, we only have 1 of 3 possible elementals so boost damage
    spellId = SPELL_WATERBOLT; //72898
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_GENERIC;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxTargetLevel = 0;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(5); //2000ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].BasePoints = 25;
    sinfo->_effects[0].DieSides = 20;
    sinfo->_effects[0].BonusMultiplier = 1.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 25.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    //17) END WATERBOLT (MAIN ATTACK)

    //DREADLORD
    //18) VAMPIRIC AURA
    spellId = SPELL_VAMPIRIC_AURA; //20810
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->ProcFlags = PROC_FLAG_DONE_MELEE_AUTO_ATTACK | PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //0 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_PASSIVE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED;
    sinfo->AttributesEx4 |= SPELL_ATTR4_DONT_REMOVE_IN_ARENA;
    sinfo->AttributesEx7 |= SPELL_ATTR7_CONSOLIDATED_RAID_BUFF;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_CRIT_DAMAGE_BONUS;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].BasePoints = 5;
    sinfo->_effects[0].MiscValue = SPELL_SCHOOL_MASK_NORMAL;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AREA_AURA_RAID;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_PROC_TRIGGER_SPELL;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[1].BasePoints = 1;
    sinfo->_effects[1].TriggerSpell = SPELL_TRIGGERED_HEAL;
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);

    //for stacking rule
    /*
    sinfo->_effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[2].BasePoints = 1;
    sinfo->_effects[2].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_YARDS);
    */
    //18) END VAMPIRIC AURA

    //19) VAMPIRIC HEAL
    spellId = SPELL_TRIGGERED_HEAL; //25155
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_DISABLE_PROC | SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED | SPELL_ATTR3_NO_DONE_BONUS;

    sinfo->_effects[0].BasePoints = 1;

    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //19) END VAMPIRIC HEAL

    //20) SLEEP
    spellId = SPELL_SLEEP; //20663
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_SLEEP;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RecoveryTime = 6000;
    //sinfo->StartRecoveryCategory = 133;
    //sinfo->StartRecoveryTime = 1000;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(3); //60000ms
    sinfo->ManaCost = 50 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_DIRECT_DAMAGE;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT | SPELL_ATTR0_HEARTBEAT_RESIST_CHECK);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    //sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_STUN;
    //sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    //sinfo->_effects[0].BasePoints = 1;

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_RESISTANCE_PCT;
    sinfo->_effects[1].MiscValue = SPELL_SCHOOL_MASK_NORMAL;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].BasePoints = -100;
    //20) END SLEEP

    //21) CARRION SWARM
    //TODO: balance
    spellId = SPELL_CARRION_SWARM; //34240
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->RecoveryTime = 10000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 110 * 5;
    //sinfo->MaxAffectedTargets = 1000;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT/* | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS*/;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CONE_ENEMY_104);
    sinfo->_effects[0].BasePoints = 425;
    sinfo->_effects[0].DieSides = 150;
    sinfo->_effects[0].BonusMultiplier = 2.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 37.5f; //2000 avg at 80
    sinfo->_effects[0].ValueMultiplier = 1.f;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);
    //21) END CARRION SWARM

    //22) INFERNO (dummy summon)
    spellId = SPELL_INFERNO; //12740
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RecoveryTime = 180000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 175 * 5;
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->Attributes &= ~(SPELL_ATTR0_ABILITY);
    sinfo->AttributesEx |= /*SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE | */SPELL_ATTR1_NO_THREAT;
    //sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    sinfo->_effects[0].BasePoints = 1;
    //22) END INFERNO

    //23) INFERNO VISUAL (dummy summon)
    spellId = SPELL_INFERNO_METEOR_VISUAL; //5739
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    //23) END INFERNO VISUAL

    //SPELL BREAKER
    //24) STEAL MAGIC
    spellId = SPELL_STEAL_MAGIC; //30036
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_PALADIN;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(34); //25 yds
    sinfo->RecoveryTime = 2000;
    sinfo->ManaCost = 75 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);

    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //24) END STEAL MAGIC

    //24.1) STEAL MAGIC VISUAL
    spellId = SPELL_STEAL_MAGIC_VISUAL; //11084
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellLevel = 1;
    sinfo->BaseLevel = 1;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //100 yds
    sinfo->RecoveryTime = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].BonusMultiplier = 0.f;
    //24.1) END STEAL MAGIC VISUAL

    //25) FEEDBACK
    spellId = SPELL_FEEDBACK; //32897
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_PALADIN;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(13); //50000 yds
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes &= ~(SPELL_ATTR0_NOT_SHAPESHIFT);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].Effect = SPELL_EFFECT_POWER_BURN;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    //25) END FEEDBACK

    // DARK RANGER
    //26) BLACK ARROW
    //TODO: balance
    spellId = SPELL_BLACK_ARROW; //20733
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_RANGED;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->Dispel = DISPEL_NONE;
    sinfo->Mechanic = MECHANIC_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //5-30 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 3000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 6 * 5 * 2; //need to increase cost since ability is not autocast, has cd and deals more damage
    sinfo->MaxAffectedTargets = 1;
    sinfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_CHANGE_MAP;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK | SPELL_ATTR0_NEGATIVE_1;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS/* | SPELL_ATTR2_CANT_CRIT*/;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;

    sinfo->_effects[1].Effect = SPELL_EFFECT_WEAPON_PERCENT_DAMAGE;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[1].BasePoints = 150;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].BonusMultiplier = 1.f;
    sinfo->_effects[1].DamageMultiplier = 1.f;
    sinfo->_effects[1].RealPointsPerLevel = 0.f;
    sinfo->_effects[1].ValueMultiplier = 1.f;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].RadiusEntry = nullptr;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    //sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    //sinfo->_effects[0].ApplyAuraName = SPELL_AURA_PERIODIC_DAMAGE;
    sinfo->_effects[0].BasePoints = 100;
    //sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 1.5f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 10.f;
    //sinfo->_effects[0].ValueMultiplier = 1.f;
    //sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].Amplitude = 2000;
    //26) END BLACK ARROW

    //27) DRAIN LIFE
    //TODO: balance
    spellId = SPELL_DRAIN_LIFE; //17238
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_MAGIC;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_SILENCE;
    sinfo->Dispel = DISPEL_NONE;
    sinfo->Mechanic = MECHANIC_NONE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    //sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 5000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 75 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->AuraInterruptFlags = 0x0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO | SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;
    sinfo->AttributesEx5 |= SPELL_ATTR5_START_PERIODIC_AT_APPLY;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_PERIODIC_LEECH;
    sinfo->_effects[0].BasePoints = 45;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 1.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 6.f;
    sinfo->_effects[0].ValueMultiplier = 2.f;
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].Amplitude = 1000;
    //27) END DRAIN LIFE

    //28) SILENCE
    //TODO: balance
    spellId = SPELL_SILENCE; //29943
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_SILENCE;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_SILENCE;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->MaxTargetLevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(2); //250ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    //sinfo->DurationEntry = sSpellDurationStore.LookupEntry(85); //18 sec
    sinfo->RecoveryTime = 15000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 75 * 5;
    sinfo->MaxAffectedTargets = 5;
    sinfo->AuraInterruptFlags = 0x0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT | TARGET_FLAG_DEST_LOCATION;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_DEST_AREA_ENEMY);
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_SILENCE;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_15_YARDS);
    //28) END SILENCE

    // NECROMANCER
    //29) SHADOW BOLT (MAIN_ATTACK)
    //TODO: balance
    spellId = SPELL_SHADOW_BOLT2; //17509
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxLevel = 82;
    sinfo->ManaCost = 0;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->CastTimeEntry = nullptr;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;

    sinfo->_effects[0].BasePoints = 15;
    sinfo->_effects[0].DieSides = 9;
    sinfo->_effects[0].BonusMultiplier = 0.75f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 8.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    //29) END SHADOW BOLT (MAIN_ATTACK)

    //30) RAISE DEAD
    spellId = SPELL_RAISE_DEAD; //34011
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->MaxTargetLevel = 0;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(34); //25 yds
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(3); //500ms
    sinfo->RecoveryTime = 8000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 50 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_CORPSE_ENEMY;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    sinfo->_effects[2].Effect = SPELL_EFFECT_NONE;
    //30) END RAISE DEAD

    //31) UNHOLY FRENZY
    spellId = SPELL_UNHOLY_FRENZY; //52499
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->SpellLevel = 30;
    sinfo->BaseLevel = 30;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(22); //566 - 0 sec //3 - 60 sec //1 - 10 sec //32 - 6 sec //22 - 45 sec
    sinfo->RecoveryTime = 2000; //original 1000
    sinfo->CategoryEntry = nullptr;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 50 * 5;
    sinfo->ManaCostPercentage = 0;
    sinfo->ManaCostPerlevel = 0;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;

    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_ATTACKSPEED;
    sinfo->_effects[0].BasePoints = 75;
    sinfo->_effects[1].Amplitude = 3000;
    sinfo->_effects[1].BasePoints = 1;
    //31) END UNHOLY FRENZY

    //32) CRIPPLE
    spellId = SPELL_CRIPPLE; //50379
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->Dispel = DISPEL_CURSE; //TODO: check if works
    sinfo->SpellLevel = 50;
    sinfo->BaseLevel = 50;
    sinfo->MaxLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(0); //0ms
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(3); //60 sec
    sinfo->RecoveryTime = 10000;
    sinfo->CategoryEntry = nullptr;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 175 * 5;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    //32) END CRIPPLE

    //33) CORPSE EXPLOSION
    spellId = SPELL_CORPSE_EXPLOSION; //61614
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARLOCK;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_NONE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->TargetCreatureType = 0x0000037F;
    sinfo->InterruptFlags = 0xF;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(21); //-1
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(110); //750ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(3); //20 yds
    sinfo->RecoveryTime = 1500;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 100 * 5;
    sinfo->ExplicitTargetMask = TARGET_FLAG_CORPSE_ENEMY;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
    sinfo->_effects[0].SpellClassMask[0] = 0;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //33) END CORPSE EXPLOSION

    //SEA WITCH
    //35) FORKED LIGHTNING
    spellId = SPELL_FORKED_LIGHTNING; //63541
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_SILENCE;
    sinfo->InterruptFlags = 0x9;
    sinfo->SpellLevel = 4;
    sinfo->BaseLevel = 4;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(110); //750ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->RecoveryTime = 11000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 110 * 5;
    sinfo->MaxAffectedTargets = 2;
    sinfo->Speed = 1000.f;
    sinfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    //sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;

    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CONE_ENEMY_24);
    //sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_CONE_ENEMY_24);
    sinfo->_effects[0].RadiusEntry = nullptr;//sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_50_YARDS);
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].DieSides = 49;
    sinfo->_effects[0].BonusMultiplier = 0.0f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 15.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    //35) END FORKED LIGHTNING

    //36) FORKED LIGHTNING EFFECT
    spellId = SPELL_FORKED_LIGHTNING_EFFECT; //50900
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_STUN;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(39); //2000ms
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //instant
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(6); //100 yds
    sinfo->ManaCost = 0;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_DONT_TURN_DURING_CAST;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CAN_TARGET_INVISIBLE;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_STUN;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].RadiusEntry = nullptr;
    //36) END FORKED LIGHTNING EFFECT

    //37) FROST ARROW
    spellId = SPELL_FROST_ARROW; //38942
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_RANGED;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->Dispel = DISPEL_NONE;
    sinfo->Mechanic = MECHANIC_NONE;
    sinfo->SpellLevel = 4;
    sinfo->BaseLevel = 4;
    sinfo->MaxTargetLevel = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(110); //750ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(35); //0-35 yds
    sinfo->DurationEntry = nullptr;
    sinfo->RecoveryTime = 0;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 750;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 10 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->AuraInterruptFlags = AURA_INTERRUPT_FLAG_CHANGE_MAP;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
    sinfo->Attributes &= ~(SPELL_ATTR0_REQ_AMMO);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS/* | SPELL_ATTR2_CANT_CRIT*/;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;

    sinfo->_effects[0].Effect = SPELL_EFFECT_WEAPON_DAMAGE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].BasePoints = 10;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 0.5f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 2.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //37) END FROST ARROW

    //38) FROST ARROW EFFECT
    spellId = SPELL_FROST_ARROW_EFFECT; //56095
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_GENERIC;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_FROST | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_SNARE;
    sinfo->Attributes &= ~(SPELL_ATTR0_CAST_TRACK_TARGET);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx4 |= SPELL_ATTR4_IGNORE_RESISTANCES;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_SPEED_SLOW_ALL;
    sinfo->_effects[0].Mechanic = MECHANIC_SLOW_ATTACK;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].BasePoints = -30;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 1.f;
    sinfo->_effects[0].DamageMultiplier = 1.f;
    sinfo->_effects[0].RealPointsPerLevel = 0.f;
    sinfo->_effects[0].ValueMultiplier = 1.f;
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_DECREASE_SPEED;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[1].BasePoints = -30;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].BonusMultiplier = 1.f;
    sinfo->_effects[1].DamageMultiplier = 1.f;
    sinfo->_effects[1].RealPointsPerLevel = 0.f;
    sinfo->_effects[1].ValueMultiplier = 1.f;
    sinfo->_effects[1].RadiusEntry = nullptr;
    //38) END FROST ARROW EFFECT

    //39) MANA SHIELD
    spellId = SPELL_MANA_SHIELD; //35064
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->Dispel = DISPEL_NONE;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(21); //-1
    sinfo->RecoveryTime = 10000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_DISABLED_WHILE_ACTIVE;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx4 |= SPELL_ATTR4_NOT_STEALABLE;

    sinfo->_effects[0].BasePoints = 1000000000;
    sinfo->_effects[0].ValueMultiplier = 10.f;
    //39) END MANA SHIELD

    //40) TORNADO
    spellId = SPELL_TORNADO; //34695
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->InterruptFlags = 0x9;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = nullptr;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(15); //4000ms
    //sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->RecoveryTime = 120000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->ManaCost = 250 * 5;
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_OUTDOORS_ONLY;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx3 &= ~(SPELL_ATTR3_ONLY_TARGET_PLAYERS);
    sinfo->AttributesEx4 = 0;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].TriggerSpell = 0;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    //40) END TORNADO

    //41) TORNADO EFFECT
    spellId = SPELL_TORNADO_EFFECT; //21990
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->Dispel = DISPEL_MAGIC;
    sinfo->Mechanic = MECHANIC_NONE; //MECHANIC_KNOCKOUT
    sinfo->InterruptFlags = 0x0;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(29); //12000ms
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(2); //5 yds
    sinfo->RecoveryTime = 3000;
    //sinfo->StartRecoveryCategory = 133;
    //sinfo->StartRecoveryTime = 1500;
    //sinfo->ManaCost = 250 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_OUTDOORS_ONLY;
    sinfo->Attributes &= ~(SPELL_ATTR0_HEARTBEAT_RESIST_CHECK);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT | SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_DONE_BONUS;
    sinfo->AttributesEx3 &= ~(SPELL_ATTR3_ONLY_TARGET_PLAYERS);
    sinfo->AttributesEx4 = 0;
    sinfo->AttributesEx5 = 0;

    //sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    //sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    //sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    //sinfo->_effects[0].RadiusEntry = nullptr;
    //sinfo->_effects[0].BasePoints = 1;
    //sinfo->_effects[0].TriggerSpell = 0;
    //sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_RESISTANCE_PCT;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].BasePoints = -100;
    sinfo->_effects[1].MiscValue = SPELL_SCHOOL_MASK_ALL;
    sinfo->_effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_PERIODIC_DAMAGE;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[2].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[2].BasePoints = 212;
    sinfo->_effects[2].DieSides = 183;
    sinfo->_effects[2].RealPointsPerLevel = 35.f;
    sinfo->_effects[2].BonusMultiplier = 0.25f;
    sinfo->_effects[2].Amplitude = 1500;
    //41) END TORNADO EFFECT

    //42) TORNADO EFFECT2
    spellId = SPELL_TORNADO_EFFECT2; //34683
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    //sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->Dispel = DISPEL_MAGIC;
    //sinfo->Mechanic = MECHANIC_DISORIENTED;
    sinfo->ProcFlags = 0;
    sinfo->InterruptFlags = 0x0;
    sinfo->SpellLevel = 60;
    sinfo->BaseLevel = 60;
    sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = nullptr;
    //sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(7); //10 yds
    sinfo->RecoveryTime = 4500;
    //sinfo->StartRecoveryCategory = 133;
    //sinfo->StartRecoveryTime = 1500;
    //sinfo->ManaCost = 250 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_OUTDOORS_ONLY;
    sinfo->Attributes &= ~(SPELL_ATTR0_UNK11);
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx4 = 0;
    sinfo->AttributesEx5 = 0;

    sinfo->_effects[0].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    //sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_10_YARDS);
    sinfo->_effects[0].BasePoints = 541;
    sinfo->_effects[0].DieSides = 215;
    sinfo->_effects[0].RealPointsPerLevel = 40.f;
    sinfo->_effects[0].BonusMultiplier = 0.5f;
    //42) END TORNADO EFFECT2

    //43) TORNADO EFFECT3
    spellId = SPELL_TORNADO_EFFECT3; //39261
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    //sinfo->SpellFamilyFlags[0] = 0x0;
    //sinfo->SpellFamilyFlags[1] = 0x4; //custom, not present in db
    //sinfo->SpellFamilyFlags[2] = 0x0;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_NATURE | SPELL_SCHOOL_MASK_ARCANE;
    //sinfo->Dispel = DISPEL_NONE;
    //sinfo->Mechanic = MECHANIC_DISORIENTED;
    //sinfo->ProcFlags = 0;
    //sinfo->InterruptFlags = 0x0;
    sinfo->SpellLevel = 0;
    sinfo->BaseLevel = 0;
    //sinfo->MaxTargetLevel = 0;
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(21); //-1
    //sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0ms
    //sinfo->RangeEntry = sSpellRangeStore.LookupEntry(1); //self
    //sinfo->RecoveryTime = 4500;
    //sinfo->StartRecoveryCategory = 133;
    //sinfo->StartRecoveryTime = 1500;
    //sinfo->ManaCost = 250 * 5;
    //sinfo->MaxAffectedTargets = 1;
    //sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_OUTDOORS_ONLY;
    sinfo->AttributesEx |= SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx4 = 0;
    sinfo->AttributesEx5 = 0;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AREA_AURA_ENEMY;
    //sinfo->_effects[0].ApplyAuraName = SPELL_AURA_MOD_DECREASE_SPEED;
    //sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    //sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENEMY);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_5_YARDS);
    //sinfo->_effects[0].BasePoints = -50;
    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AREA_AURA_ENEMY;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_DECREASE_SPEED;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENEMY);
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_5_YARDS);
    sinfo->_effects[1].BasePoints = -60;
    //sinfo->AttributesCu &= ~(SPELL_ATTR0_CU_NEGATIVE_EFF1);
    //43) END TORNADO EFFECT3

    //44) SHOOT
    spellId = SPELL_SHOOT_BOW; //41188
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_MAGE;
    sinfo->DmgClass = SPELL_DAMAGE_CLASS_RANGED;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->SpellLevel = 1;
    sinfo->BaseLevel = 1;
    sinfo->CategoryEntry = sSpellCategoryStore.LookupEntry(76);
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(110); //750ms
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(35); //0-35 yds
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 750;
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK/* | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE*/;
    sinfo->Attributes &= ~(SPELL_ATTR0_REQ_AMMO/* | SPELL_ATTR0_ABILITY*/ | SPELL_ATTR0_CAST_TRACK_TARGET | SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION | SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY);
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_CANT_BE_REFLECTED;
    sinfo->AttributesEx &= ~(SPELL_ATTR1_CHANNEL_TRACK_TARGET | SPELL_ATTR1_NO_THREAT);
    sinfo->AttributesEx2 |= SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS;
    sinfo->AttributesEx2 &= ~(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS);
    sinfo->AttributesEx3 |= SPELL_ATTR3_UNK15;

    sinfo->_effects[0].Effect = SPELL_EFFECT_WEAPON_PERCENT_DAMAGE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].BasePoints = 100;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].BonusMultiplier = 1.f;
    //44) END SHOOT

    //CRYPT LORD
    //45) IMPALE
    spellId = SPELL_IMPALE; //53458
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->CategoryEntry = nullptr;
    sinfo->RecoveryTime = 9000;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 100 * 5;
    sinfo->MaxAffectedTargets = 0;
    sinfo->InterruptFlags = 0x1;
    sinfo->ChannelInterruptFlags = 0x0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(5); //40 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(592); //400ms
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_ABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_CHANNELED_2 | SPELL_ATTR1_CHANNEL_TRACK_TARGET | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CONE_ENEMY_24);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_40_YARDS);
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_SRC_CASTER);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(TARGET_UNIT_SRC_AREA_ENEMY);
    sinfo->_effects[1].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_8_YARDS);
    sinfo->_effects[1].MiscValue = 0;
    sinfo->_effects[1].MiscValueB = 0;
    sinfo->_effects[1].BasePoints = 1;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].RealPointsPerLevel = 0.0f;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].DamageMultiplier = 0.0f;
    sinfo->_effects[1].BonusMultiplier = 0.0f;
    //45) END IMPALE

    //46) IMPALE DAMAGE
    spellId = SPELL_IMPALE_DAMAGE; //53454
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->CategoryEntry = nullptr;
    sinfo->RecoveryTime = 0;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->StartRecoveryCategory = 0;
    sinfo->StartRecoveryTime = 0;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 0;
    sinfo->MaxAffectedTargets = 1;
    sinfo->ChannelInterruptFlags = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(36); //45 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(32); //6000ms
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT_ENEMY;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_CASTABLE_WHILE_DEAD | SPELL_ATTR0_CASTABLE_WHILE_SITTING;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx5 |= SPELL_ATTR5_USABLE_WHILE_STUNNED;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE | SPELL_ATTR6_CAN_TARGET_INVISIBLE;

    sinfo->_effects[0].Effect = SPELL_EFFECT_SCHOOL_DAMAGE;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].BasePoints = 150;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].RealPointsPerLevel = 35.0f;
    sinfo->_effects[0].DieSides = 200;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;

    sinfo->_effects[1].Effect = SPELL_EFFECT_KNOCK_BACK;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].RadiusEntry = nullptr;
    sinfo->_effects[1].Mechanic = MECHANIC_KNOCKOUT;
    sinfo->_effects[1].MiscValue = 5;
    sinfo->_effects[1].MiscValueB = 0;
    sinfo->_effects[1].BasePoints = 180;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].RealPointsPerLevel = 0.0;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].DamageMultiplier = 0.0f;
    sinfo->_effects[1].BonusMultiplier = 0.0f;

    sinfo->_effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_MOD_STUN;
    //sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    //sinfo->_effects[2].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[2].TargetA = sinfo->_effects[0].TargetA;
    sinfo->_effects[2].TargetB = sinfo->_effects[0].TargetB;
    sinfo->_effects[2].RadiusEntry = nullptr;
    sinfo->_effects[2].Mechanic = MECHANIC_NONE;
    sinfo->_effects[2].MiscValue = 0;
    sinfo->_effects[2].MiscValueB = 0;
    sinfo->_effects[2].BasePoints = 1;
    sinfo->_effects[2].Amplitude = 0;
    sinfo->_effects[2].RealPointsPerLevel = 0.0;
    sinfo->_effects[2].DieSides = 0;
    sinfo->_effects[2].DamageMultiplier = 0.0f;
    sinfo->_effects[2].BonusMultiplier = 0.0f;
    //46) END IMPALE DAMAGE

    //47) IMPALE VISUAL
    spellId = SPELL_IMPALE_VISUAL; //53454
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_NONE;
    sinfo->SpellLevel = 20;
    sinfo->BaseLevel = 20;
    sinfo->CategoryEntry = nullptr;
    sinfo->RecoveryTime = 0;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->StartRecoveryCategory = 0;
    sinfo->StartRecoveryTime = 0;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 0;
    sinfo->MaxAffectedTargets = 1;
    sinfo->ChannelInterruptFlags = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(36); //45 yds
    sinfo->ExplicitTargetMask = TARGET_FLAG_DEST_LOCATION;
    sinfo->Attributes |= SPELL_ATTR0_ABILITY | SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE | SPELL_ATTR0_CASTABLE_WHILE_DEAD | SPELL_ATTR0_CASTABLE_WHILE_SITTING;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
    sinfo->AttributesEx3 |= SPELL_ATTR3_IGNORE_HIT_RESULT | SPELL_ATTR3_NO_INITIAL_AGGRO;
    sinfo->AttributesEx5 |= SPELL_ATTR5_USABLE_WHILE_STUNNED;
    sinfo->AttributesEx6 |= SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE | SPELL_ATTR6_CAN_TARGET_INVISIBLE;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_DEST_DEST);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = sSpellRadiusStore.LookupEntry(EFFECT_RADIUS_0_5_YARDS);
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;

    sinfo->_effects[1].Effect = SPELL_EFFECT_NONE;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].RadiusEntry = nullptr;
    sinfo->_effects[1].MiscValueB = 0;
    sinfo->_effects[1].BasePoints = 0;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].RealPointsPerLevel = 0.0;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].DamageMultiplier = 0.0f;
    sinfo->_effects[1].BonusMultiplier = 0.0f;
    //47) END IMPALE VISUAL

    //48) CARRION BEETLES
    spellId = SPELL_CARRION_BEETLES; //53520
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->SpellLevel = 10;
    sinfo->BaseLevel = 10;
    sinfo->RecoveryTime = 6000;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 50 * 5;
    sinfo->MaxAffectedTargets = 1;
    sinfo->InterruptFlags = 0x1;
    sinfo->ChannelInterruptFlags = 0x100C;
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(327); //500ms // (36); // 1000ms // (327); //500ms
    sinfo->ExplicitTargetMask = TARGET_FLAG_CORPSE_ENEMY;
    sinfo->Attributes |= SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_ABILITY;
    sinfo->AttributesEx |= SPELL_ATTR1_CHANNEL_TRACK_TARGET;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CAN_TARGET_DEAD;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ANY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].Amplitude = 500;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;
    //48) END CARRION BEETLES

    //49) LOCUST SWARM
    spellId = SPELL_LOCUST_SWARM; //28785
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->CategoryEntry = nullptr;
    sinfo->RecoveryTime = 180000;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->StartRecoveryCategory = 133;
    sinfo->StartRecoveryTime = 1500;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 50 * 5;
    sinfo->MaxAffectedTargets = 0;
    sinfo->StackAmount = 0;
    sinfo->InterruptFlags = 0x1;
    sinfo->ChannelInterruptFlags = 0x100C;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(4); //30 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(35); //4000ms
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_HIDDEN_CLIENTSIDE | SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_CHANNELED_2 | SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR | SPELL_ATTR1_NO_THREAT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_INITIAL_AGGRO;

    sinfo->_effects[0].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_DUMMY;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_CASTER);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].TriggerSpell = 0;
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].BasePoints = 1;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].DieSides = 0;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;

    for (uint8 i = EFFECT_1; i < MAX_SPELL_EFFECTS; ++i)
    {
        sinfo->_effects[i].Effect = SPELL_EFFECT_NONE;
        sinfo->_effects[i].ApplyAuraName = SPELL_AURA_NONE;
        sinfo->_effects[i].TargetA = SpellImplicitTargetInfo(0);
        sinfo->_effects[i].TargetB = SpellImplicitTargetInfo(0);
        sinfo->_effects[i].RadiusEntry = nullptr;
        sinfo->_effects[i].MiscValue = 0;
        sinfo->_effects[i].MiscValueB = 0;
        sinfo->_effects[i].BasePoints = 0;
        sinfo->_effects[i].Amplitude = 0;
        sinfo->_effects[i].RealPointsPerLevel = 0.0f;
        sinfo->_effects[i].DieSides = 0;
        sinfo->_effects[i].DamageMultiplier = 0.0f;
        sinfo->_effects[i].BonusMultiplier = 0.0f;
    }
    //49) END LOCUST SWARM

    //50) SOUL BITE
    spellId = SPELL_SOUL_BITE; //11016
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SpellFamilyName = SPELLFAMILY_WARRIOR;
    sinfo->PreventionType = SPELL_PREVENTION_TYPE_PACIFY;
    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW | SPELL_SCHOOL_MASK_ARCANE;
    sinfo->SpellLevel = 40;
    sinfo->BaseLevel = 40;
    sinfo->CategoryEntry = nullptr;
    sinfo->RecoveryTime = 0;
    sinfo->CategoryRecoveryTime = 0;
    sinfo->StartRecoveryCategory = 0;
    sinfo->StartRecoveryTime = 0;
    sinfo->PowerType = POWER_MANA;
    sinfo->ManaCost = 0;
    sinfo->MaxAffectedTargets = 0;
    sinfo->StackAmount = 10;
    sinfo->ChannelInterruptFlags = 0;
    sinfo->CastTimeEntry = sSpellCastTimesStore.LookupEntry(1); //0
    sinfo->RangeEntry = sSpellRangeStore.LookupEntry(11); //15 yds
    sinfo->DurationEntry = sSpellDurationStore.LookupEntry(568); // 1250ms // (36); //1000ms
    sinfo->ExplicitTargetMask = TARGET_FLAG_UNIT;
    sinfo->Attributes |= SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
    sinfo->AttributesEx |= SPELL_ATTR1_CANT_BE_REFLECTED | SPELL_ATTR1_CANT_BE_REDIRECTED;
    sinfo->AttributesEx2 |= SPELL_ATTR2_CANT_CRIT;
    sinfo->AttributesEx3 |= SPELL_ATTR3_NO_DONE_BONUS | SPELL_ATTR3_IGNORE_HIT_RESULT;
    sinfo->AttributesEx4 |= SPELL_ATTR4_FIXED_DAMAGE;
    sinfo->AttributesCu &= ~(SPELL_ATTR0_CU_CAN_CRIT);

    sinfo->_effects[0].Effect = SPELL_EFFECT_HEALTH_LEECH;
    sinfo->_effects[0].ApplyAuraName = SPELL_AURA_NONE;
    sinfo->_effects[0].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[0].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[0].RadiusEntry = nullptr;
    sinfo->_effects[0].MiscValue = 0;
    sinfo->_effects[0].MiscValueB = 0;
    sinfo->_effects[0].BasePoints = 10;
    sinfo->_effects[0].Amplitude = 0;
    sinfo->_effects[0].RealPointsPerLevel = 0.0f;
    sinfo->_effects[0].DieSides = 25;
    sinfo->_effects[0].DamageMultiplier = 0.0f;
    sinfo->_effects[0].ValueMultiplier = 0.0f;
    sinfo->_effects[0].BonusMultiplier = 0.0f;

    sinfo->_effects[1].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[1].ApplyAuraName = SPELL_AURA_MOD_PACIFY_SILENCE;
    sinfo->_effects[1].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[1].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[1].RadiusEntry = nullptr;
    sinfo->_effects[1].MiscValue = 0;
    sinfo->_effects[1].MiscValueB = 0;
    sinfo->_effects[1].BasePoints = 1;
    sinfo->_effects[1].Amplitude = 0;
    sinfo->_effects[1].RealPointsPerLevel = 0.0f;
    sinfo->_effects[1].DieSides = 0;
    sinfo->_effects[1].DamageMultiplier = 0.0f;
    sinfo->_effects[1].ValueMultiplier = 0.0f;
    sinfo->_effects[1].BonusMultiplier = 0.0f;

    sinfo->_effects[2].Effect = SPELL_EFFECT_APPLY_AURA;
    sinfo->_effects[2].ApplyAuraName = SPELL_AURA_MOD_DECREASE_SPEED;
    sinfo->_effects[2].TargetA = SpellImplicitTargetInfo(TARGET_UNIT_TARGET_ENEMY);
    sinfo->_effects[2].TargetB = SpellImplicitTargetInfo(0);
    sinfo->_effects[2].Mechanic = MECHANIC_SNARE;
    sinfo->_effects[2].RadiusEntry = nullptr;
    sinfo->_effects[2].MiscValue = 0;
    sinfo->_effects[2].MiscValueB = 0;
    sinfo->_effects[2].BasePoints = -3;
    sinfo->_effects[2].Amplitude = 0;
    sinfo->_effects[2].RealPointsPerLevel = 0.0f;
    sinfo->_effects[2].DieSides = 0;
    sinfo->_effects[2].DamageMultiplier = 0.0f;
    sinfo->_effects[2].ValueMultiplier = 0.0f;
    sinfo->_effects[2].BonusMultiplier = 0.0f;
    //50) END SOUL BITE

    //51) ENERGIZE VISUAL
    spellId = SPELL_ENERGIZE_VISUAL; //59198
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);

    sinfo->SchoolMask = SPELL_SCHOOL_MASK_SHADOW;
    sinfo->SpellLevel = 1;
    sinfo->BaseLevel = 1;

    sinfo->_effects[0].Effect = SPELL_EFFECT_DUMMY;
    sinfo->_effects[0].BasePoints = 0;
    sinfo->_effects[0].DieSides = 0;
    //51) END ENERGIZE VISUAL

    //XX) FIXES
    spellId = 48155; // Mind Flay (Rank 8)
    botSpellInfoOverrides.insert({ spellId, *sSpellMgr->GetSpellInfo(spellId) });
    sinfo = &botSpellInfoOverrides.at(spellId);
    sinfo->InterruptFlags &= SPELL_INTERRUPT_FLAG_MOVEMENT;

    for (auto& p : botSpellInfoOverrides)
    {
        for (auto& eff : p.second._effects)
        {
            eff.OverrideSpellInfo(&p.second);
        }
    }

    TC_LOG_INFO("server.loading", ">> Bot spellInfo overrides generated for {} spells", uint32(botSpellInfoOverrides.size()));

    GenerateBotCustomSpellProcs();
}
