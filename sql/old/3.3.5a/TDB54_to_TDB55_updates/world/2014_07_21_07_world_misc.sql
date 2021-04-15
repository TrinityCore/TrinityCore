DELETE FROM `smart_scripts` WHERE `entryorguid`=5697 AND `source_type`=0 AND `id` IN(14,15);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(5697, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Reached WP18 - Kneel'),
(5697, 0, 15, 0, 61, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Theresa - On Text Over - Stand');

UPDATE `smart_scripts` SET `link`=14 WHERE  `entryorguid`=5697 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `link`=15 WHERE  `entryorguid`=5697 AND `source_type`=0 AND `id`=10;

UPDATE `smart_scripts` SET `event_param3`=300000, `event_param4`=450000 WHERE  `entryorguid`=5696 AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `entry`=5700 AND `id`=16;
DELETE FROM `creature_text` WHERE `entry`=5696 AND `groupid`=2 AND `id`=4;
DELETE FROM `creature_text` WHERE `entry`=5698 AND `groupid`=0 AND `id` IN(6,7);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(5700, 0, 16, 'Back to the drawing board.', 12, 33, 100, 1, 0, 0, 'Samantha Shackleton', 2044),
(5696, 2, 4, 'Isn''t she just the most amazing little creation?', 12, 33, 100, 1, 0, 0, 'Gerard Abernathy', 2001),
(5698, 0, 6, 'Very nice, Gerard. Next you will be breeding them.', 12, 33, 100, 1, 0, 0, 'Joanna Whitehall', 2022),
(5698, 0, 7, 'Your pet is wonderful, Gerard, but she needs a collar with a bell I think.', 12, 33, 100, 1, 0, 0, 'Joanna Whitehall', 2026);

UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=23967 AND `source_type`=0 AND `id`=0 AND `link`=1;
