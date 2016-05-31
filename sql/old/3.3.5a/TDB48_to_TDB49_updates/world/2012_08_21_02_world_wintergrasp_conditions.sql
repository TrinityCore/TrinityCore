-- Conditions
-- Add gossip_menu condition for 9904 Horde
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (9904,9923);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`NegativeCondition`) VALUES
(14,9904,13759,0,1,33280,0), -- Must have Rank 1: Corporal
(14,9904,13759,1,1,55629,0), -- Or must have Rank 2: First Lieutenant
(14,9904,13761,0,1,33280,1), -- Must not have Rank 1: Corporal
(14,9904,13761,0,1,55629,1), -- Must not have Rank 2: First Lieutenant
-- Add gossip_menu condition for 9923 Alliance
(14,9923,13798,0,1,33280,0), -- Must have Rank 1: Corporal
(14,9923,13798,1,1,55629,0), -- Or must have Rank 2: First Lieutenant
(14,9923,14172,0,1,33280,1), -- Must not have Rank 1: Corporal
(14,9923,14172,0,1,55629,1), -- Must not have Rank 2: First Lieutenant
-- Add conditions to gossip options horde
(15,9904,0,0,1,33280,0), -- Must have reached Rank 1: Corporal
(15,9904,0,1,1,55629,0), -- Or must have reached Rank 2: First Lieutenant
(15,9904,1,0,1,55629,0), -- Must have reached Rank 2: First Lieutenant
(15,9904,2,0,1,55629,0), -- Must have reached Rank 2: First Lieutenant
-- Add conditions to gossip options alliance
(15,9923,0,0,1,33280,0), -- Must have reached Rank 1: Corporal
(15,9923,0,1,1,55629,0), -- Or must have reached Rank 2: First Lieutenant
(15,9923,1,0,1,55629,0), -- Must have reached Rank 2: First Lieutenant
(15,9923,2,0,1,55629,0); -- Must have reached Rank 2: First Lieutenant
