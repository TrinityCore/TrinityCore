UPDATE `gameobject_template` SET `StringId`='bg_buff_object' WHERE `entry` IN (180380,184966,180376,179905,184972,179907,180378,184975,184978,180382,180148,179904,179906,180144,180145,180362,180377,180383,184965,184971,184974,184977,179899,180146,180147,180379,184964,180381,184970,184973,180384,184976,179871);

SET @TRIGGER_ID := 29;
SET @TRIGGER_SPAWN_ID := 30;

DELETE FROM `areatrigger_template` WHERE `Id` = @TRIGGER_ID AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Data0`, `Data1`) VALUES
(@TRIGGER_ID, 1, 0, 3.0, 3.0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+4 AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `ScriptName`, `Comment`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID, 1, 2107, 815.29339599609375, 842.58331298828125, -56.0177841186523437, 3.176533222198486328, 'areatrigger_battleground_buffs', 'Arathi Basin - Battleground Buff - Farm'),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID, 1, 2107, 1147.0242919921875, 816.83160400390625, -99.2923507690429687, 0.4253254234790802, 'areatrigger_battleground_buffs', 'Arathi Basin - Battleground Buff - Gold Mine'),
(@TRIGGER_SPAWN_ID+2, @TRIGGER_ID, 1, 2107, 808.84625244140625, 1185.41748046875, 11.92160511016845703, 5.619962215423583984, 'areatrigger_battleground_buffs', 'Arathi Basin - Battleground Buff - Lumber Mill'),
(@TRIGGER_SPAWN_ID+3, @TRIGGER_ID, 1, 2107, 990.046875, 1008.62152099609375, -42.2709541320800781, 0.820303261280059814, 'areatrigger_battleground_buffs', 'Arathi Basin - Battleground Buff - Blacksmith'),
(@TRIGGER_SPAWN_ID+4, @TRIGGER_ID, 1, 2107, 1184.251708984375, 1186.52783203125, -56.126007080078125, 2.367344856262207031, 'areatrigger_battleground_buffs', 'Arathi Basin - Battleground Buff - Stables');
