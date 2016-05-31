-- Finding the Keymaster by nelegalno

UPDATE `quest_template` SET `SpecialFlags` = 0, `RequiredSpellCast1` = 0 WHERE `ID` = 10256;
DELETE FROM `event_scripts` WHERE id=12857;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(12857,0,10,19938,3000000,0,2248.43,2227.97,138.56,2.48121),
(12857,1,8,19938,1,0,0,0,0,0);
