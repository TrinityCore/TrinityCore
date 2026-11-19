UPDATE `gossip_menu_option` SET `OptionType`=5, `OptionNpcFlag`=16 WHERE `MenuID` IN (10977,10984,10986) AND `OptionID`=0;

DELETE FROM `creature_template_addon` WHERE `entry` IN (47057);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (47057,0,0,8,257,0, '');
