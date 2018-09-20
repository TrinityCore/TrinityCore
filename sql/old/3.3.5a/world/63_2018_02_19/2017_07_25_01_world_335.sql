-- Correct gender selection DB format for brother/sister is $gbrother:sister;
UPDATE `quest_offer_reward`
 SET `RewardText` = 'Congratulations, $N - I am pleased to award you with an Argent Dawn valor token!
 
To acquire a valor token in such a manner indicates that you are a true hero in the cause of good. We value all effort brought to bear against the Scourge, but to take down one of their leaders is to truly deliver onto them a crushing defeat!
 
For the Dawn, my $gbrother:sister;!'

 WHERE `ID` IN (5404, 5406, 5508); -- Corruptor's Scourgestones (Argent Dawn repeatable quests)
