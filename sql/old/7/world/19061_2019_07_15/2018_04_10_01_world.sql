-- 
DELETE FROM `gossip_menu` WHERE (`MenuId`=7489 AND `TextId`=9107) OR (`MenuId`=7465 AND `TextId`=9076) OR (`MenuId`=7547 AND `TextId`=9162) OR (`MenuId`=7544 AND `TextId`=9153) OR (`MenuId`=7542 AND `TextId`=9148) OR (`MenuId`=7545 AND `TextId`=9155) OR (`MenuId`=7546 AND `TextId`=9158) OR (`MenuId`=7543 AND `TextId`=9151) OR (`MenuId`=7541 AND `TextId`=9145) OR (`MenuId`=14149 AND `TextId`=8588) OR (`MenuId`=14153 AND `TextId`=8592) OR (`MenuId`=14147 AND `TextId`=8584) OR (`MenuId`=14145 AND `TextId`=8586);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7489, 9107, 26124), -- 17843 (Vindicator Kuros)
(7465, 9076, 26124), -- 17684 (Vindicator Boros)
(7547, 9162, 26124), -- 17468 (Prophet Velen)
(7544, 9153, 26124), -- 17116 (Exarch Menelaous)
(7542, 9148, 26124), -- 17240 (Admiral Odesyus)
(7545, 9155, 26124), -- 17649 (Kessel)
(7546, 9158, 26124), -- 17311 (Cowlen)
(7543, 9151, 26124), -- 17117 (Injured Night Elf Priestess)
(7541, 9145, 26124), -- 17440 (High Chief Stillpine)
(14149, 8588, 26124), -- 49961 (Viik)
(14153, 8592, 26124), -- 49962 (Andrenatol)
(14147, 8584, 26124), -- 49957 (Delemm)
(14145, 8586, 26124); -- 49966 (Shaniri)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=14146 AND `OptionIndex`=8) OR (`MenuId`=7465 AND `OptionIndex`=0) OR (`MenuId`=7452 AND `OptionIndex`=3) OR (`MenuId`=7452 AND `OptionIndex`=2) OR (`MenuId`=7452 AND `OptionIndex`=1) OR (`MenuId`=7452 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(14146, 8, 0, 'Enter the Proving Grounds', 74757, 26124),
(7465, 0, 0, 'Where should I begin my search for the portal?', 14503, 26124),
(7452, 3, 0, 'Jessera, could you direct me towards the blood mushrooms?', 14292, 26124),
(7452, 2, 0, 'Jessera, could you direct me towards the fel cone fungus?', 14290, 26124),
(7452, 1, 0, 'Jessera, could you direct me towards the ruinous polyspore?', 14287, 26124),
(7452, 0, 0, 'Jessera, could you direct me towards the aquatic stinkhorn?', 14284, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14429, `VerifiedBuild`=26124 WHERE (`MenuId`=7491 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14429, `VerifiedBuild`=26124 WHERE (`MenuId`=7492 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=14429, `VerifiedBuild`=26124 WHERE (`MenuId`=7493 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15945, `VerifiedBuild`=26124 WHERE (`MenuId`=7455 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15936, `VerifiedBuild`=26124 WHERE (`MenuId`=7833 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=15944, `VerifiedBuild`=26124 WHERE (`MenuId`=7459 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=7497 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=7465 AND `OptionIndex`=0) OR (`MenuId`=7452 AND `OptionIndex`=3) OR (`MenuId`=7452 AND `OptionIndex`=2) OR (`MenuId`=7452 AND `OptionIndex`=1) OR (`MenuId`=7452 AND `OptionIndex`=0) OR (`MenuId`=7491 AND `OptionIndex`=0) OR (`MenuId`=7492 AND `OptionIndex`=0) OR (`MenuId`=7493 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7465, 0, 7501, 0),
(7452, 3, 7457, 0),
(7452, 2, 7456, 0),
(7452, 1, 7454, 0),
(7452, 0, 7453, 0),
(7491, 0, 7490, 0),
(7492, 0, 7491, 0),
(7493, 0, 7492, 0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=7455 AND `OptionIndex`=0) OR (`MenuId`=7833 AND `OptionIndex`=0) OR (`MenuId`=7459 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(7455, 0, 160),
(7833, 0, 91),
(7459, 0, 133);
DELETE FROM `gossip_menu` WHERE (`MenuId`=14152 AND `TextId`=9194) OR (`MenuId`=7403 AND `TextId`=8869) OR (`MenuId`=7398 AND `TextId`=8863) OR (`MenuId`=14157 AND `TextId`=8785) OR (`MenuId`=7376 AND `TextId`=8825) OR (`MenuId`=14287 AND `TextId`=20143) OR (`MenuId`=14148 AND `TextId`=8768) OR (`MenuId`=14156 AND `TextId`=8785);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14152, 9194, 26124), -- 16721 (Shalannius)
(7403, 8869, 26124), -- 17311 (Cowlen)
(7398, 8863, 26124), -- 17241 (Priestess Kyleen Il'dinare)
(14157, 8785, 26124), -- 17212 (Tuluun)
(7376, 8825, 26124), -- 17087 (Spirit of the Vale)
(14287, 20143, 26124), -- 63335 (Mojo Stormstout)
(14148, 8768, 26124), -- 16502 (Zalduun)
(14156, 8785, 26124); -- 17089 (Firmanvaar)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=7399 AND `OptionIndex`=0) OR (`MenuId`=7431 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(7399, 0, 0, 'Admiral, I need another tree disguise kit.', 13792, 26124),
(7431, 0, 1, 'Hello, Parkat. I wish to purchase something.', 14161, 26124);
UPDATE `gossip_menu_option` SET `OptionText`='Acteon, where is the best place to hunt moongraze bucks?', `OptionBroadcastTextId`=14060, `VerifiedBuild`=26124 WHERE (`MenuId`=7368 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionText`='Acteon, where is the best area to hunt for moongraze stags?', `OptionBroadcastTextId`=14058, `VerifiedBuild`=26124 WHERE (`MenuId`=7368 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4308, `VerifiedBuild`=26124 WHERE (`MenuId`=7468 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47118, `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47111, `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=2);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=7468 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7468, 0, 1221, 0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7424 WHERE (`MenuId`=7368 AND `OptionIndex`=2);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7423 WHERE (`MenuId`=7368 AND `OptionIndex`=1);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=7389 AND `OptionIndex`=0) OR (`MenuId`=7388 AND `OptionIndex`=0) OR (`MenuId`=7429 AND `OptionIndex`=0) OR (`MenuId`=7430 AND `OptionIndex`=0) OR (`MenuId`=7383 AND `OptionIndex`=0) OR (`MenuId`=7384 AND `OptionIndex`=0) OR (`MenuId`=7380 AND `OptionIndex`=0) OR (`MenuId`=12199 AND `OptionIndex`=10) OR (`MenuId`=12198 AND `OptionIndex`=11) OR (`MenuId`=12197 AND `OptionIndex`=11) OR (`MenuId`=12196 AND `OptionIndex`=11) OR (`MenuId`=12195 AND `OptionIndex`=11) OR (`MenuId`=12193 AND `OptionIndex`=2) OR (`MenuId`=12192 AND `OptionIndex`=11) OR (`MenuId`=12191 AND `OptionIndex`=11) OR (`MenuId`=12190 AND `OptionIndex`=11) OR (`MenuId`=12189 AND `OptionIndex`=11) OR (`MenuId`=12188 AND `OptionIndex`=11) OR (`MenuId`=12180 AND `OptionIndex`=10) OR (`MenuId`=12180 AND `OptionIndex`=2) OR (`MenuId`=14991 AND `OptionIndex`=0) OR (`MenuId`=7361 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(7389, 0, 27),
(7388, 0, 136),
(7429, 0, 196),
(7430, 0, 56),
(7383, 0, 407),
(7384, 0, 105),
(7380, 0, 160),
(12199, 10, 117),
(12198, 11, 103),
(12197, 11, 48),
(12196, 11, 387),
(12195, 11, 102),
(12193, 2, 51),
(12192, 11, 80),
(12191, 11, 59),
(12190, 11, 390),
(12189, 11, 389),
(12188, 11, 388),
(12180, 10, 117),
(12180, 2, 51),
(14991, 0, 580),
(7361, 0, 10);
DELETE FROM `gossip_menu` WHERE (`MenuId`=6596 AND `TextId`=7817) OR (`MenuId`=6532 AND `TextId`=7748) OR (`MenuId`=6544 AND `TextId`=7752) OR (`MenuId`=21720 AND `TextId`=33093);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(6596, 7817, 26124), -- 15194 (Hermit Ortell)
(6532, 7748, 26124), -- 15183 (Geologist Larksbane)
(6544, 7752, 26124), -- 15190 (Noggle Ficklespragg)
(21720, 33093, 26124); -- 128607 (Zidormi)
UPDATE `gossip_menu_option` SET `OptionText`='<Nod>.', `VerifiedBuild`=26124 WHERE (`MenuId`=5702 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=6525 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=10647, `VerifiedBuild`=26124 WHERE (`MenuId`=6525 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=11037 AND `TextId`=15347) OR (`MenuId`=11036 AND `TextId`=15345) OR (`MenuId`=11036 AND `TextId`=15370) OR (`MenuId`=11038 AND `TextId`=15349) OR (`MenuId`=11039 AND `TextId`=15348) OR (`MenuId`=11040 AND `TextId`=15350) OR (`MenuId`=11041 AND `TextId`=15348) OR (`MenuId`=11042 AND `TextId`=15351) OR (`MenuId`=11043 AND `TextId`=15348) OR (`MenuId`=11055 AND `TextId`=15376) OR (`MenuId`=11056 AND `TextId`=15375) OR (`MenuId`=11057 AND `TextId`=15374) OR (`MenuId`=11058 AND `TextId`=15373) OR (`MenuId`=11059 AND `TextId`=15372) OR (`MenuId`=11060 AND `TextId`=15371) OR (`MenuId`=11037 AND `TextId`=15346) OR (`MenuId`=2181 AND `TextId`=2812) OR (`MenuId`=2177 AND `TextId`=2810) OR (`MenuId`=11022 AND `TextId`=15325) OR (`MenuId`=11228 AND `TextId`=15639) OR (`MenuId`=11021 AND `TextId`=15324) OR (`MenuId`=20609 AND `TextId`=30907) OR (`MenuId`=2182 AND `TextId`=2813) OR (`MenuId`=2179 AND `TextId`=2810) OR (`MenuId`=10978 AND `TextId`=15277) OR (`MenuId`=10994 AND `TextId`=15291) OR (`MenuId`=11030 AND `TextId`=15333) OR (`MenuId`=10995 AND `TextId`=15294) OR (`MenuId`=10995 AND `TextId`=15296) OR (`MenuId`=11029 AND `TextId`=15332) OR (`MenuId`=10978 AND `TextId`=15278) OR (`MenuId`=10982 AND `TextId`=15270) OR (`MenuId`=10981 AND `TextId`=15269) OR (`MenuId`=10980 AND `TextId`=15268) OR (`MenuId`=10979 AND `TextId`=15267) OR (`MenuId`=10989 AND `TextId`=15266) OR (`MenuId`=12601 AND `TextId`=17736) OR (`MenuId`=2180 AND `TextId`=2811) OR (`MenuId`=2178 AND `TextId`=2810) OR (`MenuId`=11044 AND `TextId`=15353);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11037, 15347, 26124), -- 38504 (Un'Goro Examinant)
(11036, 15345, 26124), -- 38502 (Nablya)
(11036, 15370, 26124), -- 38502 (Nablya)
(11038, 15349, 26124), -- 6516 (Un'Goro Thunderer)
(11039, 15348, 26124), -- 6516 (Un'Goro Thunderer)
(11040, 15350, 26124), -- 6514 (Un'Goro Gorilla)
(11041, 15348, 26124), -- 6514 (Un'Goro Gorilla)
(11042, 15351, 26124), -- 6513 (Un'Goro Stomper)
(11043, 15348, 26124), -- 6513 (Un'Goro Stomper)
(11055, 15376, 26124), -- 38502 (Nablya)
(11056, 15375, 26124), -- 38502 (Nablya)
(11057, 15374, 26124), -- 38502 (Nablya)
(11058, 15373, 26124), -- 38502 (Nablya)
(11059, 15372, 26124), -- 38502 (Nablya)
(11060, 15371, 26124), -- 38502 (Nablya)
(11037, 15346, 26124), -- 38504 (Un'Goro Examinant)
(2181, 2812, 26124), -- 164955
(2177, 2810, 26124), -- 164955
(11022, 15325, 26124), -- 38275 (Gremix)
(11228, 15639, 26124), -- 9623 (A-Me 01)
(11021, 15324, 26124), -- 38276 (Tara)
(20609, 30907, 26124), -- 115923 (Ko'Zan)
(2182, 2813, 26124), -- 164956
(2179, 2810, 26124), -- 164956
(10978, 15277, 26124), -- 38237 (Maximillian of Northshire)
(10994, 15291, 26124), -- 38255 (Maximillian of Northshire)
(11030, 15333, 26124), -- 38255 (Maximillian of Northshire)
(10995, 15294, 26124), -- 38238 (Damsel by the Shore)
(10995, 15296, 26124), -- 38238 (Damsel by the Shore)
(11029, 15332, 26124), -- 38255 (Maximillian of Northshire)
(10978, 15278, 26124), -- 38237 (Maximillian of Northshire)
(10982, 15270, 26124), -- 38237 (Maximillian of Northshire)
(10981, 15269, 26124), -- 38237 (Maximillian of Northshire)
(10980, 15268, 26124), -- 38237 (Maximillian of Northshire)
(10979, 15267, 26124), -- 38237 (Maximillian of Northshire)
(10989, 15266, 26124), -- 38237 (Maximillian of Northshire)
(12601, 17736, 26124), -- 38269 (Zen'Aliri)
(2180, 2811, 26124), -- 164957
(2178, 2810, 26124), -- 164957
(11044, 15353, 26124); -- 38263 (Ithis Moonwarden)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11037 AND `OptionIndex`=0) OR (`MenuId`=2177 AND `OptionIndex`=0) OR (`MenuId`=10978 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11037, 0, 0, 'I''m ready to go to The Shaper''s Terrace.', 38396, 26124),
(2177, 0, 0, 'Examine the pylon.', 5152, 26124),
(10978, 1, 0, 'Maximillian, I am ready for adventure.', 38164, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38397, `VerifiedBuild`=26124 WHERE (`MenuId`=11037 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38415, `VerifiedBuild`=26124 WHERE (`MenuId`=11038 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38408, `VerifiedBuild`=26124 WHERE (`MenuId`=11039 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38415, `VerifiedBuild`=26124 WHERE (`MenuId`=11040 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38410, `VerifiedBuild`=26124 WHERE (`MenuId`=11041 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38415, `VerifiedBuild`=26124 WHERE (`MenuId`=11042 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38409, `VerifiedBuild`=26124 WHERE (`MenuId`=11043 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38476, `VerifiedBuild`=26124 WHERE (`MenuId`=11055 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38475, `VerifiedBuild`=26124 WHERE (`MenuId`=11056 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38474, `VerifiedBuild`=26124 WHERE (`MenuId`=11057 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38473, `VerifiedBuild`=26124 WHERE (`MenuId`=11058 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38472, `VerifiedBuild`=26124 WHERE (`MenuId`=11059 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38393, `VerifiedBuild`=26124 WHERE (`MenuId`=11036 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38339, `VerifiedBuild`=26124 WHERE (`MenuId`=10994 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38187, `VerifiedBuild`=26124 WHERE (`MenuId`=10994 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38340, `VerifiedBuild`=26124 WHERE (`MenuId`=10994 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37969, `VerifiedBuild`=26124 WHERE (`MenuId`=10981 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37965, `VerifiedBuild`=26124 WHERE (`MenuId`=10980 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37962, `VerifiedBuild`=26124 WHERE (`MenuId`=10979 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37960, `VerifiedBuild`=26124 WHERE (`MenuId`=10989 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37975, `VerifiedBuild`=26124 WHERE (`MenuId`=10978 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11039 AND `OptionIndex`=0) OR (`MenuId`=11041 AND `OptionIndex`=0) OR (`MenuId`=11043 AND `OptionIndex`=0) OR (`MenuId`=11055 AND `OptionIndex`=0) OR (`MenuId`=11056 AND `OptionIndex`=0) OR (`MenuId`=11057 AND `OptionIndex`=0) OR (`MenuId`=11058 AND `OptionIndex`=0) OR (`MenuId`=11059 AND `OptionIndex`=0) OR (`MenuId`=11060 AND `OptionIndex`=0) OR (`MenuId`=11036 AND `OptionIndex`=1) OR (`MenuId`=2177 AND `OptionIndex`=0) OR (`MenuId`=2179 AND `OptionIndex`=0) OR (`MenuId`=10994 AND `OptionIndex`=1) OR (`MenuId`=10994 AND `OptionIndex`=0) OR (`MenuId`=10981 AND `OptionIndex`=0) OR (`MenuId`=10980 AND `OptionIndex`=0) OR (`MenuId`=10979 AND `OptionIndex`=0) OR (`MenuId`=10989 AND `OptionIndex`=0) OR (`MenuId`=10978 AND `OptionIndex`=0) OR (`MenuId`=10980 AND `OptionIndex`=1) OR (`MenuId`=2178 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(11039, 0, 11038, 0),
(11041, 0, 11040, 0),
(11043, 0, 11042, 0),
(11055, 0, 11036, 0),
(11056, 0, 11055, 0),
(11057, 0, 11056, 0),
(11058, 0, 11057, 0),
(11059, 0, 11058, 0),
(11060, 0, 11059, 0),
(11036, 1, 11060, 0),
(2177, 0, 2181, 0),
(2179, 0, 2182, 0),
(10994, 1, 11030, 0),
(10994, 0, 11029, 0),
(10981, 0, 10982, 0),
(10980, 0, 10981, 0),
(10979, 0, 10980, 0),
(10989, 0, 10979, 0),
(10978, 0, 10989, 0),
(10980, 1, 10981, 0),
(2178, 0, 2180, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=11178 AND `TextId`=15559);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11178, 15559, 26124); -- 39034 (Dr. Dealwell)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12644 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(12644, 0, 0, 'Examine the chest.', 50640, 26124);
DELETE FROM `gossip_menu` WHERE (`MenuId`=12661 AND `TextId`=17749) OR (`MenuId`=11141 AND `TextId`=15504) OR (`MenuId`=11402 AND `TextId`=15883) OR (`MenuId`=11896 AND `TextId`=16688) OR (`MenuId`=11426 AND `TextId`=15911) OR (`MenuId`=11111 AND `TextId`=15466) OR (`MenuId`=11094 AND `TextId`=15444) OR (`MenuId`=11066 AND `TextId`=15385) OR (`MenuId`=11160 AND `TextId`=15532) OR (`MenuId`=11731 AND `TextId`=16424);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12661, 17749, 26124), -- 38578 (Flinn)
(11141, 15504, 26124), -- 39059 (Kelsey Steelspark)
(11402, 15883, 26124), -- 38714 (Carmen Ibanozzle)
(11896, 16688, 26124), -- 44869 (Marvon Rivetseeker)
(11426, 15911, 26124), -- 40580 (Gus Rustflutter)
(11111, 15466, 26124), -- 38927 (Mazoga)
(11094, 15444, 26124), -- 38856 (Dunemaul "Emissary")
(11066, 15385, 26124), -- 38535 (Kelsey Steelspark)
(11160, 15532, 26124), -- 38532 (Marin Noggenfogger)
(11731, 16424, 26124); -- 43418 (Sprinkle Noggenfogger)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=6646 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(6646, 2, 0, 'I''m ready to pilot our silithid.', 38743, 26124);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=11402 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43487, `VerifiedBuild`=26124 WHERE (`MenuId`=11731 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionIcon`=1, `OptionText`='I want to browse your goods.', `OptionBroadcastTextId`=3370, `VerifiedBuild`=26124 WHERE (`MenuId`=2890 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=26124 WHERE (`MenuId`=2890 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=4152 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(4152, 0, 407);
DELETE FROM `gossip_menu` WHERE (`MenuId`=12345 AND `TextId`=17348) OR (`MenuId`=12324 AND `TextId`=17319) OR (`MenuId`=12294 AND `TextId`=17275) OR (`MenuId`=12296 AND `TextId`=17278) OR (`MenuId`=12298 AND `TextId`=17280) OR (`MenuId`=12297 AND `TextId`=17279) OR (`MenuId`=12270 AND `TextId`=17234) OR (`MenuId`=12005 AND `TextId`=16827) OR (`MenuId`=15009 AND `TextId`=21220) OR (`MenuId`=11460 AND `TextId`=15981) OR (`MenuId`=11429 AND `TextId`=15918) OR (`MenuId`=11418 AND `TextId`=15898) OR (`MenuId`=11428 AND `TextId`=15915) OR (`MenuId`=12252 AND `TextId`=17214);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12345, 17348, 25996), -- 47745 (Magatha Grimtotem)
(12324, 17319, 25996), -- 47585 (Twilight Magus)
(12294, 17275, 25996), -- 47580 (Lakota Windsong)
(12296, 17278, 25996), -- 47602 (Codemaster Deethuk)
(12298, 17280, 25996), -- 47620 (Commander Fastfuse)
(12297, 17279, 25996), -- 47619 (Elementalist Starion)
(12270, 17234, 25996), -- 47471 (Pao'ka Swiftmountain)
(12005, 16827, 25996), -- 53604 (Feralas Sentinel)
(15009, 21220, 25996), -- Kela Grimtotem
(11460, 15981, 25996), -- 41135 ("Plucky" Johnson)
(11429, 15918, 25996), -- 40726 (Mazzer Stripscrew)
(11418, 15898, 25996), -- 40591 (Drag Master Miglen)
(11428, 15915, 25996), -- 40726 (Mazzer Stripscrew)
(12252, 17214, 25996); -- 40475 (Jinky Twizzlefixxit)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11403 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11403, 0, 1, 'Let me browse your goods.', 2823, 25996); -- OptionBroadcastTextID: 2823 - 7509 - 8097
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47954, `VerifiedBuild`=25996 WHERE (`MenuId`=12296 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47975, `VerifiedBuild`=25996 WHERE (`MenuId`=12298 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47976, `VerifiedBuild`=25996 WHERE (`MenuId`=12297 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47602, `VerifiedBuild`=25996 WHERE (`MenuId`=12260 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41055, `VerifiedBuild`=25996 WHERE (`MenuId`=11460 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40647, `VerifiedBuild`=25996 WHERE (`MenuId`=11428 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=25996 WHERE (`MenuId`=11435 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40732, `VerifiedBuild`=25996 WHERE (`MenuId`=11435 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=11196 AND `TextId`=15589) OR (`MenuId`=11196 AND `TextId`=15588) OR (`MenuId`=11182 AND `TextId`=15564) OR (`MenuId`=11155 AND `TextId`=15528) OR (`MenuId`=11182 AND `TextId`=15590) OR (`MenuId`=11171 AND `TextId`=15547) OR (`MenuId`=11019 AND `TextId`=15317) OR (`MenuId`=14999 AND `TextId`=21208) OR (`MenuId`=11175 AND `TextId`=15552) OR (`MenuId`=11196 AND `TextId`=15587) OR (`MenuId`=11196 AND `TextId`=15586) OR (`MenuId`=11158 AND `TextId`=15539) OR (`MenuId`=11162 AND `TextId`=15535) OR (`MenuId`=11163 AND `TextId`=15536) OR (`MenuId`=11158 AND `TextId`=15530) OR (`MenuId`=11165 AND `TextId`=15541) OR (`MenuId`=11153 AND `TextId`=15525) OR (`MenuId`=11814 AND `TextId`=16567) OR (`MenuId`=11147 AND `TextId`=15518) OR (`MenuId`=11138 AND `TextId`=15515) OR (`MenuId`=11138 AND `TextId`=15514) OR (`MenuId`=11148 AND `TextId`=15519) OR (`MenuId`=11140 AND `TextId`=15501) OR (`MenuId`=11138 AND `TextId`=15496) OR (`MenuId`=11138 AND `TextId`=15495) OR (`MenuId`=11151 AND `TextId`=15522) OR (`MenuId`=11150 AND `TextId`=15521) OR (`MenuId`=11149 AND `TextId`=15520) OR (`MenuId`=11147 AND `TextId`=15517) OR (`MenuId`=11108 AND `TextId`=15482) OR (`MenuId`=10941 AND `TextId`=15289) OR (`MenuId`=10941 AND `TextId`=15293) OR (`MenuId`=10941 AND `TextId`=15205) OR (`MenuId`=11005 AND `TextId`=15303) OR (`MenuId`=10941 AND `TextId`=15288) OR (`MenuId`=11028 AND `TextId`=15331) OR (`MenuId`=11026 AND `TextId`=15330) OR (`MenuId`=11027 AND `TextId`=15329) OR (`MenuId`=11025 AND `TextId`=15328) OR (`MenuId`=11024 AND `TextId`=15327) OR (`MenuId`=11129 AND `TextId`=15483) OR (`MenuId`=11108 AND `TextId`=15459) OR (`MenuId`=11128 AND `TextId`=15481) OR (`MenuId`=11119 AND `TextId`=15477) OR (`MenuId`=11118 AND `TextId`=15475) OR (`MenuId`=11115 AND `TextId`=15473) OR (`MenuId`=11121 AND `TextId`=15479) OR (`MenuId`=11113 AND `TextId`=15471) OR (`MenuId`=11120 AND `TextId`=15478) OR (`MenuId`=11117 AND `TextId`=15476) OR (`MenuId`=11116 AND `TextId`=15474) OR (`MenuId`=11122 AND `TextId`=15480) OR (`MenuId`=11105 AND `TextId`=15455) OR (`MenuId`=11080 AND `TextId`=15409) OR (`MenuId`=11068 AND `TextId`=15411) OR (`MenuId`=11071 AND `TextId`=15398) OR (`MenuId`=11071 AND `TextId`=15397) OR (`MenuId`=11068 AND `TextId`=15393) OR (`MenuId`=11197 AND `TextId`=15594) OR (`MenuId`=11197 AND `TextId`=15593) OR (`MenuId`=11010 AND `TextId`=15314);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11196, 15589, 25996), -- 39118 (General Twinbraid)
(11196, 15588, 25996), -- 39118 (General Twinbraid)
(11182, 15564, 25996), -- 39155 (Marley Twinbraid)
(11155, 15528, 25996), -- 37835 (Dorn Redearth)
(11182, 15590, 25996), -- 39155 (Marley Twinbraid)
(11171, 15547, 25996), -- 3374 (Bael'dun Excavator)
(11019, 15317, 25996), -- 37812 (Mahka)
(14999, 21208, 25996), -- Cassandra Kaboom
(11175, 15552, 25996), -- 39154 (Hurlston Stonesthrow)
(11196, 15587, 25996), -- 39118 (General Twinbraid)
(11196, 15586, 25996), -- 39118 (General Twinbraid)
(11158, 15539, 25996), -- 39084 (Mizzy Pistonhammer)
(11162, 15535, 25996), -- 39083 (Commander Roberts)
(11163, 15536, 25996), -- 39085 (Logan Talonstrike)
(11158, 15530, 25996), -- 39084 (Mizzy Pistonhammer)
(11165, 15541, 25996), -- 39146 (Clarice Hawthorne)
(11153, 15525, 25996), -- 39094 (Barton Trask)
(11814, 16567, 25996), -- 44267 (Logistics Officer Salista)
(11147, 15518, 25996), -- 38986 (Ambassador Gaines)
(11138, 15515, 25996), -- 38323 (General Hawthorne)
(11138, 15514, 25996), -- 38323 (General Hawthorne)
(11148, 15519, 25996), -- 39003 (Sam Trawley)
(11140, 15501, 25996), -- 37743 (Taurajo Looter)
(11138, 15496, 25996), -- 38323 (General Hawthorne)
(11138, 15495, 25996), -- 38323 (General Hawthorne)
(11151, 15522, 25996), -- 38323 (General Hawthorne)
(11150, 15521, 25996), -- 38323 (General Hawthorne)
(11149, 15520, 25996), -- 38323 (General Hawthorne)
(11147, 15517, 25996), -- 38986 (Ambassador Gaines)
(11108, 15482, 25996), -- 38871 (Corporal Teegan)
(10941, 15289, 25996), -- 37570 (Naralex)
(10941, 15293, 25996), -- 37570 (Naralex)
(10941, 15205, 25996), -- 37570 (Naralex)
(11005, 15303, 25996), -- 38314 (Muyoh)
(10941, 15288, 25996), -- 37570 (Naralex)
(11028, 15331, 25996), -- 37570 (Naralex)
(11026, 15330, 25996), -- 37570 (Naralex)
(11027, 15329, 25996), -- 37570 (Naralex)
(11025, 15328, 25996), -- 37570 (Naralex)
(11024, 15327, 25996), -- 37570 (Naralex)
(11129, 15483, 25996), -- 38876 (Hannah Bridgewater)
(11108, 15459, 25996), -- 38871 (Corporal Teegan)
(11128, 15481, 25996), -- 38873 (Goucho)
(11119, 15477, 25996), -- 38875 (Ol' Durty Pete)
(11118, 15475, 25996), -- 38875 (Ol' Durty Pete)
(11115, 15473, 25996), -- 38875 (Ol' Durty Pete)
(11121, 15479, 25996), -- 38875 (Ol' Durty Pete)
(11113, 15471, 25996), -- 38875 (Ol' Durty Pete)
(11120, 15478, 25996), -- 38875 (Ol' Durty Pete)
(11117, 15476, 25996), -- 38875 (Ol' Durty Pete)
(11116, 15474, 25996), -- 38875 (Ol' Durty Pete)
(11122, 15480, 25996), -- 38875 (Ol' Durty Pete)
(11105, 15455, 25996), -- 38878 (Mangled Body)
(11080, 15409, 25996), -- 3454 (Cannoneer Smythe)
(11068, 15411, 25996), -- 38619 (Admiral Aubrey)
(11071, 15398, 25996), -- 38622 (Captain Fisher)
(11071, 15397, 25996), -- 38622 (Captain Fisher)
(11068, 15393, 25996), -- 38619 (Admiral Aubrey)
(11197, 15594, 25996), -- 38383 (Nibb Spindlegear)
(11197, 15593, 25996), -- 38383 (Nibb Spindlegear)
(11010, 15314, 25996); -- 38380 (Janice Mattingly)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11182 AND `OptionIndex`=0) OR (`MenuId`=11814 AND `OptionIndex`=1) OR (`MenuId`=11814 AND `OptionIndex`=0) OR (`MenuId`=11138 AND `OptionIndex`=0) OR (`MenuId`=11140 AND `OptionIndex`=0) OR (`MenuId`=11150 AND `OptionIndex`=0) OR (`MenuId`=11149 AND `OptionIndex`=0) OR (`MenuId`=11128 AND `OptionIndex`=0) OR (`MenuId`=11119 AND `OptionIndex`=1) OR (`MenuId`=11119 AND `OptionIndex`=0) OR (`MenuId`=11118 AND `OptionIndex`=1) OR (`MenuId`=11118 AND `OptionIndex`=0) OR (`MenuId`=11115 AND `OptionIndex`=1) OR (`MenuId`=11115 AND `OptionIndex`=0) OR (`MenuId`=11121 AND `OptionIndex`=1) OR (`MenuId`=11121 AND `OptionIndex`=0) OR (`MenuId`=11113 AND `OptionIndex`=0) OR (`MenuId`=11120 AND `OptionIndex`=0) OR (`MenuId`=11117 AND `OptionIndex`=0) OR (`MenuId`=11116 AND `OptionIndex`=0) OR (`MenuId`=11122 AND `OptionIndex`=0) OR (`MenuId`=11071 AND `OptionIndex`=0) OR (`MenuId`=11068 AND `OptionIndex`=0) OR (`MenuId`=11197 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11182, 0, 0, 'I''m ready, Marley. Let''s fly!', 39254, 25996),
(11814, 1, 1, 'Let me browse your goods.', 2823, 25996), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(11814, 0, 5, 'Make this inn your home.', 2822, 25996),
(11138, 0, 0, 'Tell me what happened at Taurajo.', 39123, 25996),
(11140, 0, 0, 'You''re under arrest.', 39078, 25996),
(11150, 0, 0, 'Why did you do that?', 39127, 25996),
(11149, 0, 0, 'We sacked the town?', 39125, 25996),
(11128, 0, 1, 'Let me browse your goods.', 2823, 25996), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(11119, 1, 0, 'I''ve heard this one. Tell me another...', 38942, 25996),
(11119, 0, 0, 'A butt?', 38940, 25996),
(11118, 1, 0, 'I''ve heard this one. Tell me another...', 38942, 25996),
(11118, 0, 0, 'Weep SNOT!?', 38939, 25996),
(11115, 1, 0, 'I''ve heard this one. Tell me another...', 38942, 25996),
(11115, 0, 0, 'That sounds serious.', 38937, 25996),
(11121, 1, 0, 'I''ve heard this one. Tell me another...', 38942, 25996),
(11121, 0, 0, 'That''s not good.', 38941, 25996), -- OptionBroadcastTextID: 38941 - 84845
(11113, 0, 0, 'Tell me a story, Ol'' Durty Pete!', 38928, 25996),
(11120, 0, 0, 'Tell me another story, Ol'' Durty Pete!', 38938, 25996),
(11117, 0, 0, 'Tell me another story, Ol'' Durty Pete!', 38938, 25996),
(11116, 0, 0, 'Tell me another story, Ol'' Durty Pete!', 38938, 25996),
(11122, 0, 0, 'Tell me another story, Ol'' Durty Pete!', 38938, 25996),
(11071, 0, 0, 'Captain, I need a ride back to Northwatch Hold.', 38581, 25996),
(11068, 0, 0, 'Admiral, can I get a ride to the Blackpool?', 38574, 25996),
(11197, 0, 0, 'I''m ready to fly.', 39360, 25996);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37520, `VerifiedBuild`=25996 WHERE (`MenuId`=10941 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=38336, `VerifiedBuild`=25996 WHERE (`MenuId`=11026 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11150 AND `OptionIndex`=0) OR (`MenuId`=11149 AND `OptionIndex`=0) OR (`MenuId`=11138 AND `OptionIndex`=0) OR (`MenuId`=11026 AND `OptionIndex`=0) OR (`MenuId`=11027 AND `OptionIndex`=0) OR (`MenuId`=11025 AND `OptionIndex`=0) OR (`MenuId`=11024 AND `OptionIndex`=0) OR (`MenuId`=10941 AND `OptionIndex`=1) OR (`MenuId`=11118 AND `OptionIndex`=1) OR (`MenuId`=11115 AND `OptionIndex`=1) OR (`MenuId`=11121 AND `OptionIndex`=1) OR (`MenuId`=11119 AND `OptionIndex`=1) OR (`MenuId`=11113 AND `OptionIndex`=0) OR (`MenuId`=11119 AND `OptionIndex`=0) OR (`MenuId`=11117 AND `OptionIndex`=0) OR (`MenuId`=11118 AND `OptionIndex`=0) OR (`MenuId`=11116 AND `OptionIndex`=0) OR (`MenuId`=11115 AND `OptionIndex`=0) OR (`MenuId`=11122 AND `OptionIndex`=0) OR (`MenuId`=11121 AND `OptionIndex`=0) OR (`MenuId`=11120 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(11150, 0, 11151, 0),
(11149, 0, 11150, 0),
(11138, 0, 11149, 0),
(11026, 0, 11028, 0),
(11027, 0, 11026, 0),
(11025, 0, 11027, 0),
(11024, 0, 11025, 0),
(10941, 1, 11024, 0),
(11118, 1, 11119, 0),
(11115, 1, 11118, 0),
(11121, 1, 11115, 0),
(11119, 1, 11121, 0),
(11113, 0, 11115, 0),
(11119, 0, 11120, 0),
(11117, 0, 11119, 0),
(11118, 0, 11117, 0),
(11116, 0, 11118, 0),
(11115, 0, 11116, 0),
(11122, 0, 11115, 0),
(11121, 0, 11122, 0),
(11120, 0, 11121, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=14983 AND `TextId`=21180) OR (`MenuId`=11458 AND `TextId`=15978) OR (`MenuId`=11449 AND `TextId`=15962) OR (`MenuId`=11452 AND `TextId`=15966);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14983, 21180, 25996), -- 66137 (Zonya the Sadist)
(11458, 15978, 25996), -- 41071 (Huntress Illiona)
(11449, 15962, 25996), -- 40879 (Boog the "Gear Whisperer")
(11452, 15966, 25996); -- 40973 (Sentinel Heliana)
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41360, `VerifiedBuild`=25996 WHERE (`MenuId`=11506 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41360, `VerifiedBuild`=25996 WHERE (`MenuId`=11505 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41358, `VerifiedBuild`=25996 WHERE (`MenuId`=11504 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=25996 WHERE (`MenuId`=11504 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40983, `VerifiedBuild`=25996 WHERE (`MenuId`=11453 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41110, `VerifiedBuild`=25996 WHERE (`MenuId`=11465 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=12708 AND `TextId`=17839) OR (`MenuId`=12566 AND `TextId`=17665) OR (`MenuId`=12503 AND `TextId`=17587) OR (`MenuId`=12567 AND `TextId`=17666) OR (`MenuId`=12593 AND `TextId`=17712) OR (`MenuId`=12599 AND `TextId`=825);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12708, 17839, 25996), -- Winterspring Cub
(12566, 17665, 25996), -- 49396 (Jez Goodgrub)
(12503, 17587, 25996), -- 49407 (Rinno Curtainfire)
(12567, 17666, 25996), -- 50263 (Jadrag the Slicer)
(12593, 17712, 25996), -- 48965 (Deez Rocksnitch)
(12599, 825, 25996); -- 11118 (Innkeeper Vizzie)
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=25996 WHERE (`MenuId`=12599 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=3624 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(3624, 0, 3623, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=12431 AND `TextId`=17482) OR (`MenuId`=12432 AND `TextId`=17483) OR (`MenuId`=14101 AND `TextId`=4993) OR (`MenuId`=12398 AND `TextId`=17426) OR (`MenuId`=12413 AND `TextId`=17452) OR (`MenuId`=12404 AND `TextId`=17433) OR (`MenuId`=12401 AND `TextId`=17430) OR (`MenuId`=15010 AND `TextId`=21219) OR (`MenuId`=12706 AND `TextId`=17843) OR (`MenuId`=12244 AND `TextId`=17197);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(12431, 17482, 25996), -- 47556 (Drizle)
(12432, 17483, 25996), -- 48493 (Alton Redding)
(14101, 4993, 25996), -- 5501 (Kaerbrus)
(12398, 17426, 25996), -- 47842 (Archdruid Navarax)
(12413, 17452, 25996), -- 48044 (Flourishing Protector)
(12404, 17433, 25996), -- 48042 (Sapling Protector)
(12401, 17430, 25996), -- 48032 (Seedling Protector)
(15010, 21219, 25996), -- Zoltan
(12706, 17843, 25996), -- 51664 (Andalar Shadevale)
(12244, 17197, 25996); -- 47341 (Arcanist Delaris)
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=25996 WHERE (`MenuId`=12433 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48371, `VerifiedBuild`=25996 WHERE (`MenuId`=12398 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48133, `VerifiedBuild`=25996 WHERE (`MenuId`=12353 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=3626 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(3626, 0, 163);
DELETE FROM `gossip_menu` WHERE (`MenuId`=11686 AND `TextId`=16363) OR (`MenuId`=8077 AND `TextId`=9983) OR (`MenuId`=10538 AND `TextId`=14577) OR (`MenuId`=10539 AND `TextId`=14576) OR (`MenuId`=10537 AND `TextId`=14575) OR (`MenuId`=10523 AND `TextId`=14557) OR (`MenuId`=11445 AND `TextId`=15946) OR (`MenuId`=10532 AND `TextId`=14572) OR (`MenuId`=14164 AND `TextId`=4993) OR (`MenuId`=10532 AND `TextId`=14571) OR (`MenuId`=10522 AND `TextId`=14556) OR (`MenuId`=10506 AND `TextId`=14538) OR (`MenuId`=10494 AND `TextId`=14521) OR (`MenuId`=10493 AND `TextId`=14520) OR (`MenuId`=10495 AND `TextId`=14523) OR (`MenuId`=10339 AND `TextId`=14347) OR (`MenuId`=10341 AND `TextId`=14351) OR (`MenuId`=10329 AND `TextId`=14339) OR (`MenuId`=14982 AND `TextId`=21179);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11686, 16363, 25996), -- 33777 (Gaivan Shadewalker)
(8077, 9983, 25996), -- 19908 (Su'ura Swiftarrow)
(10538, 14577, 25996), -- 34618 (Ota Wen)
(10539, 14576, 25996), -- 34618 (Ota Wen)
(10537, 14575, 25996), -- 34618 (Ota Wen)
(10523, 14557, 25996), -- 3897 (Krolg)
(11445, 15946, 25996), -- 34354 (Huntress Jalin)
(10532, 14572, 25996), -- 34608 (Big Baobob)
(14164, 4993, 25996), -- 34600 (Alenndaar Lapidaar)
(10532, 14571, 25996), -- 34608 (Big Baobob)
(10522, 14556, 25996), -- 3916 (Shael'dryn)
(10506, 14538, 25996), -- 34377 (Halannia)
(10494, 14521, 25996), -- 34289 (The Vortex)
(10493, 14520, 25996), -- 34292 (Arctanus)
(10495, 14523, 25996), -- 34290 (Core)
(10339, 14347, 25996), -- 33445 (Sentinel Avana)
(10341, 14351, 25996), -- 33454 (Sentinel Luara)
(10329, 14339, 25996), -- 11806 (Sentinel Onaeya)
(14982, 21179, 25996); -- Analynn
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=10339 AND `OptionIndex`=1) OR (`MenuId`=10341 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(10339, 1, 0, 'Sentinel, I would like to ride one of your nightsabers to Astranaar.', 33552, 25996),
(10341, 0, 0, 'Luara, I would like to take one of your nightsabers to Maestra''s Post.', 33588, 25996);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=10355, `VerifiedBuild`=25996 WHERE (`MenuId`=8077 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34856, `VerifiedBuild`=25996 WHERE (`MenuId`=10539 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34854, `VerifiedBuild`=25996 WHERE (`MenuId`=10537 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34586, `VerifiedBuild`=25996 WHERE (`MenuId`=10506 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34495, `VerifiedBuild`=25996 WHERE (`MenuId`=10494 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=4211 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33595, `VerifiedBuild`=25996 WHERE (`MenuId`=7367 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33552, `VerifiedBuild`=25996 WHERE (`MenuId`=10339 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=10539 AND `OptionIndex`=0) OR (`MenuId`=10537 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(10539, 0, 10538, 0),
(10537, 0, 10539, 0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=4211 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(4211, 0, 56);
DELETE FROM `gossip_menu` WHERE (`MenuId`=646 AND `TextId`=7016) OR (`MenuId`=657 AND `TextId`=7027) OR (`MenuId`=10486 AND `TextId`=14525) OR (`MenuId`=10486 AND `TextId`=14524);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(646, 7016, 25996), -- 5482 (Stephen Ryback)
(657, 7027, 25996), -- 56796 (Angela Leifeld)
(10486, 14525, 25996), -- 34301 (Kathrena Winterwisp)
(10486, 14524, 25996); -- 34301 (Kathrena Winterwisp)
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34514, `VerifiedBuild`=25996 WHERE (`MenuId`=10486 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34585, `VerifiedBuild`=25996 WHERE (`MenuId`=10509 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=10496 AND `TextId`=14526) OR (`MenuId`=10492 AND `TextId`=14518) OR (`MenuId`=10490 AND `TextId`=14517) OR (`MenuId`=10515 AND `TextId`=14547) OR (`MenuId`=10272 AND `TextId`=14264) OR (`MenuId`=10279 AND `TextId`=14276) OR (`MenuId`=10277 AND `TextId`=14274) OR (`MenuId`=10278 AND `TextId`=14275) OR (`MenuId`=10301 AND `TextId`=14304);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10496, 14526, 25996), -- 34301 (Kathrena Winterwisp)
(10492, 14518, 25996), -- 33072 (Onu)
(10490, 14517, 25996), -- 33072 (Onu)
(10515, 14547, 25996), -- 34403 (Felros)
(10272, 14264, 25996), -- 33001 (Thundris Windweaver)
(10279, 14276, 25996), -- 33037 (Caylais Moonfeather)
(10277, 14274, 25996), -- 33033 (Sentinel Elissa Starbreeze)
(10278, 14275, 25996), -- 33035 (Taldan)
(10301, 14304, 25996); -- 32912 (Sentinel Lendra)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=10490 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(10490, 0, 0, 'Ancient Onu, where may I find a Seed of the Earth?', 34486, 25996);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33186, `VerifiedBuild`=25996 WHERE (`MenuId`=10272 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33211, `VerifiedBuild`=25996 WHERE (`MenuId`=10279 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33207, `VerifiedBuild`=25996 WHERE (`MenuId`=10277 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=33209, `VerifiedBuild`=25996 WHERE (`MenuId`=10278 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=10486 AND `OptionIndex`=0) OR (`MenuId`=10490 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(10486, 0, 10496, 0),
(10490, 0, 10492, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=10432 AND `TextId`=14470) OR (`MenuId`=10431 AND `TextId`=14469) OR (`MenuId`=10430 AND `TextId`=14468) OR (`MenuId`=10410 AND `TextId`=14447) OR (`MenuId`=10491 AND `TextId`=14454) OR (`MenuId`=10416 AND `TextId`=14454) OR (`MenuId`=10427 AND `TextId`=14454) OR (`MenuId`=10482 AND `TextId`=14508) OR (`MenuId`=10290 AND `TextId`=14294) OR (`MenuId`=10294 AND `TextId`=14298) OR (`MenuId`=10287 AND `TextId`=14291) OR (`MenuId`=10296 AND `TextId`=14300) OR (`MenuId`=10286 AND `TextId`=14290) OR (`MenuId`=10288 AND `TextId`=14292) OR (`MenuId`=10289 AND `TextId`=14293) OR (`MenuId`=10295 AND `TextId`=14299) OR (`MenuId`=10292 AND `TextId`=14296) OR (`MenuId`=10291 AND `TextId`=14295) OR (`MenuId`=10293 AND `TextId`=14297) OR (`MenuId`=14257 AND `TextId`=4437) OR (`MenuId`=14256 AND `TextId`=4794) OR (`MenuId`=14255 AND `TextId`=5725) OR (`MenuId`=14258 AND `TextId`=17616) OR (`MenuId`=12458 AND `TextId`=17519);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10432, 14470, 25996), -- 33178 (Huntress Sandrya Moonfall)
(10431, 14469, 25996), -- 33178 (Huntress Sandrya Moonfall)
(10430, 14468, 25996), -- 34103 (Keynira Owlwing)
(10410, 14447, 25996), -- 194771
(10491, 14454, 25996), -- 33359 (Nightsaber Rider)
(10416, 14454, 25996), -- 33359 (Nightsaber Rider)
(10427, 14454, 25996), -- 33359 (Nightsaber Rider)
(10482, 14508, 25996), -- 32978 (Tharnariun Treetender)
(10290, 14294, 25996), -- 33100 (Valdaron)
(10294, 14298, 25996), -- 33094 (Volcor)
(10287, 14291, 25996), -- 33097 (Dalmond)
(10296, 14300, 25996), -- 32911 (Gershala Nightwhisper)
(10286, 14290, 25996), -- 33096 (Barithras Moonshade)
(10288, 14292, 25996), -- 33098 (Grondal Moonbreeze)
(10289, 14293, 25996), -- 33099 (Terenthis)
(10295, 14299, 25996), -- 33095 (Shaldyn)
(10292, 14296, 25996), -- 33103 (Mavralyn)
(10291, 14295, 25996), -- 33102 (Gwennyth Bly'Leggonde)
(10293, 14297, 25996), -- 33093 (Cerellean Whiteclaw)
(14257, 4437, 25996), -- 49940 (Irlara Morninglight)
(14256, 4794, 25996), -- 49939 (Kenral Nightwind)
(14255, 5725, 25996), -- 49923 (Sentinel Moonwing)
(14258, 17616, 25996), -- 49942 (Dular)
(12458, 17519, 25996); -- 48726 (Bielara Ivyshroud)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=10431 AND `OptionIndex`=0) OR (`MenuId`=10491 AND `OptionIndex`=0) OR (`MenuId`=10416 AND `OptionIndex`=0) OR (`MenuId`=10427 AND `OptionIndex`=0) OR (`MenuId`=14238 AND `OptionIndex`=8);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(10431, 0, 0, 'I am ready. Begin the attack.', 34222, 25996),
(10491, 0, 0, 'I''d like to travel to Lor''danel.', 34110, 25996),
(10416, 0, 0, 'I''d like to travel to the Ruins of Mathystra.', 34105, 25996),
(10427, 0, 0, 'I''d like to travel to the Bashal''Aran.', 34109, 25996),
(14238, 8, 0, 'Enter the Proving Grounds', 74757, 25996);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34044, `VerifiedBuild`=25996 WHERE (`MenuId`=10410 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34108, `VerifiedBuild`=25996 WHERE (`MenuId`=10428 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34110, `VerifiedBuild`=25996 WHERE (`MenuId`=10428 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=34110, `VerifiedBuild`=25996 WHERE (`MenuId`=10429 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=8521 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=4138 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=50849, `VerifiedBuild`=25996 WHERE (`MenuId`=12725 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=48895, `VerifiedBuild`=25996 WHERE (`MenuId`=12458 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=8521 AND `OptionIndex`=0) OR (`MenuId`=4138 AND `OptionIndex`=0) OR (`MenuId`=12725 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(8521, 0, 37),
(4138, 0, 407),
(12725, 0, 373);
DELETE FROM `gossip_menu` WHERE (`MenuId`=10804 AND `TextId`=14980) OR (`MenuId`=10802 AND `TextId`=14978) OR (`MenuId`=10803 AND `TextId`=14979) OR (`MenuId`=10798 AND `TextId`=14973) OR (`MenuId`=10672 AND `TextId`=14792) OR (`MenuId`=10674 AND `TextId`=14968) OR (`MenuId`=10735 AND `TextId`=14897) OR (`MenuId`=11775 AND `TextId`=14126) OR (`MenuId`=10779 AND `TextId`=14943) OR (`MenuId`=11776 AND `TextId`=14126) OR (`MenuId`=10715 AND `TextId`=14873) OR (`MenuId`=14987 AND `TextId`=21185) OR (`MenuId`=10674 AND `TextId`=14795) OR (`MenuId`=10680 AND `TextId`=14834) OR (`MenuId`=10703 AND `TextId`=14849) OR (`MenuId`=10680 AND `TextId`=14801) OR (`MenuId`=10639 AND `TextId`=14739);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10804, 14980, 25996), -- 36487 (Khan Shodo)
(10802, 14978, 25996), -- 36486 (Khan Leh'Prah)
(10803, 14979, 25996), -- 36485 (Khan Kammah)
(10798, 14973, 25996), -- 36398 (Khan Leh'Prah)
(10672, 14792, 25996), -- 35661 (Cenarion Embassador Thunk)
(10674, 14968, 25996), -- 35757 (Bizby)
(10735, 14897, 25996), -- 36034 (Karnum Marshweaver)
(11775, 14126, 25996), -- 36378 (Dumti)
(10779, 14943, 25996), -- 36329 (Thargad)
(11776, 14126, 25996), -- 36378 (Dumti)
(10715, 14873, 25996), -- 36056 (Khan Leh'Prah)
(14987, 21185, 25996), -- 66372 (Merda Stronghoof)
(10674, 14795, 25996), -- 35757 (Bizby)
(10680, 14834, 25996), -- 35773 (Cenarion Researcher Korrah)
(10703, 14849, 25996), -- 35902 (Lord Hydronis)
(10680, 14801, 25996), -- 35773 (Cenarion Researcher Korrah)
(10639, 14739, 25996); -- 195445
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=10798 AND `OptionIndex`=0) OR (`MenuId`=11775 AND `OptionIndex`=0) OR (`MenuId`=11776 AND `OptionIndex`=0) OR (`MenuId`=10715 AND `OptionIndex`=0) OR (`MenuId`=10703 AND `OptionIndex`=0) OR (`MenuId`=10680 AND `OptionIndex`=1) OR (`MenuId`=10680 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(10798, 0, 0, 'I am ready! I want to join in the battle!', 36414, 25996),
(11775, 0, 0, 'I want to browse your goods.', 3370, 25996),
(11776, 0, 1, 'I want to browse your goods.', 3370, 25996),
(10715, 0, 0, 'I am ready to do battle with the Magram clan!', 36165, 25996),
(10703, 0, 0, 'I am prepared to join you in battle, Hydronis!', 36079, 25996),
(10680, 1, 0, 'I need another Slitherblade Charm, Korrah.', 50632, 25996),
(10680, 0, 0, 'I am ready to be shown this threat you speak of, Korrah.', 35973, 25996);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=11775 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(11775, 0, 11776, 0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=11373 AND `TextId`=7778) OR (`MenuId`=11307 AND `TextId`=15761) OR (`MenuId`=11364 AND `TextId`=15838);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11373, 7778, 25996), -- 40367 (Seyala Nightwisp)
(11307, 15761, 25996), -- 39407 (Ysondre)
(11364, 15838, 25996); -- 39725 (Adella)
DELETE FROM `gossip_menu` WHERE (`MenuId`=11374 AND `TextId`=15845) OR (`MenuId`=11353 AND `TextId`=15821) OR (`MenuId`=11357 AND `TextId`=15828) OR (`MenuId`=11362 AND `TextId`=15835) OR (`MenuId`=11363 AND `TextId`=15836) OR (`MenuId`=14984 AND `TextId`=21183) OR (`MenuId`=11361 AND `TextId`=15834) OR (`MenuId`=11349 AND `TextId`=15816) OR (`MenuId`=11347 AND `TextId`=15808);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(11374, 15845, 25996), -- 40369 (Falfindel Waywarder)
(11353, 15821, 25996), -- 40913 (Handler Jesana)
(11357, 15828, 25996), -- 39653 (Silvia)
(11362, 15835, 25996), -- 40132 (Vestia Moonspear)
(11363, 15836, 25996), -- 40131 (Sensiria)
(14984, 21183, 25996), -- Traitor Gluk
(11361, 15834, 25996), -- 14637 (Zorbin Fandazzle)
(11349, 15816, 25996), -- 39723 (Tambre)
(11347, 15808, 25996); -- 40036 (Karonas)
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=9817, `VerifiedBuild`=25996 WHERE (`MenuId`=11361 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=43319, `VerifiedBuild`=25996 WHERE (`MenuId`=11349 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40212, `VerifiedBuild`=25996 WHERE (`MenuId`=11347 AND `OptionIndex`=0);
DELETE FROM `gossip_menu` WHERE (`MenuId`=18692 AND `TextId`=27173) OR (`MenuId`=11315 AND `TextId`=15771) OR (`MenuId`=11828 AND `TextId`=16585) OR (`MenuId`=11372 AND `TextId`=7778);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(18692, 27173, 25996), -- 96485 (Myshalla Streambreeze)
(11315, 15771, 25996), -- 40032 (Telaron Windflight)
(11828, 16585, 25996), -- 40035 (Erina Willowborn)
(11372, 7778, 25996); -- 40358 (Dyslix Silvergrub)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=11372 AND `OptionIndex`=2);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(11372, 2, 0, 'Dyslix, I need to get to New Thalanaar!', 40364, 25996);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=4164 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=4164 AND `OptionIndex`=0) OR (`MenuId`=4133 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(4164, 0, 62),
(4133, 0, 122);
DELETE FROM `gossip_menu` WHERE (`MenuId`=13027 AND `TextId`=18299) OR (`MenuId`=11370 AND `TextId`=15841) OR (`MenuId`=15007 AND `TextId`=21215) OR (`MenuId`=12850 AND `TextId`=18074) OR (`MenuId`=12847 AND `TextId`=18071) OR (`MenuId`=14123 AND `TextId`=4991) OR (`MenuId`=14252 AND `TextId`=18049) OR (`MenuId`=14122 AND `TextId`=3977) OR (`MenuId`=14297 AND `TextId`=16569) OR (`MenuId`=12842 AND `TextId`=18050) OR (`MenuId`=14291 AND `TextId`=12929) OR (`MenuId`=14251 AND `TextId`=18067);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(13027, 18299, 25996), -- 54674 (T'shu)
(11370, 15841, 25996), -- 40345 (Thyssiana)
(15007, 21215, 25996), -- Grazzle the Great
(12850, 18074, 25996), -- 53421 (Faena Woolybush)
(12847, 18071, 25996), -- 4894 (Craig Nollward)
(14123, 4991, 25996), -- 8141 (Captain Evencane)
(14252, 18049, 25996), -- 53403 (Allen Bright)
(14122, 3977, 25996), -- 8140 (Brother Karman)
(14297, 16569, 25996), -- 4892 (Jensen Farran)
(12842, 18050, 25996), -- 53409 ("Kobold" Kerik)
(14291, 12929, 25996), -- 27704 (Horace Alder)
(14251, 18067, 25996); -- 53404 (Redia Vaunt)
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=8851 AND `OptionIndex`=3) OR (`MenuId`=8851 AND `OptionIndex`=2) OR (`MenuId`=8851 AND `OptionIndex`=1) OR (`MenuId`=9123 AND `OptionIndex`=1) OR (`MenuId`=8846 AND `OptionIndex`=0) OR (`MenuId`=2465 AND `OptionIndex`=1) OR (`MenuId`=14297 AND `OptionIndex`=8) OR (`MenuId`=14291 AND `OptionIndex`=9) OR (`MenuId`=14291 AND `OptionIndex`=8);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(8851, 3, 0, 'Profession Trainer', 2869, 25996), -- OptionBroadcastTextID: 2869 - 3430 - 4896 - 5112 - 5352 - 5916 - 6635 - 6912 - 7022 - 7095 - 15250 - 19210 - 45382
(8851, 2, 0, 'Class Trainer', 2868, 25996), -- OptionBroadcastTextID: 2868 - 3429 - 4891 - 5088 - 5360 - 5915 - 6634 - 6911 - 6999 - 7078 - 15234 - 32202 - 45378
(8851, 1, 0, 'Bank', 3426, 25996), -- OptionBroadcastTextID: 3426 - 5908 - 6631 - 6907 - 6987 - 15214 - 19201 - 32167 - 44628 - 78584
(9123, 1, 1, 'I want to browse your goods.', 3370, 25996),
(8846, 0, 0, 'Can you send me to Theramore? I have an urgent message for Lady Jaina from King Wrynn.', 22524, 25996),
(2465, 1, 0, 'I''m ready to travel to Stormwind.', 22522, 25996),
(14297, 8, 1, 'How may I help you?', 30864, 25996), -- OptionBroadcastTextID: 30864 - 32778 - 32779 - 32780 - 53142 - 53144 - 58309 - 61023 - 61839 - 62303 - 98955 - 113783
(14291, 9, 0, 'I want to talk about the Arcane Momentum technique.', 125293, 25996),
(14291, 8, 0, 'Enter the Proving Grounds', 74757, 25996);
UPDATE `gossip_menu_option` SET `OptionIcon`=5, `OptionText`='Make this inn your home.', `OptionBroadcastTextId`=2822, `VerifiedBuild`=25996 WHERE (`MenuId`=9123 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12848 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12850 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12847 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12852 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12846 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12842 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44663, `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44649, `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12844 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=3266, `VerifiedBuild`=25996 WHERE (`MenuId`=12843 AND `OptionIndex`=0);
DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=8851 AND `OptionIndex`=3) OR (`MenuId`=1161 AND `OptionIndex`=0) OR (`MenuId`=8851 AND `OptionIndex`=2) OR (`MenuId`=8851 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(8851, 3, 12865, 0),
(1161, 0, 1162, 0),
(8851, 2, 12855, 0),
(8851, 1, 12854, 469);
DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=4355 AND `OptionIndex`=0) OR (`MenuId`=9581 AND `OptionIndex`=0) OR (`MenuId`=12848 AND `OptionIndex`=0) OR (`MenuId`=12850 AND `OptionIndex`=0) OR (`MenuId`=12852 AND `OptionIndex`=0) OR (`MenuId`=5382 AND `OptionIndex`=0) OR (`MenuId`=8826 AND `OptionIndex`=0) OR (`MenuId`=4122 AND `OptionIndex`=0) OR (`MenuId`=12843 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(4355, 0, 163),
(9581, 0, 144),
(12848, 0, 29),
(12850, 0, 373),
(12852, 0, 56),
(5382, 0, 160),
(8826, 0, 10),
(4122, 0, 122),
(12843, 0, 62);

UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=493;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=492;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=491;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=490;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=489;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=488;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=487;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=486;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=485;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=484;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=483;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=482;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=481;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=480;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=479;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=478;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=477;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=476;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=475;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=474;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=473;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=472;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=471;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=470;
UPDATE `points_of_interest` SET `VerifiedBuild`=25996 WHERE `ID`=469;
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7525 AND `TextId`=9125); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7521 AND `TextId`=9121); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8787 AND `TextId`=11243); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8788 AND `TextId`=11245); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8761 AND `TextId`=11126); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8801 AND `TextId`=11281); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8823 AND `TextId`=11365); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9123 AND `TextId`=12334); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8812 AND `TextId`=11311); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=2916 AND `TextId`=3590); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8811 AND `TextId`=11309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8830 AND `TextId`=11403); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8846 AND `TextId`=11469); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8837 AND `TextId`=11432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8793 AND `TextId`=11264); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12517 AND `TextId`=4837); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12848 AND `TextId`=18072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14247 AND `TextId`=15111); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12852 AND `TextId`=18076); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8840 AND `TextId`=11457); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=541 AND `TextId`=1058); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1162 AND `TextId`=1794); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5382 AND `TextId`=6415); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8835 AND `TextId`=11426); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8826 AND `TextId`=11376); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4357 AND `TextId`=5579); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8782 AND `TextId`=11224); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4355 AND `TextId`=5571); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4004 AND `TextId`=4859); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12846 AND `TextId`=18070); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10362 AND `TextId`=16705); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4122 AND `TextId`=5049); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8834 AND `TextId`=11424); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12879 AND `TextId`=18108); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12878 AND `TextId`=18107); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12877 AND `TextId`=18106); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12876 AND `TextId`=18105); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12875 AND `TextId`=18104); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12874 AND `TextId`=18103); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12873 AND `TextId`=18102); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12872 AND `TextId`=18101); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12871 AND `TextId`=18100); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12870 AND `TextId`=18099); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12869 AND `TextId`=18098); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12868 AND `TextId`=18097); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12867 AND `TextId`=18096); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12866 AND `TextId`=18095); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `TextId`=17774); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12864 AND `TextId`=18094); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12863 AND `TextId`=18093); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12862 AND `TextId`=18092); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12861 AND `TextId`=18091); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12860 AND `TextId`=18090); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12859 AND `TextId`=18089); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12858 AND `TextId`=18088); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12857 AND `TextId`=18087); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `TextId`=17774); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12854 AND `TextId`=18086); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8851 AND `TextId`=11492); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8762 AND `TextId`=11136); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=2465 AND `TextId`=3157); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5301 AND `TextId`=6333); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12844 AND `TextId`=18064); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12843 AND `TextId`=18063); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9581 AND `TextId`=12933); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10188 AND `TextId`=14128); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8782 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8851 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12848 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12850 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12847 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12852 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5382 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8826 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8826 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8762 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4355 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4004 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12846 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10362 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10362 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12842 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4122 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12865 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=7);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=6);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=5);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=4);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=3);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12855 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12844 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12843 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9581 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10188 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4164 AND `TextId`=5218); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4133 AND `TextId`=5104); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1802 AND `TextId`=2433); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4133 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11372 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1965 AND `TextId`=2639); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11361 AND `TextId`=7116); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11284 AND `TextId`=15719); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1965 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11373 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5303 AND `TextId`=6335); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5321 AND `TextId`=6353); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10778 AND `TextId`=14942); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8903 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3650 AND `TextId`=4449); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5302 AND `TextId`=6334); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8903 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10484 AND `TextId`=14510); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10479 AND `TextId`=14505); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10428 AND `TextId`=14454); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10429 AND `TextId`=14454); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6826 AND `TextId`=7956); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=347 AND `TextId`=824); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4301 AND `TextId`=5473); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7690 AND `TextId`=9384); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12726 AND `TextId`=17861); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8521 AND `TextId`=10654); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14239 AND `TextId`=5722); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14238 AND `TextId`=538); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10321 AND `TextId`=14327); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14991 AND `TextId`=20326); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8519 AND `TextId`=10652); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4138 AND `TextId`=5121); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12725 AND `TextId`=17859); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=347 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7690 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12726 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14238 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14991 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=14991 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8519 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10486 AND `TextId`=14511); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10499 AND `TextId`=14531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10498 AND `TextId`=14529); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11853 AND `TextId`=16615); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10516 AND `TextId`=14548); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10483 AND `TextId`=14509); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10268 AND `TextId`=14259); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10269 AND `TextId`=14260); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=688 AND `TextId`=1238); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=692 AND `TextId`=1242); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=657 AND `TextId`=1220); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10480 AND `TextId`=14506); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10509 AND `TextId`=14541); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=688 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=646 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=692 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=657 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7407 AND `TextId`=8876); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7405 AND `TextId`=8874); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8080 AND `TextId`=9986); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7406 AND `TextId`=8875); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7404 AND `TextId`=8873); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7382 AND `TextId`=8838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7410 AND `TextId`=8939); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6523 AND `TextId`=7725); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=2561 AND `TextId`=3233); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=361 AND `TextId`=838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5502 AND `TextId`=6553); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4211 AND `TextId`=5360); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6827 AND `TextId`=7956); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10312 AND `TextId`=14315); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10313 AND `TextId`=14316); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7410 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3626 AND `TextId`=4401); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3625 AND `TextId`=4399); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6801 AND `TextId`=8124); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6800 AND `TextId`=8123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12433 AND `TextId`=17484); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12353 AND `TextId`=17477); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12353 AND `TextId`=17357); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12706 AND `TextId`=17837); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6887 AND `TextId`=7956); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3074 AND `TextId`=3807); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9868 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3142 AND `TextId`=3874); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3621 AND `TextId`=4394); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3622 AND `TextId`=4393); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3626 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3626 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9868 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=9868 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3622 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3130 AND `TextId`=3854); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12502 AND `TextId`=17586); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=5482 AND `TextId`=6534); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3761 AND `TextId`=4573); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=2984 AND `TextId`=3673); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6089 AND `TextId`=7243); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6091 AND `TextId`=7247); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6090 AND `TextId`=7245); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6885 AND `TextId`=7935); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6092 AND `TextId`=7249); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6837 AND `TextId`=8143); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=8064 AND `TextId`=9964); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7238 AND `TextId`=8538); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6888 AND `TextId`=7956); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=2703 AND `TextId`=3375); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3802 AND `TextId`=4634); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3623 AND `TextId`=4396); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3624 AND `TextId`=4395); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12599 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=3624 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11500 AND `TextId`=16051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11506 AND `TextId`=16058); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11505 AND `TextId`=16057); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11504 AND `TextId`=16056); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11529 AND `TextId`=16094); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=342 AND `TextId`=820); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11527 AND `TextId`=16089); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10181 AND `TextId`=14126); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11518 AND `TextId`=16072); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11459 AND `TextId`=15979); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11453 AND `TextId`=15970); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1581 AND `TextId`=824); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11465 AND `TextId`=15991); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11467 AND `TextId`=15995); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=7367 AND `TextId`=8802); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4302 AND `TextId`=5474); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=342 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=342 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10181 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1581 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1581 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=4302 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1161 AND `TextId`=1793); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11012 AND `TextId`=15315); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=1161 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11027 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11025 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11024 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=25996 WHERE (`MenuId`=10941 AND `OptionIndex`=1);
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12331 AND `TextId`=17328); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11993 AND `TextId`=16812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=12260 AND `TextId`=17221); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11472 AND `TextId`=16004); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11435 AND `TextId`=15932); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11403 AND `TextId`=15887); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11392 AND `TextId`=15867); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=25996 WHERE (`MenuId`=11408 AND `TextId`=15893); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8124 AND `TextId`=10062); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=900 AND `TextId`=1471); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7524 AND `TextId`=9124); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1301 AND `TextId`=1934); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2242 AND `TextId`=2954); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4152 AND `TextId`=5177); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4746 AND `TextId`=5798); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1469 AND `TextId`=2138); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7083 AND `TextId`=8335); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6094 AND `TextId`=7251); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2890 AND `TextId`=3566); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6831 AND `TextId`=7935); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7239 AND `TextId`=8539); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8064 AND `TextId`=9964); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8124 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=900 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7524 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1301 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2242 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4152 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4746 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9821 AND `OptionIndex`=3);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6646 AND `TextId`=7902); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11069 AND `TextId`=15394); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11876 AND `TextId`=16644); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8072 AND `TextId`=9978); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7712 AND `TextId`=9414); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8059 AND `TextId`=9954); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8058 AND `TextId`=9953); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8057 AND `TextId`=9951); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8234 AND `TextId`=10237); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6539 AND `TextId`=7742); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1143 AND `TextId`=1759); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1142 AND `TextId`=1758); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11180 AND `TextId`=15561); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11402 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8072 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7712 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8059 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8058 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8058 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8057 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1142 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12644 AND `TextId`=17789); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6911 AND `TextId`=7935); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6944 AND `TextId`=7778); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2081 AND `TextId`=2734); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2422 AND `TextId`=3094); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8903 AND `TextId`=11714); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2184 AND `TextId`=2817); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2852 AND `TextId`=3546); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2424 AND `TextId`=3096); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2423 AND `TextId`=3095); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7956 AND `TextId`=9774); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2188 AND `TextId`=2821); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2188 AND `TextId`=2816); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6944 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11060 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=11036 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2179 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10982 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=10980 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8903 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=2178 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=699 AND `TextId`=1250); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=688 AND `TextId`=1238); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=646 AND `TextId`=7017); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=684 AND `TextId`=1234); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4353 AND `TextId`=5561); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6561 AND `TextId`=7770); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6692 AND `TextId`=8065); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6552 AND `TextId`=7768); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6553 AND `TextId`=7767); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6554 AND `TextId`=7766); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6555 AND `TextId`=7765); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6556 AND `TextId`=7764); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6557 AND `TextId`=7763); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6558 AND `TextId`=7762); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6545 AND `TextId`=7761); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6546 AND `TextId`=7760); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6547 AND `TextId`=7759); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6548 AND `TextId`=7758); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6549 AND `TextId`=7757); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6550 AND `TextId`=7756); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6551 AND `TextId`=7755); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6534 AND `TextId`=7736); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6533 AND `TextId`=7735); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6596 AND `TextId`=7816); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6923 AND `TextId`=8212); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6623 AND `TextId`=7874); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5703 AND `TextId`=6870); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5704 AND `TextId`=6869); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5701 AND `TextId`=6868); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5702 AND `TextId`=6867); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5687 AND `TextId`=6844); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5688 AND `TextId`=6843); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5689 AND `TextId`=6842); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5675 AND `TextId`=6812); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6530 AND `TextId`=7732); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6526 AND `TextId`=7728); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6583 AND `TextId`=7839); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6564 AND `TextId`=7779); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6532 AND `TextId`=7734); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6529 AND `TextId`=7731); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6528 AND `TextId`=7730); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6796 AND `TextId`=8114); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6544 AND `TextId`=7753); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7045 AND `TextId`=8280); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6525 AND `TextId`=7727); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6527 AND `TextId`=7729); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7418 AND `TextId`=8960); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6567 AND `TextId`=7782); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6531 AND `TextId`=7733); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6585 AND `TextId`=7804); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6586 AND `TextId`=7803); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6587 AND `TextId`=7802); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6588 AND `TextId`=7801); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5103 AND `TextId`=6155); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=699 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=688 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=646 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=684 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4353 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6561 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6552 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6553 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6554 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6555 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6556 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6557 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6558 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6533 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6545 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6546 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6547 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6548 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6549 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6550 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6551 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6534 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5704 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5701 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5687 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5688 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5689 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=5675 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6526 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6528 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6527 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6586 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6587 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=6588 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8213 AND `TextId`=10239); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7561 AND `TextId`=9179); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7399 AND `TextId`=8865); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7400 AND `TextId`=8868); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7426 AND `TextId`=8978); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8519 AND `TextId`=10652); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7389 AND `TextId`=8850); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7388 AND `TextId`=8849); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7399 AND `TextId`=8864); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7398 AND `TextId`=8861); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7400 AND `TextId`=8867); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7428 AND `TextId`=8990); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7434 AND `TextId`=8997); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7433 AND `TextId`=8996); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7431 AND `TextId`=8993); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7432 AND `TextId`=8994); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7429 AND `TextId`=8991); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7430 AND `TextId`=8992); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7424 AND `TextId`=8973); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7423 AND `TextId`=8972); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7370 AND `TextId`=8806); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7690 AND `TextId`=9384); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=1221 AND `TextId`=1853); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7468 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7383 AND `TextId`=8840); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7384 AND `TextId`=8844); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7380 AND `TextId`=7026); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7382 AND `TextId`=8838); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `TextId`=17138); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `TextId`=17137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `TextId`=17136); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `TextId`=17135); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `TextId`=17134); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `TextId`=17133); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `TextId`=17132); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `TextId`=17131); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `TextId`=17127); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `TextId`=17130); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `TextId`=17129); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `TextId`=17128); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `TextId`=17126); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12180 AND `TextId`=17125); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14991 AND `TextId`=20326); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7368 AND `TextId`=8823); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=4783 AND `TextId`=5839); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7361 AND `TextId`=8793); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7303 AND `TextId`=8662); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7353 AND `TextId`=8776); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7355 AND `TextId`=8780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7286 AND `TextId`=8616); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7353 AND `TextId`=8775); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8093 AND `TextId`=10008); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8097 AND `TextId`=10012); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7469 AND `TextId`=9052); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7426 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8519 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7389 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7389 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7388 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7388 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7428 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7429 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7430 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7690 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7468 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7468 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7383 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7383 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7384 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7380 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12199 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12198 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12197 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12196 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12195 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12193 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12192 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12191 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=19);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=18);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=17);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12186 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12190 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=16);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12189 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=15);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12188 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=14);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=13);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12185 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12180 AND `OptionIndex`=12);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12180 AND `OptionIndex`=11);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12180 AND `OptionIndex`=10);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=12180 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14991 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14991 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7361 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7361 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7469 AND `OptionIndex`=0);
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=13920 AND `TextId`=538); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7501 AND `TextId`=9097); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7547 AND `TextId`=9163); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7466 AND `TextId`=9045); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7523 AND `TextId`=9123); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7835 AND `TextId`=9591); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7539 AND `TextId`=9143); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7538 AND `TextId`=9142); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8298 AND `TextId`=10352); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7474 AND `TextId`=9060); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7475 AND `TextId`=9059); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7476 AND `TextId`=9058); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7477 AND `TextId`=9057); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7478 AND `TextId`=9056); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7471 AND `TextId`=9054); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7457 AND `TextId`=9032); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7456 AND `TextId`=9031); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7454 AND `TextId`=9030); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7453 AND `TextId`=9028); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7533 AND `TextId`=9141); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7534 AND `TextId`=9140); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7535 AND `TextId`=9139); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7536 AND `TextId`=9138); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7537 AND `TextId`=9137); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7531 AND `TextId`=9136); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7458 AND `TextId`=9033); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7490 AND `TextId`=9082); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7491 AND `TextId`=9081); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7492 AND `TextId`=9080); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7493 AND `TextId`=9079); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7449 AND `TextId`=9022); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7531 AND `TextId`=9134); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14146 AND `TextId`=8589); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7455 AND `TextId`=9029); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7833 AND `TextId`=9586); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7465 AND `TextId`=9044); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7489 AND `TextId`=9077); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7517 AND `TextId`=9117); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7452 AND `TextId`=9025); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7832 AND `TextId`=9584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7460 AND `TextId`=9036); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7595 AND `TextId`=9246); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7575 AND `TextId`=9206); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7557 AND `TextId`=9172); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7463 AND `TextId`=9042); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14158 AND `TextId`=8785); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7459 AND `TextId`=9034); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7464 AND `TextId`=9043); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7497 AND `TextId`=9051); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7399 AND `TextId`=9038); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7370 AND `TextId`=9040); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7434 AND `TextId`=9039); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8243 AND `TextId`=10258); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7462 AND `TextId`=9041); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7461 AND `TextId`=9037); -- 0
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=13920 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=13920 AND `OptionIndex`=8);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8298 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7475 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7476 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7477 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7478 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7471 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7533 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7534 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7535 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7536 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7537 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7531 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=14146 AND `OptionIndex`=9);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7557 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9821 AND `OptionIndex`=2);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=9821 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=7497 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=26124 WHERE (`MenuId`=8243 AND `OptionIndex`=0);
