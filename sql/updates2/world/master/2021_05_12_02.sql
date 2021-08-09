UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2989, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=11983 AND `AreaTriggerId`=16670); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`Idx`=0 AND `ConversationId` IN (7999,8248,8355,8249,7995,7993,8354,8202,7994));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(7999, 51642, 0, 38134),
(8248, 51642, 0, 38134),
(8355, 51642, 0, 38134),
(8249, 51642, 0, 38134),
(7995, 51642, 0, 38134),
(7993, 51642, 0, 38134),
(8354, 51642, 0, 38134),
(8202, 51642, 0, 38134),
(7994, 51642, 0, 38134);


DELETE FROM `conversation_actor_template` WHERE `Id` IN (57728, 66300);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(57728, 120649, 75898, 38134),
(66300, 140351, 86636, 38134);

UPDATE `conversation_actor_template` SET `CreatureId`=131925, `CreatureModelId`=78452 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131925, `CreatureModelId`=78452 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131925, `CreatureModelId`=78452 WHERE `Id`=51642;
UPDATE `conversation_actor_template` SET `CreatureId`=131913, `CreatureModelId`=81606 WHERE `Id`=51642;

DELETE FROM `conversation_line_template` WHERE `Id` IN (18210, 18672, 18910, 18673, 18206, 18204, 18909, 18604, 18205);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(18210, 0, 84, 0, 0, 38134),
(18672, 0, 1240, 0, 0, 38134),
(18910, 0, 1240, 0, 0, 38134),
(18673, 0, 1240, 0, 0, 38134),
(18206, 0, 84, 0, 0, 38134),
(18204, 0, 1240, 0, 0, 38134),
(18909, 0, 1240, 0, 0, 38134),
(18604, 0, 84, 0, 0, 38134),
(18205, 0, 1240, 0, 0, 38134);



DELETE FROM `conversation_template` WHERE `Id` IN (8355, 7993, 8354, 7994, 8202, 7995, 7999, 8249, 8248);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(8355, 18910, 4787, 0, 38134),
(7993, 18204, 4591, 0, 38134),
(8354, 18909, 7357, 0, 38134),
(7994, 18205, 5355, 0, 38134),
(8202, 18604, 8086, 0, 38134),
(7995, 18206, 3820, 0, 38134),
(7999, 18210, 5770, 0, 38134),
(8249, 18673, 4986, 0, 38134),
(8248, 18672, 6616, 0, 38134);


DELETE FROM `gameobject_template_addon` WHERE `entry`=290718;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(290718, 0, 262144, 0, 0); -- Colocar trampa

UPDATE `gameobject_template_addon` SET `flags`=262144 WHERE `entry`=278379; -- Notas de Lucille

DELETE FROM `quest_offer_reward` WHERE `ID`=50600;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(50600, 0, 0, 0, 0, 0, 0, 0, 0, 'La Orden de las Ascuas te da las gracias.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=51919 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51919 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(51919, 0, 1, 32, 0, 0, 1643, 896, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51919, 0, 0, 0, 337518, 129995, 1643, 896, 0, 0, 0, 0, 0, 1412890, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50600 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=51919 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51919 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(51919, 1, 0, -264, 1671, 0, 38134), -- -Unknown-
(51919, 0, 0, -269, 1666, 58, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51706 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51906 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51585 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51619 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50600 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`ID`=272692 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(272692, 0, 1643, -945.0999755859375, 3767.580078125, 38.029998779296875, 38134); -- Spell: 272692 (Leave Crimson Demolisher) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (144285 /*144285 (Esclavo de azerita Pantoque) - Possessed*/, 138863 /*138863*/, 126740 /*126740 (Rusty) - Shadowy Ghost Visual*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(144285, 0, 0, 50331648, 1, 0, 15563, 0, 0, '268434'), -- 144285 (Esclavo de azerita Pantoque) - Possessed
(138863, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 138863
(126740, 0, 0, 1, 1, 0, 0, 0, 0, '213677'); -- 126740 (Rusty) - Shadowy Ghost Visual

UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=124921; -- 124921 (Cuervo del puerto)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=137548; -- 137548 (Thorn Sutton)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=137551; -- 137551 (Mareen Sherwood)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137550; -- 137550 (Wallis Crowder)
UPDATE `creature_template_addon` SET `auras`='186326 84063' WHERE `entry`=131388; -- 131388 (Subyugador xilobrezo)
UPDATE `creature_template_addon` SET `auras`='186326 84063' WHERE `entry`=131372; -- 131372 (Sabueso xilobrezo)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=131393; -- 131393 (Aldeana asediada)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131845; -- 131845 (Niño de la aldea asediada)
UPDATE `creature_template_addon` SET `auras`='244874' WHERE `entry`=131844; -- 131844 (Aldeano asediado)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=131552; -- 131552 (Guardia halcónida)
UPDATE `creature_template_addon` SET `bytes1`=7 WHERE `entry`=128623; -- 128623 (Cangrejo del puerto)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='244874' WHERE `entry`=131843; -- 131843 (Aldeana asediada)
UPDATE `creature_template_addon` SET `auras`='98391' WHERE `entry`=133117; -- 133117 (Centinela maderatorcida)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=134189; -- 134189 (Bruto nudoso)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=134774; -- 134774 (Cuervo embrujado)
UPDATE `creature_template_addon` SET `auras`='281391' WHERE `entry`=142278; -- 142278 (Garrespina embrujado)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=130848; -- 130848 (Guerrero rúnico)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=131368; -- 131368 (Plebeyo de Alto de Arom)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=129575; -- 129575 (Refugiado de Corlain)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=129641; -- 129641 (Refugiada de Corlain)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=136690; -- 136690 (Merodeador ventisquero)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='169471' WHERE `entry`=127702; -- 127702 (Mula de comerciante)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=128188; -- 128188 (Halcón alpino)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=128852; -- 128852 (Halcón del viento gélido)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='123169 145953' WHERE `entry`=127807; -- 127807 (Cierva montesa)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=0, `auras`='271691' WHERE `entry`=124416; -- 124416 (Tom Odell)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='271693' WHERE `entry`=124516; -- 124516 (Lawrence Levy)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=124420; -- 124420 (Felix Odell)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=128467; -- 128467 (Elijah Eggleton)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=130684; -- 130684 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=257, `auras`='' WHERE `entry`=124497; -- 124497 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=124499; -- 124499 (Fallhaven Villager)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=0, `auras`='' WHERE `entry`=124310; -- 124310 (Ava Odell)
UPDATE `creature_template_addon` SET `aiAnimKit`=0, `auras`='' WHERE `entry`=124426; -- 124426 (Marjorie Foster)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=130164; -- 130164 (Jabalí de las Tierras Altas)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=125464; -- 125464
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=125411; -- 125411
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=129486; -- 129486 (Guardia Tarjasenda)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=130359; -- 130359 (Halieto costero)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123226; -- 123226 (Trillador del puerto)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=142804; -- 142804 (Pichel)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=142813; -- 142813 (Parroquiano de Barriga de Ballena)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=126387; -- 126387 (Carroñero costero)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='244868' WHERE `entry`=143151; -- 143151 (Marinero de cubierta de Boralus)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=124918; -- 124918 (Marinera de Boralus)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126455; -- 126455 (Zorro Trotarriscos)
UPDATE `creature_template_addon` SET `bytes1`=50331648, `aiAnimKit`=0 WHERE `entry`=126953; -- 126953 (Halcón de Tiragarde)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=139090; -- 139090 (Guardia de la expedición)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=131886; -- 131886 (Retador rabalero)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=125924; -- 125924 (Trabajador de embarcadero de Puntanzuelo)
UPDATE `creature_template_addon` SET `auras`='259795' WHERE `entry`=124805; -- 124805
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=126496; -- 126496 (Cazarratones errante)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=143700; -- 143700
UPDATE `creature_template_addon` SET `mount`=81689 WHERE `entry`=139089; -- 139089 (Guardia de Vadoarlén)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=144029; -- 144029 (Industrial de Aspafresno)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=143336; -- 143336 (Corsario contratado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142774; -- 142774 (Bodeguero Hinz)
UPDATE `creature_template_addon` SET `bytes1`=8, `auras`='' WHERE `entry`=141771; -- 141771 (Marinero de cubierta de Aspafresno)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=125004; -- 125004 (Noble kultirano)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135889; -- 135889 (Obrero de Boralus)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135112; -- 135112 (Vagabundo demacrado)
UPDATE `creature_template_addon` SET `aiAnimKit`=6644 WHERE `entry`=123641; -- 123641 (Trabajador de Boralus)
UPDATE `creature_template_addon` SET `auras`='244807 174714' WHERE `entry`=140906; -- 140906
UPDATE `creature_template_addon` SET `aiAnimKit`=573 WHERE `entry`=135677; -- 135677 (7th Legion Rifleman)
UPDATE `creature_template_addon` SET `auras`='271317' WHERE `entry`=135230; -- 135230
UPDATE `creature_template_addon` SET `bytes2`=0, `aiAnimKit`=0 WHERE `entry`=135675; -- 135675 (7th Legion Marine)
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=147972; -- 147972
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142346; -- 142346
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=143502; -- 143502
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135520; -- 135520
UPDATE `creature_template_addon` SET `aiAnimKit`=13360 WHERE `entry`=123169; -- 123169
UPDATE `creature_template_addon` SET `auras`='263194' WHERE `entry`=143250; -- 143250
UPDATE `creature_template_addon` SET `bytes1`=6, `bytes2`=0 WHERE `entry`=142166; -- 142166
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=140313; -- 140313
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=142137; -- 142137
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=143295; -- 143295
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=133325; -- 133325
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123642; -- 123642 (Boralus Citizen)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=143262; -- 143262
UPDATE `creature_template_addon` SET `bytes1`=5, `auras`='' WHERE `entry`=132638; -- 132638
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=140350; -- 140350


UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=144285 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=138863 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=130188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=187, `VerifiedBuild`=38134 WHERE (`Entry`=126740 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144361 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `BoundingRadius`=0.151963323354721069, `CombatReach`=1 WHERE `DisplayID`=76516;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.542187929153442382, `CombatReach`=0.75 WHERE `DisplayID`=80811;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84304;
UPDATE `creature_model_info` SET `BoundingRadius`=1.156227827072143554, `CombatReach`=1 WHERE `DisplayID`=70443;
UPDATE `creature_model_info` SET `BoundingRadius`=6.321063041687011718, `CombatReach`=8, `VerifiedBuild`=38134 WHERE `DisplayID`=86197;
UPDATE `creature_model_info` SET `BoundingRadius`=0.433400630950927734, `CombatReach`=1 WHERE `DisplayID`=70449;
UPDATE `creature_model_info` SET `BoundingRadius`=0.433400630950927734, `CombatReach`=1 WHERE `DisplayID`=70451;
UPDATE `creature_model_info` SET `BoundingRadius`=0.665383040904998779, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=0.433400630950927734, `CombatReach`=1 WHERE `DisplayID`=70448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.665383040904998779, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=79614;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80939;
UPDATE `creature_model_info` SET `BoundingRadius`=0.217223197221755981, `CombatReach`=1 WHERE `DisplayID`=68845;
UPDATE `creature_model_info` SET `BoundingRadius`=0.665383040904998779, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=70722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.579469561576843261 WHERE `DisplayID`=62863;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45938381552696228, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=4959;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599132537841796, `CombatReach`=1.75 WHERE `DisplayID`=75374;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88191;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88203;
UPDATE `creature_model_info` SET `BoundingRadius`=1.447181582450866699, `CombatReach`=0.699999988079071044 WHERE `DisplayID`=81217;
UPDATE `creature_model_info` SET `BoundingRadius`=0.890321731567382812, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=93455;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=87182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5 WHERE `DisplayID`=86639;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77687;
UPDATE `creature_model_info` SET `BoundingRadius`=1.180964350700378417, `CombatReach`=1.949999928474426269 WHERE `DisplayID`=82148;

DELETE FROM `npc_vendor` WHERE (`entry`=135815 AND `item`=162427 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162421 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162412 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162381 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162361 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135815 AND `item`=162322 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162330 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162329 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135815 AND `item`=162305 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162320 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162318 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162256 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162135 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=163314 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=162131 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135815 AND `item`=161908 AND `ExtendedCost`=6570 AND `type`=1) OR (`entry`=135815 AND `item`=161910 AND `ExtendedCost`=6308 AND `type`=1) OR (`entry`=135815 AND `item`=160541 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=135815 AND `item`=163491 AND `ExtendedCost`=6424 AND `type`=1) OR (`entry`=135815 AND `item`=161598 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135815 AND `item`=161596 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135815 AND `item`=161594 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135815 AND `item`=161591 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135815 AND `item`=161597 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135815 AND `item`=161595 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135815 AND `item`=161593 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135815 AND `item`=161592 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135815 AND `item`=163205 AND `ExtendedCost`=6423 AND `type`=1) OR (`entry`=135815 AND `item`=160535 AND `ExtendedCost`=6305 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(135815, 30, 162427, 0, 6419, 1, 0, 0, 38134), -- Pattern: Embroidered Deep Sea Cloak
(135815, 29, 162421, 0, 6419, 1, 0, 0, 38134), -- Pattern: Deep Sea Bag
(135815, 28, 162412, 0, 6419, 1, 0, 0, 38134), -- Recipe: Recurve Bow of the Strands
(135815, 27, 162381, 0, 6419, 1, 0, 0, 38134), -- Design: Royal Quartz Loop
(135815, 26, 162361, 0, 6418, 1, 0, 0, 38134), -- Recipe: Contract: Order of Embers
(135815, 25, 162322, 0, 6419, 1, 0, 0, 38134), -- Schematic: Frost-Laced Ammunition
(135815, 24, 162330, 0, 6419, 1, 0, 0, 38134), -- Schematic: AZ3-R1-T3 Orthogonal Optics
(135815, 23, 162329, 0, 6418, 1, 0, 0, 38134), -- Schematic: AZ3-R1-T3 Orthogonal Optics
(135815, 22, 162305, 0, 6419, 1, 0, 0, 38134), -- Formula: Enchant Ring - Pact of Versatility
(135815, 21, 162320, 0, 6419, 1, 0, 0, 38134), -- Formula: Enchant Weapon - Versatile Navigation
(135815, 20, 162318, 0, 6419, 1, 0, 0, 38134), -- Formula: Enchant Weapon - Gale-Force Striking
(135815, 19, 162256, 0, 6419, 1, 0, 0, 38134), -- Recipe: Coastal Rejuvenation Potion
(135815, 18, 162135, 0, 6419, 1, 0, 0, 38134), -- Recipe: Flask of the Undertow
(135815, 17, 163314, 0, 6419, 1, 0, 0, 38134), -- Recipe: Battle Potion of Agility
(135815, 16, 162131, 0, 6419, 1, 0, 0, 38134), -- Recipe: Potion of Rising Death
(135815, 15, 161908, 0, 6570, 1, 70400, 0, 38134), -- Reins of the Dusky Waycrest Gryphon
(135815, 14, 161910, 0, 6308, 1, 0, 0, 38134), -- Reins of the Smoky Charger
(135815, 13, 160541, 0, 6306, 1, 0, 0, 38134), -- Order of Embers Tabard
(135815, 12, 163491, 0, 6424, 1, 0, 0, 38134), -- Pristine Falcon Feather
(135815, 11, 161598, 0, 6310, 1, 0, 0, 38134), -- Hexxed-Land Treads
(135815, 10, 161596, 0, 6310, 1, 0, 0, 38134), -- Coven Buster's Waistguard
(135815, 9, 161594, 0, 6310, 1, 0, 0, 38134), -- Woven Thornspeaker's Leggings
(135815, 8, 161591, 0, 6310, 1, 0, 0, 38134), -- Eternal Flamekeeper's Handwraps
(135815, 6, 161597, 0, 6309, 1, 0, 0, 38134), -- Gauntlets of Renewed Resolution
(135815, 5, 161595, 0, 6309, 1, 0, 0, 38134), -- Grips of the Oathsworn
(135815, 4, 161593, 0, 6309, 1, 0, 0, 38134), -- Footpads of the Deft Exorcist
(135815, 3, 161592, 0, 6309, 1, 0, 0, 38134), -- Leggings of Devout Opposition
(135815, 2, 163205, 0, 6423, 1, 0, 0, 38134), -- Ghostly Pet Biscuit
(135815, 1, 160535, 0, 6305, 1, 0, 0, 38134); -- Witch Hunter's Cape


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=144285 AND `ID`=1) OR (`CreatureID`=140906 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(144285, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Esclavo de azerita Pantoque
(140906, 2, 2202, 0, 0, 0, 0, 0, 0, 0, 0); -- -Unknown-

UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=137548 AND `ID`=1); -- Thorn Sutton
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=123642 AND `ID`=1); -- Boralus Citizen
UPDATE `creature_equip_template` SET `ItemID1`=163840, `ItemID2`=0 WHERE (`CreatureID`=139088 AND `ID`=2); -- Boralus Guard
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=123641 AND `ID`=1); -- Trabajador de Boralus
UPDATE `creature_equip_template` SET `ItemID1`=163840 WHERE (`CreatureID`=135792 AND `ID`=3); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=1905 WHERE (`CreatureID`=135792 AND `ID`=2); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=80057 WHERE (`CreatureID`=135792 AND `ID`=1); -- Boralus Worker
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=142136 AND `ID`=1); -- -Unknown-
UPDATE `creature_equip_template` SET `ItemID1`=2703 WHERE (`CreatureID`=143263 AND `ID`=1); -- -Unknown-

DELETE FROM `gossip_menu` WHERE (`MenuId`=21837 AND `TextId`=33371) OR (`MenuId`=21836 AND `TextId`=33370) OR (`MenuId`=21835 AND `TextId`=33369) OR (`MenuId`=21833 AND `TextId`=33367);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21837, 33371, 38134), -- 129995
(21836, 33370, 38134), -- 129995
(21835, 33369, 38134), -- 129995
(21833, 33367, 38134); -- 129995

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (21837,21836,21835,21833));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21837, 0, 0, '¿Qué sucede?', 0, 38134),
(21836, 0, 0, '¿Puedo hacer algo para ayudar?', 0, 38134),
(21835, 0, 0, '¿Qué pasó?', 0, 38134),
(21833, 0, 0, '¿Por qué lloras?', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (21836,21835,21833));
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21836, 0, 21837, 0),
(21835, 0, 21836, 0),
(21833, 0, 21835, 0);


UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=131860; -- Jordan Stansfield
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=134866; -- Viviana Swailes
UPDATE `creature_template` SET `npcflag`=65665 WHERE `entry`=136655; -- Alisha Aguaoscura
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=1 WHERE `entry`=128623; -- Cangrejo del puerto
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=133098; -- Inquisitor Cleardawn
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=134078; -- Soldado de duramen
UPDATE `creature_template` SET `unit_flags`=33850112 WHERE `entry`=133117; -- Centinela maderatorcida
UPDATE `creature_template` SET `unit_flags`=32832, `unit_flags3`=0 WHERE `entry`=134189; -- Bruto nudoso
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=134004; -- Gorak Tul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=33587456 WHERE `entry`=144285; -- Esclavo de azerita Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=138863; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags3`=0 WHERE `entry`=130848; -- Guerrero rúnico
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=131359; -- Refugiada sospechosa
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135021; -- Inquisidora Alborada
UPDATE `creature_template` SET `gossip_menu_id`=10182 WHERE `entry`=135815; -- Intendente Alcorn
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=129485; -- Muñeco de entrenamiento
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=136697; -- Cazadora de la helada blanca
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=136690; -- Merodeador ventisquero
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=127702; -- Mula de comerciante
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130188; -- Gólem de piedra
UPDATE `creature_template` SET `unit_flags`=49216 WHERE `entry`=129783; -- -Unknown-
UPDATE `creature_template` SET `npcflag`=131, `unit_flags2`=33556480 WHERE `entry`=128467; -- Elijah Eggleton
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=124497; -- Fallhaven Villager
UPDATE `creature_template` SET `npcflag`=4224, `unit_flags2`=2048 WHERE `entry`=124426; -- Marjorie Foster
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=116633; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=126740; -- Rusty
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=126210; -- Custodio Allen
UPDATE `creature_template` SET `gossip_menu_id`=21837, `faction`=14, `npcflag`=0, `unit_flags2`=2048 WHERE `entry`=129995; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=127743; -- Tía Amanda Hale
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=125464; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=144336; -- Aldeano de Hondonada Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=144337; -- Aldeana de Hondonada Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=144338; -- Aldeano de Hondonada Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=144339; -- Aldeano de Hondonada Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=144335; -- Aldeana de Hondonada Fletcher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=125394; -- Oficial Henry Framer
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=1, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=144361; -- Toki
UPDATE `creature_template` SET `unit_flags`=536870912 WHERE `entry`=128285; -- Protector de los ancestros
UPDATE `creature_template` SET `faction`=2909 WHERE `entry`=139090; -- Guardia de la expedición
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=143560; -- Mariscal Gabriel
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=143559; -- Gran mariscal Hojatemblorosa
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=141698; -- Kort Ceefer
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=88696; -- Oficial Rumsfeld
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=88697; -- Oficial Mena de Hierro
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135064; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=139522; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135808; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=22339 WHERE `entry`=124725; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=121235; -- Taelia


UPDATE `creature_template_model` SET `DisplayScale`=1.5, `Probability`=0 WHERE (`CreatureID`=143150 AND `Idx`=0); -- Corky
UPDATE `creature_template_model` SET `DisplayScale`=1.10000002384185791 WHERE (`CreatureID`=143093 AND `Idx`=0); -- Kaloah
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=142797 AND `Idx`=0); -- Rata marina
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143153 AND `Idx`=0); -- Mordisqueador de anémona
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=140275 AND `Idx`=0); -- Dardo Temible
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=136189 AND `Idx`=0); -- El rey liquen
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=140163 AND `Idx`=0); -- Warbringer Yenajz


DELETE FROM `npc_text` WHERE `ID` IN (33371 /*33371*/, 33370 /*33370*/, 33369 /*33369*/, 33367 /*33367*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33371, 1, 0, 0, 0, 0, 0, 0, 0, 141201, 0, 0, 0, 0, 0, 0, 0, 38134), -- 33371
(33370, 1, 0, 0, 0, 0, 0, 0, 0, 141199, 0, 0, 0, 0, 0, 0, 0, 38134), -- 33370
(33369, 1, 0, 0, 0, 0, 0, 0, 0, 141198, 0, 0, 0, 0, 0, 0, 0, 38134), -- 33369
(33367, 1, 0, 0, 0, 0, 0, 0, 0, 141196, 0, 0, 0, 0, 0, 0, 0, 38134); -- 33367


DELETE FROM `world_quest` WHERE `id` IN (54836 /*54836*/, 45134 /*45134*/, 54674 /*54674*/, 54857 /*54857*/, 50591 /*50591*/, 54817 /*54817*/, 54838 /*54838*/, 51706 /*51706*/, 51919 /*51919*/);
INSERT INTO `world_quest` (`id`, `duration`, `variable`, `value`) VALUES
(54836, 86400, 17031, 1), -- 54836
(45134, 21600, 13002, 1), -- 45134
(54674, 86400, 17066, 1), -- 54674
(54857, 86400, 17075, 1), -- 54857
(50591, 86400, 15646, 1), -- 50591
(54817, 86400, 17011, 1), -- 54817
(54838, 86400, 17033, 1), -- 54838
(51706, 86400, 15276, 3), -- 51706
(51919, 86400, 15579, 1); -- 51919

UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13089 WHERE `id`=46165; -- 46165
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=46146; -- 46146
UPDATE `world_quest` SET `variable`=14062 WHERE `id`=49091; -- 49091
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45203; -- 45203
UPDATE `world_quest` SET `variable`=14243 WHERE `id`=49098; -- 49098
UPDATE `world_quest` SET `variable`=13002 WHERE `id`=45058; -- 45058
UPDATE `world_quest` SET `variable`=13087 WHERE `id`=46163; -- 46163


DELETE FROM `areatrigger_template` WHERE `Id` IN (5669, 24304, 23950, 24363);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(5669, 1, 0, 0, 3, 3, 0, 0, 0, 0, 38134),
(24304, 1, 0, 0, 15, 15, 0, 0, 0, 0, 38134),
(23950, 1, 1, 0, 1, 14, 5, 1, 14, 5, 38134),
(24363, 1, 0, 2, 5, 5, 0, 0, 0, 0, 38134);


DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=1429 AND `AreaTriggerId`=5669) OR (`SpellMiscId`=20405 AND `AreaTriggerId`=24304) OR (`SpellMiscId`=20003 AND `AreaTriggerId`=23950) OR (`SpellMiscId`=20468 AND `AreaTriggerId`=24363);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(1429, 5669, 0, 0, 0, 0, 0, 0, 0, 18000, 18000, 38134), -- SpellId : 315984
(20405, 24304, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 38134), -- SpellId : 328493
(20003, 23950, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 38134), -- SpellId : 325243
(20468, 24363, 0, 17857, 0, 0, 0, 0, 0, 0, 30000, 38134); -- SpellId : 328984

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=21827 AND `AreaTriggerId`=26038); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=20004 AND `AreaTriggerId`=23951); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=20456 AND `AreaTriggerId`=24351); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12000 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=60000 WHERE (`SpellMiscId`=4424 AND `AreaTriggerId`=9170); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=20000 WHERE (`SpellMiscId`=510 AND `AreaTriggerId`=3678); -- SpellId : 0


DELETE FROM `conversation_actor_template` WHERE `Id` IN (76529, 76140);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(76529, 165539, 94375, 38134),
(76140, 167263, 94399, 38134);


DELETE FROM `conversation_line_template` WHERE `Id` IN (38876, 39013, 39012, 39011, 39010, 37552, 41371, 35806, 38336, 38335, 38337, 35709, 35708, 35840, 37829, 35841, 37828, 37362, 37361, 37360, 37359, 36139, 36138, 37015, 37014, 37019, 36917, 36916, 35838, 35837, 40308, 40306, 35798, 35797, 36971, 36970, 36027, 36026, 36025, 36024, 37378, 37377, 37017, 37036, 37959, 37958, 37038, 37037, 35850, 41219, 38826, 38825, 41404, 41403, 41402, 41401, 41400, 37040, 35855, 35854, 35853, 39423, 35805, 36086, 36033, 36031, 36030, 37877, 36029, 37931, 41376, 37627, 37626, 37625, 37624, 37614, 15462, 13132, 13131, 13130, 13129, 13128, 13127, 13126, 13125, 13124, 21797, 21795, 21794, 26769, 26768, 26767, 13123, 13122, 13121, 13133, 13120, 13134, 35810, 35809, 35808, 35039, 35038, 35262, 37381, 37380, 37379, 34408, 34409, 34406, 34407, 36085, 36084, 34633, 34632, 34631, 37358, 37512, 37511, 37510, 38356, 38355, 38354, 37509, 38353, 38352, 38351, 37357, 37356, 37508, 38350, 38349, 38348, 38347, 38346, 38345, 38344, 37355, 37516, 37354, 37353, 37507, 37352, 37351, 35872, 35871, 35870, 35869, 39630, 35868, 35867, 35866, 36430, 36429, 35244, 35170, 35169, 35168, 35167, 35166, 37612, 37613, 37041, 39720, 37034, 37033, 37032, 36827, 35814, 35813, 35812, 36759, 37735, 36758, 36757, 36756, 36755, 36760, 41393, 41392, 36529, 36528, 36527, 36526, 36525, 36524, 36523, 36522, 36521, 35266, 35265, 37679, 37678, 37677, 37674, 36061, 36060, 36059, 38199, 38198, 38197, 38196, 38418, 38403, 38402, 38401, 37384, 37383, 37382, 40473, 41397, 35820, 35819, 37016, 36148, 36147, 36146, 36145, 36144, 36142, 36141, 37553, 37035, 41395, 41394, 35896, 35895, 41387, 41386, 41391, 41390, 37832, 39009, 37831, 37830, 36531, 36530, 37389, 37390, 39046, 37388, 37387, 37386, 37385, 37020, 39045, 39044, 35807, 38393, 38392, 38391, 37039, 36137, 36136, 36135, 35864, 39321, 36319, 36087, 38037, 37620, 37619, 37618, 37617, 37616, 36217, 36216, 38364, 35804, 35803, 38036, 35817, 35816, 35815, 36174, 36173, 38035, 36172, 36023, 37876, 36022, 36021, 36020, 37680, 36967, 36966, 36965, 35035, 41244, 36088, 40278, 40276, 35856, 35849, 35848, 35847, 35846, 35845, 35818, 35715, 41389, 41388, 38824, 38823, 37561, 37560, 38055, 36089, 37623, 37622, 37376, 37375, 37374, 36073, 36072, 37492, 39251, 40310, 37490, 37489, 38822, 38821, 34637, 34636, 34635);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(38876, 0, 0, 0, 0, 38134),
(39013, 19455, 0, 0, 0, 38134),
(39012, 9575, 0, 0, 0, 38134),
(39011, 3568, 0, 1, 0, 38134),
(39010, 0, 0, 0, 0, 38134),
(37552, 0, 0, 0, 0, 38134),
(41371, 0, 0, 0, 0, 38134),
(35806, 0, 0, 0, 0, 38134),
(38336, 18299, 0, 2, 0, 38134),
(38335, 12222, 0, 1, 0, 38134),
(38337, 0, 0, 0, 0, 38134),
(35709, 5959, 0, 0, 0, 38134),
(35708, 0, 0, 0, 0, 38134),
(35840, 17097, 0, 0, 0, 38134),
(37829, 11086, 0, 0, 0, 38134),
(35841, 5358, 0, 1, 0, 38134),
(37828, 0, 0, 0, 0, 38134),
(37362, 42411, 0, 0, 0, 38134),
(37361, 29767, 0, 0, 0, 38134),
(37360, 11872, 0, 0, 0, 38134),
(37359, 0, 0, 0, 0, 38134),
(36139, 14902, 0, 1, 0, 38134),
(36138, 0, 0, 0, 0, 38134),
(37015, 0, 0, 0, 0, 38134),
(37014, 0, 0, 0, 0, 38134),
(37019, 0, 0, 0, 0, 38134),
(36917, 4843, 0, 0, 0, 38134),
(36916, 0, 0, 0, 0, 38134),
(35838, 2346, 0, 1, 0, 38134),
(35837, 0, 0, 0, 0, 38134),
(40308, 4743, 0, 0, 0, 38134),
(40306, 0, 0, 0, 0, 38134),
(35798, 9236, 0, 1, 0, 38134),
(35797, 0, 0, 0, 0, 38134),
(36971, 5844, 0, 0, 0, 38134),
(36970, 0, 0, 0, 0, 38134),
(36027, 24384, 0, 0, 0, 38134),
(36026, 14381, 0, 1, 0, 38134),
(36025, 8689, 0, 0, 0, 38134),
(36024, 0, 0, 0, 0, 38134),
(37378, 13817, 0, 0, 0, 38134),
(37377, 0, 0, 0, 0, 38134),
(37017, 0, 0, 0, 0, 38134),
(37036, 0, 1548, 0, 0, 38134),
(37959, 4219, 0, 1, 0, 38134),
(37958, 0, 0, 0, 0, 38134),
(37038, 4000, 0, 1, 0, 38134),
(37037, 0, 0, 0, 0, 38134),
(35850, 1000, 0, 1, 0, 38134),
(41219, 0, 0, 0, 0, 38134),
(38826, 7595, 0, 0, 0, 38134),
(38825, 0, 0, 0, 0, 38134),
(41404, 14772, 0, 0, 0, 38134),
(41403, 11379, 0, 2, 0, 38134),
(41402, 7361, 0, 1, 0, 38134),
(41401, 3868, 0, 1, 0, 38134),
(41400, 0, 0, 0, 0, 38134),
(37040, 0, 1548, 0, 0, 38134),
(35855, 11448, 0, 0, 0, 38134),
(35854, 7815, 0, 1, 0, 38134),
(35853, 0, 0, 0, 0, 38134),
(39423, 0, 0, 0, 0, 38134),
(35805, 0, 0, 0, 0, 38134),
(36086, 0, 0, 0, 0, 38134),
(36033, 44331, 0, 1, 0, 38134),
(36031, 36808, 0, 0, 0, 38134),
(36030, 28481, 0, 0, 0, 38134),
(37877, 18410, 0, 1, 0, 38134),
(36029, 8216, 0, 0, 0, 38134),
(37931, 0, 0, 0, 0, 38134),
(41376, 0, 0, 0, 0, 38134),
(37627, 21451, 0, 2, 0, 38134),
(37626, 12136, 0, 1, 0, 38134),
(37625, 5545, 0, 1, 0, 38134),
(37624, 0, 0, 0, 0, 38134),
(37614, 0, 0, 0, 0, 38134),
(15462, 134186, 0, 0, 1, 38134),
(13132, 127547, 0, 1, 0, 38134),
(13131, 116669, 0, 1, 0, 38134),
(13130, 103694, 0, 5, 0, 38134),
(13129, 94989, 0, 5, 0, 38134),
(13128, 88583, 0, 5, 0, 38134),
(13127, 82096, 0, 1, 0, 38134),
(13126, 73339, 0, 4, 0, 38134),
(13125, 63212, 0, 4, 0, 38134),
(13124, 53990, 0, 4, 0, 38134),
(21797, 50620, 0, 1, 0, 38134),
(21795, 46006, 0, 3, 0, 38134),
(21794, 40331, 0, 3, 0, 38134),
(26769, 36935, 0, 1, 0, 38134),
(26768, 31684, 0, 2, 0, 38134),
(26767, 28483, 0, 2, 0, 38134),
(13123, 18234, 0, 1, 0, 38134),
(13122, 12997, 0, 1, 0, 38134),
(13121, 5473, 0, 1, 0, 38134),
(13133, 5473, 0, 0, 1, 38134),
(13120, 0, 0, 1, 0, 38134),
(13134, 0, 0, 0, 1, 38134),
(35810, 7165, 0, 1, 0, 38134),
(35809, 1000, 0, 1, 0, 38134),
(35808, 0, 0, 0, 0, 38134),
(35039, 23141, 0, 0, 0, 38134),
(35038, 12915, 0, 0, 0, 38134),
(35262, 0, 0, 0, 0, 38134),
(37381, 26247, 0, 1, 0, 38134),
(37380, 11147, 0, 0, 0, 38134),
(37379, 0, 0, 0, 0, 38134),
(34408, 16700, 0, 1, 0, 38134),
(34409, 12300, 0, 0, 0, 38134),
(34406, 6600, 0, 1, 0, 38134),
(34407, 0, 0, 0, 0, 38134),
(36085, 0, 0, 0, 0, 38134),
(36084, 0, 0, 0, 0, 38134),
(34633, 8200, 0, 0, 0, 38134),
(34632, 4700, 0, 1, 0, 38134),
(34631, 0, 0, 0, 0, 38134),
(37358, 66415, 0, 10, 0, 38134),
(37512, 66415, 0, 1, 1, 38134),
(37511, 66415, 0, 3, 1, 38134),
(37510, 66415, 0, 9, 1, 38134),
(38356, 66415, 0, 8, 1, 38134),
(38355, 66415, 0, 7, 1, 38134),
(38354, 66415, 0, 2, 1, 38134),
(37509, 66415, 0, 5, 1, 38134),
(38353, 66415, 0, 6, 1, 38134),
(38352, 66415, 0, 4, 1, 38134),
(38351, 66415, 0, 0, 1, 38134),
(37357, 58161, 0, 10, 0, 38134),
(37356, 49268, 0, 1, 1, 38134),
(37508, 49268, 0, 9, 1, 38134),
(38350, 49268, 0, 8, 1, 38134),
(38349, 49268, 0, 7, 1, 38134),
(38348, 49268, 0, 2, 1, 38134),
(38347, 49268, 0, 6, 1, 38134),
(38346, 49268, 0, 5, 1, 38134),
(38345, 49268, 0, 4, 1, 38134),
(38344, 49268, 0, 0, 1, 38134),
(37355, 41779, 0, 3, 1, 38134),
(37516, 41779, 0, 0, 1, 38134),
(37354, 30398, 0, 2, 1, 38134),
(37353, 30398, 0, 1, 1, 38134),
(37507, 22122, 0, 1, 0, 38134),
(37352, 12209, 0, 0, 0, 38134),
(37351, 0, 0, 0, 0, 38134),
(35872, 195771, 0, 0, 0, 38134),
(35871, 181846, 0, 0, 0, 38134),
(35870, 170871, 0, 0, 0, 38134),
(35869, 152911, 0, 0, 0, 38134),
(39630, 135953, 0, 0, 0, 38134),
(35868, 24401, 0, 0, 0, 38134),
(35867, 7598, 0, 0, 0, 38134),
(35866, 0, 0, 0, 0, 38134),
(36430, 9678, 0, 1, 0, 38134),
(36429, 0, 0, 0, 0, 38134),
(35244, 16850, 0, 1, 0, 38134),
(35170, 13550, 0, 0, 0, 38134),
(35169, 10800, 0, 1, 0, 38134),
(35168, 6650, 0, 0, 0, 38134),
(35167, 4150, 0, 1, 0, 38134),
(35166, 0, 0, 0, 0, 38134),
(37612, 3230, 0, 0, 0, 38134),
(37613, 0, 0, 0, 0, 38134),
(37041, 5838, 0, 1, 0, 38134),
(39720, 0, 0, 0, 0, 38134),
(37034, 12407, 1548, 1, 0, 38134),
(37033, 4000, 1548, 1, 0, 38134),
(37032, 0, 0, 0, 0, 38134),
(36827, 32249, 0, 0, 0, 38134),
(35814, 16295, 0, 2, 0, 38134),
(35813, 9648, 0, 1, 0, 38134),
(35812, 0, 0, 0, 0, 38134),
(36759, 30138, 0, 2, 0, 38134),
(37735, 25991, 0, 1, 0, 38134),
(36758, 17271, 0, 2, 0, 38134),
(36757, 10424, 0, 3, 0, 38134),
(36756, 4297, 0, 2, 0, 38134),
(36755, 1000, 0, 1, 0, 38134),
(36760, 0, 0, 0, 0, 38134),
(41393, 4015, 0, 0, 0, 38134),
(41392, 0, 0, 0, 0, 38134),
(36529, 56209, 0, 0, 0, 38134),
(36528, 48784, 0, 2, 0, 38134),
(36527, 43426, 0, 0, 0, 38134),
(36526, 33406, 0, 1, 0, 38134),
(36525, 26315, 0, 1, 0, 38134),
(36524, 17946, 0, 1, 0, 38134),
(36523, 13135, 0, 0, 0, 38134),
(36522, 4327, 0, 1, 0, 38134),
(36521, 0, 0, 0, 0, 38134),
(35266, 4744, 0, 1, 0, 38134),
(35265, 0, 0, 0, 0, 38134),
(37679, 19442, 0, 2, 0, 38134),
(37678, 12901, 0, 2, 0, 38134),
(37677, 9238, 0, 1, 0, 38134),
(37674, 0, 0, 0, 0, 38134),
(36061, 31302, 0, 2, 0, 38134),
(36060, 16396, 0, 1, 0, 38134),
(36059, 0, 0, 0, 0, 38134),
(38199, 9838, 0, 3, 0, 38134),
(38198, 4692, 0, 2, 0, 38134),
(38197, 1000, 0, 1, 0, 38134),
(38196, 0, 0, 0, 0, 38134),
(38418, 0, 0, 0, 0, 38134),
(38403, 7528, 0, 2, 0, 38134),
(38402, 5553, 0, 1, 0, 38134),
(38401, 0, 0, 0, 0, 38134),
(37384, 24876, 0, 0, 0, 38134),
(37383, 13056, 0, 0, 0, 38134),
(37382, 0, 0, 0, 0, 38134),
(40473, 0, 0, 0, 0, 38134),
(41397, 12317, 1458, 2, 0, 38134),
(35820, 5719, 0, 1, 0, 38134),
(35819, 0, 0, 0, 0, 38134),
(37016, 0, 0, 0, 0, 38134),
(36148, 71666, 0, 0, 0, 38134),
(36147, 60972, 0, 3, 0, 38134),
(36146, 48073, 0, 0, 0, 38134),
(36145, 36779, 0, 2, 0, 38134),
(36144, 21529, 0, 0, 0, 38134),
(36142, 6928, 0, 1, 0, 38134),
(36141, 0, 0, 0, 0, 38134),
(37553, 0, 0, 0, 0, 38134),
(37035, 0, 0, 0, 0, 38134),
(41395, 5768, 0, 0, 0, 38134),
(41394, 0, 0, 0, 0, 38134),
(35896, 8276, 0, 1, 0, 38134),
(35895, 0, 0, 0, 0, 38134),
(41387, 6252, 0, 0, 0, 38134),
(41386, 0, 0, 0, 0, 38134),
(41391, 6262, 0, 0, 0, 38134),
(41390, 0, 0, 0, 0, 38134),
(37832, 18105, 0, 1, 0, 38134),
(39009, 10231, 0, 0, 0, 38134),
(37831, 6442, 0, 1, 0, 38134),
(37830, 0, 0, 0, 0, 38134),
(36531, 3609, 0, 0, 0, 38134),
(36530, 0, 0, 0, 0, 38134),
(37389, 30406, 0, 2, 1, 38134),
(37390, 25139, 0, 3, 1, 38134),
(39046, 22908, 0, 2, 1, 38134),
(37388, 18148, 0, 3, 1, 38134),
(37387, 11732, 0, 2, 0, 38134),
(37386, 6362, 0, 1, 0, 38134),
(37385, 0, 0, 0, 0, 38134),
(37020, 0, 0, 0, 0, 38134),
(39045, 7565, 0, 0, 0, 38134),
(39044, 0, 0, 0, 0, 38134),
(35807, 0, 0, 0, 0, 38134),
(38393, 9096, 0, 0, 0, 38134),
(38392, 5027, 0, 1, 0, 38134);

INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(38391, 0, 0, 0, 0, 38134),
(37039, 0, 0, 0, 0, 38134),
(36137, 15845, 0, 0, 0, 38134),
(36136, 5551, 0, 0, 0, 38134),
(36135, 0, 0, 0, 0, 38134),
(35864, 0, 0, 0, 0, 38134),
(39321, 1917, 0, 1, 0, 38134),
(36319, 0, 0, 0, 0, 38134),
(36087, 0, 0, 0, 0, 38134),
(38037, 0, 0, 0, 0, 38134),
(37620, 17233, 0, 1, 0, 38134),
(37619, 12869, 0, 2, 0, 38134),
(37618, 5202, 0, 1, 0, 38134),
(37617, 2326, 0, 0, 0, 38134),
(37616, 0, 0, 0, 0, 38134),
(36217, 3000, 0, 1, 0, 38134),
(36216, 0, 0, 0, 0, 38134),
(38364, 0, 0, 0, 0, 38134),
(35804, 6461, 0, 1, 0, 38134),
(35803, 0, 0, 0, 0, 38134),
(38036, 0, 0, 0, 0, 38134),
(35817, 5787, 0, 1, 0, 38134),
(35816, 2000, 0, 1, 0, 38134),
(35815, 0, 0, 0, 0, 38134),
(36174, 15351, 0, 0, 0, 38134),
(36173, 0, 0, 0, 0, 38134),
(38035, 0, 0, 0, 0, 38134),
(36172, 0, 0, 0, 0, 38134),
(36023, 31730, 0, 0, 0, 38134),
(37876, 24343, 0, 0, 0, 38134),
(36022, 14818, 0, 1, 0, 38134),
(36021, 4302, 0, 0, 0, 38134),
(36020, 0, 0, 0, 0, 38134),
(37680, 0, 0, 0, 0, 38134),
(36967, 12113, 0, 1, 0, 38134),
(36966, 7092, 0, 0, 0, 38134),
(36965, 0, 0, 0, 0, 38134),
(35035, 0, 0, 0, 0, 38134),
(41244, 0, 0, 0, 0, 38134),
(36088, 0, 0, 0, 0, 38134),
(40278, 8773, 0, 0, 0, 38134),
(40276, 0, 0, 0, 0, 38134),
(35856, 62432, 0, 0, 0, 38134),
(35849, 59010, 0, 2, 0, 38134),
(35848, 44124, 0, 1, 0, 38134),
(35847, 33650, 0, 2, 0, 38134),
(35846, 17295, 0, 1, 0, 38134),
(35845, 0, 0, 0, 0, 38134),
(35818, 6444, 0, 1, 0, 38134),
(35715, 0, 0, 0, 0, 38134),
(41389, 5895, 0, 0, 0, 38134),
(41388, 0, 0, 0, 0, 38134),
(38824, 4388, 0, 0, 0, 38134),
(38823, 0, 0, 0, 0, 38134),
(37561, 5792, 0, 1, 0, 38134),
(37560, 0, 0, 0, 0, 38134),
(38055, 0, 1458, 0, 0, 38134),
(36089, 0, 0, 0, 0, 38134),
(37623, 5157, 0, 1, 0, 38134),
(37622, 0, 0, 0, 0, 38134),
(37376, 31443, 0, 0, 0, 38134),
(37375, 16957, 0, 0, 0, 38134),
(37374, 0, 0, 0, 0, 38134),
(36073, 8112, 0, 1, 0, 38134),
(36072, 0, 0, 0, 0, 38134),
(37492, 32285, 0, 0, 0, 38134),
(39251, 26447, 0, 0, 0, 38134),
(40310, 19705, 0, 0, 0, 38134),
(37490, 11338, 0, 0, 0, 38134),
(37489, 0, 0, 0, 0, 38134),
(38822, 6305, 0, 0, 0, 38134),
(38821, 0, 0, 0, 0, 38134),
(34637, 6750, 0, 0, 0, 38134),
(34636, 3950, 0, 1, 0, 38134),
(34635, 0, 0, 0, 0, 38134);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (335697 /*Compendio de llegada*/, 349508 /*Lata de ánima*/, 335698 /*Carillón del pensamiento puro*/, 364443 /*Enfoque ancestral*/, 353484 /*La Gran Bóveda*/, 355835 /*Mapa de las Tierras de las Sombras*/, 353170 /*Colocar hoja*/, 352985 /*Armamentos jurafauces*/, 355356 /*Muro de agua*/, 355354 /*Tentáculo*/, 352491 /*Portal a Descanso Desolado*/, 351722 /*Candado fauceforjado*/, 351754 /*Candado fauceforjado*/, 354124 /*Teletransportador*/, 351761 /*Jaula de fauceacero*/, 354042 /*Pinchos*/, 364862 /*Expositor de armas fauceforjado*/, 353979 /*Teletransportador*/, 352591 /*Fragmento de hielo*/, 315955 /*Transportador de la Plaga*/, 355461 /*Portón de la muerte a Acherus*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(335697, 0, 262144, 0, 0), -- Compendio de llegada
(349508, 0, 262144, 0, 0), -- Lata de ánima
(335698, 0, 262144, 0, 0), -- Carillón del pensamiento puro
(364443, 0, 262144, 0, 12224), -- Enfoque ancestral
(353484, 0, 262144, 0, 0), -- La Gran Bóveda
(355835, 0, 32, 0, 0), -- Mapa de las Tierras de las Sombras
(353170, 0, 16, 0, 0), -- Colocar hoja
(352985, 0, 262144, 0, 0), -- Armamentos jurafauces
(355356, 114, 0, 0, 0), -- Muro de agua
(355354, 0, 0, 0, 1004), -- Tentáculo
(352491, 0, 262144, 0, 0), -- Portal a Descanso Desolado
(351722, 0, 262144, 0, 0), -- Candado fauceforjado
(351754, 0, 262144, 0, 0), -- Candado fauceforjado
(354124, 0, 0, 15425, 0), -- Teletransportador
(351761, 0, 262144, 0, 10311), -- Jaula de fauceacero
(354042, 0, 16, 0, 0), -- Pinchos
(364862, 0, 262176, 16673, 0), -- Expositor de armas fauceforjado
(353979, 0, 0, 0, 2560), -- Teletransportador
(352591, 0, 8192, 0, 0), -- Fragmento de hielo
(315955, 0, 262176, 0, 0), -- Transportador de la Plaga
(355461, 0, 262145, 0, 0); -- Portón de la muerte a Acherus

UPDATE `gameobject_template_addon` SET `flags`=262192 WHERE `entry`=202243; -- Transportador de la Plaga
UPDATE `gameobject_template_addon` SET `flags`=262192 WHERE `entry`=202245; -- Transportador de la Plaga
UPDATE `gameobject_template_addon` SET `flags`=262192 WHERE `entry`=202244; -- Transportador de la Plaga
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=292771; -- Sleeping Mat A

DELETE FROM `scene_template` WHERE (`SceneId`=2639 AND `ScriptPackageID`=3112) OR (`SceneId`=2571 AND `ScriptPackageID`=2939) OR (`SceneId`=2608 AND `ScriptPackageID`=3065) OR (`SceneId`=2625 AND `ScriptPackageID`=3089) OR (`SceneId`=2647 AND `ScriptPackageID`=2993) OR (`SceneId`=2654 AND `ScriptPackageID`=3118) OR (`SceneId`=2646 AND `ScriptPackageID`=3019) OR (`SceneId`=2414 AND `ScriptPackageID`=2814) OR (`SceneId`=2651 AND `ScriptPackageID`=3116) OR (`SceneId`=2648 AND `ScriptPackageID`=3105) OR (`SceneId`=2653 AND `ScriptPackageID`=3117) OR (`SceneId`=2645 AND `ScriptPackageID`=3092) OR (`SceneId`=2643 AND `ScriptPackageID`=3099) OR (`SceneId`=1898 AND `ScriptPackageID`=2024);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2639, 27, 3112, 0),
(2571, 27, 2939, 0),
(2608, 16, 3065, 0),
(2625, 21, 3089, 0),
(2647, 27, 2993, 0),
(2654, 52, 3118, 0),
(2646, 27, 3019, 0),
(2414, 20, 2814, 0),
(2651, 52, 3116, 0),
(2648, 27, 3105, 0),
(2653, 52, 3117, 0),
(2645, 27, 3092, 0),
(2643, 25, 3099, 0),
(1898, 16, 2024, 0);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (59774 /*-Unknown-*/, 59773 /*-Unknown-*/, 60156 /*-Unknown-*/, 60154 /*-Unknown-*/, 60152 /*-Unknown-*/, 63771 /*-Unknown-*/, 60151 /*-Unknown-*/, 60150 /*-Unknown-*/, 60149 /*-Unknown-*/, 60148 /*-Unknown-*/, 60129 /*-Unknown-*/, 62704 /*-Unknown-*/, 59770 /*-Unknown-*/, 59767 /*-Unknown-*/, 60644 /*-Unknown-*/, 59766 /*-Unknown-*/, 59765 /*-Unknown-*/, 59762 /*-Unknown-*/, 59776 /*-Unknown-*/, 59760 /*-Unknown-*/, 59761 /*-Unknown-*/, 59759 /*-Unknown-*/, 59915 /*-Unknown-*/, 59758 /*-Unknown-*/, 59757 /*-Unknown-*/, 59756 /*-Unknown-*/, 59755 /*-Unknown-*/, 59754 /*-Unknown-*/, 59914 /*-Unknown-*/, 59753 /*-Unknown-*/, 59907 /*-Unknown-*/, 59752 /*-Unknown-*/, 59751 /*-Unknown-*/, 60545 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(59774, 273, 0, 0, 0, 0, 0, 0, 0, 'La Anfitriona responderá todas tus preguntas muy pronto. Después de todo, ese es su propósito.\n\n<Kleia te sonríe.>\n\nEspero que estés $gemocionado:emocionada;. ¡Yo sí que estoy emocionada!', 38134), -- -Unknown-
(59773, 273, 0, 0, 0, 0, 0, 0, 0, '¡El camino está abierto nuevamente! ¡Alabada sea la Arconte!', 38134), -- -Unknown-
(60156, 1, 0, 0, 0, 0, 0, 0, 0, '¡Bendito sea el Propósito! Tu camino ahora es más claro.', 38134), -- -Unknown-
(60154, 0, 0, 0, 0, 0, 0, 0, 0, 'Tu camino y el del Propósito ya casi son uno.', 38134), -- -Unknown-
(60152, 1, 0, 0, 0, 0, 0, 0, 0, 'Esperamos que te sientas a gusto aquí, $n.\n\nEste lugar ancestral está a tu disposición.', 38134), -- -Unknown-
(63771, 1, 1, 0, 0, 0, 0, 0, 0, 'Has vuelto, mortal.\n\n¿Quieres cambiar tu destino?', 38134), -- -Unknown-
(60151, 0, 0, 0, 0, 0, 0, 0, 0, 'Tu camino y el Propósito se entrecruzan.', 38134), -- -Unknown-
(60150, 1, 1, 0, 0, 0, 0, 0, 0, '¡$n! Me alegra ver que sobreviviste a ese reino de oscuridad.\n\nAnsío escuchar tu relato.', 38134), -- -Unknown-
(60149, 1, 1, 0, 0, 0, 0, 0, 0, 'Quizá hallemos una causa común en el Propósito. Te ha enviado hacia nosotros.', 38134), -- -Unknown-
(60148, 0, 0, 0, 0, 0, 0, 0, 0, 'Al fin, parece que el Propósito nos guía nuevamente.', 38134), -- -Unknown-
(60129, 0, 0, 0, 0, 0, 0, 0, 0, '¿Será posible? ¿Un verdadero ser mortal en la Ciudad Eterna? ¡Salve el Propósito!', 38134), -- -Unknown-
(62704, 1, 0, 0, 0, 0, 0, 0, 0, 'Has tomado tu decisión. El Propósito te guiará de aquí en adelante.', 38134), -- -Unknown-
(59770, 0, 0, 0, 0, 0, 0, 0, 0, '<La piedra de camino parece estar esperando algo.\n\nEstiras el brazo para tocar su superficie...>', 38134), -- -Unknown-
(59767, 5, 0, 0, 0, 0, 0, 0, 0, '¡Lo logramos! \n\nSi activamos esta piedra de camino, ¡tal vez podamos escapar de este lugar!', 38134), -- -Unknown-
(60644, 1, 1, 0, 0, 0, 0, 0, 0, 'De no haber sido por tu esfuerzo, no tengo dudas de que mi cuerpo y alma estarían atrapados en este sitio desamparado por toda la eternidad.\n\nTe debo mi vida, $n, y lucharé hasta la muerte para devolverte el favor.', 38134), -- -Unknown-
(59766, 1, 0, 0, 0, 0, 0, 0, 0, 'No tiene el equilibro ni la gracia de una buena hacha de los Lobo Gélido, pero tendré que conformarme.\n\nEn marcha.', 38134), -- -Unknown-
(59765, 1, 0, 0, 0, 0, 0, 0, 0, 'Tuvimos suerte de encontrar al hechicero que envenenó el espíritu de Baine.\n\nNecesitaré tu ayuda para romper su vínculo con el gran jefe.', 38134), -- -Unknown-
(59762, 5, 0, 0, 0, 0, 0, 0, 0, '¡El Carcelero tiene a Baine!\n\nEsto es peor de lo que temíamos...', 38134), -- -Unknown-
(59776, 1, 0, 0, 0, 0, 0, 0, 0, 'No puedo decir que disfruté usar el Yelmo de dominación. La magia que contiene es... perturbadora para los muertos.\n\nTe lo devuelvo con mucho gusto.', 38134), -- -Unknown-
(59760, 1, 0, 0, 0, 0, 0, 0, 0, 'Casi había olvidado cómo se siente la libertad.\n\nAhora, es momento de llevar la pelea a esos malignos.', 38134), -- -Unknown-
(59761, 1, 0, 0, 0, 0, 0, 0, 0, 'Sabía que podía confiar en ti para esta tarea. \n\nAunque la adversidad parezca insuperable, tenemos que intentar hacer lo correcto.', 38134), -- -Unknown-
(59759, 1, 0, 0, 0, 0, 0, 0, 0, 'Sabía en mi corazón que la Luz no nos abandonaría.\n\nTu presencia aquí es prueba suficiente.', 38134), -- -Unknown-
(59915, 1, 0, 0, 0, 0, 0, 0, 0, 'Parece que tu búsqueda fue un éxito.\n\nSuficiente descanso. Hay mucho que hacer.', 38134), -- -Unknown-
(59758, 1, 25, 0, 0, 0, 0, 0, 0, 'Si encuentras suficientes bocas, al menos una hablará. \n\nLlevemos esta cosa de regreso a la cueva y averigüemos lo que sabe.', 38134), -- -Unknown-
(59757, 5, 6, 0, 0, 0, 0, 0, 0, '¡Es inútil! Esas almas están demasiado arruinadas para darnos algo útil.\n\nUn momento... ¿qué es eso?', 38134), -- -Unknown-
(59756, 1, 6, 0, 0, 0, 0, 0, 0, 'Necesito tiempo para recuperarme de esa batalla. Thrall también necesita descansar.\n\nMientras tanto, tal vez tú y Mograine puedan buscar respuestas.', 38134), -- -Unknown-
(59755, 1, 0, 0, 0, 0, 0, 0, 0, 'Descansa aquí mientras puedas, $n.\n\nTe diré todo lo que sé.', 38134), -- -Unknown-
(59754, 5, 0, 0, 0, 0, 0, 0, 0, 'Esas imágenes mantendrán a nuestros enemigos distraídos por un tiempo, pero no abandonarán la persecución tan fácilmente.\n\n¡Debemos darnos prisa!', 38134), -- -Unknown-
(59914, 5, 6, 0, 0, 0, 0, 0, 0, '¡Alabada sea la Luz! Casi... Casi pierdo las esperanzas.\n\n<Jaina mira a los Caballeros de la Espada de Ébano.> \n\n¿Esto es... todo lo que queda de tus fuerzas?', 38134), -- -Unknown-
(59753, 1, 0, 0, 0, 0, 0, 0, 0, 'Me niego a abandonar a algunos de nuestros caballeros, pero es obvio que no podemos resistir ante enemigos tan imponentes. \n\nNuestro deber es asegurarnos de que su sacrificio no sea en vano.', 38134), -- -Unknown-
(59907, 1, 0, 0, 0, 0, 0, 0, 0, 'Nuestro enemigo es implacable, pero no dejaremos que avance.\n\nMantente $Gatento:atenta;, $c.', 38134), -- -Unknown-
(59752, 1, 25, 0, 0, 0, 0, 0, 0, 'Llevamos poco tiempo en este lugar, pero nuestras fuerzas ya están agotadas. Tendrán que ser suficientes.\n\nToma este cuerno. Puedes usarlo para convocar al resto de las fuerzas de la Espada de Ébano y pedirles que enfrenten a tus enemigos.', 38134), -- -Unknown-
(59751, 6, 1, 0, 0, 0, 0, 0, 0, 'No es una llegada perfecta, pero al menos estamos enteros.\n\nNo he visto señales de Tyrande. Debe haber aparecido en otro sitio o continuó sin nosotros. Deberíamos mantenernos en alerta.', 38134), -- -Unknown-
(60545, 1, 0, 0, 0, 0, 0, 0, 0, 'Qué bueno que hayas llegado.\n\nNecesitamos $Ghéroes:heroínas; como tú en estos tiempos funestos.', 38134); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=59773 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59773 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59773 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=63771 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59762 AND `BlobIndex`=2 AND `Idx1`=7) OR (`QuestID`=59762 AND `BlobIndex`=1 AND `Idx1`=6) OR (`QuestID`=59762 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=59762 AND `BlobIndex`=1 AND `Idx1`=4) OR (`QuestID`=59762 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59762 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59762 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59762 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59751 AND `BlobIndex`=3 AND `Idx1`=12) OR (`QuestID`=59751 AND `BlobIndex`=2 AND `Idx1`=11) OR (`QuestID`=59751 AND `BlobIndex`=1 AND `Idx1`=10) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=9) OR (`QuestID`=59751 AND `BlobIndex`=1 AND `Idx1`=8) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59751 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(59773, 0, 2, 32, 0, 0, 2222, 1671, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59773, 0, 1, 0, 397980, 167424, 2222, 1671, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59773, 0, 0, -1, 0, 0, 2222, 1533, 0, 0, 0, 0, 0, 1841344, 0, 38134), -- -Unknown-
(63771, 0, 0, -1, 0, 0, 2222, 1670, 0, 2, 0, 0, 0, 2026882, 0, 38134), -- -Unknown-
(59762, 2, 7, 32, 0, 0, 2364, 1648, 0, 1, 0, 0, 0, 1948201, 0, 38134), -- -Unknown-
(59762, 1, 6, 32, 0, 0, 1, 85, 0, 3, 0, 82723, 0, 2001295, 0, 38134), -- -Unknown-
(59762, 0, 5, 32, 0, 0, 0, 84, 0, 3, 0, 82722, 0, 2001334, 0, 38134), -- -Unknown-
(59762, 1, 4, 31, 0, 0, 1, 85, 0, 0, 0, 0, 82723, 2001295, 0, 38134), -- -Unknown-
(59762, 0, 3, 31, 0, 0, 0, 84, 0, 0, 0, 82722, 0, 2001334, 0, 38134), -- -Unknown-
(59762, 0, 2, 2, 404923, 126605, 2364, 1648, 0, 0, 0, 0, 0, 1985319, 0, 38134), -- -Unknown-
(59762, 0, 1, 0, 398073, 166980, 2364, 1648, 0, 0, 0, 0, 0, 1955054, 0, 38134), -- -Unknown-
(59762, 0, 0, -1, 0, 0, 2364, 1648, 0, 0, 0, 0, 0, 1956192, 0, 38134), -- -Unknown-
(59751, 3, 12, 32, 0, 0, 2147, 1360, 0, 6, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 2, 11, 32, 0, 0, 2364, 1648, 0, 4, 0, 87540, 0, 2003624, 0, 38134), -- -Unknown-
(59751, 1, 10, 32, 0, 0, 1, 85, 0, 4, 0, 82723, 0, 2001241, 0, 38134), -- -Unknown-
(59751, 0, 9, 32, 0, 0, 0, 84, 0, 4, 0, 82722, 0, 2001112, 0, 38134), -- -Unknown-
(59751, 1, 8, 31, 0, 0, 1, 85, 0, 0, 0, 82723, 0, 2001241, 0, 38134), -- -Unknown-
(59751, 0, 7, 31, 0, 0, 0, 84, 0, 0, 0, 82722, 0, 2001112, 0, 38134), -- -Unknown-
(59751, 0, 6, 5, 398944, 169109, 2147, 1360, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 5, 4, 398943, 169101, 2147, 1360, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 4, 3, 398942, 169100, 2147, 1360, 0, 6, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 3, 2, 398941, 169098, 2147, 1360, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 2, 1, 398940, 169095, 2147, 1360, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 1, 0, 398939, 169076, 2147, 1360, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 0, 0, -1, 0, 0, 2364, 1648, 0, 0, 0, 0, 0, 1940496, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60150 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=2 AND `Idx1`=11); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=1 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=0 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=1 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=4 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=3 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=2 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=2 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=1 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=1 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=2 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=1 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=2 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=2 AND `Idx1`=10); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=1 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=0 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=1 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=4 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=3 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=2 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=2 AND `Idx1`=9); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=1 AND `Idx1`=8); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=2 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=1 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=3 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=3 AND `Idx1`=7); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=2 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=1 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50239 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50239 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=6); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=1 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50600 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=59773 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59773 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59773 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=63771 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59762 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=12 AND `Idx2`=2) OR (`QuestID`=59751 AND `Idx1`=12 AND `Idx2`=1) OR (`QuestID`=59751 AND `Idx1`=12 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=11 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=10 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=9 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59751 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(59773, 2, 0, -1826, 1183, 0, 38134), -- -Unknown-
(59773, 1, 0, -1827, 1183, 0, 38134), -- -Unknown-
(59773, 0, 0, -4261, -3923, 6561, 38134), -- -Unknown-
(63771, 0, 0, -1829, 1064, 5274, 38134), -- -Unknown-
(59762, 7, 0, 4733, 7654, 4773, 38134), -- -Unknown-
(59762, 6, 0, 1584, -4359, 22, 38134), -- -Unknown-
(59762, 5, 0, -8484, 381, 155, 38134), -- -Unknown-
(59762, 4, 0, 1581, -4361, 21, 38134), -- -Unknown-
(59762, 3, 0, -8484, 384, 116, 38134), -- -Unknown-
(59762, 2, 0, 4565, 7425, 4792, 38134), -- -Unknown-
(59762, 1, 0, 4724, 7424, 4817, 38134), -- -Unknown-
(59762, 0, 0, 4562, 7434, 4791, 38134), -- -Unknown-
(59751, 12, 2, 502, -2126, 0, 38134), -- -Unknown-
(59751, 12, 1, 501, -2126, 0, 38134), -- -Unknown-
(59751, 12, 0, 500, -2126, 0, 38134), -- -Unknown-
(59751, 11, 0, 4122, 7884, 4971, 38134), -- -Unknown-
(59751, 10, 0, 1581, -4361, 21, 38134), -- -Unknown-
(59751, 9, 0, -8484, 384, 116, 38134), -- -Unknown-
(59751, 8, 0, 1581, -4361, 21, 38134), -- -Unknown-
(59751, 7, 0, -8484, 384, 116, 38134), -- -Unknown-
(59751, 6, 0, 507, -2123, 0, 38134), -- -Unknown-
(59751, 5, 0, 506, -2123, 0, 38134), -- -Unknown-
(59751, 4, 0, 504, -2123, 0, 38134), -- -Unknown-
(59751, 3, 0, 506, -2123, 0, 38134), -- -Unknown-
(59751, 2, 0, 504, -2124, 0, 38134), -- -Unknown-
(59751, 1, 0, 500, -2127, 0, 38134), -- -Unknown-
(59751, 0, 0, 4154, 7867, 4969, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59774 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60156 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60154 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60152 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60151 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60150 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60149 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60148 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60129 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=62704 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59770 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=11 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59767 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60644 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59766 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59765 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59776 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59761 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59760 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59759 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59915 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59758 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59757 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59756 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=10 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59755 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59754 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=9 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=8 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59914 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59753 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59907 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=7 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50239 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50239 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49929 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=32675 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=6 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=60545 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50600 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (167827,166981,167833,166723,165918));
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(167827, 0, 0, 0, 'Me alegraré el día que este... lugar sea cosa del pasado.', 38134), -- 167827
(166981, 0, 0, 0, 'Me alegraré el día que este... lugar sea cosa del pasado.', 38134), -- 166981
(167833, 0, 0, 0, 'La Luz nos guiará a través de estos tiempos.', 38134), -- 167833
(166723, 0, 0, 0, 'La Espada de Ébano prevalecerá.', 38134), -- 166723
(165918, 0, 0, 0, 'La Espada de Ébano prevalecerá.', 38134); -- 165918


DELETE FROM `quest_details` WHERE `ID` IN (57102 /*-Unknown-*/, 59774 /*-Unknown-*/, 59773 /*-Unknown-*/, 60156 /*-Unknown-*/, 60154 /*-Unknown-*/, 60152 /*-Unknown-*/, 60151 /*-Unknown-*/, 60150 /*-Unknown-*/, 60149 /*-Unknown-*/, 60148 /*-Unknown-*/, 60129 /*-Unknown-*/, 63771 /*-Unknown-*/, 62704 /*-Unknown-*/, 59770 /*-Unknown-*/, 59767 /*-Unknown-*/, 60644 /*-Unknown-*/, 59766 /*-Unknown-*/, 59765 /*-Unknown-*/, 59762 /*-Unknown-*/, 59776 /*-Unknown-*/, 59761 /*-Unknown-*/, 59760 /*-Unknown-*/, 59759 /*-Unknown-*/, 59915 /*-Unknown-*/, 59758 /*-Unknown-*/, 59757 /*-Unknown-*/, 59756 /*-Unknown-*/, 59755 /*-Unknown-*/, 59754 /*-Unknown-*/, 59914 /*-Unknown-*/, 59753 /*-Unknown-*/, 59907 /*-Unknown-*/, 59752 /*-Unknown-*/, 59751 /*-Unknown-*/, 50239 /*-Unknown-*/, 32470 /*-Unknown-*/, 49929 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(57102, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59774, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59773, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60156, 1, 0, 1, 0, 0, 0, 5, 0, 38134), -- -Unknown-
(60154, 1, 0, 1, 0, 0, 0, 5, 0, 38134), -- -Unknown-
(60152, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60151, 1, 0, 1, 0, 0, 0, 5, 0, 38134), -- -Unknown-
(60150, 1, 0, 1, 0, 0, 0, 5, 0, 38134), -- -Unknown-
(60149, 1, 1, 0, 0, 0, 5, 0, 0, 38134), -- -Unknown-
(60148, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60129, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(63771, 1, 6, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(62704, 2, 6, 0, 0, 0, 1000, 0, 0, 38134), -- -Unknown-
(59770, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59767, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(60644, 1, 6, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59766, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59765, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59762, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59776, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59761, 1, 274, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59760, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59759, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59915, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59758, 25, 0, 0, 0, 0, 1000, 0, 0, 38134), -- -Unknown-
(59757, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59756, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59755, 1, 5, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59754, 1, 25, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59914, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59753, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59907, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59752, 1, 6, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(59751, 1, 1, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(50239, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(32470, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(49929, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=32675; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=32675; -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (59760 /*-Unknown-*/, 59757 /*-Unknown-*/, 59754 /*-Unknown-*/, 60151 /*-Unknown-*/, 60148 /*-Unknown-*/, 60129 /*-Unknown-*/, 59767 /*-Unknown-*/, 59766 /*-Unknown-*/, 59765 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(59760, 6, 0, 0, 0, '¿Encontraste la llave?', 0), -- -Unknown-
(59757, 0, 6, 0, 0, '¿Quieres hablar conmigo o con los muertos?', 38134), -- -Unknown-
(59754, 0, 5, 0, 0, '¿Qué estás haciendo? ¡Este no es momento de hablar!', 38134), -- -Unknown-
(60151, 0, 0, 0, 0, '¿Ya has ayudado a los acólitos a abrir portales?', 38134), -- -Unknown-
(60148, 0, 0, 0, 0, '¿De dónde vienes, $gextraño:extraña;?', 38134), -- -Unknown-
(60129, 0, 0, 0, 0, 'Trata de comunicarte con los guardias y entra a la ciudad.', 38134), -- -Unknown-
(59767, 0, 1, 0, 0, 'Quédate cerca. No podemos permitir que nos vean las fuerzas del Carcelero.', 38134), -- -Unknown-
(59766, 0, 1, 0, 0, 'Debería haber algo que pueda usar aquí...', 38134), -- -Unknown-
(59765, 1, 0, 0, 0, 'Solo podemos suponer que la maldición de Baine sea producto de uno de los hechiceros de aquí.', 0); -- -Unknown-


DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (328076,328075,343942,328172,315985,315984,315983,315978,327205,328440,331393,343882,326539,326537,325405,348402,328796)) OR (`EffectIndex`=4 AND `ID`=343980) OR (`EffectIndex`=1 AND `ID`=329463);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(328076, 0, 2222, -1917.489990234375, 1381.5999755859375, 5266.91015625, 38134), -- Spell: 328076 (Oribos Intro - Teleport From Arbiter's Room) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(328075, 0, 2222, -1833.5799560546875, 1359.56005859375, 5963.31005859375, 38134), -- Spell: 328075 (Oribos Intro - Teleport to Arbiter's Room) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(343942, 0, 2222, -1834.199951171875, 1541.9000244140625, 5274.2001953125, 38134), -- Spell: 343942 (Chromie Teleport) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(343980, 4, 2222, -1834.050048828125, 1541.9100341796875, 5274.16015625, 38134), -- Spell: 343980 (Frozen in Place) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(328172, 0, 2222, -1834.050048828125, 1541.9100341796875, 5274.16015625, 38134), -- Spell: 328172 ([DNT] Scene: Maw Exit) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(315985, 0, 1116, 6625.60009765625, 5797.33984375, 314.769989013671875, 38134), -- Spell: 315985 (Molten Boulder) Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(315984, 0, 1116, 6625.60009765625, 5797.33984375, 314.769989013671875, 38134), -- Spell: 315984 (Molten Boulder) Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(315983, 0, 1116, 6625.60009765625, 5797.33984375, 314.769989013671875, 38134), -- Spell: 315983 (Molten Boulder) Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(315978, 0, 1116, 6625.60009765625, 5797.33984375, 314.769989013671875, 38134), -- Spell: 315978 (Molten Boulder) Efffect: 179 (SPELL_EFFECT_CREATE_AREATRIGGER)
(327205, 0, 2364, 4518.25, 7444.330078125, 4793.41015625, 38134), -- Spell: 327205 ([DNT] Scene: Jailer Intro) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(328440, 0, 2364, 4744.830078125, 7641.39990234375, 4772.6298828125, 38134), -- Spell: 328440 ([DNT] Teleport: Forlorn Respite) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(331393, 0, 2364, 5356.83984375, 7624.06005859375, 4897.4501953125, 38134), -- Spell: 331393 ([DNT] Scene: Sylvanas and Anduin) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(343882, 0, 2364, 5316.43017578125, 7593.89013671875, 4895.8701171875, 38134), -- Spell: 343882 (Jaina Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(326539, 0, 2364, 5255.2001953125, 7526.509765625, 4790.52001953125, 38134), -- Spell: 326539 ([DNT] Teleport Down) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(326537, 0, 2364, 5211.60986328125, 7499.33984375, 4895.5, 38134), -- Spell: 326537 ([DNT] Teleport Up) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(325405, 0, 2364, 4868.08984375, 7703.919921875, 4830.89013671875, 38134), -- Spell: 325405 ([DNT] Calcis Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(329463, 1, 2364, 4145.81005859375, 7872.3798828125, 4970.68017578125, 38134), -- Spell: 329463 (Opening Rift) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(348402, 0, 0, 0, 0, 0, 38134), -- Spell: 348402 (Opening Rift) Efffect: 134 (SPELL_EFFECT_KILL_CREDIT2)
(328796, 0, 2147, 559.83001708984375, -2124.31005859375, 840.8599853515625, 38134); -- Spell: 328796 ([DNT] Teleport: Frozen Throne) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=332475 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (166227 /*166227 (Kleia)*/, 172416 /*172416 (Sobrestante Kah-Sher)*/, 175133 /*175133 (Sendaescriba Roh-Avonavi)*/, 175829 /*175829 (Overseer Kah-Sher)*/, 167682 /*167682 (Acólito de la Espada de Ébano)*/, 167683 /*167683 (Acólito de la Espada de Ébano)*/, 172378 /*172378 (Acólito de la Espada de Ébano)*/, 172377 /*172377 (Acólito de la Espada de Ébano)*/, 173615 /*173615 (Tal-Inara)*/, 167486 /*167486 (Tal-Inara)*/, 167425 /*167425 (Overseer Kah-Delen)*/, 167424 /*167424 (Overseer Kah-Sher)*/, 168252 /*168252 (Capitán protector)*/, 174871 /*174871 (Sinoescriba Roh-Tahl)*/, 172532 /*172532 (Protector asistente)*/, 174917 /*174917 (Protector asistente)*/, 174575 /*174575 (Protector asistente)*/, 168588 /*168588 (Guardia jurafauces) - Accursed Strength*/, 168586 /*168586 (Hechicero jurafauces)*/, 168585 /*168585 (Presagista jurafauces) - [DNT] Mawsworn Lance Visual*/, 168535 /*168535 (Hechicero jurafauces) - [DNT] Maw Dissolve In*/, 175126 /*175126 ([DNT] Bugfix Creature)*/, 168478 /*168478 (Piedra de camino erosionada)*/, 171487 /*171487 (Estigia ardiente)*/, 175125 /*175125 ([DNT] Bugfix Creature)*/, 170208 /*170208 (Estigia ardiente)*/, 157822 /*157822 (Forjaalmas maestro) - Soul Image*/, 175124 /*175124 ([DNT] Bugfix Creature)*/, 168584 /*168584 (Buscador jurafauces)*/, 171486 /*171486 (Atrocidad fundida)*/, 171490 /*171490 (Prisma abrasador)*/, 171492 /*171492 (Forja de almacero)*/, 157820 /*157820 (Vinculadora de llamas mágmica)*/, 171491 /*171491 (Alma abrasada) - Sear Souls*/, 169832 /*169832 (Ojo de la condenación) - Invisibility Detection*/, 157824 /*157824 (Protector de la llama) - Soul Image*/, 167937 /*167937 (Aprisionador jurafauces)*/, 171488 /*171488 (Agente del caldero) - Soul Image*/, 168162 /*168162 (Baine Bloodhoof)*/, 169759 /*169759 (Presencia marchita)*/, 165539 /*165539 (El Carcelero) - [DNT] Jailer Holds Baine*/, 169687 /*169687 (Desgarrador de almas jurafauces)*/, 170519 /*170519 (Stygian Soul) - Quest Invis 5*/, 169676 /*169676 (Depleted Soul)*/, 165543 /*165543 (Helya)*/, 168019 /*168019 (Alma liberada) - Maw Soul*/, 166413 /*166413 (Ritualista de las Fauces)*/, 167834 /*167834 (Phael la Hostigadora)*/, 167960 /*167960 (Buscador colosal) - Invisibility and Stealth Detection*/, 167947 /*167947 (Cazador de almas del Tremaculum)*/, 165545 /*165545 (Sylvanas Brisaveloz)*/, 167833 /*167833 (Anduin Wrynn) - [DNT] Chained Anims*/, 167961 /*167961 ([DNT] Credit: Tremaculum Portal Found)*/, 167847 /*167847 (Alma encadenada) - Maw Soul*/, 167704 /*167704 (Centinela del Tremaculum)*/, 170783 /*170783 (Púas) - [DNT] Follow Trigger, Spikes*/, 175269 /*175269 (Celador del Tremaculum)*/, 167941 /*167941 (Interceptor jurafauces)*/, 167939 /*167939 (Presagista jurafauces)*/, 167690 /*167690 (Amalgama atormentada) - [DNT] Shackled*/, 167943 /*167943 (Alma convertida)*/, 167942 /*167942 (Quebrantador de voluntades jurafauces)*/, 165976 /*165976 (Amalgama atormentada)*/, 170220 /*170220 (Sombra de malicia) - [DNT] Ice Figure*/, 170222 /*170222 (Alma atormentada) - [DNT] Ice Figure*/, 170163 /*170163 (Baine Pezuña de Sangre) - [DNT] Ice Figure*/, 170216 /*170216 (Presagista jurafauces) - [DNT] Ice Figure*/, 170152 /*170152 (Sylvanas Brisaveloz) - [DNT] Ice Figure*/, 170151 /*170151 (El Carcelero) - [DNT] Ice Figure*/, 170180 /*170180 (Guardia jurafauces) - [DNT] Ice Figure*/, 167263 /*167263 (Tariesh) - [DNT] Mawsworn Lance Visual*/, 167604 /*167604 (Alma atormentada)*/, 174787 /*174787 ([DNT] Bugfix Creature)*/, 168544 /*168544 (Presagista jurafauces)*/, 171499 /*171499 ([DNT] Credit: Calcis Second Ambush)*/, 171498 /*171498 ([DNT] Credit: Calcis First Ambush)*/, 165977 /*165977 (Tormented Soul)*/, 177071 /*177071 (Presagista jurafauces) - Fallen Armaments*/, 165978 /*165978 (Faucerrata carroñera)*/, 165909 /*165909 (Sombra de malicia)*/, 167991 /*167991 ([DNT] Credit: Reliquary Approached)*/, 168534 /*168534 (Maestro de canes jurafauces)*/, 166980 /*166980 (Lady Jaina Valiente) - [DNT] Jaina Precast*/, 166981 /*166981 (Thrall) - Set Health (Random 30%-55%)*/, 169474 /*169474 (Large AOI Effect) - [DNT] Random FX*/, 168533 /*168533 (Buscador jurafauces)*/, 167990 /*167990 ([DNT] Credit: Soulgorger Approached)*/, 169655 /*169655 (Alma sobrenatural)*/, 171425 /*171425 ([DNT] Credit: Third Clue)*/, 169656 /*169656 (Filacteria espiritual)*/, 167703 /*167703 (Guardia jurafauces) - [DNT] Drag Soul*/, 166077 /*166077 (Relicario de almas) - Helya*/, 168134 /*168134 (Coalescencia de estigia ambivalente)*/, 167989 /*167989 ([DNT] Credit: Giant Approached)*/, 171424 /*171424 ([DNT] Credit: Second Clue)*/, 169857 /*169857 (Faucerrata monstruosa) - Permanent Feign Death (NO Stun, Untrackable, Immune), [DNT] Blood Splat (Purple)*/, 171100 /*171100 (Serath, el glotón) - [DNT] Eating Souls, Invisibility and Stealth Detection*/, 168542 /*168542 (Gigante estigio) - Permanent Feign Death (NO Stun, Untrackable, Immune), [DNT] Smoldering*/, 167988 /*167988 ([DNT] Credit: Ritual Approached)*/, 168136 /*168136 (Muerte hambrienta)*/, 174681 /*174681 (Intendente Rahm) - Backpack Visual*/, 168044 /*168044 (Alma aterrada) - Enslaved*/, 165983 /*165983 (Presagista jurafauces)*/, 166714 /*166714 (Arruinador Maroth) - Accursed Strength*/, 165862 /*165862 (Caballero de la Espada de ébano)*/, 166195 /*166195 (Devorador de almas atiborrado) - Polymorph*/, 171423 /*171423 ([DNT] Credit: First Clue)*/, 168130 /*168130 (Thelonia el Cruel)*/, 168531 /*168531 (Guardia jurafauces) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 166415 /*166415 (Gigante estigio)*/, 171497 /*171497 (El magíster) - Hologram-ify (Blue, 70% Alpha, No Fade In), [DNT] Magister Soul Channel*/, 170624 /*170624 (Wilona Espina)*/, 166612 /*166612 (Arruinador jurafauces)*/, 165992 /*165992 (Desgarrador de almas jurafauces)*/, 165860 /*165860 (Guardia jurafauces) - Accursed Strength*/, 168012 /*168012 (Mawsworn Guard) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 166119 /*166119 (Doomed Soul) - Maw Soul, Expel Anima, Enslaved*/, 168014 /*168014 (Mawsworn Soulrender) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 165918 /*165918 (Highlord Darion Mograine)*/, 175366 /*175366 (Mawsworn Guard) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 166606 /*166606 (Knight of the Ebon Blade) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 166605 /*166605 (Caballero de la Espada de ébano)*/, 165974 /*165974 (Buscador del Crisol)*/, 166963 /*166963 (Caballero de la Espada de ébano)*/, 169071 /*169071 (Genn Greymane)*/, 170758 /*170758 (Rokhan)*/, 168670 /*168670 (Controlador de reinicio) - [DNT] Reset Ping Aura*/, 169109 /*169109 (Fragmento de dominación) - [DNT] Shard of Domination Main*/, 170760 /*170760 (Trade Prince Gazlowe)*/, 170759 /*170759 (Primera Arcanista Thalyssra)*/, 170763 /*170763 (Muradin Barbabronce)*/, 169101 /*169101 (Fragmento de dominación) - [DNT] Shard of Domination 04*/, 169095 /*169095 (Fragmento de dominación) - [DNT] Shard of Domination 01*/, 170761 /*170761 (Gelbin Mekkatorque)*/, 169075 /*169075 (Calia Menethil)*/, 169072 /*169072 (Tyrande Susurravientos) - [DNT] Maw Dissolve*/, 169076 /*169076 (Alto señor Bolvar Fordragón) - [DNT] Bolvar Stand*/, 169098 /*169098 (Fragmento de dominación) - [DNT] Shard of Domination 02*/, 169073 /*169073 (Lor'themar Theron)*/, 169100 /*169100 (Fragmento de dominación) - [DNT] Shard of Domination 03*/, 169093 /*169093 (Ritualista de la Espada de Ébano) - [DNT] Ritual Stance*/, 170762 /*170762 (Alleria Brisaveloz)*/, 169070 /*169070 (Highlord Darion Mograine)*/, 171789 /*171789 (Alta inquisidora Melenablanca)*/, 176554 /*176554 (Highlord Darion Mograine)*/, 169177 /*169177 (Caballero de la Espada de Ébano)*/, 173220 /*173220 (Guardia de Ventormenta)*/, 173219 /*173219 (Espectador preocupado)*/, 157498 /*157498 (Sra. Pelusas) - Lovely Flower*/, 157496 /*157496 (Sr. Pelusas) - Dapper Hat*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(166227, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 166227 (Kleia)
(172416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172416 (Sobrestante Kah-Sher)
(175133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175133 (Sendaescriba Roh-Avonavi)
(175829, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175829 (Overseer Kah-Sher)
(167682, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167682 (Acólito de la Espada de Ébano)
(167683, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167683 (Acólito de la Espada de Ébano)
(172378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172378 (Acólito de la Espada de Ébano)
(172377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172377 (Acólito de la Espada de Ébano)
(173615, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 173615 (Tal-Inara)
(167486, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 167486 (Tal-Inara)
(167425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167425 (Overseer Kah-Delen)
(167424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167424 (Overseer Kah-Sher)
(168252, 0, 0, 0, 1, 0, 3252, 0, 0, ''), -- 168252 (Capitán protector)
(174871, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174871 (Sinoescriba Roh-Tahl)
(172532, 0, 0, 0, 1, 0, 3785, 0, 0, ''), -- 172532 (Protector asistente)
(174917, 0, 0, 0, 1, 0, 22280, 0, 0, ''), -- 174917 (Protector asistente)
(174575, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174575 (Protector asistente)
(168588, 0, 0, 0, 1, 0, 0, 0, 0, '294165'), -- 168588 (Guardia jurafauces) - Accursed Strength
(168586, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168586 (Hechicero jurafauces)
(168585, 0, 0, 0, 1, 0, 0, 0, 0, '330796'), -- 168585 (Presagista jurafauces) - [DNT] Mawsworn Lance Visual
(168535, 0, 0, 0, 1, 0, 17123, 0, 0, '334018'), -- 168535 (Hechicero jurafauces) - [DNT] Maw Dissolve In
(175126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175126 ([DNT] Bugfix Creature)
(168478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168478 (Piedra de camino erosionada)
(171487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171487 (Estigia ardiente)
(175125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175125 ([DNT] Bugfix Creature)
(170208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170208 (Estigia ardiente)
(157822, 0, 0, 33554432, 1, 0, 0, 0, 0, '307390'), -- 157822 (Forjaalmas maestro) - Soul Image
(175124, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175124 ([DNT] Bugfix Creature)
(168584, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168584 (Buscador jurafauces)
(171486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171486 (Atrocidad fundida)
(171490, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 171490 (Prisma abrasador)
(171492, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 171492 (Forja de almacero)
(157820, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 157820 (Vinculadora de llamas mágmica)
(171491, 0, 0, 0, 1, 0, 0, 0, 0, '331592'), -- 171491 (Alma abrasada) - Sear Souls
(169832, 0, 0, 0, 1, 0, 0, 0, 0, '330665'), -- 169832 (Ojo de la condenación) - Invisibility Detection
(157824, 0, 0, 0, 1, 0, 0, 0, 0, '307373'), -- 157824 (Protector de la llama) - Soul Image
(167937, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167937 (Aprisionador jurafauces)
(171488, 0, 0, 0, 1, 0, 0, 0, 0, '307373'), -- 171488 (Agente del caldero) - Soul Image
(168162, 0, 0, 0, 1, 0, 9627, 0, 0, ''), -- 168162 (Baine Bloodhoof)
(169759, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169759 (Presencia marchita)
(165539, 0, 0, 0, 1, 0, 0, 0, 0, '345139'), -- 165539 (El Carcelero) - [DNT] Jailer Holds Baine
(169687, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 169687 (Desgarrador de almas jurafauces)
(170519, 0, 0, 50397184, 1, 0, 0, 0, 0, '332513'), -- 170519 (Stygian Soul) - Quest Invis 5
(169676, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169676 (Depleted Soul)
(165543, 0, 0, 50331648, 1, 0, 1455, 0, 0, ''), -- 165543 (Helya)
(168019, 0, 0, 0, 1, 0, 0, 0, 0, '323906'), -- 168019 (Alma liberada) - Maw Soul
(166413, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 166413 (Ritualista de las Fauces)
(167834, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167834 (Phael la Hostigadora)
(167960, 0, 0, 0, 1, 0, 0, 0, 0, '18950'), -- 167960 (Buscador colosal) - Invisibility and Stealth Detection
(167947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167947 (Cazador de almas del Tremaculum)
(165545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165545 (Sylvanas Brisaveloz)
(167833, 0, 0, 0, 1, 0, 0, 0, 0, '326608'), -- 167833 (Anduin Wrynn) - [DNT] Chained Anims
(167961, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167961 ([DNT] Credit: Tremaculum Portal Found)
(167847, 0, 0, 0, 1, 0, 0, 0, 0, '323906'), -- 167847 (Alma encadenada) - Maw Soul
(167704, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 167704 (Centinela del Tremaculum)
(170783, 0, 0, 0, 1, 0, 0, 0, 0, '343834 333040'), -- 170783 (Púas) - [DNT] Follow Trigger, Spikes
(175269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 175269 (Celador del Tremaculum)
(167941, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167941 (Interceptor jurafauces)
(167939, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167939 (Presagista jurafauces)
(167690, 0, 0, 0, 1, 0, 0, 0, 0, '326320'), -- 167690 (Amalgama atormentada) - [DNT] Shackled
(167943, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167943 (Alma convertida)
(167942, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167942 (Quebrantador de voluntades jurafauces)
(165976, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165976 (Amalgama atormentada)
(170220, 0, 0, 0, 1, 0, 20920, 0, 0, '331406'), -- 170220 (Sombra de malicia) - [DNT] Ice Figure
(170222, 0, 0, 0, 1, 0, 20921, 0, 0, '331436'), -- 170222 (Alma atormentada) - [DNT] Ice Figure
(170163, 0, 0, 0, 1, 0, 20898, 0, 0, '331406'), -- 170163 (Baine Pezuña de Sangre) - [DNT] Ice Figure
(170216, 0, 0, 50331648, 1, 0, 20912, 0, 0, '331659'), -- 170216 (Presagista jurafauces) - [DNT] Ice Figure
(170152, 0, 0, 0, 1, 0, 20923, 0, 0, '331406'), -- 170152 (Sylvanas Brisaveloz) - [DNT] Ice Figure
(170151, 0, 0, 0, 1, 0, 20922, 0, 0, '331406'), -- 170151 (El Carcelero) - [DNT] Ice Figure
(170180, 0, 0, 0, 1, 0, 2971, 0, 0, '331406'), -- 170180 (Guardia jurafauces) - [DNT] Ice Figure
(167263, 0, 0, 0, 1, 0, 0, 0, 0, '330796'), -- 167263 (Tariesh) - [DNT] Mawsworn Lance Visual
(167604, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167604 (Alma atormentada)
(174787, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174787 ([DNT] Bugfix Creature)
(168544, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168544 (Presagista jurafauces)
(171499, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171499 ([DNT] Credit: Calcis Second Ambush)
(171498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171498 ([DNT] Credit: Calcis First Ambush)
(165977, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165977 (Tormented Soul)
(177071, 0, 0, 0, 1, 0, 0, 0, 0, '304970'), -- 177071 (Presagista jurafauces) - Fallen Armaments
(165978, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165978 (Faucerrata carroñera)
(165909, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165909 (Sombra de malicia)
(167991, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167991 ([DNT] Credit: Reliquary Approached)
(168534, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 168534 (Maestro de canes jurafauces)
(166980, 0, 0, 0, 1, 0, 0, 0, 0, '329892'), -- 166980 (Lady Jaina Valiente) - [DNT] Jaina Precast
(166981, 0, 0, 3, 1, 0, 0, 0, 0, '280552'), -- 166981 (Thrall) - Set Health (Random 30%-55%)
(169474, 0, 0, 0, 1, 0, 0, 0, 0, '329822'), -- 169474 (Large AOI Effect) - [DNT] Random FX
(168533, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168533 (Buscador jurafauces)
(167990, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167990 ([DNT] Credit: Soulgorger Approached)
(169655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169655 (Alma sobrenatural)
(171425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171425 ([DNT] Credit: Third Clue)
(169656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169656 (Filacteria espiritual)
(167703, 0, 0, 0, 0, 0, 0, 0, 0, '333859'), -- 167703 (Guardia jurafauces) - [DNT] Drag Soul
(166077, 0, 0, 0, 1, 0, 0, 0, 0, '234205'), -- 166077 (Relicario de almas) - Helya
(168134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168134 (Coalescencia de estigia ambivalente)
(167989, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167989 ([DNT] Credit: Giant Approached)
(171424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171424 ([DNT] Credit: Second Clue)
(169857, 0, 0, 262144, 1, 0, 0, 0, 0, '159474 334347'), -- 169857 (Faucerrata monstruosa) - Permanent Feign Death (NO Stun, Untrackable, Immune), [DNT] Blood Splat (Purple)
(171100, 0, 0, 0, 1, 0, 0, 0, 0, '333869 18950'), -- 171100 (Serath, el glotón) - [DNT] Eating Souls, Invisibility and Stealth Detection
(168542, 0, 0, 262144, 1, 0, 0, 0, 0, '159474 334399'), -- 168542 (Gigante estigio) - Permanent Feign Death (NO Stun, Untrackable, Immune), [DNT] Smoldering
(167988, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167988 ([DNT] Credit: Ritual Approached)
(168136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168136 (Muerte hambrienta)
(174681, 0, 0, 0, 1, 0, 0, 0, 0, '344606'), -- 174681 (Intendente Rahm) - Backpack Visual
(168044, 0, 0, 0, 1, 0, 0, 0, 0, '323961'), -- 168044 (Alma aterrada) - Enslaved
(165983, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 165983 (Presagista jurafauces)
(166714, 0, 0, 0, 1, 0, 0, 0, 0, '294165'), -- 166714 (Arruinador Maroth) - Accursed Strength
(165862, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 165862 (Caballero de la Espada de ébano)
(166195, 0, 0, 0, 1, 0, 0, 0, 0, '334392'), -- 166195 (Devorador de almas atiborrado) - Polymorph
(171423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171423 ([DNT] Credit: First Clue)
(168130, 0, 0, 50331648, 1, 0, 19698, 0, 0, ''), -- 168130 (Thelonia el Cruel)
(168531, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 168531 (Guardia jurafauces) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(166415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166415 (Gigante estigio)
(171497, 0, 0, 50331648, 1, 0, 0, 14339, 0, '255042 345355'), -- 171497 (El magíster) - Hologram-ify (Blue, 70% Alpha, No Fade In), [DNT] Magister Soul Channel
(170624, 0, 0, 8, 0, 0, 0, 0, 0, ''), -- 170624 (Wilona Espina)
(166612, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166612 (Arruinador jurafauces)
(165992, 0, 0, 0, 1, 0, 14590, 0, 0, ''), -- 165992 (Desgarrador de almas jurafauces)
(165860, 0, 0, 0, 1, 0, 0, 0, 0, '294165'), -- 165860 (Guardia jurafauces) - Accursed Strength
(168012, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 168012 (Mawsworn Guard) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(166119, 0, 0, 0, 1, 0, 0, 0, 0, '323906 324249 323961'), -- 166119 (Doomed Soul) - Maw Soul, Expel Anima, Enslaved
(168014, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 168014 (Mawsworn Soulrender) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(165918, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165918 (Highlord Darion Mograine)
(175366, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 175366 (Mawsworn Guard) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(166606, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 166606 (Knight of the Ebon Blade) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(166605, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 166605 (Caballero de la Espada de ébano)
(165974, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165974 (Buscador del Crisol)
(166963, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166963 (Caballero de la Espada de ébano)
(169071, 0, 0, 8, 0, 0, 0, 0, 0, ''), -- 169071 (Genn Greymane)
(170758, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170758 (Rokhan)
(168670, 0, 0, 0, 1, 0, 0, 0, 0, '328164'), -- 168670 (Controlador de reinicio) - [DNT] Reset Ping Aura
(169109, 0, 0, 0, 1, 0, 0, 0, 0, '328892'), -- 169109 (Fragmento de dominación) - [DNT] Shard of Domination Main
(170760, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170760 (Trade Prince Gazlowe)
(170759, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170759 (Primera Arcanista Thalyssra)
(170763, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170763 (Muradin Barbabronce)
(169101, 0, 0, 0, 1, 0, 0, 0, 0, '328877'), -- 169101 (Fragmento de dominación) - [DNT] Shard of Domination 04
(169095, 0, 0, 0, 1, 0, 0, 0, 0, '328866'), -- 169095 (Fragmento de dominación) - [DNT] Shard of Domination 01
(170761, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170761 (Gelbin Mekkatorque)
(169075, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169075 (Calia Menethil)
(169072, 0, 0, 0, 0, 0, 0, 0, 0, '329026'), -- 169072 (Tyrande Susurravientos) - [DNT] Maw Dissolve
(169076, 0, 0, 0, 1, 0, 0, 0, 0, '328827'), -- 169076 (Alto señor Bolvar Fordragón) - [DNT] Bolvar Stand
(169098, 0, 0, 0, 1, 0, 0, 0, 0, '328874'), -- 169098 (Fragmento de dominación) - [DNT] Shard of Domination 02
(169073, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 169073 (Lor'themar Theron)
(169100, 0, 0, 0, 1, 0, 0, 0, 0, '328876'), -- 169100 (Fragmento de dominación) - [DNT] Shard of Domination 03
(169093, 0, 0, 0, 0, 0, 0, 0, 0, '329476'), -- 169093 (Ritualista de la Espada de Ébano) - [DNT] Ritual Stance
(170762, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 170762 (Alleria Brisaveloz)
(169070, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 169070 (Highlord Darion Mograine)
(171789, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171789 (Alta inquisidora Melenablanca)
(176554, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 176554 (Highlord Darion Mograine)
(169177, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 169177 (Caballero de la Espada de Ébano)
(173220, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173220 (Guardia de Ventormenta)
(173219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 173219 (Espectador preocupado)
(157498, 0, 0, 1, 1, 0, 0, 0, 0, '307181'), -- 157498 (Sra. Pelusas) - Lovely Flower
(157496, 0, 0, 0, 257, 0, 0, 0, 0, '307179'); -- 157496 (Sr. Pelusas) - Dapper Hat

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142346; -- 142346
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='' WHERE `entry`=174794; -- 174794 (Auxiliar kyrian)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=164079; -- 164079 (Highlord Bolvar Fordragon)
UPDATE `creature_template_addon` SET `aiAnimKit`=16748 WHERE `entry`=164803; -- 164803 (Protector supremo de la bóveda)
UPDATE `creature_template_addon` SET `aiAnimKit`=21535 WHERE `entry`=173300; -- 173300 (Administrador de mercados)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=172702; -- 172702 (Facilitador de mercado)
UPDATE `creature_template_addon` SET `aiAnimKit`=16748 WHERE `entry`=156698; -- 156698 (Protector asistente)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=54638; -- 54638 (Generic Bunny)
UPDATE `creature_template_addon` SET `auras`='328888' WHERE `entry`=116633; -- 116633 (Efecto)
UPDATE `creature_template_addon` SET `auras`='127239' WHERE `entry`=51938; -- 51938 (Crithto)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65058; -- 65058 (Tortuga dragón negra)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=65060; -- 65060 (Tortuga dragón azul)
UPDATE `creature_template_addon` SET `aiAnimKit`=15024 WHERE `entry`=133675; -- 133675 (Trabajador campesino)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=44392; -- 44392 (Bozal)
UPDATE `creature_template_addon` SET `auras`='89302' WHERE `entry`=54117; -- 54117 (Vin)
UPDATE `creature_template_addon` SET `auras`='167790' WHERE `entry`=83890; -- 83890 (Pintando)
UPDATE `creature_template_addon` SET `auras`='167804' WHERE `entry`=83878; -- 83878 (Jennica Holzman)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=1302; -- 1302 (Bernard Gump)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=1286; -- 1286 (Edna Mullby)
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=1275; -- 1275 (Kyra Señalo)
UPDATE `creature_template_addon` SET `auras`='221508 18950' WHERE `entry`=113211; -- 113211 (Oficial Ribalimpia)
UPDATE `creature_template_addon` SET `auras`='56384' WHERE `entry`=331; -- 331 (Maginor Dumas)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=1415; -- 1415 (Suzanne)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=1414; -- 1414 (Lisan Pierce)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=1413; -- 1413 (Janey Anship)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=143262; -- 143262
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=143295; -- 143295
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=142136; -- 142136
UPDATE `creature_template_addon` SET `auras`='268083' WHERE `entry`=142457; -- 142457
UPDATE `creature_template_addon` SET `auras`='258793' WHERE `entry`=135230; -- 135230
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123244; -- 123244
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135520; -- 135520
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=133325; -- 133325
UPDATE `creature_template_addon` SET `aiAnimKit`=13360 WHERE `entry`=123169; -- 123169
UPDATE `creature_template_addon` SET `bytes2`=0 WHERE `entry`=142137; -- 142137
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=140313; -- 140313
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=123642; -- 123642 (Boralus Citizen)
UPDATE `creature_template_addon` SET `auras`='263194' WHERE `entry`=143250; -- 143250
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=143502; -- 143502
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142459; -- 142459
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='244874' WHERE `entry`=142166; -- 142166
UPDATE `creature_template_addon` SET `bytes1`=5, `bytes2`=0 WHERE `entry`=135509; -- 135509
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=62821; -- 62821 (Místico Gorro de Ave)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=62822; -- 62822 (Primo Manos Torpes)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=140350; -- 140350
UPDATE `creature_template_addon` SET `bytes1`=5, `auras`='' WHERE `entry`=132638; -- 132638
UPDATE `creature_template_addon` SET `aiAnimKit`=16637 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)

DELETE FROM `creature_template_scaling` WHERE (`Entry`=177071 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(177071, 0, 50, 50, 0, 0, 1400, 38134);

UPDATE `creature_template_scaling` SET `LevelScalingMin`=51, `LevelScalingMax`=51, `LevelScalingDeltaMax`=0, `ContentTuningID`=1314, `VerifiedBuild`=38134 WHERE (`Entry`=166227 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=172416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175133 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=175829 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=167682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=167683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=172378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=172377 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=173615 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=837, `VerifiedBuild`=38134 WHERE (`Entry`=167486 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=167425 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2060, `VerifiedBuild`=38134 WHERE (`Entry`=167424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=168252 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=824, `VerifiedBuild`=38134 WHERE (`Entry`=174871 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=172532 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=174917 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=783, `VerifiedBuild`=38134 WHERE (`Entry`=174575 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168588 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168586 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168585 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168535 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=175126 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168478 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171487 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=175125 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2098, `VerifiedBuild`=38134 WHERE (`Entry`=170208 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2098, `VerifiedBuild`=38134 WHERE (`Entry`=157822 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=175124 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168584 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=171486 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171490 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171492 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2098, `VerifiedBuild`=38134 WHERE (`Entry`=157820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171491 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169832 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2098, `VerifiedBuild`=38134 WHERE (`Entry`=157824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167937 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168162 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169759 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165539 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169687 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170519 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=5, `LevelScalingDeltaMax`=5, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168019 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167834 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167960 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167947 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167961 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167847 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167704 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=709, `VerifiedBuild`=38134 WHERE (`Entry`=170783 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=175269 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167941 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167939 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167943 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167942 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165976 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170220 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170222 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170163 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170152 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170151 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170180 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167263 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167604 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=174787 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168544 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171499 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171498 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165977 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165909 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167991 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166980 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=3, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166981 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=169474 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168533 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167990 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169655 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171425 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169656 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167703 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=166077 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=55, `ContentTuningID`=1936, `VerifiedBuild`=38134 WHERE (`Entry`=168134 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167989 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171424 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169857 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=171100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168542 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=167988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=174681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166714 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=166195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171423 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=168130 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168531 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166415 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=742, `VerifiedBuild`=38134 WHERE (`Entry`=171497 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166612 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165992 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165860 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=126605 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168012 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166119 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=168014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165918 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=175366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166606 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166605 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=165974 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=166963 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=691, `VerifiedBuild`=38134 WHERE (`Entry`=170758 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=181, `VerifiedBuild`=38134 WHERE (`Entry`=168670 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169109 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170760 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170759 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170763 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169101 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169095 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170761 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169073 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169100 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=170762 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=171789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=176554 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=169177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=1401, `VerifiedBuild`=38134 WHERE (`Entry`=173220 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=1400, `VerifiedBuild`=38134 WHERE (`Entry`=173219 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=142786 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=69823 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=49908 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=-4, `LevelScalingDeltaMax`=-4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=49907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=5515 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=5516 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=5517 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=45, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=293, `VerifiedBuild`=38134 WHERE (`Entry`=133369 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0 WHERE (`Entry`=126332 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=65072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=65058 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=65048 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=4, `LevelScalingDeltaMax`=4, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=43451 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=65068 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=65065 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=65060 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=65074 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=65071 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=62106 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=30, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=53, `VerifiedBuild`=38134 WHERE (`Entry`=50088 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=70296 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=872, `VerifiedBuild`=38134 WHERE (`Entry`=65076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=61809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=657, `VerifiedBuild`=38134 WHERE (`Entry`=65063 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=11069 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=44392 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=864, `VerifiedBuild`=38134 WHERE (`Entry`=2879 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=-3 WHERE (`Entry`=14496 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=883, `VerifiedBuild`=38134 WHERE (`Entry`=113211 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90333;
UPDATE `creature_model_info` SET `BoundingRadius`=2.361111164093017578, `CombatReach`=2.5 WHERE `DisplayID`=93593;
UPDATE `creature_model_info` SET `BoundingRadius`=0.441531181335449218, `CombatReach`=0.200000002980232238 WHERE `DisplayID`=93496;
UPDATE `creature_model_info` SET `BoundingRadius`=1.899010181427001953, `CombatReach`=2.25 WHERE `DisplayID`=92534;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.936106681823730468, `CombatReach`=20, `VerifiedBuild`=38134 WHERE `DisplayID`=100390;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96852;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=35372;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=57874;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=73453;
UPDATE `creature_model_info` SET `BoundingRadius`=2.083333253860473632, `CombatReach`=0.550000011920928955, `VerifiedBuild`=38134 WHERE `DisplayID`=97075;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96338;
UPDATE `creature_model_info` SET `BoundingRadius`=4.836450576782226562, `CombatReach`=3 WHERE `DisplayID`=94375;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100447;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=65775;
UPDATE `creature_model_info` SET `BoundingRadius`=1.150964021682739257, `CombatReach`=1.5 WHERE `DisplayID`=92780;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95863;
UPDATE `creature_model_info` SET `BoundingRadius`=4.809200286865234375, `CombatReach`=5 WHERE `DisplayID`=92628;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96935;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99089;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100289;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100295;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100298;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97778;
UPDATE `creature_model_info` SET `BoundingRadius`=1.141621589660644531, `CombatReach`=2.40000009536743164 WHERE `DisplayID`=93157;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100291;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97777;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97246;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97247;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97222;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97245;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97221;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97214;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97225;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97776;
UPDATE `creature_model_info` SET `BoundingRadius`=0.847640693187713623, `CombatReach`=1.25, `VerifiedBuild`=38134 WHERE `DisplayID`=92413;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80015;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=91636;
UPDATE `creature_model_info` SET `BoundingRadius`=0.050000000745058059, `CombatReach`=0.5 WHERE `DisplayID`=96843;
UPDATE `creature_model_info` SET `BoundingRadius`=0.050000000745058059, `CombatReach`=0.5 WHERE `DisplayID`=96842;
UPDATE `creature_model_info` SET `BoundingRadius`=0.075000002980232238, `CombatReach`=0.75 WHERE `DisplayID`=96841;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96113;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99133;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100435;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100319;
UPDATE `creature_model_info` SET `BoundingRadius`=1.827069997787475585, `CombatReach`=1.5 WHERE `DisplayID`=95749;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97929;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96337;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=99020;
UPDATE `creature_model_info` SET `BoundingRadius`=4.150206565856933593, `CombatReach`=17.5 WHERE `DisplayID`=94426;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94391;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100293;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100303;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100317;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=98519;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=95166;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100314;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100301;
UPDATE `creature_model_info` SET `BoundingRadius`=6.138474464416503906, `CombatReach`=8 WHERE `DisplayID`=92781;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100307;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100313;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100287;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100306;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100299;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100302;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100294;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100308;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100288;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100292;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100312;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100297;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100305;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100311;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100290;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100315;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=92412;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100270;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=31379;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=100300;
UPDATE `creature_model_info` SET `BoundingRadius`=1.150964021682739257, `CombatReach`=1.5 WHERE `DisplayID`=92779;
UPDATE `creature_model_info` SET `BoundingRadius`=1.573221087455749511, `CombatReach`=2.319999933242797851 WHERE `DisplayID`=92410;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97373;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90805;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=62751;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97033;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=94037;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88865;
UPDATE `creature_model_info` SET `BoundingRadius`=0.772163748741149902, `CombatReach`=3.674999713897705078 WHERE `DisplayID`=95194;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96328;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97018;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=97372;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96981;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3304;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=71257;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96327;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10569;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96329;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3296;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=1488;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=11746;
UPDATE `creature_model_info` SET `BoundingRadius`=0.135654911398887634, `CombatReach`=0.60000002384185791 WHERE `DisplayID`=44820;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=47711;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=99390;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3309;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3310;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=3534;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5131;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2245;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216235101222991943, `CombatReach`=0.779591858386993408 WHERE `DisplayID`=72180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=93414;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=93410;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=93416;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83234;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=83231;
UPDATE `creature_model_info` SET `BoundingRadius`=0.217223197221755981, `CombatReach`=1 WHERE `DisplayID`=68729;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37112;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=14613;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216235101222991943, `CombatReach`=0.779591858386993408 WHERE `DisplayID`=72186;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=43723;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=19335;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=41281;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=42352;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47980;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33840;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=10477;
UPDATE `creature_model_info` SET `BoundingRadius`=0.973670184612274169, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=719;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5043;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28415;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37120;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=33471;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37113;
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5 WHERE `DisplayID`=5448;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305106639862060546, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=88674;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86659;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86658;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.681569099426269531, `CombatReach`=1.399999976158142089 WHERE `DisplayID`=913;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5 WHERE `DisplayID`=5446;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=9551;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4403;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72724;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=7997;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=14755;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5441;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=4399;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90326;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2247;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=28416;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=37118;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.60000002384185791 WHERE `DisplayID`=87578;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=2269;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90336;
UPDATE `creature_model_info` SET `BoundingRadius`=0.106837116181850433, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=344;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=17514;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=90355;
UPDATE `creature_model_info` SET `BoundingRadius`=1.180964350700378417, `CombatReach`=1.949999928474426269 WHERE `DisplayID`=82148;


DELETE FROM `npc_vendor` WHERE (`entry`=177829 AND `item`=185833 AND `ExtendedCost`=7060 AND `type`=1) OR (`entry`=177829 AND `item`=185832 AND `ExtendedCost`=7060 AND `type`=1) OR (`entry`=177829 AND `item`=185765 AND `ExtendedCost`=7060 AND `type`=1) OR (`entry`=174681 AND `item`=184201 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=174681 AND `item`=184202 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(177829, 3, 185833, 0, 7060, 1, 0, 0, 38134), -- Shipment of Lightless Silk
(177829, 2, 185832, 0, 7060, 1, 0, 0, 38134), -- Shipment of Elethium Ore
(177829, 1, 185765, 0, 7060, 1, 0, 0, 38134), -- Shipment of Heavy Callous Hide
(174681, 2, 184201, 0, 0, 1, 0, 0, 38134), -- Slushy Water
(174681, 1, 184202, 0, 0, 1, 0, 0, 38134); -- Freeze-Dried Salted Meat


DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (166227,168252,172532,174917,174575,168588,168586,168585,168535,157822,157820,157824,167937,171488,168162,169687,167833,167704,175269,167941,167942,170216,167263,168544,177071,168534,166980,166981,167703,174681,165983,166714,165862,168130,168531,170624,166612,165992,165860,168012,168014,175366,166606,166605,166963,170758,170759,170763,169072,169076,169073,169093,170762,169070,171789,176554,169177,173220)) OR (`ID`=2 AND `CreatureID` IN (168531,166981,165862,166605,166606,169177)) OR (`ID`=8 AND `CreatureID`=165862) OR (`ID`=7 AND `CreatureID` IN (165862,166606)) OR (`ID`=6 AND `CreatureID` IN (165862,166605,166606,169177)) OR (`ID`=5 AND `CreatureID` IN (165862,166605,166606,169177)) OR (`ID`=4 AND `CreatureID` IN (165862,166605,166606,169177)) OR (`ID`=3 AND `CreatureID` IN (165862,166605,166606,169177));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(166227, 1, 171132, 0, 0, 0, 0, 0, 0, 0, 0), -- Kleia
(168252, 1, 178411, 0, 0, 0, 0, 0, 0, 0, 0), -- Capitán protector
(172532, 1, 178411, 0, 0, 0, 0, 0, 0, 0, 0), -- Protector asistente
(174917, 1, 180611, 0, 0, 0, 0, 0, 0, 0, 0), -- Protector asistente
(174575, 1, 180611, 0, 0, 0, 0, 0, 0, 0, 0), -- Protector asistente
(168531, 2, 179726, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardia jurafauces
(168588, 1, 108942, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardia jurafauces
(168586, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Hechicero jurafauces
(168585, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0), -- Presagista jurafauces
(168535, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Hechicero jurafauces
(157822, 1, 179725, 0, 0, 0, 0, 0, 0, 0, 0), -- Forjaalmas maestro
(166981, 2, 108941, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(157820, 1, 179725, 0, 0, 0, 0, 0, 0, 0, 0), -- Vinculadora de llamas mágmica
(157824, 1, 179728, 0, 0, 0, 0, 0, 0, 0, 0), -- Protector de la llama
(167937, 1, 178563, 0, 0, 0, 0, 0, 0, 0, 0), -- Aprisionador jurafauces
(171488, 1, 179728, 0, 0, 0, 0, 0, 0, 0, 0), -- Agente del caldero
(168162, 1, 27862, 0, 0, 0, 0, 0, 0, 0, 0), -- Baine Bloodhoof
(169687, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Desgarrador de almas jurafauces
(167833, 1, 45899, 0, 0, 0, 0, 0, 0, 0, 0), -- Anduin Wrynn
(167704, 1, 0, 0, 0, 0, 0, 0, 179731, 0, 0), -- Centinela del Tremaculum
(175269, 1, 179728, 0, 0, 0, 0, 0, 0, 0, 0), -- Celador del Tremaculum
(167941, 1, 109640, 0, 0, 0, 0, 0, 134778, 0, 0), -- Interceptor jurafauces
(167942, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Quebrantador de voluntades jurafauces
(170216, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0), -- Presagista jurafauces
(167263, 1, 109611, 0, 0, 0, 0, 0, 0, 0, 0), -- Tariesh
(168544, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0), -- Presagista jurafauces
(177071, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0), -- Presagista jurafauces
(165862, 8, 75223, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(168534, 1, 109640, 0, 0, 0, 0, 0, 134778, 0, 0), -- Maestro de canes jurafauces
(166980, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0), -- Lady Jaina Valiente
(166981, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0), -- Thrall
(167703, 1, 179728, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardia jurafauces
(165862, 7, 171617, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(165862, 6, 163542, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(174681, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0), -- Intendente Rahm
(165862, 5, 164981, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(165862, 4, 164980, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(165983, 1, 110389, 0, 0, 0, 0, 0, 0, 0, 0), -- Presagista jurafauces
(166714, 1, 110577, 0, 0, 0, 0, 0, 0, 0, 0), -- Arruinador Maroth
(165862, 3, 117049, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(165862, 2, 174488, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(165862, 1, 49886, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(168130, 1, 176061, 0, 0, 0, 0, 0, 0, 0, 0), -- Thelonia el Cruel
(166606, 7, 163542, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(168531, 1, 108942, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardia jurafauces
(166605, 6, 164980, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166605, 5, 171617, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166605, 4, 164981, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166606, 6, 117049, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(170624, 1, 164980, 0, 0, 0, 0, 0, 0, 0, 0), -- Wilona Espina
(166612, 1, 110576, 0, 0, 0, 0, 0, 0, 0, 0), -- Arruinador jurafauces
(166606, 5, 75223, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(166606, 4, 49886, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(166605, 3, 75223, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166605, 2, 49886, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166606, 3, 164981, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(165992, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Desgarrador de almas jurafauces
(165860, 1, 108942, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardia jurafauces
(166606, 2, 174488, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(168012, 1, 108942, 0, 0, 0, 0, 0, 0, 0, 0), -- Mawsworn Guard
(168014, 1, 111746, 0, 0, 0, 0, 0, 0, 0, 0), -- Mawsworn Soulrender
(175366, 1, 108942, 0, 0, 0, 0, 0, 0, 0, 0), -- Mawsworn Guard
(166606, 1, 171617, 0, 0, 0, 0, 0, 0, 0, 0), -- Knight of the Ebon Blade
(166605, 1, 174488, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(166963, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de ébano
(170758, 1, 29433, 0, 0, 0, 0, 0, 0, 0, 0), -- Rokhan
(170759, 1, 132171, 0, 0, 0, 0, 0, 0, 0, 0), -- Primera Arcanista Thalyssra
(169177, 6, 164981, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(170763, 1, 49775, 0, 0, 0, 0, 0, 0, 0, 0), -- Muradin Barbabronce
(169072, 1, 164726, 0, 0, 0, 0, 0, 0, 0, 0), -- Tyrande Susurravientos
(169076, 1, 177838, 0, 0, 0, 0, 0, 0, 0, 0), -- Alto señor Bolvar Fordragón
(169073, 1, 168606, 0, 0, 0, 0, 0, 86538, 0, 0), -- Lor'themar Theron
(169093, 1, 42477, 0, 0, 0, 0, 0, 0, 0, 0), -- Ritualista de la Espada de Ébano
(169177, 5, 49886, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(170762, 1, 0, 0, 0, 0, 0, 0, 151781, 0, 0), -- Alleria Brisaveloz
(169070, 1, 40276, 0, 0, 40276, 0, 0, 0, 0, 0), -- Highlord Darion Mograine
(169177, 4, 164980, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(171789, 1, 129456, 0, 0, 0, 0, 0, 0, 0, 0), -- Alta inquisidora Melenablanca
(176554, 1, 40276, 0, 0, 40276, 0, 0, 0, 0, 0), -- Highlord Darion Mograine
(169177, 3, 75223, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(169177, 2, 117049, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(169177, 1, 174488, 0, 0, 0, 0, 0, 0, 0, 0), -- Caballero de la Espada de Ébano
(173220, 1, 1899, 0, 0, 143, 0, 0, 2551, 0, 0); -- Guardia de Ventormenta

UPDATE `creature_equip_template` SET `ItemID1`=40276, `ItemID2`=40276 WHERE (`CreatureID`=165918 AND `ID`=1); -- Highlord Darion Mograine
UPDATE `creature_equip_template` SET `ItemID1`=1899 WHERE (`CreatureID`=1976 AND `ID`=2); -- Patrulla urbana de Ventormenta
UPDATE `creature_equip_template` SET `ItemID1`=1899 WHERE (`CreatureID`=68 AND `ID`=2); -- Guardia de la ciudad de Ventormenta
UPDATE `creature_equip_template` SET `ItemID1`=2715 WHERE (`CreatureID`=68 AND `ID`=1); -- Guardia de la ciudad de Ventormenta
UPDATE `creature_equip_template` SET `ItemID1`=2715 WHERE (`CreatureID`=1976 AND `ID`=1); -- Patrulla urbana de Ventormenta

DELETE FROM `points_of_interest` WHERE `ID`=6804;
INSERT INTO `points_of_interest` (`ID`, `PositionX`, `PositionY`, `Icon`, `Flags`, `Importance`, `Name`, `VerifiedBuild`) VALUES
(6804, -1810.7099609375, 1537.31005859375, 7, 10302, 0, '�@Portal a Ven', 38134);


DELETE FROM `gossip_menu` WHERE (`TextId`=40132 AND `MenuId`=25436) OR (`TextId`=42424 AND `MenuId`=26679) OR (`TextId`=41605 AND `MenuId`=26208) OR (`TextId`=40476 AND `MenuId`=25639) OR (`TextId`=40400 AND `MenuId` IN (25575,26362)) OR (`TextId`=40466 AND `MenuId`=25620) OR (`TextId`=40465 AND `MenuId`=25621) OR (`TextId`=42403 AND `MenuId`=26681) OR (`TextId`=39804 AND `MenuId`=25245) OR (`TextId`=40471 AND `MenuId`=25625) OR (`TextId`=41758 AND `MenuId`=26307) OR (`TextId`=40469 AND `MenuId`=25624) OR (`TextId`=42094 AND `MenuId`=26524) OR (`TextId`=40468 AND `MenuId`=25622) OR (`TextId`=40449 AND `MenuId` IN (25607,26160)) OR (`TextId`=40394 AND `MenuId`=25571) OR (`TextId`=42807 AND `MenuId`=26893) OR (`TextId`=40384 AND `MenuId`=25565) OR (`TextId`=42360 AND `MenuId`=26637) OR (`TextId`=40613 AND `MenuId`=25709) OR (`TextId`=40523 AND `MenuId`=25674) OR (`TextId`=40938 AND `MenuId`=25888) OR (`TextId`=41013 AND `MenuId`=25590) OR (`TextId`=40425 AND `MenuId`=25590) OR (`TextId`=40392 AND `MenuId`=25569) OR (`TextId`=41731 AND `MenuId`=26056) OR (`TextId`=33468 AND `MenuId`=21897) OR (`TextId`=33467 AND `MenuId`=21896);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25436, 40132, 38134), -- 166227 (Kleia)
(26679, 42424, 38134), -- 175133 (Sendaescriba Roh-Avonavi)
(26208, 41605, 38134), -- 167424 (Overseer Kah-Sher)
(25639, 40476, 38134), -- 167424 (Overseer Kah-Sher)
(25575, 40400, 38134), -- 167486 (Tal-Inara)
(25620, 40466, 38134), -- 156768 (Sobrestante Ta'readon)
(25621, 40465, 38134), -- 156768 (Sobrestante Ta'readon)
(26681, 42403, 38134), -- 164173 (Sinoescriba Roh-Tahl)
(25245, 39804, 38134), -- 164173 (Sinoescriba Roh-Tahl)
(25625, 40471, 38134), -- 164173 (Sinoescriba Roh-Tahl)
(26307, 41758, 38134), -- 173350 (Ba'vol)
(25624, 40469, 38134), -- 174564 (Cuidador Kah-Rahm)
(26524, 42094, 38134), -- 174564 (Cuidador Kah-Rahm)
(25622, 40468, 38134), -- 167738 (Capataz Au'brak)
(25607, 40449, 38134), -- 167682 (Acólito de la Espada de Ébano)
(26160, 40449, 38134), -- 172378 (Acólito de la Espada de Ébano)
(25571, 40394, 38134), -- 167425 (Overseer Kah-Delen)
(26362, 40400, 38134), -- 173615 (Tal-Inara)
(26893, 42807, 38134), -- 156698 (Protector asistente)
(25565, 40384, 38134), -- 168252 (Capitán protector)
(26637, 42360, 38134), -- 174871 (Sinoescriba Roh-Tahl)
(25709, 40613, 38134), -- 166980 (Lady Jaina Valiente)
(25674, 40523, 38134), -- 165918 (Highlord Darion Mograine)
(25888, 40938, 38134), -- 166980 (Lady Jaina Valiente)
(25590, 41013, 38134), -- 166980 (Lady Jaina Valiente)
(25590, 40425, 38134), -- 166980 (Lady Jaina Valiente)
(25569, 40392, 38134), -- 166980 (Lady Jaina Valiente)
(26056, 41731, 38134), -- 171789 (Alta inquisidora Melenablanca)
(21897, 33468, 38134), -- 16908 (Arielle Azoterraudo)
(21896, 33467, 38134); -- 16908 (Arielle Azoterraudo)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25540 AND `TextId`=40335); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=9781 AND `TextId`=13459); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=9781 AND `TextId`=13459); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25935 AND `TextId`=41113); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=26701 AND `TextId`=42457); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=26645 AND `TextId`=42430); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25930 AND `TextId`=41108); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25929 AND `TextId`=41107); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=25928 AND `TextId`=41105); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22198 AND `TextId`=34007); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (25436,26679,25639,25621,26681,25623,25607,26160,25575,25571,25565,26637,25709,25674,25888,25590,25569,26056,21896)) OR (`OptionIndex`=3 AND `MenuId`=25575) OR (`OptionIndex`=2 AND `MenuId` IN (25245,25248,26362,25590)) OR (`OptionIndex`=1 AND `MenuId` IN (25245,26524,26362,25571,25590));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(25436, 0, 0, 'Yo te sigo, Kleia.', 0, 38134),
(26679, 0, 0, 'Estoy lista. Envíame a Bastión.', 0, 38134),
(25639, 0, 0, 'Iré contigo.', 0, 38134),
(25575, 3, 0, '¿Puedes ayudarnos a encontrar respuestas?', 0, 38134),
(25621, 0, 0, '¿Qué es este bazar?', 0, 38134),
(26681, 0, 0, 'Estoy lista para elegir mi destino en las Tierras de las Sombras.', 0, 38134),
(25245, 2, 0, 'Quiero hablar contigo sobre los \"Hilos del destino\".', 0, 38134),
(25245, 1, 0, '¿Qué es este lugar?', 0, 38134),
(25248, 2, 0, 'Gracias por una bienvenida tan cálida a tu posada.', 0, 38134),
(26524, 1, 0, '¿Qué es el Salón de Posesiones?', 0, 38134),
(25623, 0, 0, '¿Qué hay aquí?', 0, 38134),
(25607, 0, 0, 'Invoca los portales aquí.', 0, 38134),
(26160, 0, 0, 'Vayamos afuera.', 0, 38134),
(26362, 2, 0, 'Estoy lista para regresar.', 0, 38134),
(26362, 1, 0, '¿Qué es este lugar?', 0, 38134),
(25575, 0, 0, 'Me uniré a ustedes.', 0, 38134),
(25571, 1, 0, 'Sí, escapé de las Fauces.', 0, 38134),
(25571, 0, 0, '¿Tú estás a cargo aquí? ¿Dónde estoy?', 0, 38134),
(25565, 0, 0, '¿Dónde estoy? ¿Escapé de las Fauces?', 0, 38134),
(26637, 0, 0, 'Estoy lista para elegir mi destino en las Tierras de las Sombras.', 0, 38134),
(25709, 0, 0, 'Estoy lista.', 0, 38134),
(25674, 0, 0, 'Hazlo hablar.', 0, 38134),
(25888, 0, 0, '<Mantén un perfil bajo y observa.>', 0, 38134),
(25590, 2, 0, '¿Qué sabes de los demás prisioneros?', 0, 38134),
(25590, 1, 0, 'Dime más sobre el Carcelero.', 0, 38134),
(25590, 0, 0, 'Háblame de este lugar.', 0, 38134),
(25569, 0, 0, 'Estoy lista.', 0, 38134),
(26056, 0, 0, 'Dime qué pasó.', 0, 38134),
(21896, 0, 0, '¿Qué significa S.E.L.F.I.E?', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (25639,25621,25623,21896)) OR (`OptionIndex`=2 AND `MenuId` IN (25245,25248)) OR (`OptionIndex`=1 AND `MenuId` IN (25245,26524)) OR (`OptionIndex`=12 AND `MenuId`=25927) OR (`OptionIndex`=6 AND `MenuId`=25927);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(25639, 0, 26208, 0),
(25621, 0, 25620, 0),
(25245, 2, 26681, 0),
(25245, 1, 25625, 0),
(25248, 2, 25248, 0),
(26524, 1, 25624, 0),
(25623, 0, 25622, 0),
(25927, 12, 26893, 6870),
(25927, 6, 26645, 6804),
(21896, 0, 21897, 0);



DELETE FROM `creature_template` WHERE `entry`=177071;
INSERT INTO `creature_template` (`entry`, `gossip_menu_id`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `VehicleId`, `HoverHeight`) VALUES
(177071, 0, 50, 50, 16, 0, 1, 1.142857193946838378, 2000, 0, 32768, 2048, 0, 4, 0, 1); -- Presagista jurafauces

UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=165107; -- Kleia
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=128 WHERE `entry`=166163; -- Goliat centurión
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=128 WHERE `entry`=156398; -- Goliat centurión
UPDATE `creature_template` SET `npcflag`=0, `dynamicflags`=128 WHERE `entry`=166164; -- Coloso centurión
UPDATE `creature_template` SET `minlevel`=51, `maxlevel`=51, `faction`=3166, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=166227; -- Kleia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=162666; -- Pathscribe Roh-Avonavi
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=3, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=172416; -- Sobrestante Kah-Sher
UPDATE `creature_template` SET `gossip_menu_id`=26679, `minlevel`=60, `maxlevel`=60, `npcflag`=8195, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175133; -- Sendaescriba Roh-Avonavi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=2, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=175829; -- Overseer Kah-Sher
UPDATE `creature_template` SET `gossip_menu_id`=21043 WHERE `entry`=156663; -- Tejedor de distorsión Ta'oren
UPDATE `creature_template` SET `gossip_menu_id`=26681 WHERE `entry`=164173; -- Sinoescriba Roh-Tahl
UPDATE `creature_template` SET `gossip_menu_id`=25620 WHERE `entry`=156768; -- Sobrestante Ta'readon
UPDATE `creature_template` SET `gossip_menu_id`=9781 WHERE `entry`=156735; -- Barbero Ta'visage
UPDATE `creature_template` SET `gossip_menu_id`=26307 WHERE `entry`=173350; -- Ba'vol
UPDATE `creature_template` SET `gossip_menu_id`=25624 WHERE `entry`=174564; -- Cuidador Kah-Rahm
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=165379; -- Investigador Au'daluk
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=156669; -- Peletero Au'qil
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=156681; -- Costurero Au'phes
UPDATE `creature_template` SET `gossip_menu_id`=25607, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167682; -- Acólito de la Espada de Ébano
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=167683; -- Acólito de la Espada de Ébano
UPDATE `creature_template` SET `gossip_menu_id`=25540 WHERE `entry`=164079; -- Highlord Bolvar Fordragon
UPDATE `creature_template` SET `gossip_menu_id`=26160, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `speed_walk`=2.40000009536743164, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=172378; -- Acólito de la Espada de Ébano
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=2.40000009536743164, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=172377; -- Acólito de la Espada de Ébano
UPDATE `creature_template` SET `gossip_menu_id`=26362, `minlevel`=60, `maxlevel`=60, `npcflag`=1, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=173615; -- Tal-Inara
UPDATE `creature_template` SET `minlevel`=60, `npcflag`=3, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167486; -- Tal-Inara
UPDATE `creature_template` SET `gossip_menu_id`=25622 WHERE `entry`=167738; -- Capataz Au'brak
UPDATE `creature_template` SET `unit_flags2`=34816 WHERE `entry`=164803; -- Protector supremo de la bóveda
UPDATE `creature_template` SET `gossip_menu_id`=25571, `minlevel`=120, `maxlevel`=120, `npcflag`=3, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167425; -- Overseer Kah-Delen
UPDATE `creature_template` SET `gossip_menu_id`=26208, `minlevel`=120, `maxlevel`=120, `npcflag`=3, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=167424; -- Overseer Kah-Sher
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=156670; -- Tasador Au'vesk
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=168252; -- Capitán protector
UPDATE `creature_template` SET `gossip_menu_id`=26637, `minlevel`=60, `maxlevel`=60, `npcflag`=3, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=174871; -- Sinoescriba Roh-Tahl
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=172532; -- Protector asistente
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=174917; -- Protector asistente
UPDATE `creature_template` SET `unit_flags2`=4229120 WHERE `entry`=156698; -- Protector asistente
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=174575; -- Protector asistente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2022, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=168588; -- Guardia jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2022, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480, `HoverHeight`=2 WHERE `entry`=168586; -- Hechicero jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2022, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=168585; -- Presagista jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099232, `HoverHeight`=2 WHERE `entry`=168535; -- Hechicero jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=175126; -- [DNT] Bugfix Creature
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=69240832 WHERE `entry`=168478; -- Piedra de camino erosionada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=171487; -- Estigia ardiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=175125; -- [DNT] Bugfix Creature
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=170208; -- Estigia ardiente
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.399999976158142089 WHERE `entry`=157822; -- Forjaalmas maestro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=175124; -- [DNT] Bugfix Creature
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2022, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=168584; -- Buscador jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=171486; -- Atrocidad fundida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=634, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=171490; -- Prisma abrasador
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=67127296, `unit_flags3`=1 WHERE `entry`=171492; -- Forja de almacero
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157820; -- Vinculadora de llamas mágmica
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=37781504, `unit_flags2`=2048 WHERE `entry`=171491; -- Alma abrasada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169832; -- Ojo de la condenación
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=157824; -- Protector de la llama
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167937; -- Aprisionador jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=171488; -- Agente del caldero
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33605632, `unit_flags3`=524800 WHERE `entry`=168162; -- Baine Bloodhoof
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169759; -- Presencia marchita
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_walk`=6, `speed_run`=2.142857074737548828, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2099200 WHERE `entry`=165539; -- El Carcelero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=169687; -- Desgarrador de almas jurafauces
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200 WHERE `entry`=170519; -- Stygian Soul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=169676; -- Depleted Soul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `speed_run`=2.142857074737548828, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2099200 WHERE `entry`=165543; -- Helya
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=168019; -- Alma liberada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=166413; -- Ritualista de las Fauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167834; -- Phael la Hostigadora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167960; -- Buscador colosal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=33556480, `VehicleId`=7162 WHERE `entry`=167947; -- Cazador de almas del Tremaculum
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=165545; -- Sylvanas Brisaveloz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2713, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=35702784 WHERE `entry`=167833; -- Anduin Wrynn
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=167961; -- [DNT] Credit: Tremaculum Portal Found
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=167847; -- Alma encadenada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167704; -- Centinela del Tremaculum
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1 WHERE `entry`=170783; -- Púas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=175269; -- Celador del Tremaculum
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167941; -- Interceptor jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=167939; -- Presagista jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=167690; -- Amalgama atormentada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `speed_walk`=1.20000004768371582, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167943; -- Alma convertida
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=167942; -- Quebrantador de voluntades jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_walk`=2, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=33552, `unit_flags2`=33556480 WHERE `entry`=165976; -- Amalgama atormentada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=100665344, `unit_flags3`=524800 WHERE `entry`=170220; -- Sombra de malicia
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `unit_flags3`=524800 WHERE `entry`=170222; -- Alma atormentada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=100681728, `unit_flags3`=524800 WHERE `entry`=170163; -- Baine Pezuña de Sangre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=100665376, `unit_flags3`=524800 WHERE `entry`=170216; -- Presagista jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `unit_flags3`=524800 WHERE `entry`=170152; -- Sylvanas Brisaveloz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=67110912, `unit_flags3`=524800 WHERE `entry`=170151; -- El Carcelero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2080, `unit_flags3`=524800 WHERE `entry`=170180; -- Guardia jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=167263; -- Tariesh
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=167604; -- Alma atormentada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=174787; -- [DNT] Bugfix Creature
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=35653664 WHERE `entry`=168544; -- Presagista jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171499; -- [DNT] Credit: Calcis Second Ambush
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171498; -- [DNT] Credit: Calcis First Ambush
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=165977; -- Tormented Soul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165978; -- Faucerrata carroñera
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `speed_walk`=2, `speed_run`=0.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=165909; -- Sombra de malicia
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=167991; -- [DNT] Credit: Reliquary Approached
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2099232 WHERE `entry`=168534; -- Maestro de canes jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2713, `BaseAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=33572864 WHERE `entry`=166980; -- Lady Jaina Valiente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2714, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432 WHERE `entry`=166981; -- Thrall
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=169474; -- Large AOI Effect
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=35653664 WHERE `entry`=168533; -- Buscador jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=167990; -- [DNT] Credit: Soulgorger Approached
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=169655; -- Alma sobrenatural
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171425; -- [DNT] Credit: Third Clue
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110944, `unit_flags3`=1 WHERE `entry`=169656; -- Filacteria espiritual
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=167703; -- Guardia jurafauces
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33816576, `unit_flags2`=2099200, `unit_flags3`=1 WHERE `entry`=166077; -- Relicario de almas
UPDATE `creature_template` SET `minlevel`=60, `faction`=2136, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=168134; -- Coalescencia de estigia ambivalente
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=167989; -- [DNT] Credit: Giant Approached
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171424; -- [DNT] Credit: Second Clue
UPDATE `creature_template` SET `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=169857; -- Faucerrata monstruosa
UPDATE `creature_template` SET `minlevel`=60, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=171100; -- Serath, el glotón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=536904512, `unit_flags2`=2099233, `unit_flags3`=8192 WHERE `entry`=168542; -- Gigante estigio
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=167988; -- [DNT] Credit: Ritual Approached
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=168136; -- Muerte hambrienta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=174681; -- Intendente Rahm
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=168044; -- Alma aterrada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165983; -- Presagista jurafauces
UPDATE `creature_template` SET `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=166714; -- Arruinador Maroth
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=165862; -- Caballero de la Espada de ébano
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=4227904, `unit_flags2`=2099200 WHERE `entry`=166195; -- Devorador de almas atiborrado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=171423; -- [DNT] Credit: First Clue
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=168130; -- Thelonia el Cruel
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2099233, `unit_flags3`=8192 WHERE `entry`=168531; -- Guardia jurafauces
UPDATE `creature_template` SET `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=166415; -- Gigante estigio
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `HoverHeight`=8 WHERE `entry`=171497; -- El magíster
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170624; -- Wilona Espina
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=166612; -- Arruinador jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.5 WHERE `entry`=165992; -- Desgarrador de almas jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=165860; -- Guardia jurafauces
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126605; -- World Trigger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=168012; -- Mawsworn Guard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048 WHERE `entry`=166119; -- Doomed Soul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192, `HoverHeight`=1.5 WHERE `entry`=168014; -- Mawsworn Soulrender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=165918; -- Highlord Darion Mograine
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=175366; -- Mawsworn Guard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=166606; -- Knight of the Ebon Blade
UPDATE `creature_template` SET `faction`=3222, `npcflag`=0, `BaseAttackTime`=2000, `unit_flags`=33296, `unit_flags2`=33556480 WHERE `entry`=166605; -- Caballero de la Espada de ébano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=67141632, `unit_flags2`=33556480 WHERE `entry`=165974; -- Buscador del Crisol
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=33556480 WHERE `entry`=166963; -- Caballero de la Espada de ébano
UPDATE `creature_template` SET `minlevel`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=169071; -- Genn Greymane
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170758; -- Rokhan
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=168670; -- Controlador de reinicio
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=169109; -- Fragmento de dominación
UPDATE `creature_template` SET `minlevel`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170760; -- Trade Prince Gazlowe
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2799, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170759; -- Primera Arcanista Thalyssra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2959, `BaseAttackTime`=1500, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=170763; -- Muradin Barbabronce
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=169101; -- Fragmento de dominación
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110944, `unit_flags3`=1 WHERE `entry`=169095; -- Fragmento de dominación
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=210, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=170761; -- Gelbin Mekkatorque
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=169075; -- Calia Menethil
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=80, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=169072; -- Tyrande Susurravientos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=169076; -- Alto señor Bolvar Fordragón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=169098; -- Fragmento de dominación
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=169073; -- Lor'themar Theron
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `unit_flags3`=1 WHERE `entry`=169100; -- Fragmento de dominación
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=169093; -- Ritualista de la Espada de Ébano
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=116633; -- Efecto
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=170762; -- Alleria Brisaveloz
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=169070; -- Highlord Darion Mograine
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=165505; -- Loretta Banks
UPDATE `creature_template` SET `gossip_menu_id`=26056, `minlevel`=50, `maxlevel`=50, `faction`=2051, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=171789; -- Alta inquisidora Melenablanca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=3222, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=176554; -- Highlord Darion Mograine
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3222, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=169177; -- Caballero de la Espada de Ébano
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=11, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=173220; -- Guardia de Ventormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=12, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=173219; -- Espectador preocupado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=142786; -- Zoey
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=69823; -- Joe el Gofres
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=49908; -- Otto von Chucho
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=49907; -- Dylan Aguilar
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=5515; -- Einris Lanza Reluciente
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `npcflag`=2, `RangeAttackTime`=0 WHERE `entry`=5516; -- Ulfir Barbaférrea
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=5517; -- Thorfin Petrescudo
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=88080; -- William Henry
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=88081; -- Lilian Mae
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3, `unit_flags`=768 WHERE `entry`=55285; -- Astrid Langstrump
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=133369; -- Druben Brazorrecio
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=141030; -- Druida darnassiano
UPDATE `creature_template` SET `speed_run`=1, `RangeAttackTime`=0 WHERE `entry`=141036; -- Acechador de calabazas
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=141054; -- Mozo de labranza voluntario
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=133408; -- Ashlee Hojaumbra
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=112698; -- Gato
UPDATE `creature_template` SET `gossip_menu_id`=22198, `unit_flags`=33536 WHERE `entry`=126332; -- Aysa Canción Etérea
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=4753; -- Jartsam
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3 WHERE `entry`=4730; -- Lelanai
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=141020; -- Anciano del conocimiento
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0 WHERE `entry`=133433; -- Explorador filo fantasmal
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=50307; -- Lord Candren
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=50305; -- Sacerdotisa Lunar Lasara
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=112686; -- Perro
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=141079; -- Centinela de Darnassus
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=167032; -- Cromi
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=4423; -- Protector de Darnassus
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=112694; -- Gato
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65072; -- Gran tortuga dragón negra
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=65058; -- Tortuga dragón negra
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65048; -- Alumno tushui
UPDATE `creature_template` SET `minlevel`=5, `maxlevel`=5, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=43451; -- Olivia Jayne
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=1, `RangeAttackTime`=0 WHERE `entry`=65068; -- Viejo Morro Blanco
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=65065; -- Tortuga dragón roja
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=65060; -- Tortuga dragón azul
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65074; -- Gran tortuga dragón azul
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65071; -- Gran tortuga dragón verde
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=62106; -- Gran tortuga dragón roja
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=50088; -- Aguas de Clarividencia
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=70296; -- Mei Lin
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=65076; -- Gran tortuga dragón marrón
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=61809; -- Tortuga dragón verde
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35, `RangeAttackTime`=0 WHERE `entry`=65063; -- Tortuga dragón morada
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=2 WHERE `entry`=44395; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43840; -- Fineas G. Bancovalor
UPDATE `creature_template` SET `gossip_menu_id`=21897 WHERE `entry`=16908; -- Arielle Azoterraudo
UPDATE `creature_template` SET `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=3681; -- Fuego fatuo
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43034; -- Colin Campos
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=60, `maxlevel`=60 WHERE `entry`=20407; -- Clarividente Umbrua
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=43723; -- Jamie Crester
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=11069; -- Jenova Petrescudo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=44392; -- Bozal
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=2879; -- Karrina Mekenda
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=11026; -- Duendy Ruedadentada
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5519; -- Billibub Volopiñón
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5518; -- Lilliam Chispeje
UPDATE `creature_template` SET `unit_flags`=33554432 WHERE `entry`=14563; -- Mecazancudo rojo presto
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=43690; -- -Unknown-
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=53626; -- Huérfano de Ventormenta
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=3, `RangeAttackTime`=0 WHERE `entry`=14450; -- Supervisora de huérfanos Ruiseñor
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=14496; -- Huérfano de Ventormenta
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=14497; -- Shellene
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=54117; -- Vin
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=83890; -- Pintando
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=83883; -- Peeps
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=83882; -- Saquea
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=83878; -- Jennica Holzman
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=54026; -- Motitas
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=1371; -- Roman
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=1370; -- Brandon
UPDATE `creature_template` SET `RangeAttackTime`=0 WHERE `entry`=1368; -- Justin
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=3518; -- Thomas Molina
UPDATE `creature_template` SET `gossip_menu_id`=12941 WHERE `entry`=8719; -- Subastador Fitch
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0 WHERE `entry`=113211; -- Oficial Ribalimpia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5566; -- Tannysa
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=150122; -- Mago de Bastión del Honor
UPDATE `creature_template` SET `unit_flags`=33536 WHERE `entry`=123244; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=139522; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=121235; -- Taelia
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135808; -- -Unknown-


DELETE FROM `quest_template` WHERE `ID`=63771;
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(63771, 2, 0, 807, 10565, 0, 0, 0, 1, 1, 23635, 1, 1, 750, 0, 0, 0, 0, 0, 1, 0, 594018304, 2107456, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 8, 0, 0, 'Recordatorio del destino', 'Reúnete con el sinoescriba Roh-Tahl en Oribos si quieres adentrarte en Los Hilos del Destino.', 'El sinoescriba Roh-Tahl te espera en Oribos, por si algún día decides cambiar el curso del destino.\n\nPuedes hablar con él cuando gustes.', '', 'Reúnete con el sinoescriba Roh-Tahl en Oribos para adentrarte en Los Hilos del Destino.', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 38134); -- -Unknown-


DELETE FROM `quest_objectives` WHERE `ID` IN (405248 /*405248*/, 405247 /*405247*/, 405246 /*405246*/, 406785 /*406785*/, 406783 /*406783*/, 396000 /*396000*/, 388050 /*388050*/, 296728 /*296728*/, 296727 /*296727*/, 296726 /*296726*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(405248, 59914, 0, 2, 7, 171425, 1, 2, 0, 0, 'Tercera pista encontrada', 38134), -- 405248
(405247, 59914, 0, 1, 6, 171424, 1, 2, 0, 0, 'Segunda pista encontrada', 38134), -- 405247
(405246, 59914, 0, 0, 5, 171423, 1, 0, 0, 0, 'Primera pista encontrada', 38134), -- 405246
(406785, 61874, 0, 2, 0, 170749, 1, 2, 0, 0, 'Usa el teletransportador para ir al Trono Helado', 38134), -- 406785
(406783, 61874, 14, 0, 1, 87225, 1, 0, 0, 0, 'Aprende sobre el destino de tus líderes', 38134), -- 406783
(396000, 50239, 2, 4, 4, 339222, 1, 0, 0, 0, 'Obtén información sobre los mecagnomos', 38134), -- 396000
(388050, 50239, 2, 3, 3, 316736, 1, 0, 0, 0, 'Obtén información sobre los kultiranos', 38134), -- 388050
(296728, 50239, 2, 2, 0, 298865, 1, 0, 0, 0, 'Obtén información sobre los enanos Hierro Negro', 38134), -- 296728
(296727, 50239, 2, 1, 2, 273853, 1, 0, 0, 0, 'Obtén información sobre los elfos del Vacío', 38134), -- 296727
(296726, 50239, 2, 0, 1, 273855, 1, 0, 0, 0, 'Obtén información sobre los draenei templeluz', 38134); -- 296726


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396945 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396944 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396943 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391724 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391724 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391724 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391650 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391650 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391650 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=391650 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396932 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396926 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396925 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=409163 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=411602 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397825 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396430 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=392886 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397980 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397969 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397891 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397713 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=407951 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397708 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397710 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397709 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397711 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397826 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397707 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405960 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397798 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397785 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397784 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397706 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397783 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397704 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398334 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398491 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398301 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398301 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398197 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398197 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398197 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=399087 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398073 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398069 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398400 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398006 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398006 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398006 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398029 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398028 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398022 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398022 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398021 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=404442 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398039 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397827 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397824 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397823 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397822 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397621 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397468 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405248 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405247 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=408196 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397740 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397740 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397055 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397055 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406785 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406784 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406784 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406783 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398944 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398943 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398943 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398942 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398942 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398941 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398941 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398940 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=398940 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=396000 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388050 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296728 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VisualEffect`=8863, `VerifiedBuild`=38134 WHERE (`ID`=296727 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VisualEffect`=8862, `VerifiedBuild`=38134 WHERE (`ID`=296726 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=59752 AND `Idx`=0);

DELETE FROM `creature_template` WHERE `entry`=177071;
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(177071, 165983, 0, 'Presagista jurafauces', '', NULL, NULL, NULL, 8, 0, 0, 1, 0, 0, 0, 0, 7, 0, 0, 1.5, 1, 0, 0, 38134); -- Presagista jurafauces


UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=154825 AND `Idx`=0); -- Pearlescent Glimmershell
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=161954 AND `Idx`=0); -- K'uddly
UPDATE `creature_template_model` SET `Probability`=100 WHERE (`CreatureID`=5515 AND `Idx`=0); -- Einris Lanza Reluciente
UPDATE `creature_template_model` SET `CreatureDisplayID`=93414 WHERE (`CreatureID`=158123 AND `Idx`=0); -- Representante elfo del Vacío
UPDATE `creature_template_model` SET `CreatureDisplayID`=93412 WHERE (`CreatureID`=158120 AND `Idx`=0); -- Representante Hierro Negro
UPDATE `creature_template_model` SET `CreatureDisplayID`=81532 WHERE (`CreatureID`=158119 AND `Idx`=0); -- Representante kultirano
UPDATE `creature_template_model` SET `Probability`=100 WHERE (`CreatureID`=43824 AND `Idx`=0); -- Ann Wainwright
UPDATE `creature_template_model` SET `Probability`=100 WHERE (`CreatureID`=43823 AND `Idx`=0); -- Leslie Wainwright



UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=203751 AND `Idx`=0); -- Calabaza de Ventormenta

DELETE FROM `playerchoice` WHERE `ChoiceId`=667;
INSERT INTO `playerchoice` (`ChoiceId`, `UiTextureKitId`, `SoundKitId`, `Question`, `HideWarboardHeader`, `KeepOpenAfterChoice`, `VerifiedBuild`) VALUES
(667, 263, 0, 'Elige tu experiencia de Shadowlands', 0, 0, 38134);


DELETE FROM `playerchoice_response` WHERE (`ChoiceId`=667 AND `ResponseId`=3275 AND `Index`=1) OR (`ChoiceId`=667 AND `ResponseId`=3272 AND `Index`=0);
INSERT INTO `playerchoice_response` (`ChoiceId`, `ResponseId`, `ResponseIdentifier`, `Index`, `ChoiceArtFileId`, `Flags`, `WidgetSetId`, `UiTextureAtlasElementID`, `SoundKitId`, `GroupId`, `Header`, `Subheader`, `ButtonTooltip`, `Answer`, `Description`, `Confirmation`, `RewardQuestID`, `UiTextureKitID`, `VerifiedBuild`) VALUES
(667, 3275, 2219, 1, 3799386, 0, 0, 0, 0, 0, 'Jugar historia de nuevo', '', 'Juega la historia principal con este personaje.', 'Jugar historia de nuevo', 'Juega la historia principal de las Tierras de las Sombras para subir de nivel, tal como hiciste con tu primer personaje.\n\nAvanzarás zona por zona a lo largo del arco narrativo hasta llegar a nivel 60 y elegir un pacto.\n\nSi cambias de opinión, puedes volver con el sinoescriba en cualquier momento para seguir los hilos del destino.', '', 0, 0, 38134),
(667, 3272, 2218, 0, 3799388, 0, 0, 0, 0, 0, 'Los hilos del destino', '', 'Omite la historia principal y permite elegir un pacto.', 'Los hilos del destino', 'Completa misiones de mundo, misiones secundarias, objetivos de bonificación y calabozos para subir de nivel.\n\nTe saltarás las misiones de la historia principal y elegirás tu pacto de inmediato.\n\nPodrás acceder a todas las zonas de las Tierras de las Sombras, excepto a las Fauces.\n\nEsta decisión es final y no puede cambiarse.', 'SHADOWLANDS_EXPERIENCE_THREADS_OF_FATE', 0, 0, 38134);

