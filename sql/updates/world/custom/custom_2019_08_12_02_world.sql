UPDATE `creature_template` SET `speed_run`= 1.714 WHERE `entry`= 45991;
UPDATE `waypoint_data` SET `move_type`= 1 WHERE `id` IN (4599100, 4599101);

UPDATE `creature_template` SET `unit_flags`= 0x00008000, `flags_extra`= 0x00000100 | 0x40000000, `mechanic_immune_mask`=  2147483647, `ScriptName`= 'npc_vp_howling_gale' WHERE `entry`= 45572;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_howling_gale',
'spell_vp_howling_gale');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85084, 'spell_vp_howling_gale');

DELETE FROM `spell_proc` WHERE `SpellId`= 85084;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(85084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 10000, 0, 100);
