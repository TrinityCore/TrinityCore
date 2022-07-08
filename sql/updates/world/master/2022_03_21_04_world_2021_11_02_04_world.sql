-- Arch Mage Xintor
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16977 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_template_addon` WHERE `entry` = 16977;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(16977, 0, 0, 0, 0, 1, 0, 0, '33900');

-- Lieutenant Commander Thalvos
UPDATE `creature_addon` SET `auras` = '33900' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16978);
UPDATE `creature_template_addon` SET `auras` = '33900' WHERE `entry` = 16978;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16978 AND `source_type` = 0 AND `id` = 2;

-- Unyielding Footman
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16904 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '33900' WHERE `entry` = 16904;
UPDATE `creature_addon` SET `auras` = '33900' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16904);

-- Unyielding Sorcerer
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16905 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '33900' WHERE `entry` = 16905;
UPDATE `creature_addon` SET `auras` = '33900' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16905);

-- Unyielding Knight
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16906 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '33900' WHERE `entry` = 16906;
UPDATE `creature_addon` SET `auras` = '33900' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16906);

-- Defias Blackguard https://youtu.be/IffoEFNUiwY?t=3978 (faded behave wrong)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 636 AND `source_type` = 0 AND `id` IN (0,1);
UPDATE `creature_template_addon` SET `auras` = '1785' WHERE `entry` = 636;

-- Shadowy Assassin
-- Credit: vmangos
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 2434;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2434 AND `source_type` = 0;

DELETE FROM `creature_template_addon` WHERE `entry` = 2434;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(2434, 0, 0, 0, 0, 1, 0, 0, '1785 3616');
