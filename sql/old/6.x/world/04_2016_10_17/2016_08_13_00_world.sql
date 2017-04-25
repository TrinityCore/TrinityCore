ALTER TABLE `creature_template`
  CHANGE `exp_unk` `RequiredExpansion` MEDIUMINT(5) DEFAULT 0 NOT NULL,
  ADD COLUMN `HealthScalingExpansion` MEDIUMINT(5) DEFAULT 0 NOT NULL AFTER `exp`,
  ADD COLUMN `VignetteID` MEDIUMINT(5) DEFAULT 0 NOT NULL AFTER `RequiredExpansion`; 
