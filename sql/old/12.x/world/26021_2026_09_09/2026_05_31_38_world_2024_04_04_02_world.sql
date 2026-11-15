-- Sting of the Scorpid (Wrong use of "$c")
UPDATE `quest_request_items` SET `CompletionText`="The carapace of a scorpid isn't so thick that the strength of a determined warrior will be deterred. Strike strongly and without doubt, and the scorpids should prove easy prey." WHERE `ID`=789;

-- A Peon's Burden (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Ah, this is the food Ukor brought to the Valley of Trials.  Did they not need it? Well, I guess they like to starve you heroes in training.  Builds spirit, they say!$b$bThank you for returning the food.  I'll stick it back on the shelves... but here, let me offer you some refreshment first!$b$bAnd don't forget to rest here in the inn. You may be a brave $c ready to take on the world, but if your energy is sapped you won't be doing yourself, or the Horde, much good." WHERE `ID`=2161;

-- Vanquish the Betrayers (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Word of your bravery travels fast, $c. Tales of your victory at Tiragarde Keep will be heralded in Orgrimmar." WHERE `ID`=784;

-- The Admiral's Orders (Upper case "$c") 
UPDATE `quest_request_items` SET `CompletionText`="There is a look of concern on your face, $c. What have you there?" WHERE `ID`=830;

-- Carry Your Weight (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Most excellent, $N. Any good $c will surely find a use for this bag on the battlefield.$b$bI salute your vigor and willingness to die in the name of the Horde!" WHERE `ID`=791;

-- From The Wreckage.... (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Your recovery mission was a success, $c. I will see to it that these tools get to Orgrimmar with the next caravan.$b$bNicely done." WHERE `ID`=825;

-- Margoz (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Welcome, $N.  Word reached me of your coming, and of your exploits in Durotar.$b$bYou are a $c of growing skill and renown.$b$bStay on the pure path, and your future will be great indeed." WHERE `ID`=828;

-- Hidden Enemies (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="What is it?! Oh, you, $c... my apologies. My anger rivals that of a rabid kodo bull... but perhaps it is my own fault. In sending travelers into Ragefire Chasm, I should have seen the possibility that some harm would come from it. It seems both Bazzalan and Jergosh were taken unaware and slain by some of Thrall's do-gooders. A most inopportune time, but there is nothing that can be done about it now." WHERE `ID`=5729;

-- Neeru Fireblade (Upper case "$c" and upper case "$r") 
UPDATE `quest_request_items` SET `CompletionText`="My most humble greetings, $c.  How might I help my $r $gbrother:sister; today?" WHERE `ID`=829;

-- The Admiral's Orders (Upper case "$c") 
UPDATE `quest_offer_reward` SET `RewardText`="Countless times I urged the Warchief not to trust the humans, but personal pride is not what is at stake here.$b$bYou have served the Horde honorably, young $c.$b$bNow excuse me, I must counsel Thrall on these matters at once...." WHERE `ID`=831;
