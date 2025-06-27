-- 'Clues in the Thicket' (Quest ID 9971) RewardText typo (Is it was/Is it what)
UPDATE `quest_offer_reward`
 SET `RewardText`="So, I was right.  That was the corpse of one of the Broken?  And you can confirm that there was a strange object on the ground next to him?$B$BThis doesn't make any sense.  What would one of the Broken be doing here?  And what is that thing it had with him?$B$BIs it what caused all of this death?"
 WHERE `ID`=9971;
-- `An Unseen Hand` (Quest ID 10013) RewardText typo (2x "it to me")
UPDATE `quest_offer_reward`
 SET `RewardText`="<Rokag takes the plans from you and looks them over.>$B$BSo Kaide was right! Those fel orc scum are up to something. I never would've guessed they were colluding with the blood elves, though.$B$BAccording to this map, the fel orcs are to keep us busy... but why? This is disturbing news, $N. You were correct in bringing it to me right away."
 WHERE `ID` = 10013;
-- 'Evil Draws Near' (Quest ID 10923) Progress typo (ben/been)
UPDATE `quest_request_items`
 SET `CompletionText` = "Has Teribus the Cursed been purged from the skies of Terokkar?"
 WHERE `ID` = 10923;
