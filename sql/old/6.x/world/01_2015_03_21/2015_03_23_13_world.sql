-- Add conditions to prevent Anti-Air Rocket friendly fire
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62363;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62363,0,1,31,0,3,33236,0,0,0,'','Anti-Air Rocket can hit Steelforged Defender'),
(13,2,62363,0,1,31,0,3,33236,0,0,0,'','Anti-Air Rocket can hit Steelforged Defender'),
(13,1,62363,0,2,31,0,3,34234,0,0,0,'','Anti-Air Rocket can hit Runeforged Sentry'),
(13,2,62363,0,2,31,0,3,34234,0,0,0,'','Anti-Air Rocket can hit Runeforged Sentry'),
(13,1,62363,0,3,31,0,3,33237,0,0,0,'','Anti-Air Rocket can hit Ulduar Colossus'),
(13,2,62363,0,3,31,0,3,33237,0,0,0,'','Anti-Air Rocket can hit Ulduar Colossus'),
(13,1,62363,0,4,31,0,3,34164,0,0,0,'','Anti-Air Rocket can hit Mechagnome Battletank'),
(13,2,62363,0,4,31,0,3,34164,0,0,0,'','Anti-Air Rocket can hit Mechagnome Battletank'),
(13,1,62363,0,5,31,0,3,33264,0,0,0,'','Anti-Air Rocket can hit Ironwork Canon'),
(13,2,62363,0,5,31,0,3,33264,0,0,0,'','Anti-Air Rocket can hit Ironwork Canon'),
(13,1,62363,0,6,31,0,3,33214,0,0,0,'','Anti-Air Rocket can hit Mechanolift 304-A'),
(13,2,62363,0,6,31,0,3,33214,0,0,0,'','Anti-Air Rocket can hit Mechanolift 304-A'),
(13,1,62363,0,7,31,0,3,33113,0,0,0,'','Anti-Air Rocket can hit Flame Leviathan'),
(13,2,62363,0,7,31,0,3,33113,0,0,0,'','Anti-Air Rocket can hit Flame Leviathan'),
(13,1,62363,0,8,31,0,3,34161,0,0,0,'','Anti-Air Rocket can hit Mechanostriker 54-A'),
(13,2,62363,0,8,31,0,3,34161,0,0,0,'','Anti-Air Rocket can hit Mechanostriker 54-A'),
(13,1,62363,0,9,31,0,3,34275,0,0,0,'','Anti-Air Rocket can hit Ward of Life'),
(13,2,62363,0,9,31,0,3,34275,0,0,0,'','Anti-Air Rocket can hit Ward of Life'),
(13,1,62363,0,10,31,0,3,33387,0,0,0,'','Anti-Air Rocket can hit Writhing Lasher'),
(13,2,62363,0,10,31,0,3,33387,0,0,0,'','Anti-Air Rocket can hit Writhing Lasher');
-- Add conditions to prevent Hurl Boulder friendly fire // Flames are supposed to do Friendly Damage, since they break Ice in HM
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62307;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62307,0,1,31,0,3,33236,0,0,0,'','Hurl Boulder can hit Steelforged Defender'),
(13,1,62307,0,2,31,0,3,34234,0,0,0,'','Hurl Boulder can hit Runeforged Sentry'),
(13,1,62307,0,3,31,0,3,33237,0,0,0,'','Hurl Boulder can hit Ulduar Colossus'),
(13,1,62307,0,4,31,0,3,34164,0,0,0,'','Hurl Boulder can hit Mechagnome Battletank'),
(13,1,62307,0,5,31,0,3,33264,0,0,0,'','Hurl Boulder can hit Ironwork Canon'),
(13,1,62307,0,6,31,0,3,33214,0,0,0,'','Hurl Boulder can hit Mechanolift 304-A'),
(13,1,62307,0,7,31,0,3,33113,0,0,0,'','Hurl Boulder can hit Flame Leviathan'),
(13,1,62307,0,8,31,0,3,33090,0,0,0,'','Hurl Boulder can hit Pool of Tar'),
(13,1,62307,0,9,31,0,3,34161,0,0,0,'','Hurl Boulder can hit Mechanostriker 54-A'),
(13,1,62307,0,10,31,0,3,34275,0,0,0,'','Hurl Boulder can hit Ward of Life'),
(13,1,62307,0,11,31,0,3,33387,0,0,0,'','Hurl Boulder can hit Writhing Lasher');
-- Add conditions to prevent Mortar friendly fire // Flames are supposed to do Friendly Damage, since they break Ice in HM
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62635;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62635,0,1,31,0,3,33236,0,0,0,'','Mortar can hit Steelforged Defender'),
(13,1,62635,0,2,31,0,3,34234,0,0,0,'','Mortar can hit Runeforged Sentry'),
(13,1,62635,0,3,31,0,3,33237,0,0,0,'','Mortar can hit Ulduar Colossus'),
(13,1,62635,0,4,31,0,3,34164,0,0,0,'','Mortar can hit Mechagnome Battletank'),
(13,1,62635,0,5,31,0,3,33264,0,0,0,'','Mortar can hit Ironwork Canon'),
(13,1,62635,0,6,31,0,3,33214,0,0,0,'','Mortar can hit Mechanolift 304-A'),
(13,1,62635,0,7,31,0,3,33113,0,0,0,'','Mortar can hit Flame Leviathan'),
(13,1,62635,0,8,31,0,3,33090,0,0,0,'','Mortar can hit Pool of Tar'),
(13,1,62635,0,9,31,0,3,34161,0,0,0,'','Mortar can hit Mechanostriker 54-A'),
(13,1,62635,0,10,31,0,3,34275,0,0,0,'','Mortar can hit Ward of Life'),
(13,1,62635,0,11,31,0,3,33387,0,0,0,'','Mortar can hit Writhing Lasher');
-- Add conditions to prevent Fire Cannon friendly fire // Flames are supposed to do Friendly Damage, since they break Ice in HM
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62357;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62357,0,1,31,0,3,33236,0,0,0,'','Fire Cannon can hit Steelforged Defender'),
(13,1,62357,0,2,31,0,3,34234,0,0,0,'','Fire Cannon can hit Runeforged Sentry'),
(13,1,62357,0,3,31,0,3,33237,0,0,0,'','Fire Cannon can hit Ulduar Colossus'),
(13,1,62357,0,4,31,0,3,34164,0,0,0,'','Fire Cannon can hit Mechagnome Battletank'),
(13,1,62357,0,5,31,0,3,33264,0,0,0,'','Fire Cannon can hit Ironwork Canon'),
(13,1,62357,0,6,31,0,3,33214,0,0,0,'','Fire Cannon can hit Mechanolift 304-A'),
(13,1,62357,0,7,31,0,3,33113,0,0,0,'','Fire Cannon can hit Flame Leviathan'),
(13,1,62357,0,8,31,0,3,33090,0,0,0,'','Fire Cannon can hit Pool of Tar'),
(13,1,62357,0,9,31,0,3,34161,0,0,0,'','Fire Cannon can hit Mechanostriker 54-A'),
(13,1,62357,0,10,31,0,3,34275,0,0,0,'','Fire Cannon can hit Ward of Life'),
(13,1,62357,0,11,31,0,3,33387,0,0,0,'','Fire Cannon can hit Writhing Lasher');
-- Add conditions to prevent Burning Tar friendly fire // Flames are supposed to do Friendly Damage, since they break Ice in HM
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62290;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62290,0,1,31,0,3,33236,0,0,0,'','Burning Tar can hit Steelforged Defender'),
(13,1,62290,0,2,31,0,3,34234,0,0,0,'','Burning Tar can hit Runeforged Sentry'),
(13,1,62290,0,3,31,0,3,33237,0,0,0,'','Burning Tar can hit Ulduar Colossus'),
(13,1,62290,0,4,31,0,3,34164,0,0,0,'','Burning Tar can hit Mechagnome Battletank'),
(13,1,62290,0,5,31,0,3,33264,0,0,0,'','Burning Tar can hit Ironwork Canon'),
(13,1,62290,0,6,31,0,3,33214,0,0,0,'','Burning Tar can hit Mechanolift 304-A'),
(13,1,62290,0,7,31,0,3,33113,0,0,0,'','Burning Tar can hit Flame Leviathan'),
(13,1,62290,0,8,31,0,3,33090,0,0,0,'','Burning Tar can hit Pool of Tar'),
(13,1,62290,0,9,31,0,3,34161,0,0,0,'','Burning Tar can hit Mechanostriker 54-A'),
(13,1,62290,0,10,31,0,3,34275,0,0,0,'','Burning Tar can hit Ward of Life'),
(13,1,62290,0,11,31,0,3,33387,0,0,0,'','Burning Tar can hit Writhing Lasher');
-- Add conditions to prevent Blue Pyrite friendly fire
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62489;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,62489,0,1,31,0,3,33236,0,0,0,'','Blue Pyrite can hit Steelforged Defender'),
(13,1,62489,0,2,31,0,3,34234,0,0,0,'','Blue Pyrite can hit Runeforged Sentry'),
(13,1,62489,0,3,31,0,3,33237,0,0,0,'','Blue Pyrite can hit Ulduar Colossus'),
(13,1,62489,0,4,31,0,3,34164,0,0,0,'','Blue Pyrite can hit Mechagnome Battletank'),
(13,1,62489,0,5,31,0,3,33264,0,0,0,'','Blue Pyrite can hit Ironwork Canon'),
(13,1,62489,0,6,31,0,3,33214,0,0,0,'','Blue Pyrite can hit Mechanolift 304-A'),
(13,1,62489,0,7,31,0,3,33113,0,0,0,'','Blue Pyrite can hit Flame Leviathan'),
(13,1,62489,0,8,31,0,3,33090,0,0,0,'','Blue Pyrite can hit Pool of Tar'),
(13,1,62489,0,9,31,0,3,34161,0,0,0,'','Blue Pyrite can hit Mechanostriker 54-A'),
(13,1,62489,0,10,31,0,3,34275,0,0,0,'','Blue Pyrite can hit Ward of Life'),
(13,1,62489,0,11,31,0,3,33387,0,0,0,'','Blue Pyrite can hit Writhing Lasher');
