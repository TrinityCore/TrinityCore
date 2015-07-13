ALTER TABLE `quest_template` CHANGE `Float13` `RewardMoneyMultiplier` FLOAT NOT NULL DEFAULT '1';

UPDATE `quest_template` SET `RewardMoney`=0 WHERE `RewardMoney`>0; -- non-static data
