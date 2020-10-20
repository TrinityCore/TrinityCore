-- Surveying the Ruins (quest ID 10335): add missing last half of RewardText
UPDATE `quest_offer_reward`
 SET `RewardText`="You're not just pulling my bandage, right? That's most excellent news!$B$BNow that you've done the surveying grunt-work, I'll be able to take my team up to the ruins and see what's there to be procured.$B$BYou have my thanks, $c."
 WHERE `Id`=10335;
