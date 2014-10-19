DELETE FROM `creature_text` WHERE `entry` IN (12428,12423,12430,12427,12429);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- Deathguard Kel
(12428, 0, 0, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those gnolls with your power to back me!', 12, 1, 100, 1, 0, 0, 'Deathguard Kel - SAY_THANKS'),
(12428, 1, 0, 'Farewell to you, and may shadow always protect you!', 12, 1, 100, 3, 0, 0, 'Deathguard Kel - SAY_GOODBYE'),
(12428, 2, 0, 'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.', 12, 0, 100, 2, 0, 0, 'Deathguard Kel - SAY_HEALED'),
-- Guard Robert
(12423, 0, 0, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those murlocs with the Light on my side!', 12, 7, 100, 1, 0, 0, 'Guard Roberts - SAY_THANKS'),
(12423, 1, 0, 'Farewell to you, and may the Light be with you always.', 12, 7, 100, 3, 0, 0, 'Guard Roberts - SAY_GOODBYE'),
(12423, 2, 0, 'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.', 12, 0, 100, 2, 0, 0, 'Guard Robert - SAY_HEALED'),
-- Grunt Kor'ja
(12430, 0, 0, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those humans with your power to back me!', 12, 7, 100, 0, 0, 0, 'Grunt Kor''ja - SAY_THANKS'),
(12430, 1, 0, 'Farewell to you, and may our ancestors be with you always!', 12, 1, 100, 3, 0, 0, 'Grunt Kor''ja - SAY_GOODBYE'),
(12430, 2, 0, 'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.', 12, 0, 100, 2, 0, 0, 'Grunt Kor''ja - SAY_HEALED'),
-- Mountaineer Dol
(12427, 0, 0, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those wendigo with the Light on my side!', 12, 7, 100, 1, 0, 0, 'Mountaineer Dolf - SAY_THANKS'),
(12427, 1, 0, 'Farewell to you, and may the Light be with you always.', 12, 7, 100, 3, 0, 0, 'Mountaineer Dolf - SAY_GOODBYE'),
(12427, 2, 0, 'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.', 12, 0, 100, 2, 0, 0, 'Mountaineer Dol - SAY_HEALED'),
-- Sentinel Shaya
(12429, 0, 0, 'Thank you! Thank you, $GPriest:Priestess;. Now I can take on those corrupt timberlings with Elune''s power behind me!', 12, 2, 100, 1, 0, 0, 'Sentinel Shaya - SAY_THANKS'),
(12429, 1, 0, 'Farewell to you, and may Elune be with you always.', 12, 2, 100, 3, 0, 0, 'Sentinel Shaya - SAY_GOODBYE'),
(12429, 2, 0, 'Ah, $GPriest:Priestess; you came along just in time. I appreciate it.', 12, 0, 100, 2, 0, 0, 'Sentinel Shaya - SAY_HEALED');
