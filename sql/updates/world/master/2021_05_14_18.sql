-- Zuldazar Portal
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=289697;
REPLACE INTO `smart_scripts` (`entryorguid`, `source_type`, `event_type`, `action_type`, `action_param1`, `target_type`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('289697', '1', '64', '62', '1642', '7', '-477.316', '576.838', '220.353', '3.15488', 'Zuldazar Portal');