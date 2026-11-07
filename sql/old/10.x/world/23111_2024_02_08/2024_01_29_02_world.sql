SET @CGUID := 7000309;

SET @ATID := 64;
SEt @ATCP := 52;
SET @ATIDSPAWN := 64;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 137066, 1643, 8717, 9802, '0', 10861, 0, 0, 1, 1138.295166015625, -535.3836669921875, 17.61626243591308593, 1.007170796394348144, 120, 0, 0, 52863, 2434, 0, NULL, NULL, NULL, NULL, 53040), -- 7th Legion Magus (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+1, 143613, 1643, 8717, 9802, '0', 10861, 0, 0, 1, 1140.8663330078125, -533.81768798828125, 17.6162567138671875, 3.718960046768188476, 120, 0, 0, 52863, 2434, 0, NULL, NULL, NULL, NULL, 53040), -- 7th Legion Magus (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+2, 143613, 1643, 8717, 9802, '0', 10861, 0, 0, 1, 1138.8853759765625, -532.90277099609375, 17.6162567138671875, 4.472505092620849609, 120, 0, 0, 52863, 2434, 0, NULL, NULL, NULL, NULL, 53040); -- 7th Legion Magus (Area: Harbormaster's Office - Difficulty: 0) CreateObject1

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 6, 8, 10, 6, 8, 10, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', 1070.142, -474.244, 17.1468, 6.039338, 0, 0, 0, NULL, 'at_boralus_sanctum_of_the_sages_conversation', 'Boralus - Trigger Conversation between Cyrus and Taelia', 0);

-- Update
UPDATE `creature_template` SET `ScriptName` = 'npc_7th_legion_magus_sanctum_of_the_sages' WHERE `entry` IN (137066, 143613);

UPDATE `creature` SET `StringId` = 'MagusStormwind' WHERE `guid` = @CGUID+0;
UPDATE `creature` SET `StringId` = 'MagusExodar' WHERE `guid` = @CGUID+1;
UPDATE `creature` SET `StringId` = 'MagusIronforge' WHERE `guid` = @CGUID+2;

-- Phasing
DELETE FROM `phase_name` WHERE `ID` = 10861;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10861, 'Cosmetic - See 7th Legion Magus in Sanctum of the Sages');

DELETE FROM `phase_area` WHERE `AreaId` = 8717 AND `PhaseId` = 10861;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8717, 10861, 'See 7th Legion Magus in Sanctum of the Sages');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 10861 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10861, 0, 0, 0, 47, 0, 47186, 2|8, 0, 0, 'Apply Phase 10861 if Quest 47186 is in progress | complete');

-- Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=48276, `VerifiedBuild`=53040 WHERE (`MenuID`=22548 AND `OptionID`=0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup` = 22548 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 22548, 0, 0, 0, 47, 0, 47186, 8, 0, 0, 'Show gossip menu option if player has Quest 47186 in progress');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=8356;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(8356, 18912, 0, 53040);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=8356 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(8356, 59635, 8000039, 1, 0, 0, 0, 0, 53040), -- Full: 0x204240CD607780800000490000307986 Creature/0 R4240/S73 Map: 1643 (Kul Tiras) Entry: 122370 (Cyrus Crestfall) Low: 3176838
(8356, 64135, 8000038, 0, 0, 0, 0, 0, 53040); -- Full: 0x204240CD607664C00000490000307987 Creature/0 R4240/S73 Map: 1643 (Kul Tiras) Entry: 121235 (Taelia) Low: 3176839

DELETE FROM `conversation_line_template` WHERE `Id` IN (18913, 18912);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(18913, 0, 1, 0, 0, 53040),
(18912, 0, 0, 0, 0, 53040);

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=53040 WHERE (`DifficultyID`=0 AND `Entry` IN (145730,124695,136063,137316,142371,129940,143502,125005,136061,144147,142457,144148,135230,123639,123633,132638,128531,143262,132036,143246,124720,142191,154464,142095,142056,136041,135153,143261,142752,143263,138725,138726,132625,177193,130377,136052,132642,143022,144383,138724,135520,144030,143295,135509,143250,142459,143244,142346,142136,142139,142132,135064,142543,143839,142137,123675,142073,142068,124295,124289,142188,142086,149045,123244,142094,123642,131994,142066,123635,142063,143243,142180,124238,143040,140944,138280,143613,137066,135658,142077,126634,137268,138704,139522,124859,145728,141033,142181,145729,140472,143251,142167,148922,133282,142160,135446,137282,144635,143709,137298,122370,142163,142089,150208,139088,124725,133325,143272,137294,141116,142174,153932,131992,142138,147206,142117,142169,143856,152000,142166,124805,143254,141114,141115,135808,137300,142187,151176,144310,131989,140350,146902,137265,137317,126781,137266,140473,123604,123169,137281,143870,151173,135681,137314,197611,140313,143844,150493,137293,121239,139148,124180,124727,137279,126682,120788,124181,135677,137295,141117,142189,135675,135678,143098,121235,120599,139144,126434,136633,143842,135521));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `VerifiedBuild`=53040 WHERE (`Entry`=214095 AND `DifficultyID`=0); -- Racing Enthusiast
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `VerifiedBuild`=53040 WHERE (`Entry`=131983 AND `DifficultyID`=0); -- Raider's Training Dummy

DELETE FROM `creature_model_info` WHERE `DisplayID`=115870;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(115870, 0.6987152099609375, 1.5, 0, 53040);

UPDATE `creature_model_info` SET `VerifiedBuild`=53040 WHERE `DisplayID` IN (88828, 1418, 84557, 82540, 84262, 86640, 78630, 87628, 77698, 52723, 88265, 87053, 84263, 82546, 78471, 84555, 77054, 88317, 82541, 87050, 77043, 82539, 88318, 82814, 77496, 79970, 87549, 82538, 79969, 81194, 87769, 33519, 39631, 81321, 87781, 87612, 80751, 87564, 80767, 84544, 87648, 84110, 87794, 87713, 87790, 85963, 85964, 85967, 81168, 84551, 82545, 74793, 77691, 85962, 88152, 88502, 81372, 80182, 82693, 78472, 87647, 87795, 87649, 87780, 87630, 87583, 76046, 87581, 84069, 41667, 87584, 86028, 77532, 87599, 80754, 88271, 38804, 77940, 77936, 87634, 87601, 76422, 78631, 88264, 87611, 80178, 87375, 77466, 87376, 86027, 87786, 80752, 82950, 83985, 79015, 32789, 32790, 83982, 85797, 68167, 22097, 64085, 87600, 79014, 82026, 229, 58202, 86443, 46710, 88825, 1141, 86950, 87422, 87788, 81166, 90161, 88606, 81363, 88050, 77687, 88690, 83093, 86764, 13069, 83521, 76907, 84812, 87602, 90661, 83812, 81802, 83533, 77041, 88613, 27681, 60256, 41325, 89604, 75877, 24052, 86763, 26353, 38801, 88262, 78195, 88612, 87796, 88607, 85771, 76552, 76549, 84415, 81313, 80893, 44575, 86638, 88528, 32778, 81302, 82025, 84173, 28047, 82024, 27823, 88610, 65, 78482, 82995, 86471, 88615, 88605, 91067, 53107, 88611, 5565, 84174, 11686, 88608, 86026, 33719, 88051, 90788, 83531, 76222, 82148, 77851, 88614, 83664, 85228, 61205, 62093, 76515, 55344, 83532, 77055, 87638, 85767, 88609, 86472, 87815, 81291, 75910, 86168, 32646, 88604, 77523);
UPDATE `creature_model_info` SET `BoundingRadius`=4.419252872467041015, `CombatReach`=3.20000004768371582, `VerifiedBuild`=53040 WHERE `DisplayID`=15275;
UPDATE `creature_model_info` SET `BoundingRadius`=0.280177772045135498, `CombatReach`=1, `VerifiedBuild`=53040 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=53040 WHERE `DisplayID`=86639;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=2, `VerifiedBuild`=53040 WHERE `DisplayID`=42178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `VerifiedBuild`=53040 WHERE `DisplayID`=79381;

-- Path 7th Legion Magus
SET @ENTRY := 137066;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, '7th Legion Magus - Path for Portal to Stormwind');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1133.365, -527.8055, 17.76624, NULL, 0);

SET @ENTRY := 137066;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, '7th Legion Magus - Path for finish Portal to Stormwind');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1138.295, -535.3837, 17.69353, NULL, 0);

-- Path 7th Legion Magus
SET @ENTRY := 143613;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, '7th Legion Magus - Path for Portal to Exodar');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1149.377, -531.3507, 17.82446, NULL, 0);

SET @ENTRY := 143613;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, '7th Legion Magus - Path for finish Portal to Exodar');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1140.866, -533.8177, 17.69841, NULL, 0);

-- Path 7th Legion Magus
SET @ENTRY := 143613;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, '7th Legion Magus - Path for Portal to Ironforge');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1147.512, -536.8195, 17.71169, NULL, 0);

SET @ENTRY := 143613;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, '7th Legion Magus - Path for finish Portal to Ironforge');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1138.885, -532.9028, 17.79848, NULL, 0);
