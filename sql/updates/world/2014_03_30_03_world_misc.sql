-- Set script name for quest giver
UPDATE `creature_template` SET `ScriptName` = 'npc_archmage_landalock' WHERE `entry` = 20735;
-- Images can't be selected and they hover
UPDATE `creature_template` SET `unit_flags` = `unit_flags` | 33555200, `InhabitType` = 4 WHERE `entry` IN (37849, 37850, 37851, 37853, 37854, 37855, 37856, 37858, 37859, 37861, 37862, 37864);
-- Fix animation of Malygos Image
DELETE FROM `creature_template_addon` WHERE `entry` = 37855;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(37855, 0, 0, 50331648, 0, 0, NULL);
