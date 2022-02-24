-- Shooting Stars
UPDATE `spell_proc` SET `SpellFamilyName`= 7, `ProcFlags`= 0 WHERE `SpellId`= -93398;
-- Telluric Currents
UPDATE `spell_proc` SET `ProcFlags`= 0 WHERE `SpellId`= -82984;
-- Thunderstruck
UPDATE `spell_proc` SET `ProcFlags`= 0 WHERE `SpellId`= -80979;

-- Long Arm of the Law
DELETE FROM `spell_proc` WHERE `SpellId`= -87168;
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_long_arm_of_the_law';
