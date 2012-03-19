-- UPDATE so we don't kill customized locale strings if user has any
UPDATE `trinity_string` SET `content_default`='The old password is wrong' WHERE `entry`=27;
-- INSERT as this string has not been used before
DELETE FROM `trinity_string` WHERE `entry`=62;
INSERT INTO `trinity_string` (`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`) VALUES (62, 'One on more parameters have incorrect values', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
