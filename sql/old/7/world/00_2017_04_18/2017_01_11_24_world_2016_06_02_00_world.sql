DELETE FROM `spell_script_names` where `ScriptName` IN ('spell_jormungars_burning_spray','spell_jormungars_paralytic_spray','spell_jormungars_paralytic_toxin','spell_jormungars_paralysis');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66902,'spell_jormungars_burning_spray'), -- Burning Spray
(66901,'spell_jormungars_paralytic_spray'), -- Paralytic Spray
(66823,'spell_jormungars_paralytic_toxin'), -- Paralytic Toxin
(66830,'spell_jormungars_paralysis'); -- Paralysis

-- Acidmaw missing text
DELETE FROM `creature_text` where entry = 35144 AND groupid = 1;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(35144,1,0,'You have been infected with a Paralytic Toxin!',42,0,100,0,0,0,36323,0,'Acidmaw - Special Attack');
