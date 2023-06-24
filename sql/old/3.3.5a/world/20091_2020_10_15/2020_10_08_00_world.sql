-- 
DELETE FROM `Kitron_string` WHERE `entry`=196;
INSERT INTO `Kitron_string` (`entry`,`content_default`) VALUES
(196, 'There is no detailed usage information associated with \'%.*s\'.
This should never occur for stock KitronCore commands - if it does, report this as a bug.
If this is a custom command, use `Kitron_string` to specify it. Look at cs_achievement.cpp for example usage.');
