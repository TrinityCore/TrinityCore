-- Random comment
SET @IMMOLATION             := 58627; 
SET @CHECKTRIGGER           := 58594; 
SET @CHECK                  := 58593; 
SET @ABOMINATION            := 30689;
SET @CREDIT                 := 58599;
SET @EXPLOSION              := 58596;
SET @SKELETON               := 31048;
SET @KC                     := 30995;

-- Add SAI for Burning Skeleton
UPDATE `creature_template` SET AIName='SmartAI' WHERE `entry`=@SKELETON;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SKELETON;
INSERT INTO `smart_scripts` VALUES
(@SKELETON,0,0,1,25,0,100,0,0,0,0,0,11,@IMMOLATION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Burning Skeleton - On spawn - Cast Immolation on self'),
(@SKELETON,0,1,0,61,0,100,0,0,0,0,0,11,@CHECKTRIGGER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Burning Skeleton - Linked with event 0 - Cast Skeleton Check Master on self'),
(@SKELETON,0,2,3,31,0,100,0,@CHECK,0,0,0,33,@KC,0,0,0,0,0,23,0,0,0,0,0,0,0,'Burning Skeleton - On target hit by spell Check  - Cast Credit Trigger on self'),
(@SKELETON,0,3,4,61,0,100,0,0,0,0,0,28,@CHECKTRIGGER,0,0,0,0,0,1,0,0,0,0,0,0,0,'Burning Skeleton - Linked with event 2 - Remove auras from spell CheckTrigger'),
(@SKELETON,0,4,0,61,0,100,0,0,0,0,0,11,@EXPLOSION,0,0,0,0,0,1,0,0,0,0,0,0,0,'Burning Skeleton - Linked with event 3 - Cast explosion on self');

-- Add condition for Check to target only abominations /that are alive/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@CHECK;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@CHECK,0,0,31,0,3,@ABOMINATION,0,0,0,'','Check can target only chained abominations'),
(13,1,@CHECK,0,0,36,0,0,0,0,0,0,'','Check can target only target alive creatures');

-- Add conditions for Explosion effect 1
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@EXPLOSION;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,2,@EXPLOSION,0,0,31,0,3,@ABOMINATION,0,0,0,'','Explosion effect 1 can target only abomination');

SET @STALKER                := 23033;
SET @ABOMINATION            := 30689;
SET @RIGHT_HAND             := 57983; -- Reference to Nayd's wife
SET @LEFT_HAND              := 57980;
-- Using creature range as a targeting method; guid wise would be wiser but it has bugs out and targets the next living abomination (Not what we want)
UPDATE `creature_template` SET AIName='SmartAI',`InhabitType`=4  WHERE `entry`=@STALKER;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-124991,-124992,-124993,-124981,-124980,-124979);
INSERT INTO `smart_scripts` VALUES
(-124991,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124992,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124993,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124981,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124980,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124979,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');
-- Group 2
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-124982,-124983,-124984,-124969,-124968,-124967);
INSERT INTO `smart_scripts` VALUES
(-124982,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124983,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124984,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124969,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124968,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124967,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');
-- Group 3
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-125000,-125001,-125002,-124985,-124986,-124987);
INSERT INTO `smart_scripts` VALUES
(-125000,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-125001,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-125002,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124985,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124986,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124987,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');
-- Group 4
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-124973,-124974,-124975,-124976,-124977,-124978);
INSERT INTO `smart_scripts` VALUES
(-124973,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124974,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124975,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124976,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124977,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124978,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');
-- Group 5
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-124988,-124989,-124990,-124970,-124971,-124972);
INSERT INTO `smart_scripts` VALUES
(-124988,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124989,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124990,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124970,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124971,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124972,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');
-- Group 6
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-124998,-124999,-124997,-124996,-124995,-124994);
INSERT INTO `smart_scripts` VALUES
(-124997,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124998,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124999,0,0,0,60,0,100,0,0,1,20000,20000,11,@RIGHT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain right hand on abomination'),
(-124994,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124995,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination'),
(-124996,0,0,0,60,0,100,0,0,1,20000,20000,11,@LEFT_HAND,0,0,0,0,0,11,@ABOMINATION,5,0,0,0,0,0,'Stalker - OOC - Cast Chain left hand on abomination');

-- Add condition target for chains
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13  AND `SourceEntry` IN (@LEFT_HAND,@RIGHT_HAND);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@LEFT_HAND,0,0,31,0,3,@ABOMINATION,0,0,0,'','Left Hand Chains only target Chained Abomination'),
(13,1,@RIGHT_HAND,0,0,31,0,3,@ABOMINATION,0,0,0,'','Right Hand Chains only target Chained Abomination');
