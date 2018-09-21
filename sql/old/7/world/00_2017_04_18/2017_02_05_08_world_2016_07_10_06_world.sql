--
UPDATE `creature_loot_template` SET `Chance`=100 WHERE `Item`=5877;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=5877;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 4130, 5877, 0, 0, 8, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is taken OR"),
(1, 4131, 5877, 0, 0, 8, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is taken OR"),
(1, 4132, 5877, 0, 0, 8, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is taken OR"),
(1, 4133, 5877, 0, 0, 8, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is taken OR"),
(1, 4130, 5877, 0, 1, 9, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is rewarded"),
(1, 4131, 5877, 0, 1, 9, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is rewarded"),
(1, 4132, 5877, 0, 1, 9, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is rewarded"),
(1, 4133, 5877, 0, 1, 9, 0, 1147, 0, 0, 0, 0, 0, "", "Item 'Cracked Silithid Carapace' can be looted if quest 'The Swarm Grows' is rewarded");
