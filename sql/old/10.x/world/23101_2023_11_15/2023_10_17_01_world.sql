-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 94410;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(94410, 0, 0, 'Good luck. I will make my way up to the foothold as soon as I am done with this demon.', 12, 0, 100, 0, 0, 55012, 96676, 5, 'Allari the Souleater to Player');

 -- Allari the Souleater smart ai
SET @ENTRY := 94410;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 39049, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Eye On the Prize (39049) - Player who accepted quest: Talk 0 to invoker'),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 188437, 0, 0, 0, 0, 0, 10, 6000128, 105316, 0, 0, 0, 0, 0, 'After 1s - Creature Allari - Cast Spell: 188437 - to Questioner Arevnaal');

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -6000138;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-6000138, 0, 1, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 11, 188437, 0, 0, 0, 0, 0, 10, 6000127, 94410, 0, 0, 0, 0, 0, 'After 1s - Creature ELM Purpose Bunny - Cast Spell: 188437 - to Allari the Souleater');

-- Allari Souleater (cave)
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 5094 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 5094, 0, 0, 0, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 0, 0, 47, 0, 40379, 64, 0, 1, 'Apply Phase 5094 if Quest 40379 is not rewarded'),
(26, 5094, 0, 1, 0, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 1, 0, 47, 0, 39049, 64, 0, 1, 'Apply Phase 5094 if Quest 39049 is not rewarded'),
(26, 5094, 0, 2, 0, 47, 0, 40378, 2|8|64, 0, 0, 'Apply Phase 5094 if Quest 40378 is complete | in progress | rewarded'),
(26, 5094, 0, 2, 0, 47, 0, 38759, 64, 0, 1, 'Apply Phase 5094 if Quest 38759 is not rewarded');
