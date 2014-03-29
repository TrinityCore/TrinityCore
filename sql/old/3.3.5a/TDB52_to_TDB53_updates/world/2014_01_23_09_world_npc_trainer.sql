--
DELETE FROM `npc_trainer` WHERE `entry`=201009 AND `spell`=63746;
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES 
(201009, 63746, 5000, 333, 225, 0);
