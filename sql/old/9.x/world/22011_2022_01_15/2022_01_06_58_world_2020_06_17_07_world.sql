--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11798,11800) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11798,0,0,1,62,0,100,0,4042,0,0,0,0,11,28001,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bunthen Plainswind - On Gossip Option 0 Selected - Cast 'Flight Path'"),
(11798,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Bunthen Plainswind - On Link - Close Gossip"),
(11800,0,0,1,62,0,100,0,4041,0,0,0,0,11,27998,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Silva Fil'naveth - On Gossip Option 0 Selected - Cast 'Flight Path'"),
(11800,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Silva Fil'naveth - On Link - Close Gossip");
