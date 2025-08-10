SET @CGUID := 8000035;
SET @ATID := 62;
SEt @ATCP := 50;
SET @ATIDSPAWN := 62;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 120788, 1643, 8717, 9802, '0', 10845, 0, 0, 0, 1068.16845703125, -487.204864501953125, 9.783460617065429687, 0.248383447527885437, 120, 0, 0, 4737000, 90350, 0, NULL, NULL, NULL, NULL, 52808), -- Genn Greymane (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+1, 120599, 1643, 8717, 9802, '0', 10845, 0, 0, 1, 1064.234375, -489.888885498046875, 9.783459663391113281, 1.296923279762268066, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 52808), -- Greyguard (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+2, 120599, 1643, 8717, 9802, '0', 10845, 0, 0, 1, 1058.7447509765625, -488.9444580078125, 9.78342437744140625, 1.206693172454833984, 120, 0, 0, 176210, 0, 0, NULL, NULL, NULL, NULL, 52808), -- Greyguard (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+3, 121235, 1643, 8717, 9802, '0', 10827, 0, 0, 1, 1070.404541015625, -489.321197509765625, 9.783461570739746093, 1.501441717147827148, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52808), -- Taelia (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+4, 122370, 1643, 8717, 9802, '0', 9001, 0, 0, 0, 1071.4288330078125, -486.3125, 9.7834625244140625, 3.499564647674560546, 120, 0, 0, 17621, 0, 0, NULL, NULL, NULL, NULL, 52808); -- Cyrus Crestfall (Area: Harbormaster's Office - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature` SET `StringId` = "GreyguardOne" WHERE `guid` = @CGUID+1;
UPDATE `creature` SET `StringId` = "GreyguardTwo" WHERE `guid` = @CGUID+2;

UPDATE `creature_template` SET `ScriptName` = 'npc_cyrus_crestfall_old_knight' WHERE `entry` = 122370;
UPDATE `creature_template` SET `npcflag`=3 WHERE `entry`=120788; -- Genn Greymane

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1) OR (`Id` = @ATID+1 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1) OR (`Id`= @ATCP+1 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 12, 8, 6, 12, 8, 6, 0, 0, '', 0),
(@ATCP+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 7, 4, 7, 7, 4, 7, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', 1083.3828, -485.8729, 20.3390, 1.313066, 0, 0, 0, NULL, 'at_boralus_old_knight_enter_harbormasters_office', 'Boralus - Enter Harbormasters Office', 0),
(@ATIDSPAWN+1, @ATCP+1, 1, 1643, '0', 1063.0791, -472.2944, 11.6384, 6.063283, 0, 0, 0, NULL, 'at_boralus_old_knight_genn_arrives_boralus', 'Boralus - Genn Greymane arrives Boralus', 0);

-- SpellScript Names
DELETE FROM `spell_script_names` WHERE `spell_id` = 269054;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(269054, 'spell_boralus_find_cyrus_objective_complete');

-- Scene
DELETE FROM `scene_template` WHERE `SceneId`=1960;
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1960, 17, 2107, 0);

UPDATE `scene_template` SET `ScriptName` = 'scene_boralus_client_scene_cyrus_and_genn' WHERE `SceneId` = 1960;

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=122370 AND `MenuID`=22543) OR (`CreatureID`=120788 AND `MenuID`=23317);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(122370, 22543, 52808), -- Cyrus Crestfall
(120788, 23317, 53040); -- Genn Greymane

UPDATE `creature_template_gossip` SET `VerifiedBuild`=52808 WHERE (`CreatureID`=121235 AND `MenuID`=21307);

DELETE FROM `gossip_menu` WHERE (`MenuID`=21307 AND `TextID`=133576);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21307, 133576, 52808); -- 121235 (Taelia)

UPDATE `gossip_menu_option` SET `GossipOptionID`=48242, `VerifiedBuild`=53040 WHERE (`MenuID`=22543 AND `OptionID`=0);

-- Quest stuff
DELETE FROM `creature_questender` WHERE (`id`=121235 AND `quest`=46729);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(121235, 46729, 52808); -- The Old Knight ended by Taelia

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (7653, 8062, 7605);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(7653, 17449, 0, 52808),
(8062, 18297, 0, 52808),
(7605, 17297, 0, 52808);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_accept_old_knight' WHERE `Id` = 9556;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_enter_harbormaster_office' WHERE `Id` = 7605;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_cyrus_meets_genn' WHERE `Id` = 8062;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_cyrus_crestfall_shaking_hands' WHERE `Id` = 7653;

DELETE FROM `conversation_actors` WHERE (`Idx`=1 AND `ConversationId` IN (8062,7653)) OR (`Idx`=0 AND `ConversationId` IN (8062,7605,7653));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(8062, 0,(@CGUID+3), 1, 0, 0, 0, 0, 52808), -- Full: 0x20309CCD607664C00000EA00001E0614 Creature/0 R3111/S234 Map: 1643 (Kul Tiras) Entry: 121235 (Taelia) Low: 1967636
(8062, 59635, 0, 0, 0, 0, 0, 0, 52808), -- Full: 0x20309CCD607780800000EA00001E0614 Creature/0 R3111/S234 Map: 1643 (Kul Tiras) Entry: 122370 (Cyrus Crestfall) Low: 1967636
(7605, 59582, 0, 0, 0, 0, 0, 0, 52808), -- Full: 0x20309CCD6079B5800000EA000021CFE2 Creature/0 R3111/S234 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 2215906
(7653, 64106, (@CGUID+0), 0, 0, 0, 0, 0, 52808), -- Full: 0x0
(7653, 59635, 0, 1, 0, 0, 0, 0, 52808); -- Full: 0x20309CCD607780800000EA00001E0614 Creature/0 R3111/S234 Map: 1643 (Kul Tiras) Entry: 122370 (Cyrus Crestfall) Low: 1967636

DELETE FROM `conversation_line_template` WHERE `Id` IN (18299, 18298, 18297, 17447, 17297, 17446, 17423, 17422, 17421, 17420, 18294, 17419, 17417, 17416, 18293, 17414, 17413, 17449);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(18299, 0, 1, 0, 0, 52808),
(18298, 0, 0, 0, 0, 52808),
(18297, 0, 0, 0, 0, 52808),
(17447, 0, 0, 0, 0, 52808),
(17297, 0, 0, 0, 0, 52808),
(17446, 0, 0, 0, 0, 52808),
(17423, 0, 0, 0, 0, 52808),
(17422, 0, 1, 0, 0, 52808),
(17421, 0, 1, 0, 0, 52808),
(17420, 0, 1, 0, 0, 52808),
(18294, 0, 1, 0, 0, 52808),
(17419, 0, 1, 0, 0, 52808),
(17417, 0, 1, 0, 0, 52808),
(17416, 0, 1, 0, 0, 52808),
(18293, 0, 1, 0, 0, 52808),
(17414, 0, 1, 0, 0, 52808),
(17413, 0, 0, 0, 0, 52808),
(17449, 0, 0, 0, 0, 52808);

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (10845, 10827, 9001);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10845, 'Cosmetic - See Genn Greymane and Greyguards in Harbormasters Office'),
(10827, 'Cosmetic - See Taelia in Harbormasters Office'),
(9001, 'Cosmetic - See Cyrus Crestfall in Harbormasters Office');

DELETE FROM `phase_area` WHERE `AreaId` = 9802 AND `PhaseId` IN (10845, 10827, 9001);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9802, 10845, 'See Genn Greymane and Greyguards in Harbormasters Office'),
(9802, 10827, 'See Taelia in Harbormasters Office'),
(9802, 9001, 'See Cyrus Crestfall in Harbormasters Office');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (10845, 10827, 9001) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10845, 0, 0, 0, 47, 0, 46729, 8, 0, 0, 'Apply Phase 10845 if Quest 46729 is in progress'),
(26, 10845, 0, 0, 0, 48, 0, 335127, 0, 1, 0, 'Apply Phase 10845 if Questobjective 335127 (Enter the Harbormasters Office) is rewarded'),
(26, 10845, 0, 0, 1, 47, 0, 46729, 2|64, 0, 0, 'Apply Phase 10845 if Quest 46729 is complete | rewarded'),
(26, 10827, 0, 0, 0, 47, 0, 46729, 8, 0, 0, 'Apply Phase 10827 if Quest 46729 is in progress'),
(26, 10827, 0, 0, 0, 48, 0, 335127, 0, 1, 0, 'Apply Phase 10827 if Questobjective 335127 (Enter the Harbormasters Office) is rewarded'),
(26, 10827, 0, 0, 1, 47, 0, 46729, 2|64, 0, 0, 'Apply Phase 10827 if Quest 46729 is complete | rewarded'),
(26, 9001, 0, 0, 0, 47, 0, 46729, 8, 0, 0, 'Apply Phase 9001 if Quest 46729 is in progress'),
(26, 9001, 0, 0, 0, 48, 0, 335127, 0, 1, 0, 'Apply Phase 9001 if Questobjective 335127 (Enter the Harbormasters Office) is rewarded'),
(26, 9001, 0, 0, 1, 47, 0, 46729, 2|64, 0, 0, 'Apply Phase 9001 if Quest 46729 is complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=15 AND `SourceGroup` = 22543 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(15, 22543, 0, 0, 0, 47, 0, 46729, 8, 0, 0, 'Show gossip menu option if player has Quest 46729 in Progress'),
(15, 22543, 0, 0, 0, 48, 0, 335216, 0, 1, 1, 'Show gossip menu option if player has not quest objective done: Speak with Cyrus Crestfall');

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52808 WHERE (`DifficultyID`=0 AND `Entry` IN (145730,121235,137314,120788,120599,122370,137316,145728,142189,137317,124238,151173,140944,142181,142089,141116,141114,141117,142163,131992,141115,135658,143272,141033,143040,135521,137298,137281,139148,139144,124805,126781,139088,146902,147206,131989,123604,145729,135681,143856,140472,143842,143116,143110,143111,143104,143107,143101,143109,143114,142138,143112,135618,143108,142160,135612,138744,137282,143844,137300,143100,137279,144635,137294,140473,138704,143846,137293,143106,153932,135614,135677,143103,143870,137295,148922,143105,135675,135678,143839,152000,142612,143718,136059,143260,143259,124695,142176,138280,135064,143248,126634,139375,141274,143242,126642,126519,144147,123633,136061,136063,143251,144148,140313,138726,124859,132625,123675,160101,137268,142086,142174,124289,143262,125005,143261,139522,142169,142132,143263,150208,142063,142056,142167,154464,135230,142188,142371,142457,124725,177193,143244,121239,143246,142191,123635,143295,124720,135153,149045,142187,143243,142073,142180,144383,142068,143709,142543,124295,142117,142136,143098,142066,150493,138724,123244,132036,132642,128531,143502,138725,142752,136041,144310,143022,140350,142137,143254,137265,132638,123642,137266,142139,135520,142346,123639,143250,130377,135808,142459,135509,142077,135446,123169,133282,133325,62821,197611,131994,62822,136052,126682,124180,142166,142094,126434,124181,124727,136633,142095,121541,124630));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `VerifiedBuild`=52808 WHERE (`Entry`=131983 AND `DifficultyID`=0); -- Raider's Training Dummy
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `VerifiedBuild`=52808 WHERE (`Entry`=115785 AND `DifficultyID`=0); -- Direbeak Hatchling
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `VerifiedBuild`=52808 WHERE (`Entry`=213407 AND `DifficultyID`=0); -- Lil' Wrathion

DELETE FROM `creature_model_info` WHERE `DisplayID`=115559;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(115559, 0.337544381618499755, 0.625, 0, 52808);

UPDATE `creature_model_info` SET `VerifiedBuild`=52808 WHERE `DisplayID` IN (80177, 88828, 84174, 75877, 75910, 76907, 88825, 83982, 87638, 84173, 82950, 91067, 83985, 86950, 86028, 87602, 77041, 77055, 84812, 86638, 60256, 76549, 1141, 32790, 32789, 83521, 82995, 86168, 65, 78193, 55345, 81302, 89604, 229, 87422, 5565, 88051, 26353, 53108, 77523, 87833, 87824, 87825, 87820, 87814, 87818, 32646, 87823, 87831, 41325, 87826, 32681, 88065, 77687, 85758, 87495, 83093, 88050, 81313, 87817, 85228, 86764, 83533, 58202, 78869, 83531, 55344, 87822, 62093, 85767, 72253, 53107, 87819, 83532, 90161, 87821, 86472, 85771, 86471, 41667, 38801, 79014, 87690, 21936, 84554, 87797, 87793, 76552, 88493, 85797, 80857, 84069, 87792, 79015, 25073, 87183, 87791, 342, 36499, 88317, 87549, 84555, 84557, 88262, 86027, 87788, 88318, 86025, 85964, 46710, 82148, 77532, 88609, 79969, 93865, 82026, 70070, 78631, 88608, 87601, 27681, 77936, 81194, 87794, 86443, 87648, 86763, 87581, 87790, 90661, 87376, 81363, 87564, 82543, 87647, 81166, 87781, 82814, 82538, 80754, 87634, 87628, 87050, 83812, 88605, 85967, 87780, 76222, 87769, 39631, 77466, 88502, 33519, 84110, 76422, 88271, 80893, 87786, 80753, 87599, 82540, 88606, 80751, 80752, 77691, 38804, 13069, 77940, 24052, 78472, 88264, 80767, 87583, 88610, 87815, 87375, 90788, 88612, 85962, 82693, 32778, 82545, 79970, 52723, 85963, 87713, 84544, 81372, 88611, 88528, 74793, 77054, 86640, 88615, 87584, 87796, 82025, 82539, 84262, 88607, 84263, 82024, 76046, 77039, 87630, 77496, 88614, 87795, 81168, 84415, 87649, 84284, 87600, 88690, 78483, 81321, 81807, 88613, 42720, 11686, 28047, 42722, 84551, 61205, 77851, 88265, 87611, 33719, 76515, 83664, 88604, 87612, 27823);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=52808 WHERE `DisplayID`=86639;
UPDATE `creature_model_info` SET `BoundingRadius`=4.419252872467041015, `CombatReach`=3.20000004768371582, `VerifiedBuild`=52808 WHERE `DisplayID`=15275;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791, `CombatReach`=2, `VerifiedBuild`=52808 WHERE `DisplayID`=42178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.280177772045135498, `CombatReach`=1, `VerifiedBuild`=52808 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `VerifiedBuild`=52808 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=52808 WHERE `DisplayID`=81291;

-- Greyguard smart ai
SET @ENTRY := 120599;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 58, 0, 100, 0, (0xFFFFFFFF), 12059900, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 12059900 ended - Self: Despawn instantly'),
(@ENTRY, 0, 1, 0, '', 58, 0, 100, 0, (0xFFFFFFFF), 12059901, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 12059901 ended - Self: Despawn instantly');

-- Path Taelia
SET @ENTRY := 124630;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Taelia - The Old Knight Quest');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1079.5695, -476.7725, 20.7355, NULL, 2000),
(@PATH, 1, 1069.0481, -473.7091, 16.4489, NULL, 0),
(@PATH, 2, 1047.5667, -470.1653, 8.95465, NULL, 0);

SET @ENTRY := 124630;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Taelia - After Client Scene: Cyrus and Genn');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1058.854, -471.6476, 11.65849, NULL, 0),
(@PATH, 1, 1059.061, -478.934, 10.2413, NULL, 0),
(@PATH, 2, 1069.51, -487.0607, 9.691328, NULL, 0),
(@PATH, 3, 1070.431, -489.1788, 9.717813, 1.50144, 0);

-- Path Cyrus
SET @ENTRY := 122370;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Cyrus - After Client Scene: Cyrus and Genn');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1059.382, -479.4549, 10.17741, NULL, 0),
(@PATH, 1, 1065.797, -484.2326, 9.897485, NULL, 0),
(@PATH, 2, 1071.325, -486.184, 9.744476, 3.49956, 0);

-- Path Genn Greymane
SET @ENTRY := 120788;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Genn - After Client Scene: Cyrus and Genn');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1058.998, -472.7778, 11.65849, NULL, 0),
(@PATH, 1, 1058.879, -478.0556, 10.12054, NULL, 0),
(@PATH, 2, 1059.028, -481.0955, 9.979296, NULL, 0),
(@PATH, 3, 1059.656, -484.1667, 9.949183, NULL, 0),
(@PATH, 4, 1065.174, -486.9184, 9.874442, NULL, 0),
(@PATH, 5, 1068.137, -487.2014, 9.691328, 0.24838, 0);

-- Path Greyguard
SET @ENTRY := 120599;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Greyguard - After Client Scene: Cyrus and Genn');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1050.243, -469.1406, 10.48856, NULL, 0),
(@PATH, 1, 1052.11, -469.5472, 11.86161, NULL, 0),
(@PATH, 2, 1055.064, -470.1649, 11.74733, NULL, 0),
(@PATH, 3, 1058.658, -472.8438, 11.65849, NULL, 0),
(@PATH, 4, 1058.786, -475.0191, 11.65849, NULL, 0),
(@PATH, 5, 1058.193, -478.4648, 10.32366, NULL, 0),
(@PATH, 6, 1058.155, -482.3889, 9.946414, NULL, 0),
(@PATH, 7, 1058.78, -488.8403, 10.06123, NULL, 0);

SET @ENTRY := 120599;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Greyguard - After Client Scene: Cyrus and Genn');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1052.17, -470.2413, 11.86161, NULL, 0),
(@PATH, 1, 1055.045, -470.7951, 11.74097, NULL, 0),
(@PATH, 2, 1058.658, -472.8438, 11.65849, NULL, 0),
(@PATH, 3, 1059.632, -474.9479, 11.65849, NULL, 0),
(@PATH, 4, 1059.16, -478.5278, 10.21113, NULL, 0),
(@PATH, 5, 1060.052, -483.7674, 9.961575, NULL, 0),
(@PATH, 6, 1064.194, -489.7517, 9.86161, NULL, 0);
