DELETE FROM `areatrigger_template` WHERE `Id` IN (18196, 21507, 22375);
INSERT INTO `areatrigger_template` (`Id`, isserverside, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(18196, 1, 0, 0, 2.5, 2.5, 0, 0, 0, 0, 38134),
(21507, 1, 0, 4, 35, 35, 0, 0, 0, 0, 38134),
(22375, 1, 0, 0, 8, 8, 0, 0, 0, 0, 38134);


UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17206;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17206;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=17206;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=16810;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=19020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=19020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=19020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=19020;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8394;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8394;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8394;
UPDATE `areatrigger_template` SET `VerifiedBuild`=38134 WHERE `Id`=8394;

REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(13677, 18196, 0, 0, 0, 0, 0, 0, 232, 0, 5000, 38134), -- SpellId : 272924
(17255, 21507, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- SpellId : 301630

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12528 AND `AreaTriggerId`=17206); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12528 AND `AreaTriggerId`=17206); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12528 AND `AreaTriggerId`=17206); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12114 AND `AreaTriggerId`=16819); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=12080 AND `AreaTriggerId`=16787); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12029 AND `AreaTriggerId`=16740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=12104 AND `AreaTriggerId`=16810); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14088 AND `AreaTriggerId`=19020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14088 AND `AreaTriggerId`=19020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14088 AND `AreaTriggerId`=19020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=14088 AND `AreaTriggerId`=19020); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12892 AND `AreaTriggerId`=17536); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=12892 AND `AreaTriggerId`=17536); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3704 AND `AreaTriggerId`=8394); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3704 AND `AreaTriggerId`=8394); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3704 AND `AreaTriggerId`=8394); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=3704 AND `AreaTriggerId`=8394); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2000, `VerifiedBuild`=38134 WHERE (`SpellMiscId`=18264 AND `AreaTriggerId`=22375); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8867 AND `AreaTriggerId`=12929); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2362 WHERE (`SpellMiscId`=21832 AND `AreaTriggerId`=26042); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0

UPDATE `conversation_actors` SET `ConversationActorId`=63615, `VerifiedBuild`=38134 WHERE (`ConversationId`=9316 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7668 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7668 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7668 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7668 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=7668 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9438 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8359 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8359 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8359 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8359 AND `Idx`=0);
UPDATE `conversation_actors` SET `ConversationActorId`=61989, `VerifiedBuild`=38134 WHERE (`ConversationId`=6528 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9435 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9001 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9001 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9196 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9213 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9437 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=2);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=1);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=8227 AND `Idx`=0);
UPDATE `conversation_actors` SET `VerifiedBuild`=38134 WHERE (`ConversationId`=9436 AND `Idx`=0);

DELETE FROM `conversation_actor_template` WHERE `Id` IN (63615, 61989);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(63615, 134282, 71764, 38134),
(61989, 131071, 86567, 38134);


DELETE FROM `conversation_line_template` WHERE `Id` IN (17730, 17729, 17728, 17727, 17726, 17725, 17724, 17731, 17723, 17722, 17400, 17404, 17403, 17402, 17399, 17398, 17405, 17476, 17475, 17474, 17473, 17472, 17471, 17486, 17485, 17484, 19469, 17482, 17673, 17672, 17671, 17670, 17669, 17668, 18464, 18463, 18462, 18461, 17630, 17629, 17628, 17627, 22001, 21764, 21763, 21762, 21761, 21760, 21759, 21758, 21756, 21755, 21754, 21753, 21752, 21751, 21750, 21749, 16626, 16624, 16623, 16622, 16621, 16447, 17635, 17634, 17633, 17465, 17464, 17463, 17462, 17461, 17460, 17459, 17458, 17632, 18964, 21768, 21769, 21767, 21766, 21765, 21770, 17481, 17480, 17479, 17478, 17477, 17631, 18962, 17637, 17636, 17738, 17737, 17736, 17735, 17734, 18963);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(17730, 71250, 0, 2, 0, 38134),
(17729, 68300, 0, 1, 0, 38134),
(17728, 57550, 0, 1, 0, 38134),
(17727, 45550, 0, 1, 0, 38134),
(17726, 39700, 0, 1, 0, 38134),
(17725, 26550, 0, 1, 0, 38134),
(17724, 13450, 0, 1, 0, 38134),
(17731, 10500, 0, 1, 0, 38134),
(17723, 4150, 0, 1, 0, 38134),
(17722, 0, 0, 0, 0, 38134),
(17400, 46200, 0, 1, 0, 38134),
(17404, 38000, 0, 1, 0, 38134),
(17403, 28850, 0, 1, 0, 38134),
(17402, 20000, 0, 1, 0, 38134),
(17399, 9700, 0, 1, 0, 38134),
(17398, 1000, 0, 1, 0, 38134),
(17405, 0, 0, 0, 0, 38134),
(17476, 33450, 0, 0, 0, 38134),
(17475, 25700, 0, 1, 0, 38134),
(17474, 17550, 0, 1, 0, 38134),
(17473, 12500, 0, 0, 0, 38134),
(17472, 4450, 0, 1, 0, 38134),
(17471, 0, 0, 0, 0, 38134),
(17486, 23900, 0, 2, 0, 38134),
(17485, 17650, 0, 0, 0, 38134),
(17484, 10500, 0, 2, 0, 38134),
(19469, 10500, 0, 1, 1, 38134),
(17482, 0, 0, 0, 0, 38134),
(17673, 35400, 0, 0, 0, 38134),
(17672, 29700, 0, 0, 0, 38134),
(17671, 21900, 0, 0, 0, 38134),
(17670, 14400, 0, 0, 0, 38134),
(17669, 3800, 0, 0, 0, 38134),
(17668, 0, 0, 0, 0, 38134),
(18464, 12400, 0, 1, 0, 38134),
(18463, 6850, 0, 0, 0, 38134),
(18462, 3150, 0, 1, 0, 38134),
(18461, 0, 0, 0, 0, 38134),
(17630, 8600, 0, 1, 0, 38134),
(17629, 7050, 0, 0, 0, 38134),
(17628, 2500, 0, 1, 0, 38134),
(17627, 0, 0, 0, 0, 38134),
(22001, 50650, 0, 0, 1, 38134),
(21764, 47050, 0, 1, 1, 38134),
(21763, 44150, 0, 1, 0, 38134),
(21762, 42100, 0, 1, 1, 38134),
(21761, 41100, 0, 2, 1, 38134),
(21760, 38450, 0, 0, 0, 38134),
(21759, 34200, 0, 0, 1, 38134),
(21758, 29100, 0, 1, 0, 38134),
(21756, 23700, 0, 0, 0, 38134),
(21755, 22150, 0, 1, 0, 38134),
(21754, 20750, 0, 0, 1, 38134),
(21753, 13250, 0, 0, 0, 38134),
(21752, 8100, 0, 0, 0, 38134),
(21751, 6900, 0, 0, 1, 38134),
(21750, 2550, 0, 0, 0, 38134),
(21749, 0, 0, 0, 1, 38134),
(16626, 26100, 0, 1, 0, 38134),
(16624, 19900, 0, 2, 0, 38134),
(16623, 13200, 0, 1, 0, 38134),
(16622, 7150, 0, 2, 0, 38134),
(16621, 0, 0, 1, 0, 38134),
(16447, 0, 0, 0, 0, 38134),
(17635, 8450, 0, 1, 0, 38134),
(17634, 2800, 0, 1, 0, 38134),
(17633, 0, 0, 0, 0, 38134),
(17465, 60100, 0, 1, 0, 38134),
(17464, 50700, 0, 1, 0, 38134),
(17463, 42250, 0, 1, 0, 38134),
(17462, 32100, 0, 1, 0, 38134),
(17461, 19850, 0, 1, 0, 38134),
(17460, 11550, 0, 1, 0, 38134),
(17459, 7000, 0, 1, 0, 38134),
(17458, 0, 0, 0, 0, 38134),
(17632, 0, 0, 0, 0, 38134),
(18964, 0, 0, 0, 0, 38134),
(21768, 12350, 0, 2, 1, 38134),
(21769, 11550, 0, 2, 0, 38134),
(21767, 9500, 0, 1, 0, 38134),
(21766, 4200, 0, 1, 0, 38134),
(21765, 2000, 0, 1, 0, 38134),
(21770, 0, 0, 0, 0, 38134),
(17481, 31500, 0, 0, 0, 38134),
(17480, 23700, 0, 1, 0, 38134),
(17479, 15550, 0, 0, 0, 38134),
(17478, 4550, 0, 1, 0, 38134),
(17477, 0, 0, 0, 0, 38134),
(17631, 0, 0, 0, 0, 38134),
(18962, 0, 0, 0, 0, 38134),
(17637, 2300, 0, 1, 0, 38134),
(17636, 0, 0, 0, 0, 38134),
(17738, 15650, 0, 0, 0, 38134),
(17737, 12950, 0, 1, 0, 38134),
(17736, 5000, 0, 0, 0, 38134),
(17735, 1550, 0, 1, 0, 38134),
(17734, 0, 0, 0, 0, 38134),
(18963, 0, 0, 0, 0, 38134);

UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=21011;
UPDATE `conversation_line_template` SET `StartTime`=14850 WHERE `Id`=17470;
UPDATE `conversation_line_template` SET `StartTime`=11650 WHERE `Id`=17469;
UPDATE `conversation_line_template` SET `StartTime`=7300 WHERE `Id`=17468;
UPDATE `conversation_line_template` SET `StartTime`=2350 WHERE `Id`=17467;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=21358;
UPDATE `conversation_line_template` SET `StartTime`=8800, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18919;
UPDATE `conversation_line_template` SET `StartTime`=3800, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18920;
UPDATE `conversation_line_template` SET `StartTime`=1800, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18923;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18918;
UPDATE `conversation_line_template` SET `VerifiedBuild`=38134 WHERE `Id`=14819;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=21355;
UPDATE `conversation_line_template` SET `StartTime`=9203, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=20333;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=20332;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=20666;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=20757;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=21357;
UPDATE `conversation_line_template` SET `StartTime`=52926, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18639;
UPDATE `conversation_line_template` SET `StartTime`=46153, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18638;
UPDATE `conversation_line_template` SET `StartTime`=44397, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18637;
UPDATE `conversation_line_template` SET `StartTime`=34280, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18636;
UPDATE `conversation_line_template` SET `StartTime`=32738, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18635;
UPDATE `conversation_line_template` SET `StartTime`=23745, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18634;
UPDATE `conversation_line_template` SET `StartTime`=20471, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18633;
UPDATE `conversation_line_template` SET `StartTime`=10079, `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18632;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=18631;
UPDATE `conversation_line_template` SET `UiCameraID`=0, `VerifiedBuild`=38134 WHERE `Id`=21356;


UPDATE `conversation_template` SET `LastLineEndTime`=4866, `VerifiedBuild`=38134 WHERE `Id`=9438;
UPDATE `conversation_template` SET `LastLineEndTime`=6201, `VerifiedBuild`=38134 WHERE `Id`=9437;
UPDATE `conversation_template` SET `LastLineEndTime`=2961, `VerifiedBuild`=38134 WHERE `Id`=9436;
UPDATE `conversation_template` SET `LastLineEndTime`=3071, `VerifiedBuild`=38134 WHERE `Id`=9435;
UPDATE `conversation_template` SET `LastLineEndTime`=16943, `VerifiedBuild`=38134 WHERE `Id`=9001;
UPDATE `conversation_template` SET `LastLineEndTime`=10963, `VerifiedBuild`=38134 WHERE `Id`=9316;
UPDATE `conversation_template` SET `LastLineEndTime`=22550 WHERE `Id`=7668;
UPDATE `conversation_template` SET `LastLineEndTime`=8800, `VerifiedBuild`=38134 WHERE `Id`=8359;
UPDATE `conversation_template` SET `LastLineEndTime`=60078, `VerifiedBuild`=38134 WHERE `Id`=8227;
UPDATE `conversation_template` SET `LastLineEndTime`=7687, `VerifiedBuild`=38134 WHERE `Id`=6528;
UPDATE `conversation_template` SET `LastLineEndTime`=6150, `VerifiedBuild`=38134 WHERE `Id`=9213;
UPDATE `conversation_template` SET `LastLineEndTime`=6400, `VerifiedBuild`=38134 WHERE `Id`=9196;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (287742 /*Puerta titánica*/, 287736 /*Puerta titánica*/, 288475 /*Escoria de las Tierras de Fuego*/, 288487 /*Cajón*/, 288474 /*Máquina topo Hierro Negro*/, 339193 /*Batería nazeshi*/, 334950 /*Lanzaarpones*/, 287955 /*Cajón de suministros de la Séptima Legión*/, 288329 /*Ofrenda para G'huun*/, 287335 /*Caldero de sangre*/, 277899 /*Estandarte de guerra sethrak*/, 288646 /*Pera espinosa*/, 288479 /*Rampa de desembarco de Redención del Viento*/, 287405 /*Redención del Viento*/, 288196 /*Estandarte de la Alianza*/, 287524 /*Caseta*/, 287947 /*Carro destrozado*/, 288523 /*Redención del Viento*/, 284407 /*Reclusadero*/, 287461 /*Rollo de cuerda*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(287742, 1375, 32, 0, 0), -- Puerta titánica
(287736, 1375, 32, 0, 0), -- Puerta titánica
(288475, 0, 2121732, 0, 0), -- Escoria de las Tierras de Fuego
(288487, 1375, 8192, 0, 0), -- Cajón
(288474, 0, 32, 0, 15581), -- Máquina topo Hierro Negro
(339193, 0, 262144, 0, 0), -- Batería nazeshi
(334950, 0, 32, 0, 0), -- Lanzaarpones
(287955, 0, 2113540, 0, 0), -- Cajón de suministros de la Séptima Legión
(288329, 0, 262144, 0, 0), -- Ofrenda para G'huun
(287335, 0, 8192, 0, 0), -- Caldero de sangre
(277899, 0, 262144, 0, 0), -- Estandarte de guerra sethrak
(288646, 0, 2113540, 0, 0), -- Pera espinosa
(288479, 0, 8192, 0, 0), -- Rampa de desembarco de Redención del Viento
(287405, 0, 1048864, 0, 0), -- Redención del Viento
(288196, 0, 32, 0, 0), -- Estandarte de la Alianza
(287524, 0, 8192, 0, 0), -- Caseta
(287947, 0, 8192, 0, 0), -- Carro destrozado
(288523, 0, 1048864, 0, 0), -- Redención del Viento
(284407, 0, 16, 0, 0), -- Reclusadero
(287461, 0, 32, 0, 0); -- Rollo de cuerda

UPDATE `gameobject_template_addon` SET `AIAnimKitID`=2664 WHERE `entry`=297895; -- Esencia de azerita
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=10368 WHERE `entry`=293847; -- Consola titánica
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=2664 WHERE `entry`=293323; -- Esencia de azerita
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=2664 WHERE `entry`=293853; -- Fisuras de azerita
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=2664 WHERE `entry`=294031; -- Base de roca de azerita
UPDATE `gameobject_template_addon` SET `flags`=294912 WHERE `entry`=325722; -- Traslocador titánico
UPDATE `gameobject_template_addon` SET `flags`=262145 WHERE `entry`=290429; -- Cañón
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=288604; -- Cofre del tesoro
UPDATE `gameobject_template_addon` SET `flags`=2113536 WHERE `entry`=277715; -- Cofre nazmani maldito
UPDATE `gameobject_template_addon` SET `flags`=6 WHERE `entry`=273484; -- Filacteria reparada
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=279367; -- Cofre del tesoro
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=12035 WHERE `entry`=277876; -- Jaula sethrak
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=12035 WHERE `entry`=289364; -- Jaula sethrak
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2100 WHERE `entry`=296580; -- Diario forrado de Ofer
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2100 WHERE `entry`=296581; -- Roca mascota de Skye
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=232554; -- Cajón
UPDATE `gameobject_template_addon` SET `flags`=8192 WHERE `entry`=232560; -- Cajón
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=14182 WHERE `entry`=277857; -- Pináculo sethrak
UPDATE `gameobject_template_addon` SET `flags`=32, `WorldEffectID`=2100 WHERE `entry`=296579; -- Brújula rota de Brian
UPDATE `gameobject_template_addon` SET `WorldEffectID`=10349 WHERE `entry`=287332; -- Pila de basura misteriosa
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=316422; -- Cajón de viales de prueba
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=316430; -- Esquirlas de plata de tormenta
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=316424; -- Escamas de cambiarenas
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=316423; -- Fardo de musgo estelar desecado
UPDATE `gameobject_template_addon` SET `faction`=3014 WHERE `entry`=187376; -- NPC Fishing Bobber
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=279302; -- Arpón zeth'jir
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=288595; -- Leche de cabra tibia
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=291264; -- Cofre del tesoro pequeño
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=303170; -- Saco de granos curioso
UPDATE `gameobject_template_addon` SET `WorldEffectID`=2437 WHERE `entry`=303039; -- Saco de granos curioso

DELETE FROM `scene_template` WHERE (`SceneId`=1913 AND `ScriptPackageID`=2042) OR (`SceneId`=1947 AND `ScriptPackageID`=2094);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(1913, 16, 2042, 0),
(1947, 27, 2094, 0);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (52450 /*-Unknown-*/, 51968 /*-Unknown-*/, 52003 /*-Unknown-*/, 51359 /*-Unknown-*/, 51309 /*-Unknown-*/, 51331 /*-Unknown-*/, 51418 /*-Unknown-*/, 51544 /*-Unknown-*/, 51190 /*-Unknown-*/, 51192 /*-Unknown-*/, 51193 /*-Unknown-*/, 51191 /*-Unknown-*/, 52443 /*-Unknown-*/, 51967 /*-Unknown-*/, 52013 /*-Unknown-*/, 51177 /*-Unknown-*/, 51282 /*-Unknown-*/, 51280 /*-Unknown-*/, 51279 /*-Unknown-*/, 51281 /*-Unknown-*/, 51169 /*-Unknown-*/, 51168 /*-Unknown-*/, 51150 /*-Unknown-*/, 51167 /*-Unknown-*/, 51129 /*-Unknown-*/, 51088 /*-Unknown-*/, 53583 /*-Unknown-*/, 51961 /*-Unknown-*/, 51571 /*-Unknown-*/, 51969 /*-Unknown-*/, 52008 /*-Unknown-*/, 51402 /*-Unknown-*/, 51395 /*-Unknown-*/, 51394 /*-Unknown-*/, 51391 /*-Unknown-*/, 51389 /*-Unknown-*/, 51369 /*-Unknown-*/, 51366 /*-Unknown-*/, 51351 /*-Unknown-*/, 51350 /*-Unknown-*/, 51349 /*-Unknown-*/, 51229 /*-Unknown-*/, 51170 /*-Unknown-*/, 51283 /*-Unknown-*/, 51572 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(52450, 1, 273, 0, 0, 0, 0, 0, 0, 'El pueblo de Kul Tiras es diverso y capaz. Ahora que sus fuerzas son leales a la Alianza, la Horda no podrá detenernos.\n\nAhora comienza el verdadero trabajo.', 38134), -- -Unknown-
(51968, 1, 66, 0, 0, 0, 0, 0, 0, 'Entonces vamos a establecer nuestra base de operaciones fuera Xibala. Y ordenaré que envíen refuerzos para ayudar al brigadier Thom.\n\nGracias por el informe, $n. Bien hecho.', 38134), -- -Unknown-
(52003, 1, 4, 0, 0, 0, 300, 0, 0, 'Sabes, $n, he estado siguiendo tu aventura por un tiempo, ¡y creo que eres simplemente genial!\n\nEsperaba que me permitieras acompañarte, ¿quizá puedo ser de ayuda? No soy una gran guerrera, ¡pero soy la mejor en mecánica!', 38134), -- -Unknown-
(51359, 11, 0, 0, 0, 0, 0, 0, 0, '¡Ah! ¡Jaja! ¡Jajajajaja! ¡Guau! Debo admitir que estoy un poco celoso por haberte dejado sacarla a pasear antes que yo. ¡Esos goblin no se esperaban eso, eh!', 38134), -- -Unknown-
(51309, 1, 0, 0, 0, 0, 0, 0, 0, 'Tienen un par de quemaduras por aquí y por allá, pero nada fuera de lo normal. Me servirán.', 38134), -- -Unknown-
(51331, 5, 0, 0, 0, 0, 0, 0, 0, 'Si no les gustan las máquinas topo, ¡deberían haber elegido otra profesión!', 38134), -- -Unknown-
(51418, 1, 0, 0, 0, 0, 0, 0, 0, '¿Eres $n, $Uel:la; $r $c $Udel:de la; que tanto habla Kelsey? Hemos oído mucho de ti, $Uchico:chica;.', 38134), -- -Unknown-
(51544, 0, 0, 0, 0, 0, 0, 0, 0, 'Ahora podemos poner a salvo a nuestros heridos.', 38134), -- -Unknown-
(51190, 1, 0, 0, 0, 0, 0, 0, 0, 'Unos cretinos menos de los que preocuparse.', 38134), -- -Unknown-
(51192, 5, 0, 0, 0, 0, 0, 0, 0, '¡Es asombroso lo que podemos hacer cuando tenemos los suministros necesarios!', 38134), -- -Unknown-
(51193, 66, 1, 0, 0, 500, 500, 0, 0, 'Sé que no parece un martillo especial. Pero para mí tiene mucho valor.', 38134), -- -Unknown-
(51191, 378, 0, 0, 0, 500, 0, 0, 0, 'Tú podrías ser $Uun excelente médico:una excelente médica;. O al lo menos $Uun enfermero:una enfermera; decente.', 38134), -- -Unknown-
(52443, 1, 0, 0, 0, 0, 0, 0, 0, '¿$UListo:Lista; para partir? Entonces, nos vamos.', 38134), -- -Unknown-
(51967, 1, 0, 0, 0, 0, 0, 0, 0, 'Las tierras de Nazmir son crueles para todos los que entran, pero el Fuerte Victoria resistirá con firmeza frente al peligro.\n\nBien hecho, $n.', 38134), -- -Unknown-
(52013, 1, 4, 0, 0, 0, 300, 0, 0, 'Ahora que nos hemos asentado aquí... quiero apuntar un poco más alto.\n\nTe has encargado de Conrad. Te has encargado de los trols de sangre. ¿Me pregunto a dónde te llevará tu camino ahora?\n\nLo cierto es que no lo sé, pero cuenta conmigo. ¡Necesitarás un combatiente experimentado, fuerte e incondicional como yo si quieres ganar esta guerra!', 38134), -- -Unknown-
(51177, 1, 0, 0, 0, 0, 0, 0, 0, 'Un asunto terrible, $n. Me había embarcado en una misión de rescate o de recuperación de un cadáver. Ver a uno de los nuestros en esas condiciones fue... perturbador.\n\nLo hecho, hecho está. Le enviaré un informe a Halford. No te preocupes por el trabajo pesado esta vez.', 38134), -- -Unknown-
(51282, 1, 0, 0, 0, 0, 0, 0, 0, 'Me preguntaba cuándo vendrían a buscarme. Debo admitir que no soy una prisionera aquí, como seguramente crees. De hecho, todo lo contrario.', 38134), -- -Unknown-
(51280, 6, 0, 0, 0, 0, 0, 0, 0, 'No parece haber muchas cosas de valor en esta selva maldita. ¿Por qué la capitana Conrad creería que vale la pena comerciar con ellos?', 38134), -- -Unknown-
(51279, 5, 0, 0, 0, 0, 0, 0, 0, '¿Conoces esa sensación de cuando te parece que algo no anda bien y no logras descifrar qué es? ¡Es emocionante!', 38134), -- -Unknown-
(51281, 1, 0, 0, 0, 0, 0, 0, 0, 'Empiezo a pensar que esto se ha convertido en la búsqueda de un cadáver. No creo que encontremos a la famosa capitana Conrad con vida a esta altura.', 38134), -- -Unknown-
(51169, 1, 0, 0, 0, 0, 0, 0, 0, 'El nombre Fuerte Victoria no me parece apropiado. Debería llamarse algo así como Fuerte Porquería.', 38134), -- -Unknown-
(51168, 1, 0, 0, 0, 0, 0, 0, 0, '¡Los peores lugares del mundo son todos agujeros oscuros y sin artefactos!', 38134), -- -Unknown-
(51150, 1, 0, 0, 0, 0, 0, 0, 0, 'Me quedaré con estas placas y se las entregaré a sus familias. Mantengamos el pico cerrado sobre los detalles se sus muertes, ¿de acuerdo? No hay necesidad de provocarles aún más tristeza.', 38134), -- -Unknown-
(51167, 1, 0, 0, 0, 0, 0, 0, 0, 'Siempre creí que las brujas realizaban sus rituales sin ropas. Oye, ¿y dónde está su escoba?', 38134), -- -Unknown-
(51129, 1, 0, 0, 0, 0, 0, 0, 0, '¡No estaba preparado para semejante caída! ¡Creo que la única parte del cuerpo que no me duele es el sombrero!', 38134), -- -Unknown-
(51088, 1, 0, 0, 0, 0, 0, 0, 0, 'He luchado contra la muerte, $r. Es el enfrentamiento más aburrido que puedas imaginar.', 38134), -- -Unknown-
(53583, 0, 0, 0, 0, 0, 0, 0, 0, 'Excelente. Empezaremos a trabajar en esto de inmediato.', 38134), -- -Unknown-
(51961, 1, 0, 0, 0, 0, 0, 0, 0, 'Excelente decisión, $n.', 38134), -- -Unknown-
(51571, 0, 0, 0, 0, 0, 0, 0, 0, 'Has elegido navegar hacia Nazmir.', 38134), -- -Unknown-
(51969, 1, 0, 0, 0, 0, 0, 0, 0, 'Las aguas que rodean Vol\'dun son despiadadas, ¡pero Jes-Tereth es una de las mejores timoneles del mar!\n\nContinuemos nuestra racha de victorias.', 38134), -- -Unknown-
(52008, 1, 4, 0, 0, 0, 300, 0, 0, 'Tenía mis reservas cuando el alto comandante Aterravermis me pidió que lo acompañara a este vasto desierto. No creí que habría muchas cosas interesantes.\n\nMis suposiciones, afortunadamente, fueron desacertadas. Los sethrak que habitan esta región controlan una magia poderosa y la emplean con técnicas poco convencionales.\n\nNo puedo esperar por estudiar sus equipamientos para revelar los secretos de su poder, pero mi prioridad es ayudarte a ti y al alto comandante en lo que necesiten.\n\nPor favor, no dudes en acudir a mí.', 38134), -- -Unknown-
(51402, 1, 1, 0, 0, 0, 0, 0, 0, '<Aterravermis escucha tu informe.>\n\nLa noticia de ese c\'thraxxi es preocupante, pero hiciste bien en ganarte la confianza de la población local. No será la última vez que necesitemos su ayuda.\n\nBien hecho, $n.', 38134), -- -Unknown-
(51395, 1, 2, 0, 0, 0, 0, 0, 0, 'Los infieles jamás se detendrán, pero tus esfuerzos nos han conseguido algo de tiempo.', 38134), -- -Unknown-
(51394, 1, 2, 0, 0, 0, 0, 0, 0, 'Los infieles jamás se detendrán, pero tus esfuerzos nos han conseguido algo de tiempo.', 38134), -- -Unknown-
(51391, 1, 2, 0, 0, 0, 0, 0, 0, '¡Ya me han contado cómo lograste que los infieles huyeran despavoridos! \n\nEn nombre de toda mi gente, muchas gracias.', 38134), -- -Unknown-
(51389, 1, 2, 0, 0, 0, 0, 0, 0, '¡No puedo creer que tú y el sargento se hayan esforzado tanto para rescatarme! Me... ¡Me he quedado sin palabras! ¡Gracias!', 38134), -- -Unknown-
(51369, 1, 273, 0, 0, 0, 0, 0, 0, '¡No! ¡Los infieles atacan el templo!', 38134), -- -Unknown-
(51366, 1, 273, 0, 0, 0, 0, 0, 0, 'Siento que la vida regresa a mis extremidades. ¡Gracias, $Uforastero:forastera;!\n\nMe temo que no hay tiempo para presentaciones. Los infieles han capturado a tu amiga.\n\nNo te preocupes, mi pueblo te ayudará con gusto para devolverte el favor.', 38134), -- -Unknown-
(51351, 1, 273, 0, 0, 0, 0, 0, 0, '¡Si, eso es! Espero que no te hayan picado a ti también.', 38134), -- -Unknown-
(51350, 1, 273, 0, 0, 0, 0, 0, 0, '¡Estas raíces servirán!', 38134), -- -Unknown-
(51349, 661, 603, 0, 0, 0, 0, 0, 0, '¿Aterravermis te envió a buscarme? Bueno, tendrá que esperar. \n\n¡Esta cosa sabe a dónde se llevaron al soldado James!', 38134), -- -Unknown-
(51229, 1, 0, 0, 0, 0, 0, 0, 0, '¡La tripulación está montando nuestro campamento en tiempo récord! Hiciste un buen trabajo al asegurar esta avanzada en la costa.\n\nAhora, en cuanto al sargento Ermey...', 38134), -- -Unknown-
(51170, 5, 1, 6, 0, 0, 0, 0, 0, '¡Gracias a la Luz que viniste con nosotros! ¡Hemos perdido al soldado Leonard, y los asquerosos hombres serpiente han capturado al soldado James!\n\nLo importante es que creo que ahuyentaste a los demás cuando empezaste a acribillarlos. \n\nAlgo es algo, ¿no?', 38134), -- -Unknown-
(51283, 1, 273, 0, 0, 0, 0, 0, 0, 'Espero que el viaje no te haya mareado, $n. Nuestra misión apenas está comenzando.', 38134), -- -Unknown-
(51572, 0, 0, 0, 0, 0, 0, 0, 0, 'Has elegido navegar hacia Vol\'dun.', 38134); -- -Unknown-

DELETE FROM `quest_poi` WHERE (`QuestID`=51193 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51193 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51193 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51281 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51281 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51402 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51402 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51391 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51391 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51391 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51369 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51369 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51369 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51369 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50698 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50698 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50698 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50621 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50621 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50621 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51215 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51215 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51204 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51204 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=52876 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=52876 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=52876 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49818 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49818 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49730 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=49730 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49730 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49730 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=49730 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49730 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(51193, 0, 2, 32, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1487620, 0, 38134), -- -Unknown-
(51193, 0, 1, 0, 335140, 159779, 1642, 862, 0, 0, 0, 0, 0, 1494759, 0, 38134), -- -Unknown-
(51193, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 0, 1487620, 0, 38134), -- -Unknown-
(51281, 0, 1, 32, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1490463, 0, 38134), -- -Unknown-
(51281, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 0, 1492527, 0, 38134), -- -Unknown-
(51402, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1504677, 0, 38134), -- -Unknown-
(51402, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1498626, 0, 38134), -- -Unknown-
(51391, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1503754, 0, 38134), -- -Unknown-
(51391, 0, 1, 0, 335673, 128664, 1642, 864, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51391, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1406075, 0, 38134), -- -Unknown-
(51369, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1501652, 0, 38134), -- -Unknown-
(51369, 0, 2, 1, 335637, 137502, 1642, 864, 0, 0, 0, 0, 0, 1503418, 0, 38134), -- -Unknown-
(51369, 0, 1, 0, 335579, 137501, 1642, 864, 0, 0, 0, 0, 0, 1503418, 0, 38134), -- -Unknown-
(51369, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 1503754, 0, 38134), -- -Unknown-
(50698, 0, 2, 32, 0, 0, 1643, 942, 0, 2, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(50698, 0, 1, 0, 333562, 281879, 1643, 942, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(50698, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1427315, 0, 38134), -- -Unknown-
(50621, 0, 2, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1428145, 0, 38134), -- -Unknown-
(50621, 0, 1, 0, 333349, 279661, 1643, 942, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(50621, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1428145, 0, 38134), -- -Unknown-
(51215, 0, 1, 0, 335159, 159781, 1643, 942, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51215, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1492453, 0, 38134), -- -Unknown-
(51204, 0, 1, 0, 335110, 136417, 1643, 942, 0, 0, 0, 0, 0, 1489941, 0, 38134), -- -Unknown-
(51204, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1489914, 0, 38134), -- -Unknown-
(52876, 0, 2, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1586566, 0, 38134), -- -Unknown-
(52876, 0, 1, 0, 340170, 141984, 1643, 942, 0, 0, 0, 0, 0, 1586329, 0, 38134), -- -Unknown-
(52876, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1534467, 0, 38134), -- -Unknown-
(49818, 0, 1, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1427669, 0, 38134), -- -Unknown-
(49818, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1428145, 0, 38134), -- -Unknown-
(49730, 1, 5, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1494756, 0, 38134), -- -Unknown-
(49730, 0, 4, 32, 0, 0, 1643, 942, 0, 0, 0, 0, 0, 1478859, 0, 38134), -- -Unknown-
(49730, 0, 3, 0, 295187, 158300, 1643, 942, 0, 0, 0, 0, 0, 1478844, 0, 38134), -- -Unknown-
(49730, 1, 2, -1, 0, 0, 1643, 942, 0, 0, 0, 55794, 0, 1472636, 0, 38134), -- -Unknown-
(49730, 0, 1, -1, 0, 0, 1643, 942, 0, 0, 0, 55007, 0, 1477346, 0, 38134), -- -Unknown-
(49730, 0, 0, -1, 0, 0, 1643, 942, 0, 0, 0, 54991, 0, 1425229, 0, 38134); -- -Unknown-

UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=1 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51201 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51201 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51282 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51282 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=0 AND `Idx1`=5); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=1 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51714 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49908 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49908 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `BlobIndex`=1 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50635 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50635 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51504 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51504 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `BlobIndex`=0 AND `Idx1`=4); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `BlobIndex`=0 AND `Idx1`=3); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `BlobIndex`=0 AND `Idx1`=2); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51218 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51218 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52068 AND `BlobIndex`=0 AND `Idx1`=1); -- -Unknown-
UPDATE `quest_poi` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52068 AND `BlobIndex`=0 AND `Idx1`=0); -- -Unknown-
DELETE FROM `quest_poi_points` WHERE (`QuestID`=51193 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51193 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51193 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51281 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51281 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51402 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51402 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51391 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51391 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51391 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51369 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51369 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51369 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51369 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50698 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50698 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50698 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50621 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50621 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50621 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51215 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51215 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51215 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51215 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51215 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51215 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51204 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51204 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=52876 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=52876 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=52876 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49818 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49818 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49730 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(51193, 2, 0, -1707, -865, 25, 38134), -- -Unknown-
(51193, 1, 0, -1502, -1224, 1, 38134), -- -Unknown-
(51193, 0, 0, -1707, -865, 25, 38134), -- -Unknown-
(51281, 1, 0, 2070, 188, -48, 38134), -- -Unknown-
(51281, 0, 0, 1743, 821, -48, 38134), -- -Unknown-
(51402, 1, 0, 1952, 4846, 102, 38134), -- -Unknown-
(51402, 0, 0, 2710, 4121, 20, 38134), -- -Unknown-
(51391, 2, 0, 1888, 4835, 71, 38134), -- -Unknown-
(51391, 1, 10, 1842, 4606, 0, 38134), -- -Unknown-
(51391, 1, 9, 1842, 4618, 0, 38134), -- -Unknown-
(51391, 1, 8, 1842, 4625, 0, 38134), -- -Unknown-
(51391, 1, 7, 1848, 4688, 40, 38134), -- -Unknown-
(51391, 1, 6, 1928, 4721, 53, 38134), -- -Unknown-
(51391, 1, 5, 2006, 4727, 56, 38134), -- -Unknown-
(51391, 1, 4, 2029, 4694, 53, 38134), -- -Unknown-
(51391, 1, 3, 2012, 4650, 54, 38134), -- -Unknown-
(51391, 1, 2, 2007, 4645, 53, 38134), -- -Unknown-
(51391, 1, 1, 1877, 4605, 55, 38134), -- -Unknown-
(51391, 1, 0, 1848, 4601, 48, 38134), -- -Unknown-
(51391, 0, 0, 1950, 4808, 70, 38134), -- -Unknown-
(51369, 3, 0, 2385, 4035, 30, 38134), -- -Unknown-
(51369, 2, 0, 2382, 4027, 27, 38134), -- -Unknown-
(51369, 1, 0, 2382, 4027, 28, 38134), -- -Unknown-
(51369, 0, 0, 1888, 4835, 71, 38134), -- -Unknown-
(50698, 2, 0, 3362, 1355, 42, 38134), -- -Unknown-
(50698, 1, 6, 3221, 1602, 4, 38134), -- -Unknown-
(50698, 1, 5, 3203, 1659, 1, 38134), -- -Unknown-
(50698, 1, 4, 3312, 1732, 0, 38134), -- -Unknown-
(50698, 1, 3, 3352, 1748, 0, 38134), -- -Unknown-
(50698, 1, 2, 3523, 1645, 4, 38134), -- -Unknown-
(50698, 1, 1, 3483, 1521, 28, 38134), -- -Unknown-
(50698, 1, 0, 3289, 1503, 31, 38134), -- -Unknown-
(50698, 0, 0, 3378, 1380, 42, 38134), -- -Unknown-
(50621, 2, 0, 2923, 1630, 9, 38134), -- -Unknown-
(50621, 1, 5, 2800, 1748, 10, 38134), -- -Unknown-
(50621, 1, 4, 2714, 1895, 6, 38134), -- -Unknown-
(50621, 1, 3, 2724, 1930, 1, 38134), -- -Unknown-
(50621, 1, 2, 2856, 1842, 2, 38134), -- -Unknown-
(50621, 1, 1, 2962, 1733, 0, 38134), -- -Unknown-
(50621, 1, 0, 2971, 1689, 1, 38134), -- -Unknown-
(50621, 0, 0, 2923, 1630, 9, 38134), -- -Unknown-
(51215, 1, 4, 2325, 1208, 0, 38134), -- -Unknown-
(51215, 1, 3, 2175, 1461, 0, 38134), -- -Unknown-
(51215, 1, 2, 2340, 1947, 0, 38134), -- -Unknown-
(51215, 1, 1, 2511, 1867, 0, 38134), -- -Unknown-
(51215, 1, 0, 2591, 1063, 0, 38134), -- -Unknown-
(51215, 0, 0, 2635, 1621, 59, 38134), -- -Unknown-
(51204, 1, 0, 2146, 1753, 171, 38134), -- -Unknown-
(51204, 0, 0, 2531, 1534, 77, 38134), -- -Unknown-
(52876, 2, 0, 3341, 690, 60, 38134), -- -Unknown-
(52876, 1, 0, 3878, 653, 160, 38134), -- -Unknown-
(52876, 0, 0, 3347, 694, 58, 38134), -- -Unknown-
(49818, 1, 0, 2516, -35, 55, 38134), -- -Unknown-
(49818, 0, 0, 2923, 1631, 9, 38134), -- -Unknown-
(49730, 5, 0, 2584, 1602, 59, 38134), -- -Unknown-
(49730, 4, 0, 2821, 729, 59, 38134), -- -Unknown-
(49730, 3, 0, 2458, 1045, 120, 38134), -- -Unknown-
(49730, 2, 0, 2722, 802, 50, 38134), -- -Unknown-
(49730, 1, 0, 2497, 15, 50, 38134), -- -Unknown-
(49730, 0, 0, 2647, 72, 41, 38134); -- -Unknown-

UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52428 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51211 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53028 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51968 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51359 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51309 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51331 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51418 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51192 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51191 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51544 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51190 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51201 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51201 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51308 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52443 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51967 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51177 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51282 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51282 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51280 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51279 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51169 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51168 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51150 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51167 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51129 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=53583 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51088 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51961 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51969 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51395 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51389 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=5 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51394 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51366 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51351 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51350 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51349 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51229 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51170 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51714 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51283 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51569 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49908 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49908 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=49831 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50706 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50705 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50679 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50672 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50773 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50653 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50644 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50649 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50645 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50635 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50635 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50616 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=50614 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=11); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=10); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51209 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51208 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51504 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51504 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51207 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `Idx1`=4 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51335 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51200 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51203 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51251 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51205 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=9); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=8); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=7); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=6); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=5); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=4); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=3); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=2); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=1); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51492 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `Idx1`=3 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `Idx1`=2 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51214 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51218 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51218 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52068 AND `Idx1`=1 AND `Idx2`=0); -- -Unknown-
UPDATE `quest_poi_points` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52068 AND `Idx1`=0 AND `Idx2`=0); -- -Unknown-

DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (137401,136675,136641));
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(137401, 0, 0, 0, 'Siento que todavía no puedo compartir mi arte con la Alianza...', 38134), -- 137401
(136675, 0, 0, 0, 'No hagas nada que yo no haría, $n.', 38134), -- 136675
(136641, 0, 0, 0, '¡Debe haber algo que valga la pena excavar en este pantano!', 38134); -- 136641

DELETE FROM `quest_details` WHERE `ID` IN (53194 /*-Unknown-*/, 52026 /*-Unknown-*/, 54938 /*-Unknown-*/, 49223 /*-Unknown-*/, 51968 /*-Unknown-*/, 51359 /*-Unknown-*/, 51309 /*-Unknown-*/, 51331 /*-Unknown-*/, 51418 /*-Unknown-*/, 51192 /*-Unknown-*/, 51193 /*-Unknown-*/, 51191 /*-Unknown-*/, 51544 /*-Unknown-*/, 51190 /*-Unknown-*/, 51201 /*-Unknown-*/, 51308 /*-Unknown-*/, 51570 /*-Unknown-*/, 52443 /*-Unknown-*/, 51967 /*-Unknown-*/, 51177 /*-Unknown-*/, 51282 /*-Unknown-*/, 51280 /*-Unknown-*/, 51279 /*-Unknown-*/, 51281 /*-Unknown-*/, 51169 /*-Unknown-*/, 51168 /*-Unknown-*/, 51150 /*-Unknown-*/, 51167 /*-Unknown-*/, 51129 /*-Unknown-*/, 53583 /*-Unknown-*/, 51088 /*-Unknown-*/, 51571 /*-Unknown-*/, 51961 /*-Unknown-*/, 51969 /*-Unknown-*/, 51402 /*-Unknown-*/, 51395 /*-Unknown-*/, 51389 /*-Unknown-*/, 51394 /*-Unknown-*/, 51391 /*-Unknown-*/, 51369 /*-Unknown-*/, 51366 /*-Unknown-*/, 51351 /*-Unknown-*/, 51350 /*-Unknown-*/, 51349 /*-Unknown-*/, 51229 /*-Unknown-*/, 51170 /*-Unknown-*/, 51283 /*-Unknown-*/, 51572 /*-Unknown-*/, 53847 /*-Unknown-*/, 53045 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(53194, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(52026, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(54938, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(49223, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51968, 1, 1, 0, 0, 0, 300, 0, 0, 38134), -- -Unknown-
(51359, 2, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51309, 1, 273, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51331, 1, 6, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51418, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51192, 3, 11, 0, 0, 500, 500, 0, 0, 38134), -- -Unknown-
(51193, 274, 1, 14, 0, 500, 500, 500, 0, 38134), -- -Unknown-
(51191, 661, 1, 0, 0, 50, 500, 0, 0, 38134), -- -Unknown-
(51544, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51190, 1, 6, 25, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51201, 25, 1, 6, 0, 500, 0, 0, 0, 38134), -- -Unknown-
(51308, 1, 66, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51570, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(52443, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51967, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51177, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51282, 1, 6, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51280, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51279, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51281, 1, 6, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51169, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51168, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51150, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51167, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51129, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(53583, 1, 0, 0, 0, 10, 0, 0, 0, 38134), -- -Unknown-
(51088, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51571, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51961, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51969, 1, 1, 0, 0, 0, 5000, 0, 0, 38134), -- -Unknown-
(51402, 1, 603, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51395, 1, 603, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51389, 1, 603, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51394, 1, 603, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51391, 1, 603, 1, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51369, 1, 30, 30, 30, 0, 0, 0, 0, 38134), -- -Unknown-
(51366, 1, 30, 30, 30, 0, 0, 0, 0, 38134), -- -Unknown-
(51351, 1, 30, 30, 30, 0, 0, 0, 0, 38134), -- -Unknown-
(51350, 1, 30, 30, 30, 0, 0, 0, 0, 38134), -- -Unknown-
(51349, 1, 273, 603, 25, 0, 0, 0, 0, 38134), -- -Unknown-
(51229, 661, 1, 273, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51170, 1, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51283, 1, 603, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(51572, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(53847, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- -Unknown-
(53045, 1, 1, 0, 0, 0, 0, 0, 0, 38134); -- -Unknown-

UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=52428; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51211; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=53028; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=53028; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51715; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51714; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51714; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51569; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51569; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50417; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50417; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49908; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49831; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=49831; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50706; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50705; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50698; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50679; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50672; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50773; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50773; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50773; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50653; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50644; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50649; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50649; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50645; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50645; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50635; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50621; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50616; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=50614; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51209; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51209; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51208; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51208; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51504; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51504; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51207; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51335; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51215; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51200; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51200; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51203; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51203; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51204; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51204; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51251; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51251; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51205; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51205; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51492; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51492; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51214; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51214; -- -Unknown-
UPDATE `quest_details` SET `VerifiedBuild`=38134 WHERE `ID`=51218; -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (51309 /*-Unknown-*/, 51359 /*-Unknown-*/, 53436 /*-Unknown-*/, 51351 /*-Unknown-*/, 51350 /*-Unknown-*/, 51193 /*-Unknown-*/, 51192 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51309, 0, 0, 0, 0, 'No me preocupaba que estuvieran rotas. Un poco de fuego jamás les haría daño a estas rocas.', 0), -- -Unknown-
(51359, 0, 0, 0, 0, 'Mis chamanes son cada vez mejores, ¿no? Con las primeras invocaciones ya generamos una pelea bien candente...', 38134), -- -Unknown-
(53436, 0, 0, 0, 0, 'Vuelve a verme cuando hayas terminado de ayudar a la Alianza, $n.', 38134), -- -Unknown-
(51351, 0, 0, 0, 0, '¿Conseguiste las púas?', 0), -- -Unknown-
(51350, 0, 0, 0, 0, '¿Conseguiste el cactus para el bálsamo?', 0), -- -Unknown-
(51193, 0, 0, 0, 0, 'No me juzgues. Este martillo es el mejor.', 0), -- -Unknown-
(51192, 0, 0, 0, 0, '¿Encontraste algo útil?', 0); -- -Unknown-

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (281356,269981,280096,268064,286960,281354,269154)) OR (`EffectIndex`=1 AND `ID` IN (267794,267320)) OR (`EffectIndex`=3 AND `ID`=269626);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(281356, 0, 1643, 1009.72998046875, -526.260009765625, 13.10000038146972656, 38134), -- Spell: 281356 (Teleport: Boralus) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(269981, 0, 1642, -2619.56005859375, 2269.6298828125, 12.85999965667724609, 38134), -- Spell: 269981 (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(280096, 0, 1642, -1736.7099609375, -1079.75, 0.349999994039535522, 38134), -- Spell: 280096 (Teleport to Talanji's Rebuke) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(267794, 1, 1642, 2337.75, 651.44000244140625, 0, 38134), -- Spell: 267794 (Kul Tiran Rowboat) Efffect: 28 (SPELL_EFFECT_SUMMON)
(267320, 1, 1642, 2336.199951171875, 638, 0.200000002980232238, 38134), -- Spell: 267320 (Kul Tiran Barge) Efffect: 28 (SPELL_EFFECT_SUMMON)
(268064, 0, 1642, 2337.75, 651.44000244140625, 0, 38134), -- Spell: 268064 (Teleport to Nazmir) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(286960, 0, 1, 6726.08984375, -3.44000005722045898, 42.6100006103515625, 38134), -- Spell: 286960 (Teleport to Darkshore) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(281354, 0, 1643, 1009.72998046875, -526.260009765625, 13.10000038146972656, 38134), -- Spell: 281354 (Teleport: Boralus) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(269626, 3, 1642, 2709.669921875, 4117.68994140625, 19.93000030517578125, 38134), -- Spell: 269626 (Claimed) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(269154, 0, 1642, 2752.530029296875, 4450.919921875, 13.22999954223632812, 38134); -- Spell: 269154 (Travel to Vol'dun) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=269183 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=259721 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=259312 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=259305 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=259316 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=38134 WHERE (`ID`=259314 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (136550 /*136550 (Centinela cargado) - Charged*/, 137766 /*137766 (Zandalari capturado)*/, 136552 /*136552 (Maleante Kao-Tien)*/, 140510 /*140510 (Jefa Revientabocas)*/, 140571 /*140571 (Transportista Pantoque) - Carry Crate*/, 140525 /*140525 (Taladrador Pantoque) - Drill, Baby, Drill (Down)*/, 140543 /*140543 (Fracturadora Pantoque)*/, 140580 /*140580 (Transportista Pantoque)*/, 140536 /*140536 (Explotador Pantoque)*/, 140579 /*140579 (Transportista Pantoque) - Cosmetic - Sleep Zzz*/, 137378 /*137378 (Magma inestable) - Bind Fire Elemental*/, 137391 /*137391 (Rompetierras Hierro Negro)*/, 136099 /*136099 (Montículo de tierra)*/, 131777 /*131777 (Acadia Tallapiedras)*/, 136097 /*136097 (Montículo de tierra)*/, 128042 /*128042 (Jannis Correolas)*/, 137400 /*137400 (Thaelin Yunqueoscuro)*/, 137401 /*137401 (Señor feudal del yunque Thurgaden) - Lightning Shield*/, 131800 /*131800 (Cahna Mantonegro)*/, 137148 /*137148 (Oficial del punto de extracción)*/, 137149 /*137149 (Incinerador Pantoque) - Cosmetic - Goblin with a Flamethrower*/, 137185 /*137185 (Peón orco) - Carry Crate*/, 137154 /*137154 (General Purpose Stalker) - Small Fire*/, 157907 /*157907 (Kill Credit: Explosives detonated)*/, 157735 /*157735 (Rompemareas nazeshi)*/, 157737 /*157737 (Barrera de agua) - Tide Barrier*/, 137678 /*137678 (Kul Tiran Rowboat)*/, 137680 /*137680 (Hablaolas de Estela de la Tormenta) - Ride Vehicle Hardcoded*/, 136292 /*136292 (Marinero de Boralus) - Ride Vehicle Hardcoded*/, 136290 /*136290 (Marinero de Boralus) - Ride Vehicle Hardcoded*/, 138109 /*138109 (Guardias de la Séptima Legión)*/, 136906 /*136906 (Mayor Alan Hawkins)*/, 136195 /*136195 (Médica Feorea)*/, 136192 /*136192 (Degdod) - -Unknown-*/, 137965 /*137965 (Marinero naufragado recuperado) - Set Health (Random 65%-85%)*/, 137624 /*137624 (Oliva)*/, 138854 /*138854 (Agua Dulce)*/, 138850 /*138850 (Birgita)*/, 136075 /*136075 (Marinero naufragado herido) - Set Health (Random 15%-55%)*/, 135620 /*135620 (Kelsey Chispacero)*/, 137440 /*137440 (Señor feudal del yunque Thurgaden) - Lightning Shield*/, 137441 /*137441 (Thaelin Yunqueoscuro)*/, 136988 /*136988 (Cautivo zandalari) - Blood Sacrifice*/, 136568 /*136568 (Capitana Conrad)*/, 136675 /*136675 (Brann Barbabronce)*/, 150102 /*150102 (Spell Bunny)*/, 132025 /*132025 (Mi'ja)*/, 132030 /*132030 (Crustájeo adolescente)*/, 138743 /*138743 (Rabioso trol de sangre) - Permanent Feign Death (Flies)*/, 138775 /*138775 (Corruptora trol de sangre) - Permanent Feign Death (Flies)*/, 139797 /*139797 (Rabioso trol de sangre) - Filthy Blades*/, 136564 /*136564 (Hir'eek) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 136565 /*136565 (Bruja sangrienta Pakkala)*/, 136639 /*136639 (Adorador de Zalamar)*/, 136641 /*136641 (Brann Barbabronce)*/, 136573 /*136573 (Murciélago mensajero de Zalamar)*/, 136575 /*136575 (Lacayo de Fuerte Victoria) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 136606 /*136606 (Ju'mak)*/, 137240 /*137240 (Brann Barbabronce)*/, 144088 /*144088 (Sirviente del Vacío)*/, 144051 /*144051 (Portal del Vacío)*/, 145245 /*145245 (Tecnoladrón de Colmillo Escamado) - Dual Wield, Permanent Feign Death*/, 137559 /*137559 (Soldado James)*/, 144353 /*144353 (Coleccionista Tojo)*/, 152093 /*152093 (Defensor del templo)*/, 137552 /*137552 (Soldado James)*/, 137537 /*137537 (Vorrik)*/, 137543 /*137543 (Sargento Ermey)*/, 150318 /*150318 (Veriss)*/, 141955 /*141955 (Squeezer)*/, 141950 /*141950 (Clubber)*/, 141951 /*141951 (Squirt)*/, 145148 /*145148 (Oficial de expedición en jefe McCormick)*/, 145345 /*145345 (Trituradora de McCormick) - Set Health % (Uses Override Points) (No Health Regen), Smoking*/, 145136 /*145136 (Persuasor de Ventura y Cía.) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 145347 /*145347 (Obrera de Ventura y Cía.)*/, 137501 /*137501 (Pterrordáctilo domado)*/, 137434 /*137434 (Vorrik)*/, 150895 /*150895 (Santuario de las Arenas)*/, 137388 /*137388 (Vorrik) - Poisoned, Injured*/, 137337 /*137337 (Sargento Ermey)*/, 136562 /*136562 (Intendente Alfin)*/, 141796 /*141796 (Sargento Sazonadora) - Invisibility and Stealth Detection*/, 137213 /*137213 (Halford Aterravermis)*/, 144121 /*144121 (Orville Manfred)*/, 135383 /*135383 (Barnard "el Aplastador" Baysworth)*/, 141784 /*141784 (Fusilero de la Séptima Legión) - Rifle Stand*/, 144136 /*144136 (Pterrordáctilo domado)*/, 139568 /*139568 (Magíster Umbric) - Inv*/, 143473 /*143473 (Parroquiano de la taberna)*/, 141813 /*141813 (Murnir Trenzas de Pedernal)*/, 137327 /*137327 ("Salvaje" Bill Karmen)*/, 137322 /*137322 (Valentina Karmen)*/, 143478 /*143478 (Thoralius el Sabio) - Read Scroll*/, 136566 /*136566 (Mordedor ladrón)*/, 137319 /*137319 (Cuidadora Mila)*/, 143472 /*143472 (Parroquiano desmayado) - Cosmetic - Sleep Zzz - Small Zs*/, 141780 /*141780 (Guardia de la Séptima Legión)*/, 143482 /*143482 (Obrero de la Alianza) - 8.0 Carry Sack New Anim*/, 137187 /*137187 (Reptaguerra krolusko) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 137173 /*137173 (Soldado Leonard) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 137008 /*137008 (Sargento Ermey)*/, 136936 /*136936 (Bestia de carga kroluska)*/, 136727 /*136727 (Jinete de batalla sethrak) - Ride Vehicle Hardcoded, Dual Wield*/, 136731 /*136731 (Reptaguerra krolusko)*/, 136915 /*136915 (Ensalmador sethrak)*/, 136916 /*136916 (Sethrak Raider) - Dual Wield*/, 136842 /*136842 (Vulpera asesinado) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 143894 /*143894 (Falla del Vacío)*/, 143891 /*143891 (Magíster Umbric) - Transform Invisible*/, 137867 /*137867 (Halford Aterravermis) - Spyglass*/, 155070 /*155070 (Lecho de flores exuberantes) - [DNT] Flower Patch + Sunshaft*/, 141354 /*141354 (Conscripto Canto Tormenta)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(136550, 0, 0, 0, 1, 0, 0, 0, 0, '277186'), -- 136550 (Centinela cargado) - Charged
(137766, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137766 (Zandalari capturado)
(136552, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 136552 (Maleante Kao-Tien)
(140510, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 140510 (Jefa Revientabocas)
(140571, 0, 0, 0, 1, 0, 0, 0, 0, '275211'), -- 140571 (Transportista Pantoque) - Carry Crate
(140525, 0, 0, 0, 1, 0, 0, 0, 0, '275176'), -- 140525 (Taladrador Pantoque) - Drill, Baby, Drill (Down)
(140543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 140543 (Fracturadora Pantoque)
(140580, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 140580 (Transportista Pantoque)
(140536, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 140536 (Explotador Pantoque)
(140579, 0, 0, 0, 1, 0, 0, 0, 0, '145953'), -- 140579 (Transportista Pantoque) - Cosmetic - Sleep Zzz
(137378, 0, 0, 0, 1, 0, 0, 0, 0, '269918'), -- 137378 (Magma inestable) - Bind Fire Elemental
(137391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137391 (Rompetierras Hierro Negro)
(136099, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136099 (Montículo de tierra)
(131777, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131777 (Acadia Tallapiedras)
(136097, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136097 (Montículo de tierra)
(128042, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 128042 (Jannis Correolas)
(137400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137400 (Thaelin Yunqueoscuro)
(137401, 0, 0, 0, 1, 0, 0, 0, 0, '12550'), -- 137401 (Señor feudal del yunque Thurgaden) - Lightning Shield
(131800, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 131800 (Cahna Mantonegro)
(137148, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137148 (Oficial del punto de extracción)
(137149, 0, 0, 0, 1, 0, 0, 0, 0, '266140'), -- 137149 (Incinerador Pantoque) - Cosmetic - Goblin with a Flamethrower
(137185, 0, 0, 0, 1, 0, 0, 0, 0, '264938'), -- 137185 (Peón orco) - Carry Crate
(137154, 0, 0, 0, 1, 0, 0, 0, 0, '151561'), -- 137154 (General Purpose Stalker) - Small Fire
(157907, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157907 (Kill Credit: Explosives detonated)
(157735, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157735 (Rompemareas nazeshi)
(157737, 0, 0, 0, 1, 0, 0, 0, 0, '307731'), -- 157737 (Barrera de agua) - Tide Barrier
(137678, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 137678 (Kul Tiran Rowboat)
(137680, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 137680 (Hablaolas de Estela de la Tormenta) - Ride Vehicle Hardcoded
(136292, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 136292 (Marinero de Boralus) - Ride Vehicle Hardcoded
(136290, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 136290 (Marinero de Boralus) - Ride Vehicle Hardcoded
(138109, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 138109 (Guardias de la Séptima Legión)
(136906, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136906 (Mayor Alan Hawkins)
(136195, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136195 (Médica Feorea)
(136192, 0, 0, 0, 1, 0, 0, 0, 0, '281798'), -- 136192 (Degdod) - -Unknown-
(137965, 0, 0, 3, 257, 0, 0, 0, 0, '244972'), -- 137965 (Marinero naufragado recuperado) - Set Health (Random 65%-85%)
(137624, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 137624 (Oliva)
(138854, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 138854 (Agua Dulce)
(138850, 0, 0, 1, 257, 0, 0, 0, 0, ''), -- 138850 (Birgita)
(136075, 0, 0, 3, 1, 0, 0, 0, 0, '244971'), -- 136075 (Marinero naufragado herido) - Set Health (Random 15%-55%)
(135620, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 135620 (Kelsey Chispacero)
(137440, 0, 0, 0, 1, 0, 0, 0, 0, '12550'), -- 137440 (Señor feudal del yunque Thurgaden) - Lightning Shield
(137441, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137441 (Thaelin Yunqueoscuro)
(136988, 0, 0, 0, 1, 0, 0, 0, 0, '268973'), -- 136988 (Cautivo zandalari) - Blood Sacrifice
(136568, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136568 (Capitana Conrad)
(136675, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136675 (Brann Barbabronce)
(150102, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 150102 (Spell Bunny)
(132025, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132025 (Mi'ja)
(132030, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132030 (Crustájeo adolescente)
(138743, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 138743 (Rabioso trol de sangre) - Permanent Feign Death (Flies)
(138775, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 138775 (Corruptora trol de sangre) - Permanent Feign Death (Flies)
(139797, 0, 0, 0, 1, 0, 0, 0, 0, '262316'), -- 139797 (Rabioso trol de sangre) - Filthy Blades
(136564, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 136564 (Hir'eek) - Permanent Feign Death (Stun, Untrackable, Immune)
(136565, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136565 (Bruja sangrienta Pakkala)
(136639, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136639 (Adorador de Zalamar)
(136641, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 136641 (Brann Barbabronce)
(136573, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 136573 (Murciélago mensajero de Zalamar)
(136575, 0, 0, 262144, 1, 0, 15494, 0, 0, '145363'), -- 136575 (Lacayo de Fuerte Victoria) - Permanent Feign Death (Stun, Untrackable, Immune)
(136606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136606 (Ju'mak)
(137240, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137240 (Brann Barbabronce)
(144088, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144088 (Sirviente del Vacío)
(144051, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144051 (Portal del Vacío)
(145245, 0, 0, 0, 1, 0, 0, 0, 0, '42459 29266'), -- 145245 (Tecnoladrón de Colmillo Escamado) - Dual Wield, Permanent Feign Death
(137559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137559 (Soldado James)
(144353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144353 (Coleccionista Tojo)
(152093, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 152093 (Defensor del templo)
(137552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137552 (Soldado James)
(137537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137537 (Vorrik)
(137543, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 137543 (Sargento Ermey)
(150318, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 150318 (Veriss)
(141955, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141955 (Squeezer)
(141950, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141950 (Clubber)
(141951, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 141951 (Squirt)
(145148, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 145148 (Oficial de expedición en jefe McCormick)
(145345, 0, 0, 0, 1, 0, 16866, 0, 0, '247866 181734'), -- 145345 (Trituradora de McCormick) - Set Health % (Uses Override Points) (No Health Regen), Smoking
(145136, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 145136 (Persuasor de Ventura y Cía.) - Permanent Feign Death (Stun, Untrackable, Immune)
(145347, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 145347 (Obrera de Ventura y Cía.)
(137501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137501 (Pterrordáctilo domado)
(137434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137434 (Vorrik)
(150895, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 150895 (Santuario de las Arenas)
(137388, 0, 0, 0, 1, 0, 0, 0, 0, '252936 246309'), -- 137388 (Vorrik) - Poisoned, Injured
(137337, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 137337 (Sargento Ermey)
(136562, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136562 (Intendente Alfin)
(141796, 0, 0, 0, 256, 0, 0, 0, 0, '18950'), -- 141796 (Sargento Sazonadora) - Invisibility and Stealth Detection
(137213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137213 (Halford Aterravermis)
(144121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144121 (Orville Manfred)
(135383, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 135383 (Barnard "el Aplastador" Baysworth)
(141784, 0, 0, 0, 256, 0, 0, 0, 0, '279937'), -- 141784 (Fusilero de la Séptima Legión) - Rifle Stand
(144136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 144136 (Pterrordáctilo domado)
(139568, 0, 0, 0, 1, 0, 0, 0, 0, '280903'), -- 139568 (Magíster Umbric) - Inv
(143473, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 143473 (Parroquiano de la taberna)
(141813, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 141813 (Murnir Trenzas de Pedernal)
(137327, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 137327 ("Salvaje" Bill Karmen)
(137322, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 137322 (Valentina Karmen)
(143478, 0, 0, 0, 1, 0, 0, 0, 0, '133464'), -- 143478 (Thoralius el Sabio) - Read Scroll
(136566, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136566 (Mordedor ladrón)
(137319, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 137319 (Cuidadora Mila)
(143472, 0, 0, 3, 1, 0, 0, 0, 0, '125567'), -- 143472 (Parroquiano desmayado) - Cosmetic - Sleep Zzz - Small Zs
(141780, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 141780 (Guardia de la Séptima Legión)
(143482, 0, 0, 0, 257, 0, 0, 0, 0, '244867'), -- 143482 (Obrero de la Alianza) - 8.0 Carry Sack New Anim
(137187, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 137187 (Reptaguerra krolusko) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(137173, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 137173 (Soldado Leonard) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(137008, 0, 0, 0, 257, 0, 2312, 0, 0, ''), -- 137008 (Sargento Ermey)
(136936, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136936 (Bestia de carga kroluska)
(136727, 0, 0, 0, 1, 0, 0, 0, 0, '46598 42459'), -- 136727 (Jinete de batalla sethrak) - Ride Vehicle Hardcoded, Dual Wield
(136731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136731 (Reptaguerra krolusko)
(136915, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 136915 (Ensalmador sethrak)
(136916, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 136916 (Sethrak Raider) - Dual Wield
(136842, 0, 0, 262144, 1, 0, 0, 0, 0, '159474'), -- 136842 (Vulpera asesinado) - Permanent Feign Death (NO Stun, Untrackable, Immune)
(143894, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 143894 (Falla del Vacío)
(143891, 0, 0, 0, 1, 0, 0, 0, 0, '70414'), -- 143891 (Magíster Umbric) - Transform Invisible
(137867, 0, 0, 0, 0, 0, 0, 0, 0, '80681'), -- 137867 (Halford Aterravermis) - Spyglass
(155070, 0, 0, 0, 1, 0, 0, 0, 0, '301630'), -- 155070 (Lecho de flores exuberantes) - [DNT] Flower Patch + Sunshaft
(141354, 0, 0, 0, 257, 0, 0, 0, 0, ''); -- 141354 (Conscripto Canto Tormenta)

UPDATE `creature_template_addon` SET `aiAnimKit`=16268 WHERE `entry`=136728; -- 136728 (Doncella de vitalidad)
UPDATE `creature_template_addon` SET `auras`='259095 268736' WHERE `entry`=136729; -- 136729 (Nodo de defensa)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=135668; -- 135668 (Druida del Círculo Cenarion)
UPDATE `creature_template_addon` SET `bytes1`=1, `bytes2`=1 WHERE `entry`=135671; -- 135671 (Chamán del Anillo de la Tierra)
UPDATE `creature_template_addon` SET `auras`='281448' WHERE `entry`=136096; -- 136096 (Declan Senal)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='207221' WHERE `entry`=135792; -- 135792 (Boralus Worker)
UPDATE `creature_template_addon` SET `bytes2`=0, `auras`='280993' WHERE `entry`=140906; -- 140906 (Rata de muelle)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=135603; -- 135603 (Boralus Civilian)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=135604; -- 135604 (Civil de Boralus)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=131789; -- 131789 (Granadero Hierro Negro)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=135876; -- 135876 (Perito de la Liga de Expedicionarios)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131674; -- 131674 (Colamuera maramargo)
UPDATE `creature_template_addon` SET `auras`='256136' WHERE `entry`=130916; -- 130916 (Mandíbula profunda salvaje)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=140664; -- 140664 (Colmillosable del sur)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=137575; -- 137575 (Albatros del Mar del Sur)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=137545; -- 137545 (Sáurido costero)
UPDATE `creature_template_addon` SET `aiAnimKit`=16468 WHERE `entry`=136197; -- 136197 (Brigadier Thom)
UPDATE `creature_template_addon` SET `aiAnimKit`=16467 WHERE `entry`=143690; -- 143690 (Trol zandalari capturado)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=135886; -- 135886 (Guardia de la muerte de los Renegados)
UPDATE `creature_template_addon` SET `auras`='262121' WHERE `entry`=133304; -- 133304 (Cautivo zandalari)
UPDATE `creature_template_addon` SET `auras`='259733' WHERE `entry`=133373; -- 133373 (Jax'teb el Reanimado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126112; -- 126112 (Guerrero de Kel'vax)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=126091; -- 126091 (Embalsamador profano)
UPDATE `creature_template_addon` SET `aiAnimKit`=9959 WHERE `entry`=126090; -- 126090 (Adoradora profana)
UPDATE `creature_template_addon` SET `auras`='261905' WHERE `entry`=133173; -- 133173 (Crustájeo de guerra feroz)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=133279; -- 133279 (Esclavo nazmani)
UPDATE `creature_template_addon` SET `auras`='273151 273038' WHERE `entry`=138812; -- 138812 (Crustájeo sangrehirviente)
UPDATE `creature_template_addon` SET `mount`=78858 WHERE `entry`=133347; -- 133347 (Devastador nazmani)
UPDATE `creature_template_addon` SET `auras`='209349' WHERE `entry`=135032; -- 135032 (Cobarde hendido)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126133; -- 126133 (Carroñero del pantano)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='12787' WHERE `entry`=127267; -- 127267 (Quijaforte enfermizo)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=126888; -- 126888 (Bruja sangrienta Vashera)
UPDATE `creature_template_addon` SET `auras`='18950' WHERE `entry`=127176; -- 127176 (Engendro de crustájeo)
UPDATE `creature_template_addon` SET `bytes1`=0, `aiAnimKit`=0 WHERE `entry`=129748; -- 129748 (Espíritu zandalari)
UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry`=126664; -- 126664 (Cuervo alafatal)
UPDATE `creature_template_addon` SET `bytes1`=8 WHERE `entry`=124703; -- 124703 (Esclavo natha'vor)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=129180; -- 129180 (Warbringer Hozzik)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=124020; -- 124020 (Exiliada zandalari)
UPDATE `creature_template_addon` SET `aiAnimKit`=15984 WHERE `entry`=139833; -- 139833 (Pterrordáctilo)
UPDATE `creature_template_addon` SET `aiAnimKit`=15982 WHERE `entry`=139835; -- 139835 (Pterrordáctilo)
UPDATE `creature_template_addon` SET `auras`='255719' WHERE `entry`=128660; -- 128660 (Agresor infiel)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=142313; -- 142313 (Defensor del templo)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=126893; -- 126893 (Alfazaque de las dunas)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='' WHERE `entry`=124718; -- 124718 (Cría de alpaca)
UPDATE `creature_template_addon` SET `auras`='244818' WHERE `entry`=128665; -- 128665 (Clamacielos infiel)
UPDATE `creature_template_addon` SET `auras`='159474' WHERE `entry`=124591; -- 124591 (Exiliado zandalari)
UPDATE `creature_template_addon` SET `auras`='61791' WHERE `entry`=124183; -- 124183 (Bilewing Egg)
UPDATE `creature_template_addon` SET `auras`='152731' WHERE `entry`=122750; -- 122750 (Cría de tenazamorte)
UPDATE `creature_template_addon` SET `auras`='42459' WHERE `entry`=128683; -- 128683 (Escarbueso infiel)
UPDATE `creature_template_addon` SET `auras`='246857' WHERE `entry`=124029; -- 124029 (Piojo de la duna)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=128681; -- 128681 (Belisario infiel)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=128685; -- 128685 (Ensalmador infiel)
UPDATE `creature_template_addon` SET `mount`=75604 WHERE `entry`=136596; -- 136596 (Sondarenas Vesarik)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=124681; -- 124681 (Acechador escarbueso)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=137422; -- 137422 (Escórpido colapétrea)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=122530; -- 122530 (Spell Bunny)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=124527; -- 124527 (Carroñero picóseo)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=143483; -- 143483 (Mula de carga)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=134722; -- 134722 (Vagabundo demacrado)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=143700; -- 143700 (Alpaca doméstica)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=124805; -- 124805 (Mozo de cuadra)
UPDATE `creature_template_addon` SET `auras`='244971' WHERE `entry`=143844; -- 143844 (Marino ocioso)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=142457; -- 142457 (Jardinero de Vientos Alisios)
UPDATE `creature_template_addon` SET `aiAnimKit`=13281 WHERE `entry`=143295; -- 143295 (Pregonero de Boralus)
UPDATE `creature_template_addon` SET `auras`='271518' WHERE `entry`=142346; -- 142346 (Sastre de Vientos Alisios)
UPDATE `creature_template_addon` SET `aiAnimKit`=0 WHERE `entry`=132642; -- 132642 (Kul Tiran Noble)
UPDATE `creature_template_addon` SET `auras`='271317' WHERE `entry`=135230; -- 135230 (Inspector de Boralus)
UPDATE `creature_template_addon` SET `bytes1`=1, `auras`='145953' WHERE `entry`=143502; -- 143502 (Whisky)
UPDATE `creature_template_addon` SET `bytes2`=257, `auras`='273259' WHERE `entry`=140350; -- 140350 (Capitán de la guardia del puerto)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=142166; -- 142166 (Trabajador de embarcadero Vientos Alisios)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=135509; -- 135509 (Ciudadano de Boralus)
UPDATE `creature_template_addon` SET `aiAnimKit`=1320 WHERE `entry`=141484; -- 141484 (Ciudadano de Presabrenna)
UPDATE `creature_template_addon` SET `auras`='255498' WHERE `entry`=141482; -- 141482 (Ciudadana de Presabrenna)
UPDATE `creature_template_addon` SET `mount`=29283 WHERE `entry`=137104; -- 137104 (Asaltante orco)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=131709; -- 131709 (Mozo de labranza mecanizado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=147008; -- 147008 (Marlowe Lexvold)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=130452; -- 130452 (Perro guardián fiel)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=129869; -- 129869 (Comerraíces hambriento)
UPDATE `creature_template_addon` SET `aiAnimKit`=14470, `auras`='258156 258159' WHERE `entry`=130395; -- 130395 (Briarback Warcaller)
UPDATE `creature_template_addon` SET `auras`='244867 272020' WHERE `entry`=138168; -- 138168 (Irontide Coin Hauler)
UPDATE `creature_template_addon` SET `mount`=76888 WHERE `entry`=135782; -- 135782 (Eddard Chimuelo)
UPDATE `creature_template_addon` SET `aiAnimKit`=15826 WHERE `entry`=134377; -- 134377 (Halieto picosuave)
UPDATE `creature_template_addon` SET `auras`='79175' WHERE `entry`=123236; -- 123236 (Cangrejo pasoveloz)
UPDATE `creature_template_addon` SET `bytes1`=8, `auras`='' WHERE `entry`=131409; -- 131409 (Soldado del batallón varado)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=131114; -- 131114 (Obrero del batallón)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='' WHERE `entry`=130867; -- 130867 (Soldado del batallón)
UPDATE `creature_template_addon` SET `auras`='263990' WHERE `entry`=134401; -- 134401 (Lady Rash'iss)
UPDATE `creature_template_addon` SET `bytes2`=256, `auras`='' WHERE `entry`=143168; -- 143168 (Desuellapeces malhumorado)
UPDATE `creature_template_addon` SET `aiAnimKit`=16059 WHERE `entry`=143182; -- 143182 (Velador atribulado)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145362' WHERE `entry`=131085; -- 131085 (Señor de las Mareas zeth'jir)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=0, `auras`='' WHERE `entry`=135037; -- 135037 (Aldeano armado)
UPDATE `creature_template_addon` SET `auras`='44530' WHERE `entry`=130130; -- 130130 (Guerracerdo hambriento)
UPDATE `creature_template_addon` SET `auras`='275702' WHERE `entry`=134341; -- 134341 (Vinculadora Sa'thress)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=131141; -- 131141 (Guardián escamoso zeth'jir)
UPDATE `creature_template_addon` SET `auras`='265780' WHERE `entry`=137025; -- 137025 (Madre de linaje)
UPDATE `creature_template_addon` SET `aiAnimKit`=16251 WHERE `entry`=136574; -- 136574 (Charles Davenport)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=140595; -- 140595 (Cazador Canto Tormenta)
UPDATE `creature_template_addon` SET `bytes1`=262144, `auras`='145363' WHERE `entry`=130073; -- 130073 (Briarback Lookout)
UPDATE `creature_template_addon` SET `bytes1`=1 WHERE `entry`=131600; -- 131600 (Halcón de las Tierras Altas)
UPDATE `creature_template_addon` SET `auras`='274377' WHERE `entry`=138755; -- 138755 (Irontide Slaver)
UPDATE `creature_template_addon` SET `bytes1`=3, `auras`='207221' WHERE `entry`=134666; -- 134666 (Cazatesoros)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=136743; -- 136743 (Cazatesoros)
UPDATE `creature_template_addon` SET `bytes1`=5, `auras`='42871' WHERE `entry`=135391; -- 135391 (Trabajador de La Rivera Muerta)
UPDATE `creature_template_addon` SET `bytes1`=5, `auras`='141453 42871' WHERE `entry`=138739; -- 138739 (Defensor de La Rivera Muerta)
UPDATE `creature_template_addon` SET `auras`='277931' WHERE `entry`=137744; -- 137744 (Generic - Empty Bunny)
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=134636; -- 134636 (Cazatesoros)
UPDATE `creature_template_addon` SET `auras`='264867' WHERE `entry`=134966; -- 134966 (Piedra inquieta)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=141195; -- 141195 (Alexys Southey)


UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=139828 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=137580 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=288, `VerifiedBuild`=38134 WHERE (`Entry`=136728 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=288, `VerifiedBuild`=38134 WHERE (`Entry`=136729 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=137607 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=141870 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131814 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=136550 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131626 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=137766 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=136552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143334 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135878 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=132188 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143488 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140510 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140571 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140525 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140580 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140579 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137378 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137391 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135879 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136099 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131763 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131777 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136097 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137401 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131800 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135875 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=131789 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135876 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=128041 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137149 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137185 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=809, `VerifiedBuild`=38134 WHERE (`Entry`=137154 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131630 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131674 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131675 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `ContentTuningID`=189 WHERE (`Entry`=75372 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129302 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142305 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=143044 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131673 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131676 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142282 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=140664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=142284 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141096 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144366 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137575 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=157907 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=129320 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137524 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=129710 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=157735 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128632 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137463 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=128604 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137545 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=144460 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=782, `VerifiedBuild`=38134 WHERE (`Entry`=157737 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130999 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=130832 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=141521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137678 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137680 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=136292 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=136290 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=138109 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136906 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137084 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137834 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133862 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133824 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137771 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136195 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136192 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137255 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136197 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137624 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138854 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138850 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143690 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=138117 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=138128 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=138118 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=144457 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=133846 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137849 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137230 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135858 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135886 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=131631 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=131013 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143677 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=143678 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=136449 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=135620 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137440 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=189, `VerifiedBuild`=38134 WHERE (`Entry`=137441 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133335 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133336 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133304 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133373 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133376 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136988 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133445 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133181 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133279 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133358 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136675 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=691, `VerifiedBuild`=38134 WHERE (`Entry`=150102 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138743 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138775 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=139797 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=138812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=133347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128935 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=805, `VerifiedBuild`=38134 WHERE (`Entry`=135054 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128965 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=128975 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136564 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136565 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136639 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136641 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=25, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=136573 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=136575 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=126056 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=124976 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=131629 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=190, `VerifiedBuild`=38134 WHERE (`Entry`=127820 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=143107 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=137240 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144088 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=144051 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129180 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124020 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124627 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130427 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130429 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=134611 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128691 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136925 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136926 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139075 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128996 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=145245 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137402 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128694 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129519 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139827 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139835 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137559 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144353 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=128695 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139831 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130023 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130022 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=134638 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=152093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137552 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128664 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128660 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128661 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128662 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129076 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=133333 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129202 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128697 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137537 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137543 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=150318 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129011 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128693 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128688 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=134613 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128689 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128692 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129216 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129521 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129014 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141955 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141950 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=371, `VerifiedBuild`=38134 WHERE (`Entry`=141951 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=1, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=373, `VerifiedBuild`=38134 WHERE (`Entry`=141945 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=142313 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=126893 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=135400 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=143454 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124716 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124718 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124522 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=136986 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136109 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136144 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130042 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=134320 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129004 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=134321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139072 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128665 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129007 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=145148 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124591 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=145345 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=145136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=145347 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124179 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=133833 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124177 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130270 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124172 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124182 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124183 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124536 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=142449 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=141597 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130248 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=123572 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=122749 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=122750 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=123473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124029 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128685 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128978 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=129120 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124526 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128678 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=128682 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137501 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137434 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=708, `VerifiedBuild`=38134 WHERE (`Entry`=150895 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124654 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136596 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124681 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124683 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137416 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137388 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130348 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137337 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137413 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=130349 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137422 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=126904 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136663 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137419 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=136553 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=706, `VerifiedBuild`=38134 WHERE (`Entry`=139361 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=122530 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137412 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124287 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=1, `LevelScalingDeltaMax`=0, `ContentTuningID`=81, `VerifiedBuild`=38134 WHERE (`Entry`=137417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=124527 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136562 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144610 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=141796 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=137213 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=144121 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=2117, `VerifiedBuild`=38134 WHERE (`Entry`=135383 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=141784 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=144136 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=139568 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=143473 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=141813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137327 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137322 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=143478 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=830, `VerifiedBuild`=38134 WHERE (`Entry`=122170 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=136566 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137319 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=143472 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=141780 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=143482 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=137187 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=137173 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=137008 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136936 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136727 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136731 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136915 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=136916 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=136842 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=143894 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=467, `VerifiedBuild`=38134 WHERE (`Entry`=143891 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=137867 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=191, `VerifiedBuild`=38134 WHERE (`Entry`=125098 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138744 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138178 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138321 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=492, `VerifiedBuild`=38134 WHERE (`Entry`=138322 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130395 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1 WHERE (`Entry`=143592 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135782 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131199 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131312 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131433 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=129973 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134669 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131315 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0 WHERE (`Entry`=138093 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=50, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=789, `VerifiedBuild`=38134 WHERE (`Entry`=155070 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135402 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134987 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135403 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134809 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134401 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134813 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=5, `LevelScalingMax`=5, `LevelScalingDeltaMin`=5, `LevelScalingDeltaMax`=5, `ContentTuningID`=1723, `VerifiedBuild`=38134 WHERE (`Entry`=137390 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=143158 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143168 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143182 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141877 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131143 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141872 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131002 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=10, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=186, `VerifiedBuild`=38134 WHERE (`Entry`=133983 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130079 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134884 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134141 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135293 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137231 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136417 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=141534 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136418 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=136734 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134341 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134343 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134340 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=131125 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=130812 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=134379 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=60, `LevelScalingMax`=60, `LevelScalingDeltaMax`=0, `ContentTuningID`=465, `VerifiedBuild`=38134 WHERE (`Entry`=141354 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143903 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=143899 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingMin`=35, `LevelScalingMax`=50, `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=137078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=139793 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMax`=0, `ContentTuningID`=188, `VerifiedBuild`=38134 WHERE (`Entry`=135745 AND `DifficultyID`=0);


UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=64192;
UPDATE `creature_model_info` SET `BoundingRadius`=0.388999998569488525, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84340;
UPDATE `creature_model_info` SET `BoundingRadius`=1.002216458320617675, `CombatReach`=1.5 WHERE `DisplayID`=83052;
UPDATE `creature_model_info` SET `BoundingRadius`=0.336600005626678466, `CombatReach`=1.65000009536743164 WHERE `DisplayID`=86639;
UPDATE `creature_model_info` SET `BoundingRadius`=1.10000002384185791, `CombatReach`=2.75, `VerifiedBuild`=38134 WHERE `DisplayID`=79700;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=47241;
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609089851379394, `CombatReach`=1.5 WHERE `DisplayID`=83648;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82051;
UPDATE `creature_model_info` SET `BoundingRadius`=1.615294933319091796, `CombatReach`=2.550000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=45728;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77699;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=77634;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86779;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82278;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86762;
UPDATE `creature_model_info` SET `BoundingRadius`=0.330480009317398071, `CombatReach`=1.620000123977661132, `VerifiedBuild`=38134 WHERE `DisplayID`=86724;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86758;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86756;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86761;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86757;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86754;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86755;
UPDATE `creature_model_info` SET `BoundingRadius`=2.854209661483764648, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86765;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86778;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86777;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86760;
UPDATE `creature_model_info` SET `BoundingRadius`=0.275399982929229736, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86775;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82280;
UPDATE `creature_model_info` SET `BoundingRadius`=0.48878103494644165, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=69826;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82279;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82281;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83214;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82035;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82041;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82018;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79754;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82087;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82049;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77633;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82088;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77637;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79752;
UPDATE `creature_model_info` SET `BoundingRadius`=0.267839998006820678, `CombatReach`=1.079999923706054687 WHERE `DisplayID`=83770;
UPDATE `creature_model_info` SET `BoundingRadius`=0.267839998006820678, `CombatReach`=1.079999923706054687 WHERE `DisplayID`=83768;
UPDATE `creature_model_info` SET `BoundingRadius`=0.267839998006820678, `CombatReach`=1.079999923706054687 WHERE `DisplayID`=83769;
UPDATE `creature_model_info` SET `BoundingRadius`=1.530432820320129394, `CombatReach`=1.0625, `VerifiedBuild`=38134 WHERE `DisplayID`=2835;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=96323;
UPDATE `creature_model_info` SET `BoundingRadius`=6.474579811096191406, `CombatReach`=14, `VerifiedBuild`=38134 WHERE `DisplayID`=80520;
UPDATE `creature_model_info` SET `BoundingRadius`=6.474579811096191406, `CombatReach`=14, `VerifiedBuild`=38134 WHERE `DisplayID`=80519;
UPDATE `creature_model_info` SET `BoundingRadius`=1.849879980087280273, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=2425;
UPDATE `creature_model_info` SET `BoundingRadius`=0.649034619331359863, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=86802;
UPDATE `creature_model_info` SET `BoundingRadius`=1.260356426239013671, `CombatReach`=0.875, `VerifiedBuild`=38134 WHERE `DisplayID`=1818;
UPDATE `creature_model_info` SET `BoundingRadius`=2.340662002563476562, `CombatReach`=1.625, `VerifiedBuild`=38134 WHERE `DisplayID`=80528;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87605;
UPDATE `creature_model_info` SET `BoundingRadius`=0.592596828937530517, `CombatReach`=1.574999928474426269 WHERE `DisplayID`=86800;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87604;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32265;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=32264;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32263;
UPDATE `creature_model_info` SET `BoundingRadius`=0.046500001102685928, `CombatReach`=0.150000005960464477, `VerifiedBuild`=38134 WHERE `DisplayID`=19998;
UPDATE `creature_model_info` SET `BoundingRadius`=4.282311916351318359, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=66813;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216999992728233337, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=85533;
UPDATE `creature_model_info` SET `BoundingRadius`=1.099327802658081054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=4036;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216999992728233337, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=85532;
UPDATE `creature_model_info` SET `BoundingRadius`=0.729359745979309082, `VerifiedBuild`=38134 WHERE `DisplayID`=31065;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75 WHERE `DisplayID`=80265;
UPDATE `creature_model_info` SET `BoundingRadius`=3.97802138328552246, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=12198;
UPDATE `creature_model_info` SET `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=2851;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87335;
UPDATE `creature_model_info` SET `BoundingRadius`=0.899999976158142089, `CombatReach`=6.299999713897705078 WHERE `DisplayID`=77955;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84704;
UPDATE `creature_model_info` SET `BoundingRadius`=0.690245032310485839, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84703;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85627;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85487;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85486;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85123;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216999992728233337, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=62709;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84457;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84446;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85484;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85485;
UPDATE `creature_model_info` SET `BoundingRadius`=0.313199996948242187, `CombatReach`=0.449999988079071044 WHERE `DisplayID`=39733;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85564;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86055;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86058;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86057;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84643;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84636;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84644;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85401;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86024;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86056;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85741;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86059;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=86060;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86061;
UPDATE `creature_model_info` SET `BoundingRadius`=0.216999992728233337, `CombatReach`=0.699999988079071044 WHERE `DisplayID`=60862;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84448;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84456;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84442;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84440;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=77149;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84443;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84449;
UPDATE `creature_model_info` SET `BoundingRadius`=0.381700009107589721, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=85249;
UPDATE `creature_model_info` SET `BoundingRadius`=0.768515944480895996, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=82877;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82879;
UPDATE `creature_model_info` SET `BoundingRadius`=0.443374603986740112, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=82878;
UPDATE `creature_model_info` SET `BoundingRadius`=1.26909041404724121 WHERE `DisplayID`=78131;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=82848;
UPDATE `creature_model_info` SET `BoundingRadius`=0.270399987697601318, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84904;
UPDATE `creature_model_info` SET `BoundingRadius`=0.270399987697601318, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84816;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82926;
UPDATE `creature_model_info` SET `BoundingRadius`=0.760386109352111816, `CombatReach`=1.65000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=82924;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82927;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82686;
UPDATE `creature_model_info` SET `BoundingRadius`=1.028887391090393066, `CombatReach`=1.539999961853027343, `VerifiedBuild`=38134 WHERE `DisplayID`=79303;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82366;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82825;
UPDATE `creature_model_info` SET `BoundingRadius`=1.469839096069335937, `CombatReach`=2.20000004768371582 WHERE `DisplayID`=78855;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82865;
UPDATE `creature_model_info` SET `BoundingRadius`=0.650950193405151367, `CombatReach`=1.897500038146972656, `VerifiedBuild`=38134 WHERE `DisplayID`=82863;
UPDATE `creature_model_info` SET `BoundingRadius`=1.830751657485961914, `CombatReach`=4.049999713897705078, `VerifiedBuild`=38134 WHERE `DisplayID`=76134;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84048;
UPDATE `creature_model_info` SET `BoundingRadius`=2.385242462158203125, `CombatReach`=2.25, `VerifiedBuild`=38134 WHERE `DisplayID`=84063;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84049;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84045;
UPDATE `creature_model_info` SET `BoundingRadius`=3.053412199020385742, `CombatReach`=2.099999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=80299;
UPDATE `creature_model_info` SET `BoundingRadius`=6.826453208923339843, `CombatReach`=5.25, `VerifiedBuild`=38134 WHERE `DisplayID`=84824;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=84811;
UPDATE `creature_model_info` SET `BoundingRadius`=0.518445074558258056, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=82822;
UPDATE `creature_model_info` SET `BoundingRadius`=0.518445074558258056, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=82823;
UPDATE `creature_model_info` SET `BoundingRadius`=1.026381731033325195 WHERE `DisplayID`=32546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044 WHERE `DisplayID`=80458;
UPDATE `creature_model_info` SET `BoundingRadius`=1.973609089851379394, `CombatReach`=1.5 WHERE `DisplayID`=83645;
UPDATE `creature_model_info` SET `BoundingRadius`=1.586651444435119628, `CombatReach`=3.509999752044677734, `VerifiedBuild`=38134 WHERE `DisplayID`=78669;
UPDATE `creature_model_info` SET `CombatReach`=2.160000085830688476, `VerifiedBuild`=38134 WHERE `DisplayID`=78278;
UPDATE `creature_model_info` SET `BoundingRadius`=3.45185708999633789, `CombatReach`=2 WHERE `DisplayID`=53767;
UPDATE `creature_model_info` SET `BoundingRadius`=0.046500001102685928, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=81376;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84089;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=53835;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=54615;
UPDATE `creature_model_info` SET `BoundingRadius`=1.21473240852355957, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82183;
UPDATE `creature_model_info` SET `BoundingRadius`=1.140607118606567382, `CombatReach`=1.5 WHERE `DisplayID`=77690;
UPDATE `creature_model_info` SET `BoundingRadius`=1.097076892852783203, `CombatReach`=0.75 WHERE `DisplayID`=84871;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87814;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32025;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=88201;
UPDATE `creature_model_info` SET `BoundingRadius`=1.121291518211364746, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80424;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.526631593704223632, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80404;
UPDATE `creature_model_info` SET `BoundingRadius`=0.526631593704223632, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=76382;
UPDATE `creature_model_info` SET `BoundingRadius`=0.36864212155342102, `CombatReach`=0.349999994039535522, `VerifiedBuild`=38134 WHERE `DisplayID`=76383;
UPDATE `creature_model_info` SET `BoundingRadius`=0.36864212155342102, `CombatReach`=0.349999994039535522, `VerifiedBuild`=38134 WHERE `DisplayID`=76384;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=83785;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80626;
UPDATE `creature_model_info` SET `BoundingRadius`=0.270000010728836059 WHERE `DisplayID`=3619;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375 WHERE `DisplayID`=983;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=5557;
UPDATE `creature_model_info` SET `BoundingRadius`=0.375 WHERE `DisplayID`=441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.270000010728836059 WHERE `DisplayID`=1762;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=86117;
UPDATE `creature_model_info` SET `BoundingRadius`=1.339599132537841796, `CombatReach`=1.75, `VerifiedBuild`=38134 WHERE `DisplayID`=641;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85309;
UPDATE `creature_model_info` SET `BoundingRadius`=0.095685653388500213, `CombatReach`=0.125, `VerifiedBuild`=38134 WHERE `DisplayID`=5560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80668;
UPDATE `creature_model_info` SET `BoundingRadius`=2.52931976318359375, `CombatReach`=4.200000286102294921, `VerifiedBuild`=38134 WHERE `DisplayID`=80972;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80973;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80630;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84493;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84497;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80623;
UPDATE `creature_model_info` SET `BoundingRadius`=2.502509117126464843, `CombatReach`=4.800000190734863281, `VerifiedBuild`=38134 WHERE `DisplayID`=80093;
UPDATE `creature_model_info` SET `BoundingRadius`=1.401614308357238769, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80681;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80660;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80661;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84499;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=85251;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84481;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80655;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80639;
UPDATE `creature_model_info` SET `BoundingRadius`=1.944476842880249023, `CombatReach`=5, `VerifiedBuild`=38134 WHERE `DisplayID`=79953;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80657;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80632;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=83417;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80631;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80633;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83784;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80635;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80629;
UPDATE `creature_model_info` SET `BoundingRadius`=0.95685654878616333, `CombatReach`=1.25 WHERE `DisplayID`=76626;
UPDATE `creature_model_info` SET `BoundingRadius`=0.699999988079071044, `CombatReach`=0.699999988079071044, `VerifiedBuild`=38134 WHERE `DisplayID`=85545;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80634;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84472;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80659;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84482;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=84659;
UPDATE `creature_model_info` SET `BoundingRadius`=0.749117851257324218, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=75324;
UPDATE `creature_model_info` SET `BoundingRadius`=0.654953062534332275, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=87965;
UPDATE `creature_model_info` SET `BoundingRadius`=0.45561954379081726, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=87966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.569524407386779785, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87963;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=0.349999994039535522, `VerifiedBuild`=38134 WHERE `DisplayID`=85308;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80466;
UPDATE `creature_model_info` SET `BoundingRadius`=0.08749999850988388, `CombatReach`=0.25, `VerifiedBuild`=38134 WHERE `DisplayID`=40999;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84492;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80624;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80654;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80658;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80487;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80651;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84495;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81231;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88984;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=82992;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81314;
UPDATE `creature_model_info` SET `BoundingRadius`=2.6875, `CombatReach`=5 WHERE `DisplayID`=56590;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=81315;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81229;
UPDATE `creature_model_info` SET `BoundingRadius`=0.429647743701934814, `CombatReach`=0.200000002980232238 WHERE `DisplayID`=45906;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=38733;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=83185;
UPDATE `creature_model_info` SET `BoundingRadius`=1.239107370376586914, `CombatReach`=0.60000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=83281;
UPDATE `creature_model_info` SET `BoundingRadius`=0.78850865364074707, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81104;
UPDATE `creature_model_info` SET `BoundingRadius`=1.548884153366088867, `CombatReach`=0.75, `VerifiedBuild`=38134 WHERE `DisplayID`=80027;
UPDATE `creature_model_info` SET `BoundingRadius`=1.992648959159851074, `CombatReach`=2.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77495;
UPDATE `creature_model_info` SET `BoundingRadius`=0.337499976158142089, `CombatReach`=1.125, `VerifiedBuild`=38134 WHERE `DisplayID`=80518;
UPDATE `creature_model_info` SET `BoundingRadius`=1.342366218566894531, `CombatReach`=0.649999976158142089, `VerifiedBuild`=38134 WHERE `DisplayID`=80021;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=80495;
UPDATE `creature_model_info` SET `BoundingRadius`=1.5, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=78205;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80571;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=78206;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80572;
UPDATE `creature_model_info` SET `BoundingRadius`=0.934409558773040771, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80664;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80647;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=31460;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84483;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84484;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84489;
UPDATE `creature_model_info` SET `BoundingRadius`=0.981130003929138183, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80636;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80648;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=80646;
UPDATE `creature_model_info` SET `BoundingRadius`=1.967838048934936523, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=77752;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=84500;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=80643;
UPDATE `creature_model_info` SET `BoundingRadius`=2.08085036277770996, `VerifiedBuild`=38134 WHERE `DisplayID`=90952;
UPDATE `creature_model_info` SET `BoundingRadius`=2.623784065246582031, `CombatReach`=4 WHERE `DisplayID`=75599;
UPDATE `creature_model_info` SET `BoundingRadius`=1.21473240852355957, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=84839;
UPDATE `creature_model_info` SET `BoundingRadius`=5.855165004730224609, `CombatReach`=7.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85438;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=78191;
UPDATE `creature_model_info` SET `BoundingRadius`=0.818858265876770019, `CombatReach`=1.949999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=2609;
UPDATE `creature_model_info` SET `BoundingRadius`=0.566901862621307373, `CombatReach`=1.349999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=78190;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85252;
UPDATE `creature_model_info` SET `BoundingRadius`=0.871917307376861572, `CombatReach`=1.080000042915344238, `VerifiedBuild`=38134 WHERE `DisplayID`=80334;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522, `CombatReach`=1, `VerifiedBuild`=38134 WHERE `DisplayID`=80465;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=85250;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=0.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81138;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199187994003295898, `CombatReach`=1.049999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=83844;
UPDATE `creature_model_info` SET `BoundingRadius`=1.967838048934936523, `CombatReach`=3, `VerifiedBuild`=38134 WHERE `DisplayID`=85225;
UPDATE `creature_model_info` SET `BoundingRadius`=0.787135243415832519, `CombatReach`=1.20000004768371582, `VerifiedBuild`=38134 WHERE `DisplayID`=77753;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629890978336334228, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=1534;
UPDATE `creature_model_info` SET `BoundingRadius`=2.771951198577880859, `VerifiedBuild`=38134 WHERE `DisplayID`=32408;
UPDATE `creature_model_info` SET `BoundingRadius`=0.428399980068206787, `CombatReach`=2.099999904632568359 WHERE `DisplayID`=82795;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=72015;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=32405;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=53108;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87454;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=73509;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=59249;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87957;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87455;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347000002861022949, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=87459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85219;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85216;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=21947;
UPDATE `creature_model_info` SET `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=85215;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=54613;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=26998;
UPDATE `creature_model_info` SET `BoundingRadius`=2.623784065246582031, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=75596;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=83733;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=83734;
UPDATE `creature_model_info` SET `BoundingRadius`=2.623784065246582031, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=75604;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79912;
UPDATE `creature_model_info` SET `BoundingRadius`=2.623784065246582031, `CombatReach`=4, `VerifiedBuild`=38134 WHERE `DisplayID`=75601;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79323;
UPDATE `creature_model_info` SET `BoundingRadius`=0.807330787181854248, `VerifiedBuild`=38134 WHERE `DisplayID`=80641;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83739;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=79326;
UPDATE `creature_model_info` SET `BoundingRadius`=0.840968608856201171, `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83737;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=83740;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=79877;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364190876483917236, `VerifiedBuild`=38134 WHERE `DisplayID`=79456;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=82048;
UPDATE `creature_model_info` SET `BoundingRadius`=0.140088886022567749, `CombatReach`=0.5 WHERE `DisplayID`=87565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.310000002384185791, `VerifiedBuild`=38134 WHERE `DisplayID`=87495;
UPDATE `creature_model_info` SET `BoundingRadius`=0.253760010004043579, `CombatReach`=1.830000042915344238 WHERE `DisplayID`=5565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.351899981498718261, `CombatReach`=1.724999904632568359, `VerifiedBuild`=38134 WHERE `DisplayID`=75719;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88686;
UPDATE `creature_model_info` SET `VerifiedBuild`=38134 WHERE `DisplayID`=87347;
UPDATE `creature_model_info` SET `BoundingRadius`=0.180290251970291137, `CombatReach`=0.649999976158142089 WHERE `DisplayID`=72186;
UPDATE `creature_model_info` SET `BoundingRadius`=0.332843631505966186, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=86543;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895694732666015, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=84065;
UPDATE `creature_model_info` SET `BoundingRadius`=0.221895739436149597, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=86546;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369678020477294, `CombatReach`=1 WHERE `DisplayID`=88674;
UPDATE `creature_model_info` SET `BoundingRadius`=0.277369618415832519, `CombatReach`=1 WHERE `DisplayID`=74789;
UPDATE `creature_model_info` SET `BoundingRadius`=0.18394915759563446, `CombatReach`=1.20000004768371582 WHERE `DisplayID`=5369;
UPDATE `creature_model_info` SET `BoundingRadius`=0.167159661650657653, `CombatReach`=1.10000002384185791 WHERE `DisplayID`=76516;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306255877017974853, `CombatReach`=0.800000011920928955 WHERE `DisplayID`=4959;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269 WHERE `DisplayID`=84402;
UPDATE `creature_model_info` SET `BoundingRadius`=0.364583075046539306, `CombatReach`=1.574999928474426269 WHERE `DisplayID`=84401;
UPDATE `creature_model_info` SET `BoundingRadius`=18.76809120178222656, `CombatReach`=26.25, `VerifiedBuild`=38134 WHERE `DisplayID`=84873;
UPDATE `creature_model_info` SET `CombatReach`=0, `VerifiedBuild`=38134 WHERE `DisplayID`=81567;
UPDATE `creature_model_info` SET `BoundingRadius`=1.32942509651184082, `CombatReach`=1.60000002384185791 WHERE `DisplayID`=81269;
UPDATE `creature_model_info` SET `BoundingRadius`=1.366205096244812011, `CombatReach`=1.75 WHERE `DisplayID`=87603;
UPDATE `creature_model_info` SET `BoundingRadius`=0.948167622089385986, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=18395;
UPDATE `creature_model_info` SET `BoundingRadius`=1.094039678573608398, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=66892;
UPDATE `creature_model_info` SET `BoundingRadius`=3.790608882904052734, `CombatReach`=5.399999618530273437 WHERE `DisplayID`=66812;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955 WHERE `DisplayID`=79380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.349999994039535522 WHERE `DisplayID`=79382;
UPDATE `creature_model_info` SET `BoundingRadius`=2.002724170684814453, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=66380;
UPDATE `creature_model_info` SET `BoundingRadius`=2.503405094146728515, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=71307;
UPDATE `creature_model_info` SET `BoundingRadius`=2.002724170684814453, `CombatReach`=2 WHERE `DisplayID`=65628;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88415;
UPDATE `creature_model_info` SET `BoundingRadius`=0.174999997019767761, `CombatReach`=2.1875 WHERE `DisplayID`=34160;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222000360488891, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=81711;
UPDATE `creature_model_info` SET `BoundingRadius`=2.396857976913452148, `CombatReach`=3.375, `VerifiedBuild`=38134 WHERE `DisplayID`=88565;
UPDATE `creature_model_info` SET `BoundingRadius`=5.220055580139160156, `CombatReach`=4.5, `VerifiedBuild`=38134 WHERE `DisplayID`=8550;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=29253;
UPDATE `creature_model_info` SET `BoundingRadius`=4.6874847412109375, `CombatReach`=3 WHERE `DisplayID`=52696;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1.5 WHERE `DisplayID`=81966;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1.5 WHERE `DisplayID`=81964;
UPDATE `creature_model_info` SET `BoundingRadius`=2.002724170684814453, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=36660;
UPDATE `creature_model_info` SET `BoundingRadius`=1.254749417304992675, `CombatReach`=1.299999952316284179, `VerifiedBuild`=38134 WHERE `DisplayID`=77173;
UPDATE `creature_model_info` SET `BoundingRadius`=1.25406193733215332, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=34269;
UPDATE `creature_model_info` SET `BoundingRadius`=0.765639662742614746, `CombatReach`=2 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `BoundingRadius`=0.199278235435485839, `CombatReach`=1.299999952316284179 WHERE `DisplayID`=304;
UPDATE `creature_model_info` SET `BoundingRadius`=0.973670184612274169, `CombatReach`=2, `VerifiedBuild`=38134 WHERE `DisplayID`=83053;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=88086;
UPDATE `creature_model_info` SET `BoundingRadius`=0.052500002086162567, `CombatReach`=0.150000005960464477 WHERE `DisplayID`=86529;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=8 WHERE `DisplayID`=30500;
UPDATE `creature_model_info` SET `BoundingRadius`=0.685569643974304199, `CombatReach`=2.5 WHERE `DisplayID`=66292;
UPDATE `creature_model_info` SET `BoundingRadius`=1.411821842193603515, `CombatReach`=2.90000009536743164, `VerifiedBuild`=38134 WHERE `DisplayID`=86493;
UPDATE `creature_model_info` SET `BoundingRadius`=0.218400001525878906, `CombatReach`=1.574999928474426269, `VerifiedBuild`=38134 WHERE `DisplayID`=84436;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=6106;
UPDATE `creature_model_info` SET `BoundingRadius`=3.76745772361755371, `CombatReach`=3 WHERE `DisplayID`=86974;
UPDATE `creature_model_info` SET `BoundingRadius`=1.278324246406555175, `CombatReach`=1.80000007152557373 WHERE `DisplayID`=88563;
UPDATE `creature_model_info` SET `BoundingRadius`=1.065270185470581054, `CombatReach`=1.5 WHERE `DisplayID`=1963;
UPDATE `creature_model_info` SET `BoundingRadius`=2, `CombatReach`=2.5, `VerifiedBuild`=38134 WHERE `DisplayID`=48169;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=38134 WHERE `DisplayID`=86449;

DELETE FROM `npc_vendor` WHERE (`entry`=135072 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=135072 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135072 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135072 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(135072, 13, 163203, 0, 6426, 1, 0, 0, 38134), -- Hypersensitive Azeritometer Sensor
(135072, 5, 6219, 0, 0, 1, 0, 0, 38134), -- Arclight Spanner
(135072, 2, 183952, 0, 0, 1, 0, 0, 38134), -- Machinist's Oil
(135072, 1, 180733, 0, 0, 1, 0, 0, 38134); -- Luminous Flux

UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=163019 AND `ExtendedCost`=0 AND `type`=1); -- Drop Anchor Dunkel
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=162026 AND `ExtendedCost`=0 AND `type`=1); -- Hook Point Porter
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=163548 AND `ExtendedCost`=0 AND `type`=1); -- Kul Tiran Tripel
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=163098 AND `ExtendedCost`=0 AND `type`=1); -- Tradewinds Kolsch
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=159849 AND `ExtendedCost`=0 AND `type`=1); -- Hook Point Schnapps
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=143244 AND `item`=163018 AND `ExtendedCost`=0 AND `type`=1); -- Pontoon Pilsner
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=131800 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=136192 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1); -- Elemental Flux
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1); -- Chemical Blasting Cap
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=135072 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1); -- Insulated Wiring
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water
UPDATE `npc_vendor` SET `slot`=34, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=33, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=32, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Bright Baubles
UPDATE `npc_vendor` SET `slot`=31, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6530 AND `ExtendedCost`=0 AND `type`=1); -- Nightcrawlers
UPDATE `npc_vendor` SET `slot`=30, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Stock
UPDATE `npc_vendor` SET `slot`=29, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1); -- Wooden Stock
UPDATE `npc_vendor` SET `slot`=28, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4289 AND `ExtendedCost`=0 AND `type`=1); -- Salt
UPDATE `npc_vendor` SET `slot`=27, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1); -- Gray Dye
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1); -- Purple Dye
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1); -- Yellow Dye
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1); -- Black Dye
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1); -- Red Dye
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1); -- Coal
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1); -- Strong Flux
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1); -- Weak Flux
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1); -- Mild Spices
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Eternium Thread
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Rune Thread
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=8343 AND `ExtendedCost`=0 AND `type`=1); -- Heavy Silken Thread
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=4291 AND `ExtendedCost`=0 AND `type`=1); -- Silken Thread
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2321 AND `ExtendedCost`=0 AND `type`=1); -- Fine Thread
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2320 AND `ExtendedCost`=0 AND `type`=1); -- Coarse Thread
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=160059 AND `ExtendedCost`=0 AND `type`=1); -- Amber Tanning Oil
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1); -- Durable Flux
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=159959 AND `ExtendedCost`=0 AND `type`=1); -- Nylon Thread
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=158205 AND `ExtendedCost`=0 AND `type`=1); -- Acacia Powder
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=139992 AND `item`=158186 AND `ExtendedCost`=0 AND `type`=1); -- Distilled Water
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Pack
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Vanishing Powder
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Virtuoso Inking Set
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Jeweler's Kit
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1); -- Blacksmith Hammer
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1); -- Copper Rod
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1); -- Fishing Pole
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1); -- Herbalist's Spade
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1); -- Skinning Knife
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1); -- Mining Pick
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1); -- Explorer's Pack
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1); -- Tinker's Kit
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Simple Wood
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1); -- Enchanting Vellum
UPDATE `npc_vendor` SET `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Crystal Vial
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=38134 WHERE (`entry`=142984 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Light Parchment

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (137766,136552,140510,140525,140536,137391,137400,137401,137148,137149,137185,137680,138109,136192,137965,136075,135620,137440,137441,136675,138743,138775,139797,136641,137240,145245,152093,137543,145136,145347,137337,141796,137213,135383,141784,141813,137327,137322,143482,143472,141780,137173,137008,136727,136915,136916,137867,141354)) OR (`ID`=2 AND `CreatureID`=136916);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(137766, 1, 153307, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari capturado
(136552, 1, 82347, 0, 0, 0, 0, 0, 0, 0, 0), -- Maleante Kao-Tien
(140510, 1, 124358, 0, 0, 124358, 0, 0, 0, 0, 0), -- Jefa Revientabocas
(140525, 1, 119398, 0, 0, 0, 0, 0, 0, 0, 0), -- Taladrador Pantoque
(140536, 1, 107673, 0, 0, 57174, 0, 0, 0, 0, 0), -- Explotador Pantoque
(137391, 1, 32537, 0, 0, 0, 0, 0, 0, 0, 0), -- Rompetierras Hierro Negro
(137400, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Thaelin Yunqueoscuro
(137401, 1, 85744, 0, 0, 85744, 0, 0, 0, 0, 0), -- Señor feudal del yunque Thurgaden
(137148, 1, 107367, 0, 0, 0, 0, 0, 0, 0, 0), -- Oficial del punto de extracción
(137149, 1, 0, 0, 0, 0, 0, 0, 35805, 0, 0), -- Incinerador Pantoque
(137185, 1, 116913, 0, 0, 0, 0, 0, 0, 0, 0), -- Peón orco
(137680, 1, 152426, 0, 0, 0, 0, 0, 0, 0, 0), -- Hablaolas de Estela de la Tormenta
(138109, 1, 3364, 0, 0, 0, 0, 0, 0, 0, 0), -- Guardias de la Séptima Legión
(136192, 1, 0, 0, 0, 141370, 0, 0, 0, 0, 0), -- Degdod
(137965, 1, 3364, 0, 0, 0, 0, 0, 0, 0, 0), -- Marinero naufragado recuperado
(136075, 1, 3364, 0, 0, 0, 0, 0, 0, 0, 0), -- Marinero naufragado herido
(135620, 1, 56090, 0, 0, 0, 0, 0, 0, 0, 0), -- Kelsey Chispacero
(137440, 1, 85744, 0, 0, 85744, 0, 0, 0, 0, 0), -- Señor feudal del yunque Thurgaden
(137441, 1, 1911, 0, 0, 0, 0, 0, 0, 0, 0), -- Thaelin Yunqueoscuro
(136675, 1, 1903, 0, 0, 0, 0, 0, 25972, 0, 0), -- Brann Barbabronce
(138743, 1, 128193, 0, 0, 0, 0, 0, 0, 0, 0), -- Rabioso trol de sangre
(138775, 1, 144211, 0, 0, 0, 0, 0, 0, 0, 0), -- Corruptora trol de sangre
(139797, 1, 128193, 0, 0, 128193, 0, 0, 0, 0, 0), -- Rabioso trol de sangre
(136641, 1, 1903, 0, 0, 0, 0, 0, 25972, 0, 0), -- Brann Barbabronce
(137240, 1, 1903, 0, 0, 0, 0, 0, 25972, 0, 0), -- Brann Barbabronce
(145245, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Tecnoladrón de Colmillo Escamado
(152093, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Defensor del templo
(137543, 1, 21553, 0, 0, 0, 0, 0, 0, 0, 0), -- Sargento Ermey
(145136, 1, 50137, 0, 0, 0, 0, 0, 0, 0, 0), -- Persuasor de Ventura y Cía.
(145347, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Obrera de Ventura y Cía.
(137337, 1, 21553, 0, 0, 0, 0, 0, 0, 0, 0), -- Sargento Ermey
(141796, 1, 54825, 0, 0, 0, 0, 0, 161296, 0, 0), -- Sargento Sazonadora
(137213, 1, 118080, 0, 0, 0, 0, 0, 0, 0, 0), -- Halford Aterravermis
(135383, 1, 155757, 0, 0, 0, 0, 0, 0, 0, 0), -- Barnard "el Aplastador" Baysworth
(141784, 1, 0, 0, 0, 0, 0, 0, 155209, 0, 0), -- Fusilero de la Séptima Legión
(141813, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Murnir Trenzas de Pedernal
(137327, 1, 2827, 0, 0, 0, 0, 0, 0, 0, 0), -- "Salvaje" Bill Karmen
(137322, 1, 13861, 0, 0, 13862, 0, 0, 0, 0, 0), -- Valentina Karmen
(143482, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Obrero de la Alianza
(143472, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Parroquiano desmayado
(141780, 1, 2178, 0, 0, 143, 0, 0, 0, 0, 0), -- Guardia de la Séptima Legión
(137173, 1, 1493, 0, 0, 143, 0, 0, 2552, 0, 0), -- Soldado Leonard
(137008, 1, 21553, 0, 0, 0, 0, 0, 0, 0, 0), -- Sargento Ermey
(136916, 2, 107254, 0, 0, 156876, 0, 0, 0, 0, 0), -- Sethrak Raider
(136727, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Jinete de batalla sethrak
(136915, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Ensalmador sethrak
(136916, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Sethrak Raider
(137867, 1, 118080, 0, 0, 0, 0, 0, 0, 0, 0), -- Halford Aterravermis
(141354, 1, 153405, 0, 0, 0, 0, 0, 0, 0, 0); -- Conscripto Canto Tormenta

UPDATE `creature_equip_template` SET `ItemID1`=153589 WHERE (`CreatureID`=133122 AND `ID`=4); -- Guerrera nazmani
UPDATE `creature_equip_template` SET `ItemID1`=114962 WHERE (`CreatureID`=133122 AND `ID`=3); -- Guerrera nazmani
UPDATE `creature_equip_template` SET `ItemID1`=108286 WHERE (`CreatureID`=133122 AND `ID`=2); -- Guerrera nazmani
UPDATE `creature_equip_template` SET `ItemID1`=116485 WHERE (`CreatureID`=133122 AND `ID`=1); -- Guerrera nazmani
UPDATE `creature_equip_template` SET `ItemID1`=31824 WHERE (`CreatureID`=135678 AND `ID`=3); -- Cañonero de la Séptima Legión
UPDATE `creature_equip_template` SET `ItemID1`=0 WHERE (`CreatureID`=135678 AND `ID`=2); -- Cañonero de la Séptima Legión
UPDATE `creature_equip_template` SET `ItemID1`=2202 WHERE (`CreatureID`=133325 AND `ID`=1); -- Comerciante de Drustvar
UPDATE `creature_equip_template` SET `ItemID1`=5278 WHERE (`CreatureID`=134688 AND `ID`=3); -- Cazatesoros
UPDATE `creature_equip_template` SET `ItemID1`=1903 WHERE (`CreatureID`=130867 AND `ID`=2); -- Soldado del batallón
UPDATE `creature_equip_template` SET `ItemID1`=155799 WHERE (`CreatureID`=130867 AND `ID`=1); -- Soldado del batallón
UPDATE `creature_equip_template` SET `ItemID1`=155692 WHERE (`CreatureID`=143168 AND `ID`=1); -- Desuellapeces malhumorado
UPDATE `creature_equip_template` SET `ItemID1`=2717 WHERE (`CreatureID`=134688 AND `ID`=2); -- Cazatesoros
UPDATE `creature_equip_template` SET `ItemID1`=1910 WHERE (`CreatureID`=134688 AND `ID`=1); -- Cazatesoros

DELETE FROM `gossip_menu` WHERE (`MenuId`=21782 AND `TextId`=34252) OR (`MenuId`=22317 AND `TextId`=34255);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21782, 34252, 38134), -- 129519 (Vorrik)
(22317, 34255, 38134); -- 129519 (Vorrik)

UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22537 AND `TextId`=33743); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22537 AND `TextId`=33743); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22620 AND `TextId`=34793); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22620 AND `TextId`=34793); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23317 AND `TextId`=36149); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23317 AND `TextId`=36149); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23270 AND `TextId`=36062); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23270 AND `TextId`=36062); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22527 AND `TextId`=34640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22527 AND `TextId`=34640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34801); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34801); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22535 AND `TextId`=34648); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22660 AND `TextId`=34957); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22660 AND `TextId`=34957); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22527 AND `TextId`=34640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22527 AND `TextId`=34640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22527 AND `TextId`=34640); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23336 AND `TextId`=36172); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23455 AND `TextId`=34568); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22344 AND `TextId`=34311); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22547 AND `TextId`=34676); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22547 AND `TextId`=34676); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22547 AND `TextId`=34676); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23455 AND `TextId`=34568); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23440 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23440 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22609 AND `TextId`=34780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22609 AND `TextId`=34780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22609 AND `TextId`=34780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22609 AND `TextId`=34780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22611 AND `TextId`=34782); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22609 AND `TextId`=34780); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21799 AND `TextId`=33310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21799 AND `TextId`=33310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=21797 AND `TextId`=33309); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23435 AND `TextId`=36306); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23435 AND `TextId`=36306); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22642 AND `TextId`=34890); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22605 AND `TextId`=34764); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22605 AND `TextId`=34764); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22605 AND `TextId`=34764); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23440 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23440 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23440 AND `TextId`=34299); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23455 AND `TextId`=34568); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22614 AND `TextId`=34785); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22614 AND `TextId`=34785); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22343 AND `TextId`=34310); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22858 AND `TextId`=35432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22858 AND `TextId`=35432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22858 AND `TextId`=35432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22858 AND `TextId`=35432); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23220 AND `TextId`=35913); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=22964 AND `TextId`=35531); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=38134 WHERE (`MenuId`=23236 AND `TextId`=35986); -- 0
DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=1 AND `MenuId` IN (21782,22317)) OR (`OptionIndex`=0 AND `MenuId` IN (21782,22317,22343));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21782, 1, 0, '¿Qué más puedes decirme?', 0, 38134),
(21782, 0, 0, '¿Quiénes son los Guardianes?', 0, 38134),
(22317, 1, 0, '¿Qué más puedes decirme?', 0, 38134),
(22317, 0, 0, '¿Quién es Korthek?', 0, 38134),
(22343, 0, 0, '<Mostrar la piedracanto a Kellam.>', 0, 38134);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (21797,22317,21799)) OR (`OptionIndex`=1 AND `MenuId`=21782);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21797, 0, 21799, 0),
(21782, 1, 21797, 0),
(22317, 0, 21782, 0),
(21799, 0, 22317, 0);




UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=136907; -- Magni Bronzebeard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=139828; -- Magni Bronzebeard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33587200 WHERE `entry`=143680; -- Proxy Credit
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=137580; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `RangeAttackTime`=0 WHERE `entry`=136728; -- Doncella de vitalidad
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `speed_run`=4.571428775787353515, `RangeAttackTime`=0 WHERE `entry`=136729; -- Nodo de defensa
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `RangeAttackTime`=0 WHERE `entry`=137607; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141870; -- Herida de azerita
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=130216; -- Magni Bronzebeard
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131904; -- Spiky Lizard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131814; -- Granadero Hierro Negro
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136550; -- Centinela cargado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131626; -- Cuernoatroz salvaje
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=131624; -- Ravasaurio xibalano
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137766; -- Zandalari capturado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136552; -- Maleante Kao-Tien
UPDATE `creature_template` SET `gossip_menu_id`=23270, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143334; -- Daria Herrero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135878; -- Estruendor Hierro Negro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=132188; -- Rompetierras Hierro Negro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143488; -- Taladrador Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=140510; -- Jefa Revientabocas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=140571; -- Transportista Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=140525; -- Taladrador Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16448, `unit_flags2`=2048 WHERE `entry`=140543; -- Fracturadora Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=140580; -- Transportista Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=140536; -- Explotador Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=16384, `unit_flags2`=2048 WHERE `entry`=140579; -- Transportista Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137378; -- Magma inestable
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137391; -- Rompetierras Hierro Negro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=135879; -- Elemental de excavación
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=16777216, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=136099; -- Montículo de tierra
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131763; -- Excavador Morgrum Chispayesca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131777; -- Acadia Tallapiedras
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=136097; -- Montículo de tierra
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128042; -- Jannis Correolas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137400; -- Thaelin Yunqueoscuro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137401; -- Señor feudal del yunque Thurgaden
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131800; -- Cahna Mantonegro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135875; -- Prospector de la Liga de Expedicionarios
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=131789; -- Granadero Hierro Negro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135876; -- Perito de la Liga de Expedicionarios
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=128041; -- Paula Correolas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=137148; -- Oficial del punto de extracción
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137149; -- Incinerador Pantoque
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=106, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137185; -- Peón orco
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200 WHERE `entry`=137154; -- General Purpose Stalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131630; -- Brutosaurio
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131674; -- Colamuera maramargo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131675; -- Cangrejo escaparena
UPDATE `creature_template` SET `unit_flags`=33536, `unit_flags2`=2099200 WHERE `entry`=75372; -- General Purpose Stalker
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129302; -- Mandíbula profunda marcada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=130916; -- Mandíbula profunda salvaje
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142305; -- Mariposa orillera
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=143044; -- Barrier Hermit
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131673; -- Pinzaespina maramargo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131676; -- Guillotina maramargo
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142282; -- Escolopácido isleño
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=140664; -- Colmillosable del sur
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=142284; -- Ermitaño de barrera
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141096; -- Delfín olaoscura
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144366; -- Mero luminoso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137575; -- Albatros del Mar del Sur
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=157907; -- Kill Credit: Explosives detonated
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=16777216, `RangeAttackTime`=0 WHERE `entry`=129320; -- Pollo de Canal Perla (Tormenta)
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137524; -- Aterraescama rayado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=129710; -- Akru
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=74, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=6905 WHERE `entry`=157735; -- Rompemareas nazeshi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128632; -- Sobrestante nazeshi
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137463; -- Alebrilla de la selva
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128604; -- Portatempestades nazeshi
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130996; -- Tortuga marina valvarena
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133349; -- Storm Bunny
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137545; -- Sáurido costero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144460; -- Sacudidor sobrealimentado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=104859648, `unit_flags3`=1 WHERE `entry`=157737; -- Barrera de agua
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130999; -- Tiburón martillo voraz
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130832; -- Pico de hacha ojosalado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141521; -- Capitana Sarai Naut
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `npcflag`=16777216, `speed_walk`=1.20000004768371582, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67635200, `VehicleId`=5967 WHERE `entry`=137678; -- Kul Tiran Rowboat
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=3000, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=67110912 WHERE `entry`=137680; -- Hablaolas de Estela de la Tormenta
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=136292; -- Marinero de Boralus
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=136290; -- Marinero de Boralus
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1802, `BaseAttackTime`=2000, `unit_flags`=32784, `unit_flags2`=2048 WHERE `entry`=138109; -- Guardias de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=83, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136906; -- Mayor Alan Hawkins
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137084; -- Marinero Jaseon
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=137834; -- Cavapozos de arena
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133862; -- Iguánido cornudo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133824; -- Pirociérnaga
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137771; -- Conjurador lóbrego
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135412; -- Aletardiente grasoso
UPDATE `creature_template` SET `minlevel`=1, `maxlevel`=1, `npcflag`=0, `RangeAttackTime`=0 WHERE `entry`=137200; -- Mosquito
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1733, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136195; -- Médica Feorea
UPDATE `creature_template` SET `gossip_menu_id`=22535, `minlevel`=50, `maxlevel`=50, `faction`=1733, `npcflag`=4227, `BaseAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=136192; -- Degdod
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=137965; -- Marinero naufragado recuperado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137255; -- Hexápodo vagabundo
UPDATE `creature_template` SET `gossip_menu_id`=22527, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=136197; -- Brigadier Thom
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1733, `npcflag`=65665, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=137624; -- Oliva
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1733, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=138854; -- Agua Dulce
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138850; -- Birgita
UPDATE `creature_template` SET `gossip_menu_id`=23336, `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=143690; -- Trol zandalari capturado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=138117; -- Marino de la Séptima Legión
UPDATE `creature_template` SET `gossip_menu_id`=22660, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138128; -- Kaolin
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138118; -- Guardia de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=144457; -- Guardias de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133846; -- Luciérnaga acuática
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137849; -- Buscavientos de La Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137230; -- Cadáver de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135858; -- Marinero de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135886; -- Guardia de la muerte de los Renegados
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=131631; -- Andarríos arenero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131013; -- Sacudidor dazariano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143677; -- Hoja rauda zandalari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=32768 WHERE `entry`=136075; -- Marinero naufragado herido
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143678; -- Lanzahachas zandalari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136449; -- Marinero de la Séptima Legión ahogado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135620; -- Kelsey Chispacero
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137440; -- Señor feudal del yunque Thurgaden
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137441; -- Thaelin Yunqueoscuro
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133335; -- Estructura de trol de sangre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133336; -- Estructura de trol de sangre
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `dynamicflags`=128 WHERE `entry`=133304; -- Cautivo zandalari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=133373; -- Jax'teb el Reanimado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133376; -- Esqueleto derruido
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=126112; -- Guerrero de Kel'vax
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=126126; -- Caminamuerte Kel'vax
UPDATE `creature_template` SET `unit_flags`=32768, `dynamicflags`=0 WHERE `entry`=126091; -- Embalsamador profano
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2977, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=136988; -- Cautivo zandalari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2131968 WHERE `entry`=136568; -- Capitana Conrad
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133445; -- Asaltante nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133181; -- Ritualista nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133173; -- Crustájeo de guerra feroz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133279; -- Esclavo nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133358; -- Discípula sanguínea
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2860, `BaseAttackTime`=2500, `unit_flags`=33024, `unit_flags2`=1067008 WHERE `entry`=136675; -- Brann Barbabronce
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85 WHERE `entry`=150102; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138743; -- Rabioso trol de sangre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138775; -- Corruptora trol de sangre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139797; -- Rabioso trol de sangre
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138812; -- Crustájeo sangrehirviente
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=133347; -- Devastador nazmani
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128935; -- Mala'kili
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135054; -- Cobarde inestable
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32848 WHERE `entry`=128965; -- Uroku el Encadenado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128975; -- Ghost Beam Channeller
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=128934; -- Guardián de filacteria
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=126107; -- Formador de esqueletos de Kel'vax
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=127267; -- Quijaforte enfermizo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=537133888, `unit_flags2`=2099201, `unit_flags3`=8192 WHERE `entry`=136564; -- Hir'eek
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2914, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=136565; -- Bruja sangrienta Pakkala
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2914, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136639; -- Adorador de Zalamar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2860, `BaseAttackTime`=2500, `unit_flags`=33536, `unit_flags2`=1067008 WHERE `entry`=136641; -- Brann Barbabronce
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=5919 WHERE `entry`=136573; -- Murciélago mensajero de Zalamar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=210, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192, `dynamicflags`=128 WHERE `entry`=136575; -- Lacayo de Fuerte Victoria
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=129335; -- Sacrificio zandalari
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=128071; -- Beliengendro domado
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=127176; -- Engendro de crustájeo
UPDATE `creature_template` SET `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=0 WHERE `entry`=129424; -- Captive Rope Anchor Point
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags2`=33556480 WHERE `entry`=127142; -- Guerrera de Zalamar
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=128875; -- Espíritu drenado
UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=135789; -- Pitón rondadora del fango
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126056; -- Creadora de tótems Jash'ga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124976; -- Traficante de cadáveres Jal'aka
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=136606; -- Ju'mak
UPDATE `creature_template` SET `gossip_menu_id`=22547 WHERE `entry`=136447; -- Harry "Lunargenta"
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=134451; -- Selina Cuervocaso
UPDATE `creature_template` SET `gossip_menu_id`=22344 WHERE `entry`=135072; -- Garrick Acero Negro
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131629; -- Trol de sangre codicioso
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=127820; -- Explorador Skrasniss
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=126017; -- Alimento de faucemaligna
UPDATE `creature_template` SET `dynamicflags`=128 WHERE `entry`=124949; -- Tótem de profanación
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=126014; -- Faucemaligna joven
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143107; -- Navegante Hudson
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1732, `BaseAttackTime`=2500, `unit_flags`=33536, `unit_flags2`=1067008 WHERE `entry`=137240; -- Brann Barbabronce
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144611; -- Hundidor lomocoral
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144088; -- Sirviente del Vacío
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144051; -- Portal del Vacío
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129180; -- Warbringer Hozzik
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536, `unit_flags2`=67110912, `unit_flags3`=0 WHERE `entry`=124020; -- Exiliada zandalari
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124627; -- Hiena Escarbueso
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130434; -- Agostador ranishu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130427; -- Devorador ranishu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130429; -- Enjambrista ranishu
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=134611; -- Seriah
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=128691; -- Izarn
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136925; -- Branquidermo pleamar
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136926; -- Vidente pleamar
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=139075; -- Vorrik's Keystone
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128996; -- Cangrejo caparasal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=145245; -- Tecnoladrón de Colmillo Escamado
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137402; -- Cangrejo pigmeo
UPDATE `creature_template` SET `gossip_menu_id`=21797, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128694; -- Vorrik
UPDATE `creature_template` SET `gossip_menu_id`=21799, `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=129519; -- Vorrik
UPDATE `creature_template` SET `minlevel`=50, `npcflag`=4194433, `RangeAttackTime`=0 WHERE `entry`=139827; -- Vithur
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139833; -- Pterrordáctilo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139835; -- Pterrordáctilo
UPDATE `creature_template` SET `gossip_menu_id`=22611, `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=137559; -- Soldado James
UPDATE `creature_template` SET `gossip_menu_id`=23435, `minlevel`=50, `maxlevel`=50, `faction`=2968, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=144353; -- Coleccionista Tojo
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=128695; -- Vethiss
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139831; -- Pterrordáctilo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130023; -- Cría Escama de Sal
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130022; -- Bestia de río Escama de Sal
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=134638; -- Warlord Zothix
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags`=32784 WHERE `entry`=152093; -- Defensor del templo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137552; -- Soldado James
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128664; -- Centinela infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128660; -- Agresor infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128661; -- Devastador infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128662; -- Celador infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=129076; -- Cañón sethrak
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `RangeAttackTime`=0 WHERE `entry`=133333; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129202; -- Defensor del templo
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128697; -- Zeriph
UPDATE `creature_template` SET `gossip_menu_id`=22642, `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=137537; -- Vorrik
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=137543; -- Sargento Ermey
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=33536 WHERE `entry`=150318; -- Veriss
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129011; -- Defensor del templo
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128693; -- Issik
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128688; -- Sorin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134613; -- Zareen
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128689; -- Sissok
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128692; -- Ikoriss
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129216; -- Belisario infiel
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129521; -- Hezzil
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129014; -- Hessir
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141955; -- Squeezer
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141950; -- Clubber
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141951; -- Squirt
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=141945; -- Sizzik
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1806, `RangeAttackTime`=0, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142313; -- Defensor del templo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=126893; -- Alfazaque de las dunas
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135400; -- Jenoh
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143454; -- Taz
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124716; -- Alfa alpaca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124718; -- Cría de alpaca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124522; -- Alpaca
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=136986; -- Tortuga valvarena
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=136109; -- Azotador atrivax
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136144; -- Miniazotador atrivax
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130042; -- Cangrejo garrapétrea
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134320; -- Devastador infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129004; -- Defensor del templo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134321; -- Agresor infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139072; -- Águila ratonera picóseo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128665; -- Clamacielos infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129008; -- Sondarenas infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129007; -- Centinela infiel
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=145148; -- Oficial de expedición en jefe McCormick
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124591; -- Exiliado zandalari
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `unit_flags`=768 WHERE `entry`=145345; -- Trituradora de McCormick
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=145136; -- Persuasor de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50 WHERE `entry`=145347; -- Obrera de Ventura y Cía.
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124179; -- Saurolisco hinchado
UPDATE `creature_template` SET `minlevel`=50, `faction`=714, `RangeAttackTime`=0, `unit_flags2`=18432 WHERE `entry`=133833; -- Rikati
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124177; -- Trepador alabilis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130270; -- Colmena de alabilis suelta
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124172; -- Infestador alabilis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124182; -- Saurolisco infectado
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=124183; -- Bilewing Egg
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124536; -- Lisiador alabilis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=142449; -- Alpaca
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141597; -- Exiliado zandalari
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130248; -- Carroñero picóseo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123572; -- Cría de tenazamorte
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122749; -- Custodio tenazamorte
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122750; -- Cría de tenazamorte
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=123473; -- Trampero infiel
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128683; -- Escarbueso infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124029; -- Piojo de la duna
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128681; -- Belisario infiel
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128685; -- Ensalmador infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128978; -- Belisario infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129120; -- Defensor del templo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124526; -- Krolusko merodeadunas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128678; -- Clamacielos infiel
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=128682; -- Defensor infiel
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=1665, `npcflag`=16777216, `speed_walk`=1.20000004768371582, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=33587712, `unit_flags2`=116736, `VehicleId`=5956 WHERE `entry`=137501; -- Pterrordáctilo domado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137434; -- Vorrik
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130070; -- Buitre del cañón
UPDATE `creature_template` SET `minlevel`=50, `unit_flags`=768 WHERE `entry`=150895; -- Santuario de las Arenas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=124654; -- Krolusko merodeadunas
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136596; -- Sondarenas Vesarik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=137681; -- King Clickyclack
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124681; -- Acechador escarbueso
UPDATE `creature_template` SET `minlevel`=50, `faction`=16, `RangeAttackTime`=0 WHERE `entry`=124683; -- Cachorro escarbueso
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137416; -- Culebra del cañón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=32768 WHERE `entry`=137388; -- Vorrik
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130348; -- Azotador marchito
UPDATE `creature_template` SET `gossip_menu_id`=22605, `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=137337; -- Sargento Ermey
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137413; -- Reptador del polvo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130349; -- Azotezno marchito
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137422; -- Escórpido colapétrea
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=126904; -- Escórpido leopardo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136663; -- Alfazaque óseo
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137419; -- Perro de la pradera
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=136553; -- Krolusko salespina
UPDATE `creature_template` SET `minlevel`=50, `faction`=2944, `RangeAttackTime`=0 WHERE `entry`=139361; -- Cría de krolusko
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `RangeAttackTime`=0 WHERE `entry`=122530; -- Spell Bunny
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137412; -- Lagarto lomopúa
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124287; -- Hiena Escarbueso
UPDATE `creature_template` SET `maxlevel`=1, `RangeAttackTime`=0 WHERE `entry`=137417; -- Cola de algodón del desierto
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=124527; -- Carroñero picóseo
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=136562; -- Intendente Alfin
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144610; -- Rémora pielplateada
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141796; -- Sargento Sazonadora
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2713, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137213; -- Halford Aterravermis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144121; -- Orville Manfred
UPDATE `creature_template` SET `gossip_menu_id`=23440, `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=135383; -- Barnard "el Aplastador" Baysworth
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=143483; -- Mula de carga
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141784; -- Fusilero de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=144136; -- Pterrordáctilo domado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139568; -- Magíster Umbric
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143473; -- Parroquiano de la taberna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141813; -- Murnir Trenzas de Pedernal
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137327; -- "Salvaje" Bill Karmen
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137322; -- Valentina Karmen
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143478; -- Thoralius el Sabio
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=122170; -- Generic Bunny
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=136566; -- Mordedor ladrón
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137319; -- Cuidadora Mila
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143472; -- Parroquiano desmayado
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=141780; -- Guardia de la Séptima Legión
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143482; -- Obrero de la Alianza
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=137187; -- Reptaguerra krolusko
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=137173; -- Soldado Leonard
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=34816 WHERE `entry`=137008; -- Sargento Ermey
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136936; -- Bestia de carga kroluska
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136727; -- Jinete de batalla sethrak
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `VehicleId`=5928 WHERE `entry`=136731; -- Reptaguerra krolusko
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136915; -- Ensalmador sethrak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=136916; -- Sethrak Raider
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=136842; -- Vulpera asesinado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912 WHERE `entry`=143894; -- Falla del Vacío
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=84, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=143891; -- Magíster Umbric
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `faction`=2713, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=51200 WHERE `entry`=137867; -- Halford Aterravermis
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=125098; -- Gaviota de cala
UPDATE `creature_template` SET `gossip_menu_id`=23352 WHERE `entry`=143968; -- Mapa de expediciones
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=142721; -- Ralston Karn
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=138744; -- Alapresta
UPDATE `creature_template` SET `gossip_menu_id`=22141, `npcflag`=137438953473 WHERE `entry`=138704; -- Mesa de comando de misión
UPDATE `creature_template` SET `gossip_menu_id`=24652 WHERE `entry`=153932; -- Genn Greymane
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=135614; -- Maestro Mathias Shaw
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138178; -- Anduin Wrynn
UPDATE `creature_template` SET `gossip_menu_id`=22508 WHERE `entry`=135681; -- Gran almirante Jes-Tereth
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=152000; -- Dori'thur
UPDATE `creature_template` SET `gossip_menu_id`=23455 WHERE `entry`=144635; -- Campaña de Zandalar
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138321; -- Capitán Shwayder
UPDATE `creature_template` SET `minlevel`=0, `maxlevel`=0, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=138322; -- Lion's Guard
UPDATE `creature_template` SET `gossip_menu_id`=20891 WHERE `entry`=131290; -- Flynn Fairwind
UPDATE `creature_template` SET `gossip_menu_id`=23317 WHERE `entry`=120788; -- Genn Greymane
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=124725; -- Joan Weber
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=126434; -- Pez globo escamafría
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=138931; -- Poppers
UPDATE `creature_template` SET `gossip_menu_id`=22614 WHERE `entry`=134752; -- Alcaldesa Roz
UPDATE `creature_template` SET `speed_run`=1.714285731315612792 WHERE `entry`=137104; -- Asaltante orco
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=131709; -- Mozo de labranza mecanizado
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=134963; -- Karla Buentiempo
UPDATE `creature_template` SET `npcflag`=16777216, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=130452; -- Perro guardián fiel
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=129870; -- Maestro de jabalíes zarzalomo
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=129869; -- Comerraíces hambriento
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `BaseAttackTime`=1739, `RangeAttackTime`=0, `unit_flags`=32768 WHERE `entry`=130395; -- Briarback Warcaller
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=134832; -- Malorian Buenviento
UPDATE `creature_template` SET `minlevel`=-10, `maxlevel`=-10 WHERE `entry`=141853; -- Rebecca Barnes
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135782; -- Eddard Chimuelo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131199; -- Orgullo de Azshara
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131312; -- Guardián escamoso zeth'jir
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `RangeAttackTime`=0 WHERE `entry`=131433; -- Shoalbreach Lance
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=129973; -- Resaca zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33555200 WHERE `entry`=131200; -- Cañón
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134669; -- Guardia del batallón varado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=131315; -- Encantadora zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=1140852736 WHERE `entry`=155070; -- Lecho de flores exuberantes
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135402; -- Encantadora zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134987; -- Cataluchador zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135403; -- Emboscadora zeth'jir
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=129980; -- Anguila abisal
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=131084; -- Guardián de la marea zeth'jir
UPDATE `creature_template` SET `dynamicflags`=0 WHERE `entry`=131409; -- Soldado del batallón varado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134809; -- Vinculadora Ser'less
UPDATE `creature_template` SET `gossip_menu_id`=22343 WHERE `entry`=131000; -- Comandante Kellam
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=2147483712 WHERE `entry`=134401; -- Lady Rash'iss
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134813; -- Vinculadora Nalashj
UPDATE `creature_template` SET `minlevel`=8, `maxlevel`=11, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=137390; -- Kul Tiran Child
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0 WHERE `entry`=143158; -- Sereno del muelle
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143168; -- Desuellapeces malhumorado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143182; -- Velador atribulado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141877; -- Gaviota de los bajíos
UPDATE `creature_template` SET `gossip_menu_id`=83 WHERE `entry`=6491; -- Ángel de la Resurrección
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=131143; -- Clamamareas zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141872; -- Caparazón blando de los bajíos
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=131002; -- Teniente Bauer
UPDATE `creature_template` SET `unit_flags`=570721088, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=131085; -- Señor de las Mareas zeth'jir
UPDATE `creature_template` SET `unit_flags`=33536, `unit_flags2`=33556480, `unit_flags3`=0 WHERE `entry`=135037; -- Aldeano armado
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=133983; -- Poza de marea
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130079; -- Wagga Dentaullido
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `unit_flags`=32832 WHERE `entry`=134884; -- Ragna
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134141; -- Maestro de manada zarzalomo
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141696 WHERE `entry`=135293; -- Truenahocico
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=130130; -- Guerracerdo hambriento
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `unit_flags`=768 WHERE `entry`=137231; -- Plato de galletas
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141696 WHERE `entry`=136417; -- Zarpador alfa
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=141534; -- Cabra bebé
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=67141632 WHERE `entry`=136418; -- Zarpador joven
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0, `dynamicflags`=0 WHERE `entry`=136734; -- Millie
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134341; -- Vinculadora Sa'thress
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0, `unit_flags`=33040 WHERE `entry`=134343; -- Sirviente de Neptulon
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134340; -- Marejada atada
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `npcflag`=0, `RangeAttackTime`=0, `unit_flags`=33536 WHERE `entry`=131125; -- Aldeano aterrorizado
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=130812; -- Hundidor coralino
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=131141; -- Guardián escamoso zeth'jir
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=134379; -- Olas invasoras
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `RangeAttackTime`=0, `unit_flags`=32784 WHERE `entry`=141354; -- Conscripto Canto Tormenta
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=136416; -- Zarpador feral
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=136939; -- Madre cabra
UPDATE `creature_template` SET `gossip_menu_id`=23220 WHERE `entry`=136414; -- Pastora Milbrooke
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=137126; -- Rata volátil
UPDATE `creature_template` SET `gossip_menu_id`=22964 WHERE `entry`=136574; -- Charles Davenport
UPDATE `creature_template` SET `gossip_menu_id`=22858 WHERE `entry`=136658; -- Marie Davenport
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143903; -- George
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=143899; -- Vigía Jeph
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=138180; -- Alexa Davenport
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50, `RangeAttackTime`=0 WHERE `entry`=137078; -- Boulder Caster
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=139793; -- Oso pardo zarpapúa
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=140595; -- Cazador Canto Tormenta
UPDATE `creature_template` SET `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=130073; -- Briarback Lookout
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=138755; -- Irontide Slaver
UPDATE `creature_template` SET `faction`=3014 WHERE `entry`=134666; -- Cazatesoros
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=136743; -- Cazatesoros
UPDATE `creature_template` SET `faction`=3014 WHERE `entry`=138739; -- Defensor de La Rivera Muerta
UPDATE `creature_template` SET `faction`=3014 WHERE `entry`=135783; -- Cazatesoros
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=134636; -- Cazatesoros
UPDATE `creature_template` SET `minlevel`=50, `RangeAttackTime`=0 WHERE `entry`=135745; -- Reptador de esquisto
UPDATE `creature_template` SET `gossip_menu_id`=23236 WHERE `entry`=139635; -- Matthew Gandorian


UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335866 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333763 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333739 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=339987 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336871 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336870 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340674 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340359 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=289066 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=388350 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333455 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333454 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333454 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333454 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=312092 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334816 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338154 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333212 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=332904 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338609 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341728 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336403 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340633 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340633 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340624 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340624 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340622 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340622 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336394 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336393 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336393 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336393 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336381 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336381 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=296286 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337061 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337847 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340066 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335716 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335132 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337744 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335563 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335535 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335818 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336093 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335134 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336234 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335151 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341335 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=338977 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337770 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335287 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335005 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335284 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=288985 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=287685 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=287649 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334950 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334842 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=341730 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334700 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337617 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=337772 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335692 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335691 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335579 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335566 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=334985 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335293 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336293 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295575 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333774 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333464 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=333448 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335125 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336027 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=336033 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335506 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335472 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335159 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335106 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335110 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335112 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335982 AND `Index`=3);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335982 AND `Index`=2);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335982 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335982 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335157 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335156 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=335155 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397741 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=397669 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=405017 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406745 AND `Index`=1);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406745 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=406744 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=340170 AND `Index`=0);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=38134 WHERE (`ID`=295187 AND `Index`=0);


UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52450 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52003 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52013 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=52008 AND `Idx`=0);
UPDATE `quest_reward_display_spell` SET `VerifiedBuild`=38134 WHERE (`QuestID`=51714 AND `Idx`=0);


UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=138279 AND `Idx`=0); -- Adhara White
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=136550 AND `Idx`=0); -- Centinela cargado
UPDATE `creature_template_model` SET `DisplayScale`=1.080000042915344238 WHERE (`CreatureID`=140510 AND `Idx`=0); -- Jefa Revientabocas
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=140580 AND `Idx`=0); -- Transportista Pantoque
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=140579 AND `Idx`=0); -- Transportista Pantoque
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=140571 AND `Idx`=0); -- Transportista Pantoque
UPDATE `creature_template_model` SET `DisplayScale`=0.150000005960464477, `Probability`=0 WHERE (`CreatureID`=137378 AND `Idx`=0); -- Magma inestable
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=135879 AND `Idx`=0); -- Elemental de excavación
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=128041 AND `Idx`=0); -- Paula Correolas
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=137185 AND `Idx`=0); -- Peón orco
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=137154 AND `Idx`=1); -- General Purpose Stalker
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=142305 AND `Idx`=0); -- Mariposa orillera
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143044 AND `Idx`=2); -- Barrier Hermit
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=143044 AND `Idx`=1); -- Barrier Hermit
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143044 AND `Idx`=0); -- Barrier Hermit
UPDATE `creature_template_model` SET `DisplayScale`=1.149999976158142089 WHERE (`CreatureID`=140664 AND `Idx`=0); -- Colmillosable del sur
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=142284 AND `Idx`=0); -- Ermitaño de barrera
UPDATE `creature_template_model` SET `DisplayScale`=0.150000005960464477 WHERE (`CreatureID`=137524 AND `Idx`=0); -- Aterraescama rayado
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=128631 AND `Idx`=0); -- Chascacaparazón de la marea
UPDATE `creature_template_model` SET `DisplayScale`=0.100000001490116119 WHERE (`CreatureID`=137463 AND `Idx`=0); -- Alebrilla de la selva
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=144460 AND `Idx`=0); -- Sacudidor sobrealimentado
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=137582 AND `Idx`=0); -- Kul Tiran Rowboat
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=137678 AND `Idx`=0); -- Kul Tiran Rowboat
UPDATE `creature_template_model` SET `DisplayScale`=0.85000002384185791 WHERE (`CreatureID`=138294 AND `Idx`=0); -- Diablillo llamarada infernal
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=143677 AND `Idx`=0); -- Hoja rauda zandalari
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=128935 AND `Idx`=0); -- Mala'kili
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=136639 AND `Idx`=0); -- Adorador de Zalamar
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=135953 AND `Idx`=0); -- Kul Tiran Rowboat
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=144088 AND `Idx`=0); -- Sirviente del Vacío
UPDATE `creature_template_model` SET `DisplayScale`=0.699999988079071044 WHERE (`CreatureID`=130429 AND `Idx`=0); -- Enjambrista ranishu
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=136925 AND `Idx`=0); -- Branquidermo pleamar
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=136926 AND `Idx`=0); -- Vidente pleamar
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=139075 AND `Idx`=0); -- Vorrik's Keystone
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=128664 AND `Idx`=0); -- Centinela infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=128661 AND `Idx`=0); -- Devastador infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=128660 AND `Idx`=0); -- Agresor infiel
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=141955 AND `Idx`=0); -- Squeezer
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=141951 AND `Idx`=0); -- Squirt
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=141950 AND `Idx`=0); -- Clubber
UPDATE `creature_template_model` SET `CreatureDisplayID`=87963, `DisplayScale`=1.149999976158142089 WHERE (`CreatureID`=124716 AND `Idx`=0); -- Alfa alpaca
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=124718 AND `Idx`=0); -- Cría de alpaca
UPDATE `creature_template_model` SET `DisplayScale`=0.25 WHERE (`CreatureID`=136144 AND `Idx`=0); -- Miniazotador atrivax
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=134321 AND `Idx`=0); -- Agresor infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=134320 AND `Idx`=0); -- Devastador infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=128665 AND `Idx`=0); -- Clamacielos infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=129008 AND `Idx`=0); -- Sondarenas infiel
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=129007 AND `Idx`=0); -- Centinela infiel
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=145345 AND `Idx`=0); -- Trituradora de McCormick
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=124029 AND `Idx`=0); -- Piojo de la duna
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=128678 AND `Idx`=0); -- Clamacielos infiel
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=136596 AND `Idx`=0); -- Sondarenas Vesarik
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=137681 AND `Idx`=0); -- King Clickyclack
UPDATE `creature_template_model` SET `DisplayScale`=0.400000005960464477 WHERE (`CreatureID`=139361 AND `Idx`=0); -- Cría de krolusko
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137419 AND `Idx`=0); -- Perro de la pradera
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137412 AND `Idx`=0); -- Lagarto lomopúa
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137417 AND `Idx`=0); -- Cola de algodón del desierto
UPDATE `creature_template_model` SET `DisplayScale`=1.399999976158142089 WHERE (`CreatureID`=136562 AND `Idx`=0); -- Intendente Alfin
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137213 AND `Idx`=0); -- Halford Aterravermis
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=143482 AND `Idx`=0); -- Obrero de la Alianza
UPDATE `creature_template_model` SET `Probability`=0 WHERE (`CreatureID`=137867 AND `Idx`=0); -- Halford Aterravermis
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=131199 AND `Idx`=0); -- Orgullo de Azshara
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=140446 AND `Idx`=0); -- Maestro de barriles Jojo
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=134813 AND `Idx`=0); -- Vinculadora Nalashj
UPDATE `creature_template_model` SET `DisplayScale`=1.75 WHERE (`CreatureID`=141877 AND `Idx`=0); -- Gaviota de los bajíos
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=130079 AND `Idx`=0); -- Wagga Dentaullido
UPDATE `creature_template_model` SET `DisplayScale`=3 WHERE (`CreatureID`=134884 AND `Idx`=0); -- Ragna
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=135293 AND `Idx`=0); -- Truenahocico
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=136420 AND `Idx`=0); -- Puñogrokk
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=137153 AND `Idx`=0); -- Cosechador modificado
UPDATE `creature_template_model` SET `DisplayScale`=0.800000011920928955 WHERE (`CreatureID`=136418 AND `Idx`=0); -- Zarpador joven
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143220 AND `Idx`=0); -- Olivala
UPDATE `creature_template_model` SET `DisplayScale`=1.5 WHERE (`CreatureID`=136417 AND `Idx`=0); -- Zarpador alfa
UPDATE `creature_template_model` SET `Probability`=2 WHERE (`CreatureID`=136415 AND `Idx`=0); -- Rebaño de Milbrooke
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=137025 AND `Idx`=0); -- Madre de linaje
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143216 AND `Idx`=0); -- Monarca carmesí
UPDATE `creature_template_model` SET `DisplayScale`=4 WHERE (`CreatureID`=137126 AND `Idx`=0); -- Rata volátil
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=137000 AND `Idx`=0); -- Reptador del sótano
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=136686 AND `Idx`=0); -- Rata de sentina
UPDATE `creature_template_model` SET `DisplayScale`=1.299999952316284179 WHERE (`CreatureID`=137404 AND `Idx`=0); -- Pollo cascarrabias
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=143903 AND `Idx`=0); -- George
UPDATE `creature_template_model` SET `DisplayScale`=0.5 WHERE (`CreatureID`=137599 AND `Idx`=0); -- Bucky
UPDATE `creature_template_model` SET `DisplayScale`=0.75 WHERE (`CreatureID`=143537 AND `Idx`=0); -- Narizón
UPDATE `creature_template_model` SET `DisplayScale`=0.300000011920928955 WHERE (`CreatureID`=143217 AND `Idx`=0); -- Emperador azul
UPDATE `creature_template_model` SET `DisplayScale`=1.20000004768371582 WHERE (`CreatureID`=141286 AND `Idx`=0); -- Furtivo Zane
UPDATE `creature_template_model` SET `DisplayScale`=2 WHERE (`CreatureID`=136419 AND `Idx`=0); -- Tirapiedras ettin
UPDATE `creature_template_model` SET `DisplayScale`=1.25 WHERE (`CreatureID`=136421 AND `Idx`=0); -- Aplastatierra ettin
UPDATE `creature_template_model` SET `DisplayScale`=0.899999976158142089 WHERE (`CreatureID`=134966 AND `Idx`=0); -- Piedra inquieta

DELETE FROM `gameobject_template` WHERE `entry` IN (287742 /*Puerta titánica*/, 287736 /*Puerta titánica*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(287742, 0, 8081, 'Puerta titánica', '', '', '', 0.999999880790710449, 1, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134), -- Puerta titánica
(287736, 0, 8081, 'Puerta titánica', '', '', '', 1, 1, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38134); -- Puerta titánica


UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=288475 AND `Idx`=0); -- Escoria de las Tierras de Fuego
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=287955 AND `Idx`=0); -- Cajón de suministros de la Séptima Legión
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=284468 AND `Idx`=0); -- Cajón de suministros de la Séptima Legión
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278193 AND `Idx`=0); -- Arma sethrak
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278192 AND `Idx`=0); -- Arma sethrak
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278191 AND `Idx`=0); -- Arma sethrak
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=278190 AND `Idx`=0); -- Arma sethrak
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=288646 AND `Idx`=0); -- Pera espinosa
UPDATE `gameobject_questitem` SET `VerifiedBuild`=38134 WHERE (`GameObjectEntry`=279302 AND `Idx`=0); -- Arpón zeth'jir


UPDATE `playerchoice_response` SET `ResponseIdentifier`=923 WHERE (`ChoiceId`=508 AND `ResponseId`=2316 AND `Index`=4);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=922 WHERE (`ChoiceId`=508 AND `ResponseId`=2330 AND `Index`=3);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=921 WHERE (`ChoiceId`=508 AND `ResponseId`=1810 AND `Index`=2);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=920 WHERE (`ChoiceId`=508 AND `ResponseId`=2257 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=919 WHERE (`ChoiceId`=508 AND `ResponseId`=1836 AND `Index`=0);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=918 WHERE (`ChoiceId`=508 AND `ResponseId`=2316 AND `Index`=4);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=917 WHERE (`ChoiceId`=508 AND `ResponseId`=2330 AND `Index`=3);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=916 WHERE (`ChoiceId`=508 AND `ResponseId`=1810 AND `Index`=2);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=915 WHERE (`ChoiceId`=508 AND `ResponseId`=2257 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=914 WHERE (`ChoiceId`=508 AND `ResponseId`=1836 AND `Index`=0);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=913 WHERE (`ChoiceId`=508 AND `ResponseId`=2316 AND `Index`=4);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=912 WHERE (`ChoiceId`=508 AND `ResponseId`=2330 AND `Index`=3);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=911 WHERE (`ChoiceId`=508 AND `ResponseId`=1810 AND `Index`=2);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=910 WHERE (`ChoiceId`=508 AND `ResponseId`=2257 AND `Index`=1);
UPDATE `playerchoice_response` SET `ResponseIdentifier`=909 WHERE (`ChoiceId`=508 AND `ResponseId`=1836 AND `Index`=0);

DELETE FROM `npc_text` WHERE `ID` IN (34252 /*34252*/, 34255 /*34255*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(34252, 1, 0, 0, 0, 0, 0, 0, 0, 148972, 0, 0, 0, 0, 0, 0, 0, 38134), -- 34252
(34255, 1, 0, 0, 0, 0, 0, 0, 0, 148973, 0, 0, 0, 0, 0, 0, 0, 38134); -- 34255

UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34793; -- 34793
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=36149; -- 36149
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=36062; -- 36062
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34801; -- 34801
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34648; -- 34648
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34957; -- 34957
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34640; -- 34640
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=36172; -- 36172
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34311; -- 34311
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34676; -- 34676
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34782; -- 34782
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34780; -- 34780
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33310; -- 33310
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=33309; -- 33309
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=36306; -- 36306
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34890; -- 34890
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34764; -- 34764
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35331; -- 35331
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34568; -- 34568
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34785; -- 34785
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=34310; -- 34310
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35432; -- 35432
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35913; -- 35913
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35531; -- 35531
UPDATE `npc_text` SET `VerifiedBuild`=38134 WHERE `ID`=35986; -- 35986