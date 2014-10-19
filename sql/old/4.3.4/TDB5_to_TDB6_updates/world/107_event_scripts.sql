DELETE FROM `event_scripts` WHERE `command` = 9 AND `datalong` NOT IN (SELECT `guid` FROM `gameobject`);
