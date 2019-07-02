-- Sabotage the Warp-Gate! (quest ID 10310): add missing end half of RewardText
UPDATE `quest_offer_reward`
 SET `RewardText`="That is most excellent news, my friend!$B$BYou and Drijya have done us a great service.  With that warp-gate out of commission, the nearby demons will not be getting any further reinforcements.$B$BPlease allow me to reward you in the proper manner of the Consortium."
 WHERE `ID` = 10310;
