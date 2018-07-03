ALTER TABLE `creature_template_scaling`
 CHANGE `LevelScalingDelta` `LevelScalingDeltaMin` smallint(5) NOT NULL DEFAULT '0' AFTER `LevelScalingMax`,
 ADD `LevelScalingDeltaMax` smallint(5) NOT NULL DEFAULT '0' AFTER `LevelScalingDeltaMin`;

UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=`LevelScalingDeltaMin`;
