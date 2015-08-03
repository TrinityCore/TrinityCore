-- Delete uneed made up GO template
UPDATE `gameobject` SET `id`=202275 WHERE `id`=300149; -- TEMP Wrathscale Lair Fountain -> Wrathscale Fountain
DELETE FROM `gameobject_template` WHERE `entry`=300149;
