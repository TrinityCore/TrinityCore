UPDATE `quest_template` SET `PrevQuestId`=`HaveQuestId` * '-1' WHERE `HaveQuestId`!='0' AND `PrevQuestId`='0';
ALTER TABLE `quest_template` DROP `HaveQuestId`;

ALTER TABLE `quest_template` ADD COLUMN `NextQuestInChain` int(11) unsigned NOT NULL default '0' AFTER `ExclusiveGroup`;
UPDATE `quest_template` SET `NextQuestInChain`=`NextQuestId` WHERE `NextQuestId`>'0';