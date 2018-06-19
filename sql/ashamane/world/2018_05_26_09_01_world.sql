UPDATE quest_template SET allowableRaces = 0 WHERE allowableRaces <= -1;
ALTER TABLE `quest_template` CHANGE `AllowableRaces` `AllowableRaces` BIGINT(20) UNSIGNED DEFAULT 0 NOT NULL; 
UPDATE quest_template SET `AllowableRaces`=18446744073709551615 WHERE allowableRaces = 0;
UPDATE quest_template SET allowableRaces = 0 WHERE ID IN (13914, 13915, 13916, 13917);
