ALTER TABLE `npc_trainer` 
    CHANGE `reqspell` `reqspell` int(11) unsigned default '0',
    CHANGE `reqskill` `reqskill` int(11) unsigned default '0',
    CHANGE `reqskillvalue` `reqskillvalue` int(11) unsigned default '0',
    ADD COLUMN `reqlevel` int(11) unsigned default '0';
