-- Quest "Nat's Measuring Tape" was removed in Patch 4.0.3a
-- Quest Starts from GO "Battered Tackle Box" (ID: 180366) and ends at Nat Pagle
-- Despawn GameObject, remove entries from Starter and Ender tables and disable the quest
DELETE FROM `gameobject` WHERE `id`=180366;
DELETE FROM `gameobject_queststarter` WHERE `quest`=8227;
DELETE FROM `creature_questender` WHERE `quest`=8227;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry`=8227;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,8227,0,0,0,'Nat''s Measuring Tape, Removed in Patch 4.0.3a');
