-- fix invalid rewardspells errors

UPDATE `quest_template` SET `RewardSpell` = 0 WHERE `RewardSpell` = 81040;