-- Fix all force gossip npc's. Merged from 1a085a3466908e8ef19b52c8a0e91c8ef398ec07
UPDATE `creature_template` SET `type_flags`= `type_flags` & ~134217728 WHERE `npcflag` > 16 AND `gossip_menu_id` != 0 AND `type_flags` & 134217728;

-- Remove BroadCastTextID from 434 gossips that are different to post-cata texts
UPDATE `gossip_menu_option` SET `OptionBroadCastTextID`= 0 WHERE `MenuID`= 435 AND `OptionID` IN (0, 1, 2);
UPDATE `gossip_menu_option` SET `OptionBroadCastTextID`= 0 WHERE `MenuID`= 1951 AND `OptionID` IN (0, 1, 2);

-- Fix Reforging gossip
UPDATE `gossip_menu_option` SET `ActionMenuID`= 13029, `ActionPoiID`= 552 WHERE `MenuID`= 435 AND `OptionID`= 0;
UPDATE `gossip_menu_option` SET `ActionMenuID`= 12246, `ActionPoiID`= 458 WHERE `MenuID`= 1951 AND `OptionID`= 0;


UPDATE `npc_text` SET `BroadCastTextID0`= 53079 WHERE `ID`= 18301;
UPDATE `npc_text` SET `BroadCastTextID0`= 47515 WHERE `ID`= 17204;

UPDATE `npc_text` SET `text0_0`= "A trio of ethereal technomancers has set up shop in Orgrimmar, along the eastern Drag.\n\nLook for the weird machinery and purple lights... you can\'t miss it.\n\nThey offer just the sort of services you\'re looking for.', 'A trio of ethereal technomancers has set up shop in Orgrimmar, along the eastern Drag.\n\nLook for the weird machinery and purple lights... you can\'t miss it.\n\nThey offer just the sort of services you\'re looking for." WHERE `ID`= 17204;
UPDATE `npc_text` SET `text0_1`= "A trio of ethereal technomancers has set up shop in Orgrimmar, along the eastern Drag.\n\nLook for the weird machinery and purple lights... you can\'t miss it.\n\nThey offer just the sort of services you\'re looking for.', 'A trio of ethereal technomancers has set up shop in Orgrimmar, along the eastern Drag.\n\nLook for the weird machinery and purple lights... you can\'t miss it.\n\nThey offer just the sort of services you\'re looking for." WHERE `ID`= 17204;

