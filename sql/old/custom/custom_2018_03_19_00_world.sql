UPDATE `battleground_template` SET `MinLvl`= 75, `StartMaxDist`= 75, `Weight`= 1 WHERE `ID`= 120;
UPDATE `battleground_template` SET `MinLvl`= 75, `StartMaxDist`= 75, `Weight`= 1 WHERE `ID`= 108;

DELETE FROM `gameobject` WHERE `id` IN (179830, 179831, 179785, 179786, 179871, 179904, 179905, 179899, 179907, 179906) AND `map`= 726;
