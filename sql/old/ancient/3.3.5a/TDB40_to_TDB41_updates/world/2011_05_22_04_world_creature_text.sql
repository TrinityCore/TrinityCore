DELETE FROM `creature_text` WHERE `entry` IN (37007,37491,37493,37494,37495);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(37007,0,0, 'The master''s sanctum has been disturbed!',14,0,0,0,0,16865, 'Deathbound Ward - SAY_TRAP_ACTIVATE'),
(37007,0,1, 'I... awaken!',14,0,0,0,0,16866, 'Deathbound Ward - SAY_TRAP_ACTIVATE'),
(37007,0,2, 'Who... goes there...?',14,0,0,0,0,16867, 'Deathbound Ward - SAY_TRAP_ACTIVATE'),
(37491,1,0, 'You miserable fools never did manage to select a decent bat wing.',14,0,0,0,0,16587, 'Captain Arnath - SAY_ARNATH_RESURRECTED'),
(37491,2,0, 'THAT was for bringing me spoiled spider ichor!',14,0,0,0,0,16588, 'Captain Arnath - SAY_ARNATH_KILL'),
(37491,3,0, 'Don''t... let Finklestein use me... for his potions...',14,0,0,0,0,16589, 'Captain Arnath - SAY_ARNATH_SECOND_DEATH'),
(37493,1,0, 'What? This strength...? All of the pain is gone! You... must join me in the eternal embrace of death!',14,0,0,0,0,16811, 'Captain Brandon - SAY_BRANDON_RESURRECTED'),
(37493,2,0, 'It doesn''t hurt anymore, does it?',14,0,0,0,0,16812, 'Captain Brandon - SAY_BRANDON_KILL'),
(37493,3,0, 'I''m sorry...',14,0,0,0,0,16813, 'Captain Brandon - SAY_BRANDON_SECOND_DEATH'),
(37494,1,0, 'No! Why was I denied a death by flame? You must all BURN!',14,0,0,0,0,16845, 'Captain Grondel - SAY_GRONDEL_RESURRECTED'),
(37494,2,0, 'Can you feel the burn?',14,0,0,0,0,16846, 'Captain Grondel - SAY_GRONDEL_KILL'),
(37494,3,0, 'What... have I done? No!',14,0,0,0,0,16847, 'Captain Grondel - SAY_GRONDEL_SECOND_DEATH'),
(37495,1,0, 'There is no escaping the Lich King''s will. Prepare for an explosive encounter!',14,0,0,0,0,16999, 'Captain Rupert - SAY_RUPERT_RESURRECTED'),
(37495,2,0, 'So that''s what happens when you stand too close to a bomb!',14,0,0,0,0,17000, 'Captain Rupert - SAY_RUPERT_KILL'),
(37495,3,0, 'What an... explosive ending!',14,0,0,0,0,17001, 'Captain Rupert - SAY_RUPERT_SECOND_DEATH');
