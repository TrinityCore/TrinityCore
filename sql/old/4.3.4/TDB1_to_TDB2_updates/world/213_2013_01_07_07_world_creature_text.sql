-- Texts for Baron Rivendare (Strathhome)
DELETE FROM `creature_text` WHERE `entry`= 15369;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15369,0,0, 'Intruders! More pawns of the Argent Dawn, no doubt. I already count one of their number among my prisoners. Withdraw from my domain before she is executed!',14,0,100,0,0,0, 'Baron Rivendare - Baron Run Start'),
(15369,1,0, 'You''re still here? Your foolishness is amusing! The Argent Dawn wench needn''t suffer in vain. Leave at once and she shall be spared!',14,0,100,0,0,0, 'Baron Rivendare - Baron Run in progress random'),
(15369,1,1, 'I shall take great pleasure in taking this poor wretch''s life! It''s not too late, she needn''t suffer in vain. Turn back and her death shall be merciful!',14,0,100,0,0,0, 'Baron Rivendare - Baron Run in progress random'),
(15369,2,0, 'May this prisoner''s death serve as a warning. None shall defy the Scourge and live!',14,0,100,0,0,0, 'Baron Rivendare - Baron Run Fail'),
(15369,3,0, 'So you see fit to toy with the Lich King''s creations? Ramstein, be sure to give the intruders a proper greeting.',14,0,100,0,0,0, 'Baron Rivendare - Event Ramstein'),
(15369,4,0, 'Time to take matters into my own hands. Come. Enter my domain and challenge the might of the Scourge!',14,0,100,0,0,0, 'Baron Rivendare - Event Baron');
