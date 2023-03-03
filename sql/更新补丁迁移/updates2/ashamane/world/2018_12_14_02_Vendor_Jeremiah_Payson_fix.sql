-- Vendor Fix https://www.wowhead.com/npc=141702/jeremiah-payson

DELETE FROM `npc_vendor` WHERE `entry` = 141702 AND `item` = 10393;
INSERT INTO `npc_vendor` (`entry`, `item`, `OverrideGoldCost`) VALUES (141702, 10393, 5000);
