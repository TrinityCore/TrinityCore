--
SET @TRANSPORT_GUID := 29;
SET @TRANSPORT_ENTRY := 272677;
SET @CGUID := 850000;

DELETE FROM `gameobject_template_addon` WHERE `entry`=@TRANSPORT_ENTRY;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@TRANSPORT_ENTRY, 0, 0x100028, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 142943, 1, 6453, 0, '0', 0, 0, 0, 0, -982.69268798828125, -5769.1474609375, 6.43129730224609375, 1.789803504943847656, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 38134), -- 142943 (Area: 0 - Difficulty: 0)
(@CGUID+1, 142964, 1958, 8499, 9717, '0', 0, 0, 0, 0, 37.68718338012695312, 6.610872745513916015, 7.138050079345703125, 5.743672370910644531, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 38134), -- Golden Skipper Sailor (Area: Bay of Kings - Difficulty: 0)
(@CGUID+2, 142971, 1958, 8499, 9717, '0', 0, 0, 0, 0, 32.22069168090820312, 0.028408050537109375, 13.14441967010498046, 3.159996747970581054, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 38134), -- Navigator Moye (Area: Bay of Kings - Difficulty: 0)
(@CGUID+3, 142972, 1958, 8499, 9717, '0', 0, 0, 0, 0, -15.4023046493530273, 6.615559101104736328, 15.34604835510253906, 5.255162239074707031, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 38134), -- Watcher Char'mayne (Area: Bay of Kings - Difficulty: 0)
(@CGUID+4, 142958, 1958, 8499, 9717, '0', 0, 0, 0, 0, 1.150999307632446289, -0.02078290842473506, 6.332591533660888671, 0.353185951709747314, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 38134); -- Captain Dam'en (Area: Bay of Kings - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '145953'), -- Golden Skipper Sailor
(@CGUID+2, 0, 0, 0, 1, 0, 16390, 0, 0, ''), -- Navigator Moye
(@CGUID+3, 0, 0, 0, 1, 426, 0, 0, 0, ''), -- Watcher Char'mayne
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Captain Dam'en

DELETE FROM `npc_text` WHERE `ID` IN (35974 /*35974*/, 35969 /*35969*/, 35987 /*35987*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(35974, 1, 0, 0, 0, 0, 0, 0, 0, 161135, 0, 0, 0, 0, 0, 0, 0, 38134), -- 35974
(35969, 1, 0, 0, 0, 0, 0, 0, 0, 161114, 0, 0, 0, 0, 0, 0, 0, 38134), -- 35969
(35987, 1, 0, 0, 0, 0, 0, 0, 0, 161154, 0, 0, 0, 0, 0, 0, 0, 38134); -- 35987

DELETE FROM `gossip_menu` WHERE (`MenuId`=23227 AND `TextId`=35974) OR (`MenuId`=23225 AND `TextId`=35969) OR (`MenuId`=23235 AND `TextId`=35987);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(23227, 35974, 38134), -- 142943 (Mith'aka)
(23225, 35969, 38134), -- 142943 (Mith'aka) -- default
(23235, 35987, 38134); -- 142958 (Captain Dam'en)

UPDATE `creature_template` SET `gossip_menu_id`=23225 WHERE `entry`=142943;
UPDATE `creature_template` SET `gossip_menu_id`=23235 WHERE `entry`=142958;
