DELETE FROM `creature_text` WHERE entry=22984;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(22984, 0, 0, 'You hear a loud rumble of metal grinding on stone...', 16, 0, 100, 0, 0, 0, 18600, 2, 'Trigger emote when High Warlord Naj\entus dies'),
(22984, 1, 0, 'The door to The Den of Mortal Delights has opened.', 16, 0, 100, 0, 0, 0, 21494, 2, 'Trigger emote when Teron Gorefiend dies');
