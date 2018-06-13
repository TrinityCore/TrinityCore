-- 
UPDATE `trinity_string` SET `content_default`="You can only summon a player to your instance if either that player or his group leader is in your instance, too." WHERE `entry`=103;
DELETE FROM `trinity_string` WHERE `entry`=187;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
  (187, "The group's leader is not in your instance - summoning only members that are already in your map.");
