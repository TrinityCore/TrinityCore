-- Add mother pool to pool template
SET @MOTHER   := 36101;
SET @ACTIVE   := 66;
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Felwood Ore Mother pool');
