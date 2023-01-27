-- add missing loot object
DELETE FROM gameobject_loot_template WHERE entry=210005;
INSERT INTO `gameobject_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES 
(210005,73209,-100,1,0,1,1),
(210005,76392,-100,1,0,1,1),
(210005,76390,-100,1,0,1,1),
(210005,73211,-100,1,0,1,1),
(210005,76393,-100,1,0,1,1),
(210005,73207,-100,1,0,1,1),
(210005,73212,-100,1,0,1,1),
(210005,73208,-100,1,0,1,1),
(210005,73213,-100,1,0,1,1),
(210005,76391,-100,1,0,1,1);
UPDATE gameobject_template SET data1=210005 WHERE entry=210005;

-- add missing loot object
DELETE FROM `gameobject_loot_template` WHERE entry='210016';
INSERT INTO `gameobject_loot_template` VALUES ('210016', '73211', '99', '1', '0', '1', '1');
UPDATE gameobject_template SET data1=210016 WHERE entry=210016;

-- delete rong spawn object in the start zone or duplicates
DELETE FROM gameobject WHERE guid IN (204257,204312,212547,212564,204265,197250,197280,197287,197294,197309,197311,197313,197376,197184);

-- add movement
UPDATE creature_template SET MovementType=1 WHERE entry=57754;
UPDATE creature SET MovementType=1 WHERE guid=355786;
UPDATE creature SET spawndist=6 WHERE guid=355786;

-- fix error required level 172 LOOOL
UPDATE gameobject_template SET unkInt32=0 WHERE entry=210986;
UPDATE gameobject_template SET unkInt32=0 WHERE entry=210987;

-- make it work the quest
UPDATE `creature_template` SET `faction_A`=7, `faction_H`=7 WHERE `entry`=59591;
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=59591;

-- add movement to  panda fox
UPDATE creature_template SET MovementType=1 WHERE entry=53704;
UPDATE `creature` SET `MovementType`=1, `spawndist`=9 WHERE `id`=53704;

-- add movement to rabbit and  set right lvl
UPDATE creature_template SET MovementType=1 WHERE entry=54133;
UPDATE `creature` SET `MovementType`=1, `spawndist`=11 WHERE `id`=54133;
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1 WHERE `entry`=54133;

-- add movement to deng
UPDATE creature_template SET MovementType=1 WHERE entry=64929;
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `guid`=333573;

-- add movement to lin
UPDATE creature_template SET MovementType=1 WHERE entry=60253;
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `guid`=258635;

-- add movement to zhen
UPDATE creature_template SET MovementType=1 WHERE entry=60245;
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `guid`=258636;

-- add movement to zhen chia-hui
UPDATE creature_template SET MovementType=1 WHERE entry=60248;
UPDATE `creature` SET `MovementType`=1, `spawndist`=5 WHERE `guid`=258639;

-- add movement to Hozen monkey 
UPDATE creature_template SET MovementType=1 WHERE entry=57205;
UPDATE `creature` SET `MovementType`=1, `spawndist`=9 WHERE `id`=57205;

-- add movement to Brewthief monkey 
UPDATE creature_template SET MovementType=1 WHERE entry=56730;
UPDATE `creature` SET `MovementType`=1, `spawndist`=9 WHERE `id`=56730;

-- add movement to zhen Wu-Song villager female
UPDATE creature_template SET MovementType=1 WHERE entry=65472;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `id`=65472;

-- add movement to zhen Wu-Song villager male
UPDATE creature_template SET MovementType=1 WHERE entry=57132;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `id`=57132;

-- add movement to Huojin Monk
UPDATE creature_template SET MovementType=1 WHERE entry=60176;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid`=333198;

-- add movement to Huojin Nim
UPDATE creature_template SET MovementType=1 WHERE entry=60183;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid`=333537;

-- add movement to Amberleaf Scamp
UPDATE creature_template SET MovementType=1 WHERE entry=54130;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `id`=54130;

-- add movement to Dawn
UPDATE creature_template SET MovementType=1 WHERE entry=65094;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid`=333625;
UPDATE `creature` SET `MovementType`=1, `spawndist`=6 WHERE `guid`=334038;

-- add movement to Deng
UPDATE creature_template SET MovementType=1 WHERE entry=60249;
UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid`=333105;
UPDATE `creature` SET `MovementType`=1, `spawndist`=6 WHERE `guid`=333106;

-- delete rong spawns
DELETE FROM creature WHERE guid IN (258637,258610);

-- add movement to turtles
UPDATE creature_template SET MovementType=1 WHERE entry=64440;
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `id`=64440;

-- add movement to Crane
UPDATE creature_template SET MovementType=1 WHERE entry=55015;
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `id`=55015;

-- add movement to Pincer
UPDATE creature_template SET MovementType=1 WHERE entry=60411;
UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `id`=60411;

DELETE FROM script_waypoint WHERE entry=56661;
INSERT INTO `script_waypoint` VALUES (56661, 1, 1225.24, 3449.83, 102.426, 0, '');
INSERT INTO `script_waypoint` VALUES (56661, 2, 1204.46, 3444.84, 102.409, 0, '');
INSERT INTO `script_waypoint` VALUES (56661, 3, 1177.37, 3444.32, 103.093, 0, '');
INSERT INTO `script_waypoint` VALUES (56661, 4, 1165.1, 3441.25, 104.974, 0, '');

-- delete not necesary spawn rong
DELETE FROM creature WHERE guid IN (258578,258575,258576,258574,258573,258577,356800);

-- the roots was teleport  players to the start zone LOOL
UPDATE gameobject_template SET data14=0 WHERE entry=209326;
UPDATE gameobject_template SET unk1="" WHERE entry=209326;

-- fix the loot for the monkey
DELETE FROM creature_loot_template WHERE entry=57205;
INSERT INTO `creature_loot_template` VALUES (57205, 117, 34.8399, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 118, 1.125549, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 159, 15.9448, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 805, 4.2059, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 828, 2.95041, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 1210, 1.125549, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 1420, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 1429, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 1468, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 2589, 1.439422, 1, 0, 1, 2);
INSERT INTO `creature_loot_template` VALUES (57205, 2635, 1.125549, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 2645, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 2773, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 2859, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 2924, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 4496, 2.82486, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 4536, 1.125549, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 4666, 1.0627746, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 4751, 1.188324, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 4757, 1.188324, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 5571, 2.76208, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 5572, 3.32706, 1, 0, 1, 1);
INSERT INTO `creature_loot_template` VALUES (57205, 6293, 1.0627746, 1, 0, 1, 1);

-- remove duplicate
DELETE FROM gameobject WHERE guid IN (204326);

-- add flames into cave at the monk starting quests
-- add script for flames game npc and add spawns
DELETE FROM smart_scripts WHERE entryorguid=59626;
INSERT INTO `smart_scripts` VALUES (59626, 0, 0, 0, 1, 0, 100, 1, 100, 100, 0, 0, 11, 114686, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame jet - Visual ground');
INSERT INTO `smart_scripts` VALUES (59626, 0, 1, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 11, 114685, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Jet - Fight off damage');
INSERT INTO `smart_scripts` VALUES (59626, 0, 2, 0, 1, 0, 100, 0, 0, 0, 10000, 10000, 11, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Visual Effect flames out of combat');
INSERT INTO `smart_scripts` VALUES (59626, 0, 3, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 114685, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Jet - fight Damage');
INSERT INTO `smart_scripts` VALUES (59626, 0, 4, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 114684, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Visual Effect fighting in flames');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=59626;
DELETE FROM creature WHERE id=59626;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1371.3, 3891.96, 95.1204, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1374.08, 3890.09, 95.4292, 6.18466, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1376.9, 3890.8, 96.2529, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1379.47, 3889.42, 96.9286, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1380.53, 3886.69, 96.8472, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1381.13, 3891.73, 97.2389, 2.14945, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1385.99, 3896.72, 100.317, 1.67778, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1387.58, 3898.96, 100.805, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1389.91, 3897.56, 100.765, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1389.95, 3900.71, 101.079, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1389.99, 3886.57, 98.4281, 2.96841, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1392.13, 3898.04, 100.876, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1392.36, 3885.11, 98.5571, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1392.38, 3887.87, 99.0246, 1.52258, 5, 0, 0, 1, 0, 0, 0, 131078, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1395.77, 3888.32, 99.4317, 0.839801, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1398.31, 3890.13, 100.058, 5.50638, 300, 0, 0, 204, 0, 0, 0, 0, 0);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES (NULL, 59626, 860, 1, 65535, 0, 0, 1399.78, 3892.67, 100.635, 1.08567, 300, 0, 0, 204, 0, 0, 0, 0, 0);

-- add trainging state and moves gesture to  pandarens student at the starting zone
DELETE FROM smart_scripts WHERE entryorguid=65469;
INSERT INTO `smart_scripts` VALUES (65469, 0, 1, 0, 1, 0, 100, 0, 6000, 6000, 20000, 20000, 5, 480, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aspiring rookie - Dodge');
INSERT INTO `smart_scripts` VALUES (65469, 0, 2, 0, 1, 0, 100, 0, 11000, 11000, 20000, 20000, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aspiring rookie - Palm');
INSERT INTO `smart_scripts` VALUES (65469, 0, 3, 0, 1, 0, 100, 0, 16000, 16000, 20000, 20000, 5, 439, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aspiring rookie - Fist');
INSERT INTO `smart_scripts` VALUES (65469, 0, 4, 0, 1, 0, 100, 0, 21000, 21000, 20000, 20000, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aspiring rookie - Stand');
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=65469;

-- add emote talk for the last 2 forgoten mobs guid
DELETE FROM creature_addon WHERE guid IN (333556,355779);
INSERT INTO `creature_addon` VALUES ('333556', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('355779', '0', '0', '0', '0', '1', '');
DELETE FROM creature_addon WHERE guid IN (355773,355774,355764,355765,333566,333555,333474,333539,333538,333465,333437,333436,333435,333011,332997,333008);
INSERT INTO `creature_addon` VALUES ('355773', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('355774', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('355764', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('355765', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333566', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333555', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333474', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333539', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333538', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333465', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333437', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333436', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333435', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333011', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('332997', '0', '0', '0', '0', '1', '');
INSERT INTO `creature_addon` VALUES ('333008', '0', '0', '0', '0', '1', '');

-- fixing quest objects scripts 29664 The Challengers Fires
DELETE FROM smart_scripts WHERE entryorguid IN (209803,209802,209924,209801);
INSERT INTO `smart_scripts` VALUES (209801, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 56037, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Red Brazier-Kill credit');
INSERT INTO `smart_scripts` VALUES (209802, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 56038, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Blue Brazier-Kill credit');
INSERT INTO `smart_scripts` VALUES (209803, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 56040, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Violet Brazier-Kill credit');
INSERT INTO `smart_scripts` VALUES (209924, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 33, 56048, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Brasier - Kill credit');
DELETE FROM gameobject_template WHERE entry IN (209803,209802,209924,209801);
INSERT INTO `gameobject_template` VALUES (209801, 10, 10996, 'Brazier of the Red Flame', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 29664, 0, 0, 0, 5, 0, 0, 0, 0, 105156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 16048);
INSERT INTO `gameobject_template` VALUES (209802, 10, 10995, 'Brazier of the Blue Flame', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 29664, 0, 0, 0, 5, 0, 0, 0, 0, 105157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 16048);
INSERT INTO `gameobject_template` VALUES (209803, 10, 10994, 'Brazier of the Violet Flame', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 29664, 0, 0, 0, 5, 0, 0, 0, 0, 105158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 16048);
INSERT INTO `gameobject_template` VALUES (209924, 10, 10791, 'Brazier of the Flickering Flame', '', '', '', 0, 32, 1, 0, 0, 0, 0, 0, 0, 0, 29664, 0, 0, 0, 5, 0, 0, 0, 0, 105151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartGameObjectAI', '', 16048);
UPDATE gameobject SET id=209924 WHERE id=209374;
UPDATE gameobject SET id=209801 WHERE id=209369;
UPDATE quest_template SET SourceItemId=75008 WHERE id=29664;
UPDATE quest_template SET RequiredSourceItemId3=0 WHERE id=29664;
UPDATE quest_template SET RequiredSourceItemId4=75008 WHERE id=29664;

-- add missing models for 2 npc
UPDATE `creature_template` SET `modelid1`='46082' WHERE `entry`='56009';
UPDATE `creature_template` SET `modelid1`='46096' WHERE `entry`='55506';
