-- A Boaring Time for Grulloc (quest ID 10721): use RewardText instead of QuestDescription
UPDATE `quest_offer_reward`
 SET `RewardText`="<Baron Sablemane peers inside the gronn's sack and seems satisfied.>$B$BVery well, you have upheld your end of the bargain. With that price paid, I will give Rexxar what he seeks."
 WHERE `Id`=10721;
