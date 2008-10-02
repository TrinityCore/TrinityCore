ALTER TABLE `creature_template` 
  CHANGE `level`     `minlevel`  int(3) unsigned default '1',
  CHANGE `level_max` `maxlevel`  int(3) unsigned default '1' AFTER `minlevel`,
  ADD COLUMN         `minhealth` int(5) unsigned default '0' AFTER `maxlevel`,
  CHANGE `maxhealth` `maxhealth` int(5) unsigned default '0' AFTER `minhealth`,
  ADD COLUMN         `minmana`   int(5) unsigned default '0' AFTER `maxhealth`,
  CHANGE `maxmana`   `maxmana`   int(5) unsigned default '0' AFTER `minmana`;

UPDATE `creature_template`
  SET `maxlevel` = `minlevel` WHERE `maxlevel` < `minlevel`;
UPDATE `creature_template`
  SET `minhealth` = `maxhealth`, `minmana` = `maxmana`;
