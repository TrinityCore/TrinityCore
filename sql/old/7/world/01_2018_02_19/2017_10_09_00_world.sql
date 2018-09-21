ALTER TABLE `npc_vendor`
  ADD `BonusListIDs` TEXT NULL AFTER `type`;

ALTER TABLE `game_event_npc_vendor`
  ADD `BonusListIDs` TEXT NULL,
  ADD PlayerConditionID INT(10) unsigned NOT NULL DEFAULT '0',
  ADD IgnoreFiltering TINYINT(3) unsigned NOT NULL DEFAULT '0';

UPDATE `command` SET `help`='Syntax: .npc add item #itemId <#maxcount><#incrtime><#extendedcost><#bonusListIDs>\r\nAdd item #itemid to item list of selected vendor. Also optionally set max count item in vendor item list and time to item count restoring and items ExtendedCost.\r\n#bonusListIDs is a semicolon separated list of bonuses to add to item (such as Mythic/Heroic/Warforged/socket)' WHERE `name`='npc add item';
