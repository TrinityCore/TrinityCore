DELETE FROM `creature_text` WHERE `entry` IN(37671,38065) AND `id`>0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(37671, 0, 1, 'Time is money, friend. Go go go!', 12, 0, 100, 1, 0, 0, 38022, 0, 'Crown Supply Guard'),
(38065, 0, 1, 'Time is money, friend. Go go go!', 12, 0, 100, 1, 0, 0, 38022, 0, 'Crown Supply Guard'),
(37671, 0, 2, 'The Lovely Merchant is waiting for that. Hurry it up!', 12, 0, 100, 1, 0, 0, 38023, 0, 'Crown Supply Guard'),
(38065, 0, 2, 'The Lovely Merchant is waiting for that. Hurry it up!', 12, 0, 100, 1, 0, 0, 38023, 0, 'Crown Supply Guard');
