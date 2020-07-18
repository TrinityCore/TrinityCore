--
SET @Shark := 50289;

DELETE FROM `gameobject_loot_template` WHERE `Item`= @Shark;
INSERT INTO `gameobject_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(25662, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Glacial Salmon School - Blacktip Shark'),
(25663, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Fangtooth Herring School - Blacktip Shark'),
(25664, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Dragonfin Angelfish School - Blacktip Shark'),
(25665, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Musselback Sculpin School - Blacktip Shark'),
(25668, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Imperial Manta Ray School - Blacktip Shark'),
(25670, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Moonglow Cuttlefish School - Blacktip Shark'),
(25671, @Shark, 0, 1, 0, 1, 7, 1, 1, 'Deep Sea Monsterbelly School - Blacktip Shark'),
(25673, @Shark, 0, 1, 0, 1, 4, 1, 1, 'Nettlefish School - Blacktip Shark'),
(25674, @Shark, 0, 1, 0, 1, 3, 1, 1, 'Glassfin Minnow School - Blacktip Shark');

-- Blacktip Shark loot Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 4 AND `SourceGroup` IN (25662,25663,25664,25665,25668,25670,25671,25673,25674) AND `SourceEntry`= @Shark;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(4, 25662, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Glacial Salmon School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25663, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Fangtooth Herring School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25664, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Dragonfin Angelfish School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25665, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Musselback Sculpin School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25668, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Imperial Manta Ray School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25670, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Moonglow Cuttlefish School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25671, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Deep Sea Monsterbelly School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25673, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Nettlefish School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active"),
(4, 25674, @Shark, 0, 0, 12, 0, 63, 0, 0, 0, 0, 0, '', "Glassfin Minnow School drops Blacktip Shark only when event 'Kalu'ak Fishing Derby' is active");
