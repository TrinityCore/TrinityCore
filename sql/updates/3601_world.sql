UPDATE `creature_template` SET `VehicleId`=200 WHERE `entry` IN (28605,28606,28607);
UPDATE `creature_template` SET `ScriptName`='npc_salanar_the_horseman' WHERE `entry`=28653;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (28605,28606,28607);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_id`, `quest_status`, `cast_flags`) VALUES
(28605, 52263, 12680, 3, 1),
(28606, 52263, 12680, 3, 1),
(28607, 52263, 12680, 3, 1);