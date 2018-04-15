ALTER TABLE `creature_template_scaling`
 CHANGE `LevelScalingDelta` `LevelScalingDeltaMin` smallint(5) NOT NULL DEFAULT '0' AFTER `LevelScalingMax`,
 ADD `LevelScalingMin` smallint(5) NOT NULL DEFAULT '0' AFTER `Entry`,
 ADD `LevelScalingMax` smallint(5) NOT NULL DEFAULT '0' AFTER `LevelScalingMin`,
 ADD `LevelScalingDeltaMax` smallint(5) NOT NULL DEFAULT '0' AFTER `LevelScalingDeltaMin`;

UPDATE creature_template AS ct, creature_template_scaling AS cts SET cts.LevelScalingMin = ct.minlevel, cts.LevelScalingMax = ct.maxLevel WHERE cts.Entry = ct.entry;
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=`LevelScalingDeltaMin`;
