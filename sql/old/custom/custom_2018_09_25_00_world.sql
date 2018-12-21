DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warl_pet_scaling_06',
'spell_dk_pet_scaling_05',
'spell_dk_rune_weapon_scaling_02',
'spell_mage_water_elemental_scaling_01',
'spell_mage_water_elemental_scaling_02');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(89953, 'spell_warl_pet_scaling_06'),
(110474, 'spell_dk_pet_scaling_05'),
(51906, 'spell_dk_rune_weapon_scaling_02'),
(35657, 'spell_mage_water_elemental_scaling_01'),
(35658, 'spell_mage_water_elemental_scaling_02');

DELETE FROM `spell_bonus_data` WHERE `entry` IN (3110, 3716, 54049, 7814, 6360, 30213, 89751, 89753, 31707, 51963, 16827, 17253, 49966, 95714, 95725 );
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES
(3110, 0.657, 0, 0, 0, 'Warlock - Firebolt (Imp)'),
(3716, 0.512, 0, 0, 0, 'Warlock - Torment (Voidwalker)'),
(54049, 1.228, 0, 0, 0, 'Warlock - Shadow Bite (Felhunter)'),
(7814, 0.612, 0, 0, 0, 'Warlock - Lash of Pain (Succubus)'),
(6360, 0.85, 0, 0, 0, 'Warlock - Whiplash (Succubus)'),
(31707, 0.833, 0, 0, 0, 'Mage - Waterbolt (Water Elemental)'),
(51963, 0.453, 0, 0, 0, 'Death Knight - Gargoyle Strike (Gargoyle)'),
(16827, 0, 0, 0.20, 0, 'Hunter - Claw (Pet)'),
(17253, 0, 0, 0.20, 0, 'Hunter - Bite (Pet)'),
(49966, 0, 0, 0.20, 0, 'Hunter - Smack (Pet)'),
(95714, 0, 0, 0.288, 0, 'Hunter - Burrow Attack (Pet)'),
(95725, 0, 0, 0.288, 0, 'Hunter - Froststorm Breath (Pet)');
