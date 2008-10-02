ALTER TABLE `eventai_scripts`
  DROP PRIMARY KEY,
  DROP `id`,
  ADD `id` int(11) unsigned NOT NULL COMMENT 'Identifier' PRIMARY KEY AUTO_INCREMENT FIRST,

  MODIFY `event_param1` int(11) signed NOT NULL default '0',
  MODIFY `event_param2` int(11) signed NOT NULL default '0',
  MODIFY `event_param3` int(11) signed NOT NULL default '0',

  MODIFY `action1_param1` int(11) signed NOT NULL default '0',
  MODIFY `action1_param2` int(11) signed NOT NULL default '0',
  MODIFY `action1_param3` int(11) signed NOT NULL default '0',

  MODIFY `action2_param1` int(11) signed NOT NULL default '0',
  MODIFY `action2_param2` int(11) signed NOT NULL default '0',
  MODIFY `action2_param3` int(11) signed NOT NULL default '0',

  MODIFY `action3_param1` int(11) signed NOT NULL default '0',
  MODIFY `action3_param2` int(11) signed NOT NULL default '0',
  MODIFY `action3_param3` int(11) signed NOT NULL default '0',

  ADD `comment` varchar(255) NOT NULL default '' COMMENT 'Event Comment';
   
ALTER TABLE `localized_texts`
  DROP PRIMARY KEY,
  DROP `id`,
  ADD `id` int(11) unsigned NOT NULL COMMENT 'Identifier' PRIMARY KEY AUTO_INCREMENT FIRST,
  ADD `comment` varchar(255) NOT NULL default '' COMMENT 'Text Comment';
  