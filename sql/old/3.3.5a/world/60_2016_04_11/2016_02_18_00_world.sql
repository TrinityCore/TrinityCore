-- Add missing creature text for Mr. Smite in Deadmines.
DELETE FROM creature_text WHERE entry=646;
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(646, 0, 0, 'You there, check out that noise!', 14, 0, 100, 0, 0, 5775, 1148, 2, 'smite SAY_ALARM1'),
(646, 1, 0, 'We\'re under attack! Avast, ye swabs! Repel the invaders!', 14, 0, 100, 0, 0, 5777, 1149, 2, 'smite SAY_ALARM2'),
(646, 2, 0, 'You landlubbers are tougher than I thought, I\'ll have to Improvise!', 12, 0, 100, 0, 0, 5778, 1344, 0, 'smite SAY_PHASE_1'),
(646, 3, 0, 'D\'ah! Now you\'re making me angry!', 12, 0, 100, 0, 0, 5779, 1345, 0, 'smite SAY_PHASE_2');
