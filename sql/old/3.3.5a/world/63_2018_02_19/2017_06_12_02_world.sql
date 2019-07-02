--
DELETE FROM `trinity_string` WHERE `entry` BETWEEN 288 AND 295;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES
  (288, '%s either isn\'t dead or has no loot available.'),
  (289, 'LOOT INFO: %s (%d)'),
  (290, '├ %s (%d items):'),
  (291, '├─ %dx |c%08x|Hitem:%d:0:0:0:0:0:0:0:0|h[%s]|h|r (#%05d)'),
  (292, '├ Money: %01d|TInterface\\MoneyFrame\\UI-GoldIcon:0:0:2:0|t %02d|TInterface\\MoneyFrame\\UI-SilverIcon:0:0:2:0|t %02d|TInterface\\MoneyFrame\\UI-CopperIcon:0:0:2:0|t'),
  (293, '├ %s:'),
  (294, '├─ %s (%d items):'),
  (295, '├── %dx |c%08x|Hitem:%d:0:0:0:0:0:0:0:0|h[%s]|h|r (#%05d)');

DELETE FROM `command` WHERE `name`='npc showloot';
INSERT INTO `command` (`name`,`permission`,`help`) VALUES
('npc showloot', 865, "Syntax: .npc showloot [all]

Shows the loot contained in targeted dead creature.");
