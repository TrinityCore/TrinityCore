-- fix string in Kitron_string incorrectly implying character customization is forced at login
UPDATE `Kitron_string` SET `content_default`='customization for player %s will be requested at next login.' WHERE `entry`=345;
UPDATE `Kitron_string` SET `content_default`='customization for player %s (GUID #%u) will be requested at next login.' WHERE `entry`=346;

UPDATE `Kitron_string` SET `content_default`='You already have a pet.' WHERE `entry`=344; -- add missing article
