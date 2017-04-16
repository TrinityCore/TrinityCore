-- Add Missing Gossip Menus
DELETE FROM `gossip_menu` WHERE `entry` IN (15727,15730);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(15727,22587),(15730,22590);

DELETE FROM `npc_text` WHERE `ID` IN (17760,17831,17835,17965,17966,20036,22593,22587,22590);
INSERT INTO `npc_text` (`ID`,   `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `text1_0`, `text1_1`, `BroadcastTextID1`, `lang1`, `Probability1`, `VerifiedBuild`) VALUES
( 17760, '', '', 7090,  0, 0, '', '', 7090, 0, 0, 0),
( 17831, '', '', 50741, 0, 0, '', '', 0, 0, 0, 0),
( 17835, '', '', 50746, 0, 0, '', '', 0, 0, 0, 0),
( 17965, '', '', 51349, 0, 0, '', '', 0, 0, 0, 0),
( 17966, '', '', 51344, 0, 0, '', '', 0, 0, 0, 0),
( 20036, '', '', 61842, 0, 0, '', '', 0, 0, 0, 0),
( 22593, '', '', 74285, 0, 0, '', '', 0, 0, 0, 0),
( 22587, '', '', 74264, 0, 0, '', '', 0, 0, 0, 0),
( 22590, '', '', 74282, 0, 0, '', '', 0, 0, 0, 0);
