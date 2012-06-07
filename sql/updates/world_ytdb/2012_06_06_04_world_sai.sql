-- Forsaken Plaguebringer SAI
SET @ENTRY  := 23760;
SET @SPELL1 := 44005; -- Shoot Plague
SET @SPELL2 := 3436;  -- Wandering Plague
SET @SPELL3 := 11978; -- Kick
SET @SPELL4 := 43333; -- Shoot Plague
UPDATE `creature_template` SET `equipment_id`=509,`AIName`= 'SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`) VALUES (@ENTRY,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,11000,7000,11000,11,@SPELL1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Forsaken Plaguebringer - Combat - Cast Shoot Plague'),
(@ENTRY,0,1,0,0,0,100,0,4000,10000,40000,50000,11,@SPELL2,0,0,0,0,0,2,0,0,0,0,0,0,0,'Forsaken Plaguebringer - Combat - Cast Wandering Plague'),
(@ENTRY,0,2,0,0,0,80,0,4000,12000,12000,18000,11,@SPELL3,0,0,0,0,0,2,0,0,0,0,0,0,0,'Forsaken Plaguebringer - Combat - Cast Kick'),
(@ENTRY,0,3,0,10,0,100,0,24042,40,6000,11000,11,@SPELL4,0,0,0,0,0,1,0,0,0,0,0,0,0,'Forsaken Plaguebringer - OOC - Cast Shoot Plague'); -- Not working correctly
-- Spell Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (43333);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,43333,0,31,3,24042,0,0,'','Spell 43333 can target Generic Trigger LAB - OLD');
