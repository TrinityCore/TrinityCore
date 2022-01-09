-- 
DELETE FROM `creature_addon` WHERE `guid` IN (121091,121122,121130,124617);
UPDATE `creature_template_addon` SET `auras`="57836" WHERE `entry` IN (30742, 30744,30950,30745);
DELETE FROM `spell_scripts` WHERE `id`=57852;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(57852,0,0,15,46419,2,0,0,0,0,0),
(57852,0,0,15,57931,2,0,0,0,0,0);
