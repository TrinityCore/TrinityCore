DELETE FROM `creature_text` where entry in (41376,41379);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(41379, 0, 0, 'Ha ha ha ha ha! The heroes have made it to the glorious finale! I take it you are in good spirits? Prepared for the final battle? Then gaze now upon my ultimate creation! RISE, SISTER!', 14, 0, 100, 0, 0, 20066, 'VO_BD_Nefarian_Intro'),
(41379, 1, 0, 'Behold, the Broodmother... Onyxia... REBORN. Perhaps my finest work.', 14, 0, 100, 0, 0, 20070, 'VO_BD_Nefarian_Intro'),
(41379, 2, 0, 'My dearest sibling... do you hunger? THEN FEAST UPON OUR ENEMIES!', 14, 0, 100, 0, 0, 20071, 'VO_BD_Nefarian_Intro'),
(41376, 0, 0, 'Cowards! Face the broodmother or face dire consequences!', 14, 0, 100, 0, 0, 20072, 'VO_BD_Nefarian_Battle'),
(41376, 1, 0, 'See how the shadowflame animates the bones? They fight at my command!', 14, 0, 100, 0, 0, 20073, 'VO_BD_Nefarian_Battle'),
(41376, 2, 0, 'Curse you mortals! Such callous disregard for one\'s possessions must be met with extreme force.', 14, 0, 100, 0, 0, 20082, 'VO_BD_Nefarian_Battle'),
(41376, 3, 0, 'I hope you can swim... IN MOLTEN LAVA!', 14, 0, 100, 0, 0, 20075, 'VO_BD_Nefarian_Battle'),
(41376, 4, 0, 'I have tried to be an accomodating host, but you simply will not die. Time to throw all pretexts aside and just KILL YOU ALL!', 14, 0, 100, 0, 0, 20077, 'VO_BD_Nefarian_Battle'),
(41376, 5, 0, 'Flesh turns to ash!', 14, 0, 100, 0, 0, 20074, 'VO_BD_Nefarian_Battle'),
(41376, 6, 0, 'It has been a pleasure!', 14, 0, 50, 0, 0, 20079, 'VO_BD_Nefarian_Battle'),
(41376, 6, 1, 'You really have to want it!', 14, 0, 50, 0, 0, 20081, 'VO_BD_Nefarian_Battle'),
(41376, 7, 0, 'Defeat has never tasted so bitter...', 14, 0, 100, 0, 0, 20083, 'VO_BD_Nefarian_Battle');

DELETE FROM `spell_script_names` WHERE `spell_id` = (77827);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77827, 'spell_nefarian_tail_lash');

DELETE FROM `spell_script_names` WHERE `spell_id` = (77944);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77944, 'spell_onyxia_lightning_discharge');