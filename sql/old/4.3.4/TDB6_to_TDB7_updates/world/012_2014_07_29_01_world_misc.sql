UPDATE `creature_template` SET `AIName`= 'SmartAI',`ScriptName`='' WHERE `entry` IN(28347,7978);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(28347,28355,7978) and `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2834700 AND 2834703 and `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7978, 0, 0, 0, 1, 0, 100, 0, 0, 30000, 15000, 45000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bimble Longberry - OOC  - Say'),
(28347, 0, 0, 0, 1, 0, 100, 0, 0, 30000, 60000, 90000, 87, 2834700, 2834701, 2834702, 2834703, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - OOC  - Run Random Script'),
(28347, 0, 1, 0, 10, 0, 100, 0, 1, 20, 30000, 60000, 1, 5, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - OOC LOS - Say Line 5'),

(2834700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 1  - Say Line 0'),
(2834700, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 28355, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 1  - Say Line 2 (Wright Williams)'),
(2834700, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 1  - Say Line 4'),
(2834701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 28355, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 2  - Say Line 0 (Wright Williams)'),
(2834701, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 2  - Say Line 1'),
(2834702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 28355, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 3  - Say Line 1 (Wright Williams)'),
(2834702, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 3  - Say Line 2'),
(2834703, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 28355, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 4  - Say Line 3 (Wright Williams)'),
(2834703, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Miles Sidney - Script 4  - Say Line 3');

DELETE FROM `creature_text` WHERE `entry` IN(7978,28347,28355);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(7978, 0, 1, 'Straight from the lush forests of Elwynn, get your fresh fruit right here.', 12, 7, 100, 0, 0, 0, 'Bimble Longberry', 4021),
(7978, 0, 2, 'Juicy fruits for sale!', 12, 7, 100, 0, 0, 0, 'Bimble Longberry', 4019),
(7978, 0, 3, 'Sink your teeth into a fresh, ripe apple.', 12, 7, 100, 0, 0, 0, 'Bimble Longberry', 4020),
(28355, 0, 0, 'Sir, our customers are complaining that there''s not enough Maiden''s Anguish in our Deadly Poisons.', 12, 0, 100, 0, 0, 0, 'Wright Williams', 27801),
(28355, 1, 0, 'Sir, I think we were close with the Lethargy Root in that last poison recipe.', 12, 0, 100, 0, 0, 0, 'Wright Williams', 27803),
(28355, 2, 0, 'I''m working on it, I just don''t want to sell it until I''m happy with it. It shouldn''t be long.', 12, 0, 100, 0, 0, 0, 'Wright Williams', 27808),
(28355, 3, 0, 'Sir, our customers are complaining that there''s too much Deathweed in our Anesthetics.', 12, 0, 100, 0, 0, 0, 'Wright Williams', 27802),
(28347, 0, 0, 'Wright, have you finished that new concoction you''ve been working on? I''m tired of these spores filling up my shop!', 12, 0, 100, 0, 0, 0, 'Miles Sidney', 27804),
(28347, 1, 0, 'Then put twice as much in next time!', 12, 0, 100, 0, 0, 0, 'Miles Sidney', 27805),
(28347, 2, 0, 'Remember, kid: You''re always more wrong than you think you are. Double It!', 12, 0, 100, 0, 0, 0, 'Miles Sidney', 27807),
(28347, 3, 0, 'Only put half as much in next time.', 12, 0, 100, 0, 0, 0, 'Miles Sidney', 27806),
(28347, 4, 0, 'That''s what you always say. Sometimes I think you''re never going to finish that thing.', 12, 0, 100, 0, 0, 0, 'Miles Sidney', 27810),
(28347, 5, 0, 'Greetings.', 12, 7, 100, 3, 0, 0, 'Miles Sidney', 43337),
(28347, 5, 1, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 'Miles Sidney', 43330),
(28347, 5, 2, 'Greetings! Please have a look around.', 12, 7, 100, 3, 0, 0, 'Miles Sidney',43333),
(28347, 5, 3, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 'Miles Sidney', 43335),
(28347, 5, 4, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 'Miles Sidney', 43336);
