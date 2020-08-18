-- https://www.wowhead.com/npc=17769/blood-knight-adept#comments:id=932320
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4339 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4339,2,0,0,46,0,100,0,4339,0,0,0,0,5,66,0,0,0,0,0,9,17769,0,20,0,0,0,0,0,"Areatrigger (Silvermoon City) - On Trigger - Play Emote 66 (Blood Knight Adept)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4339;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4339,"SmartTrigger");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 4339 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,4339,2,0,15,0,2,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player is a Paladin");
