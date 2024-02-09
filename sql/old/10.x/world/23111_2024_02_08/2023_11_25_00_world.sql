
-- remove 'sundered_mob' string id
UPDATE `creature_template` SET `StringId`=NULL WHERE `entry` IN(198874, 205735, 205734, 205737, 198872, 205736, 198871, 198873, 198869);

UPDATE `creature` SET `StringId`='kazzara_intro_trash' WHERE `guid` IN(9003990, 9003965, 9003968, 9003983, 9003992, 9003985, 9003993, 9003986);
