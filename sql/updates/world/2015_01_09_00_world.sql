--
ALTER TABLE `quest_template` CHANGE `RewardHonorMultiplier` `RewardHonorMultiplier` FLOAT NOT NULL DEFAULT '0';
UPDATE `creature_template` SET `flags_extra`=0 WHERE `entry` IN (35144,35511,35512,35513);
