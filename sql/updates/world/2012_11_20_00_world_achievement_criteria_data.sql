-- Achievement: Pilgrim's Peril
-- Based on Vincent-Michael fix
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (11134,11135,11136,11137,11138,11139,11140,11141);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
-- Horde
(11134,6,14,0,''), -- Orgrimmar
(11134,11,0,0,'achievement_piligrims_peril'),
(11134,16,404,0,''), -- Orgrimmar
(11135,6,3470,0,''), -- Silvermoon City
(11135,11,0,0,'achievement_piligrims_peril'),
(11135,16,404,0,''), -- Silvermoon City
(11136,6,1638,0,''), -- Thunder Bluff
(11136,11,0,0,'achievement_piligrims_peril'),
(11136,16,404,0,''), -- Thunder Bluff
(11137,6,1497,0,''), -- Undercity
(11137,11,0,0,'achievement_piligrims_peril'),
(11137,16,404,0,''), -- Undercity
-- Alliance
(11138,6,3557,0,''), -- Exodar
(11138,11,0,0,'achievement_piligrims_peril'),
(11138,16,404,0,''), -- Exodar
(11139,6,1657,0,''), -- Darnassus
(11139,11,0,0,'achievement_piligrims_peril'),
(11139,16,404,0,''), -- Darnassus
(11140,6,809,0,''), -- Ironforge
(11140,11,0,0,'achievement_piligrims_peril'),
(11140,16,404,0,''), -- Ironforge
(11141,6,12,0,''), -- Stormwind
(11141,11,0,0,'achievement_piligrims_peril'),
(11141,16,404,0,''); -- Stormwind
