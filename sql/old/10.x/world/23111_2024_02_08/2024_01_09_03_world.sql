SET @ATID := 58;
SEt @ATCP := 46;
SET @ATIDSPAWN := 58;

-- Update Template
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `AIName` = '', `ScriptName` = 'npc_taelia_get_your_bearings' WHERE `entry`=124630; -- Kul Tiran Guard

-- Serverside AT
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1) OR (`Id` = @ATID+1 AND `IsCustom` = 1) OR (`Id` = @ATID+2 AND `IsCustom` = 1) OR (`Id` = @ATID+3 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0),
(@ATID+1, 1, 1, 0),
(@ATID+2, 1, 1, 0),
(@ATID+3, 1, 1, 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1) OR (`Id`= @ATCP+1 AND `IsCustom`=1) OR (`Id`= @ATCP+2 AND `IsCustom`=1) OR (`Id`= @ATCP+3 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 8, 3, 8, 8, 3, 8, 0, 0, '', 0),
(@ATCP+1, 1, @ATID+1, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 12, 8, 6, 12, 8, 6, 0, 0, '', 0),
(@ATCP+2, 1, @ATID+2, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 9, 5, 5, 9, 5, 5, 0, 0, '', 0),
(@ATCP+3, 1, @ATID+3, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 9, 10, 10, 9, 10, 8, 0, 0, '', 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', 1041.622, -596.877, 1.3597, 3.11838, 0, 0, 0, NULL, 'at_boralus_get_your_bearings_ferry', 'Boralus - Hub Tour Ferry', 0),
(@ATIDSPAWN+1, @ATCP+1, 1, 1643, '0', 1123.316, -621.119, 17.533, 3.23322, 0, 0, 0, NULL, 'at_boralus_get_your_bearings_counting_house', 'Boralus - Hub Tour Tradewinds Counting House', 0),
(@ATIDSPAWN+2, @ATCP+2, 1, 1643, '0', 1178.928, -588.619, 31.502, 6.14635, 0, 0, 0, NULL, 'at_boralus_get_your_bearings_inn', 'Boralus - Hub Tour Harbor Inn', 0),
(@ATIDSPAWN+3, @ATCP+3, 1, 1643, '0', 1152.882, -472.908, 30.425, 1.25463, 0, 0, 0, NULL, 'at_boralus_get_your_bearings_flight_master', 'Boralus - Hub Tour Flightmaster', 0);

-- Creature Summoned data
DELETE FROM `creature_summoned_data` WHERE `CreatureID` = 124630;
INSERT INTO `creature_summoned_data` (`CreatureID`, `CreatureIDVisibleToSummoner`, `GroundMountDisplayID`, `FlyingMountDisplayID`) VALUES
(124630, 121235, NULL, NULL);

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (9556, 5366, 10795, 5375, 5365, 5362, 5360);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(9556, 21684, 0, 52649),
(5366, 12010, 0, 52649),
(10795, 25477, 0, 52649),
(5375, 17269, 0, 52649),
(5365, 12005, 0, 52649),
(5362, 11992, 0, 52649),
(5360, 11989, 0, 52649);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_hub_tour_00' WHERE `Id` = 5360;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_hub_tour_ferry' WHERE `Id` = 5362;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_hub_tour_counting_house' WHERE `Id` = 5365;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_hub_tour_harbor_inn' WHERE `Id` = 5375;
UPDATE `conversation_template` SET `ScriptName` = 'conversation_boralus_hub_tour_flight_master' WHERE `Id` = 5366;

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (5375,5362,9556,5366,5360,5365));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5375, 59582, 0, 0, 0, 0, 0, 52649), -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858
(5362, 59582, 0, 0, 0, 0, 0, 52649), -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858
(9556, 59582, 0, 0, 0, 0, 0, 52649), -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858
(5366, 59582, 0, 0, 0, 0, 0, 52649), -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858
(5360, 59582, 0, 0, 0, 0, 0, 52649), -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858
(5365, 59582, 0, 0, 0, 0, 0, 52649); -- Full: 0x2016ECCD6079B5800001A5000015AE3A Creature/0 R1467/S421 Map: 1643 (Kul Tiras) Entry: 124630 (Kul Tiran Guard) Low: 1420858

DELETE FROM `conversation_line_template` WHERE `Id` IN (17293, 17269, 17292, 11992, 21684, 25478, 25477, 17294, 17271, 12010, 11989, 12005);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(17293, 0, 0, 0, 0, 52649),
(17269, 0, 0, 0, 0, 52649),
(17292, 0, 0, 0, 0, 52649),
(11992, 0, 0, 0, 0, 52649),
(21684, 0, 0, 0, 0, 52649),
(25478, 0, 0, 0, 0, 52649),
(25477, 0, 0, 0, 0, 52649),
(17294, 0, 0, 0, 0, 52649),
(17271, 0, 0, 0, 0, 52649),
(12010, 0, 0, 0, 0, 52649),
(11989, 0, 0, 0, 0, 52649),
(12005, 0, 0, 0, 0, 52649);

-- Update Model & Gossip
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=52649 WHERE (`DifficultyID`=0 AND `Entry` IN (126583,135792,135603,124238,135658,136106,139148,139144,141033,132036,121239,135808,124859,124725,124727,150208,132638,150493,131994,136102,150300,130399,128531,132228,142457,136091,143502,133536,143295,143250,130377,132625,136052,143022,123169,142073,142086,142459,142139,142137,142543,129940,142132,142136,130368,142077,132642,142371,143261,136041,149045,136071,135520,142063,138726,142095,142066,148228,144030,138725,142068,138724,135153,142056,142752,177193,136061,136063,136059,139522,142346,123639,144383,154464,123635,124289,144310,143251,135446,137279,142160,142138,137293,137282,137281,148922,137294,137298,137299,135618,138744,143844,143870,142187,135677,140473,144635,138704,137301,137300,135612,125005,145729,153932,135614,123633,143114,143108,142174,143109,143110,143259,142612,124720,143107,135675,143248,138280,160101,143263,143846,143709,139375,137265,152000,137266,142169,142188,143101,142166,135064,142191,143116,142167,144148,143098,141274,143112,197611,123675,135678,135230,124180,126642,142176,124181,144147,142117,143111,143104,143105,143106,137295,137268,140350,121235,143262,143040,143242,143718,143254,123642,142094,133282,143246,140313,126434,133325,124695,126682,142180,143839,143243,143260,143100,123244,136633,135509,143244,126634,143103,124295));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=186, `VerifiedBuild`=52649 WHERE (`Entry`=124630 AND `DifficultyID`=0); -- Kul Tiran Guard

UPDATE `creature_model_info` SET `VerifiedBuild`=52649 WHERE `DisplayID` IN (4626, 78480, 82950, 81321, 84584, 1141, 32789, 80767, 82814, 32778, 76222, 84415, 87050, 46710, 88608, 83812, 83664, 81372, 82538, 82539, 82541, 90788, 28047, 84583, 81363, 81188, 79970, 79969, 82315, 87053, 87647, 84577, 88265, 52723, 82988, 88502, 87795, 81168, 82148, 88604, 84551, 87648, 74793, 78483, 87599, 87601, 87649, 76046, 87584, 77698, 87581, 87583, 81160, 87600, 87631, 82545, 88605, 84262, 87628, 76547, 80182, 87794, 84544, 76422, 84559, 80753, 77043, 87376, 85964, 87612, 87375, 93838, 88152, 85963, 38804, 85962, 84110, 87564, 87713, 85967, 88609, 84555, 84557, 84554, 86443, 87630, 77496, 77691, 87781, 77466, 77936, 80857, 88613, 88528, 87788, 88690, 85228, 81345, 77687, 41325, 83531, 83093, 82995, 90161, 88050, 83533, 83521, 84139, 32681, 87495, 88051, 80893, 55345, 53107, 27823, 85767, 86764, 58202, 81312, 81313, 85758, 78472, 87422, 80754, 80858, 88614, 84263, 62093, 86026, 72253, 87549, 87831, 88611, 88065, 27681, 87823, 87824, 87793, 87690, 33519, 87814, 85771, 87792, 32790, 93865, 87790, 78869, 13069, 61205, 88610, 25073, 82025, 82024, 86763, 87634, 87818, 88271, 84069, 39631, 87833, 81166, 88318, 87815, 86471, 87183, 87826, 11686, 77532, 86472, 82813, 78928, 77851, 88493, 76515, 88317, 24052, 87825, 87820, 87821, 87822, 83532, 82026, 86640, 81291, 81194, 79014, 88615, 87791, 32646, 21936, 87796, 80178, 87611, 81366, 87769, 86028, 88612, 33719, 81807, 76552, 88607, 81516, 61206, 80751, 41667, 87786, 87797, 87817, 78631, 88606, 80180, 87780, 79015, 87819, 77940);
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=52649 WHERE `DisplayID` IN (86168, 86638, 90661);
UPDATE `creature_model_info` SET `BoundingRadius`=0.769999980926513671, `CombatReach`=2.20000004768371582, `VerifiedBuild`=52649 WHERE `DisplayID`=38801;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599251747131347, `CombatReach`=1.75, `VerifiedBuild`=52649 WHERE `DisplayID`=342;

UPDATE `creature_template_gossip` SET `VerifiedBuild`=52649 WHERE (`CreatureID`=121235 AND `MenuID`=21307);

DELETE FROM `gossip_menu` WHERE (`MenuID`=21307 AND `TextID`=133574);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21307, 133574, 52649); -- 121235 (Taelia)

-- Quest data
UPDATE `quest_details` SET `VerifiedBuild`=52649 WHERE `ID` IN (46729, 47099);

DELETE FROM `quest_request_items` WHERE `ID`=47099;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(47099, 0, 0, 0, 0, 'I\'ll bring you to Cyrus after a brief tour of the market.', 52649); -- Get Your Bearings

DELETE FROM `creature_queststarter` WHERE (`id`=124630 AND `quest`=46729);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(124630, 46729, 52649); -- The Old Knight offered by Kul Tiran Guard

UPDATE `creature_queststarter` SET `VerifiedBuild`=52649 WHERE (`id`=121235 AND `quest`=47099);

DELETE FROM `creature_questender` WHERE (`id`=124630 AND `quest`=47099);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(124630, 47099, 52649); -- Get Your Bearings ended by Kul Tiran Guard

DELETE FROM `quest_template_addon` WHERE `ID` = 46729;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(46729, 0, 0, 0, 47099, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Creature 121235 smart ai
SET @ENTRY := 121235;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 1, '', 61, 0, 100, 0, 0, 0, 0, 0, 85, 247663, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47099 - Player who accepted quest: Cast spell 247663 on self'),
(@ENTRY, 0, 1, 0, '', 61, 0, 100, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 47099 - Player who accepted quest: Cast spell 82238 on self');

DELETE FROM `spell_area` WHERE `spell` IN(247532);
INSERT INTO `spell_area` (`area`, `spell`, `quest_start`, `quest_start_status`, `quest_end`, `quest_end_status`, `flags`, `aura_spell`, `racemask`, `gender`) VALUES
(8717, 247532, 47099, 74, 46729, 9, 3, 0, 0, 2); -- Get Your Bearings - Tradewinds Market

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 17) AND (`SourceEntry` IN (247532));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(17, 0, 247532, 0, 0, 48, 0, 335127, 0, 0, 0, 'Caster of the spell has quest objective 335127 == 0'),
(17, 0, 247532, 0, 1, 9, 0, 46729, 0, 0, 1, 'Caster of the spell has quest NOT taken');
