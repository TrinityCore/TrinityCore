-- Creature
UPDATE `creature` SET `zoneId`=1637, `areaId`=11386, `position_x`=1428.0660400390625, `position_y`=-4500.16650390625, `position_z`=18.4914703369140625, `orientation`=5.872620105743408203, `VerifiedBuild`=69933 WHERE `guid`=310938; -- Rundok (Area: -Unknown- - Difficulty: 0) CreateObject1

-- Template
UPDATE `creature_template` SET `npcflag`=49, `VerifiedBuild`=69933 WHERE `entry`=47253; -- Rundok

-- Gossip updates
UPDATE `creature_template_gossip` SET `VerifiedBuild`=69933 WHERE `CreatureID`=47253 AND `MenuID`=12235;

UPDATE `gossip_menu` SET `VerifiedBuild`=69933 WHERE `MenuID`=12235 AND `TextID` IN (17180,17181);

UPDATE `gossip_menu_option` SET `GossipOptionID`=39057, `VerifiedBuild`=69933 WHERE `MenuID`=12235 AND `OptionID`=0;

-- Gossip Conditions
SET @GOSSIP		:= 12235;
SET @OPTIONID	:= 0;
SET @TEXTYES	:= 17181;
SET @TEXTNO		:= 17180;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, @GOSSIP, @TEXTNO, 0, 0, 15, 0, 8063, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is not a mage'),
(14, @GOSSIP, @TEXTYES, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a mage'),
(15, @GOSSIP, @OPTIONID, 0, 0, 15, 0, 128, 0, 0, '', 0, 0, 0, '', 'Show gossip option if player is a mage');

-- Trainer
UPDATE `trainer` SET `VerifiedBuild`=69933 WHERE `Id`=12;
UPDATE `trainer_spell` SET `MoneyCost`=159600, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (344587,344597,53142)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=712500, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (281404,281402)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=475000, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (224869,224871)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=603250, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (176244,176242)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=401850, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (132627,132626)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=267900, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (88346,88344)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=142500, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=53140); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=21375, `ReqLevel`=21, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=49358); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=4845, `ReqLevel`=21, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (3566,32272,3563)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=76950, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=35715); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=4845, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=3567); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=15675, `ReqLevel`=24, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId` IN (11420,11418,32267)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=21375, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=49361); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=99750, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=35717); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=15675, `VerifiedBuild`=69933 WHERE (`TrainerId`=12 AND `SpellId`=11417); -- No Faction found! MoneyCost not recalculated!
