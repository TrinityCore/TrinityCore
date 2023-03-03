DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 111771;
DELETE FROM `spell_script_names` WHERE `spell_id` = 111771;
UPDATE `creature_template_addon` SET `auras` = '113900 113899' WHERE `entry` in(59271, 59262);
UPDATE `creature_template` SET `faction_A` = '32', `faction_H` = '32', `ScriptName` = 'npc_demonic_gateway' WHERE `entry` in(59271, 59262);