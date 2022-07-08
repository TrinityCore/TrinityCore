ALTER TABLE `quest_template`
CHANGE COLUMN `RewardFactionCapIn1` `RewardFactionCapIn1` INT(10) NOT NULL DEFAULT '0' AFTER `RewardFactionOverride1`,
CHANGE COLUMN `RewardFactionCapIn2` `RewardFactionCapIn2` INT(10) NOT NULL DEFAULT '0' AFTER `RewardFactionOverride2`,
CHANGE COLUMN `RewardFactionCapIn3` `RewardFactionCapIn3` INT(10) NOT NULL DEFAULT '0' AFTER `RewardFactionOverride3`,
CHANGE COLUMN `RewardFactionCapIn4` `RewardFactionCapIn4` INT(10) NOT NULL DEFAULT '0' AFTER `RewardFactionOverride4`,
CHANGE COLUMN `RewardFactionCapIn5` `RewardFactionCapIn5` INT(10) NOT NULL DEFAULT '0' AFTER `RewardFactionOverride5`;
