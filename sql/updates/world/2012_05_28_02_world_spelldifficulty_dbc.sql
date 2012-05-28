SET @DIFF := xxxx; -- set by TDB team
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (@DIFF+0,@DIFF+1);
INSERT INTO `spelldifficulty_dbc` (`id`,`spelld0`,`spellid1`,`spelld2`,`spellid3`) VALUES
(@DIFF+0,57762,57763,0,0),
(@DIFF+1,59990,61489,0,0);
