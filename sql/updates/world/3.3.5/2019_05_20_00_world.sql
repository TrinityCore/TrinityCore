INSERT INTO spell_script_names VALUES (24083, 'spell_hatch_spiders');

UPDATE gameobject_template SET ScriptName = "gob_spider_egg" WHERE entry = 179985;
UPDATE gameobject SET ScriptName = "gob_spider_egg" WHERE id = 179985;
