UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (33354,33355,33430,33431,33525,33526,33527,33528);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33354,33355,33430,33431,33525,33526,33527,33528) AND `event_type`=6;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
(33354,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Corrupted Servitor - on death set instance data for achievement Con-Speed-Atory'),
(33355,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Misguided Nymph - on death set instance data for achievement Con-Speed-Atory'),
(33430,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Guardian Lasher - on death set instance data for achievement Con-Speed-Atory'),
(33431,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Forest Swarmer - on death set instance data for achievement Con-Speed-Atory'),
(33525,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Mangrove Ent - on death set instance data for achievement Con-Speed-Atory'),
(33526,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Ironroot Lasher - on death set instance data for achievement Con-Speed-Atory'),
(33527,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Natures\'s Blade - on death set instance data for achievement Con-Speed-Atory'),
(33528,0,0,0,6,0,100,0,0,0,0,0,34,2,1,0,0,0,0,19,32906,0,0,0,0,0,0,'Guardian of Life - on death set instance data for achievement Con-Speed-Atory');
