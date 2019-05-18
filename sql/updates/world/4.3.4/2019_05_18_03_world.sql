-- Fix Quest 27943 "Angered Spirits"

-- Furious Specter SAI
SET @ENTRY := 47220;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,87976,0,0,0,0,11,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Specter - On Spellhit - Cast 'Suicide'");

DELETE FROM `quest_offer_reward` WHERE `ID`=27943;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`,`Emote2`,`RewardText`) VALUES
(27943, 396, 0, 'Very goot!$b$bYou have earned yourself a place at zhe ritual.$b$bYou shall be among zhe first to velcome Gobbles back to his... original form.');

-- Condition for source Spell condition type Health point percentage
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=87996 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 87996, 0, 1, 31, 1, 3, 47220, 0, 0, 0, 0, '', 'Spell Fire LPAC will hit target if target is Furious Specter'),
(17, 0, 87996, 0, 1, 38, 1, 50, 4, 0, 0, 0, 0, '', 'Spell Fire LPAC will hit the caster of the spell if target health percentage is equal to or lower than 50% of max Health.');
