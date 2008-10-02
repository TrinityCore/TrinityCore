DROP TABLE IF EXISTS `skinning_loot_template`;
CREATE TABLE `skinning_loot_template` (
  `entry` int(11) unsigned NOT NULL default '0',
  `item` int(11) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '100',
  `questchance` float NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

DROP TABLE IF EXISTS `skinning_loot_template_alternative`;
CREATE TABLE `skinning_loot_template_alternative` (
  `item` int(11) unsigned NOT NULL default '0',
  `item2` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

update `creature_template` set `skinloot` = 
case `type`
  when 2 then 100001  #CREATURE_TYPE_DRAGON
  when 1 then         #CREATURE_TYPE_BEAST
    case `family`
      when 7  then 0       #CREATURE_FAMILY_CARRION_BIRD
      when 26 then 0       #CREATURE_FAMILY_OWL
      when 21 then 100002  #CREATURE_FAMILY_TURTLE
      else if (`minlevel` > 48, 100003, 
           if (`minlevel` > 36, 100004, 
           if (`minlevel` > 25, 100005, 
           if (`minlevel` > 15, 100006, 
           if (`minlevel` >  3, 100007, 
                                100008 )))))
    end
  else 0 
end;

insert into `skinning_loot_template` values
  (100001, 8165,100, 0),
  (100002, 8167,100, 0),
  (100003, 8170,100, 0),
  (100004, 4304,100, 0),
  (100005, 4234,100, 0),
  (100006, 2319,100, 0),
  (100007, 2318,100, 0),
  (100008, 2934,100, 0);

insert into `skinning_loot_template_alternative` values
  (8170,8171),
  (4304,8169),
  (4234,8235),
  (2319,4232),
  (2318, 783);
