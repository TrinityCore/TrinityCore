update creature_template set ScriptName = 'npc_iruk' where entry = 26219;
UPDATE creature_template SET ScriptName = 'npc_corastrasza' WHERE entry = 32548;

DELETE FROM `spell_script_target` WHERE entry = 61245;
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(61245, 1, 32535);

UPDATE creature_template SET VehicleId = 165 , spell1 = 56091,spell2 = 56092,spell3 = 57090,spell4 = 57143 ,spell5 = 57108,spell6=57403, unit_class = 1, minhealth = 100000, maxhealth = 100000 WHERE entry = 32535;
UPDATE creature_template SET armor = 9729, mindmg = 422, maxdmg=586, minrangedmg=345, maxrangedmg=509, attackpower=642, rangedattackpower=103 WHERE entry = 32535;
update creature set DeathState = 0 where id = 26219;