-- Credit for some of auras: vmangos

-- Mad Magglish
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3655 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 3655;

-- Deviate Stalker
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 3634;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3634 AND `source_type` = 0;

DELETE FROM `creature_template_addon` WHERE `entry` = 3634;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(3634, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 3634);

-- Deviate Creeper don't need stealth https://youtu.be/H27PXbtfP54
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3632 AND `source_type` = 0 AND `id` = 1;

-- Blackhand Assassin
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10318 AND `source_type` = 0 AND `id` IN (0,1);

DELETE FROM `creature_template_addon` WHERE `entry` = 10318;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(10318, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 10318);

-- Blackhand Iron Guard don't need stealth https://tbc.wowhead.com/npc=10319/blackhand-iron-guard#abilities
DELETE FROM `creature_template_addon` WHERE `entry` = 10319;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(10319, 0, 0, 0, 0, 1, 0, 0, '12782');

UPDATE `creature_addon` SET `auras` = '12782' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 10319);

-- Coldmist Stalker https://youtu.be/srOrckK0WBM
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 16170;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16170 AND `source_type` = 0;

UPDATE `creature_template_addon` SET `auras` = '29291 28094 22766' WHERE `entry` = 16170;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 16170);

-- Crag Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4126 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_template_addon` WHERE `entry` = 4126;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(4126, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Daggerfen Assassin https://youtu.be/9yOP3xldaTI
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 18116;

-- Defias Night Runner
DELETE FROM `smart_scripts` WHERE `entryorguid` = 215 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 215;

-- Expedition Druid
UPDATE `creature_addon` SET `auras` = '22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 22206);
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 22206;

-- Fallenroot Rogue
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4789 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4789,0,0,0,0,0,100,0,6000,10000,8000,14000,0,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fallenroot Rogue - In Combat - Cast 'Exploit Weakness'");

UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 4789;

-- Fallenroot Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4798 AND `source_type` = 0 AND `id` = 1;

UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 4798;
UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 4798);

-- Felmusk Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3763 AND `source_type` = 0 AND `id` = 0;

DELETE FROM `creature_template_addon` WHERE `entry` = 3763;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(3763, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 3763);

-- They shoudn't wear any weapon here, only cata model
DELETE FROM `creature_equip_template` WHERE `CreatureID` = 3763;
UPDATE `creature` SET `equipment_id` = 0 WHERE `id` = 3763;

-- Fen Creeper
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 1040;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1040 AND `source_type` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 1040;

-- Hive'Ashi Sandstalker
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 11723;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11723 AND `source_type` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 11723;

-- Hive'Regal Ambusher
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11730 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 11730;

-- Jaguero Stalker
UPDATE `creature_template_addon` SET `auras` = '7939 22766 3417' WHERE `entry` = 2522;

-- Putridus Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11792 AND `source_type` = 0 AND `id` IN (2,3);
UPDATE `creature_template_addon` SET `auras` = '7939 22766 21061' WHERE `entry` = 11792;
UPDATE `creature_addon` SET `auras` = '7939 22766 21061' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 11792);

-- Razorfen Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 6035 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 6035;
UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 6035);

-- Razormane Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3457 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 3457;
UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 3457);

-- Ridge Stalker
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 2731;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2731 AND `source_type` = 0;
DELETE FROM `creature_template_addon` WHERE `entry` = 2731;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(2731, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Ridgespine Horror https://www.wowhead.com/npc=20998/ridgespine-horror#comments:id=1313063
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 20998;

-- Ridgespine Stalker
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 20714;

-- Rohh the Silent
DELETE FROM `smart_scripts` WHERE `entryorguid` = 947 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `creature_template_addon` WHERE `entry` = 947;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(947, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Sable Jaguar
DELETE FROM `creature_template_addon` WHERE `entry` = 18982;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(18982, 0, 0, 0, 0, 1, 0, 0, '18950 7939 22766');
UPDATE `creature_addon` SET `auras` = '18950 7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 18982);

-- Sable Jaguar Specimen
UPDATE `creature_template_addon` SET `auras` = '34712 18950 7939 22766' WHERE `entry` = 20025;

-- Shadow Panther
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 768;

-- Shadowclaw
DELETE FROM `creature_template_addon` WHERE `entry` = 2175;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(2175, 0, 0, 0, 0, 1, 0, 0, '7939 22766');
UPDATE `creature_addon` SET `auras` = '7939 22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 2175);

-- Shadowhide Assassin
DELETE FROM `smart_scripts` WHERE `entryorguid` = 579 AND `source_type` = 0 AND `id` = 2;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 579;

-- Silvermane Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2926 AND `source_type` = 0 AND `id` = 1;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 2926;

-- Stonescythe Ambusher
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16928 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 16928;

-- Stonevault Cave Lurker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4850 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766 10022' WHERE `entry` = 4850;

-- Syndicate Assassin
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2246 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 2246;

-- Syndicate Highwayman
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2586 AND `source_type` = 0 AND `id` IN (0,1);
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 2586;

-- Syndicate Prowler
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2588 AND `source_type` = 0 AND `id` IN (0,1);
DELETE FROM `creature_template_addon` WHERE `entry` = 2588;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(2588, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Syndicate Spy
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2242 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 2242;

-- Theramore Infiltrator
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4834 AND `source_type` = 0 AND `id` = 1;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 4834;

-- Wildspawn Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11456 AND `source_type` = 0 AND `id` IN (0,2);
DELETE FROM `creature_template_addon` WHERE `entry` = 11456;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(11456, 0, 0, 0, 0, 1, 0, 0, '7939 22766 8601 18950');

UPDATE `creature_addon` SET `auras` = '7939 22766 8601 18950' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 11456);

-- Witchwing Ambusher
DELETE FROM `smart_scripts` WHERE `entryorguid` = 3279 AND `source_type` = 0 AND `id` = 1;
UPDATE `creature_template_addon` SET `auras` = '7939 22766' WHERE `entry` = 3279;

-- Witherheart the Stalker
DELETE FROM `smart_scripts` WHERE `entryorguid` = 8218 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_template_addon` WHERE `entry` = 8218;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(8218, 0, 0, 0, 0, 1, 0, 0, '22766');
UPDATE `creature_addon` SET `auras` = '22766' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 8218);

-- Zulian Prowler
DELETE FROM `creature_template_addon` WHERE `entry` = 15101;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(15101, 0, 0, 0, 0, 1, 0, 0, '7939 22766');

-- Zulian Stalker
UPDATE `creature_template_addon` SET `auras` = '22766' WHERE `entry` = 15067;
