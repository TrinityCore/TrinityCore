DELETE FROM `areatrigger_involvedrelation` WHERE `id` IN (5710,5711,5712,5714,5715,5716);

DELETE FROM `smart_scripts` WHERE `entryorguid`=5710 AND `source_type`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(5710,2,0,1,46,0,100,0,5710,0,0,0,86,71713,0,10,208836,38340,0,7,0,0,0,0,0,0,0,"On Trigger - Crosscast - Invoker"),
(5710,2,1,0,61,0,100,0,0,0,0,0,51,0,0,0,0,0,0,10,208836,38340,0,0,0,0,0,"Link - Kill - Bunny");

UPDATE `quest_template` SET `SpecialFlags`=0 WHERE `Id` IN (24849,24851);
