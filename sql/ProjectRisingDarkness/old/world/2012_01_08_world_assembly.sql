DELETE FROM `achievement_criteria_data` WHERE `ScriptName`='achievement_cant_do_that_while_stunned';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10090,11,0,0,'achievement_cant_do_that_while_stunned'),
(10422,11,0,0,'achievement_cant_do_that_while_stunned'),
(10423,11,0,0,'achievement_cant_do_that_while_stunned'),
(10091,11,0,0,'achievement_cant_do_that_while_stunned'),
(10424,11,0,0,'achievement_cant_do_that_while_stunned'),
(10425,11,0,0,'achievement_cant_do_that_while_stunned');

DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (10090,10422,10423,10091,10424,10425);