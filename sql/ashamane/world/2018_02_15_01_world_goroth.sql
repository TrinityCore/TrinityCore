UPDATE creature_template SET mechanic_immune_mask = 2147483647 WHERE entry = 115844;
UPDATE creature_template SET flags_extra = 128 WHERE entry IN (117931, 116976);

DELETE FROM spell_script_names WHERE scriptname = "spell_shattering_star_dummy";
INSERT INTO spell_script_names VALUES
(233274, "spell_shattering_star_dummy");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1 AND `SourceEntry` = 233274;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 233274, 31, 3, 115844, 'Goroth - Shattering star');
