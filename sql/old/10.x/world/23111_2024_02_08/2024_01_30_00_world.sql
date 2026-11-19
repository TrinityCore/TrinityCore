-- Update Position
UPDATE `creature` SET `position_x` = -8200.7705078125, `position_y` = 746.35418701171875, `position_z` = 76.3188934326171875, `orientation` = 0.877556860446929931 WHERE `guid` = 1050136; -- Keira Onyxraven
UPDATE `creature` SET `position_x` = -8200.625, `position_y` = 746.342041015625, `position_z` = 76.33197021484375, `orientation` = 0.724010705947875976 WHERE `guid` = 1050135; -- Vindicator Minkey
UPDATE `creature` SET `position_x` = -8200.59375, `position_y` = 746.27777099609375, `position_z` = 76.33333587646484375, `orientation` = 0.855998575687408447 WHERE `guid` = 850144; -- Mudrik Leger
UPDATE `creature` SET `position_x` = -8200.7548828125, `position_y` = 746.34552001953125, `position_z` = 76.3201904296875, `orientation` = 0.807905077934265136 WHERE `guid` = 850145; -- Lulana

-- Phase names
DELETE FROM `phase_name` WHERE `ID` IN (10037, 10036, 11867, 14345);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(10037, 'Cosmetic - See Keira Onyxraven in Stormwind Embassy'),
(10036, 'Cosmetic - See Vindicator Minkey in Stormwind Embassy'),
(11867, 'Cosmetic - See Mudrik Leger in Stormwind Embassy'),
(14345, 'Cosmetic - See Lulana in Stormwind Embassy');
