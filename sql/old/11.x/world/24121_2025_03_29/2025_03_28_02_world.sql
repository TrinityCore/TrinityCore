SET @OGUID := 7000373;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272179, 1643, 8721, 9032, '0', 0, 0, -86.0746536254882812, 2083.26904296875, 48.97280502319335937, 1.536661148071289062, 0, 0, 0.694935798645019531, 0.719071745872497558, 120, 255, 1, 59888), -- Mayor's Bulletin (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 278669, 1643, 8721, 9032, '0', 0, 0, -102.713539123535156, 2111.632080078125, 47.38438034057617187, 5.693795204162597656, 0, 0, -0.29044818878173828, 0.956890761852264404, 120, 255, 1, 59888), -- Fallhaven Ledger (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+2, 272461, 1643, 8721, 9032, '0', 0, 0, -111.498268127441406, 2136.63720703125, 49.43145751953125, 2.485972404479980468, 0, 0, 0.946749687194824218, 0.321970582008361816, 120, 255, 1, 59888), -- Ava's Note (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+3, 272462, 1643, 8721, 9032, '0', 0, 0, -100.522567749023437, 1979.0260009765625, 33.4281158447265625, 0.71080780029296875, 0, 0, 0.34796905517578125, 0.937506020069122314, 120, 255, 1, 59888), -- Rancher's Letter (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+4, 272459, 1643, 8721, 9032, '0', 0, 0, -78.9774322509765625, 2250.75341796875, 47.73887252807617187, 6.239107131958007812, -0.05609703063964843, -0.04776668548583984, -0.02468013763427734, 0.996976613998413085, 120, 255, 1, 59888), -- Farmer's Journal (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+5, 277271, 1643, 8721, 9032, '0', 0, 0, -78.625, 2250.8837890625, 46.69050979614257812, 5.234978675842285156, -0.01571512222290039, -0.04906749725341796, -0.49929428100585937, 0.864899218082427978, 120, 255, 1, 59888); -- Crate (Area: Fallhaven - Difficulty: 0) CreateObject1

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (5421, 5423, 5422, 5419);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5421, 12147, 0, 59888),
(5423, 12153, 0, 59888),
(5422, 12150, 0, 59888),
(5419, 12142, 0, 59888);

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (5423,5421,5422,5419));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5423, 59734, 0, 124418, 77993, 0, 0, 59888),
(5421, 59732, 0, 124306, 77946, 0, 0, 59888),
(5422, 59733, 0, 124310, 77947, 0, 0, 59888),
(5419, 59730, 0, 124417, 77992, 0, 0, 59888);

DELETE FROM `conversation_line_template` WHERE `Id` IN (12156, 12155, 12154, 12153, 12149, 12148, 12147, 12152, 12151, 12150, 12145, 12144, 12143, 12142);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(12156, 82, 0, 0, 0, 59888),
(12155, 82, 0, 0, 0, 59888),
(12154, 82, 0, 0, 0, 59888),
(12153, 82, 0, 0, 0, 59888),
(12149, 82, 0, 0, 0, 59888),
(12148, 82, 0, 0, 0, 59888),
(12147, 82, 0, 0, 0, 59888),
(12152, 84, 0, 0, 0, 59888),
(12151, 84, 0, 0, 0, 59888),
(12150, 84, 0, 0, 0, 59888),
(12145, 82, 0, 0, 0, 59888),
(12144, 82, 0, 0, 0, 59888),
(12143, 82, 0, 0, 0, 59888),
(12142, 82, 0, 0, 0, 59888);

-- Spawntracking
DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+2,@OGUID+3,@OGUID+4));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1350094, 1, @OGUID+2, 291253), -- Ava's Note
(1350107, 1, @OGUID+3, 291252), -- Rancher's Letter
(1350078, 1, @OGUID+4, 291251); -- Farmer's Journal

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (47978 /*The Wayward Crone*/, 47968 /*Signs and Portents*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47978, 1, 0, 0, 0, 0, 0, 0, 0, 59888), -- The Wayward Crone
(47968, 1, 0, 0, 0, 0, 0, 0, 0, 59888); -- Signs and Portents

DELETE FROM `gameobject_queststarter` WHERE (`id`=278669 AND `quest`=47978) OR (`id`=272179 AND `quest`=47968);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(278669, 47978, 59888), -- The Wayward Crone offered by Fallhaven Ledger
(272179, 47968, 59888); -- Signs and Portents offered by Mayor's Bulletin

DELETE FROM `gameobject_questender` WHERE (`id`=278669 AND `quest`=47968);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(278669, 47968, 59888); -- Signs and Portents ended by Fallhaven Ledger

DELETE FROM `quest_template_addon` WHERE `ID` IN (47968,47978);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(47968, 0, 0, 0, 48622, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Signs and Portents
(47978, 0, 0, 0, 47968, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- The Wayward Crone

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (291253, 291251, 291252);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291253, NULL, NULL, 5422, 0, 0),
(291251, NULL, NULL, 5423, 0, 0),
(291252, NULL, NULL, 5421, 0, 0);

-- Mayor's Bulletin smart ai
SET @ENTRY := 272179;
UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 1 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 1, 0, 0, 19, 0, 100, 0, 47968, 0, 0, 0, 0, 143, 5419, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Signs and Portents (47968) - Player who accepted quest: Start conversation (5419) Actors<Cyril White (59730)> (first line 12142)', '');
