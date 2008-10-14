ALTER TABLE game_event ADD COLUMN world_event tinyint(3) unsigned not null default 0 comment '0 if normal event, 1 if world event';

CREATE TABLE `game_event_quest_condition` (                   
 `quest` mediumint(8) unsigned NOT NULL default '0',         
 `event_id` mediumint(8) unsigned NOT NULL default '0',      
 `condition_id` mediumint(8) unsigned NOT NULL default '0',  
 `num` float default '0',                                    
 PRIMARY KEY  (`quest`)                                      
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
            
CREATE TABLE `game_event_condition` (                                  
 `event_id` mediumint(8) unsigned NOT NULL default '0',               
 `condition_id` mediumint(8) unsigned NOT NULL default '0',           
 `req_num` float default '0',                                         
 `max_world_state_field` smallint(5) unsigned NOT NULL default '0',   
 `done_world_state_field` smallint(5) unsigned NOT NULL default '0',  
 `description` varchar(25) NOT NULL default '',                                  
 PRIMARY KEY  (`event_id`,`condition_id`)                             
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
                      
CREATE TABLE `game_event_npcflag` (                       
 `guid` mediumint(8) unsigned NOT NULL default '0',      
 `event_id` mediumint(8) unsigned NOT NULL default '0',  
 `npcflag` int(10) unsigned NOT NULL default '0',        
 PRIMARY KEY  (`guid`,`event_id`)                        
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
                    
CREATE TABLE `game_event_prerequisite` (                
 `event_id` mediumint(8) unsigned NOT NULL,            
 `prerequisite_event` mediumint(8) unsigned NOT NULL,  
 PRIMARY KEY  (`event_id`,`prerequisite_event`)        
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
                         
CREATE TABLE `game_event_npc_gossip` (                    
 `guid` int(10) unsigned NOT NULL,                       
 `event_id` mediumint(8) unsigned NOT NULL default '0',  
 `textid` mediumint(8) unsigned NOT NULL default '0',    
 PRIMARY KEY  (`guid`)                                   
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
                       
CREATE TABLE `game_event_gameobject_quest` (           
 `id` mediumint(8) unsigned NOT NULL default '0',     
 `quest` mediumint(8) unsigned NOT NULL default '0',  
 `event` smallint(5) unsigned NOT NULL default '0',   
 PRIMARY KEY  (`quest`,`event`,`id`)                  
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TABLE `game_event_npc_vendor` (                                  
 `event` mediumint(8) unsigned NOT NULL default '0',               
 `guid` mediumint(8) unsigned NOT NULL default '0',           
 `item` mediumint(8) unsigned NOT NULL default '0',               
 `maxcount` mediumint(8) unsigned NOT NULL default '0',           
 `incrtime` mediumint(8) unsigned NOT NULL default '0',           
 `ExtendedCost` mediumint(8) unsigned NOT NULL default '0',           
 PRIMARY KEY  (`guid`,`item`)                             
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE game_event_creature_quest DROP PRIMARY KEY, ADD PRIMARY KEY (quest, event, id);

ALTER TABLE game_event_creature DROP PRIMARY KEY, ADD PRIMARY KEY (guid, event);

ALTER TABLE game_event_gameobject DROP PRIMARY KEY, ADD PRIMARY KEY (guid, event);

DELETE FROM `command` WHERE `name` LIKE 'debug threatlist';
DELETE FROM `command` WHERE `name` LIKE 'debug hostilrefs';
INSERT INTO `command` VALUES
('debug threatlist', 3, 'Syntax: .debug threatlist\n\n Prints out the current threatlist of the targetted creature.'),
('debug hostilrefs', 3, 'Syntax: .debug hostilrefs\n\n Prints out the hostil refs of the targetted unit.');
