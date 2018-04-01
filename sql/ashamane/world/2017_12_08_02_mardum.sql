UPDATE gameobject_template SET scriptname = "go_mardum_tome_of_fel_secrets" WHERE entry = 245112;
UPDATE creature_template SET scriptname = "npc_mardum_dh_learn_spec" WHERE entry in (96655, 93127, 99045, 96420, 96652);
UPDATE creature_template SET scriptname = "npc_mardum_izal_whitemoon" WHERE entry = 96653;

UPDATE `creature` SET `position_x` = 1467.730103 , `position_y` = 1411.561279 , `position_z` = 243.961396 , `orientation` = 0 WHERE `guid` = 20542423; 

UPDATE creature_template SET InhabitType = 4, modelid1 = 11686 WHERE entry = 100510;
UPDATE creature_template SET InhabitType = 4 WHERE entry IN (37490, 100333);

UPDATE creature_template SET lootid = 93802 WHERE entry = 93802;
UPDATE creature_loot_template SET Chance = 100 WHERE entry = 93802 AND item = 124672;

UPDATE quest_template_addon SET PrevQuestID = 38728 WHERE id = 38729;

UPDATE creature_template SET scriptname = "npc_mardum_tyranna" WHERE entry = 93802;
UPDATE creature_template SET scriptname = "npc_mardum_kayn_sunfury_end" WHERE entry = 97303;

UPDATE gameobject_template SET scriptname = "go_mardum_the_keystone" WHERE entry = 245728;

DELETE FROM spell_script_names WHERE scriptname = "spell_mardum_back_to_black_temple";
INSERT INTO spell_script_names VALUES (192140, "spell_mardum_back_to_black_temple");
