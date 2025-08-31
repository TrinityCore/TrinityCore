-- Template
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=1000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=98519; -- Initiate Da-Nel

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=642, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98519 AND `DifficultyID`=0); -- 98519 (Initiate Da-Nel) - CanSwim

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 98519;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(98519, 0, 0, 'Hey, $n! Message for you from Grand Master Hight!', 12, 0, 100, 0, 0, 62014, 100246, 0, 'Initiate Da-Nel to Player'),
(98519, 1, 0, 'Have a safe journey.', 12, 0, 100, 2, 0, 62046, 100251, 0, 'Initiate Da-Nel to Player');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=12103;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(12103, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Before the Storm

UPDATE `quest_description_conditional` SET `VerifiedBuild`=61265 WHERE (`QuestId`=32470 AND `PlayerConditionId`=924 AND `QuestgiverCreatureId`=16908 AND `locale`='enUS') OR (`QuestId`=32470 AND `PlayerConditionId`=923 AND `QuestgiverCreatureId`=16926 AND `locale`='enUS');

DELETE FROM `creature_queststarter` WHERE (`id`=98519 AND `quest`=12103);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(98519, 12103, 61265); -- Before the Storm offered by Initiate Da-Nel

-- Disables (re-enable Quest)
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 12103;

-- Initiate Da-Nel smart ai
SET @ENTRY := 98519;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 29, 2, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Follow Owner/Summoner by distance 2, angle 0', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 2, 0, 19, 0, 100, 0, 12103, 0, 0, 0, 0, 80, 9851900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Before the Storm (12103) - Self: Start timed action list id #Initiate Da-Nel #0 (9851900) (update out of combat)', '');

-- Timed list 9851900 smart ai
SET @ENTRY := 9851900;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Follow None by distance 0, angle 0', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 2', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Talk 1 to invoker', ''),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 85, 105318, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Owner/Summoner: Cast spell 105318 on self', ''),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 20, 0, 0, 'After 0 seconds - Self: Move forward by 0, left by 20, up by 0 yards', ''),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 2 s', '');
