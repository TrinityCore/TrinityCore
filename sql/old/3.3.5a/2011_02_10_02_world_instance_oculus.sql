-- planar anomaly
DELETE FROM creature_template_addon WHERE entry=30879;
INSERT INTO creature_template_addon (`entry`,`auras`) VALUES (30879,'57971 0');
UPDATE `creature_template` SET `InhabitType`=5 WHERE `entry`=30879;

-- spell script target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=57963;
INSERT INTO `conditions` (SourceTypeOrReferenceId, SourceGroup, SourceEntry, ElseGroup, ConditionTypeOrReference, ConditionValue1, ConditionValue2, ConditionValue3, ErrorTextId, ScriptName, COMMENT) VALUES 
(13,0,57963,0,18,1,27656,0,0,'',NULL);

-- not sure about this, execute at your own risk
-- DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE `id`=28276);
-- DELETE FROM `creature` WHERE `id`=28276;

-- here we handle which spells are usable depending on Urom's event state.
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId=21 AND `SourceGroup` IN (27756,27755,27692);
INSERT INTO `conditions` (SourceTypeOrReferenceId,SourceGroup,SourceEntry,ConditionTypeOrReference,ConditionValue1,ConditionValue2) VALUES
(21,27756,50253,13,2,3), -- Ruby Drake
(21,27755,49592,13,2,3), -- Amber Drake
(21,27692,50344,13,2,3); -- Esmerald Drake

-- correcting vehicles
UPDATE `creature_template` SET `spell1`=50232,`spell2`=50248,`spell3`=50240,`spell4`=50253,`spell5`=0 WHERE `entry`=27756;
UPDATE `creature_template` SET `spell1`=49840,`spell2`=49838,`spell3`=49592,`spell4`=0 WHERE `entry`=27755;
UPDATE `creature_template` SET `spell1`=50328,`spell2`=50341,`spell3`=50344 WHERE `entry`=27692;
UPDATE `creature_template` SET `InhabitType`=5,`speed_run`=1,`speed_walk`=1.2 WHERE `entry` IN (27756,27755,27692);

-- eregos texts
DELETE FROM `creature_text` WHERE `entry`=27656;
INSERT INTO `creature_text` (entry,groupid,id,text,type,comment) VALUES
(27656,0,0,'You brash interlopers are out of your element! I will ground you!',1,'Boss Eregos - Aggro'),
(27656,1,0,'Such insolence... such arrogance... must be PUNISHED!',1,'Boss Eregos - Enrage'),
(27656,2,0,'Savor this small victory, foolish little creatures. You and your dragon allies have won this battle. But we will win... the Nexus War.',1,'Boss Eregos - Death');
