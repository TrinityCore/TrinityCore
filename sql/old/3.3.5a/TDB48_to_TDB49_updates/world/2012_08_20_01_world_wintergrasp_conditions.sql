-- Conditions
-- Add gossip_menu condition for 9904 Horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (9904,9923);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`) VALUES
(14,9904,13759,0,1,33280), -- Must have Rank 1: Corporal
(14,9904,13759,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9904,13761,0,11,33280), -- Must not have Rank 1: Corporal
(14,9904,13761,0,11,55629), -- Must not have Rank 2: First Lieutenant
-- Add gossip_menu condition for 9923 Alliance
(14,9923,13798,0,1,33280), -- Must have Rank 1: Corporal
(14,9923,13798,1,1,55629), -- Or must have Rank 2: First Lieutenant
(14,9923,14172,0,11,33280), -- Must not have Rank 1: Corporal
(14,9923,14172,0,11,55629), -- Must not have Rank 2: First Lieutenant
-- Add conditions to gossip options horde
(15,9904,0,0,1,33280), -- Must have reached Rank 1: Corporal
(15,9904,0,1,1,55629), -- Or must have reached Rank 2: First Lieutenant
(15,9904,1,0,1,55629), -- Must have reached Rank 2: First Lieutenant
(15,9904,2,0,1,55629), -- Must have reached Rank 2: First Lieutenant
-- Add conditions to gossip options alliance
(15,9923,0,0,1,33280), -- Must have reached Rank 1: Corporal
(15,9923,0,1,1,55629), -- Or must have reached Rank 2: First Lieutenant
(15,9923,1,0,1,55629), -- Must have reached Rank 2: First Lieutenant
(15,9923,2,0,1,55629); -- Must have reached Rank 2: First Lieutenant

/* Spell target conditions for spawning WG siege machines in proper place while building it */
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (56575,56661,56663,61408);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 56575, 0, 0, 31, 0, 3, 27852, 0, 0, 0, '', NULL),
(13, 1, 56661, 0, 0, 31, 0, 3, 27852, 0, 0, 0, '', NULL),
(13, 1, 56663, 0, 0, 31, 0, 3, 27852, 0, 0, 0, '', NULL),
(13, 1, 61408, 0, 0, 31, 0, 3, 27852, 0, 0, 0, '', NULL);
