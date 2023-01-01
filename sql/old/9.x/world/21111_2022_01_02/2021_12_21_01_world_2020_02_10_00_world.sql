--
UPDATE `npc_text` SET /*`Text0_0`="You can find our mana loom in the merchant's bazaar within the Lower City.", `Text0_1`="You can find our mana loom in the merchant's bazaar within the Lower City.", `Emote0_0`=1,*/ `BroadcastTextID0`=19591, `Probability0`=1 WHERE `id`=10503;
-- UPDATE `gossip_menu_option` SET `ActionMenuID`=8418 WHERE `MenuID`=8403 AND `OptionID`=6;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID`=8410 WHERE `MenuID`=8357 AND `OptionIndex`=8;

DELETE FROM `npc_text` WHERE `ID` IN (10515, 724001, 724002, 724003, 724004, 724005, 2981);
INSERT INTO `npc_text` (`ID`, `Probability0`, `BroadcastTextID0`) VALUES
(10515, 1, 41148);

DELETE FROM `gossip_menu` WHERE `MenuID`=8410 AND `TextID`=10515;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES (8410,10515);
