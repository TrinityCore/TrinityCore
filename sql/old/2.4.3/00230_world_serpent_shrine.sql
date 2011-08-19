UPDATE creature_template SET ScriptName = 'boss_leotheras_the_blind' WHERE entry = '21215';
UPDATE creature_template SET ScriptName = 'boss_leotheras_the_blind_demonform' WHERE entry = '21875';
UPDATE creature_template SET ScriptName = 'mob_greyheart_spellbinder' WHERE entry = '21806';
UPDATE creature_template SET ScriptName = 'mob_inner_demon' WHERE entry = '21857';

UPDATE creature_template SET ScriptName = 'mob_toxic_sporebat', speed = '1' WHERE entry = '22140';
UPDATE creature_template SET modelid_A = '11686', modelid_H = '11686', flags_extra = '128' WHERE entry = '22207';

-- lurker
UPDATE creature_model_info SET bounding_radius = '13', combat_reach = '20' WHERE modelid = '20216';
UPDATE creature_template SET InhabitType = '3', ScriptName = 'boss_the_lurker_below' WHERE entry = '21217';
UPDATE creature_template SET ScriptName = 'mob_coilfang_ambusher' WHERE entry = '21865';
UPDATE creature_template SET ScriptName = 'mob_coilfang_guardian' WHERE entry = '21873';
