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

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) VALUES
('13', '1', '198961', '31', '3', '98965'); 
