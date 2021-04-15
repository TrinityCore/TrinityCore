ALTER TABLE `quest_template`
  CHANGE `RewardDisplaySpell` `RewardDisplaySpell1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardBonusMoney`,
  ADD `RewardDisplaySpell2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardDisplaySpell1`,
  ADD `RewardDisplaySpell3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardDisplaySpell2`,
  ADD `RewardArtifactXPDifficulty` int(10) unsigned NOT NULL DEFAULT '0' AFTER `StartItem`,
  ADD `RewardArtifactXPMultiplier` float NOT NULL DEFAULT '1' AFTER `RewardArtifactXPDifficulty`,
  ADD `RewardArtifactCategoryID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardArtifactXPMultiplier`,
  DROP `RewardTalents`,
  ADD `RewardFactionCapIn1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardFactionOverride1`,
  ADD `RewardFactionCapIn2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardFactionOverride2`,
  ADD `RewardFactionCapIn3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardFactionOverride3`,
  ADD `RewardFactionCapIn4` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardFactionOverride4`,
  ADD `RewardFactionCapIn5` int(10) unsigned NOT NULL DEFAULT '0' AFTER `RewardFactionOverride5`,
  ADD `QuestRewardID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `AllowableRaces`;
