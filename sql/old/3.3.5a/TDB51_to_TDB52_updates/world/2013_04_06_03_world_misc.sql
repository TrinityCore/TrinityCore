DELETE FROM `gameobject_loot_template` WHERE `entry`=24320 AND `item` IN (38340,38341,38397);
DELETE FROM `gameobject_loot_template` WHERE `entry`=24326 AND `item`=38397;
DELETE FROM `gameobject_loot_template` WHERE `entry`=24330 AND `item`=38335;
DELETE FROM `gameobject_loot_template` WHERE `entry`=25028 AND `item`=38337;

UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=100 WHERE `entry` BETWEEN 24319 AND 24340;
UPDATE `gameobject_loot_template` SET `ChanceOrQuestChance`=100 WHERE `entry` IN (25026,25027,25028);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (51060,51068,51088,51094);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(51060,51226,1,'On spellhit Have Withered Batwing - Spellcast Withered Batwing Kill Credit'),
(51068,51227,1,'On spellhit Have Muddy Mire Maggot - Spellcast Muddy Mire Maggot Kill Credit'),
(51088,51228,1,'On spellhit Have Amberseed - Spellcast Amberseed Kill Credit'),
(51094,51229,1,'On spellhit Have Chilled Serpent Mucus - Spellcast Chilled Serpent Mucus Kill Credit');

DELETE FROM `spell_dbc` WHERE `Id`=50574;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`CastingTimeIndex`,`ProcChance`,`RangeIndex`,`EquippedItemClass`,`Effect1`,`EffectMiscValue1`,`EffectImplicitTargetA1`,`SchoolMask`,`Comment`) VALUES
(50574,256,1,101,11,-1,90,28042,25,1,'Captain Brandon Kill Credit');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9668 AND `SourceEntry` IN (13098,13119);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9668 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9668,13098,0,9,12587,0,0,0,'','Alchemist Finklestein - Show different gossip if player has taken quest Troll Patrol'),
(14,9668,13119,0,9,12541,0,0,0,'','Alchemist Finklestein - Show different gossip if player has taken quest Troll Patrol: The Alchemist''s Apprentice'),
(15,9668,0,0,9,12541,0,0,0,'','Alchemist Finklestein - Show gossip option only if player has taken quest Troll Patrol: The Alchemist''s Apprentice');
