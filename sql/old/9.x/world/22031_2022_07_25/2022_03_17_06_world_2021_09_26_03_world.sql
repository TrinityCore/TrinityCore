--
UPDATE `creature_template` SET `unit_flags` = 768, `flags_extra` = `flags_extra`|512 WHERE `entry` IN (36908,36909);
DELETE FROM `creature_template_addon` WHERE `entry` IN (36908,36909);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(36908,0,0,0,1,0,0,'69641'),
(36909,0,0,0,1,0,0,'69641');

DELETE FROM `spell_script_names` WHERE `spell_id` = 69641 AND `ScriptName` = 'spell_gen_gryphon_wyvern_mount_check';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(69641,'spell_gen_gryphon_wyvern_mount_check');
