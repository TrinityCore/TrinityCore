-- 
DELETE FROM `creature_text` WHERE `entry`=18209;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(18209, 0, 0, 'It''s an ambush! Defend yourself!', 12, 0, 100, 0, 0, 0, 15044, 0, 'Kurenai Captive'),
(18209, 1, 0, 'More of them coming! Watch out!', 12, 0, 100, 0, 0, 0, 15000, 0, 'Kurenai Captive'),
(18209, 2, 0, 'Ride the lightning, filth!', 12, 1, 100, 0, 0, 0, 15006, 0, 'Kurenai Captive'),
(18209, 3, 0, 'We are surrounded!', 14, 0, 100, 0, 0, 0, 15047, 0, 'Kurenai Captive'),
(18209, 4, 0, 'Up ahead is the road to Telaar. We will split up when we reach the fork as they will surely send more Murkblood after us. Hopefully one of us makes it back to Telaar alive.', 14, 7, 100, 0, 0, 0, 15048, 0, 'Kurenai Captive');
