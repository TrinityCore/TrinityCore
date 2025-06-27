-- Death From Below: Replace "troll" with $r at the end of the text (Even if you are a puny troll....)
-- Note: Quest ID 667 got replaced with ID 26628 (with identical name) in patch 4.0.3 (13277)
UPDATE `quest_offer_reward` SET `RewardText`= "We survived the attack!$b$bWe could not have done it without you, $N.$b$bWe'll be heading out as soon as the tide rises. If you weren't such a promising hero I'd offer you a place on my crew. But I can tell you have bigger fish to fry.$b$bEven if you are a puny $r...." WHERE `ID`=667;
