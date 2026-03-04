DELETE FROM `spell_proc` WHERE `SpellId` IN (85739);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(85739,0x00,4,0x00300022,0x00202700,0x00000120,0x00181000,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Whirlwind

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_improved_whirlwind_cleave');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1464, 'spell_warr_improved_whirlwind_cleave'),  -- Slam
(1715, 'spell_warr_improved_whirlwind_cleave'),  -- Hamstring
(23881, 'spell_warr_improved_whirlwind_cleave'),  -- Bloodthirst
(23922, 'spell_warr_improved_whirlwind_cleave'),  -- Shield Slam
(34428, 'spell_warr_improved_whirlwind_cleave'),  -- Victory Rush
(85384, 'spell_warr_improved_whirlwind_cleave'),  -- Raging Blow
(96103, 'spell_warr_improved_whirlwind_cleave'),  -- Raging Blow
(100130, 'spell_warr_improved_whirlwind_cleave'),  -- Furious Slash
(163558, 'spell_warr_improved_whirlwind_cleave'),  -- Execute Off-Hand
(184707, 'spell_warr_improved_whirlwind_cleave'),  -- Rampage
(184709, 'spell_warr_improved_whirlwind_cleave'),  -- Rampage
(201363, 'spell_warr_improved_whirlwind_cleave'),  -- Rampage
(201364, 'spell_warr_improved_whirlwind_cleave'),  -- Rampage
(202168, 'spell_warr_improved_whirlwind_cleave'),  -- Impending Victory
(218617, 'spell_warr_improved_whirlwind_cleave'),  -- Rampage
(260798, 'spell_warr_improved_whirlwind_cleave'),  -- Execute
(280772, 'spell_warr_improved_whirlwind_cleave'),  -- Siegebreaker
(280849, 'spell_warr_improved_whirlwind_cleave'),  -- Execute
(317483, 'spell_warr_improved_whirlwind_cleave'),  -- Condemn (Venthyr)
(317488, 'spell_warr_improved_whirlwind_cleave'),  -- Condemn (Venthyr)
(317489, 'spell_warr_improved_whirlwind_cleave'),  -- Condemn Off-Hand (Venthyr)
(335096, 'spell_warr_improved_whirlwind_cleave'),  -- Bloodbath
(335098, 'spell_warr_improved_whirlwind_cleave'),  -- Crushing Blow
(335100, 'spell_warr_improved_whirlwind_cleave'),  -- Crushing Blow
(394062, 'spell_warr_improved_whirlwind_cleave'),  -- Rend
(394063, 'spell_warr_improved_whirlwind_cleave'),  -- Rend
(396718, 'spell_warr_improved_whirlwind_cleave'),  -- Onslaught
(463815, 'spell_warr_improved_whirlwind_cleave'),  -- Arms Execute FX Test
(463816, 'spell_warr_improved_whirlwind_cleave'),  -- Fury Execute FX Test
(463817, 'spell_warr_improved_whirlwind_cleave'),  -- Fury Execute Off-Hand FX Test
(1269383, 'spell_warr_improved_whirlwind_cleave');  -- Heroic Strike
