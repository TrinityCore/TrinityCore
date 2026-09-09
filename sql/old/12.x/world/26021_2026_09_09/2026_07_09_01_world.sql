-- SpellArea
DELETE FROM `spell_area` WHERE `spell` IN (75974,74145) AND `area` IN (5051,5052,5012);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(75974, 5051, 14482, 0, 0, 0, 2, 3, 66, 11), -- (Cast) SpellID: 75974 (Kelp Forest Quest Invisibility Detection Erunak)
(75974, 5052, 14482, 0, 0, 0, 2, 3, 66, 11), -- (Cast) SpellID: 75974 (Kelp Forest Quest Invisibility Detection Erunak)
(75974, 5012, 14482, 0, 0, 0, 2, 3, 66, 11), -- (Cast) SpellID: 75974 (Kelp Forest Quest Invisibility Detection Erunak)
(74145, 5051, 14482, 0, 0, 0, 2, 3, 66, 11), -- (Cast) SpellID: 74145 (Kelp Forest Quest Invisibility Detection 1)
(74145, 5052, 14482, 0, 0, 0, 2, 3, 66, 11), -- (Cast) SpellID: 74145 (Kelp Forest Quest Invisibility Detection 1)
(74145, 5012, 14482, 0, 0, 0, 2, 3, 66, 11); -- (Cast) SpellID: 74145 (Kelp Forest Quest Invisibility Detection 1)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=53, `StaticFlags1`=0x0, `VerifiedBuild`=68453 WHERE (`Entry`=36915 AND `DifficultyID`=0); -- 36915 (Erunak Stonespeaker) - 

-- Quest
UPDATE `quest_details` SET `Emote2`=396, `VerifiedBuild`=68453 WHERE `ID`=14482; -- Call of Duty
UPDATE `creature_queststarter` SET `VerifiedBuild`=68453 WHERE (`id`=36799 AND `quest`=14482);

UPDATE `quest_template_addon` SET `NextQuestID` = 0, `ExclusiveGroup` = 0  WHERE `ID` IN (28827,27724,14481);

-- Call of Duty
SET @ENTRY := 14482;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 85, 78318, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Cast spell 78318 on self', ''),
(@ENTRY, 5, 1, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 28, 78318, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Remove aura due to spell  78318', '');
