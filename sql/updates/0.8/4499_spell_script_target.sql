ALTER TABLE `spell_script_target` 
  CHANGE COLUMN `targetEntry` `targetEntry` int(11) unsigned default '0',
  ADD UNIQUE KEY `entry_type_target` (`entry`,`type`,`targetEntry`);
