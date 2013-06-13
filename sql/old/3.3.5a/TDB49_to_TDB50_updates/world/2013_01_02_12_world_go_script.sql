-- remove the summoning of the herald and closing of the gate via the brazier
-- this is an instance encounter and should be handled via cpp, reopen the door if npc is dead
DELETE FROM `gameobject_scripts` WHERE `id`=43208;

-- This script will NOT work untill CPP changes are made, this UNSUPPORTS Scarlet Monestry Cathedral wing!
DELETE FROM `gameobject_scripts` WHERE `id` IN (11881,11894);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry` IN (104589,97701);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (104589,97701) AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(104589,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,11875,104591,0,0,0,0,0,'Lever - On activate - Activate Chapel Door'),
( 97701,1,0,0,70,0,100,0,2,0,0,0,9,0,0,0,0,0,0,14,11876, 97700,0,0,0,0,0,'Torch - On activate - Activate Secret Door');
