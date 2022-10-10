DELETE FROM `spell_script_names` WHERE (`spell_id`='81262') AND (`ScriptName`='spell_dru_swiftmend');
DELETE FROM `spell_radius` WHERE (`spell_id`='81262') AND (`effectradius0`='14') AND (`effectradius1`='0') AND (`effectradius2`='0') AND (`effectradius3`='0') AND (`effectradius4`='0') AND (`comments`='8 yard') LIMIT 1;

DELETE FROM `spell_bonus_data` WHERE (`entry`='81269');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `comments`) VALUES ('81269', '0.1548', 'Druid - Efflorescence');

DELETE FROM `spell_bonus_data` WHERE (`entry`='18562');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `comments`) VALUES ('18562', '1.29', 'Druid - Swiftmend');