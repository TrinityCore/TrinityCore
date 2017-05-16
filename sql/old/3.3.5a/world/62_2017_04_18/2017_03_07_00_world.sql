DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_on_tournament_mount';
UPDATE `creature_template` SET `ScriptName`='npc_tournament_mount' WHERE `entry` IN (33217,33316,33317,33318,33319,33320,33321,33322,33323,33324,33782,33845,33844);
