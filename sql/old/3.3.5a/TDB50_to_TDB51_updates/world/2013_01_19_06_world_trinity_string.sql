DELETE FROM `trinity_string` WHERE `entry` BETWEEN 820 AND 842;
INSERT INTO `trinity_string`(`entry`,`content_default`) VALUES
(820,'* has gossip (%u)'),
(821,'* is quest giver (%u)'),
(822,'* is class trainer (%u)'),
(823,'* is profession trainer(%u)'),
(824,'* is ammo vendor (%u)'),
(825,'* is food vendor(%u)'),
(826,'* is poison vendor (%u)'),
(827,'* is reagent vendor (%u)'),
(828,'* can repair (%u)'),
(829,'* is flight master (%u)'),
(830,'* is spirit healer (%u)'),
(831,'* is spirit guide (%u)'),
(832,'* is innkeeper (%u)'),
(833,'* is banker (%u)'),
(834,'* is petitioner (%u)'),
(835,'* is tabard designer (%u)'),
(836,'* is battle master (%u)'),
(837,'* is auctioneer (%u)'),
(838,'* is stable master (%u)'),
(839,'* is guild banker (%u)'),
(840,'* has spell click (%u)'),
(841,'* is mailbox (%u)'),
(842,'* is player vehicle (%u)');

UPDATE `trinity_string` SET `content_default`='* is vendor (%u)' WHERE `entry`=545;
UPDATE `trinity_string` SET `content_default`='* is trainer (%u)' WHERE `entry`=546;
