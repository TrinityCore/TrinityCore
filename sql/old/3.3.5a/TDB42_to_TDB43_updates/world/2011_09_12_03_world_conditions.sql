-- Fix to Spell targets for Ignis adds
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62343;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62488;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62343,0,18,1,33121,0,0, '', 'Heat to Iron Construct'),
(13,0,62488,0,18,1,33121,0,0, '', 'Activate Construct to iron Construct');

-- Burn Secondary Effect from Vehicles
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=65044;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,65044,1,18,1,34234,0,0, '', 'Flames to Runeforged Sentry'),
(13,0,65044,2,18,1,33236,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65044,3,18,1,33572,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65044,4,18,1,33237,0,0, '', 'Flames to Ulduar Colossus'),
(13,0,65044,5,18,1,33189,0,0, '', 'Flames to Liquid pyrite'),
(13,0,65044,6,18,1,33090,0,0, '', 'Flames to Pool of Tar'),
(13,0,65044,7,18,1,34161,0,0, '', 'Flames to Mechanostriker 54-A');

-- Burn Secondary Effect from Vehicles
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=65045;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,65045,1,18,1,34234,0,0, '', 'Flames to Runeforged Sentry'),
(13,0,65045,2,18,1,33236,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65045,3,18,1,33572,0,0, '', 'Flames to Steelforged Defender'),
(13,0,65045,4,18,1,33237,0,0, '', 'Flames to Ulduar Colossus'),
(13,0,65045,5,18,1,33189,0,0, '', 'Flames to Liquid pyrite'),
(13,0,65045,6,18,1,33090,0,0, '', 'Flames to Pool of Tar'),
(13,0,65045,7,18,1,34161,0,0, '', 'Flames to Mechanostriker 54-A');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62911;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62911,0,18,1,33365,0,0, '', 'Thorim\'s Hammer to Thorim\'s Hammer');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62906;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62906,0,18,1,33367,0,0, '', 'Freya\'s Ward to Freya\'s Ward');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=62705;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62705,1,18,1,33060,0,0, '', 'Auto-repair to Salvaged Siege Engine'),
(13,0,62705,2,18,1,33067,0,0, '', 'Auto-repair to Salvaged Siege Turret'),
(13,0,62705,3,18,1,33062,0,0, '', 'Auto-repair to Salvaged Chopper'),
(13,0,62705,4,18,1,33109,0,0, '', 'Auto-repair to Salvaged Demolisher'),
(13,0,62705,5,18,1,33167,0,0, '', 'Auto-repair to Salvaged Demolisher Mechanic Seat');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=63294;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,63294,0,18,1,33367,0,0, '', 'Freya Dummy Blue to Freya\'s Ward');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=63295;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,63295,0,18,1,33367,0,0, '', 'Freya Dummy Green to Freya\'s Ward');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=63292;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,63292,0,18,1,33367,0,0, '', 'Freya Dummy Yellow to Freya\'s Ward');
