DELETE FROM spell_script_target WHERE targetentry IN (8313,38968,21934);
DELETE FROM spell_proc_event WHERE entry in (19615);

UPDATE creature_template SET spell2 = 0 WHERE entry IN (16474,30000);
UPDATE gameobject_template SET scriptname = 'go_najentus_spine' WHERE entry = 185584;
UPDATE gameobject_template SET scriptname = 'go_bridge_console' WHERE entry = 184568;