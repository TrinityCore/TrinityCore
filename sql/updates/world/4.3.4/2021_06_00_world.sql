UPDATE `spell_script_names` SET `ScriptName`= 'spell_assembly_shield_of_runes' WHERE `ScriptName`= 'spell_shield_of_runes';
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (32958, 33689);
DELETE FROM `conditions` WHERE `SourceEntry`= 64320 AND `SourceTypeOrReferenceId`= 13;
UPDATE `creature_template` SET `flags_extra`= `flags_extra` &~ 0x1 WHERE `entry` IN (32857, 33694, 32867, 33693, 32927, 33692);
UPDATE `instance_encounters` SET `creditType`= 1, `creditEntry`= 65195 WHERE `entry`= 1140;

-- Ulduar: Assembly of Iron - Rune of Death
DELETE FROM `spelldifficulty_dbc` WHERE `id`=62269;
INSERT INTO `spelldifficulty_dbc`(`id`, `spellid0`, `spellid1`) VALUES
(62269, 62269, 63490);
-- Ulduar: Assembly of Iron - Overload
-- Overload 10 (61869) and 25 (63481) has same trigger spell effect 61878 (10 mode), it need set 63480 in 25 mode
DELETE FROM `spelldifficulty_dbc` WHERE `id`=61878;
INSERT INTO `spelldifficulty_dbc`(`id`, `spellid0`, `spellid1`) VALUES
(61878, 61878, 63480);
