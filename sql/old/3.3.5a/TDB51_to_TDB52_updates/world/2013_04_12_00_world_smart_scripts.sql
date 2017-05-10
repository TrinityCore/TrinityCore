UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=37120;
DELETE FROM `smart_scripts` WHERE `entryorguid`=37120;
INSERT INTO `smart_scripts` (`entryorguid`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(37120,20,24549,57,49888,1,7,'Highlord Darion Mograine - On quest rewarded - Remove item from player');
