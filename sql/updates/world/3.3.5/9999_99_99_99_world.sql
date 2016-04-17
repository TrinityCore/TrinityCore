DELETE FROM `spell_script_names` where `ScriptName` IN ('spell_burning_spray','spell_paralytic_spray','spell_jormungars_paralytic_toxin');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66902,'spell_burning_spray'), -- Burning Spray 10m normal
(67627,'spell_burning_spray'), -- Burning Spray 25m normal
(67628,'spell_burning_spray'), -- Burning Spray 10m heroic
(67629,'spell_burning_spray'), -- Burning Spray 25m heroic
(66901,'spell_paralytic_spray'), -- Paralytic Spray 10m normal
(67615,'spell_paralytic_spray'), -- Paralytic Spray 25m normal
(67616,'spell_paralytic_spray'), -- Paralytic Spray 10m heroic
(67617,'spell_paralytic_spray'), -- Paralytic Spray 25m heroic
(66823,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 10m normal
(67618,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 25m normal
(67619,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin 10m heroic
(67620,'spell_jormungars_paralytic_toxin'); -- Paralytic Toxin 25m heroic

-- Acidmaw missing text
DELETE FROM `creature_text` where entry = 35144 AND groupid = 1;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35144, 1, 0, 'You have been infected with a Paralytic Toxin!', 42, 0, 0, 0, 0, 0, 'Acidmaw - Special Attack');
