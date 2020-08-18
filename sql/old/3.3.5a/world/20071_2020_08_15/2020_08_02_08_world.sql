-- Remove never used option and text for Franclorn Forgewright
DELETE FROM `gossip_menu` WHERE `MenuID` = 1667;
DELETE FROM `gossip_menu_option` WHERE `MenuID` = 1666;
DELETE FROM `npc_text` WHERE `ID` = 2319;
