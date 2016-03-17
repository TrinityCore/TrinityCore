--
SET @ENTRY := 62266;
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` = @ENTRY;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,@ENTRY,64,0,0,'Disable LOS for Spell Trigger 3 adds');
