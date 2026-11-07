SET @CGUID := 7001500;
SET @OGUID := 7000367;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 135668, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7077.6318359375, 1286.4132080078125, -93.3216018676757812, 1.375190377235412597, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Cenarion Circle Druid (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+1, 135671, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7077.59375, 1289.53125, -93.3216018676757812, 4.647860527038574218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Ring Shaman (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+2, 135671, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7074.91650390625, 1287.267333984375, -93.3216094970703125, 2.661725044250488281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Ring Shaman (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+3, 135668, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7079.439453125, 1288.407958984375, -93.345855712890625, 0.140284672379493713, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Cenarion Circle Druid (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+4, 135671, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7082.34375, 1300.8646240234375, -93.32086181640625, 0.580006659030914306, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Ring Shaman (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+5, 142294, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7094.9130859375, 1283.140625, -93.3216094970703125, 0.291540503501892089, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Broll Bearmantle (Area: Magni's Encampment - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+6, 135671, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7100.99853515625, 1290.51220703125, -93.3498001098632812, 1.635851502418518066, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Ring Shaman (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+7, 142299, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7066.34375, 1264, -92.6266860961914062, 4.999609947204589843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Archdruid Hamuul Runetotem (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+8, 143682, 1, 9310, 9609, '0', 10277, 0, 0, 0, -7088.53125, 1304.046875, -93.317291259765625, 5.080197811126708984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Guardian (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+9, 135917, 1, 9310, 9609, '0', 10277, 0, 0, 0, -7096.19970703125, 1259.6597900390625, -103.626495361328125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Invisible Bunny (Area: Magni's Encampment - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+10, 142306, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7094.330078125, 1286.4010009765625, -93.3216094970703125, 0.274800419807434082, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Zen'kiki (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+11, 130216, 1, 9310, 9609, '0', 10277, 0, 0, 0, -7071.03466796875, 1269.8072509765625, -91.7991104125976562, 5.441308975219726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Magni Bronzebeard (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+12, 135671, 1, 9310, 9609, '0', 10277, 0, 0, 1, -7091.0537109375, 1278.8975830078125, -93.7717819213867187, 4.259976387023925781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Earthen Ring Shaman (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+13, 135917, 1, 9310, 9609, '0', 10277, 0, 0, 0, -7076.41845703125, 1218.7117919921875, -107.939201354980468, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Invisible Bunny (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+14, 152643, 1, 9310, 9609, '0', 0, 0, 0, 0, -7077.20166015625, 1230.3975830078125, -113.2498779296875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Despawn Bunny (Area: Magni's Encampment - Difficulty: 0) CreateObject1 (Auras: 182641 - Game Object Despawn Periodic)
(@CGUID+15, 152248, 1, 9310, 9609, '0', 0, 0, 0, 0, -7077.173828125, 1230.5816650390625, -112.524917602539062, 0.116791330277919769, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933), -- Invisible Stalker (Area: Magni's Encampment - Difficulty: 0) CreateObject1
(@CGUID+16, 137606, 1, 9310, 9609, '0', 0, 0, 0, 0, -7077.173828125, 1230.5816650390625, -112.524917602539062, 0.116791330277919769, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 55933); -- Invisible Stalker (Area: Magni's Encampment - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 1320, 0, 0, 0, ''), -- Earthen Ring Shaman
(@CGUID+6, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Earthen Ring Shaman

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 289698, 1, 9310, 9609, '0', 10277, 0, -7086.69970703125, 1299.685791015625, -93.404937744140625, 5.971129894256591796, 0, 0, -0.1553955078125, 0.987852334976196289, 120, 255, 1, 55933); -- Portal to Tiragarde (Area: Magni's Encampment - Difficulty: 0) CreateObject1

-- TerrainSwap
UPDATE `creature` SET `terrainSwapMap` = 1817 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+16;
UPDATE `gameobject` SET `terrainSwapMap` = 1817 WHERE `guid` = @OGUID+0;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (142306, 135671, 135668);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(142306, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 142306 (Zen'kiki)
(135671, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 135671 (Earthen Ring Shaman)
(135668, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 135668 (Cenarion Circle Druid)

-- Template
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` IN (137606, 152248, 135917, 152643);

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 10277;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10277, 'Cosmetic - See Magnis Encampment');

DELETE FROM `phase_area` WHERE `PhaseId` = 10277; 
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9310, 10277, 'Cosmetic - See Magnis Encampment');

-- Earthen Ring Shaman smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (135671, 135668);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+12), -(@CGUID+1), -(@CGUID+0));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+12), 0, 0, 0, '', 1, 0, 100, 0, 5000, 5000, 25000, 25000, 80, 13567100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 25 seconds (5s initially) (OOC) - Self: Start timed action list id #Earthen Ring Shaman #0 (13567100) (update out of combat)'),
(-(@CGUID+1), 0, 0, 0, '', 1, 0, 100, 0, 2000, 7000, 2000, 7000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds (OOC) - Self: Play emote 1'),
(-(@CGUID+0), 0, 0, 0, '', 1, 0, 100, 0, 2000, 7000, 2000, 7000, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds (OOC) - Self: Play emote 1');

-- Timed list 13567100 smart ai
SET @ENTRY := 13567100;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 267277, 0, 0, 0, 0, 0, 19, 135917, 25, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell  267277 on Closest alive creature Invisible Bunny (135917) in 25 yards'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 8000, 8000, 0, 0, 85, 267288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Cast spell 267288 on self'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 85, 267288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Cast spell 267288 on self'),
(@ENTRY, 9, 3, 0, '', 0, 0, 100, 0, 5000, 5000, 0, 0, 85, 267288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Cast spell 267288 on self');

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55933 WHERE (`Entry`=137606 AND `DifficultyID`=0); -- 137606 (Invisible Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55933 WHERE (`Entry`=152248 AND `DifficultyID`=0); -- 152248 (Invisible Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=142306 AND `DifficultyID`=0); -- 142306 (Zen'kiki) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=55933 WHERE (`Entry`=135917 AND `DifficultyID`=0); -- 135917 (Invisible Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=143682 AND `DifficultyID`=0); -- 143682 (Earthen Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=142299 AND `DifficultyID`=0); -- 142299 (Archdruid Hamuul Runetotem) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=142294 AND `DifficultyID`=0); -- 142294 (Broll Bearmantle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=135671 AND `DifficultyID`=0); -- 135671 (Earthen Ring Shaman) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55933 WHERE (`Entry`=135668 AND `DifficultyID`=0); -- 135668 (Cenarion Circle Druid) - CanSwim

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=130216 AND `item`=160544 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=130216 AND `item`=163515 AND `ExtendedCost`=6430 AND `type`=1) OR (`entry`=130216 AND `item`=163555 AND `ExtendedCost`=6424 AND `type`=1) OR (`entry`=130216 AND `item`=161563 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161560 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161557 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161555 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=160537 AND `ExtendedCost`=6305 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(130216, 8, 160544, 0, 6306, 1, 0, 0, 55933), -- Champions of Azeroth Tabard
(130216, 7, 163515, 0, 6430, 1, 0, 0, 55933), -- Shard of Azerite
(130216, 6, 163555, 0, 6424, 1, 0, 0, 55933), -- Drop of Azerite
(130216, 5, 161563, 0, 6312, 1, 0, 0, 55933), -- Helm of the Azerothian Champion
(130216, 4, 161560, 0, 6312, 1, 0, 0, 55933), -- Azerothian Champion's Spaulders
(130216, 3, 161557, 0, 6312, 1, 0, 0, 55933), -- Vest of the Azerothian Champion
(130216, 2, 161555, 0, 6312, 1, 0, 0, 55933), -- Azerothian Champion's Crown
(130216, 1, 160537, 0, 6305, 1, 0, 0, 55933); -- Drape of the Azerothian Champion
