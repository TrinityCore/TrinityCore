ALTER TABLE `spelleffect_dbc`
    CHANGE `EffectValueMultiplier` `EffectAmplitude` FLOAT UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectApplyAuraName` `EffectAura` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectAmplitude` `EffectAuraPeriod` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectBonusMultiplier` `EffectBonusCoefficient` FLOAT UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectDamageMultiplier` `EffectChainAmplitude` FLOAT UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectChainTarget` `EffectChainTargets` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    ADD COLUMN `EffectPointsPerResource` FLOAT UNSIGNED NOT NULL AFTER `EffectMiscValueB`,
    CHANGE `EffectRadiusIndexMax` `EffectRadiusMaxIndex` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectSpellId` `SpellID` INT(10) UNSIGNED NOT NULL;
