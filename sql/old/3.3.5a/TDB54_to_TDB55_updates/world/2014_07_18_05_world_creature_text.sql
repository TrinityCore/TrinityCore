--
DELETE FROM `creature_text` WHERE `entry`=1402 AND `groupid`=0 AND `id`>2;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES 
(1402, 0, 3, 'It''s all their fault, stupid orcs. Had to burn my farm to the ground.', 12, 7, 100, 0, 0, 0, 'Topper McNabb', 187),
(1402, 0, 4, 'Spare some change for a poor blind man? ...What do you mean I''m not blind? ...I''M NOT BLIND! I CAN SEE!! It''s a miracle!', 12, 7, 100, 0, 0, 0, 'Topper McNabb', 184),
(1402, 0, 5, 'Alms for the poor?', 12, 7, 100, 0, 0, 0, 'Topper McNabb', 181),
(1402, 0, 6, 'I will gladly pay you Tuesday for a hamburger today.', 12, 7, 100, 0, 0, 0, 'Topper McNabb', 182),
(1402, 0, 7, 'It''s all their fault, stupid Alliance army. Just had to build their towers right behind my farm.', 12, 7, 100, 0, 0, 0, 'Topper McNabb', 186);
