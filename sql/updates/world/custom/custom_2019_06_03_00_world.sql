ALTER TABLE `lfg_dungeon_rewards`   
  ADD COLUMN `shortageQuestId` INT(10) UNSIGNED DEFAULT 0 NULL COMMENT 'Quest ID with rewards for joining a random dungeon queue while the role is short on supply' AFTER `otherQuestId`;

UPDATE `lfg_dungeon_rewards` SET `shortageQuestId`= 29339 WHERE `dungeonId` IN (434, 301);
