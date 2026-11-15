-- Rivendark
SET @NPC=23061;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC,0,0,"Get away from my clutch!!!",14,0,100,0,0,7274,21696,0,'Rivendark'),
(@NPC,0,1,"I know you by your stench, little $n.  Here, in my perch, is where your bones shall finally rest.",14,0,100,0,0,7274,21706,0,'Rivendark'),
(@NPC,0,2,"I tire of interruptions from the insignificant.  Your time has come, $n!",14,0,100,0,0,7274,21710,0,'Rivendark'),
(@NPC,0,3,"The Skyguard shall pay for your temerity, $n!",14,0,100,0,0,7274,21714,0,'Rivendark'),
(@NPC,0,4,"I believe that I shall feast upon both $r and ogre flesh tonight.",14,0,100,0,0,7274,21718,0,'Rivendark'),
(@NPC,0,5,"Little $r, you will now come to appreciate my wrath!",14,0,100,0,0,7274,21720,0,'Rivendark'),
(@NPC,0,6,"You have dared to defile my perch and must now be cleansed in fire!",14,0,100,0,0,7274,21726,0,'Rivendark'),
(@NPC,0,7,"What's this?!  $n and $g his : her; friends come to play?",14,0,100,0,0,7274,21733,0,'Rivendark');

-- Furywing
SET @NPC=23261;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC,0,0,"Get away from my clutch!!!",14,0,100,0,0,7274,21696,0,'Furywing'),
(@NPC,0,1,"I know you by your stench, little $n.  Here, in my perch, is where your bones shall finally rest.",14,0,100,0,0,7274,21706,0,'Furywing'),
(@NPC,0,2,"I tire of interruptions from the insignificant.  Your time has come, $n!",14,0,100,0,0,7274,21710,0,'Furywing'),
(@NPC,0,3,"The Skyguard shall pay for your temerity, $n!",14,0,100,0,0,7274,21714,0,'Furywing'),
(@NPC,0,4,"I believe that I shall feast upon both $r and ogre flesh tonight.",14,0,100,0,0,7274,21718,0,'Furywing'),
(@NPC,0,5,"Little $r, you will now come to appreciate my wrath!",14,0,100,0,0,7274,21720,0,'Furywing'),
(@NPC,0,6,"You have dared to defile my perch and must now be cleansed in fire!",14,0,100,0,0,7274,21726,0,'Furywing'),
(@NPC,0,7,"What's this?!  $n and $g his : her; friends come to play?",14,0,100,0,0,7274,21733,0,'Furywing');

-- Insidion
SET @NPC=23281;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC,0,0,"Get away from my clutch!!!",14,0,100,0,0,7274,21696,0,'Insidion'),
(@NPC,0,1,"I know you by your stench, little $n.  Here, in my perch, is where your bones shall finally rest.",14,0,100,0,0,7274,21706,0,'Insidion'),
(@NPC,0,2,"I tire of interruptions from the insignificant.  Your time has come, $n!",14,0,100,0,0,7274,21710,0,'Insidion'),
(@NPC,0,3,"The Skyguard shall pay for your temerity, $n!",14,0,100,0,0,7274,21714,0,'Insidion'),
(@NPC,0,4,"I believe that I shall feast upon both $r and ogre flesh tonight.",14,0,100,0,0,7274,21718,0,'Insidion'),
(@NPC,0,5,"Little $r, you will now come to appreciate my wrath!",14,0,100,0,0,7274,21720,0,'Insidion'),
(@NPC,0,6,"You have dared to defile my perch and must now be cleansed in fire!",14,0,100,0,0,7274,21726,0,'Insidion'),
(@NPC,0,7,"What's this?!  $n and $g his : her; friends come to play?",14,0,100,0,0,7274,21733,0,'Insidion');

-- Obsidia
SET @NPC=23282;
DELETE FROM `creature_text` WHERE `CreatureID`=@NPC;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC,0,0,"Get away from my clutch!!!",14,0,100,0,0,7274,21696,0,'Obsidia'),
(@NPC,0,1,"I know you by your stench, little $n.  Here, in my perch, is where your bones shall finally rest.",14,0,100,0,0,7274,21706,0,'Obsidia'),
(@NPC,0,2,"I tire of interruptions from the insignificant.  Your time has come, $n!",14,0,100,0,0,7274,21710,0,'Obsidia'),
(@NPC,0,3,"The Skyguard shall pay for your temerity, $n!",14,0,100,0,0,7274,21714,0,'Obsidia'),
(@NPC,0,4,"I believe that I shall feast upon both $r and ogre flesh tonight.",14,0,100,0,0,7274,21718,0,'Obsidia'),
(@NPC,0,5,"Little $r, you will now come to appreciate my wrath!",14,0,100,0,0,7274,21720,0,'Obsidia'),
(@NPC,0,6,"You have dared to defile my perch and must now be cleansed in fire!",14,0,100,0,0,7274,21726,0,'Obsidia'),
(@NPC,0,7,"What's this?!  $n and $g his : her; friends come to play?",14,0,100,0,0,7274,21733,0,'Obsidia');
