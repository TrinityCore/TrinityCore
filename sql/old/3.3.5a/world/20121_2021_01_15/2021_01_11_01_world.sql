-- North Sea Shark
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `dynamicflags` = 0 WHERE `entry` = 35324;

-- Slain Outrunner
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 17849);
UPDATE `creature_template_addon` SET `bytes1` = 0, `auras` = "29266" WHERE `entry` = 17849;
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = 768, `dynamicflags` = 0 WHERE `entry` = 17849;

-- Broken Corpse
UPDATE `creature_template_addon` SET `auras` = "32423 29266 32900" WHERE `entry` = 18480;
UPDATE `creature_template` SET `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` &~ (536870912|262144), `unit_flags2` = 0, `dynamicflags` = 0 WHERE `entry` = 18480;

-- Fallen Druid
-- Auras are static, not random. The reason why those models are not shown anymore is because someone broke something after WotLK
-- https://youtu.be/3idWf8-3MeQ?t=206
UPDATE `creature_template` SET `unit_flags` = 33536, `unit_flags2` = `unit_flags2` &~ 1 WHERE `entry` = 18490;
DELETE FROM `creature_template_addon` WHERE `entry` = 18490;
DELETE FROM `creature_addon` WHERE `guid` IN (84675,84693,84690,84696,84695,84694,84676,84687,84681,84677,84672,84670,84671,84673,84674,84678,84679,84680,84682,84683,84684,84685,84686);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(84675,'32423 29266'),
(84693,'32423 29266'),
(84690,'32423 29266'),
(84696,'32423 29266'),
(84695,'32423 29266'),
(84694,'32423 29266'),
(84676,'32423 29266'),
(84687,'32423 29266'),
(84681,'32423 29266'),
(84677,'32423 29266'),
(84672,'32423 29266'),
(84670,'32423 32447 29266 5419'),
(84671,'32423 32447 29266 5419'),
(84673,'32423 32447 29266 5419'),
(84674,'32423 32447 29266 5419'),
(84678,'32423 32447 29266 5419'),
(84679,'32423 32447 29266 5419'),
(84680,'32423 32447 29266 5419'),
(84682,'32423 32447 29266 5419'),
(84683,'32423 32447 29266 5419'),
(84684,'32423 32447 29266 5419'),
(84685,'32423 32447 29266 5419'),
(84686,'32423 32447 29266 5419');

-- Cooling Infernal
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags` = 0 WHERE `entry` = 19760;
UPDATE `creature` SET `unit_flags` = 33554432+256 WHERE `id` = 19760 AND `guid` IN (84620,84621);
DELETE FROM `creature_addon` WHERE `guid` IN (84620,84621,147174);
INSERT INTO `creature_addon` (`guid`,`auras`) VALUES
(84620,'29266'),
(84621,'31261 12743'), -- don't know why, he's 'dead', anyway does not work probably because of 31261
(147174,'12743');
DELETE FROM `creature` WHERE `guid` = 147174 AND `id` = 19760;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(147174, 19760, 530, 1, 1, 0, 0, -3557.400146484375, 2137.167236328125, 23.63074111938476562, 4.96514749526977539, 300, 5, 1, 14545);

-- 12743, does not exists in 2xx or 3xx, exists in 1xx and 4xx+
-- No icon, so purely serverside https://youtu.be/vsAkJjV7oi4?t=377
DELETE FROM `spell_dbc` WHERE `Id` = 12743;
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectItemType1`, `EffectItemType2`, `EffectItemType3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `SpellName`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`) VALUES
(12743,1,0,524288,0,0,0,0,0,0,0,0,0,0,1,0,0,101,0,0,0,0,21,1,0,-1,-1,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,23,0,0,3000,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12744,0,0,0,0,0,0,0,0,0,0,0,'Immolation',0,0,0,0,0,0,0,0,1,1,1,0,4);

-- Fallen Vindicator & Kaylaan
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` = 20922;
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 20922;
UPDATE `creature` SET `position_x` = 4034.83203125, `position_y` = 3545.646728515625, `position_z` = 121.4790878295898437, `orientation` = 2.670353651046752929, `VerifiedBuild` = 15595 WHERE `guid` = 84843 AND `id` = 20922;

UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20780;
UPDATE `creature` SET `position_x` = 4032.782958984375, `position_y` = 3543.446044921875, `position_z` = 121.61126708984375, `orientation` = 0.087266460061073303, `VerifiedBuild` = 15595, `spawntimesecs` = 300 WHERE `guid` = 88900 AND `id` = 20780;

-- Defender Corpse, Warder Corpse
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` IN (21303,21304,21592,21623);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `dynamicflags` = 0 WHERE `entry` IN (21303,21304,21592,21623);

-- Kagrosh
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 21725;
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 21725;
UPDATE `creature` SET `VerifiedBuild` = 14545 WHERE `guid` = 86869 AND `id` = 21725;

-- Flanis Swiftwing
UPDATE `creature_template_addon` SET `bytes1` = 0, `auras` = "29266" WHERE `entry` = 21727;
UPDATE `creature_template` SET `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 21727;
UPDATE `creature` SET `position_x` = -3410.419189453125, `position_y` = 2320.8671875, `position_z` = 37.17919158935546875, `orientation` = 4.363323211669921875, `VerifiedBuild` = 14545 WHERE `guid` = 86861 AND `id` = 21727;

-- Murkblood Miner
UPDATE `creature` SET `unit_flags` = 33536 WHERE `id` = 23287 AND `guid` NOT IN (SELECT `guid` FROM `creature_addon` WHERE `id` = 23287);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144|512|256) WHERE `entry` = 23287;

-- Forsaken Deckhand, well, some of them should be alive / somehow remove aura because
-- they have loot and in screenshots they're alive, dunno which ones
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144) WHERE `entry` = 23982;
