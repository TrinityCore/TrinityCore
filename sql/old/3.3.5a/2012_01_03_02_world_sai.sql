-- Add text for Lynn Hyal
DELETE FROM `creature_text` WHERE `entry`=23768;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(23768, 1, 0, 'James? James... No, you\'re not James, but I know who you are...', 12, 0, 100, 0, 0, 0, 'Lynn Hyal'),
(23768, 2, 0, 'You\'re the one who tracked down the brutes who did this to us.', 12, 0, 100, 0, 0, 0, 'Lynn Hyal'),
(23768, 3, 0, 'I tried so hard to tell Jim... to tell anyone... who was behind this, but I couldn\'t find a way...', 12, 0, 100, 0, 0, 0, 'Lynn Hyal'),
(23768, 4, 0, 'Thank you for helping us and for helping Jim. If you see him, tell him little Jimmy and I love him and that we\'re waiting for him.', 12, 0, 100, 0, 0, 0, 'Lynn Hyal'),
(23768, 5, 0, 'I don\'t know when we\'ll see Daddy again, Jimmy, but I know he loves you and he misses you very much.', 12, 0, 100, 0, 0, 0, 'Lynn Hyal');
-- Add text for Jimmy Hyal
DELETE FROM `creature_text` WHERE `entry`=23769;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(23769, 1, 0, 'Mommy, when will we see Daddy again?', 12, 0, 100, 0, 0, 0, 'Jimmy Hyal');
-- add smart ai dialog for Lynn Hyal and quest credit at end of dialog
UPDATE `creature_template` SET AIName="SmartAI" WHERE `entry`=23768;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23768;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23768, 0, 0, 0, 1, 0, 100, 1, 0, 0, 0, 0, 84, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - on spawn - talk 1'),
(23768, 0, 1, 0, 1, 0, 100, 1, 2000, 2000, 0, 0, 84, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - after 2 sec - talk 2'),
(23768, 0, 2, 0, 1, 0, 100, 1, 5000, 5000, 0, 0, 84, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - after 5 sec - talk 3'),
(23768, 0, 3, 0, 1, 0, 100, 1, 8000, 8000, 0, 0, 84, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - after 8 sec - talk 4'),
(23768, 0, 4, 0, 1, 0, 100, 1, 12000, 12000, 0, 0, 84, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - after 12 sec - reply to jimmy'),
(23768, 0, 5, 0, 1, 0, 100, 1, 12000, 12000, 0, 0, 33, 23768, 0, 0, 0, 0, 0, 18, 5, 0, 0, 0, 0, 0, 0, 'Lynn Hyal - after 12 sec - kill credit quest complete');
-- add smart ai dialog for Jimmy Hyal
UPDATE `creature_template` SET AIName="SmartAI" WHERE `entry`=23769;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23769;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23769, 0, 0, 0, 1, 0, 100, 1, 10000, 10000, 0, 0, 84, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jimmy Hyal - after 10 sec - talk 1');
