DELETE FROM `spell_script_names` WHERE `spell_id` IN (19591,35695,61013,61017,61697,61783);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(19591, 'spell_gen_pet_calculate'),
(35695, 'spell_gen_pet_calculate'),
(61013, 'spell_gen_pet_calculate'),
(61017, 'spell_gen_pet_calculate'),
(61697, 'spell_gen_pet_calculate'),
(61783, 'spell_gen_pet_calculate');

DELETE FROM `creature_template_addon` WHERE `entry` = 29264;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29264,0,0,0,1,0,'61783'); -- Spirit Wolf

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` =54566;
INSERT INTO `spell_linked_spell` (`spell_trigger` ,`spell_effect` ,`type` ,`comment`) VALUES
(54566,61697,0,'Death Knight Pet Scaling 03'); -- Risen Ghoul