-- Sniff Data Start
DELETE FROM `npc_vendor` WHERE (`entry`=54442 AND `item`=164378 AND `ExtendedCost`=6444 AND `type`=1) OR (`entry`=54442 AND `item`=168061 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=54442 AND `item`=168060 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=54442 AND `item`=168059 AND `ExtendedCost`=6188 AND `type`=1) OR (`entry`=54442 AND `item`=168058 AND `ExtendedCost`=6188 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54442, 5, 164378, 0, 6444, 1, 0, 0, 40120),
(54442, 4, 168061, 0, 6188, 1, 9206, 0, 40120),
(54442, 3, 168060, 0, 6188, 1, 4617, 0, 40120),
(54442, 2, 168059, 0, 6188, 1, 0, 0, 40120),
(54442, 1, 168058, 0, 6188, 1, 4619, 0, 40120);

DELETE FROM `npc_vendor` WHERE `entry`=54473;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(54473, 14, 151116, 0, 6211, 1, 50225, 0, 40120),
(54473, 13, 151120, 0, 6188, 1, 9206, 0, 40120),
(54473, 12, 151119, 0, 6188, 1, 4617, 0, 40120),
(54473, 11, 151118, 0, 6188, 1, 0, 0, 40120),
(54473, 10, 151117, 0, 6188, 1, 4619, 0, 40120),
(54473, 9, 157577, 0, 6188, 1, 9206, 0, 40120),
(54473, 8, 157576, 0, 6188, 1, 4617, 0, 40120),
(54473, 7, 157574, 0, 6188, 1, 0, 0, 40120),
(54473, 6, 157573, 0, 6188, 1, 4619, 0, 40120),
(54473, 5, 164378, 0, 6444, 1, 0, 0, 40120),
(54473, 4, 168061, 0, 6188, 1, 9206, 0, 40120),
(54473, 3, 168060, 0, 6188, 1, 4617, 0, 40120),
(54473, 2, 168059, 0, 6188, 1, 0, 0, 40120),
(54473, 1, 168058, 0, 6188, 1, 4619, 0, 40120);

UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=151116 AND `ExtendedCost`=6211 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=151120 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=151119 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=11, `PlayerConditionID`=0, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=151118 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=10, `PlayerConditionID`=4619, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=151117 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=157577 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=157576 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=7, `PlayerConditionID`=0, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=157574 AND `ExtendedCost`=6188 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=6, `PlayerConditionID`=4619, `VerifiedBuild`=40120 WHERE (`entry`=54442 AND `item`=157573 AND `ExtendedCost`=6188 AND `type`=1);

UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=13348 AND `TextId`=18280);
UPDATE `gossip_menu` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21043 AND `TextId`=31799);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21043 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=40120 WHERE (`MenuId`=21043 AND `OptionIndex`=0);
-- Sniff Data End

-- My Fixes Start
UPDATE `gossip_menu_option` SET `OptionIcon` = 34, `OptionType` = 20, `OptionNpcFlag` = 268435456 WHERE `MenuId` = 21043 AND `OptionIndex` = 0;
UPDATE `gossip_menu_option` SET `OptionType` = 3, `OptionNpcFlag` = 128 WHERE `MenuId` = 21043 AND `OptionIndex` = 1;

DELETE FROM `gossip_menu_option` WHERE `MenuId` = 21043 AND `OptionIndex` = 2;

UPDATE `creature_template` SET `gossip_menu_id`=21043, `npcflag`=268435585 WHERE `entry` IN (54442, 54473);
-- My Fixes End
