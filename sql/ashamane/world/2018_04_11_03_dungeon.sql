UPDATE creature_template SET inhabitType = 4 WHERE entry in (99664, 100759);
DELETE FROM creature WHERE id = 111706;

UPDATE creature_template SET scriptname = "boss_illysanna_ravencrest" WHERE entry = 98696;
UPDATE creature_template SET scriptname = "npc_soultorn_vanguard" WHERE entry = 100485;
UPDATE creature_template SET scriptname = "npc_risen_arcanist" WHERE entry = 100486;

UPDATE creature_template SET scriptname = "npc_brh_boulder" WHERE entry = 111706;
UPDATE areatrigger_template SET scriptname = "at_brh_boulder" WHERE Id = 12428;

UPDATE creature_template SET scriptname = "boss_smashspite_the_hateful" WHERE entry = 98949;
UPDATE creature_template SET scriptname = "npc_brh_felbat" WHERE entry = 100759;

DELETE FROM spell_script_names WHERE scriptname = "aura_smashspite_brutality";
INSERT INTO spell_script_names VALUES
(198114, "aura_smashspite_brutality");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (196930, 198961, 199368);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
(13, 1, 196930, 31, 3, 98542),
(13, 1, 198961, 31, 3, 98965),
(13, 1, 199368, 31, 4, 0);

UPDATE creature_template SET scriptname = "boss_kurtalos_ravencrest" WHERE entry = 98965;
UPDATE creature_template SET scriptname = "npc_kurtalos_whirling_blade" WHERE entry = 100861;
UPDATE areatrigger_template SET scriptname = "at_kurtalos_whirling_blade" WHERE Id = 10185;
UPDATE creature_template SET scriptname = "npc_latosius" WHERE entry = 98970;
UPDATE creature_template SET scriptname = "npc_kurtalos_soul" WHERE entry = 101054;
UPDATE areatrigger_template SET scriptname = "at_dantalionax_cloud_of_hypnosis" WHERE Id = 10200;
UPDATE creature_template SET scriptname = "npc_dantalionax_cloud_of_hypnosis" WHERE entry = 100994;
UPDATE creature_template SET scriptname = "npc_dantalionax_stinging_swarm" WHERE entry = 101008;

DELETE FROM creature WHERE id IN (100861, 101054, 111833);
UPDATE `creature_template` SET `minlevel` = 112 , `maxlevel` = 112 , `faction` = 16 , `BaseAttackTime` = 2000 , `RangeAttackTime` = 2000 , `unit_flags` = 32768 , `unit_flags2` = 2099200 , `type` = 3 WHERE `entry` = 99611; 
UPDATE `creature_template` SET `minlevel` = 112 , `maxlevel` = 112 , `faction` = 16 , `BaseAttackTime` = 2000 , `RangeAttackTime` = 2000 WHERE `entry` = 99664;
UPDATE `creature_template` SET `minlevel` = 112 , `maxlevel` = 112 , `faction` = 16 , `BaseAttackTime` = 2000 , `RangeAttackTime` = 2000 WHERE `entry` = 101008;

DELETE FROM creature_template_addon WHERE entry IN (101008);
INSERT INTO creature_template_addon (`entry`, `auras`) VALUES
(101008, "199160");

DELETE FROM `spell_area` WHERE `spell` = 199368;
INSERT INTO `spell_area` (`spell`, `area`, `flags`) VALUES (199368, 7805, 2);
