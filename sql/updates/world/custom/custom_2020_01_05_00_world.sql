DELETE FROM `creature` WHERE `guid` IN (137743, 208786, 208778, 208777, 95035, 137744, 137745, 137788, 137787, 137786, 137785, 137784);
DELETE FROM `creature_addon` WHERE `guid` IN (137743, 208786, 208778, 208777, 95035, 137744, 137745, 137788, 137787, 137786, 137785, 137784);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-137743, -208786, -208778, -208777, -95035, -137744, -137745, -137788, -137787, -137786, -137785, -137784) AND `source_type`= 0;
UPDATE `creature_template` SET `AIName`= '' WHERE `entry` IN (38471, 38491, 38492, 38490, 38494, 38501, 38551, 38558, 39123, 38557, 38589);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_rotface_slime_spray',
'spell_frost_giant_death_plague',
'spell_icc_harvest_blight_specimen');

UPDATE `creature_template` SET `ScriptName`= '' WHERE `ScriptName` IN
('npc_alchemist_adrianna',
'npc_rotting_frost_giant',
'npc_darnavan');

DELETE FROM `areatrigger_scripts` WHERE `ScriptName`= 'at_icc_start_blood_quickening';
