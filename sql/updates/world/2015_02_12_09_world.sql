-- A Daughter's Embrace

SET @Scarlet1:=   1538;
SET @Scarlet2:=   1540;
SET @Scarlet3:=   1539;
SET @Scarlet4:=   1537;
SET @Scarlet5:=   1536;
SET @Scarlet6:=   1535;
SET @Lilian:=     39038;
SET @Nova:=       32711;
SET @BodyGuard:=  1660;
SET @Melrache:=   1665;
SET @Benedictus:= 39097;
SET @Jump:=       73308;
SET @Sanders:=    13158;
Set @Summon:=     73306;
Set @Aura:=       73305;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Sanders;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet1;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet2;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet3;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet4;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet5;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet6;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Benedictus;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Melrache;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@BodyGuard;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Lilian;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Sanders AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Lilian*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BodyGuard AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @BodyGuard*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Melrache AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Melrache*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Benedictus AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Benedictus*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet1 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet2 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet3;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet3 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet4;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet4 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet5;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet5 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Scarlet6;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Scarlet6 AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Scarlet1, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet2, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet3, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet4, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet5, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet6, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Scarlet - On Aggro - talk'),
(@Scarlet1, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet1 - IC - CAST'),
(@Scarlet1, 0, 2, 0, 0, 0, 100, 0, 4000, 4000, 18000, 18000, 11, 75967, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet1 - IC - CAST'),
(@Scarlet2, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet2, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 180000, 180000, 11, 7164, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet2, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 8000, 8000, 11, 11972, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet2 - IC - CAST'),
(@Scarlet3, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 10000, 10000, 11, 64431, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet3, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 30000, 30000, 11, 12544, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet3, 0, 3, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 13322, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet3 - IC - CAST'),
(@Scarlet4, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 84535, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet4 - IC - CAST'),
(@Scarlet5, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 4000, 4000, 11, 9053, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet5 - IC - CAST'),
(@Scarlet6, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 5000, 5000, 11, 57846, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Scarlet6 - IC - CAST'),
(@Sanders, 0, 0, 0, 19, 0, 100, 0, 25046, 0, 0, 0, 85, @Summon, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sanders - On Quest Accept - Summon'),
(@Lilian, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @Lilian*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On Spawn - action list'),
(@Lilian*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Aura, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sanders - Actionlist - CastSpell'),
(@Lilian*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - react defensif'),
(@Lilian, 0, 1, 0, 0, 0, 100, 0, 0, 0, 4000, 4000, 11, @Nova, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Lilian, 0, 2, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, 11, 73309, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Lilian, 0, 3, 0, 0, 0, 100, 0, 0, 0, 5000, 5000, 11, @Aura, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shadow - IC - CastSpell'),
(@Benedictus, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @Benedictus*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@Benedictus*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@Benedictus*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@Melrache, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @Melrache*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@Melrache*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@Melrache*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@BodyGuard, 0, 0, 0, 75, 0, 100, 1, 0, @Lilian, 30, 0, 80, @BodyGuard*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - On creature distance - action list'),
(@BodyGuard*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - reactPassif'),
(@BodyGuard*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Benedictus - actionList - UnitFlag'),
(@Lilian, 0, 4, 0, 75, 0, 100, 1, 0, @Benedictus, 20, 0, 80, @Lilian*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - On creature distance - action list'),
(@Lilian*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - Go to position'),
(@Lilian*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk1'),
(@Lilian*100+1, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk1'),
(@Lilian*100+1, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk2'),
(@Lilian*100+1, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list- CastSpell'),
(@Lilian*100+1, 9, 6, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @BodyGuard, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Kill'),
(@Lilian*100+1, 9, 7, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 8, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 9, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Melrache, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Kill'),
(@Lilian*100+1, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - Go to position'),
(@Lilian*100+1, 9, 11, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3071.607178, -563.239685, 126.717987, 0.647956, 'Lilian - action list - SetOrientation'),
(@Lilian*100+1, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk 3'),
(@Lilian*100+1, 9, 13, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk2'),
(@Lilian*100+1, 9, 14, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - talk4'),
(@Lilian*100+1, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Talk5'),
(@Lilian*100+1, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - Talk3'),
(@Lilian*100+1, 9, 17, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 11, @Jump, 2, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 18, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, @Nova, 2, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - CastSpell'),
(@Lilian*100+1, 9, 19, 0, 0, 0, 100, 0, 500, 500, 0, 0, 51, 0, 0, 0, 0, 0, 0, 19, @Benedictus, 20, 0, 0, 0, 0, 0, 'Lilian - action list - kill'),
(@Lilian*100+1, 9, 20, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 39098, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 'Lilian - Actionlist - Credit quest'),
(@Lilian*100+1, 9, 21, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - talk6'),
(@Lilian*100+1, 9, 22, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lilian - action list - Despawn');

DELETE FROM `creature_text` WHERE `entry` IN (@Scarlet1, @Scarlet2, @Scarlet3, @Scarlet4, @Scarlet5, @Scarlet6, @Lilian, @Benedictus ) ;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Scarlet1, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet1, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet1, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet1, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet2, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet2, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet2, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet2, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet3, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet3, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet3, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet3, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet4, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet4, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet4, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet4, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet5, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet5, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet5, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet5, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Scarlet6, 0, 0, 'The Scarlet Crusade shall smite the wicked and drive evil from these lands!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2628),
(@Scarlet6, 0, 1, 'There is no escape for you.  The Crusade shall destroy all who carry the Scourge''s taint.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2626),
(@Scarlet6, 0, 2, 'The Light condemns all who harbor evil. Now you will die!', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2627),
(@Scarlet6, 0, 3, 'You carry the taint of the Scourge. Prepare to enter the Twisting Nether.', 12, 0, 100, 0, 0, 0, 'Scarlet1', 2625),
(@Lilian, 0, 0, 'Father!', 12, 0, 100, 0, 0, 0, 'Lilian', 39138),
(@Lilian, 1, 0, 'Shut up.', 12, 0, 100, 0, 0, 0, 'Lilian', 39140),
(@Lilian, 2, 0, 'You raised me to be a killer.  How am I doing, daddy?', 12, 0, 100, 0, 0, 0, 'Lilian', 39141),
(@Lilian, 3, 0, 'But wait... I remember now. You taught me to only kill the undead. So you do want me to kill myself, daddy?', 12, 0, 100, 0, 0, 0, 'Lilian', 39143),
(@Lilian, 4, 0, 'Then again, why kill myself... when I can kill YOU instead!', 12, 0, 100, 0, 0, 0, 'Lilian', 39145),
(@Lilian, 5, 0, 'Thanks for everything... father.', 12, 0, 100, 0, 0, 0, 'Lilian', 39146),
(@Benedictus, 0, 0, 'Lilian... you''re... it''s so nice to see you well.', 12, 0, 100, 0, 0, 0, 'Benedictus', 39139),
(@Benedictus, 1, 0, 'I, ah...', 12, 0, 100, 0, 0, 0, 'Benedictus', 39142),
(@Benedictus, 2, 0, 'Lilian, I...', 12, 0, 100, 0, 0, 0, 'Benedictus', 39144);
