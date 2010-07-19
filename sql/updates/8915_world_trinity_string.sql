-- UPDATE so we don't kill customized locale strings if user has any
UPDATE `trinity_string` SET `content_default`='The old password is wrong' WHERE `entry`=27;
-- INSERT as this string has not been used before
INSERT INTO `trinity_string` VALUES (62, 'One on more parameters have incorrect values', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
