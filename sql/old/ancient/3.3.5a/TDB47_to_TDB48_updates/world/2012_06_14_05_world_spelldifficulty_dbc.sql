SET @DIFF := 3268; -- set by TDB team
DELETE FROM `spelldifficulty_dbc` WHERE `id` BETWEEN @DIFF+0 AND @DIFF+2;
INSERT INTO `spelldifficulty_dbc` (`id`,`spellid0`,`spellid1`,`spellid2`,`spellid3`) VALUES
(@DIFF+0,50811,61547,0,0),
(@DIFF+1,57762,59990,0,0),
(@DIFF+2,57763,61489,0,0);
