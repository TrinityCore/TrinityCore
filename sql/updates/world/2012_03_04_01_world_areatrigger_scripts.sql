-- Add Area trigger scripts
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4422,4466,4471,4472);
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(4422,'at_area_52_entrance'),
(4466,'at_area_52_entrance'),
(4471,'at_area_52_entrance'),
(4472,'at_area_52_entrance');
