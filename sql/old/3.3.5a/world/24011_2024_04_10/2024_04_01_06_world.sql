-- The Hunt Begins (Wrong use of "$c")
UPDATE `quest_request_items` SET `CompletionText`="Providing meat and feathers for the tribe is the first step in proving yourself as a hunter before the Chief." WHERE `ID`=747;

-- Break Sharptusk! (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Justice has been served on this day by your swift actions, $N.  Let this deed serve as a warning to all who would threaten our home.$b$bYou have earned this reward to help you on your sojourn, young $c." WHERE `ID`=3376;

-- The Hunt Begins (Wrong use of "$r")
UPDATE `quest_offer_reward` SET `RewardText`="The tauren of Narache thank you, $N. You show much promise." WHERE `ID`=747;

-- The Hunt Continues (Wrong use of "$r")
UPDATE `quest_offer_reward` SET `RewardText`="The tauren of Narache thank you for these provisions, $N. With your skill in the ways of the hunt you will surely be revered in Thunder Bluff someday." WHERE `ID`=750;

-- Rites of the Earthmother (Upper case "$c")
UPDATE `quest_request_items` SET `CompletionText`="What brings you to my village, $c?" WHERE `ID`=763;

-- Swoop Hunting (Upper case "$c")
UPDATE `quest_offer_reward` SET `RewardText`="I know that gathering these quills was not an easy task, $N.  In doing this, you prove that you are a $c of merit.  It is good to have you at Bloodhoof Village." WHERE `ID`=761;

-- The Demon Scarred Cloak (Wrong use of "$c" and upper case "$c")
UPDATE `quest_offer_reward` SET `RewardText`="I can barely believe my old eyes!  You defeated the great wolf Ghost Howl?  I look upon you with new respect, young $c.  You are a hunter of extreme skills!$b$bLet me offer you something.  My days of hunting are over, but I would be honored if you used one of my weapons in your hunts.$b$bMay it strike true, and bring you renown.$b$bAnd let us hope that Ghost Howl's spirit has finally found peace." WHERE `ID`=770;

-- The Hunter's Way (Wrong use of "$c")
UPDATE `quest_offer_reward` SET `RewardText`="Skorn Whitecloud is a wise tauren.  He has hunted for years and years, and although his body is old, his spirit burns fiercely.  We are honored to have him with us.$b$bIf Skorn sent you to me, then you too must have the hunter's spirit.  And to have gathered these claws shows your burgeoning skills.$b$bPerhaps you are ready to walk the path." WHERE `ID`=861;

-- Journey into Thunder Bluff (Upper case "$c")
UPDATE `quest_offer_reward` SET `RewardText`="Hail, young $c. I see you found your way to my doorstep." WHERE `ID`=775;

-- The Barrens Oases (Upper case "$c")
UPDATE `quest_offer_reward` SET `RewardText`="My brethren in Thunder Bluff were wise to send you, young $c.  For the mystery of the Barrens is one that I alone cannot unravel.$B$BWith your aid, let us hope we can find answers to our questions." WHERE `ID`=886;
