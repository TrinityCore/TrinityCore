-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 9359 AND `PhaseId` IN (10260, 10349, 9949);
INSERT INTO `phase_area`(`AreaId`, `PhaseId`, `Comment`) VALUES
(9359, 10260, 'Lightforged Draenai - Default Phase'),
(9359, 9949, 'Lightforged Draenei - After Quest 49772 rewarded'),
(9359, 10349, 'Lightforged Draenei - Before Quest 49772 rewarded');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 26 AND `SourceGroup` IN (10349, 9949);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 10349, 9359, 0, 0, 8, 0, 49772, 0, 0, 1, 0, 0, '', 'Set phase if quest 49772 is NOT rewarded'),
(26, 9949, 9359, 0, 0, 8, 0, 49772, 0, 0, 0, 0, 0, '', 'Set phase if quest 49772 is rewarded');

UPDATE `creature` SET `PhaseId` = 10349 WHERE `guid` = 650070;

-- Quest starter & ender
DELETE FROM `creature_queststarter` WHERE `id` = 130993 AND `quest` = 49772;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(130993, 49772);

DELETE FROM `creature_questender` WHERE `id` = 133362 AND `quest` = 49772;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(133362, 49772);

-- Update Jarus (ID: 132325) aiAnimKit
DELETE FROM `creature_addon` WHERE `guid` = 650116;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650116, 0, 0, 0, 1, 0, 7276, 0, 0, 0, '');

-- Update missing aiAnimKit to GUID 650125
DELETE FROM `creature_addon` WHERE `guid` = 650125;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650125, 0, 0, 0, 1, 0, 12976, 0, 0, 0, '79968');

-- Update Durael (ID: 132224) EmoteState
DELETE FROM `creature_addon` WHERE `guid` = 650078;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650078, 0, 0, 0, 1, 613, 0, 0, 0, 0, '');

-- Update Maras (ID: 130560) EmoteState
DELETE FROM `creature_addon` WHERE `guid` = 650092;
INSERT INTO `creature_addon`(`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(650092, 0, 0, 0, 1, 415, 0, 0, 0, 0, '');

-- Creature_text
DELETE FROM `creature_text` WHERE `CreatureID` = 130986 AND `GroupID` IN (0, 1, 2, 3, 4, 5) AND `ID` = 0;
INSERT INTO `creature_text`(`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(130986, 0, 0, 'Why have you returned?', 12, 0, 100, 0, 0, 96042, 146009, 0, 'Vigilant Quoram to Player'),
(130986, 1, 0, 'Congratulations.', 12, 0, 100, 0, 0, 96043, 146010, 0, 'Vigilant Quoram to Player'),
(130986, 2, 0, 'I am told power comes from unlikely places.', 12, 0, 100, 0, 0, 96046, 146013, 0, 'Vigilant Quoram to Player'),
(130986, 3, 0, 'For now.', 12, 0, 100, 0, 0, 96048, 146015, 0, 'Vigilant Quoram to Player'),
(130986, 4, 0, 'Fine.', 12, 0, 100, 0, 0, 96049, 146016, 0, 'Vigilant Quoram to Player'),
(130986, 5, 0, 'I am afraid I cannot allow that.', 12, 0, 100, 0, 0, 96050, 146017, 0, 'Vigilant Quoram to Player');

-- SET SAI in Template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (126030, 132266, 125524, 125843, 132214, 132215, 132225, 132328, 130986, 130993);

-- Conversation Stuff for Fareeya (GUID: 650070)
DELETE FROM `conversation_actors` WHERE (`ConversationId`=6481 AND `Idx`=0);
INSERT INTO `conversation_actors`(`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES
(6481, 61703, 650070, 0, 0, 0, 40593);

DELETE FROM `conversation_line_template` WHERE `Id` IN (14662, 14661, 14660, 14659, 14658);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(14662, 47915, 0, 0, 0, 40593),
(14661, 35458, 0, 0, 0, 40593),
(14660, 25276, 0, 0, 0, 40593),
(14659, 11436, 0, 0, 0, 40593),
(14658, 0, 0, 0, 0, 40593);

DELETE FROM `conversation_template` WHERE `Id`=6481;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6481, 14658, 51922, 0, 40593);

-- SAI Conversation Script for Fareeya GUID: 650070
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650070 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650070, 0, 0, 0, 19, 0, 100, 0, 49772, 0, 0, 0, 0, '', 143, 6481, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Fareeya - On Quest accept 49772 - Start Conversation 6481 - To Invoker');

-- SAI for NPC 130986 (vigilant-quoram)
DELETE FROM `smart_scripts` WHERE `entryorguid` = 130986 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(130986, 0, 0, 1, 62, 0, 100, 0, 21910, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 0 - Say Text 0'),
(130986, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip'),
(130986, 0, 2, 3, 62, 0, 100, 0, 21910, 1, 0, 0, 0, '', 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 1 - Say Text 1'),
(130986, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip'),
(130986, 0, 4, 5, 62, 0, 100, 0, 21910, 2, 0, 0, 0, '', 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 2 - say Text 2'),
(130986, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip'),
(130986, 0, 6, 7, 62, 0, 100, 0, 21910, 3, 0, 0, 0, '', 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 3 - Say Text 3'),
(130986, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip'),
(130986, 0, 8, 9, 62, 0, 100, 0, 21910, 4, 0, 0, 0, '', 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 4 - Say text 4'),
(130986, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip'),
(130986, 0, 10, 11, 62, 0, 100, 0, 21910, 5, 0, 0, 0, '', 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Gossip select option 5 - Say Text 5'),
(130986, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - close Gossip');


-- SAI Script for Guid 650087
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650087 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650087, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, '', 11, 240226, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lightsworm Anchorite - cast Cosmetic Spell on self');

-- SAI Script for Guid 650096
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650096 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650096, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, '', 11, 240226, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'lightforged bulwark - cast Cosmetic Spell on self');

-- SAI Script for Guid 650112
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650112 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650112, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650080
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650080 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650080, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650105
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650105 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650105, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650117
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650117 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650117, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650120
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650120 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650120, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650124
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650124 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650124, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650081
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650081 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650081, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650102
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650102 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650102, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650107
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650107 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650107, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650110
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650110 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650110, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650126
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650126 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650126, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650122
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650122 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650122, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650115
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650115 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650115, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- SAI Script for Guid 650113
DELETE FROM `smart_scripts` WHERE `entryorguid` = -650113 AND `source_type` = 0;
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650113, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 5000, 10000, 0, '', 10, 274, 273, 6, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC - on 3000ms to 5000ms and Repeat every 5000ms to 8000ms - Call rnd Emote');

-- Waypoints and Formation Data for GUIDs 650082 & 650103
SET @CGUID := 650103;
SET @PATH := @CGUID * 10;
SET @CLEADER := 650103;
SET @CMEMBER := 650082;

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CLEADER;
INSERT INTO `creature_formations`(`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CLEADER, @CLEADER, 0, 0, 515, 0, 0),
(@CLEADER, @CMEMBER, 2, 90, 515, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 425.095, 1438.91, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 425.317, 1442.74, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 426.108, 1446.2, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 427.422, 1448.99, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 428.614, 1451.72, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 429.68, 1454.39, 742.886, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 430.591, 1457.19, 743.547, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 431.674, 1460.08, 744.594, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 432.78, 1462.79, 745.482, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 434.441, 1465.61, 746.429, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 436.273, 1468.39, 747.52, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 438.286, 1470.49, 748.399, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 440.691, 1472.8, 749.454, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 443.108, 1474.42, 750.417, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 445.914, 1476.06, 751.394, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 448.577, 1477.23, 752.357, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 451.689, 1478.24, 753.491, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 454.527, 1478.92, 754.517, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 457.791, 1479.22, 755.482, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 460.694, 1479.34, 756.435, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 463.933, 1479.11, 757.525, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 466.045, 1479.19, 757.627, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 469.1, 1480.03, 757.472, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 469.459, 1481.52, 757.456, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 470.04, 1483.35, 757.333, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 470.281, 1484.75, 757.279, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 468.04, 1486.89, 757.356, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 466.111, 1487.73, 757.603, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 463.585, 1488.48, 758.087, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 460.578, 1488.74, 758.641, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 457.904, 1488.9, 759.686, 0, 0, 0, 0, 100, 0),
(@PATH, 31, 454.81, 1488.85, 760.096, 0, 0, 0, 0, 100, 0),
(@PATH, 32, 452.216, 1488.62, 760.753, 0, 0, 0, 0, 100, 0),
(@PATH, 33, 449.254, 1487.98, 761.71, 0, 0, 0, 0, 100, 0),
(@PATH, 34, 446.729, 1487.19, 762.13, 0, 0, 0, 0, 100, 0),
(@PATH, 35, 443.952, 1486.02, 762.769, 0, 0, 0, 0, 100, 0),
(@PATH, 36, 441.45, 1484.77, 763.477, 0, 0, 0, 0, 100, 0),
(@PATH, 37, 438.819, 1483.29, 764.144, 0, 0, 0, 0, 100, 0),
(@PATH, 38, 436.522, 1481.83, 764.613, 0, 0, 0, 0, 100, 0),
(@PATH, 39, 434.132, 1480, 765.177, 0, 0, 0, 0, 100, 0),
(@PATH, 40, 432.1, 1478.29, 765.793, 0, 0, 0, 0, 100, 0),
(@PATH, 41, 430.058, 1476.07, 766.47, 0, 0, 0, 0, 100, 0),
(@PATH, 42, 428.251, 1474.04, 767.19, 0, 0, 0, 0, 100, 0),
(@PATH, 43, 426.538, 1471.56, 767.892, 0, 0, 0, 0, 100, 0),
(@PATH, 44, 425.027, 1469.37, 768.482, 0, 0, 0, 0, 100, 0),
(@PATH, 45, 423.781, 1466.67, 769.215, 0, 0, 0, 0, 100, 0),
(@PATH, 46, 422.594, 1464.12, 769.731, 0, 0, 0, 0, 100, 0),
(@PATH, 47, 421.691, 1461.25, 770.444, 0, 0, 0, 0, 100, 0),
(@PATH, 48, 421.047, 1458.65, 771.059, 0, 0, 0, 0, 100, 0),
(@PATH, 49, 420.639, 1455.66, 771.744, 0, 0, 0, 0, 100, 0),
(@PATH, 50, 420.347, 1452.73, 772.418, 0, 0, 0, 0, 100, 0),
(@PATH, 51, 420, 1449.59, 772.758, 0, 0, 0, 0, 100, 0),
(@PATH, 52, 419.555, 1446.55, 772.844, 0, 0, 0, 0, 100, 0),
(@PATH, 53, 419.527, 1444.09, 772.69, 0, 0, 0, 0, 100, 0),
(@PATH, 54, 420.012, 1441.05, 772.664, 0, 0, 0, 0, 100, 0),
(@PATH, 55, 420.512, 1438.32, 772.671, 0, 0, 0, 0, 100, 0),
(@PATH, 56, 421.431, 1435.38, 772.685, 0, 0, 0, 0, 100, 0),
(@PATH, 57, 422.348, 1432.46, 772.819, 0, 0, 0, 0, 100, 0),
(@PATH, 58, 423.365, 1430.44, 772.697, 0, 0, 0, 0, 100, 0),
(@PATH, 59, 425.32, 1428.06, 772.664, 0, 0, 0, 0, 100, 0),
(@PATH, 60, 427.284, 1425.68, 772.728, 0, 0, 0, 0, 100, 0),
(@PATH, 61, 429.257, 1424.18, 772.782, 0, 0, 0, 0, 100, 0),
(@PATH, 62, 431.81, 1422.2, 772.791, 0, 0, 0, 0, 100, 0),
(@PATH, 63, 434.217, 1420.42, 772.751, 0, 0, 0, 0, 100, 0),
(@PATH, 64, 436.709, 1418.64, 772.429, 0, 0, 0, 0, 100, 0),
(@PATH, 65, 439.116, 1417.03, 771.734, 0, 0, 0, 0, 100, 0),
(@PATH, 66, 441.692, 1415.48, 771.134, 0, 0, 0, 0, 100, 0),
(@PATH, 67, 443.986, 1414.18, 770.556, 0, 0, 0, 0, 100, 0),
(@PATH, 68, 446.812, 1413.08, 769.907, 0, 0, 0, 0, 100, 0),
(@PATH, 69, 449.631, 1411.99, 769.273, 0, 0, 0, 0, 100, 0),
(@PATH, 70, 452.185, 1411.51, 768.583, 0, 0, 0, 0, 100, 0),
(@PATH, 71, 455.143, 1411.01, 767.863, 0, 0, 0, 0, 100, 0),
(@PATH, 72, 457.876, 1410.91, 767.276, 0, 0, 0, 0, 100, 0),
(@PATH, 73, 460.883, 1410.82, 766.629, 0, 0, 0, 0, 100, 0),
(@PATH, 74, 463.687, 1411.04, 766.026, 0, 0, 0, 0, 100, 0),
(@PATH, 75, 466.459, 1411.32, 765.402, 0, 0, 0, 0, 100, 0),
(@PATH, 76, 469.426, 1411.9, 764.664, 0, 0, 0, 0, 100, 0),
(@PATH, 77, 469.65, 1409.86, 764.7, 0, 0, 0, 0, 100, 0),
(@PATH, 78, 469.651, 1409.86, 764.699, 0, 0, 0, 0, 100, 0),
(@PATH, 79, 477.215, 1414.74, 763.059, 0, 0, 0, 0, 100, 0),
(@PATH, 80, 479.872, 1416.28, 762.292, 0, 0, 0, 0, 100, 0),
(@PATH, 81, 481.742, 1417.87, 762.106, 0, 0, 0, 0, 100, 0),
(@PATH, 82, 483.966, 1419.78, 761.211, 0, 0, 0, 0, 100, 0),
(@PATH, 83, 486.063, 1421.92, 760.265, 0, 0, 0, 0, 100, 0),
(@PATH, 84, 487.826, 1423.99, 759.804, 0, 0, 0, 0, 100, 0),
(@PATH, 85, 489.595, 1426.36, 758.859, 0, 0, 0, 0, 100, 0),
(@PATH, 86, 491.266, 1428.77, 758.153, 0, 0, 0, 0, 100, 0),
(@PATH, 87, 492.772, 1431.17, 757.649, 0, 0, 0, 0, 100, 0),
(@PATH, 89, 493.989, 1432.96, 757.442, 0, 0, 0, 0, 100, 0),
(@PATH, 90, 494.181, 1436.01, 757.323, 0, 0, 0, 0, 100, 0),
(@PATH, 91, 493.674, 1436.83, 757.259, 0, 0, 0, 0, 100, 0),
(@PATH, 92, 492.256, 1438.46, 757.278, 0, 0, 0, 0, 100, 0),
(@PATH, 93, 489.288, 1439.18, 757.412, 0, 0, 0, 0, 100, 0),
(@PATH, 94, 487.482, 1438.66, 757.536, 0, 0, 0, 0, 100, 0),
(@PATH, 95, 485.915, 1437.66, 757.604, 0, 0, 0, 0, 100, 0),
(@PATH, 96, 484.063, 1435.4, 757.656, 0, 0, 0, 0, 100, 0),
(@PATH, 97, 482.373, 1433.09, 756.492, 0, 0, 0, 0, 100, 0),
(@PATH, 98, 480.408, 1430.66, 755.344, 0, 0, 0, 0, 100, 0),
(@PATH, 99, 478.432, 1428.56, 754.382, 0, 0, 0, 0, 100, 0),
(@PATH, 100, 476.005, 1426.4, 753.537, 0, 0, 0, 0, 100, 0),
(@PATH, 101, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 102, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 103, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 104, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 105, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 106, 473.666, 1424.68, 752.412, 0, 0, 0, 0, 100, 0),
(@PATH, 107, 470.558, 1423, 751.247, 0, 0, 0, 0, 100, 0),
(@PATH, 108, 467.799, 1422.14, 750.429, 0, 0, 0, 0, 100, 0),
(@PATH, 109, 464.682, 1421.47, 749.263, 0, 0, 0, 0, 100, 0),
(@PATH, 110, 461.82, 1421.03, 748.429, 0, 0, 0, 0, 100, 0),
(@PATH, 111, 458.523, 1421.07, 747.585, 0, 0, 0, 0, 100, 0),
(@PATH, 112, 455.631, 1421.22, 746.376, 0, 0, 0, 0, 100, 0),
(@PATH, 113, 452.499, 1421.85, 745.46, 0, 0, 0, 0, 100, 0),
(@PATH, 114, 449.563, 1422.53, 744.548, 0, 0, 0, 0, 100, 0),
(@PATH, 115, 446.674, 1423.52, 743.494, 0, 0, 0, 0, 100, 0),
(@PATH, 116, 443.984, 1424.24, 742.848, 0, 0, 0, 0, 100, 0),
(@PATH, 117, 441.076, 1424.94, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 118, 438.091, 1425.64, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 119, 434.852, 1426.78, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 120, 431.627, 1428.42, 742.093, 0, 0, 0, 0, 100, 0),
(@PATH, 121, 429.287, 1430.39, 742.065, 0, 0, 0, 0, 100, 0),
(@PATH, 122, 427.075, 1433.13, 742.46, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 425.0947, `position_y`= 1438.913, `position_z`= 742.0541, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
UPDATE `creature` SET `position_x`= 425.0947, `position_y`= 1440.913, `position_z`= 742.0541, `orientation`= 0, `spawndist`= 0, `MovementType`= 0 WHERE `guid`= @CMEMBER;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- Waypoints and Formation for GUIDS 650118 & 650119
SET @CGUID := 650119;
SET @PATH := @CGUID * 10;
SET @CLEADER := 650119;
SET @CMEMBER := 650118;

DELETE FROM `creature_formations` WHERE `leaderGUID` = @CLEADER;
INSERT INTO `creature_formations`(`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CLEADER, @CLEADER, 0, 0, 515, 0, 0),
(@CLEADER, @CMEMBER, 2, 90, 515, 0, 0);

DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 0, 445.31, 1491.44, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 1, 449.102, 1492.26, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 2, 452.211, 1492.02, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 3, 455.332, 1491.77, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 4, 459.149, 1491.24, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 5, 461.977, 1489.86, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 6, 464.783, 1488.5, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 7, 467.845, 1486.43, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 8, 470.159, 1484.3, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 9, 472.47, 1482.17, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 10, 474.784, 1480.48, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 11, 477.384, 1478.69, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 12, 479.934, 1476.97, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 13, 482.59, 1475.29, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 14, 485.636, 1473.01, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 15, 487.552, 1470.53, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 16, 489.67, 1467.63, 742.351, 0, 0, 0, 0, 100, 0),
(@PATH, 17, 490.965, 1464.76, 742.41, 0, 0, 0, 0, 100, 0),
(@PATH, 18, 492.259, 1461.91, 742.094, 0, 0, 0, 0, 100, 0),
(@PATH, 19, 493.017, 1458.38, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 20, 493.614, 1455.29, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 21, 493.873, 1451.91, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 22, 494.082, 1448.77, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 23, 494.018, 1445.42, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 24, 493.892, 1442.26, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 25, 493.686, 1439.02, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 26, 493.405, 1435.87, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 27, 493.125, 1432.73, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 28, 492.558, 1429.43, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 29, 491.974, 1426.33, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 30, 490.814, 1422.84, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 31, 489.362, 1420.06, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 32, 487.307, 1416.63, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 33, 484.792, 1414.76, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 34, 482.283, 1412.89, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 35, 479.226, 1411.06, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 36, 476.346, 1409.78, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 37, 473.466, 1408.51, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 38, 470.176, 1407.37, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 39, 467.112, 1406.61, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 40, 464.061, 1405.85, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 41, 460.678, 1405.27, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 42, 457.557, 1404.97, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 43, 454.439, 1404.66, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 44, 450.63, 1404.75, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 45, 447.592, 1405.52, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 46, 444.559, 1406.3, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 47, 441.241, 1408.08, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 48, 438.659, 1409.84, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 49, 435.959, 1412.43, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 50, 434.062, 1414.93, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 51, 432.168, 1417.44, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 52, 430.249, 1419.89, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 53, 428.286, 1422.37, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 54, 426.317, 1425.07, 742.078, 0, 0, 0, 0, 100, 0),
(@PATH, 55, 424.625, 1427.71, 742.386, 0, 0, 0, 0, 100, 0),
(@PATH, 56, 422.932, 1430.35, 742.391, 0, 0, 0, 0, 100, 0),
(@PATH, 57, 420.405, 1436.27, 742.46, 0, 0, 0, 0, 100, 0),
(@PATH, 58, 419.453, 1439.03, 742.46, 0, 0, 0, 0, 100, 0),
(@PATH, 59, 418.494, 1441.81, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 60, 417.564, 1444.83, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 61, 416.921, 1447.69, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 62, 416.277, 1450.54, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 63, 415.805, 1453.77, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 64, 415.674, 1456.71, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 65, 415.543, 1459.64, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 66, 415.413, 1462.57, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 67, 416.659, 1466.18, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 68, 417.855, 1468.87, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 69, 419.464, 1471.91, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 70, 421.322, 1474.18, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 71, 423.185, 1476.45, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 72, 425.048, 1478.72, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 73, 427.477, 1480.94, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 74, 429.724, 1482.82, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 75, 431.97, 1484.71, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 76, 434.211, 1486.59, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 77, 437.152, 1488.8, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 78, 439.943, 1489.7, 742.054, 0, 0, 0, 0, 100, 0),
(@PATH, 79, 442.729, 1490.6, 742.054, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 445.3101, `position_y`= 1491.44, `position_z`= 742.0541, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
UPDATE `creature` SET `position_x`= 445.3101, `position_y`= 1489.44, `position_z`= 742.0541, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CMEMBER;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- SAI Event Script for GUID 650090
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-650090, 6500900, 6500901) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650090, 0, 0, 0, 40, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, 6500901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On WP 2 reached - run ActionList - self'),
(-650090, 0, 1, 0, 40, 0, 100, 0, 1, 6500900, 0, 0, 0, '', 80, 6500900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On WP 1 reach - run ActionList - self'),
(6500900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 45, 1, 1, 0, 0, 0, 0, 10, 650076, 132215, 0, 0, 0, 0, 0, 'After 1s - Set Byte 1 1 - Target GUID'),
(6500900, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play Emote - self'),
(6500900, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 5, 6, 0, 0, 0, 0, 0, 10, 650076, 132215, 0, 0, 0, 0, 0, 'After 3s - Play Emote - Target GUID'),
(6500900, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play Emote - self'),
(6500900, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 10, 650076, 132215, 0, 0, 0, 0, 0, 'After 2s - Play Emote - Target GUID'),
(6500900, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, '', 45, 2, 2, 0, 0, 0, 0, 10, 650076, 132215, 0, 0, 0, 0, 0, 'After 6s - Send data 2 2 - Target GUID'),
(6500901, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 128, 12894, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0s - Set AnimKit - self'),
(6500901, 9, 1, 0, 0, 0, 100, 0, 42000, 42000, 0, 0, 0, '', 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 42s - Set AnimKit to 0 - self');

SET @CGUID := 650090;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, 451.651, 1391.86, 772.655, 3.5627, 15751, 0, 0, 100, 0),
(@PATH, 2, 468.72, 1398.42, 772.649, 0, 43549, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 451.651, `position_y`= 1391.865, `position_z`= 772.6549, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

-- SAI Event Script for GUID 650085
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-650085, 65008500, -650127, -650121) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts`(`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-650085, 0, 0, 0, 40, 0, 100, 0, 1, 6500850, 0, 0, 0, '', 80, 65008500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On Waypoint 1 reached - Start Action List - Self'),
(65008500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 45, 1, 1, 0, 0, 0, 0, 9, 132214, 0, 4, 0, 0, 0, 0, 'After 1s - Set Data 1 1 to nearby Entry'),
(65008500, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3s - Play Emote - Self'),
(65008500, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 10, 650127, 132214, 0, 0, 0, 0, 0, 'After 3s - Play Emote - Target Guid'),
(65008500, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 5, 1, 0, 0, 0, 0, 0, 10, 650121, 132214, 0, 0, 0, 0, 0, 'After 3s - Play Emote - Target Guid'),
(65008500, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, '', 45, 2, 2, 0, 0, 0, 0, 9, 132214, 0, 4, 0, 0, 0, 0, 'After 4s - Set data 2 2 - Nearby Entry'),
(-650127, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 10, 650085, 132215, 0, 0, 0, 0, 0, 'On data Set 1 1 - Set Orientation - Target GUID / Entry'),
(-650127, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.20928, 'On data Set 2 2 - Set Orientation - Default Orientation'),
(-650121, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 10, 650085, 132215, 0, 0, 0, 0, 0, 'On data Set 1 1 - Set Orientation - Target GUID / Entry'),
(-650121, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 0, '', 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.48262, 'On data Set 2 2 - Set Orientation - Default Orientation');

SET @CGUID := 650085;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH; -- This Waypoints should be Spline.
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(6500850, 0, 425.337, 1412.52, 772.696, 0.1589, 6118, 0, 0, 100, 0),
(6500850, 1, 415.845, 1483.25, 772.655, 0.1196, 15743, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 425.3368, `position_y`= 1412.521, `position_z`= 772.6965, `orientation`= 0, `spawndist`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);
