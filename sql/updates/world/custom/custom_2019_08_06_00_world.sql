
DELETE FROM `gossip_menu_option` WHERE `MenuID`= 11492;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `OptionType`, `VerifiedBuild`) VALUES
(11492, 0, 0, '<Place my hand on the orb.>', 9859, 1, 1, 26365);

SET @CGUID := 259778;
DELETE FROM `creature` WHERE `guid`= @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, 41379, 669, 5094, 0, 15, 169, 0, 0, 0, -166.655, -224.602, 40.48163, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26365); -- Lord Victor Nefarius

-- Spawn Group
DELETE FROM `spawn_group_template` WHERE `groupId`= 402;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(402, 'Blackwing Descent - Nefarian''s End', 0);

DELETE FROM `spawn_group` WHERE `groupId`= 402;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(402, 0, @CGUID);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`= 669;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(669, 0, 8, 402, 1), -- Magmaw
(669, 1, 55, 402, 2), -- Omnotron Defense System
(669, 2, 55, 402, 2), -- Chimaeron
(669, 3, 55, 402, 2), -- Atramedes
(669, 4, 55, 402, 2); -- Maloriak

-- Addons
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID, 0, 0, 0, 1, 0, '78494'); -- Lord Victor Nefarius - 78494 - Aura of Dread
