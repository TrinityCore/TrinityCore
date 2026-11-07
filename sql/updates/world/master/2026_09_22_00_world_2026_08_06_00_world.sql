--
UPDATE `smart_scripts` SET `event_type` = 1, `event_param1` = 4000, `event_param2` = 5000, `event_param3` = 4000, `event_param4` = 5000, `comment` = "Surveyor Candress - Out of Combat - Cast 'Red Beam'" WHERE `entryorguid` = 16522 AND `source_type` = 0 AND `id` = 0;

DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` = 31515; 
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,31515,64,'','',"Disable LOS for spell 'Red Beam'");
