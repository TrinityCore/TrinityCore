--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27909 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2790900 AND 2790902 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27909,0,0,0,37,0,100,0,0,0,0,0,0,116,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On AI Initialize - Set Corpse Delay"),
(27909,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On AI Initialize - Set Reactstate Passive"),
(27909,0,2,0,11,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On Spawn - Set Event Phase 1"),
(27909,0,3,0,38,0,100,0,1,1,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On Data Set 1 1 - Set Event Phase 2"),
(27909,0,4,0,6,1,100,0,0,0,0,0,0,11,49960,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On Death - Cast 'Summon Random Drakkari' (Phase 1)"),
(27909,0,5,0,6,2,100,0,0,0,0,0,0,11,49952,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Darkweb Victim - On Death - Cast 'Summon Kurzel' (Phase 2)");

DELETE FROM `spell_script_names` WHERE `spell_id` = 49960 AND `ScriptName` = 'spell_summon_random_drakkari';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49960,'spell_summon_random_drakkari');
