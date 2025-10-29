-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108585 AND `DifficultyID`=0); -- 108585 (Loranea) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108747 AND `DifficultyID`=0); -- 108747 (Kymba Quickwidget) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108583 AND `DifficultyID`=0); -- 108583 (Voraatios the Benedictive) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108755 AND `DifficultyID`=0); -- 108755 (Stormsinger Taalos) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108765 AND `DifficultyID`=0); -- 108765 (Seona Fireweaver) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108758 AND `DifficultyID`=0); -- 108758 (Lightshielder Baetrix) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108051 AND `DifficultyID`=0); -- 108051 (Alasdair Whitepeak) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108753 AND `DifficultyID`=0); -- 108753 (Rorin Rivershade) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108587 AND `DifficultyID`=0); -- 108587 (Su-Lai Snowpetal) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108757 AND `DifficultyID`=0); -- 108757 (Haagios) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108743 AND `DifficultyID`=0); -- 108743 (Niall Frostdrift) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108742 AND `DifficultyID`=0); -- 108742 (Fen Cinderpaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108745 AND `DifficultyID`=0); -- 108745 (Antone Sula) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108754 AND `DifficultyID`=0); -- 108754 (Fingall Flamehammer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108141 AND `DifficultyID`=0); -- 108141 (Brother Zuo) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108756 AND `DifficultyID`=0); -- 108756 (Navea the Purifier) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108749 AND `DifficultyID`=0); -- 108749 (Bridgette Hicks) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108744 AND `DifficultyID`=0); -- 108744 (Tessa Wybroff) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=108746 AND `DifficultyID`=0); -- 108746 (Zelena Moonbreak) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107835 AND `DifficultyID`=0); -- 107835 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107827 AND `DifficultyID`=0); -- 107827 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107833 AND `DifficultyID`=0); -- 107833 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107823 AND `DifficultyID`=0); -- 107823 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107841 AND `DifficultyID`=0); -- 107841 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107839 AND `DifficultyID`=0); -- 107839 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107829 AND `DifficultyID`=0); -- 107829 (Alliance Recruit) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=107826 AND `DifficultyID`=0); -- 107826 (Alliance Recruit) - CanSwim

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=108723 AND `MenuID`=19861);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(108723, 19861, 63003); -- Kihra

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (108722,108723,108742,108743,108744,108745,108746,108747,108748,108749,108750,108751,108752,108753,108754,108755,108756,108757,108758,108759);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(108722, 0, 0, 'Well struck.', 12, 0, 100, 4, 0, 0, 114451, 0, 'Ramall Trueoak'),
(108723, 0, 0, 'Thank you for the duel.', 12, 0, 100, 25, 0, 0, 114452, 0, 'Kihra'),
(108742, 0, 0, 'You have bested me.', 12, 0, 100, 0, 0, 0, 114456, 0, 'Fen Cinderpaw'), -- BroadcastTextID: 102494 - 114456
(108743, 0, 0, 'You have bested me.', 12, 0, 100, 5, 0, 0, 114456, 0, 'Niall Frostdrift'), -- BroadcastTextID: 102494 - 114456
(108744, 0, 0, 'Well struck.', 12, 0, 100, 0, 0, 0, 114451, 0, 'Tessa Wybroff'),
(108745, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 274, 0, 0, 114455, 0, 'Antone Sula'),
(108746, 0, 0, 'You take this round.', 12, 0, 100, 0, 0, 0, 114458, 0, 'Zelena Moonbreak'),
(108747, 0, 0, 'Good battle.', 12, 0, 100, 21, 0, 0, 114450, 0, 'Kymba Quickwidget'),
(108748, 0, 0, 'Thank you for the duel.', 12, 0, 100, 274, 0, 0, 114452, 0, 'Audra Stoneshield'),
(108749, 0, 0, 'Thank you for the duel.', 12, 0, 100, 0, 0, 0, 114452, 0, 'Bridgette Hicks'),
(108750, 0, 0, 'You have won.', 12, 0, 100, 4, 0, 0, 114453, 0, 'Eunna Young'),
(108751, 0, 0, 'Well struck.', 12, 0, 100, 5, 0, 0, 114451, 0, 'Arctic Whitemace'),
(108752, 0, 0, 'You have bested me.', 12, 0, 100, 0, 0, 5495, 114456, 0, 'Ciarra Neil'), -- BroadcastTextID: 102494 - 114456
(108753, 0, 0, 'Fine duel.', 12, 0, 100, 274, 0, 0, 114457, 0, 'Rorin Rivershade'),
(108754, 0, 0, 'You have bested me.', 12, 0, 100, 0, 0, 0, 114456, 0, 'Fingall Flamehammer'), -- BroadcastTextID: 102494 - 114456
(108755, 0, 0, 'You have won.', 12, 0, 100, 0, 0, 0, 114453, 0, 'Stormsinger Taalos'),
(108756, 0, 0, 'You have won.', 12, 0, 100, 0, 0, 0, 114453, 0, 'Navea the Purifier'),
(108757, 0, 0, 'Next time I won\'t be so easy on you!', 12, 0, 100, 5, 0, 0, 114455, 0, 'Haagios'),
(108758, 0, 0, 'You have won.', 12, 0, 100, 25, 0, 0, 114453, 0, 'Lightshielder Baetrix'),
(108759, 0, 0, 'Thank you for the duel.', 12, 0, 100, 25, 0, 0, 114452, 0, 'Loranea');

-- Creature Sparring
DELETE FROM `creature_template_sparring` WHERE `Entry` IN (108765,108767);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(108765, 85),
(108767, 85);

-- Creature String update
UPDATE `creature` SET `StringId` = 'CosmeticDuelCheer' WHERE `guid` IN (651117, 651122, 651121, 651142, 651141, 651150, 651128, 651144, 651151, 651156, 651143, 651114, 651115, 651111, 651079, 651085, 651093, 651078, 651083, 651066, 651070, 651064, 651091, 651086);

-- Quest
DELETE FROM `creature_queststarter` WHERE (`id`=107934 AND `quest`=42782);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(107934, 42782, 63003); -- To Be Prepared offered by Recruiter Lee

DELETE FROM `quest_request_items` WHERE `ID`=42782;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(42782, 0, 0, 0, 0, 'The Light protects those who protect themselves!', 63003); -- To Be Prepared

DELETE FROM `quest_template_addon` WHERE `ID` = 42782;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(42782, 0, 0, 0, 40519, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Alliance Recruit smart ai
SET @ENTRY := 107826;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107826 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107826, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107823;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107823 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107823, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107841;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107841 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107841, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107829;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107829 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107829, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107839;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107839 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107839, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107835;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107835 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107835, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Alliance Recruit smart ai
SET @ENTRY := 107833;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 3000, 12000, 0, 10, 25, 10, 4, 21, 15, 5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 12 seconds (1 - 3s initially) (OOC) - Self: Play random emote: 25, 10, 4, 21, 15, 5', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 107833 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 107833, 0, 0, 58, 1, 0, 0, 0, 'CosmeticDuelCheer', 0, 'Object has StringID CosmeticDuelCheer');

-- Kiruud the Relentless smart ai
SET @ENTRY := 108767;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 19, 108765, 25, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Attack Closest alive creature Seona Fireweaver (108765) in 25 yards', ''),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 12000, 12000, 0, 11, 172757, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 12 seconds (1s initially) (IC) - Self: Cast spell  172757 on Victim', '');

-- Seona Fireweaver smart ai
SET @ENTRY := 108765;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 0, 19, 108767, 25, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Attack Closest alive creature Kiruud the Relentless (108767) in 25 yards', ''),
(@ENTRY, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 2500, 25000, 0, 11, 198623, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2.5 - 25 seconds (1 - 1s initially) (IC) - Self: Cast spell  198623 on Victim', '');

-- Niall Frostdrift smart ai
SET @ENTRY := 108743;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108743, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108743)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171858, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell  171858 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Ramall Trueoak smart ai
SET @ENTRY := 108722;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108722)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171773, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171773 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Tessa Wybroff smart ai
SET @ENTRY := 108744;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108744, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108744)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171863, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171863 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Zelena Moonbreak smart ai
SET @ENTRY := 108746;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108746, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108746)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172028, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172028 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Audra Stoneshield smart ai
SET @ENTRY := 108748;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108748, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108748)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172772, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172772 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Haagios smart ai
SET @ENTRY := 108757;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108757, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108757)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171884, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171884 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

 -- Ciarra Neil smart ai
SET @ENTRY := 108752;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108752, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108752)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171884, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171884 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

 -- Kihra smart ai
SET @ENTRY := 108723;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108723, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108723)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171777, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171777 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Stormsinger Taalos smart ai
SET @ENTRY := 108755;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108755, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108755)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172677, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172677 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Lightshielder Baetrix smart ai
SET @ENTRY := 108758;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108758, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108758)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171922, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171922 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Navea the Purifier smart ai
SET @ENTRY := 108756;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108756, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108756)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172675, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172675 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Antone Sula smart ai
SET @ENTRY := 108745;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108745, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108745)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172029, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172029 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Loranea smart ai
SET @ENTRY := 108759;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108722)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171919, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171919 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Rorin Rivershade smart ai
SET @ENTRY := 108753;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108753, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108753)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172670, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172670 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Bridgette Hicks smart ai
SET @ENTRY := 108749;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108749, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108749)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172769, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172769 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Kymba Quickwidget smart ai
SET @ENTRY := 108747;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108722, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108722)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171957, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171957 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Fingall Flamehammer smart ai
SET @ENTRY := 108754;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108754, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108754)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172779, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172779 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Eunna Young smart ai
SET @ENTRY := 108750;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108750, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108750)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 172757, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 172757 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');

-- Fen Cinderpaw smart ai
SET @ENTRY := 108742;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 37, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On AI initialize - Self: Set invincibility to 1 HP', ''),
(@ENTRY, 0, 1, 2, 62, 0, 100, 0, 19861, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Gossip player: Close gossip', ''),
(@ENTRY, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 2502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set faction to 2502', ''),
(@ENTRY, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Self: Set emote state to 333', ''),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 19861 selected - Set event phase to phase 1', ''),
(@ENTRY, 0, 5, 6, 2, 1, 100, 1, 0, 5, 0, 0, 0, 33, 108742, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Victim: Give kill credit (108742)', ''),
(@ENTRY, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 0, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Stop combat', ''),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 0, 2, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Set faction to 35', ''),
(@ENTRY, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Talk 0 to invoker', ''),
(@ENTRY, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Self: Evade', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'When health between 0%-5%% (once) - Set event phase to default (0)', ''),
(@ENTRY, 0, 11, 0, 0, 1, 100, 0, 0, 0, 2000, 3000, 0, 11, 171764, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 3 seconds (0 - 0s initially) (IC) - Self: Cast spell 171764 on Victim', ''),
(@ENTRY, 0, 12, 0, 1, 0, 100, 0, 0, 0, 2000, 12000, 0, 10, 25, 4, 21, 15, 5, 274, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 12 seconds (0 - 0s initially) (OOC) - Self: Play random emote: 25, 4, 21, 15, 5, 274', ''),
(@ENTRY, 0, 13, 0, 1, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 seconds (OOC) - Self: Reset faction', '');
