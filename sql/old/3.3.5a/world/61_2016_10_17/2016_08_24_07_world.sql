-- move sons of hodir reputation changes to reputation_reward_rate table
-- also add multipliers to Argent Crusade, Alliance Vanguard, Horde Expedition, Kirin Tor, Knights of the Ebon Blade and Wyrmrest Accord as per 3.3.0 retail patch notes
UPDATE `quest_template` SET `RewardFactionOverride1`=0 WHERE `RewardFactionID1`=1119;
UPDATE `quest_template` SET `RewardFactionOverride1`=2200000 WHERE `id` IN (12915,12924);
INSERT INTO `reputation_reward_rate` (`faction`) VALUES (1106),(1037),(1052),(1091),(1090),(1098) ON DUPLICATE KEY UPDATE `faction`=`faction`;
UPDATE `reputation_reward_rate` SET `quest_rate`=1.3,`quest_daily_rate`=1.3,`quest_weekly_rate`=1.3,`quest_monthly_rate`=1.3,`quest_repeatable_rate`=1.3 WHERE `faction` IN (1106,1037,1052,1091,1090,1098);
