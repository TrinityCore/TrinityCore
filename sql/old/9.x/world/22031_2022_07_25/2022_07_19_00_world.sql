-- 
ALTER TABLE `quest_offer_reward` MODIFY COLUMN `Emote1` smallint NOT NULL DEFAULT 0 AFTER `ID`;
ALTER TABLE `quest_offer_reward` MODIFY COLUMN `Emote2` smallint NOT NULL DEFAULT 0 AFTER `Emote1`;
ALTER TABLE `quest_offer_reward` MODIFY COLUMN `Emote3` smallint NOT NULL DEFAULT 0 AFTER `Emote2`;
ALTER TABLE `quest_offer_reward` MODIFY COLUMN `Emote4` smallint NOT NULL DEFAULT 0 AFTER `Emote3`;
