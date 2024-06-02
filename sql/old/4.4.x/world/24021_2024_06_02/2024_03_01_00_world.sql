SET @CGUID := 7000332;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 150941, 1643, 8717, 9802, '0', 12881, 0, 0, 0, 1072.9305419921875, -481.1788330078125, 9.783446311950683593, 4.408616542816162109, 120, 0, 0, 63160, 4393, 0, NULL, NULL, NULL, NULL, 53441), -- Katherine Proudmoore (Area: Harbormaster's Office - Difficulty: 0) CreateObject1
(@CGUID+1, 150947, 0, 1519, 9171, '0', 12882, 0, 0, 0, -8200.669921875, 746.3680419921875, 76.32859039306640625, 0.731448888778686523, 120, 0, 0, 1693785, 0, 0, NULL, NULL, NULL, NULL, 53441); -- Provisioner Fray (Area: Stormwind Embassy - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `faction`=84, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=150947; -- Provisioner Fray
UPDATE `creature_template` SET `faction`=2992, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=150941; -- Katherine Proudmoore

-- Phasing
DELETE FROM `phase_name` WHERE `ID` IN (12881, 12882);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12881, 'Cosmetic - See Katherine Proudmoore in Harbormaster Office'),
(12882, 'Cosmetic - See Provisioner Fray in Stormwind Embassy');

DELETE FROM `phase_area` WHERE `PhaseId` IN (12881, 12882);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8717, 12881, 'See Katherine Proudmoore in Harbormaster Office'),
(1519, 12882, 'See Provisioner Fray in Stormwind Embassy');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 12881 AND `SourceEntry` = 0) OR (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 12882 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 12881, 0, 0, 0, 16, 0, 0x80000000, 0, 0, 0, 'Apply Phase 12881 if Player is Kultiran'),
(26, 12881, 0, 0, 0, 47, 0, 55142, 64, 0, 1, 'Apply Phase 12881 if Quest 55142 is not rewarded'),
(26, 12882, 0, 0, 0, 47, 0, 55146, 2|8, 0, 0, 'Apply Phase 12881 if Quest 55146 is incomplete | complete');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=11001;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(11001, 26136, 0, 53441);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=11001 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(11001, 68967, @CGUID+0, 0, 150941, 0, 0, 0, 53441); -- Full: 0x203AE8CD609367400000350000DE9D7D Creature/0 R3770/S53 Map: 1643 (Kul Tiras) Entry: 150941 (Katherine Proudmoore) Low: 14589309

DELETE FROM `conversation_line_template` WHERE `Id` IN (26137, 26136);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(26137, 0, 0, 0, 0, 53441),
(26136, 0, 0, 0, 0, 53441);

-- Katherine Proudmoore smart ai
SET @ENTRY := 150941;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 19, 0, 100, 0, 55142, 0, 0, 0, 143, 11001, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest For the Alliance (55142) - Player who accepted quest: Start conversation Actors<> (first line 26136) (11001)');

-- Quest stuff
DELETE FROM `quest_offer_reward` WHERE `ID` IN (55146 /*Stranger in a Strange Land*/, 55142 /*For the Alliance*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(55146, 1, 0, 0, 0, 0, 0, 0, 0, 'Wherever you venture, know that Kul Tiras is behind you.', 53441), -- Stranger in a Strange Land
(55142, 0, 0, 0, 0, 0, 0, 0, 0, 'There you are! You must be $n. We\'ve been expecting you.', 53441); -- For the Alliance

UPDATE `quest_poi` SET `VerifiedBuild`=53441 WHERE (`QuestID`=55146 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55146 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55146 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=55142 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=55142 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=55142 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=53441 WHERE (`QuestID`=55146 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55146 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55146 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=55142 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=55142 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=55142 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (55146 /*Stranger in a Strange Land*/, 55142 /*For the Alliance*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(55146, 1, 0, 0, 0, 0, 0, 0, 0, 53441), -- Stranger in a Strange Land
(55142, 1, 0, 0, 0, 0, 0, 0, 0, 53441); -- For the Alliance

DELETE FROM `quest_request_items` WHERE `ID`=55146;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(55146, 0, 6, 0, 0, 'Enjoying your stay in Stormwind?', 53441); -- Stranger in a Strange Land

DELETE FROM `creature_queststarter` WHERE (`id`=150941 AND `quest`=55142);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(150941, 55142, 53441); -- For the Alliance offered by Katherine Proudmoore

UPDATE `creature_queststarter` SET `VerifiedBuild`=53441 WHERE (`id`=133362 AND `quest`=55146);

DELETE FROM `creature_questender` WHERE (`id`=150947 AND `quest`=55146);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(150947, 55146, 53441); -- Stranger in a Strange Land ended by Provisioner Fray

UPDATE `creature_questender` SET `VerifiedBuild`=53441 WHERE (`id`=133362 AND `quest`=55142);

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=53441 WHERE (`DifficultyID`=0 AND `Entry` IN (44395,88067,133326,133322,133332,88080,88081,1976,72654,1412,133362,172572,32520,209299,133411,111190,162393,133408,133409,112694,50933,130069,133509,133394,158125,133431,158123,133363,129679,158119,158120,126332,112698,133672,133675,167032,112686,133433,50927,133441,133369,143711,133396,68,135230,129940,144148,144147,136061,132036,128531,124720,143502,142457,132638,143243,143261,136041,142191,123639,143250,142095,135153,154464,142752,143263,142371,123633,142056,138724,130377,143022,136052,132625,144030,143246,132642,138725,138726,144383,177193,142136,142132,131994,142139,124295,142068,142543,142137,142066,149045,123675,142459,135520,143295,142346,124289,124695,142188,142073,142063,123244,135064,123635,143839,135509,124238,143036,151176,137314,151173,145728,137317,137316,142180,147973,143402,143420,147972,143541,143498,152000,140472,140473,138704,135658,131992,141117,133282,121235,143709,143842,150493,145729,135808,137293,137298,141116,142138,135521,137295,142077,143244,142189,137279,135681,137282,139522,125005,137281,143098,131983,142187,121239,137294,142181,139148,124805,142166,137268,143272,142117,139144,137265,139088,141114,123642,141115,144635,135446,120599,123604,133325,141033,142174,124859,146902,153932,126634,135678,197611,140350,144310,143844,148922,137266,142094,135675,138280,142167,143870,142089,142163,142169,124725,140313,147206,126781,124180,120788,143254,150208,126682,124727,124181,143856,122370,126434,142086,135677,136633,131989,123169,142160));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=674, `VerifiedBuild`=53441 WHERE (`Entry`=150947 AND `DifficultyID`=0); -- Provisioner Fray
UPDATE `creature_template_difficulty` SET `ContentTuningID`=517, `VerifiedBuild`=53441 WHERE (`Entry`=151023 AND `DifficultyID`=0); -- Proudmoore Hydromancer
UPDATE `creature_template_difficulty` SET `ContentTuningID`=517, `VerifiedBuild`=53441 WHERE (`Entry`=151021 AND `DifficultyID`=0); -- Marine Cadet
UPDATE `creature_template_difficulty` SET `ContentTuningID`=464, `VerifiedBuild`=53441 WHERE (`Entry`=150941 AND `DifficultyID`=0); -- Katherine Proudmoore

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (91005, 91006, 91004, 91008);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(91005, 0.6987152099609375, 1.5, 0, 53441),
(91006, 0.6987152099609375, 1.5, 0, 53441),
(91004, 0.347222000360488891, 1.5, 0, 53441),
(91008, 0.347222000360488891, 1.5, 0, 53441);

UPDATE `creature_model_info` SET `VerifiedBuild`=53441 WHERE `DisplayID` IN (83231, 29961, 60711, 82847, 82842, 82854, 221, 257, 18889, 134, 82874, 98008, 21342, 113854, 82899, 82897, 46929, 5585, 83222, 83233, 82973, 93416, 82884, 83229, 80978, 93410, 93415, 93409, 82875, 93413, 82867, 81533, 93412, 82928, 63716, 3167, 58463, 18890, 5446, 24877, 44820, 83232, 99389, 82925, 5131, 87971, 82895, 99391, 82814, 77698, 87050, 88318, 88317, 84555, 82538, 79969, 87647, 79970, 82540, 33519, 52723, 87053, 82539, 87786, 87794, 84544, 39631, 87648, 77496, 87795, 87612, 84110, 87781, 87713, 87790, 87628, 87549, 85962, 88264, 81168, 74793, 81363, 84551, 88152, 87769, 80754, 80767, 82545, 85963, 85964, 81802, 77691, 80752, 85967, 78472, 82543, 87583, 87581, 77940, 38804, 87584, 87375, 77039, 76422, 77532, 76550, 87649, 88502, 87630, 77936, 87634, 87599, 87376, 78630, 78631, 84069, 77466, 41667, 82234, 88271, 82950, 44575, 84174, 91067, 88825, 84173, 15275, 78965, 84262, 80751, 85292, 85277, 38801, 75910, 27823, 58202, 79015, 81321, 60256, 77055, 81366, 13069, 86639, 86638, 85797, 77523, 90788, 87422, 84415, 83531, 83521, 77041, 41325, 79382, 88609, 83532, 87600, 87780, 88050, 87638, 85228, 5565, 83093, 86443, 78471, 82995, 87815, 42178, 80893, 76222, 83533, 229, 86950, 82148, 88616, 88265, 82026, 87565, 24052, 86168, 88605, 33719, 82025, 88606, 76552, 80178, 76549, 86764, 88690, 75877, 76890, 81807, 88604, 1418, 27681, 46710, 81302, 79014, 76135, 86471, 88613, 11686, 86640, 88528, 88051, 90161, 88614, 82024, 87611, 85767, 85771, 32790, 81166, 88608, 86472, 87602, 88612, 53107, 88607, 84812, 86763, 83812, 86027, 89604, 55344, 28047, 77851, 62093, 88611, 87796, 90661, 61206, 83664, 76515, 26353, 76907, 88615, 32646, 87601, 55345, 88610, 32778, 78482, 77687);
UPDATE `creature_model_info` SET `BoundingRadius`=1.777777910232543945, `VerifiedBuild`=53441 WHERE `DisplayID`=87972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.616391122341156005, `CombatReach`=2.20000004768371582, `VerifiedBuild`=53441 WHERE `DisplayID`=87564;
UPDATE `creature_model_info` SET `BoundingRadius`=2.666666507720947265, `VerifiedBuild`=53441 WHERE `DisplayID`=76046;
UPDATE `creature_model_info` SET `BoundingRadius`=0.450062274932861328, `CombatReach`=1.72500002384185791, `VerifiedBuild`=53441 WHERE `DisplayID`=83056;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.499999880790710449, `VerifiedBuild`=53441 WHERE `DisplayID` IN (88837, 88827, 89352, 85293, 89354);
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.499999880790710449, `VerifiedBuild`=53441 WHERE `DisplayID`=88881;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.50000011920928955, `VerifiedBuild`=53441 WHERE `DisplayID`=89353;
UPDATE `creature_model_info` SET `BoundingRadius`=0.430494368076324462, `CombatReach`=1.65000009536743164, `VerifiedBuild`=53441 WHERE `DisplayID`=88490;
UPDATE `creature_model_info` SET `BoundingRadius`=0.36467781662940979, `CombatReach`=1.65000009536743164, `VerifiedBuild`=53441 WHERE `DisplayID`=88492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381254076957702636, `CombatReach`=1.72500002384185791, `VerifiedBuild`=53441 WHERE `DisplayID`=83057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.228800013661384582, `CombatReach`=1.65000009536743164, `VerifiedBuild`=53441 WHERE `DisplayID`=81291;
