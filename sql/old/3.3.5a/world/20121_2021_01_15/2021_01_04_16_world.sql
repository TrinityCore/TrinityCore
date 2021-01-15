-- Since previously that flag was used as hacky way to disable movement, apply corrections based on sniffs and\or CreatureDifficulty while at it
UPDATE `creature_template_movement` SET `Rooted` = 0 WHERE `CreatureId` IN (16400,20561,21413,23996,33342);
UPDATE `creature_template_movement` SET `Flight` = 1, `Rooted` = 0 WHERE `CreatureId` = 20251;
UPDATE `creature_template_movement` SET `Flight` = 1 WHERE `CreatureId` = 23077;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 0x00000004 WHERE `entry` IN (1921,5674,14697,16236,16400,18679,18695,20251,20561,21413,23076,23077,23876,23996,25284,25534,27064,27894,28156,28366,29475,29483,29613,29747,29790,30236,30475,31103,31280,31424,32347,32795,32938,33174,33184,33229,33243,33272,33342,33352,33353,33651,34047,34050,34071,34096,34108,34110,34121,34149,34362,34363);
