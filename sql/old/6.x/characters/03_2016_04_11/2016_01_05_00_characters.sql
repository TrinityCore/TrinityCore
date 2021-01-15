ALTER TABLE `characters`
  ADD `skin` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `money`,
  ADD `face` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `skin`,
  ADD `hairStyle` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `face`,
  ADD `hairColor` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `hairStyle`,
  ADD `facialStyle` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `hairColor`,
  ADD `bankSlots` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `facialStyle`,
  ADD `restState` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `bankSlots`;

UPDATE `characters` SET 
  `skin`=`playerBytes`&0xFF,
  `face`=(`playerBytes`>>8)&0xFF,
  `hairStyle`=(`playerBytes`>>16)&0xFF,
  `hairColor`=(`playerBytes`>>24)&0xFF,
  `facialStyle`=`playerBytes2`&0xFF,
  `bankSlots`=(`playerBytes2`>>16)&0xFF,
  `restState`=(`playerBytes2`>>24)&0xFF;

ALTER TABLE `characters` DROP `playerBytes`, DROP `playerBytes2`;
