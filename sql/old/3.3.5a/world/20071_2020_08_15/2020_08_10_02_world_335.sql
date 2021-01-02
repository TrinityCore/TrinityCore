--
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (176369,176370));
DELETE FROM `gameobject` WHERE `id` IN (176369,176370);
