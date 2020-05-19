ALTER TABLE `guild` 
ADD COLUMN `completedDungeonChallenges` int(10) unsigned DEFAULT '0' AFTER `todayExperience`,
ADD COLUMN `completedRaidChallenges` int(10) unsigned DEFAULT '0' AFTER `completedDungeonChallenges`,
ADD COLUMN `completedRatedBattlegroundChallenges` int(10) unsigned DEFAULT '0' AFTER `completedRaidChallenges`;
