-- 
UPDATE `quest_template` SET `RewardMoney`=-20000 WHERE `ID` IN (3644,3645,3646,3647);
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` IN (3644,3645,3646,3647);
INSERT INTO `disables` (`sourceType`,`entry`, `comment`) VALUES
(1, 3644, "Depracted quest Membership Card Renewal"),
(1, 3645, "Depracted quest Membership Card Renewal"),
(1, 3646, "Depracted quest Membership Card Renewal"),
(1, 3647, "Depracted quest Membership Card Renewal");
