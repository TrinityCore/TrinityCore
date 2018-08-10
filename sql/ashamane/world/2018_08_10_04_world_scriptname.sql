DELETE FROM spell_script_names WHERE scriptname = "spell_warl_call_dreadstalker";
UPDATE creature_template SET vehicleId = 4469 WHERE entry = 98035;

DELETE FROM creature_template_addon WHERE entry = 98035;
INSERT INTO creature_template_addon (entry, auras) VALUES
(98035, "215111");

UPDATE `creature_template` SET `spell1` = 205196, `AIName` = 'PetAI' WHERE entry = 98035;
