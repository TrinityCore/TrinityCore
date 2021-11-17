-- 
UPDATE `smart_scripts` SET `event_type`=23, `event_param1`=36640, `event_param3`=1000, `event_param4`=1000, `action_param2`=2, `comment`="Warp Aberration - On missing aura - Cast 'Arcane Shield' (No Repeat)" WHERE entryorguid IN (18865) AND source_type=0 AND id=0;
UPDATE `creature_template` SET `unit_flags`=33554432, `AIName`="" WHERE  `entry`=21322;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (21322) AND `source_type`=0;

DELETE FROM `creature_template_addon` WHERE `entry` IN (21322);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(21322, 0, 0, 0, 0, 0, '36581');
