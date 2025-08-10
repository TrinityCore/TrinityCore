SET @NPCTEXTID := 580005;

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 130589, 0, 0, 0, 0, 0, 0, 0, 47213), -- 120928 (Jay Maguire)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 205229, 0, 0, 0, 0, 0, 0, 0, 47213); -- 174035 (Dro Seminario)

DELETE FROM `gossip_menu` WHERE (`MenuID`=21057 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=26433 AND `TextID`=@NPCTEXTID+1) OR (`MenuID` = 21057 AND `TextID`=7956);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21057, @NPCTEXTID+0, 47213), -- 120928 (Jay Maguire)
(26433, @NPCTEXTID+1, 47213); -- 174035 (Dro Seminario)

UPDATE `gossip_menu` SET `VerifiedBuild`=47213 WHERE (`MenuID`=5665 AND `TextID`=6961);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 21057 AND `OptionID` IN (1, 2);
UPDATE `gossip_menu_option` SET `GossipOptionID`=29500, `VerifiedBuild`=47213 WHERE (`MenuID`=5665 AND `OptionID`=0);

DELETE FROM `npc_vendor` WHERE (`entry`=56069 AND `item`=6533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6529 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=136377 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=82449 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=82448 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=58263 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=58262 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=35951 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=33451 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=27858 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=8957 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=21552 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=4594 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=4593 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=4592 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=787 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6330 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=56069 AND `item`=6325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=55103 AND `item`=142398 AND `ExtendedCost`=6130 AND `type`=1) OR (`entry`=55103 AND `item`=126930 AND `ExtendedCost`=5881 AND `type`=1) OR (`entry`=55103 AND `item`=126926 AND `ExtendedCost`=5881 AND `type`=1) OR (`entry`=55103 AND `item`=126925 AND `ExtendedCost`=5880 AND `type`=1) OR (`entry`=55103 AND `item`=184689 AND `ExtendedCost`=5880 AND `type`=1) OR (`entry`=55103 AND `item`=126929 AND `ExtendedCost`=5880 AND `type`=1) OR (`entry`=55103 AND `item`=124671 AND `ExtendedCost`=5879 AND `type`=1) OR (`entry`=55103 AND `item`=184625 AND `ExtendedCost`=5879 AND `type`=1) OR (`entry`=55103 AND `item`=126927 AND `ExtendedCost`=5879 AND `type`=1) OR (`entry`=55103 AND `item`=126931 AND `ExtendedCost`=5879 AND `type`=1) OR (`entry`=55103 AND `item`=184683 AND `ExtendedCost`=5878 AND `type`=1) OR (`entry`=55103 AND `item`=126928 AND `ExtendedCost`=5878 AND `type`=1) OR (`entry`=55103 AND `item`=124674 AND `ExtendedCost`=5877 AND `type`=1) OR (`entry`=121542 AND `item`=19222 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=121542 AND `item`=147776 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=121542 AND `item`=147777 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151601 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151600 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151603 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151602 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=123735 AND `item`=151257 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=121543 AND `item`=147774 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(56069, 57, 6533, 2, 0, 1, 0, 0, 47213), -- Aquadynamic Fish Attractor
(56069, 56, 6532, 0, 0, 1, 0, 0, 47213), -- Bright Baubles
(56069, 55, 6530, 0, 0, 1, 0, 0, 47213), -- Nightcrawlers
(56069, 54, 6529, 0, 0, 1, 0, 0, 47213), -- Shiny Bauble
(56069, 53, 136377, 0, 0, 1, 0, 0, 47213), -- Oversized Bobber
(56069, 52, 6256, 0, 0, 1, 0, 0, 47213), -- Fishing Pole
(56069, 20, 82449, 0, 0, 1, 0, 0, 47213), -- Barnacle Bouillabaisse
(56069, 19, 82448, 0, 0, 1, 0, 0, 47213), -- Smoked Squid Belly
(56069, 18, 58263, 0, 0, 1, 0, 0, 47213), -- Grilled Shark
(56069, 17, 58262, 0, 0, 1, 0, 0, 47213), -- Sliced Raw Billfish
(56069, 16, 35951, 0, 0, 1, 0, 0, 47213), -- Poached Emperor Salmon
(56069, 15, 33451, 0, 0, 1, 0, 0, 47213), -- Fillet of Icefin
(56069, 14, 27858, 0, 0, 1, 0, 0, 47213), -- Sunspring Carp
(56069, 13, 8957, 0, 0, 1, 0, 0, 47213), -- Spinefin Halibut
(56069, 12, 21552, 0, 0, 1, 0, 0, 47213), -- Striped Yellowtail
(56069, 11, 4594, 0, 0, 1, 0, 0, 47213), -- Rockscale Cod
(56069, 10, 4593, 0, 0, 1, 0, 0, 47213), -- Bristle Whisker Catfish
(56069, 9, 4592, 0, 0, 1, 0, 0, 47213), -- Longjaw Mud Snapper
(56069, 8, 787, 0, 0, 1, 0, 0, 47213), -- Slitherskin Mackerel
(56069, 7, 6330, 0, 0, 1, 0, 0, 47213), -- Recipe: Bristle Whisker Catfish
(56069, 6, 6325, 0, 0, 1, 0, 0, 47213), -- Recipe: Brilliant Smallfish
(55103, 13, 142398, 0, 6130, 1, 0, 0, 47213), -- Darkwater Skate
(55103, 12, 126930, 0, 5881, 1, 0, 0, 47213), -- Faded Treasure Map
(55103, 11, 126926, 0, 5881, 1, 0, 0, 47213), -- Translucent Shell
(55103, 10, 126925, 0, 5880, 1, 0, 0, 47213), -- Blorp's Bubble
(55103, 9, 184689, 0, 5880, 1, 0, 0, 47213), -- Recipe: Extra Fancy Darkmoon Feast
(55103, 8, 126929, 0, 5880, 1, 0, 0, 47213), -- Recipe: Fancy Darkmoon Feast
(55103, 7, 124671, 0, 5879, 1, 0, 0, 47213), -- Darkmoon Firewater
(55103, 6, 184625, 0, 5879, 1, 0, 0, 47213), -- Recipe: Extra Sugary Fish Feast
(55103, 5, 126927, 0, 5879, 1, 0, 0, 47213), -- Recipe: Sugar-Crusted Fish Feast
(55103, 4, 126931, 0, 5879, 1, 0, 0, 47213), -- Seafarer's Slidewhistle
(55103, 3, 184683, 0, 5878, 1, 0, 0, 47213), -- Recipe: Extra Lemony Herb Filet
(55103, 2, 126928, 0, 5878, 1, 0, 0, 47213), -- Recipe: Lemon Herb Filet
(55103, 1, 124674, 0, 5877, 1, 0, 0, 47213), -- Day-Old Darkmoon Doughnut
(121542, 3, 19222, 0, 0, 1, 0, 0, 47213), -- Cheap Beer
(121542, 2, 147776, 0, 0, 1, 0, 0, 47213), -- "Killer" Brew
(121542, 1, 147777, 0, 0, 1, 0, 0, 47213), -- P.B.I.T.
(123735, 9, 151601, 0, 0, 1, 0, 0, 47213), -- Blighthead Romero Mask
(123735, 8, 151600, 0, 0, 1, 0, 0, 47213), -- Blighthead Mohawk Mask
(123735, 7, 151599, 0, 0, 1, 0, 0, 47213), -- Blighthead Slack-Jaw Mask
(123735, 6, 151603, 0, 0, 1, 0, 0, 47213), -- Blighthead Grim Smile Mask
(123735, 5, 151604, 0, 0, 1, 0, 0, 47213), -- Blighthead Bitter Wounds Mask
(123735, 4, 151602, 0, 0, 1, 0, 0, 47213), -- Blighthead Electric Beehive Mask
(123735, 3, 151605, 0, 0, 1, 0, 0, 47213), -- Devlynn Styx Mask
(123735, 2, 151256, 0, 0, 1, 0, 0, 47213), -- Purple Dance Stick
(123735, 1, 151257, 0, 0, 1, 0, 0, 47213), -- Green Dance Stick
(121543, 1, 147774, 0, 0, 1, 0, 0, 47213); -- Hunk of Mystery Meat

DELETE FROM `creature_trainer` WHERE (`CreatureID`=56068 AND `MenuID`=5665 AND `OptionID`=29500);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(56068, 10, 5665, 29500);