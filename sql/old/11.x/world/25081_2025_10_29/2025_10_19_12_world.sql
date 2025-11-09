-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 42500;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42500, 46598, 1, 0);

-- Template
UPDATE `creature_template` SET `VehicleId`= 899 WHERE `entry`= 42500;

-- SpawnGroup
DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` IN (275809, 280400, 308009);

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID` IN (0,1) AND `Entry` IN (42515,42492));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(42515, 0, 0, 1, 1, 53141, 0x0, 0, 0), -- Shadowy Figure
(42492, 0, 0, 10, 1, 53158, 0x0, 0, 0); -- Glubtok

UPDATE `creature_template_difficulty` SET `ContentTuningID`=6, `StaticFlags1`=0x10000200, `VerifiedBuild`=63305 WHERE (`Entry`=42515 AND `DifficultyID`=0); -- 42515 (Shadowy Figure) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=6, `VerifiedBuild`=63305 WHERE (`Entry`=42492 AND `DifficultyID`=0); -- 42492 (Glubtok) - 

-- Creature Two-Shoed Lou's Old House 42500 SAI
SET @ENTRY := 42500;
UPDATE `creature_template` SET `AIName`="SmartAI", `unit_flags`= 520 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 4250000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Start timed action list id #4250000 // "),
(@ENTRY, 0, 1, 0, 28, 0, 100, 0, 0, 0, 0, 0, 11, 79274, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "On passenger removed (vehicle) - Self: Cast spell Force Despawn Jangolode Actors (79274) on Action invoker // ");

-- Timed list 4250000 smart ai
SET @ENTRY := 4250000;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 9300, 9300, 0, 0, 0, 85, 79290, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 9.3 seconds - Self: Cast spell  79290 on Self', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6500, 6500, 0, 0, 0, 85, 79279, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 6.5 seconds - Self: Cast spell  79279 on Self', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 85, 79292, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Cast spell  79292 on Self', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 85, 79283, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Cast spell  79283 on Self', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 0, 85, 79294, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 16 seconds - Self: Cast spell  79294 on Self', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4100, 4100, 0, 0, 0, 85, 79284, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 4.1 seconds - Self: Cast spell  79284 on Self', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 6400, 6400, 0, 0, 0, 85, 79297, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 6.4 seconds - Self: Cast spell  79297 on Self', ''),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 11400, 11400, 0, 0, 0, 85, 79287, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 11.4 seconds - Self: Cast spell  79287 on Self', '');

-- Creature Shadowy Figure 42515 SAI
SET @ENTRY := 42515;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 63, 0, 100, 0, 0, 0, 0, 0, 0, 85, 79192, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Cast spell 79192 on self', ''),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 146, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set uninteractable', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set walk', ''),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -9841.68, 1400.04, 37.1295, 0, 'On just created - Self: Move to position (-9841.68, 1400.04, 37.1295, 0)', ''),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 79273, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79273 hit - Self: Despawn instantly', ''),
(@ENTRY, 0, 5, 6, 8, 0, 100, 0, 79279, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79279 hit - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 128, 610, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79279 hit - Self: Plays Anim with ID 610', ''),
(@ENTRY, 0, 7, 0, 8, 0, 100, 0, 79283, 0, 0, 0, 0, 80, 4251500, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79283 hit - Self: Start timed action list id #Shadowy Figure #0 (4251500) (update out of combat)', ''),
(@ENTRY, 0, 8, 0, 8, 0, 100, 0, 79284, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79284 hit - Self: Talk 3 to invoker', ''),
(@ENTRY, 0, 9, 0, 8, 0, 100, 0, 79287, 0, 0, 0, 0, 80, 4251501, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79287 hit - Self: Start timed action list id #Shadowy Figure #1 (4251501) (update out of combat)', '');

-- Timed list 4251500 smart ai
SET @ENTRY := 4251500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 128, 593, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 593', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Talk 2 to invoker', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 128, 606, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 606', '');

-- Timed list 4251501 smart ai
SET @ENTRY := 4251501;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 4 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Talk 5 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 0, 11, 79275, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.5 seconds - Self: Cast spell  79275 on Self', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 11, 24222, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell  24222 on Self', '');

-- Glubtok smart ai
SET @ENTRY := 42492;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 1000, 1000, 0, 0, 0, 11, 64195, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds - Self: Cast spell  64195 on Self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Time = 1 seconds - Self: Set react state to Passive', ''),
(@ENTRY, 0, 2, 0, 8, 0, 100, 0, 79273, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79273 hit - Self: Despawn instantly', ''),
(@ENTRY, 0, 3, 0, 8, 0, 100, 0, 79290, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79290 hit - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 4, 0, 8, 0, 100, 0, 79292, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79292 hit - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 5, 0, 8, 0, 100, 0, 79294, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79294 hit - Self: Talk 2 to invoker', ''),
(@ENTRY, 0, 6, 0, 8, 0, 100, 0, 79297, 0, 0, 0, 0, 80, 4249200, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  79297 hit - Self: Start timed action list id #Glubtok #0 (4249200) (update out of combat)', '');

-- Timed list 4249200 smart ai
SET @ENTRY := 4249200;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 3 to invoker', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8 seconds - Self: Talk 4 to invoker', '');

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry`=79273 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 79273, 0, 0, 51, 0, 5, 42515, 0, 0, 0, '', 'Despawn Jangolode Actors - Target Shadowy Figure'),
(13, 1, 79273, 0, 1, 51, 0, 5, 42492, 0, 0, 0, '', 'Despawn Jangolode Actors - Target Glubtok');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (42492, 42515);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `Comment`) VALUES
(42492, 0, 0, 'What little humie want? Why you call Glubtok?', 12, 0, 100, 396, 0, 0, 42418, 'Glubtok to Player'),
(42492, 1, 0, 'Glubtok crush you!', 12, 0, 100, 15, 0, 0, 42420, 'Glubtok to Player'),
(42492, 2, 0, 'What option two?', 12, 0, 100, 396, 0, 0, 42422, 'Glubtok to Player'),
(42492, 3, 0, 'So Glubtok have two choices: die or be rich and powerful?', 12, 0, 100, 396, 0, 0, 42425, 'Glubtok to Player'),
(42492, 4, 0, 'Glubtok take choice two.', 12, 0, 100, 396, 0, 0, 42427, 'Glubtok to Player'),
(42515, 0, 0, 'Sad... Is this the life that you had hoped for, Glubtok? Running two-bit extortion operations out of a cave?', 12, 0, 100, 0, 0, 0, 42419, 'Shadowy Figure to Player'),
(42515, 1, 0, 'Oh will you? Do you dare cross that line and risk your life?', 12, 0, 100, 0, 0, 0, 42421, 'Shadowy Figure to Player'),
(42515, 2, 0, 'You may attempt to kill me - and fail - or you may take option two.', 12, 0, 100, 0, 0, 0, 42423, 'Shadowy Figure to Player'),
(42515, 3, 0, 'You join me and I shower wealth and power upon you.', 12, 0, 100, 396, 0, 0, 42424, 'Shadowy Figure to Player'),
(42515, 4, 0, 'I thought you\'d see it my way.', 12, 0, 100, 153, 0, 0, 42428, 'Shadowy Figure to Player'),
(42515, 5, 0, 'I will call for you when the dawning is upon us.', 12, 0, 100, 397, 0, 0, 42429, 'Shadowy Figure to Player');

-- SpellScriptNames
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_westfall_quest_credit_jangolode_event', 'spell_westfall_summon_lous_house', 'spell_westfall_despawn_jangolode_actor', 'spell_westfall_livin_the_life_ping_glubtok', 'spell_westfall_livin_the_life_ping_figure');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79275, 'spell_westfall_quest_credit_jangolode_event'),
(79262, 'spell_westfall_summon_lous_house'),
(79273, 'spell_westfall_despawn_jangolode_actor'),
(79290, 'spell_westfall_livin_the_life_ping_glubtok'),
(79292, 'spell_westfall_livin_the_life_ping_glubtok'),
(79294, 'spell_westfall_livin_the_life_ping_glubtok'),
(79297, 'spell_westfall_livin_the_life_ping_glubtok'),
(79279, 'spell_westfall_livin_the_life_ping_figure'),
(79283, 'spell_westfall_livin_the_life_ping_figure'),
(79284, 'spell_westfall_livin_the_life_ping_figure'),
(79287, 'spell_westfall_livin_the_life_ping_figure');
