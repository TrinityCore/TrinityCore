-- Fix completion texts for both version of the Trial of the Sea Lion quest.
SET @TEXT="You've completed the Trial of the Sea Lion, $N - congratulations.$B$BEach task in acquiring the pendant shows that both agility and endurance are necessary to act in harmony with what you desire to do underwater. Neither can exist without the other, and both cannot be done without your willingness to embrace the aspect of the sea lion.$B$BRemember these lessons well, and count on them once you have gained your aquatic form.";
UPDATE `quest_offer_reward` SET `RewardText`=@TEXT WHERE `ID` IN (30,272);
