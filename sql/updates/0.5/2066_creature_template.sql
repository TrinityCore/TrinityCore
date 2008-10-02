ALTER TABLE `creature_template` 
    ADD `trainer_spell` int(11) unsigned default '0' AFTER `trainer_type`,
    ADD `race`          int(11) unsigned default '0' AFTER `class`;
