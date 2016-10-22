--
DELETE FROM `spell_scripts` WHERE `id`=43375;
DELETE FROM `spell_script_names` WHERE `spell_id` IN (43375, 43376, 43378, 43972);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43972, "spell_q11306_mixing_blood"),
(43375, "spell_q11306_mixing_vrykul_blood"),
(43376, "spell_q11306_failed_mix_43376"),
(43378, "spell_q11306_failed_mix_43378");

DELETE FROM creature_text WHERE entry IN (24042, 24251);
INSERT INTO creature_text (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(24042, 0, 0, "$N's concoction is ruined.  A new one must be created from scratch.", 16, 0, 100, 0, 0, 0, 23540, 0, "Generic Trigger LAB"),
(24042, 1, 0, "The failed concoction spills on the floor and appears to come to life!", 16, 0, 100, 0, 0, 0, 23071, 0, "Generic Trigger LAB"),
(24251, 0, 0, "The mixture!  It moves!", 14, 0, 100, 0, 0, 0, 23101, 0, "Chief Plaguebringer Harris");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=24279;
DELETE FROM `smart_scripts` WHERE `entryorguid`=24279;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24279, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 24251, 0, 0, 0, 0, 0, 0, "Animated Plague Slime - On Aggro - Talk 0 (Chief Plaguebringer Harris) (no repeat)"),
(24279, 0, 1, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, 11, 3335, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Animated Plague Slime - In Combat - Cast Dark Sludge");
