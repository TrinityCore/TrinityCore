RENAME TABLE `quest_creature_greeting` TO `quest_greeting`;
ALTER TABLE `quest_greeting`
  CHANGE `CreatureID` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  ADD `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`;
