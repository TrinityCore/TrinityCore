-- Shadi Mistrunner - selling Shiny Bauble (item 6529)
DELETE FROM `npc_vendor` WHERE `entry` = 8363 AND `item` = 6529;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`,`VerifiedBuild`) VALUES
(8363, 0, 6529, 0, 0, 0, 0);
