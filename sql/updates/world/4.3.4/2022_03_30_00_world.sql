DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_throngus_flaming_arrow', 'spell_throngus_fixate_effect');
UPDATE `creature_template` SET `ScriptName`= '', `AIName`= 'NullCreatureAI' WHERE `entry`= 40228;
