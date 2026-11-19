--
DELETE FROM `smart_scripts` WHERE `entryorguid`=5089 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(5089,0,0,1,2,0,100,1,0,20,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Balos Jacken - Between 0-20% Health - Say Line 0'),
(5089,0,1,2,61,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Balos Jacken - Link With Previous - Set Faction 35'),
(5089,0,2,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Balos Jacken - Link With Previous - Evade'),
(5089,0,3,0,1,0,100,0,120000,120000,120000,120000,2,54,0,0,0,0,0,1,0,0,0,0,0,0,0,'Balos Jacken - Out of Combat - Set Faction 54');
