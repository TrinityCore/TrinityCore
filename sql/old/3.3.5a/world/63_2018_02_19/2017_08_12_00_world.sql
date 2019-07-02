-- A Haunted History (10624): add missing bits of Progress text & Reward text
UPDATE `quest_request_items`
 SET `CompletionText`="What do you mean? I'm going to make something out of the ash - obviously."
 WHERE `ID` = 10624;

UPDATE `quest_offer_reward`
 SET `RewardText`="Your world is about to change, $N.$B$B<Hildagard begins crafting something out of the ash.>"
 WHERE `ID` = 10624;
