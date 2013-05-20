-- Fix quest The Ring of Blood: The Final Challenge (Nagrand Arena).
UPDATE `smart_scripts` SET `target_type`=16 WHERE (`entryorguid`=18398 AND `id`=1) OR (`entryorguid`=18399 AND `id`=4) OR (`entryorguid`=18400 AND `id`=5) OR (`entryorguid`=18401 AND `id`=3) OR (`entryorguid`=18402 AND `id`=4 AND `link`=5);
UPDATE `smart_scripts` SET `action_param2`=5 WHERE (`entryorguid`=1847100 AND `id`=1) OR (`entryorguid`=1847101 AND `id` IN (1,2)) OR (`entryorguid`=1847102 AND `id`=1) OR (`entryorguid`=1847103 AND `id`=1) OR (`entryorguid`=1847104 AND `id`=1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=18069 AND `id`= 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18069,0,5,0,6,0,100,0,0,0,0,0,15,9977,0,0,0,0,0,16,0,0,0,0,0,0,0,"Mogor - On Death - Give Quest Credit");
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|0x10000000 WHERE `entry`=18069;
UPDATE `creature` SET `spawntimesecs`=0 WHERE `id`=18069;
