-- Hulking Abomination
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=31140;
DELETE FROM `smart_scripts` WHERE `entryorguid`=31140 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(31140,0,6,0,0,0,0,0,11,58995,2,1,'Hulking Abomination - Just died - Cast Exploding Corpse'),
(31140,1,9,1,8,40,0,0,11,50335,0,7,'Hulking Abomination - Invoker in range of 8 to 40 yards - Cast Scourge Hook'),
(31140,2,0,0,3000,3000,7000,7000,11,40504,0,2,'Hulking Abomination - In combat - Cast Cleave');
