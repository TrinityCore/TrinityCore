-- 196406 - Back Draft Aura
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_back_draft_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(196406, 'spell_warl_back_draft_aura');

DELETE FROM `spell_proc` WHERE `SpellId`=196406;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES 
(196406, 4, 5, 0, 0x00820000, 0, 0x00400000, 0x00010000, 1, 1, 0, 0, 0, 100, 0, 0);

-- 205184 - Roaring Blaze
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_roaring_blaze';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(205184, 'spell_warr_roaring_blaze');

-- 264178 - Demonbolt
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_demonbolt';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(264178, 'spell_warl_demonbolt');

-- 265412 - Doom
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_doom';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(265412, 'spell_warl_doom');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_warl_soul_shatter', 'spell_warl_shadow_ward', 'spell_warl_soul_swap',
'spell_warl_soul_swap_dot_marker', 'spell_warl_soul_swap_exhale', 
'spell_warl_soul_swap_override', 'spell_warl_soulshatter', 'spell_mage_blazing_soul');

-- 198068 - Power Of The Dark Side
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_power_of_the_dark_side';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(198068, 'spell_pri_power_of_the_dark_side');

DELETE FROM `command` WHERE `name`='reload spell_script_names';
INSERT INTO `command` (`name`, `permission`, `help`) VALUES 
('reload spell_script_names', 2009, 'Syntax: .reload spell_script_names');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pri_penance_heal_damage', 'spell_pri_penance_triggered',
'spell_pri_penance', 'spell_pri_purge_the_wicked_selector',
'spell_pri_archangel', 'spell_pri_dark_archangel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(47750, 'spell_pri_penance_heal_damage'),
(47666, 'spell_pri_penance_heal_damage'),

(47757, 'spell_pri_penance_triggered'),
(47758, 'spell_pri_penance_triggered'),

(47540, 'spell_pri_penance'),

(204215, 'spell_pri_purge_the_wicked_selector'),

(197862, 'spell_pri_archangel'),

(197871, 'spell_pri_dark_archangel');
