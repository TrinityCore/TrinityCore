-- Template
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=42339; -- Canal Crab

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 42339;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42339, 78974, 1, 0);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 18) AND (`SourceGroup` IN (42339));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(18, 42339, 78974, 0, 0, 47, 0, 26177, 8, 0, '', 0, 'Clicker has Feeling Crabby? (26177) in state incomplete');

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID`=26177;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(26177, 2, 0, 0, 0, 0, 0, 0, 0, 'These crabs look great!  I will clean these up and make sure that the King hears about your contribution.  Thanks!', 60257); -- Feeling Crabby?

DELETE FROM `quest_details` WHERE `ID`=26177;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26177, 1, 1, 1, 0, 0, 0, 0, 0, 60257); -- Feeling Crabby?

DELETE FROM `quest_request_items` WHERE `ID`=26177;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26177, 6, 6, 0, 0, 'You must have fast hands!  I can\'t believe you caught all those crabs so quickly!', 60257); -- Feeling Crabby?

-- Canal Crab smart ai
SET @ENTRY := 42339;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 8, 0, 100, 0, 78974, 0, 0, 0, 0, 11, 78975, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On spell  78974 hit - Self: Cast spell  78975 on Caster', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On spell  78974 hit - Self: Despawn in 1 s', '');
