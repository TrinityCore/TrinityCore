--
/*
DELETE FROM `smart_scripts` WHERE `entryorguid`=18794 AND `id`=34;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18794,0,34,0,1,0,100,0,0,0,0,0,11,32958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cabal Ritualist - Out of Combat - Cast 'Crystal Channel'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=0 AND `SourceEntry`=32958;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,32958,0,0,31,0,3,18793,0,0,"","Crystal Channel – Effect 0 - Cast only on Invisible Target 18793.");
*/
