-- Update gossip_menu_option

DELETE FROM `gossip_menu_option` WHERE MenuId = 21043;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(21043,0,0,"I want to transmogrify my gear.",130510,20,268435456,26365),
(21043,1,1,"I would like to buy from you.",14967,3,128,26365),
(21043,2,0,"I want to participate in the Trial of Style!",130512,1,1,26365);

-- Apply gossip menu and correct flags

UPDATE `creature_template` SET `gossip_menu_id` = 21043, `npcflag` = 268435585 WHERE `entry` IN (54442,54473,64573,67014,99867);
