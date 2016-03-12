-- 
-- Spell removed in 4.3.4
DELETE FROM `spell_script_names` WHERE `spell_id`=52916;
-- Use DBC values
UPDATE `spell_proc_event` SET `CustomChance`=0, `Cooldown`=0 WHERE `entry` IN (51698,51700,51701);
-- Remove no longer existing script
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `entry`=177226;
