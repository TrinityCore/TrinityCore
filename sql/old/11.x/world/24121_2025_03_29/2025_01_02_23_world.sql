SET @CGUID := 10005239;

SET @NPCTEXTID := 600070;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 235895, 0, 1519, 5151, '0', 0, 0, 0, 0, -8702.263671875, 845.4930419921875, 98.7685546875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 58238); -- Seeker Najed (Area: Cathedral Square - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=129, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=235895; -- Seeker Najed

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=864, `VerifiedBuild`=58238 WHERE (`Entry`=235895 AND `DifficultyID`=0); -- 235895 (Seeker Najed) - 

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=235895 AND `MenuID`=37663);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(235895, 37663, 58238); -- Seeker Najed

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 279572, 0, 0, 0, 0, 0, 0, 0, 58238); -- 235895 (Seeker Najed)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37663 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37663, @NPCTEXTID+0, 58238); -- 235895 (Seeker Najed)

DELETE FROM `gossip_menu_addon` WHERE `MenuID`=37663;
INSERT INTO `gossip_menu_addon` (`MenuID`, `FriendshipFactionID`, `LfgDungeonsID`, `VerifiedBuild`) VALUES
(37663, 0, 1515, 58238); -- 235895 (Seeker Najed)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37663 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37663, 131517, 0, 1, 'I would like to buy from you.', 2583, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 58238); -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=116554;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116554, 1.22464299201965332, 2.40000009536743164, 0, 58238);

UPDATE `creature_model_info` SET `VerifiedBuild`=58238 WHERE `DisplayID` IN (37311, 37310, 38804, 36786, 47231, 73152, 99506, 39809, 122774, 122773, 18055, 2176, 28507, 338, 3167, 33303, 17063, 37850, 1498, 1500, 45881, 22769, 38800, 1524, 99391, 11686, 1141, 1503, 5446, 125148, 21342, 72724);
UPDATE `creature_model_info` SET `BoundingRadius`=1.030187606811523437, `CombatReach`=2, `VerifiedBuild`=58238 WHERE `DisplayID`=55896;
