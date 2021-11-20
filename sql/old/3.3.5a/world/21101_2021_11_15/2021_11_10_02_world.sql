--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (10202,10662,10663,10664) AND `source_type` = 0 AND `id` = 0;

-- Credit: vmangos
-- Azurous: Immune to Fear.
UPDATE `creature_template` SET `mechanic_immune_mask`=16 WHERE `entry`=10202;

-- Spellmaw: Immune to Fear, Silence, Snare, Stun.
UPDATE `creature_template` SET `mechanic_immune_mask`=16+256+1024+2048 WHERE `entry`=10662;

-- Manaclaw: Immune to Root, Snare, Freeze.
UPDATE `creature_template` SET `mechanic_immune_mask`=64+1024+4096 WHERE `entry`=10663;
UPDATE `creature_template_addon` SET `auras` = '17010' WHERE `entry` = 10663;

-- Scryer
DELETE FROM `creature_template_addon` WHERE `entry` = 10664;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(10664, 0, 0, 0, 0, 1, 0, 0, '8279 18943');
UPDATE `creature_addon` SET `auras` = '8279 18943' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 10664);
