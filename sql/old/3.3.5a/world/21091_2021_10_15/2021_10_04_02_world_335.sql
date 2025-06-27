--
UPDATE `gameobject` a INNER JOIN `gameobject_addon` b ON a.`guid` = b.`guid` SET
`rotation0` = `parent_rotation0`,
`rotation1` = `parent_rotation1`,
`rotation2` = `parent_rotation2`,
`rotation3` = `parent_rotation3` WHERE a.`id` IN (19569,19570,19571);
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (19569,19570,19571));
