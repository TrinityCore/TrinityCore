--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (7440,7856,8531);

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 23709; -- Dark Iron Guzzler

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 23897; -- Zungam
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 23897);
DELETE FROM `creature_template_addon` WHERE `entry` = 23897;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(23897,'25900');

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 24189; -- Ares the Oathbound
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 24189);
DELETE FROM `creature_template_addon` WHERE `entry` = 24189;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(24189,0,0,3,1,0,0,"25900");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 24477; -- Syndicate Thief
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 27558; -- Warsong Peon

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28024; -- Rainspeaker Warrior
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28025; -- Rainspeaker Oracle
DELETE FROM `creature_addon` WHERE `guid` IN (107029,107130);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(107029,0,0,3,1,0,0,"50917"),
(107130,0,0,3,1,0,0,"50503 52102");
UPDATE `creature` SET `wander_distance` = 0, `MovementType` = 0 WHERE `guid` IN (107029,107130) AND `id` IN (28024,28025);

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28037; -- The Spirit of Gnomeregan
UPDATE `creature_template_addon` SET `auras` = "51114 25900" WHERE `entry` = 28037;

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 28298; -- Captive Crocolisk
DELETE FROM `creature_template_addon` WHERE `entry` = 28298;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(28298,0,0,0,1,0,0,"29826");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 30548; -- The Guardian's Charge
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 30548);
DELETE FROM `creature_template_addon` WHERE `entry` = 30548;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(30548,0,0,0,1,0,0,"52165");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 31892; -- Darkspeaker R'khem
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 31892);
UPDATE `creature_template_addon` SET `bytes2` = 1, `auras` = "25900" WHERE `entry` = 31892;
UPDATE `smart_scripts` SET `action_param2` = 2 WHERE `entryorguid` = 3189200 AND `source_type` = 9 AND `id` = 1;

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` = 32185; -- Infinite Eradicator
UPDATE `creature_addon` SET `bytes1` = 50331648, `auras` = '4368' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32185);

UPDATE `creature_template` SET `speed_run` = 0.99206284114, `unit_flags` = `unit_flags` &~ (262144|33554432), `unit_flags2` = 67584 WHERE `entry` IN (34184,34219); -- Clockwork Mechanic
UPDATE `smart_scripts` SET `link` = 1, `event_flags` = 0, `comment` = "Clockwork Mechanic - On Just Summoned - Cast 'Ride Vehicle'" WHERE `entryorguid` = 34184 AND `source_type` = 0 AND `id` = 0;
-- Incomplete, when vehicle enters in combat they should dismount and remove all that stuff
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34184 AND `source_type` = 0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34184,0,1,2,61,0,100,0,0,0,0,0,0,11,25900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Clockwork Mechanic - On Link - Cast 'Stun Self'"),
(34184,0,2,0,61,0,100,0,0,0,0,0,0,18,33554432,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Clockwork Mechanic - On Link - Set Flag Not Selectable");

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (262144|33554432) WHERE `entry` = 23775; -- Head of the Horseman

UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.42857142857, `unit_flags` = 33554752 WHERE `entry` IN (15928,29448); -- Thaddius
UPDATE `creature_template_addon` SET `bytes2` = 1 WHERE `entry` IN (15928,29448);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 15928);
