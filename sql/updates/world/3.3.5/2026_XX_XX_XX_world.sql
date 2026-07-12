-- Replace LANG_ACCOUNT_NAME_TOO_LONG
DELETE FROM `trinity_string` WHERE `entry`=1005;
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`) VALUES
(1005, "Your account name can't be longer than 17 characters (client limit), account wasn't created!", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
