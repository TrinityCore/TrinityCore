-- Fix typo in Reward text of quest 'Dangerous!' (567)
UPDATE `quest_offer_reward` SET `RewardText`= "You are quite the bounty hunter, $C. Well done." WHERE `ID`= 567;
