DELETE FROM `spell_script_names` WHERE ScriptName IN (
'spell_pal_crusaders_might',
'spell_pal_crusader_strike',
'spell_pal_flash_of_light',
'spell_pal_holy_light',
'spell_pal_holy_shock',
'spell_pal_infusion_of_light',
'spell_pal_judgment_of_light_proc',
'spell_pal_judgment_of_light',
'spell_pal_beacon_of_light',
'spell_pal_beacon_of_light_proc',
'spell_pal_beacon_of_faith',
'spell_pal_beacon_of_light_aura'
);

INSERT INTO spell_script_names(`spell_id`, `ScriptName`) VALUES
(35395, 'spell_pal_crusader_strike'),
(19750, 'spell_pal_flash_of_light'),
(82326, 'spell_pal_holy_light'),
(53576, 'spell_pal_infusion_of_light'),
(20473, 'spell_pal_holy_shock'),
(196941, 'spell_pal_judgment_of_light_proc'),
(183778, 'spell_pal_judgment_of_light'),
(53563, 'spell_pal_beacon_of_light_aura'),
(53651, 'spell_pal_beacon_of_light_proc'),
(156910, 'spell_pal_beacon_of_light_aura'),
(177173, 'spell_pal_beacon_of_light_proc'),
(156910, 'spell_pal_beacon_of_faith'),
(53563, 'spell_pal_beacon_of_light');

DELETE FROM `spell_proc` WHERE SpellId IN ( 53576 );
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`, `Charges`) VALUES
(53576, 0x0, 10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0, 0, 0);