-- update flag to fix crash from 9 to 2
UPDATE `scene_template` SET `flags` = 2 WHERE `sceneid` IN (1900, 1901, 1902, 1903);