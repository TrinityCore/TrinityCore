UPDATE `creature_template_movement` SET `Rooted`= 1 WHERE `CreatureId`= 45981;
UPDATE `creature_template_movement` SET `Ground`= 0, `Swim`= 0, `Flight`= 1 WHERE `CreatureId` IN (45932, 45933);

UPDATE `creature_template` SET `difficulty_entry_1`= 52020 WHERE `entry`= 52019;
UPDATE `creature_template` SET `minlevel`= 85, `maxlevel`= 85, `faction`= 16, `exp`= 3 WHERE `entry`= 52020;

UPDATE `creature_template` SET `flags_extra`= 0x40000000, `mechanic_immune_mask`= 2 | 16 | 256 | 512 | 65536 | 131072 | 4194304 | 67108864 WHERE `entry` IN (45932, 45933, 52020, 52019);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_arcane_barrage';
