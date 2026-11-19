DELETE FROM `smart_scripts` WHERE `entryorguid`=19995 AND `source_type`=0 AND `id`IN(3,4,5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(1999500,1999501) AND `source_type`=9;

UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry` IN(21241);
DELETE FROM `smart_scripts` WHERE `entryorguid`=21241 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(19995, 0, 4, 5, 75, 1, 100, 0, 0, 21241, 5, 5000, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - On Creature Range - Set Phase 2'),
(19995, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 1999500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - On Creature Range - Run Script'),
(19995, 0, 6, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 1999501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - On Data Set 1 1 - Run Script 2'),
(21241, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Bloodmaul Brutebane Stout Trigger - On Just Summoned - Store Targetlist'),
(21241, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 19, 19995, 0, 0, 0, 0, 0, 0, 'Bloodmaul Brutebane Stout Trigger - On Just Summoned - Send Target List to Bladespire Brute'),
(21241, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 19995, 0, 0, 0, 0, 0, 0, 'Bloodmaul Brutebane Stout Trigger - On Just Summoned - Set Data to Bladespire Brute'),
(1999500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 21241, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Despawn Trigger'),
(1999500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotKneel (16)'),
(1999500, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 70, 300, 0, 0, 0, 0, 0, 20, 184315, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Despawn GO'),
(1999500, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2703, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Update Virtual Item Slot ID 1'),
(1999500, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Say Line 4'),
(1999500, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 10, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 12, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 13, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 92, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Play Emote OneShotEatNoSheathe'),
(1999500, 9, 14, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 35240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Cast Bloodmaul Intoxication'),
(1999500, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 14874, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Update Virtual Item Slot ID 1'),
(1999500, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Set Emote State 93'),
(1999500, 9, 17, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 21241, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Kill Credit'),
(1999500, 9, 18, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Say Line 5'),
(1999500, 9, 19, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Set Emote State 93'),
(1999500, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Set Phase 1'),
(1999500, 9, 21, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Set Aggresive'),
(1999500, 9, 22, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script - Evade'),
(1999501, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script 2 - Set Defensive'),
(1999501, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script 2 - Set Set Phase 1'),
(1999501, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 19, 21241, 0, 0, 0, 0, 0, 0, 'Bladespire Brute - Script 2 - Move to Position');

DELETE FROM `creature_text` WHERE `entry`=19995 AND `groupid` IN(4,5);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(19995, 4, 0, 'Ohh, look! Bloodmaul Brew! Mmmm...', 12, 0, 100, 16, 0, 0, 18170, 'Bladespire Brute to 21241'),
(19995, 4, 1, 'Bloodmaul Brew? Me favorite!', 12, 0, 100, 16, 0, 0, 18171, 'Bladespire Brute to 21241'),
(19995, 4, 2, 'Ohh, look! Bloodmaul Brew! Mmmm...', 12, 0, 100, 16, 0, 398, 18170, 'Bladespire Brute to 21241'),
(19995, 4, 3, 'Mmmm, Bloodmaul Brew!', 12, 0, 100, 16, 0, 0, 17844, 'Bladespire Brute to 21241'),
(19995, 5, 0, 'Ugh... Me not feel so guud.', 12, 0, 100, 92, 0, 0, 18197, 'Bladespire Brute to 21241');
