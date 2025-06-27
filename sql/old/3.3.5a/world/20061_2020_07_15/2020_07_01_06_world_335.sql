-- 
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=0 WHERE `entry` IN (7770, 10676);
DELETE FROM `gossip_menu` WHERE `TextID`=16642;
DELETE FROM `gossip_menu` WHERE `MenuID` IN (11189, 11876);
-- DELETE FROM `npc_text` WHERE `ID` IN (15572, 16642, 16644);
