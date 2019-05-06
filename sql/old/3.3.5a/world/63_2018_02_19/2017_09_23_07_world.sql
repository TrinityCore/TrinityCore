-- Out of combat texts for NPCs Elisara Sunstriker and Lord Saltheril
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16147;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (16147) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1614700) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16147, 0, 0, 0, 1, 0, 100, 0, 16000, 20000, 290000, 310000, 80, 1614700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Elisara Sunstriker - Out Of Combat - Call Actionlist"),
(1614700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Elisara Sunstriker - On Script - Say Line 0"),
(1614700, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 16144, 0, 0, 0, 0, 0, 0, "Elisara Sunstriker - On Script - Say Line 0 (Lord Saltheril)");
DELETE FROM `creature_text` WHERE `CreatureID` IN (16147, 16144);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(16147, 0, 0, "I was just thinking... we really ought to take a trip south one of these nights, maybe have an evening picnic overlooking the fighting at the border? What do you think, milord? Wouldn't that just be so exciting?", 12, 1, 100, 6, 0, 0, 12070, 0, "Elisara Sunstriker"),
(16147, 0, 1, "Milord, with much of the sin'dorei nobility regrettably crushed, does that mean that you are likely to receive an elevation soon?  I'm so excited for you!", 12, 1, 100, 6, 0, 0, 12071, 0, "Elisara Sunstriker"),
(16147, 0, 2, "Milord, do you think that we can join the party soon? I'm so bored in here.", 12, 1, 100, 6, 0, 0, 11992, 0, "Elisara Sunstriker"),
(16147, 0, 3, "Oh, my lordship, I do so hope that you've arranged for more of that excellent wine from Silvermoon City. I dare say drinking it makes me feel almost as forward as a common woman!", 12, 1, 100, 1, 0, 0, 11993, 0, "Elisara Sunstriker"),
(16147, 0, 4, "I'm so tired. We really shouldn't have stayed up so late last night... well this morning. But it was fun! You do throw the best soirees milord.", 12, 1, 100, 1, 0, 0, 0, 0, "Elisara Sunstriker"),
(16147, 0, 5, "Lord Saltheril, my dear, did you notice that supplies for the party are a little low? We really should send for one of those couriers from Fairbreeze Village to deliver more of whatever is needed. I especially like those little hors d'oeuvres wrapped in the smoked bacon. What are those called?", 12, 1, 100, 6, 0, 0, 11995, 0, "Elisara Sunstriker"),
(16147, 0, 6, "Salthy, do you think we're letting too many 'undesirables' into the party?  I do worry about what our friends might think of all of this.", 12, 1, 100, 6, 0, 0, 13355, 0, "Elisara Sunstriker"),
(16147, 0, 7, "You promised to take me out for a night on the town!  Are we just going to stand around here again tonight?", 12, 1, 100, 5, 0, 0, 13356, 0, "Elisara Sunstriker"),
(16144, 0, 0, "As you say, my dear, as you say.", 12, 1, 100, 1, 0, 0, 11996, 0, "Lord Saltheril"),
(16144, 0, 1, "Hmm, what was that? I'm sorry my dear, I must have been daydreaming.", 12, 1, 100, 6, 0, 0, 11997, 0, "Lord Saltheril"),
(16144, 0, 2, "Oh, most definitely, Elisara. But please, can you show the least bit of patience?", 12, 1, 100, 1, 0, 0, 11998, 0, "Lord Saltheril"),
(16144, 0, 3, "Is that so? How very interesting. My dear, why don't you run along and powder your nose? I have much to think about.", 12, 1, 100, 1, 0, 0, 11999, 0, "Lord Saltheril");
