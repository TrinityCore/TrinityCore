--
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 0, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Baelgun's Event Generator (Cave) - On Script - Summon Group 0" WHERE `entryorguid` = 2484500 AND `source_type` = 9 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2484500 AND `source_type` = 9 AND `id` BETWEEN 1 AND 15;
UPDATE `smart_scripts` SET `id` = 1, `comment` = "Baelgun's Event Generator (Cave) - On Script - Despawn (0) (Iron Dwarf)" WHERE `entryorguid` = 2484500 AND `source_type` = 9 AND `id` = 16;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = 24845 AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(24845,0,0,24846,306.099,-5706.15,102.435,4.96977,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,311.025,-5702.8,101.935,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,309.754,-5703.16,102.071,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,308.223,-5703.8,102.232,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,307.044,-5704.32,102.356,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,304.169,-5706.84,102.697,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,303.13,-5707.28,102.978,5.18722,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,297.246,-5726.82,96.2681,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,292.82,-5726.04,96.5843,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,292.562,-5728.57,96.5857,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,292.15,-5727.42,96.5874,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,294.578,-5730.09,96.2958,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,296.196,-5730.17,96.0082,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,297.603,-5730.79,95.6955,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24846,299.397,-5729.56,95.7274,0.347607,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Iron Dwarf"),
(24845,0,0,24847,315.101,-5723.06,96.2541,3.05433,5,0,"Baelgun's Event Generator (Cave) - Group 0 - Loken");

UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 0, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 0" WHERE `entryorguid` = 16481900 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481900 AND `source_type` = 9 AND `id` BETWEEN 3 AND 4;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 1, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 1" WHERE `entryorguid` = 16481901 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481901 AND `source_type` = 9 AND `id` BETWEEN 3 AND 4;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 2, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 2" WHERE `entryorguid` = 16481902 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481902 AND `source_type` = 9 AND `id` BETWEEN 3 AND 4;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 3, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 3" WHERE `entryorguid` = 16481903 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481903 AND `source_type` = 9 AND `id` BETWEEN 3 AND 4;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 4, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 4" WHERE `entryorguid` = 16481904 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481904 AND `source_type` = 9 AND `id` BETWEEN 3 AND 6;
UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 5, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Dark Keeper Portrait - On Script - Summon Group 5" WHERE `entryorguid` = 16481905 AND `source_type` = 9 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 16481905 AND `source_type` = 9 AND `id` BETWEEN 3 AND 4;

UPDATE `smart_scripts` SET `action_type` = 107, `action_param1` = 0, `action_param2` = 0, `action_param3` = 0, `target_type` = 0, `target_x` = 0, `target_y` = 0, `target_z` = 0, `target_o` = 0, `comment` = "Highborne Relic Fragment - On Gameobject State Changed - Summon Group 0" WHERE `entryorguid` IN (175888,175891,175892,175893) AND `source_type` = 1 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (175888,175891,175892,175893) AND `source_type` = 1 AND `id` = 1;

DELETE FROM `creature_summon_groups` WHERE `summonerId` IN (164819,175888,175891,175892) AND `summonerType` = 1;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(164819,1,0,9437,914.055,-164.125,-49.7607,2.16251,8,0,"Dark Keeper Portrait - Group 0 - Dark Keeper Vorfalk"),
(164819,1,0,9445,916.782,-163.222,-49.7607,2.22296,8,0,"Dark Keeper Portrait - Group 0 - Dark Guard"),
(164819,1,0,9445,912.515,-166.48,-49.7607,2.22296,8,0,"Dark Keeper Portrait - Group 0 - Dark Guard"),
(164819,1,1,9438,812.246,-348.875,-50.5781,0.710542,8,0,"Dark Keeper Portrait - Group 1 - Dark Keeper Bethek"),
(164819,1,1,9445,809.895,-348.221,-50.5781,0.713424,8,0,"Dark Keeper Portrait - Group 1 - Dark Guard"),
(164819,1,1,9445,812.575,-351.318,-50.5781,0.713424,8,0,"Dark Keeper Portrait - Group 1 - Dark Guard"),
(164819,1,2,9439,888.483,-361.707,-49.9358,0.612107,8,0,"Dark Keeper Portrait - Group 2 - Dark Keeper Uggel"),
(164819,1,2,9445,886.982,-360.478,-49.9358,0.612107,8,0,"Dark Keeper Portrait - Group 2 - Dark Guard"),
(164819,1,2,9445,888.82,-363.746,-49.9358,0.612107,8,0,"Dark Keeper Portrait - Group 2 - Dark Guard"),
(164819,1,3,9441,545.018,-214.379,-35.5465,0.339364,8,0,"Dark Keeper Portrait - Group 3 - Dark Keeper Zimrel"),
(164819,1,3,9445,543.337,-211.984,-35.5118,0.40162,8,0,"Dark Keeper Portrait - Group 3 - Dark Guard"),
(164819,1,3,9445,546.018,-217.407,-35.5704,0.505293,8,0,"Dark Keeper Portrait - Group 3 - Dark Guard"),
(164819,1,4,9442,659.373,2.65909,-60.0585,0.990563,8,0,"Dark Keeper Portrait - Group 4 - Dark Keeper Ofgut"),
(164819,1,4,9445,658.681,5.29951,-60.0585,0.990563,8,0,"Dark Keeper Portrait - Group 4 - Dark Guard"),
(164819,1,4,9445,661.902,2.76951,-60.0585,0.990563,8,0,"Dark Keeper Portrait - Group 4 - Dark Guard"),
(164819,1,4,9445,659.792,-0.450377,-60.0585,0.990563,8,0,"Dark Keeper Portrait - Group 4 - Dark Guard"),
(164819,1,4,9445,656.213,2.17197,-60.0585,0.99056,8,0,"Dark Keeper Portrait - Group 4 - Dark Guard"),
(164819,1,5,9443,804.041,-247.345,-43.3029,2.60616,8,0,"Dark Keeper Portrait - Group 5 - Dark Keeper Pelver"),
(164819,1,5,9445,805.992,-246.46,-43.3029,2.52525,8,0,"Dark Keeper Portrait - Group 5 - Dark Guard"),
(164819,1,5,9445,803.904,-249.408,-43.3029,2.52525,8,0,"Dark Keeper Portrait - Group 5 - Dark Guard"),
(175888,1,0,7523,6505.45,-4230.91,658.636,3.31351,1,180000,"Highborne Relic Fragment - Group 0 - Suffering Highborne"),
(175888,1,0,7524,6494.32,-4228.23,658.549,5.63829,1,180000,"Highborne Relic Fragment - Group 0 - Anguished Highborne"),
(175891,1,0,7523,6562.16,-3919.21,658.297,4.42878,1,180000,"Highborne Relic Fragment - Group 0 - Suffering Highborne"),
(175891,1,0,7524,6556.55,-3938.87,658.313,1.30682,1,180000,"Highborne Relic Fragment - Group 0 - Anguished Highborne"),
(175892,1,0,7523,6482.59,-4109.64,658.291,2.21004,1,180000,"Highborne Relic Fragment - Group 0 - Suffering Highborne"),
(175892,1,0,7524,6482.84,-4093.91,658.412,4.11463,1,180000,"Highborne Relic Fragment - Group 0 - Anguished Highborne"),
(175893,1,0,7523,6563.31,-4047.92,658.329,1.18116,1,180000,"Highborne Relic Fragment - Group 0 - Suffering Highborne"),
(175893,1,0,7524,6557.38,-4041.45,658.408,0.313297,1,180000,"Highborne Relic Fragment - Group 0 - Anguished Highborne");
