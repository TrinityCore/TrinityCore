ALTER TABLE `quest_template` 
    CHANGE `MaxLevel` `QuestLevel` int(11) unsigned NOT NULL default '0',
    CHANGE `RewMoney` `RewOrReqMoney` int(11) NOT NULL default '0';
