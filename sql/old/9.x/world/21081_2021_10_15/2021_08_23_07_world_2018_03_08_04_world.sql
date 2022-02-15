-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (36460) AND `SourceTypeOrReferenceId`=13;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, COMMENT) VALUES 
(13, 4, 36460, 0, 0, 31, 0, 3, 21262, 0, 0, 0, 0, "", "");

SET @ENTRY := 21262;
UPDATE `creature_template` SET `AIName`='SmartAI', `flags_extra`=130 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,36460,0,5000,5000,11,34815,0,0,0,0,0,1,0,0,0,0,0,0,0,"Equipement trigger - On Spellhit - Cast spell"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,20,183808,5,0,0,0,0,0,"Equipement trigger - On Spellhit - despawn gob"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,20,183807,5,0,0,0,0,0,"Equipement trigger - On Spellhit - despawn gob"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,20,183806,5,0,0,0,0,0,"Equipement trigger - On Spellhit - despawn gob"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,20,183805,5,0,0,0,0,0,"Equipement trigger - On Spellhit - despawn gob");

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` IN (36460);
INSERT INTO `disables`(`sourceType`,`entry`,`flags`,`comment`) VALUES
(0,36460,64,'Ignore LOS');
