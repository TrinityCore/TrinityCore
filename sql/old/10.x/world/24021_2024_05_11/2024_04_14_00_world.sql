UPDATE `gameobject_loot_template` SET `QuestRequired`=0 WHERE `Entry` IN (40856, 40859, 40860, 40861, 40862, 40863, 40864);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 34 AND `SourceEntry` IN (13360, 13361, 13362, 13363, 13364, 13365, 13366));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Monk
(34, 0, 13360, 0, 0, 2, 0, 73209, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13360 if player doesn''t have item 73209'),

-- Warlock and Mage
(34, 0, 13361, 0, 0, 2, 0, 76390, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13361 if player doesn''t have item 76390'),
(34, 0, 13361, 0, 1, 2, 0, 76392, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13361 if player doesn''t have item 76392'),

-- Hunter
(34, 0, 13362, 0, 0, 2, 0, 73211, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13362 if player doesn''t have item 73211'),

-- Priest
(34, 0, 13363, 0, 0, 2, 0, 73207, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13363 if player doesn''t have item 73207'),
(34, 0, 13363, 0, 1, 2, 0, 76393, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13363 if player doesn''t have item 76393'),

-- Warrior
(34, 0, 13364, 0, 0, 2, 0, 73213, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13364 if player doesn''t have item 73213'),
(34, 0, 13364, 0, 1, 2, 0, 76391, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13364 if player doesn''t have item 76391'),

-- Rogue
(34, 0, 13365, 0, 0, 2, 0, 73208, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13365 if player doesn''t have item 73208'),
(34, 0, 13365, 0, 1, 2, 0, 73212, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13365 if player doesn''t have item 73212'),

-- Shaman
(34, 0, 13366, 0, 0, 2, 0, 73213, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13366 if player doesn''t have item 73213'),
(34, 0, 13366, 0, 1, 2, 0, 76391, 1, 0, 1, 0, 0, '', 'Satisfy PlayerCondition 13366 if player doesn''t have item 76391');
