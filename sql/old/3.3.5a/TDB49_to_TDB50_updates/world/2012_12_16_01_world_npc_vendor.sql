-- Red Rider Air Rifle
DELETE FROM `npc_vendor` WHERE `entry` IN (29478,29716) AND `item`=46725;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(29478,0,46725,0,0,0), -- Jepetto Joybuzz <Toymaker>
(29716,0,46725,0,0,0); -- Clockwork Assistant <Jepetto's Companion>

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceEntry`=46725;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(23,29478,46725,0,0,12,0,2,0,0,0,0,0,'','Rotes Erbsengewehr / Jepetto Joybuzz <Toymaker> - only for Winter Veil'),
(23,29716,46725,0,0,12,0,2,0,0,0,0,0,'','Rotes Erbsengewehr / Clockwork Assistant <Jepetto''s Companion> - only for Winter Veil');
