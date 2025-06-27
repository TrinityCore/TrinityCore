-- Rewards for Kael'Thas and the Verdant Sphere

UPDATE `quest_template` SET
`RewardChoiceItemId1`=30018, -- Lord Sanguinar's Claim
`RewardChoiceItemId2`=30017, -- Telonicus' Pendant of Mayhem
`RewardChoiceItemId3`=30007, -- The Darkener's Grasp
`RewardChoiceItemId4`=30015, -- The Sun King's Talisman
`RewardChoiceItemCount1`=1,
`RewardChoiceItemCount2`=1,
`RewardChoiceItemCount3`=1,
`RewardChoiceItemCount4`=1 WHERE `Id`=11007;

-- Rewards for The Cipher of Damnation

UPDATE `quest_template` SET
`RewardItemId1`=31074, -- Amulet of the Torn-Heart
`RewardChoiceItemId1`=31073, -- Borak's Reminder
`RewardChoiceItemId2`=31071, -- Grom'tor's Charge
`RewardChoiceItemId3`=31072, -- Lohn'goron, Bow of the Torn-Heart
`RewardChoiceItemId4`=31036, -- Oronok's Ancient Scepter
`RewardChoiceItemId5`=31062, -- Torn-Heart Axe of Battle
`RewardChoiceItemId6`=31038, -- Staff of the Redeemer
`RewardItemCount1`=1, 
`RewardChoiceItemCount1`=1,
`RewardChoiceItemCount2`=1,
`RewardChoiceItemCount3`=1,
`RewardChoiceItemCount4`=1,
`RewardChoiceItemCount5`=1,
`RewardChoiceItemCount6`=1 WHERE `Id`=10588;

-- Voa Summon Stone

SET @OGUID=35834;
DELETE FROM `gameobject` WHERE `id` IN (195013);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`, `rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@OGUID,195013,571,1,65,5476.19,2861.76,418.675,0,1,300,255,1);

UPDATE `creature` SET `position_x`=5407.84,`position_y`=2819.29, `position_z`=418.676,`orientation`=0.471239 WHERE `id`=32620;

-- DB Error

UPDATE `creature_template` SET `NpcFlag`=3 WHERE `entry`=14325;
