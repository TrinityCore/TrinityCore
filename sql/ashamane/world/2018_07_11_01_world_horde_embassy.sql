
/*
	SQL Orgrimmar 
    By Leviathonbeast AKA KittensRJerks For AshamaneCore
*/

-- Remove duplicate spawns --
DELETE FROM gameobject WHERE guid = 175634; -- Northern barrens arrow
DELETE FROM gameobject WHERE guid = 175644; -- Valloy of Strength arrow
DELETE FROM gameobject WHERE guid = 175643; -- Valley of Spirits arrow

-- Remove Bruisers --
DELETE FROM creature WHERE guid = 265850; -- Siegeworker
DELETE FROM creature WHERE guid = 265852; -- Bruiser 
DELETE FROM creature WHERE guid = 265849; -- Siegeworker  
DELETE FROM creature WHERE guid = 265851; -- Siegeworker
DELETE FROM creature WHERE guid = 265825; -- Siegeworker
DELETE FROM creature WHERE guid = 265826; -- Siegeworker
DELETE FROM creature WHERE guid = 265827; -- Siegeworker

DELETE FROM creature WHERE guid = 265779; -- Siegeworker
DELETE FROM creature WHERE guid = 265778; -- Siegeworker

DELETE FROM creature WHERE guid = 265864; -- Siegeworker
DELETE FROM creature WHERE guid = 265862; -- Siegeworker

-- Remove Lanterns --
DELETE FROM gameobject WHERE guid = 205415;
DELETE FROM gameobject WHERE guid = 205428;
DELETE FROM gameobject WHERE guid = 205452;
DELETE FROM gameobject WHERE guid = 205466;
DELETE FROM gameobject WHERE guid = 205499;
DELETE FROM gameobject WHERE guid = 205509;
DELETE FROM gameobject WHERE guid = 205511;
DELETE FROM gameobject WHERE guid = 205528;
DELETE FROM gameobject WHERE guid = 205533;
DELETE FROM gameobject WHERE guid = 205540;
DELETE FROM gameobject WHERE guid = 205541;
DELETE FROM gameobject WHERE guid = 205554;
DELETE FROM gameobject WHERE guid = 205555;
DELETE FROM gameobject WHERE guid = 205571;
DELETE FROM gameobject WHERE guid = 205588;
DELETE FROM gameobject WHERE guid = 205608;
DELETE FROM gameobject WHERE guid = 205610;
DELETE FROM gameobject WHERE guid = 205632;
DELETE FROM gameobject WHERE guid = 205637;
DELETE FROM gameobject WHERE guid = 205651;


-- Not correct spawns --
DELETE FROM gameobject WHERE guid = 175653; -- barrel
DELETE FROM gameobject WHERE guid = 175657; -- barrel #2
DELETE FROM gameobject WHERE guid = 175628; -- mailbox
-- DELETE FROM gameobject WHERE guid = 175737; -- Barrel of Kezan -- not sure about this... on further research i should not remove but its in the fucking way

SET @CGUID=210119246;
SET @OGUID=21005000;

DELETE FROM `creature`          WHERE guid BETWEEN @CGUID+1 AND @CGUID+9;
DELETE FROM `creature_addon`    WHERE guid BETWEEN @CGUID+1 AND @CGUID+9;
DELETE FROM `gameobject`        WHERE guid BETWEEN @OGUID+1 AND @OGUID+3;

-- Missing guards note i have not set a phaseid --
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 3296, 1, 1637, 5170, 1, 0, 0, 0, 0, 1577.226, -4190.236, 54.08125, 3.81535, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 3296
(@CGUID+2, 74228, 1, 1637, 5170, 1, 0, 0, 0, 0, 1556.153809, -4192.720215, 54.313965, 5.011764, 120, 10, 0, 0, 0, 0, 0, 0, 0, 26972); -- 74228 beta need to fix orientation more sniff needed.

-- Gameobject missing in templates --
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(273300, 5, 33135, 'Gallywix''s Throne', '', '', '', 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 273300

 /* 
 
 #######################################################
 
 Embassy Spawns Time :D note i have not set a phaseid
 ALL BELOW IS FOR EMBASSY SPAWNS ONLY 
 
 ########################################################
 
 */

-- Gameobject missing in templates --
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(273300, 5, 33135, 'Gallywix''s Throne', '', '', '', 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 273300

-- gally needs his throne --
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 273300, 1, 1637, 5170, 1, 0, 0, 1536.797, -4171.738, 58.21138, 3.706333, 0, 0, -0.9603977, 0.2786328, 120, 255, 1, 26972); -- 273300

-- his throne needs a gally --
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+3, 133522, 1, 1637, 5170, 1, 0, 0, 0, 0, 1536.786, -4171.634, 59.16446, 0.583652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 133522 (Area: 5170 - Difficulty: 0)

-- forgot to make him have gossip --
UPDATE creature_template SET npcflag=1 WHERE entry = 133522;
UPDATE creature_template SET npcflag=1 WHERE entry = 125285;
UPDATE creature_template SET npcflag=1 WHERE entry = 133521;
UPDATE creature_template SET npcflag=1 WHERE entry = 126066;
UPDATE creature_template SET npcflag=1 WHERE entry = 126062;
UPDATE creature_template SET npcflag=1 WHERE entry = 133519;
UPDATE creature_template SET npcflag=1 WHERE entry = 133523;

-- missing npc_text data --
DELETE FROM `npc_text` WHERE `ID` IN (33550, 34003, 34004, 34001, 34005, 33999, 33549);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33550, 1, 0, 0, 0, 0, 0, 0, 0, 143290, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33550
(34003, 1, 0, 0, 0, 0, 0, 0, 0, 147234, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34003
(34004, 1, 0, 0, 0, 0, 0, 0, 0, 147235, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34004
(34001, 1, 0, 0, 0, 0, 0, 0, 0, 147240, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34001
(34005, 1, 0, 0, 0, 0, 0, 0, 0, 147238, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34005
(33999, 1, 0, 0, 0, 0, 0, 0, 0, 147236, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33999
(33549, 1, 0, 0, 0, 0, 0, 0, 0, 143287, 0, 0, 0, 0, 0, 0, 0, 26972); -- 33549

DELETE FROM `gossip_menu` WHERE `MenuId` IN (22197, 21937, 22191, 22193, 21938, 22196, 22195);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22197, 34005), -- 133522
(21937, 33549), -- 125285
(22191, 33999), -- 133521
(22193, 34001), -- 126066
(21938, 33550), -- 126062
(22196, 34004), -- 133519
(22195, 34003); -- 133523

UPDATE creature_template SET gossip_menu_id = 22197 WHERE entry = 133522;
UPDATE creature_template SET gossip_menu_id = 21937 WHERE entry = 125285;
UPDATE creature_template SET gossip_menu_id = 22191 WHERE entry = 133521;
UPDATE creature_template SET gossip_menu_id = 22193 WHERE entry = 126066;
UPDATE creature_template SET gossip_menu_id = 21938 WHERE entry = 126062;
UPDATE creature_template SET gossip_menu_id = 22196 WHERE entry = 133519;
UPDATE creature_template SET gossip_menu_id = 22195 WHERE entry = 133523;

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (21938, 21937);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(21938, 0, 0, 'What do we know about the nightborne?', 0),
(21937, 0, 0, 'What do we know about the Highmountain tauren?', 0);

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+4, 125285, 1, 1637, 5332, 1, 0, 0, 0, 0, 1546.333, -4170.707, 58.09132, 1.636336, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 125285
(@CGUID+5, 133521, 1, 1637, 5170, 1, 0, 0, 0, 0, 1541.425, -4167.842, 58.09119, 0.3275496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133521 (Area: 5170 - Difficulty: 0)
(@CGUID+6, 126066, 1, 1637, 5170, 1, 0, 0, 0, 0, 1544.938, -4152.069, 58.35732, 5.166722, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126066 (Area: 5170 - Difficulty: 0)
(@CGUID+7, 126062, 1, 1637, 5332, 1, 0, 0, 0, 0, 1552.439, -4166.842, 58.09555, 2.668837, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126062 (Area: 5332 - Difficulty: 0) (Auras: 165746 - 165746)
(@CGUID+8, 133519, 1, 1637, 5170, 1, 0, 0, 0, 0, 1554.564, -4163.147, 58.08749, 3.217828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133519 (Area: 5170 - Difficulty: 0)
(@CGUID+9, 133523, 1, 1637, 5170, 1, 0, 0, 0, 0, 1559.297, -4169.566, 58.35718, 2.710399, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 133523 (Area: 5170 - Difficulty: 0)

INSERT INTO creature_addon (`guid`, `bytes1`, `bytes2`)VALUES
(@CGUID+5,8,1),
(@CGUID+8,1,1),
(@CGUID+9,1,1);

-- Add the gameobjects finally --
INSERT IGNORE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `ScriptName`, `VerifiedBuild`) VALUES
(273293, 22, 47679, 'Nightborne', 'inspect', '', '', 1, 257928, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_allied_race_infos_nightborne', 26972), -- 273293
(273286, 22, 47678, 'Highmountain Tauren', 'inspect', '', '', 0.9, 257927, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_allied_race_infos_tauren', 26972); -- 273286

INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+2, 273286, 1, 1637, 5170, 1, 0, 0, 1541.583, -4162.396, 58.01303, 5.395095, 0, 0, -0.4295959, 0.9030212, 120, 255, 1, 26972), -- 273286 (Area: 5170 - Difficulty: 0)
(@OGUID+3, 273293, 1, 1637, 5170, 1, 0, 0, 1545.828, -4159.382, 58.01303, 5.406131, 0, 0, -0.4246063, 0.9053781, 120, 255, 1, 26972); -- 273293 (Area: 5170 - Difficulty: 0)
