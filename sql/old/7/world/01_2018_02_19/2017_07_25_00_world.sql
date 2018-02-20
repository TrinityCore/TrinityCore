-- "Bring 'Em Back Alive" (Quest 11690): Allow player to mount Infected Kodo Beast inside all 4 intended Borean Tundra zones
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=25596 AND `ConditionTypeOrReference`=23 AND `ElseGroup` IN (1,2,3,4);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16, 0, 25596, 0, 1, 23, 0, 4144, 0, 0, 0, 0, 0, '',"Bring 'Em Back Alive: Dismount when player is outside intended zone Warsong Farms Outpost"),
(16, 0, 25596, 0, 2, 23, 0, 4143, 0, 0, 0, 0, 0, '',"Bring 'Em Back Alive: Dismount when player is outside intended zone Warsong Slaughterhouse"),
(16, 0, 25596, 0, 3, 23, 0, 4142, 0, 0, 0, 0, 0, '',"Bring 'Em Back Alive: Dismount when player is outside intended zone Warsong Grannary"),
(16, 0, 25596, 0, 4, 23, 0, 4141, 0, 0, 0, 0, 0, '',"Bring 'Em Back Alive: Dismount when player is outside intended zone Torp's Farm");

UPDATE `conditions` SET `Comment`= "Bring 'Em Back Alive: Dismount when player is outside intended zone Borean Tundra"
 WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry`=25596 AND `ConditionTypeOrReference`=23 AND `ElseGroup`=0;
