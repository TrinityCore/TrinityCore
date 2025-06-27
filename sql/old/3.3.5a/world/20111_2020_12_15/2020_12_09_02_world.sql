-- Grandmaster Vorpil
-- Void Traveler already scripted in core
DELETE FROM `smart_scripts` WHERE `entryorguid` = 19226 AND `source_type` = 0;

UPDATE `creature_template` SET `speed_walk` = 0.8, `speed_run` = 0.28571, `BaseAttackTime` = 1600, `unit_flags2` = 0, `AIName` = "" WHERE `entry` IN (19226,20664); -- Void Traveler
UPDATE `creature_template` SET `speed_walk` = 1, `unit_flags2` = 0 WHERE `entry` IN (19224,20663); -- Void Portal
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` IN (19427,20665); -- Voidwalker Summoner

UPDATE `spell_target_position` SET `PositionX` = -208.411, `PositionY` = -263.652, `PositionZ` = 17.169733, `Orientation` = 3.1404307, `VerifiedBuild` = 15595 WHERE `ID` = 33582;
UPDATE `spell_target_position` SET `PositionX` = -208.411, `PositionY` = -263.652, `PositionZ` = 17.086313, `Orientation` = 3.12187, `VerifiedBuild` = 15595 WHERE `ID` = 33566;

-- Copied from portal spells, a - a, b - b and so on
UPDATE `spell_target_position` SET `PositionX` = -261.676, `PositionY` = -297.69, `PositionZ` = 17.087011, `Orientation` = 1.36025 WHERE `ID` = 33583;
UPDATE `spell_target_position` SET `PositionX` = -282.272, `PositionY` = -240.432, `PositionZ` = 12.683899, `Orientation` = 5.58017 WHERE `ID` = 33584;
UPDATE `spell_target_position` SET `PositionX` = -291.833, `PositionY` = -268.595, `PositionZ` = 12.682546, `Orientation` = 0.047734 WHERE `ID` = 33585;
UPDATE `spell_target_position` SET `PositionX` = -303.966, `PositionY` = -255.759, `PositionZ` = 12.683405, `Orientation` = 6.01283 WHERE `ID` = 33586;

DELETE FROM `spell_target_position` WHERE `ID` IN (33614,33615,33567,33616);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`VerifiedBuild`) VALUES
(33614,1,555,-261.676,-297.69,17.087011,1.36025,15595),
(33615,2,555,-282.272,-240.432,12.683899,5.58017,15595),
(33567,0,555,-291.833,-268.595,12.682546,0.047734,15595),
(33616,1,555,-303.966,-255.759,12.683405,6.01283,15595);

-- Other
UPDATE `creature_template` SET `unit_flags` = 64 WHERE `entry` = 18731; -- Ambassador Hellmaw
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 3000, `unit_flags` = 64 WHERE `entry` = 20636; -- Ambassador Hellmaw (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` BETWEEN 19300 AND 19304; -- Blackheart the Inciter
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `BaseAttackTime` = 2700 WHERE `entry` = 20637; -- Blackheart the Inciter (1)
UPDATE `creature_template` SET `speed_run` = 0.992063 WHERE `entry` = 18633; -- Cabal Acolyte
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.992063, `BaseAttackTime` = 2000 WHERE `entry` = 20638; -- Cabal Acolyte (1)
UPDATE `creature_template` SET `maxlevel` = 70, `speed_walk` = 1, `BaseAttackTime` = 1800 WHERE `entry` = 20639; -- Cabal Assassin (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20640; -- Cabal Cultist (1)
UPDATE `creature_template` SET `speed_run` = 0.992063 WHERE `entry` = 18635; -- Cabal Deathsworn
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.992063, `BaseAttackTime` = 2000 WHERE `entry` = 20641; -- Cabal Deathsworn (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2400 WHERE `entry` = 20642; -- Cabal Executioner (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1600 WHERE `entry` = 20643; -- Cabal Familiar (1)
UPDATE `creature_template` SET `maxlevel` = 70, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20644; -- Cabal Fanatic (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20645; -- Cabal Ritualist (1)
UPDATE `creature_template` SET `speed_run` = 0.992063 WHERE `entry` = 18637; -- Cabal Shadow Priest
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.992063, `BaseAttackTime` = 2000 WHERE `entry` = 20646; -- Cabal Shadow Priest (1)
UPDATE `creature_template` SET `speed_run` = 0.992063 WHERE `entry` = 18639; -- Cabal Spellbinder
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 0.992063, `BaseAttackTime` = 2000 WHERE `entry` = 20647; -- Cabal Spellbinder (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20648; -- Cabal Summoner (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20649; -- Cabal Warlock (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2200 WHERE `entry` = 20650; -- Cabal Zealot (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20651; -- Fel Guardhound (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20652; -- Fel Overseer (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857, `BaseAttackTime` = 2000 WHERE `entry` = 20653; -- Grandmaster Vorpil (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20654; -- Invisible Target (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 18663; -- Maiden of Discipline (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32768 WHERE `entry` = 20655; -- Maiden of Discipline (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 1200 WHERE `entry` = 20656; -- Malicious Instructor (1)
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `BaseAttackTime` = 2800 WHERE `entry` = 20657; -- Murmur (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 19200; -- Shape of the Beast
UPDATE `creature_template` SET `minlevel` = 70, `maxlevel` = 70, `speed_walk` = 1 WHERE `entry` = 20658; -- Shape of the Beast (1)
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 20659; -- Spy To'gun (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `RangeAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 19208; -- Summoned Cabal Acolyte
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000, `unit_flags` = 32832 WHERE `entry` = 20660; -- Summoned Cabal Acolyte (1)
UPDATE `creature_template` SET `maxlevel` = 70, `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 19209; -- Summoned Cabal Deathsworn (1)
UPDATE `creature_template` SET `maxlevel` = 71, `speed_walk` = 1 WHERE `entry` = 20661; -- Summoned Cabal Deathsworn (1)
UPDATE `creature_template` SET `speed_walk` = 1, `BaseAttackTime` = 2000 WHERE `entry` = 20662; -- Tortured Skeleton (1)

UPDATE `creature_model_info` SET `BoundingRadius` = 0.21, `CombatReach` = 2.4 WHERE `DisplayID` = 18880;
