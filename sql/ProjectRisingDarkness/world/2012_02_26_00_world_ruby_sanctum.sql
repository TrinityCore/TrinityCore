-- Trash SAI for ruby sanctum

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (40419, 40421, 40417, 40423);

DELETE FROM smart_scripts WHERE entryorguid IN (40419, 40421, 40417, 40423);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`)
VALUES
(40417, 0, 0, 0, 0, 0, 100, 0, 15000, 30000, 30000, 30000, 11, 75413, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Flammenwelle - Herbeirufer der Schmorschuppen'),
(40417, 0, 1, 0, 0, 0, 100, 0, 4000, 10000, 10000, 10000, 11, 75412, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Versengen - Herbeirufer der Schmorschuppen'),
(40417, 0, 2, 0, 0, 0, 100, 0, 45000, 45000, 45000, 45000, 11, 75416, 16, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Zusammenruf - Herbeirufer der Schmorschuppen'),
(40419, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 15284, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Spalten - Angreifer der Schmorschuppen'),
(40419, 0, 0, 0, 0, 0, 100, 0, 21000, 21000, 21000, 21000, 11, 75417, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Schockwelle - Angreifer der Schmorschuppen'),
(40419, 0, 2, 0, 0, 0, 100, 0, 60000, 60000, 60000, 60000, 11, 75416, 16, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Zusammenruf - Angreifer der Schmorschuppen'),
(40421, 0, 0, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10000, 11, 15621, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Schädelkracher - Elite der Schmorschuppen'),
(40423, 0, 0, 0, 0, 0, 100, 0, 22000, 22000, 22000, 22000, 11, 75414, 16, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Sammelruf - Kommandant der Schmorschuppen'),
(40423, 0, 1, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 13737, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Rubinsanktum - Tödlicher Stoß - Kommandant der Schmorschuppen');