ALTER TABLE `page_text`
  ADD `PlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `NextPageID`,
  ADD `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

UPDATE `gameobject_template` SET `Data8`=`Data8`^1 WHERE `type`=0;
UPDATE `gameobject_template` SET `flags`=`flags`|0x00100000 WHERE `type`=15;
