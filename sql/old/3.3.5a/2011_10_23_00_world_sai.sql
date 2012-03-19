-- Horde

-- Fix quest 8359 "Flexing for Nougat"
DELETE FROM `smart_scripts` WHERE `entryorguid`=6929 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6929,0,0,1,62,0,100,0,441,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Gryshka - On gossip option 0 select - Close gossip'),
(6929,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Gryshka - On gossip option 0 select - Player cast Trick or Treat on self'),
(6929,0,2,0,22,0,100,0,41,0,0,0,33,6929,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Gryshka - On flex emote - Give kill credit');

-- Fix quest 8358 "Incoming Gundrop"
UPDATE creature_template SET `AIName`= 'SmartAI' WHERE `entry`=11814;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11814 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(11814,0,1,0,22,0,100,0,264,0,0,0,33,11814,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Kali Remik - On train emote - Give kill credit');

-- Fix quest 8354 "Chicken Clucking for a Mint"
DELETE FROM `smart_scripts` WHERE `entryorguid`=6741 and `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(6741,0,0,1,62,0,100,0,348,2,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Norman - On gossip option 2 select - Close gossip'),
(6741,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Norman - On gossip option 2 select - Player cast Trick or Treat on self'),
(6741,0,2,0,22,0,100,0,22,0,0,0,33,6741,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Norman - On chicken emote - Give kill credit');

-- Fix quest 8360 "Dancing for Marzipan"
UPDATE creature_template SET `AIName`= 'SmartAI' WHERE `entry`=6746;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6746 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6746,0,1,0,22,0,100,0,34,0,0,0,33,6746,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Pala - On dance emote - Give kill credit');

-- Alliance

-- Fix quest 8356 "Flexing for Nougat"
DELETE FROM `smart_scripts` WHERE `entryorguid`=6740 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6740,0,0,1,62,0,100,0,342,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Allison - On gossip option 0 select - Close gossip'),
(6740,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Innkeeper Allison - On gossip option 0 select - Player cast Trick or Treat on self'),
(6740,0,2,0,22,0,100,0,41,0,0,0,33,6740,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Allison - On flex emote - Give kill credit');

-- Fix quest 8358 "Incoming Gundrop"
UPDATE creature_template SET `AIName`= 'SmartAI' WHERE `entry`=6826;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6826 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6826,0,1,0,22,0,100,0,264,0,0,0,33,6826,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Talvash del Kissel - On train emote - Give kill credit');

-- Fix quest 8360 "Dancing for Marzipan"
UPDATE creature_template SET `AIName`= 'SmartAI' WHERE `entry`=6735;
DELETE FROM `smart_scripts` WHERE `entryorguid`=6735 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(6735,0,0,1,62,0,100,0,1581,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Saelienne - On gossip option 0 select - Close gossip'),
(6735,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Saelienne - On gossip option 0 select - Player cast Trick or Treat on self'),
(6735,0,2,0,22,0,100,0,34,0,0,0,33,6735,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Saelienne - On dance emote - Give kill credit');

-- Fix quest 8353 "Chicken Clucking for a Mint"
DELETE FROM `smart_scripts` WHERE `entryorguid`=5111 and `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(5111,0,0,1,62,0,100,0,345,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Firebrew - On gossip option 0 select - Close gossip'),
(5111,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Firebrew - On gossip option 0 select - Player cast Trick or Treat on self'),
(5111,0,2,0,22,0,100,0,22,0,0,0,33,5111,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Innkeeper Firebrew - On chicken emote - Give kill credit');
