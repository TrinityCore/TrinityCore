SET @CGUID := 6005276;
SET @OGUID := 6002884;

SET @ATID := 160;
SET @ATCP := 155;
SET @ATIDSPAWN := 254;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 101513, 1220, 7502, 8011, '0', 0, 0, 0, 1, -957.11981201171875, 4548.75244140625, 698.2386474609375, 6.16636514663696289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Lord Jorach Ravenholdt (Area: The Hall of Shadows - Difficulty: 0) CreateObject1 (Auras: 49414 - Generic Quest Invisibility 1)
(@CGUID+1, 94159, 1220, 7502, 8011, '0', 0, 0, 0, 1, -949.3836669921875, 4549.3203125, 698.2386474609375, 4.57002115249633789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Fleet Admiral Tethys (Area: The Hall of Shadows - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 98102, 1220, 7502, 8011, '0', 0, 0, 0, 1, -951.607666015625, 4550.24853515625, 698.09344482421875, 4.440804481506347656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Valeera Sanguinar (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@CGUID+3, 98100, 1220, 7502, 8011, '0', 0, 0, 0, 1, -954.5069580078125, 4551.02783203125, 697.77392578125, 4.549866199493408203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Taoshi (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@CGUID+4, 105908, 1220, 7502, 8011, '0', 0, 0, 0, 1, -934.28472900390625, 4427.54541015625, 706.442138671875, 3.948340892791748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Milton Beats (Area: The Hall of Shadows - Difficulty: 0) CreateObject1 (Auras: 30831 - Stealth)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3, ''), -- Lord Jorach Ravenholdt - 49414 - Generic Quest Invisibility 1
(@CGUID+1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Fleet Admiral Tethys
(@CGUID+2, 0, 0, 0, 0, 0, 0, 0, 0, 7664, 0, 0, 0, ''), -- Valeera Sanguinar
(@CGUID+3, 0, 0, 0, 0, 0, 0, 0, 0, 10059, 0, 0, 0, ''), -- Taoshi
(@CGUID+4, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, '30831'); -- Milton Beats - 30831 - Stealth

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 249382, 1220, 7502, 8011, '0', 0, 0, -916.75347900390625, 4534.22119140625, 706.99737548828125, 2.306526422500610351, 0, 0, 0.914092063903808593, 0.405506700277328491, 120, 255, 1, 61609), -- Torch (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+1, 246386, 1220, 7502, 8011, '0', 0, 0, -914.94097900390625, 4536.14306640625, 706.22210693359375, 0.902083992958068847, 0, 0, 0.435903549194335937, 0.899993360042572021, 120, 255, 1, 61609), -- Bookcase (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+2, 246386, 1220, 7502, 8011, '0', 0, 0, -912.765625, 4538.8134765625, 706.22210693359375, 4.02302408218383789, 0, 0, -0.90444660186767578, 0.426586836576461791, 120, 255, 1, 61609), -- Bookcase (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+3, 246387, 1220, 7502, 8011, '0', 0, 0, -909.796875, 4538.94189453125, 707.64166259765625, 5.559861183166503906, 0, 0, -0.35382938385009765, 0.935309946537017822, 120, 255, 1, 61609), -- Torch (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+4, 259421, 1220, 7502, 8011, '0', 0, 0, -952.70831298828125, 4545.66162109375, 698.1552734375, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+5, 249694, 1220, 7502, 8011, '0', 0, 0, -950.171875, 4548.59033203125, 699.0997314453125, 2.401534318923950195, 0, 0, 0.932316780090332031, 0.361642658710479736, 120, 255, 1, 61609), -- Mug (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+6, 259420, 1220, 7502, 8011, '0', 0, 0, -950.2777099609375, 4545.18408203125, 698.1552734375, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+7, 259419, 1220, 7502, 8011, '0', 0, 0, -951.77392578125, 4550.14208984375, 698.1552734375, 4.529129981994628906, 0, 0, -0.76884174346923828, 0.639439105987548828, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+8, 246670, 1220, 7502, 8011, '0', 0, 0, -955.09552001953125, 4546.1806640625, 698.15533447265625, 1.424152970314025878, 0, 0, 0.653407096862792968, 0.757006764411926269, 120, 255, 0, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+9, 259422, 1220, 7502, 8011, '0', 0, 0, -949.342529296875, 4549.61083984375, 698.1552734375, 4.529129981994628906, 0, 0, -0.76884174346923828, 0.639439105987548828, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+10, 246196, 1220, 7502, 8011, '0', 0, 0, -948.78302001953125, 4549.611328125, 698.15216064453125, 6.165768623352050781, 0, 0, -0.05867481231689453, 0.998277187347412109, 120, 255, 1, 61609), -- Bottle (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+11, 259418, 1220, 7502, 8011, '0', 0, 0, -954.4658203125, 4550.77392578125, 698.1552734375, 4.529129981994628906, 0, 0, -0.76884174346923828, 0.639439105987548828, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+12, 259417, 1220, 7502, 8011, '0', 0, 0, -957.6534423828125, 4548.88720703125, 698.1552734375, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+13, 268621, 1220, 7502, 8011, '0', 0, 0, -957.80731201171875, 4534.05712890625, 698.15533447265625, 1.004240393638610839, 0, 0, 0.48128509521484375, 0.8765641450881958, 120, 255, 1, 61609), -- Training Troops (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+14, 259424, 1220, 7502, 8011, '0', 0, 0, -966.65216064453125, 4546.357421875, 698.1552734375, 6.143558979034423828, 0, 0, -0.06975650787353515, 0.997564077377319335, 120, 255, 1, 61609), -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1
(@OGUID+15, 259423, 1220, 7502, 8011, '0', 0, 0, -939.01708984375, 4534.65625, 698.1552734375, 2.539454221725463867, 0, 0, 0.955019950866699218, 0.296541541814804077, 120, 255, 1, 61609); -- Chair (Area: The Hall of Shadows - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 4668, 8182), -- Torch
(@OGUID+3, 0, 0, 0, 1, 4668, 8182), -- Torch
(@OGUID+4, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+6, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+7, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+9, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+11, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+12, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+14, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0), -- Chair
(@OGUID+15, 0, 0, -0.33380699157714843, 0.942641437053680419, 0, 0); -- Chair

-- Serverside ATs
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1) OR (`Id` = @ATID+1 AND `IsCustom` = 1) OR (`Id` = @ATID+2 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0),
(@ATID+2, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+2;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1220, '0', -965.3556, 4431.0634, 735.739, 5.068916, 0, 0, 0, 'SmartAreaTriggerAI', 'The Hall of Shadowa - Enter Hall of Shadows Credit (Quest: "Call of the Uncrowned")', 0),
(@ATIDSPAWN+1, @ATCP+1, 1, 1220, '0', -940.9575, 4421.9287, 706.360, 0.881968, 0, 0, 0, 'at_hall_of_shadows_call_of_the_uncrowned_clone_milton', 'The Hall of Shadowa - Create Clone: Milton Beats (Quest: "Call of the Uncrowned")', 0),
(@ATIDSPAWN+2, @ATCP+2, 1, 1220, '0', -951.5925, 4547.7856, 699.119, 2.959997, 0, 0, 0, 'SmartAreaTriggerAI', 'The Hall of Shadowa - Find "The Uncrowned" (Quest: "Call of the Uncrowned")', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1) OR (`Id`= @ATCP+1 AND `IsCustom`=1) OR (`Id`= @ATCP+2 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 1, 4, 3, 3, 4, 3, 3, 0, 0, '', 0),
(@ATCP+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 1, 11, 15, 5, 11, 15, 5, 0, 0, '', 0),
(@ATCP+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 20, 20, 0, 0, 0, 0, 0, 0, '', 0);

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 102018;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(102018, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '201212'); -- 102018 (Ravenholdt Courier) - Don't Kill the Messenger

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (251966 /*Smuggled Weaponry*/, 246670 /*Chair*/, 253044 /*Pillow*/, 252188 /*Requisitioned Seal of Fate*/, 250897 /*Training Troops*/, 268621 /*Training Troops*/, 250898 /*Training Troops*/, 244798 /*Bloodied Trophy*/, 259417 /*Chair*/, 259419 /*Chair*/, 259418 /*Chair*/, 259437 /*Chair*/, 259438 /*Chair*/, 259433 /*Chair*/, 259435 /*Chair*/, 259434 /*Chair*/, 259431 /*Chair*/, 241920 /*Barbershop Chair*/, 249516 /*Crucible of the Uncrowned*/, 259427 /*Chair*/, 259421 /*Chair*/, 259420 /*Chair*/, 259422 /*Chair*/, 246387, 249382);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(251966, 0, 0x40000, 0, 0), -- Smuggled Weaponry
(246670, 0, 0x40000, 0, 0), -- Chair
(253044, 1375, 0x10, 0, 0), -- Pillow
(252188, 0, 0x40000, 0, 0), -- Requisitioned Seal of Fate
(250897, 0, 0x40000, 0, 0), -- Training Troops
(268621, 0, 0x40000, 0, 0), -- Training Troops
(250898, 0, 0x40000, 0, 0), -- Training Troops
(244798, 0, 0x2000, 0, 0), -- Bloodied Trophy
(259417, 114, 0x0, 0, 0), -- Chair
(259419, 114, 0x0, 0, 0), -- Chair
(259418, 114, 0x0, 0, 0), -- Chair
(259437, 114, 0x0, 0, 0), -- Chair
(259438, 114, 0x0, 0, 0), -- Chair
(259433, 114, 0x0, 0, 0), -- Chair
(259435, 114, 0x0, 0, 0), -- Chair
(259434, 114, 0x0, 0, 0), -- Chair
(259431, 114, 0x0, 0, 0), -- Chair
(241920, 0, 0x0, 16227, 0), -- Barbershop Chair
(249516, 0, 0x42000, 0, 0), -- Crucible of the Uncrowned
(259427, 114, 0x0, 0, 0), -- Chair
(259421, 114, 0x0, 0, 0), -- Chair
(259420, 114, 0x0, 0, 0), -- Chair
(259422, 114, 0x0, 0, 0), -- Chair
(246387, 0, 0x40000, 4668, 8182), -- Torch
(249382, 0, 0x40000, 4668, 8182); -- Torch

-- Template
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=102018; -- Ravenholdt Courier
UPDATE `creature_template` SET `faction`=2789, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=105908; -- Milton Beats
UPDATE `creature_template` SET `faction`=2789, `npcflag`=3, `BaseAttackTime`=1300, `unit_flags`=0x300, `unit_flags2`=0x800, `VehicleId`=4563 WHERE `entry`=94159; -- Fleet Admiral Tethys
UPDATE `creature_template` SET `faction`=2789, `npcflag`=3, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=94138; -- Princess Tess Greymane
UPDATE `creature_template` SET `faction`=2789, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4800, `unit_flags3`=0x40000000 WHERE `entry`=98102; -- Valeera Sanguinar
UPDATE `creature_template` SET `faction`=2789, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=98100; -- Taoshi

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=102018 AND `DifficultyID`=0); -- 102018 (Ravenholdt Courier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=105908 AND `DifficultyID`=0); -- 105908 (Milton Beats) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=94159 AND `DifficultyID`=0); -- 94159 (Fleet Admiral Tethys) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `StaticFlags3`=0x2000000, `VerifiedBuild`=61609 WHERE (`Entry`=94138 AND `DifficultyID`=0); -- 94138 (Princess Tess Greymane) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61609 WHERE (`Entry`=98102 AND `DifficultyID`=0); -- 98102 (Valeera Sanguinar) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61609 WHERE (`Entry`=98100 AND `DifficultyID`=0); -- 98100 (Taoshi) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=633, `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=94159 AND `DifficultyID`=0); -- 94159 (Fleet Admiral Tethys) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=101513 AND `DifficultyID`=0); -- 101513 (Lord Jorach Ravenholdt) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (1101, 1100, 1103);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(1101, 2704, 0, 61609),
(1100, 2699, 0, 61609),
(1103, 2818, 0, 61609);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_on_summon_call_of_the_uncrowned' WHERE `Id` = 1100;

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (1100,1101)) OR (`ConversationId`=1103 AND `Idx` IN (3,2,1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(1100, 51066, 0, 0, 0, 0, 0, 0, 61609), -- Full: 0x0
(1101, 51080, 0, 0, 101513, 69542, 0, 0, 61609),
(1103, 51091, (@CGUID+0), 3, 0, 0, 0, 0, 61609), -- Full: 0x203AE49880632240006E9500006A92D5 Creature/0 R3769/S28309 Map: 1220 (Broken Isles) Entry: 101513 (Lord Jorach Ravenholdt) Low: 6984405
(1103, 51261, (@CGUID+3), 2, 0, 0, 0, 0, 61609), -- Full: 0x203AE498805FCD00006E9500006A92D5 Creature/0 R3769/S28309 Map: 1220 (Broken Isles) Entry: 98100 (Taoshi) Low: 6984405
(1103, 51262, (@CGUID+2), 1, 0, 0, 0, 0, 61609), -- Full: 0x203AE498805FCD80006E9500006A92D5 Creature/0 R3769/S28309 Map: 1220 (Broken Isles) Entry: 98102 (Valeera Sanguinar) Low: 6984405
(1103, 51260, (@CGUID+1), 0, 0, 0, 0, 0, 61609); -- Full: 0x243AE498805BF3C0006E9500006A92D5 Vehicle/0 R3769/S28309 Map: 1220 (Broken Isles) Entry: 94159 (Fleet Admiral Tethys) Low: 6984405

DELETE FROM `conversation_line_template` WHERE `Id` IN (2703, 2702, 2701, 2700, 2699, 2706, 2705, 2704, 4249, 4248, 2710, 2818);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(2703, 0, 0, 0, 0, 61609),
(2702, 0, 0, 0, 0, 61609),
(2701, 0, 0, 0, 0, 61609),
(2700, 0, 0, 0, 0, 61609),
(2699, 0, 0, 0, 0, 61609),
(2706, 82, 0, 0, 0, 61609),
(2705, 82, 0, 0, 0, 61609),
(2704, 82, 0, 0, 0, 61609),
(4249, 0, 3, 0, 0, 61609),
(4248, 0, 2, 0, 0, 61609),
(2710, 0, 1, 1, 0, 61609),
(2818, 0, 0, 0, 0, 61609);

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1443;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1443, 16, 1720, 0);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (102018,105908);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(102018, 0, 0, 'This is for your eyes only. Once you\'ve read it, destroy it.', 12, 0, 100, 0, 0, 0, 104305, 0, 'Ravenholdt Courier to Player'),
(102018, 1, 0, 'Farewell.', 12, 0, 100, 1, 0, 0, 0, 0, 'Ravenholdt Courier to Player'),
(105908, 0, 0, 'Only a fool walks into the Hall of Shadows unaware! Prepare to--', 12, 0, 100, 0, 0, 0, 104326, 0, 'Milton Beats to Player'),
(105908, 1, 0, 'Oh $p, I didn\'t realize it was you... my apologies. The Uncrowned await your arrival.', 12, 0, 100, 396, 0, 0, 108826, 0, 'Milton Beats to Player');

-- Creature
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (102605,105976)) OR (`ID`=2 AND `CreatureID`=106054);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(102605, 1, 113918, 0, 0, 113918, 0, 0, 0, 0, 0, 61609), -- Tear
(105976, 1, 13612, 0, 0, 0, 0, 0, 0, 0, 0, 61609), -- Vinemaster Suntouched
(106054, 2, 45123, 0, 0, 2711, 0, 0, 0, 0, 0, 61609); -- Kareth

-- SpellScript
DELETE FROM `spell_script_names` WHERE `spell_id` = 201253;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(201253, 'spell_dalaran_sealed_letter');

-- Spelltarget
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (209893,201324));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 209893, 0, 0, 51, 0, 8, 251033, 0, '', 0, 'Potential target of the spell is TYPEID_GAMEOBJECT, entry is 251033'),
(13, 1, 201324, 0, 0, 51, 0, 8, 246386, 0, '', 0, 'Potential target of the spell is TYPEID_GAMEOBJECT, entry is 246386');

-- Gossip
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (19540));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 19540, 0, 0, 0, 47, 0, 40832, 74, 0, '', 0, 'Player for which gossip text is shown has Call of The Uncrowned (40832) in state complete, incomplete, rewarded'),
(15, 19540, 0, 0, 0, 48, 0, 281276, 0, 1, '', 0, 'Player for which gossip text is shown has quest objective 281276 == 1 (but hasn\'t rewarded quest yet)');

-- Quest
DELETE FROM `quest_template` WHERE `ID` = 50804;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `FlagsEx3`, `RewardItem1`, `RewardAmount1`, `RewardItem2`, `RewardAmount2`, `RewardItem3`, `RewardAmount3`, `RewardItem4`, `RewardAmount4`, `ItemDrop1`, `ItemDropQuantity1`, `ItemDrop2`, `ItemDropQuantity2`, `ItemDrop3`, `ItemDropQuantity3`, `ItemDrop4`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemQuantity1`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemID2`, `RewardChoiceItemQuantity2`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemID3`, `RewardChoiceItemQuantity3`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemID4`, `RewardChoiceItemQuantity4`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemID5`, `RewardChoiceItemQuantity5`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardFactionID1`, `RewardFactionValue1`, `RewardFactionOverride1`, `RewardFactionCapIn1`, `RewardFactionID2`, `RewardFactionValue2`, `RewardFactionOverride2`, `RewardFactionCapIn2`, `RewardFactionID3`, `RewardFactionValue3`, `RewardFactionOverride3`, `RewardFactionCapIn3`, `RewardFactionID4`, `RewardFactionValue4`, `RewardFactionOverride4`, `RewardFactionCapIn4`, `RewardFactionID5`, `RewardFactionValue5`, `RewardFactionOverride5`, `RewardFactionCapIn5`, `RewardFactionFlags`, `RewardCurrencyID1`, `RewardCurrencyQty1`, `RewardCurrencyID2`, `RewardCurrencyQty2`, `RewardCurrencyID3`, `RewardCurrencyQty3`, `RewardCurrencyID4`, `RewardCurrencyQty4`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `QuestCompletionLog`, `ResetByScheduler`, `VerifiedBuild`) VALUES
(50804, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Rogue Orderhall: Entered Hall of Shadows for the first time', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0);

DELETE FROM `quest_request_items` WHERE `ID`=40832;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(40832, 0, 0, 0, 0, 'Welcome.', 61609); -- Call of The Uncrowned

DELETE FROM `creature_queststarter` WHERE (`id`=102018 AND `quest`=40832);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(102018, 40832, 61609); -- Call of The Uncrowned offered by Ravenholdt Courier

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` = 281292;
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(281292, NULL, NULL, 1103, 0, 0);

-- Serverside ATs smart ai
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ATID+0 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 33, 102086, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - reward Credit 102086 to Invoker'),
(@ATID+0, 12, 0, 1, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 152, 50804, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - reward tracking Quest 50804 to Invoker');

DELETE FROM `smart_scripts` WHERE `entryorguid` = @ATID+2 AND `source_type` = 12;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+2, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 201328, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - invoker: selfcast 201328');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 28 AND `SourceGroup` = (@ATID+2) AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, @ATID+2, 1, 0, 0, 47, 0, 40832, 8, 0, '', 0, 0, 0, '', 'Only trigger areatrigger when quest 34423 is in progress');

-- Ravenholdt Courier smart ai
SET @ENTRY := 102018;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10201800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Ravenholdt Courier #0 (10201800) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 19, 0, 100, 0, 40832, 0, 0, 0, 0, 80, 10201801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Call of The Uncrowned (40832) - Self: Start timed action list id #Ravenholdt Courier #1 (10201801) (update out of combat)', '');

-- Timed list 10201800 smart ai
SET @ENTRY := 10201800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 29, 2, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Follow Owner/Summoner by distance 2, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 85, 201214, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Cast spell 201214 on self', '');

-- Timed list 10201801 smart ai
SET @ENTRY := 10201801;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Owner/Summoner: Talk 1 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 201234, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 201234 on self', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 20, 0, 0, 'After 3 seconds - Self: Move forward by 0, left by 20, up by 0 yards', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 85, 24222, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast spell 24222 on self', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 105318, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 105318 on self', ''),
(@ENTRY, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 1 s', '');

-- "Red" Jack Findle smart ai
SET @ENTRY := 97004;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 19540, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19540 selected - Gossip player: Talk 1 to invoker', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 209918, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19540 selected - Gossip player: Cast spell 209918 on self', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19540 selected - Gossip player: Close gossip', '');

-- Milton Beats smart ai
SET @ENTRY := 105908;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 10590800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Milton Beats #0 (10590800) (update out of combat)', '');

-- Timed list 10590800 smart ai
SET @ENTRY := 10590800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 433, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 433', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 137, 43917, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays SpellVisual with SpellVisualKitId: 43917, KitType: 0 for 0 ms', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 0, 137, 25159, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7 seconds - Self: Plays SpellVisual with SpellVisualKitId: 25159, KitType: 0 for 0 ms', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Despawn in 1 s', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 433, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 433', '');
