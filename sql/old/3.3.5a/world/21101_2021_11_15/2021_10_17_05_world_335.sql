--
UPDATE `gameobject` SET `position_x` = -8337.72, `position_y` = 519.845, `position_z` = 122.939, `orientation` = -1.12724, `rotation0` = -0.667572, `rotation1` = -0.233126, `rotation2` = -0.667571, `rotation3` = 0.23313 WHERE `guid` = 20458 AND `id` = 177200;
UPDATE `gameobject` SET `position_x` = -8338.47, `position_y` = 509.136, `position_z` = 122.931, `orientation` = 0, `rotation0` = -0.307199, `rotation1` = -0.636889, `rotation2` = -0.307199, `rotation3` = 0.636891 WHERE `guid` = 31619 AND `id` = 177201;
UPDATE `gameobject` SET `position_x` = -8347.64, `position_y` = 520.972, `position_z` = 122.939, `orientation` = 0, `rotation0` = -0.307199, `rotation1` = -0.636889, `rotation2` = -0.307199, `rotation3` = 0.636891 WHERE `guid` = 20459 AND `id` = 177202;
UPDATE `gameobject_addon` SET `parent_rotation2` = 0.944089, `parent_rotation3` = -0.329691 WHERE `guid` IN (20458,31619,20459);

DELETE FROM `game_event_gameobject` WHERE `guid` = 31619;
