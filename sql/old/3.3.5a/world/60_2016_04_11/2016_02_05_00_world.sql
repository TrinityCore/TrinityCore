-- Implement "Toy Train Set" and "Wind-Up Train Wrecker"
UPDATE `gameobject_template` SET `ScriptName`="go_toy_train_set" WHERE `entry`=193963;
UPDATE `creature_template` SET `ScriptName`="npc_train_wrecker" WHERE `entry`=33404;
DELETE FROM `spell_script_names` WHERE `spell_id`=61551;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(61551,"spell_item_toy_train_set_pulse");
