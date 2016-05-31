DELETE FROM `npc_trainer` WHERE `entry` IN (11146);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(11146, -200401, 0, 0, 0, 0); -- Ironus Coldsteel <Blacksmith Trainer>


-- Blacksmithing specialisations no longer exist in cata - all values are now 0 for `trainer_spell`
UPDATE `creature_template` SET `trainer_spell`=0 WHERE `trainer_spell` IN (9787, 9788);
