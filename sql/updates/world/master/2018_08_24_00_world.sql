ALTER TABLE `conversation_line_template` ADD `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `ActorIdx`;
UPDATE `conversation_line_template` SET `Flags`=(`ActorIdx`>>8);
UPDATE `conversation_line_template` SET `ActorIdx`=`ActorIdx`&0xFF;
ALTER TABLE `conversation_line_template`
  CHANGE `ActorIdx` `ActorIdx` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `UiCameraID`,
  DROP `Unk`;
