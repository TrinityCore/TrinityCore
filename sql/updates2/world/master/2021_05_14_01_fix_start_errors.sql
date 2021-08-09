UPDATE `creature` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1712 AND `spawnDifficulties` = "1, 14, 15, 16, 17";
UPDATE `creature` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1648 AND `spawnDifficulties` = "0, 14, 15, 16, 17";
UPDATE `gameobject` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1712 AND `spawnDifficulties` = "1, 14, 15, 16, 17";
UPDATE `gameobject` SET `spawnDifficulties` = "14, 15, 16, 17" WHERE `map` = 1648 AND `spawnDifficulties` = "0, 14, 15, 16, 17";

UPDATE `creature_template` SET `KillCredit2` = 0 WHERE `KillCredit2` = 173429;

-- DELETE FROM `battleground_template` WHERE `ID` IN (901, 847);
