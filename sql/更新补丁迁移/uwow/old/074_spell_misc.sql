DELETE FROM `spell_script_names` WHERE (`spell_id`='25912') AND (`ScriptName`='spell_pal_holy_shock_damage');
DELETE FROM `spell_script_names` WHERE (`spell_id`='-20473') AND (`ScriptName`='spell_pal_holy_shock');

DELETE FROM `spell_bonus_data` WHERE (`entry`='25912');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `comments`) VALUES ('25912', '0.925', 'Paladin - Holy Shock Damage');

DELETE FROM `spell_bonus_data` WHERE (`entry`='25914');
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `comments`) VALUES ('25914', '0.833', 'Paladin - Holy Shock Heal');