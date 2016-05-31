DELETE FROM `disables` WHERE `sourceType`=4 AND `entry` IN (7567,7568);

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (7567,7568);
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(7567,11,0,0,'achievement_the_hundred_club'),
(7567,12,0,0,''),
(7568,11,0,0,'achievement_the_hundred_club'),
(7568,12,1,0,'');

DELETE FROM `script_texts` WHERE `entry` IN (-1533082,-1533083);

DELETE FROM `creature_text` WHERE `entry`=15989;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15989,0,0,'Sapphiron lifts off into the air!',41,0,100,254,0,0,'Sapphiron'),
(15989,1,0,'Sapphiron resumes his attacks!',41,0,100,0,0,0,'Sapphiron'),
(15989,2,0,'%s takes a deep breath.',41,7,100,0,0,0,'Sapphiron'),
(15989,3,0,'%s enrages!',41,0,100,0,0,0,'Sapphiron');

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (28531,55697,28542,28547) OR `spellid0` IN (28531,55697,28542,28547);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(28531,28531,55799), -- Frost Aura
(55697,55697,55696), -- Tail Sweep
(28542,28542,55665), -- Life Drain
(28547,28547,55699); -- Chill
