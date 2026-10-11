SET @OGUID := 7000679;

SET @ATID := 166;
SET @ATIDSPAWN := 262;
SET @ATCP := 160;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 278416, 1643, 8721, 8852, '0', 0, 0, -255.97222900390625, 2126.173583984375, 63.37022018432617187, 5.919377326965332031, 0, 0, -0.18090248107910156, 0.983501017093658447, 120, 255, 1, 63163), -- Trunksy (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1
(@OGUID+1, 278417, 1643, 8721, 8852, '0', 0, 0, -209.965286254882812, 2113.55908203125, 61.8964996337890625, 3.619467496871948242, 0, 0, -0.97159004211425781, 0.236670255661010742, 120, 255, 1, 63163); -- Mr. Munchykins (Area: Glenbrook Homestead - Difficulty: 0) CreateObject1

-- Serverside Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id` = @ATID+0 AND `IsCustom` = 1);
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES 
(@ATID+0, 1, 1, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATIDSPAWN+0 AND @ATIDSPAWN+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATIDSPAWN+0, @ATCP+0, 1, 1643, '0', -236.284195, 2179.960449, 64.161888, 4.373236, 0, 8671, 0, 'SmartAreaTriggerAI', 'Drustvar - trigger conversation for Abby Lewis', 0);

DELETE FROM `areatrigger_create_properties` WHERE (`Id`= @ATCP+0 AND `IsCustom`=1);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(@ATCP+0, 1, @ATID+0, 1, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, '', 0);

-- Template
UPDATE `creature_template` SET `BaseAttackTime`=2000, `npcflag`=2, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=122169; -- Abby Lewis

UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=63163 WHERE `entry`=278416; -- Trunksy
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=63163 WHERE `entry`=278418; -- Mayor Striggs
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=63163 WHERE `entry`=278417; -- Mr. Munchykins

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (278417 /*Mr. Munchykins*/, 278418 /*Mayor Striggs*/, 226941 /*Blood Splat*/, 278416 /*Trunksy*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(278417, 0, 0x204004, 0, 0), -- Mr. Munchykins
(278418, 0, 0x204004, 0, 0), -- Mayor Striggs
(226941, 0, 0x0, 0, 5605), -- Blood Splat
(278416, 0, 0x204004, 0, 0); -- Trunksy

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`=122169 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1723, `StaticFlags1`=0x10000000, `VerifiedBuild`=63163 WHERE (`Entry`=122169 AND `DifficultyID`=0); -- 122169 (Abby Lewis) - CanSwim

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=5111;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(5111, 11446, 0, 63163);

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5111 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(5111, 58657, 7003589, 0, 0, 0, 0, 0, 63163); -- Full: 0x204250CD6076C0C0004BE500004799FE Creature/0 R4244/S19429 Map: 1643 (Kul Tiras) Entry: 121603 (Abby Lewis) Low: 4692478

DELETE FROM `conversation_line_template` WHERE `Id` IN (14070, 14069, 14068, 14067, 11446);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(14070, 0, 0, 0, 0, 63163),
(14069, 0, 0, 0, 0, 63163),
(14068, 0, 0, 0, 0, 63163),
(14067, 0, 0, 0, 0, 63163),
(11446, 0, 0, 0, 0, 63163);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 122169;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(122169, 0, 0, 'Yay! This is gonna be the best tea party ever! Let\'s find the other guests.', 12, 0, 100, 1, 0, 101540, 131088, 5, 'Abby Lewis to Player'),
(122169, 1, 0, 'Trunksy! You know Miss Mary doesn\'t allow you in the house! You track mud everywhere!', 12, 0, 100, 1, 0, 101541, 131086, 5, 'Abby Lewis to Player'),
(122169, 2, 0, 'Mr. Hawthorne was always trying to keep the doggies away from his animals. But now the doggies can finally have supper!', 12, 0, 100, 0, 0, 101537, 131616, 5, 'Abby Lewis to Player'),
(122169, 3, 0, 'Oh Mr. Munchykins! You were hungry, weren\'t you? Come along now. It\'s time for tea.', 12, 0, 100, 1, 0, 101539, 131085, 5, 'Abby Lewis to Player'),
(122169, 4, 0, 'Naughty Mayor Striggs! Always running away from your responsibilities to the townsfolk. Well, you can\'t run anymore!', 12, 0, 100, 1, 0, 101538, 131081, 5, 'Abby Lewis to Player'),
(122169, 5, 0, 'Smoochums loves the woods. I\'m gonna make sure the doggies didn\'t get him!', 12, 0, 100, 1, 0, 101474, 131440, 5, 'Abby Lewis to Player');

-- GameObject Loot
DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (77468,77469,77471);
INSERT INTO `gameobject_loot_template` (`Entry`, `ItemType`, `Item`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(77468, 0, 154874, 100, 1, 1, 0, 1, 1, 'Trunksy'),
(77469, 0, 154894, 100, 1, 1, 0, 1, 1, 'Mr. Munchykins'),
(77471, 0, 154875, 100, 1, 1, 0, 1, 1, 'Mayor Striggs');

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 243706 AND `area` = 8852;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(243706, 8852 , 47289, 47428, 0, 0, 2, 3, 74, 11);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47428;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47428, 1, 0, 0, 0, 0, 0, 0, 0, 63163); -- Kitty?

DELETE FROM `creature_queststarter` WHERE (`id`=122169 AND `quest`=47428);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(122169, 47428, 63163); -- Kitty? offered by Abby Lewis

DELETE FROM `creature_questender` WHERE (`id`=122169 AND `quest`=47289);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(122169, 47289, 63163); -- Teddies and Tea ended by Abby Lewis

DELETE FROM `quest_template_addon` WHERE `ID` = 47428;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(47428, 0, 0, 0, 47289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (290270,290271,290272);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(290270, NULL, 240068, NULL, 0, 0),
(290271, NULL, 240069, NULL, 0, 0),
(290272, NULL, 240070, NULL, 0, 0);

-- Spawntracking
DELETE FROM `spawn_tracking_quest_objective` WHERE (`SpawnTrackingId`=1322940 AND `QuestObjectiveId`=290270) OR (`SpawnTrackingId`=1322933 AND `QuestObjectiveId`=290271) OR (`SpawnTrackingId`=1322913 AND `QuestObjectiveId`=290272);
INSERT INTO `spawn_tracking_quest_objective` (`SpawnTrackingId`, `QuestObjectiveId`, `VerifiedBuild`) VALUES
(1322940, 290270, 63163),
(1322933, 290271, 63163),
(1322913, 290272, 63163);

DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,7000415));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveIds`) VALUES
(1322933, 1, @OGUID+0, 290271), -- Trunksy
(1322913, 1, 7000415, 290272), -- Mayor Striggs
(1322940, 1, @OGUID+1, 290270); -- Mr. Munchykins

DELETE FROM `spawn_tracking_state` WHERE (`SpawnType` = 1 AND `SpawnId` IN (@OGUID+0,@OGUID+1,7000415));
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+0, 0, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+0, 2, 0, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 0, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, NULL),
(1, @OGUID+1, 2, 0, NULL, NULL, NULL, NULL),
(1, 7000415, 0, 1, NULL, NULL, NULL, NULL),
(1, 7000415, 1, 1, NULL, NULL, NULL, NULL),
(1, 7000415, 2, 0, NULL, NULL, NULL, NULL);

-- Abby Lewis smart ai
SET @ENTRY := 122169;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Owner/Summoner: Talk 0 to invoker', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 29, 3, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Follow Owner/Summoner by distance 3, angle 0', ''),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 240069, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On spell  240069 hit - Owner/Summoner: Talk 1 to invoker', ''),
(@ENTRY, 0, 3, 0, 8, 0, 100, 0, 240068, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On spell  240068 hit - Owner/Summoner: Talk 3 to invoker', ''),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 240070, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On spell  240070 hit - Owner/Summoner: Talk 4 to invoker', ''),
(@ENTRY, 0, 5, 0, 19, 0, 100, 0, 47428, 0, 0, 0, 0, 85, 240076, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Kitty? (47428) - Player who accepted quest: Cast spell 240076 on self', ''),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 240076, 0, 0, 0, 0, 80, 12216900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  240076 hit - Self: Start timed action list id #Abby Lewis #0 (12216900) (update out of combat)', '');

-- Timed list 12216900 smart ai
SET @ENTRY := 12216900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Owner/Summoner: Talk 5 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 15, 0, 0, 'After 3 seconds - Self: Move forward by 0, left by 15, up by 0 yards', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 3000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 3 s', '');

-- Serverside AT smart ai
DELETE FROM `smart_scripts` WHERE (`entryorguid` = @ATID+0 AND `source_type` = 12);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ATID+0, 12, 0, 0, '', 46, 0, 100, 0, 0, 0, 0, 0, 0, '', 143, 5111, 0, 0, 0, 0, 0, 0, NULL, 7, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'On areatrigger enter - invoker: start conversation 5111');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 28 AND `SourceGroup` = (@ATID+0) AND `SourceEntry` = 1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(28, (@ATID+0), 1, 0, 0, 47, 0, 47289, 2|8|64, 0, '', 1, 0, 0, '', 'Only trigger areatrigger when quest 47289 is not in progress|complete|rewarded');
