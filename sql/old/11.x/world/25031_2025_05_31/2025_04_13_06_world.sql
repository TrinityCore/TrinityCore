SET @CGUID := 7002007;

SET @REFERENCEID := 700002;

-- Creature
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 129783, 1643, 8721, 8721, '0', 0, 0, 0, 0, 251.06597900390625, 2308.475830078125, 34.596527099609375, 3.685004711151123046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257); -- Rindlewoe (Area: Drustvar - Difficulty: 0) CreateObject2

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` = 16721);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(16721, 0, 0, 60257);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` = 12011);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(12011, 0, 16721, 0, 2, 0, 5089, 0, 0, -1, 0, 207, NULL, 10000, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 60257); -- Spell: 257390 (Ground Rot)

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=129783 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `LootID` = 129783, `VerifiedBuild`=60257 WHERE (`Entry`=129783 AND `DifficultyID`=0); -- 129783 (Rindlewoe) - CanSwim - CannotSwim

-- Quest
UPDATE `quest_details` SET `VerifiedBuild`=60257 WHERE `ID`=51547;

DELETE FROM `quest_request_items` WHERE `ID`=51547;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51547, 0, 6, 0, 0, 'Yes?', 60257); -- WANTED: Rindlewoe

DELETE FROM `creature_questender` WHERE (`id`=124417 AND `quest`=51547);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(124417, 51547, 60257); -- WANTED: Rindlewoe ended by Cyril White

-- Loot
DELETE FROM `creature_loot_template` WHERE `Entry` = 129783;
INSERT INTO `creature_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(129783, 1, @REFERENCEID+0, 100, 1, 1, 0, 1, 1, 'Reference World drop junk (drustvar) loot'),
(129783, 1, 700000, 8, 0, 1, 0, 1, 1, 'Reference World drop greens loot');

DELETE FROM `reference_loot_template` WHERE `Entry` = @REFERENCEID+0;
INSERT INTO `reference_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(@REFERENCEID+0, 0, 155610, 0, 0, 1, 1, 1, 1, 'Stinging Nettle'),
(@REFERENCEID+0, 0, 158821, 0, 0, 1, 1, 1, 1, 'Cracked Mask'),
(@REFERENCEID+0, 0, 158857, 0, 0, 1, 1, 1, 1, 'Untainted Wicker');

-- Rindlewoe smart ai
SET @ENTRY := 129783;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 4000, 6000, 10000, 12000, 0, 11, 257390, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 10 - 12 seconds (4 - 6s initially) (IC) - Self: Cast spell  257390 on Self', ''),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 11000, 14000, 0, 11, 257351, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 11 - 14 seconds (10 - 10s initially) (IC) - Self: Cast spell  257351 on Victim', '');

-- Path for Rindlewoe
SET @MOVERGUID := @CGUID+0;
SET @ENTRY := 129783;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Rindlewoe - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 213.76389, 2288.8247, 34.381836, NULL, 0),
(@PATH, 1, 199.66667, 2288.4097, 35.338593, NULL, 0),
(@PATH, 2, 190.23438, 2290.3125, 35.859455, NULL, 0),
(@PATH, 3, 179.93056, 2291.7551, 36.12518, NULL, 0),
(@PATH, 4, 171.4132, 2291.0852, 35.226765, NULL, 0),
(@PATH, 5, 159.42535, 2285.4045, 35.90196, NULL, 0),
(@PATH, 6, 147.9566, 2277.7778, 33.994583, NULL, 0),
(@PATH, 7, 135.52083, 2270.2415, 32.60516, NULL, 0),
(@PATH, 8, 118.43403, 2270.3628, 34.5851, NULL, 0),
(@PATH, 9, 93.854164, 2262.8003, 36.81337, NULL, 0),
(@PATH, 10, 77.30903, 2257.6667, 34.538467, NULL, 0),
(@PATH, 11, 52.918404, 2248.2102, 33.956924, NULL, 0),
(@PATH, 12, 31.60243, 2238.4392, 33.608627, NULL, 0),
(@PATH, 13, 19.078125, 2232.1914, 34.67823, NULL, 0),
(@PATH, 14, 4.2916665, 2225.144, 36.583107, NULL, 16056),
(@PATH, 15, 18.994791, 2232.1545, 34.76701, NULL, 0),
(@PATH, 16, 31.60243, 2238.4392, 33.608627, NULL, 0),
(@PATH, 17, 52.918404, 2248.2102, 33.956924, NULL, 0),
(@PATH, 18, 77.30903, 2257.6667, 34.538467, NULL, 0),
(@PATH, 19, 93.854164, 2262.8003, 36.81337, NULL, 0),
(@PATH, 20, 118.43403, 2270.3628, 34.5851, NULL, 0),
(@PATH, 21, 135.52083, 2270.2415, 32.60516, NULL, 0),
(@PATH, 22, 147.9566, 2277.7778, 33.994583, NULL, 0),
(@PATH, 23, 159.42535, 2285.4045, 35.90196, NULL, 0),
(@PATH, 24, 171.4132, 2291.0852, 35.226765, NULL, 0),
(@PATH, 25, 179.93056, 2291.7551, 36.12518, NULL, 0),
(@PATH, 26, 190.23438, 2290.3125, 35.859455, NULL, 0),
(@PATH, 27, 199.66667, 2288.4097, 35.338593, NULL, 0),
(@PATH, 28, 213.66602, 2288.8203, 34.375385, NULL, 0),
(@PATH, 29, 228.23438, 2294.6858, 35.306408, NULL, 0),
(@PATH, 30, 245.03125, 2304.0173, 35.285767, NULL, 16569),
(@PATH, 31, 228.23438, 2294.6858, 35.306408, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
