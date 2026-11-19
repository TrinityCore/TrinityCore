DELETE FROM `areatrigger_scripts` WHERE `entry` IN (5732 /*entrance Lord Marrowgar*/, 5708/*Blood Prince Council*/, 5709 /*entrance Lady Deathwhisper*/);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5732, 'at_lord_marrowgar_entrance'),
(5708, 'at_blood_prince_council_start_intro'),
(5709, 'at_lady_deathwhisper_entrance');
