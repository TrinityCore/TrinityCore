DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (63573,63766,63716,62030,62166,63347) OR `spellid0` IN (63573,63766,63716,62030,62166,63347);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(63573,63573,64006), -- One-Armed Overhead Smash
(63766,63766,63983), -- Arm Sweep
(63716,63716,64005), -- Stone Shout
(62030,62030,63980), -- Petrifying Breath
(62166,62166,64005), -- Stone Grip
(63347,63347,63977); -- Focused Eyebeam Periodic
