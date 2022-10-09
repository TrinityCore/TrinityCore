-- Update table `gossip_menu_option`
ALTER TABLE `gossip_menu_option` DROP `OptionNpcFlag`;

-- Argent Squire | Argent Gruntling
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry` IN (33238, 33239);
UPDATE `gossip_menu_option` SET `OptionNpc`=18 WHERE `MenuID` IN (10317, 10318) AND `OptionID`=2;

-- OptionNpcFlag inserted in wrong field
UPDATE `gossip_menu_option` SET `ActionMenuID`=0 WHERE `MenuID`=10662 AND `OptionID`=0;
