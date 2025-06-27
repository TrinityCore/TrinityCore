-- Change orientation to home position instead of calling evade to restore orientation
UPDATE `smart_scripts` SET `action_type` = 66, `comment` = "Peppy Wrongnozzle - On Script - Set Orientation Home Position" WHERE `entryorguid` = 2428300 AND `source_type` = 9 AND `id` = 8;
UPDATE `smart_scripts` SET `action_type` = 66, `comment` = "Westguard Defender - On Script - Set Orientation Home Position" WHERE `entryorguid` = 2384200 AND `source_type` = 9 AND `id` = 4;
