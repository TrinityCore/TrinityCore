-- Correct all stable masters
UPDATE `creature_template` SET `npcflag`= `npcflag`| 0x00400000, `gossip_menu_id`= 9821, `scriptname`= 'npc_stable_master' WHERE `subname`= 'Stable Master';
-- Remove Battle Pet Gossip option because we are on 4.3.4
DELETE FROM `gossip_menu_option` WHERE `MenuID`= 9821 AND `OptionID`= 2;
-- Add stable master flag to stable option
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 4194304, `OptionBroadcastTextID`= 30181, `OptionType`= 14 WHERE `MenuID`= 9821 AND `OptionID`= 0;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`= 56613 WHERE `MenuID`= 9821 AND `OptionID`= 1;
