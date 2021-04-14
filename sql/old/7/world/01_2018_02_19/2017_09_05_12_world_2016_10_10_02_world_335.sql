--
-- UPDATE `quest_template` SET `AllowableRaces`=8 WHERE `ID` IN (6344, 6341, 6342, 6343);

UPDATE `quest_offer_reward` SET `RewardText`="I bid you greetings, $N. Your name rings loudly in Darnassus, for you show promise. But we shall soon see if you possess the strength of will to follow the path of the $C." WHERE `ID`=1684;

UPDATE `creature_template` SET `faction`=189 WHERE `entry`=1986;

UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid`=16819 AND `id`=1;

UPDATE `smart_scripts` SET `event_param2`=30000, `event_param4`=30000 WHERE `entryorguid`=2030 AND `id`=2;
UPDATE `smart_scripts` SET `event_param2`=30000, `event_param4`=30000 WHERE `entryorguid`=2009 AND `id`=0;
