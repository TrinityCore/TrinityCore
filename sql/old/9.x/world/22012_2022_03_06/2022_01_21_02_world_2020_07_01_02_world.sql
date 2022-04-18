--
UPDATE `areatrigger_scripts` SET `ScriptName` = "SmartTrigger" WHERE `entry` = 4960;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4960 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4960,2,0,1,46,0,100,0,4960,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Agmar's Hammer) - On Trigger - Store Targetlist"),
(4960,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,26649,0,0,0,0,0,0,0,"Areatrigger (Agmar's Hammer) - On Link - Send Target 1 (Messenger Torvus)"),
(4960,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,19,26649,0,0,0,0,0,0,0,"Areatrigger (Agmar's Hammer) - On Link - Set Data 0 1 (Messenger Torvus)");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4960 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- CanTakeQuest (level checks) are not included because https://www.wowhead.com/npc=26649/messenger-torvus#comments:id=441648
(22,1,4960,2,0,8,0,11916,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if quest 'Hellscream's Champion' is rewarded"),
(22,1,4960,2,0,9,0,12033,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player has not taken quest 'Message from the West'"),
(22,1,4960,2,0,28,0,12033,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if quest 'Message from the West' is not completed");
-- Handled in core
-- (22,1,4960,2,0,36,0,0,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player is alive");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 26649;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26649 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- No timer?
(26649,0,0,0,38,0,100,0,0,1,30000,30000,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Messenger Torvus - On Data Set 0 1 - Say Line 0");

UPDATE `creature_text` SET `comment` = "Messenger Torvus" WHERE `CreatureID` = 26649;
