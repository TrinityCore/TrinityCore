ALTER TABLE `creature_template` 
  CHANGE `maxlevel`  `maxlevel`  int(3) unsigned default '1' AFTER `minlevel`,
  CHANGE `minhealth` `minhealth` int(5) unsigned default '0' AFTER `maxlevel`,
  CHANGE `maxhealth` `maxhealth` int(5) unsigned default '0' AFTER `minhealth`,
  CHANGE `minmana`   `minmana`   int(5) unsigned default '0' AFTER `maxhealth`,
  CHANGE `maxmana`   `maxmana`   int(5) unsigned default '0' AFTER `minmana`;
