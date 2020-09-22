DELETE FROM `gossip_menu_option` WHERE (`MenuId`=1970 AND `OptionIndex`=1) OR (`MenuId`=11613 AND `OptionIndex`=0) OR (`MenuId`=5108 AND `OptionIndex`=1) OR (`MenuId`=5108 AND `OptionIndex`=0) OR (`MenuId`=11665 AND `OptionIndex`=1) OR (`MenuId`=11661 AND `OptionIndex`=1) OR (`MenuId`=11661 AND `OptionIndex`=0) OR (`MenuId`=13352 AND `OptionIndex`=1) OR (`MenuId`=5739 AND `OptionIndex`=1) OR (`MenuId`=4004 AND `OptionIndex`=1) OR (`MenuId`=7484 AND `OptionIndex`=1) OR (`MenuId`=7484 AND `OptionIndex`=0) OR (`MenuId`=11044 AND `OptionIndex`=0) OR (`MenuId`=10978 AND `OptionIndex`=2) OR (`MenuId`=10978 AND `OptionIndex`=1) OR (`MenuId`=10331 AND `OptionIndex`=1) OR (`MenuId`=10331 AND `OptionIndex`=0) OR (`MenuId`=10780 AND `OptionIndex`=1) OR (`MenuId`=10680 AND `OptionIndex`=0) OR (`MenuId`=12763 AND `OptionIndex`=1) OR (`MenuId`=11037 AND `OptionIndex`=0) OR (`MenuId`=2177 AND `OptionIndex`=0) OR (`MenuId`=9217 AND `OptionIndex`=0) OR (`MenuId`=12193 AND `OptionIndex`=10) OR (`MenuId`=12186 AND `OptionIndex`=10) OR (`MenuId`=12180 AND `OptionIndex`=10) OR (`MenuId`=12185 AND `OptionIndex`=10) OR (`MenuId`=12834 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(1970, 1, 0, 'You\'re good for nothing, Ribbly.  It\'s time to pay for your wickedness!', 4972, 15211),
(11613, 0, 0, 'I would like to start the Blood Ritual, Kasim.', 42213, 15211),
(5108, 1, 8, 'I want to create a guild crest.', 3415, 15211),
(5108, 0, 7, 'How do I form a guild?', 3413, 15211),
(11665, 1, 0, 'I\'ve brought some food for you.', 42793, 15211),
(11661, 1, 0, 'I am ready for the Mind Control ritual, Hu\'rala.', 42797, 15211),
(11661, 0, 0, 'I am ready for the Mind Vision ritual, Hu\'rala.', 42752, 15211),
(13352, 1, 0, 'Teleport me to the cannon.', 56548, 15211),
(5739, 1, 0, 'So, now that I\'m the king... what have you got for me?!', 9451, 15211),
(4004, 1, 1, 'I would like to buy from you.', 2583, 15211), -- OptionBroadcastTextID: 2583 - 6399 - 7142 - 9992 - 14967
(7484, 1, 8, 'I want to create a guild crest.', 3415, 15211),
(7484, 0, 7, 'How do I form a guild?', 3413, 15211),
(11044, 0, 0, 'Could you transport me to the pylon up above?', 38439, 15211),
(10978, 2, 0, 'Maximillian, I am ready for more adventure.', 38254, 15211),
(10978, 1, 0, 'Maximillian, I am ready for adventure.', 38164, 15211),
(10331, 1, 0, 'I am ready to accompany you to Splintertree, Kadrak!', 34040, 15211),
(10331, 0, 0, 'Truun is in need of lumber from the Warsong Camp. I need to use Brutusk to haul it.', 33514, 15211),
(10780, 1, 0, 'Tell me again about Azsharite?', 36365, 15211),
(10680, 0, 0, 'I am ready to be shown this threat you speak of, Korrah.', 35973, 15211),
(12763, 1, 0, 'I am ready to meet Nozdormu at the End Time.', 56606, 15211), -- OptionBroadcastTextID: 56606 - 56607
(11037, 0, 0, 'I\'m ready to go to The Shaper\'s Terrace.', 38396, 15211),
(2177, 0, 0, 'Examine the pylon.', 5152, 15211),
(9217, 0, 0, 'What do you know about the Cult of the Damned?', 25237, 15211),
(12193, 10, 3, 'Train me in Tailoring.', 47118, 15211),
(12186, 10, 3, 'Train me in Tailoring.', 47118, 15211),
(12180, 10, 3, 'Train me in Tailoring.', 47118, 15211),
(12185, 10, 3, 'Train me in Tailoring.', 47118, 15211),
(12834, 0, 0, 'I am ready to take part in the ceremony, Hallegosa.', 51883, 15211);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 49050, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12459) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 48889, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12451) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 48459, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12409) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47620, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12266) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47614, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12266) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47602, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12260) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47556, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12247) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 44526, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12227) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 47016, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12165) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46718, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12143) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46648, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12139) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46426, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12116) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46424, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12115) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46422, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12114) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 46420, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12113) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 45717, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 12042) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 43720, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11916) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 45131, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11909) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 44744, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11874) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 44744, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11874) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11822) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 42895, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11669) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 42795, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11666) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 42792, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11665) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 42790, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11664) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11435) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40732, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11435) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40647, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11428) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40429, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11386) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40372, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11373) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 43319, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11349) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40131, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11339) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 39545, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11238) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38756, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11093) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38472, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11059) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38473, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11058) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38474, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11057) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38475, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11056) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38476, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11055) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38410, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11054) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38409, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11043) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38415, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11042) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38410, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11041) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38415, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11040) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38408, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11039) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38415, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11038) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38397, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11037) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38393, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 11036) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38187, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10994) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38339, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10994) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 38340, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10994) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37960, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10989) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 11072, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10986) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37969, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10981) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37965, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10980) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37962, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10979) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37975, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10978) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 40429, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10976) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 37885, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10974) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 36427, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10801) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10659) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35898, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10658) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35783, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10646) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35781, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10645) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35779, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10644) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35777, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10643) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 35679, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10641) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 33592, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10342) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 33545, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 10338) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 31296, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9971) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 30634, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9860) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 30634, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9855) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 29212, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9761) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9427) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 25042, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9190) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 24901, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9182) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 9112) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 53903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7989) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 53903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7988) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 53903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7987) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 53903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7986) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 53903, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7985) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 2822, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7896) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 15285, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7673) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 15287, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7672) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 15289, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7671) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 15283, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7669) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 14741, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7560) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 14739, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7559) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 14258, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7448) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 11072, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 7438) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 10553, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 6484) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9480, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5744) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9342, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9319, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9317, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9343, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9320, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9318, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5692) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9261, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 7);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9260, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9259, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 5);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9257, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9256, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9255, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9254, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5674) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 8579, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5673) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 8586, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5673) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9236, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5669) AND (`OptionIndex` = 6);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9237, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5669) AND (`OptionIndex` = 4);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9105, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5669) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 8814, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5669) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9235, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5669) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9368, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5667) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9103, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5602) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 8764, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5146) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9292, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5003) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9292, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 5002) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9231, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 3781) AND (`OptionIndex` = 3);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9229, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 3781) AND (`OptionIndex` = 2);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9230, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 3781) AND (`OptionIndex` = 1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 9310, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 3781) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 22086, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 2101) AND (`OptionIndex` = 0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId` = 4977, `VerifiedBuild` = 15211 WHERE  (`MenuId` = 2001) AND (`OptionIndex` = 0);
