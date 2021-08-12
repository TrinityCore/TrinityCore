-- Orientation from second spell from pair(previously sniffed)
UPDATE `spell_target_position` SET `PositionX` = -8998.14, `PositionY` = 861.254, `Orientation` = 2.25 WHERE `ID` = 3561; -- Teleport: Stormwind (17334,3561)
UPDATE `spell_target_position` SET `PositionX` = 1469.96, `PositionY` = -4222.51, `PositionZ` = 58.9938, `Orientation` = 0 WHERE `ID` = 3567; -- Teleport: Orgrimmar (17609,3567)
UPDATE `spell_target_position` SET `PositionX` = -4613.71, `PositionY` = -915.287, `Orientation` = 0 WHERE `ID` = 3562; -- Teleport: Ironforge (44089,3562)
UPDATE `spell_target_position` SET `PositionX` = -1824.32, `PositionY` = 5417.23, `PositionZ` = -12.4277, `Orientation` = 2.79904 WHERE `ID` = 33690; -- Teleport: Shattrath (33728,33690)

-- Orientation from WSL or Cata
UPDATE `spell_target_position` SET `PositionX` = -4031.24, `PositionY` = -11569.6, `PositionZ` = -138.299, `Orientation` = 2.513274123 WHERE `ID` IN (32268,32271); -- Exodar
UPDATE `spell_target_position` SET `PositionX` = 9656.54, `PositionY` = 2518.26, `Orientation` = 0 WHERE `ID` IN (3565,17608); -- Darnassus
UPDATE `spell_target_position` SET `PositionX` = 9998.46, `PositionY` = -7106.55, `PositionZ` = 47.7054, `Orientation` = 2.49582083 WHERE `ID` IN (32270,32272); -- Silvermoon
UPDATE `spell_target_position` SET `PositionX` = -967.375, `PositionY` = 284.82, `PositionZ` = 110.773, `Orientation` = 3.193952531 WHERE `ID` IN (3566,17610); -- Thunder Bluff
UPDATE `spell_target_position` SET `PositionX` = 1773.42, `PositionY` = 61.7391, `PositionZ` = -46.3215, `Orientation` = 0 WHERE `ID` IN (3563,17611); -- Undercity
