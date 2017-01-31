-- Extinguishing Hope
DELETE FROM`conditions` WHERE`SourceTypeOrReferenceId`= 13 AND `SourceEntry`=80208;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 80208, 0, 0, 31, 0, 3, 42940, 0, 0, 0, '', 'Spray Water requires target Northshire Vineyards Fire Trigger');

-- Northshire Vineyards Fire Trigger
SET @ENTRY:= 42940;
SET @SOURCETYPE:= 0;
DELETE FROM `smart_scripts` WHERE `entryorguid`= @ENTRY AND `source_type`= @SOURCETYPE;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @ENTRY;
INSERT INTO`smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - SetEventPhase_1 on Reset"),
(@ENTRY,@SOURCETYPE,1,0,23,1,100,0,80175,0,0,0,11,80175,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Cast_Vineyard Fire"),
(@ENTRY,@SOURCETYPE,2,3,8,1,100,0,80208,0,0,0,33,42940,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Give Kill Credit on SpellHit_Spray Water"),
(@ENTRY,@SOURCETYPE,3,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - SetEventPhase_2"),
(@ENTRY,@SOURCETYPE,4,0,8,2,100,0,80208,0,1000,1000,37,80223,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Die on SpellHit_Spray Water");
