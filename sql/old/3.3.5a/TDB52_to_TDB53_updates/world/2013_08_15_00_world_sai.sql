-- SELECT `entryorguid`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`comment` FROM `smart_scripts`  WHERE `event_type`=14;
UPDATE `smart_scripts` SET `event_type`=74,`event_param2`=`event_param1`,`event_param1`=0,`target_type`=9 WHERE `entryorguid`=20049 AND `id`=4;
UPDATE `smart_scripts` SET `event_type`=74,`event_param2`=`event_param1`,`event_param1`=0,`target_type`=9 WHERE `entryorguid`=9045 AND `id`=3;
UPDATE `smart_scripts` SET `event_type`=74,`target_type`=9 WHERE `event_type`=14 AND `event_param1`=0 AND `event_param2` > 0 AND `event_param2` < 100;
UPDATE `smart_scripts` SET `event_param1`=`event_param2`,`event_param2`=30 WHERE `event_type`=14 AND `event_param2` >= 100;
