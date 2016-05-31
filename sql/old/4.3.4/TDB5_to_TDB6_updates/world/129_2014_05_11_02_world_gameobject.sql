ALTER TABLE `points_of_interest` ADD `VerifiedBuild` SMALLINT(5) DEFAULT '0';
ALTER TABLE `spell_target_position` ADD `VerifiedBuild` SMALLINT(5) DEFAULT '0';

UPDATE `gameobject` SET `phasemask`=256 WHERE `guid`=76992;
