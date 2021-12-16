-- Gurubashi
UPDATE `creature_template` SET `minlevel` = 63, `maxlevel` = 63, `speed_walk` = 1, `unit_flags` = 33555008 WHERE `entry` = 15047; -- Vmangos

DELETE FROM `smart_scripts` WHERE `entryorguid` = 15047 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15047,0,0,0,63,0,100,0,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Gurubashi - On Just Created - Disable Auto Attack"),
-- Apparently you can somehow avoid it because it's not used always https://youtu.be/-LnQ2hru96M?t=380
-- I don't like that you will be in combat with it, and No Reset flag is used to prevent double cast
-- (he spawns for 30 sec so can enter in combat twice). Definitely he works differently
(15047,0,1,0,0,0,50,257,3000,3000,0,0,0,11,24178,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Gurubashi - In Combat - Cast 'Will of Hakkar' (No Repeat) (No Reset)");

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 15047;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(15047,1,1,0,1,0,0);

-- Image of Commander Ameer
-- Previously I was struggling to understand what exactly he does and why calls despawn event which looked like on-aggro event
-- without entering in combat with anyone around. Well, now he can be attacked by the creatures around and that's too not correct
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` = 20482;
