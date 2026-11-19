-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (38250) AND `SourceTypeOrReferenceId`=13;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES 
(13, 1, 38250, 0, 0, 31, 0, 3, 22058, 0, 0, 0, 0, "", "");

SET @ENTRY := 22061;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,38250,0,0,0,0,0,19,22058,0,0,0,0,0,0,"Shadowmoon Soulstealer - On reset - Cast spell");

UPDATE `creature_template_addon` SET `auras`='38376' WHERE `entry` IN (22058);
UPDATE `creature_template_addon` SET `emote`=468, `auras`='38442' WHERE `entry` IN (22081);
DELETE FROM `creature_addon` WHERE `guid` IN (77374, 77375, 77376, 77379, 77380, 77381, 77382, 77383, 77384, 77387, 77389, 77390, 77391, 77392, 77393, 77394);
