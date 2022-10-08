DELETE FROM `creature_template` WHERE (`entry`='69680');
DELETE FROM `creature_template` WHERE (`entry`='69792');
DELETE FROM `creature_template` WHERE (`entry`='69791');
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `unit_flags2`, `type_flags`, `equipment_id`, `ScriptName`) VALUES ('69680', '11686', 'Storm Spirit', '90', '90', '4', '2402', '2402', '2297', '2000', '32768', '2048', '16777216', '69680', 'npc_storm_earth_and_fire');
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `unit_flags2`, `type_flags`, `equipment_id`, `ScriptName`) VALUES ('69792', '11686', 'Earth Spirit', '90', '90', '4', '2402', '2402', '2272', '2000', '32768', '2048', '16777216', '69792', 'npc_storm_earth_and_fire');
INSERT INTO `creature_template` (`entry`, `modelid1`, `name`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `unit_flags2`, `type_flags`, `equipment_id`, `ScriptName`) VALUES ('69791', '11686', 'Fire Spirit', '90', '90', '4', '2402', '2402', '2297', '2000', '32768', '2048', '16777216', '69791', 'npc_storm_earth_and_fire');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('137639', 'spell_monk_storm_earth_and_fire');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('138081', 'spell_monk_storm_earth_and_fire_clone_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('138080', 'spell_monk_storm_earth_and_fire_clone_visual');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('138083', 'spell_monk_storm_earth_and_fire_clone_visual');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('113656', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('107428', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('100780', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115698', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115687', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115693', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115695', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('108557', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('100787', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('100784', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('101546', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('115098', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('116847', 'spell_monk_clone_cast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('117952', 'spell_monk_clone_cast');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES ('120086', 'spell_monk_fists_of_fury_stun');