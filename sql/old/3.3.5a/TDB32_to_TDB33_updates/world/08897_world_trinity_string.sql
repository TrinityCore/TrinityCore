-- UPDATE so we don't kill customized locale strings if user has any
UPDATE `trinity_string` SET `content_default`='Item ''%u'' (with extended cost %u) already in vendor list.' WHERE `entry`=210;
