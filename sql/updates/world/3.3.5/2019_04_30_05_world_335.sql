-- 
UPDATE `creature_template_addon` SET `auras` = '3616' WHERE `entry` IN (
2208, -- Greymist Tidehunter
2651, -- Witherbark Hideskinner
2686, -- Witherbark Broodguard
3260, -- Bristleback Water Seeker
5224, -- Murk Slitherer
5856, -- Glassweb Spider
6004, -- Shadowsworn Cultist
6551, -- Gorishi Wasp
8762); -- Timberweb Recluse

DELETE FROM `creature_template_addon` WHERE `entry` IN (8556,10882,2644,3767,17236);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(8556, '3616'), -- Crypt Walker
(10882, '3616'), -- Arikara
(2644, '3616'), -- Vilebranch Hideskinner
(3767, '3616'), -- Bleakheart Trickster
(17236, '3616'); -- Tcha'kaz

-- Add Torch Burn 5680 for 
UPDATE `creature_template_addon` SET `auras` = '5680' WHERE `entry` IN (2977); -- Venture Co. Taskmaster
DELETE FROM `creature_template_addon` WHERE `entry` IN (3736);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(3736, '5680'); -- Darkslayer Mordenthal
UPDATE `creature_addon` SET `auras` = '5680' WHERE `guid` = 32917;

-- Add Phasing Stealth 6718 for
DELETE FROM `creature_template_addon` WHERE `entry` IN (15609, 15610, 15611);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(15609, '6718'), -- Cenarion Scout Landion
(15610, '6718'), -- Cenarion Scout Azenel
(15611, '6718'); -- Cenarion Scout Jalia
UPDATE `creature_addon` SET `auras` = '6718' WHERE `guid` IN (46164,46165,46166);

DELETE FROM `creature_template_addon` WHERE `entry` IN (3806);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(3806, '3616 8218'); -- Forsaken Infiltrator
UPDATE `creature_addon` SET `auras` = '3616 8218' WHERE `guid` IN (34245, 34244, 34243, 34242, 34241, 34240, 34239, 34238, 34237, 34236);

UPDATE `creature_template_addon` SET `auras` = '8218 8601' WHERE `entry` = 3807; -- Forsaken Assassin
UPDATE `creature_template_addon` SET `auras` = '8218' WHERE `entry` IN (3804); -- Forsaken Intruder

-- Add Slowing Poison 8601 for 
UPDATE `creature_template_addon` SET `auras` = '8601' WHERE `entry` IN (
544, -- Murloc Nightcrawler
5422, -- Scorpid Hunter
6554, -- Gorishi Stinger
8601); -- Noxious Plaguebat

DELETE FROM `creature_template_addon` WHERE `entry` IN (1110);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(1110, '8601');-- Skeletal Raider
UPDATE `creature_addon` SET `auras` = '8601' WHERE `guid` IN (5138, 5137, 5130, 5122, 5121, 5120, 5103, 5102, 5096, 5093, 5091, 5052, 5049, 4977, 4889, 4885);

DELETE FROM `creature_template_addon` WHERE `entry` = 10041;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES (10041, '8601'); -- Gorishi Hive Queen

UPDATE `creature_template_addon` SET `auras` = '3616 8601' WHERE `entry` IN (909); -- Defias Night Blade

DELETE FROM `creature_template_addon` WHERE `entry` IN (4971);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(4971, '3616 8601'); -- Slim's Friend
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(7110) AND `source_type`=0 AND `id` IN (0,1);

UPDATE `creature_template_addon` SET `auras` = '6408 8601' WHERE `entry` = 7110; -- Jadefire Shadowstalker
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(7110) AND `source_type`=0 AND `id`=1;

UPDATE `creature_template` SET `AIName`="" WHERE entry IN (1110,544,5422,8601,3807,3806,5224);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(7110,6554,6551) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(909,1110,544,5422,8601,3807,3806,5224) AND `source_type`=0 AND `id` IN (0,1);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(3767,5856) AND `source_type`=0 AND `id`=0;
