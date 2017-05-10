--
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES 
(23, 30431, 44150, 5, 1106, 192, 'Arcanum of the stalwart protector - when Argent Crusade revered/exalted'),
(23, 30431, 50369, 5, 1106, 63, 'Arcanum of the stalwart protector - when Argent Crusade not revered/exalted');
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`='32344' WHERE `menu_id` IN (10119,10120); 
