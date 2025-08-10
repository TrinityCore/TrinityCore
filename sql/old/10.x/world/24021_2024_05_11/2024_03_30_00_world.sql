DELIMITER ;;
CREATE PROCEDURE creature_health_2024_03_30_00_world() BEGIN
    IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='creature' AND `column_name`='curHealthPct') THEN
  
    ALTER TABLE `creature` 
        CHANGE COLUMN `curhealth` `curHealthPct` INT UNSIGNED NOT NULL DEFAULT 100,
        DROP COLUMN `curmana`;

    END IF;
END;;

DELIMITER ;
CALL creature_health_2024_03_30_00_world();

DROP PROCEDURE IF EXISTS creature_health_2024_03_30_00_world;

UPDATE `creature` c
INNER JOIN `creature_template` ct ON c.`id`=ct.`entry`
SET c.`curHealthPct`=100
WHERE ct.`RegenHealth`=1;

-- Spells
DELETE FROM `serverside_spell` WHERE `Id` IN (86562);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(86562, 0, 0, 0, 0, 384, 268435456, 0, 0, 128, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, '1 Health', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

UPDATE `serverside_spell` SET `AttributesEx4`=128, `AttributesEx5`=8, `ProcChance`=0 WHERE `Id` IN (24931, 24959, 28838, 73342);
UPDATE `serverside_spell` SET `Attributes`=384, `DurationIndex`=0 WHERE `Id` IN (24931, 24959);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (24931, 24959, 43645, 73342, 86562);
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(24931, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(24959, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(43645, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(73342, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(86562, 0, 0, 77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_set_health_1', 'spell_gen_set_health_100', 'spell_gen_set_health_500');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24931, 'spell_gen_set_health_100'),
(24959, 'spell_gen_set_health_500'),
(28838, 'spell_gen_set_health_1'),
(43645, 'spell_gen_set_health_1'),
(73342, 'spell_gen_set_health_1'),
(86562, 'spell_gen_set_health_1');

-- Special cases
UPDATE `creature` SET `curHealthPct`=100 WHERE `id` IN (6172, 6177, 16601, 26335);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (16601, 26335);

UPDATE `smart_scripts` SET `id`=2 WHERE `entryorguid` IN (6172,6177) AND `source_type`=0 AND `id`=1 AND `event_type`=8;
UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid` IN (6172,6177) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16601, 26335) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6172,6177) AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(6172,0,1,0,61,0,100,0,0,0,0,0,0,'',11,28838,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Henze Faulk - Event linked - Cast ''1 Health'''),
(6177,0,1,0,61,0,100,0,0,0,0,0,0,'',11,28838,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Narm Faulk - Event linked - Cast ''1 Health'''),
(16601,0,0,0,25,0,100,0,0,0,0,0,0,'',11,28838,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Dying Blood Elf - On reset - Cast ''1 Health'''),
(26335,0,0,0,25,0,100,0,0,0,0,0,0,'',11,43645,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Fallen Earthen Warrior - On reset - Cast ''1 Health''');

UPDATE `creature` SET `curHealthPct`=100 WHERE `id` IN (4510,7604,7605,7606,7607,7608,18192,18256,25063,27894,28781,30236,34775,34776,34793,34802,34929,34935,34944,35069,35273);
UPDATE `creature` SET `curHealthPct`=10 WHERE `id` IN (16483,149917,166800);
UPDATE `creature` SET `curHealthPct`=20 WHERE `id` IN (44617,44795,44857,50047,156609,156610,156612,156622);
UPDATE `creature` SET `curHealthPct`=30 WHERE `id` IN (13020,25661,30035,31273,31304,166784);
UPDATE `creature` SET `curHealthPct`=40 WHERE `id` IN (18708,20869,166791);
UPDATE `creature` SET `curHealthPct`=50 WHERE `id` IN (166786,166796);
UPDATE `creature` SET `curHealthPct`=60 WHERE `id` IN (12423,12427,12428,12429,12430,17551);

DELETE FROM `creature` WHERE `guid`=137747 AND `id`=36789;
UPDATE `creature` SET `spawnDifficulties`='3,4,5,6', `curHealthPct`=50 WHERE `id`=36789;
