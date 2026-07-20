-- Magister Sylastor is missing an Gossip Menu
-- Add creature Flag and Gossip Menu
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` = 16237;

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=16237;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(16237,7169,67823);

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7169 AND `TextID` IN (8441,8442,8650);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7169,8441,0),
(7169,8442,0),
(7169,8650,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7169;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7169,8650,0,0,8,0,9166,0,0,0,0,0,"","Gossip text 8650 requires quest 'Deliver the Plans to An'telas' rewarded and"),
(14,7169,8650,0,0,8,0,9169,0,0,1,0,0,"","Gossip text 8650 requires quest 'Deactivate An'owyn' not rewarded"),
(14,7169,8442,0,0,8,0,9169,0,0,0,0,0,"","Gossip text 8467 requires quest 'Deactivate An'owyn' rewarded");
