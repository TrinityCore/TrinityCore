-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=28287;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(28287, 77763, 0, 65893);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_after_vereesas_ceremony' WHERE `Id` = 28287;

DELETE FROM `conversation_actors` WHERE (`ConversationId`=28287 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(28287, 103076, 0, 1, 0, 0, 0, 0, 65893), -- Full: 0x2042613F00E3DC4001F632000012E1AB Creature/0 R4248/S128562 Map: 2552 (Khaz Algar (Surface)) Entry: 233329 (Silver Hand Avenger) Low: 1237419
(28287, 103060, 10006960, 0, 0, 0, 0, 0, 65893); -- Full: 0x2042613F00E3D88001F63200001183E4 Creature/0 R4248/S128562 Map: 2552 (Khaz Algar (Surface)) Entry: 233314 (Vereesa Windrunner) Low: 1147876

DELETE FROM `conversation_line_template` WHERE `Id` IN (77764, 77763);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(77764, 0, 1, 0, 0, 65893),
(77763, 0, 0, 0, 0, 65893);

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 25036 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 25036, 0, 0, 0, 47, 0, 84997, 2|64, 0, 0, 'Apply Phase 25036 if Quest 84997 is complete|rewarded'),
(26, 25036, 0, 0, 0, 47, 0, 85001, 2|8|64, 0, 1, 'Apply Phase 25036 if Quest 84997 is not complete|in progress|rewarded');

-- Quest
DELETE FROM `quest_request_items` WHERE `ID` IN (85001 /*Blessings Be Upon You*/, 84998 /*Bringer of the Void*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(85001, 0, 5, 0, 0, 'These poor souls are imperiled through no fault of their own!', 65893), -- Blessings Be Upon You
(84998, 0, 0, 0, 0, 'Why does this... void creature want... us dead?', 65893); -- Bringer of the Void

DELETE FROM `creature_queststarter` WHERE (`id`=233312 AND `quest`=85001) OR (`id`=233314 AND `quest`=84998);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(233312, 85001, 65893), -- Blessings Be Upon You offered by Arator
(233314, 84998, 65893); -- Bringer of the Void offered by Vereesa Windrunner

DELETE FROM `creature_questender` WHERE (`id`=233329 AND `quest`=85001) OR (`id`=233314 AND `quest`=84998);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(233329, 85001, 65893), -- Blessings Be Upon You ended by Silver Hand Avenger
(233314, 84998, 65893); -- Bringer of the Void ended by Vereesa Windrunner

DELETE FROM `quest_template_addon` WHERE `ID` IN (85001,84998);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(85001, 0, 0, 0, 84997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(84998, 0, 0, 0, 84997, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- SpellArea
DELETE FROM `spell_area` WHERE `spell` = 470452 AND `area` = 15943;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(470452, 15943, 85001, 85002, 0, 0, 2, 3, 74, 11);

-- Creature Summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID` = 233329;
INSERT INTO `creature_summoned_data` (`CreatureID`, `CreatureIDVisibleToSummoner`, `GroundMountDisplayID`, `FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(233329, 233312, NULL, NULL, NULL);

 -- Arator smart ai
SET @ENTRY := 233312;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 85001, 0, 0, 0, 0, 143, 28287, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest 85001 - Player who accepted quest: Start conversation (28287) Actors<> (first line 77763)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 233312 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 233312, 0, 0, 47, 0, 84998, 8, 0, '', 0, 'Action invoker has Bringer of the Void (84998) in state incomplete');

-- Vereesa Windrunner smart ai
SET @ENTRY := 233314;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 84998, 0, 0, 0, 0, 143, 28287, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Bringer of the Void (84998) - Player who accepted quest: Start conversation (28287) Actors<> (first line 77763)', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 233314 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 233314, 0, 0, 47, 0, 85001, 8, 0, '', 0, 'Action invoker has Blessings Be Upon You (85001) in state incomplete');

-- Silver Hand Avenger smart ai
SET @ENTRY := 233329;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 85, 470456, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Cast spell 470456 on self', '');
