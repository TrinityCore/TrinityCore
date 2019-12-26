-- 
UPDATE `trinity_string` SET `content_default`='Failed to teleport you to the entrance to mapid %u (%s) - are you maybe not attuned to/missing an expansion for parent map %u?' WHERE `entry`=1197;
DELETE FROM `trinity_string` WHERE `entry`=1198;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES (1198, 'Failed to teleport you to the start of mapid %u (%s) - are you maybe not attuned to/missing an expansion for the instance?');
