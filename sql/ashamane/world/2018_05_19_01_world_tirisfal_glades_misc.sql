DELETE FROM `creature` WHERE `guid`=210116547;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(210116547, 38895, 0, 6454, 5692, 1, 0, 0, 0, -1, 0, 0, 1757.48, 1666.03, 121.208, 0.02929, 10, 0, 0, 87, 60, 0, 0, 0, 0, 0, 0, '', 26365);
DELETE FROM `creature_addon` WHERE `guid`=210116547;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(210116547, 0, 0, 0, 0, 431, 0, 0, 0, NULL);
UPDATE `creature_template` SET `npcflag`='1' WHERE  `entry`=38895;
DELETE FROM `creature_queststarter` WHERE  `id`=38895 AND `quest`=24960;

UPDATE `creature_template` SET `npcflag`='0' WHERE  `entry` IN (1502,1504,1505,1890);
DELETE FROM `creature_queststarter` WHERE `id`=1504 AND `quest`=24973;
DELETE FROM `creature_queststarter` WHERE `id`=1505 AND `quest`=24973;
DELETE FROM `creature_queststarter` WHERE `id`=1890 AND `quest`=26801;

UPDATE `creature_template` SET `gossip_menu_id`='0', `npcflag`='4738' WHERE  `entry`=10666;

UPDATE `creature_template` SET `npcflag`='0', `flags_extra`='2' WHERE  `entry`=49422;
DELETE FROM `creature_queststarter` WHERE `id`=49422 AND `quest`=24971;

UPDATE `creature_template` SET `flags_extra`='2' WHERE  `entry`=49423;

DELETE FROM `creature_queststarter` WHERE `id`=1515 AND `quest`=24992;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (1515, 24992);

UPDATE `creature_template_addon` SET `bytes2`='1' WHERE  `entry`=38967;

UPDATE `creature_template` SET `InhabitType`='4' WHERE  `entry`=10716;

DELETE FROM `game_event_creature` WHERE `guid`=10649146;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES (9, 10649146);

UPDATE `quest_template_addon` SET `PrevQuestID`='25029' WHERE  `ID`=25005;

DELETE FROM `creature` WHERE  `guid`=194450;

DELETE FROM `creature_queststarter` WHERE `id`=1500 AND `quest`=25030;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES (1500, 25030);

DELETE FROM `creature_text` WHERE `CreatureID`=1934;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1934, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmer'),
(1934, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmer'),
(1934, 0, 2, 'No, no, no... you took my family, but you won\'t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmer'),
(1934, 0, 3, 'Why won\'t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmer');

DELETE FROM `creature_text` WHERE `CreatureID`=1935;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(1935, 0, 0, 'Get out of my kitchen!', 12, 0, 100, 0, 0, 0, 44544, 0, 'Tirisfal Farmhand'),
(1935, 0, 1, 'Get back, $r!', 12, 0, 100, 0, 0, 0, 44542, 0, 'Tirisfal Farmhand'),
(1935, 0, 2, 'No, no, no... you took my family, but you won\'t take my land!', 12, 0, 100, 0, 0, 0, 44541, 0, 'Tirisfal Farmhand'),
(1935, 0, 3, 'Why won\'t you leave us alone?', 12, 0, 100, 0, 0, 0, 44543, 0, 'Tirisfal Farmhand');

