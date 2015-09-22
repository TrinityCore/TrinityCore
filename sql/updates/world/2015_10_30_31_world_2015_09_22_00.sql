DELETE FROM `creature_text` WHERE `entry` =23257 and `groupid`=0 and `id` in(7,8,9);
DELETE FROM `creature_text` WHERE `entry` =22982 and `groupid`=0 and `id` in(5,6);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 

(23257, 0, 7, 'Well one thing''s for sure, $n''s not a nugget any more!', 12, 0, 100, 0, 0, 0, 21896, 0, 'Skyguard Windcharger'),
(23257, 0, 8, 'Buzz the landing pad lately, $n?', 12, 0, 100, 0, 0, 0, 21889, 0, 'Skyguard Windcharger'),
(23257, 0, 9, 'The list of Skyguard members is long and distinguished.  $n tops that list.', 12, 0, 100, 0, 0, 0, 21939, 0, 'Skyguard Windcharger'),
(22982, 0, 5, 'Well, if it isn''t our resident $g flyboy : flygirl;, $n.  How''s it going, ace?', 12, 0, 100, 0, 0, 0, 21898, 0, 'Skyguard Navigator'),
(22982, 0, 6, 'Hey, it''s our ace flyer, $n!', 12, 0, 100, 0, 0, 0, 21883, 0, 'Skyguard Navigator');
